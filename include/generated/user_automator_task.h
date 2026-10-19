#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/user_script_task.h"
#include "types.h"

namespace cocoon
{
    class Error;

    /**
     * @brief C++ handle for the Objective-C class `NSUserAutomatorTask` (Foundation).
     * @details NSUserAutomatorTask: an Automator workflow.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref UserScriptTask.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UserAutomatorTask user_automator_task;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsuserautomatortask
     */
    class UserAutomatorTask : public UserScriptTask
    {
    public:
        /// @brief Creates a new `NSUserAutomatorTask` instance and returns a handle to it.
        explicit UserAutomatorTask();
        /// @brief Creates a null handle that refers to no native object.
        UserAutomatorTask(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UserAutomatorTask(Adopt adopt);
        /**
     * @brief Calls `-[NSUserAutomatorTask executeWithInput:completionHandler:]`.
     * @param input Argument converted to the Objective-C parameter of the same role.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        void execute_with_input(const Object& input, std::function<void(Object, Error)> handler) const;
        /**
     * @brief Returns the `variables` property of `NSUserAutomatorTask`.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> variables() const;
        /**
     * @brief Sets the `variables` property of `NSUserAutomatorTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_variables(const std::map<std::string, Object>& value) const;
    };
}
