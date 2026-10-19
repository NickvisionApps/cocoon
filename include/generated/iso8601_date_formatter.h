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
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Date date_from_string(const std::string& string) const;
        /**
     * @brief Calls `-[NSISO8601DateFormatter stringFromDate:]`.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_date(const Date& date) const;
        /**
     * @brief Calls `+[NSISO8601DateFormatter stringFromDate:timeZone:formatOptions:]`.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @param time_zone Argument converted to the Objective-C parameter of the same role.
     * @param format_options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string string_from_date(const Date& date, const TimeZone& time_zone, ISO8601DateFormatOptions format_options);
        /**
     * @brief Returns the `formatOptions` property of `NSISO8601DateFormatter`.
     * @return The converted Objective-C result.
     */
        ISO8601DateFormatOptions format_options() const;
        /**
     * @brief Sets the `formatOptions` property of `NSISO8601DateFormatter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_format_options(ISO8601DateFormatOptions value) const;
        /**
     * @brief Returns the `timeZone` property of `NSISO8601DateFormatter`.
     * @details Please note that there can be a significant performance cost when resetting these properties. Resetting each property can result in regenerating the entire CFDateFormatterRef, which can be very expensive.
     * @return The converted Objective-C result.
     */
        TimeZone time_zone() const;
        /**
     * @brief Sets the `timeZone` property of `NSISO8601DateFormatter`.
     * @details Please note that there can be a significant performance cost when resetting these properties. Resetting each property can result in regenerating the entire CFDateFormatterRef, which can be very expensive.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_time_zone(const TimeZone& value) const;
    };
}
