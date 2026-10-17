#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSMovie` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Movie movie;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsmovie
     */
    class Movie : public Object
    {
    public:
        /// @brief Creates a new `NSMovie` instance and returns a handle to it.
        explicit Movie();
        /// @brief Creates a null handle that refers to no native object.
        Movie(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Movie(Adopt adopt);
    };
}
