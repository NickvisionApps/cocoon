#include "generated/user_unix_task.h"
#include "internal.h"

namespace cocoon
{
    UserUnixTask::UserUnixTask() : UserUnixTask(Adopt{cocoon::internal::retain([[::NSUserUnixTask alloc] init])})
    {
    }

    UserUnixTask::UserUnixTask(std::nullptr_t) : UserScriptTask(nullptr)
    {
    }

    UserUnixTask::UserUnixTask(Adopt adopt) : UserScriptTask(adopt)
    {
    }

    void UserUnixTask::execute_with_arguments(const std::vector<std::string>& arguments, std::function<void(Error)> handler) const
    {
        [cocoon::internal::ns<::NSUserUnixTask>(this) executeWithArguments:cocoon::internal::to_array(arguments, [](const std::string& e) -> id
                                                                          {
                                                                              return cocoon::internal::to(e);
                                                                          })
                                           completionHandler:(handler ? (::NSUserUnixTaskCompletionHandler) ^ void(::NSError * a256_0) { handler(cocoon::internal::wrap<Error>(a256_0)); } : (::NSUserUnixTaskCompletionHandler)nil)];
    }

    FileHandle UserUnixTask::standard_error() const
    {
        return cocoon::internal::wrap<FileHandle>([cocoon::internal::ns<::NSUserUnixTask>(this) standardError]);
    }

    void UserUnixTask::set_standard_error(const FileHandle& value) const
    {
        [cocoon::internal::ns<::NSUserUnixTask>(this) setStandardError:cocoon::internal::native<::NSFileHandle>(value)];
    }

    FileHandle UserUnixTask::standard_input() const
    {
        return cocoon::internal::wrap<FileHandle>([cocoon::internal::ns<::NSUserUnixTask>(this) standardInput]);
    }

    void UserUnixTask::set_standard_input(const FileHandle& value) const
    {
        [cocoon::internal::ns<::NSUserUnixTask>(this) setStandardInput:cocoon::internal::native<::NSFileHandle>(value)];
    }

    FileHandle UserUnixTask::standard_output() const
    {
        return cocoon::internal::wrap<FileHandle>([cocoon::internal::ns<::NSUserUnixTask>(this) standardOutput]);
    }

    void UserUnixTask::set_standard_output(const FileHandle& value) const
    {
        [cocoon::internal::ns<::NSUserUnixTask>(this) setStandardOutput:cocoon::internal::native<::NSFileHandle>(value)];
    }
}
