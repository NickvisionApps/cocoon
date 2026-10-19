#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitIlluminance` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitIlluminance unit_illuminance(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitilluminance
     */
    class UnitIlluminance : public Dimension
    {
    public:
        UnitIlluminance();
        /// @brief Creates a null handle that refers to no native object.
        UnitIlluminance(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitIlluminance(Adopt adopt);
        /**
     * @brief Returns the `lux` property of `NSUnitIlluminance`.
     * @details Base unit - lux
     * @return The converted Objective-C result.
     */
        static UnitIlluminance lux();
    };
}
