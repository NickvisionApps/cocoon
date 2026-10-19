#include "generated/url_session_task.h"
#include "internal.h"

@interface AKURLSessionTaskDelegate : NSObject <NSURLSessionTaskDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKURLSessionTaskDelegate

- (void)URLSession:(NSURLSession*)session didBecomeInvalidWithError:(NSError*)error
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::URLSessionTask, void(cocoon::Error)>::emit((__bridge void*)strongHost, "url_session_did_become_invalid_with_error", cocoon::internal::wrap<cocoon::Error>(error));
}

- (void)URLSession:(NSURLSession*)session didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition, NSURLCredential*))completionHandler
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLAuthenticationChallenge, std::function<void(cocoon::URLSessionAuthChallengeDisposition, cocoon::URLCredential)>)>::emit((__bridge void*)strongHost, "url_session_did_receive_challenge_completion_handler", cocoon::internal::wrap<cocoon::URLAuthenticationChallenge>(challenge), [&]() -> std::function<void(cocoon::URLSessionAuthChallengeDisposition, cocoon::URLCredential)>
                                                                                                                                                                                   {
                                                                                                                                                                                       auto blk = (void (^)(::NSURLSessionAuthChallengeDisposition, ::NSURLCredential*))(completionHandler);
                                                                                                                                                                                       if (!blk)
                                                                                                                                                                                       {
                                                                                                                                                                                           return {};
                                                                                                                                                                                       }
                                                                                                                                                                                       return [blk](cocoon::URLSessionAuthChallengeDisposition a280_0, cocoon::URLCredential a280_1) -> void
                                                                                                                                                                                       {
                                                                                                                                                                                           blk(static_cast<::NSURLSessionAuthChallengeDisposition>(a280_0), cocoon::internal::native<::NSURLCredential>(a280_1));
                                                                                                                                                                                       };
                                                                                                                                                                                   }());
}

- (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession*)session
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::URLSessionTask, void()>::emit((__bridge void*)strongHost, "url_session_did_finish_events_for_background_url_session");
}

- (void)URLSession:(NSURLSession*)session didCreateTask:(NSURLSessionTask*)task
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask)>::emit((__bridge void*)strongHost, "url_session_did_create_task", cocoon::internal::wrap<cocoon::URLSessionTask>(task));
}

- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task willBeginDelayedRequest:(NSURLRequest*)request completionHandler:(void (^)(NSURLSessionDelayedRequestDisposition, NSURLRequest*))completionHandler
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, cocoon::URLRequest, std::function<void(cocoon::URLSessionDelayedRequestDisposition, cocoon::URLRequest)>)>::emit((__bridge void*)strongHost, "url_session_task_will_begin_delayed_request_completion_handler", cocoon::internal::wrap<cocoon::URLSessionTask>(task), cocoon::internal::wrap<cocoon::URLRequest>(request), [&]() -> std::function<void(cocoon::URLSessionDelayedRequestDisposition, cocoon::URLRequest)>
                                                                                                                                                                                         {
                                                                                                                                                                                             auto blk = (void (^)(::NSURLSessionDelayedRequestDisposition, ::NSURLRequest*))(completionHandler);
                                                                                                                                                                                             if (!blk)
                                                                                                                                                                                             {
                                                                                                                                                                                                 return {};
                                                                                                                                                                                             }
                                                                                                                                                                                             return [blk](cocoon::URLSessionDelayedRequestDisposition a281_0, cocoon::URLRequest a281_1) -> void
                                                                                                                                                                                             {
                                                                                                                                                                                                 blk(static_cast<::NSURLSessionDelayedRequestDisposition>(a281_0), cocoon::internal::native<::NSURLRequest>(a281_1));
                                                                                                                                                                                             };
                                                                                                                                                                                         }());
}

- (void)URLSession:(NSURLSession*)session taskIsWaitingForConnectivity:(NSURLSessionTask*)task
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask)>::emit((__bridge void*)strongHost, "url_session_task_is_waiting_for_connectivity", cocoon::internal::wrap<cocoon::URLSessionTask>(task));
}

- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task willPerformHTTPRedirection:(NSHTTPURLResponse*)response newRequest:(NSURLRequest*)request completionHandler:(void (^)(NSURLRequest*))completionHandler
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, cocoon::HTTPURLResponse, cocoon::URLRequest, std::function<void(cocoon::URLRequest)>)>::emit((__bridge void*)strongHost, "url_session_task_will_perform_http_redirection_new_request_completion_handler", cocoon::internal::wrap<cocoon::URLSessionTask>(task), cocoon::internal::wrap<cocoon::HTTPURLResponse>(response), cocoon::internal::wrap<cocoon::URLRequest>(request), [&]() -> std::function<void(cocoon::URLRequest)>
                                                                                                                                                                     {
                                                                                                                                                                         auto blk = (void (^)(::NSURLRequest*))(completionHandler);
                                                                                                                                                                         if (!blk)
                                                                                                                                                                         {
                                                                                                                                                                             return {};
                                                                                                                                                                         }
                                                                                                                                                                         return [blk](cocoon::URLRequest a282_0) -> void
                                                                                                                                                                         {
                                                                                                                                                                             blk(cocoon::internal::native<::NSURLRequest>(a282_0));
                                                                                                                                                                         };
                                                                                                                                                                     }());
}

- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition, NSURLCredential*))completionHandler
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, cocoon::URLAuthenticationChallenge, std::function<void(cocoon::URLSessionAuthChallengeDisposition, cocoon::URLCredential)>)>::emit((__bridge void*)strongHost, "url_session_task_did_receive_challenge_completion_handler", cocoon::internal::wrap<cocoon::URLSessionTask>(task), cocoon::internal::wrap<cocoon::URLAuthenticationChallenge>(challenge), [&]() -> std::function<void(cocoon::URLSessionAuthChallengeDisposition, cocoon::URLCredential)>
                                                                                                                                                                                                           {
                                                                                                                                                                                                               auto blk = (void (^)(::NSURLSessionAuthChallengeDisposition, ::NSURLCredential*))(completionHandler);
                                                                                                                                                                                                               if (!blk)
                                                                                                                                                                                                               {
                                                                                                                                                                                                                   return {};
                                                                                                                                                                                                               }
                                                                                                                                                                                                               return [blk](cocoon::URLSessionAuthChallengeDisposition a283_0, cocoon::URLCredential a283_1) -> void
                                                                                                                                                                                                               {
                                                                                                                                                                                                                   blk(static_cast<::NSURLSessionAuthChallengeDisposition>(a283_0), cocoon::internal::native<::NSURLCredential>(a283_1));
                                                                                                                                                                                                               };
                                                                                                                                                                                                           }());
}

- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task needNewBodyStream:(void (^)(NSInputStream*))completionHandler
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, std::function<void(cocoon::InputStream)>)>::emit((__bridge void*)strongHost, "url_session_task_need_new_body_stream", cocoon::internal::wrap<cocoon::URLSessionTask>(task), [&]() -> std::function<void(cocoon::InputStream)>
                                                                                                                         {
                                                                                                                             auto blk = (void (^)(::NSInputStream*))(completionHandler);
                                                                                                                             if (!blk)
                                                                                                                             {
                                                                                                                                 return {};
                                                                                                                             }
                                                                                                                             return [blk](cocoon::InputStream a284_0) -> void
                                                                                                                             {
                                                                                                                                 blk(cocoon::internal::native<::NSInputStream>(a284_0));
                                                                                                                             };
                                                                                                                         }());
}

- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task needNewBodyStreamFromOffset:(int64_t)offset completionHandler:(void (^)(NSInputStream*))completionHandler
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, std::int64_t, std::function<void(cocoon::InputStream)>)>::emit((__bridge void*)strongHost, "url_session_task_need_new_body_stream_from_offset_completion_handler", cocoon::internal::wrap<cocoon::URLSessionTask>(task), static_cast<std::int64_t>(offset), [&]() -> std::function<void(cocoon::InputStream)>
                                                                                                                                       {
                                                                                                                                           auto blk = (void (^)(::NSInputStream*))(completionHandler);
                                                                                                                                           if (!blk)
                                                                                                                                           {
                                                                                                                                               return {};
                                                                                                                                           }
                                                                                                                                           return [blk](cocoon::InputStream a285_0) -> void
                                                                                                                                           {
                                                                                                                                               blk(cocoon::internal::native<::NSInputStream>(a285_0));
                                                                                                                                           };
                                                                                                                                       }());
}

- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task didSendBodyData:(int64_t)bytesSent totalBytesSent:(int64_t)totalBytesSent totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, std::int64_t, std::int64_t, std::int64_t)>::emit((__bridge void*)strongHost, "url_session_task_did_send_body_data_total_bytes_sent_total_bytes_expected_to_send", cocoon::internal::wrap<cocoon::URLSessionTask>(task), static_cast<std::int64_t>(bytesSent), static_cast<std::int64_t>(totalBytesSent), static_cast<std::int64_t>(totalBytesExpectedToSend));
}

- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task didReceiveInformationalResponse:(NSHTTPURLResponse*)response
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, cocoon::HTTPURLResponse)>::emit((__bridge void*)strongHost, "url_session_task_did_receive_informational_response", cocoon::internal::wrap<cocoon::URLSessionTask>(task), cocoon::internal::wrap<cocoon::HTTPURLResponse>(response));
}

- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task didFinishCollectingMetrics:(NSURLSessionTaskMetrics*)metrics
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, cocoon::URLSessionTaskMetrics)>::emit((__bridge void*)strongHost, "url_session_task_did_finish_collecting_metrics", cocoon::internal::wrap<cocoon::URLSessionTask>(task), cocoon::internal::wrap<cocoon::URLSessionTaskMetrics>(metrics));
}

- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task didCompleteWithError:(NSError*)error
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, cocoon::Error)>::emit((__bridge void*)strongHost, "url_session_task_did_complete_with_error", cocoon::internal::wrap<cocoon::URLSessionTask>(task), cocoon::internal::wrap<cocoon::Error>(error));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(URLSession:didBecomeInvalidWithError:))
    {
        return strongHost && cocoon::Signal<cocoon::URLSessionTask, void(cocoon::Error)>::connected((__bridge void*)strongHost, "url_session_did_become_invalid_with_error");
    }
    if (selector == @selector(URLSession:didReceiveChallenge:completionHandler:))
    {
        return strongHost && cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLAuthenticationChallenge, std::function<void(cocoon::URLSessionAuthChallengeDisposition, cocoon::URLCredential)>)>::connected((__bridge void*)strongHost, "url_session_did_receive_challenge_completion_handler");
    }
    if (selector == @selector(URLSessionDidFinishEventsForBackgroundURLSession:))
    {
        return strongHost && cocoon::Signal<cocoon::URLSessionTask, void()>::connected((__bridge void*)strongHost, "url_session_did_finish_events_for_background_url_session");
    }
    if (selector == @selector(URLSession:didCreateTask:))
    {
        return strongHost && cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask)>::connected((__bridge void*)strongHost, "url_session_did_create_task");
    }
    if (selector == @selector(URLSession:task:willBeginDelayedRequest:completionHandler:))
    {
        return strongHost && cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, cocoon::URLRequest, std::function<void(cocoon::URLSessionDelayedRequestDisposition, cocoon::URLRequest)>)>::connected((__bridge void*)strongHost, "url_session_task_will_begin_delayed_request_completion_handler");
    }
    if (selector == @selector(URLSession:taskIsWaitingForConnectivity:))
    {
        return strongHost && cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask)>::connected((__bridge void*)strongHost, "url_session_task_is_waiting_for_connectivity");
    }
    if (selector == @selector(URLSession:task:willPerformHTTPRedirection:newRequest:completionHandler:))
    {
        return strongHost && cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, cocoon::HTTPURLResponse, cocoon::URLRequest, std::function<void(cocoon::URLRequest)>)>::connected((__bridge void*)strongHost, "url_session_task_will_perform_http_redirection_new_request_completion_handler");
    }
    if (selector == @selector(URLSession:task:didReceiveChallenge:completionHandler:))
    {
        return strongHost && cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, cocoon::URLAuthenticationChallenge, std::function<void(cocoon::URLSessionAuthChallengeDisposition, cocoon::URLCredential)>)>::connected((__bridge void*)strongHost, "url_session_task_did_receive_challenge_completion_handler");
    }
    if (selector == @selector(URLSession:task:needNewBodyStream:))
    {
        return strongHost && cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, std::function<void(cocoon::InputStream)>)>::connected((__bridge void*)strongHost, "url_session_task_need_new_body_stream");
    }
    if (selector == @selector(URLSession:task:needNewBodyStreamFromOffset:completionHandler:))
    {
        return strongHost && cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, std::int64_t, std::function<void(cocoon::InputStream)>)>::connected((__bridge void*)strongHost, "url_session_task_need_new_body_stream_from_offset_completion_handler");
    }
    if (selector == @selector(URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:))
    {
        return strongHost && cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, std::int64_t, std::int64_t, std::int64_t)>::connected((__bridge void*)strongHost, "url_session_task_did_send_body_data_total_bytes_sent_total_bytes_expected_to_send");
    }
    if (selector == @selector(URLSession:task:didReceiveInformationalResponse:))
    {
        return strongHost && cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, cocoon::HTTPURLResponse)>::connected((__bridge void*)strongHost, "url_session_task_did_receive_informational_response");
    }
    if (selector == @selector(URLSession:task:didFinishCollectingMetrics:))
    {
        return strongHost && cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, cocoon::URLSessionTaskMetrics)>::connected((__bridge void*)strongHost, "url_session_task_did_finish_collecting_metrics");
    }
    if (selector == @selector(URLSession:task:didCompleteWithError:))
    {
        return strongHost && cocoon::Signal<cocoon::URLSessionTask, void(cocoon::URLSessionTask, cocoon::Error)>::connected((__bridge void*)strongHost, "url_session_task_did_complete_with_error");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    URLSessionTask::URLSessionTask() : URLSessionTask(Adopt{cocoon::internal::retain([[::NSURLSessionTask alloc] init])})
    {
        URLSessionTask::install_delegate_delegate_(handle());
    }

    URLSessionTask::URLSessionTask(std::nullptr_t) : Object(nullptr)
    {
    }

    URLSessionTask::URLSessionTask(Adopt adopt) : Object(adopt)
    {
    }

    void URLSessionTask::cancel() const
    {
        [cocoon::internal::ns<::NSURLSessionTask>(this) cancel];
    }

    void URLSessionTask::resume() const
    {
        [cocoon::internal::ns<::NSURLSessionTask>(this) resume];
    }

    void URLSessionTask::suspend() const
    {
        [cocoon::internal::ns<::NSURLSessionTask>(this) suspend];
    }

    std::int64_t URLSessionTask::count_of_bytes_client_expects_to_receive() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLSessionTask>(this) countOfBytesClientExpectsToReceive]);
    }

    void URLSessionTask::set_count_of_bytes_client_expects_to_receive(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSURLSessionTask>(this) setCountOfBytesClientExpectsToReceive:static_cast<::int64_t>(value)];
    }

    std::int64_t URLSessionTask::count_of_bytes_client_expects_to_send() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLSessionTask>(this) countOfBytesClientExpectsToSend]);
    }

    void URLSessionTask::set_count_of_bytes_client_expects_to_send(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSURLSessionTask>(this) setCountOfBytesClientExpectsToSend:static_cast<::int64_t>(value)];
    }

    std::int64_t URLSessionTask::count_of_bytes_expected_to_receive() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLSessionTask>(this) countOfBytesExpectedToReceive]);
    }

    std::int64_t URLSessionTask::count_of_bytes_expected_to_send() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLSessionTask>(this) countOfBytesExpectedToSend]);
    }

    std::int64_t URLSessionTask::count_of_bytes_received() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLSessionTask>(this) countOfBytesReceived]);
    }

    std::int64_t URLSessionTask::count_of_bytes_sent() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLSessionTask>(this) countOfBytesSent]);
    }

    URLRequest URLSessionTask::current_request() const
    {
        return cocoon::internal::wrap<URLRequest>([cocoon::internal::ns<::NSURLSessionTask>(this) currentRequest]);
    }

    Date URLSessionTask::earliest_begin_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSURLSessionTask>(this) earliestBeginDate]);
    }

    void URLSessionTask::set_earliest_begin_date(const Date& value) const
    {
        [cocoon::internal::ns<::NSURLSessionTask>(this) setEarliestBeginDate:cocoon::internal::native<::NSDate>(value)];
    }

    Error URLSessionTask::error() const
    {
        return cocoon::internal::wrap<Error>([cocoon::internal::ns<::NSURLSessionTask>(this) error]);
    }

    URLRequest URLSessionTask::original_request() const
    {
        return cocoon::internal::wrap<URLRequest>([cocoon::internal::ns<::NSURLSessionTask>(this) originalRequest]);
    }

    bool URLSessionTask::prefers_incremental_delivery() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionTask>(this) prefersIncrementalDelivery]);
    }

    void URLSessionTask::set_prefers_incremental_delivery(bool value) const
    {
        [cocoon::internal::ns<::NSURLSessionTask>(this) setPrefersIncrementalDelivery:static_cast<::BOOL>(value)];
    }

    float URLSessionTask::priority() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSURLSessionTask>(this) priority]);
    }

    void URLSessionTask::set_priority(float value) const
    {
        [cocoon::internal::ns<::NSURLSessionTask>(this) setPriority:static_cast<float>(value)];
    }

    Progress URLSessionTask::progress() const
    {
        return cocoon::internal::wrap<Progress>([cocoon::internal::ns<::NSURLSessionTask>(this) progress]);
    }

    URLResponse URLSessionTask::response() const
    {
        return cocoon::internal::wrap<URLResponse>([cocoon::internal::ns<::NSURLSessionTask>(this) response]);
    }

    URLSessionTaskState URLSessionTask::state() const
    {
        return static_cast<URLSessionTaskState>([cocoon::internal::ns<::NSURLSessionTask>(this) state]);
    }

    std::string URLSessionTask::task_description() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLSessionTask>(this) taskDescription]);
    }

    void URLSessionTask::set_task_description(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLSessionTask>(this) setTaskDescription:cocoon::internal::to(value)];
    }

    std::uint64_t URLSessionTask::task_identifier() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSURLSessionTask>(this) taskIdentifier]);
    }

    void URLSessionTask::install_delegate_delegate_(void* native)
    {
        ::NSURLSessionTask* host = (__bridge ::NSURLSessionTask*)native;
        AKURLSessionTaskDelegate* delegate = [[AKURLSessionTaskDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSURLSessionTask* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSURLSessionTask* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
