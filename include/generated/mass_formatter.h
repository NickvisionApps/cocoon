#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/formatter.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class NumberFormatter;

    /**
     * @brief C++ handle for the Objective-C class `NSMassFormatter` (Foundation).
     * @details A formatter that provides localized descriptions of mass and weight values. > Note: > As of iOS 10, macOS 10.12, tvOS 10, and watchOS 3, Foundation provides the ''MeasurementFormatter'' class, which can be used to represent quantities of ''UnitMass'' to provide equivalent functionality to ''MassFormatter''. You are encouraged to transition to these new Foundation Units and Measurements APIs whenever possible.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Formatter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MassFormatter mass_formatter;
     * mass_formatter.set_for_person_mass_use(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MassFormatter mass_formatter{};
     * mass_formatter.set_for_person_mass_use(true);
     * auto for_person_mass_use = mass_formatter.is_for_person_mass_use();
     * mass_formatter.set_number_formatter(cocoon::NumberFormatter());
     * auto number_formatter = mass_formatter.number_formatter();
     * mass_formatter.set_unit_style(cocoon::FormattingUnitStyle::Short);
     * auto unit_style = mass_formatter.unit_style();
     * mass_formatter.string_from_kilograms(1);
     * mass_formatter.string_from_value(1, cocoon::MassFormatterUnit::Gram);
     * mass_formatter.unit_string_from_value(1, cocoon::MassFormatterUnit::Gram);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmassformatter
     */
    class MassFormatter : public Formatter
    {
    public:
        /// @brief Creates a new `NSMassFormatter` instance and returns a handle to it.
        explicit MassFormatter();
        /// @brief Creates a null handle that refers to no native object.
        MassFormatter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MassFormatter(Adopt adopt);
        /**
     * @brief Calls `-[NSMassFormatter stringFromKilograms:]`.
     * @details Returns a mass string for the provided value in kilograms. Formats a number in kilograms to a localized string with the locale-appropriate unit and an appropriate scale (e.g. 1.2kg = 2.64lb in the US locale).
     * @param number_in_kilograms Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_kilograms(double number_in_kilograms) const;
        /**
     * @brief Calls `-[NSMassFormatter stringFromValue:unit:]`.
     * @details Returns a mass string for the provided value and unit.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_value(double value, MassFormatterUnit unit) const;
        /**
     * @brief Calls `-[NSMassFormatter unitStringFromKilograms:usedUnit:]`.
     * @details Returns a unit string based on the provided value in kilograms. Returns the locale-appropriate unit, the same unit used by 'stringFromKilograms:'.
     * @param number_in_kilograms Argument converted to the Objective-C parameter of the same role.
     * @param unitp Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string unit_string_from_kilograms(double number_in_kilograms, MassFormatterUnit* unitp) const;
        /**
     * @brief Calls `-[NSMassFormatter unitStringFromValue:unit:]`.
     * @details Returns a unit string for the provided value and unit. Returns a localized string of the given unit, and if the unit is singular or plural is based on the given number.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string unit_string_from_value(double value, MassFormatterUnit unit) const;
        /**
     * @brief Returns the `forPersonMassUse` property of `NSMassFormatter`.
     * @details A Boolean value that indicates whether the resulting string represents a person's mass. The default value is 'NO'. If set to 'YES', the number argument for 'stringFromKilograms:' and 'unitStringFromKilograms:usedUnit:' is considered as a person's mass.
     * @return The converted Objective-C result.
     */
        bool is_for_person_mass_use() const;
        /**
     * @brief Sets the `forPersonMassUse` property of `NSMassFormatter`.
     * @details A Boolean value that indicates whether the resulting string represents a person's mass. The default value is 'NO'. If set to 'YES', the number argument for 'stringFromKilograms:' and 'unitStringFromKilograms:usedUnit:' is considered as a person's mass.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_for_person_mass_use(bool value) const;
        /**
     * @brief Returns the `numberFormatter` property of `NSMassFormatter`.
     * @details The number formatter used to format the numbers in a mass string. The default value is an 'NSNumberFormatter' with 'NSNumberFormatterDecimalStyle'.
     * @return The converted Objective-C result.
     */
        NumberFormatter number_formatter() const;
        /**
     * @brief Sets the `numberFormatter` property of `NSMassFormatter`.
     * @details The number formatter used to format the numbers in a mass string. The default value is an 'NSNumberFormatter' with 'NSNumberFormatterDecimalStyle'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_number_formatter(const NumberFormatter& value) const;
        /**
     * @brief Returns the `unitStyle` property of `NSMassFormatter`.
     * @details The unit style used when creating string representations of mass values. The default value is 'NSFormattingUnitStyleMedium'.
     * @return The converted Objective-C result.
     */
        FormattingUnitStyle unit_style() const;
        /**
     * @brief Sets the `unitStyle` property of `NSMassFormatter`.
     * @details The unit style used when creating string representations of mass values. The default value is 'NSFormattingUnitStyleMedium'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_unit_style(FormattingUnitStyle value) const;
    };
}
