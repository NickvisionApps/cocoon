#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitElectricResistance` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitElectricResistance unit_electric_resistance(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitelectricresistance
     */
    class UnitElectricResistance : public Dimension
    {
    public:
        UnitElectricResistance();
        /// @brief Creates a null handle that refers to no native object.
        UnitElectricResistance(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitElectricResistance(Adopt adopt);
        /**
         * @brief Returns the `kiloohms` property of `NSUnitElectricResistance`.
         * @return The converted Objective-C result.
         */
        static UnitElectricResistance kiloohms();
        /**
         * @brief Returns the `megaohms` property of `NSUnitElectricResistance`.
         * @details Base unit - ohms
         * @return The converted Objective-C result.
         */
        static UnitElectricResistance megaohms();
        /**
         * @brief Returns the `microohms` property of `NSUnitElectricResistance`.
         * @return The converted Objective-C result.
         */
        static UnitElectricResistance microohms();
        /**
         * @brief Returns the `milliohms` property of `NSUnitElectricResistance`.
         * @return The converted Objective-C result.
         */
        static UnitElectricResistance milliohms();
        /**
         * @brief Returns the `ohms` property of `NSUnitElectricResistance`.
         * @return The converted Objective-C result.
         */
        static UnitElectricResistance ohms();
    };
}
