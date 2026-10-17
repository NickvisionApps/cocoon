#include "generated/unit_converter.h"
#include "internal.h"

namespace cocoon
{
    UnitConverter::UnitConverter() : UnitConverter(Adopt{cocoon::internal::retain([[::NSUnitConverter alloc] init])})
    {
    }

    UnitConverter::UnitConverter(std::nullptr_t) : Object(nullptr)
    {
    }

    UnitConverter::UnitConverter(Adopt adopt) : Object(adopt)
    {
    }

    double UnitConverter::base_unit_value_from_value(double value) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSUnitConverter>(this) baseUnitValueFromValue:static_cast<double>(value)]);
    }

    double UnitConverter::value_from_base_unit_value(double base_unit_value) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSUnitConverter>(this) valueFromBaseUnitValue:static_cast<double>(base_unit_value)]);
    }
}
