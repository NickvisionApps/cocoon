#include "generated/unit_duration.h"
#include "internal.h"

namespace cocoon
{
    UnitDuration::UnitDuration() : Dimension(nullptr)
    {
    }

    UnitDuration::UnitDuration(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitDuration::UnitDuration(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitDuration UnitDuration::hours()
    {
        return cocoon::internal::wrap<UnitDuration>([::NSUnitDuration hours]);
    }

    UnitDuration UnitDuration::microseconds()
    {
        return cocoon::internal::wrap<UnitDuration>([::NSUnitDuration microseconds]);
    }

    UnitDuration UnitDuration::milliseconds()
    {
        return cocoon::internal::wrap<UnitDuration>([::NSUnitDuration milliseconds]);
    }

    UnitDuration UnitDuration::minutes()
    {
        return cocoon::internal::wrap<UnitDuration>([::NSUnitDuration minutes]);
    }

    UnitDuration UnitDuration::nanoseconds()
    {
        return cocoon::internal::wrap<UnitDuration>([::NSUnitDuration nanoseconds]);
    }

    UnitDuration UnitDuration::picoseconds()
    {
        return cocoon::internal::wrap<UnitDuration>([::NSUnitDuration picoseconds]);
    }

    UnitDuration UnitDuration::seconds()
    {
        return cocoon::internal::wrap<UnitDuration>([::NSUnitDuration seconds]);
    }
}
