#include "generated/url_session_web_socket_task.h"
#include "internal.h"

namespace cocoon
{
    URLSessionWebSocketTask::URLSessionWebSocketTask() : URLSessionTask(nullptr)
    {
    }

    URLSessionWebSocketTask::URLSessionWebSocketTask(std::nullptr_t) : URLSessionTask(nullptr)
    {
    }

    URLSessionWebSocketTask::URLSessionWebSocketTask(Adopt adopt) : URLSessionTask(adopt)
    {
    }

    void URLSessionWebSocketTask::cancel_with_close_code(URLSessionWebSocketCloseCode close_code, const std::vector<std::uint8_t>& reason) const
    {
        [cocoon::internal::ns<::NSURLSessionWebSocketTask>(this) cancelWithCloseCode:static_cast<::NSURLSessionWebSocketCloseCode>(close_code) reason:cocoon::internal::to_data(reason)];
    }

    void URLSessionWebSocketTask::receive_message_with_completion_handler(std::function<void(URLSessionWebSocketMessage, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSURLSessionWebSocketTask>(this) receiveMessageWithCompletionHandler:(completion_handler ? (void (^)(::NSURLSessionWebSocketMessage*, ::NSError*)) ^ void(::NSURLSessionWebSocketMessage * a248_0, ::NSError * a248_1) { completion_handler(cocoon::internal::wrap<URLSessionWebSocketMessage>(a248_0), cocoon::internal::wrap<Error>(a248_1)); } : (void (^)(::NSURLSessionWebSocketMessage*, ::NSError*))nil)];
    }

    void URLSessionWebSocketTask::send_message(const URLSessionWebSocketMessage& message, std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSURLSessionWebSocketTask>(this) sendMessage:cocoon::internal::native<::NSURLSessionWebSocketMessage>(message) completionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a249_0) { completion_handler(cocoon::internal::wrap<Error>(a249_0)); } : (void (^)(::NSError*))nil)];
    }

    void URLSessionWebSocketTask::send_ping_with_pong_receive_handler(std::function<void(Error)> pong_receive_handler) const
    {
        [cocoon::internal::ns<::NSURLSessionWebSocketTask>(this) sendPingWithPongReceiveHandler:(pong_receive_handler ? (void (^)(::NSError*)) ^ void(::NSError * a250_0) { pong_receive_handler(cocoon::internal::wrap<Error>(a250_0)); } : (void (^)(::NSError*))nil)];
    }

    URLSessionWebSocketCloseCode URLSessionWebSocketTask::close_code() const
    {
        return static_cast<URLSessionWebSocketCloseCode>([cocoon::internal::ns<::NSURLSessionWebSocketTask>(this) closeCode]);
    }

    std::vector<std::uint8_t> URLSessionWebSocketTask::close_reason() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSURLSessionWebSocketTask>(this) closeReason]);
    }

    std::int64_t URLSessionWebSocketTask::maximum_message_size() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLSessionWebSocketTask>(this) maximumMessageSize]);
    }

    void URLSessionWebSocketTask::set_maximum_message_size(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSURLSessionWebSocketTask>(this) setMaximumMessageSize:static_cast<::NSInteger>(value)];
    }
}
