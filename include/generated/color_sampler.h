#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Color;

    /**
     * @brief C++ handle for the Objective-C class `NSColorSampler` (AppKit).
     * @details Manages a color sampling interface to allow the user to select a color from their screen.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ColorSampler color_sampler;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscolorsampler
     */
    class ColorSampler : public Object
    {
    public:
        /// @brief Creates a new `NSColorSampler` instance and returns a handle to it.
        explicit ColorSampler();
        /// @brief Creates a null handle that refers to no native object.
        ColorSampler(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ColorSampler(Adopt adopt);
        /**
         * @brief Calls `-[NSColorSampler showSamplerWithSelectionHandler:]`.
         * @details The primary method for NSColorSampler. Begins or attaches to an existing color sampling session which presents UI to the user for selecting a color from their screen. The handler will be called on the main thread when the user completes the session (either by selection, or cancelation). In the event of user-cancellation, 'colorSelectionHandler' will be called with 'nil'. The calling NSColorSampler instance is retained until the sampling session is completed.
         * @param selection_handler Argument converted to the Objective-C parameter of the same role.
         */
        void show_sampler_with_selection_handler(std::function<void(Color)> selection_handler) const;
    };
}
