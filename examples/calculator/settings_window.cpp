#include "settings_window.h"

using namespace cocoon;

namespace calculator
{
    SettingsWindow::SettingsWindow(const Application& application)
        : Window{"General", {480, 140}, WindowStyle::Titled | WindowStyle::Closable | WindowStyle::Miniaturizable}
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
            row.top_anchor().constraint_equal_to_anchor(page.top_anchor(), 24),
        });

        TabView pages;
        pages.set_tab_view_type(TabViewType::NoTabsNoBorder);
        pages.set_draws_background(false);
        pages.add_tab("general", page);
        set_content(pages);

        ToolbarItem general{"general", "General", "gearshape"};
        Toolbar toolbar{"com.cocoon.calculator.settings.toolbar"};
        toolbar.set_allows_user_customization(false);
        toolbar.set_autosaves_configuration(false);
        toolbar.add_flexible_space();
        toolbar.add_item(general);
        toolbar.add_flexible_space();
        toolbar.selectable_item_identifiers().connect([]
        {
            return std::vector<std::string>{"general"};
        });
        set_toolbar(toolbar);
        set_toolbar_style(ToolbarStyle::Preference);
        toolbar.set_selected_item_identifier("general");
    }
}
