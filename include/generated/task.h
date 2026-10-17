#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSTask` (Foundation).
     * @details An object that represents a subprocess of the current process. Using this class, your program can run another program as a subprocess and monitor that program's execution. Unlike ''Thread'', it doesn't share memory space with the process that creates it. A process operates within an environment defined by the current values for several items: the current directory, standard input, standard output, standard error, and the values of any environment variables, inheriting its environment from the process that launches it. If there are any environment variables that should be different for the subprocess (for example, if the current directory needs to change), change it in the instance after initialization, before your app launches it. Your app can't change a process's environment while it's running. You can only run the subprocess once per instance. Subsequent attempts raise an error. > Important: > In a sandboxed app, child processes you create with this class inherit the sandbox of the parent app. Instead, write helper apps as XPC Services because it allows you to specify different sandbox entitlements for helper apps. For more information, see [Daemons and Services Programming Guide](https://developer.apple.com/library/archive/documentation/MacOSX/Conceptual/BPSystemStartup/Chapters/Introduction.html\#//apple_ref/doc/uid/10000172i) and \<doc://com.apple.documentation/documentation/xpc>.
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
     * @details Sends an interrupt signal to the receiver and all of its subtasks. If the task terminates as a result, which is the default behavior, an 'NSTaskDidTerminateNotification' gets sent to the default notification center. This method has no effect if the receiver was already launched and has already finished executing. If the system hasn't launched the receiver, this method raises an 'NSInvalidArgumentException'. It isn't always possible to interrupt the receiver because it might be ignoring the interrupt signal. This method sends 'SIGINT'.
     */
        void interrupt() const;
        /**
     * @brief Calls `-[NSTask launch]`.
     * @details Launches the task represented by the receiver. \@DeprecationSummary { Use ''run()'' instead. } Raises an 'NSInvalidArgumentException' if the launch path has not been set or is invalid or if it fails to create a process.
     */
        void launch() const;
        /**
     * @brief Calls `-[NSTask launchAndReturnError:]`.
     * @details Runs the process with the current environment.
     * @return The converted Objective-C result.
     */
        bool launch_and_return_error() const;
        /**
     * @brief Calls `+[NSTask launchedTaskWithExecutableURL:arguments:error:terminationHandler:]`.
     * @details Creates and runs a task with a specified executable and arguments. - Parameter url: The URL for the executable. - Parameter arguments: An array of 'NSString' objects that supplies the arguments to the task. - Parameter error: If an error occurs, upon return contains an 'NSError' object that describes the problem. - Parameter terminationHandler: The system invokes this completion block when the task has completed. - Returns: An initialized 'NSTask' object with the environment of the current process.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param arguments Argument converted to the Objective-C parameter of the same role.
     * @param termination_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Task launched_task_with_executable_url(const URL& url, const std::vector<std::string>& arguments, std::function<void(Task)> termination_handler);
        /**
     * @brief Calls `+[NSTask launchedTaskWithLaunchPath:arguments:]`.
     * @details Creates and launches a task with a specified executable and arguments. \@deprecated Use 'launchedTaskWithExecutableURL:arguments:error:terminationHandler:' instead. The task inherits its environment from the process that invokes this method. The 'NSTask' object converts both 'path' and the strings in 'arguments' to appropriate C-style strings (using 'fileSystemRepresentation') before passing them to the task via 'argv[]'. The strings in 'arguments' don't undergo shell expansion, so you don't need to do special quoting, and shell variables, such as '$PWD', aren't resolved. - Parameter path: The path to the executable. - Parameter arguments: An array of 'NSString' objects that supplies the arguments to the task. - Returns: An initialized 'NSTask' object with the supplied 'arguments'.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param arguments Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Task launched_task_with_launch_path(const std::string& path, const std::vector<std::string>& arguments);
        /**
     * @brief Calls `-[NSTask resume]`.
     * @details Resumes execution of a suspended task. If the system sent multiple 'suspend' messages to the receiver, an equal number of 'resume' messages must be sent before the task resumes execution. - Returns: 'YES' if the receiver was able to resume execution, 'NO' otherwise.
     * @return The converted Objective-C result.
     */
        bool resume() const;
        /**
     * @brief Calls `-[NSTask suspend]`.
     * @details Suspends execution of the receiver task. Multiple 'suspend' messages can be sent, but they must be balanced with an equal number of 'resume' messages before the task resumes execution. - Returns: 'YES' if the receiver was successfully suspended, 'NO' otherwise.
     * @return The converted Objective-C result.
     */
        bool suspend() const;
        /**
     * @brief Calls `-[NSTask terminate]`.
     * @details Sends a terminate signal to the receiver and all of its subtasks. If the task terminates as a result, which is the default behavior, an 'NSTaskDidTerminateNotification' gets sent to the default notification center. This method has no effect if the receiver was already launched and has already finished executing. If the receiver hasn't been launched yet, this method raises an 'NSInvalidArgumentException'. It's not always possible to terminate the receiver because it might be ignoring the terminate signal. This method sends 'SIGTERM'.
     */
        void terminate() const;
        /**
     * @brief Calls `-[NSTask waitUntilExit]`.
     * @details Blocks the process until the receiver is finished. This method first checks to see if the receiver is still running using 'isRunning'. Then it polls the current run loop using 'NSDefaultRunLoopMode' until the task completes. \@TabNavigator { \@Tab("Swift") { '''swift let task: NSTask = // Create and initialize a task task.launch() task.waitUntilExit() let status = task.terminationStatus if status == 0 { print("Task succeeded.") } else { print("Task failed.") } ''' } \@Tab("Objective-C") { '''objc NSTask task = // Create and initialize a task [task launch]; [task waitUntilExit]; int status = [task terminationStatus]; if (status == 0) { NSLog(\@"Task succeeded."); } else { NSLog(\@"Task failed."); } ''' } } 'waitUntilExit' does not guarantee that the 'terminationHandler' block has been fully executed before 'waitUntilExit' returns.
     */
        void wait_until_exit() const;
        /**
     * @brief Returns the `arguments` property of `NSTask`.
     * @details The command arguments that the system uses to launch the executable. The 'NSTask' object converts both 'path' and the strings in 'arguments' to appropriate C-style strings (using 'fileSystemRepresentation') before passing them to the task through 'argv[]'. The strings in 'arguments' don't undergo shell expansion, so you don't need to do special quoting, and shell variables, such as '$PWD', aren't resolved.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> arguments() const;
        /**
     * @brief Sets the `arguments` property of `NSTask`.
     * @details The command arguments that the system uses to launch the executable. The 'NSTask' object converts both 'path' and the strings in 'arguments' to appropriate C-style strings (using 'fileSystemRepresentation') before passing them to the task through 'argv[]'. The strings in 'arguments' don't undergo shell expansion, so you don't need to do special quoting, and shell variables, such as '$PWD', aren't resolved.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_arguments(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `currentDirectoryPath` property of `NSTask`.
     * @details Sets the current directory for the receiver. \@deprecated Use 'currentDirectoryURL' instead. If this method isn't used, the current directory is inherited from the process that created the receiver. This method raises an 'NSInvalidArgumentException' if the receiver has already been launched.
     * @return The converted Objective-C result.
     */
        std::string current_directory_path() const;
        /**
     * @brief Sets the `currentDirectoryPath` property of `NSTask`.
     * @details Sets the current directory for the receiver. \@deprecated Use 'currentDirectoryURL' instead. If this method isn't used, the current directory is inherited from the process that created the receiver. This method raises an 'NSInvalidArgumentException' if the receiver has already been launched.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_current_directory_path(const std::string& value) const;
        /**
     * @brief Returns the `currentDirectoryURL` property of `NSTask`.
     * @details The current directory for the receiver.
     * @return The converted Objective-C result.
     */
        URL current_directory_url() const;
        /**
     * @brief Sets the `currentDirectoryURL` property of `NSTask`.
     * @details The current directory for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_current_directory_url(const URL& value) const;
        /**
     * @brief Returns the `environment` property of `NSTask`.
     * @details The environment for the receiver. If this method isn't used, the environment is inherited from the process that created the receiver. This method raises an 'NSInvalidArgumentException' if the system has launched the receiver.
     * @return The converted Objective-C result.
     */
        std::map<std::string, std::string> environment() const;
        /**
     * @brief Sets the `environment` property of `NSTask`.
     * @details The environment for the receiver. If this method isn't used, the environment is inherited from the process that created the receiver. This method raises an 'NSInvalidArgumentException' if the system has launched the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_environment(const std::map<std::string, std::string>& value) const;
        /**
     * @brief Returns the `executableURL` property of `NSTask`.
     * @details The receiver's executable.
     * @return The converted Objective-C result.
     */
        URL executable_url() const;
        /**
     * @brief Sets the `executableURL` property of `NSTask`.
     * @details The receiver's executable.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_executable_url(const URL& value) const;
        /**
     * @brief Returns the `launchPath` property of `NSTask`.
     * @details Sets the receiver's executable. \@deprecated Use 'executableURL' instead.
     * @return The converted Objective-C result.
     */
        std::string launch_path() const;
        /**
     * @brief Sets the `launchPath` property of `NSTask`.
     * @details Sets the receiver's executable. \@deprecated Use 'executableURL' instead.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_launch_path(const std::string& value) const;
        /**
     * @brief Returns the `launchRequirementData` property of `NSTask`.
     * @details The launch requirement data for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> launch_requirement_data() const;
        /**
     * @brief Sets the `launchRequirementData` property of `NSTask`.
     * @details The launch requirement data for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_launch_requirement_data(const std::vector<std::uint8_t>& value) const;
        /**
     * @brief Returns the `processIdentifier` property of `NSTask`.
     * @details The receiver's process identifier.
     * @return The converted Objective-C result.
     */
        int process_identifier() const;
        /**
     * @brief Returns the `qualityOfService` property of `NSTask`.
     * @details The default quality of service level the system applies to operations the task executes.
     * @return The converted Objective-C result.
     */
        QualityOfService quality_of_service() const;
        /**
     * @brief Sets the `qualityOfService` property of `NSTask`.
     * @details The default quality of service level the system applies to operations the task executes.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_quality_of_service(QualityOfService value) const;
        /**
     * @brief Returns the `running` property of `NSTask`.
     * @details A status that indicates whether the receiver is still running.
     * @return The converted Objective-C result.
     */
        bool is_running() const;
        /**
     * @brief Returns the `standardError` property of `NSTask`.
     * @details The standard error for the receiver. If this is an 'NSPipe' object, launching the receiver automatically closes the write end of the pipe in the current task. Don't create a handle for the pipe and pass that as the argument, or the system won't automatically close the write end of the pipe. If this method isn't used, the standard error is inherited from the process that created the receiver. This method raises an 'NSInvalidArgumentException' if the system has launched the receiver.
     * @return The converted Objective-C result.
     */
        Object standard_error() const;
        /**
     * @brief Sets the `standardError` property of `NSTask`.
     * @details The standard error for the receiver. If this is an 'NSPipe' object, launching the receiver automatically closes the write end of the pipe in the current task. Don't create a handle for the pipe and pass that as the argument, or the system won't automatically close the write end of the pipe. If this method isn't used, the standard error is inherited from the process that created the receiver. This method raises an 'NSInvalidArgumentException' if the system has launched the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standard_error(const Object& value) const;
        /**
     * @brief Returns the `standardInput` property of `NSTask`.
     * @details The standard input for the receiver. If this is an 'NSPipe' object, launching the receiver automatically closes the read end of the pipe in the current task. Don't create a handle for the pipe and pass that as the argument, or the read end of the pipe won't be closed automatically. If this method isn't used, the standard input is inherited from the process that created the receiver. This method raises an 'NSInvalidArgumentException' if the system has launched the receiver.
     * @return The converted Objective-C result.
     */
        Object standard_input() const;
        /**
     * @brief Sets the `standardInput` property of `NSTask`.
     * @details The standard input for the receiver. If this is an 'NSPipe' object, launching the receiver automatically closes the read end of the pipe in the current task. Don't create a handle for the pipe and pass that as the argument, or the read end of the pipe won't be closed automatically. If this method isn't used, the standard input is inherited from the process that created the receiver. This method raises an 'NSInvalidArgumentException' if the system has launched the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standard_input(const Object& value) const;
        /**
     * @brief Returns the `standardOutput` property of `NSTask`.
     * @details The standard output for the receiver. If this is an 'NSPipe' object, launching the receiver automatically closes the write end of the pipe in the current task. Don't create a handle for the pipe and pass that as the argument, or the write end of the pipe won't be closed automatically. If this method isn't used, the standard output is inherited from the process that created the receiver. This method raises an 'NSInvalidArgumentException' if the system has launched the receiver.
     * @return The converted Objective-C result.
     */
        Object standard_output() const;
        /**
     * @brief Sets the `standardOutput` property of `NSTask`.
     * @details The standard output for the receiver. If this is an 'NSPipe' object, launching the receiver automatically closes the write end of the pipe in the current task. Don't create a handle for the pipe and pass that as the argument, or the write end of the pipe won't be closed automatically. If this method isn't used, the standard output is inherited from the process that created the receiver. This method raises an 'NSInvalidArgumentException' if the system has launched the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standard_output(const Object& value) const;
        /**
     * @brief Returns the `terminationHandler` property of `NSTask`.
     * @details A completion block the system invokes when the task completes. The system passes the task object to the block to allow access to the task parameters, for example to determine if the task completed successfully. This block isn't guaranteed to be fully executed prior to 'waitUntilExit' returning. Setting the block to nil is valid, and stops the previous block from being invoked, as long as it hasn't started in any way. Only one termination handler block can be set at any time. If a terminationHandler is set on an NSTask, the NSTaskDidTerminateNotification notification is not posted for that task.
     * @return The converted Objective-C result.
     */
        std::function<void(Task)> termination_handler() const;
        /**
     * @brief Sets the `terminationHandler` property of `NSTask`.
     * @details A completion block the system invokes when the task completes. The system passes the task object to the block to allow access to the task parameters, for example to determine if the task completed successfully. This block isn't guaranteed to be fully executed prior to 'waitUntilExit' returning. Setting the block to nil is valid, and stops the previous block from being invoked, as long as it hasn't started in any way. Only one termination handler block can be set at any time. If a terminationHandler is set on an NSTask, the NSTaskDidTerminateNotification notification is not posted for that task.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_termination_handler(std::function<void(Task)> value) const;
        /**
     * @brief Returns the `terminationReason` property of `NSTask`.
     * @details The reason the system terminated the task. The possible values are described in 'NSTaskTerminationReason'.
     * @return The converted Objective-C result.
     */
        TaskTerminationReason termination_reason() const;
        /**
     * @brief Returns the `terminationStatus` property of `NSTask`.
     * @details The exit status the receiver's executable returns. Each task defines and documents how your app should interpret the return value. For example, many commands return 0 if they complete successfully or an error code if they don't. You'll need to look at the documentation for that task to learn what values it returns under what circumstances. This method raises an 'NSInvalidArgumentException' if the receiver is still running. Verify that the receiver isn't running before you use it.
     * @return The converted Objective-C result.
     */
        int termination_status() const;
    };
}
