#include "generated/date_interval_formatter.h"
#include "internal.h"

namespace cocoon
{
    DateIntervalFormatter::DateIntervalFormatter() : DateIntervalFormatter(Adopt{cocoon::internal::retain([[::NSDateIntervalFormatter alloc] init])})
    {
    }

    DateIntervalFormatter::DateIntervalFormatter(std::nullptr_t) : Formatter(nullptr)
    {
    }

    DateIntervalFormatter::DateIntervalFormatter(Adopt adopt) : Formatter(adopt)
    {
    }

    std::string DateIntervalFormatter::string_from_date(const Date& from_date, const Date& to_date) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDateIntervalFormatter>(this) stringFromDate:cocoon::internal::native<::NSDate>(from_date) toDate:cocoon::internal::native<::NSDate>(to_date)]);
    }

    std::string DateIntervalFormatter::string_from_date_interval(const DateInterval& date_interval) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDateIntervalFormatter>(this) stringFromDateInterval:cocoon::internal::native<::NSDateInterval>(date_interval)]);
    }

    Calendar DateIntervalFormatter::calendar() const
    {
        return cocoon::internal::wrap<Calendar>([cocoon::internal::ns<::NSDateIntervalFormatter>(this) calendar]);
    }

    void DateIntervalFormatter::set_calendar(const Calendar& value) const
    {
        [cocoon::internal::ns<::NSDateIntervalFormatter>(this) setCalendar:cocoon::internal::native<::NSCalendar>(value)];
    }

    DateIntervalFormatterStyle DateIntervalFormatter::date_style() const
    {
        return static_cast<DateIntervalFormatterStyle>([cocoon::internal::ns<::NSDateIntervalFormatter>(this) dateStyle]);
    }

    void DateIntervalFormatter::set_date_style(DateIntervalFormatterStyle value) const
    {
        [cocoon::internal::ns<::NSDateIntervalFormatter>(this) setDateStyle:static_cast<::NSDateIntervalFormatterStyle>(value)];
    }

    std::string DateIntervalFormatter::date_template() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDateIntervalFormatter>(this) dateTemplate]);
    }

    void DateIntervalFormatter::set_date_template(const std::string& value) const
    {
        [cocoon::internal::ns<::NSDateIntervalFormatter>(this) setDateTemplate:cocoon::internal::to(value)];
    }

    Locale DateIntervalFormatter::locale() const
    {
        return cocoon::internal::wrap<Locale>([cocoon::internal::ns<::NSDateIntervalFormatter>(this) locale]);
    }

    void DateIntervalFormatter::set_locale(const Locale& value) const
    {
        [cocoon::internal::ns<::NSDateIntervalFormatter>(this) setLocale:cocoon::internal::native<::NSLocale>(value)];
    }

    DateIntervalFormatterStyle DateIntervalFormatter::time_style() const
    {
        return static_cast<DateIntervalFormatterStyle>([cocoon::internal::ns<::NSDateIntervalFormatter>(this) timeStyle]);
    }

    void DateIntervalFormatter::set_time_style(DateIntervalFormatterStyle value) const
    {
        [cocoon::internal::ns<::NSDateIntervalFormatter>(this) setTimeStyle:static_cast<::NSDateIntervalFormatterStyle>(value)];
    }

    TimeZone DateIntervalFormatter::time_zone() const
    {
        return cocoon::internal::wrap<TimeZone>([cocoon::internal::ns<::NSDateIntervalFormatter>(this) timeZone]);
    }

    void DateIntervalFormatter::set_time_zone(const TimeZone& value) const
    {
        [cocoon::internal::ns<::NSDateIntervalFormatter>(this) setTimeZone:cocoon::internal::native<::NSTimeZone>(value)];
    }
}
