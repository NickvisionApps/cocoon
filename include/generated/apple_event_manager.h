#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AppleEventDescriptor;
    class AppleEventManagerSuspensionID;

    /**
     * @brief C++ handle for the Objective-C class `NSAppleEventManager` (Foundation).
     * @details A mechanism for registering handler routines for specific types of Apple events and dispatching events to those handlers. Cocoa provides built-in scriptability support that uses scriptability information supplied by an application to automatically convert Apple events into script command objects that perform the desired operation. However, some applications may want to perform more basic Apple event handling, in which an application registers handlers for the Apple events it can process, then calls on the Apple Event Manager to dispatch received Apple events to the appropriate handler. 'NSAppleEventManager' supports these mechanisms by providing methods to register and remove handlers and to dispatch Apple events to the appropriate handler, if one exists. For related information, see [How Cocoa Applications Handle Apple Events](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_handle_AEs/SAppsHandleAEs.html\#//apple_ref/doc/uid/20001239) Each application has at most one instance of 'NSAppleEventManager'. To obtain a reference to it, you call the class method ''shared()'', which creates the instance if it doesn't already exist. For information about the Apple Event Manager, see \<doc://com.apple.documentation/documentation/applicationservices/apple_event_manager> and Apple Events Programming Guide.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::AppleEventManager apple_event_manager;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::AppleEventManager apple_event_manager{};
     * auto made_0 = cocoon::AppleEventManager::shared_apple_event_manager();
     * apple_event_manager.remove_event_handler_for_event_class(1, 1);
     * apple_event_manager.suspend_current_apple_event();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsappleeventmanager
     */
    class AppleEventManager : public Object
    {
    public:
        /// @brief Creates a new `NSAppleEventManager` instance and returns a handle to it.
        explicit AppleEventManager();
        /// @brief Creates a null handle that refers to no native object.
        AppleEventManager(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit AppleEventManager(Adopt adopt);
        /**
         * @brief Calls `-[NSAppleEventManager appleEventForSuspensionID:]`.
         * @details Given a nonzero suspension ID returned by an invocation of '-suspendCurrentAppleEvent', returns the descriptor for the event whose handling was suspended. The effects of mutating or retaining the returned descriptor are undefined, although it may be copied. This method may be invoked in any thread, not just the one in which the corresponding invocation of '-suspendCurrentAppleEvent' occurred.
         * @param suspension_id Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor apple_event_for_suspension_id(const AppleEventManagerSuspensionID& suspension_id) const;
        /**
         * @brief Calls `-[NSAppleEventManager dispatchRawAppleEvent:withRawReply:handlerRefCon:]`.
         * @details Causes the Apple event specified by 'theAppleEvent' to be dispatched to the appropriate Apple event handler, if one has been registered by calling '-setEventHandler:andSelector:forEventClass:andEventID:'. The 'theReply' parameter always specifies a reply Apple event, never 'nil'. However, the handler should not fill out the reply if the descriptor type for the reply event is 'typeNull', indicating the sender does not want a reply. The 'handlerRefcon' parameter provides 4 bytes of data to the handler; a common use for this parameter is to pass a pointer to additional data. This method is primarily intended for Cocoa's internal use. Note that dispatching an event means routing an event to an appropriate handler in the current application. You cannot use this method to send events to other applications.
         * @param the_apple_event Argument converted to the Objective-C parameter of the same role.
         * @param the_reply Argument converted to the Objective-C parameter of the same role.
         * @param handler_ref_con Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int16_t dispatch_raw_apple_event(const AEDesc* the_apple_event, AEDesc* the_reply, void* handler_ref_con) const;
        /**
         * @brief Calls `-[NSAppleEventManager removeEventHandlerForEventClass:andEventID:]`.
         * @details If an Apple event handler has been registered for the event specified by 'eventClass' and 'eventID', removes it. Otherwise does nothing.
         * @param event_class Argument converted to the Objective-C parameter of the same role.
         * @param event_id Argument converted to the Objective-C parameter of the same role.
         */
        void remove_event_handler_for_event_class(unsigned int event_class, unsigned int event_id) const;
        /**
         * @brief Calls `-[NSAppleEventManager replyAppleEventForSuspensionID:]`.
         * @details Given a nonzero suspension ID returned by an invocation of '-suspendCurrentAppleEvent', returns the corresponding reply event descriptor. This descriptor, including any mutations, will be returned to the sender of the suspended event when handling of the event is resumed, if the sender has requested a reply. The effects of retaining the descriptor are undefined; it may be copied, but mutations of the copy will not be returned to the sender of the suspended event. This method may be invoked in any thread, not just the one in which the corresponding invocation of '-suspendCurrentAppleEvent' occurred.
         * @param suspension_id Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor reply_apple_event_for_suspension_id(const AppleEventManagerSuspensionID& suspension_id) const;
        /**
         * @brief Calls `-[NSAppleEventManager resumeWithSuspensionID:]`.
         * @details Given a nonzero suspension ID returned by an invocation of '-suspendCurrentAppleEvent', signal that handling of the suspended event may now continue. This may result in the immediate sending of the reply event to the sender of the suspended event, if the sender has requested a reply. If the suspension ID has been used in a previous invocation of '-setCurrentAppleEventAndReplyEventWithSuspensionID:' the effects of that invocation will be completely undone. Subsequent invocations of other 'NSAppleEventManager' methods using the same suspension ID are invalid. This method may be invoked in any thread, not just the one in which the corresponding invocation of '-suspendCurrentAppleEvent' occurred.
         * @param suspension_id Argument converted to the Objective-C parameter of the same role.
         */
        void resume_with_suspension_id(const AppleEventManagerSuspensionID& suspension_id) const;
        /**
         * @brief Calls `-[NSAppleEventManager setCurrentAppleEventAndReplyEventWithSuspensionID:]`.
         * @details Given a nonzero suspension ID returned by an invocation of '-suspendCurrentAppleEvent', sets the values that will be returned by subsequent invocations of 'currentAppleEvent' and 'currentReplyAppleEvent' to be the event whose handling was suspended and its corresponding reply event, respectively. Redundant invocations of this method will be ignored.
         * @param suspension_id Argument converted to the Objective-C parameter of the same role.
         */
        void set_current_apple_event_and_reply_event_with_suspension_id(const AppleEventManagerSuspensionID& suspension_id) const;
        /**
         * @brief Calls `-[NSAppleEventManager setEventHandler:andSelector:forEventClass:andEventID:]`.
         * @details Registers the Apple event handler specified by 'handler' for the event specified by 'eventClass' and 'eventID'. If an event handler is already registered for the specified event class and event ID, removes it. The signature for 'handler' should match the following: '''objc - (void)handleAppleEvent:(NSAppleEventDescriptor )event withReplyEvent:(NSAppleEventDescriptor )replyEvent; ''' When it is invoked, the value of the first parameter will be the event to be handled. The value of the second parameter will be the reply event to fill in. A reply event object will always be passed in (replyEvent will never be nil), but it should not be touched if the event sender has not requested a reply, which is indicated by '[replyEvent descriptorType]==typeNull'.
         * @param handler Argument converted to the Objective-C parameter of the same role.
         * @param handle_event_selector Argument converted to the Objective-C parameter of the same role.
         * @param event_class Argument converted to the Objective-C parameter of the same role.
         * @param event_id Argument converted to the Objective-C parameter of the same role.
         */
        void set_event_handler(const Object& handler, const std::string& handle_event_selector, unsigned int event_class, unsigned int event_id) const;
        /**
         * @brief Calls `+[NSAppleEventManager sharedAppleEventManager]`.
         * @details Returns the single instance of 'NSAppleEventManager', creating it first if it doesn't exist.
         * @return The converted Objective-C result.
         */
        static AppleEventManager shared_apple_event_manager();
        /**
         * @brief Calls `-[NSAppleEventManager suspendCurrentAppleEvent]`.
         * @details Suspends the handling of the current event and returns an ID that must be used to resume the handling of the event if an Apple event is being handled on the current thread. An Apple event is being handled on the current thread if 'currentAppleEvent' does not return 'nil'. Returns zero otherwise. The suspended event is no longer the current event after this method returns.
         * @return The converted Objective-C result.
         */
        AppleEventManagerSuspensionID suspend_current_apple_event() const;
        /**
         * @brief Returns the `currentAppleEvent` property of `NSAppleEventManager`.
         * @details Returns the descriptor for 'currentAppleEvent' if an Apple event is being handled on the current thread. An Apple event is being handled on the current thread if a handler that was registered with '-setEventHandler:andSelector:forEventClass:andEventID:' is being messaged at this instant or '-setCurrentAppleEventAndReplyEventWithSuspensionID:' has just been invoked. Returns 'nil' otherwise. The effects of mutating or retaining the returned descriptor are undefined, although it may be copied.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor current_apple_event() const;
        /**
         * @brief Returns the `currentReplyAppleEvent` property of `NSAppleEventManager`.
         * @details Returns the corresponding reply event descriptor if an Apple event is being handled on the current thread. An Apple event is being handled on the current thread if 'currentAppleEvent' does not return 'nil'. Returns 'nil' otherwise. This descriptor, including any mutations, will be returned to the sender of the current event when all handling of the event has been completed, if the sender has requested a reply. The effects of retaining the descriptor are undefined; it may be copied, but mutations of the copy are not returned to the sender of the current event.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor current_reply_apple_event() const;
    };
}
