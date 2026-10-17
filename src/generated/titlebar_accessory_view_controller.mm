#include "generated/titlebar_accessory_view_controller.h"
#include "internal.h"

namespace cocoon
{
    TitlebarAccessoryViewController::TitlebarAccessoryViewController() : TitlebarAccessoryViewController(Adopt{cocoon::internal::retain([[::NSTitlebarAccessoryViewController alloc] init])})
    {
    }

    TitlebarAccessoryViewController::TitlebarAccessoryViewController(std::nullptr_t) : ViewController(nullptr)
    {
    }

    TitlebarAccessoryViewController::TitlebarAccessoryViewController(Adopt adopt) : ViewController(adopt)
    {
    }

    void TitlebarAccessoryViewController::view_did_appear() const
    {
        [cocoon::internal::ns<::NSTitlebarAccessoryViewController>(this) viewDidAppear];
    }

    void TitlebarAccessoryViewController::view_did_disappear() const
    {
        [cocoon::internal::ns<::NSTitlebarAccessoryViewController>(this) viewDidDisappear];
    }

    void TitlebarAccessoryViewController::view_will_appear() const
    {
        [cocoon::internal::ns<::NSTitlebarAccessoryViewController>(this) viewWillAppear];
    }

    bool TitlebarAccessoryViewController::automatically_adjusts_size() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTitlebarAccessoryViewController>(this) automaticallyAdjustsSize]);
    }

    void TitlebarAccessoryViewController::set_automatically_adjusts_size(bool value) const
    {
        [cocoon::internal::ns<::NSTitlebarAccessoryViewController>(this) setAutomaticallyAdjustsSize:static_cast<::BOOL>(value)];
    }

    double TitlebarAccessoryViewController::full_screen_min_height() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTitlebarAccessoryViewController>(this) fullScreenMinHeight]);
    }

    void TitlebarAccessoryViewController::set_full_screen_min_height(double value) const
    {
        [cocoon::internal::ns<::NSTitlebarAccessoryViewController>(this) setFullScreenMinHeight:static_cast<::CGFloat>(value)];
    }

    bool TitlebarAccessoryViewController::is_hidden() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTitlebarAccessoryViewController>(this) isHidden]);
    }

    void TitlebarAccessoryViewController::set_hidden(bool value) const
    {
        [cocoon::internal::ns<::NSTitlebarAccessoryViewController>(this) setHidden:static_cast<::BOOL>(value)];
    }

    LayoutAttribute TitlebarAccessoryViewController::layout_attribute() const
    {
        return static_cast<LayoutAttribute>([cocoon::internal::ns<::NSTitlebarAccessoryViewController>(this) layoutAttribute]);
    }

    void TitlebarAccessoryViewController::set_layout_attribute(LayoutAttribute value) const
    {
        [cocoon::internal::ns<::NSTitlebarAccessoryViewController>(this) setLayoutAttribute:static_cast<::NSLayoutAttribute>(value)];
    }

    ScrollEdgeEffectStyle TitlebarAccessoryViewController::preferred_scroll_edge_effect_style() const
    {
        if (@available(macOS 26.1, *))
        {
            return cocoon::internal::wrap<ScrollEdgeEffectStyle>([cocoon::internal::ns<::NSTitlebarAccessoryViewController>(this) preferredScrollEdgeEffectStyle]);
        }
        return ScrollEdgeEffectStyle(nullptr);
    }

    void TitlebarAccessoryViewController::set_preferred_scroll_edge_effect_style(const ScrollEdgeEffectStyle& value) const
    {
        if (@available(macOS 26.1, *))
        {
            [cocoon::internal::ns<::NSTitlebarAccessoryViewController>(this) setPreferredScrollEdgeEffectStyle:cocoon::internal::native<::NSScrollEdgeEffectStyle>(value)];
        }
    }
}
