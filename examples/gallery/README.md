# gallery

A complete macOS app written entirely in C++ with cocoon. It doubles as a reference for how the library is meant to be used.

## Build and run

The gallery is built along with the library (`COCOON_BUILD_EXAMPLES` is `ON` by default):

```
cmake -S . -B build
cmake --build build --parallel --target gallery
open build/examples/gallery/gallery.app
```

## What it shows

- a unified titlebar window with a full-size content view, a sidebar `SplitViewController` and sidebar-driven navigation;
- Liquid Glass surfaces (`GlassEffectView`, `GlassEffectContainerView`);
- a customizable, autosaved toolbar (identifiers, allowed and required items, a search field);
- the standard menu bar (App, File, Edit, View, Window, Help) plus a **Settings…** item;
- a Settings window with a preference-style toolbar, General and Advanced panes, and a theme picker (System, Light, Dark) that changes the app's appearance immediately;
- reopening the window from the Dock icon;
- subclassing a handle class (`SettingsWindow : public cocoon::Window`).

## Source

| File | Role |
|---|---|
| `main.cpp` | Application setup and run loop |
| `main_window.*` | The main window, sidebar and content |
| `settings_window.*` | The Settings window and its panes |
| `main_menu.*` | The menu bar |
| `helpers.*` | Small shared UI helpers |

## State

Window frame, split view and toolbar state are saved by AppKit in `~/Library/Preferences/com.cocoon.gallery.plist`.
