#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/url_session_task.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSURLSessionDownloadTask` (Foundation).
     * @details NSURLSessionDownloadTask is a task that represents a download to local storage.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref URLSessionTask.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLSessionDownloadTask url_session_download_task;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlsessiondownloadtask
     */
    class URLSessionDownloadTask : public URLSessionTask
    {
    public:
        /// @brief Creates a new `NSURLSessionDownloadTask` instance and returns a handle to it.
        explicit URLSessionDownloadTask();
        /// @brief Creates a null handle that refers to no native object.
        URLSessionDownloadTask(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLSessionDownloadTask(Adopt adopt);
        /**
     * @brief Calls `-[NSURLSessionDownloadTask cancelByProducingResumeData:]`.
     * @details Cancel the download (and calls the superclass -cancel). If conditions will allow for resuming the download in the future, the callback will be called with an opaque data blob, which may be used with -downloadTaskWithResumeData: to attempt to resume the download. If resume data cannot be created, the completion handler will be called with nil resumeData.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void cancel_by_producing_resume_data(std::function<void(std::vector<std::uint8_t>)> completion_handler) const;
    };
}
