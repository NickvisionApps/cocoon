#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitTemperature` (Foundation).
     * @details A unit of measure for temperature. You typically use instances of ''NSUnitTemperature'' to represent specific quantities of temperature using the ''NSMeasurement'' class. \#\#\# Temperature Temperature is a comparative measure of thermal energy. The SI unit for temperature is the kelvin (K), which is defined in terms of the triple point of water. Temperature is also commonly measured by degrees of various scales, including Celsius (°C) and Fahrenheit (°F). The ''NSUnitTemperature'' class defines its ''Dimension/baseUnit()'' to be ''kelvin'', and provides the following units, which are initialized using ''UnitConverterLinear'' converters with the specified coefficients and constants: | Name | Method | Symbol | Coefficient | Constant | |---|---|---|---|---| | Kelvin | ''kelvin'' | K | '1' | '0' | | Degree Celsius | ''celsius'' | °C | '1.0' | '273.15' | | Degree Fahrenheit | ''fahrenheit'' | °F | '0.55555555555556' | '255.37222222222427' |
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitTemperature unit_temperature(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunittemperature
     */
    class UnitTemperature : public Dimension
    {
    public:
        UnitTemperature();
        /// @brief Creates a null handle that refers to no native object.
        UnitTemperature(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitTemperature(Adopt adopt);
        /**
         * @brief Returns the `celsius` property of `NSUnitTemperature`.
         * @details The degrees Celsius unit of temperature.
         * @return The converted Objective-C result.
         */
        static UnitTemperature celsius();
        /**
         * @brief Returns the `fahrenheit` property of `NSUnitTemperature`.
         * @details The degrees Fahrenheit unit of temperature.
         * @return The converted Objective-C result.
         */
        static UnitTemperature fahrenheit();
        /**
         * @brief Returns the `kelvin` property of `NSUnitTemperature`.
         * @details The kelvin unit of temperature.
         * @return The converted Objective-C result.
         */
        static UnitTemperature kelvin();
    };
}
