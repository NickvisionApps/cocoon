#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSTask` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Task task;
     * task.set_arguments({"a", "b"});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Task task{};
     * task.set_arguments({"a", "b"});
     * auto arguments = task.arguments();
     * task.set_current_directory_path("text");
     * auto current_directory_path = task.current_directory_path();
     * task.set_current_directory_url(cocoon::URL());
     * auto current_directory_url = task.current_directory_url();
     * auto made_0 = cocoon::Task::launched_task_with_launch_path("text", {"a", "b"});
     * task.interrupt();
     * task.launch();
     * task.launch_and_return_error();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nstask
     */
    class Task : public Object
    {
    public:
        /// @brief Creates a new `NSTask` instance and returns a handle to it.
        explicit Task();
        /// @brief Creates a null handle that refers to no native object.
        Task(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Task(Adopt adopt);
        /**
     * @brief Calls `-[NSTask interrupt]`.
     */
        void interrupt() const;
        /**
     * @brief Calls `-[NSTask launch]`.
     */
        void launch() const;
        /**
     * @brief Calls `-[NSTask launchAndReturnError:]`.
     * @return The converted Objective-C result.
     */
        bool launch_and_return_error() const;
        /**
     * @brief Calls `+[NSTask launchedTaskWithExecutableURL:arguments:error:terminationHandler:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param arguments Argument converted to the Objective-C parameter of the same role.
     * @param termination_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Task launched_task_with_executable_url(const URL& url, const std::vector<std::string>& arguments, std::function<void(Task)> termination_handler);
        /**
     * @brief Calls `+[NSTask launchedTaskWithLaunchPath:arguments:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param arguments Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Task launched_task_with_launch_path(const std::string& path, const std::vector<std::string>& arguments);
        /**
     * @brief Calls `-[NSTask resume]`.
     * @return The converted Objective-C result.
     */
        bool resume() const;
        /**
     * @brief Calls `-[NSTask suspend]`.
     * @return The converted Objective-C result.
     */
        bool suspend() const;
        /**
     * @brief Calls `-[NSTask terminate]`.
     */
        void terminate() const;
        /**
     * @brief Calls `-[NSTask waitUntilExit]`.
     */
        void wait_until_exit() const;
        /**
     * @brief Returns the `arguments` property of `NSTask`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> arguments() const;
        /**
     * @brief Sets the `arguments` property of `NSTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_arguments(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `currentDirectoryPath` property of `NSTask`.
     * @return The converted Objective-C result.
     */
        std::string current_directory_path() const;
        /**
     * @brief Sets the `currentDirectoryPath` property of `NSTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_current_directory_path(const std::string& value) const;
        /**
     * @brief Returns the `currentDirectoryURL` property of `NSTask`.
     * @return The converted Objective-C result.
     */
        URL current_directory_url() const;
        /**
     * @brief Sets the `currentDirectoryURL` property of `NSTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_current_directory_url(const URL& value) const;
        /**
     * @brief Returns the `environment` property of `NSTask`.
     * @return The converted Objective-C result.
     */
        std::map<std::string, std::string> environment() const;
        /**
     * @brief Sets the `environment` property of `NSTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_environment(const std::map<std::string, std::string>& value) const;
        /**
     * @brief Returns the `executableURL` property of `NSTask`.
     * @return The converted Objective-C result.
     */
        URL executable_url() const;
        /**
     * @brief Sets the `executableURL` property of `NSTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_executable_url(const URL& value) const;
        /**
     * @brief Returns the `launchPath` property of `NSTask`.
     * @return The converted Objective-C result.
     */
        std::string launch_path() const;
        /**
     * @brief Sets the `launchPath` property of `NSTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_launch_path(const std::string& value) const;
        /**
     * @brief Returns the `launchRequirementData` property of `NSTask`.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> launch_requirement_data() const;
        /**
     * @brief Sets the `launchRequirementData` property of `NSTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_launch_requirement_data(const std::vector<std::uint8_t>& value) const;
        /**
     * @brief Returns the `processIdentifier` property of `NSTask`.
     * @return The converted Objective-C result.
     */
        int process_identifier() const;
        /**
     * @brief Returns the `qualityOfService` property of `NSTask`.
     * @return The converted Objective-C result.
     */
        QualityOfService quality_of_service() const;
        /**
     * @brief Sets the `qualityOfService` property of `NSTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_quality_of_service(QualityOfService value) const;
        /**
     * @brief Returns the `running` property of `NSTask`.
     * @return The converted Objective-C result.
     */
        bool is_running() const;
        /**
     * @brief Returns the `standardError` property of `NSTask`.
     * @return The converted Objective-C result.
     */
        Object standard_error() const;
        /**
     * @brief Sets the `standardError` property of `NSTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standard_error(const Object& value) const;
        /**
     * @brief Returns the `standardInput` property of `NSTask`.
     * @return The converted Objective-C result.
     */
        Object standard_input() const;
        /**
     * @brief Sets the `standardInput` property of `NSTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standard_input(const Object& value) const;
        /**
     * @brief Returns the `standardOutput` property of `NSTask`.
     * @return The converted Objective-C result.
     */
        Object standard_output() const;
        /**
     * @brief Sets the `standardOutput` property of `NSTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standard_output(const Object& value) const;
        /**
     * @brief Returns the `terminationHandler` property of `NSTask`.
     * @details A block to be invoked when the process underlying the NSTask terminates. Setting the block to nil is valid, and stops the previous block from being invoked, as long as it hasn't started in any way. The NSTask is passed as the argument to the block so the block does not have to capture, and thus retain, it. The block is copied when set. Only one termination handler block can be set at any time. The execution context in which the block is invoked is undefined. If the NSTask has already finished, the block is executed immediately/soon (not necessarily on the current thread). If a terminationHandler is set on an NSTask, the NSTaskDidTerminateNotification notification is not posted for that task. Also note that -waitUntilExit won't wait until the terminationHandler has been fully executed. You cannot use this property in a concrete subclass of NSTask which hasn't been updated to include an implementation of the storage and use of it.
     * @return The converted Objective-C result.
     */
        std::function<void(Task)> termination_handler() const;
        /**
     * @brief Sets the `terminationHandler` property of `NSTask`.
     * @details A block to be invoked when the process underlying the NSTask terminates. Setting the block to nil is valid, and stops the previous block from being invoked, as long as it hasn't started in any way. The NSTask is passed as the argument to the block so the block does not have to capture, and thus retain, it. The block is copied when set. Only one termination handler block can be set at any time. The execution context in which the block is invoked is undefined. If the NSTask has already finished, the block is executed immediately/soon (not necessarily on the current thread). If a terminationHandler is set on an NSTask, the NSTaskDidTerminateNotification notification is not posted for that task. Also note that -waitUntilExit won't wait until the terminationHandler has been fully executed. You cannot use this property in a concrete subclass of NSTask which hasn't been updated to include an implementation of the storage and use of it.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_termination_handler(std::function<void(Task)> value) const;
        /**
     * @brief Returns the `terminationReason` property of `NSTask`.
     * @return The converted Objective-C result.
     */
        TaskTerminationReason termination_reason() const;
        /**
     * @brief Returns the `terminationStatus` property of `NSTask`.
     * @return The converted Objective-C result.
     */
        int termination_status() const;
    };
}
