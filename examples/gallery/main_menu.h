#pragma once

#include <cocoon.h>
#include <string>

namespace gallery
{
    class MainMenu : public cocoon::Menu
    {
    public:
        MainMenu(const std::string& application_name, const cocoon::Application& application);
    };
}
