#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AppleEventDescriptor;

    /**
     * @brief C++ handle for the Objective-C class `NSWorkspaceOpenConfiguration` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::WorkspaceOpenConfiguration workspace_open_configuration;
     * workspace_open_configuration.set_activates(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::WorkspaceOpenConfiguration workspace_open_configuration{};
     * workspace_open_configuration.set_activates(true);
     * auto activates = workspace_open_configuration.activates();
     * workspace_open_configuration.set_adds_to_recent_items(true);
     * auto adds_to_recent_items = workspace_open_configuration.adds_to_recent_items();
     * workspace_open_configuration.set_allows_running_application_substitution(true);
     * auto allows_running_application_substitution = workspace_open_configuration.allows_running_application_substitution();
     * auto made_0 = cocoon::WorkspaceOpenConfiguration::configuration();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsworkspaceopenconfiguration
     */
    class WorkspaceOpenConfiguration : public Object
    {
    public:
        /// @brief Creates a new `NSWorkspaceOpenConfiguration` instance and returns a handle to it.
        explicit WorkspaceOpenConfiguration();
        /// @brief Creates a null handle that refers to no native object.
        WorkspaceOpenConfiguration(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit WorkspaceOpenConfiguration(Adopt adopt);
        /**
     * @brief Calls `+[NSWorkspaceOpenConfiguration configuration]`.
     * @details Instantiates a configuration object with default values. Equivalent to [[[NSWorkspaceOpenConfiguration alloc] init] autorelease].
     * @return The converted Objective-C result.
     */
        static WorkspaceOpenConfiguration configuration();
        /**
     * @brief Returns the `activates` property of `NSWorkspaceOpenConfiguration`.
     * @details Bring the application instance to the foreground. Defaults to YES.
     * @return The converted Objective-C result.
     */
        bool activates() const;
        /**
     * @brief Sets the `activates` property of `NSWorkspaceOpenConfiguration`.
     * @details Bring the application instance to the foreground. Defaults to YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_activates(bool value) const;
        /**
     * @brief Returns the `addsToRecentItems` property of `NSWorkspaceOpenConfiguration`.
     * @details Add the application instance or documents to the Recent Items menu. Defaults to YES.
     * @return The converted Objective-C result.
     */
        bool adds_to_recent_items() const;
        /**
     * @brief Sets the `addsToRecentItems` property of `NSWorkspaceOpenConfiguration`.
     * @details Add the application instance or documents to the Recent Items menu. Defaults to YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_adds_to_recent_items(bool value) const;
        /**
     * @brief Returns the `allowsRunningApplicationSubstitution` property of `NSWorkspaceOpenConfiguration`.
     * @details If an instance of an application is already running, but the running instance is at a different URL (and is capable of opening the provided URLs), use the running application. Defaults to YES. Set this to NO if you are letting the user select between specific versions of an application or letting them choose a particular installation.
     * @return The converted Objective-C result.
     */
        bool allows_running_application_substitution() const;
        /**
     * @brief Sets the `allowsRunningApplicationSubstitution` property of `NSWorkspaceOpenConfiguration`.
     * @details If an instance of an application is already running, but the running instance is at a different URL (and is capable of opening the provided URLs), use the running application. Defaults to YES. Set this to NO if you are letting the user select between specific versions of an application or letting them choose a particular installation.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_running_application_substitution(bool value) const;
        /**
     * @brief Returns the `appleEvent` property of `NSWorkspaceOpenConfiguration`.
     * @details The first NSAppleEventDescriptor to send to the new app. If an instance of the app is already running, this is sent to that app. Defaults to nil. When nil, a default apple event will be sent, if required.
     * @return The converted Objective-C result.
     */
        AppleEventDescriptor apple_event() const;
        /**
     * @brief Sets the `appleEvent` property of `NSWorkspaceOpenConfiguration`.
     * @details The first NSAppleEventDescriptor to send to the new app. If an instance of the app is already running, this is sent to that app. Defaults to nil. When nil, a default apple event will be sent, if required.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_apple_event(const AppleEventDescriptor& value) const;
        /**
     * @brief Returns the `architecture` property of `NSWorkspaceOpenConfiguration`.
     * @details A cpu_type_t (from \<mach/machine.h>) that specifies the architecture to launch. Ignored if a new instance is not launched. Defaults to CPU_TYPE_ANY. When CPU_TYPE_ANY, the system will decide the preferred architecture based on those present in the executable.
     * @return The converted Objective-C result.
     */
        int architecture() const;
        /**
     * @brief Sets the `architecture` property of `NSWorkspaceOpenConfiguration`.
     * @details A cpu_type_t (from \<mach/machine.h>) that specifies the architecture to launch. Ignored if a new instance is not launched. Defaults to CPU_TYPE_ANY. When CPU_TYPE_ANY, the system will decide the preferred architecture based on those present in the executable.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_architecture(int value) const;
        /**
     * @brief Returns the `arguments` property of `NSWorkspaceOpenConfiguration`.
     * @details Command-line arguments to pass to a new application instance. Defaults to \@[]. Only applies when a new application instance is created. The path to the application instance is always automatically inserted as the first argument. If the calling process is sandboxed, the value of this property is ignored.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> arguments() const;
        /**
     * @brief Sets the `arguments` property of `NSWorkspaceOpenConfiguration`.
     * @details Command-line arguments to pass to a new application instance. Defaults to \@[]. Only applies when a new application instance is created. The path to the application instance is always automatically inserted as the first argument. If the calling process is sandboxed, the value of this property is ignored.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_arguments(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `createsNewApplicationInstance` property of `NSWorkspaceOpenConfiguration`.
     * @details Ignore any running instance of the application and launch a new one. Defaults to NO (i.e. prefers to reuse a running instance). When createsNewApplicationInstance is YES, the value of allowsRunningApplicationSubstitution is not consulted.
     * @return The converted Objective-C result.
     */
        bool creates_new_application_instance() const;
        /**
     * @brief Sets the `createsNewApplicationInstance` property of `NSWorkspaceOpenConfiguration`.
     * @details Ignore any running instance of the application and launch a new one. Defaults to NO (i.e. prefers to reuse a running instance). When createsNewApplicationInstance is YES, the value of allowsRunningApplicationSubstitution is not consulted.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_creates_new_application_instance(bool value) const;
        /**
     * @brief Returns the `environment` property of `NSWorkspaceOpenConfiguration`.
     * @details Environment variables to set in a new application instance. Defaults to \@{}. Only applies when a new application instance is created. Additional environment variables may be included by the system.
     * @return The converted Objective-C result.
     */
        std::map<std::string, std::string> environment() const;
        /**
     * @brief Sets the `environment` property of `NSWorkspaceOpenConfiguration`.
     * @details Environment variables to set in a new application instance. Defaults to \@{}. Only applies when a new application instance is created. Additional environment variables may be included by the system.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_environment(const std::map<std::string, std::string>& value) const;
        /**
     * @brief Returns the `forPrinting` property of `NSWorkspaceOpenConfiguration`.
     * @details Print documents and URLs instead of opening them. Defaults to NO.
     * @return The converted Objective-C result.
     */
        bool is_for_printing() const;
        /**
     * @brief Sets the `forPrinting` property of `NSWorkspaceOpenConfiguration`.
     * @details Print documents and URLs instead of opening them. Defaults to NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_for_printing(bool value) const;
        /**
     * @brief Returns the `hides` property of `NSWorkspaceOpenConfiguration`.
     * @details Hide the application instance. Defaults to NO.
     * @return The converted Objective-C result.
     */
        bool hides() const;
        /**
     * @brief Sets the `hides` property of `NSWorkspaceOpenConfiguration`.
     * @details Hide the application instance. Defaults to NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hides(bool value) const;
        /**
     * @brief Returns the `hidesOthers` property of `NSWorkspaceOpenConfiguration`.
     * @details Hide other application instances. Defaults to NO.
     * @return The converted Objective-C result.
     */
        bool hides_others() const;
        /**
     * @brief Sets the `hidesOthers` property of `NSWorkspaceOpenConfiguration`.
     * @details Hide other application instances. Defaults to NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hides_others(bool value) const;
        /**
     * @brief Returns the `promptsUserIfNeeded` property of `NSWorkspaceOpenConfiguration`.
     * @details Display user interface elements if needed, including errors and authentication. Defaults to YES. The completion handler will not be invoked until the user dismisses any such UI. Gatekeeper UI is not affected and will always be presented if needed.
     * @return The converted Objective-C result.
     */
        bool prompts_user_if_needed() const;
        /**
     * @brief Sets the `promptsUserIfNeeded` property of `NSWorkspaceOpenConfiguration`.
     * @details Display user interface elements if needed, including errors and authentication. Defaults to YES. The completion handler will not be invoked until the user dismisses any such UI. Gatekeeper UI is not affected and will always be presented if needed.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_prompts_user_if_needed(bool value) const;
        /**
     * @brief Returns the `requiresUniversalLinks` property of `NSWorkspaceOpenConfiguration`.
     * @details Only open the provided URL if it is a valid universal link with an application configured to open it. If there is no application configured, or the user disabled using it to open the link, then the open will fail with an error. Defaults to NO.
     * @return The converted Objective-C result.
     */
        bool requires_universal_links() const;
        /**
     * @brief Sets the `requiresUniversalLinks` property of `NSWorkspaceOpenConfiguration`.
     * @details Only open the provided URL if it is a valid universal link with an application configured to open it. If there is no application configured, or the user disabled using it to open the link, then the open will fail with an error. Defaults to NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_requires_universal_links(bool value) const;
    };
}
