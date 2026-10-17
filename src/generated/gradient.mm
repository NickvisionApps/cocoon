#include "generated/gradient.h"
#include "internal.h"

namespace cocoon
{
    Gradient::Gradient(const std::vector<Color>& color_array) : Gradient(Adopt{cocoon::internal::retain([[::NSGradient alloc] initWithColors:cocoon::internal::to_array(color_array, [](const Color& e) -> id
                                                                                                                                                                        {
                                                                                                                                                                            return cocoon::internal::native<::NSColor>(e);
                                                                                                                                                                        })])})
    {
    }

    Gradient::Gradient(const std::vector<Color>& color_array, const double* locations, const ColorSpace& color_space) : Gradient(Adopt{cocoon::internal::retain([[::NSGradient alloc] initWithColors:cocoon::internal::to_array(color_array, [](const Color& e) -> id
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                    return cocoon::internal::native<::NSColor>(e);
                                                                                                                                                                                                                                })
                                                                                                                                                                                         atLocations:(const ::CGFloat*)(locations)colorSpace:cocoon::internal::native<::NSColorSpace>(color_space)])})
    {
    }

    Gradient::Gradient(const Color& starting_color, const Color& ending_color) : Gradient(Adopt{cocoon::internal::retain([[::NSGradient alloc] initWithStartingColor:cocoon::internal::native<::NSColor>(starting_color) endingColor:cocoon::internal::native<::NSColor>(ending_color)])})
    {
    }

    Gradient::Gradient() : Gradient(Adopt{cocoon::internal::retain([[::NSGradient alloc] init])})
    {
    }

    Gradient::Gradient(std::nullptr_t) : Object(nullptr)
    {
    }

    Gradient::Gradient(Adopt adopt) : Object(adopt)
    {
    }

    void Gradient::draw_from_center(const Point& start_center, double start_radius, const Point& end_center, double end_radius, GradientDrawingOptions options) const
    {
        [cocoon::internal::ns<::NSGradient>(this) drawFromCenter:cocoon::internal::to(start_center) radius:static_cast<::CGFloat>(start_radius) toCenter:cocoon::internal::to(end_center) radius:static_cast<::CGFloat>(end_radius) options:static_cast<::NSGradientDrawingOptions>(options)];
    }

    void Gradient::draw_from_point(const Point& starting_point, const Point& ending_point, GradientDrawingOptions options) const
    {
        [cocoon::internal::ns<::NSGradient>(this) drawFromPoint:cocoon::internal::to(starting_point) toPoint:cocoon::internal::to(ending_point) options:static_cast<::NSGradientDrawingOptions>(options)];
    }

    void Gradient::draw_in_bezier_path(const BezierPath& path, double angle) const
    {
        [cocoon::internal::ns<::NSGradient>(this) drawInBezierPath:cocoon::internal::native<::NSBezierPath>(path) angle:static_cast<::CGFloat>(angle)];
    }

    void Gradient::draw_in_bezier_path(const BezierPath& path, const Point& relative_center_position) const
    {
        [cocoon::internal::ns<::NSGradient>(this) drawInBezierPath:cocoon::internal::native<::NSBezierPath>(path) relativeCenterPosition:cocoon::internal::to(relative_center_position)];
    }

    void Gradient::draw_in_rect(const Rect& rect, double angle) const
    {
        [cocoon::internal::ns<::NSGradient>(this) drawInRect:cocoon::internal::to(rect) angle:static_cast<::CGFloat>(angle)];
    }

    void Gradient::draw_in_rect(const Rect& rect, const Point& relative_center_position) const
    {
        [cocoon::internal::ns<::NSGradient>(this) drawInRect:cocoon::internal::to(rect) relativeCenterPosition:cocoon::internal::to(relative_center_position)];
    }

    void Gradient::get_color(Color& color, double* location, std::int64_t index) const
    {
        ::NSColor* __v_color = nil;
        [cocoon::internal::ns<::NSGradient>(this) getColor:&__v_color location:(::CGFloat*)(location)atIndex:static_cast<::NSInteger>(index)];
        color = cocoon::internal::wrap<Color>(__v_color);
    }

    Color Gradient::interpolated_color_at_location(double location) const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSGradient>(this) interpolatedColorAtLocation:static_cast<::CGFloat>(location)]);
    }

    ColorSpace Gradient::color_space() const
    {
        return cocoon::internal::wrap<ColorSpace>([cocoon::internal::ns<::NSGradient>(this) colorSpace]);
    }

    std::int64_t Gradient::number_of_color_stops() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSGradient>(this) numberOfColorStops]);
    }
}
