#include "generated/calendar.h"
#include "internal.h"

namespace cocoon
{
    Calendar::Calendar() : Object(nullptr)
    {
    }

    Calendar::Calendar(std::nullptr_t) : Object(nullptr)
    {
    }

    Calendar::Calendar(Adopt adopt) : Object(adopt)
    {
    }

    Calendar Calendar::calendar_with_identifier(const std::string& calendar_identifier_constant)
    {
        return cocoon::internal::wrap<Calendar>([::NSCalendar calendarWithIdentifier:cocoon::internal::to(calendar_identifier_constant)]);
    }

    ComparisonResult Calendar::compare_date(const Date& date1, const Date& date2, CalendarUnit unit) const
    {
        return static_cast<ComparisonResult>([cocoon::internal::ns<::NSCalendar>(this) compareDate:cocoon::internal::native<::NSDate>(date1) toDate:cocoon::internal::native<::NSDate>(date2) toUnitGranularity:static_cast<::NSCalendarUnit>(unit)]);
    }

    std::int64_t Calendar::component(CalendarUnit unit, const Date& date) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCalendar>(this) component:static_cast<::NSCalendarUnit>(unit) fromDate:cocoon::internal::native<::NSDate>(date)]);
    }

    DateComponents Calendar::components(CalendarUnit unit_flags, const Date& date) const
    {
        return cocoon::internal::wrap<DateComponents>([cocoon::internal::ns<::NSCalendar>(this) components:static_cast<::NSCalendarUnit>(unit_flags) fromDate:cocoon::internal::native<::NSDate>(date)]);
    }

    DateComponents Calendar::components(CalendarUnit unit_flags, const Date& starting_date, const Date& result_date, CalendarOptions opts) const
    {
        return cocoon::internal::wrap<DateComponents>([cocoon::internal::ns<::NSCalendar>(this) components:static_cast<::NSCalendarUnit>(unit_flags) fromDate:cocoon::internal::native<::NSDate>(starting_date) toDate:cocoon::internal::native<::NSDate>(result_date) options:static_cast<::NSCalendarOptions>(opts)]);
    }

    DateComponents Calendar::components(CalendarUnit unit_flags, const DateComponents& starting_date_comp, const DateComponents& result_date_comp, CalendarOptions options) const
    {
        return cocoon::internal::wrap<DateComponents>([cocoon::internal::ns<::NSCalendar>(this) components:static_cast<::NSCalendarUnit>(unit_flags) fromDateComponents:cocoon::internal::native<::NSDateComponents>(starting_date_comp) toDateComponents:cocoon::internal::native<::NSDateComponents>(result_date_comp) options:static_cast<::NSCalendarOptions>(options)]);
    }

    DateComponents Calendar::components_in_time_zone(const TimeZone& timezone, const Date& date) const
    {
        return cocoon::internal::wrap<DateComponents>([cocoon::internal::ns<::NSCalendar>(this) componentsInTimeZone:cocoon::internal::native<::NSTimeZone>(timezone) fromDate:cocoon::internal::native<::NSDate>(date)]);
    }

    bool Calendar::date(const Date& date, const DateComponents& components) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCalendar>(this) date:cocoon::internal::native<::NSDate>(date) matchesComponents:cocoon::internal::native<::NSDateComponents>(components)]);
    }

    Date Calendar::date_by_adding_components(const DateComponents& comps, const Date& date, CalendarOptions opts) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSCalendar>(this) dateByAddingComponents:cocoon::internal::native<::NSDateComponents>(comps) toDate:cocoon::internal::native<::NSDate>(date) options:static_cast<::NSCalendarOptions>(opts)]);
    }

    Date Calendar::date_by_adding_unit(CalendarUnit unit, std::int64_t value, const Date& date, CalendarOptions options) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSCalendar>(this) dateByAddingUnit:static_cast<::NSCalendarUnit>(unit) value:static_cast<::NSInteger>(value) toDate:cocoon::internal::native<::NSDate>(date) options:static_cast<::NSCalendarOptions>(options)]);
    }

    Date Calendar::date_by_setting_hour(std::int64_t h, std::int64_t m, std::int64_t s, const Date& date, CalendarOptions opts) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSCalendar>(this) dateBySettingHour:static_cast<::NSInteger>(h) minute:static_cast<::NSInteger>(m) second:static_cast<::NSInteger>(s) ofDate:cocoon::internal::native<::NSDate>(date) options:static_cast<::NSCalendarOptions>(opts)]);
    }

    Date Calendar::date_by_setting_unit(CalendarUnit unit, std::int64_t v, const Date& date, CalendarOptions opts) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSCalendar>(this) dateBySettingUnit:static_cast<::NSCalendarUnit>(unit) value:static_cast<::NSInteger>(v) ofDate:cocoon::internal::native<::NSDate>(date) options:static_cast<::NSCalendarOptions>(opts)]);
    }

    Date Calendar::date_from_components(const DateComponents& comps) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSCalendar>(this) dateFromComponents:cocoon::internal::native<::NSDateComponents>(comps)]);
    }

    Date Calendar::date_with_era(std::int64_t era_value, std::int64_t year_value, std::int64_t month_value, std::int64_t day_value, std::int64_t hour_value, std::int64_t minute_value, std::int64_t second_value, std::int64_t nanosecond_value) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSCalendar>(this) dateWithEra:static_cast<::NSInteger>(era_value) year:static_cast<::NSInteger>(year_value) month:static_cast<::NSInteger>(month_value) day:static_cast<::NSInteger>(day_value) hour:static_cast<::NSInteger>(hour_value) minute:static_cast<::NSInteger>(minute_value) second:static_cast<::NSInteger>(second_value) nanosecond:static_cast<::NSInteger>(nanosecond_value)]);
    }

    void Calendar::enumerate_dates_starting_after_date(const Date& start, const DateComponents& comps, CalendarOptions opts, std::function<void(Date, bool, bool&)> block) const
    {
        [cocoon::internal::ns<::NSCalendar>(this) enumerateDatesStartingAfterDate:cocoon::internal::native<::NSDate>(start) matchingComponents:cocoon::internal::native<::NSDateComponents>(comps) options:static_cast<::NSCalendarOptions>(opts) usingBlock:(block ? (void (^)(::NSDate*, BOOL, BOOL*)) ^ void(::NSDate * a129_0, ::BOOL a129_1, ::BOOL * a129_2) { bool __o129_2 = a129_2 ? static_cast<bool>(*a129_2) : bool(); block(cocoon::internal::wrap<Date>(a129_0), static_cast<bool>(a129_1), __o129_2); if (a129_2) { *a129_2 = static_cast<::BOOL>(__o129_2); } } : (void (^)(::NSDate*, BOOL, BOOL*))nil)];
    }

    void Calendar::get_era(std::int64_t* era_value_pointer, std::int64_t* year_value_pointer, std::int64_t* month_value_pointer, std::int64_t* day_value_pointer, const Date& date) const
    {
        [cocoon::internal::ns<::NSCalendar>(this) getEra:(::NSInteger*)(era_value_pointer) year:(::NSInteger*)(year_value_pointer)month:(::NSInteger*)(month_value_pointer)day:(::NSInteger*)(day_value_pointer)fromDate:cocoon::internal::native<::NSDate>(date)];
    }

    void Calendar::get_hour(std::int64_t* hour_value_pointer, std::int64_t* minute_value_pointer, std::int64_t* second_value_pointer, std::int64_t* nanosecond_value_pointer, const Date& date) const
    {
        [cocoon::internal::ns<::NSCalendar>(this) getHour:(::NSInteger*)(hour_value_pointer) minute:(::NSInteger*)(minute_value_pointer)second:(::NSInteger*)(second_value_pointer)nanosecond:(::NSInteger*)(nanosecond_value_pointer)fromDate:cocoon::internal::native<::NSDate>(date)];
    }

    Object Calendar::init_with_calendar_identifier(const std::string& ident) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSCalendar>(this) initWithCalendarIdentifier:cocoon::internal::to(ident)]);
    }

    bool Calendar::is_date(const Date& date1, const Date& date2, CalendarUnit unit) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCalendar>(this) isDate:cocoon::internal::native<::NSDate>(date1) equalToDate:cocoon::internal::native<::NSDate>(date2) toUnitGranularity:static_cast<::NSCalendarUnit>(unit)]);
    }

    bool Calendar::is_date(const Date& date1, const Date& date2) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCalendar>(this) isDate:cocoon::internal::native<::NSDate>(date1) inSameDayAsDate:cocoon::internal::native<::NSDate>(date2)]);
    }

    bool Calendar::is_date_in_today(const Date& date) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCalendar>(this) isDateInToday:cocoon::internal::native<::NSDate>(date)]);
    }

    bool Calendar::is_date_in_tomorrow(const Date& date) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCalendar>(this) isDateInTomorrow:cocoon::internal::native<::NSDate>(date)]);
    }

    bool Calendar::is_date_in_weekend(const Date& date) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCalendar>(this) isDateInWeekend:cocoon::internal::native<::NSDate>(date)]);
    }

    bool Calendar::is_date_in_yesterday(const Date& date) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCalendar>(this) isDateInYesterday:cocoon::internal::native<::NSDate>(date)]);
    }

    Range Calendar::maximum_range_of_unit(CalendarUnit unit) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCalendar>(this) maximumRangeOfUnit:static_cast<::NSCalendarUnit>(unit)]);
    }

    Range Calendar::minimum_range_of_unit(CalendarUnit unit) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCalendar>(this) minimumRangeOfUnit:static_cast<::NSCalendarUnit>(unit)]);
    }

    Date Calendar::next_date_after_date(const Date& date, const DateComponents& comps, CalendarOptions options) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSCalendar>(this) nextDateAfterDate:cocoon::internal::native<::NSDate>(date) matchingComponents:cocoon::internal::native<::NSDateComponents>(comps) options:static_cast<::NSCalendarOptions>(options)]);
    }

    Date Calendar::next_date_after_date(const Date& date, std::int64_t hour_value, std::int64_t minute_value, std::int64_t second_value, CalendarOptions options) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSCalendar>(this) nextDateAfterDate:cocoon::internal::native<::NSDate>(date) matchingHour:static_cast<::NSInteger>(hour_value) minute:static_cast<::NSInteger>(minute_value) second:static_cast<::NSInteger>(second_value) options:static_cast<::NSCalendarOptions>(options)]);
    }

    Date Calendar::next_date_after_date(const Date& date, CalendarUnit unit, std::int64_t value, CalendarOptions options) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSCalendar>(this) nextDateAfterDate:cocoon::internal::native<::NSDate>(date) matchingUnit:static_cast<::NSCalendarUnit>(unit) value:static_cast<::NSInteger>(value) options:static_cast<::NSCalendarOptions>(options)]);
    }

    bool Calendar::next_weekend_start_date(Date& datep, double* tip, CalendarOptions options, const Date& date) const
    {
        ::NSDate* __v_datep = nil;
        auto __r = [cocoon::internal::ns<::NSCalendar>(this) nextWeekendStartDate:&__v_datep interval:(::NSTimeInterval*)(tip)options:static_cast<::NSCalendarOptions>(options) afterDate:cocoon::internal::native<::NSDate>(date)];
        datep = cocoon::internal::wrap<Date>(__v_datep);
        return static_cast<bool>(__r);
    }

    std::uint64_t Calendar::ordinality_of_unit(CalendarUnit smaller, CalendarUnit larger, const Date& date) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSCalendar>(this) ordinalityOfUnit:static_cast<::NSCalendarUnit>(smaller) inUnit:static_cast<::NSCalendarUnit>(larger) forDate:cocoon::internal::native<::NSDate>(date)]);
    }

    Range Calendar::range_of_unit(CalendarUnit smaller, CalendarUnit larger, const Date& date) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCalendar>(this) rangeOfUnit:static_cast<::NSCalendarUnit>(smaller) inUnit:static_cast<::NSCalendarUnit>(larger) forDate:cocoon::internal::native<::NSDate>(date)]);
    }

    bool Calendar::range_of_unit(CalendarUnit unit, Date& datep, double* tip, const Date& date) const
    {
        ::NSDate* __v_datep = nil;
        auto __r = [cocoon::internal::ns<::NSCalendar>(this) rangeOfUnit:static_cast<::NSCalendarUnit>(unit) startDate:&__v_datep interval:(::NSTimeInterval*)(tip)forDate:cocoon::internal::native<::NSDate>(date)];
        datep = cocoon::internal::wrap<Date>(__v_datep);
        return static_cast<bool>(__r);
    }

    bool Calendar::range_of_weekend_start_date(Date& datep, double* tip, const Date& date) const
    {
        ::NSDate* __v_datep = nil;
        auto __r = [cocoon::internal::ns<::NSCalendar>(this) rangeOfWeekendStartDate:&__v_datep interval:(::NSTimeInterval*)(tip)containingDate:cocoon::internal::native<::NSDate>(date)];
        datep = cocoon::internal::wrap<Date>(__v_datep);
        return static_cast<bool>(__r);
    }

    Date Calendar::start_of_day_for_date(const Date& date) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSCalendar>(this) startOfDayForDate:cocoon::internal::native<::NSDate>(date)]);
    }

    std::string Calendar::am_symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCalendar>(this) AMSymbol]);
    }

    std::string Calendar::pm_symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCalendar>(this) PMSymbol]);
    }

    Calendar Calendar::autoupdating_current_calendar()
    {
        return cocoon::internal::wrap<Calendar>([::NSCalendar autoupdatingCurrentCalendar]);
    }

    std::string Calendar::calendar_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCalendar>(this) calendarIdentifier]);
    }

    Calendar Calendar::current_calendar()
    {
        return cocoon::internal::wrap<Calendar>([::NSCalendar currentCalendar]);
    }

    std::vector<std::string> Calendar::era_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) eraSymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::uint64_t Calendar::first_weekday() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSCalendar>(this) firstWeekday]);
    }

    void Calendar::set_first_weekday(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSCalendar>(this) setFirstWeekday:static_cast<::NSUInteger>(value)];
    }

    Locale Calendar::locale() const
    {
        return cocoon::internal::wrap<Locale>([cocoon::internal::ns<::NSCalendar>(this) locale]);
    }

    void Calendar::set_locale(const Locale& value) const
    {
        [cocoon::internal::ns<::NSCalendar>(this) setLocale:cocoon::internal::native<::NSLocale>(value)];
    }

    std::vector<std::string> Calendar::long_era_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) longEraSymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::uint64_t Calendar::minimum_days_in_first_week() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSCalendar>(this) minimumDaysInFirstWeek]);
    }

    void Calendar::set_minimum_days_in_first_week(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSCalendar>(this) setMinimumDaysInFirstWeek:static_cast<::NSUInteger>(value)];
    }

    std::vector<std::string> Calendar::month_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) monthSymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Calendar::quarter_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) quarterSymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Calendar::short_month_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) shortMonthSymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Calendar::short_quarter_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) shortQuarterSymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Calendar::short_standalone_month_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) shortStandaloneMonthSymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Calendar::short_standalone_quarter_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) shortStandaloneQuarterSymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Calendar::short_standalone_weekday_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) shortStandaloneWeekdaySymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Calendar::short_weekday_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) shortWeekdaySymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Calendar::standalone_month_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) standaloneMonthSymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Calendar::standalone_quarter_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) standaloneQuarterSymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Calendar::standalone_weekday_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) standaloneWeekdaySymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    TimeZone Calendar::time_zone() const
    {
        return cocoon::internal::wrap<TimeZone>([cocoon::internal::ns<::NSCalendar>(this) timeZone]);
    }

    void Calendar::set_time_zone(const TimeZone& value) const
    {
        [cocoon::internal::ns<::NSCalendar>(this) setTimeZone:cocoon::internal::native<::NSTimeZone>(value)];
    }

    std::vector<std::string> Calendar::very_short_month_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) veryShortMonthSymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Calendar::very_short_standalone_month_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) veryShortStandaloneMonthSymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Calendar::very_short_standalone_weekday_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) veryShortStandaloneWeekdaySymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Calendar::very_short_weekday_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) veryShortWeekdaySymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Calendar::weekday_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSCalendar>(this) weekdaySymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }
}
