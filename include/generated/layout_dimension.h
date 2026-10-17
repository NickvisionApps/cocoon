#pragma once

#include "generated/enums.h"
#include "generated/layout_anchor_base.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class LayoutConstraint;

    /**
     * @brief C++ handle for the Objective-C class `NSLayoutDimension` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref LayoutAnchorBase.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::LayoutDimension layout_dimension;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::LayoutDimension layout_dimension{};
     * layout_dimension.constraint_equal_to_anchor(cocoon::LayoutDimension(), 1);
     * layout_dimension.constraint_equal_to_anchor(cocoon::LayoutDimension(), 1, 1);
     * layout_dimension.constraint_equal_to_constant(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nslayoutdimension
     */
    class LayoutDimension : public LayoutAnchorBase
    {
    public:
        /// @brief Creates a new `NSLayoutDimension` instance and returns a handle to it.
        explicit LayoutDimension();
        /// @brief Creates a null handle that refers to no native object.
        LayoutDimension(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit LayoutDimension(Adopt adopt);
        using LayoutAnchorBase::constraint_equal_to_anchor;
        using LayoutAnchorBase::constraint_greater_than_or_equal_to_anchor;
        using LayoutAnchorBase::constraint_less_than_or_equal_to_anchor;
        /**
     * @brief Calls `-[NSLayoutDimension constraintEqualToAnchor:multiplier:]`.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @param m Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_equal_to_anchor(const LayoutDimension& anchor, double m) const;
        /**
     * @brief Calls `-[NSLayoutDimension constraintEqualToAnchor:multiplier:constant:]`.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @param m Argument converted to the Objective-C parameter of the same role.
     * @param c Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_equal_to_anchor(const LayoutDimension& anchor, double m, double c) const;
        /**
     * @brief Calls `-[NSLayoutDimension constraintEqualToConstant:]`.
     * @param c Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_equal_to_constant(double c) const;
        /**
     * @brief Calls `-[NSLayoutDimension constraintGreaterThanOrEqualToAnchor:multiplier:]`.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @param m Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_greater_than_or_equal_to_anchor(const LayoutDimension& anchor, double m) const;
        /**
     * @brief Calls `-[NSLayoutDimension constraintGreaterThanOrEqualToAnchor:multiplier:constant:]`.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @param m Argument converted to the Objective-C parameter of the same role.
     * @param c Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_greater_than_or_equal_to_anchor(const LayoutDimension& anchor, double m, double c) const;
        /**
     * @brief Calls `-[NSLayoutDimension constraintGreaterThanOrEqualToConstant:]`.
     * @param c Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_greater_than_or_equal_to_constant(double c) const;
        /**
     * @brief Calls `-[NSLayoutDimension constraintLessThanOrEqualToAnchor:multiplier:]`.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @param m Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_less_than_or_equal_to_anchor(const LayoutDimension& anchor, double m) const;
        /**
     * @brief Calls `-[NSLayoutDimension constraintLessThanOrEqualToAnchor:multiplier:constant:]`.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @param m Argument converted to the Objective-C parameter of the same role.
     * @param c Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_less_than_or_equal_to_anchor(const LayoutDimension& anchor, double m, double c) const;
        /**
     * @brief Calls `-[NSLayoutDimension constraintLessThanOrEqualToConstant:]`.
     * @param c Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_less_than_or_equal_to_constant(double c) const;
    };
}
