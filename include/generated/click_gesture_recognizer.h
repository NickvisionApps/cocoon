#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/gesture_recognizer.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSClickGestureRecognizer` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref GestureRecognizer.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ClickGestureRecognizer click_gesture_recognizer;
     * click_gesture_recognizer.set_button_mask(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ClickGestureRecognizer click_gesture_recognizer{};
     * click_gesture_recognizer.set_button_mask(1);
     * auto button_mask = click_gesture_recognizer.button_mask();
     * click_gesture_recognizer.set_number_of_clicks_required(1);
     * auto number_of_clicks_required = click_gesture_recognizer.number_of_clicks_required();
     * click_gesture_recognizer.set_number_of_touches_required(1);
     * auto number_of_touches_required = click_gesture_recognizer.number_of_touches_required();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsclickgesturerecognizer
     */
    class ClickGestureRecognizer : public GestureRecognizer
    {
    public:
        /// @brief Creates a new `NSClickGestureRecognizer` instance and returns a handle to it.
        explicit ClickGestureRecognizer();
        /// @brief Creates a null handle that refers to no native object.
        ClickGestureRecognizer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ClickGestureRecognizer(Adopt adopt);
        /**
         * @brief Returns the `buttonMask` property of `NSClickGestureRecognizer`.
         * @details bitfield of the button(s) required to recognize this click where bit 0 is the primary button, 1 is the secondary button, etc... NSClickGestureRecognizer dynamically returns YES to delay primary, secondary and other mouse events depending on this value.
         * @return The converted Objective-C result.
         */
        std::uint64_t button_mask() const;
        /**
         * @brief Sets the `buttonMask` property of `NSClickGestureRecognizer`.
         * @details bitfield of the button(s) required to recognize this click where bit 0 is the primary button, 1 is the secondary button, etc... NSClickGestureRecognizer dynamically returns YES to delay primary, secondary and other mouse events depending on this value.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_button_mask(std::uint64_t value) const;
        /**
         * @brief Returns the `numberOfClicksRequired` property of `NSClickGestureRecognizer`.
         * @details the number of clicks required to match
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_clicks_required() const;
        /**
         * @brief Sets the `numberOfClicksRequired` property of `NSClickGestureRecognizer`.
         * @details the number of clicks required to match
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_number_of_clicks_required(std::int64_t value) const;
        /**
         * @brief Returns the `numberOfTouchesRequired` property of `NSClickGestureRecognizer`.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_touches_required() const;
        /**
         * @brief Sets the `numberOfTouchesRequired` property of `NSClickGestureRecognizer`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_number_of_touches_required(std::int64_t value) const;
    };
}
