/**
 * @example gallery/main.cpp
 * Gallery application: a MainWindow (unified titlebar, sidebar navigation, Liquid Glass, customizable toolbar),
 * a MainMenu with a Settings item, and a SettingsWindow with preference style toolbar panes.
 */
#include "main_menu.h"
#include "main_window.h"

using namespace cocoon;

int main(int argc, char** argv)
{
    Application app{argc, argv};
    app.set_name("Gallery");

    gallery::MainMenu menu{"Gallery", app};
    app.set_menu_bar(menu);

    gallery::MainWindow window;
    app.should_handle_reopen_has_visible_windows().connect([window](bool has_visible_windows)
    {
        if (!has_visible_windows)
        {
            window.show();
        }
        return true;
    });

    window.show();
    return app.exec();
}
