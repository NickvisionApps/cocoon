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
     * @details A URL session task that communicates over the WebSockets protocol standard. ''URLSessionWebSocketTask'' is a concrete subclass of ''URLSessionTask'' that provides a message-oriented transport protocol over TCP and TLS in the form of WebSocket framing. It follows the WebSocket Protocol defined in [RFC 6455](https://tools.ietf.org/html/rfc6455). You create a ''URLSessionWebSocketTask'' with either a 'ws:' or 'wss:' URL. When creating the task, you can also provide a list of protocols to advertise during the handshake phase. Once the handshake completes, your app receives notifications through the session's ''URLSession/delegate''. You send data with ''send(:completionHandler:)'' and receive data with ''receive(completionHandler:)''. The task performs reads and writes asynchronously, and allows you to send and receive messages that contain both binary frames and UTF-8 encoded text frames. The task enqueues any reads or writes you perform prior to the handshake's completion, and executes them after the handshake completes. ''URLSessionWebSocketTask'' supports redirection and authentication like other types of tasks do, using the methods in ''URLSessionTaskDelegate''. The WebSocket task calls the redirection and authentication delegate methods prior to completing the handshake. The WebSocket task also supports cookies, by storing cookies to the session configuration's ''URLSessionConfiguration/httpCookieStorage'', and attaches cookies to outgoing HTTP handshake requests. > Note: > watchOS supports ''URLSessionWebSocketTask'' for specific use cases. For more details, see \<doc://com.apple.documentation/documentation/technotes/tn3135-low-level-networking-on-watchos>.
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
     * @details Sends a close frame with the given close code. An optional reason can be provided while sending the close frame. Simply calling '-cancel' on the task will result in a cancellation frame being sent without any reason. - Parameter closeCode: The close code to send. - Parameter reason: An optional data object containing the close reason.
     * @param close_code Argument converted to the Objective-C parameter of the same role.
     * @param reason Argument converted to the Objective-C parameter of the same role.
     */
        void cancel_with_close_code(URLSessionWebSocketCloseCode close_code, const std::vector<std::uint8_t>& reason) const;
        /**
     * @brief Calls `-[NSURLSessionWebSocketTask receiveMessageWithCompletionHandler:]`.
     * @details Reads a WebSocket message once all the frames of the message are available. If the task reaches the ''maximumMessageSize'' while buffering the frames, the receive call will error out and all outstanding work will also fail, resulting in the end of the task. - Parameters: - completionHandler: A closure that receives the WebSocket message and an 'NSError' that indicates an error encountered while receiving, or 'nil' if no error occurred.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void receive_message_with_completion_handler(std::function<void(URLSessionWebSocketMessage, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSessionWebSocketTask sendMessage:completionHandler:]`.
     * @details Sends a WebSocket message, receiving the result in a completion handler. If an error occurs while sending the message, any outstanding work also fails. Note that invocation of the completion handler does not guarantee that the remote side has received all the bytes, only that they have been written to the kernel. - Parameters: - message: The WebSocket message to send to the other endpoint. - completionHandler: A closure that receives an 'NSError' that indicates an error encountered while sending, or 'nil' if no error occurred.
     * @param message Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void send_message(const URLSessionWebSocketMessage& message, std::function<void(Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSessionWebSocketTask sendPingWithPongReceiveHandler:]`.
     * @details Sends a ping frame from the client side. The 'pongReceiveHandler' is invoked when the client receives a pong from the server endpoint. If a connection is lost or an error occurs before receiving the pong from the endpoint, the handler will be invoked with an error. The handler will always be called in the order in which the pings were sent. - Parameter pongReceiveHandler: The handler to call when a pong is received or an error occurs.
     * @param pong_receive_handler Argument converted to the Objective-C parameter of the same role.
     */
        void send_ping_with_pong_receive_handler(std::function<void(Error)> pong_receive_handler) const;
        /**
     * @brief Returns the `closeCode` property of `NSURLSessionWebSocketTask`.
     * @details A code that indicates the reason a connection closed. You can retrieve the close code at any time. When the task is not yet closed, this value is 'NSURLSessionWebSocketCloseCodeInvalid'.
     * @return The converted Objective-C result.
     */
        URLSessionWebSocketCloseCode close_code() const;
        /**
     * @brief Returns the `closeReason` property of `NSURLSessionWebSocketTask`.
     * @details The close reason received from the server. A task can be queried for its close reason at any point. A 'nil' value indicates no close reason or that the task is still running.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> close_reason() const;
        /**
     * @brief Returns the `maximumMessageSize` property of `NSURLSessionWebSocketTask`.
     * @details The maximum number of bytes to be buffered before erroring out. This includes the sum of all bytes from continuation frames. Receive calls will error out if this value is reached.
     * @return The converted Objective-C result.
     */
        std::int64_t maximum_message_size() const;
        /**
     * @brief Sets the `maximumMessageSize` property of `NSURLSessionWebSocketTask`.
     * @details The maximum number of bytes to be buffered before erroring out. This includes the sum of all bytes from continuation frames. Receive calls will error out if this value is reached.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_message_size(std::int64_t value) const;
    };
}
