#pragma once

#include "generated/availability.h"
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
     * @details NSDateComponentsFormatter provides locale-correct and flexible string formatting of quantities of time, such as "1 day" or "1h 10m", as specified by NSDateComponents. For formatting intervals of time (such as "2PM to 5PM"), see NSDateIntervalFormatter. NSDateComponentsFormatter is thread-safe, in that calling methods on it from multiple threads will not cause crashes or incorrect results, but it makes no attempt to prevent confusion when one thread sets something and another thread isn't expecting it to change.
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
     * @param components Argument converted to the Objective-C parameter of the same role.
     * @param units_style Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string localized_string_from_date_components(const DateComponents& components, DateComponentsFormatterUnitsStyle units_style);
        /**
     * @brief Calls `-[NSDateComponentsFormatter stringForObjectValue:]`.
     * @details 'obj' must be an instance of NSDateComponents.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_for_object_value(const Object& obj) const;
        /**
     * @brief Calls `-[NSDateComponentsFormatter stringFromDate:toDate:]`.
     * @details Normally, NSDateComponentsFormatter will calculate as though counting from referenceDate (e.g. in February, 1 month formatted as a number of days will be 28). -stringFromDate:toDate: calculates from the passed-in startDate instead. See 'allowedUnits' for how the default set of allowed units differs from -stringFromDateComponents:. Note that this is still formatting the quantity of time between the dates, not the pair of dates itself. For strings like "Feb 22nd - Feb 28th", use NSDateIntervalFormatter.
     * @param start_date Argument converted to the Objective-C parameter of the same role.
     * @param end_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_date(const Date& start_date, const Date& end_date) const;
        /**
     * @brief Calls `-[NSDateComponentsFormatter stringFromDateComponents:]`.
     * @details Convenience method for formatting an NSDateComponents object. This calculates the count of the unit(s) starting from referenceDate.
     * @param components Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_date_components(const DateComponents& components) const;
        /**
     * @brief Calls `-[NSDateComponentsFormatter stringFromTimeInterval:]`.
     * @details Convenience method for formatting a number of seconds. See 'allowedUnits' for how the default set of allowed units differs from -stringFromDateComponents:. This calculates the count of the unit(s) from referenceDate to the passed-in time interval.
     * @param ti Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_time_interval(double ti) const;
        /**
     * @brief Returns the `allowedUnits` property of `NSDateComponentsFormatter`.
     * @details Bitmask of units to include. Set to 0 to get the default behavior. Note that, especially if the maximum number of units is low, unit collapsing is on, or zero dropping is on, not all allowed units may actually be used for a given NSDateComponents. Default value is the components of the passed-in NSDateComponents object, or years | months | weeks | days | hours | minutes | seconds if passed an NSTimeInterval or pair of NSDates. Allowed units are: NSCalendarUnitYear NSCalendarUnitMonth NSCalendarUnitWeekOfMonth (used to mean "quantity of weeks") NSCalendarUnitDay NSCalendarUnitHour NSCalendarUnitMinute NSCalendarUnitSecond Specifying any other NSCalendarUnits will result in an exception.
     * @return The converted Objective-C result.
     */
        CalendarUnit allowed_units() const;
        /**
     * @brief Sets the `allowedUnits` property of `NSDateComponentsFormatter`.
     * @details Bitmask of units to include. Set to 0 to get the default behavior. Note that, especially if the maximum number of units is low, unit collapsing is on, or zero dropping is on, not all allowed units may actually be used for a given NSDateComponents. Default value is the components of the passed-in NSDateComponents object, or years | months | weeks | days | hours | minutes | seconds if passed an NSTimeInterval or pair of NSDates. Allowed units are: NSCalendarUnitYear NSCalendarUnitMonth NSCalendarUnitWeekOfMonth (used to mean "quantity of weeks") NSCalendarUnitDay NSCalendarUnitHour NSCalendarUnitMinute NSCalendarUnitSecond Specifying any other NSCalendarUnits will result in an exception.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allowed_units(CalendarUnit value) const;
        /**
     * @brief Returns the `allowsFractionalUnits` property of `NSDateComponentsFormatter`.
     * @details Choose whether non-integer units should be used to handle display of values that can't be exactly represented with the allowed units. For example, if minutes aren't allowed, then "1h 30m" could be formatted as "1.5h". Default is NO.
     * @return The converted Objective-C result.
     */
        bool allows_fractional_units() const;
        /**
     * @brief Sets the `allowsFractionalUnits` property of `NSDateComponentsFormatter`.
     * @details Choose whether non-integer units should be used to handle display of values that can't be exactly represented with the allowed units. For example, if minutes aren't allowed, then "1h 30m" could be formatted as "1.5h". Default is NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_fractional_units(bool value) const;
        /**
     * @brief Returns the `calendar` property of `NSDateComponentsFormatter`.
     * @details Specifies the locale and calendar to use for formatting date components that do not themselves have calendars. Defaults to NSAutoupdatingCurrentCalendar. If set to nil, uses the gregorian calendar with the en_US_POSIX locale.
     * @return The converted Objective-C result.
     */
        Calendar calendar() const;
        /**
     * @brief Sets the `calendar` property of `NSDateComponentsFormatter`.
     * @details Specifies the locale and calendar to use for formatting date components that do not themselves have calendars. Defaults to NSAutoupdatingCurrentCalendar. If set to nil, uses the gregorian calendar with the en_US_POSIX locale.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_calendar(const Calendar& value) const;
        /**
     * @brief Returns the `collapsesLargestUnit` property of `NSDateComponentsFormatter`.
     * @details Choose whether to express largest units just above the threshold for the next lowest unit as a larger quantity of the lower unit. For example: "1m 3s" vs "63s". Default is NO.
     * @return The converted Objective-C result.
     */
        bool collapses_largest_unit() const;
        /**
     * @brief Sets the `collapsesLargestUnit` property of `NSDateComponentsFormatter`.
     * @details Choose whether to express largest units just above the threshold for the next lowest unit as a larger quantity of the lower unit. For example: "1m 3s" vs "63s". Default is NO.
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
     * @details Choose whether to indicate that the allowed units/insignificant units choices lead to inexact results. In some languages, simply prepending "about " to the string will produce incorrect results; this handles those cases correctly. Default is NO.
     * @return The converted Objective-C result.
     */
        bool includes_approximation_phrase() const;
        /**
     * @brief Sets the `includesApproximationPhrase` property of `NSDateComponentsFormatter`.
     * @details Choose whether to indicate that the allowed units/insignificant units choices lead to inexact results. In some languages, simply prepending "about " to the string will produce incorrect results; this handles those cases correctly. Default is NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_includes_approximation_phrase(bool value) const;
        /**
     * @brief Returns the `includesTimeRemainingPhrase` property of `NSDateComponentsFormatter`.
     * @details Choose whether to produce strings like "35 minutes remaining". Default is NO.
     * @return The converted Objective-C result.
     */
        bool includes_time_remaining_phrase() const;
        /**
     * @brief Sets the `includesTimeRemainingPhrase` property of `NSDateComponentsFormatter`.
     * @details Choose whether to produce strings like "35 minutes remaining". Default is NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_includes_time_remaining_phrase(bool value) const;
        /**
     * @brief Returns the `maximumUnitCount` property of `NSDateComponentsFormatter`.
     * @details Choose whether or not, and at which point, to round small units in large values to zero. Examples: 1h 10m 30s, maximumUnitCount set to 0: "1h 10m 30s" 1h 10m 30s, maximumUnitCount set to 2: "1h 10m" 10m 30s, maximumUnitCount set to 0: "10m 30s" 10m 30s, maximumUnitCount set to 2: "10m 30s" Default is 0, which is interpreted as unlimited.
     * @return The converted Objective-C result.
     */
        std::int64_t maximum_unit_count() const;
        /**
     * @brief Sets the `maximumUnitCount` property of `NSDateComponentsFormatter`.
     * @details Choose whether or not, and at which point, to round small units in large values to zero. Examples: 1h 10m 30s, maximumUnitCount set to 0: "1h 10m 30s" 1h 10m 30s, maximumUnitCount set to 2: "1h 10m" 10m 30s, maximumUnitCount set to 0: "10m 30s" 10m 30s, maximumUnitCount set to 2: "10m 30s" Default is 0, which is interpreted as unlimited.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_unit_count(std::int64_t value) const;
        /**
     * @brief Returns the `referenceDate` property of `NSDateComponentsFormatter`.
     * @details Where units have variable length (number of days in a month, number of hours in a day, etc...), NSDateComponentsFormatter will calculate as though counting from the date specified by the referenceDate in the appropriate calendar. Defaults to [NSDate dateWithTimeIntervalSinceReferenceDate:0] at the time of the -stringForObjectValue: call if not set. Set to nil to get the default behavior.
     * @return The converted Objective-C result.
     */
        Date reference_date() const;
        /**
     * @brief Sets the `referenceDate` property of `NSDateComponentsFormatter`.
     * @details Where units have variable length (number of days in a month, number of hours in a day, etc...), NSDateComponentsFormatter will calculate as though counting from the date specified by the referenceDate in the appropriate calendar. Defaults to [NSDate dateWithTimeIntervalSinceReferenceDate:0] at the time of the -stringForObjectValue: call if not set. Set to nil to get the default behavior.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_reference_date(const Date& value) const;
        /**
     * @brief Returns the `unitsStyle` property of `NSDateComponentsFormatter`.
     * @details Choose how to indicate units. For example, 1h 10m vs 1:10. Default is NSDateComponentsFormatterUnitsStylePositional.
     * @return The converted Objective-C result.
     */
        DateComponentsFormatterUnitsStyle units_style() const;
        /**
     * @brief Sets the `unitsStyle` property of `NSDateComponentsFormatter`.
     * @details Choose how to indicate units. For example, 1h 10m vs 1:10. Default is NSDateComponentsFormatterUnitsStylePositional.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_units_style(DateComponentsFormatterUnitsStyle value) const;
        /**
     * @brief Returns the `zeroFormattingBehavior` property of `NSDateComponentsFormatter`.
     * @details Bitmask specifying how to handle zeros in units. This includes both padding and dropping zeros so that a consistent number digits are displayed, causing updating displays to remain more stable. Default is NSDateComponentsFormatterZeroFormattingBehaviorDefault. If the combination of zero formatting behavior and style would lead to ambiguous date formats (for example, 1:10 meaning 1 hour, 10 seconds), NSDateComponentsFormatter will throw an exception.
     * @return The converted Objective-C result.
     */
        DateComponentsFormatterZeroFormattingBehavior zero_formatting_behavior() const;
        /**
     * @brief Sets the `zeroFormattingBehavior` property of `NSDateComponentsFormatter`.
     * @details Bitmask specifying how to handle zeros in units. This includes both padding and dropping zeros so that a consistent number digits are displayed, causing updating displays to remain more stable. Default is NSDateComponentsFormatterZeroFormattingBehaviorDefault. If the combination of zero formatting behavior and style would lead to ambiguous date formats (for example, 1:10 meaning 1 hour, 10 seconds), NSDateComponentsFormatter will throw an exception.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_zero_formatting_behavior(DateComponentsFormatterZeroFormattingBehavior value) const;
    };
}
