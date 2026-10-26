#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/url_session_task.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSURLSessionDataTask` (Foundation).
     * @details An NSURLSessionDataTask does not provide any additional functionality over an NSURLSessionTask and its presence is merely to provide lexical differentiation from download and upload tasks.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref URLSessionTask.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLSessionDataTask url_session_data_task;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlsessiondatatask
     */
    class URLSessionDataTask : public URLSessionTask
    {
    public:
        /// @brief Creates a new `NSURLSessionDataTask` instance and returns a handle to it.
        explicit URLSessionDataTask();
        /// @brief Creates a null handle that refers to no native object.
        URLSessionDataTask(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLSessionDataTask(Adopt adopt);
    };
}
