#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSDecimalNumberHandler` (Foundation).
     * @details A class for defining common behaviors
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DecimalNumberHandler decimal_number_handler;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdecimalnumberhandler
     */
    class DecimalNumberHandler : public Object
    {
    public:
        /// @brief Creates a new `NSDecimalNumberHandler` instance and returns a handle to it.
        explicit DecimalNumberHandler(RoundingMode rounding_mode, std::int16_t scale, bool exact, bool overflow, bool underflow, bool divide_by_zero);
        /// @brief Creates a new `NSDecimalNumberHandler` instance and returns a handle to it.
        explicit DecimalNumberHandler();
        /// @brief Creates a null handle that refers to no native object.
        DecimalNumberHandler(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DecimalNumberHandler(Adopt adopt);
        /**
         * @brief Returns the `defaultDecimalNumberHandler` property of `NSDecimalNumberHandler`.
         * @return The converted Objective-C result.
         */
        static DecimalNumberHandler default_decimal_number_handler();
    };
}
