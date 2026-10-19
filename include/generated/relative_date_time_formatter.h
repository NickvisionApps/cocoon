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
    class Locale;

    /**
     * @brief C++ handle for the Objective-C class `NSRelativeDateTimeFormatter` (Foundation).
     * @details NSRelativeDateTimeFormatter provides locale-aware formatting of a relative date or time, such as "1 hour ago", "in 2 weeks", "yesterday", and "tomorrow." Note that the string produced by the formatter should only be used in a standalone manner as it may not be grammatically correct to embed the string in longer strings.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Formatter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::RelativeDateTimeFormatter relative_date_time_formatter;
     * relative_date_time_formatter.set_calendar(cocoon::Calendar());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::RelativeDateTimeFormatter relative_date_time_formatter{};
     * relative_date_time_formatter.set_calendar(cocoon::Calendar());
     * auto calendar = relative_date_time_formatter.calendar();
     * relative_date_time_formatter.set_date_time_style(cocoon::RelativeDateTimeFormatterStyle::Numeric);
     * auto date_time_style = relative_date_time_formatter.date_time_style();
     * relative_date_time_formatter.set_formatting_context(cocoon::FormattingContext::Unknown);
     * auto formatting_context = relative_date_time_formatter.formatting_context();
     * relative_date_time_formatter.localized_string_for_date(cocoon::Date(), cocoon::Date());
     * relative_date_time_formatter.localized_string_from_date_components(cocoon::DateComponents());
     * relative_date_time_formatter.localized_string_from_time_interval(1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsrelativedatetimeformatter
     */
    class RelativeDateTimeFormatter : public Formatter
    {
    public:
        /// @brief Creates a new `NSRelativeDateTimeFormatter` instance and returns a handle to it.
        explicit RelativeDateTimeFormatter();
        /// @brief Creates a null handle that refers to no native object.
        RelativeDateTimeFormatter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit RelativeDateTimeFormatter(Adopt adopt);
        using Formatter::string_for_object_value;
        /**
     * @brief Calls `-[NSRelativeDateTimeFormatter localizedStringForDate:relativeToDate:]`.
     * @details Formats the date interval from the reference date to the given date using the formatter's calendar.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @param reference_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string localized_string_for_date(const Date& date, const Date& reference_date) const;
        /**
     * @brief Calls `-[NSRelativeDateTimeFormatter localizedStringFromDateComponents:]`.
     * @details Convenience method for formatting a relative time represented by an NSDateComponents object. Negative component values are evaluated as a date in the past. This method formats the value of the least granular unit in the NSDateComponents object, and does not provide a compound format of the date component. Note this method only supports the following components: year, month, week of month, day, hour, minute, and second. The rest will be ignored.
     * @param date_components Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string localized_string_from_date_components(const DateComponents& date_components) const;
        /**
     * @brief Calls `-[NSRelativeDateTimeFormatter localizedStringFromTimeInterval:]`.
     * @details Convenience method for formatting a time interval using the formatter's calendar. Negative time interval is evaluated as a date in the past.
     * @param time_interval Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string localized_string_from_time_interval(double time_interval) const;
        /**
     * @brief Calls `-[NSRelativeDateTimeFormatter stringForObjectValue:]`.
     * @details Inherited from NSFormatter. 'obj' must be an instance of NSDate. Returns nil otherwise. When formatting a relative date using this method, the class uses -[NSDate date] as the reference date.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_for_object_value(const Object& obj) const;
        /**
     * @brief Returns the `calendar` property of `NSRelativeDateTimeFormatter`.
     * @details Specifies the calendar to use for formatting values that do not have an inherent calendar of their own. Defaults to autoupdatingCurrentCalendar. Also resets to autoupdatingCurrentCalendar on assignment of nil.
     * @return The converted Objective-C result.
     */
        Calendar calendar() const;
        /**
     * @brief Sets the `calendar` property of `NSRelativeDateTimeFormatter`.
     * @details Specifies the calendar to use for formatting values that do not have an inherent calendar of their own. Defaults to autoupdatingCurrentCalendar. Also resets to autoupdatingCurrentCalendar on assignment of nil.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_calendar(const Calendar& value) const;
        /**
     * @brief Returns the `dateTimeStyle` property of `NSRelativeDateTimeFormatter`.
     * @details Specifies how to describe a relative date. For example, "yesterday" vs "1 day ago" in English. Default is NSRelativeDateTimeFormatterStyleNumeric.
     * @return The converted Objective-C result.
     */
        RelativeDateTimeFormatterStyle date_time_style() const;
        /**
     * @brief Sets the `dateTimeStyle` property of `NSRelativeDateTimeFormatter`.
     * @details Specifies how to describe a relative date. For example, "yesterday" vs "1 day ago" in English. Default is NSRelativeDateTimeFormatterStyleNumeric.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_time_style(RelativeDateTimeFormatterStyle value) const;
        /**
     * @brief Returns the `formattingContext` property of `NSRelativeDateTimeFormatter`.
     * @details Specifies the formatting context of the output. Default is NSFormattingContextUnknown.
     * @return The converted Objective-C result.
     */
        FormattingContext formatting_context() const;
        /**
     * @brief Sets the `formattingContext` property of `NSRelativeDateTimeFormatter`.
     * @details Specifies the formatting context of the output. Default is NSFormattingContextUnknown.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_formatting_context(FormattingContext value) const;
        /**
     * @brief Returns the `locale` property of `NSRelativeDateTimeFormatter`.
     * @details Specifies the locale of the output string. Defaults to and resets on assignment of nil to the calendar's locale.
     * @return The converted Objective-C result.
     */
        Locale locale() const;
        /**
     * @brief Sets the `locale` property of `NSRelativeDateTimeFormatter`.
     * @details Specifies the locale of the output string. Defaults to and resets on assignment of nil to the calendar's locale.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_locale(const Locale& value) const;
        /**
     * @brief Returns the `unitsStyle` property of `NSRelativeDateTimeFormatter`.
     * @details Specifies how to format the quantity or the name of the unit. For example, "1 day ago" vs "one day ago" in English. Default is NSRelativeDateTimeFormatterUnitsStyleFull.
     * @return The converted Objective-C result.
     */
        RelativeDateTimeFormatterUnitsStyle units_style() const;
        /**
     * @brief Sets the `unitsStyle` property of `NSRelativeDateTimeFormatter`.
     * @details Specifies how to format the quantity or the name of the unit. For example, "1 day ago" vs "one day ago" in English. Default is NSRelativeDateTimeFormatterUnitsStyleFull.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_units_style(RelativeDateTimeFormatterUnitsStyle value) const;
    };
}
