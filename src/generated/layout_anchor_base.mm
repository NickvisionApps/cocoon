#include "generated/layout_anchor_base.h"
#include "internal.h"

namespace cocoon
{
    LayoutAnchorBase::LayoutAnchorBase() : LayoutAnchorBase(Adopt{cocoon::internal::retain([[::NSLayoutAnchor alloc] init])})
    {
    }

    LayoutAnchorBase::LayoutAnchorBase(std::nullptr_t) : Object(nullptr)
    {
    }

    LayoutAnchorBase::LayoutAnchorBase(Adopt adopt) : Object(adopt)
    {
    }

    LayoutConstraint LayoutAnchorBase::constraint_equal_to_anchor(const LayoutAnchorBase& anchor) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutAnchor>(this) constraintEqualToAnchor:cocoon::internal::native<NSLayoutAnchor<id>>(anchor)]);
    }

    LayoutConstraint LayoutAnchorBase::constraint_equal_to_anchor(const LayoutAnchorBase& anchor, double c) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutAnchor>(this) constraintEqualToAnchor:cocoon::internal::native<NSLayoutAnchor<id>>(anchor) constant:static_cast<::CGFloat>(c)]);
    }

    LayoutConstraint LayoutAnchorBase::constraint_greater_than_or_equal_to_anchor(const LayoutAnchorBase& anchor) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutAnchor>(this) constraintGreaterThanOrEqualToAnchor:cocoon::internal::native<NSLayoutAnchor<id>>(anchor)]);
    }

    LayoutConstraint LayoutAnchorBase::constraint_greater_than_or_equal_to_anchor(const LayoutAnchorBase& anchor, double c) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutAnchor>(this) constraintGreaterThanOrEqualToAnchor:cocoon::internal::native<NSLayoutAnchor<id>>(anchor) constant:static_cast<::CGFloat>(c)]);
    }

    LayoutConstraint LayoutAnchorBase::constraint_less_than_or_equal_to_anchor(const LayoutAnchorBase& anchor) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutAnchor>(this) constraintLessThanOrEqualToAnchor:cocoon::internal::native<NSLayoutAnchor<id>>(anchor)]);
    }

    LayoutConstraint LayoutAnchorBase::constraint_less_than_or_equal_to_anchor(const LayoutAnchorBase& anchor, double c) const
    {
        return cocoon::internal::wrap<LayoutConstraint>([cocoon::internal::ns<::NSLayoutAnchor>(this) constraintLessThanOrEqualToAnchor:cocoon::internal::native<NSLayoutAnchor<id>>(anchor) constant:static_cast<::CGFloat>(c)]);
    }

    std::vector<LayoutConstraint> LayoutAnchorBase::constraints_affecting_layout() const
    {
        return cocoon::internal::from_array<LayoutConstraint>([cocoon::internal::ns<::NSLayoutAnchor>(this) constraintsAffectingLayout], [](id e) -> LayoutConstraint
                                                              {
                                                                  return cocoon::internal::wrap<LayoutConstraint>((::NSLayoutConstraint*)e);
                                                              });
    }

    bool LayoutAnchorBase::has_ambiguous_layout() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutAnchor>(this) hasAmbiguousLayout]);
    }

    Object LayoutAnchorBase::item() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSLayoutAnchor>(this) item]);
    }

    std::string LayoutAnchorBase::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutAnchor>(this) name]);
    }
}
