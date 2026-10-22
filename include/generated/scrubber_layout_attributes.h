#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSScrubberLayoutAttributes` (AppKit).
     * @details \@class NSScrubberLayoutAttributes \@abstract \@c NSScrubberLayoutAttributes describes the layout of a single \@c NSScrubber item. \@discussion \@c NSScrubberLayout objects transact in terms of \@c NSScrubberLayoutAttributes. \@c NSScrubberLayoutAttributes can be subclassed if a layout object wants to include more layout information than the base implementation provides. Subclasses of \@c NSScrubberLayoutAttributes must implement \@c isEqual:, \@c hash, and the \@c NSCopying protocol.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScrubberLayoutAttributes scrubber_layout_attributes;
     * scrubber_layout_attributes.set_alpha(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScrubberLayoutAttributes scrubber_layout_attributes{};
     * scrubber_layout_attributes.set_alpha(1);
     * auto alpha = scrubber_layout_attributes.alpha();
     * scrubber_layout_attributes.set_frame({{0, 0}, {100, 100}});
     * auto frame = scrubber_layout_attributes.frame();
     * scrubber_layout_attributes.set_item_index(1);
     * auto item_index = scrubber_layout_attributes.item_index();
     * auto made_0 = cocoon::ScrubberLayoutAttributes::layout_attributes_for_item_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsscrubberlayoutattributes
     */
    class ScrubberLayoutAttributes : public Object
    {
    public:
        /// @brief Creates a new `NSScrubberLayoutAttributes` instance and returns a handle to it.
        explicit ScrubberLayoutAttributes();
        /// @brief Creates a null handle that refers to no native object.
        ScrubberLayoutAttributes(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScrubberLayoutAttributes(Adopt adopt);
        /**
         * @brief Calls `+[NSScrubberLayoutAttributes layoutAttributesForItemAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static ScrubberLayoutAttributes layout_attributes_for_item_at_index(std::int64_t index);
        /**
         * @brief Returns the `alpha` property of `NSScrubberLayoutAttributes`.
         * @return The converted Objective-C result.
         */
        double alpha() const;
        /**
         * @brief Sets the `alpha` property of `NSScrubberLayoutAttributes`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_alpha(double value) const;
        /**
         * @brief Returns the `frame` property of `NSScrubberLayoutAttributes`.
         * @return The converted Objective-C result.
         */
        Rect frame() const;
        /**
         * @brief Sets the `frame` property of `NSScrubberLayoutAttributes`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_frame(const Rect& value) const;
        /**
         * @brief Returns the `itemIndex` property of `NSScrubberLayoutAttributes`.
         * @return The converted Objective-C result.
         */
        std::int64_t item_index() const;
        /**
         * @brief Sets the `itemIndex` property of `NSScrubberLayoutAttributes`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_item_index(std::int64_t value) const;
    };
}
