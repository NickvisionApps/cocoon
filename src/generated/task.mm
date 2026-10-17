#include "generated/task.h"
#include "internal.h"

namespace cocoon
{
    Task::Task() : Task(Adopt{cocoon::internal::retain([[::NSTask alloc] init])})
    {
    }

    Task::Task(std::nullptr_t) : Object(nullptr)
    {
    }

    Task::Task(Adopt adopt) : Object(adopt)
    {
    }

    void Task::interrupt() const
    {
        [cocoon::internal::ns<::NSTask>(this) interrupt];
    }

    void Task::launch() const
    {
        [cocoon::internal::ns<::NSTask>(this) launch];
    }

    bool Task::launch_and_return_error() const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSTask>(this) launchAndReturnError:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    Task Task::launched_task_with_executable_url(const URL& url, const std::vector<std::string>& arguments, std::function<void(Task)> termination_handler)
    {
        NSError* __error = nil;
        auto __r = [::NSTask launchedTaskWithExecutableURL:cocoon::internal::native<::NSURL>(url)
                                                 arguments:cocoon::internal::to_array(arguments, [](const std::string& e) -> id
                                                                                      {
                                                                                          return cocoon::internal::to(e);
                                                                                      })
                                                     error:&__error
                                        terminationHandler:(termination_handler ? (void (^)(::NSTask*)) ^ void(::NSTask * a220_0) { termination_handler(cocoon::internal::wrap<Task>(a220_0)); } : (void (^)(::NSTask*))nil)];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Task>(__r);
    }

    Task Task::launched_task_with_launch_path(const std::string& path, const std::vector<std::string>& arguments)
    {
        return cocoon::internal::wrap<Task>([::NSTask launchedTaskWithLaunchPath:cocoon::internal::to(path)
                                                                       arguments:cocoon::internal::to_array(arguments, [](const std::string& e) -> id
                                                                                                            {
                                                                                                                return cocoon::internal::to(e);
                                                                                                            })]);
    }

    bool Task::resume() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTask>(this) resume]);
    }

    bool Task::suspend() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTask>(this) suspend]);
    }

    void Task::terminate() const
    {
        [cocoon::internal::ns<::NSTask>(this) terminate];
    }

    void Task::wait_until_exit() const
    {
        [cocoon::internal::ns<::NSTask>(this) waitUntilExit];
    }

    std::vector<std::string> Task::arguments() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTask>(this) arguments], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void Task::set_arguments(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSTask>(this) setArguments:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                      {
                                                                                          return cocoon::internal::to(e);
                                                                                      })];
    }

    std::string Task::current_directory_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTask>(this) currentDirectoryPath]);
    }

    void Task::set_current_directory_path(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTask>(this) setCurrentDirectoryPath:cocoon::internal::to(value)];
    }

    URL Task::current_directory_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSTask>(this) currentDirectoryURL]);
    }

    void Task::set_current_directory_url(const URL& value) const
    {
        [cocoon::internal::ns<::NSTask>(this) setCurrentDirectoryURL:cocoon::internal::native<::NSURL>(value)];
    }

    std::map<std::string, std::string> Task::environment() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::string>>([cocoon::internal::ns<::NSTask>(this) environment], [](id k) -> std::string
                                                                                     {
                                                                                         return cocoon::internal::from((NSString*)k);
                                                                                     },
                                                                                     [](id v) -> std::string
                                                                                     {
                                                                                         return cocoon::internal::from((NSString*)v);
                                                                                     });
    }

    void Task::set_environment(const std::map<std::string, std::string>& value) const
    {
        [cocoon::internal::ns<::NSTask>(this) setEnvironment:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                             {
                                                                                                 return cocoon::internal::to(k);
                                                                                             },
                                                                                             [](const std::string& v) -> id
                                                                                             {
                                                                                                 return cocoon::internal::to(v);
                                                                                             })];
    }

    URL Task::executable_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSTask>(this) executableURL]);
    }

    void Task::set_executable_url(const URL& value) const
    {
        [cocoon::internal::ns<::NSTask>(this) setExecutableURL:cocoon::internal::native<::NSURL>(value)];
    }

    std::string Task::launch_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTask>(this) launchPath]);
    }

    void Task::set_launch_path(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTask>(this) setLaunchPath:cocoon::internal::to(value)];
    }

    std::vector<std::uint8_t> Task::launch_requirement_data() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSTask>(this) launchRequirementData]);
    }

    void Task::set_launch_requirement_data(const std::vector<std::uint8_t>& value) const
    {
        [cocoon::internal::ns<::NSTask>(this) setLaunchRequirementData:cocoon::internal::to_data(value)];
    }

    int Task::process_identifier() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSTask>(this) processIdentifier]);
    }

    QualityOfService Task::quality_of_service() const
    {
        return static_cast<QualityOfService>([cocoon::internal::ns<::NSTask>(this) qualityOfService]);
    }

    void Task::set_quality_of_service(QualityOfService value) const
    {
        [cocoon::internal::ns<::NSTask>(this) setQualityOfService:static_cast<::NSQualityOfService>(value)];
    }

    bool Task::is_running() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTask>(this) isRunning]);
    }

    Object Task::standard_error() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTask>(this) standardError]);
    }

    void Task::set_standard_error(const Object& value) const
    {
        [cocoon::internal::ns<::NSTask>(this) setStandardError:cocoon::internal::native_id(value)];
    }

    Object Task::standard_input() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTask>(this) standardInput]);
    }

    void Task::set_standard_input(const Object& value) const
    {
        [cocoon::internal::ns<::NSTask>(this) setStandardInput:cocoon::internal::native_id(value)];
    }

    Object Task::standard_output() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTask>(this) standardOutput]);
    }

    void Task::set_standard_output(const Object& value) const
    {
        [cocoon::internal::ns<::NSTask>(this) setStandardOutput:cocoon::internal::native_id(value)];
    }

    std::function<void(Task)> Task::termination_handler() const
    {
        return [&]() -> std::function<void(Task)>
        {
            auto blk = (void (^)(::NSTask*))([cocoon::internal::ns<::NSTask>(this) terminationHandler]);
            if (!blk)
            {
                return {};
            }
            return [blk](Task a221_0) -> void
            {
                blk(cocoon::internal::native<::NSTask>(a221_0));
            };
        }();
    }

    void Task::set_termination_handler(std::function<void(Task)> value) const
    {
        [cocoon::internal::ns<::NSTask>(this) setTerminationHandler:(value ? (void (^)(::NSTask*)) ^ void(::NSTask * a222_0) { value(cocoon::internal::wrap<Task>(a222_0)); } : (void (^)(::NSTask*))nil)];
    }

    TaskTerminationReason Task::termination_reason() const
    {
        return static_cast<TaskTerminationReason>([cocoon::internal::ns<::NSTask>(this) terminationReason]);
    }

    int Task::termination_status() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSTask>(this) terminationStatus]);
    }
}
