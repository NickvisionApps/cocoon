#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitEnergy` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitEnergy unit_energy(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitenergy
     */
    class UnitEnergy : public Dimension
    {
    public:
        UnitEnergy();
        /// @brief Creates a null handle that refers to no native object.
        UnitEnergy(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitEnergy(Adopt adopt);
        /**
     * @brief Returns the `calories` property of `NSUnitEnergy`.
     * @return The converted Objective-C result.
     */
        static UnitEnergy calories();
        /**
     * @brief Returns the `joules` property of `NSUnitEnergy`.
     * @return The converted Objective-C result.
     */
        static UnitEnergy joules();
        /**
     * @brief Returns the `kilocalories` property of `NSUnitEnergy`.
     * @return The converted Objective-C result.
     */
        static UnitEnergy kilocalories();
        /**
     * @brief Returns the `kilojoules` property of `NSUnitEnergy`.
     * @details Base unit - joules
     * @return The converted Objective-C result.
     */
        static UnitEnergy kilojoules();
        /**
     * @brief Returns the `kilowattHours` property of `NSUnitEnergy`.
     * @return The converted Objective-C result.
     */
        static UnitEnergy kilowatt_hours();
    };
}
