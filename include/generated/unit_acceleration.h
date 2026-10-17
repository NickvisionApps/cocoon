#pragma once

#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitAcceleration` (Foundation).
     * @details A unit of measure for acceleration. You typically use instances of ''NSUnitAcceleration'' to represent specific quantities of acceleration using the ''NSMeasurement'' class. \#\#\# Acceleration Acceleration is the rate of change of velocity. Acceleration can be expressed by SI derived units in terms of meters per second squared (m/s2). The ''NSUnitAcceleration'' class defines its ''Dimension/baseUnit()'' as ''metersPerSecondSquared'', and provides the following units, which are initialized using ''UnitConverterLinear'' converters with the specified coefficients: | Name | Method | Symbol | Coefficient | |---|---|---|---| | Meters Per Second Squared | ''metersPerSecondSquared'' | m/s² | '1.0' | | Gravity | ''gravity'' | g | '9.81' |
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
     * @details The gravity unit of acceleration.
     * @return The converted Objective-C result.
     */
        static UnitAcceleration gravity();
        /**
     * @brief Returns the `metersPerSecondSquared` property of `NSUnitAcceleration`.
     * @details The meters per second squared unit of acceleration.
     * @return The converted Objective-C result.
     */
        static UnitAcceleration meters_per_second_squared();
    };
}
