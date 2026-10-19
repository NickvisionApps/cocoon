#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/url_session_task.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class URLSessionWebSocketMessage;

    /**
     * @brief C++ handle for the Objective-C class `NSURLSessionWebSocketTask` (Foundation).
     * @details A WebSocket task can be created with a ws or wss url. A client can also provide a list of protocols it wishes to advertise during the WebSocket handshake phase. Once the handshake is successfully completed the client will be notified through an optional delegate. All reads and writes enqueued before the completion of the handshake will be queued up and executed once the handshake succeeds. Before the handshake completes, the client can be called to handle redirection or authentication using the same delegates as NSURLSessionTask. WebSocket task will also provide support for cookies and will store cookies to the cookie storage on the session and will attach cookies to outgoing HTTP handshake requests.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref URLSessionTask.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLSessionWebSocketTask url_session_web_socket_task(nullptr);  // null handle; instances normally come from other API calls
     * url_session_web_socket_task.set_maximum_message_size(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::URLSessionWebSocketTask url_session_web_socket_task(nullptr);
     * url_session_web_socket_task.set_maximum_message_size(1);
     * auto maximum_message_size = url_session_web_socket_task.maximum_message_size();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlsessionwebsockettask
     */
    class URLSessionWebSocketTask : public URLSessionTask
    {
    public:
        URLSessionWebSocketTask();
        /// @brief Creates a null handle that refers to no native object.
        URLSessionWebSocketTask(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLSessionWebSocketTask(Adopt adopt);
        /**
     * @brief Calls `-[NSURLSessionWebSocketTask cancelWithCloseCode:reason:]`.
     * @details Sends a close frame with the given closeCode. An optional reason can be provided while sending the close frame. Simply calling cancel on the task will result in a cancellation frame being sent without any reason.
     * @param close_code Argument converted to the Objective-C parameter of the same role.
     * @param reason Argument converted to the Objective-C parameter of the same role.
     */
        void cancel_with_close_code(URLSessionWebSocketCloseCode close_code, const std::vector<std::uint8_t>& reason) const;
        /**
     * @brief Calls `-[NSURLSessionWebSocketTask receiveMessageWithCompletionHandler:]`.
     * @details Reads a WebSocket message once all the frames of the message are available. If the maximumMessage size is hit while buffering the frames, the receiveMessage call will error out and all outstanding work will also fail resulting in the end of the task.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void receive_message_with_completion_handler(std::function<void(URLSessionWebSocketMessage, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSessionWebSocketTask sendMessage:completionHandler:]`.
     * @details Sends a WebSocket message. If an error occurs, any outstanding work will also fail. Note that invocation of the completion handler does not guarantee that the remote side has received all the bytes, only that they have been written to the kernel.
     * @param message Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void send_message(const URLSessionWebSocketMessage& message, std::function<void(Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSessionWebSocketTask sendPingWithPongReceiveHandler:]`.
     * @details Sends a ping frame from the client side. The pongReceiveHandler is invoked when the client receives a pong from the server endpoint. If a connection is lost or an error occurs before receiving the pong from the endpoint, the pongReceiveHandler block will be invoked with an error. Note - the pongReceiveHandler will always be called in the order in which the pings were sent.
     * @param pong_receive_handler Argument converted to the Objective-C parameter of the same role.
     */
        void send_ping_with_pong_receive_handler(std::function<void(Error)> pong_receive_handler) const;
        /**
     * @brief Returns the `closeCode` property of `NSURLSessionWebSocketTask`.
     * @details \@property NSInteger maximumMessageSize; / The maximum number of bytes to be buffered before erroring out. This includes the sum of all bytes from continuation frames. Receive calls will error out if this value is reached
     * @return The converted Objective-C result.
     */
        URLSessionWebSocketCloseCode close_code() const;
        /**
     * @brief Returns the `closeReason` property of `NSURLSessionWebSocketTask`.
     * @details \@property (readonly) NSURLSessionWebSocketCloseCode closeCode; / A task can be queried for it's close code at any point. When the task is not closed, it will be set to NSURLSessionWebSocketCloseCodeInvalid
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> close_reason() const;
        /**
     * @brief Returns the `maximumMessageSize` property of `NSURLSessionWebSocketTask`.
     * @return The converted Objective-C result.
     */
        std::int64_t maximum_message_size() const;
        /**
     * @brief Sets the `maximumMessageSize` property of `NSURLSessionWebSocketTask`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_message_size(std::int64_t value) const;
    };
}
