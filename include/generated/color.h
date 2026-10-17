#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Appearance;
    class Bundle;
    class CGColor;
    class CIColor;
    class ColorSpace;
    class Image;
    class Pasteboard;

    /**
     * @brief A color (NSColor).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * cocoon::Color brand(0.2, 0.4, 0.9);
     * cocoon::Color label = cocoon::Color::label_color();
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Color color{};
     * auto made_0 = cocoon::Color::color_from_pasteboard(cocoon::Pasteboard());
     * auto made_1 = cocoon::Color::color_named("text");
     * color.blended_color_with_fraction(1, cocoon::Color());
     * color.color_by_applying_content_headroom(1);
     * color.color_using_color_space(cocoon::ColorSpace());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscolor
     */
    class Color : public Object
    {
    public:
        /// @brief Creates a new `NSColor` instance and returns a handle to it.
        explicit Color(double red, double green, double blue, double alpha = 1.0);
        /// @brief Creates a new `NSColor` instance and returns a handle to it.
        explicit Color();
        /// @brief Creates a null handle that refers to no native object.
        Color(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Color(Adopt adopt);
        /**
     * @brief Calls `-[NSColor blendedColorWithFraction:ofColor:]`.
     * @details Blend using the NSCalibratedRGB color space. Both colors are converted into the calibrated RGB color space, and they are blended by taking fraction of color and 1 - fraction of the receiver. The result is in the calibrated RGB color space. If the colors cannot be converted into the calibrated RGB color space the blending fails and nil is returned.
     * @param fraction Argument converted to the Objective-C parameter of the same role.
     * @param color Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Color blended_color_with_fraction(double fraction, const Color& color) const;
        /**
     * @brief Calls `-[NSColor colorByApplyingContentHeadroom:]`.
     * @details Reinterpret the color by applying a new 'contentHeadroom' without changing the color components. Changing the 'contentHeadroom' redefines the color relative to a different peak white, changing its behavior under tone mapping and the result of calling 'standardDynamicRangeColor'. The new color will have a 'contentHeadroom' >= 1.0. If called on a color with a color space that does not support extended range, or does not have an equivalent extended range counterpart, this will return 'self'.
     * @param content_headroom Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Color color_by_applying_content_headroom(double content_headroom) const;
        /**
     * @brief Calls `+[NSColor colorFromPasteboard:]`.
     * @details Pasteboard methods
     * @param paste_board Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_from_pasteboard(const Pasteboard& paste_board);
        /**
     * @brief Calls `+[NSColor colorNamed:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_named(const std::string& name);
        /**
     * @brief Calls `+[NSColor colorNamed:bundle:]`.
     * @details Create catalog colors from values stored with the given name in the Asset Catalog of the specified bundle. To look in the main bundle, use the method without the bundle argument, or specify a nil bundle argument.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param bundle Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_named(const std::string& name, const Bundle& bundle);
        /**
     * @brief Calls `-[NSColor colorUsingColorSpace:]`.
     * @details colorUsingColorSpace: will convert existing color to a new color space, if the receiver can be represented as a component-based color. This method will return the receiver if its colorspace is already the same as the one specified. Will return nil if conversion is not possible. This method is highly recommended before using any specialized component accessors such as redComponent, cyanComponent, etc, since these will raise an exception if the color is not in an appropriate color space.
     * @param space Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Color color_using_color_space(const ColorSpace& space) const;
        /**
     * @brief Calls `-[NSColor colorUsingType:]`.
     * @details Convert the color to a color of different type; return nil if conversion is not possible.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Color color_using_type(ColorType type) const;
        /**
     * @brief Calls `-[NSColor colorWithAlphaComponent:]`.
     * @details Returns a color in the same color space as the receiver with the specified alpha component. The abstract implementation of this method returns the receiver if alpha is 1.0, otherwise it returns nil; subclassers who have explicit opacity components override this method to actually return a color with the specified alpha.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Color color_with_alpha_component(double alpha) const;
        /**
     * @brief Calls `+[NSColor colorWithCGColor:]`.
     * @details Convert to and from CGColorRef.
     * @param cg_color Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_cg_color(const CGColor& cg_color);
        /**
     * @brief Calls `+[NSColor colorWithCIColor:]`.
     * @param color Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_ci_color(const CIColor& color);
        /**
     * @brief Calls `+[NSColor colorWithCalibratedHue:saturation:brightness:alpha:]`.
     * @param hue Argument converted to the Objective-C parameter of the same role.
     * @param saturation Argument converted to the Objective-C parameter of the same role.
     * @param brightness Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_calibrated_hue(double hue, double saturation, double brightness, double alpha);
        /**
     * @brief Calls `+[NSColor colorWithCalibratedRed:green:blue:alpha:]`.
     * @param red Argument converted to the Objective-C parameter of the same role.
     * @param green Argument converted to the Objective-C parameter of the same role.
     * @param blue Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_calibrated_red(double red, double green, double blue, double alpha);
        /**
     * @brief Calls `+[NSColor colorWithCalibratedWhite:alpha:]`.
     * @details Create component-based colors in NSCalibratedWhiteColorSpace or NSCalibratedRGBColorSpace color spaces. In general it's best to avoid these methods, since sRGB or P3 colors are preferred over the calibrated (aka "generic") color spaces.
     * @param white Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_calibrated_white(double white, double alpha);
        /**
     * @brief Calls `+[NSColor colorWithCatalogName:colorName:]`.
     * @details Look up and return catalog colors from standard color catalogs, or from NSColorList whose name matches the specified catalog name.
     * @param list_name Argument converted to the Objective-C parameter of the same role.
     * @param color_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_catalog_name(const std::string& list_name, const std::string& color_name);
        /**
     * @brief Calls `+[NSColor colorWithColorSpace:components:count:]`.
     * @details Create component-based colors with arbitrary colorspace. The colorspace should be component-based, and the number of components in the provided array should match the number dictated by the specified colorspace, plus one for alpha (supply 1.0 for opaque colors); otherwise an exception will be raised.
     * @param space Argument converted to the Objective-C parameter of the same role.
     * @param components Argument converted to the Objective-C parameter of the same role.
     * @param number_of_components Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_color_space(const ColorSpace& space, const double* components, std::int64_t number_of_components);
        /**
     * @brief Calls `+[NSColor colorWithColorSpace:hue:saturation:brightness:alpha:]`.
     * @details Create a RGB-based color using HSB component values. An exception will be raised if the color model of the provided color space is not RGB.
     * @param space Argument converted to the Objective-C parameter of the same role.
     * @param hue Argument converted to the Objective-C parameter of the same role.
     * @param saturation Argument converted to the Objective-C parameter of the same role.
     * @param brightness Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_color_space(const ColorSpace& space, double hue, double saturation, double brightness, double alpha);
        /**
     * @brief Calls `+[NSColor colorWithDeviceCyan:magenta:yellow:black:alpha:]`.
     * @param cyan Argument converted to the Objective-C parameter of the same role.
     * @param magenta Argument converted to the Objective-C parameter of the same role.
     * @param yellow Argument converted to the Objective-C parameter of the same role.
     * @param black Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_device_cyan(double cyan, double magenta, double yellow, double black, double alpha);
        /**
     * @brief Calls `+[NSColor colorWithDeviceHue:saturation:brightness:alpha:]`.
     * @param hue Argument converted to the Objective-C parameter of the same role.
     * @param saturation Argument converted to the Objective-C parameter of the same role.
     * @param brightness Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_device_hue(double hue, double saturation, double brightness, double alpha);
        /**
     * @brief Calls `+[NSColor colorWithDeviceRed:green:blue:alpha:]`.
     * @param red Argument converted to the Objective-C parameter of the same role.
     * @param green Argument converted to the Objective-C parameter of the same role.
     * @param blue Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_device_red(double red, double green, double blue, double alpha);
        /**
     * @brief Calls `+[NSColor colorWithDeviceWhite:alpha:]`.
     * @details Create component-based colors in various device color spaces.
     * @param white Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_device_white(double white, double alpha);
        /**
     * @brief Calls `+[NSColor colorWithDisplayP3Red:green:blue:alpha:]`.
     * @param red Argument converted to the Objective-C parameter of the same role.
     * @param green Argument converted to the Objective-C parameter of the same role.
     * @param blue Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_display_p3_red(double red, double green, double blue, double alpha);
        /**
     * @brief Calls `+[NSColor colorWithGenericGamma22White:alpha:]`.
     * @param white Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_generic_gamma22_white(double white, double alpha);
        /**
     * @brief Calls `+[NSColor colorWithHue:saturation:brightness:alpha:]`.
     * @param hue Argument converted to the Objective-C parameter of the same role.
     * @param saturation Argument converted to the Objective-C parameter of the same role.
     * @param brightness Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_hue(double hue, double saturation, double brightness, double alpha);
        /**
     * @brief Calls `+[NSColor colorWithName:dynamicProvider:]`.
     * @details Create a dynamic catalog color with a provider that is used to lazily resolve the exact color value. When methods are called on this color that need color component values, the provider is called with +NSAppearance.currentAppearance. The provider can use the appearance to return another color to be used for drawing. As much as possible, use the given appearance to make that decision, not other state. The 'colorName' should be universally unique and equates to the identity of the color, if nil is provided a unique name will be generated. The name and the Aqua appearance color fallback will be encoded as part of the color. The decoded color is also able to 'join' to a color that gets registered with the same name and become dynamic again.
     * @param color_name Argument converted to the Objective-C parameter of the same role.
     * @param dynamic_provider Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_name(const std::string& color_name, std::function<Color(Appearance)> dynamic_provider);
        /**
     * @brief Calls `+[NSColor colorWithPatternImage:]`.
     * @details Create pattern colors that paint with the specified image.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_pattern_image(const Image& image);
        /**
     * @brief Calls `+[NSColor colorWithRed:green:blue:alpha:]`.
     * @param red Argument converted to the Objective-C parameter of the same role.
     * @param green Argument converted to the Objective-C parameter of the same role.
     * @param blue Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_red(double red, double green, double blue, double alpha);
        /**
     * @brief Calls `+[NSColor colorWithRed:green:blue:alpha:exposure:]`.
     * @details Generates an HDR color in the extended sRGB colorspace by applying an exposure to the SDR color defined by the red, green, and blue components. The 'red', 'green', and 'blue' components have a nominal range of [0..1], 'exposure' is a value >= 0. To produce an HDR color, we process the given color in a linear color space, multiplying component values by '2^exposure'. The produced color will have a 'contentHeadroom' equal to the linearized exposure value. Each whole value of exposure produces a color that is twice as bright.
     * @param red Argument converted to the Objective-C parameter of the same role.
     * @param green Argument converted to the Objective-C parameter of the same role.
     * @param blue Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @param exposure Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_red(double red, double green, double blue, double alpha, double exposure);
        /**
     * @brief Calls `+[NSColor colorWithSRGBRed:green:blue:alpha:]`.
     * @details Create component-based colors in the sRGB, GenericGamma22Gray, or P3 colorspaces.
     * @param red Argument converted to the Objective-C parameter of the same role.
     * @param green Argument converted to the Objective-C parameter of the same role.
     * @param blue Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_srgb_red(double red, double green, double blue, double alpha);
        /**
     * @brief Calls `-[NSColor colorWithSystemEffect:]`.
     * @details Returns a color representing the base color with a system defined effect applied to it. This color is safe to create before draw time, as the resolution of the final color only happens when being '-set', retrieving its 'CGColor', resolving with '-colorWithType:', etc. The return color type is '.named'.
     * @param system_effect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Color color_with_system_effect(ColorSystemEffect system_effect) const;
        /**
     * @brief Calls `+[NSColor colorWithWhite:alpha:]`.
     * @details Create component-based colors that are compatible with sRGB colorspace; these methods are effectively same as colorWithSRGBRed:... or colorWithGenericGamma22White:..., but provided for easier reuse of code that uses UIColor on iOS. If red, green, blue, or saturation, brightness, or white values are outside of the 0..1 range, these will create colors in the extended sRGB (or for colorWithWhite:alpha:, extendedGenericGamma22GrayColorSpace) color spaces. This behavior is compatible with iOS UIColor.
     * @param white Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Color color_with_white(double white, double alpha);
        /**
     * @brief Calls `-[NSColor drawSwatchInRect:]`.
     * @details Draws the color and adorns it to indicate the type of color. Used by colorwells, swatches, and other UI objects that need to display colors. Implementation in NSColor simply draws the color (with an indication of transparency if the color isn't fully opaque); subclassers can draw more stuff as they see fit.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        void draw_swatch_in_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSColor getComponents:]`.
     * @param components Argument converted to the Objective-C parameter of the same role.
     */
        void get_components(double* components) const;
        /**
     * @brief Calls `-[NSColor getCyan:magenta:yellow:black:alpha:]`.
     * @param cyan Argument converted to the Objective-C parameter of the same role.
     * @param magenta Argument converted to the Objective-C parameter of the same role.
     * @param yellow Argument converted to the Objective-C parameter of the same role.
     * @param black Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     */
        void get_cyan(double* cyan, double* magenta, double* yellow, double* black, double* alpha) const;
        /**
     * @brief Calls `-[NSColor getHue:saturation:brightness:alpha:]`.
     * @param hue Argument converted to the Objective-C parameter of the same role.
     * @param saturation Argument converted to the Objective-C parameter of the same role.
     * @param brightness Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     */
        void get_hue(double* hue, double* saturation, double* brightness, double* alpha) const;
        /**
     * @brief Calls `-[NSColor getRed:green:blue:alpha:]`.
     * @param red Argument converted to the Objective-C parameter of the same role.
     * @param green Argument converted to the Objective-C parameter of the same role.
     * @param blue Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     */
        void get_red(double* red, double* green, double* blue, double* alpha) const;
        /**
     * @brief Calls `-[NSColor getWhite:alpha:]`.
     * @param white Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     */
        void get_white(double* white, double* alpha) const;
        /**
     * @brief Calls `-[NSColor highlightWithLevel:]`.
     * @param val Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Color highlight_with_level(double val) const;
        /**
     * @brief Calls `-[NSColor set]`.
     * @details Set the color: Sets the fill and stroke colors in the current drawing context. If the color doesn't know about alpha, it's set to 1.0. Should be implemented by subclassers.
     */
        void set() const;
        /**
     * @brief Calls `-[NSColor setFill]`.
     * @details Set the fill or stroke colors individually. These should be implemented by subclassers.
     */
        void set_fill() const;
        /**
     * @brief Calls `-[NSColor setStroke]`.
     */
        void set_stroke() const;
        /**
     * @brief Calls `-[NSColor shadowWithLevel:]`.
     * @param val Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Color shadow_with_level(double val) const;
        /**
     * @brief Calls `-[NSColor writeToPasteboard:]`.
     * @param paste_board Argument converted to the Objective-C parameter of the same role.
     */
        void write_to_pasteboard(const Pasteboard& paste_board) const;
        /**
     * @brief Returns the `CGColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        CGColor cg_color() const;
        /**
     * @brief Returns the `alphaComponent` property of `NSColor`.
     * @details Get the alpha component. Valid on all colors; for colors which do not have alpha components, this will return 1.0 (opaque).
     * @return The converted Objective-C result.
     */
        double alpha_component() const;
        /**
     * @brief Returns the `alternateSelectedControlTextColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color alternate_selected_control_text_color();
        /**
     * @brief Returns the `alternatingContentBackgroundColors` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static std::vector<Color> alternating_content_background_colors();
        /**
     * @brief Returns the `blackColor` property of `NSColor`.
     * @details Some convenience methods to create standard colors, typically should not be used for display in user interface elements. Do not make any assumptions about the actual color spaces used: For applications built against the 10.13 SDK these return colors in the sRGB or genericGamma22GrayColorSpace color spaces, while in older apps they use calibrated color spaces.
     * @return The converted Objective-C result.
     */
        static Color black_color();
        /**
     * @brief Returns the `blackComponent` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        double black_component() const;
        /**
     * @brief Returns the `blueColor` property of `NSColor`.
     * @details \@property (class, strong, readonly) NSColor greenColor; / 0.0, 1.0, 0.0 RGB
     * @return The converted Objective-C result.
     */
        static Color blue_color();
        /**
     * @brief Returns the `blueComponent` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        double blue_component() const;
        /**
     * @brief Returns the `brightnessComponent` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        double brightness_component() const;
        /**
     * @brief Returns the `brownColor` property of `NSColor`.
     * @details \@property (class, strong, readonly) NSColor purpleColor; / 0.5, 0.0, 0.5 RGB
     * @return The converted Objective-C result.
     */
        static Color brown_color();
        /**
     * @brief Returns the `catalogNameComponent` property of `NSColor`.
     * @details Get the catalog and color name of standard colors from catalogs. Valid only on colors whose type is NSColorTypeCatalog. These colors are special colors which can have different device or appearance specific underlying colors.
     * @return The converted Objective-C result.
     */
        std::string catalog_name_component() const;
        /**
     * @brief Returns the `clearColor` property of `NSColor`.
     * @details \@property (class, strong, readonly) NSColor brownColor; / 0.6, 0.4, 0.2 RGB
     * @return The converted Objective-C result.
     */
        static Color clear_color();
        /**
     * @brief Returns the `colorNameComponent` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        std::string color_name_component() const;
        /**
     * @brief Returns the `colorSpace` property of `NSColor`.
     * @details In colors with type == NSColorTypeComponentBased, return the colorspace and individual floating point components, including alpha. Like other colorspace-specific methods these will raise exceptions on other color types.
     * @return The converted Objective-C result.
     */
        ColorSpace color_space() const;
        /**
     * @brief Returns the `controlAccentColor` property of `NSColor`.
     * @details A dynamic color that reflects the user's current preferred accent color. This color automatically updates when the accent color preference changes. Do not make assumptions about the color space of this color, which may change across releases.
     * @return The converted Objective-C result.
     */
        static Color control_accent_color();
        /**
     * @brief Returns the `controlBackgroundColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color control_background_color();
        /**
     * @brief Returns the `controlColor` property of `NSColor`.
     * @details Control Colors
     * @return The converted Objective-C result.
     */
        static Color control_color();
        /**
     * @brief Returns the `controlTextColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color control_text_color();
        /**
     * @brief Returns the `currentControlTint` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static ControlTint current_control_tint();
        /**
     * @brief Returns the `cyanColor` property of `NSColor`.
     * @details \@property (class, strong, readonly) NSColor blueColor; / 0.0, 0.0, 1.0 RGB
     * @return The converted Objective-C result.
     */
        static Color cyan_color();
        /**
     * @brief Returns the `cyanComponent` property of `NSColor`.
     * @details Get the CMYK components of NSDeviceCMYK colors, or NSCustomColorSpace colors with color spaces with CMYK model. Raise for other types of colors.
     * @return The converted Objective-C result.
     */
        double cyan_component() const;
        /**
     * @brief Returns the `darkGrayColor` property of `NSColor`.
     * @details \@property (class, strong, readonly) NSColor blackColor; / 0.0 white
     * @return The converted Objective-C result.
     */
        static Color dark_gray_color();
        /**
     * @brief Returns the `disabledControlTextColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color disabled_control_text_color();
        /**
     * @brief Returns the `findHighlightColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color find_highlight_color();
        /**
     * @brief Returns the `grayColor` property of `NSColor`.
     * @details \@property (class, strong, readonly) NSColor whiteColor; / 1.0 white
     * @return The converted Objective-C result.
     */
        static Color gray_color();
        /**
     * @brief Returns the `greenColor` property of `NSColor`.
     * @details \@property (class, strong, readonly) NSColor redColor; / 1.0, 0.0, 0.0 RGB
     * @return The converted Objective-C result.
     */
        static Color green_color();
        /**
     * @brief Returns the `greenComponent` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        double green_component() const;
        /**
     * @brief Returns the `gridColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color grid_color();
        /**
     * @brief Returns the `headerTextColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color header_text_color();
        /**
     * @brief Returns the `highlightColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color highlight_color();
        /**
     * @brief Returns the `hueComponent` property of `NSColor`.
     * @details Get the components of NSCalibratedRGB or NSDeviceRGB colors as hue, saturation, or brightness. Raise for other types of colors.
     * @return The converted Objective-C result.
     */
        double hue_component() const;
        /**
     * @brief Returns the `keyboardFocusIndicatorColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color keyboard_focus_indicator_color();
        /**
     * @brief Returns the `labelColor` property of `NSColor`.
     * @details Foreground Colors
     * @return The converted Objective-C result.
     */
        static Color label_color();
        /**
     * @brief Returns the `lightGrayColor` property of `NSColor`.
     * @details \@property (class, strong, readonly) NSColor darkGrayColor; / 0.333 white
     * @return The converted Objective-C result.
     */
        static Color light_gray_color();
        /**
     * @brief Returns the `linearExposure` property of `NSColor`.
     * @details For HDR colors, the linear brightness multiplier that was applied when generating the color. Colors created with an exposure by NSColor create CGColors that are tagged with a contentHeadroom value. While CGColors created without a contentHeadroom tag will return 0 from CGColorGetHeadroom, NSColors generated in a similar fashion return a linearExposure of 1.0.
     * @return The converted Objective-C result.
     */
        double linear_exposure() const;
        /**
     * @brief Returns the `linkColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color link_color();
        /**
     * @brief Returns the `localizedCatalogNameComponent` property of `NSColor`.
     * @details Return localized versions of the above.
     * @return The converted Objective-C result.
     */
        std::string localized_catalog_name_component() const;
        /**
     * @brief Returns the `localizedColorNameComponent` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        std::string localized_color_name_component() const;
        /**
     * @brief Returns the `magentaColor` property of `NSColor`.
     * @details \@property (class, strong, readonly) NSColor yellowColor; / 1.0, 1.0, 0.0 RGB
     * @return The converted Objective-C result.
     */
        static Color magenta_color();
        /**
     * @brief Returns the `magentaComponent` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        double magenta_component() const;
        /**
     * @brief Returns the `numberOfComponents` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_components() const;
        /**
     * @brief Returns the `orangeColor` property of `NSColor`.
     * @details \@property (class, strong, readonly) NSColor magentaColor; / 1.0, 0.0, 1.0 RGB
     * @return The converted Objective-C result.
     */
        static Color orange_color();
        /**
     * @brief Returns the `patternImage` property of `NSColor`.
     * @details Return the image used for the pattern color. Will raise exception for colors other than type == NSColorTypePattern.
     * @return The converted Objective-C result.
     */
        Image pattern_image() const;
        /**
     * @brief Returns the `placeholderTextColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color placeholder_text_color();
        /**
     * @brief Returns the `purpleColor` property of `NSColor`.
     * @details \@property (class, strong, readonly) NSColor orangeColor; / 1.0, 0.5, 0.0 RGB
     * @return The converted Objective-C result.
     */
        static Color purple_color();
        /**
     * @brief Returns the `quaternaryLabelColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color quaternary_label_color();
        /**
     * @brief Returns the `quaternarySystemFillColor` property of `NSColor`.
     * @details A color appropriate for filling large areas, such as a group box or tab pane.
     * @return The converted Objective-C result.
     */
        static Color quaternary_system_fill_color();
        /**
     * @brief Returns the `quinaryLabelColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color quinary_label_color();
        /**
     * @brief Returns the `quinarySystemFillColor` property of `NSColor`.
     * @details A color appropriate for filling large areas that require subtle emphasis, such as content of a form.
     * @return The converted Objective-C result.
     */
        static Color quinary_system_fill_color();
        /**
     * @brief Returns the `redColor` property of `NSColor`.
     * @details \@property (class, strong, readonly) NSColor grayColor; / 0.5 white
     * @return The converted Objective-C result.
     */
        static Color red_color();
        /**
     * @brief Returns the `redComponent` property of `NSColor`.
     * @details Get the red, green, or blue components of NSColorTypeComponentBased colors whose colorSpace model is RGB. Raise for other types of colors. To call these safely on unknown colors, you can use code like: NSColor sRGBColor = color.colorUsingColorSpace(NSColorSpace.sRGBColorSpace); CGFloat red = sRGBColor ? sRGBColor.redComponent : someFallBackValue;
     * @return The converted Objective-C result.
     */
        double red_component() const;
        /**
     * @brief Returns the `saturationComponent` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        double saturation_component() const;
        /**
     * @brief Returns the `scrubberTexturedBackgroundColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color scrubber_textured_background_color();
        /**
     * @brief Returns the `secondaryLabelColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color secondary_label_color();
        /**
     * @brief Returns the `secondarySystemFillColor` property of `NSColor`.
     * @details A color appropriate for filling small-size shapes, such as the backing of a progress indicator.
     * @return The converted Objective-C result.
     */
        static Color secondary_system_fill_color();
        /**
     * @brief Returns the `selectedContentBackgroundColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color selected_content_background_color();
        /**
     * @brief Returns the `selectedControlColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color selected_control_color();
        /**
     * @brief Returns the `selectedControlTextColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color selected_control_text_color();
        /**
     * @brief Returns the `selectedMenuItemTextColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color selected_menu_item_text_color();
        /**
     * @brief Returns the `selectedTextBackgroundColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color selected_text_background_color();
        /**
     * @brief Returns the `selectedTextColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color selected_text_color();
        /**
     * @brief Returns the `separatorColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color separator_color();
        /**
     * @brief Returns the `shadowColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color shadow_color();
        /**
     * @brief Returns the `standardDynamicRangeColor` property of `NSColor`.
     * @details In some cases it is useful to recover the color that was base the SDR color that was exposed to generate an HDR color. If a color's 'linearExposure' is > 1, then this will return the base SDR color. If the color is not an HDR color, this will return 'self'.
     * @return The converted Objective-C result.
     */
        Color standard_dynamic_range_color() const;
        /**
     * @brief Returns the `systemBlueColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color system_blue_color();
        /**
     * @brief Returns the `systemBrownColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color system_brown_color();
        /**
     * @brief Returns the `systemCyanColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color system_cyan_color();
        /**
     * @brief Returns the `systemFillColor` property of `NSColor`.
     * @details A color appropriate for filling thin shapes, such as the track of a slider.
     * @return The converted Objective-C result.
     */
        static Color system_fill_color();
        /**
     * @brief Returns the `systemGrayColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color system_gray_color();
        /**
     * @brief Returns the `systemGreenColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color system_green_color();
        /**
     * @brief Returns the `systemIndigoColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color system_indigo_color();
        /**
     * @brief Returns the `systemMintColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color system_mint_color();
        /**
     * @brief Returns the `systemOrangeColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color system_orange_color();
        /**
     * @brief Returns the `systemPinkColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color system_pink_color();
        /**
     * @brief Returns the `systemPurpleColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color system_purple_color();
        /**
     * @brief Returns the `systemRedColor` property of `NSColor`.
     * @details Some colors that are used by system elements and applications. Like the above dynamic system colors, these return named colors whose values may vary between different appearances and releases. Do not make assumptions about the color spaces or actual colors used.
     * @return The converted Objective-C result.
     */
        static Color system_red_color();
        /**
     * @brief Returns the `systemTealColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color system_teal_color();
        /**
     * @brief Returns the `systemYellowColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color system_yellow_color();
        /**
     * @brief Returns the `tertiaryLabelColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color tertiary_label_color();
        /**
     * @brief Returns the `tertiarySystemFillColor` property of `NSColor`.
     * @details A color appropriate for filling medium-size shapes, such as the backing of a switch.
     * @return The converted Objective-C result.
     */
        static Color tertiary_system_fill_color();
        /**
     * @brief Returns the `textBackgroundColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color text_background_color();
        /**
     * @brief Returns the `textColor` property of `NSColor`.
     * @details Text Colors
     * @return The converted Objective-C result.
     */
        static Color text_color();
        /**
     * @brief Returns the `textInsertionPointColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color text_insertion_point_color();
        /**
     * @brief Returns the `type` property of `NSColor`.
     * @details Return the type of the color, which in turn determines which accessors are valid for this color. It's an exception-raising error to use properties that are not valid for a color; so, before using a given accessor on a color, call colorUsingType: to convert the color to the appropriate type. Or, if wanting to use colorSpace-specific accessors such as redComponent, convert to the desired colorSpace with colorUsingColorSpace:. Note that as of macOS 10.13, the new APIs type and colorUsingType: replace colorSpaceName and colorUsingColorSpaceName: as the funnel APIs for determining the type of color. In code destined to run on 10.13 and newer systems, subclassers are encouraged to implement these two rather than the older colorSpaceName based methods.
     * @return The converted Objective-C result.
     */
        ColorType type() const;
        /**
     * @brief Returns the `underPageBackgroundColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color under_page_background_color();
        /**
     * @brief Returns the `unemphasizedSelectedContentBackgroundColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color unemphasized_selected_content_background_color();
        /**
     * @brief Returns the `unemphasizedSelectedTextBackgroundColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color unemphasized_selected_text_background_color();
        /**
     * @brief Returns the `unemphasizedSelectedTextColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color unemphasized_selected_text_color();
        /**
     * @brief Returns the `whiteColor` property of `NSColor`.
     * @details \@property (class, strong, readonly) NSColor lightGrayColor; / 0.667 white
     * @return The converted Objective-C result.
     */
        static Color white_color();
        /**
     * @brief Returns the `whiteComponent` property of `NSColor`.
     * @details Get the white component of NSCalibratedWhite or NSDeviceWhite colors, or NSCustomColorSpace colors with color spaces with grayscale model. Raise for other types of colors.
     * @return The converted Objective-C result.
     */
        double white_component() const;
        /**
     * @brief Returns the `windowBackgroundColor` property of `NSColor`.
     * @details Background Colors
     * @return The converted Objective-C result.
     */
        static Color window_background_color();
        /**
     * @brief Returns the `windowFrameTextColor` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        static Color window_frame_text_color();
        /**
     * @brief Returns the `yellowColor` property of `NSColor`.
     * @details \@property (class, strong, readonly) NSColor cyanColor; / 0.0, 1.0, 1.0 RGB
     * @return The converted Objective-C result.
     */
        static Color yellow_color();
        /**
     * @brief Returns the `yellowComponent` property of `NSColor`.
     * @return The converted Objective-C result.
     */
        double yellow_component() const;
    };
}
