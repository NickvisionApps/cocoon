#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief Information about the running process (NSProcessInfo).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * cocoon::ProcessInfo info;
     * std::string name = info.process_name();
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ProcessInfo process_info{};
     * process_info.set_automatic_termination_support_enabled(true);
     * auto automatic_termination_support_enabled = process_info.automatic_termination_support_enabled();
     * process_info.set_process_name("text");
     * auto process_name = process_info.process_name();
     * process_info.begin_activity_with_options(cocoon::ActivityOptions::IdleDisplaySleepDisabled, "text");
     * process_info.disable_automatic_termination("text");
     * process_info.disable_sudden_termination();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsprocessinfo
     */
    class ProcessInfo : public Object
    {
    public:
        /// @brief Creates a new `NSProcessInfo` instance and returns a handle to it.
        explicit ProcessInfo();
        /// @brief Creates a null handle that refers to no native object.
        ProcessInfo(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ProcessInfo(Adopt adopt);
        /**
         * @brief Calls `-[NSProcessInfo beginActivityWithOptions:reason:]`.
         * @details Pass in an activity to this API, and a non-NULL, non-empty reason string. Indicate completion of the activity by calling the corresponding endActivity: method with the result of the beginActivityWithOptions:reason: method. The reason string is used for debugging.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param reason Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object begin_activity_with_options(ActivityOptions options, const std::string& reason) const;
        /**
         * @brief Calls `-[NSProcessInfo disableAutomaticTermination:]`.
         * @details Increment or decrement the counter tracking the number of automatic quit opt-out requests. When this counter is greater than zero, the app will be considered 'active' and ineligible for automatic termination. An example of using this would be disabling autoquitting when the user of an instant messaging application signs on, due to it requiring a background connection to be maintained even if the app is otherwise inactive. Each pair of calls should have a matching "reason" argument, which can be used to easily track why an application is or is not automatically terminable. A given reason can be used more than once at the same time (for example: two files are transferring over the network, each one disables automatic termination with the reason \@"file transfer in progress")
         * @param reason Argument converted to the Objective-C parameter of the same role.
         */
        void disable_automatic_termination(const std::string& reason) const;
        /**
         * @brief Calls `-[NSProcessInfo disableSuddenTermination]`.
         * @details Disable or reenable the ability to be quickly killed. The default implementations of these methods increment or decrement, respectively, a counter whose value is 1 when the process is first created. When the counter's value is 0 the application is considered to be safely killable and may be killed by the operating system without any notification or event being sent to the process first. If an application's Info.plist has an NSSupportsSuddenTermination entry whose value is true then NSApplication invokes -enableSuddenTermination automatically during application launch, which typically renders the process killable right away. You can also manually invoke -enableSuddenTermination right away in, for example, agents or daemons that don't depend on AppKit. After that, you can invoke these methods whenever the process has work it must do before it terminates. For example: - NSUserDefaults uses these to prevent process killing between the time at which a default has been set and the time at which the preferences file including that default has been written to disk. - NSDocument uses these to prevent process killing between the time at which the user has made a change to a document and the time at which the user's change has been written to disk. - You can use these whenever your application defers work that must be done before the application terminates. If for example your application ever defers writing something to disk, and it has an NSSupportsSuddenTermination entry in its Info.plist so as not to contribute to user-visible delays at logout or shutdown time, it must invoke -disableSuddenTermination when the writing is first deferred and -enableSuddenTermination after the writing is actually done.
         */
        void disable_sudden_termination() const;
        /**
         * @brief Calls `-[NSProcessInfo enableAutomaticTermination:]`.
         * @param reason Argument converted to the Objective-C parameter of the same role.
         */
        void enable_automatic_termination(const std::string& reason) const;
        /**
         * @brief Calls `-[NSProcessInfo enableSuddenTermination]`.
         */
        void enable_sudden_termination() const;
        /**
         * @brief Calls `-[NSProcessInfo endActivity:]`.
         * @details The argument to this method is the result of beginActivityWithOptions:reason:.
         * @param activity Argument converted to the Objective-C parameter of the same role.
         */
        void end_activity(const Object& activity) const;
        /**
         * @brief Calls `-[NSProcessInfo isOperatingSystemAtLeastVersion:]`.
         * @param version Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_operating_system_at_least_version(const OperatingSystemVersion& version) const;
        /**
         * @brief Calls `-[NSProcessInfo performActivityWithOptions:reason:usingBlock:]`.
         * @details Synchronously perform an activity. The activity will be automatically ended after your block argument returns. The reason string is used for debugging.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param reason Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void perform_activity_with_options(ActivityOptions options, const std::string& reason, std::function<void()> block) const;
        /**
         * @brief Returns the `activeProcessorCount` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        std::uint64_t active_processor_count() const;
        /**
         * @brief Returns the `arguments` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> arguments() const;
        /**
         * @brief Returns the `automaticTerminationSupportEnabled` property of `NSProcessInfo`.
         * @details Marks the calling app as supporting automatic termination. Without calling this or setting the equivalent Info.plist key (NSSupportsAutomaticTermination), the above methods (disableAutomaticTermination:/enableAutomaticTermination:) have no effect, although the counter tracking automatic termination opt-outs is still kept up to date to ensure correctness if this is called later. Currently, passing NO has no effect. This should be called during -applicationDidFinishLaunching or earlier.
         * @return The converted Objective-C result.
         */
        bool automatic_termination_support_enabled() const;
        /**
         * @brief Sets the `automaticTerminationSupportEnabled` property of `NSProcessInfo`.
         * @details Marks the calling app as supporting automatic termination. Without calling this or setting the equivalent Info.plist key (NSSupportsAutomaticTermination), the above methods (disableAutomaticTermination:/enableAutomaticTermination:) have no effect, although the counter tracking automatic termination opt-outs is still kept up to date to ensure correctness if this is called later. Currently, passing NO has no effect. This should be called during -applicationDidFinishLaunching or earlier.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatic_termination_support_enabled(bool value) const;
        /**
         * @brief Returns the `environment` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, std::string> environment() const;
        /**
         * @brief Returns the `fullUserName` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        std::string full_user_name() const;
        /**
         * @brief Returns the `globallyUniqueString` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        std::string globally_unique_string() const;
        /**
         * @brief Returns the `hostName` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        std::string host_name() const;
        /**
         * @brief Returns the `iOSAppOnMac` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        bool isi_os_app_on_mac() const;
        /**
         * @brief Returns the `iOSAppOnVision` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        bool isi_os_app_on_vision() const;
        /**
         * @brief Returns the `lowPowerModeEnabled` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        bool is_low_power_mode_enabled() const;
        /**
         * @brief Returns the `macCatalystApp` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        bool is_mac_catalyst_app() const;
        /**
         * @brief Returns the `operatingSystemVersion` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        OperatingSystemVersion operating_system_version() const;
        /**
         * @brief Returns the `operatingSystemVersionString` property of `NSProcessInfo`.
         * @details Human readable, localized; appropriate for displaying to user or using in bug emails and such; NOT appropriate for parsing
         * @return The converted Objective-C result.
         */
        std::string operating_system_version_string() const;
        /**
         * @brief Returns the `physicalMemory` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        std::uint64_t physical_memory() const;
        /**
         * @brief Returns the `processIdentifier` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        int process_identifier() const;
        /**
         * @brief Returns the `processInfo` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        static ProcessInfo process_info();
        /**
         * @brief Returns the `processName` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        std::string process_name() const;
        /**
         * @brief Sets the `processName` property of `NSProcessInfo`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_process_name(const std::string& value) const;
        /**
         * @brief Returns the `processorCount` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        std::uint64_t processor_count() const;
        /**
         * @brief Returns the `systemUptime` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        double system_uptime() const;
        /**
         * @brief Returns the `thermalState` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        ProcessInfoThermalState thermal_state() const;
        /**
         * @brief Returns the `userName` property of `NSProcessInfo`.
         * @return The converted Objective-C result.
         */
        std::string user_name() const;
    };
}
