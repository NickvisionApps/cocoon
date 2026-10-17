#include "generated/glass_effect_container_view.h"
#include "internal.h"

namespace cocoon
{
    GlassEffectContainerView::GlassEffectContainerView() : GlassEffectContainerView(Adopt{cocoon::internal::retain([[NSGlassEffectContainerView alloc] init])})
    {
    }

    GlassEffectContainerView::GlassEffectContainerView(std::nullptr_t) : View(nullptr)
    {
    }

    GlassEffectContainerView::GlassEffectContainerView(Adopt adopt) : View(adopt)
    {
    }

    View GlassEffectContainerView::content_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSGlassEffectContainerView>(this) contentView]);
    }

    void GlassEffectContainerView::set_content_view(const View& value) const
    {
        [cocoon::internal::ns<::NSGlassEffectContainerView>(this) setContentView:cocoon::internal::native<::NSView>(value)];
    }

    double GlassEffectContainerView::spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSGlassEffectContainerView>(this) spacing]);
    }

    void GlassEffectContainerView::set_spacing(double value) const
    {
        [cocoon::internal::ns<::NSGlassEffectContainerView>(this) setSpacing:static_cast<::CGFloat>(value)];
    }
}
