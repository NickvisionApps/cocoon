#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitElectricPotentialDifference` (Foundation).
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
     * @return The converted Objective-C result.
     */
        static UnitElectricPotentialDifference kilovolts();
        /**
     * @brief Returns the `megavolts` property of `NSUnitElectricPotentialDifference`.
     * @details Base unit - volts
     * @return The converted Objective-C result.
     */
        static UnitElectricPotentialDifference megavolts();
        /**
     * @brief Returns the `microvolts` property of `NSUnitElectricPotentialDifference`.
     * @return The converted Objective-C result.
     */
        static UnitElectricPotentialDifference microvolts();
        /**
     * @brief Returns the `millivolts` property of `NSUnitElectricPotentialDifference`.
     * @return The converted Objective-C result.
     */
        static UnitElectricPotentialDifference millivolts();
        /**
     * @brief Returns the `volts` property of `NSUnitElectricPotentialDifference`.
     * @return The converted Objective-C result.
     */
        static UnitElectricPotentialDifference volts();
    };
}
