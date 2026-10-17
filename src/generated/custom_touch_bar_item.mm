#include "generated/custom_touch_bar_item.h"
#include "internal.h"

namespace cocoon
{
    CustomTouchBarItem::CustomTouchBarItem() : TouchBarItem(nullptr)
    {
    }

    CustomTouchBarItem::CustomTouchBarItem(std::nullptr_t) : TouchBarItem(nullptr)
    {
    }

    CustomTouchBarItem::CustomTouchBarItem(Adopt adopt) : TouchBarItem(adopt)
    {
    }

    std::string CustomTouchBarItem::customization_label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCustomTouchBarItem>(this) customizationLabel]);
    }

    void CustomTouchBarItem::set_customization_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSCustomTouchBarItem>(this) setCustomizationLabel:cocoon::internal::to(value)];
    }

    View CustomTouchBarItem::view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSCustomTouchBarItem>(this) view]);
    }

    void CustomTouchBarItem::set_view(const View& value) const
    {
        [cocoon::internal::ns<::NSCustomTouchBarItem>(this) setView:cocoon::internal::native<::NSView>(value)];
    }

    ViewController CustomTouchBarItem::view_controller() const
    {
        return cocoon::internal::wrap<ViewController>([cocoon::internal::ns<::NSCustomTouchBarItem>(this) viewController]);
    }

    void CustomTouchBarItem::set_view_controller(const ViewController& value) const
    {
        [cocoon::internal::ns<::NSCustomTouchBarItem>(this) setViewController:cocoon::internal::native<::NSViewController>(value)];
    }
}
