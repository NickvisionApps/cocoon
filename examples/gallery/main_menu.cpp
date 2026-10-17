#include "main_menu.h"
#include "settings_window.h"

using namespace cocoon;

namespace gallery
{
    MainMenu::MainMenu(const std::string& application_name, const Application& application)
        : Menu{Menu::standard_menu_bar(application_name)}
    {
        Menu file = find_menu("File");
        MenuItem new_item{"New Window", "Cmd+N"};
        new_item.triggered().connect([]
        {
            Alert{"New Window", "Not implemented in this example."}.exec();
        });
        MenuItem open_item{"Open...", "Cmd+O"};
        open_item.triggered().connect([]
        {
            OpenPanel::open_panel().run_modal();
        });
        file.insert_item(new_item, 0);
        file.insert_item(open_item, 1);
        file.insert_item(MenuItem::separator(), 2);

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
