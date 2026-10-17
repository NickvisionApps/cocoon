#include "generated/date_components.h"
#include "internal.h"

namespace cocoon
{
    DateComponents::DateComponents() : DateComponents(Adopt{cocoon::internal::retain([[::NSDateComponents alloc] init])})
    {
    }

    DateComponents::DateComponents(std::nullptr_t) : Object(nullptr)
    {
    }

    DateComponents::DateComponents(Adopt adopt) : Object(adopt)
    {
    }

    bool DateComponents::is_valid_date_in_calendar(const Calendar& calendar) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDateComponents>(this) isValidDateInCalendar:cocoon::internal::native<::NSCalendar>(calendar)]);
    }

    void DateComponents::set_value(std::int64_t value, CalendarUnit unit) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setValue:static_cast<::NSInteger>(value) forComponent:static_cast<::NSCalendarUnit>(unit)];
    }

    std::int64_t DateComponents::value_for_component(CalendarUnit unit) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) valueForComponent:static_cast<::NSCalendarUnit>(unit)]);
    }

    Calendar DateComponents::calendar() const
    {
        return cocoon::internal::wrap<Calendar>([cocoon::internal::ns<::NSDateComponents>(this) calendar]);
    }

    void DateComponents::set_calendar(const Calendar& value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setCalendar:cocoon::internal::native<::NSCalendar>(value)];
    }

    Date DateComponents::date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDateComponents>(this) date]);
    }

    std::int64_t DateComponents::day() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) day]);
    }

    void DateComponents::set_day(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setDay:static_cast<::NSInteger>(value)];
    }

    std::int64_t DateComponents::day_of_year() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) dayOfYear]);
    }

    void DateComponents::set_day_of_year(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setDayOfYear:static_cast<::NSInteger>(value)];
    }

    std::int64_t DateComponents::era() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) era]);
    }

    void DateComponents::set_era(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setEra:static_cast<::NSInteger>(value)];
    }

    std::int64_t DateComponents::hour() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) hour]);
    }

    void DateComponents::set_hour(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setHour:static_cast<::NSInteger>(value)];
    }

    bool DateComponents::is_leap_month() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDateComponents>(this) isLeapMonth]);
    }

    void DateComponents::set_leap_month(bool value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setLeapMonth:static_cast<::BOOL>(value)];
    }

    std::int64_t DateComponents::minute() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) minute]);
    }

    void DateComponents::set_minute(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setMinute:static_cast<::NSInteger>(value)];
    }

    std::int64_t DateComponents::month() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) month]);
    }

    void DateComponents::set_month(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setMonth:static_cast<::NSInteger>(value)];
    }

    std::int64_t DateComponents::nanosecond() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) nanosecond]);
    }

    void DateComponents::set_nanosecond(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setNanosecond:static_cast<::NSInteger>(value)];
    }

    std::int64_t DateComponents::quarter() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) quarter]);
    }

    void DateComponents::set_quarter(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setQuarter:static_cast<::NSInteger>(value)];
    }

    bool DateComponents::is_repeated_day() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDateComponents>(this) isRepeatedDay]);
    }

    void DateComponents::set_repeated_day(bool value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setRepeatedDay:static_cast<::BOOL>(value)];
    }

    std::int64_t DateComponents::second() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) second]);
    }

    void DateComponents::set_second(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setSecond:static_cast<::NSInteger>(value)];
    }

    TimeZone DateComponents::time_zone() const
    {
        return cocoon::internal::wrap<TimeZone>([cocoon::internal::ns<::NSDateComponents>(this) timeZone]);
    }

    void DateComponents::set_time_zone(const TimeZone& value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setTimeZone:cocoon::internal::native<::NSTimeZone>(value)];
    }

    bool DateComponents::is_valid_date() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDateComponents>(this) isValidDate]);
    }

    std::int64_t DateComponents::week_of_month() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) weekOfMonth]);
    }

    void DateComponents::set_week_of_month(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setWeekOfMonth:static_cast<::NSInteger>(value)];
    }

    std::int64_t DateComponents::week_of_year() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) weekOfYear]);
    }

    void DateComponents::set_week_of_year(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setWeekOfYear:static_cast<::NSInteger>(value)];
    }

    std::int64_t DateComponents::weekday() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) weekday]);
    }

    void DateComponents::set_weekday(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setWeekday:static_cast<::NSInteger>(value)];
    }

    std::int64_t DateComponents::weekday_ordinal() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) weekdayOrdinal]);
    }

    void DateComponents::set_weekday_ordinal(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setWeekdayOrdinal:static_cast<::NSInteger>(value)];
    }

    std::int64_t DateComponents::year() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) year]);
    }

    void DateComponents::set_year(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setYear:static_cast<::NSInteger>(value)];
    }

    std::int64_t DateComponents::year_for_week_of_year() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponents>(this) yearForWeekOfYear]);
    }

    void DateComponents::set_year_for_week_of_year(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponents>(this) setYearForWeekOfYear:static_cast<::NSInteger>(value)];
    }
}
