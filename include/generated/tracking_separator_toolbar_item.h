#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/toolbar_item.h"
#include "types.h"

namespace cocoon
{
    class SplitView;

    /**
     * @brief C++ handle for the Objective-C class `NSTrackingSeparatorToolbarItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ToolbarItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TrackingSeparatorToolbarItem tracking_separator_toolbar_item;
     * tracking_separator_toolbar_item.set_divider_index(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TrackingSeparatorToolbarItem tracking_separator_toolbar_item{};
     * tracking_separator_toolbar_item.set_divider_index(1);
     * auto divider_index = tracking_separator_toolbar_item.divider_index();
     * tracking_separator_toolbar_item.set_split_view(cocoon::SplitView());
     * auto split_view = tracking_separator_toolbar_item.split_view();
     * auto made_0 = cocoon::TrackingSeparatorToolbarItem::tracking_separator_toolbar_item_with_identifier("text", cocoon::SplitView(), 1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstrackingseparatortoolbaritem
     */
    class TrackingSeparatorToolbarItem : public ToolbarItem
    {
    public:
        /// @brief Creates a new `NSTrackingSeparatorToolbarItem` instance and returns a handle to it.
        explicit TrackingSeparatorToolbarItem();
        /// @brief Creates a null handle that refers to no native object.
        TrackingSeparatorToolbarItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TrackingSeparatorToolbarItem(Adopt adopt);
        /**
     * @brief Calls `+[NSTrackingSeparatorToolbarItem trackingSeparatorToolbarItemWithIdentifier:splitView:dividerIndex:]`.
     * @details Creates a new 'NSTrackingSeparatorToolbarItem' and configures it to attempt to visually align with the specified divider of the 'splitView'. The 'splitView' must be in the same window as the toolbar containing this item by the time the toolbar is shown. Only vertical 'splitViews' are supported.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @param split_view Argument converted to the Objective-C parameter of the same role.
     * @param divider_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TrackingSeparatorToolbarItem tracking_separator_toolbar_item_with_identifier(const std::string& identifier, const SplitView& split_view, std::int64_t divider_index);
        /**
     * @brief Returns the `dividerIndex` property of `NSTrackingSeparatorToolbarItem`.
     * @details The specific divider of the 'splitView' which will be tracked.
     * @return The converted Objective-C result.
     */
        std::int64_t divider_index() const;
        /**
     * @brief Sets the `dividerIndex` property of `NSTrackingSeparatorToolbarItem`.
     * @details The specific divider of the 'splitView' which will be tracked.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_divider_index(std::int64_t value) const;
        /**
     * @brief Returns the `splitView` property of `NSTrackingSeparatorToolbarItem`.
     * @details The 'splitView' must be in the same window as the toolbar containing this item by the time the toolbar is shown. Only vertical 'splitViews' are supported.
     * @return The converted Objective-C result.
     */
        SplitView split_view() const;
        /**
     * @brief Sets the `splitView` property of `NSTrackingSeparatorToolbarItem`.
     * @details The 'splitView' must be in the same window as the toolbar containing this item by the time the toolbar is shown. Only vertical 'splitViews' are supported.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_split_view(const SplitView& value) const;
    };
}
