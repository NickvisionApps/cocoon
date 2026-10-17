#pragma once

#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitSpeed` (Foundation).
     * @details A unit of measure for speed. You typically use instances of ''NSUnitSpeed'' to represent specific quantities of speed using the ''NSMeasurement'' class. \#\#\# Speed Speed is the magnitude of velocity, or the rate of change of position. Speed can be expressed by SI derived units in terms of meters per second (m/s), and is also commonly expressed in terms of kilometers per hour (km/h) and miles per hour (mph). The ''NSUnitSpeed'' class defines its ''Dimension/baseUnit()'' as ''metersPerSecond'', and provides the following units, which are initialized using ''UnitConverterLinear'' converters with the specified coefficients: | Name | Method | Symbol | Coefficient | |---|---|---|---| | Meters Per Second | ''metersPerSecond'' | m/s | '1.0' | | Kilometers Per Hour | ''kilometersPerHour'' | km/h | '0.277778' | | Miles Per Hour | ''milesPerHour'' | mph | '0.44704' | | Knots | ''knots'' | kn | '0.514444' | The base unit is ''metersPerSecond'' and is accessed via ''NSDimension/baseUnit'' on the ''NSDimension'' protocol.
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
     * @details The kilometers per hour unit of speed.
     * @return The converted Objective-C result.
     */
        static UnitSpeed kilometers_per_hour();
        /**
     * @brief Returns the `knots` property of `NSUnitSpeed`.
     * @details The knots unit of speed.
     * @return The converted Objective-C result.
     */
        static UnitSpeed knots();
        /**
     * @brief Returns the `metersPerSecond` property of `NSUnitSpeed`.
     * @details The meters per second unit of speed.
     * @return The converted Objective-C result.
     */
        static UnitSpeed meters_per_second();
        /**
     * @brief Returns the `milesPerHour` property of `NSUnitSpeed`.
     * @details The miles per hour unit of speed.
     * @return The converted Objective-C result.
     */
        static UnitSpeed miles_per_hour();
    };
}
