#pragma once

#include "generated/enums.h"
#include "generated/formatter.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Calendar;
    class Date;
    class Locale;
    class TimeZone;

    /**
     * @brief C++ handle for the Objective-C class `NSDateFormatter` (Foundation).
     * @details A formatter that converts between dates and their textual representations. Instances of ''DateFormatter'' create string representations of ''NSDate'' objects, and convert textual representations of dates and times into ''NSDate'' objects. For user-visible representations of dates and times, ''DateFormatter'' provides a variety of localized presets and configuration options. For fixed format representations of dates and times, you can specify a custom format string. When working with date representations in ISO 8601 format, use ''ISO8601DateFormatter'' instead. To represent an interval between two ''NSDate'' objects, use ''DateIntervalFormatter'' instead. To represent a quantity of time specified by an ''NSDateComponents'' object, use ''DateComponentsFormatter'' instead. > Tip: > In Swift, you can use ''Date/FormatStyle'' or ''Date/VerbatimFormatStyle'' rather than ''DateFormatter''. The ''FormatStyle'' API offers a declarative idiom for customizing the formatting of various types. Also, Foundation caches identical ''FormatStyle'' instances, so you don't need to pass them around your app, or risk wasting memory with duplicate formatters. \#\#\# Working With User-Visible Representations of Dates and Times When displaying a date to a user, you set the ''dateStyle'' and ''timeStyle'' properties of the date formatter according to your particular needs. For example, if you want to show the month, day, and year without showing the time, you would set the ''dateStyle'' property to ''Style/long'' and the ''timeStyle'' property to ''Style/none''. Conversely, if you want to show only the time, you would set the 'dateStyle' property to ''Style/none'' and the ''timeStyle'' property to ''Style/short''. Based on the values of the ''dateStyle'' and ''timeStyle'' properties, ''DateFormatter'' provides a representation of a specified date that is appropriate for a given locale. \@TabNavigator { \@Tab("Swift") { '''swift let dateFormatter = DateFormatter() dateFormatter.dateStyle = .medium dateFormatter.timeStyle = .none let date = Date(timeIntervalSinceReferenceDate: 118800) // US English Locale (en_US) dateFormatter.locale = Locale(identifier: "en_US") print(dateFormatter.string(from: date)) // Jan 2, 2001 // French Locale (fr_FR) dateFormatter.locale = Locale(identifier: "fr_FR") print(dateFormatter.string(from: date)) // 2 janv. 2001 // Japanese Locale (ja_JP) dateFormatter.locale = Locale(identifier: "ja_JP") print(dateFormatter.string(from: date)) // 2001/01/02 ''' } \@Tab("Objective-C") { '''objc NSDateFormatter dateFormatter = [[NSDateFormatter alloc] init]; dateFormatter.dateStyle = NSDateFormatterMediumStyle; dateFormatter.timeStyle = NSDateFormatterNoStyle; NSDate date = [NSDate dateWithTimeIntervalSinceReferenceDate:118800]; // US English Locale (en_US) dateFormatter.locale = [[NSLocale alloc] initWithLocaleIdentifier:\@"en_US"]; NSLog(\@"\%\@", [dateFormatter stringFromDate:date]); // Jan 2, 2001 // French Locale (fr_FR) dateFormatter.locale = [[NSLocale alloc] initWithLocaleIdentifier:\@"fr_FR"]; NSLog(\@"\%\@", [dateFormatter stringFromDate:date]); // 2 janv. 2001 // Japanese Locale (ja_JP) dateFormatter.locale = [[NSLocale alloc] initWithLocaleIdentifier:\@"ja_JP"]; NSLog(\@"\%\@", [dateFormatter stringFromDate:date]); // 2001/01/02 ''' } } If you need to define a format that cannot be achieved using the predefined styles, you can use the ''setLocalizedDateFormatFromTemplate(:)'' to specify a localized date format from a template. \@TabNavigator { \@Tab("Swift") { '''swift let dateFormatter = DateFormatter() let date = Date(timeIntervalSinceReferenceDate: 410220000) // US English Locale (en_US) dateFormatter.locale = Locale(identifier: "en_US") dateFormatter.setLocalizedDateFormatFromTemplate("MMMMd") // set template after setting locale print(dateFormatter.string(from: date)) // December 31 // British English Locale (en_GB) dateFormatter.locale = Locale(identifier: "en_GB") dateFormatter.setLocalizedDateFormatFromTemplate("MMMMd") // // set template after setting locale print(dateFormatter.string(from: date)) // 31 December ''' } \@Tab("Objective-C") { '''objc NSDateFormatter dateFormatter = [[NSDateFormatter alloc] init]; NSDate date = [NSDate dateWithTimeIntervalSinceReferenceDate:410220000]; // US English Locale (en_US) dateFormatter.locale = [[NSLocale alloc] initWithLocaleIdentifier:\@"en_US"]; [dateFormatter setLocalizedDateFormatFromTemplate:\@"MMMMd"]; // set template after setting locale NSLog(\@"\%\@", [dateFormatter stringFromDate:date]); // December 31 // British English Locale (en_GB) dateFormatter.locale = [[NSLocale alloc] initWithLocaleIdentifier:\@"en_GB"]; [dateFormatter setLocalizedDateFormatFromTemplate:\@"MMMMd"]; // set template after setting locale NSLog(\@"\%\@", [dateFormatter stringFromDate:date]); // 31 December ''' } } \#\#\# Working With Fixed Format Date Representations > Important: > In macOS 10.12 and later or iOS 10 and later, use the ''ISO8601DateFormatter'' class when working with ISO 8601 date representations. When working with fixed format dates, such as RFC 3339, you set the ''dateFormat'' property to specify a format string. For most fixed formats, you should also set the ''locale'' property to a POSIX locale ('"en_US_POSIX"'), and set the ''timeZone'' property to UTC. \@TabNavigator { \@Tab("Swift") { '''swift let RFC3339DateFormatter = DateFormatter() RFC3339DateFormatter.locale = Locale(identifier: "en_US_POSIX") RFC3339DateFormatter.dateFormat = "yyyy-MM-dd'T'HH:mm:ssZZZZZ" RFC3339DateFormatter.timeZone = TimeZone(secondsFromGMT: 0) / 39 minutes and 57 seconds after the 16th hour of December 19th, 1996 with an offset of -08:00 from UTC (Pacific Standard Time) let string = "1996-12-19T16:39:57-08:00" let date = RFC3339DateFormatter.date(from: string) ''' } \@Tab("Objective-C") { '''objc RFC3339DateFormatter = [[NSDateFormatter alloc] init]; RFC3339DateFormatter.locale = [NSLocale localeWithLocaleIdentifier:\@"en_US_POSIX"]; RFC3339DateFormatter.dateFormat = \@"yyyy-MM-dd'T'HH:mm:ssZZZZZ"; RFC3339DateFormatter.timeZone = [NSTimeZone timeZoneForSecondsFromGMT:0]; / 39 minutes and 57 seconds after the 16th hour of December 19th, 1996 with an offset of -08:00 from UTC (Pacific Standard Time) NSString string = \@"1996-12-19T16:39:57-08:00"; NSDate date = [RFC3339DateFormatter dateFromString:string]; ''' } } For more information, see [Technical Q&A QA1480 “NSDateFormatter and Internet Dates”](https://developer.apple.com/library/mac/qa/qa1480/). \#\#\# Thread Safety On iOS 7 and later 'NSDateFormatter' is thread safe. In macOS 10.9 and later 'NSDateFormatter' is thread safe so long as you are using the modern behavior in a 64-bit app. On earlier versions of the operating system, or when using the legacy formatter behavior or running in 32-bit in macOS, 'NSDateFormatter' is not thread safe, and you therefore must not mutate a date formatter simultaneously from multiple threads.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Formatter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DateFormatter date_formatter;
     * date_formatter.set_am_symbol("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DateFormatter date_formatter{};
     * date_formatter.set_am_symbol("text");
     * auto am_symbol = date_formatter.am_symbol();
     * date_formatter.set_pm_symbol("text");
     * auto pm_symbol = date_formatter.pm_symbol();
     * date_formatter.set_calendar(cocoon::Calendar());
     * auto calendar = date_formatter.calendar();
     * date_formatter.date_from_string("text");
     * date_formatter.set_localized_date_format_from_template("text");
     * date_formatter.string_from_date(cocoon::Date());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdateformatter
     */
    class DateFormatter : public Formatter
    {
    public:
        /// @brief Creates a new `NSDateFormatter` instance and returns a handle to it.
        explicit DateFormatter();
        /// @brief Creates a null handle that refers to no native object.
        DateFormatter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DateFormatter(Adopt adopt);
        /**
     * @brief Calls `+[NSDateFormatter dateFormatFromTemplate:options:locale:]`.
     * @details Returns a localized date format string representing the given date format components arranged appropriately for the specified locale. - Parameters: - tmplate: A string containing date format patterns (such as "MM" or "h"). - opts: No options are currently defined — pass '0'. - locale: The locale for which the template is required. - Returns: A localized date format string representing the date format components given in 'tmplate', arranged appropriately for the locale specified by 'locale'. The returned string may not contain exactly those components given in 'tmplate', but may — for example — have locale-specific adjustments applied. Different locales have different conventions for the ordering of date components. You use this method to get an appropriate format string for a given set of components for a specified locale (typically you use the current locale).
     * @param tmplate Argument converted to the Objective-C parameter of the same role.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param locale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string date_format_from_template(const std::string& tmplate, std::uint64_t opts, const Locale& locale);
        /**
     * @brief Calls `-[NSDateFormatter dateFromString:]`.
     * @details Returns a date representation of a specified string that the system interprets using the receiver's current settings. - Parameter string: The string to parse. - Returns: A date representation of 'string'. If 'dateFromString:' can't parse the string, returns 'nil'.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Date date_from_string(const std::string& string) const;
        /**
     * @brief Calls `+[NSDateFormatter localizedStringFromDate:dateStyle:timeStyle:]`.
     * @details Returns a string representation of a specified date, that the system formats for the current locale using the specified date and time styles. - Parameters: - date: A date. - dstyle: A format style for the date. For possible values, see 'NSDateFormatterStyle'. - tstyle: A format style for the time. For possible values, see 'NSDateFormatterStyle'. - Returns: A localized string representation of 'date' using the specified date and time styles. This method uses a date formatter configured with the current default settings. The returned string is the same as if you configured and used a date formatter as shown in the following example: NSDateFormatter formatter = [[NSDateFormatter alloc] init]; formatter.formatterBehavior = NSDateFormatterBehavior10_4; formatter.dateStyle = dateStyle; formatter.timeStyle = timeStyle; NSString result = [formatter stringForObjectValue:date];
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @param dstyle Argument converted to the Objective-C parameter of the same role.
     * @param tstyle Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string localized_string_from_date(const Date& date, DateFormatterStyle dstyle, DateFormatterStyle tstyle);
        /**
     * @brief Calls `-[NSDateFormatter setLocalizedDateFormatFromTemplate:]`.
     * @details Sets the date format from a template using the specified locale for the receiver. - Parameter dateFormatTemplate: A string containing date format patterns (such as "MM" or "h"). Calling this method is equivalent to, but not necessarily implemented as, setting the 'dateFormat' property to the result of calling the 'dateFormatFromTemplate:options:locale:' method, passing no options and the 'locale' property value. > Important: You should call this method only after setting the 'locale' of the receiver.
     * @param date_format_template Argument converted to the Objective-C parameter of the same role.
     */
        void set_localized_date_format_from_template(const std::string& date_format_template) const;
        /**
     * @brief Calls `-[NSDateFormatter stringFromDate:]`.
     * @details Returns a string representation of a specified date that the system formats using the receiver's current settings. - Parameter date: The date to format. - Returns: A string representation of 'date'.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_date(const Date& date) const;
        /**
     * @brief Returns the `AMSymbol` property of `NSDateFormatter`.
     * @details The AM symbol for the receiver.
     * @return The converted Objective-C result.
     */
        std::string am_symbol() const;
        /**
     * @brief Sets the `AMSymbol` property of `NSDateFormatter`.
     * @details The AM symbol for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_am_symbol(const std::string& value) const;
        /**
     * @brief Returns the `PMSymbol` property of `NSDateFormatter`.
     * @details The PM symbol for the receiver.
     * @return The converted Objective-C result.
     */
        std::string pm_symbol() const;
        /**
     * @brief Sets the `PMSymbol` property of `NSDateFormatter`.
     * @details The PM symbol for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_pm_symbol(const std::string& value) const;
        /**
     * @brief Returns the `calendar` property of `NSDateFormatter`.
     * @details The calendar for the receiver. If unspecified, the logical calendar for the current user is used.
     * @return The converted Objective-C result.
     */
        Calendar calendar() const;
        /**
     * @brief Sets the `calendar` property of `NSDateFormatter`.
     * @details The calendar for the receiver. If unspecified, the logical calendar for the current user is used.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_calendar(const Calendar& value) const;
        /**
     * @brief Returns the `dateFormat` property of `NSDateFormatter`.
     * @details The date format string used by the receiver. You should only set this property when working with fixed format representations. For user-visible representations, you should use the 'dateStyle' and 'timeStyle' properties, or the 'setLocalizedDateFormatFromTemplate:' method if your desired format cannot be achieved using the predefined styles; both of these properties and this method provide a localized date representation appropriate for display to the user.
     * @return The converted Objective-C result.
     */
        std::string date_format() const;
        /**
     * @brief Sets the `dateFormat` property of `NSDateFormatter`.
     * @details The date format string used by the receiver. You should only set this property when working with fixed format representations. For user-visible representations, you should use the 'dateStyle' and 'timeStyle' properties, or the 'setLocalizedDateFormatFromTemplate:' method if your desired format cannot be achieved using the predefined styles; both of these properties and this method provide a localized date representation appropriate for display to the user.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_format(const std::string& value) const;
        /**
     * @brief Returns the `dateStyle` property of `NSDateFormatter`.
     * @details The date style of the receiver.
     * @return The converted Objective-C result.
     */
        DateFormatterStyle date_style() const;
        /**
     * @brief Sets the `dateStyle` property of `NSDateFormatter`.
     * @details The date style of the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_style(DateFormatterStyle value) const;
        /**
     * @brief Returns the `defaultDate` property of `NSDateFormatter`.
     * @details The default date for the receiver. By default, this property is 'nil'.
     * @return The converted Objective-C result.
     */
        Date default_date() const;
        /**
     * @brief Sets the `defaultDate` property of `NSDateFormatter`.
     * @details The default date for the receiver. By default, this property is 'nil'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_date(const Date& value) const;
        /**
     * @brief Returns the `defaultFormatterBehavior` property of `NSDateFormatter`.
     * @details Returns the default formatting behavior for instances of the class. For iOS and for macOS applications linked against macOS 10.5 and later, the default is 'NSDateFormatterBehavior10_4'.
     * @return The converted Objective-C result.
     */
        static DateFormatterBehavior default_formatter_behavior();
        /**
     * @brief Sets the `defaultFormatterBehavior` property of `NSDateFormatter`.
     * @details Returns the default formatting behavior for instances of the class. For iOS and for macOS applications linked against macOS 10.5 and later, the default is 'NSDateFormatterBehavior10_4'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_default_formatter_behavior(DateFormatterBehavior value);
        /**
     * @brief Returns the `doesRelativeDateFormatting` property of `NSDateFormatter`.
     * @details A Boolean value that indicates whether the receiver uses phrases such as "today" and "tomorrow" for the date component. 'YES' if the receiver uses relative date formatting, otherwise 'NO'. If a date formatter uses relative date formatting, where possible it replaces the date component of its output with a phrase — such as "today" or "tomorrow" — that indicates a relative date. The available phrases depend on the locale for the date formatter; whereas, for dates in the future, English may only allow "tomorrow," French may allow "the day after the day after tomorrow."
     * @return The converted Objective-C result.
     */
        bool does_relative_date_formatting() const;
        /**
     * @brief Sets the `doesRelativeDateFormatting` property of `NSDateFormatter`.
     * @details A Boolean value that indicates whether the receiver uses phrases such as "today" and "tomorrow" for the date component. 'YES' if the receiver uses relative date formatting, otherwise 'NO'. If a date formatter uses relative date formatting, where possible it replaces the date component of its output with a phrase — such as "today" or "tomorrow" — that indicates a relative date. The available phrases depend on the locale for the date formatter; whereas, for dates in the future, English may only allow "tomorrow," French may allow "the day after the day after tomorrow."
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_does_relative_date_formatting(bool value) const;
        /**
     * @brief Returns the `eraSymbols` property of `NSDateFormatter`.
     * @details The era symbols for the receiver. An array containing 'NSString' objects representing the era symbols for the receiver (for example, {"B.C.E.", "C.E."}).
     * @return The converted Objective-C result.
     */
        std::vector<std::string> era_symbols() const;
        /**
     * @brief Sets the `eraSymbols` property of `NSDateFormatter`.
     * @details The era symbols for the receiver. An array containing 'NSString' objects representing the era symbols for the receiver (for example, {"B.C.E.", "C.E."}).
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_era_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `formatterBehavior` property of `NSDateFormatter`.
     * @details The formatter behavior for the receiver.
     * @return The converted Objective-C result.
     */
        DateFormatterBehavior formatter_behavior() const;
        /**
     * @brief Sets the `formatterBehavior` property of `NSDateFormatter`.
     * @details The formatter behavior for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_formatter_behavior(DateFormatterBehavior value) const;
        /**
     * @brief Returns the `formattingContext` property of `NSDateFormatter`.
     * @details The capitalization formatting context used when formatting a date. The formatting context allows the formatter to apply appropriate capitalization depending on how the string will be used, and whether the locale makes capitalization distinctions.
     * @return The converted Objective-C result.
     */
        FormattingContext formatting_context() const;
        /**
     * @brief Sets the `formattingContext` property of `NSDateFormatter`.
     * @details The capitalization formatting context used when formatting a date. The formatting context allows the formatter to apply appropriate capitalization depending on how the string will be used, and whether the locale makes capitalization distinctions.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_formatting_context(FormattingContext value) const;
        /**
     * @brief Returns the `generatesCalendarDates` property of `NSDateFormatter`.
     * @details Indicates whether the formatter generates the deprecated calendar date type. This property is 'YES' if the formatter generates the deprecated 'NSCalendarDate' type, and is 'NO' otherwise. You should use 'NSDate' and 'NSCalendar' rather than 'NSCalendarDate'.
     * @return The converted Objective-C result.
     */
        bool generates_calendar_dates() const;
        /**
     * @brief Sets the `generatesCalendarDates` property of `NSDateFormatter`.
     * @details Indicates whether the formatter generates the deprecated calendar date type. This property is 'YES' if the formatter generates the deprecated 'NSCalendarDate' type, and is 'NO' otherwise. You should use 'NSDate' and 'NSCalendar' rather than 'NSCalendarDate'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_generates_calendar_dates(bool value) const;
        /**
     * @brief Returns the `gregorianStartDate` property of `NSDateFormatter`.
     * @details The start date of the Gregorian calendar for the receiver. This is used to specify the start date for the Gregorian calendar switch from the Julian calendar. Different locales switched at different times. Normally you should just accept the locale's default date for the switch.
     * @return The converted Objective-C result.
     */
        Date gregorian_start_date() const;
        /**
     * @brief Sets the `gregorianStartDate` property of `NSDateFormatter`.
     * @details The start date of the Gregorian calendar for the receiver. This is used to specify the start date for the Gregorian calendar switch from the Julian calendar. Different locales switched at different times. Normally you should just accept the locale's default date for the switch.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_gregorian_start_date(const Date& value) const;
        /**
     * @brief Returns the `lenient` property of `NSDateFormatter`.
     * @details A Boolean value that indicates whether the receiver uses heuristics when parsing a string. 'YES' if the receiver has been set to use heuristics when parsing a string to guess at the date which is intended, otherwise 'NO'. If a formatter is set to be lenient, when parsing a string it uses heuristics to guess at the date which is intended. As with any guessing, it may get the result date wrong (that is, a date other than that which was intended).
     * @return The converted Objective-C result.
     */
        bool is_lenient() const;
        /**
     * @brief Sets the `lenient` property of `NSDateFormatter`.
     * @details A Boolean value that indicates whether the receiver uses heuristics when parsing a string. 'YES' if the receiver has been set to use heuristics when parsing a string to guess at the date which is intended, otherwise 'NO'. If a formatter is set to be lenient, when parsing a string it uses heuristics to guess at the date which is intended. As with any guessing, it may get the result date wrong (that is, a date other than that which was intended).
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_lenient(bool value) const;
        /**
     * @brief Returns the `locale` property of `NSDateFormatter`.
     * @details The locale for the receiver.
     * @return The converted Objective-C result.
     */
        Locale locale() const;
        /**
     * @brief Sets the `locale` property of `NSDateFormatter`.
     * @details The locale for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_locale(const Locale& value) const;
        /**
     * @brief Returns the `longEraSymbols` property of `NSDateFormatter`.
     * @details The long era symbols for the receiver. An array containing 'NSString' objects representing the era symbols for the receiver (for example, {"Before Common Era", "Common Era"}).
     * @return The converted Objective-C result.
     */
        std::vector<std::string> long_era_symbols() const;
        /**
     * @brief Sets the `longEraSymbols` property of `NSDateFormatter`.
     * @details The long era symbols for the receiver. An array containing 'NSString' objects representing the era symbols for the receiver (for example, {"Before Common Era", "Common Era"}).
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_long_era_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `monthSymbols` property of `NSDateFormatter`.
     * @details The month symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> month_symbols() const;
        /**
     * @brief Sets the `monthSymbols` property of `NSDateFormatter`.
     * @details The month symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_month_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `quarterSymbols` property of `NSDateFormatter`.
     * @details The quarter symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> quarter_symbols() const;
        /**
     * @brief Sets the `quarterSymbols` property of `NSDateFormatter`.
     * @details The quarter symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_quarter_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `shortMonthSymbols` property of `NSDateFormatter`.
     * @details The array of short month symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_month_symbols() const;
        /**
     * @brief Sets the `shortMonthSymbols` property of `NSDateFormatter`.
     * @details The array of short month symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_short_month_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `shortQuarterSymbols` property of `NSDateFormatter`.
     * @details The short quarter symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_quarter_symbols() const;
        /**
     * @brief Sets the `shortQuarterSymbols` property of `NSDateFormatter`.
     * @details The short quarter symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_short_quarter_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `shortStandaloneMonthSymbols` property of `NSDateFormatter`.
     * @details The short standalone month symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_standalone_month_symbols() const;
        /**
     * @brief Sets the `shortStandaloneMonthSymbols` property of `NSDateFormatter`.
     * @details The short standalone month symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_short_standalone_month_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `shortStandaloneQuarterSymbols` property of `NSDateFormatter`.
     * @details The short standalone quarter symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_standalone_quarter_symbols() const;
        /**
     * @brief Sets the `shortStandaloneQuarterSymbols` property of `NSDateFormatter`.
     * @details The short standalone quarter symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_short_standalone_quarter_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `shortStandaloneWeekdaySymbols` property of `NSDateFormatter`.
     * @details The array of short standalone weekday symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_standalone_weekday_symbols() const;
        /**
     * @brief Sets the `shortStandaloneWeekdaySymbols` property of `NSDateFormatter`.
     * @details The array of short standalone weekday symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_short_standalone_weekday_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `shortWeekdaySymbols` property of `NSDateFormatter`.
     * @details The array of short weekday symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_weekday_symbols() const;
        /**
     * @brief Sets the `shortWeekdaySymbols` property of `NSDateFormatter`.
     * @details The array of short weekday symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_short_weekday_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `standaloneMonthSymbols` property of `NSDateFormatter`.
     * @details The standalone month symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> standalone_month_symbols() const;
        /**
     * @brief Sets the `standaloneMonthSymbols` property of `NSDateFormatter`.
     * @details The standalone month symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standalone_month_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `standaloneQuarterSymbols` property of `NSDateFormatter`.
     * @details The standalone quarter symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> standalone_quarter_symbols() const;
        /**
     * @brief Sets the `standaloneQuarterSymbols` property of `NSDateFormatter`.
     * @details The standalone quarter symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standalone_quarter_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `standaloneWeekdaySymbols` property of `NSDateFormatter`.
     * @details The array of standalone weekday symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> standalone_weekday_symbols() const;
        /**
     * @brief Sets the `standaloneWeekdaySymbols` property of `NSDateFormatter`.
     * @details The array of standalone weekday symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standalone_weekday_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `timeStyle` property of `NSDateFormatter`.
     * @details The time style of the receiver.
     * @return The converted Objective-C result.
     */
        DateFormatterStyle time_style() const;
        /**
     * @brief Sets the `timeStyle` property of `NSDateFormatter`.
     * @details The time style of the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_time_style(DateFormatterStyle value) const;
        /**
     * @brief Returns the `timeZone` property of `NSDateFormatter`.
     * @details The time zone for the receiver. If unspecified, the system time zone is used.
     * @return The converted Objective-C result.
     */
        TimeZone time_zone() const;
        /**
     * @brief Sets the `timeZone` property of `NSDateFormatter`.
     * @details The time zone for the receiver. If unspecified, the system time zone is used.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_time_zone(const TimeZone& value) const;
        /**
     * @brief Returns the `twoDigitStartDate` property of `NSDateFormatter`.
     * @details The earliest date that can be denoted by a two-digit year specifier. If the two-digit start date is set to January 6, 1976, then "January 1, 76" is interpreted as New Year's Day in 2076, whereas "February 14, 76" is interpreted as Valentine's Day in 1976. By default, this property is equal to December 31, 1949.
     * @return The converted Objective-C result.
     */
        Date two_digit_start_date() const;
        /**
     * @brief Sets the `twoDigitStartDate` property of `NSDateFormatter`.
     * @details The earliest date that can be denoted by a two-digit year specifier. If the two-digit start date is set to January 6, 1976, then "January 1, 76" is interpreted as New Year's Day in 2076, whereas "February 14, 76" is interpreted as Valentine's Day in 1976. By default, this property is equal to December 31, 1949.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_two_digit_start_date(const Date& value) const;
        /**
     * @brief Returns the `veryShortMonthSymbols` property of `NSDateFormatter`.
     * @details The very short month symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> very_short_month_symbols() const;
        /**
     * @brief Sets the `veryShortMonthSymbols` property of `NSDateFormatter`.
     * @details The very short month symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_very_short_month_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `veryShortStandaloneMonthSymbols` property of `NSDateFormatter`.
     * @details The very short month symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> very_short_standalone_month_symbols() const;
        /**
     * @brief Sets the `veryShortStandaloneMonthSymbols` property of `NSDateFormatter`.
     * @details The very short month symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_very_short_standalone_month_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `veryShortStandaloneWeekdaySymbols` property of `NSDateFormatter`.
     * @details The array of very short standalone weekday symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> very_short_standalone_weekday_symbols() const;
        /**
     * @brief Sets the `veryShortStandaloneWeekdaySymbols` property of `NSDateFormatter`.
     * @details The array of very short standalone weekday symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_very_short_standalone_weekday_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `veryShortWeekdaySymbols` property of `NSDateFormatter`.
     * @details The array of very short weekday symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> very_short_weekday_symbols() const;
        /**
     * @brief Sets the `veryShortWeekdaySymbols` property of `NSDateFormatter`.
     * @details The array of very short weekday symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_very_short_weekday_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `weekdaySymbols` property of `NSDateFormatter`.
     * @details The array of weekday symbols for the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> weekday_symbols() const;
        /**
     * @brief Sets the `weekdaySymbols` property of `NSDateFormatter`.
     * @details The array of weekday symbols for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_weekday_symbols(const std::vector<std::string>& value) const;
    };
}
