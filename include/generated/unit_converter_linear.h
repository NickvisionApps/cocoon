#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/unit_converter.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitConverterLinear` (Foundation).
     * @details A description of how to convert between units using a linear equation. A linear equation for unit conversion takes the form 'y = mx + b', such that the following is true: - 'y' is the value in terms of the base unit of the dimension. - 'm' is the known coefficient to use for this unit's conversion. - 'x' is the value in terms of the unit on which you call this method. - 'b' is the known constant to use for this unit's conversion. The 'baseUnitValueFromValue:' method performs the conversion in the form of 'y = mx + b', where 'x' represents the value passed in and 'y' represents the value returned. The 'valueFromBaseUnitValue:' method performs the inverse conversion in the form of 'x = (y - b) / m', where 'y' represents the value passed in and 'x' represents the value returned. For example, consider the ''UnitTemperature/fahrenheit'' unit that ''UnitTemperature'' defines. The ''UnitConverter/baseUnitValue(fromValue:)'' method calculates the value in the base unit, ''UnitTemperature/kelvin'', using the formula 'K = (0.55555555555556) × °F + 255.37222222222427'. The ''UnitConverter/value(fromBaseUnitValue:)'' method calculates the value in ''UnitTemperature/fahrenheit'' using the formula '°F = (K — 255.37222222222427) / (0.55555555555556)', where the ''coefficient'' is '(0.55555555555556)' and the ''constant'' is '255.37222222222427'. \@TabNavigator { \@Tab("Swift") { '''swift let kelvinToFahrenheit = UnitConverterLinear(coefficient: 0.55555555555556, constant: 255.37222222222427) ''' } \@Tab("Objective-C") { '''objc NSUnitConverter kelvinToFahrenheit = [[NSUnitConverterLinear alloc] initWithCoefficient:0.55555555555556 constant:255.37222222222427]; ''' } } Units that perform conversion using only a scale factor have a ''coefficient'' equal to the scale factor and a ''constant'' equal to '0'. For example, consider the ''UnitLength/kilometers'' unit ''UnitLength'' defines. The ''UnitConverter/baseUnitValue(fromValue:)'' method calculates the value in meters using the formula 'valueInMeters = 1000 valueInKilometers + 0'. The ''UnitConverter/value(fromBaseUnitValue:)'' calculates the value in kilometers using the formula 'valueInKilometers = (valueInMeters - 0) / 1000', where the coefficient is '1000' and the constant is '0'. \@TabNavigator { \@Tab("Swift") { '''swift let kilometersToMeters = UnitConverterLinear(coefficient: 1000.0, constant: 0.0) ''' } \@Tab("Objective-C") { '''objc NSUnitConverterLinear kilometersToMeters = [[NSUnitConverterLinear alloc] initWithCoefficient:1000.0 constant:0.0]; ''' } }
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
     * @details The coefficient to use in the linear unit conversion calculation.
     * @return The converted Objective-C result.
     */
        double coefficient() const;
        /**
     * @brief Returns the `constant` property of `NSUnitConverterLinear`.
     * @details The constant to use in the linear unit conversion calculation.
     * @return The converted Objective-C result.
     */
        double constant() const;
    };
}
