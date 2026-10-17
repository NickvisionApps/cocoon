#pragma once

#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitIlluminance` (Foundation).
     * @details A unit of measure for illuminance. You typically use instances of ''NSUnitIlluminance'' to represent specific quantities of illuminance using the ''NSMeasurement'' class. \#\#\# Illuminance Illuminance is the luminous flux incident on a surface. The SI unit for illuminance is the lux (lx), which is derived as one lumen per square meter (1lm / 1m2). The ''NSUnitIlluminance'' class defines its ''Dimension/baseUnit()'' as ''lux''. | Name | Method | Symbol | |---|---|---| | Lux | ''lux'' | lx |
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
     * @details The lux unit of illuminance.
     * @return The converted Objective-C result.
     */
        static UnitIlluminance lux();
    };
}
