#include "generated/unit_angle.h"
#include "internal.h"

namespace cocoon
{
    UnitAngle::UnitAngle() : Dimension(nullptr)
    {
    }

    UnitAngle::UnitAngle(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitAngle::UnitAngle(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitAngle UnitAngle::arc_minutes()
    {
        return cocoon::internal::wrap<UnitAngle>([::NSUnitAngle arcMinutes]);
    }

    UnitAngle UnitAngle::arc_seconds()
    {
        return cocoon::internal::wrap<UnitAngle>([::NSUnitAngle arcSeconds]);
    }

    UnitAngle UnitAngle::degrees()
    {
        return cocoon::internal::wrap<UnitAngle>([::NSUnitAngle degrees]);
    }

    UnitAngle UnitAngle::gradians()
    {
        return cocoon::internal::wrap<UnitAngle>([::NSUnitAngle gradians]);
    }

    UnitAngle UnitAngle::radians()
    {
        return cocoon::internal::wrap<UnitAngle>([::NSUnitAngle radians]);
    }

    UnitAngle UnitAngle::revolutions()
    {
        return cocoon::internal::wrap<UnitAngle>([::NSUnitAngle revolutions]);
    }
}
