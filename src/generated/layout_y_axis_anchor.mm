#include "generated/layout_y_axis_anchor.h"
#include "internal.h"

namespace cocoon
{
    LayoutYAxisAnchor::LayoutYAxisAnchor() : LayoutYAxisAnchor(Adopt{cocoon::internal::retain([[::NSLayoutYAxisAnchor alloc] init])})
    {
    }

    LayoutYAxisAnchor::LayoutYAxisAnchor(std::nullptr_t) : LayoutAnchorBase(nullptr)
    {
    }

    LayoutYAxisAnchor::LayoutYAxisAnchor(Adopt adopt) : LayoutAnchorBase(adopt)
    {
    }

    LayoutDimension LayoutYAxisAnchor::anchor_with_offset_to_anchor(const LayoutYAxisAnchor& other_anchor) const
    {
        return cocoon::internal::wrap<LayoutDimension>([cocoon::internal::ns<::NSLayoutYAxisAnchor>(this) anchorWithOffsetToAnchor:cocoon::internal::native<::NSLayoutYAxisAnchor>(other_anchor)]);
    }

    LayoutConstraint LayoutYAxisAnchor::constraint_equal_to_system_spacing_below_anchor(const LayoutYAxisAnchor& anchor, double multiplier) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutYAxisAnchor>(this) constraintEqualToSystemSpacingBelowAnchor:cocoon::internal::native<::NSLayoutYAxisAnchor>(anchor) multiplier:static_cast<::CGFloat>(multiplier)]);
    }

    LayoutConstraint LayoutYAxisAnchor::constraint_greater_than_or_equal_to_system_spacing_below_anchor(const LayoutYAxisAnchor& anchor, double multiplier) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutYAxisAnchor>(this) constraintGreaterThanOrEqualToSystemSpacingBelowAnchor:cocoon::internal::native<::NSLayoutYAxisAnchor>(anchor) multiplier:static_cast<::CGFloat>(multiplier)]);
    }

    LayoutConstraint LayoutYAxisAnchor::constraint_less_than_or_equal_to_system_spacing_below_anchor(const LayoutYAxisAnchor& anchor, double multiplier) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutYAxisAnchor>(this) constraintLessThanOrEqualToSystemSpacingBelowAnchor:cocoon::internal::native<::NSLayoutYAxisAnchor>(anchor) multiplier:static_cast<::CGFloat>(multiplier)]);
    }
}
