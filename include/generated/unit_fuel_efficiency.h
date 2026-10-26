#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitFuelEfficiency` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitFuelEfficiency unit_fuel_efficiency(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitfuelefficiency
     */
    class UnitFuelEfficiency : public Dimension
    {
    public:
        UnitFuelEfficiency();
        /// @brief Creates a null handle that refers to no native object.
        UnitFuelEfficiency(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitFuelEfficiency(Adopt adopt);
        /**
         * @brief Returns the `litersPer100Kilometers` property of `NSUnitFuelEfficiency`.
         * @details Base unit - litersPer100Kilometers
         * @return The converted Objective-C result.
         */
        static UnitFuelEfficiency liters_per100_kilometers();
        /**
         * @brief Returns the `milesPerGallon` property of `NSUnitFuelEfficiency`.
         * @return The converted Objective-C result.
         */
        static UnitFuelEfficiency miles_per_gallon();
        /**
         * @brief Returns the `milesPerImperialGallon` property of `NSUnitFuelEfficiency`.
         * @return The converted Objective-C result.
         */
        static UnitFuelEfficiency miles_per_imperial_gallon();
    };
}
