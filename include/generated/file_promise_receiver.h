#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class OperationQueue;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSFilePromiseReceiver` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FilePromiseReceiver file_promise_receiver;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsfilepromisereceiver
     */
    class FilePromiseReceiver : public Object
    {
    public:
        /// @brief Creates a new `NSFilePromiseReceiver` instance and returns a handle to it.
        explicit FilePromiseReceiver();
        /// @brief Creates a null handle that refers to no native object.
        FilePromiseReceiver(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FilePromiseReceiver(Adopt adopt);
        /**
     * @brief Calls `-[NSFilePromiseReceiver receivePromisedFilesAtDestination:options:operationQueue:reader:]`.
     * @details This effectively calls in the promises. Therefore, only call once you are accepting the file promise. All file promisesReceiver's in a drag must specify the same destination location. This is an array, because legacy promises are an array of files on one pasteboard item. The reader block is called on the supplied operationQueue when the promised file is ready to be read. When the source is an NSFilePromiseProvider, the readerBlock call is wrapped in an NSFileCoordination read. Otherwise, a heuristic is used to determine when the promised file is ready to be read. The options dictionary is ignored for now. Note: Writing of the promised file may be cancelled or fail. When either occurs, the readerBlock is still called, but with a non-nil NSError. When NSError is non-nil, fileURL should be ignored.
     * @param destination_dir Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param operation_queue Argument converted to the Objective-C parameter of the same role.
     * @param reader Argument converted to the Objective-C parameter of the same role.
     */
        void receive_promised_files_at_destination(const URL& destination_dir, const std::vector<std::pair<Object, Object>>& options, const OperationQueue& operation_queue, std::function<void(URL, Error)> reader) const;
        /**
     * @brief Returns the `fileNames` property of `NSFilePromiseReceiver`.
     * @details The file names of the promised files that are being written to the destination location. Note: This property returns an empty array until the file promise is called in via receivePromisedFilesAtDestination. Note: This is an array, because legacy promises are an array of files on one pasteboard item.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> file_names() const;
        /**
     * @brief Returns the `fileTypes` property of `NSFilePromiseReceiver`.
     * @details The UTI of the file types promised (Note: The count of fileTypes should tell you the number of promised files, however, that is not guaranteed. Historically, some legacy file promisers only list each unique fileType once and write one or more files per type.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> file_types() const;
        /**
     * @brief Returns the `readableDraggedTypes` property of `NSFilePromiseReceiver`.
     * @details A view must register what types it accepts via -registerForDraggedTypes:. Use this class method to get the file promise drag types that NSFilePromiseReceiver can accept, in order to register a view to accept promised files.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> readable_dragged_types();
    };
}
