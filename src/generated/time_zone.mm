#include "generated/time_zone.h"
#include "internal.h"

namespace cocoon
{
    TimeZone::TimeZone(const std::string& tz_name) : TimeZone(Adopt{cocoon::internal::retain([[::NSTimeZone alloc] initWithName:cocoon::internal::to(tz_name)])})
    {
    }

    TimeZone::TimeZone(const std::string& tz_name, const std::vector<std::uint8_t>& a_data) : TimeZone(Adopt{cocoon::internal::retain([[::NSTimeZone alloc] initWithName:cocoon::internal::to(tz_name) data:cocoon::internal::to_data(a_data)])})
    {
    }

    TimeZone::TimeZone() : TimeZone(Adopt{cocoon::internal::retain([[::NSTimeZone alloc] init])})
    {
    }

    TimeZone::TimeZone(std::nullptr_t) : Object(nullptr)
    {
    }

    TimeZone::TimeZone(Adopt adopt) : Object(adopt)
    {
    }

    std::map<std::string, std::string> TimeZone::abbreviation_dictionary()
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::string>>([::NSTimeZone abbreviationDictionary], [](id k) -> std::string
                                                                       {
                                                                           return cocoon::internal::from((NSString*)k);
                                                                       },
                                                                       [](id v) -> std::string
                                                                       {
                                                                           return cocoon::internal::from((NSString*)v);
                                                                       });
    }

    std::string TimeZone::abbreviation_for_date(const Date& a_date) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTimeZone>(this) abbreviationForDate:cocoon::internal::native<::NSDate>(a_date)]);
    }

    double TimeZone::daylight_saving_time_offset_for_date(const Date& a_date) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTimeZone>(this) daylightSavingTimeOffsetForDate:cocoon::internal::native<::NSDate>(a_date)]);
    }

    bool TimeZone::is_daylight_saving_time_for_date(const Date& a_date) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTimeZone>(this) isDaylightSavingTimeForDate:cocoon::internal::native<::NSDate>(a_date)]);
    }

    bool TimeZone::is_equal_to_time_zone(const TimeZone& a_time_zone) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTimeZone>(this) isEqualToTimeZone:cocoon::internal::native<::NSTimeZone>(a_time_zone)]);
    }

    std::string TimeZone::localized_name(TimeZoneNameStyle style, const Locale& locale) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTimeZone>(this) localizedName:static_cast<::NSTimeZoneNameStyle>(style) locale:cocoon::internal::native<::NSLocale>(locale)]);
    }

    Date TimeZone::next_daylight_saving_time_transition_after_date(const Date& a_date) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSTimeZone>(this) nextDaylightSavingTimeTransitionAfterDate:cocoon::internal::native<::NSDate>(a_date)]);
    }

    void TimeZone::reset_system_time_zone()
    {
        [::NSTimeZone resetSystemTimeZone];
    }

    std::int64_t TimeZone::seconds_from_gmt_for_date(const Date& a_date) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTimeZone>(this) secondsFromGMTForDate:cocoon::internal::native<::NSDate>(a_date)]);
    }

    TimeZone TimeZone::time_zone_for_seconds_from_gmt(std::int64_t seconds)
    {
        return cocoon::internal::wrap<TimeZone>([::NSTimeZone timeZoneForSecondsFromGMT:static_cast<::NSInteger>(seconds)]);
    }

    TimeZone TimeZone::time_zone_with_abbreviation(const std::string& abbreviation)
    {
        return cocoon::internal::wrap<TimeZone>([::NSTimeZone timeZoneWithAbbreviation:cocoon::internal::to(abbreviation)]);
    }

    TimeZone TimeZone::time_zone_with_name(const std::string& tz_name)
    {
        return cocoon::internal::wrap<TimeZone>([::NSTimeZone timeZoneWithName:cocoon::internal::to(tz_name)]);
    }

    TimeZone TimeZone::time_zone_with_name(const std::string& tz_name, const std::vector<std::uint8_t>& a_data)
    {
        return cocoon::internal::wrap<TimeZone>([::NSTimeZone timeZoneWithName:cocoon::internal::to(tz_name) data:cocoon::internal::to_data(a_data)]);
    }

    std::string TimeZone::abbreviation() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTimeZone>(this) abbreviation]);
    }

    std::vector<std::uint8_t> TimeZone::data() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSTimeZone>(this) data]);
    }

    bool TimeZone::is_daylight_saving_time() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTimeZone>(this) isDaylightSavingTime]);
    }

    double TimeZone::daylight_saving_time_offset() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTimeZone>(this) daylightSavingTimeOffset]);
    }

    TimeZone TimeZone::default_time_zone()
    {
        return cocoon::internal::wrap<TimeZone>([::NSTimeZone defaultTimeZone]);
    }

    void TimeZone::set_default_time_zone(const TimeZone& value)
    {
        [::NSTimeZone setDefaultTimeZone:cocoon::internal::native<::NSTimeZone>(value)];
    }

    std::string TimeZone::description() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTimeZone>(this) description]);
    }

    std::vector<std::string> TimeZone::known_time_zone_names()
    {
        return cocoon::internal::from_array<std::string>([::NSTimeZone knownTimeZoneNames], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    TimeZone TimeZone::local_time_zone()
    {
        return cocoon::internal::wrap<TimeZone>([::NSTimeZone localTimeZone]);
    }

    std::string TimeZone::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTimeZone>(this) name]);
    }

    Date TimeZone::next_daylight_saving_time_transition() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSTimeZone>(this) nextDaylightSavingTimeTransition]);
    }

    std::int64_t TimeZone::seconds_from_gmt() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTimeZone>(this) secondsFromGMT]);
    }

    TimeZone TimeZone::system_time_zone()
    {
        return cocoon::internal::wrap<TimeZone>([::NSTimeZone systemTimeZone]);
    }

    std::string TimeZone::time_zone_data_version()
    {
        return cocoon::internal::from([::NSTimeZone timeZoneDataVersion]);
    }
}
