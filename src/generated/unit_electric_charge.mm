#include "generated/unit_electric_charge.h"
#include "internal.h"

namespace cocoon
{
    UnitElectricCharge::UnitElectricCharge() : Dimension(nullptr)
    {
    }

    UnitElectricCharge::UnitElectricCharge(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitElectricCharge::UnitElectricCharge(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitElectricCharge UnitElectricCharge::ampere_hours()
    {
        return cocoon::internal::wrap<UnitElectricCharge>([::NSUnitElectricCharge ampereHours]);
    }

    UnitElectricCharge UnitElectricCharge::coulombs()
    {
        return cocoon::internal::wrap<UnitElectricCharge>([::NSUnitElectricCharge coulombs]);
    }

    UnitElectricCharge UnitElectricCharge::kiloampere_hours()
    {
        return cocoon::internal::wrap<UnitElectricCharge>([::NSUnitElectricCharge kiloampereHours]);
    }

    UnitElectricCharge UnitElectricCharge::megaampere_hours()
    {
        return cocoon::internal::wrap<UnitElectricCharge>([::NSUnitElectricCharge megaampereHours]);
    }

    UnitElectricCharge UnitElectricCharge::microampere_hours()
    {
        return cocoon::internal::wrap<UnitElectricCharge>([::NSUnitElectricCharge microampereHours]);
    }

    UnitElectricCharge UnitElectricCharge::milliampere_hours()
    {
        return cocoon::internal::wrap<UnitElectricCharge>([::NSUnitElectricCharge milliampereHours]);
    }
}
