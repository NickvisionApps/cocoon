#include "generated/unit_length.h"
#include "internal.h"

namespace cocoon
{
    UnitLength::UnitLength() : Dimension(nullptr)
    {
    }

    UnitLength::UnitLength(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitLength::UnitLength(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitLength UnitLength::astronomical_units()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength astronomicalUnits]);
    }

    UnitLength UnitLength::centimeters()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength centimeters]);
    }

    UnitLength UnitLength::decameters()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength decameters]);
    }

    UnitLength UnitLength::decimeters()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength decimeters]);
    }

    UnitLength UnitLength::fathoms()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength fathoms]);
    }

    UnitLength UnitLength::feet()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength feet]);
    }

    UnitLength UnitLength::furlongs()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength furlongs]);
    }

    UnitLength UnitLength::hectometers()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength hectometers]);
    }

    UnitLength UnitLength::inches()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength inches]);
    }

    UnitLength UnitLength::kilometers()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength kilometers]);
    }

    UnitLength UnitLength::lightyears()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength lightyears]);
    }

    UnitLength UnitLength::megameters()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength megameters]);
    }

    UnitLength UnitLength::meters()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength meters]);
    }

    UnitLength UnitLength::micrometers()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength micrometers]);
    }

    UnitLength UnitLength::miles()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength miles]);
    }

    UnitLength UnitLength::millimeters()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength millimeters]);
    }

    UnitLength UnitLength::nanometers()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength nanometers]);
    }

    UnitLength UnitLength::nautical_miles()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength nauticalMiles]);
    }

    UnitLength UnitLength::parsecs()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength parsecs]);
    }

    UnitLength UnitLength::picometers()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength picometers]);
    }

    UnitLength UnitLength::scandinavian_miles()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength scandinavianMiles]);
    }

    UnitLength UnitLength::yards()
    {
        return cocoon::internal::wrap<UnitLength>([::NSUnitLength yards]);
    }
}
