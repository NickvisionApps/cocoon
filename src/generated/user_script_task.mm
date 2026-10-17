#include "generated/user_script_task.h"
#include "internal.h"

namespace cocoon
{
    UserScriptTask::UserScriptTask(const URL& url) : UserScriptTask(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                   {
                                                                                                       NSError* __error = nil;
                                                                                                       id __r = [[::NSUserScriptTask alloc] initWithURL:cocoon::internal::native<::NSURL>(url) error:&__error];
                                                                                                       if (!__r && __error)
                                                                                                       {
                                                                                                           throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                       }
                                                                                                       return __r;
                                                                                                   }())})
    {
    }

    UserScriptTask::UserScriptTask() : UserScriptTask(Adopt{cocoon::internal::retain([[::NSUserScriptTask alloc] init])})
    {
    }

    UserScriptTask::UserScriptTask(std::nullptr_t) : Object(nullptr)
    {
    }

    UserScriptTask::UserScriptTask(Adopt adopt) : Object(adopt)
    {
    }

    void UserScriptTask::execute_with_completion_handler(std::function<void(Error)> handler) const
    {
        [cocoon::internal::ns<::NSUserScriptTask>(this) executeWithCompletionHandler:(handler ? (::NSUserScriptTaskCompletionHandler) ^ void(::NSError * a255_0) { handler(cocoon::internal::wrap<Error>(a255_0)); } : (::NSUserScriptTaskCompletionHandler)nil)];
    }

    URL UserScriptTask::script_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSUserScriptTask>(this) scriptURL]);
    }
}
