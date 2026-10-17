#include "generated/user_automator_task.h"
#include "internal.h"

namespace cocoon
{
    UserAutomatorTask::UserAutomatorTask() : UserAutomatorTask(Adopt{cocoon::internal::retain([[::NSUserAutomatorTask alloc] init])})
    {
    }

    UserAutomatorTask::UserAutomatorTask(std::nullptr_t) : UserScriptTask(nullptr)
    {
    }

    UserAutomatorTask::UserAutomatorTask(Adopt adopt) : UserScriptTask(adopt)
    {
    }

    void UserAutomatorTask::execute_with_input(const Object& input, std::function<void(Object, Error)> handler) const
    {
        [cocoon::internal::ns<::NSUserAutomatorTask>(this) executeWithInput:cocoon::internal::native_id(input) completionHandler:(handler ? (::NSUserAutomatorTaskCompletionHandler) ^ void(id a258_0, ::NSError * a258_1) { handler(cocoon::internal::wrap<Object>(a258_0), cocoon::internal::wrap<Error>(a258_1)); } : (::NSUserAutomatorTaskCompletionHandler)nil)];
    }

    std::map<std::string, Object> UserAutomatorTask::variables() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSUserAutomatorTask>(this) variables], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void UserAutomatorTask::set_variables(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSUserAutomatorTask>(this) setVariables:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                                        {
                                                                                                            return cocoon::internal::to(k);
                                                                                                        },
                                                                                                        [](const Object& v) -> id
                                                                                                        {
                                                                                                            return cocoon::internal::native_id(v);
                                                                                                        })];
    }
}
