#include "generated/color_space.h"
#include "internal.h"

namespace cocoon
{
    ColorSpace::ColorSpace(const CGColorSpace& cg_color_space) : ColorSpace(Adopt{cocoon::internal::retain([[::NSColorSpace alloc] initWithCGColorSpace:((::CGColorSpaceRef)(cg_color_space).handle())])})
    {
    }

    ColorSpace::ColorSpace(void* prof) : ColorSpace(Adopt{cocoon::internal::retain([[::NSColorSpace alloc] initWithColorSyncProfile:prof])})
    {
    }

    ColorSpace::ColorSpace(const std::vector<std::uint8_t>& icc_data) : ColorSpace(Adopt{cocoon::internal::retain([[::NSColorSpace alloc] initWithICCProfileData:cocoon::internal::to_data(icc_data)])})
    {
    }

    ColorSpace::ColorSpace() : ColorSpace(Adopt{cocoon::internal::retain([[::NSColorSpace alloc] init])})
    {
    }

    ColorSpace::ColorSpace(std::nullptr_t) : Object(nullptr)
    {
    }

    ColorSpace::ColorSpace(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<ColorSpace> ColorSpace::available_color_spaces_with_model(ColorSpaceModel model)
    {
        return cocoon::internal::from_array<ColorSpace>([::NSColorSpace availableColorSpacesWithModel:static_cast<::NSColorSpaceModel>(model)], [](id e) -> ColorSpace
                                          {
                                              return cocoon::internal::wrap<ColorSpace>((::NSColorSpace*)e);
                                          });
    }

    CGColorSpace ColorSpace::cg_color_space() const
    {
        return cocoon::internal::wrap_cf<CGColorSpace>((const void*)([cocoon::internal::ns<::NSColorSpace>(this) CGColorSpace]));
    }

    std::vector<std::uint8_t> ColorSpace::icc_profile_data() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSColorSpace>(this) ICCProfileData]);
    }

    ColorSpace ColorSpace::adobe_rgb1998_color_space()
    {
        return cocoon::internal::wrap<ColorSpace>([::NSColorSpace adobeRGB1998ColorSpace]);
    }

    ColorSpaceModel ColorSpace::color_space_model() const
    {
        return static_cast<ColorSpaceModel>([cocoon::internal::ns<::NSColorSpace>(this) colorSpaceModel]);
    }

    void* ColorSpace::color_sync_profile() const
    {
        return [cocoon::internal::ns<::NSColorSpace>(this) colorSyncProfile];
    }

    ColorSpace ColorSpace::device_cmyk_color_space()
    {
        return cocoon::internal::wrap<ColorSpace>([::NSColorSpace deviceCMYKColorSpace]);
    }

    ColorSpace ColorSpace::device_gray_color_space()
    {
        return cocoon::internal::wrap<ColorSpace>([::NSColorSpace deviceGrayColorSpace]);
    }

    ColorSpace ColorSpace::device_rgb_color_space()
    {
        return cocoon::internal::wrap<ColorSpace>([::NSColorSpace deviceRGBColorSpace]);
    }

    ColorSpace ColorSpace::display_p3_color_space()
    {
        return cocoon::internal::wrap<ColorSpace>([::NSColorSpace displayP3ColorSpace]);
    }

    ColorSpace ColorSpace::extended_generic_gamma22_gray_color_space()
    {
        return cocoon::internal::wrap<ColorSpace>([::NSColorSpace extendedGenericGamma22GrayColorSpace]);
    }

    ColorSpace ColorSpace::extended_srgb_color_space()
    {
        return cocoon::internal::wrap<ColorSpace>([::NSColorSpace extendedSRGBColorSpace]);
    }

    ColorSpace ColorSpace::generic_cmyk_color_space()
    {
        return cocoon::internal::wrap<ColorSpace>([::NSColorSpace genericCMYKColorSpace]);
    }

    ColorSpace ColorSpace::generic_gamma22_gray_color_space()
    {
        return cocoon::internal::wrap<ColorSpace>([::NSColorSpace genericGamma22GrayColorSpace]);
    }

    ColorSpace ColorSpace::generic_gray_color_space()
    {
        return cocoon::internal::wrap<ColorSpace>([::NSColorSpace genericGrayColorSpace]);
    }

    ColorSpace ColorSpace::generic_rgb_color_space()
    {
        return cocoon::internal::wrap<ColorSpace>([::NSColorSpace genericRGBColorSpace]);
    }

    std::string ColorSpace::localized_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSColorSpace>(this) localizedName]);
    }

    std::int64_t ColorSpace::number_of_color_components() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSColorSpace>(this) numberOfColorComponents]);
    }

    ColorSpace ColorSpace::s_rgb_color_space()
    {
        return cocoon::internal::wrap<ColorSpace>([::NSColorSpace sRGBColorSpace]);
    }
}
