#include "main_menu.h"
#include "settings_window.h"

using namespace cocoon;

namespace calculator
{
    MainMenu::MainMenu(const std::string& application_name, const Application& application)
        : Menu{Menu::standard_menu_bar(application_name)}
    {
        Menu application_menu = item_at_index(0).submenu();
        MenuItem settings_item{"Settings\xE2\x80\xA6", "Cmd+,"};
        settings_item.triggered().connect([application]
        {
            SettingsWindow{application}.show();
        });
        application_menu.insert_item(settings_item, 2);
        application_menu.insert_item(MenuItem::separator(), 3);
    }
}
