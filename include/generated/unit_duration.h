#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitDuration` (Foundation).
     * @details A unit of measure for a duration of time. You typically use instances of ''NSUnitDuration'' to represent specific quantities of planar angle using the ''NSMeasurement'' class. \#\#\# Duration Duration is a quantity of time. The SI unit for time is the second (sec), which is defined in terms of the radioactivity of a cesium-133 atom. Duration is also commonly expressed in terms of minutes (min) and hours (hr). > Note: > Use the ''NSDateComponents'' class to represent quantities of calendrical units, such as days, weeks, months, and years. The ''NSUnitDuration'' class defines its ''Dimension/baseUnit()'' as ''seconds'', and provides the following units, which ''UnitConverterLinear'' converters initialize with the given coefficients: | Name | Method | Symbol | Coefficient | |---|---|---|---| | Seconds | ''seconds'' | sec | '1' | | Minutes | ''minutes'' | min | '60' | | Hours | ''hours'' | hr | '3600' |
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitDuration unit_duration(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitduration
     */
    class UnitDuration : public Dimension
    {
    public:
        UnitDuration();
        /// @brief Creates a null handle that refers to no native object.
        UnitDuration(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitDuration(Adopt adopt);
        /**
         * @brief Returns the `hours` property of `NSUnitDuration`.
         * @details The hours unit of duration.
         * @return The converted Objective-C result.
         */
        static UnitDuration hours();
        /**
         * @brief Returns the `microseconds` property of `NSUnitDuration`.
         * @details The microseconds unit of duration.
         * @return The converted Objective-C result.
         */
        static UnitDuration microseconds();
        /**
         * @brief Returns the `milliseconds` property of `NSUnitDuration`.
         * @details The milliseconds unit of duration.
         * @return The converted Objective-C result.
         */
        static UnitDuration milliseconds();
        /**
         * @brief Returns the `minutes` property of `NSUnitDuration`.
         * @details The minutes unit of duration.
         * @return The converted Objective-C result.
         */
        static UnitDuration minutes();
        /**
         * @brief Returns the `nanoseconds` property of `NSUnitDuration`.
         * @details The nanoseconds unit of duration.
         * @return The converted Objective-C result.
         */
        static UnitDuration nanoseconds();
        /**
         * @brief Returns the `picoseconds` property of `NSUnitDuration`.
         * @details The picoseconds unit of duration.
         * @return The converted Objective-C result.
         */
        static UnitDuration picoseconds();
        /**
         * @brief Returns the `seconds` property of `NSUnitDuration`.
         * @details The seconds unit of duration.
         * @return The converted Objective-C result.
         */
        static UnitDuration seconds();
    };
}
