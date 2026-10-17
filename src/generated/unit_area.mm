#include "generated/unit_area.h"
#include "internal.h"

namespace cocoon
{
    UnitArea::UnitArea() : Dimension(nullptr)
    {
    }

    UnitArea::UnitArea(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitArea::UnitArea(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitArea UnitArea::acres()
    {
        return cocoon::internal::wrap<UnitArea>([::NSUnitArea acres]);
    }

    UnitArea UnitArea::ares()
    {
        return cocoon::internal::wrap<UnitArea>([::NSUnitArea ares]);
    }

    UnitArea UnitArea::hectares()
    {
        return cocoon::internal::wrap<UnitArea>([::NSUnitArea hectares]);
    }

    UnitArea UnitArea::square_centimeters()
    {
        return cocoon::internal::wrap<UnitArea>([::NSUnitArea squareCentimeters]);
    }

    UnitArea UnitArea::square_feet()
    {
        return cocoon::internal::wrap<UnitArea>([::NSUnitArea squareFeet]);
    }

    UnitArea UnitArea::square_inches()
    {
        return cocoon::internal::wrap<UnitArea>([::NSUnitArea squareInches]);
    }

    UnitArea UnitArea::square_kilometers()
    {
        return cocoon::internal::wrap<UnitArea>([::NSUnitArea squareKilometers]);
    }

    UnitArea UnitArea::square_megameters()
    {
        return cocoon::internal::wrap<UnitArea>([::NSUnitArea squareMegameters]);
    }

    UnitArea UnitArea::square_meters()
    {
        return cocoon::internal::wrap<UnitArea>([::NSUnitArea squareMeters]);
    }

    UnitArea UnitArea::square_micrometers()
    {
        return cocoon::internal::wrap<UnitArea>([::NSUnitArea squareMicrometers]);
    }

    UnitArea UnitArea::square_miles()
    {
        return cocoon::internal::wrap<UnitArea>([::NSUnitArea squareMiles]);
    }

    UnitArea UnitArea::square_millimeters()
    {
        return cocoon::internal::wrap<UnitArea>([::NSUnitArea squareMillimeters]);
    }

    UnitArea UnitArea::square_nanometers()
    {
        return cocoon::internal::wrap<UnitArea>([::NSUnitArea squareNanometers]);
    }

    UnitArea UnitArea::square_yards()
    {
        return cocoon::internal::wrap<UnitArea>([::NSUnitArea squareYards]);
    }
}
