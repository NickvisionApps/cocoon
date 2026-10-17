#include "generated/unit_pressure.h"
#include "internal.h"

namespace cocoon
{
    UnitPressure::UnitPressure() : Dimension(nullptr)
    {
    }

    UnitPressure::UnitPressure(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitPressure::UnitPressure(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitPressure UnitPressure::bars()
    {
        return cocoon::internal::wrap<UnitPressure>([::NSUnitPressure bars]);
    }

    UnitPressure UnitPressure::gigapascals()
    {
        return cocoon::internal::wrap<UnitPressure>([::NSUnitPressure gigapascals]);
    }

    UnitPressure UnitPressure::hectopascals()
    {
        return cocoon::internal::wrap<UnitPressure>([::NSUnitPressure hectopascals]);
    }

    UnitPressure UnitPressure::inches_of_mercury()
    {
        return cocoon::internal::wrap<UnitPressure>([::NSUnitPressure inchesOfMercury]);
    }

    UnitPressure UnitPressure::kilopascals()
    {
        return cocoon::internal::wrap<UnitPressure>([::NSUnitPressure kilopascals]);
    }

    UnitPressure UnitPressure::megapascals()
    {
        return cocoon::internal::wrap<UnitPressure>([::NSUnitPressure megapascals]);
    }

    UnitPressure UnitPressure::millibars()
    {
        return cocoon::internal::wrap<UnitPressure>([::NSUnitPressure millibars]);
    }

    UnitPressure UnitPressure::millimeters_of_mercury()
    {
        return cocoon::internal::wrap<UnitPressure>([::NSUnitPressure millimetersOfMercury]);
    }

    UnitPressure UnitPressure::newtons_per_meters_squared()
    {
        return cocoon::internal::wrap<UnitPressure>([::NSUnitPressure newtonsPerMetersSquared]);
    }

    UnitPressure UnitPressure::pounds_force_per_square_inch()
    {
        return cocoon::internal::wrap<UnitPressure>([::NSUnitPressure poundsForcePerSquareInch]);
    }
}
