/**
 * @example home_tray/main.cpp
 * Home Tray application: a menu bar item with a folder icon whose menu lists the files in the user's home
 * directory.
 */
#include <algorithm>
#include <cocoon.h>

using namespace cocoon;

int main(int argc, char** argv)
{
    Application app{argc, argv};
    app.set_name("Home Tray");
    app.set_activation_policy(ActivationPolicy::Accessory);

    StatusItem status_item{StatusBar::system_status_bar().status_item_with_length(-1)};
    status_item.button().set_image(Image::symbol("folder", "Home folder"));

    Menu menu;
    std::vector<std::string> names{FileManager::default_manager().contents_of_directory_at_path(
        FileManager::default_manager().home_directory_for_current_user().file_system_representation())};
    std::sort(names.begin(), names.end());
    for (const std::string& name : names)
    {
        if (name.front() != '.')
        {
            menu.add_item(name);
        }
    }
    menu.add_separator();
    menu.add_item(
        "Quit",
        "Cmd+Q",
        [app]
    {
        app.terminate(Object{nullptr});
    });
    status_item.set_menu(menu);

    return app.exec();
}
