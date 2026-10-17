#include "generated/unit_electric_potential_difference.h"
#include "internal.h"

namespace cocoon
{
    UnitElectricPotentialDifference::UnitElectricPotentialDifference() : Dimension(nullptr)
    {
    }

    UnitElectricPotentialDifference::UnitElectricPotentialDifference(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitElectricPotentialDifference::UnitElectricPotentialDifference(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitElectricPotentialDifference UnitElectricPotentialDifference::kilovolts()
    {
        return cocoon::internal::wrap<UnitElectricPotentialDifference>([::NSUnitElectricPotentialDifference kilovolts]);
    }

    UnitElectricPotentialDifference UnitElectricPotentialDifference::megavolts()
    {
        return cocoon::internal::wrap<UnitElectricPotentialDifference>([::NSUnitElectricPotentialDifference megavolts]);
    }

    UnitElectricPotentialDifference UnitElectricPotentialDifference::microvolts()
    {
        return cocoon::internal::wrap<UnitElectricPotentialDifference>([::NSUnitElectricPotentialDifference microvolts]);
    }

    UnitElectricPotentialDifference UnitElectricPotentialDifference::millivolts()
    {
        return cocoon::internal::wrap<UnitElectricPotentialDifference>([::NSUnitElectricPotentialDifference millivolts]);
    }

    UnitElectricPotentialDifference UnitElectricPotentialDifference::volts()
    {
        return cocoon::internal::wrap<UnitElectricPotentialDifference>([::NSUnitElectricPotentialDifference volts]);
    }
}
