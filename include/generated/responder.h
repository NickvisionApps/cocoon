#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Coder;
    class Error;
    class Event;
    class Menu;
    class OperationQueue;
    class TouchBar;
    class UndoManager;
    class UserActivity;
    class Window;

    /**
     * @brief C++ handle for the Objective-C class `NSResponder` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Responder responder;
     * responder.set_menu(cocoon::Menu());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Responder responder{};
     * responder.set_menu(cocoon::Menu());
     * auto menu = responder.menu();
     * responder.set_next_responder(cocoon::Responder());
     * auto next_responder = responder.next_responder();
     * responder.set_touch_bar(cocoon::TouchBar());
     * auto touch_bar = responder.touch_bar();
     * responder.become_first_responder();
     * responder.begin_gesture_with_event(cocoon::Event());
     * responder.change_mode_with_event(cocoon::Event());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsresponder
     */
    class Responder : public Object
    {
    public:
        /// @brief Creates a new `NSResponder` instance and returns a handle to it.
        explicit Responder();
        /// @brief Creates a null handle that refers to no native object.
        Responder(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Responder(Adopt adopt);
        /**
         * @brief Calls `+[NSResponder allowedClassesForRestorableStateKeyPath:]`.
         * @param key_path Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> allowed_classes_for_restorable_state_key_path(const std::string& key_path);
        /**
         * @brief Calls `-[NSResponder becomeFirstResponder]`.
         * @return The converted Objective-C result.
         */
        bool become_first_responder() const;
        /**
         * @brief Calls `-[NSResponder beginGestureWithEvent:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void begin_gesture_with_event(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder changeModeWithEvent:]`.
         * @details Issued in response to a double-tap on the side of the Apple Pencil
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void change_mode_with_event(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder contextMenuKeyDown:]`.
         * @details \@method 'contextMenuKeyDown' \@abstract Handle a key event that should present a context menu at the user focus. \@discussion Most applications should not override this method. Instead, you should customize the context menu displayed from a keyboard event by implementing 'menuForEvent:' and 'selectionAnchorRect', or 'showContextMenuForSelection:', rather than this method. You should only override this method when you do not want the system-provided default behavior for the context menu hotkey, either for a specific key combination, or for the hotkey in general. For example, if your application already provides a different behavior for control-Return (the default context menu hotkey definition), and you want to preserve that behavior, you should override this method to handle that specific key combination, and then return without calling 'super'. Note that the user may customize the hotkey to a different key combination, so in this example, if any other key combination is passed to your method, you would call 'super'. An implementation of this method should call '[super contextMenuKeyDown:event]' to pass the request up the responder chain. If the message reaches the application object, NSApplication's implementation of this method will send 'showContextMenuForSelection:' to the responder chain. If you do not call 'super', then no further handling of the key event will be performed. \@note In some cases, 'showContextMenuForSelection:' will be called without a prior call to 'contextMenuKeyDown:'. This occurs when a view receives an Accessibility ShowMenu action, or when the user has created a Cocoa Text key binding to map a different key combination to the 'showContextMenuForSelection:' action. \@param event The key down event that matches the system-wide context menu hotkey combination. \@seealso 'showContextMenuForSelection:'
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void context_menu_key_down(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder cursorUpdate:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void cursor_update(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder encodeRestorableStateWithCoder:]`.
         * @param coder Argument converted to the Objective-C parameter of the same role.
         */
        void encode_restorable_state_with_coder(const Coder& coder) const;
        /**
         * @brief Calls `-[NSResponder encodeRestorableStateWithCoder:backgroundQueue:]`.
         * @param coder Argument converted to the Objective-C parameter of the same role.
         * @param queue Argument converted to the Objective-C parameter of the same role.
         */
        void encode_restorable_state_with_coder(const Coder& coder, const OperationQueue& queue) const;
        /**
         * @brief Calls `-[NSResponder endGestureWithEvent:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void end_gesture_with_event(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder flagsChanged:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void flags_changed(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder flushBufferedKeyEvents]`.
         */
        void flush_buffered_key_events() const;
        /**
         * @brief Calls `-[NSResponder helpRequested:]`.
         * @param event_ptr Argument converted to the Objective-C parameter of the same role.
         */
        void help_requested(const Event& event_ptr) const;
        /**
         * @brief Calls `-[NSResponder interpretKeyEvents:]`.
         * @param event_array Argument converted to the Objective-C parameter of the same role.
         */
        void interpret_key_events(const std::vector<Event>& event_array) const;
        /**
         * @brief Calls `-[NSResponder invalidateRestorableState]`.
         */
        void invalidate_restorable_state() const;
        /**
         * @brief Calls `-[NSResponder keyDown:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void key_down(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder keyUp:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void key_up(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder magnifyWithEvent:]`.
         * @details The following WithEvent methods are available on 10.5.2 or later, and will be sent only on hardware capable of generating the corresponding NSEvent types
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void magnify_with_event(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder makeTouchBar]`.
         * @return The converted Objective-C result.
         */
        TouchBar make_touch_bar() const;
        /**
         * @brief Calls `-[NSResponder mouseCancelled:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void mouse_cancelled(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder mouseDown:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void mouse_down(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder mouseDragged:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void mouse_dragged(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder mouseEntered:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void mouse_entered(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder mouseExited:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void mouse_exited(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder mouseMoved:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void mouse_moved(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder mouseUp:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void mouse_up(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder newWindowForTab:]`.
         * @details For automatic window tabbing: This method can be implemented in the responder chain. It is automatically called for tabbed windows when the plus button is clicked, and the next window that is created and shown will be placed in a tab. This can be implemented in an NSDocumentController subclass, or somewhere in the responder chain starting at NSWindow (such as NSWindow, the window delegate, the windowController, the NSApp delegate, etc. A plus button on tabbed windows will only be shown if this method exists in the responder chain.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void new_window_for_tab(const Object& sender) const;
        /**
         * @brief Calls `-[NSResponder noResponderFor:]`.
         * @param event_selector Argument converted to the Objective-C parameter of the same role.
         */
        void no_responder_for(const std::string& event_selector) const;
        /**
         * @brief Calls `-[NSResponder otherMouseDown:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void other_mouse_down(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder otherMouseDragged:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void other_mouse_dragged(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder otherMouseUp:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void other_mouse_up(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder performKeyEquivalent:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool perform_key_equivalent(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder performTextFinderAction:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void perform_text_finder_action(const Object& sender) const;
        /**
         * @brief Calls `-[NSResponder presentError:]`.
         * @details Present an error alert to the user, as an application-modal panel, and return YES if error recovery was done, NO otherwise. This method behaves much like the previous one except it does not return until the user has dismissed the alert and, if the error had recovery options and a recovery delegate, the error's recovery delegate has been sent an -attemptRecoveryFromError:optionIndex: message. You can invoke this method to present error alert dialog boxes. For example, Cocoa's own [NSDocumentController openDocument:] invokes this method when document opening fails. You probably shouldn't override this method, because you have no way of reliably predicting whether this method vs. -presentError:modalForWindow:delegate:didPresentSelector:contextInfo: will be invoked for any particular error. You should instead override the -willPresentError: method described below.
         * @param error Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool present_error(const Error& error) const;
        /**
         * @brief Calls `-[NSResponder presentError:modalForWindow:delegate:didPresentSelector:contextInfo:]`.
         * @details Present an error alert to the user, as a document-modal panel. When the user has dismissed the alert and any recovery possible for the error and chosen by the user has been attempted, send the selected message to the specified delegate. The method selected by didPresentSelector must have the same signature as: - (void)didPresentErrorWithRecovery:(BOOL)didRecover contextInfo:(void )contextInfo; The default implementation of this method always invokes [self willPresentError:error] to give subclassers an opportunity to customize error presentation. It then forwards the message, passing the customized error, to the next responder or, if there is no next responder, NSApp. NSApplication's override of this method invokes [[NSAlert alertWithError:errorToPresent] beginSheetModalForWindow:window modalDelegate:self didEndSelector:selectorForAPrivateMethod contextInfo:privateContextInfo]. When the user has dismissed the alert, the error's recovery attempter is sent an -attemptRecoveryFromError:optionIndex:delegate:didRecoverSelector:contextInfo: message, if the error had recovery options and a recovery delegate. Errors for which ([[error domain] isEqualToString:NSCocoaErrorDomain] && [error code]==NSUserCancelledError) are a special case, because they do not actually represent errors and should not be presented as such to the user. NSApplication's override of this method does not present an alert to the user for these kinds of errors. Instead it merely invokes the delegate specifying didRecover==NO. Between the responder chain in a typical application and various overrides of this method in AppKit classes, objects are given the opportunity to present errors in orders like these: For windows owned by documents: view -> superviews -> window -> window controller -> document -> document controller -> application For windows that have window controllers but aren't associated with documents: view -> superviews -> window -> window controller -> application For windows that have no window controller at all: view -> superviews -> window -> application You can invoke this method to present error alert sheets. For example, Cocoa's own -[NSDocument saveToURL:ofType:forSaveOperation:delegate:didSaveSelector:contextInfo:] invokes this method when it's just invoked -saveToURL:ofType:forSaveOperation:completionHandler: and that method has signalled an error. You probably shouldn't override this method, because you have no way of reliably predicting whether this method vs. -presentError will be invoked for any particular error. You should instead override the -willPresentError: method described below.
         * @param error Argument converted to the Objective-C parameter of the same role.
         * @param window Argument converted to the Objective-C parameter of the same role.
         * @param delegate Argument converted to the Objective-C parameter of the same role.
         * @param did_present_selector Argument converted to the Objective-C parameter of the same role.
         * @param context_info Argument converted to the Objective-C parameter of the same role.
         */
        void present_error(const Error& error, const Window& window, const Object& delegate, const std::string& did_present_selector, void* context_info) const;
        /**
         * @brief Calls `-[NSResponder pressureChangeWithEvent:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void pressure_change_with_event(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder quickLookWithEvent:]`.
         * @details Perform a Quick Look on the content at location in the event. If there are no Quick Look items at the location, call super. Also, see quickLookPreviewItems: further below.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void quick_look_with_event(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder resignFirstResponder]`.
         * @return The converted Objective-C result.
         */
        bool resign_first_responder() const;
        /**
         * @brief Calls `-[NSResponder restoreStateWithCoder:]`.
         * @param coder Argument converted to the Objective-C parameter of the same role.
         */
        void restore_state_with_coder(const Coder& coder) const;
        /**
         * @brief Calls `-[NSResponder rightMouseDown:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void right_mouse_down(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder rightMouseDragged:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void right_mouse_dragged(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder rightMouseUp:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void right_mouse_up(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder rotateWithEvent:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void rotate_with_event(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder scrollWheel:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void scroll_wheel(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder shouldBeTreatedAsInkEvent:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool should_be_treated_as_ink_event(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder showContextHelp:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void show_context_help(const Object& sender) const;
        /**
         * @brief Calls `-[NSResponder showWritingTools:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void show_writing_tools(const Object& sender) const;
        /**
         * @brief Calls `-[NSResponder smartMagnifyWithEvent:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void smart_magnify_with_event(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder supplementalTargetForAction:sender:]`.
         * @details This method is used in the process of finding a target for an action method. If this NSResponder instance does not itself respondsToSelector:action, then supplementalTargetForAction:sender: is called. This method should return an object which responds to the action; if this responder does not have a supplemental object that does that, the implementation of this method should call super's supplementalTargetForAction:sender:. NSResponder's implementation returns nil.
         * @param action Argument converted to the Objective-C parameter of the same role.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object supplemental_target_for_action(const std::string& action, const Object& sender) const;
        /**
         * @brief Calls `-[NSResponder swipeWithEvent:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void swipe_with_event(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder tabletPoint:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void tablet_point(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder tabletProximity:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void tablet_proximity(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder touchesBeganWithEvent:]`.
         * @details A new set of touches has been recognized. To get the set of touches that began for this view (or descendants of this view): [event touchesMatchingPhase:NSTouchPhaseBegan inView:self]; Note: this is not always the point of contact with the touch device. A touch that transitions from resting to active may be part of a Began set. Note: These 'touches' responder methods are used for indirect touches and touchbar devices only. They are not used for Sidecar devices.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void touches_began_with_event(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder touchesCancelledWithEvent:]`.
         * @details The System has cancelled the tracking of touches for any reason.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void touches_cancelled_with_event(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder touchesEndedWithEvent:]`.
         * @details A set of touches have been removed. To get the set of touches that ended for this view (or descendants of this view): [event touchesMatchingPhase:NSTouchPhaseEnded inView:self]; Note: this is not always the point of removal with the touch device. A touch that transitions from active to resting may be part of an Ended set.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void touches_ended_with_event(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder touchesMovedWithEvent:]`.
         * @details One or more touches has moved. To get the set of touches that moved for this view (or descendants of this view): [event touchesMatchingPhase:NSTouchPhaseMoved inView:self];
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void touches_moved_with_event(const Event& event) const;
        /**
         * @brief Calls `-[NSResponder tryToPerform:with:]`.
         * @param action Argument converted to the Objective-C parameter of the same role.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool try_to_perform(const std::string& action, const Object& object) const;
        /**
         * @brief Calls `-[NSResponder updateUserActivityState:]`.
         * @param user_activity Argument converted to the Objective-C parameter of the same role.
         */
        void update_user_activity_state(const UserActivity& user_activity) const;
        /**
         * @brief Calls `-[NSResponder validRequestorForSendType:returnType:]`.
         * @param send_type Argument converted to the Objective-C parameter of the same role.
         * @param return_type Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object valid_requestor_for_send_type(const std::string& send_type, const std::string& return_type) const;
        /**
         * @brief Calls `-[NSResponder validateProposedFirstResponder:forEvent:]`.
         * @details This is a responder chain method to allow controls to determine when they should become first responder or not. Some controls, such as NSTextField, should only become first responder when the enclosing NSTableView/NSBrowser indicates that the view can begin editing. It is up to the particular control that wants to be validated to call this method in its -mouseDown: (or other time) to determine if it should attempt to become the first responder or not. The default implementation returns YES when there is no -nextResponder, otherwise, it is forwarded up the responder chain. NSTableView/NSBrowser implements this to only allow first responder status if the responder is a view in a selected row. It also delays the first responder assignment if a doubleAction needs to (possibly) be sent. 'event' may be nil if there is no applicable event.
         * @param responder Argument converted to the Objective-C parameter of the same role.
         * @param event Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool validate_proposed_first_responder(const Responder& responder, const Event& event) const;
        /**
         * @brief Calls `-[NSResponder wantsForwardedScrollEventsForAxis:]`.
         * @details Some views process gesture scroll events to perform elastic scrolling. In some cases, the scroll events should be forwarded up the responder chain for further processing (for example an enclosing scroll view). Implement this method returning yes and views that perform elastic scrolling will forward gesture scroll events up the responder chain on the following condition: the content to be scrolled is already at the edge of the scrolled direction at the beginning of the scroll gesture. Otherwise, the view will perform elastic scrolling. Note: If you intend to call -trackSwipeEventWithOptions:dampenAmountThresholdMin:max:usingHandler: implement -wantsToTrackScrollEventsAsSwipeForAxis, as defined above instead. Default implementation returns NO.
         * @param axis Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool wants_forwarded_scroll_events_for_axis(EventGestureAxis axis) const;
        /**
         * @brief Calls `-[NSResponder wantsScrollEventsForSwipeTrackingOnAxis:]`.
         * @details Some views process gesture scroll events to perform elastic scrolling. In some cases, you may want to track gesture scroll events like a swipe. (see -trackSwipeEventWithOptions:dampenAmountThresholdMin:max:usingHandler: in NSEvent.h) Implement this method and return YES in your swipe controller and views that perform elastic scrolling will forward gesture scroll events up the responder chain on the following condition: the content to be scrolled is already at the edge of the scrolled direction at the beginning of the scroll gesture. Otherwise, the view will perform elastic scrolling. Default implementation returns NO.
         * @param axis Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool wants_scroll_events_for_swipe_tracking_on_axis(EventGestureAxis axis) const;
        /**
         * @brief Calls `-[NSResponder willPresentError:]`.
         * @details Given that the receiver is about to present an error (perhaps by just forwarding it to the next responder), return the error that should actually be presented. The default implementation of this method merely returns the passed-in error. You can override this method to customize the presentation of errors by examining the passed-in error and if, for example, its localized description or recovery information is unsuitably generic, returning a more specific one. When you override this method always check the NSError's domain and code to discriminate between errors whose presentation you want to customize and those you don't. For those you don't just return [super willPresentError:error]. Don't make decisions based on the NSError's localized description, recovery suggestion, or recovery options because it's usually not a good idea to try to parse localized text.
         * @param error Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Error will_present_error(const Error& error) const;
        /**
         * @brief Returns the `acceptsFirstResponder` property of `NSResponder`.
         * @return The converted Objective-C result.
         */
        bool accepts_first_responder() const;
        /**
         * @brief Returns the `menu` property of `NSResponder`.
         * @return The converted Objective-C result.
         */
        Menu menu() const;
        /**
         * @brief Sets the `menu` property of `NSResponder`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_menu(const Menu& value) const;
        /**
         * @brief Returns the `nextResponder` property of `NSResponder`.
         * @return The converted Objective-C result.
         */
        Responder next_responder() const;
        /**
         * @brief Sets the `nextResponder` property of `NSResponder`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_next_responder(const Responder& value) const;
        /**
         * @brief Returns the `restorableStateKeyPaths` property of `NSResponder`.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> restorable_state_key_paths();
        /**
         * @brief Returns the `touchBar` property of `NSResponder`.
         * @return The converted Objective-C result.
         */
        TouchBar touch_bar() const;
        /**
         * @brief Sets the `touchBar` property of `NSResponder`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_touch_bar(const TouchBar& value) const;
        /**
         * @brief Returns the `undoManager` property of `NSResponder`.
         * @return The converted Objective-C result.
         */
        UndoManager undo_manager() const;
        /**
         * @brief Returns the `userActivity` property of `NSResponder`.
         * @return The converted Objective-C result.
         */
        UserActivity user_activity() const;
        /**
         * @brief Sets the `userActivity` property of `NSResponder`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_user_activity(const UserActivity& value) const;
    };
}
