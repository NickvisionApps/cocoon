#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Image;
    class ItemBadge;
    class MenuItem;
    class Toolbar;
    class View;

    /**
     * @brief A toolbar item (NSToolbarItem).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * cocoon::ToolbarItem item("share", "Share", "square.and.arrow.up");
     * item.clicked().connect([] {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ToolbarItem toolbar_item{};
     * toolbar_item.set_action("text");
     * auto action = toolbar_item.action();
     * toolbar_item.set_autovalidates(true);
     * auto autovalidates = toolbar_item.autovalidates();
     * toolbar_item.set_background_tint_color(cocoon::Color());
     * auto background_tint_color = toolbar_item.background_tint_color();
     * toolbar_item.validate();
     * toolbar_item.clicked().connect([]() {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstoolbaritem
     */
    class ToolbarItem : public Object
    {
    public:
        /// @brief Creates a new `NSToolbarItem` instance and returns a handle to it.
        explicit ToolbarItem(const std::string& identifier, const std::string& label, const std::string& symbol);
        /// @brief Creates a new `NSToolbarItem` instance and returns a handle to it.
        explicit ToolbarItem(const std::string& item_identifier);
        /// @brief Creates a new `NSToolbarItem` instance and returns a handle to it.
        explicit ToolbarItem();
        /// @brief Creates a null handle that refers to no native object.
        ToolbarItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ToolbarItem(Adopt adopt);
        /**
         * @brief Calls `-[NSToolbarItem validate]`.
         * @details Typically you should not invoke this method. This method is called by its toolbar during validation. Standard items validate themselves by sending the '-validateToolbarItem:' validate message to the current validator. Since items with custom views don't always have meaningful target/actions, they do nothing. So for your custom items it may be useful to override this method and invent your own validation.
         */
        void validate() const;
        /**
         * @brief Returns the `action` property of `NSToolbarItem`.
         * @details Set and get the action of an item. For custom views, this method will call '-setAction:' on the view if it responds. (forwards to '-view' if it responds)
         * @return The converted Objective-C result.
         */
        std::string action() const;
        /**
         * @brief Sets the `action` property of `NSToolbarItem`.
         * @details Set and get the action of an item. For custom views, this method will call '-setAction:' on the view if it responds. (forwards to '-view' if it responds)
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_action(const std::string& value) const;
        /**
         * @brief Returns the `autovalidates` property of `NSToolbarItem`.
         * @details This property only affects automatic validation performed by NSToolbar. Explicit validation requests, such as the '-[NSToolbar validateVisibleItems]' method, will invoke the '-validate' method even if 'autovalidates' is 'NO'. Defaults to YES.
         * @return The converted Objective-C result.
         */
        bool autovalidates() const;
        /**
         * @brief Sets the `autovalidates` property of `NSToolbarItem`.
         * @details This property only affects automatic validation performed by NSToolbar. Explicit validation requests, such as the '-[NSToolbar validateVisibleItems]' method, will invoke the '-validate' method even if 'autovalidates' is 'NO'. Defaults to YES.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_autovalidates(bool value) const;
        /**
         * @brief Returns the `backgroundTintColor` property of `NSToolbarItem`.
         * @return The converted Objective-C result.
         */
        Color background_tint_color() const;
        /**
         * @brief Sets the `backgroundTintColor` property of `NSToolbarItem`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_background_tint_color(const Color& value) const;
        /**
         * @brief Returns the `badge` property of `NSToolbarItem`.
         * @details A badge that can be attached to an NSToolbarItem. This provides a way to display small visual indicators that can be used to highlight important information, such as unread notifications or status indicators.
         * @return The converted Objective-C result.
         */
        ItemBadge badge() const;
        /**
         * @brief Sets the `badge` property of `NSToolbarItem`.
         * @details A badge that can be attached to an NSToolbarItem. This provides a way to display small visual indicators that can be used to highlight important information, such as unread notifications or status indicators.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_badge(const ItemBadge& value) const;
        /**
         * @brief Returns the `bordered` property of `NSToolbarItem`.
         * @details When set on an item without a custom view, the button produced will have a bordered style. Defaults to NO.
         * @return The converted Objective-C result.
         */
        bool is_bordered() const;
        /**
         * @brief Sets the `bordered` property of `NSToolbarItem`.
         * @details When set on an item without a custom view, the button produced will have a bordered style. Defaults to NO.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_bordered(bool value) const;
        /**
         * @brief Returns the `enabled` property of `NSToolbarItem`.
         * @details Set and get the enabled flag of an item. For custom views, this method will call '-setEnabled:' on the view if it responds. (forwards to '-view' if it responds)
         * @return The converted Objective-C result.
         */
        bool is_enabled() const;
        /**
         * @brief Sets the `enabled` property of `NSToolbarItem`.
         * @details Set and get the enabled flag of an item. For custom views, this method will call '-setEnabled:' on the view if it responds. (forwards to '-view' if it responds)
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_enabled(bool value) const;
        /**
         * @brief Returns the `hidden` property of `NSToolbarItem`.
         * @details Determines whether an item is visible in the toolbar. The item will still be visible in the customization panel. Because hidden items may be visible during user customization, use the 'visible' property to determine if an item is currently displayed. Note that even hidden toolbar items are sync'd to other toolbars with a shared identifier, but its 'hidden' state can be unique to each instance. Use this property to show a toolbar item in one toolbar instance but not another.
         * @return The converted Objective-C result.
         */
        bool is_hidden() const;
        /**
         * @brief Sets the `hidden` property of `NSToolbarItem`.
         * @details Determines whether an item is visible in the toolbar. The item will still be visible in the customization panel. Because hidden items may be visible during user customization, use the 'visible' property to determine if an item is currently displayed. Note that even hidden toolbar items are sync'd to other toolbars with a shared identifier, but its 'hidden' state can be unique to each instance. Use this property to show a toolbar item in one toolbar instance but not another.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_hidden(bool value) const;
        /**
         * @brief Returns the `image` property of `NSToolbarItem`.
         * @return The converted Objective-C result.
         */
        Image image() const;
        /**
         * @brief Sets the `image` property of `NSToolbarItem`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_image(const Image& value) const;
        /**
         * @brief Returns the `itemIdentifier` property of `NSToolbarItem`.
         * @return The converted Objective-C result.
         */
        std::string item_identifier() const;
        /**
         * @brief Returns the `label` property of `NSToolbarItem`.
         * @details Use this to set the item's label that appears in the toolbar. The label may also be used for the default 'menuFormRepresentation' of the item. Also, developers should make sure the length of the label is appropriate and not too long.
         * @return The converted Objective-C result.
         */
        std::string label() const;
        /**
         * @brief Sets the `label` property of `NSToolbarItem`.
         * @details Use this to set the item's label that appears in the toolbar. The label may also be used for the default 'menuFormRepresentation' of the item. Also, developers should make sure the length of the label is appropriate and not too long.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_label(const std::string& value) const;
        /**
         * @brief Returns the `menuFormRepresentation` property of `NSToolbarItem`.
         * @details The menu form of a toolbar item's purpose is twofold. First, when the window is too small to display an item, it will be clipped but remain accessible from a "clipped items" menu containing the menu item returned here. Second, in text only mode, the menu returned will be used to create the displayed items. Singleton menu items will be clickable, while submenu items will be represented as a pull down. For instance, say you want a button that allows you to switch between modes A, B, and C. You could represent this as a menu by: a menu item "mode" with three submenu items "A", "B", and "C". By default, this method returns a singleton menu item with item label as the title. For standard items, the target, action is set.
         * @return The converted Objective-C result.
         */
        MenuItem menu_form_representation() const;
        /**
         * @brief Sets the `menuFormRepresentation` property of `NSToolbarItem`.
         * @details The menu form of a toolbar item's purpose is twofold. First, when the window is too small to display an item, it will be clipped but remain accessible from a "clipped items" menu containing the menu item returned here. Second, in text only mode, the menu returned will be used to create the displayed items. Singleton menu items will be clickable, while submenu items will be represented as a pull down. For instance, say you want a button that allows you to switch between modes A, B, and C. You could represent this as a menu by: a menu item "mode" with three submenu items "A", "B", and "C". By default, this method returns a singleton menu item with item label as the title. For standard items, the target, action is set.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_menu_form_representation(const MenuItem& value) const;
        /**
         * @brief Returns the `navigational` property of `NSToolbarItem`.
         * @details Whether or not the item behaves as a navigation item (i.e. back/forward) in the toolbar. Navigation items may be specially positioned by the system outside the normal list of items of the toolbar in the order specified by '-toolbarDefaultItemIdentifiers:'. Defaults to NO.
         * @return The converted Objective-C result.
         */
        bool is_navigational() const;
        /**
         * @brief Sets the `navigational` property of `NSToolbarItem`.
         * @details Whether or not the item behaves as a navigation item (i.e. back/forward) in the toolbar. Navigation items may be specially positioned by the system outside the normal list of items of the toolbar in the order specified by '-toolbarDefaultItemIdentifiers:'. Defaults to NO.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_navigational(bool value) const;
        /**
         * @brief Returns the `paletteLabel` property of `NSToolbarItem`.
         * @details Use this to set the item's label that appears when the item is in the customization palette. All Items must have a palette label, and for most things it is reasonable to set them to the same string as the label used in the toolbar.
         * @return The converted Objective-C result.
         */
        std::string palette_label() const;
        /**
         * @brief Sets the `paletteLabel` property of `NSToolbarItem`.
         * @details Use this to set the item's label that appears when the item is in the customization palette. All Items must have a palette label, and for most things it is reasonable to set them to the same string as the label used in the toolbar.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_palette_label(const std::string& value) const;
        /**
         * @brief Returns the `possibleLabels` property of `NSToolbarItem`.
         * @details An array of all alternate labels this item may display. The item will use the size of the longest label to prevent resizing when the label is changed.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> possible_labels() const;
        /**
         * @brief Sets the `possibleLabels` property of `NSToolbarItem`.
         * @details An array of all alternate labels this item may display. The item will use the size of the longest label to prevent resizing when the label is changed.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_possible_labels(const std::vector<std::string>& value) const;
        /**
         * @brief Returns the `style` property of `NSToolbarItem`.
         * @details Defines the toolbar item’s appearance. The default style is plain. Prominent style tints the background. If a background tint color is set, it uses it; otherwise, it uses the app’s or system’s accent color. If grouped with other items, it moves to its own to avoid tinting other items' background.
         * @return The converted Objective-C result.
         */
        ToolbarItemStyle style() const;
        /**
         * @brief Sets the `style` property of `NSToolbarItem`.
         * @details Defines the toolbar item’s appearance. The default style is plain. Prominent style tints the background. If a background tint color is set, it uses it; otherwise, it uses the app’s or system’s accent color. If grouped with other items, it moves to its own to avoid tinting other items' background.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_style(ToolbarItemStyle value) const;
        /**
         * @brief Returns the `tag` property of `NSToolbarItem`.
         * @details Tag for your own custom purpose. (forwards to '-view' if it responds)
         * @return The converted Objective-C result.
         */
        std::int64_t tag() const;
        /**
         * @brief Sets the `tag` property of `NSToolbarItem`.
         * @details Tag for your own custom purpose. (forwards to '-view' if it responds)
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tag(std::int64_t value) const;
        /**
         * @brief Returns the `target` property of `NSToolbarItem`.
         * @details Set and get the action of an item. (forwards to '-view' if it responds)
         * @return The converted Objective-C result.
         */
        Object target() const;
        /**
         * @brief Sets the `target` property of `NSToolbarItem`.
         * @details Set and get the action of an item. (forwards to '-view' if it responds)
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_target(const Object& value) const;
        /**
         * @brief Returns the `title` property of `NSToolbarItem`.
         * @details Set and get the title of an item. For custom views, this method will call '-setTitle:' on the view if it responds. (forwards to '-view' if it responds)
         * @return The converted Objective-C result.
         */
        std::string title() const;
        /**
         * @brief Sets the `title` property of `NSToolbarItem`.
         * @details Set and get the title of an item. For custom views, this method will call '-setTitle:' on the view if it responds. (forwards to '-view' if it responds)
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_title(const std::string& value) const;
        /**
         * @brief Returns the `toolTip` property of `NSToolbarItem`.
         * @details Use this to set a tooltip to be used when the item is displayed in the toolbar. (forwards to '-view' if it responds)
         * @return The converted Objective-C result.
         */
        std::string tool_tip() const;
        /**
         * @brief Sets the `toolTip` property of `NSToolbarItem`.
         * @details Use this to set a tooltip to be used when the item is displayed in the toolbar. (forwards to '-view' if it responds)
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tool_tip(const std::string& value) const;
        /**
         * @brief Returns the `toolbar` property of `NSToolbarItem`.
         * @details Use this to determine the toolbar in which an item is currently displayed.
         * @return The converted Objective-C result.
         */
        Toolbar toolbar() const;
        /**
         * @brief Returns the `view` property of `NSToolbarItem`.
         * @details Items with automatically generated views will return nil from this getter. Custom views may be provided but not all 'NSToolbarItem' subclasses support custom views. Note that, by default, many of the set/get methods will be implemented by calls forwarded to the view you set, if it responds to it.
         * @return The converted Objective-C result.
         */
        View view() const;
        /**
         * @brief Sets the `view` property of `NSToolbarItem`.
         * @details Items with automatically generated views will return nil from this getter. Custom views may be provided but not all 'NSToolbarItem' subclasses support custom views. Note that, by default, many of the set/get methods will be implemented by calls forwarded to the view you set, if it responds to it.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_view(const View& value) const;
        /**
         * @brief Returns the `visibilityPriority` property of `NSToolbarItem`.
         * @details When a toolbar does not have enough space to fit all its items, it must push some into the overflow menu. Items with the highest 'visibilityPriority' level are chosen last for the overflow menu. The default 'visibilityPriority' value is 'NSToolbarItemVisibilityPriorityStandard'. To suggest that an item always remain visible, give it a value greater than 'NSToolbarItemVisibilityPriorityStandard', but less than 'NSToolbarItemVisibilityPriorityUser'. In 10.7, users can no longer modify the toolbar item visibility priority.
         * @return The converted Objective-C result.
         */
        std::int64_t visibility_priority() const;
        /**
         * @brief Sets the `visibilityPriority` property of `NSToolbarItem`.
         * @details When a toolbar does not have enough space to fit all its items, it must push some into the overflow menu. Items with the highest 'visibilityPriority' level are chosen last for the overflow menu. The default 'visibilityPriority' value is 'NSToolbarItemVisibilityPriorityStandard'. To suggest that an item always remain visible, give it a value greater than 'NSToolbarItemVisibilityPriorityStandard', but less than 'NSToolbarItemVisibilityPriorityUser'. In 10.7, users can no longer modify the toolbar item visibility priority.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_visibility_priority(std::int64_t value) const;
        /**
         * @brief Returns the `visible` property of `NSToolbarItem`.
         * @details An item is visible if it is present in the NSToolbar and not in the overflow menu. This property is key value observable.
         * @return The converted Objective-C result.
         */
        bool is_visible() const;
        /// @brief Signal `clicked`: connect a callback with `clicked().connect(...)`.
        Signal<ToolbarItem, void()> clicked() const
        {
            return Signal<ToolbarItem, void()>(handle(), "clicked");
        }

    protected:
        static void bind_action_(void* native);
    };
}
