#include "generated/running_application.h"
#include "internal.h"

namespace cocoon
{
    RunningApplication::RunningApplication() : RunningApplication(Adopt{cocoon::internal::retain([[::NSRunningApplication alloc] init])})
    {
    }

    RunningApplication::RunningApplication(std::nullptr_t) : Object(nullptr)
    {
    }

    RunningApplication::RunningApplication(Adopt adopt) : Object(adopt)
    {
    }

    bool RunningApplication::activate_from_application(const RunningApplication& application, ApplicationActivationOptions options) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRunningApplication>(this) activateFromApplication:cocoon::internal::native<::NSRunningApplication>(application) options:static_cast<::NSApplicationActivationOptions>(options)]);
    }

    bool RunningApplication::activate_with_options(ApplicationActivationOptions options) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRunningApplication>(this) activateWithOptions:static_cast<::NSApplicationActivationOptions>(options)]);
    }

    bool RunningApplication::force_terminate() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRunningApplication>(this) forceTerminate]);
    }

    bool RunningApplication::hide() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRunningApplication>(this) hide]);
    }

    RunningApplication RunningApplication::running_application_with_process_identifier(int pid)
    {
        return cocoon::internal::wrap<RunningApplication>([::NSRunningApplication runningApplicationWithProcessIdentifier:static_cast<::pid_t>(pid)]);
    }

    std::vector<RunningApplication> RunningApplication::running_applications_with_bundle_identifier(const std::string& bundle_identifier)
    {
        return cocoon::internal::from_array<RunningApplication>([::NSRunningApplication runningApplicationsWithBundleIdentifier:cocoon::internal::to(bundle_identifier)], [](id e) -> RunningApplication
                                                  {
                                                      return cocoon::internal::wrap<RunningApplication>((::NSRunningApplication*)e);
                                                  });
    }

    bool RunningApplication::terminate() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRunningApplication>(this) terminate]);
    }

    void RunningApplication::terminate_automatically_terminable_applications()
    {
        [::NSRunningApplication terminateAutomaticallyTerminableApplications];
    }

    bool RunningApplication::unhide() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRunningApplication>(this) unhide]);
    }

    ActivationPolicy RunningApplication::activation_policy() const
    {
        return static_cast<ActivationPolicy>([cocoon::internal::ns<::NSRunningApplication>(this) activationPolicy]);
    }

    bool RunningApplication::is_active() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRunningApplication>(this) isActive]);
    }

    std::string RunningApplication::bundle_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRunningApplication>(this) bundleIdentifier]);
    }

    URL RunningApplication::bundle_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSRunningApplication>(this) bundleURL]);
    }

    RunningApplication RunningApplication::current_application()
    {
        return cocoon::internal::wrap<RunningApplication>([::NSRunningApplication currentApplication]);
    }

    std::int64_t RunningApplication::executable_architecture() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSRunningApplication>(this) executableArchitecture]);
    }

    URL RunningApplication::executable_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSRunningApplication>(this) executableURL]);
    }

    bool RunningApplication::is_finished_launching() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRunningApplication>(this) isFinishedLaunching]);
    }

    bool RunningApplication::is_hidden() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRunningApplication>(this) isHidden]);
    }

    Image RunningApplication::icon() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSRunningApplication>(this) icon]);
    }

    Date RunningApplication::launch_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSRunningApplication>(this) launchDate]);
    }

    std::string RunningApplication::localized_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRunningApplication>(this) localizedName]);
    }

    bool RunningApplication::owns_menu_bar() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRunningApplication>(this) ownsMenuBar]);
    }

    int RunningApplication::process_identifier() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSRunningApplication>(this) processIdentifier]);
    }

    bool RunningApplication::is_terminated() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRunningApplication>(this) isTerminated]);
    }
}
