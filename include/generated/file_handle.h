#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSFileHandle` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FileHandle file_handle;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::FileHandle file_handle{};
     * auto made_0 = cocoon::FileHandle::file_handle_for_reading_at_path("text");
     * auto made_1 = cocoon::FileHandle::file_handle_for_reading_from_url(cocoon::URL());
     * file_handle.accept_connection_in_background_and_notify();
     * file_handle.accept_connection_in_background_and_notify_for_modes({"a", "b"});
     * file_handle.close_and_return_error();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsfilehandle
     */
    class FileHandle : public Object
    {
    public:
        /// @brief Creates a new `NSFileHandle` instance and returns a handle to it.
        explicit FileHandle(int fd);
        /// @brief Creates a new `NSFileHandle` instance and returns a handle to it.
        explicit FileHandle(int fd, bool closeopt);
        /// @brief Creates a new `NSFileHandle` instance and returns a handle to it.
        explicit FileHandle();
        /// @brief Creates a null handle that refers to no native object.
        FileHandle(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FileHandle(Adopt adopt);
        /**
     * @brief Calls `-[NSFileHandle acceptConnectionInBackgroundAndNotify]`.
     */
        void accept_connection_in_background_and_notify() const;
        /**
     * @brief Calls `-[NSFileHandle acceptConnectionInBackgroundAndNotifyForModes:]`.
     * @param modes Argument converted to the Objective-C parameter of the same role.
     */
        void accept_connection_in_background_and_notify_for_modes(const std::vector<std::string>& modes) const;
        /**
     * @brief Calls `-[NSFileHandle closeAndReturnError:]`.
     * @return The converted Objective-C result.
     */
        bool close_and_return_error() const;
        /**
     * @brief Calls `+[NSFileHandle fileHandleForReadingAtPath:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_for_reading_at_path(const std::string& path);
        /**
     * @brief Calls `+[NSFileHandle fileHandleForReadingFromURL:error:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_for_reading_from_url(const URL& url);
        /**
     * @brief Calls `+[NSFileHandle fileHandleForUpdatingAtPath:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_for_updating_at_path(const std::string& path);
        /**
     * @brief Calls `+[NSFileHandle fileHandleForUpdatingURL:error:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_for_updating_url(const URL& url);
        /**
     * @brief Calls `+[NSFileHandle fileHandleForWritingAtPath:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_for_writing_at_path(const std::string& path);
        /**
     * @brief Calls `+[NSFileHandle fileHandleForWritingToURL:error:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_for_writing_to_url(const URL& url);
        /**
     * @brief Calls `-[NSFileHandle getOffset:error:]`.
     * @param offset_in_file Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool get_offset(std::uint64_t* offset_in_file) const;
        /**
     * @brief Calls `-[NSFileHandle readDataToEndOfFileAndReturnError:]`.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> read_data_to_end_of_file_and_return_error() const;
        /**
     * @brief Calls `-[NSFileHandle readDataUpToLength:error:]`.
     * @param length Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> read_data_up_to_length(std::uint64_t length) const;
        /**
     * @brief Calls `-[NSFileHandle readInBackgroundAndNotify]`.
     */
        void read_in_background_and_notify() const;
        /**
     * @brief Calls `-[NSFileHandle readInBackgroundAndNotifyForModes:]`.
     * @param modes Argument converted to the Objective-C parameter of the same role.
     */
        void read_in_background_and_notify_for_modes(const std::vector<std::string>& modes) const;
        /**
     * @brief Calls `-[NSFileHandle readToEndOfFileInBackgroundAndNotify]`.
     */
        void read_to_end_of_file_in_background_and_notify() const;
        /**
     * @brief Calls `-[NSFileHandle readToEndOfFileInBackgroundAndNotifyForModes:]`.
     * @param modes Argument converted to the Objective-C parameter of the same role.
     */
        void read_to_end_of_file_in_background_and_notify_for_modes(const std::vector<std::string>& modes) const;
        /**
     * @brief Calls `-[NSFileHandle seekToEndReturningOffset:error:]`.
     * @param offset_in_file Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool seek_to_end_returning_offset(std::uint64_t* offset_in_file) const;
        /**
     * @brief Calls `-[NSFileHandle seekToOffset:error:]`.
     * @param offset Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool seek_to_offset(std::uint64_t offset) const;
        /**
     * @brief Calls `-[NSFileHandle synchronizeAndReturnError:]`.
     * @return The converted Objective-C result.
     */
        bool synchronize_and_return_error() const;
        /**
     * @brief Calls `-[NSFileHandle truncateAtOffset:error:]`.
     * @param offset Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool truncate_at_offset(std::uint64_t offset) const;
        /**
     * @brief Calls `-[NSFileHandle waitForDataInBackgroundAndNotify]`.
     */
        void wait_for_data_in_background_and_notify() const;
        /**
     * @brief Calls `-[NSFileHandle waitForDataInBackgroundAndNotifyForModes:]`.
     * @param modes Argument converted to the Objective-C parameter of the same role.
     */
        void wait_for_data_in_background_and_notify_for_modes(const std::vector<std::string>& modes) const;
        /**
     * @brief Calls `-[NSFileHandle writeData:error:]`.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool write_data(const std::vector<std::uint8_t>& data) const;
        /**
     * @brief Returns the `availableData` property of `NSFileHandle`.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> available_data() const;
        /**
     * @brief Returns the `fileDescriptor` property of `NSFileHandle`.
     * @return The converted Objective-C result.
     */
        int file_descriptor() const;
        /**
     * @brief Returns the `fileHandleWithNullDevice` property of `NSFileHandle`.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_with_null_device();
        /**
     * @brief Returns the `fileHandleWithStandardError` property of `NSFileHandle`.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_with_standard_error();
        /**
     * @brief Returns the `fileHandleWithStandardInput` property of `NSFileHandle`.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_with_standard_input();
        /**
     * @brief Returns the `fileHandleWithStandardOutput` property of `NSFileHandle`.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_with_standard_output();
        /**
     * @brief Returns the `readabilityHandler` property of `NSFileHandle`.
     * @return The converted Objective-C result.
     */
        std::function<void(FileHandle)> readability_handler() const;
        /**
     * @brief Sets the `readabilityHandler` property of `NSFileHandle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_readability_handler(std::function<void(FileHandle)> value) const;
        /**
     * @brief Returns the `writeabilityHandler` property of `NSFileHandle`.
     * @return The converted Objective-C result.
     */
        std::function<void(FileHandle)> writeability_handler() const;
        /**
     * @brief Sets the `writeabilityHandler` property of `NSFileHandle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_writeability_handler(std::function<void(FileHandle)> value) const;
    };
}
