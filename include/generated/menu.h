#pragma once

#include <functional>
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "standard_action.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Event;
    class Font;
    class Image;
    class MenuItem;
    class Screen;
    class View;

    /**
     * @brief A menu or menu bar (NSMenu). Menu::standard_menu_bar builds the standard application menus.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * cocoon::Menu bar = cocoon::Menu::standard_menu_bar("Demo");
     * cocoon::Menu file = bar.find_menu("File");
     * cocoon::MenuItem open("Open...", "Cmd+O");
     * open.triggered().connect([] {});
     * file.insert_item(open, 0);
     * cocoon::Application app(0, nullptr);
     * app.set_menu_bar(bar);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Menu menu{"text"};
     * menu.set_allows_context_menu_plug_ins(true);
     * auto allows_context_menu_plug_ins = menu.allows_context_menu_plug_ins();
     * menu.set_autoenables_items(true);
     * auto autoenables_items = menu.autoenables_items();
     * menu.set_automatically_inserts_writing_tools_items(true);
     * auto automatically_inserts_writing_tools_items = menu.automatically_inserts_writing_tools_items();
     * menu.add_item(cocoon::MenuItem());
     * menu.add_item_with_title("text", "text", "text");
     * menu.cancel_tracking();
     * menu.needs_update().connect([]() {});
     * menu.will_open().connect([]() {});
     * menu.did_close().connect([]() {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsmenu
     */
    class Menu : public Object
    {
    public:
        /// @brief Creates a new `NSMenu` instance and returns a handle to it.
        explicit Menu(const std::string& title = "");
        /// @brief Creates a null handle that refers to no native object.
        Menu(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Menu(Adopt adopt);
        /**
     * @brief Calls `-[NSMenu addItem:]`.
     * @details Appends an item to the end of the menu. A nil item will raise an exception.
     * @param new_item Argument converted to the Objective-C parameter of the same role.
     */
        void add_item(const MenuItem& new_item) const;
        /**
     * @brief Calls `-[NSMenu addItemWithTitle:action:keyEquivalent:]`.
     * @details Appends a new menu item with the given properties to the end of the menu.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @param selector Argument converted to the Objective-C parameter of the same role.
     * @param char_code Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        MenuItem add_item_with_title(const std::string& string, const std::string& selector, const std::string& char_code) const;
        /**
     * @brief Calls `-[NSMenu cancelTracking]`.
     * @details Dismisses the menu and ends all menu tracking
     */
        void cancel_tracking() const;
        /**
     * @brief Calls `-[NSMenu cancelTrackingWithoutAnimation]`.
     * @details Dismisses the menu immediately, without any fade or other effect, and ends all menu tracking
     */
        void cancel_tracking_without_animation() const;
        /**
     * @brief Calls `-[NSMenu indexOfItem:]`.
     * @details Returns the index of the item in the menu, or -1 if the item is not present in the menu
     * @param item Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item(const MenuItem& item) const;
        /**
     * @brief Calls `-[NSMenu indexOfItemWithRepresentedObject:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item_with_represented_object(const Object& object) const;
        /**
     * @brief Calls `-[NSMenu indexOfItemWithSubmenu:]`.
     * @param submenu Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item_with_submenu(const Menu& submenu) const;
        /**
     * @brief Calls `-[NSMenu indexOfItemWithTag:]`.
     * @param tag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item_with_tag(std::int64_t tag) const;
        /**
     * @brief Calls `-[NSMenu indexOfItemWithTarget:andAction:]`.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action_selector Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item_with_target(const Object& target, const std::string& action_selector) const;
        /**
     * @brief Calls `-[NSMenu indexOfItemWithTitle:]`.
     * @details Returns the first item in the menu that matches the given property, or -1 if no item in the menu matches.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item_with_title(const std::string& title) const;
        /**
     * @brief Calls `-[NSMenu insertItem:atIndex:]`.
     * @details Inserts a menu item at the given index, which must be at least zero and no more than the receiver's item count. If newItem is nil, this raises an exception.
     * @param new_item Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_item(const MenuItem& new_item, std::int64_t index) const;
        /**
     * @brief Calls `-[NSMenu insertItemWithTitle:action:keyEquivalent:atIndex:]`.
     * @details Inserts a new menu item with the given title, action, and key equivalent, at the given index. The index must be at least zero and no more than the receiver's item count. The title and key equivalent must not be nil (pass the empty string to indicate no key equivalent). This returns the new item.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @param selector Argument converted to the Objective-C parameter of the same role.
     * @param char_code Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        MenuItem insert_item_with_title(const std::string& string, const std::string& selector, const std::string& char_code, std::int64_t index) const;
        /**
     * @brief Calls `-[NSMenu itemAtIndex:]`.
     * @details Returns the item at the given index, which must be at least zero and less than the number of items.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        MenuItem item_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSMenu itemChanged:]`.
     * @details This method is called when a menu item's enabled state, submenu, title, attributed title, image, key equivalent, key equivalent modifier mask, alternate status, indent, tooltip, view, or visibility (via isHidden) changes. This method posts NSMenuDidChangeItemNotification. Future properties will likely not call this method when they change, because posting a notification when a property changes is rather expensive.
     * @param item Argument converted to the Objective-C parameter of the same role.
     */
        void item_changed(const MenuItem& item) const;
        /**
     * @brief Calls `-[NSMenu itemWithTag:]`.
     * @param tag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        MenuItem item_with_tag(std::int64_t tag) const;
        /**
     * @brief Calls `-[NSMenu itemWithTitle:]`.
     * @details Returns the first item in the menu with the given property, or nil if no item in the menu matches.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        MenuItem item_with_title(const std::string& title) const;
        /**
     * @brief Calls `+[NSMenu menuBarVisible]`.
     * @return The converted Objective-C result.
     */
        static bool menu_bar_visible();
        /**
     * @brief Calls `+[NSMenu paletteMenuWithColors:titles:selectionHandler:]`.
     * @details Creates a palette menu displaying user-selectable color tags using the provided array of colors and optional titles. Note that the palette menu is configured for display as an inline menu; you must set it as the submenu of another menu item, contained in a standard menu. The palette menu cannot be used to invoke the 'popUpMenuPositioningItem' method, or attached directly to a popup button or toolbar item. \@return An autoconfigured palette menu.
     * @param colors Argument converted to the Objective-C parameter of the same role.
     * @param item_titles Argument converted to the Objective-C parameter of the same role.
     * @param on_selection_change Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Menu palette_menu_with_colors(const std::vector<Color>& colors, const std::vector<std::string>& item_titles, std::function<void(Menu)> on_selection_change);
        /**
     * @brief Calls `+[NSMenu paletteMenuWithColors:titles:templateImage:selectionHandler:]`.
     * @details Creates a palette menu displaying user-selectable color tags using the provided template image, tinted using the specified array of colors. Optionally allows observing changes to the selection state in the compact menu. The block is invoked after the selection has been updated. Currently selected items can be retrieved from the 'selectedItems' property. Note that the palette menu is configured for display as an inline menu; you must set it as the submenu of another menu item, contained in a standard menu. The palette menu cannot be used to invoke the 'popUpMenuPositioningItem' method, or attached directly to a popup button or toolbar item. \@return An autoconfigured palette menu.
     * @param colors Argument converted to the Objective-C parameter of the same role.
     * @param item_titles Argument converted to the Objective-C parameter of the same role.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param on_selection_change Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Menu palette_menu_with_colors(const std::vector<Color>& colors, const std::vector<std::string>& item_titles, const Image& image, std::function<void(Menu)> on_selection_change);
        /**
     * @brief Calls `-[NSMenu performActionForItemAtIndex:]`.
     * @details Triggers the action for the item at the given index in the receiver. This is useful as both an override point and something you may call directly. As an override point, this is called when the user chooses the item during normal menu tracking; subclassers can override it to take some different action. If you call it directly, it triggers the action for that item. In SnowLeopard and later, calling it directly will also highlight the menu (if present in the main menu) and trigger accessibility notifications, including VoiceOver speaking the title.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void perform_action_for_item_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSMenu performKeyEquivalent:]`.
     * @details Attempts to perform the given key equivalent. If the event is a key down event that matches the key equivalent of a menu item in the receiver or, recursively, any menu item in a submenu of the receiver, then this triggers that menu item's action (if the item is enabled) and returns YES. Otherwise, this returns NO.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool perform_key_equivalent(const Event& event) const;
        /**
     * @brief Calls `+[NSMenu popUpContextMenu:withEvent:forView:]`.
     * @details Pops up the receiver as a context menu. The menu is positioned such that the top left corner lies at the given event's location, interpreted in the coordinate system of the given view. If this would cause the menu to scroll offscreen, it will be moved up to be onscreen. The event must not be nil. If a font is specified, then it will be applied to the menu. In 10.6, the setFont: API below should be preferred.
     * @param menu Argument converted to the Objective-C parameter of the same role.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     */
        static void pop_up_context_menu(const Menu& menu, const Event& event, const View& view);
        /**
     * @brief Calls `+[NSMenu popUpContextMenu:withEvent:forView:withFont:]`.
     * @param menu Argument converted to the Objective-C parameter of the same role.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param font Argument converted to the Objective-C parameter of the same role.
     */
        static void pop_up_context_menu(const Menu& menu, const Event& event, const View& view, const Font& font);
        /**
     * @brief Calls `-[NSMenu popUpMenuPositioningItem:atLocation:inView:]`.
     * @details Pops up the receiver as a popup menu. The top left or right corner of the given item (which must be present in the receiver) is positioned at the given location in the given view, interpreted in the view's own coordinate system. If item is nil, the menu is positioned such that the top left or right of the menu content frame is at the given location. If view is nil, the location is interpreted in the screen coordinate system. This allows you to pop up a menu disconnected from any window. The method returns YES if menu tracking ended because an item was selected, and NO if menu tracking was cancelled for any reason. This method determines whether to use the top left or right corner by calling userInterfaceLayoutDirection on the view or its cell (if implemented). If not implemented, or if the view is nil, it inspects the userInterfaceLayoutDirection of the NSApplication.
     * @param item Argument converted to the Objective-C parameter of the same role.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool pop_up_menu_positioning_item(const MenuItem& item, const Point& location, const View& view) const;
        /**
     * @brief Calls `-[NSMenu removeAllItems]`.
     * @details Removes all items. This is more efficient than removing items one by one. This does not post NSMenuDidRemoveItemNotification, for efficiency.
     */
        void remove_all_items() const;
        /**
     * @brief Calls `-[NSMenu removeItem:]`.
     * @details Removes the item from the menu. If the item is nil, or is not present in the receiver, an exception will be raised.
     * @param item Argument converted to the Objective-C parameter of the same role.
     */
        void remove_item(const MenuItem& item) const;
        /**
     * @brief Calls `-[NSMenu removeItemAtIndex:]`.
     * @details Removes the item at the given index, which must be at least zero and less than the number of items. All subsequent items will shift down one index.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_item_at_index(std::int64_t index) const;
        /**
     * @brief Calls `+[NSMenu setMenuBarVisible:]`.
     * @details Determines whether the menu bar is visible for this application. Users cannot access the menu bar unless it is visible. It is visible by default.
     * @param visible Argument converted to the Objective-C parameter of the same role.
     */
        static void set_menu_bar_visible(bool visible);
        /**
     * @brief Calls `-[NSMenu setSubmenu:forItem:]`.
     * @details Same as [item setSubmenu:menu]. item may not be nil.
     * @param menu Argument converted to the Objective-C parameter of the same role.
     * @param item Argument converted to the Objective-C parameter of the same role.
     */
        void set_submenu(const Menu& menu, const MenuItem& item) const;
        /**
     * @brief Calls `-[NSMenu submenuAction:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void submenu_action(const Object& sender) const;
        /**
     * @brief Calls `-[NSMenu update]`.
     * @details If the receiver is set to autoenable items, then this triggers autovalidation of all menu items according to the NSMenuValidation informal protocol; otherwise this does nothing. It is normally not necessary to call this; it will be called for you at the right time.
     */
        void update() const;
        /**
     * @brief Returns the `allowsContextMenuPlugIns` property of `NSMenu`.
     * @details Determines whether contextual menu plugins may be appended to the menu, if used as a context menu. The default is YES.
     * @return The converted Objective-C result.
     */
        bool allows_context_menu_plug_ins() const;
        /**
     * @brief Sets the `allowsContextMenuPlugIns` property of `NSMenu`.
     * @details Determines whether contextual menu plugins may be appended to the menu, if used as a context menu. The default is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_context_menu_plug_ins(bool value) const;
        /**
     * @brief Returns the `autoenablesItems` property of `NSMenu`.
     * @details Set and get whether the menu autoenables items. If a menu autoenables items, then calls to -[NSMenuItem setEnabled:] are ignored, and the enabled state is computed via the NSMenuValidation informal protocol below. Autoenabling is on by default.
     * @return The converted Objective-C result.
     */
        bool autoenables_items() const;
        /**
     * @brief Sets the `autoenablesItems` property of `NSMenu`.
     * @details Set and get whether the menu autoenables items. If a menu autoenables items, then calls to -[NSMenuItem setEnabled:] are ignored, and the enabled state is computed via the NSMenuValidation informal protocol below. Autoenabling is on by default.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_autoenables_items(bool value) const;
        /**
     * @brief Returns the `automaticallyInsertsWritingToolsItems` property of `NSMenu`.
     * @details Determines whether Writing Tools menu items may be inserted into the menu, if used as a context menu. The default is YES.
     * @return The converted Objective-C result.
     */
        bool automatically_inserts_writing_tools_items() const;
        /**
     * @brief Sets the `automaticallyInsertsWritingToolsItems` property of `NSMenu`.
     * @details Determines whether Writing Tools menu items may be inserted into the menu, if used as a context menu. The default is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_automatically_inserts_writing_tools_items(bool value) const;
        /**
     * @brief Returns the `font` property of `NSMenu`.
     * @details Sets the font for the menu. This also affects the font of all submenus that do not have their own font.
     * @return The converted Objective-C result.
     */
        Font font() const;
        /**
     * @brief Sets the `font` property of `NSMenu`.
     * @details Sets the font for the menu. This also affects the font of all submenus that do not have their own font.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_font(const Font& value) const;
        /**
     * @brief Returns the `highlightedItem` property of `NSMenu`.
     * @details Returns the highlighted item in the menu, or nil if no item in the menu is highlighted
     * @return The converted Objective-C result.
     */
        MenuItem highlighted_item() const;
        /**
     * @brief Returns the `itemArray` property of `NSMenu`.
     * @details Returns an array containing the receiver's menu items. This property is settable in macOS 10.14 and later.
     * @return The converted Objective-C result.
     */
        std::vector<MenuItem> item_array() const;
        /**
     * @brief Sets the `itemArray` property of `NSMenu`.
     * @details Returns an array containing the receiver's menu items. This property is settable in macOS 10.14 and later.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_item_array(const std::vector<MenuItem>& value) const;
        /**
     * @brief Returns the `menuBarHeight` property of `NSMenu`.
     * @details If called on the main menu, returns the height of the menu bar in pixels. If called on any other menu, returns 0.
     * @return The converted Objective-C result.
     */
        double menu_bar_height() const;
        /**
     * @brief Returns the `minimumWidth` property of `NSMenu`.
     * @details Set the minimum width of the menu, in screen coordinates. The menu will prefer to not draw smaller than its minimum width, but may draw larger if it needs more space. The default value is 0.
     * @return The converted Objective-C result.
     */
        double minimum_width() const;
        /**
     * @brief Sets the `minimumWidth` property of `NSMenu`.
     * @details Set the minimum width of the menu, in screen coordinates. The menu will prefer to not draw smaller than its minimum width, but may draw larger if it needs more space. The default value is 0.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_width(double value) const;
        /**
     * @brief Returns the `numberOfItems` property of `NSMenu`.
     * @details Returns the number of menu items in the menu.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_items() const;
        /**
     * @brief Returns the `presentationStyle` property of `NSMenu`.
     * @details The presentation style of the menu. \@note This property is not respected if the menu is the main menu of the app.
     * @return The converted Objective-C result.
     */
        MenuPresentationStyle presentation_style() const;
        /**
     * @brief Sets the `presentationStyle` property of `NSMenu`.
     * @details The presentation style of the menu. \@note This property is not respected if the menu is the main menu of the app.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_presentation_style(MenuPresentationStyle value) const;
        /**
     * @brief Returns the `propertiesToUpdate` property of `NSMenu`.
     * @return The converted Objective-C result.
     */
        MenuProperties properties_to_update() const;
        /**
     * @brief Returns the `selectedItems` property of `NSMenu`.
     * @details The menu items that are selected. An item is selected when its state is 'NSControl.StateValue.on'. \@note This property is settable. Setting 'selectedItems' will select any items that are contained in the provided array, and deselect any previously selected items that are not in the array.
     * @return The converted Objective-C result.
     */
        std::vector<MenuItem> selected_items() const;
        /**
     * @brief Sets the `selectedItems` property of `NSMenu`.
     * @details The menu items that are selected. An item is selected when its state is 'NSControl.StateValue.on'. \@note This property is settable. Setting 'selectedItems' will select any items that are contained in the provided array, and deselect any previously selected items that are not in the array.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected_items(const std::vector<MenuItem>& value) const;
        /**
     * @brief Returns the `selectionMode` property of `NSMenu`.
     * @details The selection mode of the menu. Note the selection mode only has effect on menu items that belong to the same selection group. A selection group consists of the items with the same target/action.
     * @return The converted Objective-C result.
     */
        MenuSelectionMode selection_mode() const;
        /**
     * @brief Sets the `selectionMode` property of `NSMenu`.
     * @details The selection mode of the menu. Note the selection mode only has effect on menu items that belong to the same selection group. A selection group consists of the items with the same target/action.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selection_mode(MenuSelectionMode value) const;
        /**
     * @brief Returns the `showsStateColumn` property of `NSMenu`.
     * @details Determines whether the menu contains a column for the state image. The default is YES.
     * @return The converted Objective-C result.
     */
        bool shows_state_column() const;
        /**
     * @brief Sets the `showsStateColumn` property of `NSMenu`.
     * @details Determines whether the menu contains a column for the state image. The default is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_state_column(bool value) const;
        /**
     * @brief Returns the `size` property of `NSMenu`.
     * @details Returns the size of the menu, in screen coordinates. The menu may draw at a smaller size when shown, depending on its positioning and display configuration.
     * @return The converted Objective-C result.
     */
        Size size() const;
        /**
     * @brief Returns the `supermenu` property of `NSMenu`.
     * @details Getter: Returns the menu containing the item that has the receiver as a submenu, or nil if this menu is not the submenu of an item in a menu. Setter: If a menu item has the receiver as a submenu, then this method will be called when the menu containing that item changes. You should never call this, but you may override it to take some action when the supermenu changes.
     * @return The converted Objective-C result.
     */
        Menu supermenu() const;
        /**
     * @brief Sets the `supermenu` property of `NSMenu`.
     * @details Getter: Returns the menu containing the item that has the receiver as a submenu, or nil if this menu is not the submenu of an item in a menu. Setter: If a menu item has the receiver as a submenu, then this method will be called when the menu containing that item changes. You should never call this, but you may override it to take some action when the supermenu changes.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_supermenu(const Menu& value) const;
        /**
     * @brief Returns the `title` property of `NSMenu`.
     * @details Set and get the menu's title. The titles of the submenus of the application's main menu items appear in the menu bar.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSMenu`.
     * @details Set and get the menu's title. The titles of the submenus of the application's main menu items appear in the menu bar.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
        /**
     * @brief Returns the `userInterfaceLayoutDirection` property of `NSMenu`.
     * @details Determines the layout direction for menu items in the menu. If no layout direction is explicitly set, the menu will default to the value of [NSApp userInterfaceLayoutDirection].
     * @return The converted Objective-C result.
     */
        UserInterfaceLayoutDirection user_interface_layout_direction() const;
        /**
     * @brief Sets the `userInterfaceLayoutDirection` property of `NSMenu`.
     * @details Determines the layout direction for menu items in the menu. If no layout direction is explicitly set, the menu will default to the value of [NSApp userInterfaceLayoutDirection].
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_user_interface_layout_direction(UserInterfaceLayoutDirection value) const;
        /// @brief Convenience helper `add_item` provided by cocoon.
        MenuItem add_item(const std::string& title, const std::string& shortcut = {}, std::function<void()> on_triggered = {}) const;
        /// @brief Convenience helper `add_separator` provided by cocoon.
        MenuItem add_separator() const;
        /// @brief Convenience helper `add_standard_item` provided by cocoon.
        MenuItem add_standard_item(StandardAction action) const;
        /// @brief Convenience helper `add_menu` provided by cocoon.
        Menu add_menu(const std::string& title) const;
        /// @brief Convenience helper `find_menu` provided by cocoon.
        Menu find_menu(const std::string& title) const;
        /// @brief Convenience helper `standard_menu_bar` provided by cocoon.
        static Menu standard_menu_bar(const std::string& application_name);
        /// @brief Signal for the delegate/data-source method behind `needs_update`; connect a callback with `needs_update().connect(...)`.
        Signal<Menu, void()> needs_update() const
        {
            return Signal<Menu, void()>(handle(), "needs_update");
        }
        /// @brief Signal for the delegate/data-source method behind `number_of_items_in_menu`; connect a callback with `number_of_items_in_menu().connect(...)`.
        Signal<Menu, std::int64_t()> number_of_items_in_menu() const
        {
            return Signal<Menu, std::int64_t()>(handle(), "number_of_items_in_menu");
        }
        /// @brief Signal for the delegate/data-source method behind `update_item_at_index_should_cancel`; connect a callback with `update_item_at_index_should_cancel().connect(...)`.
        Signal<Menu, bool(MenuItem, std::int64_t, bool)> update_item_at_index_should_cancel() const
        {
            return Signal<Menu, bool(MenuItem, std::int64_t, bool)>(handle(), "update_item_at_index_should_cancel");
        }
        /// @brief Signal for the delegate/data-source method behind `will_open`; connect a callback with `will_open().connect(...)`.
        Signal<Menu, void()> will_open() const
        {
            return Signal<Menu, void()>(handle(), "will_open");
        }
        /// @brief Signal for the delegate/data-source method behind `did_close`; connect a callback with `did_close().connect(...)`.
        Signal<Menu, void()> did_close() const
        {
            return Signal<Menu, void()>(handle(), "did_close");
        }
        /// @brief Signal for the delegate/data-source method behind `will_highlight_item`; connect a callback with `will_highlight_item().connect(...)`.
        Signal<Menu, void(MenuItem)> will_highlight_item() const
        {
            return Signal<Menu, void(MenuItem)>(handle(), "will_highlight_item");
        }
        /// @brief Signal for the delegate/data-source method behind `confinement_rect_for_menu_on_screen`; connect a callback with `confinement_rect_for_menu_on_screen().connect(...)`.
        Signal<Menu, Rect(Screen)> confinement_rect_for_menu_on_screen() const
        {
            return Signal<Menu, Rect(Screen)>(handle(), "confinement_rect_for_menu_on_screen");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
