#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/formatter.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class TimeZone;

    /**
     * @brief C++ handle for the Objective-C class `NSISO8601DateFormatter` (Foundation).
     * @details A formatter that converts between dates and their ISO 8601 string representations. The ''ISO8601DateFormatter'' class generates and parses string representations of dates following the [ISO 8601](http://www.iso.org/iso/home/standards/iso8601) standard. Use this class to create ISO 8601 representations of dates and create dates from text strings in ISO 8601 format. > Tip: > In Swift, you can use ''Date/ISO8601FormatStyle'' rather than ''ISO8601DateFormatter''. The ''FormatStyle'' API offers a declarative idiom for customizing the formatting of various types. Also, Foundation caches identical ''FormatStyle'' instances, so you don't need to pass them around your app, or risk wasting memory with duplicate formatters.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Formatter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ISO8601DateFormatter iso8601_date_formatter;
     * iso8601_date_formatter.set_format_options(cocoon::ISO8601DateFormatOptions::Year);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ISO8601DateFormatter iso8601_date_formatter{};
     * iso8601_date_formatter.set_format_options(cocoon::ISO8601DateFormatOptions::Year);
     * auto format_options = iso8601_date_formatter.format_options();
     * iso8601_date_formatter.set_time_zone(cocoon::TimeZone());
     * auto time_zone = iso8601_date_formatter.time_zone();
     * iso8601_date_formatter.date_from_string("text");
     * iso8601_date_formatter.string_from_date(cocoon::Date());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsiso8601dateformatter
     */
    class ISO8601DateFormatter : public Formatter
    {
    public:
        /// @brief Creates a new `NSISO8601DateFormatter` instance and returns a handle to it.
        explicit ISO8601DateFormatter();
        /// @brief Creates a null handle that refers to no native object.
        ISO8601DateFormatter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ISO8601DateFormatter(Adopt adopt);
        /**
     * @brief Calls `-[NSISO8601DateFormatter dateFromString:]`.
     * @details Creates and returns a date object from the specified ISO 8601 formatted string representation. - Parameter string: The ISO 8601 formatted string representation of a date. - Returns: A date object, or 'nil' if no valid date was found.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Date date_from_string(const std::string& string) const;
        /**
     * @brief Calls `-[NSISO8601DateFormatter stringFromDate:]`.
     * @details Creates and returns an ISO 8601 formatted string representation of the specified date. - Parameter date: The date to be represented. - Returns: A user-readable string representing the date.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_date(const Date& date) const;
        /**
     * @brief Calls `+[NSISO8601DateFormatter stringFromDate:timeZone:formatOptions:]`.
     * @details Creates a representation of the specified date with a given time zone and format options. - Parameters: - date: The date to be represented. - timeZone: The time zone used. - formatOptions: The options used. For possible values, see 'NSISO8601DateFormatOptions'. - Returns: A user-readable string representing the date.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @param time_zone Argument converted to the Objective-C parameter of the same role.
     * @param format_options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string string_from_date(const Date& date, const TimeZone& time_zone, ISO8601DateFormatOptions format_options);
        /**
     * @brief Returns the `formatOptions` property of `NSISO8601DateFormatter`.
     * @details Options for generating and parsing ISO 8601 date representations. The ISO 8601 specification allows for dates to be expressed in a variety of ways. You can configure the format used to parse and generate representations by specifying various combinations of format options. > Important: Resetting this property can incur a significant performance cost, > as it may cause internal state to be regenerated.
     * @return The converted Objective-C result.
     */
        ISO8601DateFormatOptions format_options() const;
        /**
     * @brief Sets the `formatOptions` property of `NSISO8601DateFormatter`.
     * @details Options for generating and parsing ISO 8601 date representations. The ISO 8601 specification allows for dates to be expressed in a variety of ways. You can configure the format used to parse and generate representations by specifying various combinations of format options. > Important: Resetting this property can incur a significant performance cost, > as it may cause internal state to be regenerated.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_format_options(ISO8601DateFormatOptions value) const;
        /**
     * @brief Returns the `timeZone` property of `NSISO8601DateFormatter`.
     * @details The time zone used to create and parse date representations. When unspecified, GMT is used. Resetting this property can incur a significant performance cost, as it may cause internal state to be regenerated.
     * @return The converted Objective-C result.
     */
        TimeZone time_zone() const;
        /**
     * @brief Sets the `timeZone` property of `NSISO8601DateFormatter`.
     * @details The time zone used to create and parse date representations. When unspecified, GMT is used. Resetting this property can incur a significant performance cost, as it may cause internal state to be regenerated.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_time_zone(const TimeZone& value) const;
    };
}
