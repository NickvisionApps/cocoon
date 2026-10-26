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
         * @return The converted Objective-C result.
         */
        FileHandle file_handle_for_reading() const;
        /**
         * @brief Returns the `fileHandleForWriting` property of `NSPipe`.
         * @return The converted Objective-C result.
         */
        FileHandle file_handle_for_writing() const;
    };
}
