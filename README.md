# cocoon

A C++20 wrapper over modern AppKit (macOS 26+, Liquid Glass included), implemented in Objective-C++. The public headers are pure C++ and never expose Objective-C, so an application can be written entirely in C++ without a single `.mm` file.

```cpp
#include <cocoon.h>

using namespace cocoon;

int main(int argc, char** argv)
{
    Application app{argc, argv};
    Window window{"Hello", {480, 320}};
    VStack stack;
    Button button{"Click me"};
    stack.add_arranged_subview(button);
    button.clicked().connect([] {});
    window.set_content(stack);
    window.show();
    return app.exec();
}
```

## Requirements

- macOS 26 or newer
- Xcode 26 (the macOS 26 SDK)
- CMake 3.24 or newer
- Optional: Python 3 and `clang-format` to regenerate the bindings and format the sources, Doxygen to build the API documentation (`brew install clang-format doxygen`)

## Design

cocoon exists to make AppKit feel native in C++: the full framework surface, with C++ types, C++ naming and C++ lifetimes, and nothing Objective-C leaking through the headers.

- **Handles.** Every class is a cheap copyable handle (one pointer) around a retained native object. Copies share the native object and AppKit's reference counting owns its lifetime. A visible `Window` stays alive until it is closed.
- **Naming.** Class names drop the `NS` prefix (`NSToolbarItem` is `ToolbarItem`, `NSURL` is `URL`). Methods are `snake_case`; properties become `title()` and `set_title(...)`; factories are static methods; initializers are constructors.
- **Types.** Foundation collections and strings map to the standard library (`NSString` to `std::string`, `NSArray` to `std::vector`, `NSDictionary` to `std::map`, `NSData` to `std::vector<std::uint8_t>`). `id` maps to `Object`, blocks to `std::function`, C structs to plain structs and option sets to enums with `|` and `test_flag`. Constants are grouped by type (`AppearanceName::aqua()`, `FontWeight::bold()`).
- **Errors.** `NSError**` out-parameters become a `cocoon::NativeError` exception.
- **Signals.** Events are accessors returning `Signal<Sender, R(Args...)>`: `button.clicked().connect([](Button& sender) {})`, or without the sender argument. Delegate and data source methods are signals too, and a method only counts as implemented while a callback is connected. Callbacks live on the native object, so capture handles with `WeakRef<T>` to avoid retain cycles.
- **Controllers.** `ViewController` and `NSWindowController` are handled implicitly: a `View` converts to a `ViewController` wherever one is needed (`window.set_content(view)`).
- **Generics.** Objective-C generic classes produce an untyped `...Base` class plus a typed template, for example `DiffableDataSourceSnapshot<Section, Item>`.
- **Extending.** Handle classes can be derived from, as the gallery does (`class SettingsWindow : public cocoon::Window`). Copies slice to the base handle and share the native object, so callbacks should capture handles, not `this`.

## Build and installation

Build the static library `cocoon::cocoon` (and the example applications):

```
cmake -S . -B build
cmake --build build --parallel
```

The first build compiles about 580 classes, so it takes a few minutes.

| Option | Default | Meaning |
|---|---|---|
| `COCOON_BUILD_EXAMPLES` | `ON` | Build the example applications |
| `COCOON_REGENERATE` | `OFF` | Add a `cocoon_generate` target that reruns the generator |

Install the library, headers and CMake package files:

```
cmake --install build --prefix /usr/local
```

### Using cocoon from CMake

After installing, find the package and link the imported target:

```cmake
find_package(cocoon REQUIRED)
target_link_libraries(my_app PRIVATE cocoon::cocoon)
```

If the install prefix is not on the default search path, pass `-DCMAKE_PREFIX_PATH=<prefix>` when configuring your project.

To build cocoon as part of your project instead, add it as a subdirectory:

```cmake
add_subdirectory(cocoon)
target_link_libraries(my_app PRIVATE cocoon::cocoon)
```

Either way the target brings in C++20, the include directory and the AppKit, Foundation, CoreFoundation, UniformTypeIdentifiers, QuartzCore, CoreImage and CoreGraphics frameworks.

### SDK versions

cocoon supports macOS 26 and newer. API that only exists in a later SDK is wrapped in a macro named after the major version, `COCOON_MACOS_27` for macOS 27 and so on. Everything up to the minimum (26) is always available and is never wrapped.

```cpp
#ifdef COCOON_MACOS_27
event.some_new_api();
#endif
```

The macros are defined in `generated/availability.h` and are on when the SDK major version is at least that number. CMake detects the SDK being used (`CMAKE_OSX_SYSROOT`) and passes it as `COCOON_SDK_MAJOR` to cocoon and, through the imported target, to every project that links it, so the library and your code always agree on which macros are on. Without CMake the macros fall back to `__MAC_OS_X_VERSION_MAX_ALLOWED`. Wrapped members also check `@available` at run time, so a build made with a newer SDK still runs on macOS 26.

### Formatting

When `clang-format` is installed, building cocoon first runs the `cocoon_format` target, which formats the hand-written headers, sources and examples (generated files are formatted by the generator). Turn it off with `-DCOCOON_FORMAT=OFF`.

## Examples

`examples/gallery` is a complete application that exercises much of the library: a unified titlebar window with a sidebar, Liquid Glass surfaces, a customizable toolbar, the standard menu bar and a Settings window. It is built by default and lands in `build/examples/gallery/gallery.app`; see its own [README](examples/gallery/README.md) for details.

`examples/calculator` is a small calculator with a Liquid Glass keypad, a resizable window and its logic in a plain C++ class. It lands in `build/examples/calculator/calculator.app`; see its own [README](examples/calculator/README.md).
