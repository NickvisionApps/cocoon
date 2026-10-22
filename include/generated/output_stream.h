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
     * @brief C++ handle for the Objective-C class `NSOutputStream` (Foundation).
     * @details A stream that provides write-only stream functionality. ''OutputStream'' is "toll-free bridged" with its Core Foundation counterpart, \<doc://com.apple.documentation/documentation/corefoundation/cfwritestream>. For more information on toll-free bridging, see [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2). \#\#\# Subclassing Notes 'NSOutputStream' is a concrete subclass of 'NSStream' that lets you write data to a stream. Although 'NSOutputStream' is probably sufficient for most situations requiring this capability, you can create a subclass of 'NSOutputStream' if you want more specialized behavior (for example, you want to record statistics on the data in a stream). \#\#\#\# Methods to Override To create a subclass of 'NSOutputStream' you may have to implement initializers for the type of stream data supported and suitably reimplement existing initializers. You must also provide complete implementations of the following methods: - ''write(:maxLength:)'' From the current write pointer, take up to the number of bytes specified in the 'maxLength:' parameter from the client-supplied buffer (first parameter) and put them onto the stream. The buffer must be of the size specified by the second parameter. To prepare for the next operation, offset the write pointer by the number of bytes written. Return a signed integer based on the outcome of the current operation: - If the write operation is successful, return the actual number of bytes put onto the stream. - If the stream is of a fixed length and has reached its capacity, return '0'. - If there was an error writing to the stream, return '-1'. - ''hasSpaceAvailable'' Return \<doc://com.apple.documentation/documentation/swift/true> if the stream can currently accept more data, \<doc://com.apple.documentation/documentation/swift/false> if it cannot. If you want to be semantically compatible with 'NSOutputStream', return \<doc://com.apple.documentation/documentation/swift/true> if a write must be attempted to determine if space is available.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Stream.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::OutputStream output_stream;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::OutputStream output_stream{};
     * auto made_0 = cocoon::OutputStream::output_stream_to_file_at_path("text", true);
     * auto made_1 = cocoon::OutputStream::output_stream_to_memory();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsoutputstream
     */
    class OutputStream : public Stream
    {
    public:
        /// @brief Creates a new `NSOutputStream` instance and returns a handle to it.
        explicit OutputStream(std::uint8_t* buffer, std::uint64_t capacity);
        /// @brief Creates a new `NSOutputStream` instance and returns a handle to it.
        explicit OutputStream(const std::string& path, bool should_append);
        /// @brief Creates a new `NSOutputStream` instance and returns a handle to it.
        explicit OutputStream();
        /// @brief Creates a new `NSOutputStream` instance and returns a handle to it.
        explicit OutputStream(const URL& url, bool should_append);
        /// @brief Creates a null handle that refers to no native object.
        OutputStream(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit OutputStream(Adopt adopt);
        /**
         * @brief Calls `+[NSOutputStream outputStreamToBuffer:capacity:]`.
         * @details Creates and returns an initialized output stream that can write to a provided buffer. The stream must be opened before it can be used. When the number of bytes written to 'buffer' has reached 'capacity', the stream's 'streamStatus' will return 'NSStreamStatusAtEnd'. - Parameters: - buffer: The buffer the output stream will write to. - capacity: The size of the buffer in bytes. - Returns: An initialized output stream that can write to 'buffer'.
         * @param buffer Argument converted to the Objective-C parameter of the same role.
         * @param capacity Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static OutputStream output_stream_to_buffer(std::uint8_t* buffer, std::uint64_t capacity);
        /**
         * @brief Calls `+[NSOutputStream outputStreamToFileAtPath:append:]`.
         * @details Creates and returns an initialized output stream for writing to a specified file. The stream must be opened before it can be used. - Parameters: - path: The path to the file the output stream will write to. - shouldAppend: 'YES' if newly written data should be appended to any existing file contents, otherwise 'NO'. - Returns: An initialized output stream that can write to 'path'.
         * @param path Argument converted to the Objective-C parameter of the same role.
         * @param should_append Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static OutputStream output_stream_to_file_at_path(const std::string& path, bool should_append);
        /**
         * @brief Calls `+[NSOutputStream outputStreamToMemory]`.
         * @details Creates and returns an initialized output stream that will write stream data to memory. The stream must be opened before it can be used. You retrieve the contents of the memory stream by sending the message 'propertyForKey:' to the receiver with an argument of 'NSStreamDataWrittenToMemoryStreamKey'.
         * @return The converted Objective-C result.
         */
        static OutputStream output_stream_to_memory();
        /**
         * @brief Calls `-[NSOutputStream write:maxLength:]`.
         * @details Writes the contents of a provided data buffer to the receiver. - Parameters: - buffer: The data to write. - len: The length of the data buffer, in bytes. The behavior of this method is undefined if you pass a negative or zero number. - Returns: A positive number indicates the number of bytes written; '0' indicates that a fixed-length stream has reached its capacity; '-1' means that the operation failed (more information about the error can be obtained with 'streamError').
         * @param buffer Argument converted to the Objective-C parameter of the same role.
         * @param len Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t write(const std::uint8_t* buffer, std::uint64_t len) const;
        /**
         * @brief Returns the `hasSpaceAvailable` property of `NSOutputStream`.
         * @details A Boolean value that indicates whether the receiver can be written to. 'YES' if the stream can be written to or if a write must be attempted in order to determine if space is available, 'NO' otherwise.
         * @return The converted Objective-C result.
         */
        bool has_space_available() const;
    };
}
