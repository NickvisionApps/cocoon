#include "generated/measurement_formatter.h"
#include "internal.h"

namespace cocoon
{
    MeasurementFormatter::MeasurementFormatter() : MeasurementFormatter(Adopt{cocoon::internal::retain([[::NSMeasurementFormatter alloc] init])})
    {
    }

    MeasurementFormatter::MeasurementFormatter(std::nullptr_t) : Formatter(nullptr)
    {
    }

    MeasurementFormatter::MeasurementFormatter(Adopt adopt) : Formatter(adopt)
    {
    }

    std::string MeasurementFormatter::string_from_measurement(const MeasurementBase& measurement) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMeasurementFormatter>(this) stringFromMeasurement:cocoon::internal::native<::NSMeasurement>(measurement)]);
    }

    std::string MeasurementFormatter::string_from_unit(const Unit& unit) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMeasurementFormatter>(this) stringFromUnit:cocoon::internal::native<::NSUnit>(unit)]);
    }

    Locale MeasurementFormatter::locale() const
    {
        return cocoon::internal::wrap<Locale>([cocoon::internal::ns<::NSMeasurementFormatter>(this) locale]);
    }

    void MeasurementFormatter::set_locale(const Locale& value) const
    {
        [cocoon::internal::ns<::NSMeasurementFormatter>(this) setLocale:cocoon::internal::native<::NSLocale>(value)];
    }

    NumberFormatter MeasurementFormatter::number_formatter() const
    {
        return cocoon::internal::wrap<NumberFormatter>([cocoon::internal::ns<::NSMeasurementFormatter>(this) numberFormatter]);
    }

    void MeasurementFormatter::set_number_formatter(const NumberFormatter& value) const
    {
        [cocoon::internal::ns<::NSMeasurementFormatter>(this) setNumberFormatter:cocoon::internal::native<::NSNumberFormatter>(value)];
    }

    MeasurementFormatterUnitOptions MeasurementFormatter::unit_options() const
    {
        return static_cast<MeasurementFormatterUnitOptions>([cocoon::internal::ns<::NSMeasurementFormatter>(this) unitOptions]);
    }

    void MeasurementFormatter::set_unit_options(MeasurementFormatterUnitOptions value) const
    {
        [cocoon::internal::ns<::NSMeasurementFormatter>(this) setUnitOptions:static_cast<::NSMeasurementFormatterUnitOptions>(value)];
    }

    FormattingUnitStyle MeasurementFormatter::unit_style() const
    {
        return static_cast<FormattingUnitStyle>([cocoon::internal::ns<::NSMeasurementFormatter>(this) unitStyle]);
    }

    void MeasurementFormatter::set_unit_style(FormattingUnitStyle value) const
    {
        [cocoon::internal::ns<::NSMeasurementFormatter>(this) setUnitStyle:static_cast<::NSFormattingUnitStyle>(value)];
    }
}
