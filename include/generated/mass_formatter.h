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
         * @param number_in_kilograms Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_from_kilograms(double number_in_kilograms) const;
        /**
         * @brief Calls `-[NSMassFormatter stringFromValue:unit:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_from_value(double value, MassFormatterUnit unit) const;
        /**
         * @brief Calls `-[NSMassFormatter unitStringFromKilograms:usedUnit:]`.
         * @param number_in_kilograms Argument converted to the Objective-C parameter of the same role.
         * @param unitp Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string unit_string_from_kilograms(double number_in_kilograms, MassFormatterUnit* unitp) const;
        /**
         * @brief Calls `-[NSMassFormatter unitStringFromValue:unit:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string unit_string_from_value(double value, MassFormatterUnit unit) const;
        /**
         * @brief Returns the `forPersonMassUse` property of `NSMassFormatter`.
         * @return The converted Objective-C result.
         */
        bool is_for_person_mass_use() const;
        /**
         * @brief Sets the `forPersonMassUse` property of `NSMassFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_for_person_mass_use(bool value) const;
        /**
         * @brief Returns the `numberFormatter` property of `NSMassFormatter`.
         * @return The converted Objective-C result.
         */
        NumberFormatter number_formatter() const;
        /**
         * @brief Sets the `numberFormatter` property of `NSMassFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_number_formatter(const NumberFormatter& value) const;
        /**
         * @brief Returns the `unitStyle` property of `NSMassFormatter`.
         * @return The converted Objective-C result.
         */
        FormattingUnitStyle unit_style() const;
        /**
         * @brief Sets the `unitStyle` property of `NSMassFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_unit_style(FormattingUnitStyle value) const;
    };
}
