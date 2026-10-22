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
     * @details A URL session task that uploads data to the network in a request body. The ''URLSessionUploadTask'' class is a subclass of ''URLSessionDataTask'', which in turn is a concrete subclass of ''URLSessionTask''. The methods associated with the ''URLSessionUploadTask'' class are documented in ''URLSessionTask''. Upload tasks are used for making HTTP requests that require a request body (such as 'POST' or 'PUT'). They behave similarly to data tasks, but you create them by calling different methods on the session that are designed to make it easier to provide the content to upload. As with data tasks, if the server provides a response, upload tasks return that response as one or more 'NSData' objects in memory. > Note: > Unlike data tasks, you can use upload tasks to upload content in the background. When you create an upload task, you provide a ''URLRequest'' instance that contains any additional headers that you might need to send alongside the upload, such as the content type, content disposition, and so on. In iOS, when you create an upload task for a file in a background session, the system copies that file to a temporary location and streams data from there. While the upload is in progress, the task calls the session delegate's ''URLSessionTaskDelegate/urlSession(:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:)'' method periodically to provide you with status information. When the upload phase of the request finishes, the task behaves like a data task, calling methods on the session delegate to provide you with the server's response—headers, status code, content data, and so on.
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
