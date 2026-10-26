#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/regular_expression.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSDataDetector` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref RegularExpression.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DataDetector data_detector;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdatadetector
     */
    class DataDetector : public RegularExpression
    {
    public:
        /// @brief Creates a new `NSDataDetector` instance and returns a handle to it.
        explicit DataDetector(std::uint64_t checking_types);
        /// @brief Creates a new `NSDataDetector` instance and returns a handle to it.
        explicit DataDetector();
        /// @brief Creates a null handle that refers to no native object.
        DataDetector(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DataDetector(Adopt adopt);
        /**
         * @brief Returns the `checkingTypes` property of `NSDataDetector`.
         * @return The converted Objective-C result.
         */
        std::uint64_t checking_types() const;
    };
}
