#pragma once

#include <cocoon.h>

namespace gallery
{
    class SettingsWindow : public cocoon::Window
    {
    public:
        explicit SettingsWindow(const cocoon::Application& application);

    private:
        static cocoon::View make_general_pane(const cocoon::Application& application);
        static cocoon::View make_advanced_pane();
        static cocoon::Toolbar make_toolbar(const cocoon::Window& window, const cocoon::TabView& pages);
    };
}
