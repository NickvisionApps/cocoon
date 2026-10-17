#include "generated/unit_dispersion.h"
#include "internal.h"

namespace cocoon
{
    UnitDispersion::UnitDispersion() : Dimension(nullptr)
    {
    }

    UnitDispersion::UnitDispersion(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitDispersion::UnitDispersion(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitDispersion UnitDispersion::parts_per_million()
    {
        return cocoon::internal::wrap<UnitDispersion>([::NSUnitDispersion partsPerMillion]);
    }
}
