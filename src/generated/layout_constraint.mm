#include "generated/layout_constraint.h"
#include "internal.h"

namespace cocoon
{
    LayoutConstraint::LayoutConstraint() : LayoutConstraint(Adopt{cocoon::internal::retain([[::NSLayoutConstraint alloc] init])})
    {
    }

    LayoutConstraint::LayoutConstraint(std::nullptr_t) : Object(nullptr)
    {
    }

    LayoutConstraint::LayoutConstraint(Adopt adopt) : Object(adopt)
    {
    }

    void LayoutConstraint::activate_constraints(const std::vector<LayoutConstraint>& constraints)
    {
        [::NSLayoutConstraint activateConstraints:cocoon::internal::to_array(constraints, [](const LayoutConstraint& e) -> id
                                                                             {
                                                                                 return cocoon::internal::native<::NSLayoutConstraint>(e);
                                                                             })];
    }

    LayoutConstraint LayoutConstraint::constraint_with_item(const Object& view1, LayoutAttribute attr1, LayoutRelation relation, const Object& view2, LayoutAttribute attr2, double multiplier, double c)
    {
        return cocoon::internal::wrap<LayoutConstraint>([::NSLayoutConstraint constraintWithItem:cocoon::internal::native_id(view1) attribute:static_cast<::NSLayoutAttribute>(attr1) relatedBy:static_cast<::NSLayoutRelation>(relation) toItem:cocoon::internal::native_id(view2) attribute:static_cast<::NSLayoutAttribute>(attr2) multiplier:static_cast<::CGFloat>(multiplier) constant:static_cast<::CGFloat>(c)]);
    }

    std::vector<LayoutConstraint> LayoutConstraint::constraints_with_visual_format(const std::string& format, LayoutFormatOptions opts, const std::map<std::string, Object>& metrics, const std::map<std::string, Object>& views)
    {
        return cocoon::internal::from_array<LayoutConstraint>([::NSLayoutConstraint constraintsWithVisualFormat:cocoon::internal::to(format)
                                                                                                        options:static_cast<::NSLayoutFormatOptions>(opts)
                                                                                                        metrics:cocoon::internal::to_dictionary(metrics, [](const std::string& k) -> id
                                                                                                                                                {
                                                                                                                                                    return cocoon::internal::to(k);
                                                                                                                                                },
                                                                                                                                                [](const Object& v) -> id
                                                                                                                                                {
                                                                                                                                                    return cocoon::internal::native_id(v);
                                                                                                                                                })
                                                                                                          views:cocoon::internal::to_dictionary(views, [](const std::string& k) -> id
                                                                                                                                                {
                                                                                                                                                    return cocoon::internal::to(k);
                                                                                                                                                },
                                                                                                                                                [](const Object& v) -> id
                                                                                                                                                {
                                                                                                                                                    return cocoon::internal::native_id(v);
                                                                                                                                                })],
                                                              [](id e) -> LayoutConstraint
                                                              {
                                                                  return cocoon::internal::wrap<LayoutConstraint>((::NSLayoutConstraint*)e);
                                                              });
    }

    void LayoutConstraint::deactivate_constraints(const std::vector<LayoutConstraint>& constraints)
    {
        [::NSLayoutConstraint deactivateConstraints:cocoon::internal::to_array(constraints, [](const LayoutConstraint& e) -> id
                                                                               {
                                                                                   return cocoon::internal::native<::NSLayoutConstraint>(e);
                                                                               })];
    }

    bool LayoutConstraint::is_active() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutConstraint>(this) isActive]);
    }

    void LayoutConstraint::set_active(bool value) const
    {
        [cocoon::internal::ns<::NSLayoutConstraint>(this) setActive:static_cast<::BOOL>(value)];
    }

    double LayoutConstraint::constant() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSLayoutConstraint>(this) constant]);
    }

    void LayoutConstraint::set_constant(double value) const
    {
        [cocoon::internal::ns<::NSLayoutConstraint>(this) setConstant:static_cast<::CGFloat>(value)];
    }

    LayoutAnchorBase LayoutConstraint::first_anchor() const
    {
        return cocoon::internal::wrap<LayoutAnchorBase>([cocoon::internal::ns<::NSLayoutConstraint>(this) firstAnchor]);
    }

    LayoutAttribute LayoutConstraint::first_attribute() const
    {
        return static_cast<LayoutAttribute>([cocoon::internal::ns<::NSLayoutConstraint>(this) firstAttribute]);
    }

    Object LayoutConstraint::first_item() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSLayoutConstraint>(this) firstItem]);
    }

    std::string LayoutConstraint::identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutConstraint>(this) identifier]);
    }

    void LayoutConstraint::set_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSLayoutConstraint>(this) setIdentifier:cocoon::internal::to(value)];
    }

    double LayoutConstraint::multiplier() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSLayoutConstraint>(this) multiplier]);
    }

    float LayoutConstraint::priority() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSLayoutConstraint>(this) priority]);
    }

    void LayoutConstraint::set_priority(float value) const
    {
        [cocoon::internal::ns<::NSLayoutConstraint>(this) setPriority:static_cast<::NSLayoutPriority>(value)];
    }

    LayoutRelation LayoutConstraint::relation() const
    {
        return static_cast<LayoutRelation>([cocoon::internal::ns<::NSLayoutConstraint>(this) relation]);
    }

    LayoutAnchorBase LayoutConstraint::second_anchor() const
    {
        return cocoon::internal::wrap<LayoutAnchorBase>([cocoon::internal::ns<::NSLayoutConstraint>(this) secondAnchor]);
    }

    LayoutAttribute LayoutConstraint::second_attribute() const
    {
        return static_cast<LayoutAttribute>([cocoon::internal::ns<::NSLayoutConstraint>(this) secondAttribute]);
    }

    Object LayoutConstraint::second_item() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSLayoutConstraint>(this) secondItem]);
    }

    bool LayoutConstraint::should_be_archived() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutConstraint>(this) shouldBeArchived]);
    }

    void LayoutConstraint::set_should_be_archived(bool value) const
    {
        [cocoon::internal::ns<::NSLayoutConstraint>(this) setShouldBeArchived:static_cast<::BOOL>(value)];
    }
}
