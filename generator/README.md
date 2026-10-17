# generator

Generates the whole wrapper library from the macOS SDK. Every file under `include/generated` and `src/generated` is written by this folder; do not edit those files by hand, change the generator or `spec.py` and run it again.

```
python3 generator/generate.py
```

Requirements: macOS 26 with Xcode 26 (`xcrun clang` and the SDK), Python 3 (standard library only) and `clang-format` (`brew install clang-format`). A cold run parses about 800 SDK entities and takes a few minutes; later runs reuse the cache and take seconds. From CMake: configure with `-DCOCOON_REGENERATE=ON` and build the `cocoon_generate` target.

## Files

| File | Role |
|---|---|
| `generate.py` | The driver. Discovers classes, builds a model of each (constructors, properties, methods, signals, delegates, docs), writes headers and sources, then formats the whole project. |
| `typemap.py` | The type system. Turns an Objective-C type into a C++ type plus the conversion code in both directions. |
| `astdump.py` | The SDK reader: runs clang, caches its JSON AST, reads availability and doc comments from the headers, lists classes and constants. |
| `spec.py` | The curated part: everything the SDK headers cannot express (see below). |
| `skipped.txt` | Report written on every run: members that could not be mapped, grouped by reason. Committed so changes are visible in review. |

Not committed: `.cache/` (parsed ASTs, keyed by SDK version, a few hundred MB) and `__pycache__/`.

## How a run works

1. **Discover.** Every `@interface` in the AppKit and Foundation headers becomes a class, minus classes unavailable on macOS and `NSProxy` roots. The Foundation value types (`NSString`, `NSArray`, `NSDictionary`, `NSSet`, `NSData`) are mapped to standard types instead.
2. **Read.** For each class, clang dumps its AST (`-ast-dump=json` filtered by name). `astdump.py` merges the interface and its categories, and reads `API_AVAILABLE`, `API_DEPRECATED` and `NS_UNAVAILABLE` from the header text. Deprecated and unavailable members are skipped; members newer than the deployment target get an `@available` guard.
3. **Map types.** `typemap.py` resolves every type, following typedefs to the underlying type. Anything that cannot be mapped is skipped and logged; referenced classes outside the discovered set (for example Core Animation) are generated on demand.
4. **Model.** Properties become getters and setters, methods become methods or static factories, `init` methods become constructors, protocols named `...Delegate` and `...DataSource` become signals, and Objective-C generics become a `...Base` class plus a typed template.
5. **Write.** One header and one `.mm` per class, plus `enums.h`, `structs.h`, `constants.h` and the opaque handle types. Doc comments (with a usage example) are emitted next to each declaration.
6. **Format.** `clang-format` is run over `include/`, `src/` and `examples/` using the repository `.clang-format`, followed by a cleanup of blank lines at the start and end of namespaces.

## Type mapping

| Objective-C | C++ |
|---|---|
| `NSString *`, `const char *` | `std::string` |
| `NSArray<T *> *`, `NSSet` | `std::vector<T>` |
| `NSDictionary<NSString *, V> *` | `std::map<std::string, V>` (otherwise a vector of pairs) |
| `NSData *` | `std::vector<std::uint8_t>` |
| `id`, `id<Protocol>`, unavailable class pointers | `Object` |
| `NSFoo *` | the handle class `Foo` |
| `NS_ENUM`, `NS_OPTIONS` | `enum class` (option sets get `|`, `&` and `test_flag`) |
| C structs (`NSRange`, `CGAffineTransform`, ...) | plain structs; ones with bit-fields or arrays become opaque byte blobs |
| `CFxxxRef`, `CGxxxRef` | opaque handle classes |
| blocks | `std::function` (including blocks that take blocks and out-pointers) |
| function pointers | C++ function pointers (object arguments become `void*`) |
| `T *`, `T **` buffers | raw C++ pointers |
| `NSError **` | `cocoon::NativeError` exception |
| `SEL`, `Class` | `std::string` |
| variadic `...` | C++ variadic template over the `arguments:` sibling method |

Names: `NS` is dropped, methods use the first selector component (`add_item_with_title`), everything is `snake_case`, and members that collide with a type name or C++ keyword get a trailing underscore.

## Delegates and signals

For every property typed `id<SomeDelegate>` or `id<SomeDataSource>` the generator emits a hidden Objective-C delegate class that forwards each protocol method to a signal on the owning handle (`window.will_close()`). The delegate only responds to a selector while a callback is connected (`respondsToSelector:` is overridden), so AppKit's optional-method behavior is preserved, and the delegate is reinstalled when a callback is connected.

## spec.py

`SPEC` is a plain Python dictionary:

| Key | Meaning |
|---|---|
| `deploymentTarget` | Minimum macOS version; also decides which API gets availability guards. |
| `renames`, `enumPrefixes` | C++ names for enums and the prefix stripped from their constants. |
| `enums` | Enumerations declared by hand (for example `ControlState`, whose constants are plain integers in the SDK). |
| `skipClasses`, `classNames` | Classes to leave out, and overrides for generated class names. |
| `signalOverrides` | Name and arguments for a delegate selector (for example `windowDidResize:`). |
| `classes` | Curated additions per class, keyed by generated name (below). |
| `docs` | Hand-written brief and usage example for key classes. |

Each entry of `classes` can contain: `ns` (the Objective-C class), `alias` and `base` (a specialised subclass such as `CheckBox`), `ctors` (hand-written constructors with default arguments), `signals` (target-action and notification based signals), `extra` (convenience methods, each a C++ declaration plus an Objective-C++ body; `{cls}` and `{ns}` are substituted), `ctorBody`, `forward`, `includes`, `preamble`, `headerExtra` and `doc`.

## Adding or changing something

- A new convenience method: add an `extra` entry to the class in `spec.py`.
- A member is missing: look it up in `skipped.txt`; if its type cannot be mapped, extend `typemap.py`.
- Different naming or docs: `spec.py`.
- After any change, run the generator and build the library; the generated tree is committed.
