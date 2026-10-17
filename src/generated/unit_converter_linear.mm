#include "generated/unit_converter_linear.h"
#include "internal.h"

namespace cocoon
{
    UnitConverterLinear::UnitConverterLinear(double coefficient) : UnitConverterLinear(Adopt{cocoon::internal::retain([[::NSUnitConverterLinear alloc] initWithCoefficient:static_cast<double>(coefficient)])})
    {
    }

    UnitConverterLinear::UnitConverterLinear(double coefficient, double constant) : UnitConverterLinear(Adopt{cocoon::internal::retain([[::NSUnitConverterLinear alloc] initWithCoefficient:static_cast<double>(coefficient) constant:static_cast<double>(constant)])})
    {
    }

    UnitConverterLinear::UnitConverterLinear() : UnitConverterLinear(Adopt{cocoon::internal::retain([[::NSUnitConverterLinear alloc] init])})
    {
    }

    UnitConverterLinear::UnitConverterLinear(std::nullptr_t) : UnitConverter(nullptr)
    {
    }

    UnitConverterLinear::UnitConverterLinear(Adopt adopt) : UnitConverter(adopt)
    {
    }

    double UnitConverterLinear::coefficient() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSUnitConverterLinear>(this) coefficient]);
    }

    double UnitConverterLinear::constant() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSUnitConverterLinear>(this) constant]);
    }
}
