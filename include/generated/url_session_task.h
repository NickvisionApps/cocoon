#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class Error;
    class HTTPURLResponse;
    class InputStream;
    class Progress;
    class URLAuthenticationChallenge;
    class URLCredential;
    class URLRequest;
    class URLResponse;
    class URLSessionTaskMetrics;

    /**
     * @brief C++ handle for the Objective-C class `NSURLSessionTask` (Foundation).
     * @details A task, like downloading a specific resource, performed in a URL session. The ''URLSessionTask'' class is the base class for tasks in a URL session. Tasks are always part of a session; you create a task by calling one of the task creation methods on a ''URLSession'' instance. The method you call determines the type of task. - Use ''URLSession'''s ''URLSession/dataTask(with:)-10dy7'' and related methods to create ''URLSessionDataTask'' instances. Data tasks request a resource, returning the server's response as one or more 'NSData' objects in memory. They are supported in default, ephemeral, and shared sessions, but are not supported in background sessions. - Use ''URLSession'''s ''URLSession/uploadTask(with:from:)'' and related methods to create ''URLSessionUploadTask'' instances. Upload tasks are like data tasks, except that they make it easier to provide a request body so you can upload data before retrieving the server's response. Additionally, upload tasks are supported in background sessions. - Use ''URLSession'''s ''URLSession/downloadTask(with:)-1onj'' and related methods to create ''URLSessionDownloadTask'' instances. Download tasks download a resource directly to a file on disk. Download tasks are supported in any type of session. - Use ''URLSession'''s ''URLSession/streamTask(withHostName:port:)'' or ''URLSession/streamTask(with:)'' to create ''URLSessionStreamTask'' instances. Stream tasks establish a TCP/IP connection from a host name and port or a net service object. After you create a task, you start it by calling its ''resume()'' method. The session then maintains a strong reference to the task until the request finishes or fails; you don't need to maintain a reference to the task unless it's useful for your app's internal bookkeeping. > Note: > All task properties support key-value observing.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLSessionTask url_session_task;
     * url_session_task.set_count_of_bytes_client_expects_to_receive(1);
     * url_session_task.url_session_did_become_invalid_with_error().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::URLSessionTask url_session_task{};
     * url_session_task.set_count_of_bytes_client_expects_to_receive(1);
     * auto count_of_bytes_client_expects_to_receive = url_session_task.count_of_bytes_client_expects_to_receive();
     * url_session_task.set_count_of_bytes_client_expects_to_send(1);
     * auto count_of_bytes_client_expects_to_send = url_session_task.count_of_bytes_client_expects_to_send();
     * url_session_task.set_earliest_begin_date(cocoon::Date());
     * auto earliest_begin_date = url_session_task.earliest_begin_date();
     * url_session_task.cancel();
     * url_session_task.resume();
     * url_session_task.suspend();
     * url_session_task.url_session_did_become_invalid_with_error().connect([](cocoon::Error a0) {});
     * url_session_task.url_session_did_receive_challenge_completion_handler().connect([](cocoon::URLAuthenticationChallenge a0, std::function<void(cocoon::URLSessionAuthChallengeDisposition, cocoon::URLCredential)> a1) {});
     * url_session_task.url_session_did_finish_events_for_background_url_session().connect([]() {});
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlsessiontask
     */
    class URLSessionTask : public Object
    {
    public:
        /// @brief Creates a new `NSURLSessionTask` instance and returns a handle to it.
        explicit URLSessionTask();
        /// @brief Creates a null handle that refers to no native object.
        URLSessionTask(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLSessionTask(Adopt adopt);
        /**
     * @brief Calls `-[NSURLSessionTask cancel]`.
     * @details Cancels the task. This method returns immediately, marking the task as being canceled. Once a task is marked as being canceled, 'URLSession:task:didCompleteWithError:' will be sent to the task delegate, passing an error in the domain 'NSURLErrorDomain' with the code 'NSURLErrorCancelled'. A task may, under some circumstances, send messages to its delegate before the cancelation is acknowledged. This method may be called on a task that is suspended.
     */
        void cancel() const;
        /**
     * @brief Calls `-[NSURLSessionTask resume]`.
     * @details Resumes the task, if it is suspended. Newly-initialized tasks begin in a suspended state, so you need to call this method to start the task.
     */
        void resume() const;
        /**
     * @brief Calls `-[NSURLSessionTask suspend]`.
     * @details Temporarily suspends the task. Suspending a task will prevent the 'NSURLSession' from continuing to load data. There may still be delegate calls made on behalf of this task (for instance, to report data received while suspending) but no further transmissions will be made on behalf of the task until '-resume' is sent. The timeout timer associated with the task will be disabled while a task is suspended. '-suspend' and '-resume' are nestable.
     */
        void suspend() const;
        /**
     * @brief Returns the `countOfBytesClientExpectsToReceive` property of `NSURLSessionTask`.
     * @details A best-guess upper bound on the number of bytes the client expects to receive. The value set for this property should account for the size of both HTTP response headers and the response body. If no value is specified, the system uses 'NSURLSessionTransferSizeUnknown' instead. This property is used by the system to optimize the scheduling of URL session tasks. Developers are strongly encouraged to provide an approximate upper bound, or an exact byte count, if possible, rather than accept the default.
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_bytes_client_expects_to_receive() const;
        /**
     * @brief Sets the `countOfBytesClientExpectsToReceive` property of `NSURLSessionTask`.
     * @details A best-guess upper bound on the number of bytes the client expects to receive. The value set for this property should account for the size of both HTTP response headers and the response body. If no value is specified, the system uses 'NSURLSessionTransferSizeUnknown' instead. This property is used by the system to optimize the scheduling of URL session tasks. Developers are strongly encouraged to provide an approximate upper bound, or an exact byte count, if possible, rather than accept the default.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_count_of_bytes_client_expects_to_receive(std::int64_t value) const;
        /**
     * @brief Returns the `countOfBytesClientExpectsToSend` property of `NSURLSessionTask`.
     * @details A best-guess upper bound on the number of bytes the client expects to send. The value set for this property should account for the size of HTTP headers and body data or body stream. If no value is specified, the system uses 'NSURLSessionTransferSizeUnknown' instead. This property is used by the system to optimize the scheduling of URL session tasks. Developers are strongly encouraged to provide an approximate upper bound, or an exact byte count, if possible, rather than accept the default.
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_bytes_client_expects_to_send() const;
        /**
     * @brief Sets the `countOfBytesClientExpectsToSend` property of `NSURLSessionTask`.
     * @details A best-guess upper bound on the number of bytes the client expects to send. The value set for this property should account for the size of HTTP headers and body data or body stream. If no value is specified, the system uses 'NSURLSessionTransferSizeUnknown' instead. This property is used by the system to optimize the scheduling of URL session tasks. Developers are strongly encouraged to provide an approximate upper bound, or an exact byte count, if possible, rather than accept the default.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_count_of_bytes_client_expects_to_send(std::int64_t value) const;
        /**
     * @brief Returns the `countOfBytesExpectedToReceive` property of `NSURLSessionTask`.
     * @details The number of bytes that the task expects to receive in the response body. This value is determined based on the 'Content-Length' header received from the server. If that header is absent, the value is 'NSURLSessionTransferSizeUnknown'.
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_bytes_expected_to_receive() const;
        /**
     * @brief Returns the `countOfBytesExpectedToSend` property of `NSURLSessionTask`.
     * @details The number of bytes that the task expects to send in the request body. The URL loading system can determine the length of the upload data in three ways: - From the length of the data object provided as the upload body. - From the length of the file on disk provided as the upload body of an upload task (not a download task). - From the 'Content-Length' in the request object, if you explicitly set it. Otherwise, the value is 'NSURLSessionTransferSizeUnknown' ('-1') if you provided a stream or body data object, or zero ('0') if you did not.
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_bytes_expected_to_send() const;
        /**
     * @brief Returns the `countOfBytesReceived` property of `NSURLSessionTask`.
     * @details The number of bytes that the task has received from the server in the response body. To be notified when this value changes, implement the 'URLSession:dataTask:didReceiveData:' delegate method (for data and upload tasks) or the 'URLSession:downloadTask:didWriteData:totalBytesWritten:totalBytesExpectedToWrite:' method (for download tasks).
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_bytes_received() const;
        /**
     * @brief Returns the `countOfBytesSent` property of `NSURLSessionTask`.
     * @details The number of bytes that the task has sent to the server in the request body. This byte count includes only the length of the request body itself, not the request headers. To be notified when this value changes, implement the 'URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:' delegate method.
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_bytes_sent() const;
        /**
     * @brief Returns the `currentRequest` property of `NSURLSessionTask`.
     * @details The URL request object currently being handled by the task. This value is typically the same as the initial request ('originalRequest') except when the server has responded to the initial request with a redirect to a different URL.
     * @return The converted Objective-C result.
     */
        URLRequest current_request() const;
        /**
     * @brief Returns the `earliestBeginDate` property of `NSURLSessionTask`.
     * @details The earliest date at which the network load should begin. For tasks created from background 'NSURLSession' instances, this property indicates that the network load should not begin any earlier than this date. Setting this property does not guarantee that the load will begin at the specified date, but only that it will not begin sooner. If not specified, no start delay is used. This property has no effect for tasks created from nonbackground sessions.
     * @return The converted Objective-C result.
     */
        Date earliest_begin_date() const;
        /**
     * @brief Sets the `earliestBeginDate` property of `NSURLSessionTask`.
     * @details The earliest date at which the network load should begin. For tasks created from background 'NSURLSession' instances, this property indicates that the network load should not begin any earlier than this date. Setting this property does not guarantee that the load will begin at the specified date, but only that it will not begin sooner. If not specified, no start delay is used. This property has no effect for tasks created from nonbackground sessions.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_earliest_begin_date(const Date& value) const;
        /**
     * @brief Returns the `error` property of `NSURLSessionTask`.
     * @details An error object that indicates why the task failed. This value is 'nil' if the task is still active or if the transfer completed successfully.
     * @return The converted Objective-C result.
     */
        Error error() const;
        /**
     * @brief Returns the `originalRequest` property of `NSURLSessionTask`.
     * @details The original request object passed when the task was created. This value is typically the same as the currently active request ('currentRequest') except when the server has responded to the initial request with a redirect to a different URL.
     * @return The converted Objective-C result.
     */
        URLRequest original_request() const;
        /**
     * @brief Returns the `prefersIncrementalDelivery` property of `NSURLSessionTask`.
     * @details A Boolean value that determines whether to deliver a partial response body in increments. Set this property to 'true' to tell the task that the app would benefit from receiving a partial response body in increments. If the app can't process the response until it has all the data, set this property to 'false'. Task performance may improve when this value is 'false', in which case the task only delivers data when complete. This property defaults to 'true', except in the following cases which default to 'false': - The task delivers results to a completion handler rather than to a delegate. - The task is a download task.
     * @return The converted Objective-C result.
     */
        bool prefers_incremental_delivery() const;
        /**
     * @brief Sets the `prefersIncrementalDelivery` property of `NSURLSessionTask`.
     * @details A Boolean value that determines whether to deliver a partial response body in increments. Set this property to 'true' to tell the task that the app would benefit from receiving a partial response body in increments. If the app can't process the response until it has all the data, set this property to 'false'. Task performance may improve when this value is 'false', in which case the task only delivers data when complete. This property defaults to 'true', except in the following cases which default to 'false': - The task delivers results to a completion handler rather than to a delegate. - The task is a download task.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_prefers_incremental_delivery(bool value) const;
        /**
     * @brief Returns the `priority` property of `NSURLSessionTask`.
     * @details The relative priority at which you'd like a host to handle the task, specified as a floating point value between '0.0' (lowest priority) and '1.0' (highest priority). To provide hints to a host on how to prioritize URL session tasks from your app, specify a priority for each task. Specifying a priority provides only a hint and does not guarantee performance. If you don't specify a priority, a URL session task has a priority of 'NSURLSessionTaskPriorityDefault', with a value of '0.5'. There are three named priorities you can employ: 'NSURLSessionTaskPriorityDefault', 'NSURLSessionTaskPriorityLow', and 'NSURLSessionTaskPriorityHigh'. You can specify or change a task's priority at any time, but not all networking protocols respond to changes after a task has started. There is no API to let you determine the effective priority for a task from a host's perspective.
     * @return The converted Objective-C result.
     */
        float priority() const;
        /**
     * @brief Sets the `priority` property of `NSURLSessionTask`.
     * @details The relative priority at which you'd like a host to handle the task, specified as a floating point value between '0.0' (lowest priority) and '1.0' (highest priority). To provide hints to a host on how to prioritize URL session tasks from your app, specify a priority for each task. Specifying a priority provides only a hint and does not guarantee performance. If you don't specify a priority, a URL session task has a priority of 'NSURLSessionTaskPriorityDefault', with a value of '0.5'. There are three named priorities you can employ: 'NSURLSessionTaskPriorityDefault', 'NSURLSessionTaskPriorityLow', and 'NSURLSessionTaskPriorityHigh'. You can specify or change a task's priority at any time, but not all networking protocols respond to changes after a task has started. There is no API to let you determine the effective priority for a task from a host's perspective.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_priority(float value) const;
        /**
     * @brief Returns the `progress` property of `NSURLSessionTask`.
     * @details A representation of the overall task progress. It can be used for task progress tracking.
     * @return The converted Objective-C result.
     */
        Progress progress() const;
        /**
     * @brief Returns the `response` property of `NSURLSessionTask`.
     * @details The server's response to the currently active request. This object provides information about the request as provided by the server. This information always includes the original URL. It may also include an expected length, MIME type information, encoding information, a suggested filename, or a combination of these.
     * @return The converted Objective-C result.
     */
        URLResponse response() const;
        /**
     * @brief Returns the `state` property of `NSURLSessionTask`.
     * @details The current state of the task---active, suspended, in the process of being canceled, or completed.
     * @return The converted Objective-C result.
     */
        URLSessionTaskState state() const;
        /**
     * @brief Returns the `taskDescription` property of `NSURLSessionTask`.
     * @details An app-provided string value for the current task. The system doesn't interpret this value; use it for whatever purpose you see fit. For example, you could store a description of the task for debugging purposes, or a key to track the task in your own data structures.
     * @return The converted Objective-C result.
     */
        std::string task_description() const;
        /**
     * @brief Sets the `taskDescription` property of `NSURLSessionTask`.
     * @details An app-provided string value for the current task. The system doesn't interpret this value; use it for whatever purpose you see fit. For example, you could store a description of the task for debugging purposes, or a key to track the task in your own data structures.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_task_description(const std::string& value) const;
        /**
     * @brief Returns the `taskIdentifier` property of `NSURLSessionTask`.
     * @details An identifier uniquely identifying the task within a given session. This value is unique only within the context of a single session; tasks in other sessions may have the same 'taskIdentifier' value.
     * @return The converted Objective-C result.
     */
        std::uint64_t task_identifier() const;
        /// @brief Signal for the delegate/data-source method behind `url_session_did_become_invalid_with_error`; connect a callback with `url_session_did_become_invalid_with_error().connect(...)`.
        Signal<URLSessionTask, void(Error)> url_session_did_become_invalid_with_error() const
        {
            return Signal<URLSessionTask, void(Error)>(handle(), "url_session_did_become_invalid_with_error");
        }
        /// @brief Signal for the delegate/data-source method behind `url_session_did_receive_challenge_completion_handler`; connect a callback with `url_session_did_receive_challenge_completion_handler().connect(...)`.
        Signal<URLSessionTask, void(URLAuthenticationChallenge, std::function<void(URLSessionAuthChallengeDisposition, URLCredential)>)> url_session_did_receive_challenge_completion_handler() const
        {
            return Signal<URLSessionTask, void(URLAuthenticationChallenge, std::function<void(URLSessionAuthChallengeDisposition, URLCredential)>)>(handle(), "url_session_did_receive_challenge_completion_handler");
        }
        /// @brief Signal for the delegate/data-source method behind `url_session_did_finish_events_for_background_url_session`; connect a callback with `url_session_did_finish_events_for_background_url_session().connect(...)`.
        Signal<URLSessionTask, void()> url_session_did_finish_events_for_background_url_session() const
        {
            return Signal<URLSessionTask, void()>(handle(), "url_session_did_finish_events_for_background_url_session");
        }
        /// @brief Signal for the delegate/data-source method behind `url_session_did_create_task`; connect a callback with `url_session_did_create_task().connect(...)`.
        Signal<URLSessionTask, void(URLSessionTask)> url_session_did_create_task() const
        {
            return Signal<URLSessionTask, void(URLSessionTask)>(handle(), "url_session_did_create_task");
        }
        /// @brief Signal for the delegate/data-source method behind `url_session_task_will_begin_delayed_request_completion_handler`; connect a callback with `url_session_task_will_begin_delayed_request_completion_handler().connect(...)`.
        Signal<URLSessionTask, void(URLSessionTask, URLRequest, std::function<void(URLSessionDelayedRequestDisposition, URLRequest)>)> url_session_task_will_begin_delayed_request_completion_handler() const
        {
            return Signal<URLSessionTask, void(URLSessionTask, URLRequest, std::function<void(URLSessionDelayedRequestDisposition, URLRequest)>)>(handle(), "url_session_task_will_begin_delayed_request_completion_handler");
        }
        /// @brief Signal for the delegate/data-source method behind `url_session_task_is_waiting_for_connectivity`; connect a callback with `url_session_task_is_waiting_for_connectivity().connect(...)`.
        Signal<URLSessionTask, void(URLSessionTask)> url_session_task_is_waiting_for_connectivity() const
        {
            return Signal<URLSessionTask, void(URLSessionTask)>(handle(), "url_session_task_is_waiting_for_connectivity");
        }
        /// @brief Signal for the delegate/data-source method behind `url_session_task_will_perform_http_redirection_new_request_completion_handler`; connect a callback with `url_session_task_will_perform_http_redirection_new_request_completion_handler().connect(...)`.
        Signal<URLSessionTask, void(URLSessionTask, HTTPURLResponse, URLRequest, std::function<void(URLRequest)>)> url_session_task_will_perform_http_redirection_new_request_completion_handler() const
        {
            return Signal<URLSessionTask, void(URLSessionTask, HTTPURLResponse, URLRequest, std::function<void(URLRequest)>)>(handle(), "url_session_task_will_perform_http_redirection_new_request_completion_handler");
        }
        /// @brief Signal for the delegate/data-source method behind `url_session_task_did_receive_challenge_completion_handler`; connect a callback with `url_session_task_did_receive_challenge_completion_handler().connect(...)`.
        Signal<URLSessionTask, void(URLSessionTask, URLAuthenticationChallenge, std::function<void(URLSessionAuthChallengeDisposition, URLCredential)>)> url_session_task_did_receive_challenge_completion_handler() const
        {
            return Signal<URLSessionTask, void(URLSessionTask, URLAuthenticationChallenge, std::function<void(URLSessionAuthChallengeDisposition, URLCredential)>)>(handle(), "url_session_task_did_receive_challenge_completion_handler");
        }
        /// @brief Signal for the delegate/data-source method behind `url_session_task_need_new_body_stream`; connect a callback with `url_session_task_need_new_body_stream().connect(...)`.
        Signal<URLSessionTask, void(URLSessionTask, std::function<void(InputStream)>)> url_session_task_need_new_body_stream() const
        {
            return Signal<URLSessionTask, void(URLSessionTask, std::function<void(InputStream)>)>(handle(), "url_session_task_need_new_body_stream");
        }
        /// @brief Signal for the delegate/data-source method behind `url_session_task_need_new_body_stream_from_offset_completion_handler`; connect a callback with `url_session_task_need_new_body_stream_from_offset_completion_handler().connect(...)`.
        Signal<URLSessionTask, void(URLSessionTask, std::int64_t, std::function<void(InputStream)>)> url_session_task_need_new_body_stream_from_offset_completion_handler() const
        {
            return Signal<URLSessionTask, void(URLSessionTask, std::int64_t, std::function<void(InputStream)>)>(handle(), "url_session_task_need_new_body_stream_from_offset_completion_handler");
        }
        /// @brief Signal for the delegate/data-source method behind `url_session_task_did_send_body_data_total_bytes_sent_total_bytes_expected_to_send`; connect a callback with `url_session_task_did_send_body_data_total_bytes_sent_total_bytes_expected_to_send().connect(...)`.
        Signal<URLSessionTask, void(URLSessionTask, std::int64_t, std::int64_t, std::int64_t)> url_session_task_did_send_body_data_total_bytes_sent_total_bytes_expected_to_send() const
        {
            return Signal<URLSessionTask, void(URLSessionTask, std::int64_t, std::int64_t, std::int64_t)>(handle(), "url_session_task_did_send_body_data_total_bytes_sent_total_bytes_expected_to_send");
        }
        /// @brief Signal for the delegate/data-source method behind `url_session_task_did_receive_informational_response`; connect a callback with `url_session_task_did_receive_informational_response().connect(...)`.
        Signal<URLSessionTask, void(URLSessionTask, HTTPURLResponse)> url_session_task_did_receive_informational_response() const
        {
            return Signal<URLSessionTask, void(URLSessionTask, HTTPURLResponse)>(handle(), "url_session_task_did_receive_informational_response");
        }
        /// @brief Signal for the delegate/data-source method behind `url_session_task_did_finish_collecting_metrics`; connect a callback with `url_session_task_did_finish_collecting_metrics().connect(...)`.
        Signal<URLSessionTask, void(URLSessionTask, URLSessionTaskMetrics)> url_session_task_did_finish_collecting_metrics() const
        {
            return Signal<URLSessionTask, void(URLSessionTask, URLSessionTaskMetrics)>(handle(), "url_session_task_did_finish_collecting_metrics");
        }
        /// @brief Signal for the delegate/data-source method behind `url_session_task_did_complete_with_error`; connect a callback with `url_session_task_did_complete_with_error().connect(...)`.
        Signal<URLSessionTask, void(URLSessionTask, Error)> url_session_task_did_complete_with_error() const
        {
            return Signal<URLSessionTask, void(URLSessionTask, Error)>(handle(), "url_session_task_did_complete_with_error");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
