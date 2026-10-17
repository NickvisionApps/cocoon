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
     * @details A collection of information about the current process. Each process has a single, shared ''ProcessInfo'' object known as a process information agent that can return information such as arguments, environment variables, host name, and process name. The ''processInfo'' class method returns the shared agent for the current process. For example, the following line returns the ''ProcessInfo'' object, which then provides the name of the current process: \@TabNavigator { \@Tab("Swift") { '''swift let processName = ProcessInfo.processInfo.processName ''' } \@Tab("Objective-C") { '''objc NSString processName = [[NSProcessInfo processInfo] processName]; ''' } } > Note: > ''ProcessInfo'' is thread-safe in macOS 10.7 and later. The ''ProcessInfo'' class also includes the ''operatingSystemVersion'' property, which returns an ''OperatingSystemVersion'' structure identifying the operating system version on which the process is executing. ''ProcessInfo'' objects attempt to interpret environment variables and command-line arguments in the user's default C string encoding if they can't convert to Unicode as UTF-8 strings. If neither the Unicode nor C string conversion works, the ''ProcessInfo'' object ignores these values. \#\#\# Manage Activities The system has heuristics to improve battery life, performance, and responsiveness of applications for the benefit of the user. You can use the following methods to manage activities that give hints to the system that your application has special requirements: - ''beginActivity(options:reason:)'' - ''endActivity(:)'' - ''performActivity(options:reason:using:)'' In response to creating an activity, the system disables some or all of the heuristics so your application can finish quickly while still providing responsive behavior if the user needs it. You use activities when your application performs a long-running operation. If the activity can take different amounts of time (for example, calculating the next move in a chess game), it should use this API to ensure correct behavior when the amount of data or the capabilities of the user's computer varies. Activities fall into two major categories: - User-initiated activities are explicitly started by the user. Examples include exporting or downloading a user-specified file. - Background activities perform the normal operations of your application and aren't explicitly started by the user. Examples include autosaving, indexing, and automatic downloading of files. In addition, if your application requires high priority input/output (I/O), you can include the ''ActivityOptions/latencyCritical'' flag (using a bitwise 'OR'). You should only use this flag for activities like audio or video recording that require high priority I/O. If your activity takes place synchronously inside an event callback on the main thread, you don't need to use this API. Be aware that failing to end these activities for an extended period of time can have significant negative impacts on the performance of your user's computer, so be sure to use only the minimum amount of time required. User preferences may override your application's request. You can also use this API to control automatic termination or sudden termination (see \<doc:\#Support-Sudden-Termination>). For example, the following code brackets the work to protect it from sudden termination: \@TabNavigator { \@Tab("Swift") { '''swift let activity = ProcessInfo.processInfo.beginActivity( options: .automaticTerminationDisabled, reason: "Good Reason") // Perform some work. ProcessInfo.processInfo.endActivity(activity) ''' } \@Tab("Objective-C") { '''objc id activity = [[NSProcessInfo processInfo] beginActivityWithOptions:NSActivityAutomaticTerminationDisabled reason:\@"Good Reason"]; // Perform some work. [[NSProcessInfo processInfo] endActivity:activity]; ''' } } The above example is equivalent to the following code, which uses the ''disableAutomaticTermination(:)'' method: \@TabNavigator { \@Tab("Swift") { '''swift ProcessInfo.processInfo.disableAutomaticTermination("Good Reason") // Perform some work. ProcessInfo.processInfo.enableAutomaticTermination("Good Reason") ''' } \@Tab("Objective-C") { '''objc [[NSProcessInfo processInfo] disableAutomaticTermination:\@"Good Reason"]; // Perform some work. [[NSProcessInfo processInfo] enableAutomaticTermination:\@"Good Reason"]; ''' } } Because this API returns an object, it may be easier to pair begins and ends than when using the automatic termination API. If your app deallocates the object before the ''endActivity(:)'' call, the activity ends automatically. This API also provides a mechanism to disable system-wide idle sleep and display idle sleep. These can have a large impact on the user experience, so be careful to end activities that disable sleep (including ''ActivityOptions/userInitiated''). \#\#\# Support Sudden Termination macOS 10.6 and later includes a mechanism that allows the system to log out or shut down more quickly by, whenever possible, killing applications instead of requesting that they quit themselves. Your application can enable this capability on a global basis and then manually override its availability during actions that could cause data corruption or a poor user experience by allowing sudden termination. Alternatively, your application can manually enable and disable this functionality. Creating a process assigns a counter that indicates if the process is safe to terminate. You decrement and increment the counter using the methods ''enableSuddenTermination()'' and ''disableSuddenTermination()''. A value of '0' enables the system to terminate the process without first sending a notification or event. Your application can support sudden termination upon launch by adding a key to the application's 'Info.plist' file. If the \<doc://com.apple.documentation/documentation/bundleresources/information-property-list/nssupportssuddentermination> key exists in the 'Info.plist' file and has a value of \<doc://com.apple.documentation/documentation/swift/true>, it's the equivalent of calling ''enableSuddenTermination()'' during your application launch. This allows the system to terminate the process immediately. You can still override this behavior by invoking ''disableSuddenTermination()''. Typically, you disable sudden termination whenever your app defers work that the app must complete before it terminates. If, for example, your app defers writing data to disk and enables sudden termination, you should bracket the sensitive operations with a call to ''disableSuddenTermination()'', perform the necessary operations, and then send a balancing ''enableSuddenTermination()'' message. In agents or daemon executables that don't depend on AppKit, you can manually invoke ''enableSuddenTermination()'' right away. You can then use the enable and disable methods whenever the process has work it must do before it terminates. Some AppKit functionality automatically disables sudden termination on a temporary basis to ensure data integrity. - ''UserDefaults'' temporarily disables sudden termination to prevent the process from terminating between the time at which it sets the default and the time at which it writes the preferences file — including that default — to disk. - \<doc://com.apple.documentation/documentation/appkit/nsdocument> temporarily disables sudden termination to prevent the process from terminating between the time at which the user has made a change to a document and the time at which \<doc://com.apple.documentation/documentation/appkit/nsdocument> writes the user's change to disk. > Tip: > You can determine the value of the sudden termination using the following LLDB command. > > '''objc > print (long)[[NSClassFromString(\@"NSProcessInfo") processInfo] suddenTerminationDisablingCount] > ''' > > Don't attempt to invoke or override 'suddenTerminationDisablingCount' (a private method) in your application. It's there for this debugging purpose and may disappear at any time. \#\#\# Monitor Thermal State to Adjust App Performance Thermal state indicates the level of heat generated by logic components as they run apps. As the thermal state increases, the system decreases heat by reducing the speed of the processors. Optimize your app's performance by monitoring the thermal state and reducing system usage as the thermal state increases. Query the current state with ''thermalState'' to determine if your app needs to reduce system usage. You can register the ''thermalStateDidChangeNotification'' for notifications of a change in thermal state. For recommended actions, see ''ThermalState''.
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
     * @details Begins an activity using the given options and reason. Indicate completion of the activity by calling ''endActivity(:)'' passing the returned object as the argument. - Parameters: - options: Options for the activity. See ''ProcessInfo/ActivityOptions'' for possible values. - reason: A string used in debugging to indicate the reason the activity began. - Returns: An object token representing the activity.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param reason Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object begin_activity_with_options(ActivityOptions options, const std::string& reason) const;
        /**
     * @brief Calls `-[NSProcessInfo disableAutomaticTermination:]`.
     * @details Disables automatic termination for the application. This method increments the automatic termination counter. When the counter is greater than '0', the application is considered active and ineligible for automatic termination. For example, you could disable automatic termination when the user of an instant messaging application signs on, because the application requires a background connection to be maintained even if the application is otherwise inactive. The reason parameter is used to track why an application is or is not automatically terminable and can be inspected by debugging tools. A given reason can be used more than once at the same time. - Parameters: - reason: The reason why automatic termination is being disabled.
     * @param reason Argument converted to the Objective-C parameter of the same role.
     */
        void disable_automatic_termination(const std::string& reason) const;
        /**
     * @brief Calls `-[NSProcessInfo disableSuddenTermination]`.
     * @details Disables the application for quick killing using sudden termination. This method increments the sudden termination counter. When the termination counter reaches '0' the application allows sudden termination. By default the sudden termination counter is set to 1. This can be overridden in your application Info.plist. See \<doc:ProcessInfo\#Support-Sudden-Termination> for more information and debugging suggestions.
     */
        void disable_sudden_termination() const;
        /**
     * @brief Calls `-[NSProcessInfo enableAutomaticTermination:]`.
     * @details Enables automatic termination for the application. This method decrements the automatic termination counter. When the counter is '0', the application is eligible for automatic termination. The reason parameter is used to track why an application is or is not automatically terminable and can be inspected by debugging tools. A given reason can be used more than once at the same time. - Parameters: - reason: The reason why automatic termination is being enabled.
     * @param reason Argument converted to the Objective-C parameter of the same role.
     */
        void enable_automatic_termination(const std::string& reason) const;
        /**
     * @brief Calls `-[NSProcessInfo enableSuddenTermination]`.
     * @details Enables the application for quick killing using sudden termination. This method decrements the sudden termination counter. When the termination counter reaches '0' the application allows sudden termination. By default the sudden termination counter is set to 1. This can be overridden in your application Info.plist. See \<doc:ProcessInfo\#Support-Sudden-Termination> for more information and debugging suggestions.
     */
        void enable_sudden_termination() const;
        /**
     * @brief Calls `-[NSProcessInfo endActivity:]`.
     * @details Ends the given activity. - Parameters: - activity: An activity object returned by ''beginActivity(options:reason:)''.
     * @param activity Argument converted to the Objective-C parameter of the same role.
     */
        void end_activity(const Object& activity) const;
        /**
     * @brief Calls `-[NSProcessInfo isOperatingSystemAtLeastVersion:]`.
     * @details Returns a Boolean value indicating whether the version of the operating system on which the process is executing is the same or later than the given version. This method accounts for major, minor, and update versions of the operating system. - Parameters: - version: The operating system version to test against. - Returns: 'true' if the operating system on which the process is executing is the same or later than the given version; otherwise 'false'.
     * @param version Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_operating_system_at_least_version(const OperatingSystemVersion& version) const;
        /**
     * @brief Calls `-[NSProcessInfo performActivityWithOptions:reason:usingBlock:]`.
     * @details Synchronously performs an activity defined by a given block using the given options. The activity will be automatically ended after 'block' returns. - Parameters: - options: Options for the activity. See ''ProcessInfo/ActivityOptions'' for possible values. - reason: A string used in debugging to indicate the reason the activity began. - block: A block containing the work to be performed by the activity.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param reason Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void perform_activity_with_options(ActivityOptions options, const std::string& reason, std::function<void()> block) const;
        /**
     * @brief Returns the `activeProcessorCount` property of `NSProcessInfo`.
     * @details The number of active processing cores available on the computer. Whereas the ''processorCount'' property reports the number of advertised processing cores, the ''activeProcessorCount'' property reflects the actual number of active processing cores on the system. There are a number of different factors that may cause a core to not be active, including boot arguments, thermal throttling, or a manufacturing defect. This property value is equal to the result of entering the command 'sysctl -n hw.logicalcpu' on the current system.
     * @return The converted Objective-C result.
     */
        std::uint64_t active_processor_count() const;
        /**
     * @brief Returns the `arguments` property of `NSProcessInfo`.
     * @details Array of strings with the command-line arguments for the process. This array contains all the information passed in the 'argv' array, including the executable name in the first element.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> arguments() const;
        /**
     * @brief Returns the `automaticTerminationSupportEnabled` property of `NSProcessInfo`.
     * @details A Boolean value indicating whether the app supports automatic termination. Without setting this property or setting the equivalent 'Info.plist' key ('NSSupportsAutomaticTermination'), the methods ''disableAutomaticTermination:'' and ''enableAutomaticTermination:'' have no effect, although the counter tracking automatic termination opt-outs is still kept up to date to ensure correctness if this is called later. Currently, setting this property to 'NO' has no effect. This property should be set during '-applicationDidFinishLaunching:' or earlier.
     * @return The converted Objective-C result.
     */
        bool automatic_termination_support_enabled() const;
        /**
     * @brief Sets the `automaticTerminationSupportEnabled` property of `NSProcessInfo`.
     * @details A Boolean value indicating whether the app supports automatic termination. Without setting this property or setting the equivalent 'Info.plist' key ('NSSupportsAutomaticTermination'), the methods ''disableAutomaticTermination:'' and ''enableAutomaticTermination:'' have no effect, although the counter tracking automatic termination opt-outs is still kept up to date to ensure correctness if this is called later. Currently, setting this property to 'NO' has no effect. This property should be set during '-applicationDidFinishLaunching:' or earlier.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_automatic_termination_support_enabled(bool value) const;
        /**
     * @brief Returns the `environment` property of `NSProcessInfo`.
     * @details The variable names (keys) and their values in the environment from which the process was launched.
     * @return The converted Objective-C result.
     */
        std::map<std::string, std::string> environment() const;
        /**
     * @brief Returns the `fullUserName` property of `NSProcessInfo`.
     * @details Returns the full name of the current user.
     * @return The converted Objective-C result.
     */
        std::string full_user_name() const;
        /**
     * @brief Returns the `globallyUniqueString` property of `NSProcessInfo`.
     * @details Global unique identifier for the process. The global ID for the process includes the host name, process ID, and a time stamp, which ensures that the ID is unique for the network. This property generates a new string each time its getter is invoked, and it uses a counter to guarantee that strings created from the same process are unique.
     * @return The converted Objective-C result.
     */
        std::string globally_unique_string() const;
        /**
     * @brief Returns the `hostName` property of `NSProcessInfo`.
     * @details The name of the host computer on which the process is executing.
     * @return The converted Objective-C result.
     */
        std::string host_name() const;
        /**
     * @brief Returns the `iOSAppOnMac` property of `NSProcessInfo`.
     * @details A Boolean value that indicates whether the process is an iPhone or iPad app running on a Mac. The value of this property is 'YES' only when the process is an iOS app running on a Mac. The value is 'NO' for all other apps on the Mac, including Mac apps built using Mac Catalyst. The property is also 'NO' for processes running on platforms other than macOS.
     * @return The converted Objective-C result.
     */
        bool isi_os_app_on_mac() const;
        /**
     * @brief Returns the `iOSAppOnVision` property of `NSProcessInfo`.
     * @details A Boolean value that indicates whether the process is an iPhone or iPad app running on visionOS. The value of this property is 'YES' only when the process is an iOS app running on a visionOS device. The value is 'NO' for all other apps on visionOS. The property is also 'NO' for processes running on platforms other than visionOS.
     * @return The converted Objective-C result.
     */
        bool isi_os_app_on_vision() const;
        /**
     * @brief Returns the `lowPowerModeEnabled` property of `NSProcessInfo`.
     * @details A Boolean value that indicates the current state of Low Power Mode. Users who wish to prolong their device's battery life can enable Low Power Mode under Settings > Battery. In Low Power Mode, the system conserves battery life by enacting certain energy-saving measures, such as: - Reducing CPU and GPU performance. - Reducing screen brightness. - Pausing discretionary and background activities. Your app can query the 'isLowPowerModeEnabled' property at any time to determine whether Low Power Mode is active. Your app can also register to receive notifications when the Low Power Mode state of a device changes by observing ''NSProcessInfoPowerStateDidChangeNotification''.
     * @return The converted Objective-C result.
     */
        bool is_low_power_mode_enabled() const;
        /**
     * @brief Returns the `macCatalystApp` property of `NSProcessInfo`.
     * @details A Boolean value that indicates whether the process originated as an iOS app and runs on macOS. The value of this property is 'YES' when the process is a Mac app built with Mac Catalyst, or an iOS app running on Apple silicon, and is running on a Mac. Frameworks that support iOS and macOS use this property to determine if the process is a Mac app built with Mac Catalyst. > Note: > To distinguish between an iOS app running on Apple silicon and a Mac app built with Mac Catalyst, use the ''isiOSAppOnMac'' property.
     * @return The converted Objective-C result.
     */
        bool is_mac_catalyst_app() const;
        /**
     * @brief Returns the `operatingSystemVersion` property of `NSProcessInfo`.
     * @details The version of the operating system on which the process is executing.
     * @return The converted Objective-C result.
     */
        OperatingSystemVersion operating_system_version() const;
        /**
     * @brief Returns the `operatingSystemVersionString` property of `NSProcessInfo`.
     * @details A string containing the version of the operating system on which the process is executing. The operating system version string is human readable, localized, and is appropriate for displaying to the user. This string is not appropriate for parsing.
     * @return The converted Objective-C result.
     */
        std::string operating_system_version_string() const;
        /**
     * @brief Returns the `physicalMemory` property of `NSProcessInfo`.
     * @details The amount of physical memory on the computer in bytes.
     * @return The converted Objective-C result.
     */
        std::uint64_t physical_memory() const;
        /**
     * @brief Returns the `processIdentifier` property of `NSProcessInfo`.
     * @details The identifier of the process (often called process ID).
     * @return The converted Objective-C result.
     */
        int process_identifier() const;
        /**
     * @brief Returns the `processInfo` property of `NSProcessInfo`.
     * @details Returns the process information agent for the process. An 'NSProcessInfo' object is created the first time this property is accessed, and that same object is returned on each subsequent access.
     * @return The converted Objective-C result.
     */
        static ProcessInfo process_info();
        /**
     * @brief Returns the `processName` property of `NSProcessInfo`.
     * @details The name of the process. The process name is used to register application defaults and is used in error messages. It does not uniquely identify the process. > Warning: > User defaults and other aspects of the environment might depend on the process name, so be very careful if you change it. Setting the process name in this manner is not thread safe.
     * @return The converted Objective-C result.
     */
        std::string process_name() const;
        /**
     * @brief Sets the `processName` property of `NSProcessInfo`.
     * @details The name of the process. The process name is used to register application defaults and is used in error messages. It does not uniquely identify the process. > Warning: > User defaults and other aspects of the environment might depend on the process name, so be very careful if you change it. Setting the process name in this manner is not thread safe.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_process_name(const std::string& value) const;
        /**
     * @brief Returns the `processorCount` property of `NSProcessInfo`.
     * @details The number of processing cores available on the computer. This property value is equal to the result of entering the command 'sysctl -n hw.ncpu' on the current system.
     * @return The converted Objective-C result.
     */
        std::uint64_t processor_count() const;
        /**
     * @brief Returns the `systemUptime` property of `NSProcessInfo`.
     * @details The amount of time the system has been awake since the last time it was restarted. > Important: > This API has the potential of being misused to access device signals to try to identify the device or user, also known as fingerprinting. Regardless of whether a user gives your app permission to track, fingerprinting is not allowed. When you use this API in your app or third-party SDK (an SDK not provided by Apple), declare your usage and the reason for using the API in your app or third-party SDK's 'PrivacyInfo.xcprivacy' file. For more information, including the list of valid reasons for using the API, see [Describing use of required reason API](https://developer.apple.com/documentation/bundleresources/describing-use-of-required-reason-api).
     * @return The converted Objective-C result.
     */
        double system_uptime() const;
        /**
     * @brief Returns the `thermalState` property of `NSProcessInfo`.
     * @details The current thermal state of the system. At higher thermal states your app should reduce usage of system resources. For more information, see ''NSProcessInfoThermalState''.
     * @return The converted Objective-C result.
     */
        ProcessInfoThermalState thermal_state() const;
        /**
     * @brief Returns the `userName` property of `NSProcessInfo`.
     * @details Returns the account name of the current user.
     * @return The converted Objective-C result.
     */
        std::string user_name() const;
    };
}
