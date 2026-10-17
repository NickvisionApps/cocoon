#include "generated/menu.h"
#include "internal.h"

@interface AKMenuDelegate : NSObject <NSMenuDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKMenuDelegate

- (void)menuNeedsUpdate:(NSMenu*)menu
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Menu, void()>::emit((__bridge void*)strongHost, "needs_update");
}

- (NSInteger)numberOfItemsInMenu:(NSMenu*)menu
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Menu, std::int64_t()>::emit((__bridge void*)strongHost, "number_of_items_in_menu");
    return static_cast<::NSInteger>(__r);
}

- (BOOL)menu:(NSMenu*)menu updateItem:(NSMenuItem*)item atIndex:(NSInteger)index shouldCancel:(BOOL)shouldCancel
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Menu, bool(cocoon::MenuItem, std::int64_t, bool)>::emit((__bridge void*)strongHost, "update_item_at_index_should_cancel", cocoon::internal::wrap<cocoon::MenuItem>(item), static_cast<std::int64_t>(index), static_cast<bool>(shouldCancel));
    return static_cast<::BOOL>(__r);
}

- (void)menuWillOpen:(NSMenu*)menu
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Menu, void()>::emit((__bridge void*)strongHost, "will_open");
}

- (void)menuDidClose:(NSMenu*)menu
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Menu, void()>::emit((__bridge void*)strongHost, "did_close");
}

- (void)menu:(NSMenu*)menu willHighlightItem:(NSMenuItem*)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Menu, void(cocoon::MenuItem)>::emit((__bridge void*)strongHost, "will_highlight_item", cocoon::internal::wrap<cocoon::MenuItem>(item));
}

- (NSRect)confinementRectForMenu:(NSMenu*)menu onScreen:(NSScreen*)screen
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Menu, cocoon::Rect(cocoon::Screen)>::emit((__bridge void*)strongHost, "confinement_rect_for_menu_on_screen", cocoon::internal::wrap<cocoon::Screen>(screen));
    return cocoon::internal::to(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(menuNeedsUpdate:))
    {
        return strongHost && cocoon::Signal<cocoon::Menu, void()>::connected((__bridge void*)strongHost, "needs_update");
    }
    if (selector == @selector(numberOfItemsInMenu:))
    {
        return strongHost && cocoon::Signal<cocoon::Menu, std::int64_t()>::connected((__bridge void*)strongHost, "number_of_items_in_menu");
    }
    if (selector == @selector(menu:updateItem:atIndex:shouldCancel:))
    {
        return strongHost && cocoon::Signal<cocoon::Menu, bool(cocoon::MenuItem, std::int64_t, bool)>::connected((__bridge void*)strongHost, "update_item_at_index_should_cancel");
    }
    if (selector == @selector(menuWillOpen:))
    {
        return strongHost && cocoon::Signal<cocoon::Menu, void()>::connected((__bridge void*)strongHost, "will_open");
    }
    if (selector == @selector(menuDidClose:))
    {
        return strongHost && cocoon::Signal<cocoon::Menu, void()>::connected((__bridge void*)strongHost, "did_close");
    }
    if (selector == @selector(menu:willHighlightItem:))
    {
        return strongHost && cocoon::Signal<cocoon::Menu, void(cocoon::MenuItem)>::connected((__bridge void*)strongHost, "will_highlight_item");
    }
    if (selector == @selector(confinementRectForMenu:onScreen:))
    {
        return strongHost && cocoon::Signal<cocoon::Menu, cocoon::Rect(cocoon::Screen)>::connected((__bridge void*)strongHost, "confinement_rect_for_menu_on_screen");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    Menu::Menu(const std::string& title) : Menu(Adopt{cocoon::internal::retain([[NSMenu alloc] initWithTitle:cocoon::internal::to(title)])})
    {
        Menu::install_delegate_delegate_(handle());
    }

    Menu::Menu(std::nullptr_t) : Object(nullptr)
    {
    }

    Menu::Menu(Adopt adopt) : Object(adopt)
    {
    }

    void Menu::add_item(const MenuItem& new_item) const
    {
        [cocoon::internal::ns<::NSMenu>(this) addItem:cocoon::internal::native<::NSMenuItem>(new_item)];
    }

    MenuItem Menu::add_item_with_title(const std::string& string, const std::string& selector, const std::string& char_code) const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSMenu>(this) addItemWithTitle:cocoon::internal::to(string) action:NSSelectorFromString(cocoon::internal::to(selector)) keyEquivalent:cocoon::internal::to(char_code)]);
    }

    void Menu::cancel_tracking() const
    {
        [cocoon::internal::ns<::NSMenu>(this) cancelTracking];
    }

    void Menu::cancel_tracking_without_animation() const
    {
        [cocoon::internal::ns<::NSMenu>(this) cancelTrackingWithoutAnimation];
    }

    std::int64_t Menu::index_of_item(const MenuItem& item) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMenu>(this) indexOfItem:cocoon::internal::native<::NSMenuItem>(item)]);
    }

    std::int64_t Menu::index_of_item_with_represented_object(const Object& object) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMenu>(this) indexOfItemWithRepresentedObject:cocoon::internal::native_id(object)]);
    }

    std::int64_t Menu::index_of_item_with_submenu(const Menu& submenu) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMenu>(this) indexOfItemWithSubmenu:cocoon::internal::native<::NSMenu>(submenu)]);
    }

    std::int64_t Menu::index_of_item_with_tag(std::int64_t tag) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMenu>(this) indexOfItemWithTag:static_cast<::NSInteger>(tag)]);
    }

    std::int64_t Menu::index_of_item_with_target(const Object& target, const std::string& action_selector) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMenu>(this) indexOfItemWithTarget:cocoon::internal::native_id(target) andAction:NSSelectorFromString(cocoon::internal::to(action_selector))]);
    }

    std::int64_t Menu::index_of_item_with_title(const std::string& title) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMenu>(this) indexOfItemWithTitle:cocoon::internal::to(title)]);
    }

    void Menu::insert_item(const MenuItem& new_item, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSMenu>(this) insertItem:cocoon::internal::native<::NSMenuItem>(new_item) atIndex:static_cast<::NSInteger>(index)];
    }

    MenuItem Menu::insert_item_with_title(const std::string& string, const std::string& selector, const std::string& char_code, std::int64_t index) const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSMenu>(this) insertItemWithTitle:cocoon::internal::to(string) action:NSSelectorFromString(cocoon::internal::to(selector)) keyEquivalent:cocoon::internal::to(char_code) atIndex:static_cast<::NSInteger>(index)]);
    }

    MenuItem Menu::item_at_index(std::int64_t index) const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSMenu>(this) itemAtIndex:static_cast<::NSInteger>(index)]);
    }

    void Menu::item_changed(const MenuItem& item) const
    {
        [cocoon::internal::ns<::NSMenu>(this) itemChanged:cocoon::internal::native<::NSMenuItem>(item)];
    }

    MenuItem Menu::item_with_tag(std::int64_t tag) const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSMenu>(this) itemWithTag:static_cast<::NSInteger>(tag)]);
    }

    MenuItem Menu::item_with_title(const std::string& title) const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSMenu>(this) itemWithTitle:cocoon::internal::to(title)]);
    }

    bool Menu::menu_bar_visible()
    {
        return static_cast<bool>([::NSMenu menuBarVisible]);
    }

    Menu Menu::palette_menu_with_colors(const std::vector<Color>& colors, const std::vector<std::string>& item_titles, std::function<void(Menu)> on_selection_change)
    {
        return cocoon::internal::wrap<Menu>([::NSMenu paletteMenuWithColors:cocoon::internal::to_array(colors, [](const Color& e) -> id
                                                                                                       {
                                                                                                           return cocoon::internal::native<::NSColor>(e);
                                                                                                       })
                                                                     titles:cocoon::internal::to_array(item_titles, [](const std::string& e) -> id
                                                                                                       {
                                                                                                           return cocoon::internal::to(e);
                                                                                                       })
                                                           selectionHandler:(on_selection_change ? (void (^)(::NSMenu*)) ^ void(::NSMenu * a63_0) { on_selection_change(cocoon::internal::wrap<Menu>(a63_0)); } : (void (^)(::NSMenu*))nil)]);
    }

    Menu Menu::palette_menu_with_colors(const std::vector<Color>& colors, const std::vector<std::string>& item_titles, const Image& image, std::function<void(Menu)> on_selection_change)
    {
        return cocoon::internal::wrap<Menu>([::NSMenu paletteMenuWithColors:cocoon::internal::to_array(colors, [](const Color& e) -> id
                                                                                                       {
                                                                                                           return cocoon::internal::native<::NSColor>(e);
                                                                                                       })
                                                                     titles:cocoon::internal::to_array(item_titles, [](const std::string& e) -> id
                                                                                                       {
                                                                                                           return cocoon::internal::to(e);
                                                                                                       })
                                                              templateImage:cocoon::internal::native<::NSImage>(image)
                                                           selectionHandler:(on_selection_change ? (void (^)(::NSMenu*)) ^ void(::NSMenu * a64_0) { on_selection_change(cocoon::internal::wrap<Menu>(a64_0)); } : (void (^)(::NSMenu*))nil)]);
    }

    void Menu::perform_action_for_item_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSMenu>(this) performActionForItemAtIndex:static_cast<::NSInteger>(index)];
    }

    bool Menu::perform_key_equivalent(const Event& event) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenu>(this) performKeyEquivalent:cocoon::internal::native<::NSEvent>(event)]);
    }

    void Menu::pop_up_context_menu(const Menu& menu, const Event& event, const View& view)
    {
        [::NSMenu popUpContextMenu:cocoon::internal::native<::NSMenu>(menu) withEvent:cocoon::internal::native<::NSEvent>(event) forView:cocoon::internal::native<::NSView>(view)];
    }

    void Menu::pop_up_context_menu(const Menu& menu, const Event& event, const View& view, const Font& font)
    {
        [::NSMenu popUpContextMenu:cocoon::internal::native<::NSMenu>(menu) withEvent:cocoon::internal::native<::NSEvent>(event) forView:cocoon::internal::native<::NSView>(view) withFont:cocoon::internal::native<::NSFont>(font)];
    }

    bool Menu::pop_up_menu_positioning_item(const MenuItem& item, const Point& location, const View& view) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenu>(this) popUpMenuPositioningItem:cocoon::internal::native<::NSMenuItem>(item) atLocation:cocoon::internal::to(location) inView:cocoon::internal::native<::NSView>(view)]);
    }

    void Menu::remove_all_items() const
    {
        [cocoon::internal::ns<::NSMenu>(this) removeAllItems];
    }

    void Menu::remove_item(const MenuItem& item) const
    {
        [cocoon::internal::ns<::NSMenu>(this) removeItem:cocoon::internal::native<::NSMenuItem>(item)];
    }

    void Menu::remove_item_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSMenu>(this) removeItemAtIndex:static_cast<::NSInteger>(index)];
    }

    void Menu::set_menu_bar_visible(bool visible)
    {
        [::NSMenu setMenuBarVisible:static_cast<::BOOL>(visible)];
    }

    void Menu::set_submenu(const Menu& menu, const MenuItem& item) const
    {
        [cocoon::internal::ns<::NSMenu>(this) setSubmenu:cocoon::internal::native<::NSMenu>(menu) forItem:cocoon::internal::native<::NSMenuItem>(item)];
    }

    void Menu::submenu_action(const Object& sender) const
    {
        [cocoon::internal::ns<::NSMenu>(this) submenuAction:cocoon::internal::native_id(sender)];
    }

    void Menu::update() const
    {
        [cocoon::internal::ns<::NSMenu>(this) update];
    }

    bool Menu::allows_context_menu_plug_ins() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenu>(this) allowsContextMenuPlugIns]);
    }

    void Menu::set_allows_context_menu_plug_ins(bool value) const
    {
        [cocoon::internal::ns<::NSMenu>(this) setAllowsContextMenuPlugIns:static_cast<::BOOL>(value)];
    }

    bool Menu::autoenables_items() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenu>(this) autoenablesItems]);
    }

    void Menu::set_autoenables_items(bool value) const
    {
        [cocoon::internal::ns<::NSMenu>(this) setAutoenablesItems:static_cast<::BOOL>(value)];
    }

    bool Menu::automatically_inserts_writing_tools_items() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenu>(this) automaticallyInsertsWritingToolsItems]);
    }

    void Menu::set_automatically_inserts_writing_tools_items(bool value) const
    {
        [cocoon::internal::ns<::NSMenu>(this) setAutomaticallyInsertsWritingToolsItems:static_cast<::BOOL>(value)];
    }

    Font Menu::font() const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSMenu>(this) font]);
    }

    void Menu::set_font(const Font& value) const
    {
        [cocoon::internal::ns<::NSMenu>(this) setFont:cocoon::internal::native<::NSFont>(value)];
    }

    MenuItem Menu::highlighted_item() const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSMenu>(this) highlightedItem]);
    }

    std::vector<MenuItem> Menu::item_array() const
    {
        return cocoon::internal::from_array<MenuItem>([cocoon::internal::ns<::NSMenu>(this) itemArray], [](id e) -> MenuItem
                                                      {
                                                          return cocoon::internal::wrap<MenuItem>((::NSMenuItem*)e);
                                                      });
    }

    void Menu::set_item_array(const std::vector<MenuItem>& value) const
    {
        [cocoon::internal::ns<::NSMenu>(this) setItemArray:cocoon::internal::to_array(value, [](const MenuItem& e) -> id
                                                                                      {
                                                                                          return cocoon::internal::native<::NSMenuItem>(e);
                                                                                      })];
    }

    double Menu::menu_bar_height() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMenu>(this) menuBarHeight]);
    }

    double Menu::minimum_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMenu>(this) minimumWidth]);
    }

    void Menu::set_minimum_width(double value) const
    {
        [cocoon::internal::ns<::NSMenu>(this) setMinimumWidth:static_cast<::CGFloat>(value)];
    }

    std::int64_t Menu::number_of_items() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMenu>(this) numberOfItems]);
    }

    MenuPresentationStyle Menu::presentation_style() const
    {
        return static_cast<MenuPresentationStyle>([cocoon::internal::ns<::NSMenu>(this) presentationStyle]);
    }

    void Menu::set_presentation_style(MenuPresentationStyle value) const
    {
        [cocoon::internal::ns<::NSMenu>(this) setPresentationStyle:static_cast<::NSMenuPresentationStyle>(value)];
    }

    MenuProperties Menu::properties_to_update() const
    {
        return static_cast<MenuProperties>([cocoon::internal::ns<::NSMenu>(this) propertiesToUpdate]);
    }

    std::vector<MenuItem> Menu::selected_items() const
    {
        return cocoon::internal::from_array<MenuItem>([cocoon::internal::ns<::NSMenu>(this) selectedItems], [](id e) -> MenuItem
                                                      {
                                                          return cocoon::internal::wrap<MenuItem>((::NSMenuItem*)e);
                                                      });
    }

    void Menu::set_selected_items(const std::vector<MenuItem>& value) const
    {
        [cocoon::internal::ns<::NSMenu>(this) setSelectedItems:cocoon::internal::to_array(value, [](const MenuItem& e) -> id
                                                                                          {
                                                                                              return cocoon::internal::native<::NSMenuItem>(e);
                                                                                          })];
    }

    MenuSelectionMode Menu::selection_mode() const
    {
        return static_cast<MenuSelectionMode>([cocoon::internal::ns<::NSMenu>(this) selectionMode]);
    }

    void Menu::set_selection_mode(MenuSelectionMode value) const
    {
        [cocoon::internal::ns<::NSMenu>(this) setSelectionMode:static_cast<::NSMenuSelectionMode>(value)];
    }

    bool Menu::shows_state_column() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenu>(this) showsStateColumn]);
    }

    void Menu::set_shows_state_column(bool value) const
    {
        [cocoon::internal::ns<::NSMenu>(this) setShowsStateColumn:static_cast<::BOOL>(value)];
    }

    Size Menu::size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMenu>(this) size]);
    }

    Menu Menu::supermenu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSMenu>(this) supermenu]);
    }

    void Menu::set_supermenu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSMenu>(this) setSupermenu:cocoon::internal::native<::NSMenu>(value)];
    }

    std::string Menu::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMenu>(this) title]);
    }

    void Menu::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSMenu>(this) setTitle:cocoon::internal::to(value)];
    }

    UserInterfaceLayoutDirection Menu::user_interface_layout_direction() const
    {
        return static_cast<UserInterfaceLayoutDirection>([cocoon::internal::ns<::NSMenu>(this) userInterfaceLayoutDirection]);
    }

    void Menu::set_user_interface_layout_direction(UserInterfaceLayoutDirection value) const
    {
        [cocoon::internal::ns<::NSMenu>(this) setUserInterfaceLayoutDirection:static_cast<::NSUserInterfaceLayoutDirection>(value)];
    }

    MenuItem Menu::add_item(const std::string& title, const std::string& shortcut, std::function<void()> on_triggered) const
    {
        MenuItem item(title, shortcut);
        if (on_triggered)
        {
            item.triggered().connect(std::move(on_triggered));
        }
        add_item(item);
        return item;
    }

    MenuItem Menu::add_separator() const
    {
        MenuItem item = MenuItem::separator();
        add_item(item);
        return item;
    }

    MenuItem Menu::add_standard_item(StandardAction action) const
    {
        MenuItem item = MenuItem::standard(action);
        add_item(item);
        return item;
    }

    Menu Menu::add_menu(const std::string& title) const
    {
        Menu submenu(title);
        MenuItem item(title);
        item.set_submenu(submenu);
        add_item(item);
        return submenu;
    }

    Menu Menu::find_menu(const std::string& title) const
    {
        for (NSMenuItem* item in cocoon::internal::ns<NSMenu>(this).itemArray)
        {
            if (item.submenu && [item.title isEqualToString:cocoon::internal::to(title)])
            {
                return cocoon::internal::wrap<Menu>(item.submenu);
            }
        }
        return Menu(nullptr);
    }

    Menu Menu::standard_menu_bar(const std::string& application_name)
    {
        Menu bar;
        Menu application = bar.add_menu(application_name);
        application.add_standard_item(StandardAction::About).set_title("About " + application_name);
        application.add_separator();
        application.add_standard_item(StandardAction::Hide).set_title("Hide " + application_name);
        application.add_standard_item(StandardAction::HideOthers);
        application.add_standard_item(StandardAction::ShowAll);
        application.add_separator();
        application.add_standard_item(StandardAction::Quit).set_title("Quit " + application_name);
        Menu file = bar.add_menu("File");
        file.add_standard_item(StandardAction::Close);
        Menu edit = bar.add_menu("Edit");
        edit.add_standard_item(StandardAction::Undo);
        edit.add_standard_item(StandardAction::Redo);
        edit.add_separator();
        edit.add_standard_item(StandardAction::Cut);
        edit.add_standard_item(StandardAction::Copy);
        edit.add_standard_item(StandardAction::Paste);
        edit.add_standard_item(StandardAction::SelectAll);
        Menu view = bar.add_menu("View");
        view.add_standard_item(StandardAction::ToggleSidebar);
        view.add_standard_item(StandardAction::ToggleFullScreen);
        Menu window = bar.add_menu("Window");
        window.add_standard_item(StandardAction::Minimize);
        window.add_standard_item(StandardAction::Zoom);
        window.add_separator();
        window.add_standard_item(StandardAction::BringAllToFront);
        Menu help = bar.add_menu("Help");
        help.add_standard_item(StandardAction::ShowHelp).set_title(application_name + " Help");
        return bar;
    }

    void Menu::install_delegate_delegate_(void* native)
    {
        ::NSMenu* host = (__bridge ::NSMenu*)native;
        AKMenuDelegate* delegate = [[AKMenuDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSMenu* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSMenu* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
