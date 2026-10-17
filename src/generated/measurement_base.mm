#include "generated/measurement_base.h"
#include "internal.h"

namespace cocoon
{
    MeasurementBase::MeasurementBase(double double_value, const Object& unit) : MeasurementBase(Adopt{cocoon::internal::retain([[::NSMeasurement alloc] initWithDoubleValue:static_cast<double>(double_value) unit:cocoon::internal::native_id(unit)])})
    {
    }

    MeasurementBase::MeasurementBase() : Object(nullptr)
    {
    }

    MeasurementBase::MeasurementBase(std::nullptr_t) : Object(nullptr)
    {
    }

    MeasurementBase::MeasurementBase(Adopt adopt) : Object(adopt)
    {
    }

    bool MeasurementBase::can_be_converted_to_unit(const Unit& unit) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMeasurement>(this) canBeConvertedToUnit:cocoon::internal::native<::NSUnit>(unit)]);
    }

    MeasurementBase MeasurementBase::measurement_by_adding_measurement(const MeasurementBase& measurement) const
    {
        return cocoon::internal::wrap<MeasurementBase>([cocoon::internal::ns<::NSMeasurement>(this) measurementByAddingMeasurement:cocoon::internal::native<::NSMeasurement>(measurement)]);
    }

    MeasurementBase MeasurementBase::measurement_by_converting_to_unit(const Unit& unit) const
    {
        return cocoon::internal::wrap<MeasurementBase>([cocoon::internal::ns<::NSMeasurement>(this) measurementByConvertingToUnit:cocoon::internal::native<::NSUnit>(unit)]);
    }

    MeasurementBase MeasurementBase::measurement_by_subtracting_measurement(const MeasurementBase& measurement) const
    {
        return cocoon::internal::wrap<MeasurementBase>([cocoon::internal::ns<::NSMeasurement>(this) measurementBySubtractingMeasurement:cocoon::internal::native<::NSMeasurement>(measurement)]);
    }

    double MeasurementBase::double_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMeasurement>(this) doubleValue]);
    }

    Object MeasurementBase::unit() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSMeasurement>(this) unit]);
    }
}
