#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class NetService;
    class OperationQueue;
    class URL;
    class URLRequest;
    class URLResponse;
    class URLSessionConfiguration;
    class URLSessionDataTask;
    class URLSessionDownloadTask;
    class URLSessionStreamTask;
    class URLSessionTask;
    class URLSessionUploadTask;
    class URLSessionWebSocketTask;

    /**
     * @brief C++ handle for the Objective-C class `NSURLSession` (Foundation).
     * @details FOUNDATION_EXPORT const int64_t NSURLSessionTransferSizeUnknown API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0)); / -1LL
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLSession url_session;
     * url_session.set_session_description("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::URLSession url_session{};
     * url_session.set_session_description("text");
     * auto session_description = url_session.session_description();
     * auto made_0 = cocoon::URLSession::session_with_configuration(cocoon::URLSessionConfiguration());
     * url_session.data_task_with_request(cocoon::URLRequest());
     * url_session.data_task_with_url(cocoon::URL());
     * url_session.download_task_with_request(cocoon::URLRequest());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlsession
     */
    class URLSession : public Object
    {
    public:
        /// @brief Creates a new `NSURLSession` instance and returns a handle to it.
        explicit URLSession();
        /// @brief Creates a null handle that refers to no native object.
        URLSession(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLSession(Adopt adopt);
        /**
     * @brief Calls `-[NSURLSession dataTaskWithRequest:]`.
     * @details Creates a data task with the given request. The request may have a body stream.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDataTask data_task_with_request(const URLRequest& request) const;
        /**
     * @brief Calls `-[NSURLSession dataTaskWithRequest:completionHandler:]`.
     * @details data task convenience methods. These methods create tasks that bypass the normal delegate calls for response and data delivery, and provide a simple cancelable asynchronous interface to receiving data. Errors will be returned in the NSURLErrorDomain, see \<Foundation/NSURLError.h>. The delegate, if any, will still be called for authentication challenges.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDataTask data_task_with_request(const URLRequest& request, std::function<void(std::vector<std::uint8_t>, URLResponse, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession dataTaskWithURL:]`.
     * @details Creates a data task to retrieve the contents of the given URL.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDataTask data_task_with_url(const URL& url) const;
        /**
     * @brief Calls `-[NSURLSession dataTaskWithURL:completionHandler:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDataTask data_task_with_url(const URL& url, std::function<void(std::vector<std::uint8_t>, URLResponse, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession downloadTaskWithRequest:]`.
     * @details Creates a download task with the given request.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDownloadTask download_task_with_request(const URLRequest& request) const;
        /**
     * @brief Calls `-[NSURLSession downloadTaskWithRequest:completionHandler:]`.
     * @details download task convenience methods. When a download successfully completes, the NSURL will point to a file that must be read or copied during the invocation of the completion routine. The file will be removed automatically.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDownloadTask download_task_with_request(const URLRequest& request, std::function<void(URL, URLResponse, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession downloadTaskWithResumeData:]`.
     * @details Creates a download task with the resume data. If the download cannot be successfully resumed, URLSession:task:didCompleteWithError: will be called.
     * @param resume_data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDownloadTask download_task_with_resume_data(const std::vector<std::uint8_t>& resume_data) const;
        /**
     * @brief Calls `-[NSURLSession downloadTaskWithResumeData:completionHandler:]`.
     * @param resume_data Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDownloadTask download_task_with_resume_data(const std::vector<std::uint8_t>& resume_data, std::function<void(URL, URLResponse, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession downloadTaskWithURL:]`.
     * @details Creates a download task to download the contents of the given URL.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDownloadTask download_task_with_url(const URL& url) const;
        /**
     * @brief Calls `-[NSURLSession downloadTaskWithURL:completionHandler:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDownloadTask download_task_with_url(const URL& url, std::function<void(URL, URLResponse, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession finishTasksAndInvalidate]`.
     * @details -finishTasksAndInvalidate returns immediately and existing tasks will be allowed to run to completion. New tasks may not be created. The session will continue to make delegate callbacks until URLSession:didBecomeInvalidWithError: has been issued. -finishTasksAndInvalidate and -invalidateAndCancel do not have any effect on the shared session instance. When invalidating a background session, it is not safe to create another background session with the same identifier until URLSession:didBecomeInvalidWithError: has been issued.
     */
        void finish_tasks_and_invalidate() const;
        /**
     * @brief Calls `-[NSURLSession flushWithCompletionHandler:]`.
     * @details - (void)resetWithCompletionHandler:(void (NS_SWIFT_SENDABLE ^)(void))completionHandler; / empty all cookies, cache and credential stores, removes disk files, issues -flushWithCompletionHandler:. Invokes completionHandler() on the delegate queue.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void flush_with_completion_handler(std::function<void()> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession getAllTasksWithCompletionHandler:]`.
     * @details - (void)getTasksWithCompletionHandler:(void (NS_SWIFT_SENDABLE ^)(NSArray\<NSURLSessionDataTask > dataTasks, NSArray\<NSURLSessionUploadTask > uploadTasks, NSArray\<NSURLSessionDownloadTask > downloadTasks))completionHandler NS_SWIFT_ASYNC_NAME(getter:tasks()); / invokes completionHandler with outstanding data, upload and download tasks.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void get_all_tasks_with_completion_handler(std::function<void(std::vector<URLSessionTask>)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession getTasksWithCompletionHandler:]`.
     * @details - (void)flushWithCompletionHandler:(void (NS_SWIFT_SENDABLE ^)(void))completionHandler; / flush storage to disk and clear transient network caches. Invokes completionHandler() on the delegate queue.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void get_tasks_with_completion_handler(std::function<void(std::vector<URLSessionDataTask>, std::vector<URLSessionUploadTask>, std::vector<URLSessionDownloadTask>)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession invalidateAndCancel]`.
     * @details -invalidateAndCancel acts as -finishTasksAndInvalidate, but issues -cancel to all outstanding tasks for this session. Note task cancellation is subject to the state of the task, and some tasks may have already have completed at the time they are sent -cancel.
     */
        void invalidate_and_cancel() const;
        /**
     * @brief Calls `-[NSURLSession resetWithCompletionHandler:]`.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void reset_with_completion_handler(std::function<void()> completion_handler) const;
        /**
     * @brief Calls `+[NSURLSession sessionWithConfiguration:]`.
     * @details Customization of NSURLSession occurs during creation of a new session. If you only need to use the convenience routines with custom configuration options it is not necessary to specify a delegate. If you do specify a delegate, the delegate will be retained until after the delegate has been sent the URLSession:didBecomeInvalidWithError: message.
     * @param configuration Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URLSession session_with_configuration(const URLSessionConfiguration& configuration);
        /**
     * @brief Calls `+[NSURLSession sessionWithConfiguration:delegate:delegateQueue:]`.
     * @param configuration Argument converted to the Objective-C parameter of the same role.
     * @param delegate Argument converted to the Objective-C parameter of the same role.
     * @param queue Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URLSession session_with_configuration(const URLSessionConfiguration& configuration, const Object& delegate, const OperationQueue& queue);
        /**
     * @brief Calls `-[NSURLSession streamTaskWithHostName:port:]`.
     * @details Creates a bidirectional stream task to a given host and port.
     * @param hostname Argument converted to the Objective-C parameter of the same role.
     * @param port Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionStreamTask stream_task_with_host_name(const std::string& hostname, std::int64_t port) const;
        /**
     * @brief Calls `-[NSURLSession streamTaskWithNetService:]`.
     * @details Creates a bidirectional stream task with an NSNetService to identify the endpoint. The NSNetService will be resolved before any IO completes.
     * @param service Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionStreamTask stream_task_with_net_service(const NetService& service) const;
        /**
     * @brief Calls `-[NSURLSession uploadTaskWithRequest:fromData:]`.
     * @details Creates an upload task with the given request. The body of the request is provided from the bodyData.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @param body_data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionUploadTask upload_task_with_request(const URLRequest& request, const std::vector<std::uint8_t>& body_data) const;
        /**
     * @brief Calls `-[NSURLSession uploadTaskWithRequest:fromData:completionHandler:]`.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @param body_data Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionUploadTask upload_task_with_request(const URLRequest& request, const std::vector<std::uint8_t>& body_data, std::function<void(std::vector<std::uint8_t>, URLResponse, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession uploadTaskWithRequest:fromFile:]`.
     * @details Creates an upload task with the given request. The body of the request will be created from the file referenced by fileURL
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @param file_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionUploadTask upload_task_with_request(const URLRequest& request, const URL& file_url) const;
        /**
     * @brief Calls `-[NSURLSession uploadTaskWithRequest:fromFile:completionHandler:]`.
     * @details upload convenience method.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @param file_url Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionUploadTask upload_task_with_request(const URLRequest& request, const URL& file_url, std::function<void(std::vector<std::uint8_t>, URLResponse, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession uploadTaskWithResumeData:]`.
     * @details Creates an upload task from a resume data blob. Requires the server to support the latest resumable uploads Internet-Draft from the HTTP Working Group, found at https://datatracker.ietf.org/doc/draft-ietf-httpbis-resumable-upload/ If resuming from an upload file, the file must still exist and be unmodified. If the upload cannot be successfully resumed, URLSession:task:didCompleteWithError: will be called. - Parameter resumeData: Resume data blob from an incomplete upload, such as data returned by the cancelByProducingResumeData: method. - Returns: A new session upload task, or nil if the resumeData is invalid.
     * @param resume_data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionUploadTask upload_task_with_resume_data(const std::vector<std::uint8_t>& resume_data) const;
        /**
     * @brief Calls `-[NSURLSession uploadTaskWithResumeData:completionHandler:]`.
     * @details Creates a URLSessionUploadTask from a resume data blob. If resuming from an upload file, the file must still exist and be unmodified. - Parameter resumeData: Resume data blob from an incomplete upload, such as data returned by the cancelByProducingResumeData: method. - Parameter completionHandler: The completion handler to call when the load request is complete. - Returns: A new session upload task, or nil if the resumeData is invalid.
     * @param resume_data Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionUploadTask upload_task_with_resume_data(const std::vector<std::uint8_t>& resume_data, std::function<void(std::vector<std::uint8_t>, URLResponse, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession uploadTaskWithStreamedRequest:]`.
     * @details Creates an upload task with the given request. The previously set body stream of the request (if any) is ignored and the URLSession:task:needNewBodyStream: delegate will be called when the body payload is required.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionUploadTask upload_task_with_streamed_request(const URLRequest& request) const;
        /**
     * @brief Calls `-[NSURLSession webSocketTaskWithRequest:]`.
     * @details Creates a WebSocket task given the request. The request properties can be modified and will be used by the task during the HTTP handshake phase. Clients who want to add custom protocols can do so by directly adding headers with the key Sec-WebSocket-Protocol and a comma separated list of protocols they wish to negotiate with the server. The custom HTTP headers provided by the client will remain unchanged for the handshake with the server.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionWebSocketTask web_socket_task_with_request(const URLRequest& request) const;
        /**
     * @brief Calls `-[NSURLSession webSocketTaskWithURL:]`.
     * @details Creates a WebSocket task given the url. The given url must have a ws or wss scheme.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionWebSocketTask web_socket_task_with_url(const URL& url) const;
        /**
     * @brief Calls `-[NSURLSession webSocketTaskWithURL:protocols:]`.
     * @details Creates a WebSocket task given the url and an array of protocols. The protocols will be used in the WebSocket handshake to negotiate a preferred protocol with the server Note - The protocol will not affect the WebSocket framing. More details on the protocol can be found by reading the WebSocket RFC
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param protocols Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionWebSocketTask web_socket_task_with_url(const URL& url, const std::vector<std::string>& protocols) const;
        /**
     * @brief Returns the `configuration` property of `NSURLSession`.
     * @return The converted Objective-C result.
     */
        URLSessionConfiguration configuration() const;
        /**
     * @brief Returns the `delegateQueue` property of `NSURLSession`.
     * @return The converted Objective-C result.
     */
        OperationQueue delegate_queue() const;
        /**
     * @brief Returns the `sessionDescription` property of `NSURLSession`.
     * @details The sessionDescription property is available for the developer to provide a descriptive label for the session.
     * @return The converted Objective-C result.
     */
        std::string session_description() const;
        /**
     * @brief Sets the `sessionDescription` property of `NSURLSession`.
     * @details The sessionDescription property is available for the developer to provide a descriptive label for the session.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_session_description(const std::string& value) const;
        /**
     * @brief Returns the `sharedSession` property of `NSURLSession`.
     * @details The shared session uses the currently set global NSURLCache, NSHTTPCookieStorage and NSURLCredentialStorage objects.
     * @return The converted Objective-C result.
     */
        static URLSession shared_session();
    };
}
