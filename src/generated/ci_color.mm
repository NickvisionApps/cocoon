#include "generated/ci_color.h"
#include "internal.h"

namespace cocoon
{
    CIColor::CIColor(const CGColor& color) : CIColor(Adopt{cocoon::internal::retain([[::CIColor alloc] initWithCGColor:((::CGColorRef)(color).handle())])})
    {
    }

    CIColor::CIColor(const Color& color) : CIColor(Adopt{cocoon::internal::retain([[::CIColor alloc] initWithColor:cocoon::internal::native<::NSColor>(color)])})
    {
    }

    CIColor::CIColor(double red, double green, double blue) : CIColor(Adopt{cocoon::internal::retain([[::CIColor alloc] initWithRed:static_cast<::CGFloat>(red) green:static_cast<::CGFloat>(green) blue:static_cast<::CGFloat>(blue)])})
    {
    }

    CIColor::CIColor(double red, double green, double blue, double alpha) : CIColor(Adopt{cocoon::internal::retain([[::CIColor alloc] initWithRed:static_cast<::CGFloat>(red) green:static_cast<::CGFloat>(green) blue:static_cast<::CGFloat>(blue) alpha:static_cast<::CGFloat>(alpha)])})
    {
    }

    CIColor::CIColor(double red, double green, double blue, double alpha, const CGColorSpace& color_space) : CIColor(Adopt{cocoon::internal::retain([[::CIColor alloc] initWithRed:static_cast<::CGFloat>(red) green:static_cast<::CGFloat>(green) blue:static_cast<::CGFloat>(blue) alpha:static_cast<::CGFloat>(alpha) colorSpace:((::CGColorSpaceRef)(color_space).handle())])})
    {
    }

    CIColor::CIColor(double red, double green, double blue, const CGColorSpace& color_space) : CIColor(Adopt{cocoon::internal::retain([[::CIColor alloc] initWithRed:static_cast<::CGFloat>(red) green:static_cast<::CGFloat>(green) blue:static_cast<::CGFloat>(blue) colorSpace:((::CGColorSpaceRef)(color_space).handle())])})
    {
    }

    CIColor::CIColor() : CIColor(Adopt{cocoon::internal::retain([[::CIColor alloc] init])})
    {
    }

    CIColor::CIColor(std::nullptr_t) : Object(nullptr)
    {
    }

    CIColor::CIColor(Adopt adopt) : Object(adopt)
    {
    }

    CIColor CIColor::color_with_cg_color(const CGColor& color)
    {
        return cocoon::internal::wrap<CIColor>([::CIColor colorWithCGColor:((::CGColorRef)(color).handle())]);
    }

    CIColor CIColor::color_with_red(double red, double green, double blue)
    {
        return cocoon::internal::wrap<CIColor>([::CIColor colorWithRed:static_cast<::CGFloat>(red) green:static_cast<::CGFloat>(green) blue:static_cast<::CGFloat>(blue)]);
    }

    CIColor CIColor::color_with_red(double red, double green, double blue, double alpha)
    {
        return cocoon::internal::wrap<CIColor>([::CIColor colorWithRed:static_cast<::CGFloat>(red) green:static_cast<::CGFloat>(green) blue:static_cast<::CGFloat>(blue) alpha:static_cast<::CGFloat>(alpha)]);
    }

    CIColor CIColor::color_with_red(double red, double green, double blue, double alpha, const CGColorSpace& color_space)
    {
        return cocoon::internal::wrap<CIColor>([::CIColor colorWithRed:static_cast<::CGFloat>(red) green:static_cast<::CGFloat>(green) blue:static_cast<::CGFloat>(blue) alpha:static_cast<::CGFloat>(alpha) colorSpace:((::CGColorSpaceRef)(color_space).handle())]);
    }

    CIColor CIColor::color_with_red(double red, double green, double blue, const CGColorSpace& color_space)
    {
        return cocoon::internal::wrap<CIColor>([::CIColor colorWithRed:static_cast<::CGFloat>(red) green:static_cast<::CGFloat>(green) blue:static_cast<::CGFloat>(blue) colorSpace:((::CGColorSpaceRef)(color_space).handle())]);
    }

    CIColor CIColor::color_with_string(const std::string& representation)
    {
        return cocoon::internal::wrap<CIColor>([::CIColor colorWithString:cocoon::internal::to(representation)]);
    }

    double CIColor::alpha() const
    {
        return static_cast<double>([cocoon::internal::ns<::CIColor>(this) alpha]);
    }

    CIColor CIColor::black_color()
    {
        return cocoon::internal::wrap<CIColor>([::CIColor blackColor]);
    }

    double CIColor::blue() const
    {
        return static_cast<double>([cocoon::internal::ns<::CIColor>(this) blue]);
    }

    CIColor CIColor::blue_color()
    {
        return cocoon::internal::wrap<CIColor>([::CIColor blueColor]);
    }

    CIColor CIColor::clear_color()
    {
        return cocoon::internal::wrap<CIColor>([::CIColor clearColor]);
    }

    const double* CIColor::components() const
    {
        return (const double*)([cocoon::internal::ns<::CIColor>(this) components]);
    }

    CIColor CIColor::cyan_color()
    {
        return cocoon::internal::wrap<CIColor>([::CIColor cyanColor]);
    }

    CIColor CIColor::gray_color()
    {
        return cocoon::internal::wrap<CIColor>([::CIColor grayColor]);
    }

    double CIColor::green() const
    {
        return static_cast<double>([cocoon::internal::ns<::CIColor>(this) green]);
    }

    CIColor CIColor::green_color()
    {
        return cocoon::internal::wrap<CIColor>([::CIColor greenColor]);
    }

    CIColor CIColor::magenta_color()
    {
        return cocoon::internal::wrap<CIColor>([::CIColor magentaColor]);
    }

    std::uint64_t CIColor::number_of_components() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::CIColor>(this) numberOfComponents]);
    }

    double CIColor::red() const
    {
        return static_cast<double>([cocoon::internal::ns<::CIColor>(this) red]);
    }

    CIColor CIColor::red_color()
    {
        return cocoon::internal::wrap<CIColor>([::CIColor redColor]);
    }

    std::string CIColor::string_representation() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CIColor>(this) stringRepresentation]);
    }

    CIColor CIColor::white_color()
    {
        return cocoon::internal::wrap<CIColor>([::CIColor whiteColor]);
    }

    CIColor CIColor::yellow_color()
    {
        return cocoon::internal::wrap<CIColor>([::CIColor yellowColor]);
    }
}
