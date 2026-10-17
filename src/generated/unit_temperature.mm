#include "generated/unit_temperature.h"
#include "internal.h"

namespace cocoon
{
    UnitTemperature::UnitTemperature() : Dimension(nullptr)
    {
    }

    UnitTemperature::UnitTemperature(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitTemperature::UnitTemperature(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitTemperature UnitTemperature::celsius()
    {
        return cocoon::internal::wrap<UnitTemperature>([::NSUnitTemperature celsius]);
    }

    UnitTemperature UnitTemperature::fahrenheit()
    {
        return cocoon::internal::wrap<UnitTemperature>([::NSUnitTemperature fahrenheit]);
    }

    UnitTemperature UnitTemperature::kelvin()
    {
        return cocoon::internal::wrap<UnitTemperature>([::NSUnitTemperature kelvin]);
    }
}
