#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/stream.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSInputStream` (Foundation).
     * @details A stream that provides read-only stream functionality. ''InputStream'' is "toll-free bridged" with its Core Foundation counterpart, \<doc://com.apple.documentation/documentation/corefoundation/cfreadstream>. For more information on toll-free bridging, see [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2). \#\#\# Subclassing Notes 'NSInputStream' is an abstract superclass of a class cluster consisting of concrete subclasses of 'NSStream' that provide standard read-only access to stream data. Although 'NSInputStream' is probably sufficient for most situations requiring access to stream data, you can create a subclass of 'NSInputStream' if you want more specialized behavior (for example, you want to record statistics on the data in a stream). \#\#\#\# Methods to Override To create a subclass of 'NSInputStream' you may have to implement initializers for the type of stream data supported and suitably re-implement existing initializers. You must also provide complete implementations of the following methods: - ''read(:maxLength:)'' From the current read index, take up to the number of bytes specified in the second parameter from the stream and place them in the client-supplied buffer (first parameter). The buffer must be of the size specified by the second parameter. Return the actual number of bytes placed in the buffer; if there is nothing left in the stream, return '0'. Reset the index into the stream for the next read operation. - ''getBuffer(:length:)'' Return in 0(1) a pointer to the subclass-allocated buffer (first parameter). Return by reference in the second parameter the number of bytes actually put into the buffer. The buffer's contents are valid only until the next stream operation. Return \<doc://com.apple.documentation/documentation/swift/false> if you cannot access data in the buffer; otherwise, return \<doc://com.apple.documentation/documentation/swift/true>. If this method is not appropriate for your type of stream, you may return \<doc://com.apple.documentation/documentation/swift/false>. - ''hasBytesAvailable'' Return \<doc://com.apple.documentation/documentation/swift/true> if there is more data to read in the stream, \<doc://com.apple.documentation/documentation/swift/false> if there is not. If you want to be semantically compatible with 'NSInputStream', return \<doc://com.apple.documentation/documentation/swift/true> if a read must be attempted to determine if bytes are available.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Stream.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::InputStream input_stream;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::InputStream input_stream{};
     * auto made_0 = cocoon::InputStream::input_stream_with_file_at_path("text");
     * auto made_1 = cocoon::InputStream::input_stream_with_url(cocoon::URL());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsinputstream
     */
    class InputStream : public Stream
    {
    public:
        /// @brief Creates a new `NSInputStream` instance and returns a handle to it.
        explicit InputStream(const std::vector<std::uint8_t>& data);
        /// @brief Creates a new `NSInputStream` instance and returns a handle to it.
        explicit InputStream(const std::string& path);
        /// @brief Creates a new `NSInputStream` instance and returns a handle to it.
        explicit InputStream(const URL& url);
        /// @brief Creates a new `NSInputStream` instance and returns a handle to it.
        explicit InputStream();
        /// @brief Creates a null handle that refers to no native object.
        InputStream(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit InputStream(Adopt adopt);
        /**
     * @brief Calls `-[NSInputStream getBuffer:length:]`.
     * @details Returns by reference a pointer to a read buffer and, by reference, the number of bytes available, and returns a Boolean value that indicates whether the buffer is available. This buffer is only valid until the next stream operation. Subclassers may return 'NO' for this if it is not appropriate for the stream type. This may return 'NO' if the buffer is not available. - Parameters: - buffer: Upon return, contains a pointer to a read buffer. - len: Upon return, contains the number of bytes available. - Returns: 'YES' if the buffer is available, otherwise 'NO'.
     * @param buffer Argument converted to the Objective-C parameter of the same role.
     * @param len Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool get_buffer(std::uint8_t** buffer, std::uint64_t* len) const;
        /**
     * @brief Calls `+[NSInputStream inputStreamWithData:]`.
     * @details Creates and returns an initialized 'NSInputStream' object for reading from a given 'NSData' object. The stream must be opened before it can be used. - Parameter data: The data object from which to read. The contents of 'data' are copied. - Returns: An initialized 'NSInputStream' object for reading from 'data'. If 'data' is not an 'NSData' object, this method returns 'nil'.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static InputStream input_stream_with_data(const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `+[NSInputStream inputStreamWithFileAtPath:]`.
     * @details Creates and returns an initialized 'NSInputStream' object that reads data from the file at a given path. The stream must be opened before it can be used. - Parameter path: The path to the file. - Returns: An initialized 'NSInputStream' object that reads data from the file at 'path'.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static InputStream input_stream_with_file_at_path(const std::string& path);
        /**
     * @brief Calls `+[NSInputStream inputStreamWithURL:]`.
     * @details Creates and returns an initialized 'NSInputStream' object that reads data from the file at a given URL. The stream must be opened before it can be used. - Parameter url: The URL to the file.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static InputStream input_stream_with_url(const URL& url);
        /**
     * @brief Calls `-[NSInputStream read:maxLength:]`.
     * @details Reads up to a given number of bytes into a given buffer. - Parameters: - buffer: A data buffer. The buffer must be large enough to contain the number of bytes specified by 'len'. - len: The maximum number of bytes to read. - Returns: A positive number indicates the number of bytes read; '0' indicates that the end of the buffer was reached; '-1' means that the operation failed (more information about the error can be obtained with 'streamError').
     * @param buffer Argument converted to the Objective-C parameter of the same role.
     * @param len Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t read(std::uint8_t* buffer, std::uint64_t len) const;
        /**
     * @brief Returns the `hasBytesAvailable` property of `NSInputStream`.
     * @details A Boolean value that indicates whether the receiver has bytes available to read. 'YES' if the stream has bytes available or if it is impossible to tell without actually doing the read.
     * @return The converted Objective-C result.
     */
        bool has_bytes_available() const;
    };
}
