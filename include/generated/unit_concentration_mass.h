#pragma once

#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitConcentrationMass` (Foundation).
     * @details A unit of measure for concentration of mass. You typically use instances of ''NSUnitConcentrationMass'' to represent specific quantities of concentration using the ''NSMeasurement'' class. \#\#\# Concentration of Mass Concentration is the abundance of a constituent within a volume. Concentration can be expressed by SI derived units in terms of kilograms per cubic meter (kg/m3). The ''NSUnitConcentrationMass'' class defines its ''Dimension/baseUnit()'' as ''gramsPerLiter'', and provides the following units, which are initialized using ''UnitConverterLinear'' converters with the specified coefficients: | Name | Method | Symbol | Coefficient | |---|---|---|---| | Grams Per Liter | ''gramsPerLiter'' | g/L | '1' | | Milligrams Per Deciliter | ''milligramsPerDeciliter'' | mg/dL | '0.01' | | Millimoles Per Liter | ''millimolesPerLiter(withGramsPerMole:)'' | mmol/L | '18 gramsPerMole' |
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitConcentrationMass unit_concentration_mass(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::UnitConcentrationMass unit_concentration_mass(nullptr);
     * auto made_0 = cocoon::UnitConcentrationMass::millimoles_per_liter_with_grams_per_mole(1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitconcentrationmass
     */
    class UnitConcentrationMass : public Dimension
    {
    public:
        UnitConcentrationMass();
        /// @brief Creates a null handle that refers to no native object.
        UnitConcentrationMass(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitConcentrationMass(Adopt adopt);
        /**
     * @brief Calls `+[NSUnitConcentrationMass millimolesPerLiterWithGramsPerMole:]`.
     * @details Returns the millimoles per liter unit with the specified grams per mole.
     * @param grams_per_mole Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static UnitConcentrationMass millimoles_per_liter_with_grams_per_mole(double grams_per_mole);
        /**
     * @brief Returns the `gramsPerLiter` property of `NSUnitConcentrationMass`.
     * @details The grams per liter unit of concentration.
     * @return The converted Objective-C result.
     */
        static UnitConcentrationMass grams_per_liter();
        /**
     * @brief Returns the `milligramsPerDeciliter` property of `NSUnitConcentrationMass`.
     * @details The milligrams per deciliter unit of concentration.
     * @return The converted Objective-C result.
     */
        static UnitConcentrationMass milligrams_per_deciliter();
    };
}
