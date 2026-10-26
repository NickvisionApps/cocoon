#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSNull` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Null null;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsnull
     */
    class Null : public Object
    {
    public:
        /// @brief Creates a new `NSNull` instance and returns a handle to it.
        explicit Null();
        /// @brief Creates a null handle that refers to no native object.
        Null(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Null(Adopt adopt);
    };
}
