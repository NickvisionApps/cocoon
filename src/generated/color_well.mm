#include "generated/color_well.h"
#include "internal.h"

namespace cocoon
{
    ColorWell::ColorWell() : ColorWell(Adopt{cocoon::internal::retain([[NSColorWell alloc] init])})
    {
        ColorWell::bind_action_(handle());
    }

    ColorWell::ColorWell(std::nullptr_t) : Control(nullptr)
    {
    }

    ColorWell::ColorWell(Adopt adopt) : Control(adopt)
    {
    }

    void ColorWell::activate(bool exclusive) const
    {
        [cocoon::internal::ns<::NSColorWell>(this) activate:static_cast<::BOOL>(exclusive)];
    }

    ColorWell ColorWell::color_well_with_style(ColorWellStyle style)
    {
        return cocoon::internal::wrap<ColorWell>([::NSColorWell colorWellWithStyle:static_cast<::NSColorWellStyle>(style)]);
    }

    void ColorWell::deactivate() const
    {
        [cocoon::internal::ns<::NSColorWell>(this) deactivate];
    }

    void ColorWell::draw_well_inside(const Rect& inside_rect) const
    {
        [cocoon::internal::ns<::NSColorWell>(this) drawWellInside:cocoon::internal::to(inside_rect)];
    }

    void ColorWell::take_color_from(const Object& sender) const
    {
        [cocoon::internal::ns<::NSColorWell>(this) takeColorFrom:cocoon::internal::native_id(sender)];
    }

    bool ColorWell::is_active() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSColorWell>(this) isActive]);
    }

    bool ColorWell::is_bordered() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSColorWell>(this) isBordered]);
    }

    void ColorWell::set_bordered(bool value) const
    {
        [cocoon::internal::ns<::NSColorWell>(this) setBordered:static_cast<::BOOL>(value)];
    }

    Color ColorWell::color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSColorWell>(this) color]);
    }

    void ColorWell::set_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSColorWell>(this) setColor:cocoon::internal::native<::NSColor>(value)];
    }

    ColorWellStyle ColorWell::color_well_style() const
    {
        return static_cast<ColorWellStyle>([cocoon::internal::ns<::NSColorWell>(this) colorWellStyle]);
    }

    void ColorWell::set_color_well_style(ColorWellStyle value) const
    {
        [cocoon::internal::ns<::NSColorWell>(this) setColorWellStyle:static_cast<::NSColorWellStyle>(value)];
    }

    Image ColorWell::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSColorWell>(this) image]);
    }

    void ColorWell::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSColorWell>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }

    double ColorWell::maximum_linear_exposure() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColorWell>(this) maximumLinearExposure]);
    }

    void ColorWell::set_maximum_linear_exposure(double value) const
    {
        [cocoon::internal::ns<::NSColorWell>(this) setMaximumLinearExposure:static_cast<::CGFloat>(value)];
    }

    std::string ColorWell::pulldown_action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSColorWell>(this) pulldownAction]));
    }

    void ColorWell::set_pulldown_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSColorWell>(this) setPulldownAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    Object ColorWell::pulldown_target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSColorWell>(this) pulldownTarget]);
    }

    void ColorWell::set_pulldown_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSColorWell>(this) setPulldownTarget:cocoon::internal::native_id(value)];
    }

    bool ColorWell::supports_alpha() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSColorWell>(this) supportsAlpha]);
    }

    void ColorWell::set_supports_alpha(bool value) const
    {
        [cocoon::internal::ns<::NSColorWell>(this) setSupportsAlpha:static_cast<::BOOL>(value)];
    }

    void ColorWell::bind_action_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::bind_action(host, host, [](id host, id sender)
                        {
                            cocoon::Signal<cocoon::ColorWell, void(Color)>::emit((__bridge void*)host, "color_changed", cocoon::internal::wrap<Color>(((NSColorWell*)sender).color));
                        });
    }
}
