add_executable(calculator MACOSX_BUNDLE
    main.cpp
    main_window.cpp
    main_menu.cpp
    settings_window.cpp
    engine.cpp)
target_link_libraries(calculator PRIVATE cocoon::cocoon)
set_target_properties(calculator PROPERTIES
    MACOSX_BUNDLE_BUNDLE_NAME "Calculator"
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.cocoon.calculator")
