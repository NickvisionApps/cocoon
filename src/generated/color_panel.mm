#include "generated/color_panel.h"
#include "internal.h"

namespace cocoon
{
    ColorPanel::ColorPanel() : ColorPanel(Adopt{cocoon::internal::retain([[::NSColorPanel alloc] init])})
    {
        Window::install_delegate_delegate_(handle());
    }

    ColorPanel::ColorPanel(std::nullptr_t) : Panel(nullptr)
    {
    }

    ColorPanel::ColorPanel(Adopt adopt) : Panel(adopt)
    {
    }

    void ColorPanel::attach_color_list(const ColorList& color_list) const
    {
        [cocoon::internal::ns<::NSColorPanel>(this) attachColorList:cocoon::internal::native<::NSColorList>(color_list)];
    }

    void ColorPanel::detach_color_list(const ColorList& color_list) const
    {
        [cocoon::internal::ns<::NSColorPanel>(this) detachColorList:cocoon::internal::native<::NSColorList>(color_list)];
    }

    bool ColorPanel::drag_color(const Color& color, const Event& event, const View& source_view)
    {
        return static_cast<bool>([::NSColorPanel dragColor:cocoon::internal::native<::NSColor>(color) withEvent:cocoon::internal::native<::NSEvent>(event) fromView:cocoon::internal::native<::NSView>(source_view)]);
    }

    void ColorPanel::set_action(const std::string& selector) const
    {
        [cocoon::internal::ns<::NSColorPanel>(this) setAction:NSSelectorFromString(cocoon::internal::to(selector))];
    }

    void ColorPanel::set_picker_mask(ColorPanelOptions mask)
    {
        [::NSColorPanel setPickerMask:static_cast<::NSColorPanelOptions>(mask)];
    }

    void ColorPanel::set_picker_mode(ColorPanelMode mode)
    {
        [::NSColorPanel setPickerMode:static_cast<::NSColorPanelMode>(mode)];
    }

    void ColorPanel::set_target(const Object& target) const
    {
        [cocoon::internal::ns<::NSColorPanel>(this) setTarget:cocoon::internal::native_id(target)];
    }

    View ColorPanel::accessory_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSColorPanel>(this) accessoryView]);
    }

    void ColorPanel::set_accessory_view(const View& value) const
    {
        [cocoon::internal::ns<::NSColorPanel>(this) setAccessoryView:cocoon::internal::native<::NSView>(value)];
    }

    double ColorPanel::alpha() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColorPanel>(this) alpha]);
    }

    Color ColorPanel::color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSColorPanel>(this) color]);
    }

    void ColorPanel::set_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSColorPanel>(this) setColor:cocoon::internal::native<::NSColor>(value)];
    }

    bool ColorPanel::is_continuous() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSColorPanel>(this) isContinuous]);
    }

    void ColorPanel::set_continuous(bool value) const
    {
        [cocoon::internal::ns<::NSColorPanel>(this) setContinuous:static_cast<::BOOL>(value)];
    }

    double ColorPanel::maximum_linear_exposure() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColorPanel>(this) maximumLinearExposure]);
    }

    void ColorPanel::set_maximum_linear_exposure(double value) const
    {
        [cocoon::internal::ns<::NSColorPanel>(this) setMaximumLinearExposure:static_cast<::CGFloat>(value)];
    }

    ColorPanelMode ColorPanel::mode() const
    {
        return static_cast<ColorPanelMode>([cocoon::internal::ns<::NSColorPanel>(this) mode]);
    }

    void ColorPanel::set_mode(ColorPanelMode value) const
    {
        [cocoon::internal::ns<::NSColorPanel>(this) setMode:static_cast<::NSColorPanelMode>(value)];
    }

    ColorPanel ColorPanel::shared_color_panel()
    {
        return cocoon::internal::wrap<ColorPanel>([::NSColorPanel sharedColorPanel]);
    }

    bool ColorPanel::shared_color_panel_exists()
    {
        return static_cast<bool>([::NSColorPanel sharedColorPanelExists]);
    }

    bool ColorPanel::shows_alpha() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSColorPanel>(this) showsAlpha]);
    }

    void ColorPanel::set_shows_alpha(bool value) const
    {
        [cocoon::internal::ns<::NSColorPanel>(this) setShowsAlpha:static_cast<::BOOL>(value)];
    }
}
