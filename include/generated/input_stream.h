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
     * @param buffer Argument converted to the Objective-C parameter of the same role.
     * @param len Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool get_buffer(std::uint8_t** buffer, std::uint64_t* len) const;
        /**
     * @brief Calls `+[NSInputStream inputStreamWithData:]`.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static InputStream input_stream_with_data(const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `+[NSInputStream inputStreamWithFileAtPath:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static InputStream input_stream_with_file_at_path(const std::string& path);
        /**
     * @brief Calls `+[NSInputStream inputStreamWithURL:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static InputStream input_stream_with_url(const URL& url);
        /**
     * @brief Calls `-[NSInputStream read:maxLength:]`.
     * @param buffer Argument converted to the Objective-C parameter of the same role.
     * @param len Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t read(std::uint8_t* buffer, std::uint64_t len) const;
        /**
     * @brief Returns the `hasBytesAvailable` property of `NSInputStream`.
     * @return The converted Objective-C result.
     */
        bool has_bytes_available() const;
    };
}
