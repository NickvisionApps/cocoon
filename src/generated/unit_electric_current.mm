#include "generated/unit_electric_current.h"
#include "internal.h"

namespace cocoon
{
    UnitElectricCurrent::UnitElectricCurrent() : Dimension(nullptr)
    {
    }

    UnitElectricCurrent::UnitElectricCurrent(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitElectricCurrent::UnitElectricCurrent(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitElectricCurrent UnitElectricCurrent::amperes()
    {
        return cocoon::internal::wrap<UnitElectricCurrent>([::NSUnitElectricCurrent amperes]);
    }

    UnitElectricCurrent UnitElectricCurrent::kiloamperes()
    {
        return cocoon::internal::wrap<UnitElectricCurrent>([::NSUnitElectricCurrent kiloamperes]);
    }

    UnitElectricCurrent UnitElectricCurrent::megaamperes()
    {
        return cocoon::internal::wrap<UnitElectricCurrent>([::NSUnitElectricCurrent megaamperes]);
    }

    UnitElectricCurrent UnitElectricCurrent::microamperes()
    {
        return cocoon::internal::wrap<UnitElectricCurrent>([::NSUnitElectricCurrent microamperes]);
    }

    UnitElectricCurrent UnitElectricCurrent::milliamperes()
    {
        return cocoon::internal::wrap<UnitElectricCurrent>([::NSUnitElectricCurrent milliamperes]);
    }
}
