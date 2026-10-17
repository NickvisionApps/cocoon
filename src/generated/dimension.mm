#include "generated/dimension.h"
#include "internal.h"

namespace cocoon
{
    Dimension::Dimension(const std::string& symbol, const UnitConverter& converter) : Dimension(Adopt{cocoon::internal::retain([[::NSDimension alloc] initWithSymbol:cocoon::internal::to(symbol) converter:cocoon::internal::native<::NSUnitConverter>(converter)])})
    {
    }

    Dimension::Dimension() : Unit(nullptr)
    {
    }

    Dimension::Dimension(std::nullptr_t) : Unit(nullptr)
    {
    }

    Dimension::Dimension(Adopt adopt) : Unit(adopt)
    {
    }

    Dimension Dimension::base_unit()
    {
        return cocoon::internal::wrap<Dimension>([::NSDimension baseUnit]);
    }

    UnitConverter Dimension::converter() const
    {
        return cocoon::internal::wrap<UnitConverter>([cocoon::internal::ns<::NSDimension>(this) converter]);
    }
}
