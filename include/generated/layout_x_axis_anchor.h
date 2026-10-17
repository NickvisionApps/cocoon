#pragma once

#include "generated/enums.h"
#include "generated/layout_anchor_base.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class LayoutConstraint;
    class LayoutDimension;

    /**
     * @brief C++ handle for the Objective-C class `NSLayoutXAxisAnchor` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref LayoutAnchorBase.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::LayoutXAxisAnchor layout_x_axis_anchor;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::LayoutXAxisAnchor layout_x_axis_anchor{};
     * layout_x_axis_anchor.anchor_with_offset_to_anchor(cocoon::LayoutXAxisAnchor());
     * layout_x_axis_anchor.constraint_equal_to_system_spacing_after_anchor(cocoon::LayoutXAxisAnchor(), 1);
     * layout_x_axis_anchor.constraint_greater_than_or_equal_to_system_spacing_after_anchor(cocoon::LayoutXAxisAnchor(), 1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nslayoutxaxisanchor
     */
    class LayoutXAxisAnchor : public LayoutAnchorBase
    {
    public:
        /// @brief Creates a new `NSLayoutXAxisAnchor` instance and returns a handle to it.
        explicit LayoutXAxisAnchor();
        /// @brief Creates a null handle that refers to no native object.
        LayoutXAxisAnchor(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit LayoutXAxisAnchor(Adopt adopt);
        /**
     * @brief Calls `-[NSLayoutXAxisAnchor anchorWithOffsetToAnchor:]`.
     * @param other_anchor Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutDimension anchor_with_offset_to_anchor(const LayoutXAxisAnchor& other_anchor) const;
        /**
     * @brief Calls `-[NSLayoutXAxisAnchor constraintEqualToSystemSpacingAfterAnchor:multiplier:]`.
     * @details Constraints of the form, receiver [= | ≥ | ≤] 'anchor' + 'multiplier' system space, where the value of the system space is determined from information available from the anchors. The constraint affects how far the receiver will be positioned trailing 'anchor', per the effective user interface layout direction.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @param multiplier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_equal_to_system_spacing_after_anchor(const LayoutXAxisAnchor& anchor, double multiplier) const;
        /**
     * @brief Calls `-[NSLayoutXAxisAnchor constraintGreaterThanOrEqualToSystemSpacingAfterAnchor:multiplier:]`.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @param multiplier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_greater_than_or_equal_to_system_spacing_after_anchor(const LayoutXAxisAnchor& anchor, double multiplier) const;
        /**
     * @brief Calls `-[NSLayoutXAxisAnchor constraintLessThanOrEqualToSystemSpacingAfterAnchor:multiplier:]`.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @param multiplier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_less_than_or_equal_to_system_spacing_after_anchor(const LayoutXAxisAnchor& anchor, double multiplier) const;
    };
}
