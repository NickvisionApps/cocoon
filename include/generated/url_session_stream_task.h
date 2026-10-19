#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/url_session_task.h"
#include "types.h"

namespace cocoon
{
    class Error;

    /**
     * @brief C++ handle for the Objective-C class `NSURLSessionStreamTask` (Foundation).
     * @details An NSURLSessionStreamTask provides an interface to perform reads and writes to a TCP/IP stream created via NSURLSession. This task may be explicitly created from an NSURLSession, or created as a result of the appropriate disposition response to a -URLSession:dataTask:didReceiveResponse: delegate message. NSURLSessionStreamTask can be used to perform asynchronous reads and writes. Reads and writes are enqueued and executed serially, with the completion handler being invoked on the sessions delegate queue. If an error occurs, or the task is canceled, all outstanding read and write calls will have their completion handlers invoked with an appropriate error. It is also possible to create NSInputStream and NSOutputStream instances from an NSURLSessionTask by sending -captureStreams to the task. All outstanding reads and writes are completed before the streams are created. Once the streams are delivered to the session delegate, the task is considered complete and will receive no more messages. These streams are disassociated from the underlying session.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref URLSessionTask.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLSessionStreamTask url_session_stream_task;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::URLSessionStreamTask url_session_stream_task{};
     * url_session_stream_task.capture_streams();
     * url_session_stream_task.close_read();
     * url_session_stream_task.close_write();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlsessionstreamtask
     */
    class URLSessionStreamTask : public URLSessionTask
    {
    public:
        /// @brief Creates a new `NSURLSessionStreamTask` instance and returns a handle to it.
        explicit URLSessionStreamTask();
        /// @brief Creates a null handle that refers to no native object.
        URLSessionStreamTask(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLSessionStreamTask(Adopt adopt);
        /**
     * @brief Calls `-[NSURLSessionStreamTask captureStreams]`.
     * @details -captureStreams completes any already enqueued reads and writes, and then invokes the URLSession:streamTask:didBecomeInputStream:outputStream: delegate message. When that message is received, the task object is considered completed and will not receive any more delegate messages.
     */
        void capture_streams() const;
        /**
     * @brief Calls `-[NSURLSessionStreamTask closeRead]`.
     * @details Enqueue a request to close the read side of the underlying socket. All outstanding IO will complete before the read side is closed. You may continue writing to the server.
     */
        void close_read() const;
        /**
     * @brief Calls `-[NSURLSessionStreamTask closeWrite]`.
     * @details Enqueue a request to close the write end of the underlying socket. All outstanding IO will complete before the write side of the socket is closed. The server, however, may continue to write bytes back to the client, so best practice is to continue reading from the server until you receive EOF.
     */
        void close_write() const;
        /**
     * @brief Calls `-[NSURLSessionStreamTask readDataOfMinLength:maxLength:timeout:completionHandler:]`.
     * @details Read minBytes, or at most maxBytes bytes and invoke the completion handler on the sessions delegate queue with the data or an error. If an error occurs, any outstanding reads will also fail, and new read requests will error out immediately.
     * @param min_bytes Argument converted to the Objective-C parameter of the same role.
     * @param max_bytes Argument converted to the Objective-C parameter of the same role.
     * @param timeout Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void read_data_of_min_length(std::uint64_t min_bytes, std::uint64_t max_bytes, double timeout, std::function<void(std::vector<std::uint8_t>, bool, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLSessionStreamTask startSecureConnection]`.
     * @details Begin encrypted handshake. The handshake begins after all pending IO has completed. TLS authentication callbacks are sent to the session's -URLSession:task:didReceiveChallenge:completionHandler:
     */
        void start_secure_connection() const;
        /**
     * @brief Calls `-[NSURLSessionStreamTask writeData:timeout:completionHandler:]`.
     * @details Write the data completely to the underlying socket. If all the bytes have not been written by the timeout, a timeout error will occur. Note that invocation of the completion handler does not guarantee that the remote side has received all the bytes, only that they have been written to the kernel.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param timeout Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void write_data(const std::vector<std::uint8_t>& data, double timeout, std::function<void(Error)> completion_handler) const;
    };
}
