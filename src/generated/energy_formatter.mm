#include "generated/energy_formatter.h"
#include "internal.h"

namespace cocoon
{
    EnergyFormatter::EnergyFormatter() : EnergyFormatter(Adopt{cocoon::internal::retain([[::NSEnergyFormatter alloc] init])})
    {
    }

    EnergyFormatter::EnergyFormatter(std::nullptr_t) : Formatter(nullptr)
    {
    }

    EnergyFormatter::EnergyFormatter(Adopt adopt) : Formatter(adopt)
    {
    }

    std::string EnergyFormatter::string_from_joules(double number_in_joules) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSEnergyFormatter>(this) stringFromJoules:static_cast<double>(number_in_joules)]);
    }

    std::string EnergyFormatter::string_from_value(double value, EnergyFormatterUnit unit) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSEnergyFormatter>(this) stringFromValue:static_cast<double>(value) unit:static_cast<::NSEnergyFormatterUnit>(unit)]);
    }

    std::string EnergyFormatter::unit_string_from_joules(double number_in_joules, EnergyFormatterUnit* unitp) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSEnergyFormatter>(this) unitStringFromJoules:static_cast<double>(number_in_joules) usedUnit:(::NSEnergyFormatterUnit*)(unitp)]);
    }

    std::string EnergyFormatter::unit_string_from_value(double value, EnergyFormatterUnit unit) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSEnergyFormatter>(this) unitStringFromValue:static_cast<double>(value) unit:static_cast<::NSEnergyFormatterUnit>(unit)]);
    }

    bool EnergyFormatter::is_for_food_energy_use() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSEnergyFormatter>(this) isForFoodEnergyUse]);
    }

    void EnergyFormatter::set_for_food_energy_use(bool value) const
    {
        [cocoon::internal::ns<::NSEnergyFormatter>(this) setForFoodEnergyUse:static_cast<::BOOL>(value)];
    }

    NumberFormatter EnergyFormatter::number_formatter() const
    {
        return cocoon::internal::wrap<NumberFormatter>([cocoon::internal::ns<::NSEnergyFormatter>(this) numberFormatter]);
    }

    void EnergyFormatter::set_number_formatter(const NumberFormatter& value) const
    {
        [cocoon::internal::ns<::NSEnergyFormatter>(this) setNumberFormatter:cocoon::internal::native<::NSNumberFormatter>(value)];
    }

    FormattingUnitStyle EnergyFormatter::unit_style() const
    {
        return static_cast<FormattingUnitStyle>([cocoon::internal::ns<::NSEnergyFormatter>(this) unitStyle]);
    }

    void EnergyFormatter::set_unit_style(FormattingUnitStyle value) const
    {
        [cocoon::internal::ns<::NSEnergyFormatter>(this) setUnitStyle:static_cast<::NSFormattingUnitStyle>(value)];
    }
}
