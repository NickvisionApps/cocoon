#include "generated/unit_power.h"
#include "internal.h"

namespace cocoon
{
    UnitPower::UnitPower() : Dimension(nullptr)
    {
    }

    UnitPower::UnitPower(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitPower::UnitPower(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitPower UnitPower::femtowatts()
    {
        return cocoon::internal::wrap<UnitPower>([::NSUnitPower femtowatts]);
    }

    UnitPower UnitPower::gigawatts()
    {
        return cocoon::internal::wrap<UnitPower>([::NSUnitPower gigawatts]);
    }

    UnitPower UnitPower::horsepower()
    {
        return cocoon::internal::wrap<UnitPower>([::NSUnitPower horsepower]);
    }

    UnitPower UnitPower::kilowatts()
    {
        return cocoon::internal::wrap<UnitPower>([::NSUnitPower kilowatts]);
    }

    UnitPower UnitPower::megawatts()
    {
        return cocoon::internal::wrap<UnitPower>([::NSUnitPower megawatts]);
    }

    UnitPower UnitPower::microwatts()
    {
        return cocoon::internal::wrap<UnitPower>([::NSUnitPower microwatts]);
    }

    UnitPower UnitPower::milliwatts()
    {
        return cocoon::internal::wrap<UnitPower>([::NSUnitPower milliwatts]);
    }

    UnitPower UnitPower::nanowatts()
    {
        return cocoon::internal::wrap<UnitPower>([::NSUnitPower nanowatts]);
    }

    UnitPower UnitPower::picowatts()
    {
        return cocoon::internal::wrap<UnitPower>([::NSUnitPower picowatts]);
    }

    UnitPower UnitPower::terawatts()
    {
        return cocoon::internal::wrap<UnitPower>([::NSUnitPower terawatts]);
    }

    UnitPower UnitPower::watts()
    {
        return cocoon::internal::wrap<UnitPower>([::NSUnitPower watts]);
    }
}
