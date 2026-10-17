#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSFileHandle` (Foundation).
     * @details An object-oriented wrapper for a file descriptor. You use file handle objects to access data associated with files, sockets, pipes, and devices. For files, you can read, write, and seek within the file. For sockets, pipes, and devices, you can use a file handle object to monitor the device and process data asynchronously. Most creation methods for ''FileHandle'' cause the file handle object to take ownership of the associated file descriptor. This means that the file handle object both creates the file descriptor and is responsible for closing it later, usually when the system deallocates the file handle object. If you want to use a file handle object with a file descriptor that you created, use the ''init(fileDescriptor:)'' method or use the ''init(fileDescriptor:closeOnDealloc:)'' method and pass \<doc://com.apple.documentation/documentation/swift/false> for the 'flag' parameter. \#\#\# Run Loop Considerations When using a file handle object to communicate asynchronously with a socket, you must initiate the corresponding operations from a thread with an active run loop. Although the read, accept, and wait operations themselves are performed asynchronously on background threads, the file handle uses a run loop source to monitor the operations and notify your code appropriately. Therefore, you must call those methods from your application's main thread or from any thread where you've configured a run loop and are using it to process events.
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
     * @details Accepts a socket connection (for stream-type sockets only) in the background and creates a file handle for the "near" (client) end of the communications channel. This method asynchronously creates a file handle for the other end of the socket connection and returns that object by posting an 'NSFileHandleConnectionAcceptedNotification'. The notification includes a 'userInfo' dictionary with the created ''FileHandle'' object, accessible using the 'NSFileHandleNotificationFileHandleItem' key. You must call this method from a thread that has an active run loop.
     */
        void accept_connection_in_background_and_notify() const;
        /**
     * @brief Calls `-[NSFileHandle acceptConnectionInBackgroundAndNotifyForModes:]`.
     * @details Accepts a socket connection (for stream-type sockets only) in the background and creates a file handle for the "near" (client) end of the communications channel. - Parameter modes: The runloop modes in which the connection accepted notification can be posted. See ''FileHandle/acceptConnectionInBackgroundAndNotify()'' for details. This method differs in that the notification is queued for posting in the specified run-loop modes.
     * @param modes Argument converted to the Objective-C parameter of the same role.
     */
        void accept_connection_in_background_and_notify_for_modes(const std::vector<std::string>& modes) const;
        /**
     * @brief Calls `-[NSFileHandle closeAndReturnError:]`.
     * @details Disallows further access to the represented file or communications channel and signals end of file on communications channels that permit writing. If the file handle object owns its file descriptor, it automatically closes that descriptor when it is deallocated. If you initialized the file handle object using the ''FileHandle/init(fileDescriptor:closeOnDealloc:)'' method, the file handle object takes ownership of the file descriptor if you passed 'YES' for the 'flag' parameter. After invoking this method, you may still need to release the file handle object, but the object should not be used to read from or write to the file.
     * @return The converted Objective-C result.
     */
        bool close_and_return_error() const;
        /**
     * @brief Calls `+[NSFileHandle fileHandleForReadingAtPath:]`.
     * @details Returns a file handle initialized for reading the file, device, or named socket at the specified path. - Parameter path: The path to the file, device, or named socket to access. - Returns: The initialized file handle object or 'nil' if no file exists at 'path'. The file pointer is set to the beginning of the file. You cannot write data to the returned file handle object. The returned object responds only to ''FileHandle/readData(ofLength:)'', ''FileHandle/readDataToEndOfFile()'', and ''FileHandle/availableData''. The file handle owns its file descriptor.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_for_reading_at_path(const std::string& path);
        /**
     * @brief Calls `+[NSFileHandle fileHandleForReadingFromURL:error:]`.
     * @details Returns a file handle initialized for reading the file, device, or named socket at the specified URL. - Parameters: - url: The URL of the file, device, or named socket to access. - error: If an error occurs, upon return contains an 'NSError' object that describes the problem. Pass 'NULL' if you do not want error information. - Returns: The initialized file handle object or 'nil' if no file exists at 'url'. The file pointer is set to the beginning of the file. You cannot write data to the returned file handle object. Use the ''FileHandle/readDataToEndOfFile()'' or ''FileHandle/readData(ofLength:)'' methods to read data from it. When using this method to create a file handle object, the file handle owns its associated file descriptor and is responsible for closing it.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_for_reading_from_url(const URL& url);
        /**
     * @brief Calls `+[NSFileHandle fileHandleForUpdatingAtPath:]`.
     * @details Returns a file handle initialized for reading and writing to the file, device, or named socket at the specified path. - Parameter path: The path to the file, device, or named socket to access. - Returns: The initialized file handle object or 'nil' if no file exists at 'path'. The file pointer is set to the beginning of the file. The returned object responds to both read and write messages.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_for_updating_at_path(const std::string& path);
        /**
     * @brief Calls `+[NSFileHandle fileHandleForUpdatingURL:error:]`.
     * @details Returns a file handle initialized for reading and writing to the file, device, or named socket at the specified URL. - Parameters: - url: The URL of the file, device, or named socket to access. - error: If an error occurs, upon return contains an 'NSError' object that describes the problem. Pass 'NULL' if you do not want error information. - Returns: The initialized file handle object or 'nil' if no file exists at 'url'. The file pointer is set to the beginning of the file. The returned object responds to both read and ''FileHandle/write(:)'' messages. When using this method to create a file handle object, the file handle owns its associated file descriptor and is responsible for closing it.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_for_updating_url(const URL& url);
        /**
     * @brief Calls `+[NSFileHandle fileHandleForWritingAtPath:]`.
     * @details Returns a file handle initialized for writing to the file, device, or named socket at the specified path. - Parameter path: The path to the file, device, or named socket to access. - Returns: The initialized file handle object or 'nil' if no file exists at 'path'. The file pointer is set to the beginning of the file. You cannot read data from the returned file handle object. Use ''FileHandle/write(:)'' to write data to the returned file handle object. The file handle owns its file descriptor.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_for_writing_at_path(const std::string& path);
        /**
     * @brief Calls `+[NSFileHandle fileHandleForWritingToURL:error:]`.
     * @details Returns a file handle initialized for writing to the file, device, or named socket at the specified URL. - Parameters: - url: The URL of the file, device, or named socket to access. - error: If an error occurs, upon return contains an 'NSError' object that describes the problem. Pass 'NULL' if you do not want error information. - Returns: The initialized file handle object or 'nil' if no file exists at 'url'. The file pointer is set to the beginning of the file. The returned object responds only to ''FileHandle/write(:)''. When using this method to create a file handle object, the file handle owns its associated file descriptor and is responsible for closing it.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_for_writing_to_url(const URL& url);
        /**
     * @brief Calls `-[NSFileHandle getOffset:error:]`.
     * @details Gets the position of the file pointer within the file. - Parameters: - offsetInFile: On return, contains the file offset. - error: If an error occurs, upon return contains an 'NSError' object that describes the problem. - Returns: 'YES' if the offset was retrieved successfully; otherwise, 'NO'.
     * @param offset_in_file Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool get_offset(std::uint64_t* offset_in_file) const;
        /**
     * @brief Calls `-[NSFileHandle readDataToEndOfFileAndReturnError:]`.
     * @details Reads the available data synchronously up to the end of file or maximum number of bytes. - Returns: The data available through the receiver up to the maximum size that can be represented by an 'NSData' object. This method invokes ''FileHandle/readData(ofLength:)'' as part of its implementation.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> read_data_to_end_of_file_and_return_error() const;
        /**
     * @brief Calls `-[NSFileHandle readDataUpToLength:error:]`.
     * @details Reads data synchronously up to the specified number of bytes. - Parameters: - length: The number of bytes to read from the receiver. - error: If an error occurs, upon return contains an 'NSError' object that describes the problem. - Returns: The data available through the receiver up to a maximum of 'length' bytes, or 'nil' if an error occurred. If the receiver is a file, this method returns data obtained by reading 'length' bytes starting at the current file pointer. If 'length' bytes are not available, returns as many bytes as are available. Returns an empty 'NSData' when the end of file is reached.
     * @param length Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> read_data_up_to_length(std::uint64_t length) const;
        /**
     * @brief Calls `-[NSFileHandle readInBackgroundAndNotify]`.
     * @details Reads from the file or communications channel in the background and posts a notification when finished. This method performs an asynchronous ''FileHandle/availableData'' operation on a file or communications channel and posts an ''FileHandle/readCompletionNotification''. You must call this method from a thread that has an active run loop.
     */
        void read_in_background_and_notify() const;
        /**
     * @brief Calls `-[NSFileHandle readInBackgroundAndNotifyForModes:]`.
     * @details Reads from the file or communications channel in the background and posts a notification when finished. - Parameter modes: The runloop modes in which the read completion notification can be posted. See ''FileHandle/readInBackgroundAndNotify()'' for details. This method differs in that the notification is queued for posting in the specified run-loop modes.
     * @param modes Argument converted to the Objective-C parameter of the same role.
     */
        void read_in_background_and_notify_for_modes(const std::vector<std::string>& modes) const;
        /**
     * @brief Calls `-[NSFileHandle readToEndOfFileInBackgroundAndNotify]`.
     * @details Reads to the end of file from the file or communications channel in the background and posts a notification when finished. This method performs an asynchronous ''FileHandle/readDataToEndOfFile()'' operation on a file or communications channel and posts an 'NSFileHandleReadToEndOfFileCompletionNotification'. You must call this method from a thread that has an active run loop.
     */
        void read_to_end_of_file_in_background_and_notify() const;
        /**
     * @brief Calls `-[NSFileHandle readToEndOfFileInBackgroundAndNotifyForModes:]`.
     * @details Reads to the end of file from the file or communications channel in the background and posts a notification when finished. - Parameter modes: The runloop modes in which the read completion notification can be posted. See ''FileHandle/readToEndOfFileInBackgroundAndNotify()'' for details. This method differs in that the notification is queued for posting in the specified run-loop modes.
     * @param modes Argument converted to the Objective-C parameter of the same role.
     */
        void read_to_end_of_file_in_background_and_notify_for_modes(const std::vector<std::string>& modes) const;
        /**
     * @brief Calls `-[NSFileHandle seekToEndReturningOffset:error:]`.
     * @details Places the file pointer at the end of the file and returns the new file offset. - Parameters: - offsetInFile: On return, contains the new file offset, which is the file size. - error: If an error occurs, upon return contains an 'NSError' object that describes the problem. - Returns: 'YES' if the operation succeeded; otherwise, 'NO'.
     * @param offset_in_file Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool seek_to_end_returning_offset(std::uint64_t* offset_in_file) const;
        /**
     * @brief Calls `-[NSFileHandle seekToOffset:error:]`.
     * @details Moves the file pointer to the specified offset within the file. - Parameters: - offset: The offset to seek to. - error: If an error occurs, upon return contains an 'NSError' object that describes the problem. - Returns: 'YES' if the operation succeeded; otherwise, 'NO'.
     * @param offset Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool seek_to_offset(std::uint64_t offset) const;
        /**
     * @brief Calls `-[NSFileHandle synchronizeAndReturnError:]`.
     * @details Causes all in-memory data and attributes of the file represented by the file handle to write to permanent storage. This method should be invoked by programs that require the file to be in a known state. Invocation of this method does not return until memory is flushed.
     * @return The converted Objective-C result.
     */
        bool synchronize_and_return_error() const;
        /**
     * @brief Calls `-[NSFileHandle truncateAtOffset:error:]`.
     * @details Truncates or extends the file represented by the file handle to a specified offset within the file and puts the file pointer at that position. - Parameters: - offset: The offset within the file that will mark the new end of the file. - error: If an error occurs, upon return contains an 'NSError' object that describes the problem. - Returns: 'YES' if the operation succeeded; otherwise, 'NO'. If the file is extended (if 'offset' is beyond the current end of file), the added characters are null bytes.
     * @param offset Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool truncate_at_offset(std::uint64_t offset) const;
        /**
     * @brief Calls `-[NSFileHandle waitForDataInBackgroundAndNotify]`.
     * @details Asynchronously checks to see if data is available. When the data becomes available, this method posts a ''FileHandle/dataAvailableNotification'' notification on the current thread. You must call this method from a thread that has an active run loop.
     */
        void wait_for_data_in_background_and_notify() const;
        /**
     * @brief Calls `-[NSFileHandle waitForDataInBackgroundAndNotifyForModes:]`.
     * @details Asynchronously checks to see if data is available. - Parameter modes: The runloop modes in which the data available notification can be posted. See ''FileHandle/waitForDataInBackgroundAndNotify()'' for details. This method differs in that the notification is queued for posting in the specified run-loop modes.
     * @param modes Argument converted to the Objective-C parameter of the same role.
     */
        void wait_for_data_in_background_and_notify_for_modes(const std::vector<std::string>& modes) const;
        /**
     * @brief Calls `-[NSFileHandle writeData:error:]`.
     * @details Writes the specified data synchronously to the file handle. - Parameters: - data: The data to write. - error: If an error occurs, upon return contains an 'NSError' object that describes the problem. - Returns: 'YES' if the data was written successfully; otherwise, 'NO'. This method writes data at the current file pointer, advancing the file pointer.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool write_data(const std::vector<std::uint8_t>& data) const;
        /**
     * @brief Returns the `availableData` property of `NSFileHandle`.
     * @details The data currently available in the receiver. If the receiver is a file, returns the data obtained by reading the file from the current file pointer to the end of the file. If the receiver is a communications channel, reads up to a buffer of data and returns it; if no data is available, the method blocks. Returns an empty data object if the end of file has been reached. Raises ''NSExceptionName/fileHandleOperationException'' upon failure.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> available_data() const;
        /**
     * @brief Returns the `fileDescriptor` property of `NSFileHandle`.
     * @details The POSIX file descriptor associated with the receiver. You can use this property to get the file descriptor while it is open. If the file handle object owns the file descriptor, you must not close it yourself. However, you can use the ''FileHandle/close()'' method to close the file handle, which also closes the file descriptor. If the receiver is not the owner of the file descriptor, closing the file descriptor while the file handle is still associated with it raises ''NSExceptionName/fileHandleOperationException''.
     * @return The converted Objective-C result.
     */
        int file_descriptor() const;
        /**
     * @brief Returns the `fileHandleWithNullDevice` property of `NSFileHandle`.
     * @details The file handle associated with a null device. You can use the returned file handle as a "stand in" for standard file handles. Reads from the null-device file handle return an empty ''NSData'' object. Writes to it are discarded. The ''FileHandle/fileDescriptor'' property returns an illegal value. The ''FileHandle/close()'' method has no effect.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_with_null_device();
        /**
     * @brief Returns the `fileHandleWithStandardError` property of `NSFileHandle`.
     * @details The file handle associated with the standard error file. Conventionally this is a terminal device to which error messages are sent. There is one standard error file handle per process; it is a shared instance.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_with_standard_error();
        /**
     * @brief Returns the `fileHandleWithStandardInput` property of `NSFileHandle`.
     * @details The file handle associated with the standard input file. Conventionally this is a terminal device on which the user enters a stream of data. There is one standard input file handle per process; it is a shared instance.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_with_standard_input();
        /**
     * @brief Returns the `fileHandleWithStandardOutput` property of `NSFileHandle`.
     * @details The file handle associated with the standard output file. Conventionally this is a terminal device that receives a stream of data from a program. There is one standard output file handle per process; it is a shared instance.
     * @return The converted Objective-C result.
     */
        static FileHandle file_handle_with_standard_output();
        /**
     * @brief Returns the `readabilityHandler` property of `NSFileHandle`.
     * @details The block to use for reading the contents of the file handle asynchronously. The default value is 'nil'. To read data asynchronously, assign a non-nil block. Doing so creates a dispatch source for the associated file descriptor and submits the block to that source when data arrives. Set to 'nil' to stop reading.
     * @return The converted Objective-C result.
     */
        std::function<void(FileHandle)> readability_handler() const;
        /**
     * @brief Sets the `readabilityHandler` property of `NSFileHandle`.
     * @details The block to use for reading the contents of the file handle asynchronously. The default value is 'nil'. To read data asynchronously, assign a non-nil block. Doing so creates a dispatch source for the associated file descriptor and submits the block to that source when data arrives. Set to 'nil' to stop reading.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_readability_handler(std::function<void(FileHandle)> value) const;
        /**
     * @brief Returns the `writeabilityHandler` property of `NSFileHandle`.
     * @details The block to use for writing the contents of the file handle asynchronously. The default value is 'nil'. To write data asynchronously, assign a non-nil block. Doing so creates a dispatch source for the associated file descriptor and submits the block when the file handle has room for data. Set to 'nil' to stop.
     * @return The converted Objective-C result.
     */
        std::function<void(FileHandle)> writeability_handler() const;
        /**
     * @brief Sets the `writeabilityHandler` property of `NSFileHandle`.
     * @details The block to use for writing the contents of the file handle asynchronously. The default value is 'nil'. To write data asynchronously, assign a non-nil block. Doing so creates a dispatch source for the associated file descriptor and submits the block when the file handle has room for data. Set to 'nil' to stop.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_writeability_handler(std::function<void(FileHandle)> value) const;
    };
}
