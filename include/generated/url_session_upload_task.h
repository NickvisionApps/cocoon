#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/url_session_data_task.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSURLSessionUploadTask` (Foundation).
     * @details An NSURLSessionUploadTask does not currently provide any additional functionality over an NSURLSessionDataTask. All delegate messages that may be sent referencing an NSURLSessionDataTask equally apply to NSURLSessionUploadTasks.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref URLSessionDataTask.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLSessionUploadTask url_session_upload_task;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlsessionuploadtask
     */
    class URLSessionUploadTask : public URLSessionDataTask
    {
    public:
        /// @brief Creates a new `NSURLSessionUploadTask` instance and returns a handle to it.
        explicit URLSessionUploadTask();
        /// @brief Creates a null handle that refers to no native object.
        URLSessionUploadTask(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLSessionUploadTask(Adopt adopt);
        /**
     * @brief Calls `-[NSURLSessionUploadTask cancelByProducingResumeData:]`.
     * @details Cancels an upload and calls the completion handler with resume data for later use. resumeData will be nil if the server does not support the latest resumable uploads Internet-Draft from the HTTP Working Group, found at https://datatracker.ietf.org/doc/draft-ietf-httpbis-resumable-upload/ - Parameter completionHandler: The completion handler to call when the upload has been successfully canceled.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void cancel_by_producing_resume_data(std::function<void(std::vector<std::uint8_t>)> completion_handler) const;
    };
}
