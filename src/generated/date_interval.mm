#include "generated/date_interval.h"
#include "internal.h"

namespace cocoon
{
    DateInterval::DateInterval(const Date& start_date, double duration) : DateInterval(Adopt{cocoon::internal::retain([[::NSDateInterval alloc] initWithStartDate:cocoon::internal::native<::NSDate>(start_date) duration:static_cast<::NSTimeInterval>(duration)])})
    {
    }

    DateInterval::DateInterval(const Date& start_date, const Date& end_date) : DateInterval(Adopt{cocoon::internal::retain([[::NSDateInterval alloc] initWithStartDate:cocoon::internal::native<::NSDate>(start_date) endDate:cocoon::internal::native<::NSDate>(end_date)])})
    {
    }

    DateInterval::DateInterval() : DateInterval(Adopt{cocoon::internal::retain([[::NSDateInterval alloc] init])})
    {
    }

    DateInterval::DateInterval(std::nullptr_t) : Object(nullptr)
    {
    }

    DateInterval::DateInterval(Adopt adopt) : Object(adopt)
    {
    }

    ComparisonResult DateInterval::compare(const DateInterval& date_interval) const
    {
        return static_cast<ComparisonResult>([cocoon::internal::ns<::NSDateInterval>(this) compare:cocoon::internal::native<::NSDateInterval>(date_interval)]);
    }

    bool DateInterval::contains_date(const Date& date) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDateInterval>(this) containsDate:cocoon::internal::native<::NSDate>(date)]);
    }

    DateInterval DateInterval::intersection_with_date_interval(const DateInterval& date_interval) const
    {
        return cocoon::internal::wrap<DateInterval>([cocoon::internal::ns<::NSDateInterval>(this) intersectionWithDateInterval:cocoon::internal::native<::NSDateInterval>(date_interval)]);
    }

    bool DateInterval::intersects_date_interval(const DateInterval& date_interval) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDateInterval>(this) intersectsDateInterval:cocoon::internal::native<::NSDateInterval>(date_interval)]);
    }

    bool DateInterval::is_equal_to_date_interval(const DateInterval& date_interval) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDateInterval>(this) isEqualToDateInterval:cocoon::internal::native<::NSDateInterval>(date_interval)]);
    }

    double DateInterval::duration() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSDateInterval>(this) duration]);
    }

    Date DateInterval::end_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDateInterval>(this) endDate]);
    }

    Date DateInterval::start_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDateInterval>(this) startDate]);
    }
}
