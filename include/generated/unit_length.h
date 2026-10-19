#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitLength` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitLength unit_length(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitlength
     */
    class UnitLength : public Dimension
    {
    public:
        UnitLength();
        /// @brief Creates a null handle that refers to no native object.
        UnitLength(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitLength(Adopt adopt);
        /**
     * @brief Returns the `astronomicalUnits` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength astronomical_units();
        /**
     * @brief Returns the `centimeters` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength centimeters();
        /**
     * @brief Returns the `decameters` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength decameters();
        /**
     * @brief Returns the `decimeters` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength decimeters();
        /**
     * @brief Returns the `fathoms` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength fathoms();
        /**
     * @brief Returns the `feet` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength feet();
        /**
     * @brief Returns the `furlongs` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength furlongs();
        /**
     * @brief Returns the `hectometers` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength hectometers();
        /**
     * @brief Returns the `inches` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength inches();
        /**
     * @brief Returns the `kilometers` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength kilometers();
        /**
     * @brief Returns the `lightyears` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength lightyears();
        /**
     * @brief Returns the `megameters` property of `NSUnitLength`.
     * @details Base unit - meters
     * @return The converted Objective-C result.
     */
        static UnitLength megameters();
        /**
     * @brief Returns the `meters` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength meters();
        /**
     * @brief Returns the `micrometers` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength micrometers();
        /**
     * @brief Returns the `miles` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength miles();
        /**
     * @brief Returns the `millimeters` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength millimeters();
        /**
     * @brief Returns the `nanometers` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength nanometers();
        /**
     * @brief Returns the `nauticalMiles` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength nautical_miles();
        /**
     * @brief Returns the `parsecs` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength parsecs();
        /**
     * @brief Returns the `picometers` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength picometers();
        /**
     * @brief Returns the `scandinavianMiles` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength scandinavian_miles();
        /**
     * @brief Returns the `yards` property of `NSUnitLength`.
     * @return The converted Objective-C result.
     */
        static UnitLength yards();
    };
}
