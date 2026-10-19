#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitVolume` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitVolume unit_volume(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitvolume
     */
    class UnitVolume : public Dimension
    {
    public:
        UnitVolume();
        /// @brief Creates a null handle that refers to no native object.
        UnitVolume(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitVolume(Adopt adopt);
        /**
     * @brief Returns the `acreFeet` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume acre_feet();
        /**
     * @brief Returns the `bushels` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume bushels();
        /**
     * @brief Returns the `centiliters` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume centiliters();
        /**
     * @brief Returns the `cubicCentimeters` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_centimeters();
        /**
     * @brief Returns the `cubicDecimeters` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_decimeters();
        /**
     * @brief Returns the `cubicFeet` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_feet();
        /**
     * @brief Returns the `cubicInches` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_inches();
        /**
     * @brief Returns the `cubicKilometers` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_kilometers();
        /**
     * @brief Returns the `cubicMeters` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_meters();
        /**
     * @brief Returns the `cubicMiles` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_miles();
        /**
     * @brief Returns the `cubicMillimeters` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_millimeters();
        /**
     * @brief Returns the `cubicYards` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_yards();
        /**
     * @brief Returns the `cups` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume cups();
        /**
     * @brief Returns the `deciliters` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume deciliters();
        /**
     * @brief Returns the `fluidOunces` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume fluid_ounces();
        /**
     * @brief Returns the `gallons` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume gallons();
        /**
     * @brief Returns the `imperialFluidOunces` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume imperial_fluid_ounces();
        /**
     * @brief Returns the `imperialGallons` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume imperial_gallons();
        /**
     * @brief Returns the `imperialPints` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume imperial_pints();
        /**
     * @brief Returns the `imperialQuarts` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume imperial_quarts();
        /**
     * @brief Returns the `imperialTablespoons` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume imperial_tablespoons();
        /**
     * @brief Returns the `imperialTeaspoons` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume imperial_teaspoons();
        /**
     * @brief Returns the `kiloliters` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume kiloliters();
        /**
     * @brief Returns the `liters` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume liters();
        /**
     * @brief Returns the `megaliters` property of `NSUnitVolume`.
     * @details Base unit - liters
     * @return The converted Objective-C result.
     */
        static UnitVolume megaliters();
        /**
     * @brief Returns the `metricCups` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume metric_cups();
        /**
     * @brief Returns the `milliliters` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume milliliters();
        /**
     * @brief Returns the `pints` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume pints();
        /**
     * @brief Returns the `quarts` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume quarts();
        /**
     * @brief Returns the `tablespoons` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume tablespoons();
        /**
     * @brief Returns the `teaspoons` property of `NSUnitVolume`.
     * @return The converted Objective-C result.
     */
        static UnitVolume teaspoons();
    };
}
