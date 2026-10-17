/**
 * @example calculator/main.cpp
 * Calculator application: a resizable MainWindow with a display and a Liquid Glass keypad, driven by a plain
 * C++ Engine, plus a MainMenu with a Settings item and a SettingsWindow with a light/dark theme picker.
 */
#include "main_menu.h"
#include "main_window.h"

using namespace cocoon;

int main(int argc, char** argv)
{
    Application app{argc, argv};
    app.set_name("Calculator");
    calculator::MainMenu menu{"Calculator", app};
    app.set_menu_bar(menu);

    calculator::MainWindow window;
    app.should_terminate_after_last_window_closed().connect([]
    {
        return true;
    });

    window.show();
    return app.exec();
}
