#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSMenuItemBadge` (AppKit).
     * @details A badge used to provide additional quantitative information specific to the menu item, such as the number of available updates.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MenuItemBadge menu_item_badge{1};
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MenuItemBadge menu_item_badge{1};
     * auto made_0 = cocoon::MenuItemBadge::alerts_with_count(1);
     * auto made_1 = cocoon::MenuItemBadge::new_items_with_count(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsmenuitembadge
     */
    class MenuItemBadge : public Object
    {
    public:
        /// @brief Creates a new `NSMenuItemBadge` instance and returns a handle to it.
        explicit MenuItemBadge(std::int64_t item_count);
        /// @brief Creates a new `NSMenuItemBadge` instance and returns a handle to it.
        explicit MenuItemBadge(std::int64_t item_count, MenuItemBadgeType type);
        /// @brief Creates a new `NSMenuItemBadge` instance and returns a handle to it.
        explicit MenuItemBadge(const std::string& string);
        MenuItemBadge();
        /// @brief Creates a null handle that refers to no native object.
        MenuItemBadge(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MenuItemBadge(Adopt adopt);
        /**
         * @brief Calls `+[NSMenuItemBadge alertsWithCount:]`.
         * @details Creates a badge with an integer count and a label representing the number of alerts.
         * @param item_count Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static MenuItemBadge alerts_with_count(std::int64_t item_count);
        /**
         * @brief Calls `+[NSMenuItemBadge newItemsWithCount:]`.
         * @details Creates a badge with an integer count and a label representing the number of new items.
         * @param item_count Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static MenuItemBadge new_items_with_count(std::int64_t item_count);
        /**
         * @brief Calls `+[NSMenuItemBadge updatesWithCount:]`.
         * @details Creates a badge with an integer count and a label representing the number of available updates.
         * @param item_count Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static MenuItemBadge updates_with_count(std::int64_t item_count);
        /**
         * @brief Returns the `itemCount` property of `NSMenuItemBadge`.
         * @details The count of items the badge displays. If a custom string was used to create a badge, the value is 0.
         * @return The converted Objective-C result.
         */
        std::int64_t item_count() const;
        /**
         * @brief Returns the `stringValue` property of `NSMenuItemBadge`.
         * @details The string representation of the badge as it would appear when the badge is displayed.
         * @return The converted Objective-C result.
         */
        std::string string_value() const;
        /**
         * @brief Returns the `type` property of `NSMenuItemBadge`.
         * @details The type of items the badge displays. If a custom string was used to create a badge, this value is \@c NSMenuItemBadgeTypeNone.
         * @return The converted Objective-C result.
         */
        MenuItemBadgeType type() const;
    };
}
