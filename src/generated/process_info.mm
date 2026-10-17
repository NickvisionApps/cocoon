#include "generated/process_info.h"
#include "internal.h"

namespace cocoon
{
    ProcessInfo::ProcessInfo() : ProcessInfo(Adopt{cocoon::internal::retain([NSProcessInfo processInfo])})
    {
    }

    ProcessInfo::ProcessInfo(std::nullptr_t) : Object(nullptr)
    {
    }

    ProcessInfo::ProcessInfo(Adopt adopt) : Object(adopt)
    {
    }

    Object ProcessInfo::begin_activity_with_options(ActivityOptions options, const std::string& reason) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSProcessInfo>(this) beginActivityWithOptions:static_cast<::NSActivityOptions>(options) reason:cocoon::internal::to(reason)]);
    }

    void ProcessInfo::disable_automatic_termination(const std::string& reason) const
    {
        [cocoon::internal::ns<::NSProcessInfo>(this) disableAutomaticTermination:cocoon::internal::to(reason)];
    }

    void ProcessInfo::disable_sudden_termination() const
    {
        [cocoon::internal::ns<::NSProcessInfo>(this) disableSuddenTermination];
    }

    void ProcessInfo::enable_automatic_termination(const std::string& reason) const
    {
        [cocoon::internal::ns<::NSProcessInfo>(this) enableAutomaticTermination:cocoon::internal::to(reason)];
    }

    void ProcessInfo::enable_sudden_termination() const
    {
        [cocoon::internal::ns<::NSProcessInfo>(this) enableSuddenTermination];
    }

    void ProcessInfo::end_activity(const Object& activity) const
    {
        [cocoon::internal::ns<::NSProcessInfo>(this) endActivity:cocoon::internal::native_id(activity)];
    }

    bool ProcessInfo::is_operating_system_at_least_version(const OperatingSystemVersion& version) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSProcessInfo>(this) isOperatingSystemAtLeastVersion:cocoon::internal::to(version)]);
    }

    void ProcessInfo::perform_activity_with_options(ActivityOptions options, const std::string& reason, std::function<void()> block) const
    {
        [cocoon::internal::ns<::NSProcessInfo>(this) performActivityWithOptions:static_cast<::NSActivityOptions>(options) reason:cocoon::internal::to(reason) usingBlock:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)];
    }

    std::uint64_t ProcessInfo::active_processor_count() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSProcessInfo>(this) activeProcessorCount]);
    }

    std::vector<std::string> ProcessInfo::arguments() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSProcessInfo>(this) arguments], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    bool ProcessInfo::automatic_termination_support_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSProcessInfo>(this) automaticTerminationSupportEnabled]);
    }

    void ProcessInfo::set_automatic_termination_support_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSProcessInfo>(this) setAutomaticTerminationSupportEnabled:static_cast<::BOOL>(value)];
    }

    std::map<std::string, std::string> ProcessInfo::environment() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::string>>([cocoon::internal::ns<::NSProcessInfo>(this) environment], [](id k) -> std::string
                                                                       {
                                                                           return cocoon::internal::from((NSString*)k);
                                                                       },
                                                                       [](id v) -> std::string
                                                                       {
                                                                           return cocoon::internal::from((NSString*)v);
                                                                       });
    }

    std::string ProcessInfo::full_user_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSProcessInfo>(this) fullUserName]);
    }

    std::string ProcessInfo::globally_unique_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSProcessInfo>(this) globallyUniqueString]);
    }

    std::string ProcessInfo::host_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSProcessInfo>(this) hostName]);
    }

    bool ProcessInfo::isi_os_app_on_mac() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSProcessInfo>(this) isiOSAppOnMac]);
    }

    bool ProcessInfo::isi_os_app_on_vision() const
    {
        if (@available(macOS 26.1, *))
        {
            return static_cast<bool>([cocoon::internal::ns<::NSProcessInfo>(this) isiOSAppOnVision]);
        }
        return {};
    }

    bool ProcessInfo::is_low_power_mode_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSProcessInfo>(this) isLowPowerModeEnabled]);
    }

    bool ProcessInfo::is_mac_catalyst_app() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSProcessInfo>(this) isMacCatalystApp]);
    }

    OperatingSystemVersion ProcessInfo::operating_system_version() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSProcessInfo>(this) operatingSystemVersion]);
    }

    std::string ProcessInfo::operating_system_version_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSProcessInfo>(this) operatingSystemVersionString]);
    }

    std::uint64_t ProcessInfo::physical_memory() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSProcessInfo>(this) physicalMemory]);
    }

    int ProcessInfo::process_identifier() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSProcessInfo>(this) processIdentifier]);
    }

    ProcessInfo ProcessInfo::process_info()
    {
        return cocoon::internal::wrap<ProcessInfo>([::NSProcessInfo processInfo]);
    }

    std::string ProcessInfo::process_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSProcessInfo>(this) processName]);
    }

    void ProcessInfo::set_process_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSProcessInfo>(this) setProcessName:cocoon::internal::to(value)];
    }

    std::uint64_t ProcessInfo::processor_count() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSProcessInfo>(this) processorCount]);
    }

    double ProcessInfo::system_uptime() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSProcessInfo>(this) systemUptime]);
    }

    ProcessInfoThermalState ProcessInfo::thermal_state() const
    {
        return static_cast<ProcessInfoThermalState>([cocoon::internal::ns<::NSProcessInfo>(this) thermalState]);
    }

    std::string ProcessInfo::user_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSProcessInfo>(this) userName]);
    }
}
