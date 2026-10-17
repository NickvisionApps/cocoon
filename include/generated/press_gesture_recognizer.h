#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/gesture_recognizer.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSPressGestureRecognizer` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref GestureRecognizer.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PressGestureRecognizer press_gesture_recognizer;
     * press_gesture_recognizer.set_allowable_movement(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PressGestureRecognizer press_gesture_recognizer{};
     * press_gesture_recognizer.set_allowable_movement(1);
     * auto allowable_movement = press_gesture_recognizer.allowable_movement();
     * press_gesture_recognizer.set_button_mask(1);
     * auto button_mask = press_gesture_recognizer.button_mask();
     * press_gesture_recognizer.set_minimum_press_duration(1);
     * auto minimum_press_duration = press_gesture_recognizer.minimum_press_duration();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspressgesturerecognizer
     */
    class PressGestureRecognizer : public GestureRecognizer
    {
    public:
        /// @brief Creates a new `NSPressGestureRecognizer` instance and returns a handle to it.
        explicit PressGestureRecognizer();
        /// @brief Creates a null handle that refers to no native object.
        PressGestureRecognizer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PressGestureRecognizer(Adopt adopt);
        /**
     * @brief Returns the `allowableMovement` property of `NSPressGestureRecognizer`.
     * @details Maximum movement in screen points allowed before the gesture fails. Once recognized (after minimumPressDuration) there is no limit on cursor movement for the remainder of the gesture tracking
     * @return The converted Objective-C result.
     */
        double allowable_movement() const;
        /**
     * @brief Sets the `allowableMovement` property of `NSPressGestureRecognizer`.
     * @details Maximum movement in screen points allowed before the gesture fails. Once recognized (after minimumPressDuration) there is no limit on cursor movement for the remainder of the gesture tracking
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allowable_movement(double value) const;
        /**
     * @brief Returns the `buttonMask` property of `NSPressGestureRecognizer`.
     * @details bitfield of the button(s) required to recognize this click where bit 0 is the primary button, 1 is the secondary button, etc... NSPressGestureRecognizer dynamically returns YES to delay primary, secondary and other mouse events depending on this value.
     * @return The converted Objective-C result.
     */
        std::uint64_t button_mask() const;
        /**
     * @brief Sets the `buttonMask` property of `NSPressGestureRecognizer`.
     * @details bitfield of the button(s) required to recognize this click where bit 0 is the primary button, 1 is the secondary button, etc... NSPressGestureRecognizer dynamically returns YES to delay primary, secondary and other mouse events depending on this value.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_button_mask(std::uint64_t value) const;
        /**
     * @brief Returns the `minimumPressDuration` property of `NSPressGestureRecognizer`.
     * @details Time in seconds the mouse button must be held down for the gesture to be recognized
     * @return The converted Objective-C result.
     */
        double minimum_press_duration() const;
        /**
     * @brief Sets the `minimumPressDuration` property of `NSPressGestureRecognizer`.
     * @details Time in seconds the mouse button must be held down for the gesture to be recognized
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_press_duration(double value) const;
        /**
     * @brief Returns the `numberOfTouchesRequired` property of `NSPressGestureRecognizer`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_touches_required() const;
        /**
     * @brief Sets the `numberOfTouchesRequired` property of `NSPressGestureRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_number_of_touches_required(std::int64_t value) const;
    };
}
