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
     * @details A unit of measure for electric resistance. You typically use instances of ''NSUnitElectricResistance'' to represent specific quantities of electric resistance using the ''NSMeasurement'' class. \#\#\# Electric Resistance Electric resistance is the difficulty of passing an electric current through a conductor. The SI unit for electric resistance is the ohm (Ω), which is derived as the electric resistance that produces one ampere of current between two points in conductor with one volt of electric potential difference (1Ω = 1V/1A). The ''NSUnitElectricResistance'' class defines its ''Dimension/baseUnit()'' as ''ohms'', and provides the following units, which are initialized using ''UnitConverterLinear'' converters with the specified coefficients: | Name | Method | Symbol | Coefficient | |---|---|---|---| | Megaohms | ''megaohms'' | MΩ | '1000000.0' | | Kiloohms | ''kiloohms'' | kΩ | '1000.0' | | Ohms | ''ohms'' | Ω | '1.0' | | Milliohms | ''milliohms'' | mΩ | '0.001' | | Microohms | ''microohms'' | µΩ | '0.000001' |
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
         * @details The kiloohms unit of electric resistance.
         * @return The converted Objective-C result.
         */
        static UnitElectricResistance kiloohms();
        /**
         * @brief Returns the `megaohms` property of `NSUnitElectricResistance`.
         * @details The megaohms unit of electric resistance.
         * @return The converted Objective-C result.
         */
        static UnitElectricResistance megaohms();
        /**
         * @brief Returns the `microohms` property of `NSUnitElectricResistance`.
         * @details The microohms unit of electric resistance.
         * @return The converted Objective-C result.
         */
        static UnitElectricResistance microohms();
        /**
         * @brief Returns the `milliohms` property of `NSUnitElectricResistance`.
         * @details The milliohms unit of electric resistance.
         * @return The converted Objective-C result.
         */
        static UnitElectricResistance milliohms();
        /**
         * @brief Returns the `ohms` property of `NSUnitElectricResistance`.
         * @details The ohms unit of electric resistance.
         * @return The converted Objective-C result.
         */
        static UnitElectricResistance ohms();
    };
}
