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
    class DateInterval;
    class Locale;
    class TimeZone;

    /**
     * @brief C++ handle for the Objective-C class `NSDateIntervalFormatter` (Foundation).
     * @details A formatter that creates string representations of time intervals. A ''DateIntervalFormatter'' object creates user-readable strings from pairs of dates. Use a date interval formatter to create user-readable strings of the form \\\<start\\> '-' \\\<end\\> for your app's interface, where \\\<start\\> and \\\<end\\> are date values that you supply. The formatter uses locale and language information, along with custom formatting options, to define the content of the resulting string. You can specify different styles for the date and time information in each date value. To use this class, create an instance, configure its properties, and call the ''string(from:to:)'' method to generate a string. The properties of this class let you configure the calendar and specify the style to apply to date and time values. Given a current date of January 16, 2015, Configuring the Formatter Options shows how to configure a formatter object and generate the string "1/16/15 - 1/17/15". Configuring a formatter object \@TabNavigator { \@Tab("Swift") { '''swift let formatter = DateIntervalFormatter() formatter.dateStyle = .short formatter.timeStyle = .none // Create two dates that are exactly 1 day apart. let startDate = Date() let endDate = Date(timeInterval: 86400, since: startDate) // Use the configured formatter to generate the string. let outputString = formatter.string(from: startDate, to: endDate) ''' } \@Tab("Objective-C") { '''objc NSDateIntervalFormatter formatter = [[NSDateIntervalFormatter alloc] init]; formatter.dateStyle = NSDateIntervalFormatterShortStyle; formatter.timeStyle = NSDateIntervalFormatterNoStyle; // Create two dates that are exactly 1 day apart. NSDate startDate = [NSDate date]; NSDate endDate = [NSDate dateWithTimeInterval:86400 sinceDate:startDate]; // Use the configured formatter to generate the string. NSString outputString = [formatter stringFromDate:startDate toDate:endDate]; ''' } } > Note: > Always set to the ''dateStyle'' and ''timeStyle'' properties to appropriate values before generating any strings. The ''string(from:to:)'' method may be called safely from any thread of your app. It is also safe to share a single instance of this class from multiple threads, with the caveat that you should not change the configuration of the object while another thread is using it to generate a string. > Tip: > In Swift, you can use ''Date/IntervalFormatStyle'' rather than ''DateIntervalFormatter''. The ''FormatStyle'' API offers a declarative idiom for customizing the formatting of various types. Also, Foundation caches identical ''FormatStyle'' instances, so you don't need to pass them around your app, or risk wasting memory with duplicate formatters.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Formatter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DateIntervalFormatter date_interval_formatter;
     * date_interval_formatter.set_calendar(cocoon::Calendar());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DateIntervalFormatter date_interval_formatter{};
     * date_interval_formatter.set_calendar(cocoon::Calendar());
     * auto calendar = date_interval_formatter.calendar();
     * date_interval_formatter.set_date_style(cocoon::DateIntervalFormatterStyle::NoStyle);
     * auto date_style = date_interval_formatter.date_style();
     * date_interval_formatter.set_date_template("text");
     * auto date_template = date_interval_formatter.date_template();
     * date_interval_formatter.string_from_date(cocoon::Date(), cocoon::Date());
     * date_interval_formatter.string_from_date_interval(cocoon::DateInterval());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdateintervalformatter
     */
    class DateIntervalFormatter : public Formatter
    {
    public:
        /// @brief Creates a new `NSDateIntervalFormatter` instance and returns a handle to it.
        explicit DateIntervalFormatter();
        /// @brief Creates a null handle that refers to no native object.
        DateIntervalFormatter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DateIntervalFormatter(Adopt adopt);
        /**
     * @brief Calls `-[NSDateIntervalFormatter stringFromDate:toDate:]`.
     * @details Returns a formatted date interval from the specified start date to end date. If the range is smaller than the resolution specified by the 'dateTemplate', a single date format will be produced. If the range is larger than the format specified by the 'dateTemplate', a locale-specific fallback will be used to format the items missing from the pattern. For example, if the range is 2010-03-04 07:56 - 2010-03-04 19:56 (12 hours) - The pattern 'jm' will produce for 'en_US', "7:56 AM - 7:56 PM" for 'en_GB', "7:56 - 19:56" - The pattern 'MMMd' will produce for 'en_US', "Mar 4" for 'en_GB', "4 Mar" If the range is 2010-03-04 07:56 - 2010-03-08 16:11 (4 days, 8 hours, 15 minutes) - The pattern 'jm' will produce for 'en_US', "3/4/2010 7:56 AM - 3/8/2010 4:11 PM" for 'en_GB', "4/3/2010 7:56 - 8/3/2010 16:11" - The pattern 'MMMd' will produce for 'en_US', "Mar 4-8" for 'en_GB', "4-8 Mar"
     * @param from_date Argument converted to the Objective-C parameter of the same role.
     * @param to_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_date(const Date& from_date, const Date& to_date) const;
        /**
     * @brief Calls `-[NSDateIntervalFormatter stringFromDateInterval:]`.
     * @details Returns a formatted string for the given date interval.
     * @param date_interval Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_date_interval(const DateInterval& date_interval) const;
        /**
     * @brief Returns the `calendar` property of `NSDateIntervalFormatter`.
     * @details The calendar for the formatter. Default is the calendar of the locale.
     * @return The converted Objective-C result.
     */
        Calendar calendar() const;
        /**
     * @brief Sets the `calendar` property of `NSDateIntervalFormatter`.
     * @details The calendar for the formatter. Default is the calendar of the locale.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_calendar(const Calendar& value) const;
        /**
     * @brief Returns the `dateStyle` property of `NSDateIntervalFormatter`.
     * @details The date style for the formatter. Default is 'NSDateIntervalFormatterNoStyle'.
     * @return The converted Objective-C result.
     */
        DateIntervalFormatterStyle date_style() const;
        /**
     * @brief Sets the `dateStyle` property of `NSDateIntervalFormatter`.
     * @details The date style for the formatter. Default is 'NSDateIntervalFormatterNoStyle'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_style(DateIntervalFormatterStyle value) const;
        /**
     * @brief Returns the `dateTemplate` property of `NSDateIntervalFormatter`.
     * @details The date template for the formatter. Default is an empty string.
     * @return The converted Objective-C result.
     */
        std::string date_template() const;
        /**
     * @brief Sets the `dateTemplate` property of `NSDateIntervalFormatter`.
     * @details The date template for the formatter. Default is an empty string.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_template(const std::string& value) const;
        /**
     * @brief Returns the `locale` property of `NSDateIntervalFormatter`.
     * @details The locale for the formatter. Default is '[NSLocale currentLocale]'.
     * @return The converted Objective-C result.
     */
        Locale locale() const;
        /**
     * @brief Sets the `locale` property of `NSDateIntervalFormatter`.
     * @details The locale for the formatter. Default is '[NSLocale currentLocale]'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_locale(const Locale& value) const;
        /**
     * @brief Returns the `timeStyle` property of `NSDateIntervalFormatter`.
     * @details The time style for the formatter. Default is 'NSDateIntervalFormatterNoStyle'.
     * @return The converted Objective-C result.
     */
        DateIntervalFormatterStyle time_style() const;
        /**
     * @brief Sets the `timeStyle` property of `NSDateIntervalFormatter`.
     * @details The time style for the formatter. Default is 'NSDateIntervalFormatterNoStyle'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_time_style(DateIntervalFormatterStyle value) const;
        /**
     * @brief Returns the `timeZone` property of `NSDateIntervalFormatter`.
     * @details The time zone for the formatter. Default is '[NSTimeZone defaultTimeZone]'.
     * @return The converted Objective-C result.
     */
        TimeZone time_zone() const;
        /**
     * @brief Sets the `timeZone` property of `NSDateIntervalFormatter`.
     * @details The time zone for the formatter. Default is '[NSTimeZone defaultTimeZone]'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_time_zone(const TimeZone& value) const;
    };
}
