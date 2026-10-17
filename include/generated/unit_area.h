#pragma once

#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitArea` (Foundation).
     * @details A unit of measure for area. You typically use instances of ''NSUnitArea'' to represent specific quantities of area using the ''NSMeasurement'' class. \#\#\# Area Area is a quantity of extent in two dimensions. Area can be expressed by SI derived units in terms of square meters (m2). Area is also commonly measured in square feet (ft2) and acres (ac). The ''NSUnitArea'' class defines its ''Dimension/baseUnit()'' as ''squareMeters'', and provides the following units, which are initialized using ''UnitConverterLinear'' converters with the specified coefficients: | Name | Method | Symbol | Coefficient | |---|---|---|---| | Square Megameters | ''squareMegameters'' | Mm² | '1e12' | | Square Kilometers | ''squareKilometers'' | km² | '1000000.0' | | Square Meters | ''squareMeters'' | m² | '1.0' | | Square Centimeter | ''squareCentimeters'' | cm² | '0.0001' | | Square Millimeters | ''squareMillimeters'' | mm² | '0.000001' | | Square Micrometers | ''squareMicrometers'' | µm² | '1e-12' | | Square Nanometers | ''squareNanometers'' | nm² | '1e-18' | | Square Inches | ''squareInches'' | in² | '0.00064516' | | Square Feet | ''squareFeet'' | ft² | '0.092903' | | Square Yards | ''squareYards'' | yd² | '0.836127' | | Square Miles | ''squareMiles'' | mi² | '2.59e+6' | | Acres | ''acres'' | ac | '4046.86' | | Ares | ''ares'' | a | '100' | | Hectares | ''hectares'' | ha | '10000' |
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitArea unit_area(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitarea
     */
    class UnitArea : public Dimension
    {
    public:
        UnitArea();
        /// @brief Creates a null handle that refers to no native object.
        UnitArea(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitArea(Adopt adopt);
        /**
     * @brief Returns the `acres` property of `NSUnitArea`.
     * @details The acres unit of area.
     * @return The converted Objective-C result.
     */
        static UnitArea acres();
        /**
     * @brief Returns the `ares` property of `NSUnitArea`.
     * @details The ares unit of area.
     * @return The converted Objective-C result.
     */
        static UnitArea ares();
        /**
     * @brief Returns the `hectares` property of `NSUnitArea`.
     * @details The hectares unit of area.
     * @return The converted Objective-C result.
     */
        static UnitArea hectares();
        /**
     * @brief Returns the `squareCentimeters` property of `NSUnitArea`.
     * @details The square centimeters unit of area.
     * @return The converted Objective-C result.
     */
        static UnitArea square_centimeters();
        /**
     * @brief Returns the `squareFeet` property of `NSUnitArea`.
     * @details The square feet unit of area.
     * @return The converted Objective-C result.
     */
        static UnitArea square_feet();
        /**
     * @brief Returns the `squareInches` property of `NSUnitArea`.
     * @details The square inches unit of area.
     * @return The converted Objective-C result.
     */
        static UnitArea square_inches();
        /**
     * @brief Returns the `squareKilometers` property of `NSUnitArea`.
     * @details The square kilometers unit of area.
     * @return The converted Objective-C result.
     */
        static UnitArea square_kilometers();
        /**
     * @brief Returns the `squareMegameters` property of `NSUnitArea`.
     * @details The square megameters unit of area.
     * @return The converted Objective-C result.
     */
        static UnitArea square_megameters();
        /**
     * @brief Returns the `squareMeters` property of `NSUnitArea`.
     * @details The square meters unit of area.
     * @return The converted Objective-C result.
     */
        static UnitArea square_meters();
        /**
     * @brief Returns the `squareMicrometers` property of `NSUnitArea`.
     * @details The square micrometers unit of area.
     * @return The converted Objective-C result.
     */
        static UnitArea square_micrometers();
        /**
     * @brief Returns the `squareMiles` property of `NSUnitArea`.
     * @details The square miles unit of area.
     * @return The converted Objective-C result.
     */
        static UnitArea square_miles();
        /**
     * @brief Returns the `squareMillimeters` property of `NSUnitArea`.
     * @details The square millimeters unit of area.
     * @return The converted Objective-C result.
     */
        static UnitArea square_millimeters();
        /**
     * @brief Returns the `squareNanometers` property of `NSUnitArea`.
     * @details The square nanometers unit of area.
     * @return The converted Objective-C result.
     */
        static UnitArea square_nanometers();
        /**
     * @brief Returns the `squareYards` property of `NSUnitArea`.
     * @details The square yards unit of area.
     * @return The converted Objective-C result.
     */
        static UnitArea square_yards();
    };
}
