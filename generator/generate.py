#!/usr/bin/env python3
import collections
import pathlib
import re
import shutil
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "generator"))

import astdump as A
import typemap as T
from spec import SPEC
from typemap import S, TI, Unmappable, ClassModel, clean, ident, snake, typeinfo, ensure_class, unique_type_name, class_cpp_name

A.configure(SPEC["deploymentTarget"])
MAJOR = int(SPEC["deploymentTarget"].split(".")[0])
OUT_INCLUDE = ROOT / "include" / "generated"
OUT_SRC = ROOT / "src" / "generated"

S.enum_renames = SPEC.get("renames", {})
S.enum_prefixes = SPEC.get("enumPrefixes", {})
S.manual_enums = {e["ns"]: e for e in SPEC.get("enums", [])}
S.class_names = SPEC.get("classNames", {})
SIGNAL_OVERRIDES = SPEC.get("signalOverrides", {})
SKIP_CLASSES = set(SPEC.get("skipClasses", [])) | {"NSProxy"}
SKIP_SELECTORS = {"alloc", "allocWithZone:", "new", "copyWithZone:", "mutableCopyWithZone:", "dealloc", "retain", "release", "autorelease", "retainCount", "zone", "class", "superclass", "self", "load", "initialize"}
SKIP_SELECTORS_STATIC = {"alloc", "allocWithZone:", "new", "load", "initialize", "class", "superclass", "instanceMethodForSelector:", "supportsSecureCoding", "copyWithZone:"}

ALL_MODELS = []
BY_NAME = {}
SKIPPED = collections.defaultdict(list)
SIGNAL_TABLE = {}
QUALIFIER = None


class Skip(Exception):
    pass


CALL = re.compile(r"\b([a-z][a-zA-Z0-9]*[A-Z][a-zA-Z0-9]*)(?=\s*\()")
WRITTEN = []


def sname(name):
    return ident(snake(name))


def convert_cpp(text):
    return CALL.sub(lambda m: snake(m.group(1)), text)


def rename_word(text, old, new):
    return re.sub(r"(?<![\w.>])(?<!::)" + re.escape(old) + r"\b(?!:)", new, text)


def param_names(decl_text):
    start = decl_text.index("(")
    depth, end = 0, start
    for i in range(start, len(decl_text)):
        if decl_text[i] == "(":
            depth += 1
        elif decl_text[i] == ")":
            depth -= 1
            if depth == 0:
                end = i
                break
    names = []
    for p in T.split_top(decl_text[start + 1:end]):
        m = re.search(r"(\w+)\s*(?:=.*)?$", p)
        if m:
            names.append(m.group(1))
    return names


def convert_extra(decl, impl):
    for name in param_names(decl):
        if snake(name) != name:
            decl = rename_word(decl, name, snake(name))
            impl = rename_word(impl, name, snake(name))
    return convert_cpp(decl), convert_cpp(impl)


def write(path, text):
    path.write_text(text)
    WRITTEN.append(path)


class Member:
    def __init__(self, name, ret, cpp_params, lines, key, static):
        self.name = name
        self.ret = ret
        self.cpp_params = cpp_params
        self.lines = lines
        self.key = key
        self.arity = len(cpp_params)
        self.static = static
        self.extra_decl = ""
        self.typed = None
        self.since = None
        self.selector = ""
        self.prop = None
        self.role = "method"
        self.sdk_doc = ""

    def render_typed(self, base_name, name):
        t = self.typed
        decl_params = ", ".join(declare(ty, n) for ty, n, _ in t["params"])
        args = ", ".join((conv.replace("@@", n) if conv else n) for _, n, conv in t["params"])
        const = "" if self.static else " const"
        prefix = "static " if self.static else ""
        call = f"{base_name}::{name}({args})"
        if t["void"]:
            body = f"{call};"
        else:
            body = f"return {t['ret_out'].replace('@@', call) if t['ret_out'] else call};"
        return f"        {prefix}auto {name}({decl_params}){const} {{ {body} }}"

    def render(self, class_name, name):
        decl_params = ", ".join(declare(t, n) for t, n in self.cpp_params)
        const = "" if self.static else " const"
        prefix = "static " if self.static else ""
        if "(*)" in self.ret:
            decl = f"    {prefix}auto {name}({decl_params}){const} -> {self.ret};"
            impl = f"auto {class_name}::{name}({decl_params}){const} -> {self.ret} {{\n" + "\n".join(self.lines) + "\n}\n"
        else:
            decl = f"    {prefix}{self.ret} {name}({decl_params}){const};"
            impl = f"{self.ret} {class_name}::{name}({decl_params}){const} {{\n" + "\n".join(self.lines) + "\n}\n"
        return decl, impl


def declare(type_text, name):
    if "(*)" in type_text:
        return type_text.replace("(*)", f"(*{name})", 1)
    return f"{type_text} {name}"


def norm_type(t):
    return re.sub(r"\s+", "", t.replace("const ", "").replace("&", ""))


def chain_of(model):
    result = [model]
    while model.base_name != "Object":
        model = BY_NAME[model.base_name]
        result.insert(0, model)
    return result


FUTURE_MAJORS = set()


def future_major(since):
    if since and int(since) > MAJOR:
        FUTURE_MAJORS.add(int(since))
        return int(since)
    return 0


_FUTURE_CACHE = {}


def future_types():
    key = (len(ALL_MODELS), len(S.enums))
    if _FUTURE_CACHE.get("key") != key:
        result = {}
        for m in ALL_MODELS:
            major = future_major(m.since)
            if major:
                result[m.name] = result[m.ns] = major
        for ns, e in S.enums.items():
            major = future_major(e.get("since"))
            if major:
                result[e["name"]] = result[ns] = major
        _FUTURE_CACHE["key"] = key
        _FUTURE_CACHE["value"] = result
    return _FUTURE_CACHE["value"]


def taint(text):
    return max([0] + [v for k, v in future_types().items() if re.search(r"\b" + re.escape(k) + r"\b", text)])


def macro_guard(major, text):
    if not major:
        return text
    return f"#ifdef COCOON_MACOS_{major}\n{text}\n#endif"


def guard_lines(lines, since, void, ret=None):
    if since and since > MAJOR:
        body = ["    " + line for line in lines]
        fallback = [] if void else [f"    return {ret.cpp}(nullptr);" if ret is not None and ret.kind in ("handle", "opaque", "object") else "    return {};"]
        return [f"    if (@available(macOS {since}, *)) {{"] + body + ["    }"] + fallback
    return lines


def parm_list(decl, to_snake=True):
    result = []
    used = []
    for i, p in enumerate(x for x in decl.get("inner", []) if x["kind"] == "ParmVarDecl"):
        raw = p.get("name") or f"arg{i}"
        name = ident(snake(raw) if to_snake else raw)
        if name[:1].isupper():
            name += "_"
        while name in used:
            name += "_"
        used.append(name)
        noescape = any(c.get("kind") == "NoEscapeAttr" for c in p.get("inner", []))
        result.append((name, {**p["type"], "noescape": True} if noescape else p["type"]))
    return result


def signature_type(t):
    q = t["qualType"]
    text = clean(q)
    if t.get("noescape"):
        text = text.replace("(^", "(NS_NOESCAPE ^", 1)
    if re.match(r"\s*const\b", q) and text.endswith("*") and not text.startswith("const"):
        return "const " + text
    return text


def log_skip(model, what, reason):
    key = "unmapped " + reason.split("unmapped", 1)[1].strip().split(" ")[0] if "unmapped" in reason else reason
    SKIPPED[key].append(f"{model.ns}.{what}")


def make_body(model, static, selector, params, ret_type, since):
    infos = [typeinfo(t["qualType"], model.ns, t.get("desugaredQualType")) for _, t in params]
    ret = typeinfo(ret_type["qualType"], model.ns, ret_type.get("desugaredQualType"))
    if ret.kind in ("out", "error"):
        raise Skip("odd return")
    cpp_params, pre, post, args = [], [], [], []
    needs_error = False
    for (name, _), ti in zip(params, infos):
        if ti.kind == "error":
            args.append("&__error")
            needs_error = True
            continue
        if ti.kind == "objout":
            cpp_params.append((ti.cpp, name))
            pre.append(f"{ti.inner.objc} __v_{name} = nil;")
            args.append(f"&__v_{name}")
            post.append(f"{name} = {ti.inner.conv_from('__v_' + name)};")
            continue
        cpp_params.append((ti.param, name))
        args.append(ti.conv_to(name))
    parts = selector.split(":")
    segments = " ".join(f"{parts[i]}:{args[i]}" for i in range(len(params))) if params else selector
    target = f"::{model.ns}" if static else f"cocoon::internal::ns<::{model.ns}>(this)"
    call = f"[{target} {segments}]"
    if needs_error:
        pre.insert(0, "NSError* __error = nil;")
    err = ["if (__error) {", "    throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));", "}"] if needs_error else []
    if ret.kind == "void":
        lines = ["    " + l for l in pre + [call + ";"] + post + err]
    elif pre or post or needs_error:
        lines = ["    " + l for l in pre + [f"auto __r = {call};"] + post + err + [f"return {ret.conv_from('__r')};"]]
    else:
        lines = [f"    return {ret.conv_from(call)};"]
    typed = None
    if (ret.typed or any(i.typed for i in infos)) and not any(i.kind in ("error", "objout") for i in infos):
        typed = {"ret": ret.tcpp if ret.typed else ret.cpp, "ret_out": ret.box_out if ret.typed else None, "void": ret.kind == "void",
                 "params": [((i.tparam_param if i.typed else i.param), n, (i.box_in if i.typed else None)) for (n, _), i in zip(params, infos)]}
    make_body.last_typed = typed
    return ret, cpp_params, guard_lines(lines, since, ret.kind == "void", ret)


def make_member(model, selector, params, ret_type, static, since, cpp_name):
    ret, cpp_params, lines = make_body(model, static, selector, params, ret_type, since)
    key = (static, cpp_name, tuple(norm_type(t) for t, _ in cpp_params))
    member = Member(cpp_name, ret.cpp, cpp_params, lines, key, static)
    member.since = since
    member.typed = make_body.last_typed
    member.selector = selector
    return member


def variadic_member(model, decl, static, methods, info):
    selector = decl["name"]
    sibling = methods.get((not static, selector + "arguments:"))
    if sibling is None:
        raise Skip("variadic without va_list sibling")
    params = parm_list(decl)
    infos = [typeinfo(t["qualType"], model.ns, t.get("desugaredQualType")) for _, t in params]
    ret = typeinfo(decl["returnType"]["qualType"], model.ns, decl["returnType"].get("desugaredQualType"))
    cpp_params = [(ti.param, n) for (n, _), ti in zip(params, infos)]
    args = [ti.conv_to(n) for (n, _), ti in zip(params, infos)]
    parts = (selector + "arguments:").split(":")
    segments = " ".join(f"{parts[i]}:{args[i]}" for i in range(len(params))) + f" {parts[len(params)]}:__list"
    target = f"::{model.ns}" if static else f"cocoon::internal::ns<::{model.ns}>(this)"
    call = f"[{target} {segments}]"
    lines = ["    std::vector<std::uint64_t> __slots = cocoon::internal::pack_var_args(args);", "    va_list __list = cocoon::internal::make_va_list(__slots);"]
    lines.append(f"    {call};" if ret.kind == "void" else f"    return {ret.conv_from(call)};")
    lines = guard_lines(lines, info.introduced, ret.kind == "void", ret)
    name = ident(snake(selector.split(":")[0]))
    inner_params = cpp_params + [("const std::vector<VarArg>&", "args")]
    key = (static, name + "_", tuple(norm_type(t) for t, _ in inner_params))
    member = Member(name + "_", ret.cpp, inner_params, lines, key, static)
    member.since = info.introduced
    fixed_decl = ", ".join(declare(t, n) for t, n in cpp_params)
    fixed_names = ", ".join(n for _, n in cpp_params)
    const = "" if static else " const"
    prefix = "static " if static else ""
    call_inner = f"{name}_({fixed_names}{', ' if fixed_names else ''}std::vector<VarArg>{{VarArg(args)...}})"
    body = f"{call_inner};" if ret.kind == "void" else f"return {call_inner};"
    member.extra_decl = f"    template <class... Args> {prefix}{ret.cpp} {name}({fixed_decl}{', ' if fixed_decl else ''}const Args&... args){const} {{ {body} }}"
    return member


def member_from_method(model, decl, static, methods=None):
    info = A.availability(decl)
    if info.unavailable:
        raise Skip("unavailable")
    if info.deprecated:
        raise Skip("deprecated")
    if decl.get("variadic"):
        return variadic_member(model, decl, static, methods or {}, info)
    selector = decl["name"]
    introduced = float(SPEC.get("availabilityOverrides", {}).get(f"{model.ns}.{selector}", info.introduced or 0)) or None
    member = make_member(model, selector, parm_list(decl), decl["returnType"], static, introduced, ident(snake(selector.split(":")[0])))
    member.sdk_doc = A.doc_comment(A.CLASS_FILES.get(model.ns, ""), decl.get("loc", {}).get("line"), selector.split(":")[0])
    return member


def members_from_property(model, prop):
    info = A.availability(prop)
    if info.unavailable or info.deprecated:
        raise Skip("unavailable/deprecated")
    static = bool(prop.get("class"))
    t = prop["type"]
    getter = prop.get("getter", {}).get("name", prop["name"])
    sdk_doc = A.doc_comment(A.CLASS_FILES.get(model.ns, ""), prop.get("loc", {}).get("line"), prop["name"])
    result = [make_member(model, getter, [], t, static, info.introduced, ident(snake(getter)))]
    if not prop.get("readonly"):
        setter = prop.get("setter", {}).get("name") or "set" + prop["name"][:1].upper() + prop["name"][1:] + ":"
        result.append(make_member(model, setter, [("value", t)], {"qualType": "void"}, static, info.introduced, ident(snake(setter.rstrip(":")))))
        result[1].role = "setter"
        result[1].prop = prop["name"]
        result[1].sdk_doc = sdk_doc
    result[0].role = "getter"
    result[0].prop = prop["name"]
    result[0].sdk_doc = sdk_doc
    return result


def make_ctor(model, decl):
    info = A.availability(decl)
    if info.unavailable or info.deprecated or decl.get("variadic"):
        raise Skip("unavailable")
    selector = decl["name"]
    params = parm_list(decl)
    cpp_params, args, pre, post = [], [], [], []
    needs_error = False
    for name, t in params:
        ti = typeinfo(t["qualType"], model.ns, t.get("desugaredQualType"))
        if ti.kind == "error":
            needs_error = True
            args.append("&__error")
            continue
        if ti.kind == "objout":
            cpp_params.append((ti.cpp, name))
            pre.append(f"{ti.inner.objc} __v_{name} = nil;")
            args.append(f"&__v_{name}")
            post.append(f"{name} = {ti.inner.conv_from('__v_' + name)};")
            continue
        cpp_params.append((ti.param, name))
        args.append(ti.conv_to(name))
    if len(cpp_params) == 1 and cpp_params[0][0] in (f"const {model.name}&", f"const {model.name}Base&"):
        raise Skip("copy-like constructor")
    parts = selector.split(":")
    segments = " ".join(f"{parts[i]}:{args[i]}" for i in range(len(params))) if params else selector
    decl_params = ", ".join(declare(t, n) for t, n in cpp_params)
    expr = f"[[::{model.ns} alloc] {segments}]"
    if pre or post or needs_error:
        body = (["NSError* __error = nil;"] if needs_error else []) + pre + [f"id __r = {expr};"] + post
        if needs_error:
            body += ["if (!__r && __error) { throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription)); }"]
        expr = "[&]() -> id { " + " ".join(body) + " return __r; }()"
    return {"header": f"    explicit {model.name}({decl_params});", "params": decl_params, "expr": expr,
            "key": tuple(norm_type(t) for t, _ in cpp_params), "since": info.introduced,
            "types": " ".join(t for t, _ in cpp_params)}


def collect_delegate_property(model, prop):
    if prop.get("class"):
        return False
    q = clean(prop["type"]["qualType"])
    model.delegate_majors[prop["name"]] = future_major(A.availability(prop).introduced)
    if prop.get("readonly") and re.fullmatch(r"id<[\w, ]+>", q):
        return True
    m = re.fullmatch(r"id<([\w, ]+)>", q)
    if not m:
        return False
    protocols = [p.strip() for p in m.group(1).split(",")]
    if prop["name"] in ("delegate", "dataSource") or any(p.endswith("Delegate") or p.endswith("DataSource") for p in protocols):
        model.delegate_props[prop["name"]] = protocols
        return True
    return False


def extra_keys_of(curated):
    keys = set()
    for extra in curated.get("extra", []):
        match = re.search(r"(\w+)\s*\(([^)]*)\)", extra["decl"])
        if match:
            keys.add((snake(match.group(1)), len(T.split_top(match.group(2)))))
    return keys


def type_params_of(interface):
    if not interface:
        return []
    return [c["name"] for c in interface.get("inner", []) if c["kind"] == "ObjCTypeParamDecl"]


def build_model(model):
    S.refs = model.refs
    S.allow_new = model.tier == "A"
    interface, props, methods = A.class_members(model.ns)
    model.interface = interface
    model.weak_unavailable = any(c["kind"] == "ArcWeakrefUnavailableAttr" for c in (interface or {}).get("inner", []))
    S.current_tparams = set(model.tparams)
    if interface is None:
        raise Unmappable(f"{model.ns} has no definition")
    sup = interface.get("super", {}).get("name")
    model.base_name = "Object"
    if sup and sup not in T.VALUE_CLASSES:
        saved = S.allow_new
        S.allow_new = True
        try:
            base = ensure_class(sup)
            model.base_name = base.name
        except Unmappable:
            model.base_name = "Object"
        S.allow_new = saved
    own_init = methods.get((True, "init"))
    if own_init is not None:
        model.own_init = True
        model.init_available = not A.availability(own_init).unavailable
    members = {}
    for (is_instance, selector), decl in sorted(methods.items(), key=lambda kv: kv[0][1]):
        try:
            if is_instance:
                if selector in SKIP_SELECTORS:
                    raise Skip("skipped selector")
                if selector.startswith("init"):
                    if selector in ("init", "initWithCoder:"):
                        continue
                    ret_q = clean(decl["returnType"]["qualType"])
                    if "instancetype" in ret_q or ret_q.startswith(model.ns):
                        model.ctors.append(make_ctor(model, decl))
                        continue
                member = member_from_method(model, decl, False, methods)
            else:
                if selector in SKIP_SELECTORS_STATIC:
                    raise Skip("skipped selector")
                member = member_from_method(model, decl, True, methods)
            members.setdefault(member.key, member)
        except Skip as e:
            log_skip(model, selector, str(e))
        except Unmappable as e:
            log_skip(model, selector, "unmapped " + str(e))
    for (is_class, name), prop in sorted(props.items(), key=lambda kv: kv[0][1]):
        try:
            if collect_delegate_property(model, prop):
                continue
            for member in members_from_property(model, prop):
                members.setdefault(member.key, member)
        except Skip as e:
            log_skip(model, name, str(e))
        except Unmappable as e:
            log_skip(model, name, "unmapped " + str(e))
    instance_keys = {(k[1], k[2]) for k in members if not k[0]}
    model.members = [m for k, m in members.items() if not (k[0] and (k[1], k[2]) in instance_keys)]


def protocol_methods(protocols, seen=None):
    seen = seen if seen is not None else set()
    result = collections.OrderedDict()
    for name in protocols:
        if name in seen or name in ("NSObject", "NSCopying", "NSCoding", "NSSecureCoding", "NSMutableCopying"):
            continue
        seen.add(name)
        nodes = [n for n in A.dump(name) if n["kind"] == "ObjCProtocolDecl" and n.get("name") == name]
        for node in nodes:
            for child in node.get("inner", []):
                if child["kind"] == "ObjCMethodDecl" and child.get("instance") and not child.get("isImplicit"):
                    result.setdefault(child["name"], (child, name))
            for parent in node.get("protocols", []):
                for sel, value in protocol_methods([parent["name"]], seen).items():
                    result.setdefault(sel, value)
    return result


def camel_tail(parts):
    return "".join(p[:1].upper() + p[1:] for p in parts)


def signal_name_for(selector, first_param_type, taken):
    override = SIGNAL_OVERRIDES.get(selector, {}).get("name")
    if override:
        return sname(override)
    parts = [p for p in selector.split(":") if p]
    sender = ""
    if first_param_type:
        m = re.match(r"(?:NS)?(\w+)", clean(first_param_type).replace("*", "").strip())
        if m:
            sender = m.group(1)
    sender_lower = sender[:1].lower() + sender[1:] if sender else ""
    first = parts[0]
    candidates = []
    if sender_lower and first == sender_lower and len(parts) > 1:
        candidates.append(parts[1][:1].lower() + parts[1][1:] + camel_tail(parts[2:]))
    elif sender_lower and first.startswith(sender_lower) and len(first) > len(sender_lower):
        rest = first[len(sender_lower):]
        candidates.append(rest[:1].lower() + rest[1:] + camel_tail(parts[1:]))
    candidates.append(first + camel_tail(parts[1:]))
    for c in candidates:
        c = sname(c)
        if c not in taken:
            return c
    return sname(candidates[-1]) + "_signal"


def delegate_args(parms):
    if parms and clean(parms[0][1]["qualType"]).startswith("NSNotification"):
        return parms
    return parms[1:]


def model_names(model):
    names = {m.name for m in model.members} | {n for n, _ in extra_keys_of(model.curated)} | {s["name"] for s in model.curated.get("signals", [])}
    return names


def process_delegates():
    for model in ALL_MODELS:
        model.delegates = []
        for prop, protocols in model.delegate_props.items():
            model.delegates.append({"prop": prop, "protocols": protocols, "methods": protocol_methods(protocols), "built": [], "cls": None, "text": "", "major": model.delegate_majors.get(prop, 0)})
    for model in ALL_MODELS:
        for d in model.delegates:
            for selector, (decl, protocol) in d["methods"].items():
                owner = None
                for m in chain_of(model):
                    for d2 in m.delegates:
                        if d2["prop"] == d["prop"] and selector in d2["methods"]:
                            owner = m
                            break
                    if owner:
                        break
                d["built"].append((selector, decl, owner or model))
    signal_defs = {}
    for model in ALL_MODELS:
        S.refs = model.refs
        S.allow_new = model.tier == "A"
        taken = set()
        for m in chain_of(model):
            taken |= model_names(m)
        taken |= {s["name"] for s in model.signals}
        for d in model.delegates:
            for selector, decl, owner in d["built"]:
                if owner is not model:
                    continue
                info = A.availability(decl)
                if info.unavailable or info.deprecated or decl.get("variadic"):
                    continue
                try:
                    parms = parm_list(decl, False)
                    override = SIGNAL_OVERRIDES.get(selector, {})
                    ret = typeinfo(decl["returnType"]["qualType"], model.ns, decl["returnType"].get("desugaredQualType"))
                    if ret.kind in ("out", "error"):
                        raise Skip("odd return")
                    if "args" in override:
                        args = [(a[0], a[1]) for a in override["args"]]
                    else:
                        args = []
                        for n, t in delegate_args(parms):
                            ti = typeinfo(t["qualType"], model.ns, t.get("desugaredQualType"))
                            if ti.kind == "error":
                                raise Skip("error param")
                            args.append((f"{ti.cpp}&" if ti.kind == "out" else ti.cpp, n))
                    notification = bool(parms) and clean(parms[0][1]["qualType"]).startswith("NSNotification")
                    name = signal_name_for(selector, model.ns if notification or not parms else parms[0][1]["qualType"], taken)
                    taken.add(name)
                    sig = f"{ret.cpp}({', '.join(a[0] for a in args)})"
                    signal_defs[(model.ns, d["prop"], selector)] = {"name": name, "sig": sig}
                    method_major = max(d["major"], future_major(info.introduced), taint(sig + " " + " ".join(t["qualType"] for _, t in parms)))
                    model.signals.append({"name": name, "sig": sig, "origin": "delegate", "major": method_major})
                except Skip as e:
                    log_skip(model, selector, "delegate " + str(e))
                except Unmappable as e:
                    log_skip(model, selector, "delegate unmapped " + str(e))
    return signal_defs


def make_qualifier():
    names = {m.name for m in ALL_MODELS} | {e["name"] for e in S.enums.values()} | {s["name"] for s in S.structs.values() if s["name"]} | set(S.opaques) | {"Size", "Point", "Rect", "Insets", "Object", "VarArg"}
    pattern = re.compile(r"(?<![\w:])(" + "|".join(sorted(map(re.escape, names), key=len, reverse=True)) + r")\b")
    return lambda text: pattern.sub(r"cocoon::\1", text)


def build_delegate_block(model, d, signal_defs):
    cls = f"AK{model.name}{'' if d['prop'] == 'delegate' else d['prop'][:1].upper() + d['prop'][1:]}Delegate"
    methods_text, responds = [], []
    S.refs = model.refs
    S.allow_new = model.tier == "A"
    for selector, decl, owner in d["built"]:
        sd = signal_defs.get((owner.ns, d["prop"], selector))
        if sd is None:
            continue
        try:
            parms = parm_list(decl, False)
            override = SIGNAL_OVERRIDES.get(selector, {})
            ret = typeinfo(decl["returnType"]["qualType"], model.ns, decl["returnType"].get("desugaredQualType"))
            ret_q = clean(decl["returnType"]["qualType"])
            parts = selector.split(":")
            if parms:
                qualifiers = A.parameter_qualifiers(selector)
                sig_text = f"- ({ret_q})" + " ".join(f"{parts[i]}:({qualifiers[i] + ' ' if qualifiers[i] else ''}{signature_type(parms[i][1])}){parms[i][0]}" for i in range(len(parms)))
            else:
                sig_text = f"- ({ret_q}){selector}"
            pre, post, emit_args = [], [], []
            if "args" in override:
                emit_args = [a[1] for a in override["args"]]
            else:
                for n, t in delegate_args(parms):
                    ti = typeinfo(t["qualType"], model.ns, t.get("desugaredQualType"))
                    if ti.kind in ("out", "objout"):
                        value_type = ti.inner.cpp
                        pre.append(QUALIFIER(f"{value_type} __v_{n} = {n} ? {ti.inner.conv_from('*' + n)} : {value_type}();"))
                        post.append(QUALIFIER(f"if ({n}) {{ *{n} = {ti.inner.conv_to('__v_' + n)}; }}"))
                        emit_args.append(f"__v_{n}")
                    else:
                        emit_args.append(QUALIFIER(ti.conv_from(n)))
            signal = f"cocoon::Signal<cocoon::{owner.name}, {QUALIFIER(sd['sig'])}>"
            emit = f"{signal}::emit((__bridge void*)strongHost, \"{sd['name']}\"" + "".join(f", {a}" for a in emit_args) + ")"
            body = ["    id strongHost = host;", "    if (!strongHost) {", "        return" + ("" if ret.kind == "void" else " {}") + ";", "    }"]
            body += ["    " + l for l in pre]
            if ret.kind == "void":
                body.append(f"    {emit};")
                body += ["    " + l for l in post]
            else:
                body.append(f"    auto __r = {emit};")
                body += ["    " + l for l in post]
                body.append(f"    return {QUALIFIER(ret.conv_to('__r'))};")
            method_major = max(d["major"], future_major(A.availability(decl).introduced), taint(sig_text + " " + sd["sig"]))
            methods_text.append(macro_guard(method_major, sig_text + "\n{\n" + "\n".join(body) + "\n}\n"))
            responds.append(macro_guard(method_major, f"    if (selector == @selector({selector})) {{\n        return strongHost && {signal}::connected((__bridge void*)strongHost, \"{sd['name']}\");\n    }}"))
        except (Skip, Unmappable) as e:
            log_skip(model, selector, "delegate emit " + str(e))
    if not methods_text:
        return
    protocols = ", ".join(d["protocols"])
    d["cls"] = cls
    weak_word = "__unsafe_unretained" if any(m.weak_unavailable for m in chain_of(model)) else "__weak"
    d["weak"] = weak_word
    d["text"] = (f"@interface {cls} : NSObject <{protocols}> {{\n@public\n    {weak_word} id host;\n}}\n@end\n\n@implementation {cls}\n\n" + "\n".join(methods_text)
                 + "\n- (BOOL)respondsToSelector:(SEL)selector\n{\n    id strongHost = host;\n" + "\n".join(responds) + "\n    return [super respondsToSelector:selector];\n}\n\n@end\n\n")


NUMERIC_TYPES = {"int", "unsigned int", "double", "float", "std::int64_t", "std::uint64_t", "std::int32_t", "std::uint32_t", "std::int16_t", "std::uint16_t", "std::int8_t", "std::uint8_t", "char16_t"}


def example_value(type_text):
    t = type_text.strip()
    if t.endswith("&") and not t.startswith("const "):
        return None
    base = re.sub(r"^const\s+", "", t).rstrip("&").strip()
    if base == "std::string":
        return '"text"'
    if base == "bool":
        return "true"
    if base in NUMERIC_TYPES:
        return "1"
    if base == "Size":
        return "{100, 100}"
    if base == "Point":
        return "{0, 0}"
    if base == "Rect":
        return "{{0, 0}, {100, 100}}"
    if base == "Insets":
        return "cocoon::Insets(8)"
    if base == "std::vector<std::string>":
        return '{"a", "b"}'
    for enum in S.enums.values():
        if enum["name"] == base and enum["values"]:
            return f"cocoon::{base}::{enum['values'][0][0]}"
    if base in BY_NAME and not BY_NAME[base].tparams:
        return f"cocoon::{base}()"
    return None


def example_args(params_text):
    if not params_text.strip():
        return ""
    values = []
    for p in T.split_top(params_text):
        p = re.sub(r"\s*=.*$", "", p).strip()
        type_text = p.rsplit(" ", 1)[0] if " " in p else p
        value = example_value(type_text)
        if value is None:
            return None
        values.append(value)
    return ", ".join(values)


def auto_example(model, entries, setters, signal_names):
    var = ident(snake(model.name))
    lines = ["#include <cocoon.h>", ""]
    construct = None
    best = None
    for header, params, init in entries:
        args = example_args(params)
        if args is not None and (best is None or len(args) < len(best)):
            best = args
    if best is not None:
        construct = f"cocoon::{model.name} {var}" + (f"{{{best}}};" if best else ";")
    else:
        construct = f"cocoon::{model.name} {var}(nullptr);  // null handle; instances normally come from other API calls"
    lines.append(construct)
    for name, params in setters[:1]:
        arg = example_args(params)
        if arg:
            lines.append(f"{var}.{name}({arg});")
    for signal, sig in signal_names:
        if sig.startswith("void("):
            lines.append(f"{var}.{signal}().connect([](auto&&...) {{}});")
            break
    return lines


def common_tasks(model, infos, doc_signals):
    var = ident(snake(model.name))
    lines = []
    seen_props = set()
    for kind, name, params, ret, static, prop in infos:
        if kind == "setter" and prop not in seen_props and len(params) == 1:
            value = example_value(params[0][0])
            getter = next((i for i in infos if i[0] == "getter" and i[5] == prop), None)
            if value is not None and getter is not None:
                seen_props.add(prop)
                lines.append(f"{var}.{name}({value});")
                lines.append(f"auto {snake(prop)} = {var}.{getter[1]}();")
                if len(seen_props) >= 3:
                    break
    factories = 0
    for kind, name, params, ret, static, prop in infos:
        if kind == "method" and static and ret == model.name and factories < 2:
            args = example_args(", ".join(f"{t} {n}" for t, n in params))
            if args is not None:
                lines.append(f"auto made_{factories} = cocoon::{model.name}::{name}({args});")
                factories += 1
    methods = 0
    for kind, name, params, ret, static, prop in infos:
        if kind == "method" and not static and methods < 3 and not name.endswith("_"):
            args = example_args(", ".join(f"{t} {n}" for t, n in params))
            if args is not None:
                lines.append(f"{var}.{name}({args});")
                methods += 1
    signals = 0
    for signal, sig in doc_signals:
        if signals >= 3:
            break
        match = re.fullmatch(r"(.*?)\((.*)\)", sig)
        if not match:
            continue
        ret, args = match.group(1), T.split_top(match.group(2))
        if ret != "void" or any("&" in a and "const" not in a for a in args):
            continue
        params = ", ".join(f"{QUALIFIER(a)} a{i}" for i, a in enumerate(args)) if args else ""
        lines.append(f"{var}.{signal}().connect([]({params}) {{}});")
        signals += 1
    return lines


def member_doc(model, member):
    if member.role == "getter":
        brief = f"Returns the `{member.prop}` property of `{model.ns}`."
    elif member.role == "setter":
        brief = f"Sets the `{member.prop}` property of `{model.ns}`."
    else:
        brief = f"Calls `{'+' if member.static else '-'}[{model.ns} {member.selector}]`."
    lines = ["/**", f" * @brief {brief}"]
    if member.sdk_doc:
        lines.append(f" * @details {member.sdk_doc}")
    for _, n in member.cpp_params:
        lines.append(f" * @param {n} Argument converted to the Objective-C parameter of the same role.")
    if member.ret != "void":
        lines.append(" * @return The converted Objective-C result.")
    lines.append(" */")
    return "\n".join("    " + l for l in lines)


def best_construct_args(entries):
    best = None
    for header, params, init in entries:
        args = example_args(params)
        if args is not None and (best is None or len(args) < len(best)):
            best = args
    return best if best is not None else None


def class_doc(model, entries, setters, signal_names, usage_infos=()):
    doc = model.curated.get("doc") or SPEC.get("docs", {}).get(model.name, {})
    framework = A.FRAMEWORK_OF.get(model.ns, "AppKit")
    url_name = model.ns.lower()
    brief = doc.get("brief") or (f"Specialised handle for `{model.ns}` ({framework}), created through {model.name}'s own constructors." if model.alias else f"C++ handle for the Objective-C class `{model.ns}` ({framework}).")
    lines = ["/**", f" * @brief {brief}"]
    sdk = A.doc_comment(A.CLASS_FILES.get(model.ns, ""), A.CLASS_LINES.get(model.ns), "@interface") if model.ns in A.CLASS_FILES else ""
    if sdk:
        lines.append(f" * @details {sdk}")
    lines.append(" * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.")
    if model.base_name != "Object":
        lines.append(f" * Inherits from @ref {model.base_name}.")
    if model.tparams:
        lines.append(f" * Use the typed template @ref {model.template_name} to supply {', '.join(model.tparams)}.")
    lines.append(" *")
    lines.append(" * @par Example")
    lines.append(" * @code")
    example = doc.get("example")
    code = example.strip("\n").split("\n") if example else auto_example(model, entries, setters, signal_names)
    lines += [" * " + c if c else " *" for c in code]
    lines.append(" * @endcode")
    tasks = common_tasks(model, usage_infos, signal_names)
    if tasks:
        lines.append(" *")
        lines.append(" * @par Common tasks")
        lines.append(" * Snippets built from this class's own members (values are placeholders).")
        lines.append(" * @code")
        construct_args = best_construct_args(entries)
        lines.append(f" * cocoon::{model.name} {ident(snake(model.name))}{{{construct_args}}};" if construct_args is not None else f" * cocoon::{model.name} {ident(snake(model.name))}(nullptr);")
        lines += [" * " + c for c in tasks]
        lines.append(" * @endcode")
    if model.ns.startswith("NS") or model.ns in A.CLASS_FILES:
        lines.append(f" * @see https://developer.apple.com/documentation/{framework.lower()}/{url_name}")
    lines.append(" */")
    return "\n".join("    " + l for l in lines)


def chain_init_available(model):
    for m in reversed(chain_of(model)):
        if m.own_init:
            return m.init_available
    return True


def ctor_bind_lines(model):
    chain = chain_of(model)
    lines = []
    for m in chain:
        if m.has_others:
            lines.append(f"    {m.name}::bind_others_(handle());")
    owner = next((m for m in reversed(chain) if m.has_action), None)
    if owner:
        lines.append(f"    {owner.name}::bind_action_(handle());")
    seen = set()
    for m in reversed(chain):
        for d in m.delegates:
            if d["cls"] and d["prop"] not in seen:
                seen.add(d["prop"])
                lines.append(macro_guard(d["major"], f"    {m.name}::install_{snake(d['prop'])}_delegate_(handle());"))
    if model.curated.get("ctorBody"):
        lines.append(f"    {convert_cpp(model.curated['ctorBody'])}")
    return lines


def emit_model(model, signal_defs):
    name = model.name
    future_classes = future_types()
    class_major = future_major(model.since)
    curated = model.curated
    refs = set(model.refs)
    refs.update(curated.get("forward", []))
    for extra in curated.get("extra", []):
        for word in re.findall(r"\b[A-Z]\w*\b", extra["decl"]):
            if word in BY_NAME or word in S.opaques:
                refs.add(word)
    entries = []
    ctor_major = {}
    curated_keys = set()
    default_callable = False
    for ctor in curated.get("ctors", []):
        ctor = dict(ctor)
        ctor["params"] = [list(p) for p in ctor.get("params", [])]
        objc_text = ctor["objc"]
        for p in ctor["params"]:
            if snake(p[1]) != p[1]:
                objc_text = rename_word(objc_text, p[1], snake(p[1]))
                p[1] = snake(p[1])
        ctor["objc"] = convert_cpp(objc_text)
        params = ctor["params"]
        decl_params = ", ".join(f"{p[0]} {p[1]}" + (f" = {p[2]}" if len(p) > 2 else "") for p in params)
        impl_params = ", ".join(f"{p[0]} {p[1]}" for p in params)
        explicit = "" if ctor.get("implicit") else "explicit "
        entries.append((f"    {explicit}{name}({decl_params});", impl_params, f"Adopt{{cocoon::internal::retain({ctor['objc']})}}"))
        curated_keys.add(tuple(norm_type(p[0]) for p in params))
        if all(len(p) > 2 for p in params):
            default_callable = True
    for c in model.ctors:
        if c["key"] not in curated_keys:
            entries.append((c["header"], c["params"], f"Adopt{{cocoon::internal::retain({c['expr']})}}"))
            ctor_major[c["header"]] = max(future_major(c.get("since")), taint(c.get("types", "")))
            curated_keys.add(c["key"])
    has_zero = default_callable or any(e[1] == "" and not ctor_major.get(e[0]) for e in entries)
    if not has_zero and not model.alias and chain_init_available(model):
        entries.append((f"    explicit {name}();", "", f"Adopt{{cocoon::internal::retain([[::{model.ns} alloc] init])}}"))
        has_zero = True
    binds = ctor_bind_lines(model)
    ctor_decls, other_decls, impl = [], [], []
    for header, params, init in entries:
        ctor_decls.append(macro_guard(ctor_major.get(header, 0), f"    /// @brief Creates a new `{model.ns}` instance and returns a handle to it.\n{header}"))
        impl.append(macro_guard(ctor_major.get(header, 0), f"{name}::{name}({params}) : {name}({init})\n{{\n" + "\n".join(binds) + ("\n" if binds else "") + "}\n"))
    if not has_zero:
        ctor_decls.append(f"    {name}();")
        impl.append(f"{name}::{name}() : {model.base_name}(nullptr) {{}}\n")
    ctor_decls.append(f"    /// @brief Creates a null handle that refers to no native object.\n    {name}(std::nullptr_t);")
    ctor_decls.append(f"    /// @brief Wraps an existing retained native object without creating a new one.\n    explicit {name}(Adopt adopt);")
    impl.append(f"{name}::{name}(std::nullptr_t) : {model.base_name}(nullptr) {{}}\n")
    impl.append(f"{name}::{name}(Adopt adopt) : {model.base_name}(adopt) {{}}\n")

    extra_keys = extra_keys_of(curated)
    member_names = set()
    typed_decls = []
    setters = []
    usage_infos = []
    type_names = {m.name for m in ALL_MODELS} | {e["name"] for e in S.enums.values()} | {st["name"] for st in S.structs.values() if st["name"]} | set(S.opaques) | {"Object", "Size", "Point", "Rect", "Insets", "Signal", "WeakRef", "Adopt"}
    name_major = {}
    for member in model.members:
        if (member.name, member.arity) in extra_keys:
            continue
        final = member.name
        if final in type_names or final == name:
            final = final.lower() if final.isupper() else final + "_"
        decl, member_impl = member.render(name, final)
        signature = " ".join([member.ret] + [t for t, _ in member.cpp_params])
        major = max([future_major(member.since)] + [v for k, v in future_classes.items() if re.search(r"\b" + re.escape(k) + r"\b", signature)])
        if member.extra_decl:
            other_decls.append(macro_guard(major, member.extra_decl))
        other_decls.append(macro_guard(major, member_doc(model, member) + "\n" + decl))
        usage_infos.append((member.role, final, member.cpp_params, member.ret, member.static, member.prop))
        if member.role == "setter" and len(member.cpp_params) == 1:
            setters.append((final, member.cpp_params[0][0] + " value"))
        if member.typed and model.tparams:
            typed_decls.append(macro_guard(major, member.render_typed(name, final)))
        impl.append(macro_guard(major, member_impl))
        member_names.add(final)
        name_major[final] = min(name_major.get(final, major), major)
    for extra in curated.get("extra", []):
        decl_text, impl_text = convert_extra(extra["decl"], extra["impl"].replace("{cls}", name).replace("{ns}", model.ns))
        if not decl_text.startswith("static") and not decl_text.endswith("const;"):
            decl_text = decl_text[:-1] + " const;"
            brace = impl_text.index("{")
            signature = impl_text[:brace].rstrip()
            impl_text = signature + " const" + impl_text[len(signature):]
        extra_match = re.search(r"(\w+)\s*\(", decl_text)
        extra_brief = extra.get("doc") or f"Convenience helper `{extra_match.group(1) if extra_match else decl_text}` provided by cocoon."
        other_decls.append(f"    /// @brief {extra_brief}\n    {decl_text}")
        impl.append(impl_text + "\n")
        m = re.search(r"(\w+)\s*\(", decl_text)
        if m:
            member_names.add(m.group(1))
            name_major[m.group(1)] = 0
    signal_names = set()
    doc_signals = []
    for s in curated.get("signals", []):
        sig = f"void({', '.join(a[0] for a in s.get('args', []))})"
        key = sname(s["name"])
        other_decls.append(f"    /// @brief Signal `{key}`: connect a callback with `{key}().connect(...)`.\n    Signal<{name}, {sig}> {key}() const {{ return Signal<{name}, {sig}>(handle(), \"{key}\"); }}")
        signal_names.add(key)
        doc_signals.append((key, sig))
    for s in model.signals:
        if s["origin"] == "delegate":
            signal_major = max([s.get("major", 0)] + [v for k, v in future_classes.items() if re.search(r"\b" + re.escape(k) + r"\b", s["sig"])])
            other_decls.append(macro_guard(signal_major, f"    /// @brief Signal for the delegate/data-source method behind `{s['name']}`; connect a callback with `{s['name']}().connect(...)`.\n    Signal<{name}, {s['sig']}> {s['name']}() const {{ return Signal<{name}, {s['sig']}>(handle(), \"{s['name']}\"); }}"))
            name_major[s["name"]] = signal_major
            signal_names.add(s["name"])
            doc_signals.append((s["name"], s["sig"]))
    using = []
    ancestors = chain_of(model)[:-1]
    for member_name in sorted(member_names):
        for anc in reversed(ancestors):
            if member_name in anc.all_names:
                using.append(macro_guard(max(name_major.get(member_name, 0), anc.name_major.get(member_name, 0)), f"    using {anc.name}::{member_name};"))
                break
    model.all_names = member_names | signal_names
    model.name_major = name_major

    protected = []
    if model.has_action:
        protected.append("    static void bind_action_(void* native);")
        action_signals = [s for s in curated["signals"] if not s.get("notification")]
        target = action_signals[0].get("target", "host")
        emits = []
        for s in action_signals:
            for also in s.get("also", []):
                declaring, types = SIGNAL_TABLE[also]
                emits.append(f"        cocoon::Signal<cocoon::{declaring}, void({', '.join(types)})>::emit((__bridge void*)host, \"{sname(also)}\");")
            sig = f"void({', '.join(a[0] for a in s.get('args', []))})"
            emit_args = "".join(f", {a[1]}" for a in s.get("args", []))
            emits.append(f"        cocoon::Signal<cocoon::{name}, {sig}>::emit((__bridge void*)host, \"{sname(s['name'])}\"{emit_args});")
        impl.append(f"void {name}::bind_action_(void* native) {{\n    id host = (__bridge id)native;\n    cocoon::internal::bind_action({target}, host, [](id host, id sender) {{\n" + "\n".join(emits) + "\n    });\n}\n")
    observer_lines = []
    for s in curated.get("signals", []):
        if s.get("notification"):
            sig = f"void({', '.join(a[0] for a in s.get('args', []))})"
            emit_args = "".join(f", {a[1]}" for a in s.get("args", []))
            observer_lines.append(f"    cocoon::internal::observe(host, host, {s['notification']}, [](id host, NSNotification* note) {{\n        cocoon::Signal<cocoon::{name}, {sig}>::emit((__bridge void*)host, \"{sname(s['name'])}\"{emit_args});\n    }});")
    if observer_lines:
        protected.append("    static void bind_others_(void* native);")
        impl.append(f"void {name}::bind_others_(void* native) {{\n    id host = (__bridge id)native;\n" + "\n".join(observer_lines) + "\n}\n")
    delegate_text = ""
    for d in model.delegates:
        if not d["cls"]:
            continue
        delegate_text += macro_guard(d["major"], d["text"])
        prop, cls = d["prop"], d["cls"]
        protected.append(macro_guard(d["major"], f"    static void install_{snake(prop)}_delegate_(void* native);"))
        impl.append(macro_guard(d["major"], f"void {name}::install_{snake(prop)}_delegate_(void* native) {{\n    ::{model.ns}* host = (__bridge ::{model.ns}*)native;\n    {cls}* delegate = [[{cls} alloc] init];\n    delegate->host = host;\n    host.{prop} = delegate;\n    {d['weak']} ::{model.ns}* weakHost = host;\n    cocoon::internal::keep_delegate(host, delegate, ^{{\n        ::{model.ns}* strongHost = weakHost;\n        strongHost.{prop} = nil;\n        strongHost.{prop} = delegate;\n    }});\n}}\n"))
    wrapper = ""
    if model.tparams:
        template_head = ", ".join(f"class {p}" for p in model.tparams)
        usings = "".join(macro_guard(name_major.get(n, 0), f"    using {name}::{n};") + "\n" for n in sorted(model.all_names))
        wrapper = (f"template <{template_head}>\nclass {model.template_name} : public {name} {{\npublic:\n    using {name}::{name};\n"
                   f"    {model.template_name}() : {name}() {{}}\n    {model.template_name}(const {name}& other) : {name}(other) {{}}\n{usings}"
                   + "\n".join(typed_decls) + "\n};\n\n")
    includes = "".join((f"#include {i}\n" if i.startswith("<") else f'#include "{i}"\n') for i in curated.get("includes", []))
    forwards = "".join(f"class {r};\n" for r in sorted(refs - {name}))
    bottoms = ""
    base_include = '#include "object.h"' if model.base_name == "Object" else f'#include "generated/{snake(model.base_name)}.h"'
    header_body = (f'{base_include}\n#include "generated/enums.h"\n#include "generated/structs.h"\n#include "types.h"\n{includes}\n'
              f"namespace cocoon {{\n\n{forwards}\n{curated.get('preamble', '')}\n{class_doc(model, entries, setters, doc_signals, usage_infos)}\nclass {name} : public {model.base_name} {{\npublic:\n"
              + "\n".join(ctor_decls + using + other_decls) + ("\n\nprotected:\n" + "\n".join(protected) if protected else "")
              + f"\n}};\n\n{wrapper}{curated.get('headerExtra', '')}\n}}\n\n{bottoms}")
    header = '#pragma once\n\n#include "generated/availability.h"\n\n' + macro_guard(class_major, header_body)
    write(OUT_INCLUDE / f"{snake(name)}.h", header)
    write(OUT_SRC / f"{snake(name)}.mm", f'#include "generated/{snake(name)}.h"\n#include "internal.h"\n\n' + macro_guard(class_major, delegate_text + "namespace cocoon {\n\n" + "\n".join(impl) + "\n}\n"))


def literal(value, underlying):
    if underlying == "std::uint64_t" and value > 2**63 - 1:
        return f"{value}ULL"
    if underlying == "std::uint32_t" and value > 2**31 - 1:
        return f"{value}U"
    return str(value)


def emit_enums():
    for e in SPEC.get("enums", []):
        S.enums[e["ns"]] = {"name": e["name"], "underlying": e["underlying"], "flags": e.get("flags", False), "values": list(e["values"].items())}
    text = ["#pragma once", "", "#include <cstdint>", "", "namespace cocoon {", ""]
    for ns in sorted(S.enums):
        e = S.enums[ns]
        kind = "option set" if e["flags"] else "enumeration"
        text.append(f"/** @brief Wraps the Objective-C {kind} `{ns}`. Combine option sets with `|` and test them with `test_flag`. */" if e["flags"] else f"/** @brief Wraps the Objective-C {kind} `{ns}`. */")
        text.append(f"enum class {e['name']} : {e['underlying']} {{")
        text.extend(f"    {k} = {literal(v, e['underlying'])}," for k, v in e["values"])
        text.append("};\n")
        if e["flags"]:
            u, n = e["underlying"], e["name"]
            text.append(f"constexpr {n} operator|({n} a, {n} b) {{ return static_cast<{n}>(static_cast<{u}>(a) | static_cast<{u}>(b)); }}")
            text.append(f"constexpr {n} operator&({n} a, {n} b) {{ return static_cast<{n}>(static_cast<{u}>(a) & static_cast<{u}>(b)); }}")
            text.append(f"constexpr bool test_flag({n} value, {n} flag) {{ return (static_cast<{u}>(value) & static_cast<{u}>(flag)) != 0; }}\n")
    text.append("}")
    write(OUT_INCLUDE / "enums.h", "\n".join(text) + "\n")


def emit_structs():
    structs = [s for s in S.structs.values() if not s["manual"]]
    ordered, placed = [], set()

    def place(s):
        if s["name"] in placed:
            return
        placed.add(s["name"])
        for _, ti in s["fields"]:
            if ti.kind == "struct":
                for other in structs:
                    if other["name"] == ti.cpp:
                        place(other)
        ordered.append(s)

    for s in structs:
        place(s)
    header = ["#pragma once", "", "#include <cstdint>", "", '#include "geometry.h"', "", "namespace cocoon {", ""]
    conversions = ["#pragma once", "", "#import <AppKit/AppKit.h>", "", "#include <cstring>", "", '#include "generated/structs.h"', "", "namespace cocoon::internal {", ""]
    for s in ordered:
        if s["blob"]:
            size, align = s["blob"]
            header.append(f"/** @brief Opaque {size}-byte blob holding a `{s['ctype']}` value. */")
            header.append(f"struct alignas({align}) {s['name']} {{\n    std::uint8_t bytes[{size}] = {{}};\n}};\n")
        else:
            header.append(f"/** @brief Plain C++ mirror of the C structure `{s['ctype']}`. */")
            header.append(f"struct {s['name']} {{")
            for fname, ti in s["fields"]:
                header.append(f"    {ti.cpp} {sname(fname)} = {{}};")
            header.append("};\n")
        conversions.append(f"::{s['ctype']} to(const cocoon::{s['name']}& value);")
        conversions.append(f"cocoon::{s['name']} from(::{s['ctype']} value);")
    conversions.append("")
    for s in ordered:
        conversions.append(f"inline ::{s['ctype']} to(const cocoon::{s['name']}& value)\n{{\n    ::{s['ctype']} result;")
        if s["blob"]:
            conversions.append("    std::memcpy(&result, value.bytes, sizeof(result));")
        else:
            for fname, ti in s["fields"]:
                conversions.append(f"    result.{fname} = {ti.conv_to('value.' + sname(fname))};")
        conversions.append("    return result;\n}\n")
        conversions.append(f"inline cocoon::{s['name']} from(::{s['ctype']} value)\n{{\n    cocoon::{s['name']} result;")
        if s["blob"]:
            conversions.append("    std::memcpy(result.bytes, &value, sizeof(value));")
        else:
            for fname, ti in s["fields"]:
                conversions.append(f"    result.{sname(fname)} = {ti.conv_from('value.' + fname)};")
        conversions.append("    return result;\n}\n")
    header.append("}")
    conversions.append("}")
    write(OUT_INCLUDE / "structs.h", "\n".join(header) + "\n")
    write(OUT_SRC / "struct_conversions.h", "\n".join(conversions) + "\n")


def emit_opaques():
    for name in S.opaques:
        write(OUT_INCLUDE / f"{snake(name)}.h",
            f'#pragma once\n\n#include "object.h"\n\nnamespace cocoon {{\n\n/** @brief Opaque handle for the Core Foundation style type `{S.opaques[name]}`. */\nclass {name} : public Object {{\npublic:\n    {name}() = default;\n    {name}(std::nullptr_t) {{}}\n    explicit {name}(Adopt adopt) : Object(adopt) {{}}\n}};\n\n}}\n')


def emit_constants():
    groups = collections.OrderedDict()
    seen = set()
    for type_text, cname in A.discover_constants():
        if cname in seen or cname.startswith("_"):
            continue
        seen.add(cname)
        if type_text in S.manual_enums:
            continue
        try:
            ti = typeinfo(type_text)
        except Unmappable:
            continue
        if ti.kind not in ("string", "prim") or ti.cpp in ("void*", "char*"):
            continue
        if ti.kind == "string" and not type_text.endswith("*") and not re.fullmatch(r"NS\w+", type_text):
            continue
        if re.fullmatch(r"NS\w+", type_text):
            key = type_text
        else:
            key = "NSStringConstants" if ti.kind == "string" else "NSNumberConstants"
        groups.setdefault(key, []).append((cname, ti))
    header = ["#pragma once", "", "#include <cstdint>", "#include <string>", "", "namespace cocoon {", ""]
    impl = ['#include "generated/constants.h"', '#include "internal.h"', "", "namespace cocoon {", ""]
    for key, items in groups.items():
        struct = unique_type_name(re.sub(r"^NS", "", key), "Constants")
        header.append(f"/** @brief Named constants of type `{key}`; each function reads the SDK symbol at runtime. */")
        header.append(f"struct {struct} {{")
        used = set()
        for cname, ti in items:
            stripped = cname[len(key):] if cname.startswith(key) and len(cname) > len(key) else re.sub(r"^NS", "", cname)
            name = sname(stripped)
            base, n = name, 2
            while name in used:
                name = f"{base}{n}"
                n += 1
            used.add(name)
            cpp = "std::string" if ti.kind == "string" else ti.cpp
            header.append(f"    /// @brief Value of the SDK constant `{cname}`.")
            header.append(f"    static {cpp} {name}();")
            if ti.kind == "string":
                body = f'return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("{cname}", nil));'
            else:
                body = f'return {ti.conv_from(f"cocoon::internal::load_symbol<{ti.objc}>(\"{cname}\", {ti.objc}())")};'
            impl.append(f"{cpp} {struct}::{name}() {{ {body} }}")
        header.append("};\n")
        impl.append("")
    header.append("}")
    impl.append("}")
    write(OUT_INCLUDE / "constants.h", "\n".join(header) + "\n")
    write(OUT_SRC / "constants.mm", "\n".join(impl) + "\n")


def format_files():
    import concurrent.futures
    import subprocess

    paths = []
    for directory in ("include", "src", "examples"):
        for pattern in ("*.h", "*.mm", "*.cpp"):
            paths.extend(p for p in (ROOT / directory).rglob(pattern) if ".cache" not in p.parts)

    def run(path):
        source = path.read_text()
        out = subprocess.run(["clang-format", f"--assume-filename={path}", "--style=file"], input=source, capture_output=True, text=True)
        if out.returncode == 0 and out.stdout:
            text = re.sub(r"(namespace[^\n]*\n\s*\{\n)\n+", r"\1", out.stdout)
            text = re.sub(r"\n\n+(\s*\}\n)", r"\n\1", text)
            if text != source:
                path.write_text(text)

    with concurrent.futures.ThreadPoolExecutor(8) as pool:
        list(pool.map(run, paths))


def main():
    global SIGNAL_TABLE, QUALIFIER
    for d in (OUT_INCLUDE, OUT_SRC):
        shutil.rmtree(d, ignore_errors=True)
        d.mkdir(parents=True)

    discovered = [n for n in A.discover_classes() if n not in SKIP_CLASSES and n not in T.VALUE_CLASSES]
    curated = {c["name"]: c for c in SPEC["classes"]}
    for c in SPEC["classes"]:
        if not c.get("alias") and c["ns"] not in discovered:
            discovered.append(c["ns"])
    A.prefetch(discovered)
    for ns in discovered:
        interface = A.class_nodes(ns)[1]
        if interface is None or A.availability(interface).unavailable or interface.get("super", {}).get("name") == "NSProxy":
            continue
        tparams = type_params_of(interface)
        base_cpp = class_cpp_name(ns)
        model = ClassModel(ns, unique_type_name(base_cpp + "Base" if tparams else base_cpp), "A")
        model.since = A.availability(interface).introduced
        model.tparams = tparams
        model.template_name = base_cpp if tparams else None
        model.curated = curated.get(base_cpp, {})
        S.classes[ns] = model
        ALL_MODELS.append(model)
        BY_NAME[model.name] = model
    aliases = []
    for c in SPEC["classes"]:
        if c.get("alias"):
            model = ClassModel(c["ns"], unique_type_name(c["name"]), "A")
            model.alias = True
            model.curated = c
            model.base_name = c["base"]
            aliases.append(model)

    for model in list(ALL_MODELS):
        try:
            build_model(model)
        except Unmappable as e:
            log_skip(model, "<class>", str(e))
    while S.queue:
        ns = S.queue.pop(0)
        model = S.classes[ns]
        ALL_MODELS.append(model)
        BY_NAME[model.name] = model
        try:
            build_model(model)
        except Unmappable as e:
            log_skip(model, "<class>", str(e))
    for model in aliases:
        ALL_MODELS.append(model)
        BY_NAME[model.name] = model

    for model in ALL_MODELS:
        model.has_action = any(not s.get("notification") for s in model.curated.get("signals", []))
        for s in model.curated.get("signals", []):
            SIGNAL_TABLE.setdefault(s["name"], (model.name, [a[0] for a in s.get("args", [])]))

    signal_defs = process_delegates()
    QUALIFIER = make_qualifier()
    for model in ALL_MODELS:
        for d in model.delegates:
            build_delegate_block(model, d, signal_defs)
        model.has_others = any(s.get("notification") for s in model.curated.get("signals", []))

    for model in sorted(ALL_MODELS, key=lambda m: len(chain_of(m))):
        emit_model(model, signal_defs)

    emit_constants()
    emit_enums()
    emit_structs()
    emit_opaques()
    write(OUT_INCLUDE / "availability.h", "#pragma once\n\n#include <Availability.h>\n\n" + "".join(f"#if defined(COCOON_SDK_MAJOR)\n#if COCOON_SDK_MAJOR >= {major}\n#define COCOON_MACOS_{major}\n#endif\n#elif defined(__MAC_OS_X_VERSION_MAX_ALLOWED) && __MAC_OS_X_VERSION_MAX_ALLOWED >= {major * 10000}\n#define COCOON_MACOS_{major}\n#endif\n\n" for major in range(MAJOR + 1, max(FUTURE_MAJORS | {MAJOR}) + 1)))
    write(OUT_INCLUDE / "generated.h", "#pragma once\n\n" + "".join(f'#include "generated/{snake(m.name)}.h"\n' for m in sorted(ALL_MODELS, key=lambda m: snake(m.name))) + "".join(f'#include "generated/{snake(n)}.h"\n' for n in sorted(S.opaques)) + '#include "generated/constants.h"\n')
    format_files()
    report = ["Skipped members by reason"]
    for reason, items in sorted(SKIPPED.items(), key=lambda kv: -len(kv[1])):
        report.append(f"\n{reason}: {len(items)}\n" + "\n".join(f"  {i}" for i in items[:40]) + ("\n  ..." if len(items) > 40 else ""))
    (ROOT / "generator" / "skipped.txt").write_text("\n".join(report) + "\n")
    print(f"{len(ALL_MODELS)} classes, {len(S.enums)} enums, {len(S.structs)} structs, {len(S.opaques)} opaque, {sum(len(v) for v in SKIPPED.values())} skipped members", file=sys.stderr)


if __name__ == "__main__":
    main()
