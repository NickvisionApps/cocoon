add_executable(home_tray MACOSX_BUNDLE
    main.cpp)
target_link_libraries(home_tray PRIVATE cocoon::cocoon)
set_target_properties(home_tray PROPERTIES
    MACOSX_BUNDLE_BUNDLE_NAME "Home Tray"
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.cocoon.hometray")
