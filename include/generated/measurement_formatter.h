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
     * @details A formatter that provides localized representations of units and measurements. You use the ''string(from:)-wt9y'' method to create a localized representation of an ''NSMeasurement'' object, and you use the ''string(from:)-4hwjz'' method to create a localized representation of an ''Unit'' object. The formatter takes into account the specified ''locale'', ''unitStyle'', and ''unitOptions'' when producing string representations of units and measurements. > Tip: > In Swift, you can use ''Measurement/FormatStyle'' rather than ''MeasurementFormatter''. The ''FormatStyle'' API offers a declarative idiom for customizing the formatting of various types. Also, Foundation caches identical ''FormatStyle'' instances, so you don't need to pass them around your app, or risk wasting memory with duplicate formatters.
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
     * @details Creates and returns a localized string representation of the provided measurement. - Parameters: - measurement: The measurement to be represented. - Returns: A user-readable string that represents the measurement.
     * @param measurement Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_measurement(const MeasurementBase& measurement) const;
        /**
     * @brief Calls `-[NSMeasurementFormatter stringFromUnit:]`.
     * @details Creates and returns a localized string representation of the provided unit of measure. If the unit cannot be localized, the unit's 'symbol' value is used. - Parameters: - unit: The unit of measure to be represented. - Returns: A user-readable string that represents the unit of measure.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_unit(const Unit& unit) const;
        /**
     * @brief Returns the `locale` property of `NSMeasurementFormatter`.
     * @details The locale used when formatting measurements. If not specified, the locale is set to the user's current locale.
     * @return The converted Objective-C result.
     */
        Locale locale() const;
        /**
     * @brief Sets the `locale` property of `NSMeasurementFormatter`.
     * @details The locale used when formatting measurements. If not specified, the locale is set to the user's current locale.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_locale(const Locale& value) const;
        /**
     * @brief Returns the `numberFormatter` property of `NSMeasurementFormatter`.
     * @details The number formatter used to format the numeric value of a measurement. If not specified, the number formatter is set up with 'NSNumberFormatterDecimalStyle'.
     * @return The converted Objective-C result.
     */
        NumberFormatter number_formatter() const;
        /**
     * @brief Sets the `numberFormatter` property of `NSMeasurementFormatter`.
     * @details The number formatter used to format the numeric value of a measurement. If not specified, the number formatter is set up with 'NSNumberFormatterDecimalStyle'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_number_formatter(const NumberFormatter& value) const;
        /**
     * @brief Returns the `unitOptions` property of `NSMeasurementFormatter`.
     * @details The options for how the unit is formatted. This property can be set to ensure that the formatter behaves in a way the developer expects, even if it is not standard according to the preferences of the user's locale. If not specified, 'unitOptions' defaults to localizing according to the preferences of the locale. Note that 'NSMeasurementFormatter' will handle converting measurement objects to the preferred units in a particular locale. For instance, if provided a measurement object in kilometers and the set locale is en_US, the formatter will implicitly convert the measurement object to miles and return the formatted string as the equivalent measurement in miles.
     * @return The converted Objective-C result.
     */
        MeasurementFormatterUnitOptions unit_options() const;
        /**
     * @brief Sets the `unitOptions` property of `NSMeasurementFormatter`.
     * @details The options for how the unit is formatted. This property can be set to ensure that the formatter behaves in a way the developer expects, even if it is not standard according to the preferences of the user's locale. If not specified, 'unitOptions' defaults to localizing according to the preferences of the locale. Note that 'NSMeasurementFormatter' will handle converting measurement objects to the preferred units in a particular locale. For instance, if provided a measurement object in kilometers and the set locale is en_US, the formatter will implicitly convert the measurement object to miles and return the formatted string as the equivalent measurement in miles.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_unit_options(MeasurementFormatterUnitOptions value) const;
        /**
     * @brief Returns the `unitStyle` property of `NSMeasurementFormatter`.
     * @details The unit style used when creating string representations of measurements. If not specified, 'unitStyle' is set to 'NSFormattingUnitStyleMedium'.
     * @return The converted Objective-C result.
     */
        FormattingUnitStyle unit_style() const;
        /**
     * @brief Sets the `unitStyle` property of `NSMeasurementFormatter`.
     * @details The unit style used when creating string representations of measurements. If not specified, 'unitStyle' is set to 'NSFormattingUnitStyleMedium'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_unit_style(FormattingUnitStyle value) const;
    };
}
