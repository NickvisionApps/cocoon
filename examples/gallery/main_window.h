#pragma once

#include <cocoon.h>

namespace gallery
{
    class MainWindow : public cocoon::Window
    {
    public:
        MainWindow();

    private:
        static cocoon::View make_controls_page();
        static cocoon::View make_glass_page();
        static cocoon::View make_table_page();
        static cocoon::Toolbar make_toolbar();
    };
}
