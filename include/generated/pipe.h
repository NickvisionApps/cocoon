#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class FileHandle;

    /**
     * @brief C++ handle for the Objective-C class `NSPipe` (Foundation).
     * @details A one-way communications channel between related processes. ''Pipe'' objects provide an object-oriented interface for accessing pipes. An ''Pipe'' object represents both ends of a pipe and enables communication through the pipe. A pipe is a one-way communications channel between related processes; one process writes data, while the other process reads that data. The data that passes through the pipe is buffered; the size of the buffer is determined by the underlying operating system. ''Pipe'' is an abstract class, the public interface of a class cluster.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Pipe pipe;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nspipe
     */
    class Pipe : public Object
    {
    public:
        /// @brief Creates a new `NSPipe` instance and returns a handle to it.
        explicit Pipe();
        /// @brief Creates a null handle that refers to no native object.
        Pipe(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Pipe(Adopt adopt);
        /**
         * @brief Returns the `fileHandleForReading` property of `NSPipe`.
         * @details The receiver's read file handle.
         * @return The converted Objective-C result.
         */
        FileHandle file_handle_for_reading() const;
        /**
         * @brief Returns the `fileHandleForWriting` property of `NSPipe`.
         * @details The receiver's write file handle.
         * @return The converted Objective-C result.
         */
        FileHandle file_handle_for_writing() const;
    };
}
