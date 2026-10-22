#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/layout_anchor_base.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class LayoutConstraint;
    class LayoutDimension;

    /**
     * @brief C++ handle for the Objective-C class `NSLayoutYAxisAnchor` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref LayoutAnchorBase.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::LayoutYAxisAnchor layout_y_axis_anchor;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::LayoutYAxisAnchor layout_y_axis_anchor{};
     * layout_y_axis_anchor.anchor_with_offset_to_anchor(cocoon::LayoutYAxisAnchor());
     * layout_y_axis_anchor.constraint_equal_to_system_spacing_below_anchor(cocoon::LayoutYAxisAnchor(), 1);
     * layout_y_axis_anchor.constraint_greater_than_or_equal_to_system_spacing_below_anchor(cocoon::LayoutYAxisAnchor(), 1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nslayoutyaxisanchor
     */
    class LayoutYAxisAnchor : public LayoutAnchorBase
    {
    public:
        /// @brief Creates a new `NSLayoutYAxisAnchor` instance and returns a handle to it.
        explicit LayoutYAxisAnchor();
        /// @brief Creates a null handle that refers to no native object.
        LayoutYAxisAnchor(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit LayoutYAxisAnchor(Adopt adopt);
        /**
         * @brief Calls `-[NSLayoutYAxisAnchor anchorWithOffsetToAnchor:]`.
         * @param other_anchor Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        LayoutDimension anchor_with_offset_to_anchor(const LayoutYAxisAnchor& other_anchor) const;
        /**
         * @brief Calls `-[NSLayoutYAxisAnchor constraintEqualToSystemSpacingBelowAnchor:multiplier:]`.
         * @details Constraints of the form, receiver [= | ≥ | ≤] 'anchor' + 'multiplier' system space, where the value of the system space is determined from information available from the anchors. The constraint affects how far the receiver will be positioned below 'anchor'.
         * @param anchor Argument converted to the Objective-C parameter of the same role.
         * @param multiplier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        LayoutConstraint constraint_equal_to_system_spacing_below_anchor(const LayoutYAxisAnchor& anchor, double multiplier) const;
        /**
         * @brief Calls `-[NSLayoutYAxisAnchor constraintGreaterThanOrEqualToSystemSpacingBelowAnchor:multiplier:]`.
         * @param anchor Argument converted to the Objective-C parameter of the same role.
         * @param multiplier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        LayoutConstraint constraint_greater_than_or_equal_to_system_spacing_below_anchor(const LayoutYAxisAnchor& anchor, double multiplier) const;
        /**
         * @brief Calls `-[NSLayoutYAxisAnchor constraintLessThanOrEqualToSystemSpacingBelowAnchor:multiplier:]`.
         * @param anchor Argument converted to the Objective-C parameter of the same role.
         * @param multiplier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        LayoutConstraint constraint_less_than_or_equal_to_system_spacing_below_anchor(const LayoutYAxisAnchor& anchor, double multiplier) const;
    };
}
