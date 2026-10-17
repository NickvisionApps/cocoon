#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSSimpleCString` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SimpleCString simple_c_string;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nssimplecstring
     */
    class SimpleCString : public Object
    {
    public:
        /// @brief Creates a new `NSSimpleCString` instance and returns a handle to it.
        explicit SimpleCString();
        /// @brief Creates a null handle that refers to no native object.
        SimpleCString(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SimpleCString(Adopt adopt);
    };
}
