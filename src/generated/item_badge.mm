#include "generated/item_badge.h"
#include "internal.h"

namespace cocoon
{
    ItemBadge::ItemBadge() : ItemBadge(Adopt{cocoon::internal::retain([[::NSItemBadge alloc] init])})
    {
    }

    ItemBadge::ItemBadge(std::nullptr_t) : Object(nullptr)
    {
    }

    ItemBadge::ItemBadge(Adopt adopt) : Object(adopt)
    {
    }

    ItemBadge ItemBadge::badge_with_count(std::int64_t count)
    {
        return cocoon::internal::wrap<ItemBadge>([::NSItemBadge badgeWithCount:static_cast<::NSInteger>(count)]);
    }

    ItemBadge ItemBadge::badge_with_text(const std::string& text)
    {
        return cocoon::internal::wrap<ItemBadge>([::NSItemBadge badgeWithText:cocoon::internal::to(text)]);
    }

    ItemBadge ItemBadge::indicator_badge()
    {
        return cocoon::internal::wrap<ItemBadge>([::NSItemBadge indicatorBadge]);
    }

    std::string ItemBadge::text() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSItemBadge>(this) text]);
    }
}
