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
    class Locale;
    class TimeZone;

    /**
     * @brief C++ handle for the Objective-C class `NSDateFormatter` (Foundation).
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
     * @param tmplate Argument converted to the Objective-C parameter of the same role.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param locale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string date_format_from_template(const std::string& tmplate, std::uint64_t opts, const Locale& locale);
        /**
     * @brief Calls `-[NSDateFormatter dateFromString:]`.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Date date_from_string(const std::string& string) const;
        /**
     * @brief Calls `+[NSDateFormatter localizedStringFromDate:dateStyle:timeStyle:]`.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @param dstyle Argument converted to the Objective-C parameter of the same role.
     * @param tstyle Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string localized_string_from_date(const Date& date, DateFormatterStyle dstyle, DateFormatterStyle tstyle);
        /**
     * @brief Calls `-[NSDateFormatter setLocalizedDateFormatFromTemplate:]`.
     * @details A convenient way to generate an appropriate localized date format, and set it, in a single operation. Equivalent to, though not necessarily implemented as: formatter.dateFormat = [NSDateFormatter dateFormatFromTemplate:dateFormatTemplate options:0 locale:formatter.locale]; Note that the template string is used only to specify which date format components should be included. Ordering and other text will not be preserved. The parameter is also not stored, or updated when the locale or other options change, just as with the ‘dateFormat’ property.
     * @param date_format_template Argument converted to the Objective-C parameter of the same role.
     */
        void set_localized_date_format_from_template(const std::string& date_format_template) const;
        /**
     * @brief Calls `-[NSDateFormatter stringFromDate:]`.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_date(const Date& date) const;
        /**
     * @brief Returns the `AMSymbol` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::string am_symbol() const;
        /**
     * @brief Sets the `AMSymbol` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_am_symbol(const std::string& value) const;
        /**
     * @brief Returns the `PMSymbol` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::string pm_symbol() const;
        /**
     * @brief Sets the `PMSymbol` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_pm_symbol(const std::string& value) const;
        /**
     * @brief Returns the `calendar` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        Calendar calendar() const;
        /**
     * @brief Sets the `calendar` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_calendar(const Calendar& value) const;
        /**
     * @brief Returns the `dateFormat` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::string date_format() const;
        /**
     * @brief Sets the `dateFormat` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_format(const std::string& value) const;
        /**
     * @brief Returns the `dateStyle` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        DateFormatterStyle date_style() const;
        /**
     * @brief Sets the `dateStyle` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_style(DateFormatterStyle value) const;
        /**
     * @brief Returns the `defaultDate` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        Date default_date() const;
        /**
     * @brief Sets the `defaultDate` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_date(const Date& value) const;
        /**
     * @brief Returns the `defaultFormatterBehavior` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        static DateFormatterBehavior default_formatter_behavior();
        /**
     * @brief Sets the `defaultFormatterBehavior` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_default_formatter_behavior(DateFormatterBehavior value);
        /**
     * @brief Returns the `doesRelativeDateFormatting` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        bool does_relative_date_formatting() const;
        /**
     * @brief Sets the `doesRelativeDateFormatting` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_does_relative_date_formatting(bool value) const;
        /**
     * @brief Returns the `eraSymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> era_symbols() const;
        /**
     * @brief Sets the `eraSymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_era_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `formatterBehavior` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        DateFormatterBehavior formatter_behavior() const;
        /**
     * @brief Sets the `formatterBehavior` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_formatter_behavior(DateFormatterBehavior value) const;
        /**
     * @brief Returns the `formattingContext` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        FormattingContext formatting_context() const;
        /**
     * @brief Sets the `formattingContext` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_formatting_context(FormattingContext value) const;
        /**
     * @brief Returns the `generatesCalendarDates` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        bool generates_calendar_dates() const;
        /**
     * @brief Sets the `generatesCalendarDates` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_generates_calendar_dates(bool value) const;
        /**
     * @brief Returns the `gregorianStartDate` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        Date gregorian_start_date() const;
        /**
     * @brief Sets the `gregorianStartDate` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_gregorian_start_date(const Date& value) const;
        /**
     * @brief Returns the `lenient` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        bool is_lenient() const;
        /**
     * @brief Sets the `lenient` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_lenient(bool value) const;
        /**
     * @brief Returns the `locale` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        Locale locale() const;
        /**
     * @brief Sets the `locale` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_locale(const Locale& value) const;
        /**
     * @brief Returns the `longEraSymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> long_era_symbols() const;
        /**
     * @brief Sets the `longEraSymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_long_era_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `monthSymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> month_symbols() const;
        /**
     * @brief Sets the `monthSymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_month_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `quarterSymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> quarter_symbols() const;
        /**
     * @brief Sets the `quarterSymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_quarter_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `shortMonthSymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_month_symbols() const;
        /**
     * @brief Sets the `shortMonthSymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_short_month_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `shortQuarterSymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_quarter_symbols() const;
        /**
     * @brief Sets the `shortQuarterSymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_short_quarter_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `shortStandaloneMonthSymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_standalone_month_symbols() const;
        /**
     * @brief Sets the `shortStandaloneMonthSymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_short_standalone_month_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `shortStandaloneQuarterSymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_standalone_quarter_symbols() const;
        /**
     * @brief Sets the `shortStandaloneQuarterSymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_short_standalone_quarter_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `shortStandaloneWeekdaySymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_standalone_weekday_symbols() const;
        /**
     * @brief Sets the `shortStandaloneWeekdaySymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_short_standalone_weekday_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `shortWeekdaySymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_weekday_symbols() const;
        /**
     * @brief Sets the `shortWeekdaySymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_short_weekday_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `standaloneMonthSymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> standalone_month_symbols() const;
        /**
     * @brief Sets the `standaloneMonthSymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standalone_month_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `standaloneQuarterSymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> standalone_quarter_symbols() const;
        /**
     * @brief Sets the `standaloneQuarterSymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standalone_quarter_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `standaloneWeekdaySymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> standalone_weekday_symbols() const;
        /**
     * @brief Sets the `standaloneWeekdaySymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standalone_weekday_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `timeStyle` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        DateFormatterStyle time_style() const;
        /**
     * @brief Sets the `timeStyle` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_time_style(DateFormatterStyle value) const;
        /**
     * @brief Returns the `timeZone` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        TimeZone time_zone() const;
        /**
     * @brief Sets the `timeZone` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_time_zone(const TimeZone& value) const;
        /**
     * @brief Returns the `twoDigitStartDate` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        Date two_digit_start_date() const;
        /**
     * @brief Sets the `twoDigitStartDate` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_two_digit_start_date(const Date& value) const;
        /**
     * @brief Returns the `veryShortMonthSymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> very_short_month_symbols() const;
        /**
     * @brief Sets the `veryShortMonthSymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_very_short_month_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `veryShortStandaloneMonthSymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> very_short_standalone_month_symbols() const;
        /**
     * @brief Sets the `veryShortStandaloneMonthSymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_very_short_standalone_month_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `veryShortStandaloneWeekdaySymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> very_short_standalone_weekday_symbols() const;
        /**
     * @brief Sets the `veryShortStandaloneWeekdaySymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_very_short_standalone_weekday_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `veryShortWeekdaySymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> very_short_weekday_symbols() const;
        /**
     * @brief Sets the `veryShortWeekdaySymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_very_short_weekday_symbols(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `weekdaySymbols` property of `NSDateFormatter`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> weekday_symbols() const;
        /**
     * @brief Sets the `weekdaySymbols` property of `NSDateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_weekday_symbols(const std::vector<std::string>& value) const;
    };
}
