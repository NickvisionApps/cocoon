#include "generated/unit_speed.h"
#include "internal.h"

namespace cocoon
{
    UnitSpeed::UnitSpeed() : Dimension(nullptr)
    {
    }

    UnitSpeed::UnitSpeed(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitSpeed::UnitSpeed(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitSpeed UnitSpeed::kilometers_per_hour()
    {
        return cocoon::internal::wrap<UnitSpeed>([::NSUnitSpeed kilometersPerHour]);
    }

    UnitSpeed UnitSpeed::knots()
    {
        return cocoon::internal::wrap<UnitSpeed>([::NSUnitSpeed knots]);
    }

    UnitSpeed UnitSpeed::meters_per_second()
    {
        return cocoon::internal::wrap<UnitSpeed>([::NSUnitSpeed metersPerSecond]);
    }

    UnitSpeed UnitSpeed::miles_per_hour()
    {
        return cocoon::internal::wrap<UnitSpeed>([::NSUnitSpeed milesPerHour]);
    }
}
