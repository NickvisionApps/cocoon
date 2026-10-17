#pragma once

#include "generated/enums.h"
#include "generated/formatter.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Calendar;
    class Date;
    class DateComponents;

    /**
     * @brief C++ handle for the Objective-C class `NSDateComponentsFormatter` (Foundation).
     * @details A formatter that creates string representations of quantities of time. An ''DateComponentsFormatter'' object takes quantities of time and formats them as a user-readable string. Use a date components formatter to create strings for your app's interface. The formatter object has many options for creating both abbreviated and expanded strings. The formatter takes the current user's locale and language into account when generating strings. To use this class, create an instance, configure its properties, and call one of its methods to generate an appropriate string. The properties of this class let you configure the calendar and specify the date and time units you want displayed in the resulting string. The listing below shows how to configure a formatter to create the string "About 5 minutes remaining". \@TabNavigator { \@Tab("Swift") { '''swift let formatter = DateComponentsFormatter() formatter.unitsStyle = .full formatter.includesApproximationPhrase = true formatter.includesTimeRemainingPhrase = true formatter.allowedUnits = [.minute] // Use the configured formatter to generate the string. let outputString = formatter.string(from: 300.0) ''' } \@Tab("Objective-C") { '''objc NSDateComponentsFormatter formatter = [[NSDateComponentsFormatter alloc] init]; formatter.unitsStyle = NSDateComponentsFormatterUnitsStyleFull; formatter.includesApproximationPhrase = YES; formatter.includesTimeRemainingPhrase = YES; formatter.allowedUnits = NSCalendarUnitMinute; // Use the configured formatter to generate the string. NSString outputString = [formatter stringFromTimeInterval:300.0]; ''' } } The methods of this class may be called safely from any thread of your app. It is also safe to share a single instance of this class from multiple threads, with the caveat that you should not change the configuration of the object while another thread is using it to generate a string. > Tip: > In Swift, you can use ''Date/RelativeFormatStyle'' rather than ''DateComponentsFormatter''. The ''FormatStyle'' API offers a declarative idiom for customizing the formatting of various types. Also, Foundation caches identical ''FormatStyle'' instances, so you don't need to pass them around your app, or risk wasting memory with duplicate formatters.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Formatter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DateComponentsFormatter date_components_formatter;
     * date_components_formatter.set_allowed_units(cocoon::CalendarUnit::Era);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DateComponentsFormatter date_components_formatter{};
     * date_components_formatter.set_allowed_units(cocoon::CalendarUnit::Era);
     * auto allowed_units = date_components_formatter.allowed_units();
     * date_components_formatter.set_allows_fractional_units(true);
     * auto allows_fractional_units = date_components_formatter.allows_fractional_units();
     * date_components_formatter.set_calendar(cocoon::Calendar());
     * auto calendar = date_components_formatter.calendar();
     * date_components_formatter.string_from_date(cocoon::Date(), cocoon::Date());
     * date_components_formatter.string_from_date_components(cocoon::DateComponents());
     * date_components_formatter.string_from_time_interval(1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdatecomponentsformatter
     */
    class DateComponentsFormatter : public Formatter
    {
    public:
        /// @brief Creates a new `NSDateComponentsFormatter` instance and returns a handle to it.
        explicit DateComponentsFormatter();
        /// @brief Creates a null handle that refers to no native object.
        DateComponentsFormatter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DateComponentsFormatter(Adopt adopt);
        using Formatter::string_for_object_value;
        /**
     * @brief Calls `+[NSDateComponentsFormatter localizedStringFromDateComponents:unitsStyle:]`.
     * @details Returns a localized string based on the specified date components and style option. Use this convenience method to format a string using the default formatter values, with the exception of the 'unitsStyle' value. \@param components The value to format. \@param unitsStyle The style for the resulting units. Use this parameter to specify whether you want the resulting string to use an abbreviated or more spelled out format. \@return A string containing the localized date and time information.
     * @param components Argument converted to the Objective-C parameter of the same role.
     * @param units_style Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string localized_string_from_date_components(const DateComponents& components, DateComponentsFormatterUnitsStyle units_style);
        /**
     * @brief Calls `-[NSDateComponentsFormatter stringForObjectValue:]`.
     * @details Returns a formatted string based on the date information in the specified object. \@param obj An object containing the date and time information to format. The object in this parameter must be an instance of 'NSDateComponents'. \@return A formatted string representing the specified date information.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_for_object_value(const Object& obj) const;
        /**
     * @brief Calls `-[NSDateComponentsFormatter stringFromDate:toDate:]`.
     * @details Returns a formatted string based on the time difference between two dates. This method calculates the elapsed time between the 'startDate' and 'endDate' values and uses that information to generate the string. For example, if there is exactly one hour and ten minutes difference between the start and end dates, generating an abbreviated string would result in a string of "1h 10m". Note that this is still formatting the quantity of time between the dates, not the pair of dates itself. For strings like "Feb 22nd - Feb 28th", use 'NSDateIntervalFormatter'. \@param startDate The start time. This parameter must not be 'nil'. \@param endDate The end time. This parameter must not be 'nil'. \@return A formatted string representing the specified time information.
     * @param start_date Argument converted to the Objective-C parameter of the same role.
     * @param end_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_date(const Date& start_date, const Date& end_date) const;
        /**
     * @brief Calls `-[NSDateComponentsFormatter stringFromDateComponents:]`.
     * @details Returns a formatted string based on the specified date component information. Use this method to format date information that is already broken down into the component day and time values. \@param components A date components object containing the date and time information to format. The 'allowedUnits' property determines which date components are actually used to generate the string. All other date components are ignored. This parameter must not be 'nil'. \@return A formatted string representing the specified date information.
     * @param components Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_date_components(const DateComponents& components) const;
        /**
     * @brief Calls `-[NSDateComponentsFormatter stringFromTimeInterval:]`.
     * @details Returns a formatted string based on the specified number of seconds. This method formats the specified number of seconds into the appropriate units. For example, if the formatter allows the display of minutes and seconds, creating an abbreviated string for the value 70 seconds results in the string "1m 10s". \@param ti The time interval, measured in seconds. The value must be a finite number. Negative numbers are treated as positive numbers when creating the string. \@return A formatted string representing the specified time interval.
     * @param ti Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_time_interval(double ti) const;
        /**
     * @brief Returns the `allowedUnits` property of `NSDateComponentsFormatter`.
     * @details The bitmask of calendrical units such as day and month to include in the output string. The allowed calendar units are: - 'NSCalendarUnitYear' - 'NSCalendarUnitMonth' - 'NSCalendarUnitWeekOfMonth' (used to mean "quantity of weeks") - 'NSCalendarUnitDay' - 'NSCalendarUnitHour' - 'NSCalendarUnitMinute' - 'NSCalendarUnitSecond' Assigning any other calendar units to this property results in an exception.
     * @return The converted Objective-C result.
     */
        CalendarUnit allowed_units() const;
        /**
     * @brief Sets the `allowedUnits` property of `NSDateComponentsFormatter`.
     * @details The bitmask of calendrical units such as day and month to include in the output string. The allowed calendar units are: - 'NSCalendarUnitYear' - 'NSCalendarUnitMonth' - 'NSCalendarUnitWeekOfMonth' (used to mean "quantity of weeks") - 'NSCalendarUnitDay' - 'NSCalendarUnitHour' - 'NSCalendarUnitMinute' - 'NSCalendarUnitSecond' Assigning any other calendar units to this property results in an exception.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allowed_units(CalendarUnit value) const;
        /**
     * @brief Returns the `allowsFractionalUnits` property of `NSDateComponentsFormatter`.
     * @details A Boolean indicating whether non-integer units may be used for values. Fractional units may be used when a value cannot be exactly represented using the available units. For example, if minutes are not allowed, the value "1h 30m" could be formatted as "1.5h". The default value of this property is 'NO'.
     * @return The converted Objective-C result.
     */
        bool allows_fractional_units() const;
        /**
     * @brief Sets the `allowsFractionalUnits` property of `NSDateComponentsFormatter`.
     * @details A Boolean indicating whether non-integer units may be used for values. Fractional units may be used when a value cannot be exactly represented using the available units. For example, if minutes are not allowed, the value "1h 30m" could be formatted as "1.5h". The default value of this property is 'NO'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_fractional_units(bool value) const;
        /**
     * @brief Returns the `calendar` property of `NSDateComponentsFormatter`.
     * @details The default calendar to use when formatting date components. The formatter uses the calendar in this property to format values that do not have an inherent calendar of their own. For example, the formatter uses this calendar when formatting an 'NSTimeInterval' value. The default value of this property is the autoupdating current calendar. Setting this property to 'nil' causes the formatter to use the Gregorian calendar with the 'en_US_POSIX' locale.
     * @return The converted Objective-C result.
     */
        Calendar calendar() const;
        /**
     * @brief Sets the `calendar` property of `NSDateComponentsFormatter`.
     * @details The default calendar to use when formatting date components. The formatter uses the calendar in this property to format values that do not have an inherent calendar of their own. For example, the formatter uses this calendar when formatting an 'NSTimeInterval' value. The default value of this property is the autoupdating current calendar. Setting this property to 'nil' causes the formatter to use the Gregorian calendar with the 'en_US_POSIX' locale.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_calendar(const Calendar& value) const;
        /**
     * @brief Returns the `collapsesLargestUnit` property of `NSDateComponentsFormatter`.
     * @details A Boolean value indicating whether to collapse the largest unit into smaller units when a certain threshold is met. An example of when this property might apply is when expressing 63 seconds worth of time. When this property is set to 'YES', the formatted value would be "63s". When the value of this property is 'NO', the formatted value would be "1m 3s". The default value of this property is 'NO'.
     * @return The converted Objective-C result.
     */
        bool collapses_largest_unit() const;
        /**
     * @brief Sets the `collapsesLargestUnit` property of `NSDateComponentsFormatter`.
     * @details A Boolean value indicating whether to collapse the largest unit into smaller units when a certain threshold is met. An example of when this property might apply is when expressing 63 seconds worth of time. When this property is set to 'YES', the formatted value would be "63s". When the value of this property is 'NO', the formatted value would be "1m 3s". The default value of this property is 'NO'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_collapses_largest_unit(bool value) const;
        /**
     * @brief Returns the `formattingContext` property of `NSDateComponentsFormatter`.
     * @details Not yet supported.
     * @return The converted Objective-C result.
     */
        FormattingContext formatting_context() const;
        /**
     * @brief Sets the `formattingContext` property of `NSDateComponentsFormatter`.
     * @details Not yet supported.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_formatting_context(FormattingContext value) const;
        /**
     * @brief Returns the `includesApproximationPhrase` property of `NSDateComponentsFormatter`.
     * @details A Boolean value indicating whether the resulting phrase reflects an inexact time value. Setting the value of this property to 'YES' adds phrasing to output strings to reflect that the given time value is approximate and not exact. Using this property yields more correct phrasing than simply prepending the string "About" to an output string. The default value of this property is 'NO'.
     * @return The converted Objective-C result.
     */
        bool includes_approximation_phrase() const;
        /**
     * @brief Sets the `includesApproximationPhrase` property of `NSDateComponentsFormatter`.
     * @details A Boolean value indicating whether the resulting phrase reflects an inexact time value. Setting the value of this property to 'YES' adds phrasing to output strings to reflect that the given time value is approximate and not exact. Using this property yields more correct phrasing than simply prepending the string "About" to an output string. The default value of this property is 'NO'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_includes_approximation_phrase(bool value) const;
        /**
     * @brief Returns the `includesTimeRemainingPhrase` property of `NSDateComponentsFormatter`.
     * @details A Boolean value indicating whether output strings reflect the amount of time remaining. Setting this property to 'YES' results in output strings like "30 minutes remaining". The default value of this property is 'NO'.
     * @return The converted Objective-C result.
     */
        bool includes_time_remaining_phrase() const;
        /**
     * @brief Sets the `includesTimeRemainingPhrase` property of `NSDateComponentsFormatter`.
     * @details A Boolean value indicating whether output strings reflect the amount of time remaining. Setting this property to 'YES' results in output strings like "30 minutes remaining". The default value of this property is 'NO'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_includes_time_remaining_phrase(bool value) const;
        /**
     * @brief Returns the `maximumUnitCount` property of `NSDateComponentsFormatter`.
     * @details The maximum number of time units to include in the output string. Use this property to limit the number of units displayed in the resulting string. For example, with this property set to 2, instead of "1h 10m, 30s", the resulting string would be "1h 10m". Use this property when you are constrained for space or want to round up values to the nearest large unit. The default value of this property is '0', which does not cause the elimination of any units.
     * @return The converted Objective-C result.
     */
        std::int64_t maximum_unit_count() const;
        /**
     * @brief Sets the `maximumUnitCount` property of `NSDateComponentsFormatter`.
     * @details The maximum number of time units to include in the output string. Use this property to limit the number of units displayed in the resulting string. For example, with this property set to 2, instead of "1h 10m, 30s", the resulting string would be "1h 10m". Use this property when you are constrained for space or want to round up values to the nearest large unit. The default value of this property is '0', which does not cause the elimination of any units.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_unit_count(std::int64_t value) const;
        /**
     * @brief Returns the `referenceDate` property of `NSDateComponentsFormatter`.
     * @details Where units have variable length (number of days in a month, number of hours in a day, etc.), 'NSDateComponentsFormatter' will calculate as though counting from the date specified by the 'referenceDate' in the appropriate calendar. Defaults to '[NSDate dateWithTimeIntervalSinceReferenceDate:0]' at the time of the '-stringForObjectValue:' call if not set. Set to 'nil' to get the default behavior.
     * @return The converted Objective-C result.
     */
        Date reference_date() const;
        /**
     * @brief Sets the `referenceDate` property of `NSDateComponentsFormatter`.
     * @details Where units have variable length (number of days in a month, number of hours in a day, etc.), 'NSDateComponentsFormatter' will calculate as though counting from the date specified by the 'referenceDate' in the appropriate calendar. Defaults to '[NSDate dateWithTimeIntervalSinceReferenceDate:0]' at the time of the '-stringForObjectValue:' call if not set. Set to 'nil' to get the default behavior.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_reference_date(const Date& value) const;
        /**
     * @brief Returns the `unitsStyle` property of `NSDateComponentsFormatter`.
     * @details The formatting style for unit names. Configures the strings to use (if any) for unit names such as days, hours, minutes, and seconds. Use this property to specify whether you want abbreviated or shortened versions of unit names---for example, "hrs" instead of "hours". The default value of this property is 'NSDateComponentsFormatterUnitsStylePositional'.
     * @return The converted Objective-C result.
     */
        DateComponentsFormatterUnitsStyle units_style() const;
        /**
     * @brief Sets the `unitsStyle` property of `NSDateComponentsFormatter`.
     * @details The formatting style for unit names. Configures the strings to use (if any) for unit names such as days, hours, minutes, and seconds. Use this property to specify whether you want abbreviated or shortened versions of unit names---for example, "hrs" instead of "hours". The default value of this property is 'NSDateComponentsFormatterUnitsStylePositional'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_units_style(DateComponentsFormatterUnitsStyle value) const;
        /**
     * @brief Returns the `zeroFormattingBehavior` property of `NSDateComponentsFormatter`.
     * @details The formatting style for units whose value is 0. When the value for a particular unit is 0, the zero formatting behavior determines whether that value is retained or omitted from any resulting strings. For example, when the formatting behavior is 'NSDateComponentsFormatterZeroFormattingBehaviorDropTrailing', the value of one hour, ten minutes, and zero seconds would omit the mention of seconds. The default value of this property is 'NSDateComponentsFormatterZeroFormattingBehaviorDefault'.
     * @return The converted Objective-C result.
     */
        DateComponentsFormatterZeroFormattingBehavior zero_formatting_behavior() const;
        /**
     * @brief Sets the `zeroFormattingBehavior` property of `NSDateComponentsFormatter`.
     * @details The formatting style for units whose value is 0. When the value for a particular unit is 0, the zero formatting behavior determines whether that value is retained or omitted from any resulting strings. For example, when the formatting behavior is 'NSDateComponentsFormatterZeroFormattingBehaviorDropTrailing', the value of one hour, ten minutes, and zero seconds would omit the mention of seconds. The default value of this property is 'NSDateComponentsFormatterZeroFormattingBehaviorDefault'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_zero_formatting_behavior(DateComponentsFormatterZeroFormattingBehavior value) const;
    };
}
