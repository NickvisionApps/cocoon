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
     * @details NSUnitConverter describes how to convert a unit to and from the base unit of its dimension. Subclass NSUnitConverter to implement new ways of converting a unit.
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
     * @details This method takes a value in terms of a unit and returns the corresponding value in terms of the base unit of the original unit's dimension. \@param value Value in terms of the unit class \@return Value in terms of the base unit
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double base_unit_value_from_value(double value) const;
        /**
     * @brief Calls `-[NSUnitConverter valueFromBaseUnitValue:]`.
     * @details This method takes in a value in terms of the base unit of a unit's dimension and returns the equivalent value in terms of the unit. \@param baseUnitValue Value in terms of the base unit \@return Value in terms of the unit class
     * @param base_unit_value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double value_from_base_unit_value(double base_unit_value) const;
    };
}
