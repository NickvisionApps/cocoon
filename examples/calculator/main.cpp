/**
 * @example calculator/main.cpp
 * Calculator application: a resizable MainWindow with a display and a Liquid Glass keypad, driven by a plain
 * C++ Engine.
 */
#include "main_window.h"

using namespace cocoon;

int main(int argc, char** argv)
{
    Application app{argc, argv};
    app.set_name("Calculator");
    app.set_menu_bar(Menu::standard_menu_bar("Calculator"));

    calculator::MainWindow window;
    app.should_terminate_after_last_window_closed().connect([]
    {
        return true;
    });

    window.show();
    return app.exec();
}
