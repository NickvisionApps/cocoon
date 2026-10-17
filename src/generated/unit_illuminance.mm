#include "generated/unit_illuminance.h"
#include "internal.h"

namespace cocoon
{
    UnitIlluminance::UnitIlluminance() : Dimension(nullptr)
    {
    }

    UnitIlluminance::UnitIlluminance(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitIlluminance::UnitIlluminance(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitIlluminance UnitIlluminance::lux()
    {
        return cocoon::internal::wrap<UnitIlluminance>([::NSUnitIlluminance lux]);
    }
}
