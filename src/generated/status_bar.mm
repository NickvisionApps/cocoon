#include "generated/status_bar.h"
#include "internal.h"

namespace cocoon
{
    StatusBar::StatusBar() : StatusBar(Adopt{cocoon::internal::retain([[::NSStatusBar alloc] init])})
    {
    }

    StatusBar::StatusBar(std::nullptr_t) : Object(nullptr)
    {
    }

    StatusBar::StatusBar(Adopt adopt) : Object(adopt)
    {
    }

    void StatusBar::remove_status_item(const StatusItem& item) const
    {
        [cocoon::internal::ns<::NSStatusBar>(this) removeStatusItem:cocoon::internal::native<::NSStatusItem>(item)];
    }

    StatusItem StatusBar::status_item_with_length(double length) const
    {
        return cocoon::internal::wrap<StatusItem>([cocoon::internal::ns<::NSStatusBar>(this) statusItemWithLength:static_cast<::CGFloat>(length)]);
    }

    StatusBar StatusBar::system_status_bar()
    {
        return cocoon::internal::wrap<StatusBar>([::NSStatusBar systemStatusBar]);
    }

    double StatusBar::thickness() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStatusBar>(this) thickness]);
    }

    bool StatusBar::is_vertical() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSStatusBar>(this) isVertical]);
    }
}
