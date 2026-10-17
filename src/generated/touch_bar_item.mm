#include "generated/touch_bar_item.h"
#include "internal.h"

namespace cocoon
{
    TouchBarItem::TouchBarItem(const std::string& identifier) : TouchBarItem(Adopt{cocoon::internal::retain([[::NSTouchBarItem alloc] initWithIdentifier:cocoon::internal::to(identifier)])})
    {
    }

    TouchBarItem::TouchBarItem() : Object(nullptr)
    {
    }

    TouchBarItem::TouchBarItem(std::nullptr_t) : Object(nullptr)
    {
    }

    TouchBarItem::TouchBarItem(Adopt adopt) : Object(adopt)
    {
    }

    std::string TouchBarItem::customization_label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTouchBarItem>(this) customizationLabel]);
    }

    std::string TouchBarItem::identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTouchBarItem>(this) identifier]);
    }

    View TouchBarItem::view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSTouchBarItem>(this) view]);
    }

    ViewController TouchBarItem::view_controller() const
    {
        return cocoon::internal::wrap<ViewController>([cocoon::internal::ns<::NSTouchBarItem>(this) viewController]);
    }

    float TouchBarItem::visibility_priority() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSTouchBarItem>(this) visibilityPriority]);
    }

    void TouchBarItem::set_visibility_priority(float value) const
    {
        [cocoon::internal::ns<::NSTouchBarItem>(this) setVisibilityPriority:static_cast<::NSTouchBarItemPriority>(value)];
    }

    bool TouchBarItem::is_visible() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTouchBarItem>(this) isVisible]);
    }
}
