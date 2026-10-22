#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitDispersion` (Foundation).
     * @details A unit of measure for specific quantities of dispersion. You typically use instances of ''NSUnitDispersion'' to represent specific quantities of dispersion using the ''NSMeasurement'' class. \#\#\# Dispersion Dispersion describes the amount of a constituent divided by the amount of all other constituents in a mixture. Dispersion is a dimensionless quantity that is commonly expressed in "parts-per" notation, such as "parts per million" (ppm), to describe small relative quantities. The ''NSUnitDispersion'' class defines its ''Dimension/baseUnit()'' as ''partsPerMillion''. | Name | Method | Abbreviation | |---|---|---| | Parts Per Million | ''partsPerMillion'' | ppm |
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitDispersion unit_dispersion(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitdispersion
     */
    class UnitDispersion : public Dimension
    {
    public:
        UnitDispersion();
        /// @brief Creates a null handle that refers to no native object.
        UnitDispersion(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitDispersion(Adopt adopt);
        /**
         * @brief Returns the `partsPerMillion` property of `NSUnitDispersion`.
         * @details The parts per million unit of dispersion.
         * @return The converted Objective-C result.
         */
        static UnitDispersion parts_per_million();
    };
}
