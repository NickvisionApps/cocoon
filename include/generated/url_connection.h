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
     * @details \@class NSURLConnection \@abstract An NSURLConnection object provides support to perform asynchronous loads of a URL request, providing data to a client supplied delegate. \@discussion The interface for NSURLConnection is very sparse, providing only the controls to start and cancel asynchronous loads of a URL request.\<p> An NSURLConnection may be used for loading of resource data directly to memory, in which case an NSURLConnectionDataDelegate should be supplied, or for downloading of resource data directly to a file, in which case an NSURLConnectionDownloadDelegate is used. The delegate is retained by the NSURLConnection until a terminal condition is encountered. These two delegates are logically subclasses of the base protocol, NSURLConnectionDelegate.\<p> A terminal condition produced by the loader will result in a connection:didFailWithError: in the case of an error, or connectionDidFinishLoading: or connectionDidFinishDownloading: delegate message.\<p> The -cancel message hints to the loader that a resource load should be abandoned but does not guarantee that more delegate messages will not be delivered. If -cancel does cause the load to be abandoned, the delegate will be released without further messages. In general, a caller should be prepared for -cancel to have no effect, and internally ignore any delegate callbacks until the delegate is released. Scheduling of an NSURLConnection specifies the context in which delegate callbacks will be made, but the actual IO may occur on a separate thread and should be considered an implementation detail.\<p> When created, an NSURLConnection performs a deep-copy of the NSURLRequest. This copy is available through the -originalRequest method. As the connection performs the load, this request may change as a result of protocol canonicalization or due to following redirects. -currentRequest can be used to retrieve this value.\<p> An NSURLConnections created with the +connectionWithRequest:delegate: or -initWithRequest:delegate: methods are scheduled on the current runloop immediately, and it is not necessary to send the -start message to begin the resource load.\<p> NSURLConnections created with -initWithRequest:delegate:startImmediately: are not automatically scheduled. Use -scheduleWithRunLoop:forMode: or -setDelegateQueue: to specify the context for delegate callbacks, and -start to begin the load. If you do not explicitly schedule the connection before -start, it will be scheduled on the current runloop and mode automatically.\<p> The NSURLConnectionSynchronousLoading category adds +sendSynchronousRequest:returningResponse:error, which blocks the current thread until the resource data is available or an error occurs. It should be noted that using this method on an applications main run loop may result in an unacceptably long delay in a user interface and its use is strongly discourage.\<p> The NSURLConnectionQueuedLoading category implements +sendAsynchronousRequest:queue:completionHandler, providing similar simplicity but provides a mechanism where the current runloop is not blocked.\<p> Both of the immediate loading categories do not provide for customization of resource load, and do not allow the caller to respond to, e.g., authentication challenges.\<p>
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
     * @details \@method canHandleRequest: \@abstract Performs a "preflight" operation that performs some speculative checks to see if a connection can be initialized, and the associated I/O that is started in the initializer methods can begin. \@discussion The result of this method is valid only as long as no protocols are registered or unregistered, and as long as the request is not mutated (if the request is mutable). Hence, clients should be prepared to handle failures even if they have performed request preflighting by calling this method. \@param request The request to preflight. \@result YES if it is likely that the given request can be used to initialize a connection and the associated I/O can be started, NO otherwise.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool can_handle_request(const URLRequest& request);
        /**
     * @brief Calls `-[NSURLConnection cancel]`.
     */
        void cancel() const;
        /**
     * @brief Calls `-[NSURLConnection scheduleInRunLoop:forMode:]`.
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
     * @details \@method sendSynchronousRequest:returningResponse:error: \@abstract Performs a synchronous load of the given request, returning an NSURLResponse in the given out parameter. \@discussion A synchronous load for the given request is built on top of the asynchronous loading code made available by the class. The calling thread is blocked while the asynchronous loading system performs the URL load on a thread spawned specifically for this load request. No special threading or run loop configuration is necessary in the calling thread in order to perform a synchronous load. For instance, the calling thread need not be running its run loop. \@param request The request to load. Note that the request is deep-copied as part of the initialization process. Changes made to the request argument after this method returns do not affect the request that is used for the loading process. \@param response An out parameter which is filled in with the response generated by performing the load. \@param error Out parameter (may be NULL) used if an error occurs while processing the request. Will not be modified if the load succeeds. \@result The content of the URL resulting from performing the load, or nil if the load failed.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @param response Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::uint8_t> send_synchronous_request(const URLRequest& request, URLResponse& response);
        /**
     * @brief Calls `-[NSURLConnection setDelegateQueue:]`.
     * @param queue Argument converted to the Objective-C parameter of the same role.
     */
        void set_delegate_queue(const OperationQueue& queue) const;
        /**
     * @brief Calls `-[NSURLConnection start]`.
     */
        void start() const;
        /**
     * @brief Calls `-[NSURLConnection unscheduleFromRunLoop:forMode:]`.
     * @param a_run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void unschedule_from_run_loop(const RunLoop& a_run_loop, const std::string& mode) const;
        /**
     * @brief Returns the `currentRequest` property of `NSURLConnection`.
     * @return The converted Objective-C result.
     */
        URLRequest current_request() const;
        /**
     * @brief Returns the `originalRequest` property of `NSURLConnection`.
     * @return The converted Objective-C result.
     */
        URLRequest original_request() const;
    };
}
