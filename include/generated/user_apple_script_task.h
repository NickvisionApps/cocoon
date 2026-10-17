#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/user_script_task.h"
#include "types.h"

namespace cocoon
{
    class AppleEventDescriptor;
    class Error;

    /**
     * @brief C++ handle for the Objective-C class `NSUserAppleScriptTask` (Foundation).
     * @details An object that executes AppleScript scripts. The ''NSUserAppleScriptTask'' class is intended to run AppleScript scripts from your application. It is intended to execute user-supplied scripts and will execute them outside of the application's sandbox, if any. The class is not intended to execute scripts built into an application; for that, use one of the ''Process'' classes. If the application is sandboxed, then the script must be in the ''FileManager/SearchPathDirectory/applicationScriptsDirectory'' folder. A sandboxed application may read from, but not write to, this folder. If you simply need to execute scripts without regard to input or output, use ''NSUserScriptTask'', which can execute any of the specific types. If you need specific control over the input to or output from the script, use this class.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref UserScriptTask.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UserAppleScriptTask user_apple_script_task;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsuserapplescripttask
     */
    class UserAppleScriptTask : public UserScriptTask
    {
    public:
        /// @brief Creates a new `NSUserAppleScriptTask` instance and returns a handle to it.
        explicit UserAppleScriptTask();
        /// @brief Creates a null handle that refers to no native object.
        UserAppleScriptTask(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UserAppleScriptTask(Adopt adopt);
        /**
     * @brief Calls `-[NSUserAppleScriptTask executeWithAppleEvent:completionHandler:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        void execute_with_apple_event(const AppleEventDescriptor& event, std::function<void(AppleEventDescriptor, Error)> handler) const;
    };
}
