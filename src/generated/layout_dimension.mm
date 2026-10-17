#include "generated/layout_dimension.h"
#include "internal.h"

namespace cocoon
{
    LayoutDimension::LayoutDimension() : LayoutDimension(Adopt{cocoon::internal::retain([[::NSLayoutDimension alloc] init])})
    {
    }

    LayoutDimension::LayoutDimension(std::nullptr_t) : LayoutAnchorBase(nullptr)
    {
    }

    LayoutDimension::LayoutDimension(Adopt adopt) : LayoutAnchorBase(adopt)
    {
    }

    LayoutConstraint LayoutDimension::constraint_equal_to_anchor(const LayoutDimension& anchor, double m) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutDimension>(this) constraintEqualToAnchor:cocoon::internal::native<::NSLayoutDimension>(anchor) multiplier:static_cast<::CGFloat>(m)]);
    }

    LayoutConstraint LayoutDimension::constraint_equal_to_anchor(const LayoutDimension& anchor, double m, double c) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutDimension>(this) constraintEqualToAnchor:cocoon::internal::native<::NSLayoutDimension>(anchor) multiplier:static_cast<::CGFloat>(m) constant:static_cast<::CGFloat>(c)]);
    }

    LayoutConstraint LayoutDimension::constraint_equal_to_constant(double c) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutDimension>(this) constraintEqualToConstant:static_cast<::CGFloat>(c)]);
    }

    LayoutConstraint LayoutDimension::constraint_greater_than_or_equal_to_anchor(const LayoutDimension& anchor, double m) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutDimension>(this) constraintGreaterThanOrEqualToAnchor:cocoon::internal::native<::NSLayoutDimension>(anchor) multiplier:static_cast<::CGFloat>(m)]);
    }

    LayoutConstraint LayoutDimension::constraint_greater_than_or_equal_to_anchor(const LayoutDimension& anchor, double m, double c) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutDimension>(this) constraintGreaterThanOrEqualToAnchor:cocoon::internal::native<::NSLayoutDimension>(anchor) multiplier:static_cast<::CGFloat>(m) constant:static_cast<::CGFloat>(c)]);
    }

    LayoutConstraint LayoutDimension::constraint_greater_than_or_equal_to_constant(double c) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutDimension>(this) constraintGreaterThanOrEqualToConstant:static_cast<::CGFloat>(c)]);
    }

    LayoutConstraint LayoutDimension::constraint_less_than_or_equal_to_anchor(const LayoutDimension& anchor, double m) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutDimension>(this) constraintLessThanOrEqualToAnchor:cocoon::internal::native<::NSLayoutDimension>(anchor) multiplier:static_cast<::CGFloat>(m)]);
    }

    LayoutConstraint LayoutDimension::constraint_less_than_or_equal_to_anchor(const LayoutDimension& anchor, double m, double c) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutDimension>(this) constraintLessThanOrEqualToAnchor:cocoon::internal::native<::NSLayoutDimension>(anchor) multiplier:static_cast<::CGFloat>(m) constant:static_cast<::CGFloat>(c)]);
    }

    LayoutConstraint LayoutDimension::constraint_less_than_or_equal_to_constant(double c) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutDimension>(this) constraintLessThanOrEqualToConstant:static_cast<::CGFloat>(c)]);
    }
}
