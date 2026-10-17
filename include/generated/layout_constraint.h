#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class LayoutAnchorBase;

    /**
     * @brief C++ handle for the Objective-C class `NSLayoutConstraint` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::LayoutConstraint layout_constraint;
     * layout_constraint.set_active(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::LayoutConstraint layout_constraint{};
     * layout_constraint.set_active(true);
     * auto active = layout_constraint.is_active();
     * layout_constraint.set_constant(1);
     * auto constant = layout_constraint.constant();
     * layout_constraint.set_identifier("text");
     * auto identifier = layout_constraint.identifier();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nslayoutconstraint
     */
    class LayoutConstraint : public Object
    {
    public:
        /// @brief Creates a new `NSLayoutConstraint` instance and returns a handle to it.
        explicit LayoutConstraint();
        /// @brief Creates a null handle that refers to no native object.
        LayoutConstraint(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit LayoutConstraint(Adopt adopt);
        /**
     * @brief Calls `+[NSLayoutConstraint activateConstraints:]`.
     * @details Convenience method that activates each constraint in the contained array, in the same manner as setting active=YES. This is often more efficient than activating each constraint individually.
     * @param constraints Argument converted to the Objective-C parameter of the same role.
     */
        static void activate_constraints(const std::vector<LayoutConstraint>& constraints);
        /**
     * @brief Calls `+[NSLayoutConstraint constraintWithItem:attribute:relatedBy:toItem:attribute:multiplier:constant:]`.
     * @details Create constraints explicitly. Constraints are of the form "view1.attr1 = view2.attr2 multiplier + constant" If your equation does not have a second view and attribute, use nil and NSLayoutAttributeNotAnAttribute. Use of this method is not recommended. Constraints should be created using anchor objects on views and layout guides.
     * @param view1 Argument converted to the Objective-C parameter of the same role.
     * @param attr1 Argument converted to the Objective-C parameter of the same role.
     * @param relation Argument converted to the Objective-C parameter of the same role.
     * @param view2 Argument converted to the Objective-C parameter of the same role.
     * @param attr2 Argument converted to the Objective-C parameter of the same role.
     * @param multiplier Argument converted to the Objective-C parameter of the same role.
     * @param c Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static LayoutConstraint constraint_with_item(const Object& view1, LayoutAttribute attr1, LayoutRelation relation, const Object& view2, LayoutAttribute attr2, double multiplier, double c);
        /**
     * @brief Calls `+[NSLayoutConstraint constraintsWithVisualFormat:options:metrics:views:]`.
     * @details Create an array of constraints using an ASCII-art-like visual format string. The values of the 'metrics' dictionary should be NSNumber (or some other type that responds to -doubleValue and returns a double).
     * @param format Argument converted to the Objective-C parameter of the same role.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param metrics Argument converted to the Objective-C parameter of the same role.
     * @param views Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<LayoutConstraint> constraints_with_visual_format(const std::string& format, LayoutFormatOptions opts, const std::map<std::string, Object>& metrics, const std::map<std::string, Object>& views);
        /**
     * @brief Calls `+[NSLayoutConstraint deactivateConstraints:]`.
     * @details Convenience method that deactivates each constraint in the contained array, in the same manner as setting active=NO. This is often more efficient than deactivating each constraint individually.
     * @param constraints Argument converted to the Objective-C parameter of the same role.
     */
        static void deactivate_constraints(const std::vector<LayoutConstraint>& constraints);
        /**
     * @brief Returns the `active` property of `NSLayoutConstraint`.
     * @details The receiver may be activated or deactivated by manipulating this property. Only active constraints affect the calculated layout. Attempting to activate a constraint whose items have no common ancestor will cause an exception to be thrown. Defaults to NO for newly created constraints.
     * @return The converted Objective-C result.
     */
        bool is_active() const;
        /**
     * @brief Sets the `active` property of `NSLayoutConstraint`.
     * @details The receiver may be activated or deactivated by manipulating this property. Only active constraints affect the calculated layout. Attempting to activate a constraint whose items have no common ancestor will cause an exception to be thrown. Defaults to NO for newly created constraints.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_active(bool value) const;
        /**
     * @brief Returns the `constant` property of `NSLayoutConstraint`.
     * @details Unlike the other properties, the constant may be modified after constraint creation. Setting the constant on an existing constraint performs much better than removing the constraint and adding a new one that's just like the old but for having a new constant.
     * @return The converted Objective-C result.
     */
        double constant() const;
        /**
     * @brief Sets the `constant` property of `NSLayoutConstraint`.
     * @details Unlike the other properties, the constant may be modified after constraint creation. Setting the constant on an existing constraint performs much better than removing the constraint and adding a new one that's just like the old but for having a new constant.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_constant(double value) const;
        /**
     * @brief Returns the `firstAnchor` property of `NSLayoutConstraint`.
     * @details accessors firstAnchor{==,\<=,>=} secondAnchor multiplier + constant
     * @return The converted Objective-C result.
     */
        LayoutAnchorBase first_anchor() const;
        /**
     * @brief Returns the `firstAttribute` property of `NSLayoutConstraint`.
     * @return The converted Objective-C result.
     */
        LayoutAttribute first_attribute() const;
        /**
     * @brief Returns the `firstItem` property of `NSLayoutConstraint`.
     * @details accessors firstItem.firstAttribute {==,\<=,>=} secondItem.secondAttribute multiplier + constant Access to these properties is not recommended. Use the 'firstAnchor' and 'secondAnchor' properties instead.
     * @return The converted Objective-C result.
     */
        Object first_item() const;
        /**
     * @brief Returns the `identifier` property of `NSLayoutConstraint`.
     * @details For ease in debugging, name a constraint by setting its identifier, which will be printed in the constraint's description. Identifiers starting with NS or UI are reserved by the system.
     * @return The converted Objective-C result.
     */
        std::string identifier() const;
        /**
     * @brief Sets the `identifier` property of `NSLayoutConstraint`.
     * @details For ease in debugging, name a constraint by setting its identifier, which will be printed in the constraint's description. Identifiers starting with NS or UI are reserved by the system.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_identifier(const std::string& value) const;
        /**
     * @brief Returns the `multiplier` property of `NSLayoutConstraint`.
     * @return The converted Objective-C result.
     */
        double multiplier() const;
        /**
     * @brief Returns the `priority` property of `NSLayoutConstraint`.
     * @return The converted Objective-C result.
     */
        float priority() const;
        /**
     * @brief Sets the `priority` property of `NSLayoutConstraint`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_priority(float value) const;
        /**
     * @brief Returns the `relation` property of `NSLayoutConstraint`.
     * @return The converted Objective-C result.
     */
        LayoutRelation relation() const;
        /**
     * @brief Returns the `secondAnchor` property of `NSLayoutConstraint`.
     * @return The converted Objective-C result.
     */
        LayoutAnchorBase second_anchor() const;
        /**
     * @brief Returns the `secondAttribute` property of `NSLayoutConstraint`.
     * @return The converted Objective-C result.
     */
        LayoutAttribute second_attribute() const;
        /**
     * @brief Returns the `secondItem` property of `NSLayoutConstraint`.
     * @return The converted Objective-C result.
     */
        Object second_item() const;
        /**
     * @brief Returns the `shouldBeArchived` property of `NSLayoutConstraint`.
     * @details When a view is archived, it archives some but not all constraints in its -constraints array. The value of shouldBeArchived informs the view if a particular constraint should be archived by the view. If a constraint is created at runtime in response to the state of the object, it isn't appropriate to archive the constraint - rather you archive the state that gives rise to the constraint. Since the majority of constraints that should be archived are created in Interface Builder (which is smart enough to set this prop to YES), the default value for this property is NO.
     * @return The converted Objective-C result.
     */
        bool should_be_archived() const;
        /**
     * @brief Sets the `shouldBeArchived` property of `NSLayoutConstraint`.
     * @details When a view is archived, it archives some but not all constraints in its -constraints array. The value of shouldBeArchived informs the view if a particular constraint should be archived by the view. If a constraint is created at runtime in response to the state of the object, it isn't appropriate to archive the constraint - rather you archive the state that gives rise to the constraint. Since the majority of constraints that should be archived are created in Interface Builder (which is smart enough to set this prop to YES), the default value for this property is NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_should_be_archived(bool value) const;
    };
}
