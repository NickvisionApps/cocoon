#include "helpers.h"
#include "settings_window.h"

using namespace cocoon;

namespace gallery
{
    namespace
    {
        const Size pane_size{480, 140};
    }

    SettingsWindow::SettingsWindow(const Application& application)
        : Window{"General", pane_size, WindowStyle::Titled | WindowStyle::Closable | WindowStyle::Miniaturizable}
    {
        TabView pages;
        pages.set_tab_view_type(TabViewType::NoTabsNoBorder);
        pages.set_draws_background(false);
        pages.add_tab("general", top_centered_page(make_general_pane(application)));
        pages.add_tab("advanced", top_centered_page(make_advanced_pane()));
        set_content(pages);

        Toolbar toolbar = make_toolbar(*this, pages);
        set_toolbar(toolbar);
        set_toolbar_style(ToolbarStyle::Preference);
        toolbar.set_selected_item_identifier("general");
    }

    View SettingsWindow::make_general_pane(const Application& application)
    {
        VStack pane;
        pane.set_spacing(12);
        pane.set_alignment(LayoutAttribute::CenterX);

        HStack row;
        row.set_spacing(12);
        Label label{"Theme:"};
        PopUpButton theme;
        theme.add_items_with_titles({"System", "Light", "Dark"});
        theme.select_item_at_index(0);
        row.add_arranged_subviews({label, theme});
        pane.add_arranged_subview(row);

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
        return pane;
    }

    View SettingsWindow::make_advanced_pane()
    {
        return VStack();
    }

    Toolbar SettingsWindow::make_toolbar(const Window& window, const TabView& pages)
    {
        WeakRef<Window> weak_window{window};

        ToolbarItem general{"general", "General", "gearshape"};
        general.clicked().connect([weak_window, pages]
        {
            pages.set_current_index(0);
            Window target = weak_window.lock();
            target.set_title("General");
            target.set_content_size(pane_size);
        });

        ToolbarItem advanced{"advanced", "Advanced", "gearshape.2"};
        advanced.clicked().connect([weak_window, pages]
        {
            pages.set_current_index(1);
            Window target = weak_window.lock();
            target.set_title("Advanced");
            target.set_content_size(pane_size);
        });

        Toolbar toolbar{"com.cocoon.gallery.settings.toolbar"};
        toolbar.set_allows_user_customization(false);
        toolbar.set_autosaves_configuration(false);
        toolbar.add_flexible_space();
        toolbar.add_item(general);
        toolbar.add_item(advanced);
        toolbar.add_flexible_space();
        toolbar.selectable_item_identifiers().connect([]
        {
            return std::vector<std::string>{"general", "advanced"};
        });
        return toolbar;
    }
}
