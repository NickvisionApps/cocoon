#pragma once

#include <cocoon.h>

namespace calculator
{
    class SettingsWindow : public cocoon::Window
    {
    public:
        explicit SettingsWindow(const cocoon::Application& application);
    };
}
