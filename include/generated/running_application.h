#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class Image;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSRunningApplication` (AppKit).
     * @details 'NSRunningApplication' is a class to manipulate and provide information for a single instance of an application. Only user applications are tracked; this does not provide information about every process on the system. Some properties of an application are fixed, such as the bundle identifier. Other properties may vary over time, such as whether the app is hidden. Properties that vary can be observed with KVO, in which case the description comment for the method will mention it. Properties that vary over time are inherently race-prone. For example, a hidden app may unhide itself at any time. To ameliorate this, properties persist until the next turn of the main run loop in a common mode. For example, if you repeatedly poll an unhidden app for its hidden property without allowing the run loop to run, it will continue to return 'NO', even if the app hides, until the next turn of the run loop. 'NSRunningApplication' is thread safe, in that its properties are returned atomically. However, it is still subject to the main run loop policy described above. If you access an instance of 'NSRunningApplication' from a background thread, be aware that its time-varying properties may change from under you as the main run loop runs (or not). An 'NSRunningApplication' instance remains valid after the application exits. However, most properties lose their significance, and some properties may not be available on a terminated application. To access the list of all running applications, use the '-runningApplications' method on 'NSWorkspace'.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::RunningApplication running_application;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::RunningApplication running_application{};
     * auto made_0 = cocoon::RunningApplication::running_application_with_process_identifier(1);
     * running_application.activate_from_application(cocoon::RunningApplication(), cocoon::ApplicationActivationOptions::AllWindows);
     * running_application.activate_with_options(cocoon::ApplicationActivationOptions::AllWindows);
     * running_application.force_terminate();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsrunningapplication
     */
    class RunningApplication : public Object
    {
    public:
        /// @brief Creates a new `NSRunningApplication` instance and returns a handle to it.
        explicit RunningApplication();
        /// @brief Creates a null handle that refers to no native object.
        RunningApplication(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit RunningApplication(Adopt adopt);
        /**
     * @brief Calls `-[NSRunningApplication activateFromApplication:options:]`.
     * @details Attempts to activate the application using the specified options. You shouldn’t assume the app will be active immediately after sending this message. The framework also does not guarantee that the app will be activated at all. Additionally allows specifying another application to take the active status from, which can be used for coordinated or cooperative activation. The other application should call '-yieldActivationToApplication:' or equivalent prior to this request being sent. \@return 'YES' if the request has been allowed by the system, otherwise 'NO'.
     * @param application Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool activate_from_application(const RunningApplication& application, ApplicationActivationOptions options) const;
        /**
     * @brief Calls `-[NSRunningApplication activateWithOptions:]`.
     * @details Attempts to activate the receiver. \@return 'YES' if the request to activate was successfully sent, 'NO' if not (for example, if the application has quit, or is of a type that cannot be activated).
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool activate_with_options(ApplicationActivationOptions options) const;
        /**
     * @brief Calls `-[NSRunningApplication forceTerminate]`.
     * @details Attempts to force the receiver to quit. \@return 'YES' if the request was successfully sent, 'NO' if not (for example, if the application is no longer running). This method may return before the receiver exits; you should observe the terminated property or listen for the notification to detect when the app has exited.
     * @return The converted Objective-C result.
     */
        bool force_terminate() const;
        /**
     * @brief Calls `-[NSRunningApplication hide]`.
     * @details Attempts to hide the receiver. \@return 'YES' if the request to hide or unhide was successfully sent, 'NO' if not (for example, if the application has quit, or is of a type that cannot be unhidden).
     * @return The converted Objective-C result.
     */
        bool hide() const;
        /**
     * @brief Calls `+[NSRunningApplication runningApplicationWithProcessIdentifier:]`.
     * @details \@return The running application with the given process identifier, or nil if no application has that pid. Applications that do not have PIDs cannot be returned from this method.
     * @param pid Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static RunningApplication running_application_with_process_identifier(int pid);
        /**
     * @brief Calls `+[NSRunningApplication runningApplicationsWithBundleIdentifier:]`.
     * @details \@return An array of currently running applications with the given bundle identifier, or an empty array if no apps match.
     * @param bundle_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<RunningApplication> running_applications_with_bundle_identifier(const std::string& bundle_identifier);
        /**
     * @brief Calls `-[NSRunningApplication terminate]`.
     * @details Attempts to quit the receiver normally. \@return 'YES' if the request was successfully sent, 'NO' if not (for example, if the application is no longer running). This method may return before the receiver exits; you should observe the terminated property or listen for the notification to detect when the app has exited.
     * @return The converted Objective-C result.
     */
        bool terminate() const;
        /**
     * @brief Calls `+[NSRunningApplication terminateAutomaticallyTerminableApplications]`.
     * @details Cause any applications that are invisibly still running (see 'NSProcessInfo.h' automatic termination methods and docs) to terminate as if triggered by system memory pressure. This is intended for installer apps and the like to make sure that nothing is unexpectedly relying on the files they're replacing.
     */
        static void terminate_automatically_terminable_applications();
        /**
     * @brief Calls `-[NSRunningApplication unhide]`.
     * @details Attempts to unhide the receiver. \@return 'YES' if the request to hide or unhide was successfully sent, 'NO' if not (for example, if the application has quit, or is of a type that cannot be unhidden).
     * @return The converted Objective-C result.
     */
        bool unhide() const;
        /**
     * @brief Returns the `activationPolicy` property of `NSRunningApplication`.
     * @details Indicates the activation policy of the application. This is observable through KVO (the type is usually fixed, but may be changed through a call to '-[NSApplication setActivationPolicy:]').
     * @return The converted Objective-C result.
     */
        ActivationPolicy activation_policy() const;
        /**
     * @brief Returns the `active` property of `NSRunningApplication`.
     * @details Indicates whether the application is currently frontmost. This is observable through KVO.
     * @return The converted Objective-C result.
     */
        bool is_active() const;
        /**
     * @brief Returns the `bundleIdentifier` property of `NSRunningApplication`.
     * @details Indicates the 'CFBundleIdentifier' of the application, or nil if the application does not have an 'Info.plist'.
     * @return The converted Objective-C result.
     */
        std::string bundle_identifier() const;
        /**
     * @brief Returns the `bundleURL` property of `NSRunningApplication`.
     * @details Indicates the URL to the application's bundle, or nil if the application does not have a bundle.
     * @return The converted Objective-C result.
     */
        URL bundle_url() const;
        /**
     * @brief Returns the `currentApplication` property of `NSRunningApplication`.
     * @details \@return An \@c NSRunningApplication representing this application.
     * @return The converted Objective-C result.
     */
        static RunningApplication current_application();
        /**
     * @brief Returns the `executableArchitecture` property of `NSRunningApplication`.
     * @details Indicates the executing processor architecture for the application, as an \@c NSBundleExecutableArchitecture from 'NSBundle.h'.
     * @return The converted Objective-C result.
     */
        std::int64_t executable_architecture() const;
        /**
     * @brief Returns the `executableURL` property of `NSRunningApplication`.
     * @details Indicates the URL to the application's executable.
     * @return The converted Objective-C result.
     */
        URL executable_url() const;
        /**
     * @brief Returns the `finishedLaunching` property of `NSRunningApplication`.
     * @details Indicates that the process is finished launching, which corresponds to the \@c NSApplicationDidFinishLaunching internal notification. This is observable through KVO. Some applications do not post this notification and so are never reported as finished launching.
     * @return The converted Objective-C result.
     */
        bool is_finished_launching() const;
        /**
     * @brief Returns the `hidden` property of `NSRunningApplication`.
     * @details Indicates whether the application is currently hidden. This is observable through KVO.
     * @return The converted Objective-C result.
     */
        bool is_hidden() const;
        /**
     * @brief Returns the `icon` property of `NSRunningApplication`.
     * @details \@return The icon of the application.
     * @return The converted Objective-C result.
     */
        Image icon() const;
        /**
     * @brief Returns the `launchDate` property of `NSRunningApplication`.
     * @details Indicates the date when the application was launched. This property is not available for all applications. Specifically, it is not available for applications that were launched without going through 'LaunchServices'.
     * @return The converted Objective-C result.
     */
        Date launch_date() const;
        /**
     * @brief Returns the `localizedName` property of `NSRunningApplication`.
     * @details Indicates the name of the application. This is dependent on the current localization of the referenced app, and is suitable for presentation to the user.
     * @return The converted Objective-C result.
     */
        std::string localized_name() const;
        /**
     * @brief Returns the `ownsMenuBar` property of `NSRunningApplication`.
     * @details Indicates whether the application currently owns the menu bar. This is observable through KVO.
     * @return The converted Objective-C result.
     */
        bool owns_menu_bar() const;
        /**
     * @brief Returns the `processIdentifier` property of `NSRunningApplication`.
     * @details Indicates the process identifier (pid) of the application. Do not rely on this for comparing processes. Use '-isEqual:' instead. \@note Not all applications have a pid. Applications without a pid return -1 from this method. This is observable through KVO (an application's pid may change if it is automatically terminated).
     * @return The converted Objective-C result.
     */
        int process_identifier() const;
        /**
     * @brief Returns the `terminated` property of `NSRunningApplication`.
     * @details Indicates that the process is an exited application. This is observable through KVO.
     * @return The converted Objective-C result.
     */
        bool is_terminated() const;
    };
}
