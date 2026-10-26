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
         * @details Base unit - seconds
         * @return The converted Objective-C result.
         */
        static UnitDuration hours();
        /**
         * @brief Returns the `microseconds` property of `NSUnitDuration`.
         * @return The converted Objective-C result.
         */
        static UnitDuration microseconds();
        /**
         * @brief Returns the `milliseconds` property of `NSUnitDuration`.
         * @return The converted Objective-C result.
         */
        static UnitDuration milliseconds();
        /**
         * @brief Returns the `minutes` property of `NSUnitDuration`.
         * @return The converted Objective-C result.
         */
        static UnitDuration minutes();
        /**
         * @brief Returns the `nanoseconds` property of `NSUnitDuration`.
         * @return The converted Objective-C result.
         */
        static UnitDuration nanoseconds();
        /**
         * @brief Returns the `picoseconds` property of `NSUnitDuration`.
         * @return The converted Objective-C result.
         */
        static UnitDuration picoseconds();
        /**
         * @brief Returns the `seconds` property of `NSUnitDuration`.
         * @return The converted Objective-C result.
         */
        static UnitDuration seconds();
    };
}
