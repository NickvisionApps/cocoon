#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/formatter.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Locale;
    class MeasurementBase;
    class NumberFormatter;
    class Unit;

    /**
     * @brief C++ handle for the Objective-C class `NSMeasurementFormatter` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Formatter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MeasurementFormatter measurement_formatter;
     * measurement_formatter.set_locale(cocoon::Locale());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MeasurementFormatter measurement_formatter{};
     * measurement_formatter.set_locale(cocoon::Locale());
     * auto locale = measurement_formatter.locale();
     * measurement_formatter.set_number_formatter(cocoon::NumberFormatter());
     * auto number_formatter = measurement_formatter.number_formatter();
     * measurement_formatter.set_unit_options(cocoon::MeasurementFormatterUnitOptions::ProvidedUnit);
     * auto unit_options = measurement_formatter.unit_options();
     * measurement_formatter.string_from_unit(cocoon::Unit());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmeasurementformatter
     */
    class MeasurementFormatter : public Formatter
    {
    public:
        /// @brief Creates a new `NSMeasurementFormatter` instance and returns a handle to it.
        explicit MeasurementFormatter();
        /// @brief Creates a null handle that refers to no native object.
        MeasurementFormatter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MeasurementFormatter(Adopt adopt);
        /**
         * @brief Calls `-[NSMeasurementFormatter stringFromMeasurement:]`.
         * @param measurement Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_from_measurement(const MeasurementBase& measurement) const;
        /**
         * @brief Calls `-[NSMeasurementFormatter stringFromUnit:]`.
         * @details \@param An NSUnit \@return A formatted string representing the localized form of the unit without a value attached to it. This method will return [unit symbol] if the provided unit cannot be localized.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_from_unit(const Unit& unit) const;
        /**
         * @brief Returns the `locale` property of `NSMeasurementFormatter`.
         * @details If not specified, locale is set to the user's current locale.
         * @return The converted Objective-C result.
         */
        Locale locale() const;
        /**
         * @brief Sets the `locale` property of `NSMeasurementFormatter`.
         * @details If not specified, locale is set to the user's current locale.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_locale(const Locale& value) const;
        /**
         * @brief Returns the `numberFormatter` property of `NSMeasurementFormatter`.
         * @details If not specified, the number formatter is set up with NSNumberFormatterDecimalStyle.
         * @return The converted Objective-C result.
         */
        NumberFormatter number_formatter() const;
        /**
         * @brief Sets the `numberFormatter` property of `NSMeasurementFormatter`.
         * @details If not specified, the number formatter is set up with NSNumberFormatterDecimalStyle.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_number_formatter(const NumberFormatter& value) const;
        /**
         * @brief Returns the `unitOptions` property of `NSMeasurementFormatter`.
         * @details This property can be set to ensure that the formatter behaves in a way the developer expects, even if it is not standard according to the preferences of the user's locale. If not specified, unitOptions defaults to localizing according to the preferences of the locale. Ex: By default, if unitOptions is set to the empty set, the formatter will do the following: - kilocalories may be formatted as "C" instead of "kcal" depending on the locale. - kilometersPerHour may be formatted as "miles per hour" for US and UK locales but "kilometers per hour" for other locales. However, if NSMeasurementFormatterUnitOptionsProvidedUnit is set, the formatter will do the following: - kilocalories would be formatted as "kcal" in the language of the locale, even if the locale prefers "C". - kilometersPerHour would be formatted as "kilometers per hour" for US and UK locales even though the preference is for "miles per hour." Note that NSMeasurementFormatter will handle converting measurement objects to the preferred units in a particular locale. For instance, if provided a measurement object in kilometers and the set locale is en_US, the formatter will implicitly convert the measurement object to miles and return the formatted string as the equivalent measurement in miles.
         * @return The converted Objective-C result.
         */
        MeasurementFormatterUnitOptions unit_options() const;
        /**
         * @brief Sets the `unitOptions` property of `NSMeasurementFormatter`.
         * @details This property can be set to ensure that the formatter behaves in a way the developer expects, even if it is not standard according to the preferences of the user's locale. If not specified, unitOptions defaults to localizing according to the preferences of the locale. Ex: By default, if unitOptions is set to the empty set, the formatter will do the following: - kilocalories may be formatted as "C" instead of "kcal" depending on the locale. - kilometersPerHour may be formatted as "miles per hour" for US and UK locales but "kilometers per hour" for other locales. However, if NSMeasurementFormatterUnitOptionsProvidedUnit is set, the formatter will do the following: - kilocalories would be formatted as "kcal" in the language of the locale, even if the locale prefers "C". - kilometersPerHour would be formatted as "kilometers per hour" for US and UK locales even though the preference is for "miles per hour." Note that NSMeasurementFormatter will handle converting measurement objects to the preferred units in a particular locale. For instance, if provided a measurement object in kilometers and the set locale is en_US, the formatter will implicitly convert the measurement object to miles and return the formatted string as the equivalent measurement in miles.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_unit_options(MeasurementFormatterUnitOptions value) const;
        /**
         * @brief Returns the `unitStyle` property of `NSMeasurementFormatter`.
         * @details If not specified, unitStyle is set to NSFormattingUnitStyleMedium.
         * @return The converted Objective-C result.
         */
        FormattingUnitStyle unit_style() const;
        /**
         * @brief Sets the `unitStyle` property of `NSMeasurementFormatter`.
         * @details If not specified, unitStyle is set to NSFormattingUnitStyleMedium.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_unit_style(FormattingUnitStyle value) const;
    };
}
