#include "generated/bezier_path.h"
#include "internal.h"

namespace cocoon
{
    BezierPath::BezierPath() : BezierPath(Adopt{cocoon::internal::retain([::NSBezierPath bezierPath])})
    {
    }

    BezierPath::BezierPath(const CGPath& cg_path) : BezierPath(Adopt{cocoon::internal::retain([::NSBezierPath bezierPathWithCGPath:((::CGPathRef)(cg_path).handle())])})
    {
    }

    BezierPath::BezierPath(const Rect& rect) : BezierPath(Adopt{cocoon::internal::retain([::NSBezierPath bezierPathWithOvalInRect:cocoon::internal::to(rect)])})
    {
    }

    BezierPath::BezierPath(const Rect& rect, double x_radius, double y_radius) : BezierPath(Adopt{cocoon::internal::retain([::NSBezierPath bezierPathWithRoundedRect:cocoon::internal::to(rect) xRadius:static_cast<::CGFloat>(x_radius) yRadius:static_cast<::CGFloat>(y_radius)])})
    {
    }

    BezierPath::BezierPath(std::nullptr_t) : Object(nullptr)
    {
    }

    BezierPath::BezierPath(Adopt adopt) : Object(adopt)
    {
    }

    void BezierPath::add_clip() const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) addClip];
    }

    void BezierPath::append_bezier_path(const BezierPath& path) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) appendBezierPath:cocoon::internal::native<::NSBezierPath>(path)];
    }

    void BezierPath::append_bezier_path_with_arc_from_point(const Point& point1, const Point& point2, double radius) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) appendBezierPathWithArcFromPoint:cocoon::internal::to(point1) toPoint:cocoon::internal::to(point2) radius:static_cast<::CGFloat>(radius)];
    }

    void BezierPath::append_bezier_path_with_arc_with_center(const Point& center, double radius, double start_angle, double end_angle) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) appendBezierPathWithArcWithCenter:cocoon::internal::to(center) radius:static_cast<::CGFloat>(radius) startAngle:static_cast<::CGFloat>(start_angle) endAngle:static_cast<::CGFloat>(end_angle)];
    }

    void BezierPath::append_bezier_path_with_arc_with_center(const Point& center, double radius, double start_angle, double end_angle, bool clockwise) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) appendBezierPathWithArcWithCenter:cocoon::internal::to(center) radius:static_cast<::CGFloat>(radius) startAngle:static_cast<::CGFloat>(start_angle) endAngle:static_cast<::CGFloat>(end_angle) clockwise:static_cast<::BOOL>(clockwise)];
    }

    void BezierPath::append_bezier_path_with_cg_glyph(std::uint16_t glyph, const Font& font) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) appendBezierPathWithCGGlyph:static_cast<::CGGlyph>(glyph) inFont:cocoon::internal::native<::NSFont>(font)];
    }

    void BezierPath::append_bezier_path_with_cg_glyphs(const std::uint16_t* glyphs, std::int64_t count, const Font& font) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) appendBezierPathWithCGGlyphs:(const ::CGGlyph*)(glyphs) count:static_cast<::NSInteger>(count) inFont:cocoon::internal::native<::NSFont>(font)];
    }

    void BezierPath::append_bezier_path_with_oval_in_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) appendBezierPathWithOvalInRect:cocoon::internal::to(rect)];
    }

    void BezierPath::append_bezier_path_with_points(Point* points, std::int64_t count) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) appendBezierPathWithPoints:(::NSPointArray)(points) count:static_cast<::NSInteger>(count)];
    }

    void BezierPath::append_bezier_path_with_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) appendBezierPathWithRect:cocoon::internal::to(rect)];
    }

    void BezierPath::append_bezier_path_with_rounded_rect(const Rect& rect, double x_radius, double y_radius) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) appendBezierPathWithRoundedRect:cocoon::internal::to(rect) xRadius:static_cast<::CGFloat>(x_radius) yRadius:static_cast<::CGFloat>(y_radius)];
    }

    void BezierPath::clip_rect(const Rect& rect)
    {
        [::NSBezierPath clipRect:cocoon::internal::to(rect)];
    }

    void BezierPath::close_path() const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) closePath];
    }

    bool BezierPath::contains_point(const Point& point) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBezierPath>(this) containsPoint:cocoon::internal::to(point)]);
    }

    void BezierPath::curve_to_point(const Point& end_point, const Point& control_point1, const Point& control_point2) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) curveToPoint:cocoon::internal::to(end_point) controlPoint1:cocoon::internal::to(control_point1) controlPoint2:cocoon::internal::to(control_point2)];
    }

    void BezierPath::curve_to_point(const Point& end_point, const Point& control_point) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) curveToPoint:cocoon::internal::to(end_point) controlPoint:cocoon::internal::to(control_point)];
    }

    void BezierPath::draw_packed_glyphs(const std::string& packed_glyphs, const Point& point)
    {
        [::NSBezierPath drawPackedGlyphs:packed_glyphs.c_str() atPoint:cocoon::internal::to(point)];
    }

    BezierPathElement BezierPath::element_at_index(std::int64_t index) const
    {
        return static_cast<BezierPathElement>([cocoon::internal::ns<::NSBezierPath>(this) elementAtIndex:static_cast<::NSInteger>(index)]);
    }

    BezierPathElement BezierPath::element_at_index(std::int64_t index, Point* points) const
    {
        return static_cast<BezierPathElement>([cocoon::internal::ns<::NSBezierPath>(this) elementAtIndex:static_cast<::NSInteger>(index) associatedPoints:(::NSPointArray)(points)]);
    }

    void BezierPath::fill() const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) fill];
    }

    void BezierPath::fill_rect(const Rect& rect)
    {
        [::NSBezierPath fillRect:cocoon::internal::to(rect)];
    }

    void BezierPath::get_line_dash(double* pattern, std::int64_t* count, double* phase) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) getLineDash:(::CGFloat*)(pattern) count:(::NSInteger*)(count)phase:(::CGFloat*)(phase)];
    }

    void BezierPath::line_to_point(const Point& point) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) lineToPoint:cocoon::internal::to(point)];
    }

    void BezierPath::move_to_point(const Point& point) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) moveToPoint:cocoon::internal::to(point)];
    }

    void BezierPath::relative_curve_to_point(const Point& end_point, const Point& control_point1, const Point& control_point2) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) relativeCurveToPoint:cocoon::internal::to(end_point) controlPoint1:cocoon::internal::to(control_point1) controlPoint2:cocoon::internal::to(control_point2)];
    }

    void BezierPath::relative_curve_to_point(const Point& end_point, const Point& control_point) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) relativeCurveToPoint:cocoon::internal::to(end_point) controlPoint:cocoon::internal::to(control_point)];
    }

    void BezierPath::relative_line_to_point(const Point& point) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) relativeLineToPoint:cocoon::internal::to(point)];
    }

    void BezierPath::relative_move_to_point(const Point& point) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) relativeMoveToPoint:cocoon::internal::to(point)];
    }

    void BezierPath::remove_all_points() const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) removeAllPoints];
    }

    void BezierPath::set_associated_points(Point* points, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) setAssociatedPoints:(::NSPointArray)(points) atIndex:static_cast<::NSInteger>(index)];
    }

    void BezierPath::set_clip() const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) setClip];
    }

    void BezierPath::set_line_dash(const double* pattern, std::int64_t count, double phase) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) setLineDash:(const ::CGFloat*)(pattern) count:static_cast<::NSInteger>(count) phase:static_cast<::CGFloat>(phase)];
    }

    void BezierPath::stroke() const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) stroke];
    }

    void BezierPath::stroke_line_from_point(const Point& point1, const Point& point2)
    {
        [::NSBezierPath strokeLineFromPoint:cocoon::internal::to(point1) toPoint:cocoon::internal::to(point2)];
    }

    void BezierPath::stroke_rect(const Rect& rect)
    {
        [::NSBezierPath strokeRect:cocoon::internal::to(rect)];
    }

    void BezierPath::transform_using_affine_transform(const AffineTransform& transform) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) transformUsingAffineTransform:cocoon::internal::native<::NSAffineTransform>(transform)];
    }

    CGPath BezierPath::cg_path() const
    {
        return cocoon::internal::wrap_cf<CGPath>((const void*)([cocoon::internal::ns<::NSBezierPath>(this) CGPath]));
    }

    void BezierPath::set_cg_path(const CGPath& value) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) setCGPath:((::CGPathRef)(value).handle())];
    }

    BezierPath BezierPath::bezier_path_by_flattening_path() const
    {
        return cocoon::internal::wrap<BezierPath>([cocoon::internal::ns<::NSBezierPath>(this) bezierPathByFlatteningPath]);
    }

    BezierPath BezierPath::bezier_path_by_reversing_path() const
    {
        return cocoon::internal::wrap<BezierPath>([cocoon::internal::ns<::NSBezierPath>(this) bezierPathByReversingPath]);
    }

    Rect BezierPath::bounds() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBezierPath>(this) bounds]);
    }

    Rect BezierPath::control_point_bounds() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBezierPath>(this) controlPointBounds]);
    }

    Point BezierPath::current_point() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBezierPath>(this) currentPoint]);
    }

    double BezierPath::default_flatness()
    {
        return static_cast<double>([::NSBezierPath defaultFlatness]);
    }

    void BezierPath::set_default_flatness(double value)
    {
        [::NSBezierPath setDefaultFlatness:static_cast<::CGFloat>(value)];
    }

    LineCapStyle BezierPath::default_line_cap_style()
    {
        return static_cast<LineCapStyle>([::NSBezierPath defaultLineCapStyle]);
    }

    void BezierPath::set_default_line_cap_style(LineCapStyle value)
    {
        [::NSBezierPath setDefaultLineCapStyle:static_cast<::NSLineCapStyle>(value)];
    }

    LineJoinStyle BezierPath::default_line_join_style()
    {
        return static_cast<LineJoinStyle>([::NSBezierPath defaultLineJoinStyle]);
    }

    void BezierPath::set_default_line_join_style(LineJoinStyle value)
    {
        [::NSBezierPath setDefaultLineJoinStyle:static_cast<::NSLineJoinStyle>(value)];
    }

    double BezierPath::default_line_width()
    {
        return static_cast<double>([::NSBezierPath defaultLineWidth]);
    }

    void BezierPath::set_default_line_width(double value)
    {
        [::NSBezierPath setDefaultLineWidth:static_cast<::CGFloat>(value)];
    }

    double BezierPath::default_miter_limit()
    {
        return static_cast<double>([::NSBezierPath defaultMiterLimit]);
    }

    void BezierPath::set_default_miter_limit(double value)
    {
        [::NSBezierPath setDefaultMiterLimit:static_cast<::CGFloat>(value)];
    }

    WindingRule BezierPath::default_winding_rule()
    {
        return static_cast<WindingRule>([::NSBezierPath defaultWindingRule]);
    }

    void BezierPath::set_default_winding_rule(WindingRule value)
    {
        [::NSBezierPath setDefaultWindingRule:static_cast<::NSWindingRule>(value)];
    }

    std::int64_t BezierPath::element_count() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBezierPath>(this) elementCount]);
    }

    bool BezierPath::is_empty() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBezierPath>(this) isEmpty]);
    }

    double BezierPath::flatness() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSBezierPath>(this) flatness]);
    }

    void BezierPath::set_flatness(double value) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) setFlatness:static_cast<::CGFloat>(value)];
    }

    LineCapStyle BezierPath::line_cap_style() const
    {
        return static_cast<LineCapStyle>([cocoon::internal::ns<::NSBezierPath>(this) lineCapStyle]);
    }

    void BezierPath::set_line_cap_style(LineCapStyle value) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) setLineCapStyle:static_cast<::NSLineCapStyle>(value)];
    }

    LineJoinStyle BezierPath::line_join_style() const
    {
        return static_cast<LineJoinStyle>([cocoon::internal::ns<::NSBezierPath>(this) lineJoinStyle]);
    }

    void BezierPath::set_line_join_style(LineJoinStyle value) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) setLineJoinStyle:static_cast<::NSLineJoinStyle>(value)];
    }

    double BezierPath::line_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSBezierPath>(this) lineWidth]);
    }

    void BezierPath::set_line_width(double value) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) setLineWidth:static_cast<::CGFloat>(value)];
    }

    double BezierPath::miter_limit() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSBezierPath>(this) miterLimit]);
    }

    void BezierPath::set_miter_limit(double value) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) setMiterLimit:static_cast<::CGFloat>(value)];
    }

    WindingRule BezierPath::winding_rule() const
    {
        return static_cast<WindingRule>([cocoon::internal::ns<::NSBezierPath>(this) windingRule]);
    }

    void BezierPath::set_winding_rule(WindingRule value) const
    {
        [cocoon::internal::ns<::NSBezierPath>(this) setWindingRule:static_cast<::NSWindingRule>(value)];
    }
}
