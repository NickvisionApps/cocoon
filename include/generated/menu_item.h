#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "standard_action.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Image;
    class Menu;
    class MenuItemBadge;
    class View;

    /**
     * @brief A menu item (NSMenuItem). Shortcuts use strings such as "Cmd+Shift+N".
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * cocoon::MenuItem item("Rename", "Cmd+R");
     * item.set_enabled(true);
     * item.triggered().connect([] {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MenuItem menu_item{"text", "text"};
     * menu_item.set_action("text");
     * auto action = menu_item.action();
     * menu_item.set_allows_automatic_key_equivalent_localization(true);
     * auto allows_automatic_key_equivalent_localization = menu_item.allows_automatic_key_equivalent_localization();
     * menu_item.set_allows_automatic_key_equivalent_mirroring(true);
     * auto allows_automatic_key_equivalent_mirroring = menu_item.allows_automatic_key_equivalent_mirroring();
     * auto made_0 = cocoon::MenuItem::section_header_with_title("text");
     * auto made_1 = cocoon::MenuItem::separator_item();
     * menu_item.triggered().connect([]() {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsmenuitem
     */
    class MenuItem : public Object
    {
    public:
        /// @brief Creates a new `NSMenuItem` instance and returns a handle to it.
        explicit MenuItem(const std::string& title = "", const std::string& shortcut = "");
        /// @brief Creates a new `NSMenuItem` instance and returns a handle to it.
        explicit MenuItem(const std::string& string, const std::string& selector, const std::string& char_code);
        /// @brief Creates a null handle that refers to no native object.
        MenuItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MenuItem(Adopt adopt);
        /**
     * @brief Calls `+[NSMenuItem sectionHeaderWithTitle:]`.
     * @details Creates a menu item representing a section header with the provided title. Section header items are used to provide context to a grouping of menu items. Items created using this method are non-interactive and do not perform an action.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static MenuItem section_header_with_title(const std::string& title);
        /**
     * @brief Calls `+[NSMenuItem separatorItem]`.
     * @return The converted Objective-C result.
     */
        static MenuItem separator_item();
        /**
     * @brief Returns the `action` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        std::string action() const;
        /**
     * @brief Sets the `action` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_action(const std::string& value) const;
        /**
     * @brief Returns the `allowsAutomaticKeyEquivalentLocalization` property of `NSMenuItem`.
     * @details Suppose the system detects a given key equivalent that is not reachable in the current keyboard layout; it will localize the key equivalent to something reachable. By setting this property to NO, you will opt-out this menu item from the system-provided localization. YES by default for apps linked against 12.0 and later SDK.
     * @return The converted Objective-C result.
     */
        bool allows_automatic_key_equivalent_localization() const;
        /**
     * @brief Sets the `allowsAutomaticKeyEquivalentLocalization` property of `NSMenuItem`.
     * @details Suppose the system detects a given key equivalent that is not reachable in the current keyboard layout; it will localize the key equivalent to something reachable. By setting this property to NO, you will opt-out this menu item from the system-provided localization. YES by default for apps linked against 12.0 and later SDK.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_automatic_key_equivalent_localization(bool value) const;
        /**
     * @brief Returns the `allowsAutomaticKeyEquivalentMirroring` property of `NSMenuItem`.
     * @details Suppose the system detects a given key equivalent with the following input string [ ] { } ( ) \< > ← → in a right-to-left user interface environment (NSUserInterfaceLayoutDirectionRightToLeft); in that case, the system will automatically mirror the key equivalent. For example, a pair of menu items with key equivalents { and } will be localized to } and { in a right-to-left user interface. By setting this property to NO, you will opt-out this menu item of automatically mirroring in RTL. It would be best only to do this if your shortcut action will result in some sort of directional change in the UI, e.g. text alignment or a D-pad in a game. YES by default for apps linked against 12.0 and later SDK.
     * @return The converted Objective-C result.
     */
        bool allows_automatic_key_equivalent_mirroring() const;
        /**
     * @brief Sets the `allowsAutomaticKeyEquivalentMirroring` property of `NSMenuItem`.
     * @details Suppose the system detects a given key equivalent with the following input string [ ] { } ( ) \< > ← → in a right-to-left user interface environment (NSUserInterfaceLayoutDirectionRightToLeft); in that case, the system will automatically mirror the key equivalent. For example, a pair of menu items with key equivalents { and } will be localized to } and { in a right-to-left user interface. By setting this property to NO, you will opt-out this menu item of automatically mirroring in RTL. It would be best only to do this if your shortcut action will result in some sort of directional change in the UI, e.g. text alignment or a D-pad in a game. YES by default for apps linked against 12.0 and later SDK.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_automatic_key_equivalent_mirroring(bool value) const;
        /**
     * @brief Returns the `allowsKeyEquivalentWhenHidden` property of `NSMenuItem`.
     * @details By default, when a menu item is hidden, its key equivalent is ignored. By setting this property to YES, you allow a hidden item's key equivalent to be considered when searching for a menu item that matches a key event. This is useful to provide a keyboard shortcut when it's not necessary to have a visible menu item in the menubar. Note that Apple HI guidelines generally recommend that keyboard shortcuts should be clearly indicated in a menu, so this property should be used only rarely.
     * @return The converted Objective-C result.
     */
        bool allows_key_equivalent_when_hidden() const;
        /**
     * @brief Sets the `allowsKeyEquivalentWhenHidden` property of `NSMenuItem`.
     * @details By default, when a menu item is hidden, its key equivalent is ignored. By setting this property to YES, you allow a hidden item's key equivalent to be considered when searching for a menu item that matches a key event. This is useful to provide a keyboard shortcut when it's not necessary to have a visible menu item in the menubar. Note that Apple HI guidelines generally recommend that keyboard shortcuts should be clearly indicated in a menu, so this property should be used only rarely.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_key_equivalent_when_hidden(bool value) const;
        /**
     * @brief Returns the `alternate` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        bool is_alternate() const;
        /**
     * @brief Sets the `alternate` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alternate(bool value) const;
        /**
     * @brief Returns the `attributedTitle` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_title() const;
        /**
     * @brief Sets the `attributedTitle` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_title(const AttributedString& value) const;
        /**
     * @brief Returns the `badge` property of `NSMenuItem`.
     * @details A badge used to provide additional quantitative information specific to the menu item, such as the number of available updates. The default value of this property is 'nil'.
     * @return The converted Objective-C result.
     */
        MenuItemBadge badge() const;
        /**
     * @brief Sets the `badge` property of `NSMenuItem`.
     * @details A badge used to provide additional quantitative information specific to the menu item, such as the number of available updates. The default value of this property is 'nil'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_badge(const MenuItemBadge& value) const;
        /**
     * @brief Returns the `hasSubmenu` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        bool has_submenu() const;
        /**
     * @brief Returns the `hidden` property of `NSMenuItem`.
     * @details Set (and get) the visibility of a menu item. Hidden menu items (or items with a hidden superitem) do not appear in a menu and do not participate in command key matching. isHiddenOrHasHiddenAncestor returns YES if the item is hidden or any of its superitems are hidden.
     * @return The converted Objective-C result.
     */
        bool is_hidden() const;
        /**
     * @brief Sets the `hidden` property of `NSMenuItem`.
     * @details Set (and get) the visibility of a menu item. Hidden menu items (or items with a hidden superitem) do not appear in a menu and do not participate in command key matching. isHiddenOrHasHiddenAncestor returns YES if the item is hidden or any of its superitems are hidden.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hidden(bool value) const;
        /**
     * @brief Returns the `hiddenOrHasHiddenAncestor` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        bool is_hidden_or_has_hidden_ancestor() const;
        /**
     * @brief Returns the `highlighted` property of `NSMenuItem`.
     * @details Indicates whether the menu item should be drawn highlighted or not.
     * @return The converted Objective-C result.
     */
        bool is_highlighted() const;
        /**
     * @brief Returns the `image` property of `NSMenuItem`.
     * @details Set an image that is displayed next to the menu item's title. Note that in macOS 27 and later, AppKit determines the visibility of menu item images, and will typically hide images. Use the 'preferredImageVisibility' property with the '.visible' constant to specify that an image should always be visible.
     * @return The converted Objective-C result.
     */
        Image image() const;
        /**
     * @brief Sets the `image` property of `NSMenuItem`.
     * @details Set an image that is displayed next to the menu item's title. Note that in macOS 27 and later, AppKit determines the visibility of menu item images, and will typically hide images. Use the 'preferredImageVisibility' property with the '.visible' constant to specify that an image should always be visible.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image(const Image& value) const;
        /**
     * @brief Returns the `indentationLevel` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        std::int64_t indentation_level() const;
        /**
     * @brief Sets the `indentationLevel` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_indentation_level(std::int64_t value) const;
        /**
     * @brief Returns the `keyEquivalent` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        std::string key_equivalent() const;
        /**
     * @brief Sets the `keyEquivalent` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_key_equivalent(const std::string& value) const;
        /**
     * @brief Returns the `keyEquivalentModifierMask` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        EventModifierFlags key_equivalent_modifier_mask() const;
        /**
     * @brief Sets the `keyEquivalentModifierMask` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_key_equivalent_modifier_mask(EventModifierFlags value) const;
        /**
     * @brief Returns the `menu` property of `NSMenuItem`.
     * @details \@note Never call the setter method directly: it is there only for subclassers.
     * @return The converted Objective-C result.
     */
        Menu menu() const;
        /**
     * @brief Sets the `menu` property of `NSMenuItem`.
     * @details \@note Never call the setter method directly: it is there only for subclassers.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_menu(const Menu& value) const;
        /**
     * @brief Returns the `mixedStateImage` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        Image mixed_state_image() const;
        /**
     * @brief Sets the `mixedStateImage` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_mixed_state_image(const Image& value) const;
        /**
     * @brief Returns the `offStateImage` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        Image off_state_image() const;
        /**
     * @brief Sets the `offStateImage` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_off_state_image(const Image& value) const;
        /**
     * @brief Returns the `onStateImage` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        Image on_state_image() const;
        /**
     * @brief Sets the `onStateImage` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_on_state_image(const Image& value) const;
        /**
     * @brief Returns the `parentItem` property of `NSMenuItem`.
     * @details \@return The 'NSMenuItem' whose submenu contains the receiver, or nil if the receiver does not have a parent item.
     * @return The converted Objective-C result.
     */
        MenuItem parent_item() const;
#ifdef COCOON_MACOS_27
        /**
     * @brief Returns the `preferredImageVisibility` property of `NSMenuItem`.
     * @details A menu item's image visibility determines whether the item's image is displayed when the menu is open. The default visibility for an item's image is Automatic. With this value, AppKit determines whether the item's image is visible based on system configuration. If an item's image should be visible in all cases, regardless of macOS version or other settings, then set the image visibility to '.visible'.
     * @return The converted Objective-C result.
     */
        MenuItemImageVisibility preferred_image_visibility() const;
#endif
#ifdef COCOON_MACOS_27
        /**
     * @brief Sets the `preferredImageVisibility` property of `NSMenuItem`.
     * @details A menu item's image visibility determines whether the item's image is displayed when the menu is open. The default visibility for an item's image is Automatic. With this value, AppKit determines whether the item's image is visible based on system configuration. If an item's image should be visible in all cases, regardless of macOS version or other settings, then set the image visibility to '.visible'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_image_visibility(MenuItemImageVisibility value) const;
#endif
        /**
     * @brief Returns the `representedObject` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        Object represented_object() const;
        /**
     * @brief Sets the `representedObject` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_represented_object(const Object& value) const;
        /**
     * @brief Returns the `sectionHeader` property of `NSMenuItem`.
     * @details Indicates whether the item is a section header. Section header items are created using the 'sectionHeader(title:)' class method.
     * @return The converted Objective-C result.
     */
        bool is_section_header() const;
        /**
     * @brief Returns the `separatorItem` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        bool is_separator_item() const;
        /**
     * @brief Returns the `state` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        ControlState state() const;
        /**
     * @brief Sets the `state` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_state(ControlState value) const;
        /**
     * @brief Returns the `submenu` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        Menu submenu() const;
        /**
     * @brief Sets the `submenu` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_submenu(const Menu& value) const;
        /**
     * @brief Returns the `subtitle` property of `NSMenuItem`.
     * @details \@abstract Used to specify a standard subtitle for the menu item. \@discussion The subtitle is displayed below the standard title. \@note On macOS 14, a menu item with an attributed title does not show the subtitle. The subtitle is shown on macOS 15 and later.
     * @return The converted Objective-C result.
     */
        std::string subtitle() const;
        /**
     * @brief Sets the `subtitle` property of `NSMenuItem`.
     * @details \@abstract Used to specify a standard subtitle for the menu item. \@discussion The subtitle is displayed below the standard title. \@note On macOS 14, a menu item with an attributed title does not show the subtitle. The subtitle is shown on macOS 15 and later.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_subtitle(const std::string& value) const;
        /**
     * @brief Returns the `tag` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        std::int64_t tag() const;
        /**
     * @brief Sets the `tag` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tag(std::int64_t value) const;
        /**
     * @brief Returns the `target` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        Object target() const;
        /**
     * @brief Sets the `target` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_target(const Object& value) const;
        /**
     * @brief Returns the `title` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
        /**
     * @brief Returns the `toolTip` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        std::string tool_tip() const;
        /**
     * @brief Sets the `toolTip` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tool_tip(const std::string& value) const;
        /**
     * @brief Returns the `userKeyEquivalent` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        std::string user_key_equivalent() const;
        /**
     * @brief Returns the `usesUserKeyEquivalents` property of `NSMenuItem`.
     * @return The converted Objective-C result.
     */
        static bool uses_user_key_equivalents();
        /**
     * @brief Sets the `usesUserKeyEquivalents` property of `NSMenuItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_uses_user_key_equivalents(bool value);
        /**
     * @brief Returns the `view` property of `NSMenuItem`.
     * @details Set (and get) the view for a menu item. By default, a menu item has a nil view. A menu item with a view does not draw its title, state, font, or other standard drawing attributes, and assigns drawing responsibility entirely to the view. Keyboard equivalents and type-select continue to use the key equivalent and title as normal. A menu item with a view sizes itself according to the view's frame, and the width of the other menu items. The menu item will always be at least as wide as its view, but it may be wider. If you want your view to auto-expand to fill the menu item, then make sure that its autoresizing mask has NSViewWidthSizable set; in that case, the view's width at the time setView: is called will be treated as the minimum width for the view. A menu will resize itself as its containing views change frame size. Changes to the view's frame during tracking are reflected immediately in the menu. A view in a menu item will receive mouse and keyboard events normally. During non-sticky menu tracking (manipulating menus with the mouse button held down), a view in a menu item will receive mouseDragged: events. Animation is possible via the usual mechanism (set a timer to call setNeedsDisplay: or display), but because menu tracking occurs in the NSEventTrackingRunLoopMode, you must add the timer to the run loop in that mode. When the menu is opened, the view is added to a window; when the menu is closed the view is removed from the window. Override viewDidMoveToWindow in your view for a convenient place to start/stop animations, reset tracking rects, etc., but do not attempt to move or otherwise modify the window. When a menu item is copied via NSCopying, any attached view is copied via archiving/unarchiving. Menu item views are not supported in the Dock menu.
     * @return The converted Objective-C result.
     */
        View view() const;
        /**
     * @brief Sets the `view` property of `NSMenuItem`.
     * @details Set (and get) the view for a menu item. By default, a menu item has a nil view. A menu item with a view does not draw its title, state, font, or other standard drawing attributes, and assigns drawing responsibility entirely to the view. Keyboard equivalents and type-select continue to use the key equivalent and title as normal. A menu item with a view sizes itself according to the view's frame, and the width of the other menu items. The menu item will always be at least as wide as its view, but it may be wider. If you want your view to auto-expand to fill the menu item, then make sure that its autoresizing mask has NSViewWidthSizable set; in that case, the view's width at the time setView: is called will be treated as the minimum width for the view. A menu will resize itself as its containing views change frame size. Changes to the view's frame during tracking are reflected immediately in the menu. A view in a menu item will receive mouse and keyboard events normally. During non-sticky menu tracking (manipulating menus with the mouse button held down), a view in a menu item will receive mouseDragged: events. Animation is possible via the usual mechanism (set a timer to call setNeedsDisplay: or display), but because menu tracking occurs in the NSEventTrackingRunLoopMode, you must add the timer to the run loop in that mode. When the menu is opened, the view is added to a window; when the menu is closed the view is removed from the window. Override viewDidMoveToWindow in your view for a convenient place to start/stop animations, reset tracking rects, etc., but do not attempt to move or otherwise modify the window. When a menu item is copied via NSCopying, any attached view is copied via archiving/unarchiving. Menu item views are not supported in the Dock menu.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_view(const View& value) const;
        /**
     * @brief Returns the `writingToolsItems` property of `NSMenuItem`.
     * @details An array of standard menu items related to Writing Tools. Each call to this method returns an array of newly allocated instances of NSMenuItem.
     * @return The converted Objective-C result.
     */
        static std::vector<MenuItem> writing_tools_items();
        /// @brief Convenience helper `separator` provided by cocoon.
        static MenuItem separator();
        /// @brief Convenience helper `standard` provided by cocoon.
        static MenuItem standard(StandardAction action);
        /// @brief Convenience helper `set_shortcut` provided by cocoon.
        void set_shortcut(const std::string& shortcut) const;
        /// @brief Convenience helper `is_enabled` provided by cocoon.
        bool is_enabled() const;
        /// @brief Convenience helper `set_enabled` provided by cocoon.
        void set_enabled(bool enabled) const;
        /// @brief Convenience helper `is_checked` provided by cocoon.
        bool is_checked() const;
        /// @brief Convenience helper `set_checked` provided by cocoon.
        void set_checked(bool checked) const;
        /// @brief Signal `triggered`: connect a callback with `triggered().connect(...)`.
        Signal<MenuItem, void()> triggered() const
        {
            return Signal<MenuItem, void()>(handle(), "triggered");
        }

    protected:
        static void bind_action_(void* native);
    };
}
