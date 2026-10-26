#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitElectricCurrent` (Foundation).
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
         * @return The converted Objective-C result.
         */
        static UnitElectricCurrent amperes();
        /**
         * @brief Returns the `kiloamperes` property of `NSUnitElectricCurrent`.
         * @return The converted Objective-C result.
         */
        static UnitElectricCurrent kiloamperes();
        /**
         * @brief Returns the `megaamperes` property of `NSUnitElectricCurrent`.
         * @details Base unit - amperes
         * @return The converted Objective-C result.
         */
        static UnitElectricCurrent megaamperes();
        /**
         * @brief Returns the `microamperes` property of `NSUnitElectricCurrent`.
         * @return The converted Objective-C result.
         */
        static UnitElectricCurrent microamperes();
        /**
         * @brief Returns the `milliamperes` property of `NSUnitElectricCurrent`.
         * @return The converted Objective-C result.
         */
        static UnitElectricCurrent milliamperes();
    };
}
