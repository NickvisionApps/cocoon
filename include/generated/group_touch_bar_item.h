#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/touch_bar_item.h"
#include "types.h"

namespace cocoon
{
    class TouchBar;
    class TouchBarItem;
    class UserInterfaceCompressionOptions;

    /**
     * @brief C++ handle for the Objective-C class `NSGroupTouchBarItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TouchBarItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::GroupTouchBarItem group_touch_bar_item(nullptr);  // null handle; instances normally come from other API calls
     * group_touch_bar_item.set_customization_label("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::GroupTouchBarItem group_touch_bar_item(nullptr);
     * group_touch_bar_item.set_customization_label("text");
     * auto customization_label = group_touch_bar_item.customization_label();
     * group_touch_bar_item.set_group_touch_bar(cocoon::TouchBar());
     * auto group_touch_bar = group_touch_bar_item.group_touch_bar();
     * group_touch_bar_item.set_group_user_interface_layout_direction(cocoon::UserInterfaceLayoutDirection::LeftToRight);
     * auto group_user_interface_layout_direction = group_touch_bar_item.group_user_interface_layout_direction();
     * auto made_0 = cocoon::GroupTouchBarItem::alert_style_group_item_with_identifier("text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsgrouptouchbaritem
     */
    class GroupTouchBarItem : public TouchBarItem
    {
    public:
        GroupTouchBarItem();
        /// @brief Creates a null handle that refers to no native object.
        GroupTouchBarItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit GroupTouchBarItem(Adopt adopt);
        using TouchBarItem::customization_label;
        /**
     * @brief Calls `+[NSGroupTouchBarItem alertStyleGroupItemWithIdentifier:]`.
     * @details Creates a NSGroupTouchBarItem with the appropriate settings to match system style alerts in NSTouchBar. Spacing between items is under control of the client, but in general NSTouchBarItemIdentifierFixedSpaceLarge is recommended anywhere additional spacing is required. The groupUserInterfaceLayoutDirection will be set to [NSApp userInterfaceLayoutDirection].
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static GroupTouchBarItem alert_style_group_item_with_identifier(const std::string& identifier);
        /**
     * @brief Calls `+[NSGroupTouchBarItem groupItemWithIdentifier:items:]`.
     * @details Returns an autoreleased NSGroupTouchBarItem whose groupTouchBar is built from the given items array. Customization is not enabled by default when creating an NSGroupTouchBarItem this way.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @param items Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static GroupTouchBarItem group_item_with_identifier(const std::string& identifier, const std::vector<TouchBarItem>& items);
        /**
     * @brief Calls `+[NSGroupTouchBarItem groupItemWithIdentifier:items:allowedCompressionOptions:]`.
     * @details Creates a NSGroupTouchBarItem with the allowed compression options provided in the order AppKit defines. Default order: BreakEqualWidths, ReduceMetrics, HideText, HideImages. This should only be used with standard options provided by AppKit. Custom options need to be added using the prioritizedCompressionOptions property.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @param items Argument converted to the Objective-C parameter of the same role.
     * @param allowed_compression_options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static GroupTouchBarItem group_item_with_identifier(const std::string& identifier, const std::vector<TouchBarItem>& items, const UserInterfaceCompressionOptions& allowed_compression_options);
        /**
     * @brief Returns the `customizationLabel` property of `NSGroupTouchBarItem`.
     * @details The localized string labelling this item during user customization. The default value is the empty string. This property is archived.
     * @return The converted Objective-C result.
     */
        std::string customization_label() const;
        /**
     * @brief Sets the `customizationLabel` property of `NSGroupTouchBarItem`.
     * @details The localized string labelling this item during user customization. The default value is the empty string. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_customization_label(const std::string& value) const;
        /**
     * @brief Returns the `effectiveCompressionOptions` property of `NSGroupTouchBarItem`.
     * @details The currently active NSUserInterfaceCompressionOptions on the group.
     * @return The converted Objective-C result.
     */
        UserInterfaceCompressionOptions effective_compression_options() const;
        /**
     * @brief Returns the `groupTouchBar` property of `NSGroupTouchBarItem`.
     * @details An NSTouchBar, presented seamlessly as part of the NSTouchBar this item is hosted in. The NSTouchBar may have its own principal item, and can be customized (or not) per the normal customization rules. By default this is an empty bar that cannot be customized. This property is archived.
     * @return The converted Objective-C result.
     */
        TouchBar group_touch_bar() const;
        /**
     * @brief Sets the `groupTouchBar` property of `NSGroupTouchBarItem`.
     * @details An NSTouchBar, presented seamlessly as part of the NSTouchBar this item is hosted in. The NSTouchBar may have its own principal item, and can be customized (or not) per the normal customization rules. By default this is an empty bar that cannot be customized. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_group_touch_bar(const TouchBar& value) const;
        /**
     * @brief Returns the `groupUserInterfaceLayoutDirection` property of `NSGroupTouchBarItem`.
     * @details Get and set the user interface layout direction of the groupTouchBar, which defines the order in which the items should be laid out. By default, this value is NSUserInterfaceLayoutDirectionLeftToRight. To flip the layout direction of the group to the user’s preferred layout, this should be set to [NSApp userInterfaceLayoutDirection].
     * @return The converted Objective-C result.
     */
        UserInterfaceLayoutDirection group_user_interface_layout_direction() const;
        /**
     * @brief Sets the `groupUserInterfaceLayoutDirection` property of `NSGroupTouchBarItem`.
     * @details Get and set the user interface layout direction of the groupTouchBar, which defines the order in which the items should be laid out. By default, this value is NSUserInterfaceLayoutDirectionLeftToRight. To flip the layout direction of the group to the user’s preferred layout, this should be set to [NSApp userInterfaceLayoutDirection].
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_group_user_interface_layout_direction(UserInterfaceLayoutDirection value) const;
        /**
     * @brief Returns the `preferredItemWidth` property of `NSGroupTouchBarItem`.
     * @details The preferred width for items in the group when prefersEqualWidths is YES. This is the width that items will be set to if they fit, and the item doesn't clip. Optional; ignored if \<0. Defaults to -1.
     * @return The converted Objective-C result.
     */
        double preferred_item_width() const;
        /**
     * @brief Sets the `preferredItemWidth` property of `NSGroupTouchBarItem`.
     * @details The preferred width for items in the group when prefersEqualWidths is YES. This is the width that items will be set to if they fit, and the item doesn't clip. Optional; ignored if \<0. Defaults to -1.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_item_width(double value) const;
        /**
     * @brief Returns the `prefersEqualWidths` property of `NSGroupTouchBarItem`.
     * @details When set, items in the associated groupTouchBar will be sized to have equal widths when possible. Defaults to NO.
     * @return The converted Objective-C result.
     */
        bool prefers_equal_widths() const;
        /**
     * @brief Sets the `prefersEqualWidths` property of `NSGroupTouchBarItem`.
     * @details When set, items in the associated groupTouchBar will be sized to have equal widths when possible. Defaults to NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_prefers_equal_widths(bool value) const;
        /**
     * @brief Returns the `prioritizedCompressionOptions` property of `NSGroupTouchBarItem`.
     * @details The allowed compression options in the order they will be exercised. Client defined options should be added to specify the order in which they will be exercised. Options not included will be ignored. Defaults to an array containing all standard AppKit options in the order AppKit defines.
     * @return The converted Objective-C result.
     */
        std::vector<UserInterfaceCompressionOptions> prioritized_compression_options() const;
        /**
     * @brief Sets the `prioritizedCompressionOptions` property of `NSGroupTouchBarItem`.
     * @details The allowed compression options in the order they will be exercised. Client defined options should be added to specify the order in which they will be exercised. Options not included will be ignored. Defaults to an array containing all standard AppKit options in the order AppKit defines.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_prioritized_compression_options(const std::vector<UserInterfaceCompressionOptions>& value) const;
    };
}
