#include "generated/dock_tile.h"
#include "internal.h"

namespace cocoon
{
    DockTile::DockTile() : DockTile(Adopt{cocoon::internal::retain([[::NSDockTile alloc] init])})
    {
    }

    DockTile::DockTile(std::nullptr_t) : Object(nullptr)
    {
    }

    DockTile::DockTile(Adopt adopt) : Object(adopt)
    {
    }

    void DockTile::display() const
    {
        [cocoon::internal::ns<::NSDockTile>(this) display];
    }

    std::string DockTile::badge_label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDockTile>(this) badgeLabel]);
    }

    void DockTile::set_badge_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSDockTile>(this) setBadgeLabel:cocoon::internal::to(value)];
    }

    View DockTile::content_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSDockTile>(this) contentView]);
    }

    void DockTile::set_content_view(const View& value) const
    {
        [cocoon::internal::ns<::NSDockTile>(this) setContentView:cocoon::internal::native<::NSView>(value)];
    }

    Object DockTile::owner() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSDockTile>(this) owner]);
    }

    bool DockTile::shows_application_badge() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDockTile>(this) showsApplicationBadge]);
    }

    void DockTile::set_shows_application_badge(bool value) const
    {
        [cocoon::internal::ns<::NSDockTile>(this) setShowsApplicationBadge:static_cast<::BOOL>(value)];
    }

    Size DockTile::size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDockTile>(this) size]);
    }
}
