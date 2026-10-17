#include "main_window.h"

using namespace cocoon;

namespace gallery
{
    MainWindow::MainWindow()
        : Window{
              "Gallery",
              {960, 640},
              WindowStyle::Titled | WindowStyle::Closable | WindowStyle::Miniaturizable | WindowStyle::Resizable |
                  WindowStyle::FullSizeContentView}
    {
        set_titlebar_appears_transparent(true);
        set_title_visibility(TitleVisibility::Hidden);

        SplitViewController split;
        split.split_view().set_autosave_name("GallerySplitView.v2");

        SidebarList sidebar;
        sidebar.set_items({
            {1, "Controls", "slider.horizontal.3"},
            {2, "Glass", "sparkles"},
            {3, "Table", "tablecells"},
        });
        SplitViewItem sidebar_item = split.add_sidebar(sidebar, 200, 400);
        sidebar_item.set_preferred_thickness_fraction(0.25);

        TabView pages;
        pages.set_tab_view_type(TabViewType::NoTabsNoBorder);
        pages.set_draws_background(false);
        pages.add_tab("Controls", make_controls_page());
        pages.add_tab("Glass", make_glass_page());
        pages.add_tab("Table", make_table_page());
        split.add_content(pages);

        sidebar.selection_changed().connect([pages](int id)
        {
            pages.set_current_index(id - 1);
        });
        sidebar.select_item(1);

        set_content(split);
        set_toolbar(make_toolbar());
        set_toolbar_style(ToolbarStyle::Unified);
        set_frame_autosave_name("GalleryMainWindow");
    }

    View MainWindow::make_controls_page()
    {
        VStack controls;
        controls.set_spacing(12);
        controls.set_edge_insets(Insets{24});
        controls.set_alignment(LayoutAttribute::Leading);

        Label title{"Controls"};
        title.set_font(Font::bold_system_font_of_size(24));
        Button button{"Click me"};
        button.set_bezel_style(BezelStyle::Push);
        CheckBox check{"Enable feature"};
        Switch toggle;
        TextField field;
        field.set_placeholder_string("Type something");
        Slider slider{0, 100, 25};
        ProgressIndicator progress;
        progress.set_max_value(100);
        PopUpButton popup;
        popup.add_items_with_titles({"Small", "Medium", "Large"});
        Label status{"Ready"};

        for (const View& view :
             {View{title},
              View{button},
              View{check},
              View{toggle},
              View{field},
              View{slider},
              View{progress},
              View{popup},
              View{status}})
        {
            controls.add_arranged_subview(view);
        }

        button.clicked().connect([status]
        {
            status.set_string_value("Button clicked");
        });
        check.toggled().connect([status](bool on)
        {
            status.set_string_value(on ? "Feature on" : "Feature off");
        });
        toggle.toggled().connect([status](bool on)
        {
            status.set_string_value(on ? "Switch on" : "Switch off");
        });
        field.text_changed().connect([status](const std::string& text)
        {
            status.set_string_value("Text: " + text);
        });
        slider.value_changed().connect([progress](double value)
        {
            progress.set_double_value(value);
        });
        popup.selection_changed().connect([status](std::int64_t index)
        {
            status.set_string_value("Size " + std::to_string(index));
        });

        View page;
        page.add_subview(controls);
        controls.pin_to_safe_area();
        return page;
    }

    View MainWindow::make_glass_page()
    {
        View page;
        VisualEffectView backdrop;
        backdrop.set_material(VisualEffectMaterial::Sidebar);
        page.add_subview(backdrop);
        backdrop.pin_to_superview();

        GlassEffectContainerView container;
        container.set_spacing(24);
        page.add_subview(container);
        container.pin_to_superview(Insets{80});

        HStack content;
        content.set_spacing(16);
        content.set_edge_insets(Insets{16});
        Button glass_button{"Glass"};
        glass_button.set_bezel_style(BezelStyle::Glass);
        Button more_button{"Buttons"};
        more_button.set_bezel_style(BezelStyle::Glass);
        content.add_arranged_subview(glass_button);
        content.add_arranged_subview(more_button);

        GlassEffectView glass;
        glass.set_corner_radius(20);
        glass.set_content_view(content);
        container.set_content_view(glass);
        return page;
    }

    View MainWindow::make_table_page()
    {
        TableList table;
        table.set_columns({"Name", "Kind"});
        table.set_rows({{"Button", "Control"}, {"Slider", "Control"}, {"Glass", "Effect"}});
        return table;
    }

    Toolbar MainWindow::make_toolbar()
    {
        Toolbar toolbar{"com.cocoon.gallery.toolbar.v2"};
        toolbar.set_display_mode(ToolbarDisplayMode::IconOnly);
        toolbar.add_flexible_space();
        toolbar.add_sidebar_toggle();
        toolbar.add_sidebar_tracking_separator();
        toolbar.add_button(
            "add",
            "Add",
            "plus",
            []
        {
            Alert{"Add item", "This is an alert."}.exec();
        });
        toolbar.add_allowed_item(ToolbarItem{"favorite", "Favorite", "star"});
        toolbar.add_flexible_space();
        toolbar.add_search_field("search");
        toolbar.set_allows_user_customization(true);
        toolbar.set_autosaves_configuration(true);
        return toolbar;
    }
}
