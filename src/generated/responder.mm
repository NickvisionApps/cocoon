#include "generated/responder.h"
#include "internal.h"

namespace cocoon
{
    Responder::Responder() : Responder(Adopt{cocoon::internal::retain([[::NSResponder alloc] init])})
    {
    }

    Responder::Responder(std::nullptr_t) : Object(nullptr)
    {
    }

    Responder::Responder(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<std::string> Responder::allowed_classes_for_restorable_state_key_path(const std::string& key_path)
    {
        return cocoon::internal::from_array<std::string>([::NSResponder allowedClassesForRestorableStateKeyPath:cocoon::internal::to(key_path)], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from(NSStringFromClass(e));
                                           });
    }

    bool Responder::become_first_responder() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSResponder>(this) becomeFirstResponder]);
    }

    void Responder::begin_gesture_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) beginGestureWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::change_mode_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) changeModeWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::context_menu_key_down(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) contextMenuKeyDown:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::cursor_update(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) cursorUpdate:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::encode_restorable_state_with_coder(const Coder& coder) const
    {
        [cocoon::internal::ns<::NSResponder>(this) encodeRestorableStateWithCoder:cocoon::internal::native<::NSCoder>(coder)];
    }

    void Responder::encode_restorable_state_with_coder(const Coder& coder, const OperationQueue& queue) const
    {
        [cocoon::internal::ns<::NSResponder>(this) encodeRestorableStateWithCoder:cocoon::internal::native<::NSCoder>(coder) backgroundQueue:cocoon::internal::native<::NSOperationQueue>(queue)];
    }

    void Responder::end_gesture_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) endGestureWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::flags_changed(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) flagsChanged:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::flush_buffered_key_events() const
    {
        [cocoon::internal::ns<::NSResponder>(this) flushBufferedKeyEvents];
    }

    void Responder::help_requested(const Event& event_ptr) const
    {
        [cocoon::internal::ns<::NSResponder>(this) helpRequested:cocoon::internal::native<::NSEvent>(event_ptr)];
    }

    void Responder::interpret_key_events(const std::vector<Event>& event_array) const
    {
        [cocoon::internal::ns<::NSResponder>(this) interpretKeyEvents:cocoon::internal::to_array(event_array, [](const Event& e) -> id
                                                                     {
                                                                         return cocoon::internal::native<::NSEvent>(e);
                                                                     })];
    }

    void Responder::invalidate_restorable_state() const
    {
        [cocoon::internal::ns<::NSResponder>(this) invalidateRestorableState];
    }

    void Responder::key_down(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) keyDown:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::key_up(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) keyUp:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::magnify_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) magnifyWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    TouchBar Responder::make_touch_bar() const
    {
        return cocoon::internal::wrap<TouchBar>([cocoon::internal::ns<::NSResponder>(this) makeTouchBar]);
    }

    void Responder::mouse_cancelled(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) mouseCancelled:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::mouse_down(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) mouseDown:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::mouse_dragged(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) mouseDragged:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::mouse_entered(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) mouseEntered:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::mouse_exited(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) mouseExited:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::mouse_moved(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) mouseMoved:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::mouse_up(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) mouseUp:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::new_window_for_tab(const Object& sender) const
    {
        [cocoon::internal::ns<::NSResponder>(this) newWindowForTab:cocoon::internal::native_id(sender)];
    }

    void Responder::no_responder_for(const std::string& event_selector) const
    {
        [cocoon::internal::ns<::NSResponder>(this) noResponderFor:NSSelectorFromString(cocoon::internal::to(event_selector))];
    }

    void Responder::other_mouse_down(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) otherMouseDown:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::other_mouse_dragged(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) otherMouseDragged:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::other_mouse_up(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) otherMouseUp:cocoon::internal::native<::NSEvent>(event)];
    }

    bool Responder::perform_key_equivalent(const Event& event) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSResponder>(this) performKeyEquivalent:cocoon::internal::native<::NSEvent>(event)]);
    }

    void Responder::perform_text_finder_action(const Object& sender) const
    {
        [cocoon::internal::ns<::NSResponder>(this) performTextFinderAction:cocoon::internal::native_id(sender)];
    }

    bool Responder::present_error(const Error& error) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSResponder>(this) presentError:cocoon::internal::native<::NSError>(error)]);
    }

    void Responder::present_error(const Error& error, const Window& window, const Object& delegate, const std::string& did_present_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSResponder>(this) presentError:cocoon::internal::native<::NSError>(error) modalForWindow:cocoon::internal::native<::NSWindow>(window) delegate:cocoon::internal::native_id(delegate) didPresentSelector:NSSelectorFromString(cocoon::internal::to(did_present_selector)) contextInfo:context_info];
    }

    void Responder::pressure_change_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) pressureChangeWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::quick_look_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) quickLookWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    bool Responder::resign_first_responder() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSResponder>(this) resignFirstResponder]);
    }

    void Responder::restore_state_with_coder(const Coder& coder) const
    {
        [cocoon::internal::ns<::NSResponder>(this) restoreStateWithCoder:cocoon::internal::native<::NSCoder>(coder)];
    }

    void Responder::right_mouse_down(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) rightMouseDown:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::right_mouse_dragged(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) rightMouseDragged:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::right_mouse_up(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) rightMouseUp:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::rotate_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) rotateWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::scroll_wheel(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) scrollWheel:cocoon::internal::native<::NSEvent>(event)];
    }

    bool Responder::should_be_treated_as_ink_event(const Event& event) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSResponder>(this) shouldBeTreatedAsInkEvent:cocoon::internal::native<::NSEvent>(event)]);
    }

    void Responder::show_context_help(const Object& sender) const
    {
        [cocoon::internal::ns<::NSResponder>(this) showContextHelp:cocoon::internal::native_id(sender)];
    }

    void Responder::show_writing_tools(const Object& sender) const
    {
        [cocoon::internal::ns<::NSResponder>(this) showWritingTools:cocoon::internal::native_id(sender)];
    }

    void Responder::smart_magnify_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) smartMagnifyWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    Object Responder::supplemental_target_for_action(const std::string& action, const Object& sender) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSResponder>(this) supplementalTargetForAction:NSSelectorFromString(cocoon::internal::to(action)) sender:cocoon::internal::native_id(sender)]);
    }

    void Responder::swipe_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) swipeWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::tablet_point(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) tabletPoint:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::tablet_proximity(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) tabletProximity:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::touches_began_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) touchesBeganWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::touches_cancelled_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) touchesCancelledWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::touches_ended_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) touchesEndedWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void Responder::touches_moved_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSResponder>(this) touchesMovedWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    bool Responder::try_to_perform(const std::string& action, const Object& object) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSResponder>(this) tryToPerform:NSSelectorFromString(cocoon::internal::to(action)) with:cocoon::internal::native_id(object)]);
    }

    void Responder::update_user_activity_state(const UserActivity& user_activity) const
    {
        [cocoon::internal::ns<::NSResponder>(this) updateUserActivityState:cocoon::internal::native<::NSUserActivity>(user_activity)];
    }

    Object Responder::valid_requestor_for_send_type(const std::string& send_type, const std::string& return_type) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSResponder>(this) validRequestorForSendType:cocoon::internal::to(send_type) returnType:cocoon::internal::to(return_type)]);
    }

    bool Responder::validate_proposed_first_responder(const Responder& responder, const Event& event) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSResponder>(this) validateProposedFirstResponder:cocoon::internal::native<::NSResponder>(responder) forEvent:cocoon::internal::native<::NSEvent>(event)]);
    }

    bool Responder::wants_forwarded_scroll_events_for_axis(EventGestureAxis axis) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSResponder>(this) wantsForwardedScrollEventsForAxis:static_cast<::NSEventGestureAxis>(axis)]);
    }

    bool Responder::wants_scroll_events_for_swipe_tracking_on_axis(EventGestureAxis axis) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSResponder>(this) wantsScrollEventsForSwipeTrackingOnAxis:static_cast<::NSEventGestureAxis>(axis)]);
    }

    Error Responder::will_present_error(const Error& error) const
    {
        return cocoon::internal::wrap<Error>([cocoon::internal::ns<::NSResponder>(this) willPresentError:cocoon::internal::native<::NSError>(error)]);
    }

    bool Responder::accepts_first_responder() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSResponder>(this) acceptsFirstResponder]);
    }

    Menu Responder::menu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSResponder>(this) menu]);
    }

    void Responder::set_menu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSResponder>(this) setMenu:cocoon::internal::native<::NSMenu>(value)];
    }

    Responder Responder::next_responder() const
    {
        return cocoon::internal::wrap<Responder>([cocoon::internal::ns<::NSResponder>(this) nextResponder]);
    }

    void Responder::set_next_responder(const Responder& value) const
    {
        [cocoon::internal::ns<::NSResponder>(this) setNextResponder:cocoon::internal::native<::NSResponder>(value)];
    }

    std::vector<std::string> Responder::restorable_state_key_paths()
    {
        return cocoon::internal::from_array<std::string>([::NSResponder restorableStateKeyPaths], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    TouchBar Responder::touch_bar() const
    {
        return cocoon::internal::wrap<TouchBar>([cocoon::internal::ns<::NSResponder>(this) touchBar]);
    }

    void Responder::set_touch_bar(const TouchBar& value) const
    {
        [cocoon::internal::ns<::NSResponder>(this) setTouchBar:cocoon::internal::native<::NSTouchBar>(value)];
    }

    UndoManager Responder::undo_manager() const
    {
        return cocoon::internal::wrap<UndoManager>([cocoon::internal::ns<::NSResponder>(this) undoManager]);
    }

    UserActivity Responder::user_activity() const
    {
        return cocoon::internal::wrap<UserActivity>([cocoon::internal::ns<::NSResponder>(this) userActivity]);
    }

    void Responder::set_user_activity(const UserActivity& value) const
    {
        [cocoon::internal::ns<::NSResponder>(this) setUserActivity:cocoon::internal::native<::NSUserActivity>(value)];
    }
}
