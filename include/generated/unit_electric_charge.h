#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitElectricCharge` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitElectricCharge unit_electric_charge(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitelectriccharge
     */
    class UnitElectricCharge : public Dimension
    {
    public:
        UnitElectricCharge();
        /// @brief Creates a null handle that refers to no native object.
        UnitElectricCharge(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitElectricCharge(Adopt adopt);
        /**
         * @brief Returns the `ampereHours` property of `NSUnitElectricCharge`.
         * @return The converted Objective-C result.
         */
        static UnitElectricCharge ampere_hours();
        /**
         * @brief Returns the `coulombs` property of `NSUnitElectricCharge`.
         * @details Base unit - coulombs
         * @return The converted Objective-C result.
         */
        static UnitElectricCharge coulombs();
        /**
         * @brief Returns the `kiloampereHours` property of `NSUnitElectricCharge`.
         * @return The converted Objective-C result.
         */
        static UnitElectricCharge kiloampere_hours();
        /**
         * @brief Returns the `megaampereHours` property of `NSUnitElectricCharge`.
         * @return The converted Objective-C result.
         */
        static UnitElectricCharge megaampere_hours();
        /**
         * @brief Returns the `microampereHours` property of `NSUnitElectricCharge`.
         * @return The converted Objective-C result.
         */
        static UnitElectricCharge microampere_hours();
        /**
         * @brief Returns the `milliampereHours` property of `NSUnitElectricCharge`.
         * @return The converted Objective-C result.
         */
        static UnitElectricCharge milliampere_hours();
    };
}
