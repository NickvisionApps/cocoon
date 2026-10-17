#pragma once

#include "generated/enums.h"
#include "generated/gesture_recognizer.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSPanGestureRecognizer` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref GestureRecognizer.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PanGestureRecognizer pan_gesture_recognizer;
     * pan_gesture_recognizer.set_button_mask(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PanGestureRecognizer pan_gesture_recognizer{};
     * pan_gesture_recognizer.set_button_mask(1);
     * auto button_mask = pan_gesture_recognizer.button_mask();
     * pan_gesture_recognizer.set_maximum_number_of_touches(1);
     * auto maximum_number_of_touches = pan_gesture_recognizer.maximum_number_of_touches();
     * pan_gesture_recognizer.set_minimum_number_of_touches(1);
     * auto minimum_number_of_touches = pan_gesture_recognizer.minimum_number_of_touches();
     * pan_gesture_recognizer.set_translation({0, 0}, cocoon::View());
     * pan_gesture_recognizer.translation_in_view(cocoon::View());
     * pan_gesture_recognizer.velocity_in_view(cocoon::View());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspangesturerecognizer
     */
    class PanGestureRecognizer : public GestureRecognizer
    {
    public:
        /// @brief Creates a new `NSPanGestureRecognizer` instance and returns a handle to it.
        explicit PanGestureRecognizer();
        /// @brief Creates a null handle that refers to no native object.
        PanGestureRecognizer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PanGestureRecognizer(Adopt adopt);
        /**
     * @brief Calls `-[NSPanGestureRecognizer setTranslation:inView:]`.
     * @param translation Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     */
        void set_translation(const Point& translation, const View& view) const;
        /**
     * @brief Calls `-[NSPanGestureRecognizer translationInView:]`.
     * @details Translation in the coordinate system of the specified view
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point translation_in_view(const View& view) const;
        /**
     * @brief Calls `-[NSPanGestureRecognizer velocityInView:]`.
     * @details Velocity of the pan in points/second in the coordinate system of the specified view
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point velocity_in_view(const View& view) const;
        /**
     * @brief Returns the `buttonMask` property of `NSPanGestureRecognizer`.
     * @details Bitfield of the button(s) required to recognize this click where bit 0 is the primary button, 1 is the secondary button, etc... NSClickGestureRecognizer.h dynamically returns YES to delay primary, secondary and other mouse events depending on this value.
     * @return The converted Objective-C result.
     */
        std::uint64_t button_mask() const;
        /**
     * @brief Sets the `buttonMask` property of `NSPanGestureRecognizer`.
     * @details Bitfield of the button(s) required to recognize this click where bit 0 is the primary button, 1 is the secondary button, etc... NSClickGestureRecognizer.h dynamically returns YES to delay primary, secondary and other mouse events depending on this value.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_button_mask(std::uint64_t value) const;
        /**
     * @brief Returns the `maximumNumberOfTouches` property of `NSPanGestureRecognizer`.
     * @details The maximum number of touches allowed to recognize this gesture Set this property to 0 to require exactly 'minimumNumberOfTouches' touches to recognize the gesture. Defaults to 'NSIntegerMax'.
     * @return The converted Objective-C result.
     */
        std::int64_t maximum_number_of_touches() const;
        /**
     * @brief Sets the `maximumNumberOfTouches` property of `NSPanGestureRecognizer`.
     * @details The maximum number of touches allowed to recognize this gesture Set this property to 0 to require exactly 'minimumNumberOfTouches' touches to recognize the gesture. Defaults to 'NSIntegerMax'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_number_of_touches(std::int64_t value) const;
        /**
     * @brief Returns the `minimumNumberOfTouches` property of `NSPanGestureRecognizer`.
     * @details The minimum number of touches needed to recognize this gesture Defaults to 1.
     * @return The converted Objective-C result.
     */
        std::int64_t minimum_number_of_touches() const;
        /**
     * @brief Sets the `minimumNumberOfTouches` property of `NSPanGestureRecognizer`.
     * @details The minimum number of touches needed to recognize this gesture Defaults to 1.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_number_of_touches(std::int64_t value) const;
        /**
     * @brief Returns the `numberOfTouchesRequired` property of `NSPanGestureRecognizer`.
     * @details Number of touches required to recognize the gesture when used in NSTouchBar
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_touches_required() const;
        /**
     * @brief Sets the `numberOfTouchesRequired` property of `NSPanGestureRecognizer`.
     * @details Number of touches required to recognize the gesture when used in NSTouchBar
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_number_of_touches_required(std::int64_t value) const;
    };
}
