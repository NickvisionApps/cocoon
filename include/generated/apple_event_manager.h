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
         * @param suspension_id Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor apple_event_for_suspension_id(const AppleEventManagerSuspensionID& suspension_id) const;
        /**
         * @brief Calls `-[NSAppleEventManager dispatchRawAppleEvent:withRawReply:handlerRefCon:]`.
         * @param the_apple_event Argument converted to the Objective-C parameter of the same role.
         * @param the_reply Argument converted to the Objective-C parameter of the same role.
         * @param handler_ref_con Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int16_t dispatch_raw_apple_event(const AEDesc* the_apple_event, AEDesc* the_reply, void* handler_ref_con) const;
        /**
         * @brief Calls `-[NSAppleEventManager removeEventHandlerForEventClass:andEventID:]`.
         * @param event_class Argument converted to the Objective-C parameter of the same role.
         * @param event_id Argument converted to the Objective-C parameter of the same role.
         */
        void remove_event_handler_for_event_class(unsigned int event_class, unsigned int event_id) const;
        /**
         * @brief Calls `-[NSAppleEventManager replyAppleEventForSuspensionID:]`.
         * @param suspension_id Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor reply_apple_event_for_suspension_id(const AppleEventManagerSuspensionID& suspension_id) const;
        /**
         * @brief Calls `-[NSAppleEventManager resumeWithSuspensionID:]`.
         * @param suspension_id Argument converted to the Objective-C parameter of the same role.
         */
        void resume_with_suspension_id(const AppleEventManagerSuspensionID& suspension_id) const;
        /**
         * @brief Calls `-[NSAppleEventManager setCurrentAppleEventAndReplyEventWithSuspensionID:]`.
         * @param suspension_id Argument converted to the Objective-C parameter of the same role.
         */
        void set_current_apple_event_and_reply_event_with_suspension_id(const AppleEventManagerSuspensionID& suspension_id) const;
        /**
         * @brief Calls `-[NSAppleEventManager setEventHandler:andSelector:forEventClass:andEventID:]`.
         * @param handler Argument converted to the Objective-C parameter of the same role.
         * @param handle_event_selector Argument converted to the Objective-C parameter of the same role.
         * @param event_class Argument converted to the Objective-C parameter of the same role.
         * @param event_id Argument converted to the Objective-C parameter of the same role.
         */
        void set_event_handler(const Object& handler, const std::string& handle_event_selector, unsigned int event_class, unsigned int event_id) const;
        /**
         * @brief Calls `+[NSAppleEventManager sharedAppleEventManager]`.
         * @return The converted Objective-C result.
         */
        static AppleEventManager shared_apple_event_manager();
        /**
         * @brief Calls `-[NSAppleEventManager suspendCurrentAppleEvent]`.
         * @return The converted Objective-C result.
         */
        AppleEventManagerSuspensionID suspend_current_apple_event() const;
        /**
         * @brief Returns the `currentAppleEvent` property of `NSAppleEventManager`.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor current_apple_event() const;
        /**
         * @brief Returns the `currentReplyAppleEvent` property of `NSAppleEventManager`.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor current_reply_apple_event() const;
    };
}
