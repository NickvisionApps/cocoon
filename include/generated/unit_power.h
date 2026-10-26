#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitPower` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitPower unit_power(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitpower
     */
    class UnitPower : public Dimension
    {
    public:
        UnitPower();
        /// @brief Creates a null handle that refers to no native object.
        UnitPower(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitPower(Adopt adopt);
        /**
         * @brief Returns the `femtowatts` property of `NSUnitPower`.
         * @return The converted Objective-C result.
         */
        static UnitPower femtowatts();
        /**
         * @brief Returns the `gigawatts` property of `NSUnitPower`.
         * @return The converted Objective-C result.
         */
        static UnitPower gigawatts();
        /**
         * @brief Returns the `horsepower` property of `NSUnitPower`.
         * @return The converted Objective-C result.
         */
        static UnitPower horsepower();
        /**
         * @brief Returns the `kilowatts` property of `NSUnitPower`.
         * @return The converted Objective-C result.
         */
        static UnitPower kilowatts();
        /**
         * @brief Returns the `megawatts` property of `NSUnitPower`.
         * @return The converted Objective-C result.
         */
        static UnitPower megawatts();
        /**
         * @brief Returns the `microwatts` property of `NSUnitPower`.
         * @return The converted Objective-C result.
         */
        static UnitPower microwatts();
        /**
         * @brief Returns the `milliwatts` property of `NSUnitPower`.
         * @return The converted Objective-C result.
         */
        static UnitPower milliwatts();
        /**
         * @brief Returns the `nanowatts` property of `NSUnitPower`.
         * @return The converted Objective-C result.
         */
        static UnitPower nanowatts();
        /**
         * @brief Returns the `picowatts` property of `NSUnitPower`.
         * @return The converted Objective-C result.
         */
        static UnitPower picowatts();
        /**
         * @brief Returns the `terawatts` property of `NSUnitPower`.
         * @details Base unit - watts
         * @return The converted Objective-C result.
         */
        static UnitPower terawatts();
        /**
         * @brief Returns the `watts` property of `NSUnitPower`.
         * @return The converted Objective-C result.
         */
        static UnitPower watts();
    };
}
