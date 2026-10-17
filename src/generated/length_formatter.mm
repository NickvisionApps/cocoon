#include "generated/length_formatter.h"
#include "internal.h"

namespace cocoon
{
    LengthFormatter::LengthFormatter() : LengthFormatter(Adopt{cocoon::internal::retain([[::NSLengthFormatter alloc] init])})
    {
    }

    LengthFormatter::LengthFormatter(std::nullptr_t) : Formatter(nullptr)
    {
    }

    LengthFormatter::LengthFormatter(Adopt adopt) : Formatter(adopt)
    {
    }

    std::string LengthFormatter::string_from_meters(double number_in_meters) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLengthFormatter>(this) stringFromMeters:static_cast<double>(number_in_meters)]);
    }

    std::string LengthFormatter::string_from_value(double value, LengthFormatterUnit unit) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLengthFormatter>(this) stringFromValue:static_cast<double>(value) unit:static_cast<::NSLengthFormatterUnit>(unit)]);
    }

    std::string LengthFormatter::unit_string_from_meters(double number_in_meters, LengthFormatterUnit* unitp) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLengthFormatter>(this) unitStringFromMeters:static_cast<double>(number_in_meters) usedUnit:(::NSLengthFormatterUnit*)(unitp)]);
    }

    std::string LengthFormatter::unit_string_from_value(double value, LengthFormatterUnit unit) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLengthFormatter>(this) unitStringFromValue:static_cast<double>(value) unit:static_cast<::NSLengthFormatterUnit>(unit)]);
    }

    bool LengthFormatter::is_for_person_height_use() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLengthFormatter>(this) isForPersonHeightUse]);
    }

    void LengthFormatter::set_for_person_height_use(bool value) const
    {
        [cocoon::internal::ns<::NSLengthFormatter>(this) setForPersonHeightUse:static_cast<::BOOL>(value)];
    }

    NumberFormatter LengthFormatter::number_formatter() const
    {
        return cocoon::internal::wrap<NumberFormatter>([cocoon::internal::ns<::NSLengthFormatter>(this) numberFormatter]);
    }

    void LengthFormatter::set_number_formatter(const NumberFormatter& value) const
    {
        [cocoon::internal::ns<::NSLengthFormatter>(this) setNumberFormatter:cocoon::internal::native<::NSNumberFormatter>(value)];
    }

    FormattingUnitStyle LengthFormatter::unit_style() const
    {
        return static_cast<FormattingUnitStyle>([cocoon::internal::ns<::NSLengthFormatter>(this) unitStyle]);
    }

    void LengthFormatter::set_unit_style(FormattingUnitStyle value) const
    {
        [cocoon::internal::ns<::NSLengthFormatter>(this) setUnitStyle:static_cast<::NSFormattingUnitStyle>(value)];
    }
}
