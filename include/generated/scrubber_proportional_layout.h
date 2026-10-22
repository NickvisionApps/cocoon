#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/scrubber_layout.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSScrubberProportionalLayout` (AppKit).
     * @details \@class NSScrubberProportionalLayout \@abstract \@c NSScrubberProportionalLayout is a concrete layout object that sizes each item to some fraction of the scrubber's visible size.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScrubberLayout.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScrubberProportionalLayout scrubber_proportional_layout;
     * scrubber_proportional_layout.set_number_of_visible_items(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScrubberProportionalLayout scrubber_proportional_layout{};
     * scrubber_proportional_layout.set_number_of_visible_items(1);
     * auto number_of_visible_items = scrubber_proportional_layout.number_of_visible_items();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsscrubberproportionallayout
     */
    class ScrubberProportionalLayout : public ScrubberLayout
    {
    public:
        /// @brief Creates a new `NSScrubberProportionalLayout` instance and returns a handle to it.
        explicit ScrubberProportionalLayout(std::int64_t number_of_visible_items);
        /// @brief Creates a new `NSScrubberProportionalLayout` instance and returns a handle to it.
        explicit ScrubberProportionalLayout();
        /// @brief Creates a null handle that refers to no native object.
        ScrubberProportionalLayout(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScrubberProportionalLayout(Adopt adopt);
        /**
         * @brief Returns the `numberOfVisibleItems` property of `NSScrubberProportionalLayout`.
         * @details The number of items that should fit within the scrubber's viewport at once.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_visible_items() const;
        /**
         * @brief Sets the `numberOfVisibleItems` property of `NSScrubberProportionalLayout`.
         * @details The number of items that should fit within the scrubber's viewport at once.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_number_of_visible_items(std::int64_t value) const;
    };
}
