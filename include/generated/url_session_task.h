#pragma once

#include "generated/availability.h"
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
     * @details NSURLSessionTask - a cancelable object that refers to the lifetime of processing a given request.
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
     * @details -cancel returns immediately, but marks a task as being canceled. The task will signal -URLSession:task:didCompleteWithError: with an error value of { NSURLErrorDomain, NSURLErrorCancelled }. In some cases, the task may signal other work before it acknowledges the cancelation. -cancel may be sent to a task that has been suspended.
     */
        void cancel() const;
        /**
     * @brief Calls `-[NSURLSessionTask resume]`.
     */
        void resume() const;
        /**
     * @brief Calls `-[NSURLSessionTask suspend]`.
     * @details Suspending a task will prevent the NSURLSession from continuing to load data. There may still be delegate calls made on behalf of this task (for instance, to report data received while suspending) but no further transmissions will be made on behalf of the task until -resume is sent. The timeout timer associated with the task will be disabled while a task is suspended. -suspend and -resume are nestable.
     */
        void suspend() const;
        /**
     * @brief Returns the `countOfBytesClientExpectsToReceive` property of `NSURLSessionTask`.
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_bytes_client_expects_to_receive() const;
        /**
     * @brief Sets the `countOfBytesClientExpectsToReceive` property of `NSURLSessionTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_count_of_bytes_client_expects_to_receive(std::int64_t value) const;
        /**
     * @brief Returns the `countOfBytesClientExpectsToSend` property of `NSURLSessionTask`.
     * @details The number of bytes that the client expects (a best-guess upper-bound) will be sent and received by this task. These values are used by system scheduling policy. If unspecified, NSURLSessionTransferSizeUnknown is used.
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_bytes_client_expects_to_send() const;
        /**
     * @brief Sets the `countOfBytesClientExpectsToSend` property of `NSURLSessionTask`.
     * @details The number of bytes that the client expects (a best-guess upper-bound) will be sent and received by this task. These values are used by system scheduling policy. If unspecified, NSURLSessionTransferSizeUnknown is used.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_count_of_bytes_client_expects_to_send(std::int64_t value) const;
        /**
     * @brief Returns the `countOfBytesExpectedToReceive` property of `NSURLSessionTask`.
     * @details number of byte bytes we expect to receive, usually derived from the Content-Length header of an HTTP response.
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_bytes_expected_to_receive() const;
        /**
     * @brief Returns the `countOfBytesExpectedToSend` property of `NSURLSessionTask`.
     * @details number of body bytes we expect to send, derived from the Content-Length of the HTTP request
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_bytes_expected_to_send() const;
        /**
     * @brief Returns the `countOfBytesReceived` property of `NSURLSessionTask`.
     * @details number of body bytes already received
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_bytes_received() const;
        /**
     * @brief Returns the `countOfBytesSent` property of `NSURLSessionTask`.
     * @details number of body bytes already sent
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_bytes_sent() const;
        /**
     * @brief Returns the `currentRequest` property of `NSURLSessionTask`.
     * @details \@property (nullable, readonly, copy) NSURLRequest originalRequest; / may be nil if this is a stream task
     * @return The converted Objective-C result.
     */
        URLRequest current_request() const;
        /**
     * @brief Returns the `earliestBeginDate` property of `NSURLSessionTask`.
     * @details Start the network load for this task no earlier than the specified date. If not specified, no start delay is used. Only applies to tasks created from background NSURLSession instances; has no effect for tasks created from other session types.
     * @return The converted Objective-C result.
     */
        Date earliest_begin_date() const;
        /**
     * @brief Sets the `earliestBeginDate` property of `NSURLSessionTask`.
     * @details Start the network load for this task no earlier than the specified date. If not specified, no start delay is used. Only applies to tasks created from background NSURLSession instances; has no effect for tasks created from other session types.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_earliest_begin_date(const Date& value) const;
        /**
     * @brief Returns the `error` property of `NSURLSessionTask`.
     * @details The error, if any, delivered via -URLSession:task:didCompleteWithError: This property will be nil in the event that no error occurred.
     * @return The converted Objective-C result.
     */
        Error error() const;
        /**
     * @brief Returns the `originalRequest` property of `NSURLSessionTask`.
     * @details \@property (readonly) NSUInteger taskIdentifier; / an identifier for this task, assigned by and unique to the owning session
     * @return The converted Objective-C result.
     */
        URLRequest original_request() const;
        /**
     * @brief Returns the `prefersIncrementalDelivery` property of `NSURLSessionTask`.
     * @details Provides a hint indicating if incremental delivery of a partial response body would be useful for the application, or if it cannot process the response until it is complete. Indicating that incremental delivery is not desired may improve task performance. For example, if a response cannot be decoded until the entire content is received, set this property to false. Defaults to true unless this task is created with completion-handler based convenience methods, or if it is a download task.
     * @return The converted Objective-C result.
     */
        bool prefers_incremental_delivery() const;
        /**
     * @brief Sets the `prefersIncrementalDelivery` property of `NSURLSessionTask`.
     * @details Provides a hint indicating if incremental delivery of a partial response body would be useful for the application, or if it cannot process the response until it is complete. Indicating that incremental delivery is not desired may improve task performance. For example, if a response cannot be decoded until the entire content is received, set this property to false. Defaults to true unless this task is created with completion-handler based convenience methods, or if it is a download task.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_prefers_incremental_delivery(bool value) const;
        /**
     * @brief Returns the `priority` property of `NSURLSessionTask`.
     * @details Sets a scaling factor for the priority of the task. The scaling factor is a value between 0.0 and 1.0 (inclusive), where 0.0 is considered the lowest priority and 1.0 is considered the highest. The priority is a hint and not a hard requirement of task performance. The priority of a task may be changed using this API at any time, but not all protocols support this; in these cases, the last priority that took effect will be used. If no priority is specified, the task will operate with the default priority as defined by the constant NSURLSessionTaskPriorityDefault. Two additional priority levels are provided: NSURLSessionTaskPriorityLow and NSURLSessionTaskPriorityHigh, but use is not restricted to these.
     * @return The converted Objective-C result.
     */
        float priority() const;
        /**
     * @brief Sets the `priority` property of `NSURLSessionTask`.
     * @details Sets a scaling factor for the priority of the task. The scaling factor is a value between 0.0 and 1.0 (inclusive), where 0.0 is considered the lowest priority and 1.0 is considered the highest. The priority is a hint and not a hard requirement of task performance. The priority of a task may be changed using this API at any time, but not all protocols support this; in these cases, the last priority that took effect will be used. If no priority is specified, the task will operate with the default priority as defined by the constant NSURLSessionTaskPriorityDefault. Two additional priority levels are provided: NSURLSessionTaskPriorityLow and NSURLSessionTaskPriorityHigh, but use is not restricted to these.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_priority(float value) const;
        /**
     * @brief Returns the `progress` property of `NSURLSessionTask`.
     * @details NSProgress object which represents the task progress. It can be used for task progress tracking.
     * @return The converted Objective-C result.
     */
        Progress progress() const;
        /**
     * @brief Returns the `response` property of `NSURLSessionTask`.
     * @details \@property (nullable, readonly, copy) NSURLRequest currentRequest; / may differ from originalRequest due to http server redirection
     * @return The converted Objective-C result.
     */
        URLResponse response() const;
        /**
     * @brief Returns the `state` property of `NSURLSessionTask`.
     * @details The current state of the task within the session.
     * @return The converted Objective-C result.
     */
        URLSessionTaskState state() const;
        /**
     * @brief Returns the `taskDescription` property of `NSURLSessionTask`.
     * @details The taskDescription property is available for the developer to provide a descriptive label for the task.
     * @return The converted Objective-C result.
     */
        std::string task_description() const;
        /**
     * @brief Sets the `taskDescription` property of `NSURLSessionTask`.
     * @details The taskDescription property is available for the developer to provide a descriptive label for the task.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_task_description(const std::string& value) const;
        /**
     * @brief Returns the `taskIdentifier` property of `NSURLSessionTask`.
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
