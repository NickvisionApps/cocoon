#include "generated/gesture_recognizer.h"
#include "internal.h"

@interface AKGestureRecognizerDelegate : NSObject <NSGestureRecognizerDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKGestureRecognizerDelegate

- (BOOL)gestureRecognizer:(NSGestureRecognizer*)gestureRecognizer shouldAttemptToRecognizeWithEvent:(NSEvent*)event
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::GestureRecognizer, bool(cocoon::Event)>::emit((__bridge void*)strongHost, "should_attempt_to_recognize_with_event", cocoon::internal::wrap<cocoon::Event>(event));
    return static_cast<::BOOL>(__r);
}

- (BOOL)gestureRecognizerShouldBegin:(NSGestureRecognizer*)gestureRecognizer
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::GestureRecognizer, bool()>::emit((__bridge void*)strongHost, "should_begin");
    return static_cast<::BOOL>(__r);
}

- (BOOL)gestureRecognizer:(NSGestureRecognizer*)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(NSGestureRecognizer*)otherGestureRecognizer
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::GestureRecognizer, bool(cocoon::GestureRecognizer)>::emit((__bridge void*)strongHost, "should_recognize_simultaneously_with_gesture_recognizer", cocoon::internal::wrap<cocoon::GestureRecognizer>(otherGestureRecognizer));
    return static_cast<::BOOL>(__r);
}

- (BOOL)gestureRecognizer:(NSGestureRecognizer*)gestureRecognizer shouldRequireFailureOfGestureRecognizer:(NSGestureRecognizer*)otherGestureRecognizer
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::GestureRecognizer, bool(cocoon::GestureRecognizer)>::emit((__bridge void*)strongHost, "gesture_recognizer_should_require_failure_of_gesture_recognizer", cocoon::internal::wrap<cocoon::GestureRecognizer>(otherGestureRecognizer));
    return static_cast<::BOOL>(__r);
}

- (BOOL)gestureRecognizer:(NSGestureRecognizer*)gestureRecognizer shouldBeRequiredToFailByGestureRecognizer:(NSGestureRecognizer*)otherGestureRecognizer
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::GestureRecognizer, bool(cocoon::GestureRecognizer)>::emit((__bridge void*)strongHost, "gesture_recognizer_should_be_required_to_fail_by_gesture_recognizer", cocoon::internal::wrap<cocoon::GestureRecognizer>(otherGestureRecognizer));
    return static_cast<::BOOL>(__r);
}

- (BOOL)gestureRecognizer:(NSGestureRecognizer*)gestureRecognizer shouldReceiveTouch:(NSTouch*)touch
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::GestureRecognizer, bool(cocoon::Touch)>::emit((__bridge void*)strongHost, "should_receive_touch", cocoon::internal::wrap<cocoon::Touch>(touch));
    return static_cast<::BOOL>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(gestureRecognizer:shouldAttemptToRecognizeWithEvent:))
    {
        return strongHost && cocoon::Signal<cocoon::GestureRecognizer, bool(cocoon::Event)>::connected((__bridge void*)strongHost, "should_attempt_to_recognize_with_event");
    }
    if (selector == @selector(gestureRecognizerShouldBegin:))
    {
        return strongHost && cocoon::Signal<cocoon::GestureRecognizer, bool()>::connected((__bridge void*)strongHost, "should_begin");
    }
    if (selector == @selector(gestureRecognizer:shouldRecognizeSimultaneouslyWithGestureRecognizer:))
    {
        return strongHost && cocoon::Signal<cocoon::GestureRecognizer, bool(cocoon::GestureRecognizer)>::connected((__bridge void*)strongHost, "should_recognize_simultaneously_with_gesture_recognizer");
    }
    if (selector == @selector(gestureRecognizer:shouldRequireFailureOfGestureRecognizer:))
    {
        return strongHost && cocoon::Signal<cocoon::GestureRecognizer, bool(cocoon::GestureRecognizer)>::connected((__bridge void*)strongHost, "gesture_recognizer_should_require_failure_of_gesture_recognizer");
    }
    if (selector == @selector(gestureRecognizer:shouldBeRequiredToFailByGestureRecognizer:))
    {
        return strongHost && cocoon::Signal<cocoon::GestureRecognizer, bool(cocoon::GestureRecognizer)>::connected((__bridge void*)strongHost, "gesture_recognizer_should_be_required_to_fail_by_gesture_recognizer");
    }
    if (selector == @selector(gestureRecognizer:shouldReceiveTouch:))
    {
        return strongHost && cocoon::Signal<cocoon::GestureRecognizer, bool(cocoon::Touch)>::connected((__bridge void*)strongHost, "should_receive_touch");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    GestureRecognizer::GestureRecognizer(const Object& target, const std::string& action) : GestureRecognizer(Adopt{cocoon::internal::retain([[::NSGestureRecognizer alloc] initWithTarget:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))])})
    {
        GestureRecognizer::install_delegate_delegate_(handle());
    }

    GestureRecognizer::GestureRecognizer() : GestureRecognizer(Adopt{cocoon::internal::retain([[::NSGestureRecognizer alloc] init])})
    {
        GestureRecognizer::install_delegate_delegate_(handle());
    }

    GestureRecognizer::GestureRecognizer(std::nullptr_t) : Object(nullptr)
    {
    }

    GestureRecognizer::GestureRecognizer(Adopt adopt) : Object(adopt)
    {
    }

    bool GestureRecognizer::can_be_prevented_by_gesture_recognizer(const GestureRecognizer& preventing_gesture_recognizer) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGestureRecognizer>(this) canBePreventedByGestureRecognizer:cocoon::internal::native<::NSGestureRecognizer>(preventing_gesture_recognizer)]);
    }

    bool GestureRecognizer::can_prevent_gesture_recognizer(const GestureRecognizer& prevented_gesture_recognizer) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGestureRecognizer>(this) canPreventGestureRecognizer:cocoon::internal::native<::NSGestureRecognizer>(prevented_gesture_recognizer)]);
    }

    void GestureRecognizer::flags_changed(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) flagsChanged:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::key_down(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) keyDown:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::key_up(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) keyUp:cocoon::internal::native<::NSEvent>(event)];
    }

    Point GestureRecognizer::location_in_view(const View& view) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSGestureRecognizer>(this) locationInView:cocoon::internal::native<::NSView>(view)]);
    }

    void GestureRecognizer::magnify_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) magnifyWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::mouse_cancelled(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) mouseCancelled:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::mouse_down(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) mouseDown:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::mouse_dragged(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) mouseDragged:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::mouse_up(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) mouseUp:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::other_mouse_down(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) otherMouseDown:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::other_mouse_dragged(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) otherMouseDragged:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::other_mouse_up(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) otherMouseUp:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::pressure_change_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) pressureChangeWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::reset() const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) reset];
    }

    void GestureRecognizer::right_mouse_down(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) rightMouseDown:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::right_mouse_dragged(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) rightMouseDragged:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::right_mouse_up(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) rightMouseUp:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::rotate_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) rotateWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    bool GestureRecognizer::should_be_required_to_fail_by_gesture_recognizer(const GestureRecognizer& other_gesture_recognizer) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGestureRecognizer>(this) shouldBeRequiredToFailByGestureRecognizer:cocoon::internal::native<::NSGestureRecognizer>(other_gesture_recognizer)]);
    }

    bool GestureRecognizer::should_require_failure_of_gesture_recognizer(const GestureRecognizer& other_gesture_recognizer) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGestureRecognizer>(this) shouldRequireFailureOfGestureRecognizer:cocoon::internal::native<::NSGestureRecognizer>(other_gesture_recognizer)]);
    }

    void GestureRecognizer::tablet_point(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) tabletPoint:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::touches_began_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) touchesBeganWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::touches_cancelled_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) touchesCancelledWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::touches_ended_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) touchesEndedWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void GestureRecognizer::touches_moved_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) touchesMovedWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    std::string GestureRecognizer::action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSGestureRecognizer>(this) action]));
    }

    void GestureRecognizer::set_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) setAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    TouchTypeMask GestureRecognizer::allowed_touch_types() const
    {
        return static_cast<TouchTypeMask>([cocoon::internal::ns<::NSGestureRecognizer>(this) allowedTouchTypes]);
    }

    void GestureRecognizer::set_allowed_touch_types(TouchTypeMask value) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) setAllowedTouchTypes:static_cast<::NSTouchTypeMask>(value)];
    }

#ifdef COCOON_MACOS_27
    bool GestureRecognizer::is_cancellable_by_scroll_gesture() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<bool>([cocoon::internal::ns<::NSGestureRecognizer>(this) isCancellableByScrollGesture]);
        }
        return {};
    }

#endif
#ifdef COCOON_MACOS_27
    void GestureRecognizer::set_cancellable_by_scroll_gesture(bool value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSGestureRecognizer>(this) setCancellableByScrollGesture:static_cast<::BOOL>(value)];
        }
    }

#endif
    bool GestureRecognizer::delays_key_events() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGestureRecognizer>(this) delaysKeyEvents]);
    }

    void GestureRecognizer::set_delays_key_events(bool value) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) setDelaysKeyEvents:static_cast<::BOOL>(value)];
    }

    bool GestureRecognizer::delays_magnification_events() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGestureRecognizer>(this) delaysMagnificationEvents]);
    }

    void GestureRecognizer::set_delays_magnification_events(bool value) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) setDelaysMagnificationEvents:static_cast<::BOOL>(value)];
    }

    bool GestureRecognizer::delays_other_mouse_button_events() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGestureRecognizer>(this) delaysOtherMouseButtonEvents]);
    }

    void GestureRecognizer::set_delays_other_mouse_button_events(bool value) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) setDelaysOtherMouseButtonEvents:static_cast<::BOOL>(value)];
    }

    bool GestureRecognizer::delays_primary_mouse_button_events() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGestureRecognizer>(this) delaysPrimaryMouseButtonEvents]);
    }

    void GestureRecognizer::set_delays_primary_mouse_button_events(bool value) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) setDelaysPrimaryMouseButtonEvents:static_cast<::BOOL>(value)];
    }

    bool GestureRecognizer::delays_rotation_events() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGestureRecognizer>(this) delaysRotationEvents]);
    }

    void GestureRecognizer::set_delays_rotation_events(bool value) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) setDelaysRotationEvents:static_cast<::BOOL>(value)];
    }

    bool GestureRecognizer::delays_secondary_mouse_button_events() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGestureRecognizer>(this) delaysSecondaryMouseButtonEvents]);
    }

    void GestureRecognizer::set_delays_secondary_mouse_button_events(bool value) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) setDelaysSecondaryMouseButtonEvents:static_cast<::BOOL>(value)];
    }

    bool GestureRecognizer::is_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGestureRecognizer>(this) isEnabled]);
    }

    void GestureRecognizer::set_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) setEnabled:static_cast<::BOOL>(value)];
    }

    EventModifierFlags GestureRecognizer::modifier_flags() const
    {
        return static_cast<EventModifierFlags>([cocoon::internal::ns<::NSGestureRecognizer>(this) modifierFlags]);
    }

    std::string GestureRecognizer::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSGestureRecognizer>(this) name]);
    }

    void GestureRecognizer::set_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) setName:cocoon::internal::to(value)];
    }

    PressureConfiguration GestureRecognizer::pressure_configuration() const
    {
        return cocoon::internal::wrap<PressureConfiguration>([cocoon::internal::ns<::NSGestureRecognizer>(this) pressureConfiguration]);
    }

    void GestureRecognizer::set_pressure_configuration(const PressureConfiguration& value) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) setPressureConfiguration:cocoon::internal::native<::NSPressureConfiguration>(value)];
    }

    GestureRecognizerState GestureRecognizer::state() const
    {
        return static_cast<GestureRecognizerState>([cocoon::internal::ns<::NSGestureRecognizer>(this) state]);
    }

    void GestureRecognizer::set_state(GestureRecognizerState value) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) setState:static_cast<::NSGestureRecognizerState>(value)];
    }

    Object GestureRecognizer::target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSGestureRecognizer>(this) target]);
    }

    void GestureRecognizer::set_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSGestureRecognizer>(this) setTarget:cocoon::internal::native_id(value)];
    }

    View GestureRecognizer::view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSGestureRecognizer>(this) view]);
    }

    void GestureRecognizer::install_delegate_delegate_(void* native)
    {
        ::NSGestureRecognizer* host = (__bridge ::NSGestureRecognizer*)native;
        AKGestureRecognizerDelegate* delegate = [[AKGestureRecognizerDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSGestureRecognizer* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSGestureRecognizer* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
