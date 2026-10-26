#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitSpeed` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitSpeed unit_speed(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitspeed
     */
    class UnitSpeed : public Dimension
    {
    public:
        UnitSpeed();
        /// @brief Creates a null handle that refers to no native object.
        UnitSpeed(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitSpeed(Adopt adopt);
        /**
         * @brief Returns the `kilometersPerHour` property of `NSUnitSpeed`.
         * @return The converted Objective-C result.
         */
        static UnitSpeed kilometers_per_hour();
        /**
         * @brief Returns the `knots` property of `NSUnitSpeed`.
         * @return The converted Objective-C result.
         */
        static UnitSpeed knots();
        /**
         * @brief Returns the `metersPerSecond` property of `NSUnitSpeed`.
         * @details Base unit - metersPerSecond
         * @return The converted Objective-C result.
         */
        static UnitSpeed meters_per_second();
        /**
         * @brief Returns the `milesPerHour` property of `NSUnitSpeed`.
         * @return The converted Objective-C result.
         */
        static UnitSpeed miles_per_hour();
    };
}
