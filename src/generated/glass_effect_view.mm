#include "generated/glass_effect_view.h"
#include "internal.h"

namespace cocoon
{
    GlassEffectView::GlassEffectView() : GlassEffectView(Adopt{cocoon::internal::retain([[NSGlassEffectView alloc] init])})
    {
    }

    GlassEffectView::GlassEffectView(std::nullptr_t) : View(nullptr)
    {
    }

    GlassEffectView::GlassEffectView(Adopt adopt) : View(adopt)
    {
    }

    View GlassEffectView::content_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSGlassEffectView>(this) contentView]);
    }

    void GlassEffectView::set_content_view(const View& value) const
    {
        [cocoon::internal::ns<::NSGlassEffectView>(this) setContentView:cocoon::internal::native<::NSView>(value)];
    }

    double GlassEffectView::corner_radius() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSGlassEffectView>(this) cornerRadius]);
    }

    void GlassEffectView::set_corner_radius(double value) const
    {
        [cocoon::internal::ns<::NSGlassEffectView>(this) setCornerRadius:static_cast<::CGFloat>(value)];
    }

    bool GlassEffectView::effect_is_interactive() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<bool>([cocoon::internal::ns<::NSGlassEffectView>(this) effectIsInteractive]);
        }
        return {};
    }

    void GlassEffectView::set_effect_is_interactive(bool value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSGlassEffectView>(this) setEffectIsInteractive:static_cast<::BOOL>(value)];
        }
    }

    GlassStyle GlassEffectView::style() const
    {
        return static_cast<GlassStyle>([cocoon::internal::ns<::NSGlassEffectView>(this) style]);
    }

    void GlassEffectView::set_style(GlassStyle value) const
    {
        [cocoon::internal::ns<::NSGlassEffectView>(this) setStyle:static_cast<::NSGlassEffectViewStyle>(value)];
    }

    Color GlassEffectView::tint_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSGlassEffectView>(this) tintColor]);
    }

    void GlassEffectView::set_tint_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSGlassEffectView>(this) setTintColor:cocoon::internal::native<::NSColor>(value)];
    }
}
