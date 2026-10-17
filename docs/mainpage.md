# cocoon {#mainpage}

A C++20 wrapper over modern AppKit (macOS 26+, Liquid Glass included). Public headers are pure C++; the implementation is Objective-C++.

## Getting started

```cpp
#include <cocoon.h>

int main(int argc, char** argv)
{
    cocoon::Application app(argc, argv);
    cocoon::Window window("Hello", {480, 320});
    cocoon::VStack stack;
    cocoon::Button button("Click me");
    stack.add_arranged_subview(button);
    button.clicked().connect([] {});
    window.set_content(stack);
    window.show();
    return app.exec();
}
```

Link `cocoon::cocoon` from CMake:

```cmake
add_subdirectory(cocoon)
target_link_libraries(my_app PRIVATE cocoon::cocoon)
```

## Concepts

- **Handles** – every class is a cheap copyable handle around a retained native object (see cocoon::Object). Copies share the same instance; lifetime follows AppKit reference counting. A visible cocoon::Window stays alive until it is closed.
- **Naming** – the `NS` prefix is dropped (`NSButton` is cocoon::Button), methods are `snake_case`, getters/setters come from properties (`title()` / `set_title()`), static factories are static methods.
- **Signals** – events are exposed as accessors returning cocoon::Signal: `button.clicked().connect(...)`. Delegates and data sources are generated from the SDK protocols; a delegate method only counts as implemented while a callback is connected. Use cocoon::WeakRef to capture a control inside a callback without a retain cycle.
- **Types** – `NSString`, `NSArray`, `NSDictionary`, `NSSet`, `NSData` become `std::string`, `std::vector`, `std::map`, `std::vector`, `std::vector<std::uint8_t>`; `id` is cocoon::Object; blocks are `std::function`; C structs are plain structs; `NSError**` becomes cocoon::NativeError.
- **Generics** – Objective-C generic classes generate a `...Base` class plus a typed template (for example cocoon::DiffableDataSourceSnapshot).
- **Constants** – named SDK constants are grouped by type, for example `cocoon::AppearanceName::aqua()`.

## Generated code

`generator/generate.py` reads the SDK headers through clang and writes `include/generated` and `src/generated`. Curated additions live in `generator/spec.py`; unmapped members are listed in `generator/skipped.txt`.

## Building the documentation

```
cmake -S . -B build
cmake --build build --target docs
```

or run `doxygen Doxyfile` in the repository root. The HTML output is written to `docs/html`.
