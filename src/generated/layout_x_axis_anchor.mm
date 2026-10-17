#include "generated/layout_x_axis_anchor.h"
#include "internal.h"

namespace cocoon
{
    LayoutXAxisAnchor::LayoutXAxisAnchor() : LayoutXAxisAnchor(Adopt{cocoon::internal::retain([[::NSLayoutXAxisAnchor alloc] init])})
    {
    }

    LayoutXAxisAnchor::LayoutXAxisAnchor(std::nullptr_t) : LayoutAnchorBase(nullptr)
    {
    }

    LayoutXAxisAnchor::LayoutXAxisAnchor(Adopt adopt) : LayoutAnchorBase(adopt)
    {
    }

    LayoutDimension LayoutXAxisAnchor::anchor_with_offset_to_anchor(const LayoutXAxisAnchor& other_anchor) const
    {
        return cocoon::internal::wrap<LayoutDimension>([cocoon::internal::ns<::NSLayoutXAxisAnchor>(this) anchorWithOffsetToAnchor:cocoon::internal::native<::NSLayoutXAxisAnchor>(other_anchor)]);
    }

    LayoutConstraint LayoutXAxisAnchor::constraint_equal_to_system_spacing_after_anchor(const LayoutXAxisAnchor& anchor, double multiplier) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutXAxisAnchor>(this) constraintEqualToSystemSpacingAfterAnchor:cocoon::internal::native<::NSLayoutXAxisAnchor>(anchor) multiplier:static_cast<::CGFloat>(multiplier)]);
    }

    LayoutConstraint LayoutXAxisAnchor::constraint_greater_than_or_equal_to_system_spacing_after_anchor(const LayoutXAxisAnchor& anchor, double multiplier) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutXAxisAnchor>(this) constraintGreaterThanOrEqualToSystemSpacingAfterAnchor:cocoon::internal::native<::NSLayoutXAxisAnchor>(anchor) multiplier:static_cast<::CGFloat>(multiplier)]);
    }

    LayoutConstraint LayoutXAxisAnchor::constraint_less_than_or_equal_to_system_spacing_after_anchor(const LayoutXAxisAnchor& anchor, double multiplier) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutXAxisAnchor>(this) constraintLessThanOrEqualToSystemSpacingAfterAnchor:cocoon::internal::native<::NSLayoutXAxisAnchor>(anchor) multiplier:static_cast<::CGFloat>(multiplier)]);
    }
}
