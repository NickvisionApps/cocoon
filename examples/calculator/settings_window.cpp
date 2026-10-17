#include "settings_window.h"

using namespace cocoon;

namespace calculator
{
    SettingsWindow::SettingsWindow(const Application& application)
        : Window{"Settings", {360, 100}, WindowStyle::Titled | WindowStyle::Closable | WindowStyle::Miniaturizable}
    {
        HStack row;
        row.set_spacing(12);
        Label label{"Theme:"};
        PopUpButton theme;
        theme.add_items_with_titles({"System", "Light", "Dark"});
        theme.select_item_at_index(0);
        row.add_arranged_subviews({label, theme});

        theme.selection_changed().connect([application](std::int64_t index)
        {
            if (index == 1)
            {
                application.set_appearance(Appearance::appearance_named(AppearanceName::aqua()));
            }
            else if (index == 2)
            {
                application.set_appearance(Appearance::appearance_named(AppearanceName::dark_aqua()));
            }
            else
            {
                application.set_appearance(Appearance{nullptr});
            }
        });

        View page;
        page.add_subview(row);
        LayoutConstraint::activate_constraints({
            row.center_x_anchor().constraint_equal_to_anchor(page.center_x_anchor()),
            row.center_y_anchor().constraint_equal_to_anchor(page.center_y_anchor()),
        });
        set_content(page);
    }
}
