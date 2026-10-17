#pragma once

#include "generated/enums.h"
#include "generated/gesture_recognizer.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSRotationGestureRecognizer` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref GestureRecognizer.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::RotationGestureRecognizer rotation_gesture_recognizer;
     * rotation_gesture_recognizer.set_rotation(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::RotationGestureRecognizer rotation_gesture_recognizer{};
     * rotation_gesture_recognizer.set_rotation(1);
     * auto rotation = rotation_gesture_recognizer.rotation();
     * rotation_gesture_recognizer.set_rotation_in_degrees(1);
     * auto rotation_in_degrees = rotation_gesture_recognizer.rotation_in_degrees();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsrotationgesturerecognizer
     */
    class RotationGestureRecognizer : public GestureRecognizer
    {
    public:
        /// @brief Creates a new `NSRotationGestureRecognizer` instance and returns a handle to it.
        explicit RotationGestureRecognizer();
        /// @brief Creates a null handle that refers to no native object.
        RotationGestureRecognizer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit RotationGestureRecognizer(Adopt adopt);
        /**
     * @brief Returns the `rotation` property of `NSRotationGestureRecognizer`.
     * @return The converted Objective-C result.
     */
        double rotation() const;
        /**
     * @brief Sets the `rotation` property of `NSRotationGestureRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_rotation(double value) const;
        /**
     * @brief Returns the `rotationInDegrees` property of `NSRotationGestureRecognizer`.
     * @return The converted Objective-C result.
     */
        double rotation_in_degrees() const;
        /**
     * @brief Sets the `rotationInDegrees` property of `NSRotationGestureRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_rotation_in_degrees(double value) const;
    };
}
