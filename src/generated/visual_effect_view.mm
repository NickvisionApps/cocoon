#include "generated/visual_effect_view.h"
#include "internal.h"

namespace cocoon
{
    VisualEffectView::VisualEffectView() : VisualEffectView(Adopt{cocoon::internal::retain([[NSVisualEffectView alloc] init])})
    {
    }

    VisualEffectView::VisualEffectView(std::nullptr_t) : View(nullptr)
    {
    }

    VisualEffectView::VisualEffectView(Adopt adopt) : View(adopt)
    {
    }

    void VisualEffectView::view_did_move_to_window() const
    {
        [cocoon::internal::ns<::NSVisualEffectView>(this) viewDidMoveToWindow];
    }

    void VisualEffectView::view_will_move_to_window(const Window& new_window) const
    {
        [cocoon::internal::ns<::NSVisualEffectView>(this) viewWillMoveToWindow:cocoon::internal::native<::NSWindow>(new_window)];
    }

    VisualEffectBlendingMode VisualEffectView::blending_mode() const
    {
        return static_cast<VisualEffectBlendingMode>([cocoon::internal::ns<::NSVisualEffectView>(this) blendingMode]);
    }

    void VisualEffectView::set_blending_mode(VisualEffectBlendingMode value) const
    {
        [cocoon::internal::ns<::NSVisualEffectView>(this) setBlendingMode:static_cast<::NSVisualEffectBlendingMode>(value)];
    }

    bool VisualEffectView::is_emphasized() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSVisualEffectView>(this) isEmphasized]);
    }

    void VisualEffectView::set_emphasized(bool value) const
    {
        [cocoon::internal::ns<::NSVisualEffectView>(this) setEmphasized:static_cast<::BOOL>(value)];
    }

    BackgroundStyle VisualEffectView::interior_background_style() const
    {
        return static_cast<BackgroundStyle>([cocoon::internal::ns<::NSVisualEffectView>(this) interiorBackgroundStyle]);
    }

    Image VisualEffectView::mask_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSVisualEffectView>(this) maskImage]);
    }

    void VisualEffectView::set_mask_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSVisualEffectView>(this) setMaskImage:cocoon::internal::native<::NSImage>(value)];
    }

    VisualEffectMaterial VisualEffectView::material() const
    {
        return static_cast<VisualEffectMaterial>([cocoon::internal::ns<::NSVisualEffectView>(this) material]);
    }

    void VisualEffectView::set_material(VisualEffectMaterial value) const
    {
        [cocoon::internal::ns<::NSVisualEffectView>(this) setMaterial:static_cast<::NSVisualEffectMaterial>(value)];
    }

    VisualEffectState VisualEffectView::state() const
    {
        return static_cast<VisualEffectState>([cocoon::internal::ns<::NSVisualEffectView>(this) state]);
    }

    void VisualEffectView::set_state(VisualEffectState value) const
    {
        [cocoon::internal::ns<::NSVisualEffectView>(this) setState:static_cast<::NSVisualEffectState>(value)];
    }
}
