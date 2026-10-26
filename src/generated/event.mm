#include "generated/event.h"
#include "internal.h"

namespace cocoon
{
    Event::Event(const CGEvent& cg_event) : Event(Adopt{cocoon::internal::retain([::NSEvent eventWithCGEvent:((::CGEventRef)(cg_event).handle())])})
    {
    }

    Event::Event(const void* event_ref) : Event(Adopt{cocoon::internal::retain([::NSEvent eventWithEventRef:event_ref])})
    {
    }

    Event::Event() : Event(Adopt{cocoon::internal::retain([[::NSEvent alloc] init])})
    {
    }

    Event::Event(std::nullptr_t) : Object(nullptr)
    {
    }

    Event::Event(Adopt adopt) : Object(adopt)
    {
    }

    Object Event::add_global_monitor_for_events_matching_mask(EventMask mask, std::function<void(Event)> block)
    {
        return cocoon::internal::wrap<Object>([::NSEvent addGlobalMonitorForEventsMatchingMask:static_cast<::NSEventMask>(mask) handler:(block ? (void (^)(::NSEvent*)) ^ void(::NSEvent * a57_0) { block(cocoon::internal::wrap<Event>(a57_0)); } : (void (^)(::NSEvent*))nil)]);
    }

    Object Event::add_local_monitor_for_events_matching_mask(EventMask mask, std::function<Event(Event)> block)
    {
        return cocoon::internal::wrap<Object>([::NSEvent addLocalMonitorForEventsMatchingMask:static_cast<::NSEventMask>(mask) handler:(block ? (::NSEvent * (^)(::NSEvent*)) ^ ::NSEvent * (::NSEvent * a58_0) { auto __r = block(cocoon::internal::wrap<Event>(a58_0)); return cocoon::internal::native<::NSEvent>(__r); } : (::NSEvent * (^)(::NSEvent*)) nil)]);
    }

    std::vector<Touch> Event::all_touches() const
    {
        return cocoon::internal::from_array<Touch>([[cocoon::internal::ns<::NSEvent>(this) allTouches] allObjects], [](id e) -> Touch
                                                   {
                                                       return cocoon::internal::wrap<Touch>((::NSTouch*)e);
                                                   });
    }

    std::string Event::characters_by_applying_modifiers(EventModifierFlags modifiers) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSEvent>(this) charactersByApplyingModifiers:static_cast<::NSEventModifierFlags>(modifiers)]);
    }

    std::vector<Touch> Event::coalesced_touches_for_touch(const Touch& touch) const
    {
        return cocoon::internal::from_array<Touch>([cocoon::internal::ns<::NSEvent>(this) coalescedTouchesForTouch:cocoon::internal::native<::NSTouch>(touch)], [](id e) -> Touch
                                                   {
                                                       return cocoon::internal::wrap<Touch>((::NSTouch*)e);
                                                   });
    }

    Event Event::enter_exit_event_with_type(EventType type, const Point& location, EventModifierFlags flags, double time, std::int64_t w_num, const GraphicsContext& unused_pass_nil, std::int64_t e_num, std::int64_t t_num, void* data)
    {
        return cocoon::internal::wrap<Event>([::NSEvent enterExitEventWithType:static_cast<::NSEventType>(type) location:cocoon::internal::to(location) modifierFlags:static_cast<::NSEventModifierFlags>(flags) timestamp:static_cast<::NSTimeInterval>(time) windowNumber:static_cast<::NSInteger>(w_num) context:cocoon::internal::native<::NSGraphicsContext>(unused_pass_nil) eventNumber:static_cast<::NSInteger>(e_num) trackingNumber:static_cast<::NSInteger>(t_num) userData:data]);
    }

    Event Event::key_event_with_type(EventType type, const Point& location, EventModifierFlags flags, double time, std::int64_t w_num, const GraphicsContext& unused_pass_nil, const std::string& keys, const std::string& ukeys, bool flag, std::uint16_t code)
    {
        return cocoon::internal::wrap<Event>([::NSEvent keyEventWithType:static_cast<::NSEventType>(type) location:cocoon::internal::to(location) modifierFlags:static_cast<::NSEventModifierFlags>(flags) timestamp:static_cast<::NSTimeInterval>(time) windowNumber:static_cast<::NSInteger>(w_num) context:cocoon::internal::native<::NSGraphicsContext>(unused_pass_nil) characters:cocoon::internal::to(keys) charactersIgnoringModifiers:cocoon::internal::to(ukeys) isARepeat:static_cast<::BOOL>(flag) keyCode:static_cast<unsigned short>(code)]);
    }

    Event Event::mouse_event_with_type(EventType type, const Point& location, EventModifierFlags flags, double time, std::int64_t w_num, const GraphicsContext& unused_pass_nil, std::int64_t e_num, std::int64_t c_num, float pressure)
    {
        return cocoon::internal::wrap<Event>([::NSEvent mouseEventWithType:static_cast<::NSEventType>(type) location:cocoon::internal::to(location) modifierFlags:static_cast<::NSEventModifierFlags>(flags) timestamp:static_cast<::NSTimeInterval>(time) windowNumber:static_cast<::NSInteger>(w_num) context:cocoon::internal::native<::NSGraphicsContext>(unused_pass_nil) eventNumber:static_cast<::NSInteger>(e_num) clickCount:static_cast<::NSInteger>(c_num) pressure:static_cast<float>(pressure)]);
    }

    Event Event::other_event_with_type(EventType type, const Point& location, EventModifierFlags flags, double time, std::int64_t w_num, const GraphicsContext& unused_pass_nil, std::int16_t subtype, std::int64_t d1, std::int64_t d2)
    {
        return cocoon::internal::wrap<Event>([::NSEvent otherEventWithType:static_cast<::NSEventType>(type) location:cocoon::internal::to(location) modifierFlags:static_cast<::NSEventModifierFlags>(flags) timestamp:static_cast<::NSTimeInterval>(time) windowNumber:static_cast<::NSInteger>(w_num) context:cocoon::internal::native<::NSGraphicsContext>(unused_pass_nil) subtype:static_cast<short>(subtype) data1:static_cast<::NSInteger>(d1) data2:static_cast<::NSInteger>(d2)]);
    }

    void Event::remove_monitor(const Object& event_monitor)
    {
        [::NSEvent removeMonitor:cocoon::internal::native_id(event_monitor)];
    }

    void Event::start_periodic_events_after_delay(double delay, double period)
    {
        [::NSEvent startPeriodicEventsAfterDelay:static_cast<::NSTimeInterval>(delay) withPeriod:static_cast<::NSTimeInterval>(period)];
    }

    void Event::stop_periodic_events()
    {
        [::NSEvent stopPeriodicEvents];
    }

    std::vector<Touch> Event::touches_for_view(const View& view) const
    {
        return cocoon::internal::from_array<Touch>([[cocoon::internal::ns<::NSEvent>(this) touchesForView:cocoon::internal::native<::NSView>(view)] allObjects], [](id e) -> Touch
                                                   {
                                                       return cocoon::internal::wrap<Touch>((::NSTouch*)e);
                                                   });
    }

    std::vector<Touch> Event::touches_matching_phase(TouchPhase phase, const View& view) const
    {
        return cocoon::internal::from_array<Touch>([[cocoon::internal::ns<::NSEvent>(this) touchesMatchingPhase:static_cast<::NSTouchPhase>(phase) inView:cocoon::internal::native<::NSView>(view)] allObjects], [](id e) -> Touch
                                                   {
                                                       return cocoon::internal::wrap<Touch>((::NSTouch*)e);
                                                   });
    }

    void Event::track_swipe_event_with_options(EventSwipeTrackingOptions options, double min_dampen_threshold, double max_dampen_threshold, std::function<void(double, EventPhase, bool, bool&)> tracking_handler) const
    {
        [cocoon::internal::ns<::NSEvent>(this) trackSwipeEventWithOptions:static_cast<::NSEventSwipeTrackingOptions>(options) dampenAmountThresholdMin:static_cast<::CGFloat>(min_dampen_threshold) max:static_cast<::CGFloat>(max_dampen_threshold) usingHandler:(tracking_handler ? (void (^)(::CGFloat, ::NSEventPhase, BOOL, BOOL*)) ^ void(::CGFloat a59_0, ::NSEventPhase a59_1, ::BOOL a59_2, ::BOOL * a59_3) { bool __o59_3 = a59_3 ? static_cast<bool>(*a59_3) : bool(); tracking_handler(static_cast<double>(a59_0), static_cast<EventPhase>(a59_1), static_cast<bool>(a59_2), __o59_3); if (a59_3) { *a59_3 = static_cast<::BOOL>(__o59_3); } } : (void (^)(::CGFloat, ::NSEventPhase, BOOL, BOOL*))nil)];
    }

    bool Event::is_a_repeat() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSEvent>(this) isARepeat]);
    }

    CGEvent Event::cg_event() const
    {
        return cocoon::internal::wrap_cf<CGEvent>((const void*)([cocoon::internal::ns<::NSEvent>(this) CGEvent]));
    }

    std::int64_t Event::absolute_x() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSEvent>(this) absoluteX]);
    }

    std::int64_t Event::absolute_y() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSEvent>(this) absoluteY]);
    }

    std::int64_t Event::absolute_z() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSEvent>(this) absoluteZ]);
    }

    EventMask Event::associated_events_mask() const
    {
        return static_cast<EventMask>([cocoon::internal::ns<::NSEvent>(this) associatedEventsMask]);
    }

    EventButtonMask Event::button_mask() const
    {
        return static_cast<EventButtonMask>([cocoon::internal::ns<::NSEvent>(this) buttonMask]);
    }

    std::int64_t Event::button_number() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSEvent>(this) buttonNumber]);
    }

    std::uint64_t Event::capability_mask() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSEvent>(this) capabilityMask]);
    }

    std::string Event::characters() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSEvent>(this) characters]);
    }

    std::string Event::characters_ignoring_modifiers() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSEvent>(this) charactersIgnoringModifiers]);
    }

    std::int64_t Event::click_count() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSEvent>(this) clickCount]);
    }

    std::int64_t Event::data1() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSEvent>(this) data1]);
    }

    std::int64_t Event::data2() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSEvent>(this) data2]);
    }

    double Event::delta_x() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSEvent>(this) deltaX]);
    }

    double Event::delta_y() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSEvent>(this) deltaY]);
    }

    double Event::delta_z() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSEvent>(this) deltaZ]);
    }

    std::uint64_t Event::device_id() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSEvent>(this) deviceID]);
    }

    bool Event::is_direction_inverted_from_device() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSEvent>(this) isDirectionInvertedFromDevice]);
    }

    double Event::double_click_interval()
    {
        return static_cast<double>([::NSEvent doubleClickInterval]);
    }

    bool Event::is_entering_proximity() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSEvent>(this) isEnteringProximity]);
    }

    std::int64_t Event::event_number() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSEvent>(this) eventNumber]);
    }

    const void* Event::event_ref() const
    {
        return [cocoon::internal::ns<::NSEvent>(this) eventRef];
    }

    bool Event::has_precise_scrolling_deltas() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSEvent>(this) hasPreciseScrollingDeltas]);
    }

    std::uint16_t Event::key_code() const
    {
        return static_cast<std::uint16_t>([cocoon::internal::ns<::NSEvent>(this) keyCode]);
    }

    double Event::key_repeat_delay()
    {
        return static_cast<double>([::NSEvent keyRepeatDelay]);
    }

    double Event::key_repeat_interval()
    {
        return static_cast<double>([::NSEvent keyRepeatInterval]);
    }

    Point Event::location_in_window() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSEvent>(this) locationInWindow]);
    }

    double Event::magnification() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSEvent>(this) magnification]);
    }

    EventModifierFlags Event::modifier_flags() const
    {
        return static_cast<EventModifierFlags>([cocoon::internal::ns<::NSEvent>(this) modifierFlags]);
    }

    EventPhase Event::momentum_phase() const
    {
        return static_cast<EventPhase>([cocoon::internal::ns<::NSEvent>(this) momentumPhase]);
    }

    bool Event::is_mouse_coalescing_enabled()
    {
        return static_cast<bool>([::NSEvent isMouseCoalescingEnabled]);
    }

    void Event::set_mouse_coalescing_enabled(bool value)
    {
        [::NSEvent setMouseCoalescingEnabled:static_cast<::BOOL>(value)];
    }

    Point Event::mouse_location()
    {
        return cocoon::internal::from([::NSEvent mouseLocation]);
    }

    EventPhase Event::phase() const
    {
        return static_cast<EventPhase>([cocoon::internal::ns<::NSEvent>(this) phase]);
    }

    std::uint64_t Event::pointing_device_id() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSEvent>(this) pointingDeviceID]);
    }

    std::uint64_t Event::pointing_device_serial_number() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSEvent>(this) pointingDeviceSerialNumber]);
    }

    PointingDeviceType Event::pointing_device_type() const
    {
        return static_cast<PointingDeviceType>([cocoon::internal::ns<::NSEvent>(this) pointingDeviceType]);
    }

    std::uint64_t Event::pressed_mouse_buttons()
    {
        return static_cast<std::uint64_t>([::NSEvent pressedMouseButtons]);
    }

    float Event::pressure() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSEvent>(this) pressure]);
    }

    PressureBehavior Event::pressure_behavior() const
    {
        return static_cast<PressureBehavior>([cocoon::internal::ns<::NSEvent>(this) pressureBehavior]);
    }

    float Event::rotation() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSEvent>(this) rotation]);
    }

    double Event::scrolling_delta_x() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSEvent>(this) scrollingDeltaX]);
    }

    double Event::scrolling_delta_y() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSEvent>(this) scrollingDeltaY]);
    }

    std::int64_t Event::stage() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSEvent>(this) stage]);
    }

    double Event::stage_transition() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSEvent>(this) stageTransition]);
    }

    EventSubtype Event::subtype() const
    {
        return static_cast<EventSubtype>([cocoon::internal::ns<::NSEvent>(this) subtype]);
    }

    bool Event::is_swipe_tracking_from_scroll_events_enabled()
    {
        return static_cast<bool>([::NSEvent isSwipeTrackingFromScrollEventsEnabled]);
    }

    std::uint64_t Event::system_tablet_id() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSEvent>(this) systemTabletID]);
    }

    std::uint64_t Event::tablet_id() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSEvent>(this) tabletID]);
    }

    float Event::tangential_pressure() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSEvent>(this) tangentialPressure]);
    }

    Point Event::tilt() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSEvent>(this) tilt]);
    }

    double Event::timestamp() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSEvent>(this) timestamp]);
    }

    TrackingArea Event::tracking_area() const
    {
        return cocoon::internal::wrap<TrackingArea>([cocoon::internal::ns<::NSEvent>(this) trackingArea]);
    }

    std::int64_t Event::tracking_number() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSEvent>(this) trackingNumber]);
    }

    EventType Event::type() const
    {
        return static_cast<EventType>([cocoon::internal::ns<::NSEvent>(this) type]);
    }

    std::uint64_t Event::unique_id() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSEvent>(this) uniqueID]);
    }

    void* Event::user_data() const
    {
        return [cocoon::internal::ns<::NSEvent>(this) userData];
    }

    Object Event::vendor_defined() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSEvent>(this) vendorDefined]);
    }

    std::uint64_t Event::vendor_id() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSEvent>(this) vendorID]);
    }

    std::uint64_t Event::vendor_pointing_device_type() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSEvent>(this) vendorPointingDeviceType]);
    }

    Window Event::window() const
    {
        return cocoon::internal::wrap<Window>([cocoon::internal::ns<::NSEvent>(this) window]);
    }

    std::int64_t Event::window_number() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSEvent>(this) windowNumber]);
    }
}
