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
     * @brief C++ handle for the Objective-C class `NSLengthFormatter` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Formatter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::LengthFormatter length_formatter;
     * length_formatter.set_for_person_height_use(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::LengthFormatter length_formatter{};
     * length_formatter.set_for_person_height_use(true);
     * auto for_person_height_use = length_formatter.is_for_person_height_use();
     * length_formatter.set_number_formatter(cocoon::NumberFormatter());
     * auto number_formatter = length_formatter.number_formatter();
     * length_formatter.set_unit_style(cocoon::FormattingUnitStyle::Short);
     * auto unit_style = length_formatter.unit_style();
     * length_formatter.string_from_meters(1);
     * length_formatter.string_from_value(1, cocoon::LengthFormatterUnit::Millimeter);
     * length_formatter.unit_string_from_value(1, cocoon::LengthFormatterUnit::Millimeter);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nslengthformatter
     */
    class LengthFormatter : public Formatter
    {
    public:
        /// @brief Creates a new `NSLengthFormatter` instance and returns a handle to it.
        explicit LengthFormatter();
        /// @brief Creates a null handle that refers to no native object.
        LengthFormatter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit LengthFormatter(Adopt adopt);
        /**
     * @brief Calls `-[NSLengthFormatter stringFromMeters:]`.
     * @param number_in_meters Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_meters(double number_in_meters) const;
        /**
     * @brief Calls `-[NSLengthFormatter stringFromValue:unit:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_value(double value, LengthFormatterUnit unit) const;
        /**
     * @brief Calls `-[NSLengthFormatter unitStringFromMeters:usedUnit:]`.
     * @param number_in_meters Argument converted to the Objective-C parameter of the same role.
     * @param unitp Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string unit_string_from_meters(double number_in_meters, LengthFormatterUnit* unitp) const;
        /**
     * @brief Calls `-[NSLengthFormatter unitStringFromValue:unit:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string unit_string_from_value(double value, LengthFormatterUnit unit) const;
        /**
     * @brief Returns the `forPersonHeightUse` property of `NSLengthFormatter`.
     * @return The converted Objective-C result.
     */
        bool is_for_person_height_use() const;
        /**
     * @brief Sets the `forPersonHeightUse` property of `NSLengthFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_for_person_height_use(bool value) const;
        /**
     * @brief Returns the `numberFormatter` property of `NSLengthFormatter`.
     * @return The converted Objective-C result.
     */
        NumberFormatter number_formatter() const;
        /**
     * @brief Sets the `numberFormatter` property of `NSLengthFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_number_formatter(const NumberFormatter& value) const;
        /**
     * @brief Returns the `unitStyle` property of `NSLengthFormatter`.
     * @return The converted Objective-C result.
     */
        FormattingUnitStyle unit_style() const;
        /**
     * @brief Sets the `unitStyle` property of `NSLengthFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_unit_style(FormattingUnitStyle value) const;
    };
}
