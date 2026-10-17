#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Event;
    class PressureConfiguration;
    class Touch;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSGestureRecognizer` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::GestureRecognizer gesture_recognizer;
     * gesture_recognizer.set_action("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::GestureRecognizer gesture_recognizer{};
     * gesture_recognizer.set_action("text");
     * auto action = gesture_recognizer.action();
     * gesture_recognizer.set_allowed_touch_types(cocoon::TouchTypeMask::Direct);
     * auto allowed_touch_types = gesture_recognizer.allowed_touch_types();
     * gesture_recognizer.set_cancellable_by_scroll_gesture(true);
     * auto cancellable_by_scroll_gesture = gesture_recognizer.is_cancellable_by_scroll_gesture();
     * gesture_recognizer.can_be_prevented_by_gesture_recognizer(cocoon::GestureRecognizer());
     * gesture_recognizer.can_prevent_gesture_recognizer(cocoon::GestureRecognizer());
     * gesture_recognizer.flags_changed(cocoon::Event());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsgesturerecognizer
     */
    class GestureRecognizer : public Object
    {
    public:
        /// @brief Creates a new `NSGestureRecognizer` instance and returns a handle to it.
        explicit GestureRecognizer(const Object& target, const std::string& action);
        /// @brief Creates a new `NSGestureRecognizer` instance and returns a handle to it.
        explicit GestureRecognizer();
        /// @brief Creates a null handle that refers to no native object.
        GestureRecognizer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit GestureRecognizer(Adopt adopt);
        /**
     * @brief Calls `-[NSGestureRecognizer canBePreventedByGestureRecognizer:]`.
     * @param preventing_gesture_recognizer Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool can_be_prevented_by_gesture_recognizer(const GestureRecognizer& preventing_gesture_recognizer) const;
        /**
     * @brief Calls `-[NSGestureRecognizer canPreventGestureRecognizer:]`.
     * @param prevented_gesture_recognizer Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool can_prevent_gesture_recognizer(const GestureRecognizer& prevented_gesture_recognizer) const;
        /**
     * @brief Calls `-[NSGestureRecognizer flagsChanged:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void flags_changed(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer keyDown:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void key_down(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer keyUp:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void key_up(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer locationInView:]`.
     * @details individual NSGestureRecognizer subclasses may provide subclass-specific location information. see individual subclasses for details. Note that locationInView: is only set after the recognizer starts recognizing events, so for example it is not valid to consult locationInView: from gestureRecognizer:shouldAttemptToRecognizeWithEvent: or gestureRecognizer:shouldReceiveTouch:, but it is valid for gestureRecognizerShouldBegin:
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point location_in_view(const View& view) const;
        /**
     * @brief Calls `-[NSGestureRecognizer magnifyWithEvent:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void magnify_with_event(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer mouseCancelled:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void mouse_cancelled(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer mouseDown:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void mouse_down(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer mouseDragged:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void mouse_dragged(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer mouseUp:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void mouse_up(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer otherMouseDown:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void other_mouse_down(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer otherMouseDragged:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void other_mouse_dragged(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer otherMouseUp:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void other_mouse_up(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer pressureChangeWithEvent:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void pressure_change_with_event(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer reset]`.
     */
        void reset() const;
        /**
     * @brief Calls `-[NSGestureRecognizer rightMouseDown:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void right_mouse_down(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer rightMouseDragged:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void right_mouse_dragged(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer rightMouseUp:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void right_mouse_up(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer rotateWithEvent:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void rotate_with_event(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer shouldBeRequiredToFailByGestureRecognizer:]`.
     * @param other_gesture_recognizer Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool should_be_required_to_fail_by_gesture_recognizer(const GestureRecognizer& other_gesture_recognizer) const;
        /**
     * @brief Calls `-[NSGestureRecognizer shouldRequireFailureOfGestureRecognizer:]`.
     * @param other_gesture_recognizer Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool should_require_failure_of_gesture_recognizer(const GestureRecognizer& other_gesture_recognizer) const;
        /**
     * @brief Calls `-[NSGestureRecognizer tabletPoint:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void tablet_point(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer touchesBeganWithEvent:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void touches_began_with_event(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer touchesCancelledWithEvent:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void touches_cancelled_with_event(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer touchesEndedWithEvent:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void touches_ended_with_event(const Event& event) const;
        /**
     * @brief Calls `-[NSGestureRecognizer touchesMovedWithEvent:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void touches_moved_with_event(const Event& event) const;
        /**
     * @brief Returns the `action` property of `NSGestureRecognizer`.
     * @return The converted Objective-C result.
     */
        std::string action() const;
        /**
     * @brief Sets the `action` property of `NSGestureRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_action(const std::string& value) const;
        /**
     * @brief Returns the `allowedTouchTypes` property of `NSGestureRecognizer`.
     * @details Currently, only NSTouchTypeDirect is supported. Defaults to NSTouchTypeDirect as of macOS 27, and 0 on earlier releases.
     * @return The converted Objective-C result.
     */
        TouchTypeMask allowed_touch_types() const;
        /**
     * @brief Sets the `allowedTouchTypes` property of `NSGestureRecognizer`.
     * @details Currently, only NSTouchTypeDirect is supported. Defaults to NSTouchTypeDirect as of macOS 27, and 0 on earlier releases.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allowed_touch_types(TouchTypeMask value) const;
#ifdef COCOON_MACOS_27
        /**
     * @brief Returns the `cancellableByScrollGesture` property of `NSGestureRecognizer`.
     * @details Causes the receiver to be cancelled when its enclosing scroll view's gesture recognizer begins. Defaults to 'false'.
     * @return The converted Objective-C result.
     */
        bool is_cancellable_by_scroll_gesture() const;
#endif
#ifdef COCOON_MACOS_27
        /**
     * @brief Sets the `cancellableByScrollGesture` property of `NSGestureRecognizer`.
     * @details Causes the receiver to be cancelled when its enclosing scroll view's gesture recognizer begins. Defaults to 'false'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_cancellable_by_scroll_gesture(bool value) const;
#endif
        /**
     * @brief Returns the `delaysKeyEvents` property of `NSGestureRecognizer`.
     * @return The converted Objective-C result.
     */
        bool delays_key_events() const;
        /**
     * @brief Sets the `delaysKeyEvents` property of `NSGestureRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_delays_key_events(bool value) const;
        /**
     * @brief Returns the `delaysMagnificationEvents` property of `NSGestureRecognizer`.
     * @return The converted Objective-C result.
     */
        bool delays_magnification_events() const;
        /**
     * @brief Sets the `delaysMagnificationEvents` property of `NSGestureRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_delays_magnification_events(bool value) const;
        /**
     * @brief Returns the `delaysOtherMouseButtonEvents` property of `NSGestureRecognizer`.
     * @return The converted Objective-C result.
     */
        bool delays_other_mouse_button_events() const;
        /**
     * @brief Sets the `delaysOtherMouseButtonEvents` property of `NSGestureRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_delays_other_mouse_button_events(bool value) const;
        /**
     * @brief Returns the `delaysPrimaryMouseButtonEvents` property of `NSGestureRecognizer`.
     * @details causes the specified events to be delivered to the target view only after this gesture has failed recognition. set to YES to prevent views from processing any events that may be recognized as part of this gesture. note: once a gesture recognizer starts delaying one type of event, all event types are delayed until this gesture has failed recognition. refer to specific gesture subclasses as they have different defaults.
     * @return The converted Objective-C result.
     */
        bool delays_primary_mouse_button_events() const;
        /**
     * @brief Sets the `delaysPrimaryMouseButtonEvents` property of `NSGestureRecognizer`.
     * @details causes the specified events to be delivered to the target view only after this gesture has failed recognition. set to YES to prevent views from processing any events that may be recognized as part of this gesture. note: once a gesture recognizer starts delaying one type of event, all event types are delayed until this gesture has failed recognition. refer to specific gesture subclasses as they have different defaults.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_delays_primary_mouse_button_events(bool value) const;
        /**
     * @brief Returns the `delaysRotationEvents` property of `NSGestureRecognizer`.
     * @return The converted Objective-C result.
     */
        bool delays_rotation_events() const;
        /**
     * @brief Sets the `delaysRotationEvents` property of `NSGestureRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_delays_rotation_events(bool value) const;
        /**
     * @brief Returns the `delaysSecondaryMouseButtonEvents` property of `NSGestureRecognizer`.
     * @return The converted Objective-C result.
     */
        bool delays_secondary_mouse_button_events() const;
        /**
     * @brief Sets the `delaysSecondaryMouseButtonEvents` property of `NSGestureRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_delays_secondary_mouse_button_events(bool value) const;
        /**
     * @brief Returns the `enabled` property of `NSGestureRecognizer`.
     * @details default is YES. disabled gesture recognizers will not receive events. when changed to NO the gesture recognizer will be cancelled if it's currently recognizing a gesture
     * @return The converted Objective-C result.
     */
        bool is_enabled() const;
        /**
     * @brief Sets the `enabled` property of `NSGestureRecognizer`.
     * @details default is YES. disabled gesture recognizers will not receive events. when changed to NO the gesture recognizer will be cancelled if it's currently recognizing a gesture
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_enabled(bool value) const;
        /**
     * @brief Returns the `modifierFlags` property of `NSGestureRecognizer`.
     * @return The converted Objective-C result.
     */
        EventModifierFlags modifier_flags() const;
        /**
     * @brief Returns the `name` property of `NSGestureRecognizer`.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Sets the `name` property of `NSGestureRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_name(const std::string& value) const;
        /**
     * @brief Returns the `pressureConfiguration` property of `NSGestureRecognizer`.
     * @details The pressure configuration the view should use when this recognizer is eligible for recognition. At any point in time during recognition the view's effective pressure configuration will be the most compatible configuration among the set of active recognizers. This property may be set at any time before or during recognition. If recognition fails, the effective configuration will revert to the view's -pressureConfiguration.
     * @return The converted Objective-C result.
     */
        PressureConfiguration pressure_configuration() const;
        /**
     * @brief Sets the `pressureConfiguration` property of `NSGestureRecognizer`.
     * @details The pressure configuration the view should use when this recognizer is eligible for recognition. At any point in time during recognition the view's effective pressure configuration will be the most compatible configuration among the set of active recognizers. This property may be set at any time before or during recognition. If recognition fails, the effective configuration will revert to the view's -pressureConfiguration.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_pressure_configuration(const PressureConfiguration& value) const;
        /**
     * @brief Returns the `state` property of `NSGestureRecognizer`.
     * @return The converted Objective-C result.
     */
        GestureRecognizerState state() const;
        /**
     * @brief Sets the `state` property of `NSGestureRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_state(GestureRecognizerState value) const;
        /**
     * @brief Returns the `target` property of `NSGestureRecognizer`.
     * @return The converted Objective-C result.
     */
        Object target() const;
        /**
     * @brief Sets the `target` property of `NSGestureRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_target(const Object& value) const;
        /**
     * @brief Returns the `view` property of `NSGestureRecognizer`.
     * @details an NSGestureRecognizer receives events hit-tested to its view and any of that view's subviews the view the gesture is attached to. set by adding the recognizer to a NSView using the addGestureRecognizer: method
     * @return The converted Objective-C result.
     */
        View view() const;
        /// @brief Signal for the delegate/data-source method behind `should_attempt_to_recognize_with_event`; connect a callback with `should_attempt_to_recognize_with_event().connect(...)`.
        Signal<GestureRecognizer, bool(Event)> should_attempt_to_recognize_with_event() const
        {
            return Signal<GestureRecognizer, bool(Event)>(handle(), "should_attempt_to_recognize_with_event");
        }
        /// @brief Signal for the delegate/data-source method behind `should_begin`; connect a callback with `should_begin().connect(...)`.
        Signal<GestureRecognizer, bool()> should_begin() const
        {
            return Signal<GestureRecognizer, bool()>(handle(), "should_begin");
        }
        /// @brief Signal for the delegate/data-source method behind `should_recognize_simultaneously_with_gesture_recognizer`; connect a callback with `should_recognize_simultaneously_with_gesture_recognizer().connect(...)`.
        Signal<GestureRecognizer, bool(GestureRecognizer)> should_recognize_simultaneously_with_gesture_recognizer() const
        {
            return Signal<GestureRecognizer, bool(GestureRecognizer)>(handle(), "should_recognize_simultaneously_with_gesture_recognizer");
        }
        /// @brief Signal for the delegate/data-source method behind `gesture_recognizer_should_require_failure_of_gesture_recognizer`; connect a callback with `gesture_recognizer_should_require_failure_of_gesture_recognizer().connect(...)`.
        Signal<GestureRecognizer, bool(GestureRecognizer)> gesture_recognizer_should_require_failure_of_gesture_recognizer() const
        {
            return Signal<GestureRecognizer, bool(GestureRecognizer)>(handle(), "gesture_recognizer_should_require_failure_of_gesture_recognizer");
        }
        /// @brief Signal for the delegate/data-source method behind `gesture_recognizer_should_be_required_to_fail_by_gesture_recognizer`; connect a callback with `gesture_recognizer_should_be_required_to_fail_by_gesture_recognizer().connect(...)`.
        Signal<GestureRecognizer, bool(GestureRecognizer)> gesture_recognizer_should_be_required_to_fail_by_gesture_recognizer() const
        {
            return Signal<GestureRecognizer, bool(GestureRecognizer)>(handle(), "gesture_recognizer_should_be_required_to_fail_by_gesture_recognizer");
        }
        /// @brief Signal for the delegate/data-source method behind `should_receive_touch`; connect a callback with `should_receive_touch().connect(...)`.
        Signal<GestureRecognizer, bool(Touch)> should_receive_touch() const
        {
            return Signal<GestureRecognizer, bool(Touch)>(handle(), "should_receive_touch");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
