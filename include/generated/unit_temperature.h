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
         * @return The converted Objective-C result.
         */
        static UnitTemperature celsius();
        /**
         * @brief Returns the `fahrenheit` property of `NSUnitTemperature`.
         * @return The converted Objective-C result.
         */
        static UnitTemperature fahrenheit();
        /**
         * @brief Returns the `kelvin` property of `NSUnitTemperature`.
         * @details Base unit - kelvin
         * @return The converted Objective-C result.
         */
        static UnitTemperature kelvin();
    };
}
