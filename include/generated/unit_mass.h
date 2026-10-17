#pragma once

#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitMass` (Foundation).
     * @details A unit of measure for mass. You typically use instances of ''NSUnitMass'' to represent specific quantities of mass using the ''NSMeasurement'' class. \#\#\# Mass Mass is a fundamental property of matter that causes it to resist a force accelerating it. The SI unit for mass is the kilogram (kg), which defined in terms of the mass of the international prototype kilogram. The ''NSUnitMass'' class defines its ''Dimension/baseUnit()'' as ''kilograms'', and provides the following units, which ''UnitConverterLinear'' converters initialize with the given coefficients: | Name | Method | Symbol | Coefficient | |---|---|---|---| | Kilograms | ''kilograms'' | kg | '1.0' | | Grams | ''grams'' | g | '0.001' | | Decigrams | ''decigrams'' | dg | '0.0001' | | Centigrams | ''centigrams'' | cg | '0.00001' | | Milligrams | ''milligrams'' | mg | '0.000001' | | Micrograms | ''micrograms'' | µg | '1e-9' | | Nanograms | ''nanograms'' | ng | '1e-12' | | Picograms | ''picograms'' | pg | '1e-15' | | Ounces | ''ounces'' | oz | '0.0283495' | | Pounds | ''pounds'' | lb | '0.453592' | | Stones | ''stones'' | st | '0.157473' | | Metric Tons | ''metricTons'' | t | '1000' | | Short Tons | ''shortTons'' | ton | '907.185' | | Carats | ''carats'' | ct | '0.0002' | | Ounces Troy | ''ouncesTroy'' | oz t | '0.03110348' | | Slugs | ''slugs'' | slug | '14.5939' |
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitMass unit_mass(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitmass
     */
    class UnitMass : public Dimension
    {
    public:
        UnitMass();
        /// @brief Creates a null handle that refers to no native object.
        UnitMass(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitMass(Adopt adopt);
        /**
     * @brief Returns the `carats` property of `NSUnitMass`.
     * @details The carats unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass carats();
        /**
     * @brief Returns the `centigrams` property of `NSUnitMass`.
     * @details The centigrams unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass centigrams();
        /**
     * @brief Returns the `decigrams` property of `NSUnitMass`.
     * @details The decigrams unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass decigrams();
        /**
     * @brief Returns the `grams` property of `NSUnitMass`.
     * @details The grams unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass grams();
        /**
     * @brief Returns the `kilograms` property of `NSUnitMass`.
     * @details The kilograms unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass kilograms();
        /**
     * @brief Returns the `metricTons` property of `NSUnitMass`.
     * @details The metric tons unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass metric_tons();
        /**
     * @brief Returns the `micrograms` property of `NSUnitMass`.
     * @details The micrograms unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass micrograms();
        /**
     * @brief Returns the `milligrams` property of `NSUnitMass`.
     * @details The milligrams unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass milligrams();
        /**
     * @brief Returns the `nanograms` property of `NSUnitMass`.
     * @details The nanograms unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass nanograms();
        /**
     * @brief Returns the `ounces` property of `NSUnitMass`.
     * @details The ounces unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass ounces();
        /**
     * @brief Returns the `ouncesTroy` property of `NSUnitMass`.
     * @details The troy ounces unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass ounces_troy();
        /**
     * @brief Returns the `picograms` property of `NSUnitMass`.
     * @details The picograms unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass picograms();
        /**
     * @brief Returns the `poundsMass` property of `NSUnitMass`.
     * @details The pounds unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass pounds_mass();
        /**
     * @brief Returns the `shortTons` property of `NSUnitMass`.
     * @details The short tons unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass short_tons();
        /**
     * @brief Returns the `slugs` property of `NSUnitMass`.
     * @details The slugs unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass slugs();
        /**
     * @brief Returns the `stones` property of `NSUnitMass`.
     * @details The stones unit of mass.
     * @return The converted Objective-C result.
     */
        static UnitMass stones();
    };
}
