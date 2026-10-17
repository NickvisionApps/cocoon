#include "generated/user_apple_script_task.h"
#include "internal.h"

namespace cocoon
{
    UserAppleScriptTask::UserAppleScriptTask() : UserAppleScriptTask(Adopt{cocoon::internal::retain([[::NSUserAppleScriptTask alloc] init])})
    {
    }

    UserAppleScriptTask::UserAppleScriptTask(std::nullptr_t) : UserScriptTask(nullptr)
    {
    }

    UserAppleScriptTask::UserAppleScriptTask(Adopt adopt) : UserScriptTask(adopt)
    {
    }

    void UserAppleScriptTask::execute_with_apple_event(const AppleEventDescriptor& event, std::function<void(AppleEventDescriptor, Error)> handler) const
    {
        [cocoon::internal::ns<::NSUserAppleScriptTask>(this) executeWithAppleEvent:cocoon::internal::native<::NSAppleEventDescriptor>(event) completionHandler:(handler ? (::NSUserAppleScriptTaskCompletionHandler) ^ void(::NSAppleEventDescriptor * a257_0, ::NSError * a257_1) { handler(cocoon::internal::wrap<AppleEventDescriptor>(a257_0), cocoon::internal::wrap<Error>(a257_1)); } : (::NSUserAppleScriptTaskCompletionHandler)nil)];
    }
}
