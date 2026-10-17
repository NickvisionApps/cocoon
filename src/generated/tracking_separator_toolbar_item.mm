#include "generated/tracking_separator_toolbar_item.h"
#include "internal.h"

namespace cocoon
{
    TrackingSeparatorToolbarItem::TrackingSeparatorToolbarItem() : TrackingSeparatorToolbarItem(Adopt{cocoon::internal::retain([[::NSTrackingSeparatorToolbarItem alloc] init])})
    {
        ToolbarItem::bind_action_(handle());
    }

    TrackingSeparatorToolbarItem::TrackingSeparatorToolbarItem(std::nullptr_t) : ToolbarItem(nullptr)
    {
    }

    TrackingSeparatorToolbarItem::TrackingSeparatorToolbarItem(Adopt adopt) : ToolbarItem(adopt)
    {
    }

    TrackingSeparatorToolbarItem TrackingSeparatorToolbarItem::tracking_separator_toolbar_item_with_identifier(const std::string& identifier, const SplitView& split_view, std::int64_t divider_index)
    {
        return cocoon::internal::wrap<TrackingSeparatorToolbarItem>([::NSTrackingSeparatorToolbarItem trackingSeparatorToolbarItemWithIdentifier:cocoon::internal::to(identifier) splitView:cocoon::internal::native<::NSSplitView>(split_view) dividerIndex:static_cast<::NSInteger>(divider_index)]);
    }

    std::int64_t TrackingSeparatorToolbarItem::divider_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTrackingSeparatorToolbarItem>(this) dividerIndex]);
    }

    void TrackingSeparatorToolbarItem::set_divider_index(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSTrackingSeparatorToolbarItem>(this) setDividerIndex:static_cast<::NSInteger>(value)];
    }

    SplitView TrackingSeparatorToolbarItem::split_view() const
    {
        return cocoon::internal::wrap<SplitView>([cocoon::internal::ns<::NSTrackingSeparatorToolbarItem>(this) splitView]);
    }

    void TrackingSeparatorToolbarItem::set_split_view(const SplitView& value) const
    {
        [cocoon::internal::ns<::NSTrackingSeparatorToolbarItem>(this) setSplitView:cocoon::internal::native<::NSSplitView>(value)];
    }
}
