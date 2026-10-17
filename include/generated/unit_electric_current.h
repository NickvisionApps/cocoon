#pragma once

#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitElectricCurrent` (Foundation).
     * @details A unit of measure for electric current. You typically use instances of ''NSUnitElectricCurrent'' to represent specific quantities of electric current using the ''NSMeasurement'' class. \#\#\# Electric Current Electric current is the flow of electric charge. The SI unit for electric current is the ampere (A), which is defined in terms the production of electromagnetic force between two parallel linear conductors. It can also be expressed as the flow of one coulomb per second (1A = 1C / s). The ''NSUnitElectricCurrent'' class defines its ''Dimension/baseUnit()'' as ''amperes'', and provides the following units, which are initialized using ''UnitConverterLinear'' converters with the specified coefficients: | Name | Method | Symbol | Coefficient | |---|---|---|---| | Megaamperes | ''megaamperes'' | MA | '1000000.0' | | Kiloamperes | ''kiloamperes'' | kA | '1000.0' | | Amperes | ''amperes'' | A | '1.0' | | Milliamperes | ''milliamperes'' | mA | '0.001' | | Microamperes | ''microamperes'' | µA | '0.000001' |
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitElectricCurrent unit_electric_current(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitelectriccurrent
     */
    class UnitElectricCurrent : public Dimension
    {
    public:
        UnitElectricCurrent();
        /// @brief Creates a null handle that refers to no native object.
        UnitElectricCurrent(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitElectricCurrent(Adopt adopt);
        /**
     * @brief Returns the `amperes` property of `NSUnitElectricCurrent`.
     * @details The amperes unit of electric current.
     * @return The converted Objective-C result.
     */
        static UnitElectricCurrent amperes();
        /**
     * @brief Returns the `kiloamperes` property of `NSUnitElectricCurrent`.
     * @details The kiloamperes unit of electric current.
     * @return The converted Objective-C result.
     */
        static UnitElectricCurrent kiloamperes();
        /**
     * @brief Returns the `megaamperes` property of `NSUnitElectricCurrent`.
     * @details The megaamperes unit of electric current.
     * @return The converted Objective-C result.
     */
        static UnitElectricCurrent megaamperes();
        /**
     * @brief Returns the `microamperes` property of `NSUnitElectricCurrent`.
     * @details The microamperes unit of electric current.
     * @return The converted Objective-C result.
     */
        static UnitElectricCurrent microamperes();
        /**
     * @brief Returns the `milliamperes` property of `NSUnitElectricCurrent`.
     * @details The milliamperes unit of electric current.
     * @return The converted Objective-C result.
     */
        static UnitElectricCurrent milliamperes();
    };
}
