#include "generated/status_item.h"
#include "internal.h"

namespace cocoon
{
    StatusItem::StatusItem() : StatusItem(Adopt{cocoon::internal::retain([[::NSStatusItem alloc] init])})
    {
    }

    StatusItem::StatusItem(std::nullptr_t) : Object(nullptr)
    {
    }

    StatusItem::StatusItem(Adopt adopt) : Object(adopt)
    {
    }

    std::string StatusItem::autosave_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSStatusItem>(this) autosaveName]);
    }

    void StatusItem::set_autosave_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSStatusItem>(this) setAutosaveName:cocoon::internal::to(value)];
    }

    StatusItemBehavior StatusItem::behavior() const
    {
        return static_cast<StatusItemBehavior>([cocoon::internal::ns<::NSStatusItem>(this) behavior]);
    }

    void StatusItem::set_behavior(StatusItemBehavior value) const
    {
        [cocoon::internal::ns<::NSStatusItem>(this) setBehavior:static_cast<::NSStatusItemBehavior>(value)];
    }

    StatusBarButton StatusItem::button() const
    {
        return cocoon::internal::wrap<StatusBarButton>([cocoon::internal::ns<::NSStatusItem>(this) button]);
    }

    double StatusItem::length() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStatusItem>(this) length]);
    }

    void StatusItem::set_length(double value) const
    {
        [cocoon::internal::ns<::NSStatusItem>(this) setLength:static_cast<::CGFloat>(value)];
    }

    Menu StatusItem::menu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSStatusItem>(this) menu]);
    }

    void StatusItem::set_menu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSStatusItem>(this) setMenu:cocoon::internal::native<::NSMenu>(value)];
    }

    StatusBar StatusItem::status_bar() const
    {
        return cocoon::internal::wrap<StatusBar>([cocoon::internal::ns<::NSStatusItem>(this) statusBar]);
    }

    bool StatusItem::is_visible() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSStatusItem>(this) isVisible]);
    }

    void StatusItem::set_visible(bool value) const
    {
        [cocoon::internal::ns<::NSStatusItem>(this) setVisible:static_cast<::BOOL>(value)];
    }
}
