#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSUserScriptTask` (Foundation).
     * @details NSUserScriptTask: An abstract "user script".
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UserScriptTask user_script_task;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsuserscripttask
     */
    class UserScriptTask : public Object
    {
    public:
        /// @brief Creates a new `NSUserScriptTask` instance and returns a handle to it.
        explicit UserScriptTask(const URL& url);
        /// @brief Creates a new `NSUserScriptTask` instance and returns a handle to it.
        explicit UserScriptTask();
        /// @brief Creates a null handle that refers to no native object.
        UserScriptTask(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UserScriptTask(Adopt adopt);
        /**
     * @brief Calls `-[NSUserScriptTask executeWithCompletionHandler:]`.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        void execute_with_completion_handler(std::function<void(Error)> handler) const;
        /**
     * @brief Returns the `scriptURL` property of `NSUserScriptTask`.
     * @return The converted Objective-C result.
     */
        URL script_url() const;
    };
}
