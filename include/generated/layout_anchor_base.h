#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class LayoutConstraint;

    /**
     * @brief C++ handle for the Objective-C class `NSLayoutAnchor` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Use the typed template @ref LayoutAnchor to supply AnchorType.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::LayoutAnchorBase layout_anchor_base;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nslayoutanchor
     */
    class LayoutAnchorBase : public Object
    {
    public:
        /// @brief Creates a new `NSLayoutAnchor` instance and returns a handle to it.
        explicit LayoutAnchorBase();
        /// @brief Creates a null handle that refers to no native object.
        LayoutAnchorBase(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit LayoutAnchorBase(Adopt adopt);
        /**
     * @brief Calls `-[NSLayoutAnchor constraintEqualToAnchor:]`.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_equal_to_anchor(const LayoutAnchorBase& anchor) const;
        /**
     * @brief Calls `-[NSLayoutAnchor constraintEqualToAnchor:constant:]`.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @param c Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_equal_to_anchor(const LayoutAnchorBase& anchor, double c) const;
        /**
     * @brief Calls `-[NSLayoutAnchor constraintGreaterThanOrEqualToAnchor:]`.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_greater_than_or_equal_to_anchor(const LayoutAnchorBase& anchor) const;
        /**
     * @brief Calls `-[NSLayoutAnchor constraintGreaterThanOrEqualToAnchor:constant:]`.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @param c Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_greater_than_or_equal_to_anchor(const LayoutAnchorBase& anchor, double c) const;
        /**
     * @brief Calls `-[NSLayoutAnchor constraintLessThanOrEqualToAnchor:]`.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_less_than_or_equal_to_anchor(const LayoutAnchorBase& anchor) const;
        /**
     * @brief Calls `-[NSLayoutAnchor constraintLessThanOrEqualToAnchor:constant:]`.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @param c Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutConstraint constraint_less_than_or_equal_to_anchor(const LayoutAnchorBase& anchor, double c) const;
        /**
     * @brief Returns the `constraintsAffectingLayout` property of `NSLayoutAnchor`.
     * @return The converted Objective-C result.
     */
        std::vector<LayoutConstraint> constraints_affecting_layout() const;
        /**
     * @brief Returns the `hasAmbiguousLayout` property of `NSLayoutAnchor`.
     * @return The converted Objective-C result.
     */
        bool has_ambiguous_layout() const;
        /**
     * @brief Returns the `item` property of `NSLayoutAnchor`.
     * @return The converted Objective-C result.
     */
        Object item() const;
        /**
     * @brief Returns the `name` property of `NSLayoutAnchor`.
     * @return The converted Objective-C result.
     */
        std::string name() const;
    };

    template <class AnchorType>
    class LayoutAnchor : public LayoutAnchorBase
    {
    public:
        using LayoutAnchorBase::LayoutAnchorBase;
        LayoutAnchor() : LayoutAnchorBase()
        {
        }
        LayoutAnchor(const LayoutAnchorBase& other) : LayoutAnchorBase(other)
        {
        }
        using LayoutAnchorBase::constraint_equal_to_anchor;
        using LayoutAnchorBase::constraint_greater_than_or_equal_to_anchor;
        using LayoutAnchorBase::constraint_less_than_or_equal_to_anchor;
        using LayoutAnchorBase::constraints_affecting_layout;
        using LayoutAnchorBase::has_ambiguous_layout;
        using LayoutAnchorBase::item;
        using LayoutAnchorBase::name;
    };
}
