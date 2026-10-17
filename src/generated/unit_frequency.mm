#include "generated/unit_frequency.h"
#include "internal.h"

namespace cocoon
{
    UnitFrequency::UnitFrequency() : Dimension(nullptr)
    {
    }

    UnitFrequency::UnitFrequency(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitFrequency::UnitFrequency(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitFrequency UnitFrequency::frames_per_second()
    {
        return cocoon::internal::wrap<UnitFrequency>([::NSUnitFrequency framesPerSecond]);
    }

    UnitFrequency UnitFrequency::gigahertz()
    {
        return cocoon::internal::wrap<UnitFrequency>([::NSUnitFrequency gigahertz]);
    }

    UnitFrequency UnitFrequency::hertz()
    {
        return cocoon::internal::wrap<UnitFrequency>([::NSUnitFrequency hertz]);
    }

    UnitFrequency UnitFrequency::kilohertz()
    {
        return cocoon::internal::wrap<UnitFrequency>([::NSUnitFrequency kilohertz]);
    }

    UnitFrequency UnitFrequency::megahertz()
    {
        return cocoon::internal::wrap<UnitFrequency>([::NSUnitFrequency megahertz]);
    }

    UnitFrequency UnitFrequency::microhertz()
    {
        return cocoon::internal::wrap<UnitFrequency>([::NSUnitFrequency microhertz]);
    }

    UnitFrequency UnitFrequency::millihertz()
    {
        return cocoon::internal::wrap<UnitFrequency>([::NSUnitFrequency millihertz]);
    }

    UnitFrequency UnitFrequency::nanohertz()
    {
        return cocoon::internal::wrap<UnitFrequency>([::NSUnitFrequency nanohertz]);
    }

    UnitFrequency UnitFrequency::terahertz()
    {
        return cocoon::internal::wrap<UnitFrequency>([::NSUnitFrequency terahertz]);
    }
}
