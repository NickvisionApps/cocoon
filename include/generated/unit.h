#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnit` (Foundation).
     * @details An abstract class representing a unit of measure. Each instance of an ''Unit'' subclass consists of a ''symbol'', which can be used to create string representations of ''NSMeasurement'' objects with the ''MeasurementFormatter'' class. The ''Dimension'' subclass is an abstract class that represents a dimensional unit, which can be converted into different units of the same type. The Foundation framework provides several concrete ''Dimension'' subclasses to represent the most common physical quantities, including mass, length, duration, and speed. \#\#\# Subclassing Notes ''NSUnit'' is intended for subclassing. For dimensional units, you should use one of the Apple provided ''Dimension'' subclasses listed in Table 1 of ''Dimension'', or create a custom subclass of ''Dimension''. You can create a direct subclass of ''NSUnit'' to represent a custom dimensionless unit, such as a count, score, or ratio.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Unit unit{"text"};
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunit
     */
    class Unit : public Object
    {
    public:
        /// @brief Creates a new `NSUnit` instance and returns a handle to it.
        explicit Unit(const std::string& symbol);
        Unit();
        /// @brief Creates a null handle that refers to no native object.
        Unit(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Unit(Adopt adopt);
        /**
     * @brief Returns the `symbol` property of `NSUnit`.
     * @details The symbolic representation of the unit. The symbol of a unit is a string that can be used to designate a number as a quantity of a particular unit in user-readable representations. Units typically have symbols that are abbreviated and standardized, so as to be easily and unambiguously conveyed. For example, the 'milePerHour' unit has the symbol 'mph'. If a unit does not have a standardized or well-understood symbol, the lowercase name of the unit can be used. For example, the 'metricCup' unit has the symbol 'metric cup'. Unit symbols may incorporate a metric prefix to indicate a multiple or fraction of existing unit symbols. For example, the 'kilogram' unit has the symbol 'kg', which uses the SI prefix k for kilo- to indicate a magnitude of 10^3 for the 'gram' unit, and the 'microgram' unit has the symbol 'µg', which uses the SI prefix µ for micro- to indicate a magnitude of 10^-6 for the 'gram' unit.
     * @return The converted Objective-C result.
     */
        std::string symbol() const;
    };
}
