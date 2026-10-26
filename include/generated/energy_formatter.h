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
     * @brief C++ handle for the Objective-C class `NSEnergyFormatter` (Foundation).
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
         * @param number_in_joules Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_from_joules(double number_in_joules) const;
        /**
         * @brief Calls `-[NSEnergyFormatter stringFromValue:unit:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_from_value(double value, EnergyFormatterUnit unit) const;
        /**
         * @brief Calls `-[NSEnergyFormatter unitStringFromJoules:usedUnit:]`.
         * @param number_in_joules Argument converted to the Objective-C parameter of the same role.
         * @param unitp Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string unit_string_from_joules(double number_in_joules, EnergyFormatterUnit* unitp) const;
        /**
         * @brief Calls `-[NSEnergyFormatter unitStringFromValue:unit:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string unit_string_from_value(double value, EnergyFormatterUnit unit) const;
        /**
         * @brief Returns the `forFoodEnergyUse` property of `NSEnergyFormatter`.
         * @return The converted Objective-C result.
         */
        bool is_for_food_energy_use() const;
        /**
         * @brief Sets the `forFoodEnergyUse` property of `NSEnergyFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_for_food_energy_use(bool value) const;
        /**
         * @brief Returns the `numberFormatter` property of `NSEnergyFormatter`.
         * @return The converted Objective-C result.
         */
        NumberFormatter number_formatter() const;
        /**
         * @brief Sets the `numberFormatter` property of `NSEnergyFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_number_formatter(const NumberFormatter& value) const;
        /**
         * @brief Returns the `unitStyle` property of `NSEnergyFormatter`.
         * @return The converted Objective-C result.
         */
        FormattingUnitStyle unit_style() const;
        /**
         * @brief Sets the `unitStyle` property of `NSEnergyFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_unit_style(FormattingUnitStyle value) const;
    };
}
