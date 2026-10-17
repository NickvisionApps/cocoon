# calculator

A small macOS calculator written entirely in C++ with cocoon.

## Build and run

The calculator is built along with the library (`COCOON_BUILD_EXAMPLES` is `ON` by default):

```
cmake -S . -B build
cmake --build build --parallel --target calculator
open build/examples/calculator/calculator.app
```

## What it shows

- a resizable unified titlebar window whose content is built from nested `VStack` and `HStack` views;
- Liquid Glass buttons (`BezelStyle::Glass`) with tinted operator keys;
- a monospaced digit display `Label`;
- button `clicked()` signals capturing handles and shared state;
- a settings window (Cmd+,) with a System/Light/Dark theme picker applied through `Application::set_appearance`;
- UI-independent logic in a plain C++ class (`Engine`).

## Source

| File | Role |
|---|---|
| `main.cpp` | Application setup and run loop |
| `main_window.*` | The window, display and keypad |
| `main_menu.*` | Menu bar with the Settings item |
| `settings_window.*` | Settings window with the theme picker |
| `engine.*` | Calculator state and arithmetic |
