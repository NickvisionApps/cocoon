#pragma once

#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitElectricPotentialDifference` (Foundation).
     * @details A unit of measure for electric potential difference. You typically use instances of ''NSUnitElectricPotentialDifference'' to represent specific quantities of electric potential difference using the ''NSMeasurement'' class. \#\#\# Electric Potential Difference Electric potential difference is the amount of electric potential energy of a point charge at a point in space. The SI unit for electric potential difference is the volt (V), which is derived as the difference in electric potential energy between two points of a linear conductor when an electric current of one ampere dissipates one watt of power between those points (1V = 1W/1A). The ''NSUnitElectricPotentialDifference'' class defines its ''Dimension/baseUnit()'' as ''volts'', and provides the following units, which are initialized using ''UnitConverterLinear'' converters with the specified coefficients: | Name | Method | Symbol | Coefficient | |---|---|---|---| | Megavolts | ''megavolts'' | MV | '1000000.0' | | Kilovolts | ''kilovolts'' | kV | '1000.0' | | Volts | ''volts'' | V | '1.0' | | Millivolts | ''millivolts'' | mV | '0.001' | | Microvolts | ''microvolts'' | µV | '0.000001' |
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitElectricPotentialDifference unit_electric_potential_difference(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitelectricpotentialdifference
     */
    class UnitElectricPotentialDifference : public Dimension
    {
    public:
        UnitElectricPotentialDifference();
        /// @brief Creates a null handle that refers to no native object.
        UnitElectricPotentialDifference(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitElectricPotentialDifference(Adopt adopt);
        /**
     * @brief Returns the `kilovolts` property of `NSUnitElectricPotentialDifference`.
     * @details The kilovolts unit of electric potential difference.
     * @return The converted Objective-C result.
     */
        static UnitElectricPotentialDifference kilovolts();
        /**
     * @brief Returns the `megavolts` property of `NSUnitElectricPotentialDifference`.
     * @details The megavolts unit of electric potential difference.
     * @return The converted Objective-C result.
     */
        static UnitElectricPotentialDifference megavolts();
        /**
     * @brief Returns the `microvolts` property of `NSUnitElectricPotentialDifference`.
     * @details The microvolts unit of electric potential difference.
     * @return The converted Objective-C result.
     */
        static UnitElectricPotentialDifference microvolts();
        /**
     * @brief Returns the `millivolts` property of `NSUnitElectricPotentialDifference`.
     * @details The millivolts unit of electric potential difference.
     * @return The converted Objective-C result.
     */
        static UnitElectricPotentialDifference millivolts();
        /**
     * @brief Returns the `volts` property of `NSUnitElectricPotentialDifference`.
     * @details The volts unit of electric potential difference.
     * @return The converted Objective-C result.
     */
        static UnitElectricPotentialDifference volts();
    };
}
