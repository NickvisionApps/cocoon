#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitConverter` (Foundation).
     * @details An abstract class that provides a description of how to convert a unit to and from the base unit of its dimension. For units that can be converted by a scale factor or linear equation, use the concrete subclass ''UnitConverterLinear''. \#\#\# Subclassing Notes ''NSUnitConverter'' is an abstract class that is intended for subclassing. You can implement your own subclass of ''NSUnitConverter'' to convert between units according to any desired mapping function. For example, units may be converted using a logarithmic, exponential, or quantile scale. \#\#\#\# Methods to Override All subclasses must fully implement the following methods: - ''baseUnitValue(fromValue:)'' - ''value(fromBaseUnitValue:)'' \#\#\#\# Alternatives to Subclassing As stated above, most physical units can be converted using a linear equation with ''UnitConverterLinear''. You should only create a custom subclass of ''NSUnitConverter'' for units that cannot be converted in this way.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitConverter unit_converter;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::UnitConverter unit_converter{};
     * unit_converter.base_unit_value_from_value(1);
     * unit_converter.value_from_base_unit_value(1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitconverter
     */
    class UnitConverter : public Object
    {
    public:
        /// @brief Creates a new `NSUnitConverter` instance and returns a handle to it.
        explicit UnitConverter();
        /// @brief Creates a null handle that refers to no native object.
        UnitConverter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitConverter(Adopt adopt);
        /**
     * @brief Calls `-[NSUnitConverter baseUnitValueFromValue:]`.
     * @details For a given unit, returns the specified value of that unit in terms of the base unit of its dimension. This method takes a value in a particular unit and returns the result of converting it into the base unit of that unit's dimension. For example, a converter for the miles unit calling this method, passing '1.0' to the 'value' parameter, results in '1609.34' (1 mi = 1609.34 m). \@param value Value in terms of the unit class. \@return Value in terms of the base unit.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double base_unit_value_from_value(double value) const;
        /**
     * @brief Calls `-[NSUnitConverter valueFromBaseUnitValue:]`.
     * @details For a given unit, returns the specified base unit value in terms of that unit. This method takes in a value in terms of the base unit of a unit's dimension and returns the equivalent value in terms of the unit. \@param baseUnitValue Value in terms of the base unit. \@return Value in terms of the unit class.
     * @param base_unit_value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double value_from_base_unit_value(double base_unit_value) const;
    };
}
