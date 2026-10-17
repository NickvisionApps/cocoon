#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class LayoutConstraint;
    class LayoutDimension;
    class LayoutXAxisAnchor;
    class LayoutYAxisAnchor;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSLayoutGuide` (AppKit).
     * @details NSLayoutGuides will not show up in the view hierarchy, but may be used as items in an NSLayoutConstraint and represent a rectangle in the layout engine.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::LayoutGuide layout_guide;
     * layout_guide.set_identifier("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::LayoutGuide layout_guide{};
     * layout_guide.set_identifier("text");
     * auto identifier = layout_guide.identifier();
     * layout_guide.set_owning_view(cocoon::View());
     * auto owning_view = layout_guide.owning_view();
     * layout_guide.constraints_affecting_layout_for_orientation(cocoon::ConstraintOrientation::Horizontal);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nslayoutguide
     */
    class LayoutGuide : public Object
    {
    public:
        /// @brief Creates a new `NSLayoutGuide` instance and returns a handle to it.
        explicit LayoutGuide();
        /// @brief Creates a null handle that refers to no native object.
        LayoutGuide(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit LayoutGuide(Adopt adopt);
        /**
     * @brief Calls `-[NSLayoutGuide constraintsAffectingLayoutForOrientation:]`.
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<LayoutConstraint> constraints_affecting_layout_for_orientation(ConstraintOrientation orientation) const;
        /**
     * @brief Returns the `bottomAnchor` property of `NSLayoutGuide`.
     * @return The converted Objective-C result.
     */
        LayoutYAxisAnchor bottom_anchor() const;
        /**
     * @brief Returns the `centerXAnchor` property of `NSLayoutGuide`.
     * @return The converted Objective-C result.
     */
        LayoutXAxisAnchor center_x_anchor() const;
        /**
     * @brief Returns the `centerYAnchor` property of `NSLayoutGuide`.
     * @return The converted Objective-C result.
     */
        LayoutYAxisAnchor center_y_anchor() const;
        /**
     * @brief Returns the `frame` property of `NSLayoutGuide`.
     * @return The converted Objective-C result.
     */
        Rect frame() const;
        /**
     * @brief Returns the `hasAmbiguousLayout` property of `NSLayoutGuide`.
     * @return The converted Objective-C result.
     */
        bool has_ambiguous_layout() const;
        /**
     * @brief Returns the `heightAnchor` property of `NSLayoutGuide`.
     * @return The converted Objective-C result.
     */
        LayoutDimension height_anchor() const;
        /**
     * @brief Returns the `identifier` property of `NSLayoutGuide`.
     * @return The converted Objective-C result.
     */
        std::string identifier() const;
        /**
     * @brief Sets the `identifier` property of `NSLayoutGuide`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_identifier(const std::string& value) const;
        /**
     * @brief Returns the `leadingAnchor` property of `NSLayoutGuide`.
     * @details These properties aid concise creation of constraints. Layout guides can be constrained using simple code like the following: [view.topAnchor constraintEqualTo:someLayoutGuide.topAnchor constant:10]; See NSLayoutAnchor.h for more details.
     * @return The converted Objective-C result.
     */
        LayoutXAxisAnchor leading_anchor() const;
        /**
     * @brief Returns the `leftAnchor` property of `NSLayoutGuide`.
     * @return The converted Objective-C result.
     */
        LayoutXAxisAnchor left_anchor() const;
        /**
     * @brief Returns the `owningView` property of `NSLayoutGuide`.
     * @return The converted Objective-C result.
     */
        View owning_view() const;
        /**
     * @brief Sets the `owningView` property of `NSLayoutGuide`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_owning_view(const View& value) const;
        /**
     * @brief Returns the `rightAnchor` property of `NSLayoutGuide`.
     * @return The converted Objective-C result.
     */
        LayoutXAxisAnchor right_anchor() const;
        /**
     * @brief Returns the `topAnchor` property of `NSLayoutGuide`.
     * @return The converted Objective-C result.
     */
        LayoutYAxisAnchor top_anchor() const;
        /**
     * @brief Returns the `trailingAnchor` property of `NSLayoutGuide`.
     * @return The converted Objective-C result.
     */
        LayoutXAxisAnchor trailing_anchor() const;
        /**
     * @brief Returns the `widthAnchor` property of `NSLayoutGuide`.
     * @return The converted Objective-C result.
     */
        LayoutDimension width_anchor() const;
    };
}
