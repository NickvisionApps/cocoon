#pragma once

#include <functional>
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Notification;
    class SearchToolbarItem;
    class ToolbarItem;

    /**
     * @brief A customizable window toolbar (NSToolbar). Stable identifiers let the user customization be saved.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * cocoon::Toolbar toolbar("com.example.toolbar");
     * toolbar.add_sidebar_toggle();
     * toolbar.add_button("add", "Add", "plus", [] {});
     * toolbar.add_allowed_item(cocoon::ToolbarItem("share", "Share", "square.and.arrow.up"));
     * toolbar.add_flexible_space();
     * toolbar.add_search_field("search");
     * toolbar.set_autosaves_configuration(true);
     * cocoon::Window window("Window", {800, 600});
     * window.set_toolbar(toolbar);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Toolbar toolbar{};
     * toolbar.set_allows_display_mode_customization(true);
     * auto allows_display_mode_customization = toolbar.allows_display_mode_customization();
     * toolbar.set_allows_extension_items(true);
     * auto allows_extension_items = toolbar.allows_extension_items();
     * toolbar.set_allows_user_customization(true);
     * auto allows_user_customization = toolbar.allows_user_customization();
     * toolbar.insert_item_with_item_identifier("text", 1);
     * toolbar.remove_item_at_index(1);
     * toolbar.remove_item_with_item_identifier("text");
     * toolbar.will_add_item().connect([](cocoon::Notification a0) {});
     * toolbar.did_remove_item().connect([](cocoon::Notification a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstoolbar
     */
    class Toolbar : public Object
    {
    public:
        /// @brief Creates a new `NSToolbar` instance and returns a handle to it.
        explicit Toolbar(const std::string& identifier);
        /// @brief Creates a new `NSToolbar` instance and returns a handle to it.
        explicit Toolbar();
        /// @brief Creates a null handle that refers to no native object.
        Toolbar(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Toolbar(Adopt adopt);
        /**
     * @brief Calls `-[NSToolbar insertItemWithItemIdentifier:atIndex:]`.
     * @details Inserts an item with the specified identifier in the receiving toolbar at the specified index. Any change made will be propagated immediately to all other toolbars with the same identifier.
     * @param item_identifier Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_item_with_item_identifier(const std::string& item_identifier, std::int64_t index) const;
        /**
     * @brief Calls `-[NSToolbar removeItemAtIndex:]`.
     * @details Removes the item at the specified index in the receiving toolbar. Any change made will be propagated immediately to all other toolbars with the same identifier.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_item_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSToolbar removeItemWithItemIdentifier:]`.
     * @details Removes the item with matching 'itemIdentifier' in the receiving toolbar. If multiple items share the same identifier (as is the case with space items) all matching items will be removed. To remove only a single space item, use '-removeItemAtIndex:' instead. Any change made will be propagated immediately to all other toolbars with the same identifier.
     * @param item_identifier Argument converted to the Objective-C parameter of the same role.
     */
        void remove_item_with_item_identifier(const std::string& item_identifier) const;
        /**
     * @brief Calls `-[NSToolbar runCustomizationPalette:]`.
     * @details Customizable toolbars (those with delegates) can show a palette which allows users to populate the toolbar with individual items or to reset the toolbar to some default set of items. The items and item sets in the palette are specified by the delegate ('-toolbarAllowedItemIdentifiers:' and '-toolbarDefaultItemIdentifiers:'). When the user is done configuring, they will dismiss the palette.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void run_customization_palette(const Object& sender) const;
        /**
     * @brief Calls `-[NSToolbar validateVisibleItems]`.
     * @details Typically you should not invoke this method. This method is called on window updates with the purpose of validating each of the visible items. The toolbar will iterate through the list of visible items, sending each a '-validate' message. If this method is invoked directly, all visible items including those with 'autovalidates' disabled will get a '-validate' message.
     */
        void validate_visible_items() const;
        /**
     * @brief Returns the `allowsDisplayModeCustomization` property of `NSToolbar`.
     * @details Whether or not the user is allowed to change display modes at run time. This functionality is independent of customizing the order of the items themselves. Only disable when the functionality or legibility of your toolbar could not be improved by another display mode. The user's selection will be persisted using the toolbar's 'identifier' when 'autosavesConfiguration' is enabled. The default is YES for apps linked on macOS 15.0 and above.
     * @return The converted Objective-C result.
     */
        bool allows_display_mode_customization() const;
        /**
     * @brief Sets the `allowsDisplayModeCustomization` property of `NSToolbar`.
     * @details Whether or not the user is allowed to change display modes at run time. This functionality is independent of customizing the order of the items themselves. Only disable when the functionality or legibility of your toolbar could not be improved by another display mode. The user's selection will be persisted using the toolbar's 'identifier' when 'autosavesConfiguration' is enabled. The default is YES for apps linked on macOS 15.0 and above.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_display_mode_customization(bool value) const;
        /**
     * @brief Returns the `allowsExtensionItems` property of `NSToolbar`.
     * @details When YES, the receiver can dynamically create toolbar items for Action extensions in the toolbar configuration panel. To be included, an extension needs to declare NSExtensionServiceAllowsToolbarItem=YES in its Info.plist. The default value is NO.
     * @return The converted Objective-C result.
     */
        bool allows_extension_items() const;
        /**
     * @brief Sets the `allowsExtensionItems` property of `NSToolbar`.
     * @details When YES, the receiver can dynamically create toolbar items for Action extensions in the toolbar configuration panel. To be included, an extension needs to declare NSExtensionServiceAllowsToolbarItem=YES in its Info.plist. The default value is NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_extension_items(bool value) const;
        /**
     * @brief Returns the `allowsUserCustomization` property of `NSToolbar`.
     * @details This flag controls whether or not users can configure the toolbar by dragging items around, and whether or not the customization palette can be used. The default value is NO, but can be changed at any time. For instance, a developer may not want users to be able to edit the toolbar while some event is being processed.
     * @return The converted Objective-C result.
     */
        bool allows_user_customization() const;
        /**
     * @brief Sets the `allowsUserCustomization` property of `NSToolbar`.
     * @details This flag controls whether or not users can configure the toolbar by dragging items around, and whether or not the customization palette can be used. The default value is NO, but can be changed at any time. For instance, a developer may not want users to be able to edit the toolbar while some event is being processed.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_user_customization(bool value) const;
        /**
     * @brief Returns the `autosavesConfiguration` property of `NSToolbar`.
     * @details If 'autosavesConfiguration' is YES, the toolbar will automatically write changes the user makes to user defaults. Customizable toolbars will want to set this flag to YES. Setting this to NO means changes in configuration are not written automatically, however you can use the 'configurationDictionary' method to do it yourself. Default is NO.
     * @return The converted Objective-C result.
     */
        bool autosaves_configuration() const;
        /**
     * @brief Sets the `autosavesConfiguration` property of `NSToolbar`.
     * @details If 'autosavesConfiguration' is YES, the toolbar will automatically write changes the user makes to user defaults. Customizable toolbars will want to set this flag to YES. Setting this to NO means changes in configuration are not written automatically, however you can use the 'configurationDictionary' method to do it yourself. Default is NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_autosaves_configuration(bool value) const;
        /**
     * @brief Returns the `centeredItemIdentifier` property of `NSToolbar`.
     * @return The converted Objective-C result.
     */
        std::string centered_item_identifier() const;
        /**
     * @brief Sets the `centeredItemIdentifier` property of `NSToolbar`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_centered_item_identifier(const std::string& value) const;
        /**
     * @brief Returns the `centeredItemIdentifiers` property of `NSToolbar`.
     * @details Items with centered identifiers will be centered together in the Toolbar relative to the window assuming space allows. The order of items is initially defined by the default set of identifiers, but may be customized by the user. Centered items may not be moved outside of the center set of items by the user. This property is archived.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> centered_item_identifiers() const;
        /**
     * @brief Sets the `centeredItemIdentifiers` property of `NSToolbar`.
     * @details Items with centered identifiers will be centered together in the Toolbar relative to the window assuming space allows. The order of items is initially defined by the default set of identifiers, but may be customized by the user. Centered items may not be moved outside of the center set of items by the user. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_centered_item_identifiers(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `customizationPaletteIsRunning` property of `NSToolbar`.
     * @details Whether or not the customization palette is currently running. On macOS 15.0 and above this property is key value observable.
     * @return The converted Objective-C result.
     */
        bool customization_palette_is_running() const;
        /**
     * @brief Returns the `displayMode` property of `NSToolbar`.
     * @details The current display mode of items in the toolbar. In toolbars with 'allowsDisplayModeCustomization' enabled this is a user modifiable property. This property is key value observable.
     * @return The converted Objective-C result.
     */
        ToolbarDisplayMode display_mode() const;
        /**
     * @brief Sets the `displayMode` property of `NSToolbar`.
     * @details The current display mode of items in the toolbar. In toolbars with 'allowsDisplayModeCustomization' enabled this is a user modifiable property. This property is key value observable.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_display_mode(ToolbarDisplayMode value) const;
        /**
     * @brief Returns the `identifier` property of `NSToolbar`.
     * @details All toolbars with the same name will share the same display attributes, and item order. If a toolbar autosaves its configuration, the item identifier will be used as the autosave name.
     * @return The converted Objective-C result.
     */
        std::string identifier() const;
        /**
     * @brief Returns the `itemIdentifiers` property of `NSToolbar`.
     * @details An array of itemIdentifiers that represent the current items in the toolbar. Setting this property will set the current items in the toolbar by diffing against items that already exist. Use this with great caution if 'allowsUserCustomization' is enabled as it will override any customizations the user has made. This property is key value observable.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> item_identifiers() const;
        /**
     * @brief Sets the `itemIdentifiers` property of `NSToolbar`.
     * @details An array of itemIdentifiers that represent the current items in the toolbar. Setting this property will set the current items in the toolbar by diffing against items that already exist. Use this with great caution if 'allowsUserCustomization' is enabled as it will override any customizations the user has made. This property is key value observable.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_item_identifiers(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `items` property of `NSToolbar`.
     * @details Allows you to access all current items in the toolbar.
     * @return The converted Objective-C result.
     */
        std::vector<ToolbarItem> items() const;
        /**
     * @brief Returns the `selectedItemIdentifier` property of `NSToolbar`.
     * @details Sets the toolbar's selected item by identifier. Use this to force an item identifier to be selected. Toolbar manages selection of image items automatically. This method can be used to select identifiers of custom view items, or to force a selection change. See '-toolbarSelectableItemIdentifiers:' delegate method for more details. This property is key value observable.
     * @return The converted Objective-C result.
     */
        std::string selected_item_identifier() const;
        /**
     * @brief Sets the `selectedItemIdentifier` property of `NSToolbar`.
     * @details Sets the toolbar's selected item by identifier. Use this to force an item identifier to be selected. Toolbar manages selection of image items automatically. This method can be used to select identifiers of custom view items, or to force a selection change. See '-toolbarSelectableItemIdentifiers:' delegate method for more details. This property is key value observable.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected_item_identifier(const std::string& value) const;
        /**
     * @brief Returns the `sizeMode` property of `NSToolbar`.
     * @return The converted Objective-C result.
     */
        ToolbarSizeMode size_mode() const;
        /**
     * @brief Sets the `sizeMode` property of `NSToolbar`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_size_mode(ToolbarSizeMode value) const;
        /**
     * @brief Returns the `visible` property of `NSToolbar`.
     * @details Toggles the visibility of the toolbar. This property may be modified by the user in toolbars with 'allowsUserCustomization' enabled. This property is key value observable on macOS 14.0 and higher.
     * @return The converted Objective-C result.
     */
        bool is_visible() const;
        /**
     * @brief Sets the `visible` property of `NSToolbar`.
     * @details Toggles the visibility of the toolbar. This property may be modified by the user in toolbars with 'allowsUserCustomization' enabled. This property is key value observable on macOS 14.0 and higher.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_visible(bool value) const;
        /**
     * @brief Returns the `visibleItems` property of `NSToolbar`.
     * @details Allows you to access the current visible items (non clipped).
     * @return The converted Objective-C result.
     */
        std::vector<ToolbarItem> visible_items() const;
        /// @brief Convenience helper `add_item` provided by cocoon.
        void add_item(const ToolbarItem& item) const;
        /// @brief Convenience helper `add_required_item` provided by cocoon.
        void add_required_item(const ToolbarItem& item) const;
        /// @brief Convenience helper `add_allowed_item` provided by cocoon.
        void add_allowed_item(const ToolbarItem& item) const;
        /// @brief Convenience helper `add_button` provided by cocoon.
        ToolbarItem add_button(const std::string& identifier, const std::string& label, const std::string& symbol, std::function<void()> on_clicked = {}) const;
        /// @brief Convenience helper `add_search_field` provided by cocoon.
        SearchToolbarItem add_search_field(const std::string& identifier, std::function<void(const std::string&)> on_searched = {}) const;
        /// @brief Convenience helper `add_flexible_space` provided by cocoon.
        void add_flexible_space() const;
        /// @brief Convenience helper `add_space` provided by cocoon.
        void add_space() const;
        /// @brief Convenience helper `add_sidebar_toggle` provided by cocoon.
        void add_sidebar_toggle() const;
        /// @brief Convenience helper `add_sidebar_tracking_separator` provided by cocoon.
        void add_sidebar_tracking_separator() const;
        /// @brief Signal for the delegate/data-source method behind `item_for_identifier`; connect a callback with `item_for_identifier().connect(...)`.
        Signal<Toolbar, ToolbarItem(std::string, bool)> item_for_identifier() const
        {
            return Signal<Toolbar, ToolbarItem(std::string, bool)>(handle(), "item_for_identifier");
        }
        /// @brief Signal for the delegate/data-source method behind `default_item_identifiers`; connect a callback with `default_item_identifiers().connect(...)`.
        Signal<Toolbar, std::vector<std::string>()> default_item_identifiers() const
        {
            return Signal<Toolbar, std::vector<std::string>()>(handle(), "default_item_identifiers");
        }
        /// @brief Signal for the delegate/data-source method behind `allowed_item_identifiers`; connect a callback with `allowed_item_identifiers().connect(...)`.
        Signal<Toolbar, std::vector<std::string>()> allowed_item_identifiers() const
        {
            return Signal<Toolbar, std::vector<std::string>()>(handle(), "allowed_item_identifiers");
        }
        /// @brief Signal for the delegate/data-source method behind `selectable_item_identifiers`; connect a callback with `selectable_item_identifiers().connect(...)`.
        Signal<Toolbar, std::vector<std::string>()> selectable_item_identifiers() const
        {
            return Signal<Toolbar, std::vector<std::string>()>(handle(), "selectable_item_identifiers");
        }
        /// @brief Signal for the delegate/data-source method behind `immovable_item_identifiers`; connect a callback with `immovable_item_identifiers().connect(...)`.
        Signal<Toolbar, std::vector<std::string>()> immovable_item_identifiers() const
        {
            return Signal<Toolbar, std::vector<std::string>()>(handle(), "immovable_item_identifiers");
        }
        /// @brief Signal for the delegate/data-source method behind `item_identifier_can_be_inserted_at_index`; connect a callback with `item_identifier_can_be_inserted_at_index().connect(...)`.
        Signal<Toolbar, bool(std::string, std::int64_t)> item_identifier_can_be_inserted_at_index() const
        {
            return Signal<Toolbar, bool(std::string, std::int64_t)>(handle(), "item_identifier_can_be_inserted_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `will_add_item`; connect a callback with `will_add_item().connect(...)`.
        Signal<Toolbar, void(Notification)> will_add_item() const
        {
            return Signal<Toolbar, void(Notification)>(handle(), "will_add_item");
        }
        /// @brief Signal for the delegate/data-source method behind `did_remove_item`; connect a callback with `did_remove_item().connect(...)`.
        Signal<Toolbar, void(Notification)> did_remove_item() const
        {
            return Signal<Toolbar, void(Notification)>(handle(), "did_remove_item");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
