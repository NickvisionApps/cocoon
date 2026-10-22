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
     * @details A URL session task that is stream-based. ''URLSessionStreamTask'' is a concrete subclass of ''URLSessionTask''. Many of the methods in the ''URLSessionStreamTask'' class are documented in ''URLSessionTask''. The ''URLSessionStreamTask'' class provides an interface a TCP/IP connection created via ''URLSession''. Tasks may be created from an ''URLSession'' using the ''URLSession/streamTask(withHostName:port:)'' and ''URLSession/streamTask(with:)'' methods. They may also be created as a result of an ''URLSessionDataTask'' being upgraded via the HTTP 'Upgrade:' response header and appropriate use of the ''URLSessionConfiguration/httpShouldUsePipelining'' option of ''URLSessionConfiguration''. > Note: > See [RFC 2817](https://tools.ietf.org/html/rfc2817) and [RFC 6455](https://tools.ietf.org/html/rfc6455) for information about the 'Upgrade:' header. A ''URLSessionStreamTask'' object performs asynchronous reads and writes, which are enqueued and executed serially, calling a handler upon completion being on the session delegate queue. If the task is canceled, all enqueued reads and writes will call their completion handlers with an appropriate error. When working with APIs that accept ''Stream'' objects, you can create ''InputStream'' and ''OutputStream'' objects from an ''URLSessionStreamTask'' object by calling the ''captureStreams()'' method. > Note: > watchOS supports ''URLSessionStreamTask'' for specific use cases. For more details, see \<doc://com.apple.documentation/documentation/technotes/tn3135-low-level-networking-on-watchos>.
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
         * @details Completes any already enqueued reads and writes, then invokes the 'URLSession:streamTask:didBecomeInputStream:outputStream:' delegate message. When that message is received, the task object is considered completed and will not receive any more delegate messages.
         */
        void capture_streams() const;
        /**
         * @brief Calls `-[NSURLSessionStreamTask closeRead]`.
         * @details Enqueues a request to close the read side of the underlying socket. All outstanding IO will complete before the read side is closed. You may continue writing to the server.
         */
        void close_read() const;
        /**
         * @brief Calls `-[NSURLSessionStreamTask closeWrite]`.
         * @details Enqueues a request to close the write end of the underlying socket. All outstanding IO will complete before the write side of the socket is closed. The server, however, may continue to write bytes back to the client, so best practice is to continue reading from the server until you receive EOF.
         */
        void close_write() const;
        /**
         * @brief Calls `-[NSURLSessionStreamTask readDataOfMinLength:maxLength:timeout:completionHandler:]`.
         * @details Reads minimum 'minBytes', or at most 'maxBytes' bytes and invokes the completion handler on the session's delegate queue with the data or an error. If an error occurs, any outstanding reads will also fail, and new read requests will error out immediately. - Parameter minBytes: The minimum number of bytes to read. - Parameter maxBytes: The maximum number of bytes to read. - Parameter timeout: The timeout interval for the read operation. - Parameter completionHandler: The completion handler to call when the read operation completes.
         * @param min_bytes Argument converted to the Objective-C parameter of the same role.
         * @param max_bytes Argument converted to the Objective-C parameter of the same role.
         * @param timeout Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void read_data_of_min_length(std::uint64_t min_bytes, std::uint64_t max_bytes, double timeout, std::function<void(std::vector<std::uint8_t>, bool, Error)> completion_handler) const;
        /**
         * @brief Calls `-[NSURLSessionStreamTask startSecureConnection]`.
         * @details Begins encrypted handshake. The handshake begins after all pending IO has completed. TLS authentication callbacks are sent to the session's 'URLSession:task:didReceiveChallenge:completionHandler:' delegate method.
         */
        void start_secure_connection() const;
        /**
         * @brief Calls `-[NSURLSessionStreamTask writeData:timeout:completionHandler:]`.
         * @details Writes the data completely to the underlying socket. If all the bytes have not been written by the timeout, a timeout error will occur. Note that invocation of the completion handler does not guarantee that the remote side has received all the bytes, only that they have been written to the kernel. - Parameter data: The data to write to the stream. - Parameter timeout: The timeout interval for the write operation. - Parameter completionHandler: The completion handler to call when the write operation completes.
         * @param data Argument converted to the Objective-C parameter of the same role.
         * @param timeout Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void write_data(const std::vector<std::uint8_t>& data, double timeout, std::function<void(Error)> completion_handler) const;
    };
}
