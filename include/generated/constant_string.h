#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/simple_c_string.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSConstantString` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref SimpleCString.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ConstantString constant_string;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsconstantstring
     */
    class ConstantString : public SimpleCString
    {
    public:
        /// @brief Creates a new `NSConstantString` instance and returns a handle to it.
        explicit ConstantString();
        /// @brief Creates a null handle that refers to no native object.
        ConstantString(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ConstantString(Adopt adopt);
    };
}
