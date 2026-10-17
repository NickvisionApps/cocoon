#include "generated/color.h"
#include "internal.h"

namespace cocoon
{
    Color::Color(double red, double green, double blue, double alpha) : Color(Adopt{cocoon::internal::retain([NSColor colorWithSRGBRed:red green:green blue:blue alpha:alpha])})
    {
    }

    Color::Color() : Color(Adopt{cocoon::internal::retain([[::NSColor alloc] init])})
    {
    }

    Color::Color(std::nullptr_t) : Object(nullptr)
    {
    }

    Color::Color(Adopt adopt) : Object(adopt)
    {
    }

    Color Color::blended_color_with_fraction(double fraction, const Color& color) const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSColor>(this) blendedColorWithFraction:static_cast<::CGFloat>(fraction) ofColor:cocoon::internal::native<::NSColor>(color)]);
    }

    Color Color::color_by_applying_content_headroom(double content_headroom) const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSColor>(this) colorByApplyingContentHeadroom:static_cast<::CGFloat>(content_headroom)]);
    }

    Color Color::color_from_pasteboard(const Pasteboard& paste_board)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorFromPasteboard:cocoon::internal::native<::NSPasteboard>(paste_board)]);
    }

    Color Color::color_named(const std::string& name)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorNamed:cocoon::internal::to(name)]);
    }

    Color Color::color_named(const std::string& name, const Bundle& bundle)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorNamed:cocoon::internal::to(name) bundle:cocoon::internal::native<::NSBundle>(bundle)]);
    }

    Color Color::color_using_color_space(const ColorSpace& space) const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSColor>(this) colorUsingColorSpace:cocoon::internal::native<::NSColorSpace>(space)]);
    }

    Color Color::color_using_type(ColorType type) const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSColor>(this) colorUsingType:static_cast<::NSColorType>(type)]);
    }

    Color Color::color_with_alpha_component(double alpha) const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSColor>(this) colorWithAlphaComponent:static_cast<::CGFloat>(alpha)]);
    }

    Color Color::color_with_cg_color(const CGColor& cg_color)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithCGColor:((::CGColorRef)(cg_color).handle())]);
    }

    Color Color::color_with_ci_color(const CIColor& color)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithCIColor:cocoon::internal::native<::CIColor>(color)]);
    }

    Color Color::color_with_calibrated_hue(double hue, double saturation, double brightness, double alpha)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithCalibratedHue:static_cast<::CGFloat>(hue) saturation:static_cast<::CGFloat>(saturation) brightness:static_cast<::CGFloat>(brightness) alpha:static_cast<::CGFloat>(alpha)]);
    }

    Color Color::color_with_calibrated_red(double red, double green, double blue, double alpha)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithCalibratedRed:static_cast<::CGFloat>(red) green:static_cast<::CGFloat>(green) blue:static_cast<::CGFloat>(blue) alpha:static_cast<::CGFloat>(alpha)]);
    }

    Color Color::color_with_calibrated_white(double white, double alpha)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithCalibratedWhite:static_cast<::CGFloat>(white) alpha:static_cast<::CGFloat>(alpha)]);
    }

    Color Color::color_with_catalog_name(const std::string& list_name, const std::string& color_name)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithCatalogName:cocoon::internal::to(list_name) colorName:cocoon::internal::to(color_name)]);
    }

    Color Color::color_with_color_space(const ColorSpace& space, const double* components, std::int64_t number_of_components)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithColorSpace:cocoon::internal::native<::NSColorSpace>(space) components:(const ::CGFloat*)(components)count:static_cast<::NSInteger>(number_of_components)]);
    }

    Color Color::color_with_color_space(const ColorSpace& space, double hue, double saturation, double brightness, double alpha)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithColorSpace:cocoon::internal::native<::NSColorSpace>(space) hue:static_cast<::CGFloat>(hue) saturation:static_cast<::CGFloat>(saturation) brightness:static_cast<::CGFloat>(brightness) alpha:static_cast<::CGFloat>(alpha)]);
    }

    Color Color::color_with_device_cyan(double cyan, double magenta, double yellow, double black, double alpha)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithDeviceCyan:static_cast<::CGFloat>(cyan) magenta:static_cast<::CGFloat>(magenta) yellow:static_cast<::CGFloat>(yellow) black:static_cast<::CGFloat>(black) alpha:static_cast<::CGFloat>(alpha)]);
    }

    Color Color::color_with_device_hue(double hue, double saturation, double brightness, double alpha)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithDeviceHue:static_cast<::CGFloat>(hue) saturation:static_cast<::CGFloat>(saturation) brightness:static_cast<::CGFloat>(brightness) alpha:static_cast<::CGFloat>(alpha)]);
    }

    Color Color::color_with_device_red(double red, double green, double blue, double alpha)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithDeviceRed:static_cast<::CGFloat>(red) green:static_cast<::CGFloat>(green) blue:static_cast<::CGFloat>(blue) alpha:static_cast<::CGFloat>(alpha)]);
    }

    Color Color::color_with_device_white(double white, double alpha)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithDeviceWhite:static_cast<::CGFloat>(white) alpha:static_cast<::CGFloat>(alpha)]);
    }

    Color Color::color_with_display_p3_red(double red, double green, double blue, double alpha)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithDisplayP3Red:static_cast<::CGFloat>(red) green:static_cast<::CGFloat>(green) blue:static_cast<::CGFloat>(blue) alpha:static_cast<::CGFloat>(alpha)]);
    }

    Color Color::color_with_generic_gamma22_white(double white, double alpha)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithGenericGamma22White:static_cast<::CGFloat>(white) alpha:static_cast<::CGFloat>(alpha)]);
    }

    Color Color::color_with_hue(double hue, double saturation, double brightness, double alpha)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithHue:static_cast<::CGFloat>(hue) saturation:static_cast<::CGFloat>(saturation) brightness:static_cast<::CGFloat>(brightness) alpha:static_cast<::CGFloat>(alpha)]);
    }

    Color Color::color_with_name(const std::string& color_name, std::function<Color(Appearance)> dynamic_provider)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithName:cocoon::internal::to(color_name) dynamicProvider:(dynamic_provider ? (::NSColor * (^)(::NSAppearance*)) ^ ::NSColor * (::NSAppearance * a19_0) { auto __r = dynamic_provider(cocoon::internal::wrap<Appearance>(a19_0)); return cocoon::internal::native<::NSColor>(__r); } : (::NSColor * (^)(::NSAppearance*)) nil)]);
    }

    Color Color::color_with_pattern_image(const Image& image)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithPatternImage:cocoon::internal::native<::NSImage>(image)]);
    }

    Color Color::color_with_red(double red, double green, double blue, double alpha)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithRed:static_cast<::CGFloat>(red) green:static_cast<::CGFloat>(green) blue:static_cast<::CGFloat>(blue) alpha:static_cast<::CGFloat>(alpha)]);
    }

    Color Color::color_with_red(double red, double green, double blue, double alpha, double exposure)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithRed:static_cast<::CGFloat>(red) green:static_cast<::CGFloat>(green) blue:static_cast<::CGFloat>(blue) alpha:static_cast<::CGFloat>(alpha) exposure:static_cast<::CGFloat>(exposure)]);
    }

    Color Color::color_with_srgb_red(double red, double green, double blue, double alpha)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithSRGBRed:static_cast<::CGFloat>(red) green:static_cast<::CGFloat>(green) blue:static_cast<::CGFloat>(blue) alpha:static_cast<::CGFloat>(alpha)]);
    }

    Color Color::color_with_system_effect(ColorSystemEffect system_effect) const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSColor>(this) colorWithSystemEffect:static_cast<::NSColorSystemEffect>(system_effect)]);
    }

    Color Color::color_with_white(double white, double alpha)
    {
        return cocoon::internal::wrap<Color>([::NSColor colorWithWhite:static_cast<::CGFloat>(white) alpha:static_cast<::CGFloat>(alpha)]);
    }

    void Color::draw_swatch_in_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSColor>(this) drawSwatchInRect:cocoon::internal::to(rect)];
    }

    void Color::get_components(double* components) const
    {
        [cocoon::internal::ns<::NSColor>(this) getComponents:(::CGFloat*)(components)];
    }

    void Color::get_cyan(double* cyan, double* magenta, double* yellow, double* black, double* alpha) const
    {
        [cocoon::internal::ns<::NSColor>(this) getCyan:(::CGFloat*)(cyan) magenta:(::CGFloat*)(magenta)yellow:(::CGFloat*)(yellow)black:(::CGFloat*)(black)alpha:(::CGFloat*)(alpha)];
    }

    void Color::get_hue(double* hue, double* saturation, double* brightness, double* alpha) const
    {
        [cocoon::internal::ns<::NSColor>(this) getHue:(::CGFloat*)(hue) saturation:(::CGFloat*)(saturation)brightness:(::CGFloat*)(brightness)alpha:(::CGFloat*)(alpha)];
    }

    void Color::get_red(double* red, double* green, double* blue, double* alpha) const
    {
        [cocoon::internal::ns<::NSColor>(this) getRed:(::CGFloat*)(red) green:(::CGFloat*)(green)blue:(::CGFloat*)(blue)alpha:(::CGFloat*)(alpha)];
    }

    void Color::get_white(double* white, double* alpha) const
    {
        [cocoon::internal::ns<::NSColor>(this) getWhite:(::CGFloat*)(white) alpha:(::CGFloat*)(alpha)];
    }

    Color Color::highlight_with_level(double val) const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSColor>(this) highlightWithLevel:static_cast<::CGFloat>(val)]);
    }

    void Color::set() const
    {
        [cocoon::internal::ns<::NSColor>(this) set];
    }

    void Color::set_fill() const
    {
        [cocoon::internal::ns<::NSColor>(this) setFill];
    }

    void Color::set_stroke() const
    {
        [cocoon::internal::ns<::NSColor>(this) setStroke];
    }

    Color Color::shadow_with_level(double val) const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSColor>(this) shadowWithLevel:static_cast<::CGFloat>(val)]);
    }

    void Color::write_to_pasteboard(const Pasteboard& paste_board) const
    {
        [cocoon::internal::ns<::NSColor>(this) writeToPasteboard:cocoon::internal::native<::NSPasteboard>(paste_board)];
    }

    CGColor Color::cg_color() const
    {
        return cocoon::internal::wrap_cf<CGColor>((const void*)([cocoon::internal::ns<::NSColor>(this) CGColor]));
    }

    double Color::alpha_component() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColor>(this) alphaComponent]);
    }

    Color Color::alternate_selected_control_text_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor alternateSelectedControlTextColor]);
    }

    std::vector<Color> Color::alternating_content_background_colors()
    {
        return cocoon::internal::from_array<Color>([::NSColor alternatingContentBackgroundColors], [](id e) -> Color
                                                   {
                                                       return cocoon::internal::wrap<Color>((::NSColor*)e);
                                                   });
    }

    Color Color::black_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor blackColor]);
    }

    double Color::black_component() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColor>(this) blackComponent]);
    }

    Color Color::blue_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor blueColor]);
    }

    double Color::blue_component() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColor>(this) blueComponent]);
    }

    double Color::brightness_component() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColor>(this) brightnessComponent]);
    }

    Color Color::brown_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor brownColor]);
    }

    std::string Color::catalog_name_component() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSColor>(this) catalogNameComponent]);
    }

    Color Color::clear_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor clearColor]);
    }

    std::string Color::color_name_component() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSColor>(this) colorNameComponent]);
    }

    ColorSpace Color::color_space() const
    {
        return cocoon::internal::wrap<ColorSpace>([cocoon::internal::ns<::NSColor>(this) colorSpace]);
    }

    Color Color::control_accent_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor controlAccentColor]);
    }

    Color Color::control_background_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor controlBackgroundColor]);
    }

    Color Color::control_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor controlColor]);
    }

    Color Color::control_text_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor controlTextColor]);
    }

    ControlTint Color::current_control_tint()
    {
        return static_cast<ControlTint>([::NSColor currentControlTint]);
    }

    Color Color::cyan_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor cyanColor]);
    }

    double Color::cyan_component() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColor>(this) cyanComponent]);
    }

    Color Color::dark_gray_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor darkGrayColor]);
    }

    Color Color::disabled_control_text_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor disabledControlTextColor]);
    }

    Color Color::find_highlight_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor findHighlightColor]);
    }

    Color Color::gray_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor grayColor]);
    }

    Color Color::green_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor greenColor]);
    }

    double Color::green_component() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColor>(this) greenComponent]);
    }

    Color Color::grid_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor gridColor]);
    }

    Color Color::header_text_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor headerTextColor]);
    }

    Color Color::highlight_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor highlightColor]);
    }

    double Color::hue_component() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColor>(this) hueComponent]);
    }

    Color Color::keyboard_focus_indicator_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor keyboardFocusIndicatorColor]);
    }

    Color Color::label_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor labelColor]);
    }

    Color Color::light_gray_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor lightGrayColor]);
    }

    double Color::linear_exposure() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColor>(this) linearExposure]);
    }

    Color Color::link_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor linkColor]);
    }

    std::string Color::localized_catalog_name_component() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSColor>(this) localizedCatalogNameComponent]);
    }

    std::string Color::localized_color_name_component() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSColor>(this) localizedColorNameComponent]);
    }

    Color Color::magenta_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor magentaColor]);
    }

    double Color::magenta_component() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColor>(this) magentaComponent]);
    }

    std::int64_t Color::number_of_components() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSColor>(this) numberOfComponents]);
    }

    Color Color::orange_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor orangeColor]);
    }

    Image Color::pattern_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSColor>(this) patternImage]);
    }

    Color Color::placeholder_text_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor placeholderTextColor]);
    }

    Color Color::purple_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor purpleColor]);
    }

    Color Color::quaternary_label_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor quaternaryLabelColor]);
    }

    Color Color::quaternary_system_fill_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor quaternarySystemFillColor]);
    }

    Color Color::quinary_label_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor quinaryLabelColor]);
    }

    Color Color::quinary_system_fill_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor quinarySystemFillColor]);
    }

    Color Color::red_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor redColor]);
    }

    double Color::red_component() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColor>(this) redComponent]);
    }

    double Color::saturation_component() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColor>(this) saturationComponent]);
    }

    Color Color::scrubber_textured_background_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor scrubberTexturedBackgroundColor]);
    }

    Color Color::secondary_label_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor secondaryLabelColor]);
    }

    Color Color::secondary_system_fill_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor secondarySystemFillColor]);
    }

    Color Color::selected_content_background_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor selectedContentBackgroundColor]);
    }

    Color Color::selected_control_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor selectedControlColor]);
    }

    Color Color::selected_control_text_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor selectedControlTextColor]);
    }

    Color Color::selected_menu_item_text_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor selectedMenuItemTextColor]);
    }

    Color Color::selected_text_background_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor selectedTextBackgroundColor]);
    }

    Color Color::selected_text_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor selectedTextColor]);
    }

    Color Color::separator_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor separatorColor]);
    }

    Color Color::shadow_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor shadowColor]);
    }

    Color Color::standard_dynamic_range_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSColor>(this) standardDynamicRangeColor]);
    }

    Color Color::system_blue_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor systemBlueColor]);
    }

    Color Color::system_brown_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor systemBrownColor]);
    }

    Color Color::system_cyan_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor systemCyanColor]);
    }

    Color Color::system_fill_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor systemFillColor]);
    }

    Color Color::system_gray_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor systemGrayColor]);
    }

    Color Color::system_green_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor systemGreenColor]);
    }

    Color Color::system_indigo_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor systemIndigoColor]);
    }

    Color Color::system_mint_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor systemMintColor]);
    }

    Color Color::system_orange_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor systemOrangeColor]);
    }

    Color Color::system_pink_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor systemPinkColor]);
    }

    Color Color::system_purple_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor systemPurpleColor]);
    }

    Color Color::system_red_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor systemRedColor]);
    }

    Color Color::system_teal_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor systemTealColor]);
    }

    Color Color::system_yellow_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor systemYellowColor]);
    }

    Color Color::tertiary_label_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor tertiaryLabelColor]);
    }

    Color Color::tertiary_system_fill_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor tertiarySystemFillColor]);
    }

    Color Color::text_background_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor textBackgroundColor]);
    }

    Color Color::text_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor textColor]);
    }

    Color Color::text_insertion_point_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor textInsertionPointColor]);
    }

    ColorType Color::type() const
    {
        return static_cast<ColorType>([cocoon::internal::ns<::NSColor>(this) type]);
    }

    Color Color::under_page_background_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor underPageBackgroundColor]);
    }

    Color Color::unemphasized_selected_content_background_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor unemphasizedSelectedContentBackgroundColor]);
    }

    Color Color::unemphasized_selected_text_background_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor unemphasizedSelectedTextBackgroundColor]);
    }

    Color Color::unemphasized_selected_text_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor unemphasizedSelectedTextColor]);
    }

    Color Color::white_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor whiteColor]);
    }

    double Color::white_component() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColor>(this) whiteComponent]);
    }

    Color Color::window_background_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor windowBackgroundColor]);
    }

    Color Color::window_frame_text_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor windowFrameTextColor]);
    }

    Color Color::yellow_color()
    {
        return cocoon::internal::wrap<Color>([::NSColor yellowColor]);
    }

    double Color::yellow_component() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSColor>(this) yellowComponent]);
    }
}
