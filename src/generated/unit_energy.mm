#include "generated/unit_energy.h"
#include "internal.h"

namespace cocoon
{
    UnitEnergy::UnitEnergy() : Dimension(nullptr)
    {
    }

    UnitEnergy::UnitEnergy(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitEnergy::UnitEnergy(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitEnergy UnitEnergy::calories()
    {
        return cocoon::internal::wrap<UnitEnergy>([::NSUnitEnergy calories]);
    }

    UnitEnergy UnitEnergy::joules()
    {
        return cocoon::internal::wrap<UnitEnergy>([::NSUnitEnergy joules]);
    }

    UnitEnergy UnitEnergy::kilocalories()
    {
        return cocoon::internal::wrap<UnitEnergy>([::NSUnitEnergy kilocalories]);
    }

    UnitEnergy UnitEnergy::kilojoules()
    {
        return cocoon::internal::wrap<UnitEnergy>([::NSUnitEnergy kilojoules]);
    }

    UnitEnergy UnitEnergy::kilowatt_hours()
    {
        return cocoon::internal::wrap<UnitEnergy>([::NSUnitEnergy kilowattHours]);
    }
}
