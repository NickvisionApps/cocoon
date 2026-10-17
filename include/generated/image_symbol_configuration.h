#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Color;

    /**
     * @brief C++ handle for the Objective-C class `NSImageSymbolConfiguration` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ImageSymbolConfiguration image_symbol_configuration;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ImageSymbolConfiguration image_symbol_configuration{};
     * auto made_0 = cocoon::ImageSymbolConfiguration::configuration_preferring_hierarchical();
     * auto made_1 = cocoon::ImageSymbolConfiguration::configuration_preferring_monochrome();
     * image_symbol_configuration.configuration_by_applying_configuration(cocoon::ImageSymbolConfiguration());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsimagesymbolconfiguration
     */
    class ImageSymbolConfiguration : public Object
    {
    public:
        /// @brief Creates a new `NSImageSymbolConfiguration` instance and returns a handle to it.
        explicit ImageSymbolConfiguration();
        /// @brief Creates a null handle that refers to no native object.
        ImageSymbolConfiguration(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ImageSymbolConfiguration(Adopt adopt);
        /**
     * @brief Calls `-[NSImageSymbolConfiguration configurationByApplyingConfiguration:]`.
     * @details Returns a new configuration object whose values are defined by applying values from the provided configuration and the receiver. Values defined by both configurations will use the provided configuration’s values.
     * @param configuration Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ImageSymbolConfiguration configuration_by_applying_configuration(const ImageSymbolConfiguration& configuration) const;
        /**
     * @brief Calls `+[NSImageSymbolConfiguration configurationPreferringHierarchical]`.
     * @details Creates a configuration that specifies that the symbol should prefer its hierarchical variant, if one exists. If the symbol doesn’t support hierarchical, the result will be a monochrome (templated) symbol.
     * @return The converted Objective-C result.
     */
        static ImageSymbolConfiguration configuration_preferring_hierarchical();
        /**
     * @brief Calls `+[NSImageSymbolConfiguration configurationPreferringMonochrome]`.
     * @details Creates a configuration that specifies that the symbol should prefer its monochrome variant.
     * @return The converted Objective-C result.
     */
        static ImageSymbolConfiguration configuration_preferring_monochrome();
        /**
     * @brief Calls `+[NSImageSymbolConfiguration configurationPreferringMulticolor]`.
     * @details Create a configuration that specifies that the symbol should prefer its multicolor variant, if one exists. This configuration can be combined with one of the palette-based configurations; in that case, the symbol will use the multicolor variant if one exists, or the palette variant otherwise. If the symbol supports neither, the result will be a monochrome (templated) symbol.
     * @return The converted Objective-C result.
     */
        static ImageSymbolConfiguration configuration_preferring_multicolor();
        /**
     * @brief Calls `+[NSImageSymbolConfiguration configurationWithColorRenderingMode:]`.
     * @details Create a configuration with a specific color rendering mode.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ImageSymbolConfiguration configuration_with_color_rendering_mode(ImageSymbolColorRenderingMode mode);
        /**
     * @brief Calls `+[NSImageSymbolConfiguration configurationWithHierarchicalColor:]`.
     * @details Create a color configuration with a palette derived from one color. A color scheme will be created based on the provided color, deriving secondary and tertiary colors by reducing the intensity of the base color. This is typically (but not only) accomplished by reducing opacity of the primary color. When combined with another configuration creating a palette, the last specified configuration will win, overwriting the other color configuration. If the symbol doesn’t have a palette-based variant, the configuration will have no effect and the result will be a monochrome (templated) symbol.
     * @param hierarchical_color Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ImageSymbolConfiguration configuration_with_hierarchical_color(const Color& hierarchical_color);
        /**
     * @brief Calls `+[NSImageSymbolConfiguration configurationWithPaletteColors:]`.
     * @details Create a color configuration by specifying a palette of colors. The colors are used sequentially per layer: the first color for the first layer, the second color for the second layer etc. This is independent of the hierarchy level of the layer. When combined with another configuration creating a palette, the last specified configuration will win, overwriting the other color configuration. If the symbol doesn’t have a palette-based variant, the configuration will have no effect and the result will be a monochrome (templated) symbol.
     * @param palette_colors Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ImageSymbolConfiguration configuration_with_palette_colors(const std::vector<Color>& palette_colors);
        /**
     * @brief Calls `+[NSImageSymbolConfiguration configurationWithPointSize:weight:]`.
     * @param point_size Argument converted to the Objective-C parameter of the same role.
     * @param weight Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ImageSymbolConfiguration configuration_with_point_size(double point_size, double weight);
        /**
     * @brief Calls `+[NSImageSymbolConfiguration configurationWithPointSize:weight:scale:]`.
     * @param point_size Argument converted to the Objective-C parameter of the same role.
     * @param weight Argument converted to the Objective-C parameter of the same role.
     * @param scale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ImageSymbolConfiguration configuration_with_point_size(double point_size, double weight, ImageSymbolScale scale);
        /**
     * @brief Calls `+[NSImageSymbolConfiguration configurationWithScale:]`.
     * @param scale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ImageSymbolConfiguration configuration_with_scale(ImageSymbolScale scale);
        /**
     * @brief Calls `+[NSImageSymbolConfiguration configurationWithTextStyle:]`.
     * @param style Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ImageSymbolConfiguration configuration_with_text_style(const std::string& style);
        /**
     * @brief Calls `+[NSImageSymbolConfiguration configurationWithTextStyle:scale:]`.
     * @param style Argument converted to the Objective-C parameter of the same role.
     * @param scale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ImageSymbolConfiguration configuration_with_text_style(const std::string& style, ImageSymbolScale scale);
        /**
     * @brief Calls `+[NSImageSymbolConfiguration configurationWithVariableValueMode:]`.
     * @details Create a configuration with a specified variable value mode.
     * @param variable_value_mode Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ImageSymbolConfiguration configuration_with_variable_value_mode(ImageSymbolVariableValueMode variable_value_mode);
    };
}
