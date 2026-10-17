#include "generated/menu_item_badge.h"
#include "internal.h"

namespace cocoon
{
    MenuItemBadge::MenuItemBadge(std::int64_t item_count) : MenuItemBadge(Adopt{cocoon::internal::retain([[::NSMenuItemBadge alloc] initWithCount:static_cast<::NSInteger>(item_count)])})
    {
    }

    MenuItemBadge::MenuItemBadge(std::int64_t item_count, MenuItemBadgeType type) : MenuItemBadge(Adopt{cocoon::internal::retain([[::NSMenuItemBadge alloc] initWithCount:static_cast<::NSInteger>(item_count) type:static_cast<::NSMenuItemBadgeType>(type)])})
    {
    }

    MenuItemBadge::MenuItemBadge(const std::string& string) : MenuItemBadge(Adopt{cocoon::internal::retain([[::NSMenuItemBadge alloc] initWithString:cocoon::internal::to(string)])})
    {
    }

    MenuItemBadge::MenuItemBadge() : Object(nullptr)
    {
    }

    MenuItemBadge::MenuItemBadge(std::nullptr_t) : Object(nullptr)
    {
    }

    MenuItemBadge::MenuItemBadge(Adopt adopt) : Object(adopt)
    {
    }

    MenuItemBadge MenuItemBadge::alerts_with_count(std::int64_t item_count)
    {
        return cocoon::internal::wrap<MenuItemBadge>([::NSMenuItemBadge alertsWithCount:static_cast<::NSInteger>(item_count)]);
    }

    MenuItemBadge MenuItemBadge::new_items_with_count(std::int64_t item_count)
    {
        return cocoon::internal::wrap<MenuItemBadge>([::NSMenuItemBadge newItemsWithCount:static_cast<::NSInteger>(item_count)]);
    }

    MenuItemBadge MenuItemBadge::updates_with_count(std::int64_t item_count)
    {
        return cocoon::internal::wrap<MenuItemBadge>([::NSMenuItemBadge updatesWithCount:static_cast<::NSInteger>(item_count)]);
    }

    std::int64_t MenuItemBadge::item_count() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMenuItemBadge>(this) itemCount]);
    }

    std::string MenuItemBadge::string_value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMenuItemBadge>(this) stringValue]);
    }

    MenuItemBadgeType MenuItemBadge::type() const
    {
        return static_cast<MenuItemBadgeType>([cocoon::internal::ns<::NSMenuItemBadge>(this) type]);
    }
}
