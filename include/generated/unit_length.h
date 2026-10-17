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
     * @details A unit of measure for length. You typically use instances of ''UnitLength'' to represent specific quantities of length using the ''NSMeasurement'' class. \#\#\# Length Length is the dimensional extent of matter. The SI unit for length is the meter (m), which is defined in terms of the distance traveled by light in a vacuum. The ''UnitLength'' class defines its ''Dimension/baseUnit()'' as ''meters'', and provides the following units, which are initialized using ''UnitConverterLinear'' converters with the specified coefficients: | Name | Method | Symbol | Coefficient | |---|---|---|---| | Megameters | ''megameters'' | Mm | '1000000.0' | | Kilometers | ''kilometers'' | kM | '1000.0' | | Hectometers | ''hectometers'' | hm | '100.0' | | Decameters | ''decameters'' | dam | '10.0' | | Meters | ''meters'' | m | '1.0' | | Decimeters | ''decimeters'' | dm | '0.1' | | Centimeters | ''centimeters'' | cm | '0.01' | | Millimeters | ''millimeters'' | mm | '0.001' | | Micrometers | ''micrometers'' | µm | '0.000001' | | Nanometers | ''nanometers'' | nm | '1e-9' | | Picometers | ''picometers'' | pm | '1e-12' | | Inches | ''inches'' | in | '0.0254' | | Feet | ''feet'' | ft | '0.3048' | | Yards | ''yards'' | yd | '0.9144' | | Miles | ''miles'' | mi | '1609.34' | | Scandinavian Miles | ''scandinavianMiles'' | smi | '10000' | | Light Years | ''lightyears'' | ly | '9.461e+15' | | Nautical Miles | ''nauticalMiles'' | NM | '1852' | | Fathoms | ''fathoms'' | ftm | '1.8288' | | Furlongs | ''furlongs'' | fur | '201.168' | | Astronomical Units | ''astronomicalUnits'' | au | '1.496e+11' | | Parsecs | ''parsecs'' | pc | '3.086e+16' |
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
     * @details The astronomical units unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength astronomical_units();
        /**
     * @brief Returns the `centimeters` property of `NSUnitLength`.
     * @details The centimeters unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength centimeters();
        /**
     * @brief Returns the `decameters` property of `NSUnitLength`.
     * @details The decameters unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength decameters();
        /**
     * @brief Returns the `decimeters` property of `NSUnitLength`.
     * @details The decimeters unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength decimeters();
        /**
     * @brief Returns the `fathoms` property of `NSUnitLength`.
     * @details The fathoms unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength fathoms();
        /**
     * @brief Returns the `feet` property of `NSUnitLength`.
     * @details The feet unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength feet();
        /**
     * @brief Returns the `furlongs` property of `NSUnitLength`.
     * @details The furlongs unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength furlongs();
        /**
     * @brief Returns the `hectometers` property of `NSUnitLength`.
     * @details The hectometers unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength hectometers();
        /**
     * @brief Returns the `inches` property of `NSUnitLength`.
     * @details The inches unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength inches();
        /**
     * @brief Returns the `kilometers` property of `NSUnitLength`.
     * @details The kilometers unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength kilometers();
        /**
     * @brief Returns the `lightyears` property of `NSUnitLength`.
     * @details The lightyears unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength lightyears();
        /**
     * @brief Returns the `megameters` property of `NSUnitLength`.
     * @details The megameters unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength megameters();
        /**
     * @brief Returns the `meters` property of `NSUnitLength`.
     * @details The meters unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength meters();
        /**
     * @brief Returns the `micrometers` property of `NSUnitLength`.
     * @details The micrometers unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength micrometers();
        /**
     * @brief Returns the `miles` property of `NSUnitLength`.
     * @details The miles unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength miles();
        /**
     * @brief Returns the `millimeters` property of `NSUnitLength`.
     * @details The millimeters unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength millimeters();
        /**
     * @brief Returns the `nanometers` property of `NSUnitLength`.
     * @details The nanometers unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength nanometers();
        /**
     * @brief Returns the `nauticalMiles` property of `NSUnitLength`.
     * @details The nautical miles unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength nautical_miles();
        /**
     * @brief Returns the `parsecs` property of `NSUnitLength`.
     * @details The parsecs unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength parsecs();
        /**
     * @brief Returns the `picometers` property of `NSUnitLength`.
     * @details The picometers unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength picometers();
        /**
     * @brief Returns the `scandinavianMiles` property of `NSUnitLength`.
     * @details The Scandinavian miles unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength scandinavian_miles();
        /**
     * @brief Returns the `yards` property of `NSUnitLength`.
     * @details The yards unit of length.
     * @return The converted Objective-C result.
     */
        static UnitLength yards();
    };
}
