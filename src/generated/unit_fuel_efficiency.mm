#include "generated/unit_fuel_efficiency.h"
#include "internal.h"

namespace cocoon
{
    UnitFuelEfficiency::UnitFuelEfficiency() : Dimension(nullptr)
    {
    }

    UnitFuelEfficiency::UnitFuelEfficiency(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitFuelEfficiency::UnitFuelEfficiency(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitFuelEfficiency UnitFuelEfficiency::liters_per100_kilometers()
    {
        return cocoon::internal::wrap<UnitFuelEfficiency>([::NSUnitFuelEfficiency litersPer100Kilometers]);
    }

    UnitFuelEfficiency UnitFuelEfficiency::miles_per_gallon()
    {
        return cocoon::internal::wrap<UnitFuelEfficiency>([::NSUnitFuelEfficiency milesPerGallon]);
    }

    UnitFuelEfficiency UnitFuelEfficiency::miles_per_imperial_gallon()
    {
        return cocoon::internal::wrap<UnitFuelEfficiency>([::NSUnitFuelEfficiency milesPerImperialGallon]);
    }
}
