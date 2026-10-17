#include "generated/unit_volume.h"
#include "internal.h"

namespace cocoon
{
    UnitVolume::UnitVolume() : Dimension(nullptr)
    {
    }

    UnitVolume::UnitVolume(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitVolume::UnitVolume(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitVolume UnitVolume::acre_feet()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume acreFeet]);
    }

    UnitVolume UnitVolume::bushels()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume bushels]);
    }

    UnitVolume UnitVolume::centiliters()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume centiliters]);
    }

    UnitVolume UnitVolume::cubic_centimeters()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume cubicCentimeters]);
    }

    UnitVolume UnitVolume::cubic_decimeters()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume cubicDecimeters]);
    }

    UnitVolume UnitVolume::cubic_feet()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume cubicFeet]);
    }

    UnitVolume UnitVolume::cubic_inches()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume cubicInches]);
    }

    UnitVolume UnitVolume::cubic_kilometers()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume cubicKilometers]);
    }

    UnitVolume UnitVolume::cubic_meters()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume cubicMeters]);
    }

    UnitVolume UnitVolume::cubic_miles()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume cubicMiles]);
    }

    UnitVolume UnitVolume::cubic_millimeters()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume cubicMillimeters]);
    }

    UnitVolume UnitVolume::cubic_yards()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume cubicYards]);
    }

    UnitVolume UnitVolume::cups()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume cups]);
    }

    UnitVolume UnitVolume::deciliters()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume deciliters]);
    }

    UnitVolume UnitVolume::fluid_ounces()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume fluidOunces]);
    }

    UnitVolume UnitVolume::gallons()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume gallons]);
    }

    UnitVolume UnitVolume::imperial_fluid_ounces()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume imperialFluidOunces]);
    }

    UnitVolume UnitVolume::imperial_gallons()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume imperialGallons]);
    }

    UnitVolume UnitVolume::imperial_pints()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume imperialPints]);
    }

    UnitVolume UnitVolume::imperial_quarts()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume imperialQuarts]);
    }

    UnitVolume UnitVolume::imperial_tablespoons()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume imperialTablespoons]);
    }

    UnitVolume UnitVolume::imperial_teaspoons()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume imperialTeaspoons]);
    }

    UnitVolume UnitVolume::kiloliters()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume kiloliters]);
    }

    UnitVolume UnitVolume::liters()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume liters]);
    }

    UnitVolume UnitVolume::megaliters()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume megaliters]);
    }

    UnitVolume UnitVolume::metric_cups()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume metricCups]);
    }

    UnitVolume UnitVolume::milliliters()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume milliliters]);
    }

    UnitVolume UnitVolume::pints()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume pints]);
    }

    UnitVolume UnitVolume::quarts()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume quarts]);
    }

    UnitVolume UnitVolume::tablespoons()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume tablespoons]);
    }

    UnitVolume UnitVolume::teaspoons()
    {
        return cocoon::internal::wrap<UnitVolume>([::NSUnitVolume teaspoons]);
    }
}
