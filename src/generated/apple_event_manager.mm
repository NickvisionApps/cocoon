#include "generated/apple_event_manager.h"
#include "internal.h"

namespace cocoon
{
    AppleEventManager::AppleEventManager() : AppleEventManager(Adopt{cocoon::internal::retain([[::NSAppleEventManager alloc] init])})
    {
    }

    AppleEventManager::AppleEventManager(std::nullptr_t) : Object(nullptr)
    {
    }

    AppleEventManager::AppleEventManager(Adopt adopt) : Object(adopt)
    {
    }

    AppleEventDescriptor AppleEventManager::apple_event_for_suspension_id(const AppleEventManagerSuspensionID& suspension_id) const
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([cocoon::internal::ns<::NSAppleEventManager>(this) appleEventForSuspensionID:((::NSAppleEventManagerSuspensionID)(suspension_id).handle())]);
    }

    std::int16_t AppleEventManager::dispatch_raw_apple_event(const AEDesc* the_apple_event, AEDesc* the_reply, void* handler_ref_con) const
    {
        return static_cast<std::int16_t>([cocoon::internal::ns<::NSAppleEventManager>(this) dispatchRawAppleEvent:(const ::AppleEvent*)(the_apple_event) withRawReply:(::AppleEvent*)(the_reply)handlerRefCon:handler_ref_con]);
    }

    void AppleEventManager::remove_event_handler_for_event_class(unsigned int event_class, unsigned int event_id) const
    {
        [cocoon::internal::ns<::NSAppleEventManager>(this) removeEventHandlerForEventClass:static_cast<::AEEventClass>(event_class) andEventID:static_cast<::AEEventID>(event_id)];
    }

    AppleEventDescriptor AppleEventManager::reply_apple_event_for_suspension_id(const AppleEventManagerSuspensionID& suspension_id) const
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([cocoon::internal::ns<::NSAppleEventManager>(this) replyAppleEventForSuspensionID:((::NSAppleEventManagerSuspensionID)(suspension_id).handle())]);
    }

    void AppleEventManager::resume_with_suspension_id(const AppleEventManagerSuspensionID& suspension_id) const
    {
        [cocoon::internal::ns<::NSAppleEventManager>(this) resumeWithSuspensionID:((::NSAppleEventManagerSuspensionID)(suspension_id).handle())];
    }

    void AppleEventManager::set_current_apple_event_and_reply_event_with_suspension_id(const AppleEventManagerSuspensionID& suspension_id) const
    {
        [cocoon::internal::ns<::NSAppleEventManager>(this) setCurrentAppleEventAndReplyEventWithSuspensionID:((::NSAppleEventManagerSuspensionID)(suspension_id).handle())];
    }

    void AppleEventManager::set_event_handler(const Object& handler, const std::string& handle_event_selector, unsigned int event_class, unsigned int event_id) const
    {
        [cocoon::internal::ns<::NSAppleEventManager>(this) setEventHandler:cocoon::internal::native_id(handler) andSelector:NSSelectorFromString(cocoon::internal::to(handle_event_selector)) forEventClass:static_cast<::AEEventClass>(event_class) andEventID:static_cast<::AEEventID>(event_id)];
    }

    AppleEventManager AppleEventManager::shared_apple_event_manager()
    {
        return cocoon::internal::wrap<AppleEventManager>([::NSAppleEventManager sharedAppleEventManager]);
    }

    AppleEventManagerSuspensionID AppleEventManager::suspend_current_apple_event() const
    {
        return cocoon::internal::wrap_cf<AppleEventManagerSuspensionID>((const void*)([cocoon::internal::ns<::NSAppleEventManager>(this) suspendCurrentAppleEvent]));
    }

    AppleEventDescriptor AppleEventManager::current_apple_event() const
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([cocoon::internal::ns<::NSAppleEventManager>(this) currentAppleEvent]);
    }

    AppleEventDescriptor AppleEventManager::current_reply_apple_event() const
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([cocoon::internal::ns<::NSAppleEventManager>(this) currentReplyAppleEvent]);
    }
}
