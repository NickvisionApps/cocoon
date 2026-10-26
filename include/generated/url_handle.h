#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSURLHandle` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLHandle url_handle;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlhandle
     */
    class URLHandle : public Object
    {
    public:
        /// @brief Creates a new `NSURLHandle` instance and returns a handle to it.
        explicit URLHandle();
        /// @brief Creates a null handle that refers to no native object.
        URLHandle(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLHandle(Adopt adopt);
    };
}
