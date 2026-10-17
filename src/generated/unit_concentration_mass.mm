#include "generated/unit_concentration_mass.h"
#include "internal.h"

namespace cocoon
{
    UnitConcentrationMass::UnitConcentrationMass() : Dimension(nullptr)
    {
    }

    UnitConcentrationMass::UnitConcentrationMass(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitConcentrationMass::UnitConcentrationMass(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitConcentrationMass UnitConcentrationMass::millimoles_per_liter_with_grams_per_mole(double grams_per_mole)
    {
        return cocoon::internal::wrap<UnitConcentrationMass>([::NSUnitConcentrationMass millimolesPerLiterWithGramsPerMole:static_cast<double>(grams_per_mole)]);
    }

    UnitConcentrationMass UnitConcentrationMass::grams_per_liter()
    {
        return cocoon::internal::wrap<UnitConcentrationMass>([::NSUnitConcentrationMass gramsPerLiter]);
    }

    UnitConcentrationMass UnitConcentrationMass::milligrams_per_deciliter()
    {
        return cocoon::internal::wrap<UnitConcentrationMass>([::NSUnitConcentrationMass milligramsPerDeciliter]);
    }
}
