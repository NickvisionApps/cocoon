#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSItemBadge` (AppKit).
     * @details 'NSItemBadge' represents a badge that can be attached to an 'NSToolbarItem'. This badge provides a way to display small visual indicators, such as counts and text labels, within a toolbar item. Badges can be used to highlight important information, such as unread notifications or status indicators.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ItemBadge item_badge;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ItemBadge item_badge{};
     * auto made_0 = cocoon::ItemBadge::badge_with_count(1);
     * auto made_1 = cocoon::ItemBadge::badge_with_text("text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsitembadge
     */
    class ItemBadge : public Object
    {
    public:
        /// @brief Creates a new `NSItemBadge` instance and returns a handle to it.
        explicit ItemBadge();
        /// @brief Creates a null handle that refers to no native object.
        ItemBadge(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ItemBadge(Adopt adopt);
        /**
         * @brief Calls `+[NSItemBadge badgeWithCount:]`.
         * @details Creates a badge displaying a localized numerical count. \@param count The integer value to localize and display in the badge. \@return A new NSItemBadge instance with the localized specified count.
         * @param count Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static ItemBadge badge_with_count(std::int64_t count);
        /**
         * @brief Calls `+[NSItemBadge badgeWithText:]`.
         * @details Creates a badge displaying a text. \@param text The text to be displayed inside the badge. \@return A new 'NSItemBadge' instance with the specified text.
         * @param text Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static ItemBadge badge_with_text(const std::string& text);
        /**
         * @brief Calls `+[NSItemBadge indicatorBadge]`.
         * @details Creates a badge styled as an indicator. In this context, an indicator is simply a badge without any text. \@return A new 'NSItemBadge' instance styled as an indicator.
         * @return The converted Objective-C result.
         */
        static ItemBadge indicator_badge();
        /**
         * @brief Returns the `text` property of `NSItemBadge`.
         * @details The text to be displayed within the badge.
         * @return The converted Objective-C result.
         */
        std::string text() const;
    };
}
