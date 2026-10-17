import re

import astdump as A

VALUE_CLASSES = {
    "NSString", "NSMutableString", "NSArray", "NSMutableArray", "NSDictionary", "NSMutableDictionary",
    "NSSet", "NSMutableSet", "NSOrderedSet", "NSMutableOrderedSet", "NSData", "NSMutableData", "NSObject",
}

RESERVED = {
    "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", "case", "catch", "char",
    "class", "compl", "concept", "const", "constexpr", "const_cast", "continue", "decltype", "default", "delete", "do",
    "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto",
    "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator",
    "or", "or_eq", "private", "protected", "public", "register", "reinterpret_cast", "requires", "return", "short",
    "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch", "template", "this", "thread_local",
    "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void", "volatile",
    "while", "xor", "xor_eq", "self", "super", "id", "nil", "Nil", "NO", "YES", "in", "out", "inout", "handle", "isNull",
    "as", "NULL", "TRUE", "FALSE", "main", "errno", "stdin", "stdout", "stderr", "assert", "signal", "major", "minor",
}

BUILTINS = {
    "bool": "bool", "_Bool": "bool", "char": "std::int8_t", "signed char": "std::int8_t", "unsigned char": "std::uint8_t",
    "short": "std::int16_t", "unsigned short": "std::uint16_t", "int": "int", "unsigned int": "unsigned int",
    "long": "std::int64_t", "unsigned long": "std::uint64_t", "long long": "std::int64_t", "unsigned long long": "std::uint64_t",
    "float": "float", "double": "double", "wchar_t": "wchar_t", "char16_t": "char16_t", "char32_t": "char32_t",
}

MANUAL_STRUCTS = {"CGPoint": "Point", "CGSize": "Size", "CGRect": "Rect", "NSEdgeInsets": "Insets"}


class Unmappable(Exception):
    pass


class TI:
    def __init__(self, cpp, param, to, frm, objc, kind, inner=None, key=None, key_ti=None, value_ti=None, sig=None):
        self.cpp = cpp
        self.param = param
        self.to = to
        self.frm = frm
        self.objc = objc
        self.kind = kind
        self.inner = inner
        self.sig = sig
        self.const = False
        self.typed = False
        self.tcpp = None
        self.tparam_param = None
        self.box_in = None
        self.box_out = None

    def conv_to(self, expr):
        return self.to.replace("@@", expr)

    def conv_from(self, expr):
        return self.frm.replace("@@", expr)


class State:
    def __init__(self):
        self.classes = {}
        self.queue = []
        self.allow_new = True
        self.refs = set()
        self.enums = {}
        self.structs = {}
        self.opaques = {}
        self.names = set()
        self.enum_renames = {}
        self.enum_prefixes = {}
        self.class_names = {}
        self.manual_enums = {}
        self.skipped = []
        self.current_tparams = set()
        self.block_counter = 0


S = State()


def clean(t):
    t = re.sub(r"\b(API|NS)_[A-Z_]+\b(\([^)]*\))?", "", t)
    t = re.sub(r"_Nullable_result|_Nullable|_Nonnull|_Null_unspecified|__strong|__weak|__unsafe_unretained|__autoreleasing|__kindof|__unused|__attribute__\(\([^)]*\)\)", "", t)
    t = re.sub(r"<\s+", "<", re.sub(r"\s+>", ">", t))
    t = re.sub(r"\(\^\s+", "(^", t)
    t = re.sub(r"\(\*\s+\)", "(*)", t)
    t = re.sub(r"\s+\*", " *", re.sub(r"\s+", " ", t)).strip()
    t = re.sub(r"\bconst\b", "", t)
    t = re.sub(r"\s+", " ", t).strip()
    t = re.sub(r"\*\s+\*", "**", t)
    return t


def snake(name):
    name = re.sub(r"([A-Z])([A-Z]+)s\b", lambda m: m.group(1) + m.group(2).lower() + "s", name)
    name = re.sub(r"([A-Z]+)([A-Z][a-z])", r"\1_\2", name)
    name = re.sub(r"([a-z0-9])([A-Z])", r"\1_\2", name)
    return name.lower()


def ident(name):
    if name[:1].isdigit():
        return "n" + name
    if name in RESERVED:
        return name + "_"
    if not name:
        return "arg"
    return name


def class_cpp_name(ns):
    if ns in S.class_names:
        return S.class_names[ns]
    if ns.startswith("NS") and len(ns) > 2 and ns[2].isupper():
        return ns[2:]
    return ns


def has_interface(name):
    for node in A.dump(name):
        if node["kind"] == "ObjCInterfaceDecl" and node.get("name") == name and node.get("super") is not None and node.get("inner") is not None:
            return True
    for node in A.dump(name):
        if node["kind"] == "ObjCInterfaceDecl" and node.get("name") == name and node.get("inner"):
            return True
    return False


def typedef_underlying(name):
    for node in A.dump(name):
        if node["kind"] == "TypedefDecl" and node.get("name") == name:
            t = node["type"]
            return t.get("desugaredQualType") or t["qualType"]
    return None


def split_top(text):
    parts, depth, current = [], 0, ""
    for ch in text:
        if ch in "<([":
            depth += 1
        elif ch in ">)]":
            depth -= 1
        if ch == "," and depth == 0:
            parts.append(current.strip())
            current = ""
        else:
            current += ch
    if current.strip():
        parts.append(current.strip())
    return parts


def unique_type_name(base, suffix="Enum"):
    name = base
    n = 2
    while name in S.names:
        name = f"{base}{suffix if n == 2 else n}"
        n += 1
    S.names.add(name)
    return name


def enum_cpp_name(ns):
    if ns in S.enums:
        return S.enums[ns]["name"]
    base = S.enum_renames.get(ns, ns[2:] if ns.startswith("NS") else ns)
    return base


def load_enum(ns):
    if ns in S.enums:
        return S.enums[ns]
    for node in A.dump(ns):
        if node["kind"] == "EnumDecl" and node.get("name") == ns and any(c["kind"] == "EnumConstantDecl" for c in node.get("inner", [])):
            fixed = node.get("fixedUnderlyingType", {"qualType": "int"})
            underlying = clean(fixed.get("desugaredQualType", fixed["qualType"]))
            cpp_under = {"long": "std::int64_t", "unsigned long": "std::uint64_t", "int": "std::int32_t", "unsigned int": "std::uint32_t",
                         "long long": "std::int64_t", "unsigned long long": "std::uint64_t", "short": "std::int16_t", "unsigned short": "std::uint16_t",
                         "char": "std::int8_t", "unsigned char": "std::uint8_t"}.get(underlying, "std::int64_t")
            constants = []
            previous = -1
            for constant in node["inner"]:
                if constant["kind"] != "EnumConstantDecl":
                    continue
                attrs = A.availability(constant)
                found = None
                stack = list(constant.get("inner", []))
                while stack:
                    current = stack.pop()
                    if current["kind"] == "ConstantExpr":
                        found = int(current["value"])
                        break
                    stack.extend(current.get("inner", []))
                value = previous + 1 if found is None else found
                previous = value
                constants.append((constant["name"], value, attrs.unavailable))
            names = [c[0] for c in constants if not c[2]]
            prefix = S.enum_prefixes.get(ns, ns)
            starting = [n for n in names if n.startswith(prefix) and len(n) > len(prefix)]
            if len(starting) * 2 < len(names):
                common = names[0] if names else ""
                for n in names:
                    i = 0
                    while i < len(common) and i < len(n) and common[i] == n[i]:
                        i += 1
                    common = common[:i]
                while common and not (len(common) < len(names[0]) and names[0][len(common)].isupper()):
                    common = common[:-1]
                prefix = common if len(common) > 2 else "NS"
            values = []
            seen = set()
            for cname, value, unavailable in constants:
                if unavailable:
                    continue
                short = cname[len(prefix):] if cname.startswith(prefix) and len(cname) > len(prefix) else re.sub(r"^NS", "", cname)
                if not short or short[0].isdigit():
                    short = "_" + short
                if short in RESERVED or short in {"NULL", "None_"}:
                    short = short + "_"
                base, n = short, 2
                while short in seen:
                    short = f"{base}{n}"
                    n += 1
                seen.add(short)
                values.append((short, value))
            S.enums[ns] = {
                "ns": ns,
                "name": unique_type_name(enum_cpp_name(ns)),
                "underlying": cpp_under,
                "flags": any(c["kind"] == "FlagEnumAttr" for c in node["inner"]),
                "values": values,
                "since": A.availability(node).introduced,
            }
            return S.enums[ns]
    raise Unmappable(f"enum {ns} not found")


def load_struct(tag, ctype):
    unnamed = "unnamed" in tag or "anonymous" in tag
    key = ctype if unnamed else tag
    if key in S.structs:
        return S.structs[key]
    name = MANUAL_STRUCTS.get(tag)
    if name:
        S.structs[key] = {"tag": tag, "name": name, "ctype": ctype, "fields": None, "manual": True, "blob": None}
        return S.structs[key]
    lookup = ctype if unnamed else tag
    definition = None
    for node in A.dump(lookup):
        if node["kind"] == "RecordDecl" and node.get("completeDefinition") and (unnamed or node.get("name") == tag):
            definition = node
            break
    blob_only = definition is None and unnamed
    if definition is None and not unnamed:
        raise Unmappable(f"struct {tag} has no definition")
    fields = []
    plain = definition is not None and definition.get("tagUsed") != "union"
    if plain:
        S.structs[key] = {"tag": tag, "name": None, "ctype": ctype, "fields": [], "manual": False, "blob": None}
        try:
            for field in definition["inner"]:
                if field["kind"] != "FieldDecl" or field.get("isBitfield"):
                    raise Unmappable("not plain")
                ft = field["type"]
                ti = typeinfo(ft["qualType"], hint=ft.get("desugaredQualType"))
                if ti.kind not in ("prim", "enum", "struct"):
                    raise Unmappable("not plain")
                fields.append((field["name"], ti))
        except Unmappable:
            plain = False
            del S.structs[key]
    cpp = re.sub(r"^(NS|CG)", "", (spelled_name(ctype) if unnamed else tag).lstrip("_"))
    if plain:
        S.structs[key] = {"tag": tag, "name": unique_type_name(cpp, "Struct"), "ctype": ctype, "fields": fields, "manual": False, "blob": None}
        return S.structs[key]
    size = A.layout(ctype)
    if size is None:
        raise Unmappable(f"struct {tag} layout unknown")
    S.structs[key] = {"tag": tag, "name": unique_type_name(cpp, "Struct"), "ctype": ctype, "fields": [], "manual": False, "blob": size}
    return S.structs[key]


def spelled_name(ctype):
    return ctype.replace("struct ", "").strip()


class ClassModel:
    def __init__(self, ns, name, tier):
        self.ns = ns
        self.name = name
        self.tier = tier
        self.since = None
        self.curated = {}
        self.alias = False
        self.base_ns = None
        self.base_name = "Object"
        self.interface = None
        self.members = []
        self.ctors = []
        self.signals = []
        self.delegates = []
        self.refs = set()
        self.init_available = True
        self.own_init = False
        self.delegate_props = {}
        self.delegate_majors = {}
        self.weak_unavailable = False
        self.tparams = []
        self.template_name = None
        self.has_action = False
        self.has_others = False
        self.all_names = set()


def ensure_class(ns):
    if ns in S.classes:
        return S.classes[ns]
    if not S.allow_new:
        raise Unmappable(f"class {ns} not available")
    if not has_interface(ns):
        raise Unmappable(f"class {ns} not defined")
    if ns == "NSProxy":
        raise Unmappable("NSProxy is a root class")
    for node in A.dump(ns):
        if node["kind"] == "ObjCInterfaceDecl" and node.get("name") == ns and node.get("super", {}).get("name") == "NSProxy":
            raise Unmappable("NSProxy subclass")
    tparams = []
    for node in A.dump(ns):
        if node["kind"] == "ObjCInterfaceDecl" and node.get("name") == ns and node.get("inner"):
            tparams = [c["name"] for c in node["inner"] if c["kind"] == "ObjCTypeParamDecl"]
            if tparams:
                break
    base_cpp = class_cpp_name(ns)
    model = ClassModel(ns, unique_type_name(base_cpp + "Base" if tparams else base_cpp), "B")
    model.tparams = tparams
    model.template_name = base_cpp if tparams else None
    S.classes[ns] = model
    S.queue.append(ns)
    return model


def gq(name):
    if re.fullmatch(r"[A-Za-z_]\w*", name) and name not in BUILTINS and name not in ("id", "Class", "SEL"):
        return "::" + name
    return name


def numeric(spelled, cpp):
    return TI(cpp, cpp, f"static_cast<{gq(spelled)}>(@@)", f"static_cast<{cpp}>(@@)", gq(spelled), "prim")


def string_ti():
    return TI("std::string", "const std::string&", "cocoon::internal::to(@@)", "cocoon::internal::from(@@)", "NSString *", "string")


def object_ti():
    return TI("Object", "const Object&", "cocoon::internal::native_id(@@)", "cocoon::internal::wrap<Object>(@@)", "id", "object")


def parse_block(s):
    index = s.index("(^")
    ret = s[:index].strip()
    close = s.index(")", index)
    rest = s[close + 1:].strip()
    if not rest.startswith("(") or not rest.endswith(")"):
        raise Unmappable("odd block")
    params = split_top(rest[1:-1])
    if params == ["void"]:
        params = []
    return ret, params


C_KEYWORDS = {"const", "volatile", "struct", "enum", "union", "unsigned", "signed", "long", "short", "int", "char", "float", "double", "void", "bool", "_Bool", "id", "Class", "SEL", "BOOL", "__kindof", "restrict"}


def qualify_c_type(text):
    result, depth, i = "", 0, 0
    while i < len(text):
        ch = text[i]
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth -= 1
        m = re.match(r"[A-Za-z_]\w*", text[i:]) if (ch.isalpha() or ch == "_") and (i == 0 or not (text[i - 1].isalnum() or text[i - 1] in "_:")) else None
        if m:
            word = m.group(0)
            followed_by_generic = text[i + len(word):i + len(word) + 1] == "<"
            result += word if depth > 0 or followed_by_generic or word in C_KEYWORDS or word.startswith("__") else "::" + word
            i += len(word)
            continue
        result += ch
        i += 1
    return result


def clean_cast(q):
    text = re.sub(r"\b(API|NS)_[A-Z_]+\b(\([^)]*\))?", "", q)
    text = re.sub(r"_Nullable_result|_Nullable|_Nonnull|_Null_unspecified|__strong|__weak|__unsafe_unretained|__autoreleasing", "", text)
    for name in S.current_tparams:
        text = re.sub(r"\b" + re.escape(name) + r"\b", "id", text)
    return qualify_c_type(re.sub(r"\s+", " ", text).strip())


def block_ti(s, cast=None):
    S.block_counter += 1
    uid = S.block_counter
    cast = cast or s
    for name in S.current_tparams:
        s = re.sub(r"\b" + re.escape(name) + r"\b", "id", s)
    ret_s, param_s = parse_block(s)
    ret = typeinfo(ret_s)
    params = [typeinfo(p) for p in param_s]
    params = [(TI(p.inner.cpp, f"{p.inner.cpp}&", "", "", p.objc, "out", inner=p.inner) if p.kind == "ptr" and p.inner.kind in ("prim", "enum", "struct") and not p.cpp.startswith("const ") else p) for p in params]
    for p in params:
        if p.kind in ("error", "void", "objout"):
            raise Unmappable("block param kind")
    if ret.kind in ("out", "error", "objout"):
        raise Unmappable("block return kind")
    cpp_types = [f"{p.cpp}&" if p.kind == "out" else p.cpp for p in params]
    sig = f"{ret.cpp}({', '.join(cpp_types)})"
    objc_ret = ret.objc if ret.kind != "void" else "void"
    objc_params = ", ".join((f"{p.objc} a{uid}_{i}" if p.kind != "out" else f"{p.inner.objc} *a{uid}_{i}") for i, p in enumerate(params))
    to_pre, to_post, to_args = [], [], []
    for i, p in enumerate(params):
        if p.kind == "out":
            to_pre.append(f"{p.cpp} __o{uid}_{i} = a{uid}_{i} ? {p.inner.conv_from('*a' + str(uid) + '_' + str(i))} : {p.cpp}();")
            to_post.append(f"if (a{uid}_{i}) {{ *a{uid}_{i} = {p.inner.conv_to('__o' + str(uid) + '_' + str(i))}; }}")
            to_args.append(f"__o{uid}_{i}")
        else:
            to_args.append(p.conv_from(f"a{uid}_{i}"))
    call = f"@@({', '.join(to_args)})"
    if ret.kind == "void":
        to_body = " ".join(to_pre + [call + ";"] + to_post)
    else:
        to_body = " ".join(to_pre + [f"auto __r = {call};"] + to_post + [f"return {ret.conv_to('__r')};"])
    to = f"(@@ ? ({cast})^{objc_ret}({objc_params}) {{ {to_body} }} : ({cast})nil)"
    cpp_params = ", ".join(f"{t} a{uid}_{i}" for i, t in enumerate(cpp_types))
    from_pre, from_post, from_args = [], [], []
    for i, p in enumerate(params):
        if p.kind == "out":
            from_pre.append(f"{p.inner.objc} __o{uid}_{i} = {p.inner.conv_to('a' + str(uid) + '_' + str(i))};")
            from_post.append(f"a{uid}_{i} = {p.inner.conv_from('__o' + str(uid) + '_' + str(i))};")
            from_args.append(f"&__o{uid}_{i}")
        else:
            from_args.append(p.conv_to(f"a{uid}_{i}"))
    block_call = f"blk({', '.join(from_args)})"
    if ret.kind == "void":
        from_body = " ".join(from_pre + [block_call + ";"] + from_post)
    else:
        from_body = " ".join(from_pre + [f"auto __r = {block_call};"] + from_post + [f"return {ret.conv_from('__r')};"])
    frm = (f"[&]() -> std::function<{sig}> {{ auto blk = ({cast})(@@); if (!blk) {{ return {{}}; }} "
           f"return [blk]({cpp_params}) -> {ret.cpp} {{ {from_body} }}; }}()")
    return TI(f"std::function<{sig}>", f"std::function<{sig}>", to, frm, "id", "block", sig=sig)


def container_ti(name, generic):
    element = typeinfo(generic) if generic else object_ti()
    if element.kind in ("void", "out", "error"):
        raise Unmappable("container element")
    elem_param = f"const {element.cpp}&"
    to_array = (f"cocoon::internal::to_array(@@, [](const {element.cpp}& e) -> id {{ return {element.conv_to('e')}; }})")
    from_array = (f"cocoon::internal::from_array<{element.cpp}>(@@, [](id e) -> {element.cpp} {{ return {element.conv_from('(' + element.objc + ')e' if element.objc.endswith('*') else 'e')}; }})")
    cpp = f"std::vector<{element.cpp}>"
    if name in ("NSArray", "NSMutableArray"):
        result = TI(cpp, f"const {cpp}&", to_array, from_array, "NSArray *", "vector", inner=element)
        if element.typed:
            result.typed = True
            result.tcpp = f"std::vector<{element.tcpp}>"
            result.tparam_param = f"const std::vector<{element.tcpp}>&"
            result.box_in = "cocoon::box_all(@@)"
            result.box_out = f"cocoon::unbox_all<{element.tcpp}>(@@)"
        return result
    if name in ("NSSet", "NSMutableSet"):
        return TI(cpp, f"const {cpp}&", f"[NSSet setWithArray:{to_array}]", from_array.replace("@@", "[@@ allObjects]"), "NSSet *", "vector", inner=element)
    return TI(cpp, f"const {cpp}&", f"[NSOrderedSet orderedSetWithArray:{to_array}]", from_array.replace("@@", "[@@ array]"), "NSOrderedSet *", "vector", inner=element)


def dictionary_ti(generic):
    args = split_top(generic) if generic else []
    key = typeinfo(args[0]) if len(args) == 2 else object_ti()
    value = typeinfo(args[1]) if len(args) == 2 else object_ti()
    for t in (key, value):
        if t.kind in ("void", "out", "error", "block"):
            raise Unmappable("dictionary element")
    cpp = f"std::map<std::string, {value.cpp}>" if key.kind == "string" else f"std::vector<std::pair<{key.cpp}, {value.cpp}>>"
    to = (f"cocoon::internal::to_dictionary(@@, [](const {key.cpp}& k) -> id {{ return {key.conv_to('k')}; }}, "
          f"[](const {value.cpp}& v) -> id {{ return {value.conv_to('v')}; }})")
    kfrom = key.conv_from("(" + key.objc + ")k" if key.objc.endswith("*") else "k")
    vfrom = value.conv_from("(" + value.objc + ")v" if value.objc.endswith("*") else "v")
    frm = f"cocoon::internal::from_dictionary<{cpp}>(@@, [](id k) -> {key.cpp} {{ return {kfrom}; }}, [](id v) -> {value.cpp} {{ return {vfrom}; }})"
    return TI(cpp, f"const {cpp}&", to, frm, "NSDictionary *", "map")


def raw_pointer(inner, is_const):
    const = "const " if is_const else ""
    return TI(f"{const}{inner.cpp}*", f"{const}{inner.cpp}*", f"({const}{inner.objc}*)(@@)", f"({const}{inner.cpp}*)(@@)",
              f"{const}{inner.objc} *", "ptr", inner=inner)


def protocol_qualified(q):
    match = re.search(r"\w\s*<([^<>*]*)>\s*\*", q)
    if not match:
        return False
    names = [n.strip() for n in match.group(1).split(",")]
    return all(re.fullmatch(r"[A-Za-z_]\w*", n) and n != "id" and n not in S.current_tparams for n in names)


def with_cast(ti, q):
    if ti.kind in ("ptr", "fnptr"):
        cast = clean_cast(q)
        ti.to = f"({cast})(@@)"
    elif ti.kind == "data" and "NSMutableData" in q:
        ti.to = "cocoon::internal::to_mutable_data(@@)"
    elif ti.kind == "handle" and protocol_qualified(q):
        ti.to = f"cocoon::internal::native<{clean_cast(q).rstrip(' *')}>(@@)"
    elif ti.kind in ("string", "vector", "map") and re.match(r"\s*(?:const\s+)?NSMutable(String|Array|Dictionary|Set|OrderedSet)\b", q):
        ti.to = f"[{ti.to} mutableCopy]"
    return ti


def pointer_ti(base, spelled, is_const=False):
    if base == "char":
        if is_const:
            return TI("std::string", "const std::string&", "@@.c_str()", "cocoon::internal::from(@@)", "const char *", "string")
        return TI("char*", "char*", "@@", "@@", "char *", "ptr", inner=numeric("char", "std::int8_t"))
    if base in ("void", ""):
        if is_const:
            return TI("const void*", "const void*", "@@", "@@", "const void *", "prim")
        return TI("void*", "void*", "@@", "@@", "void *", "prim")
    if base.endswith("*"):
        inner = base[:-1].strip()
        if inner == "NSError":
            return TI("", "", "", "", "NSError **", "error")
        try:
            object_ti_inner = typeinfo(base)
        except Unmappable:
            object_ti_inner = None
        if object_ti_inner is not None and object_ti_inner.kind in ("string", "handle", "object", "vector", "map", "data", "opaque"):
            return TI(f"{object_ti_inner.cpp}&", f"{object_ti_inner.cpp}&", "", "", f"{object_ti_inner.objc} *", "objout", inner=object_ti_inner)
        inner_ti = pointer_ti(inner, None, False)
        if inner_ti.kind not in ("ptr", "prim"):
            raise Unmappable(f"pointer to pointer {base}")
        return raw_pointer(inner_ti, is_const)
    match = re.fullmatch(r"([A-Za-z_]\w*)\s*(?:<(.*)>)?", base)
    if match:
        name, generic = match.group(1), match.group(2)
        if name in ("NSString", "NSMutableString"):
            return string_ti()
        if name in ("NSArray", "NSMutableArray", "NSSet", "NSMutableSet", "NSOrderedSet", "NSMutableOrderedSet"):
            return container_ti(name, generic)
        if name in ("NSDictionary", "NSMutableDictionary"):
            return dictionary_ti(generic)
        if name in ("NSData", "NSMutableData"):
            return TI("std::vector<std::uint8_t>", "const std::vector<std::uint8_t>&", "cocoon::internal::to_data(@@)", "cocoon::internal::from_data(@@)", "NSData *", "data")
        if name == "NSObject":
            return object_ti()
        if name in S.classes or (has_interface(name) and typedef_underlying(name) is None):
            model = ensure_class(name)
            S.refs.add(model.name)
            return TI(model.name, f"const {model.name}&", f"cocoon::internal::native<::{name}>(@@)", f"cocoon::internal::wrap<{model.name}>(@@)", f"::{name} *", "handle")
        if has_forward_only(name):
            return object_ti()
    if base.startswith("struct ") or base.startswith("union "):
        raise Unmappable(f"raw struct pointer {base}")
    inner = typeinfo(base)
    if inner.kind not in ("prim", "enum", "struct", "ptr"):
        raise Unmappable(f"pointer to {inner.kind}")
    return raw_pointer(inner, is_const)


def function_pointer_ti(s):
    index = s.index("(*)")
    ret_s = s[:index].strip()
    rest = s[index + 3:].strip()
    if not (rest.startswith("(") and rest.endswith(")")):
        raise Unmappable("odd function pointer")
    params = split_top(rest[1:-1])
    if params == ["void"]:
        params = []

    def c_compatible(type_s):
        ti = typeinfo(type_s)
        if ti.kind in ("prim", "enum", "void", "ptr", "fnptr"):
            return ti.cpp
        if ti.kind in ("handle", "object", "opaque", "string", "data", "vector", "map"):
            return "void*"
        raise Unmappable("function pointer type " + type_s)

    cpp = f"{c_compatible(ret_s)}(*)({', '.join(c_compatible(p) for p in params)})"
    return TI(cpp, cpp, f"({s})(@@)", f"({cpp})(@@)", s, "fnptr")


def has_forward_only(name):
    for node in A.dump(name):
        if node["kind"] == "ObjCInterfaceDecl" and node.get("name") == name:
            return True
    return False


def typeinfo(q, ctx=None, hint=None, spelled=None):
    return with_cast(_typeinfo(q, ctx, hint, spelled), q)


def _typeinfo(q, ctx=None, hint=None, spelled=None):
    s = clean(q)
    if "(^" in s:
        if spelled and re.fullmatch(r"[A-Za-z_]\w*", spelled):
            cast = gq(spelled)
        else:
            cast = clean_cast(q)
        return block_ti(s, cast)
    if "(*)" in s:
        return function_pointer_ti(s)
    if s == "void":
        return TI("void", "void", "", "", "void", "void")
    if s == "instancetype":
        if ctx is None:
            raise Unmappable("instancetype without class")
        model = S.classes[ctx]
        S.refs.add(model.name)
        return TI(model.name, f"const {model.name}&", f"cocoon::internal::native<::{ctx}>(@@)", f"cocoon::internal::wrap<{model.name}>(@@)", f"::{ctx} *", "handle")
    if s == "id" or s.startswith("id<"):
        return object_ti()
    if s == "Class":
        return TI("std::string", "const std::string&", "NSClassFromString(cocoon::internal::to(@@))", "cocoon::internal::from(NSStringFromClass(@@))", "Class", "string")
    if re.fullmatch(r"Class<[\w, ]+>", s):
        return TI("std::string", "const std::string&", "NSClassFromString(cocoon::internal::to(@@))", "cocoon::internal::from(NSStringFromClass(@@))", "Class", "string")
    if s == "SEL":
        return TI("std::string", "const std::string&", "NSSelectorFromString(cocoon::internal::to(@@))", "cocoon::internal::from(NSStringFromSelector(@@))", "SEL", "string")
    if s.endswith("*"):
        base = s[:-1].strip()
        if spelled and base.startswith("struct "):
            tag = base[7:].strip()
            if any(n["kind"] == "RecordDecl" and n.get("name") == tag and n.get("completeDefinition") for n in A.dump(tag)):
                raise Unmappable(f"pointer to defined struct {tag}")
            name = re.sub(r"^NS", "", re.sub(r"Ref$", "", spelled))
            S.opaques[name] = spelled
            S.refs.add(name)
            return TI(name, f"const {name}&", f"((::{spelled})(@@).handle())", f"cocoon::internal::wrap_cf<{name}>((const void*)(@@))", f"::{spelled}", "opaque")
        is_const = bool(re.search(r"\bconst\b[^*]*\*\s*(_Nullable|_Nonnull|__strong)?\s*$", q)) and not re.search(r"\*\s*const\s*$", q)
        return pointer_ti(base, spelled, is_const)
    if s in BUILTINS:
        return numeric(spelled or s, BUILTINS[s])
    if s.startswith("enum "):
        tag = s[5:].strip()
        if "unnamed" in tag or "anonymous" in tag:
            return numeric(spelled or "int", "int")
        enum = load_enum(tag)
        return TI(enum["name"], enum["name"], f"static_cast<{gq(spelled or tag)}>(@@)", f"static_cast<{enum['name']}>(@@)", gq(spelled or tag), "enum")
    if s.startswith("struct "):
        tag = s[7:].strip()
        struct = load_struct(tag, spelled or s)
        return TI(struct["name"], f"const {struct['name']}&", "cocoon::internal::to(@@)", "cocoon::internal::from(@@)", gq(spelled or s) if spelled else s, "struct")
    if s.startswith("union "):
        raise Unmappable("union")
    if re.fullmatch(r"[A-Za-z_]\w*", s):
        if s in S.current_tparams:
            ti = TI("Object", "const Object&", "cocoon::internal::native_id(@@)", "cocoon::internal::wrap<Object>(@@)", "id", "object")
            ti.typed = True
            ti.tcpp = s
            ti.tparam_param = f"const {s}&"
            ti.box_in = "cocoon::box(@@)"
            ti.box_out = f"cocoon::unbox<{s}>(@@)"
            return ti
        if s in S.manual_enums:
            e = S.manual_enums[s]
            return TI(e["name"], e["name"], f"static_cast<{s}>(@@)", f"static_cast<{e['name']}>(@@)", s, "enum")
        d = hint if hint and clean(hint) != s else typedef_underlying(s)
        if d is None:
            raise Unmappable(f"unknown type {s}")
        d = clean(d)
        if d == s:
            struct = load_struct("(unnamed)", s)
            return TI(struct["name"], f"const {struct['name']}&", "cocoon::internal::to(@@)", "cocoon::internal::from(@@)", s, "struct")
        result = typeinfo(d, ctx, None, spelled or s)
        return result
    raise Unmappable(f"unmapped type {s}")
