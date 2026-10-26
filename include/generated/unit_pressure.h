#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitPressure` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitPressure unit_pressure(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitpressure
     */
    class UnitPressure : public Dimension
    {
    public:
        UnitPressure();
        /// @brief Creates a null handle that refers to no native object.
        UnitPressure(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitPressure(Adopt adopt);
        /**
         * @brief Returns the `bars` property of `NSUnitPressure`.
         * @return The converted Objective-C result.
         */
        static UnitPressure bars();
        /**
         * @brief Returns the `gigapascals` property of `NSUnitPressure`.
         * @return The converted Objective-C result.
         */
        static UnitPressure gigapascals();
        /**
         * @brief Returns the `hectopascals` property of `NSUnitPressure`.
         * @return The converted Objective-C result.
         */
        static UnitPressure hectopascals();
        /**
         * @brief Returns the `inchesOfMercury` property of `NSUnitPressure`.
         * @return The converted Objective-C result.
         */
        static UnitPressure inches_of_mercury();
        /**
         * @brief Returns the `kilopascals` property of `NSUnitPressure`.
         * @return The converted Objective-C result.
         */
        static UnitPressure kilopascals();
        /**
         * @brief Returns the `megapascals` property of `NSUnitPressure`.
         * @return The converted Objective-C result.
         */
        static UnitPressure megapascals();
        /**
         * @brief Returns the `millibars` property of `NSUnitPressure`.
         * @return The converted Objective-C result.
         */
        static UnitPressure millibars();
        /**
         * @brief Returns the `millimetersOfMercury` property of `NSUnitPressure`.
         * @return The converted Objective-C result.
         */
        static UnitPressure millimeters_of_mercury();
        /**
         * @brief Returns the `newtonsPerMetersSquared` property of `NSUnitPressure`.
         * @details Base unit - newtonsPerMetersSquared (equivalent to 1 pascal)
         * @return The converted Objective-C result.
         */
        static UnitPressure newtons_per_meters_squared();
        /**
         * @brief Returns the `poundsForcePerSquareInch` property of `NSUnitPressure`.
         * @return The converted Objective-C result.
         */
        static UnitPressure pounds_force_per_square_inch();
    };
}
