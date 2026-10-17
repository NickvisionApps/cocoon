#include "generated/image_symbol_configuration.h"
#include "internal.h"

namespace cocoon
{
    ImageSymbolConfiguration::ImageSymbolConfiguration() : ImageSymbolConfiguration(Adopt{cocoon::internal::retain([[::NSImageSymbolConfiguration alloc] init])})
    {
    }

    ImageSymbolConfiguration::ImageSymbolConfiguration(std::nullptr_t) : Object(nullptr)
    {
    }

    ImageSymbolConfiguration::ImageSymbolConfiguration(Adopt adopt) : Object(adopt)
    {
    }

    ImageSymbolConfiguration ImageSymbolConfiguration::configuration_by_applying_configuration(const ImageSymbolConfiguration& configuration) const
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([cocoon::internal::ns<::NSImageSymbolConfiguration>(this) configurationByApplyingConfiguration:cocoon::internal::native<::NSImageSymbolConfiguration>(configuration)]);
    }

    ImageSymbolConfiguration ImageSymbolConfiguration::configuration_preferring_hierarchical()
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([::NSImageSymbolConfiguration configurationPreferringHierarchical]);
    }

    ImageSymbolConfiguration ImageSymbolConfiguration::configuration_preferring_monochrome()
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([::NSImageSymbolConfiguration configurationPreferringMonochrome]);
    }

    ImageSymbolConfiguration ImageSymbolConfiguration::configuration_preferring_multicolor()
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([::NSImageSymbolConfiguration configurationPreferringMulticolor]);
    }

    ImageSymbolConfiguration ImageSymbolConfiguration::configuration_with_color_rendering_mode(ImageSymbolColorRenderingMode mode)
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([::NSImageSymbolConfiguration configurationWithColorRenderingMode:static_cast<::NSImageSymbolColorRenderingMode>(mode)]);
    }

    ImageSymbolConfiguration ImageSymbolConfiguration::configuration_with_hierarchical_color(const Color& hierarchical_color)
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([::NSImageSymbolConfiguration configurationWithHierarchicalColor:cocoon::internal::native<::NSColor>(hierarchical_color)]);
    }

    ImageSymbolConfiguration ImageSymbolConfiguration::configuration_with_palette_colors(const std::vector<Color>& palette_colors)
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([::NSImageSymbolConfiguration configurationWithPaletteColors:cocoon::internal::to_array(palette_colors, [](const Color& e) -> id
                                                                                                                                                        {
                                                                                                                                                            return cocoon::internal::native<::NSColor>(e);
                                                                                                                                                        })]);
    }

    ImageSymbolConfiguration ImageSymbolConfiguration::configuration_with_point_size(double point_size, double weight)
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([::NSImageSymbolConfiguration configurationWithPointSize:static_cast<::CGFloat>(point_size) weight:static_cast<::NSFontWeight>(weight)]);
    }

    ImageSymbolConfiguration ImageSymbolConfiguration::configuration_with_point_size(double point_size, double weight, ImageSymbolScale scale)
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([::NSImageSymbolConfiguration configurationWithPointSize:static_cast<::CGFloat>(point_size) weight:static_cast<::NSFontWeight>(weight) scale:static_cast<::NSImageSymbolScale>(scale)]);
    }

    ImageSymbolConfiguration ImageSymbolConfiguration::configuration_with_scale(ImageSymbolScale scale)
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([::NSImageSymbolConfiguration configurationWithScale:static_cast<::NSImageSymbolScale>(scale)]);
    }

    ImageSymbolConfiguration ImageSymbolConfiguration::configuration_with_text_style(const std::string& style)
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([::NSImageSymbolConfiguration configurationWithTextStyle:cocoon::internal::to(style)]);
    }

    ImageSymbolConfiguration ImageSymbolConfiguration::configuration_with_text_style(const std::string& style, ImageSymbolScale scale)
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([::NSImageSymbolConfiguration configurationWithTextStyle:cocoon::internal::to(style) scale:static_cast<::NSImageSymbolScale>(scale)]);
    }

    ImageSymbolConfiguration ImageSymbolConfiguration::configuration_with_variable_value_mode(ImageSymbolVariableValueMode variable_value_mode)
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([::NSImageSymbolConfiguration configurationWithVariableValueMode:static_cast<::NSImageSymbolVariableValueMode>(variable_value_mode)]);
    }
}
