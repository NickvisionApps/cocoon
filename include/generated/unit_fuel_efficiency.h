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
     * @details A unit of measure for fuel efficiency. You typically use instances of ''NSUnitFuelEfficiency'' to represent specific quantities of fuel efficiency using the ''NSMeasurement'' class. \#\#\# Fuel Efficiency Fuel efficiency corresponds to the thermal efficiency of a process that converts the chemical potential energy of a fuel into kinetic energy. Fuel efficiency can be expressed by SI derived units in terms of cubic meters per meter (m3/m), but is more commonly expressed in terms of liters per kilometer (L/km) and miles per gallon (mpg). The ''NSUnitFuelEfficiency'' class defines its ''Dimension/baseUnit()'' as ''litersPer100Kilometers'', and provides the following units: | Name | Method | Symbol | |---|---|---| | Liters Per 100 Kilometers | ''litersPer100Kilometers'' | L/100km | | Miles Per Gallon | ''milesPerGallon'' | mpg | | Miles Per Imperial Gallon | ''milesPerImperialGallon'' | mpg |
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
     * @details The liters per 100 kilometers unit of fuel efficiency.
     * @return The converted Objective-C result.
     */
        static UnitFuelEfficiency liters_per100_kilometers();
        /**
     * @brief Returns the `milesPerGallon` property of `NSUnitFuelEfficiency`.
     * @details The miles per gallon unit of fuel efficiency.
     * @return The converted Objective-C result.
     */
        static UnitFuelEfficiency miles_per_gallon();
        /**
     * @brief Returns the `milesPerImperialGallon` property of `NSUnitFuelEfficiency`.
     * @details The miles per imperial gallon unit of fuel efficiency.
     * @return The converted Objective-C result.
     */
        static UnitFuelEfficiency miles_per_imperial_gallon();
    };
}
