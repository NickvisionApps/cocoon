#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CGEvent;
    class GraphicsContext;
    class Touch;
    class TrackingArea;
    class View;
    class Window;

    /**
     * @brief C++ handle for the Objective-C class `NSEvent` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Event event;
     * event.set_mouse_coalescing_enabled(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Event event{};
     * event.set_mouse_coalescing_enabled(true);
     * auto mouse_coalescing_enabled = event.is_mouse_coalescing_enabled();
     * auto made_0 = cocoon::Event::key_event_with_type(cocoon::EventType::LeftMouseDown, {0, 0}, cocoon::EventModifierFlags::CapsLock, 1, 1, cocoon::GraphicsContext(), "text", "text", true, 1);
     * auto made_1 = cocoon::Event::mouse_event_with_type(cocoon::EventType::LeftMouseDown, {0, 0}, cocoon::EventModifierFlags::CapsLock, 1, 1, cocoon::GraphicsContext(), 1, 1, 1);
     * event.all_touches();
     * event.characters_by_applying_modifiers(cocoon::EventModifierFlags::CapsLock);
     * event.coalesced_touches_for_touch(cocoon::Touch());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsevent
     */
    class Event : public Object
    {
    public:
        /// @brief Creates a new `NSEvent` instance and returns a handle to it.
        explicit Event();
        /// @brief Creates a null handle that refers to no native object.
        Event(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Event(Adopt adopt);
        /**
     * @brief Calls `+[NSEvent addGlobalMonitorForEventsMatchingMask:handler:]`.
     * @details API for monitoring events in other processes, or in your own process. For either +addGlobal or +addLocal, pass an event mask specifying which events you wish to monitor, and a block that will be called with the event to monitor. Use +addGlobal to install an event monitor that receives copies of events posted to other applications. Events are delivered asynchronously to your app and you can only observe the event; you cannot modify or otherwise prevent the event from being delivered to its original target application. Key-related events may only be monitored if accessibility is enabled or if your application is trusted for accessibility access (see AXIsProcessTrusted in AXUIElement.h). Note that your handler will not be called for events that are sent to your own application. Use +addLocal to install an event monitor that receives events before they are dispatched by -[NSApplication sendEvent:]. In this case, your block should either return a valid NSEvent (which may be the same as the incoming NSEvent, or may be a newly created NSEvent) to cause the event to be dispatched, or it may return nil to stop dispatching of the event. Note that your handler will not be called for events that are consumed by nested event-tracking loops such as control tracking, menu tracking, or window dragging; only events that are dispatched through -[NSApplication sendEvent:] will be passed to your handler. In either case, the return value of the API is a retained NSObject. You typically do not need to retain and release the event monitor yourself, since the implementation will retain it while needed. To remove the event monitor, under both garbage collection and non-GC, pass the return value from the +add API to +removeMonitor.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object add_global_monitor_for_events_matching_mask(EventMask mask, std::function<void(Event)> block);
        /**
     * @brief Calls `+[NSEvent addLocalMonitorForEventsMatchingMask:handler:]`.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object add_local_monitor_for_events_matching_mask(EventMask mask, std::function<Event(Event)> block);
        /**
     * @brief Calls `-[NSEvent allTouches]`.
     * @details Only valid for NSEventTypeGesture events. Equivalent to [event touchesMatchingPhase:NSTouchPhaseAny inView:nil]
     * @return The converted Objective-C result.
     */
        std::vector<Touch> all_touches() const;
        /**
     * @brief Calls `-[NSEvent charactersByApplyingModifiers:]`.
     * @details This message is valid keyup and keydown events. It returns the character(s) that would have been generated if a different modifier combination had been used. It uses [self keyCode], the new modifiers and the current keyboard input source's layout data for re-translation. It entirely ignores the modifiers that are already present in the event and calling this method will not affect the dead key state for current text input. If there is invalid data in this event, -charactersByApplyingModifiers will return nil.
     * @param modifiers Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string characters_by_applying_modifiers(EventModifierFlags modifiers) const;
        /**
     * @brief Calls `-[NSEvent coalescedTouchesForTouch:]`.
     * @details An array of auxiliary NSTouch’s for the touch events that did not get delivered for a given main touch. This also includes an auxiliary version of the main touch itself. Only valid for NSEventTypeDirectTouch events.
     * @param touch Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<Touch> coalesced_touches_for_touch(const Touch& touch) const;
        /**
     * @brief Calls `+[NSEvent enterExitEventWithType:location:modifierFlags:timestamp:windowNumber:context:eventNumber:trackingNumber:userData:]`.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @param flags Argument converted to the Objective-C parameter of the same role.
     * @param time Argument converted to the Objective-C parameter of the same role.
     * @param w_num Argument converted to the Objective-C parameter of the same role.
     * @param unused_pass_nil Argument converted to the Objective-C parameter of the same role.
     * @param e_num Argument converted to the Objective-C parameter of the same role.
     * @param t_num Argument converted to the Objective-C parameter of the same role.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Event enter_exit_event_with_type(EventType type, const Point& location, EventModifierFlags flags, double time, std::int64_t w_num, const GraphicsContext& unused_pass_nil, std::int64_t e_num, std::int64_t t_num, void* data);
        /**
     * @brief Calls `+[NSEvent eventWithCGEvent:]`.
     * @details +eventWithCGEvent: returns an autoreleased NSEvent corresponding to the CGEventRef. The CGEventRef is retained by the NSEvent and will be released when the NSEvent is freed. If there is no NSEvent corresponding to the CGEventRef, +eventWithEventRef will return nil.
     * @param cg_event Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Event event_with_cg_event(const CGEvent& cg_event);
        /**
     * @brief Calls `+[NSEvent eventWithEventRef:]`.
     * @details +eventWithEventRef: returns an autoreleased NSEvent corresponding to the EventRef. The EventRef is retained by the NSEvent and will be released when the NSEvent is freed. If there is no NSEvent corresponding to the EventRef, +eventWithEventRef will return nil.
     * @param event_ref Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Event event_with_event_ref(const void* event_ref);
        /**
     * @brief Calls `+[NSEvent keyEventWithType:location:modifierFlags:timestamp:windowNumber:context:characters:charactersIgnoringModifiers:isARepeat:keyCode:]`.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @param flags Argument converted to the Objective-C parameter of the same role.
     * @param time Argument converted to the Objective-C parameter of the same role.
     * @param w_num Argument converted to the Objective-C parameter of the same role.
     * @param unused_pass_nil Argument converted to the Objective-C parameter of the same role.
     * @param keys Argument converted to the Objective-C parameter of the same role.
     * @param ukeys Argument converted to the Objective-C parameter of the same role.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @param code Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Event key_event_with_type(EventType type, const Point& location, EventModifierFlags flags, double time, std::int64_t w_num, const GraphicsContext& unused_pass_nil, const std::string& keys, const std::string& ukeys, bool flag, std::uint16_t code);
        /**
     * @brief Calls `+[NSEvent mouseEventWithType:location:modifierFlags:timestamp:windowNumber:context:eventNumber:clickCount:pressure:]`.
     * @details apps will rarely create these objects
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @param flags Argument converted to the Objective-C parameter of the same role.
     * @param time Argument converted to the Objective-C parameter of the same role.
     * @param w_num Argument converted to the Objective-C parameter of the same role.
     * @param unused_pass_nil Argument converted to the Objective-C parameter of the same role.
     * @param e_num Argument converted to the Objective-C parameter of the same role.
     * @param c_num Argument converted to the Objective-C parameter of the same role.
     * @param pressure Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Event mouse_event_with_type(EventType type, const Point& location, EventModifierFlags flags, double time, std::int64_t w_num, const GraphicsContext& unused_pass_nil, std::int64_t e_num, std::int64_t c_num, float pressure);
        /**
     * @brief Calls `+[NSEvent otherEventWithType:location:modifierFlags:timestamp:windowNumber:context:subtype:data1:data2:]`.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @param flags Argument converted to the Objective-C parameter of the same role.
     * @param time Argument converted to the Objective-C parameter of the same role.
     * @param w_num Argument converted to the Objective-C parameter of the same role.
     * @param unused_pass_nil Argument converted to the Objective-C parameter of the same role.
     * @param subtype Argument converted to the Objective-C parameter of the same role.
     * @param d1 Argument converted to the Objective-C parameter of the same role.
     * @param d2 Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Event other_event_with_type(EventType type, const Point& location, EventModifierFlags flags, double time, std::int64_t w_num, const GraphicsContext& unused_pass_nil, std::int16_t subtype, std::int64_t d1, std::int64_t d2);
        /**
     * @brief Calls `+[NSEvent removeMonitor:]`.
     * @param event_monitor Argument converted to the Objective-C parameter of the same role.
     */
        static void remove_monitor(const Object& event_monitor);
        /**
     * @brief Calls `+[NSEvent startPeriodicEventsAfterDelay:withPeriod:]`.
     * @details used for initial delay and periodic behavior in tracking loops
     * @param delay Argument converted to the Objective-C parameter of the same role.
     * @param period Argument converted to the Objective-C parameter of the same role.
     */
        static void start_periodic_events_after_delay(double delay, double period);
        /**
     * @brief Calls `+[NSEvent stopPeriodicEvents]`.
     */
        static void stop_periodic_events();
        /**
     * @brief Calls `-[NSEvent touchesForView:]`.
     * @details Only valid for NSEventTypeGesture events. Equivalent to [event touchesMatchingPhase:NSTouchPhaseAny inView:view]
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<Touch> touches_for_view(const View& view) const;
        /**
     * @brief Calls `-[NSEvent touchesMatchingPhase:inView:]`.
     * @param phase Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<Touch> touches_matching_phase(TouchPhase phase, const View& view) const;
        /**
     * @brief Calls `-[NSEvent trackSwipeEventWithOptions:dampenAmountThresholdMin:max:usingHandler:]`.
     * @details This method allows easy tracking and UI feedback of scroll events as fluid swipes. Fluid swipes are tracked not only to the end of the physical gesture phase by the user, but also to the completion of any UI animation that should be performed. Using this method allows your implementation to maintain a consistent fluid feel with other applications. Any gesture amount outside of the supplied minimum and maximum dampen amount is pre-dampened for you to provide an elastic feel. The trackingHandler has the following parameters: gestureAmount: the amount of gesture that you should display in the UI. This may be a fractional amount. Note: Upon completion, the gesture amount will animate to one of the following values: -1, 0, 1. phase: the phase of the physical gesture as performed by the user. When the phase is either NSPhaseEnded, or NSPhaseCancelled, the use has physically ended the gesture successfully or not, respectively. Your handler will continue to be called with updated progress values to complete the fluid swipe animation with a phase of NSPhaseNone. isComplete: Signifies the swipe and animation are complete and you should tear down any temporary animation objects. The trackingHandler is released and will not be called further. stop: A pointer to a BOOL allowing you to cancel further use of this trackingHandler by setting its value to YES. The trackingHandler is released appropriately. Note: This method returns immediately and tracking is performed asynchronously. Valid for Scroll events with a phase of NSEventPhaseBegan or NSEventPhaseChanged
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param min_dampen_threshold Argument converted to the Objective-C parameter of the same role.
     * @param max_dampen_threshold Argument converted to the Objective-C parameter of the same role.
     * @param tracking_handler Argument converted to the Objective-C parameter of the same role.
     */
        void track_swipe_event_with_options(EventSwipeTrackingOptions options, double min_dampen_threshold, double max_dampen_threshold, std::function<void(double, EventPhase, bool, bool&)> tracking_handler) const;
        /**
     * @brief Returns the `ARepeat` property of `NSEvent`.
     * @details the chars that would have been generated, regardless of modifier keys (except shift)
     * @return The converted Objective-C result.
     */
        bool is_a_repeat() const;
        /**
     * @brief Returns the `CGEvent` property of `NSEvent`.
     * @details -CGEvent returns an autoreleased CGEventRef corresponding to the NSEvent. If there is no CGEventRef corresponding to the NSEvent, -CGEvent will return NULL.
     * @return The converted Objective-C result.
     */
        CGEvent cg_event() const;
        /**
     * @brief Returns the `absoluteX` property of `NSEvent`.
     * @details absolute x coordinate in tablet space at full tablet resolution
     * @return The converted Objective-C result.
     */
        std::int64_t absolute_x() const;
        /**
     * @brief Returns the `absoluteY` property of `NSEvent`.
     * @details absolute y coordinate in tablet space at full tablet resolution
     * @return The converted Objective-C result.
     */
        std::int64_t absolute_y() const;
        /**
     * @brief Returns the `absoluteZ` property of `NSEvent`.
     * @details absolute z coordinate in tablet space at full tablet resolution
     * @return The converted Objective-C result.
     */
        std::int64_t absolute_z() const;
        /**
     * @brief Returns the `associatedEventsMask` property of `NSEvent`.
     * @details This message is valid for Mouse events. The event mask describing the various events that you may also get during this event sequence. Useful for determining if the input device issuing this mouse event can also simultaneously issue NSEventTypePressure events.
     * @return The converted Objective-C result.
     */
        EventMask associated_events_mask() const;
        /**
     * @brief Returns the `buttonMask` property of `NSEvent`.
     * @details mask indicating which buttons are pressed.
     * @return The converted Objective-C result.
     */
        EventButtonMask button_mask() const;
        /**
     * @brief Returns the `buttonNumber` property of `NSEvent`.
     * @return The converted Objective-C result.
     */
        std::int64_t button_number() const;
        /**
     * @brief Returns the `capabilityMask` property of `NSEvent`.
     * @details mask representing capabilities of device
     * @return The converted Objective-C result.
     */
        std::uint64_t capability_mask() const;
        /**
     * @brief Returns the `characters` property of `NSEvent`.
     * @details these messages are valid for keyup and keydown events
     * @return The converted Objective-C result.
     */
        std::string characters() const;
        /**
     * @brief Returns the `charactersIgnoringModifiers` property of `NSEvent`.
     * @return The converted Objective-C result.
     */
        std::string characters_ignoring_modifiers() const;
        /**
     * @brief Returns the `clickCount` property of `NSEvent`.
     * @details these messages are valid for all mouse down/up/drag events
     * @return The converted Objective-C result.
     */
        std::int64_t click_count() const;
        /**
     * @brief Returns the `data1` property of `NSEvent`.
     * @details these messages are valid for kit, system, and app-defined events
     * @return The converted Objective-C result.
     */
        std::int64_t data1() const;
        /**
     * @brief Returns the `data2` property of `NSEvent`.
     * @return The converted Objective-C result.
     */
        std::int64_t data2() const;
        /**
     * @brief Returns the `deltaX` property of `NSEvent`.
     * @details these messages are valid for scroll wheel events and mouse move/drag events. As of 10.5.2, deltaX and deltaY are also valid for swipe events. A non-0 deltaX will represent a horizontal swipe, -1 for swipe right and 1 for swipe left. A non-0 deltaY will represent a vertical swipe, -1 for swipe down and 1 for swipe up. As of 10.7, the preferred methods for scroll wheel events are scrollingDeltaX and scrollingDeltaY defined below.
     * @return The converted Objective-C result.
     */
        double delta_x() const;
        /**
     * @brief Returns the `deltaY` property of `NSEvent`.
     * @return The converted Objective-C result.
     */
        double delta_y() const;
        /**
     * @brief Returns the `deltaZ` property of `NSEvent`.
     * @return The converted Objective-C result.
     */
        double delta_z() const;
        /**
     * @brief Returns the `deviceID` property of `NSEvent`.
     * @details this message is valid for mouse events with subtype NSEventSubtypeTabletPoint or NSEventSubtypeTabletProximity, and for NSEventTypeTabletPoint and NSEventTypeTabletProximity events
     * @return The converted Objective-C result.
     */
        std::uint64_t device_id() const;
        /**
     * @brief Returns the `directionInvertedFromDevice` property of `NSEvent`.
     * @details valid for NSEventScrollWheel events. The user may choose to change the scrolling behavior such that it feels like they are moving the content instead of the scroll bar. To accomplish this, deltaX/Y and scrollingDeltaX/Y are automatically inverted for NSEventScrollWheel events according to the user's preferences. However, for some uses, the behavior should not respect the user preference. This method allows you to determine when the event has been inverted and compensate by multiplying -1 if needed.
     * @return The converted Objective-C result.
     */
        bool is_direction_inverted_from_device() const;
        /**
     * @brief Returns the `doubleClickInterval` property of `NSEvent`.
     * @details the time in which a second click must occur in order to be considered a doubleClick. This is a system value so overrides will have no effect.
     * @return The converted Objective-C result.
     */
        static double double_click_interval();
        /**
     * @brief Returns the `enteringProximity` property of `NSEvent`.
     * @details YES - entering; NO - leaving
     * @return The converted Objective-C result.
     */
        bool is_entering_proximity() const;
        /**
     * @brief Returns the `eventNumber` property of `NSEvent`.
     * @details these messages are valid for all mouse down/up/drag and enter/exit events
     * @return The converted Objective-C result.
     */
        std::int64_t event_number() const;
        /**
     * @brief Returns the `eventRef` property of `NSEvent`.
     * @details -eventRef returns an EventRef corresponding to the NSEvent. The EventRef is retained by the NSEvent, so will be valid as long as the NSEvent is valid, and will be released when the NSEvent is freed. You can use RetainEvent to extend the lifetime of the EventRef, with a corresponding ReleaseEvent when you are done with it. If there is no EventRef corresponding to the NSEvent, -eventRef will return NULL.
     * @return The converted Objective-C result.
     */
        const void* event_ref() const;
        /**
     * @brief Returns the `hasPreciseScrollingDeltas` property of `NSEvent`.
     * @details This message is valid for NSEventTypeScrollWheel events. A generic scroll wheel issues rather coarse scroll deltas. Some Apple mice and trackpads provide much more precise delta. This method determines the resolution of the scrollDeltaX and scrollDeltaY values.
     * @return The converted Objective-C result.
     */
        bool has_precise_scrolling_deltas() const;
        /**
     * @brief Returns the `keyCode` property of `NSEvent`.
     * @details this message is valid for keyup, keydown and flagschanged events
     * @return The converted Objective-C result.
     */
        std::uint16_t key_code() const;
        /**
     * @brief Returns the `keyRepeatDelay` property of `NSEvent`.
     * @details the time for which a key must be held down in order to generate the first key repeat event. This is a system value so overrides will have no effect.
     * @return The converted Objective-C result.
     */
        static double key_repeat_delay();
        /**
     * @brief Returns the `keyRepeatInterval` property of `NSEvent`.
     * @details the time between subsequent key repeat events. This is a system value so overrides will have no effect.
     * @return The converted Objective-C result.
     */
        static double key_repeat_interval();
        /**
     * @brief Returns the `locationInWindow` property of `NSEvent`.
     * @details -locationInWindow is valid for all mouse-related events
     * @return The converted Objective-C result.
     */
        Point location_in_window() const;
        /**
     * @brief Returns the `magnification` property of `NSEvent`.
     * @details This message is valid for events of type NSEventTypeMagnify, on 10.5.2 or later
     * @return The converted Objective-C result.
     */
        double magnification() const;
        /**
     * @brief Returns the `modifierFlags` property of `NSEvent`.
     * @return The converted Objective-C result.
     */
        EventModifierFlags modifier_flags() const;
        /**
     * @brief Returns the `momentumPhase` property of `NSEvent`.
     * @details This message is valid for NSEventTypeScrollWheel events. With the Magic Mouse and some trackpads, the user can flick thier finger resulting in a stream of scroll events that dissipate over time. The location of these scroll wheel events changes as the user moves the cursor. AppKit latches these scroll wheel events to the view that is under the cursor when the flick occurs. A custom view can use this method to recognize these momentum scroll events and further route the event to the appropriate sub component.
     * @return The converted Objective-C result.
     */
        EventPhase momentum_phase() const;
        /**
     * @brief Returns the `mouseCoalescingEnabled` property of `NSEvent`.
     * @details Enable or disable coalescing of mouse movement events, including mouse moved, mouse dragged, and tablet events. Coalescing is enabled by default.
     * @return The converted Objective-C result.
     */
        static bool is_mouse_coalescing_enabled();
        /**
     * @brief Sets the `mouseCoalescingEnabled` property of `NSEvent`.
     * @details Enable or disable coalescing of mouse movement events, including mouse moved, mouse dragged, and tablet events. Coalescing is enabled by default.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_mouse_coalescing_enabled(bool value);
        /**
     * @brief Returns the `mouseLocation` property of `NSEvent`.
     * @return The converted Objective-C result.
     */
        static Point mouse_location();
        /**
     * @brief Returns the `phase` property of `NSEvent`.
     * @details The phase of a gesture scroll event. A gesture phrase are all the events that begin with a NSEventPhaseBegan and end with either a NSEventPhaseEnded or NSEventPhaseCancelled. All the gesture events are sent to the view under the cursor when the NSEventPhaseBegan occurred. A gesture scroll event starts with a NSEventPhaseBegan phase and ends with a NSPhaseEnded. Legacy scroll wheel events (say from a Mighty Mouse) and momentum scroll wheel events have a phase of NSEventPhaseNone. Valid for NSEventTypeScrollWheel
     * @return The converted Objective-C result.
     */
        EventPhase phase() const;
        /**
     * @brief Returns the `pointingDeviceID` property of `NSEvent`.
     * @details index of the device on the tablet. Usually 0, except for tablets that support multiple concurrent devices
     * @return The converted Objective-C result.
     */
        std::uint64_t pointing_device_id() const;
        /**
     * @brief Returns the `pointingDeviceSerialNumber` property of `NSEvent`.
     * @details vendor defined serial number of pointing device
     * @return The converted Objective-C result.
     */
        std::uint64_t pointing_device_serial_number() const;
        /**
     * @brief Returns the `pointingDeviceType` property of `NSEvent`.
     * @details mask representing capabilities of device
     * @return The converted Objective-C result.
     */
        PointingDeviceType pointing_device_type() const;
        /**
     * @brief Returns the `pressedMouseButtons` property of `NSEvent`.
     * @details mouse buttons currently down. Returns indices of the mouse buttons currently down. 1 \<\< 0 corresponds to leftMouse, 1 \<\< 1 to rightMouse, and 1 \<\< n, n >= 2 to other mouse buttons. This returns the state of devices combined with synthesized events at the moment, independent of which events have been delivered via the event stream, so this method is not suitable for tracking.
     * @return The converted Objective-C result.
     */
        static std::uint64_t pressed_mouse_buttons();
        /**
     * @brief Returns the `pressure` property of `NSEvent`.
     * @details -pressure is valid for all mouse down/up/drag events, and is also valid for NSEventTypeTabletPoint events on 10.4 or later and NSEventTypePressure on 10.10.3 or later
     * @return The converted Objective-C result.
     */
        float pressure() const;
        /**
     * @brief Returns the `pressureBehavior` property of `NSEvent`.
     * @details this message is valid for NSEventTypePressure events
     * @return The converted Objective-C result.
     */
        PressureBehavior pressure_behavior() const;
        /**
     * @brief Returns the `rotation` property of `NSEvent`.
     * @details this message is valid for valid for mouse events with subtype NSEventSubtypeTabletPoint, and for NSEventTypeTabletPoint events. On 10.5.2 or later, it is also valid for NSEventTypeRotate events.
     * @return The converted Objective-C result.
     */
        float rotation() const;
        /**
     * @brief Returns the `scrollingDeltaX` property of `NSEvent`.
     * @details The following two message are the preferred API for accessing NSEventTypeScrollWheel deltas. When -hasPreciseScrollingDeltas reutrns NO, multiply the returned value by line or row height. When -hasPreciseScrollingDeltas returns YES, scroll by the returned value (in points).
     * @return The converted Objective-C result.
     */
        double scrolling_delta_x() const;
        /**
     * @brief Returns the `scrollingDeltaY` property of `NSEvent`.
     * @return The converted Objective-C result.
     */
        double scrolling_delta_y() const;
        /**
     * @brief Returns the `stage` property of `NSEvent`.
     * @details This message is valid for NSEventTypePressure events. Pressure gesture events go through multiple stages.
     * @return The converted Objective-C result.
     */
        std::int64_t stage() const;
        /**
     * @brief Returns the `stageTransition` property of `NSEvent`.
     * @details This message is valid for NSEventTypePressure events. Positive stageTransition describes approaching the next stage of the pressure gesture. Negative stageTransition describes approaching release of the current stage.
     * @return The converted Objective-C result.
     */
        double stage_transition() const;
        /**
     * @brief Returns the `subtype` property of `NSEvent`.
     * @details this message is also valid for mouse events on 10.4 or later
     * @return The converted Objective-C result.
     */
        EventSubtype subtype() const;
        /**
     * @brief Returns the `swipeTrackingFromScrollEventsEnabled` property of `NSEvent`.
     * @details Returns the user's preference about using gesture scrolls as a way to track fluid swipes. This value is determined by the Mouse / Trackpad preference panel for the current user. Generally, NSScrollView will check this for you. However, if your app is not using an NSScrollView, or your NSResponder can receive scrollWheel messages without first being sent to an NSScrollView, then you should check this preference before calling -trackSwipeEventWithOptions:dampenAmountThresholdMin:max:usingHandler:
     * @return The converted Objective-C result.
     */
        static bool is_swipe_tracking_from_scroll_events_enabled();
        /**
     * @brief Returns the `systemTabletID` property of `NSEvent`.
     * @details system assigned unique tablet ID
     * @return The converted Objective-C result.
     */
        std::uint64_t system_tablet_id() const;
        /**
     * @brief Returns the `tabletID` property of `NSEvent`.
     * @details vendor defined tablet ID
     * @return The converted Objective-C result.
     */
        std::uint64_t tablet_id() const;
        /**
     * @brief Returns the `tangentialPressure` property of `NSEvent`.
     * @details tangential pressure on the device; range is -1 to 1
     * @return The converted Objective-C result.
     */
        float tangential_pressure() const;
        /**
     * @brief Returns the `tilt` property of `NSEvent`.
     * @details range is -1 to 1 for both axes
     * @return The converted Objective-C result.
     */
        Point tilt() const;
        /**
     * @brief Returns the `timestamp` property of `NSEvent`.
     * @return The converted Objective-C result.
     */
        double timestamp() const;
        /**
     * @brief Returns the `trackingArea` property of `NSEvent`.
     * @details -trackingArea returns the NSTrackingArea that generated this event. It is possible for there to be no trackingArea associated with the event in some cases where the event corresponds to a trackingRect installed with -[NSView addTrackingRect:owner:userData:assumeInside:], in which case nil is returned.
     * @return The converted Objective-C result.
     */
        TrackingArea tracking_area() const;
        /**
     * @brief Returns the `trackingNumber` property of `NSEvent`.
     * @details these messages are valid for enter and exit events
     * @return The converted Objective-C result.
     */
        std::int64_t tracking_number() const;
        /**
     * @brief Returns the `type` property of `NSEvent`.
     * @details these messages are valid for all events
     * @return The converted Objective-C result.
     */
        EventType type() const;
        /**
     * @brief Returns the `uniqueID` property of `NSEvent`.
     * @details vendor defined unique ID
     * @return The converted Objective-C result.
     */
        std::uint64_t unique_id() const;
        /**
     * @brief Returns the `userData` property of `NSEvent`.
     * @return The converted Objective-C result.
     */
        void* user_data() const;
        /**
     * @brief Returns the `vendorDefined` property of `NSEvent`.
     * @details NSArray of 3 vendor defined shorts
     * @return The converted Objective-C result.
     */
        Object vendor_defined() const;
        /**
     * @brief Returns the `vendorID` property of `NSEvent`.
     * @details vendor defined, typically USB vendor ID
     * @return The converted Objective-C result.
     */
        std::uint64_t vendor_id() const;
        /**
     * @brief Returns the `vendorPointingDeviceType` property of `NSEvent`.
     * @details vendor defined pointing device type
     * @return The converted Objective-C result.
     */
        std::uint64_t vendor_pointing_device_type() const;
        /**
     * @brief Returns the `window` property of `NSEvent`.
     * @return The converted Objective-C result.
     */
        Window window() const;
        /**
     * @brief Returns the `windowNumber` property of `NSEvent`.
     * @return The converted Objective-C result.
     */
        std::int64_t window_number() const;
    };
}
