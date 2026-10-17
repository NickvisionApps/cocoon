#include "generated/mass_formatter.h"
#include "internal.h"

namespace cocoon
{
    MassFormatter::MassFormatter() : MassFormatter(Adopt{cocoon::internal::retain([[::NSMassFormatter alloc] init])})
    {
    }

    MassFormatter::MassFormatter(std::nullptr_t) : Formatter(nullptr)
    {
    }

    MassFormatter::MassFormatter(Adopt adopt) : Formatter(adopt)
    {
    }

    std::string MassFormatter::string_from_kilograms(double number_in_kilograms) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMassFormatter>(this) stringFromKilograms:static_cast<double>(number_in_kilograms)]);
    }

    std::string MassFormatter::string_from_value(double value, MassFormatterUnit unit) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMassFormatter>(this) stringFromValue:static_cast<double>(value) unit:static_cast<::NSMassFormatterUnit>(unit)]);
    }

    std::string MassFormatter::unit_string_from_kilograms(double number_in_kilograms, MassFormatterUnit* unitp) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMassFormatter>(this) unitStringFromKilograms:static_cast<double>(number_in_kilograms) usedUnit:(::NSMassFormatterUnit*)(unitp)]);
    }

    std::string MassFormatter::unit_string_from_value(double value, MassFormatterUnit unit) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMassFormatter>(this) unitStringFromValue:static_cast<double>(value) unit:static_cast<::NSMassFormatterUnit>(unit)]);
    }

    bool MassFormatter::is_for_person_mass_use() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMassFormatter>(this) isForPersonMassUse]);
    }

    void MassFormatter::set_for_person_mass_use(bool value) const
    {
        [cocoon::internal::ns<::NSMassFormatter>(this) setForPersonMassUse:static_cast<::BOOL>(value)];
    }

    NumberFormatter MassFormatter::number_formatter() const
    {
        return cocoon::internal::wrap<NumberFormatter>([cocoon::internal::ns<::NSMassFormatter>(this) numberFormatter]);
    }

    void MassFormatter::set_number_formatter(const NumberFormatter& value) const
    {
        [cocoon::internal::ns<::NSMassFormatter>(this) setNumberFormatter:cocoon::internal::native<::NSNumberFormatter>(value)];
    }

    FormattingUnitStyle MassFormatter::unit_style() const
    {
        return static_cast<FormattingUnitStyle>([cocoon::internal::ns<::NSMassFormatter>(this) unitStyle]);
    }

    void MassFormatter::set_unit_style(FormattingUnitStyle value) const
    {
        [cocoon::internal::ns<::NSMassFormatter>(this) setUnitStyle:static_cast<::NSFormattingUnitStyle>(value)];
    }
}
