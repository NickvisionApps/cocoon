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
     * @details A URL session task that stores downloaded data to a file. An ''URLSessionDownloadTask'' is a concrete subclass of ''URLSessionTask'', which provides most of the methods for this class. Download tasks directly write the server's response data to a temporary file, providing your app with progress updates as data arrives from the server. When you use download tasks in background sessions, these downloads continue even when your app is in the suspended state or otherwise not running. You can pause (cancel) download tasks and resume them later (assuming the server supports doing so). You can also resume downloads that failed because of network connectivity problems. \#\#\# Download delegate behavior When you use a download task, your delegate receives several callbacks unique to download scenarios. - During download, the session periodically calls the delegate's ''URLSessionDownloadDelegate/urlSession(:downloadTask:didWriteData:totalBytesWritten:totalBytesExpectedToWrite:)'' method with status information. - Upon successful completion, the session calls the delegate's ''URLSessionDownloadDelegate/urlSession(:downloadTask:didFinishDownloadingTo:)'' method or completion handler. In that method, you must either open the file for reading or move it to a permanent location in your app's sandbox container directory. - Upon unsuccessful completion, the session calls the delegate's ''URLSessionTaskDelegate/urlSession(:task:didCompleteWithError:)'' method or completion handler. The only errors your delegate receives through the 'error' parameter are client-side errors, such as being unable to resolve the hostname or connect to the host. To check for server-side errors, inspect the ''URLSessionTask/response'' property of the 'task' parameter received by this callback.
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
     * @details Cancels a download and calls the completion handler with resume data for later use. If conditions will allow for resuming the download in the future, the callback will be called with an opaque data blob, which may be used with '-downloadTaskWithResumeData:' to attempt to resume the download. If resume data cannot be created, the completion handler will be called with 'nil' resumeData. - Parameter completionHandler: The completion handler to call when the cancel operation is complete. The 'resumeData' parameter contains data that can be used to resume the download at a later time, or 'nil' if resuming is not possible.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void cancel_by_producing_resume_data(std::function<void(std::vector<std::uint8_t>)> completion_handler) const;
    };
}
