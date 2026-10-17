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
     * @details A URL session task that returns downloaded data directly to the app in memory. A ''URLSessionDataTask'' is a concrete subclass of ''URLSessionTask''. The methods in the ''URLSessionDataTask'' class are documented in ''URLSessionTask''. A data task returns data directly to the app (in memory) as one or more 'NSData' objects. When you use a data task: - During upload of the body data (if your app provides any), the session periodically calls its delegate's ''URLSessionTaskDelegate/urlSession(:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:)'' method with status information. - After receiving an initial response, the session calls its delegate's ''URLSessionDataDelegate/urlSession(:dataTask:didReceive:completionHandler:)'' method to let you examine the status code and headers, and optionally convert the data task into a download task. - During the transfer, the session calls its delegate's ''URLSessionDataDelegate/urlSession(:dataTask:didReceive:)'' method to provide your app with the content as it arrives. - Upon completion, the session calls its delegate's ''URLSessionDataDelegate/urlSession(:dataTask:willCacheResponse:completionHandler:)'' method to let you determine whether the response should be cached. For examples of using data tasks for fetching and uploading data, see \<doc:fetching-website-data-into-memory> and \<doc:uploading-data-to-a-website>.
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
