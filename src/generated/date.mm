#include "generated/date.h"
#include "internal.h"

namespace cocoon
{
    Date::Date(double secs_to_be_added, const Date& date) : Date(Adopt{cocoon::internal::retain([[::NSDate alloc] initWithTimeInterval:static_cast<::NSTimeInterval>(secs_to_be_added) sinceDate:cocoon::internal::native<::NSDate>(date)])})
    {
    }

    Date::Date(double secs) : Date(Adopt{cocoon::internal::retain([[::NSDate alloc] initWithTimeIntervalSince1970:static_cast<::NSTimeInterval>(secs)])})
    {
    }

    Date::Date() : Date(Adopt{cocoon::internal::retain([::NSDate date])})
    {
    }

    Date::Date(std::nullptr_t) : Object(nullptr)
    {
    }

    Date::Date(Adopt adopt) : Object(adopt)
    {
    }

    ComparisonResult Date::compare(const Date& other) const
    {
        return static_cast<ComparisonResult>([cocoon::internal::ns<::NSDate>(this) compare:cocoon::internal::native<::NSDate>(other)]);
    }

    Date Date::date_by_adding_time_interval(double ti) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDate>(this) dateByAddingTimeInterval:static_cast<::NSTimeInterval>(ti)]);
    }

    std::string Date::description_with_locale(const Object& locale) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDate>(this) descriptionWithLocale:cocoon::internal::native_id(locale)]);
    }

    Date Date::earlier_date(const Date& another_date) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDate>(this) earlierDate:cocoon::internal::native<::NSDate>(another_date)]);
    }

    bool Date::is_equal_to_date(const Date& other_date) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDate>(this) isEqualToDate:cocoon::internal::native<::NSDate>(other_date)]);
    }

    Date Date::later_date(const Date& another_date) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDate>(this) laterDate:cocoon::internal::native<::NSDate>(another_date)]);
    }

    double Date::time_interval_since_date(const Date& another_date) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSDate>(this) timeIntervalSinceDate:cocoon::internal::native<::NSDate>(another_date)]);
    }

    std::string Date::description() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDate>(this) description]);
    }

    Date Date::distant_future()
    {
        return cocoon::internal::wrap<Date>([::NSDate distantFuture]);
    }

    Date Date::distant_past()
    {
        return cocoon::internal::wrap<Date>([::NSDate distantPast]);
    }

    Date Date::now()
    {
        return cocoon::internal::wrap<Date>([::NSDate now]);
    }

    double Date::time_interval_since1970() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSDate>(this) timeIntervalSince1970]);
    }

    double Date::time_interval_since_now() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSDate>(this) timeIntervalSinceNow]);
    }

    double Date::time_interval_since_reference_date() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSDate>(this) timeIntervalSinceReferenceDate]);
    }
}
