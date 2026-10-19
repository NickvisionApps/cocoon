#pragma once

#include "generated/availability.h"
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
     * @details NSUserAppleScriptTask: an AppleScript script.
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
