#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class OperationQueue;
    class RunLoop;
    class URLRequest;
    class URLResponse;

    /**
     * @brief C++ handle for the Objective-C class `NSURLConnection` (Foundation).
     * @details An object that enables you to start and stop URL requests. > Important: > This API is considered legacy. Use ''URLSession'' instead. An 'NSURLConnection' object lets you load the contents of a URL by providing a URL request object. The interface for 'NSURLConnection' is sparse, providing only the controls to start and cancel asynchronous loads of a URL request. You perform most of your configuration on the URL request object itself. > Note: > Although instances of this class are commonly called "connections", there is not a 1:1 correlation between these objects and the underlying network connections. The 'NSURLConnection' class provides convenience class methods to load URL requests both asynchronously using a callback block and synchronously. For greater control, you can create a URL connection object with a delegate object that conforms to the ''NSURLConnectionDelegate'' and ''NSURLConnectionDataDelegate'' protocols. The connection calls methods on that delegate to provide you with progress and status as the URL request is loaded asynchronously. The connection also calls delegate methods to let you override the connection's default behavior (for example, specifying how a particular redirect should be handled). These delegate methods are called on the thread that initiated the asynchronous load operation. > Note: > During a request, the connection maintains a strong reference to its delegate. It releases that strong reference when the connection finishes loading, fails, or is canceled. For more information about errors, see the 'NSURLError.h' header, \<doc:foundation-constants>, and URL Loading System Error Codes in [Error Handling Programming Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ErrorHandlingCocoa/ErrorHandling/ErrorHandling.html\#//apple_ref/doc/uid/TP40001806). \#\#\# NSURLConnection Protocols The 'NSURLConnection' class works in tandem with three formal protocols: ''NSURLConnectionDelegate'', ''NSURLConnectionDataDelegate'', and ''NSURLConnectionDownloadDelegate''. To use these protocols, you write a class that conforms to them and implement any methods that are appropriate, then provide an instance of that class as the delegate when you create a connection object. The ''NSURLConnectionDelegate'' protocol is primarily used for credential handling, but also handles connection completion. Because it handles connection failure during data transfers, all connection delegates must typically implement this protocol. In addition, unless you're using Newsstand Kit, your delegate must also conform to the ''NSURLConnectionDataDelegate'' protocol, because this protocol provides methods that the 'NSURLConnection' class calls with progress information during an upload, with fragments of the response data during a download, and to provide a new upload body stream if the server's response necessitates a second connection attempt—for example, if 'NSURLConnection' must retry the request with different credentials. Finally, if you're using Newsstand Kit, your delegate can conform to the ''NSURLConnectionDownloadDelegate'' protocol. This protocol provides support for continuing interrupted file downloads and receiving a notification whenever a download finishes. This protocol is solely for use with 'NSURLConnection' objects created using Newsstand Kit's 'download(with:)' method. > Note: > Some methods in these protocols were previously part of other formal protocols or were previously part of an informal protocol on 'NSObject'.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLConnection url_connection;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::URLConnection url_connection{};
     * url_connection.cancel();
     * url_connection.schedule_in_run_loop(cocoon::RunLoop(), "text");
     * url_connection.set_delegate_queue(cocoon::OperationQueue());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlconnection
     */
    class URLConnection : public Object
    {
    public:
        /// @brief Creates a new `NSURLConnection` instance and returns a handle to it.
        explicit URLConnection();
        /// @brief Creates a null handle that refers to no native object.
        URLConnection(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLConnection(Adopt adopt);
        /**
     * @brief Calls `+[NSURLConnection canHandleRequest:]`.
     * @details Returns whether a request can be handled based on a preflight evaluation. The result of this method is valid as long as no ''NSURLProtocol'' classes are registered or unregistered, and 'request' remains unchanged. Applications should be prepared to handle failures even if they have performed request preflighting by calling this method. - Parameter request: The request to evaluate. The connection deep-copies the request on creation. - Returns: 'YES' if a preflight operation determines that a connection with 'request' can be created and the associated I/O can be started, 'NO' otherwise.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool can_handle_request(const URLRequest& request);
        /**
     * @brief Calls `-[NSURLConnection cancel]`.
     * @details Cancels an asynchronous load of a request. After this method is called, the connection makes no further delegate method calls. If you want to reattempt the connection, you should create a new connection object.
     */
        void cancel() const;
        /**
     * @brief Calls `-[NSURLConnection scheduleInRunLoop:forMode:]`.
     * @details Determines the run loop and mode that the connection uses to call methods on its delegate. By default, a connection is scheduled on the current thread in the default mode when it is created. You cannot reschedule a connection after it has started.
     * @param a_run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void schedule_in_run_loop(const RunLoop& a_run_loop, const std::string& mode) const;
        /**
     * @brief Calls `+[NSURLConnection sendAsynchronousRequest:queue:completionHandler:]`.
     * @details \@method sendAsynchronousRequest:queue:completionHandler: \@abstract Performs an asynchronous load of the given request. When the request has completed or failed, the block will be executed from the context of the specified NSOperationQueue. \@discussion This is a convenience routine that allows for asynchronous loading of a url-based resource. If the resource load is successful, the data parameter to the callback will contain the resource data and the error parameter will be nil. If the resource load fails, the data parameter will be nil and the error will contain information about the failure. \@param request The request to load. Note that the request is deep-copied as part of the initialization process. Changes made to the request argument after this method returns do not affect the request that is used for the loading process. \@param queue An NSOperationQueue upon which the handler block will be dispatched. \@param handler A block which receives the results of the resource load.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @param queue Argument converted to the Objective-C parameter of the same role.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        static void send_asynchronous_request(const URLRequest& request, const OperationQueue& queue, std::function<void(URLResponse, std::vector<std::uint8_t>, Error)> handler);
        /**
     * @brief Calls `+[NSURLConnection sendSynchronousRequest:returningResponse:error:]`.
     * @details Performs a synchronous load of the specified URL request. A synchronous load is built on top of the asynchronous loading code made available by the class. The calling thread is blocked while the asynchronous loading system performs the URL load on a thread spawned specifically for this load request. No special threading or run loop configuration is necessary in the calling thread in order to perform a synchronous load. > Important: Because this call can potentially take several minutes to complete (particularly when using a cellular network in iOS), you should never call this function from the main thread of your application. The solution is to migrate to URL loading using ''NSURLSession''. If authentication is required in order to download the request, the required credentials must be specified as part of the URL. If authentication fails, or credentials are missing, the connection will attempt to continue without credentials. - Parameters: - request: The URL request to load. The 'request' object is deep-copied as part of the initialization process. Changes made to 'request' after this method returns do not affect the request that is used for the loading process. - response: Out parameter for the URL response returned by the server. - error: Out parameter used if an error occurs while processing the request. May be 'NULL'. - Returns: The downloaded data for the URL request. Returns 'nil' if a connection could not be created or if the download fails.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @param response Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::uint8_t> send_synchronous_request(const URLRequest& request, URLResponse& response);
        /**
     * @brief Calls `-[NSURLConnection setDelegateQueue:]`.
     * @details Determines the operation queue that is used to call methods on the connection's delegate. By default, a connection is scheduled on the current thread in the default mode when it is created. You cannot reschedule a connection after it has started.
     * @param queue Argument converted to the Objective-C parameter of the same role.
     */
        void set_delegate_queue(const OperationQueue& queue) const;
        /**
     * @brief Calls `-[NSURLConnection start]`.
     * @details Causes the connection to begin loading data, if it has not already. Calling this method is necessary only if you create a connection with the '-initWithRequest:delegate:startImmediately:' method and provide 'NO' for the 'startImmediately' parameter. If you don't schedule the connection in a run loop or an operation queue before calling this method, the connection is scheduled in the current run loop in the default mode.
     */
        void start() const;
        /**
     * @brief Calls `-[NSURLConnection unscheduleFromRunLoop:forMode:]`.
     * @details Removes the connection from the specified run loop and mode.
     * @param a_run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void unschedule_from_run_loop(const RunLoop& a_run_loop, const std::string& mode) const;
        /**
     * @brief Returns the `currentRequest` property of `NSURLConnection`.
     * @details The current connection request. As the connection performs the load, the request may change as a result of protocol canonicalization or due to following redirects. This property provides the current value of the request.
     * @return The converted Objective-C result.
     */
        URLRequest current_request() const;
        /**
     * @brief Returns the `originalRequest` property of `NSURLConnection`.
     * @details A deep copy of the original connection request. As the connection performs the load, the request may change as a result of protocol canonicalization or due to following redirects.
     * @return The converted Objective-C result.
     */
        URLRequest original_request() const;
    };
}
