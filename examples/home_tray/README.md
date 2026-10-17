# home_tray

A minimal macOS menu bar app written in C++ with cocoon.

## Build and run

```
cmake -S . -B build
cmake --build build --parallel --target home_tray
open build/examples/home_tray/home_tray.app
```

## What it shows

- an accessory app (`ActivationPolicy::Accessory`) with no Dock icon;
- a `StatusItem` in the system `StatusBar` with a folder symbol image;
- a `Menu` attached to the status item listing the non-hidden entries of the home directory.
