#include "generated/affine_transform.h"
#include "internal.h"

namespace cocoon
{
    AffineTransform::AffineTransform() : AffineTransform(Adopt{cocoon::internal::retain([[::NSAffineTransform alloc] init])})
    {
    }

    AffineTransform::AffineTransform(std::nullptr_t) : Object(nullptr)
    {
    }

    AffineTransform::AffineTransform(Adopt adopt) : Object(adopt)
    {
    }

    void AffineTransform::append_transform(const AffineTransform& transform) const
    {
        [cocoon::internal::ns<::NSAffineTransform>(this) appendTransform:cocoon::internal::native<::NSAffineTransform>(transform)];
    }

    void AffineTransform::concat() const
    {
        [cocoon::internal::ns<::NSAffineTransform>(this) concat];
    }

    void AffineTransform::invert() const
    {
        [cocoon::internal::ns<::NSAffineTransform>(this) invert];
    }

    void AffineTransform::prepend_transform(const AffineTransform& transform) const
    {
        [cocoon::internal::ns<::NSAffineTransform>(this) prependTransform:cocoon::internal::native<::NSAffineTransform>(transform)];
    }

    void AffineTransform::rotate_by_degrees(double angle) const
    {
        [cocoon::internal::ns<::NSAffineTransform>(this) rotateByDegrees:static_cast<::CGFloat>(angle)];
    }

    void AffineTransform::rotate_by_radians(double angle) const
    {
        [cocoon::internal::ns<::NSAffineTransform>(this) rotateByRadians:static_cast<::CGFloat>(angle)];
    }

    void AffineTransform::scale_by(double scale) const
    {
        [cocoon::internal::ns<::NSAffineTransform>(this) scaleBy:static_cast<::CGFloat>(scale)];
    }

    void AffineTransform::scale_x_by(double scale_x, double scale_y) const
    {
        [cocoon::internal::ns<::NSAffineTransform>(this) scaleXBy:static_cast<::CGFloat>(scale_x) yBy:static_cast<::CGFloat>(scale_y)];
    }

    void AffineTransform::set() const
    {
        [cocoon::internal::ns<::NSAffineTransform>(this) set];
    }

    AffineTransform AffineTransform::transform()
    {
        return cocoon::internal::wrap<AffineTransform>([::NSAffineTransform transform]);
    }

    BezierPath AffineTransform::transform_bezier_path(const BezierPath& path) const
    {
        return cocoon::internal::wrap<BezierPath>([cocoon::internal::ns<::NSAffineTransform>(this) transformBezierPath:cocoon::internal::native<::NSBezierPath>(path)]);
    }

    Point AffineTransform::transform_point(const Point& a_point) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAffineTransform>(this) transformPoint:cocoon::internal::to(a_point)]);
    }

    Size AffineTransform::transform_size(const Size& a_size) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAffineTransform>(this) transformSize:cocoon::internal::to(a_size)]);
    }

    void AffineTransform::translate_x_by(double delta_x, double delta_y) const
    {
        [cocoon::internal::ns<::NSAffineTransform>(this) translateXBy:static_cast<::CGFloat>(delta_x) yBy:static_cast<::CGFloat>(delta_y)];
    }

    AffineTransformStruct AffineTransform::transform_struct() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAffineTransform>(this) transformStruct]);
    }

    void AffineTransform::set_transform_struct(const AffineTransformStruct& value) const
    {
        [cocoon::internal::ns<::NSAffineTransform>(this) setTransformStruct:cocoon::internal::to(value)];
    }
}
