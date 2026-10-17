#include "generated/split_view_item_accessory_view_controller.h"
#include "internal.h"

namespace cocoon
{
    SplitViewItemAccessoryViewController::SplitViewItemAccessoryViewController() : SplitViewItemAccessoryViewController(Adopt{cocoon::internal::retain([[::NSSplitViewItemAccessoryViewController alloc] init])})
    {
    }

    SplitViewItemAccessoryViewController::SplitViewItemAccessoryViewController(std::nullptr_t) : ViewController(nullptr)
    {
    }

    SplitViewItemAccessoryViewController::SplitViewItemAccessoryViewController(Adopt adopt) : ViewController(adopt)
    {
    }

    void SplitViewItemAccessoryViewController::view_did_appear() const
    {
        [cocoon::internal::ns<::NSSplitViewItemAccessoryViewController>(this) viewDidAppear];
    }

    void SplitViewItemAccessoryViewController::view_did_disappear() const
    {
        [cocoon::internal::ns<::NSSplitViewItemAccessoryViewController>(this) viewDidDisappear];
    }

    void SplitViewItemAccessoryViewController::view_will_appear() const
    {
        [cocoon::internal::ns<::NSSplitViewItemAccessoryViewController>(this) viewWillAppear];
    }

    void SplitViewItemAccessoryViewController::view_will_disappear() const
    {
        [cocoon::internal::ns<::NSSplitViewItemAccessoryViewController>(this) viewWillDisappear];
    }

    bool SplitViewItemAccessoryViewController::automatically_applies_content_insets() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSplitViewItemAccessoryViewController>(this) automaticallyAppliesContentInsets]);
    }

    void SplitViewItemAccessoryViewController::set_automatically_applies_content_insets(bool value) const
    {
        [cocoon::internal::ns<::NSSplitViewItemAccessoryViewController>(this) setAutomaticallyAppliesContentInsets:static_cast<::BOOL>(value)];
    }

    bool SplitViewItemAccessoryViewController::is_hidden() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSplitViewItemAccessoryViewController>(this) isHidden]);
    }

    void SplitViewItemAccessoryViewController::set_hidden(bool value) const
    {
        [cocoon::internal::ns<::NSSplitViewItemAccessoryViewController>(this) setHidden:static_cast<::BOOL>(value)];
    }

    ScrollEdgeEffectStyle SplitViewItemAccessoryViewController::preferred_scroll_edge_effect_style() const
    {
        if (@available(macOS 26.1, *))
        {
            return cocoon::internal::wrap<ScrollEdgeEffectStyle>([cocoon::internal::ns<::NSSplitViewItemAccessoryViewController>(this) preferredScrollEdgeEffectStyle]);
        }
        return ScrollEdgeEffectStyle(nullptr);
    }

    void SplitViewItemAccessoryViewController::set_preferred_scroll_edge_effect_style(const ScrollEdgeEffectStyle& value) const
    {
        if (@available(macOS 26.1, *))
        {
            [cocoon::internal::ns<::NSSplitViewItemAccessoryViewController>(this) setPreferredScrollEdgeEffectStyle:cocoon::internal::native<::NSScrollEdgeEffectStyle>(value)];
        }
    }
}
