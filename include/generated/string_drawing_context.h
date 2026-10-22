#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSStringDrawingContext` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::StringDrawingContext string_drawing_context;
     * string_drawing_context.set_minimum_scale_factor(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::StringDrawingContext string_drawing_context{};
     * string_drawing_context.set_minimum_scale_factor(1);
     * auto minimum_scale_factor = string_drawing_context.minimum_scale_factor();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsstringdrawingcontext
     */
    class StringDrawingContext : public Object
    {
    public:
        /// @brief Creates a new `NSStringDrawingContext` instance and returns a handle to it.
        explicit StringDrawingContext();
        /// @brief Creates a null handle that refers to no native object.
        StringDrawingContext(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit StringDrawingContext(Adopt adopt);
        /**
         * @brief Returns the `actualScaleFactor` property of `NSStringDrawingContext`.
         * @return The converted Objective-C result.
         */
        double actual_scale_factor() const;
        /**
         * @brief Returns the `minimumScaleFactor` property of `NSStringDrawingContext`.
         * @return The converted Objective-C result.
         */
        double minimum_scale_factor() const;
        /**
         * @brief Sets the `minimumScaleFactor` property of `NSStringDrawingContext`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_minimum_scale_factor(double value) const;
        /**
         * @brief Returns the `totalBounds` property of `NSStringDrawingContext`.
         * @return The converted Objective-C result.
         */
        Rect total_bounds() const;
    };
}
