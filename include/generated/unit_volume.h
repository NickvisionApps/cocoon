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
     * @details A unit of measure for volume. You typically use instances of ''NSUnitVolume'' to represent specific quantities of volume using the ''NSMeasurement'' class. \#\#\# Volume Volume is a quantity of the extend of matter in three dimensions. The SI accepted unit of volume is the liter (L), which is derived as one cubic decimeter (1 dm3). Volume is also commonly expressed in terms of cubic meters (m3), gallons (gal), and cups (cup). The ''NSUnitVolume'' class defines its ''Dimension/baseUnit()'' as ''liters'', and provides the following units, which are initialized using ''UnitConverterLinear'' converters with the specified coefficients: | Name | Method | Symbol | Coefficient | |---|---|---|---| | Megaliters | ''megaliters'' | ML | '1000000.0' | | Kiloliters | ''kiloliters'' | kL | '1000.0' | | Liters | ''liters'' | L | '1.0' | | Deciliters | ''deciliters'' | dL | '0.1' | | Centiliters | ''centiliters'' | cL | '0.01' | | Milliliters | ''milliliters'' | mL | '0.001' | | Cubic Kilometers | ''cubicKilometers'' | km³ | '1e12' | | Cubic Meters | ''cubicMeters'' | m³ | '1000.0' | | Cubic Decimeters | ''cubicDecimeters'' | dm³ | '1.0' | | Cubic Centimeters | ''cubicCentimeters'' | cm³ | '0.001' | | Cubic Millimeters | ''cubicMillimeters'' | mm³ | '0.000001' | | Cubic Inches | ''cubicInches'' | in³ | '0.0163871' | | Cubic Feet | ''cubicFeet'' | ft³ | '28.3168' | | Cubic Yards | ''cubicYards'' | yd³ | '764.555' | | Cubic Miles | ''cubicMiles'' | mi³ | '4.168e+12' | | Acre Feet | ''acreFeet'' | af | '1.233e+6' | | Bushels | ''bushels'' | bsh | '35.2391' | | Teaspoons | ''teaspoons'' | tsp | '0.00492892' | | Tablespoons | ''tablespoons'' | tbsp | '0.0147868' | | Fluid Ounces | ''fluidOunces'' | fl oz | '0.0295735' | | Cups | ''cups'' | cup | '0.24' | | Pints | ''pints'' | pt | '0.473176' | | Quarts | ''quarts'' | qt | '0.946353' | | Gallons | ''gallons'' | gal | '3.78541' | | Imperial Teaspoons | ''imperialTeaspoons'' | tsp | '0.00591939' | | Imperial Tablespoons | ''imperialTablespoons'' | tbsp | '0.0177582' | | Imperial Fluid Ounces | ''imperialFluidOunces'' | fl oz | '0.0284131' | | Imperial Pints | ''imperialPints'' | pt | '0.568261' | | Imperial Quarts | ''imperialQuarts'' | qt | '1.13652' | | Imperial Gallons | ''imperialGallons'' | gal | '4.54609' | | Metric Cups | ''metricCups'' | metric cup | '0.25' |
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
     * @details The acre-feet unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume acre_feet();
        /**
     * @brief Returns the `bushels` property of `NSUnitVolume`.
     * @details The bushels unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume bushels();
        /**
     * @brief Returns the `centiliters` property of `NSUnitVolume`.
     * @details The centiliters unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume centiliters();
        /**
     * @brief Returns the `cubicCentimeters` property of `NSUnitVolume`.
     * @details The cubic centimeters unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_centimeters();
        /**
     * @brief Returns the `cubicDecimeters` property of `NSUnitVolume`.
     * @details The cubic decimeters unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_decimeters();
        /**
     * @brief Returns the `cubicFeet` property of `NSUnitVolume`.
     * @details The cubic feet unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_feet();
        /**
     * @brief Returns the `cubicInches` property of `NSUnitVolume`.
     * @details The cubic inches unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_inches();
        /**
     * @brief Returns the `cubicKilometers` property of `NSUnitVolume`.
     * @details The cubic kilometers unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_kilometers();
        /**
     * @brief Returns the `cubicMeters` property of `NSUnitVolume`.
     * @details The cubic meters unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_meters();
        /**
     * @brief Returns the `cubicMiles` property of `NSUnitVolume`.
     * @details The cubic miles unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_miles();
        /**
     * @brief Returns the `cubicMillimeters` property of `NSUnitVolume`.
     * @details The cubic millimeters unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_millimeters();
        /**
     * @brief Returns the `cubicYards` property of `NSUnitVolume`.
     * @details The cubic yards unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume cubic_yards();
        /**
     * @brief Returns the `cups` property of `NSUnitVolume`.
     * @details The cups unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume cups();
        /**
     * @brief Returns the `deciliters` property of `NSUnitVolume`.
     * @details The deciliters unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume deciliters();
        /**
     * @brief Returns the `fluidOunces` property of `NSUnitVolume`.
     * @details The fluid ounces unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume fluid_ounces();
        /**
     * @brief Returns the `gallons` property of `NSUnitVolume`.
     * @details The gallons unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume gallons();
        /**
     * @brief Returns the `imperialFluidOunces` property of `NSUnitVolume`.
     * @details The imperial fluid ounces unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume imperial_fluid_ounces();
        /**
     * @brief Returns the `imperialGallons` property of `NSUnitVolume`.
     * @details The imperial gallons unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume imperial_gallons();
        /**
     * @brief Returns the `imperialPints` property of `NSUnitVolume`.
     * @details The imperial pints unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume imperial_pints();
        /**
     * @brief Returns the `imperialQuarts` property of `NSUnitVolume`.
     * @details The imperial quarts unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume imperial_quarts();
        /**
     * @brief Returns the `imperialTablespoons` property of `NSUnitVolume`.
     * @details The imperial tablespoons unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume imperial_tablespoons();
        /**
     * @brief Returns the `imperialTeaspoons` property of `NSUnitVolume`.
     * @details The imperial teaspoons unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume imperial_teaspoons();
        /**
     * @brief Returns the `kiloliters` property of `NSUnitVolume`.
     * @details The kiloliters unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume kiloliters();
        /**
     * @brief Returns the `liters` property of `NSUnitVolume`.
     * @details The liters unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume liters();
        /**
     * @brief Returns the `megaliters` property of `NSUnitVolume`.
     * @details The megaliters unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume megaliters();
        /**
     * @brief Returns the `metricCups` property of `NSUnitVolume`.
     * @details The metric cups unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume metric_cups();
        /**
     * @brief Returns the `milliliters` property of `NSUnitVolume`.
     * @details The milliliters unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume milliliters();
        /**
     * @brief Returns the `pints` property of `NSUnitVolume`.
     * @details The pints unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume pints();
        /**
     * @brief Returns the `quarts` property of `NSUnitVolume`.
     * @details The quarts unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume quarts();
        /**
     * @brief Returns the `tablespoons` property of `NSUnitVolume`.
     * @details The tablespoons unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume tablespoons();
        /**
     * @brief Returns the `teaspoons` property of `NSUnitVolume`.
     * @details The teaspoons unit of volume.
     * @return The converted Objective-C result.
     */
        static UnitVolume teaspoons();
    };
}
