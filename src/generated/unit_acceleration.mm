#include "generated/unit_acceleration.h"
#include "internal.h"

namespace cocoon
{
    UnitAcceleration::UnitAcceleration() : Dimension(nullptr)
    {
    }

    UnitAcceleration::UnitAcceleration(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitAcceleration::UnitAcceleration(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitAcceleration UnitAcceleration::gravity()
    {
        return cocoon::internal::wrap<UnitAcceleration>([::NSUnitAcceleration gravity]);
    }

    UnitAcceleration UnitAcceleration::meters_per_second_squared()
    {
        return cocoon::internal::wrap<UnitAcceleration>([::NSUnitAcceleration metersPerSecondSquared]);
    }
}
