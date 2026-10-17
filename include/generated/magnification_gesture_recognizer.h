#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/gesture_recognizer.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSMagnificationGestureRecognizer` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref GestureRecognizer.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MagnificationGestureRecognizer magnification_gesture_recognizer;
     * magnification_gesture_recognizer.set_magnification(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MagnificationGestureRecognizer magnification_gesture_recognizer{};
     * magnification_gesture_recognizer.set_magnification(1);
     * auto magnification = magnification_gesture_recognizer.magnification();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsmagnificationgesturerecognizer
     */
    class MagnificationGestureRecognizer : public GestureRecognizer
    {
    public:
        /// @brief Creates a new `NSMagnificationGestureRecognizer` instance and returns a handle to it.
        explicit MagnificationGestureRecognizer();
        /// @brief Creates a null handle that refers to no native object.
        MagnificationGestureRecognizer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MagnificationGestureRecognizer(Adopt adopt);
        /**
     * @brief Returns the `magnification` property of `NSMagnificationGestureRecognizer`.
     * @return The converted Objective-C result.
     */
        double magnification() const;
        /**
     * @brief Sets the `magnification` property of `NSMagnificationGestureRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_magnification(double value) const;
    };
}
