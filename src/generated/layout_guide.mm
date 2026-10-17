#include "generated/layout_guide.h"
#include "internal.h"

namespace cocoon
{
    LayoutGuide::LayoutGuide() : LayoutGuide(Adopt{cocoon::internal::retain([[::NSLayoutGuide alloc] init])})
    {
    }

    LayoutGuide::LayoutGuide(std::nullptr_t) : Object(nullptr)
    {
    }

    LayoutGuide::LayoutGuide(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<LayoutConstraint> LayoutGuide::constraints_affecting_layout_for_orientation(ConstraintOrientation orientation) const
    {
        return cocoon::internal::from_array<LayoutConstraint>([cocoon::internal::ns<::NSLayoutGuide>(this) constraintsAffectingLayoutForOrientation:static_cast<::NSLayoutConstraintOrientation>(orientation)], [](id e) -> LayoutConstraint
                                                {
                                                    return cocoon::internal::wrap<LayoutConstraint>((::NSLayoutConstraint*)e);
                                                });
    }

    LayoutYAxisAnchor LayoutGuide::bottom_anchor() const
    {
        return cocoon::internal::wrap<LayoutYAxisAnchor>([cocoon::internal::ns<::NSLayoutGuide>(this) bottomAnchor]);
    }

    LayoutXAxisAnchor LayoutGuide::center_x_anchor() const
    {
        return cocoon::internal::wrap<LayoutXAxisAnchor>([cocoon::internal::ns<::NSLayoutGuide>(this) centerXAnchor]);
    }

    LayoutYAxisAnchor LayoutGuide::center_y_anchor() const
    {
        return cocoon::internal::wrap<LayoutYAxisAnchor>([cocoon::internal::ns<::NSLayoutGuide>(this) centerYAnchor]);
    }

    Rect LayoutGuide::frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutGuide>(this) frame]);
    }

    bool LayoutGuide::has_ambiguous_layout() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutGuide>(this) hasAmbiguousLayout]);
    }

    LayoutDimension LayoutGuide::height_anchor() const
    {
        return cocoon::internal::wrap<LayoutDimension>([cocoon::internal::ns<::NSLayoutGuide>(this) heightAnchor]);
    }

    std::string LayoutGuide::identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutGuide>(this) identifier]);
    }

    void LayoutGuide::set_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSLayoutGuide>(this) setIdentifier:cocoon::internal::to(value)];
    }

    LayoutXAxisAnchor LayoutGuide::leading_anchor() const
    {
        return cocoon::internal::wrap<LayoutXAxisAnchor>([cocoon::internal::ns<::NSLayoutGuide>(this) leadingAnchor]);
    }

    LayoutXAxisAnchor LayoutGuide::left_anchor() const
    {
        return cocoon::internal::wrap<LayoutXAxisAnchor>([cocoon::internal::ns<::NSLayoutGuide>(this) leftAnchor]);
    }

    View LayoutGuide::owning_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSLayoutGuide>(this) owningView]);
    }

    void LayoutGuide::set_owning_view(const View& value) const
    {
        [cocoon::internal::ns<::NSLayoutGuide>(this) setOwningView:cocoon::internal::native<::NSView>(value)];
    }

    LayoutXAxisAnchor LayoutGuide::right_anchor() const
    {
        return cocoon::internal::wrap<LayoutXAxisAnchor>([cocoon::internal::ns<::NSLayoutGuide>(this) rightAnchor]);
    }

    LayoutYAxisAnchor LayoutGuide::top_anchor() const
    {
        return cocoon::internal::wrap<LayoutYAxisAnchor>([cocoon::internal::ns<::NSLayoutGuide>(this) topAnchor]);
    }

    LayoutXAxisAnchor LayoutGuide::trailing_anchor() const
    {
        return cocoon::internal::wrap<LayoutXAxisAnchor>([cocoon::internal::ns<::NSLayoutGuide>(this) trailingAnchor]);
    }

    LayoutDimension LayoutGuide::width_anchor() const
    {
        return cocoon::internal::wrap<LayoutDimension>([cocoon::internal::ns<::NSLayoutGuide>(this) widthAnchor]);
    }
}
