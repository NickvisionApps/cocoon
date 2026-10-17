import concurrent.futures
import functools
import json
import pathlib
import re
import subprocess
import tempfile

ROOT = pathlib.Path(__file__).resolve().parent
SDK_PATH = subprocess.run(["xcrun", "--show-sdk-path"], capture_output=True, text=True).stdout.strip()
SDK_VERSION = subprocess.run(["xcrun", "--show-sdk-version"], capture_output=True, text=True).stdout.strip()
FRAMEWORKS = ["AppKit", "Foundation"]
HEADER_DIRS = [pathlib.Path(SDK_PATH) / f"System/Library/Frameworks/{name}.framework/Headers" for name in FRAMEWORKS]

_tu = pathlib.Path(tempfile.mkdtemp()) / "tu.m"
_tu.write_text("#import <AppKit/AppKit.h>\n")
_target = "26.0"
_cache_dir = None


def configure(target):
    global _target, _cache_dir
    _target = target
    _cache_dir = ROOT / ".cache" / f"{SDK_VERSION}-{target}"
    _cache_dir.mkdir(parents=True, exist_ok=True)


@functools.lru_cache(maxsize=None)
def dump(name):
    cached = _cache_dir / f"{name}.json"
    if cached.exists():
        out = cached.read_text()
    else:
        out = subprocess.run(
            ["xcrun", "clang", "-fsyntax-only", "-fobjc-arc", f"-mmacosx-version-min={_target}",
             "-Xclang", "-ast-dump=json", "-Xclang", f"-ast-dump-filter={name}", str(_tu)],
            capture_output=True, text=True).stdout
        cached.write_text(out)
    decoder = json.JSONDecoder()
    nodes = []
    i = 0
    while i < len(out):
        while i < len(out) and out[i].isspace():
            i += 1
        if i >= len(out):
            break
        node, i = decoder.raw_decode(out, i)
        nodes.append(node)
    return nodes


def prefetch(names):
    with concurrent.futures.ThreadPoolExecutor(8) as pool:
        list(pool.map(dump, sorted(set(names))))


@functools.lru_cache(maxsize=None)
def _file_lines(path):
    try:
        return pathlib.Path(path).read_text(errors="replace").split("\n")
    except OSError:
        return []


def _macro_text(loc):
    spelling = loc.get("expansionLoc", loc)
    lines = _file_lines(spelling.get("file", ""))
    line = spelling.get("line", 0)
    col = spelling.get("col", 1)
    if not line or line > len(lines):
        return ""
    text = "\n".join(lines[line - 1:line + 6])[col - 1:]
    match = re.match(r"([A-Za-z_][A-Za-z0-9_]*)\s*", text)
    if not match:
        return ""
    end = match.end()
    if end < len(text) and text[end] == "(":
        depth = 0
        for i in range(end, len(text)):
            if text[i] == "(":
                depth += 1
            elif text[i] == ")":
                depth -= 1
                if depth == 0:
                    return text[:i + 1]
    return match.group(1)


def _version(text):
    match = re.match(r"\s*(\d+)(?:[._](\d+))?", text or "")
    if not match:
        return None
    return float(f"{match.group(1)}.{match.group(2) or 0}")


class Availability:
    def __init__(self):
        self.unavailable = False
        self.deprecated = False
        self.introduced = None


def availability(node):
    result = Availability()
    for attr in node.get("inner", []):
        kind = attr.get("kind")
        if kind == "UnavailableAttr":
            result.unavailable = True
        elif kind == "DeprecatedAttr":
            result.deprecated = True
        elif kind == "AvailabilityAttr":
            begin = attr.get("range", {}).get("begin")
            text = _macro_text(begin) if begin else ""
            name = re.match(r"[A-Za-z_0-9]+", text).group(0) if text else ""
            if not name:
                continue
            if name.startswith("NS_UNAVAILABLE") or name.startswith("API_UNAVAILABLE"):
                if name.startswith("NS_UNAVAILABLE") or "macos" in text:
                    result.unavailable = True
            elif "DEPRECATED" in name and "SWIFT" not in name:
                macos = re.search(r"macos\(\s*([\d._]+)\s*,\s*([\w._]+)", text)
                if macos:
                    end = _version(macos.group(2))
                    if end is not None and end <= 26.0:
                        result.deprecated = True
                elif name.startswith("NS_DEPRECATED_MAC") or name.startswith("NS_DEPRECATED"):
                    numbers = re.findall(r"\(\s*([\d._]+)\s*,\s*([\w._]+)", text)
                    if numbers:
                        end = _version(numbers[0][1])
                        if end is not None and end <= 26.0:
                            result.deprecated = True
            elif "AVAILABLE" in name and "SWIFT" not in name:
                macos = re.search(r"macos\(\s*([\d._]+)", text)
                if macos:
                    result.introduced = _version(macos.group(1))
                elif name.startswith("NS_AVAILABLE_MAC"):
                    result.introduced = _version(re.search(r"\(\s*([\d._]+)", text).group(1)) if re.search(r"\(\s*([\d._]+)", text) else None
    return result


def _owner_of_method(node):
    match = re.match(r"^[-+]\[(\w+)(?:\((\w+)\))? ", node.get("mangledName", ""))
    return match.group(1) if match else None


def class_nodes(ns):
    nodes = dump(ns)
    interface = None
    for node in nodes:
        if node["kind"] == "ObjCInterfaceDecl" and node.get("name") == ns and node.get("inner") is not None and node.get("super") is not None:
            interface = node
            break
    if interface is None:
        for node in nodes:
            if node["kind"] == "ObjCInterfaceDecl" and node.get("name") == ns and node.get("inner"):
                interface = node
                break
    return nodes, interface


def class_members(ns):
    nodes, interface = class_nodes(ns)
    properties, methods = {}, {}

    def add_property(node):
        properties[(bool(node.get("class")), node["name"])] = node

    def add_method(node):
        if node.get("isImplicit"):
            return
        methods[(bool(node.get("instance")), node["name"])] = node

    for node in nodes:
        if node["kind"] == "ObjCInterfaceDecl" and node.get("name") == ns:
            for child in node.get("inner", []):
                if child["kind"] == "ObjCPropertyDecl":
                    add_property(child)
                elif child["kind"] == "ObjCMethodDecl":
                    add_method(child)
        elif node["kind"] == "ObjCCategoryDecl" and node.get("interface", {}).get("name") == ns:
            for child in node.get("inner", []):
                if child["kind"] == "ObjCPropertyDecl":
                    add_property(child)
                elif child["kind"] == "ObjCMethodDecl":
                    add_method(child)
    accessor_owner = {}
    for node in nodes:
        if node["kind"] == "ObjCMethodDecl" and node.get("isImplicit"):
            accessor_owner[(bool(node.get("instance")), node["name"])] = _owner_of_method(node)
    for node in nodes:
        if node["kind"] == "ObjCMethodDecl" and not node.get("isImplicit") and _owner_of_method(node) == ns:
            add_method(node)
        elif node["kind"] == "ObjCPropertyDecl":
            getter = node.get("getter", {}).get("name", node["name"])
            if accessor_owner.get((not node.get("class"), getter)) == ns:
                add_property(node)
    return interface, properties, methods


CLASS_FILES = {}
CLASS_LINES = {}
FRAMEWORK_OF = {}


def discover_classes():
    names = []
    pattern = re.compile(r"^@interface\s+(NS\w+)\s*(?:<[^>]*>)?\s*:", re.M)
    for directory in HEADER_DIRS:
        for header in sorted(directory.glob("*.h")):
            text = header.read_text(errors="replace")
            for match in pattern.finditer(text):
                if match.group(1) not in names:
                    names.append(match.group(1))
                    CLASS_LINES[match.group(1)] = text[:match.start()].count("\n") + 1
                    CLASS_FILES[match.group(1)] = str(header)
                    FRAMEWORK_OF[match.group(1)] = directory.parent.name.replace(".framework", "")
    return names


def doc_comment(path, line, keyword):
    lines = _file_lines(path)
    if not path or not line or line > len(lines) or keyword not in lines[line - 1] + (lines[line] if line < len(lines) else "") + (lines[line - 2] if line > 1 else ""):
        return ""
    i = line - 2
    while i >= 0 and (lines[i].strip().startswith("API_") or lines[i].strip().startswith("NS_") or lines[i].strip() == ""):
        i -= 1
    if i < 0:
        return ""
    text = lines[i].strip()
    collected = []
    if text.startswith("///"):
        while i >= 0 and lines[i].strip().startswith("///"):
            collected.insert(0, lines[i].strip()[3:].strip())
            i -= 1
    elif text.endswith("*/"):
        while i >= 0:
            collected.insert(0, lines[i].strip())
            if "/*" in lines[i]:
                break
            i -= 1
        collected = [re.sub(r"^/\*+!?|\*+/$|^\*+", "", c).strip() for c in collected]
    else:
        return ""
    body = " ".join(c for c in collected if c)
    body = body.replace("*/", "").replace("/*", "/ *").replace("*", "").replace("`", "'").replace("\\", "\\\\").replace("@", "\\@").replace("#", "\\#").replace("%", "\\%").replace("<", "\\<")
    body = re.sub(r"(?<![A-Za-z0-9])_|_(?![A-Za-z0-9])", "", body)
    return re.sub(r"\s+", " ", body).strip()


def _strip_macros(text):
    out = ""
    i = 0
    while i < len(text):
        m = re.match(r"\b(?:API|NS)_[A-Z0-9_]+\b", text[i:])
        if m:
            i += m.end()
            while i < len(text) and text[i] == " ":
                i += 1
            if i < len(text) and text[i] == "(":
                depth = 0
                while i < len(text):
                    if text[i] == "(":
                        depth += 1
                    elif text[i] == ")":
                        depth -= 1
                        if depth == 0:
                            i += 1
                            break
                    i += 1
            continue
        out += text[i]
        i += 1
    return out


def discover_constants():
    found = []
    export = re.compile(r"^(?:APPKIT_EXTERN|FOUNDATION_EXPORT|FOUNDATION_EXTERN|NS_EXTERN|extern)\s+(.*)$")
    for directory in HEADER_DIRS:
        for header in sorted(directory.glob("*.h")):
            for line in header.read_text(errors="replace").split("\n"):
                m = export.match(line.strip())
                if not m:
                    continue
                text = m.group(1).split(";")[0]
                if re.search(r"API_DEPRECATED|NS_DEPRECATED|API_UNAVAILABLE\(\s*macos|NS_UNAVAILABLE|API_TO_BE_DEPRECATED", text):
                    continue
                text = _strip_macros(text).strip()
                parts = re.match(r"^(.*\S)\s+(\w+)$", text)
                if not parts or "(" in parts.group(1):
                    continue
                type_text = re.sub(r"\bconst\b", "", parts.group(1))
                type_text = re.sub(r"\s+", " ", type_text).strip()
                found.append((type_text, parts.group(2)))
    return found


@functools.lru_cache(maxsize=None)
def layout(ctype):
    source = f"#import <AppKit/AppKit.h>\n{ctype} __a;\nchar (*__size)[sizeof({ctype})] = 1;\nchar (*__align)[_Alignof({ctype})] = 1;\n"
    probe = _tu.parent / "probe.m"
    probe.write_text(source)
    out = subprocess.run(["xcrun", "clang", "-fsyntax-only", "-fobjc-arc", f"-mmacosx-version-min={_target}", str(probe)], capture_output=True, text=True).stderr
    sizes = re.findall(r"char \(\*\)\[(\d+)\]", out)
    if len(sizes) < 2:
        return None
    return int(sizes[0]), int(sizes[1])
