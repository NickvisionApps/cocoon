#include "generated/unit_electric_resistance.h"
#include "internal.h"

namespace cocoon
{
    UnitElectricResistance::UnitElectricResistance() : Dimension(nullptr)
    {
    }

    UnitElectricResistance::UnitElectricResistance(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitElectricResistance::UnitElectricResistance(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitElectricResistance UnitElectricResistance::kiloohms()
    {
        return cocoon::internal::wrap<UnitElectricResistance>([::NSUnitElectricResistance kiloohms]);
    }

    UnitElectricResistance UnitElectricResistance::megaohms()
    {
        return cocoon::internal::wrap<UnitElectricResistance>([::NSUnitElectricResistance megaohms]);
    }

    UnitElectricResistance UnitElectricResistance::microohms()
    {
        return cocoon::internal::wrap<UnitElectricResistance>([::NSUnitElectricResistance microohms]);
    }

    UnitElectricResistance UnitElectricResistance::milliohms()
    {
        return cocoon::internal::wrap<UnitElectricResistance>([::NSUnitElectricResistance milliohms]);
    }

    UnitElectricResistance UnitElectricResistance::ohms()
    {
        return cocoon::internal::wrap<UnitElectricResistance>([::NSUnitElectricResistance ohms]);
    }
}
