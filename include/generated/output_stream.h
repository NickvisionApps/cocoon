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
     * @param buffer Argument converted to the Objective-C parameter of the same role.
     * @param capacity Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static OutputStream output_stream_to_buffer(std::uint8_t* buffer, std::uint64_t capacity);
        /**
     * @brief Calls `+[NSOutputStream outputStreamToFileAtPath:append:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param should_append Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static OutputStream output_stream_to_file_at_path(const std::string& path, bool should_append);
        /**
     * @brief Calls `+[NSOutputStream outputStreamToMemory]`.
     * @return The converted Objective-C result.
     */
        static OutputStream output_stream_to_memory();
        /**
     * @brief Calls `+[NSOutputStream outputStreamWithURL:append:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param should_append Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static OutputStream output_stream_with_url(const URL& url, bool should_append);
        /**
     * @brief Calls `-[NSOutputStream write:maxLength:]`.
     * @param buffer Argument converted to the Objective-C parameter of the same role.
     * @param len Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t write(const std::uint8_t* buffer, std::uint64_t len) const;
        /**
     * @brief Returns the `hasSpaceAvailable` property of `NSOutputStream`.
     * @return The converted Objective-C result.
     */
        bool has_space_available() const;
    };
}
