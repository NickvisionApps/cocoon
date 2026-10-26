#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/unit_converter.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitConverterLinear` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref UnitConverter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitConverterLinear unit_converter_linear;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitconverterlinear
     */
    class UnitConverterLinear : public UnitConverter
    {
    public:
        /// @brief Creates a new `NSUnitConverterLinear` instance and returns a handle to it.
        explicit UnitConverterLinear(double coefficient);
        /// @brief Creates a new `NSUnitConverterLinear` instance and returns a handle to it.
        explicit UnitConverterLinear(double coefficient, double constant);
        /// @brief Creates a new `NSUnitConverterLinear` instance and returns a handle to it.
        explicit UnitConverterLinear();
        /// @brief Creates a null handle that refers to no native object.
        UnitConverterLinear(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitConverterLinear(Adopt adopt);
        /**
         * @brief Returns the `coefficient` property of `NSUnitConverterLinear`.
         * @details For units that require linear conversion, the methods perform calculations in the form of y = ax + b, where - x is the value in terms of the unit on which this method is called - y is the value in terms of the base unit of the dimension - a is the known coefficient used for this unit's conversion - b is the known constant used for this unit's conversion baseUnitValueFromValue: performs the conversion in the form of y = ax + b, where x represents the value passed in and y represents the value returned. valueFromBaseUnitValue: performs the inverse conversion in the form of x = (y + (-1 b))/a, where y represents the value passed in and x represents the value returned. An example of this is NSUnitTemperature. For Celsius, baseUnitValueFromValue: calculates the value in Kelvin using the formula K = 1 °C + 273.15 and valueFromBaseUnitValue: calculates the value in Celsius using the formula C° = (K + (-1 273.15))/1 where the coefficient is 1 and the constant is 273.15. For units that only require conversion by scale factor, the coefficient is the scale factor and the constant is always 0. baseUnitValueFromValue: calculates the value in meters using the formula valueInMeters = 1000 valueInKilometers + 0 and valueFromBaseUnitValue: calculates the value in kilometers using the formula valueInKilometers = valueInMeters / 1000 where the coefficient is 1000 and the constant is 0. This API provides a convenience initializer initWithCoefficient: that assumes the constant is 0.
         * @return The converted Objective-C result.
         */
        double coefficient() const;
        /**
         * @brief Returns the `constant` property of `NSUnitConverterLinear`.
         * @return The converted Objective-C result.
         */
        double constant() const;
    };
}
