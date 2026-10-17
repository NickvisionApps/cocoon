#pragma once

#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitElectricCharge` (Foundation).
     * @details A unit of measure for electric charge. You typically use instances of ''NSUnitElectricCharge'' to represent specific quantities of electric charge using the ''NSMeasurement'' class. \#\#\# Electric Charge Electric charge is a fundamental physical property of matter that causes it to experience a force within an electromagnetic field. The SI unit for electric charge is the coulomb (C), which is defined as the amount of charge carried by a current of one ampere in one second (1C = 1A · 1s). Charge is also commonly expressed in terms of ampere hours (Ah). The ''NSUnitElectricCharge'' class defines its ''Dimension/baseUnit()'' as ''coulombs'', and provides the following units, which are initialized using ''UnitConverterLinear'' converters with the specified coefficients: | Name | Method | Symbol | Coefficient | |---|---|---|---| | Coulombs | ''coulombs'' | C | '1.0' | | Megaampere Hours | ''megaampereHours'' | MAh | '3.6e9' | | Kiloampere Hours | ''kiloampereHours'' | kAh | '3600000.0' | | Ampere Hours | ''ampereHours'' | Ah | '3600.0' | | Milliampere Hours | ''milliampereHours'' | mAh | '3.6' | | Microampere Hours | ''microampereHours'' | µAh | '0.0036' |
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
     * @details The ampere hours unit of electric charge.
     * @return The converted Objective-C result.
     */
        static UnitElectricCharge ampere_hours();
        /**
     * @brief Returns the `coulombs` property of `NSUnitElectricCharge`.
     * @details The coulombs unit of electric charge.
     * @return The converted Objective-C result.
     */
        static UnitElectricCharge coulombs();
        /**
     * @brief Returns the `kiloampereHours` property of `NSUnitElectricCharge`.
     * @details The kiloampere hours unit of electric charge.
     * @return The converted Objective-C result.
     */
        static UnitElectricCharge kiloampere_hours();
        /**
     * @brief Returns the `megaampereHours` property of `NSUnitElectricCharge`.
     * @details The megaampere hours unit of electric charge.
     * @return The converted Objective-C result.
     */
        static UnitElectricCharge megaampere_hours();
        /**
     * @brief Returns the `microampereHours` property of `NSUnitElectricCharge`.
     * @details The microampere hours unit of electric charge.
     * @return The converted Objective-C result.
     */
        static UnitElectricCharge microampere_hours();
        /**
     * @brief Returns the `milliampereHours` property of `NSUnitElectricCharge`.
     * @details The milliampere hours unit of electric charge.
     * @return The converted Objective-C result.
     */
        static UnitElectricCharge milliampere_hours();
    };
}
