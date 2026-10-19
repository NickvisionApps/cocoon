#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/user_script_task.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class FileHandle;

    /**
     * @brief C++ handle for the Objective-C class `NSUserUnixTask` (Foundation).
     * @details NSUserUnixTask: a Unix executable file, typically a shell script.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref UserScriptTask.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UserUnixTask user_unix_task;
     * user_unix_task.set_standard_error(cocoon::FileHandle());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::UserUnixTask user_unix_task{};
     * user_unix_task.set_standard_error(cocoon::FileHandle());
     * auto standard_error = user_unix_task.standard_error();
     * user_unix_task.set_standard_input(cocoon::FileHandle());
     * auto standard_input = user_unix_task.standard_input();
     * user_unix_task.set_standard_output(cocoon::FileHandle());
     * auto standard_output = user_unix_task.standard_output();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsuserunixtask
     */
    class UserUnixTask : public UserScriptTask
    {
    public:
        /// @brief Creates a new `NSUserUnixTask` instance and returns a handle to it.
        explicit UserUnixTask();
        /// @brief Creates a null handle that refers to no native object.
        UserUnixTask(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UserUnixTask(Adopt adopt);
        /**
     * @brief Calls `-[NSUserUnixTask executeWithArguments:completionHandler:]`.
     * @param arguments Argument converted to the Objective-C parameter of the same role.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        void execute_with_arguments(const std::vector<std::string>& arguments, std::function<void(Error)> handler) const;
        /**
     * @brief Returns the `standardError` property of `NSUserUnixTask`.
     * @return The converted Objective-C result.
     */
        FileHandle standard_error() const;
        /**
     * @brief Sets the `standardError` property of `NSUserUnixTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standard_error(const FileHandle& value) const;
        /**
     * @brief Returns the `standardInput` property of `NSUserUnixTask`.
     * @return The converted Objective-C result.
     */
        FileHandle standard_input() const;
        /**
     * @brief Sets the `standardInput` property of `NSUserUnixTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standard_input(const FileHandle& value) const;
        /**
     * @brief Returns the `standardOutput` property of `NSUserUnixTask`.
     * @return The converted Objective-C result.
     */
        FileHandle standard_output() const;
        /**
     * @brief Sets the `standardOutput` property of `NSUserUnixTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standard_output(const FileHandle& value) const;
    };
}
