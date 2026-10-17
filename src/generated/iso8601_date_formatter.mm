#include "generated/iso8601_date_formatter.h"
#include "internal.h"

namespace cocoon
{
    ISO8601DateFormatter::ISO8601DateFormatter() : ISO8601DateFormatter(Adopt{cocoon::internal::retain([[::NSISO8601DateFormatter alloc] init])})
    {
    }

    ISO8601DateFormatter::ISO8601DateFormatter(std::nullptr_t) : Formatter(nullptr)
    {
    }

    ISO8601DateFormatter::ISO8601DateFormatter(Adopt adopt) : Formatter(adopt)
    {
    }

    Date ISO8601DateFormatter::date_from_string(const std::string& string) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSISO8601DateFormatter>(this) dateFromString:cocoon::internal::to(string)]);
    }

    std::string ISO8601DateFormatter::string_from_date(const Date& date) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSISO8601DateFormatter>(this) stringFromDate:cocoon::internal::native<::NSDate>(date)]);
    }

    std::string ISO8601DateFormatter::string_from_date(const Date& date, const TimeZone& time_zone, ISO8601DateFormatOptions format_options)
    {
        return cocoon::internal::from([::NSISO8601DateFormatter stringFromDate:cocoon::internal::native<::NSDate>(date) timeZone:cocoon::internal::native<::NSTimeZone>(time_zone) formatOptions:static_cast<::NSISO8601DateFormatOptions>(format_options)]);
    }

    ISO8601DateFormatOptions ISO8601DateFormatter::format_options() const
    {
        return static_cast<ISO8601DateFormatOptions>([cocoon::internal::ns<::NSISO8601DateFormatter>(this) formatOptions]);
    }

    void ISO8601DateFormatter::set_format_options(ISO8601DateFormatOptions value) const
    {
        [cocoon::internal::ns<::NSISO8601DateFormatter>(this) setFormatOptions:static_cast<::NSISO8601DateFormatOptions>(value)];
    }

    TimeZone ISO8601DateFormatter::time_zone() const
    {
        return cocoon::internal::wrap<TimeZone>([cocoon::internal::ns<::NSISO8601DateFormatter>(this) timeZone]);
    }

    void ISO8601DateFormatter::set_time_zone(const TimeZone& value) const
    {
        [cocoon::internal::ns<::NSISO8601DateFormatter>(this) setTimeZone:cocoon::internal::native<::NSTimeZone>(value)];
    }
}
