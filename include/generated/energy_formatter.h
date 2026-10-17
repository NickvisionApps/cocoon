#pragma once

#include "generated/enums.h"
#include "generated/formatter.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class NumberFormatter;

    /**
     * @brief C++ handle for the Objective-C class `NSEnergyFormatter` (Foundation).
     * @details A formatter that provides localized descriptions of energy values. > Note: > As of iOS 10, macOS 10.12, tvOS 10, and watchOS 3, Foundation provides the ''MeasurementFormatter'' class, which can be used to represent quantities of ''UnitEnergy'' to provide equivalent functionality to ''EnergyFormatter''. You are encouraged to transition to these new Foundation Units and Measurements APIs whenever possible.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Formatter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::EnergyFormatter energy_formatter;
     * energy_formatter.set_for_food_energy_use(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::EnergyFormatter energy_formatter{};
     * energy_formatter.set_for_food_energy_use(true);
     * auto for_food_energy_use = energy_formatter.is_for_food_energy_use();
     * energy_formatter.set_number_formatter(cocoon::NumberFormatter());
     * auto number_formatter = energy_formatter.number_formatter();
     * energy_formatter.set_unit_style(cocoon::FormattingUnitStyle::Short);
     * auto unit_style = energy_formatter.unit_style();
     * energy_formatter.string_from_joules(1);
     * energy_formatter.string_from_value(1, cocoon::EnergyFormatterUnit::Joule);
     * energy_formatter.unit_string_from_value(1, cocoon::EnergyFormatterUnit::Joule);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsenergyformatter
     */
    class EnergyFormatter : public Formatter
    {
    public:
        /// @brief Creates a new `NSEnergyFormatter` instance and returns a handle to it.
        explicit EnergyFormatter();
        /// @brief Creates a null handle that refers to no native object.
        EnergyFormatter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit EnergyFormatter(Adopt adopt);
        /**
     * @brief Calls `-[NSEnergyFormatter stringFromJoules:]`.
     * @details Returns an energy string for the provided value in joules. Formats a number in joules to a localized string with the locale-appropriate unit and an appropriate scale (e.g. 10.3J = 2.46cal in the US locale).
     * @param number_in_joules Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_joules(double number_in_joules) const;
        /**
     * @brief Calls `-[NSEnergyFormatter stringFromValue:unit:]`.
     * @details Returns an energy string for the provided value and unit.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_value(double value, EnergyFormatterUnit unit) const;
        /**
     * @brief Calls `-[NSEnergyFormatter unitStringFromJoules:usedUnit:]`.
     * @details Returns a unit string based on the provided value in joules. Returns the locale-appropriate unit, the same unit used by 'stringFromJoules:'.
     * @param number_in_joules Argument converted to the Objective-C parameter of the same role.
     * @param unitp Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string unit_string_from_joules(double number_in_joules, EnergyFormatterUnit* unitp) const;
        /**
     * @brief Calls `-[NSEnergyFormatter unitStringFromValue:unit:]`.
     * @details Returns a unit string for the provided value and unit. Returns a localized string of the given unit, and if the unit is singular or plural is based on the given number.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string unit_string_from_value(double value, EnergyFormatterUnit unit) const;
        /**
     * @brief Returns the `forFoodEnergyUse` property of `NSEnergyFormatter`.
     * @details A Boolean value that indicates whether the resulting string is used to represent food energy. The default value is 'NO'. If set to 'YES', 'NSEnergyFormatterUnitKilocalorie' may be displayed as "C" instead of "kcal".
     * @return The converted Objective-C result.
     */
        bool is_for_food_energy_use() const;
        /**
     * @brief Sets the `forFoodEnergyUse` property of `NSEnergyFormatter`.
     * @details A Boolean value that indicates whether the resulting string is used to represent food energy. The default value is 'NO'. If set to 'YES', 'NSEnergyFormatterUnitKilocalorie' may be displayed as "C" instead of "kcal".
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_for_food_energy_use(bool value) const;
        /**
     * @brief Returns the `numberFormatter` property of `NSEnergyFormatter`.
     * @details The number formatter used to format the numbers in an energy string. The default value is an 'NSNumberFormatter' with 'NSNumberFormatterDecimalStyle'.
     * @return The converted Objective-C result.
     */
        NumberFormatter number_formatter() const;
        /**
     * @brief Sets the `numberFormatter` property of `NSEnergyFormatter`.
     * @details The number formatter used to format the numbers in an energy string. The default value is an 'NSNumberFormatter' with 'NSNumberFormatterDecimalStyle'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_number_formatter(const NumberFormatter& value) const;
        /**
     * @brief Returns the `unitStyle` property of `NSEnergyFormatter`.
     * @details The unit style used when creating string representations of energy values. The default value is 'NSFormattingUnitStyleMedium'.
     * @return The converted Objective-C result.
     */
        FormattingUnitStyle unit_style() const;
        /**
     * @brief Sets the `unitStyle` property of `NSEnergyFormatter`.
     * @details The unit style used when creating string representations of energy values. The default value is 'NSFormattingUnitStyleMedium'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_unit_style(FormattingUnitStyle value) const;
    };
}
