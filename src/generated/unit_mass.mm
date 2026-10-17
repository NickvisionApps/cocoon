#include "generated/unit_mass.h"
#include "internal.h"

namespace cocoon
{
    UnitMass::UnitMass() : Dimension(nullptr)
    {
    }

    UnitMass::UnitMass(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitMass::UnitMass(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitMass UnitMass::carats()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass carats]);
    }

    UnitMass UnitMass::centigrams()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass centigrams]);
    }

    UnitMass UnitMass::decigrams()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass decigrams]);
    }

    UnitMass UnitMass::grams()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass grams]);
    }

    UnitMass UnitMass::kilograms()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass kilograms]);
    }

    UnitMass UnitMass::metric_tons()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass metricTons]);
    }

    UnitMass UnitMass::micrograms()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass micrograms]);
    }

    UnitMass UnitMass::milligrams()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass milligrams]);
    }

    UnitMass UnitMass::nanograms()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass nanograms]);
    }

    UnitMass UnitMass::ounces()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass ounces]);
    }

    UnitMass UnitMass::ounces_troy()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass ouncesTroy]);
    }

    UnitMass UnitMass::picograms()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass picograms]);
    }

    UnitMass UnitMass::pounds_mass()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass poundsMass]);
    }

    UnitMass UnitMass::short_tons()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass shortTons]);
    }

    UnitMass UnitMass::slugs()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass slugs]);
    }

    UnitMass UnitMass::stones()
    {
        return cocoon::internal::wrap<UnitMass>([::NSUnitMass stones]);
    }
}
