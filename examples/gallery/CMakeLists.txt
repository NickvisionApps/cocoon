add_executable(gallery MACOSX_BUNDLE
    main.cpp
    main_window.cpp
    main_menu.cpp
    helpers.cpp
    settings_window.cpp)
target_link_libraries(gallery PRIVATE cocoon::cocoon)
set_target_properties(gallery PROPERTIES
    MACOSX_BUNDLE_BUNDLE_NAME "Gallery"
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.cocoon.gallery")
