#include "generated/status_bar_button.h"
#include "internal.h"

namespace cocoon
{
    StatusBarButton::StatusBarButton() : StatusBarButton(Adopt{cocoon::internal::retain([[::NSStatusBarButton alloc] init])})
    {
        Button::bind_action_(handle());
    }

    StatusBarButton::StatusBarButton(std::nullptr_t) : Button(nullptr)
    {
    }

    StatusBarButton::StatusBarButton(Adopt adopt) : Button(adopt)
    {
    }

    bool StatusBarButton::appears_disabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSStatusBarButton>(this) appearsDisabled]);
    }

    void StatusBarButton::set_appears_disabled(bool value) const
    {
        [cocoon::internal::ns<::NSStatusBarButton>(this) setAppearsDisabled:static_cast<::BOOL>(value)];
    }
}
