#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitAcceleration` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitAcceleration unit_acceleration(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitacceleration
     */
    class UnitAcceleration : public Dimension
    {
    public:
        UnitAcceleration();
        /// @brief Creates a null handle that refers to no native object.
        UnitAcceleration(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitAcceleration(Adopt adopt);
        /**
         * @brief Returns the `gravity` property of `NSUnitAcceleration`.
         * @return The converted Objective-C result.
         */
        static UnitAcceleration gravity();
        /**
         * @brief Returns the `metersPerSecondSquared` property of `NSUnitAcceleration`.
         * @details Base unit - metersPerSecondSquared
         * @return The converted Objective-C result.
         */
        static UnitAcceleration meters_per_second_squared();
    };
}
