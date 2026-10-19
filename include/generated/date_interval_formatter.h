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
     * @details If the range smaller than the resolution specified by the dateTemplate, a single date format will be produced. If the range is larger than the format specified by the dateTemplate, a locale-specific fallback will be used to format the items missing from the pattern. For example, if the range is 2010-03-04 07:56 - 2010-03-04 19:56 (12 hours) - The pattern jm will produce for en_US, "7:56 AM - 7:56 PM" for en_GB, "7:56 - 19:56" - The pattern MMMd will produce for en_US, "Mar 4" for en_GB, "4 Mar" If the range is 2010-03-04 07:56 - 2010-03-08 16:11 (4 days, 8 hours, 15 minutes) - The pattern jm will produce for en_US, "3/4/2010 7:56 AM - 3/8/2010 4:11 PM" for en_GB, "4/3/2010 7:56 - 8/3/2010 16:11" - The pattern MMMd will produce for en_US, "Mar 4-8" for en_GB, "4-8 Mar"
     * @param from_date Argument converted to the Objective-C parameter of the same role.
     * @param to_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_date(const Date& from_date, const Date& to_date) const;
        /**
     * @brief Calls `-[NSDateIntervalFormatter stringFromDateInterval:]`.
     * @param date_interval Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_date_interval(const DateInterval& date_interval) const;
        /**
     * @brief Returns the `calendar` property of `NSDateIntervalFormatter`.
     * @return The converted Objective-C result.
     */
        Calendar calendar() const;
        /**
     * @brief Sets the `calendar` property of `NSDateIntervalFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_calendar(const Calendar& value) const;
        /**
     * @brief Returns the `dateStyle` property of `NSDateIntervalFormatter`.
     * @return The converted Objective-C result.
     */
        DateIntervalFormatterStyle date_style() const;
        /**
     * @brief Sets the `dateStyle` property of `NSDateIntervalFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_style(DateIntervalFormatterStyle value) const;
        /**
     * @brief Returns the `dateTemplate` property of `NSDateIntervalFormatter`.
     * @return The converted Objective-C result.
     */
        std::string date_template() const;
        /**
     * @brief Sets the `dateTemplate` property of `NSDateIntervalFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_template(const std::string& value) const;
        /**
     * @brief Returns the `locale` property of `NSDateIntervalFormatter`.
     * @return The converted Objective-C result.
     */
        Locale locale() const;
        /**
     * @brief Sets the `locale` property of `NSDateIntervalFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_locale(const Locale& value) const;
        /**
     * @brief Returns the `timeStyle` property of `NSDateIntervalFormatter`.
     * @return The converted Objective-C result.
     */
        DateIntervalFormatterStyle time_style() const;
        /**
     * @brief Sets the `timeStyle` property of `NSDateIntervalFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_time_style(DateIntervalFormatterStyle value) const;
        /**
     * @brief Returns the `timeZone` property of `NSDateIntervalFormatter`.
     * @return The converted Objective-C result.
     */
        TimeZone time_zone() const;
        /**
     * @brief Sets the `timeZone` property of `NSDateIntervalFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_time_zone(const TimeZone& value) const;
    };
}
