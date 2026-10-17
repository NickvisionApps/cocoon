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
     * @details An object that coordinates a group of related, network data transfer tasks. The ''URLSession'' class and related classes provide an API for downloading data from and uploading data to endpoints indicated by URLs. Your app can also use this API to perform background downloads when your app isn't running or, in iOS, while your app is suspended. You can use the related ''URLSessionDelegate'' and ''URLSessionTaskDelegate'' to support authentication and receive events like redirection and task completion. > Note: > The ''URLSession'' API involves many different classes that work together in a fairly complex way which may not be obvious if you read the reference documentation by itself. Before using the API, read the overview in the \<doc:url-loading-system> topic. The articles in the Essentials, Uploading, and Downloading sections offer examples of performing common tasks with ''URLSession''. Your app creates one or more ''URLSession'' instances, each of which coordinates a group of related data-transfer tasks. For example, if you're creating a web browser, your app might create one session per tab or window, or one session for interactive use and another for background downloads. Within each session, your app adds a series of tasks, each of which represents a request for a specific URL (following HTTP redirects, if necessary). \#\#\# Types of URL sessions The tasks within a given URL session share a common session configuration object, which defines connection behavior, like the maximum number of simultaneous connections to make to a single host, whether connections can use the cellular network, and so on. ''URLSession'' has a singleton ''shared'' session (which doesn't have a configuration object) for basic requests. It's not as customizable as sessions you create, but it serves as a good starting point if you have very limited requirements. You access this session by calling the shared class method. For other kinds of sessions, you create a ''URLSession'' with one of three kinds of configurations: - A default session behaves much like the shared session, but lets you configure it. You can also assign a delegate to the default session to obtain data incrementally. - Ephemeral sessions are similar to shared sessions, but don't write caches, cookies, or credentials to disk. - Background sessions let you perform uploads and downloads of content in the background while your app isn't running. See Creating a session configuration object in the ''URLSessionConfiguration'' class for details on creating each type of configuration. \#\#\# Types of URL session tasks Within a session, you create tasks that optionally upload data to a server and then retrieve data from the server either as a file on disk or as one or more ''NSData'' objects in memory. The ''URLSession'' API provides four types of tasks: - Data tasks send and receive data using ''NSData'' objects. Data tasks are intended for short, often interactive requests to a server. - Upload tasks are similar to data tasks, but they also send data (often in the form of a file), and support background uploads while the app isn't running. - Download tasks retrieve data in the form of a file, and support background downloads and uploads while the app isn't running. - WebSocket tasks exchange messages over TCP and TLS, using the WebSocket protocol defined in [RFC 6455](https://tools.ietf.org/html/rfc6455). \#\#\# Using a session delegate Tasks in a session also share a common delegate object. You implement this delegate to provide and obtain information when various events occur, including when: - Authentication fails. - Data arrives from the server. - Data becomes available for caching. If you don't need the features provided by a delegate, you can use this API without providing one by passing 'nil' when you create a session. > Important: > The session object keeps a strong reference to the delegate until your app exits or explicitly invalidates the session. If you don't invalidate the session, your app leaks memory until the app terminates. Each task you create with the session calls back to the session's delegate, using the methods defined in ''URLSessionTaskDelegate''. You can also intercept these callbacks before they reach the session delegate by populating a separate ''URLSessionTask/delegate'' that's specific to the task. \#\#\# Asynchronicity and URL sessions Like most networking APIs, the ''URLSession'' API is highly asynchronous. It returns data to your app in one of three ways, depending on the methods you call: - If you're using Swift, you can use the methods marked with the 'async' keyword to perform common tasks. For example, ''data(from:delegate:)'' fetches data, while ''download(from:delegate:)'' downloads files. Your call point uses the 'await' keyword to suspend running until the transfer completes. You can also use the ''bytes(from:delegate:)'' method to receive data as an \<doc://com.apple.documentation/documentation/swift/asyncsequence>. With this approach, you use the 'for'-'await'-'in' syntax to iterate over the data as your app receives it. The ''URL'' type also offers covenience methods to fetch bytes or lines from the shared URL session. - In Swift or Objective-C, you can provide a completion handler block, which runs when the transfer completes. - In Swift or Objective-C, you can receive callbacks to a delegate method as the transfer progresses and immediately after it completes. In addition to delivering this information to delegates, the ''URLSession'' provides status and progress properties. Query these properties if you need to make programmatic decisions based on the current state of the task (with the caveat that its state can change at any time). \#\#\# Protocol support The ''URLSession'' class natively supports the 'data', 'file', 'ftp', 'http', and 'https' URL schemes, with transparent support for proxy servers and SOCKS gateways, as configured in the user's system preferences. ''URLSession'' supports the HTTP/1.1, HTTP/2, and HTTP/3 protocols. HTTP/2 support, as described by [RFC 7540](https://tools.ietf.org/html/rfc7540), requires a server that supports Application-Layer Protocol Negotiation (ALPN). You can also add support for your own custom networking protocols and URL schemes (for your app's private use) by subclassing ''URLProtocol''. \#\#\# App Transport Security (ATS) iOS 9.0 and macOS 10.11 and later use App Transport Security (ATS) for all HTTP connections made with ''URLSession''. ATS requires that HTTP connections use HTTPS ([RFC 2818](https://tools.ietf.org/html/rfc2818)). For more information, see \<doc://com.apple.documentation/documentation/bundleresources/information-property-list/nsapptransportsecurity>. \#\#\# Foundation copying behavior Session and task objects conform to the ''NSCopying'' protocol as follows: - When your app copies a session or task object, you get the same object back. - When your app copies a configuration object, you get a new copy you can independently modify. \#\#\# Thread safety The URL session API is thread-safe. You can freely create sessions and tasks in any thread context. When your delegate methods call the provided completion handlers, the work is automatically scheduled on the correct delegate queue.
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
     * @details Creates a task that retrieves the contents of a URL based on the specified URL request object. By creating a task based on a request object, you can tune various aspects of the task's behavior, including the cache policy and timeout interval. After you create the task, you must start it by calling its '-resume' method. - Parameter request: A URL request object that provides request-specific information such as the URL, cache policy, request type, and body data or body stream. - Returns: The new session data task.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDataTask data_task_with_request(const URLRequest& request) const;
        /**
     * @brief Calls `-[NSURLSession dataTaskWithRequest:completionHandler:]`.
     * @details Creates a task that retrieves the contents of a URL based on the specified URL request object, and calls a handler upon completion. By creating a task based on a request object, you can tune various aspects of the task's behavior, including the cache policy and timeout interval. By using the completion handler, the task bypasses calls to delegate methods for response and data delivery, and instead provides any resulting 'NSData', 'NSURLResponse', and 'NSError' objects inside the completion handler. Delegate methods for handling authentication challenges, however, are still called. After you create the task, you must start it by calling its '-resume' method. - Parameter request: A URL request object that provides the URL, cache policy, request type, body data or body stream, and so on. - Parameter completionHandler: The completion handler to call when the load request is complete. This handler is executed on the delegate queue.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDataTask data_task_with_request(const URLRequest& request, std::function<void(std::vector<std::uint8_t>, URLResponse, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession dataTaskWithURL:]`.
     * @details Creates a task that retrieves the contents of the specified URL. After you create the task, you must start it by calling its '-resume' method. The task calls methods on the session's delegate to provide you with the response metadata, response data, and so on. - Parameter url: The URL to be retrieved. - Returns: The new session data task.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDataTask data_task_with_url(const URL& url) const;
        /**
     * @brief Calls `-[NSURLSession dataTaskWithURL:completionHandler:]`.
     * @details Creates a task that retrieves the contents of the specified URL, then calls a handler upon completion. After you create the task, you must start it by calling its '-resume' method. By using the completion handler, the task bypasses calls to delegate methods for response and data delivery, and instead provides any resulting 'NSData', 'NSURLResponse', and 'NSError' objects inside the completion handler. Delegate methods for handling authentication challenges, however, are still called. - Parameter url: The URL to be retrieved. - Parameter completionHandler: The completion handler to call when the load request is complete. This handler is executed on the delegate queue.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDataTask data_task_with_url(const URL& url, std::function<void(std::vector<std::uint8_t>, URLResponse, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession downloadTaskWithRequest:]`.
     * @details Creates a download task that retrieves the contents of a URL based on the specified URL request object and saves the results to a file. By creating a task based on a request object, you can tune various aspects of the task's behavior, including the cache policy and timeout interval. After you create the task, you must start it by calling its '-resume' method. The task calls methods on the session's delegate to provide you with progress notifications, the location of the resulting temporary file, and so on. - Parameter request: A URL request object that provides the URL, cache policy, request type, body data or body stream, and so on. - Returns: The new session download task.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDownloadTask download_task_with_request(const URLRequest& request) const;
        /**
     * @brief Calls `-[NSURLSession downloadTaskWithRequest:completionHandler:]`.
     * @details Creates a download task that retrieves the contents of a URL based on the specified URL request object, saves the results to a file, and calls a handler upon completion. By creating a task based on a request object, you can tune various aspects of the task's behavior, including the cache policy and timeout interval. After you create the task, you must start it by calling its '-resume' method. - Parameter request: A URL request object that provides the URL, cache policy, request type, body data or body stream, and so on. - Parameter completionHandler: The completion handler to call when the load request is complete. This handler is executed on the delegate queue.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDownloadTask download_task_with_request(const URLRequest& request, std::function<void(URL, URLResponse, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession downloadTaskWithResumeData:]`.
     * @details Creates a download task to resume a previously canceled or failed download. After you create the task, you must start it by calling its '-resume' method. This method is equivalent to '-downloadTaskWithResumeData:completionHandler:' with a 'nil' completion handler. For detailed usage information, including ways to obtain a resume data object, see that method. - Parameter resumeData: A data object that provides the data necessary to resume a download. - Returns: The new session download task.
     * @param resume_data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDownloadTask download_task_with_resume_data(const std::vector<std::uint8_t>& resume_data) const;
        /**
     * @brief Calls `-[NSURLSession downloadTaskWithResumeData:completionHandler:]`.
     * @details Creates a download task to resume a previously canceled or failed download and calls a handler upon completion. Your app can obtain a 'resumeData' object in two ways: - If your app cancels an existing transfer by calling '-cancelByProducingResumeData:', the session object passes a 'resumeData' object to the completion handler that you provided in that call. - If a transfer fails, the session object provides an 'NSError' object either to its delegate or to the task's completion handler. In that object, the 'NSURLSessionDownloadTaskResumeData' key in the 'userInfo' dictionary contains a 'resumeData' object. After you create the task, you must start it by calling its '-resume' method. > Note: A download can be resumed only if it is an HTTP or HTTPS 'GET' request, and only > if the remote server supports byte-range requests (with the 'Range' header) and provides > the 'ETag' or 'Last-Modified' header in its responses. - Parameter resumeData: A data object that provides the data necessary to resume the download. - Parameter completionHandler: The completion handler to call when the load request is complete. This handler is executed on the delegate queue.
     * @param resume_data Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDownloadTask download_task_with_resume_data(const std::vector<std::uint8_t>& resume_data, std::function<void(URL, URLResponse, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession downloadTaskWithURL:]`.
     * @details Creates a download task that retrieves the contents of the specified URL and saves the results to a file. After you create the task, you must start it by calling its '-resume' method. - Parameter url: The URL to download. - Returns: The new session download task.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDownloadTask download_task_with_url(const URL& url) const;
        /**
     * @brief Calls `-[NSURLSession downloadTaskWithURL:completionHandler:]`.
     * @details Creates a download task that retrieves the contents of the specified URL, saves the results to a file, and calls a handler upon completion. After you create the task, you must start it by calling its '-resume' method. - Parameter url: The URL to download. - Parameter completionHandler: The completion handler to call when the load request is complete. This handler is executed on the delegate queue.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionDownloadTask download_task_with_url(const URL& url, std::function<void(URL, URLResponse, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession finishTasksAndInvalidate]`.
     * @details Invalidates the session, allowing any outstanding tasks to finish. This method returns immediately without waiting for tasks to finish. Once a session is invalidated, new tasks cannot be created in the session, but existing tasks continue until completion. After the last task finishes and the session makes the last delegate call related to those tasks, the session calls the 'URLSession:didBecomeInvalidWithError:' method on its delegate, then breaks references to the delegate and callback objects. After invalidation, session objects cannot be reused. To cancel all outstanding tasks, call '-invalidateAndCancel' instead. > Important: Calling this method on the shared session has no effect. When invalidating a background session, it is not safe to create another background session with the same identifier until 'URLSession:didBecomeInvalidWithError:' has been issued.
     */
        void finish_tasks_and_invalidate() const;
        /**
     * @brief Calls `-[NSURLSession flushWithCompletionHandler:]`.
     * @details Flushes cookies and credentials to disk, clears transient caches, and ensures that future requests occur on a new TCP connection. - Parameter completionHandler: The completion handler to call when the flush operation is complete. This handler is executed on the delegate queue.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void flush_with_completion_handler(std::function<void()> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession getAllTasksWithCompletionHandler:]`.
     * @details Asynchronously calls a completion callback with all tasks in a session. - Parameter completionHandler: The completion handler to call with the list of tasks.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void get_all_tasks_with_completion_handler(std::function<void(std::vector<URLSessionTask>)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession getTasksWithCompletionHandler:]`.
     * @details Asynchronously calls a completion callback with all data, upload, and download tasks in a session. - Parameter completionHandler: The completion handler to call with the list of tasks. This handler is executed on the delegate queue. The arrays passed to the completion handler contain any tasks that you have created within the session, not including any tasks that have been invalidated after completing, failing, or being cancelled.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void get_tasks_with_completion_handler(std::function<void(std::vector<URLSessionDataTask>, std::vector<URLSessionUploadTask>, std::vector<URLSessionDownloadTask>)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession invalidateAndCancel]`.
     * @details Cancels all outstanding tasks and then invalidates the session. Once invalidated, references to the delegate and callback objects are broken. After invalidation, session objects cannot be reused. To allow outstanding tasks to run until completion, call '-finishTasksAndInvalidate' instead. > Important: Calling this method on the shared session has no effect.
     */
        void invalidate_and_cancel() const;
        /**
     * @brief Calls `-[NSURLSession resetWithCompletionHandler:]`.
     * @details Empties all cookies, caches and credential stores, removes disk files, flushes in-progress downloads to disk, and ensures that future requests occur on a new socket. - Parameter completionHandler: The completion handler to call when the reset operation is complete. This handler is executed on the delegate queue.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void reset_with_completion_handler(std::function<void()> completion_handler) const;
        /**
     * @brief Calls `+[NSURLSession sessionWithConfiguration:]`.
     * @details Creates a session with the specified session configuration. - Parameter configuration: A configuration object that specifies certain behaviors, such as caching policies, timeouts, proxies, pipelining, TLS versions to support, cookie policies, credential storage, and so on. See 'NSURLSessionConfiguration' for more information. Calling this method is equivalent to calling '+sessionWithConfiguration:delegate:delegateQueue:' with a 'nil' delegate and queue.
     * @param configuration Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URLSession session_with_configuration(const URLSessionConfiguration& configuration);
        /**
     * @brief Calls `+[NSURLSession sessionWithConfiguration:delegate:delegateQueue:]`.
     * @details Creates a session with the specified session configuration, delegate, and operation queue. - Parameter configuration: A configuration object that specifies certain behaviors, such as caching policies, timeouts, proxies, pipelining, TLS versions to support, cookie policies, and credential storage. See 'NSURLSessionConfiguration' for more information. - Parameter delegate: A session delegate object that handles requests for authentication and other session-related events. This delegate object is responsible for handling authentication challenges, for making caching decisions, and for handling other session-related events. If 'nil', the class should be used only with methods that take completion handlers. The session object keeps a strong reference to the delegate until your app exits or explicitly invalidates the session. If you do not invalidate the session by calling '-invalidateAndCancel' or '-finishTasksAndInvalidate', your app leaks memory until it exits. - Parameter queue: An operation queue for scheduling the delegate calls and completion handlers. The queue should be a serial queue, in order to ensure the correct ordering of callbacks. If 'nil', the session creates a serial operation queue for performing all delegate method calls and completion handler calls.
     * @param configuration Argument converted to the Objective-C parameter of the same role.
     * @param delegate Argument converted to the Objective-C parameter of the same role.
     * @param queue Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URLSession session_with_configuration(const URLSessionConfiguration& configuration, const Object& delegate, const OperationQueue& queue);
        /**
     * @brief Calls `-[NSURLSession streamTaskWithHostName:port:]`.
     * @details Creates a task that establishes a bidirectional TCP/IP connection to a specified hostname and port. After you create the task, you must start it by calling its '-resume' method. - Parameter hostname: The hostname of the connection endpoint. - Parameter port: The port of the connection endpoint. - Returns: The new session stream task.
     * @param hostname Argument converted to the Objective-C parameter of the same role.
     * @param port Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionStreamTask stream_task_with_host_name(const std::string& hostname, std::int64_t port) const;
        /**
     * @brief Calls `-[NSURLSession streamTaskWithNetService:]`.
     * @details Creates a task that establishes a bidirectional TCP/IP connection using a specified network service. After you create the task, you must start it by calling its '-resume' method. - Parameter service: An 'NSNetService' object used to determine the endpoint of the TCP/IP connection. This network service is resolved before any data is read or written to the resulting stream task. - Returns: The new session stream task.
     * @param service Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionStreamTask stream_task_with_net_service(const NetService& service) const;
        /**
     * @brief Calls `-[NSURLSession uploadTaskWithRequest:fromData:]`.
     * @details Creates a task that performs an HTTP request for the specified URL request object and uploads the provided data. An HTTP upload request is any request that contains a request body, such as a 'POST' or 'PUT' request. Upload tasks require you to create a request object so that you can provide metadata for the upload, like HTTP request headers. After you create the task, you must start it by calling its '-resume' method. The task calls methods on the session's delegate to provide you with the upload's progress, response metadata, response data, and so on. - Parameter request: A URL request object that provides the URL, cache policy, request type, and so on. The body stream and body data in this request object are ignored. - Parameter bodyData: The body data for the request. - Returns: The new session upload task.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @param body_data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionUploadTask upload_task_with_request(const URLRequest& request, const std::vector<std::uint8_t>& body_data) const;
        /**
     * @brief Calls `-[NSURLSession uploadTaskWithRequest:fromData:completionHandler:]`.
     * @details Creates a task that performs an HTTP request for the specified URL request object, uploads the provided data, and calls a handler upon completion. - Parameter request: A URL request object that provides the URL, cache policy, request type, and so on. The body stream and body data in this request object are ignored. - Parameter bodyData: The body data for the request. - Parameter completionHandler: The completion handler to call when the load request is complete. This handler is executed on the delegate queue.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @param body_data Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionUploadTask upload_task_with_request(const URLRequest& request, const std::vector<std::uint8_t>& body_data, std::function<void(std::vector<std::uint8_t>, URLResponse, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSession uploadTaskWithRequest:fromFile:]`.
     * @details Creates a task that performs an HTTP request for uploading the specified file. An HTTP upload request is any request that contains a request body, such as a 'POST' or 'PUT' request. Upload tasks require you to create a request object so that you can provide metadata for the upload, like HTTP request headers. After you create the task, you must start it by calling its '-resume' method. The task calls methods on the session's delegate to provide you with the upload's progress, response metadata, response data, and so on. - Parameter request: A URL request object that provides the URL, cache policy, request type, and so on. The body stream and body data in this request object are ignored. - Parameter fileURL: The URL of the file to upload. - Returns: The new session upload task.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @param file_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionUploadTask upload_task_with_request(const URLRequest& request, const URL& file_url) const;
        /**
     * @brief Calls `-[NSURLSession uploadTaskWithRequest:fromFile:completionHandler:]`.
     * @details Creates a task that performs an HTTP request for uploading the specified file, then calls a handler upon completion. - Parameter request: A URL request object that provides the URL, cache policy, request type, and so on. The body stream and body data in this request object are ignored. - Parameter fileURL: The URL of the file to upload. - Parameter completionHandler: The completion handler to call when the load request is complete. This handler is executed on the delegate queue.
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
     * @details Creates a task that performs an HTTP request for uploading data based on the specified URL request. An HTTP upload request is any request that contains a request body, such as a 'POST' or 'PUT' request. Upload tasks require you to provide a request object so that you can provide metadata for the upload, such as HTTP request headers. After you create the task, you must start it by calling its '-resume' method. The task calls methods on the session's delegate to provide you with the upload's progress, response metadata, response data, and so on. The session's delegate must have a 'URLSession:task:needNewBodyStream:' method that provides the body data to upload. - Parameter request: A URL request object that provides the URL, cache policy, request type, and so on. The body stream and body data in this request object are ignored, and the session calls its delegate's 'URLSession:task:needNewBodyStream:' method to supply an upload body. - Returns: The new session upload task.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionUploadTask upload_task_with_streamed_request(const URLRequest& request) const;
        /**
     * @brief Calls `-[NSURLSession webSocketTaskWithRequest:]`.
     * @details Creates a WebSocket task for the provided URL request. You can modify the request's properties prior to calling '-resume' on the task. The task uses these properties during the HTTP handshake phase. To add custom protocols, add a header with the key 'Sec-WebSocket-Protocol', and a comma-separated list of protocols you want to negotiate with the server. The custom HTTP headers provided by the client remain unchanged for the handshake with the server. - Parameter request: A URL request that indicates a WebSocket endpoint with which to connect.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionWebSocketTask web_socket_task_with_request(const URLRequest& request) const;
        /**
     * @brief Calls `-[NSURLSession webSocketTaskWithURL:]`.
     * @details Creates a WebSocket task for the provided URL. The provided URL must have a 'ws' or 'wss' scheme. - Parameter url: The WebSocket URL with which to connect.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionWebSocketTask web_socket_task_with_url(const URL& url) const;
        /**
     * @brief Calls `-[NSURLSession webSocketTaskWithURL:protocols:]`.
     * @details Creates a WebSocket task given a URL and an array of protocols. During the WebSocket handshake, the task uses the provided protocols to negotiate a preferred protocol with the server. > Note: The protocol doesn't affect the WebSocket framing. More details on the protocol > are available in RFC 6455, The WebSocket Protocol. - Parameter url: The WebSocket URL with which to connect. - Parameter protocols: An array of protocols to negotiate with the server.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param protocols Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLSessionWebSocketTask web_socket_task_with_url(const URL& url, const std::vector<std::string>& protocols) const;
        /**
     * @brief Returns the `configuration` property of `NSURLSession`.
     * @details A copy of the configuration object for this session. Beginning in iOS 9 and OS X 10.11, 'NSURLSession' objects store a copy of the 'NSURLSessionConfiguration' object passed to their initializers, such that a session's configuration is immutable after initialization. Any further changes to mutable properties on the configuration object passed to a session's initializer or the value returned from a session's configuration property do not affect the behavior of that session. However, you can create a new session with the modified configuration object.
     * @return The converted Objective-C result.
     */
        URLSessionConfiguration configuration() const;
        /**
     * @brief Returns the `delegateQueue` property of `NSURLSession`.
     * @details The operation queue provided when this object was created. All delegate method calls and completion handlers related to the session are performed on this queue. The session object keeps a strong reference to this queue until your app exits or the session object is deallocated. If you do not invalidate the session, your app leaks memory until it exits. > Note: This queue must be set at object creation time and may not be changed.
     * @return The converted Objective-C result.
     */
        OperationQueue delegate_queue() const;
        /**
     * @brief Returns the `sessionDescription` property of `NSURLSession`.
     * @details An app-defined descriptive label for the session. This property contains a human-readable string that you can use for debugging purposes. This value may be 'nil' and defaults to 'nil'. The value is ignored by the session.
     * @return The converted Objective-C result.
     */
        std::string session_description() const;
        /**
     * @brief Sets the `sessionDescription` property of `NSURLSession`.
     * @details An app-defined descriptive label for the session. This property contains a human-readable string that you can use for debugging purposes. This value may be 'nil' and defaults to 'nil'. The value is ignored by the session.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_session_description(const std::string& value) const;
        /**
     * @brief Returns the `sharedSession` property of `NSURLSession`.
     * @details The shared singleton session object. For basic requests, the 'NSURLSession' class provides a shared singleton session object that gives you a reasonable default behavior for creating tasks. Use the shared session to fetch the contents of a URL to memory with just a few lines of code. Unlike the other session types, you don't create the shared session; you merely access it by using this property directly. As a result, you don't provide a delegate or a configuration object. Because the shared session has neither a delegate nor a customizable configuration object, the shared session has important limitations: - You can't obtain data incrementally as it arrives from the server. - You can't significantly customize the default connection behavior. - Your ability to perform authentication is limited. - You can't perform background downloads or uploads when your app isn't running. The shared session uses the shared 'NSURLCache', 'NSHTTPCookieStorage', and 'NSURLCredentialStorage' objects, uses a shared custom networking protocol list (configured with '+[NSURLProtocol registerClass:]' and '+[NSURLProtocol unregisterClass:]'), and is based on a default configuration.
     * @return The converted Objective-C result.
     */
        static URLSession shared_session();
    };
}
