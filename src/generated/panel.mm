#include "generated/panel.h"
#include "internal.h"

namespace cocoon
{
    Panel::Panel() : Panel(Adopt{cocoon::internal::retain([[::NSPanel alloc] init])})
    {
        Window::install_delegate_delegate_(handle());
    }

    Panel::Panel(std::nullptr_t) : Window(nullptr)
    {
    }

    Panel::Panel(Adopt adopt) : Window(adopt)
    {
    }

    bool Panel::becomes_key_only_if_needed() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPanel>(this) becomesKeyOnlyIfNeeded]);
    }

    void Panel::set_becomes_key_only_if_needed(bool value) const
    {
        [cocoon::internal::ns<::NSPanel>(this) setBecomesKeyOnlyIfNeeded:static_cast<::BOOL>(value)];
    }

    bool Panel::is_floating_panel() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPanel>(this) isFloatingPanel]);
    }

    void Panel::set_floating_panel(bool value) const
    {
        [cocoon::internal::ns<::NSPanel>(this) setFloatingPanel:static_cast<::BOOL>(value)];
    }

    bool Panel::works_when_modal() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPanel>(this) worksWhenModal]);
    }

    void Panel::set_works_when_modal(bool value) const
    {
        [cocoon::internal::ns<::NSPanel>(this) setWorksWhenModal:static_cast<::BOOL>(value)];
    }
}
