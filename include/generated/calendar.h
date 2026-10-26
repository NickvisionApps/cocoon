#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class DateComponents;
    class Locale;
    class TimeZone;

    /**
     * @brief C++ handle for the Objective-C class `NSCalendar` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Calendar calendar{"text"};
     * calendar.set_first_weekday(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Calendar calendar{"text"};
     * calendar.set_first_weekday(1);
     * auto first_weekday = calendar.first_weekday();
     * calendar.set_locale(cocoon::Locale());
     * auto locale = calendar.locale();
     * calendar.set_minimum_days_in_first_week(1);
     * auto minimum_days_in_first_week = calendar.minimum_days_in_first_week();
     * calendar.compare_date(cocoon::Date(), cocoon::Date(), cocoon::CalendarUnit::Era);
     * calendar.component(cocoon::CalendarUnit::Era, cocoon::Date());
     * calendar.components(cocoon::CalendarUnit::Era, cocoon::Date());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nscalendar
     */
    class Calendar : public Object
    {
    public:
        /// @brief Creates a new `NSCalendar` instance and returns a handle to it.
        explicit Calendar(const std::string& ident);
        Calendar();
        /// @brief Creates a null handle that refers to no native object.
        Calendar(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Calendar(Adopt adopt);
        /**
         * @brief Calls `-[NSCalendar compareDate:toDate:toUnitGranularity:]`.
         * @details This API compares the given dates down to the given unit, reporting them equal if they are the same in the given unit and all larger units, otherwise either less than or greater than.
         * @param date1 Argument converted to the Objective-C parameter of the same role.
         * @param date2 Argument converted to the Objective-C parameter of the same role.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        ComparisonResult compare_date(const Date& date1, const Date& date2, CalendarUnit unit) const;
        /**
         * @brief Calls `-[NSCalendar component:fromDate:]`.
         * @details Get just one component's value.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t component(CalendarUnit unit, const Date& date) const;
        /**
         * @brief Calls `-[NSCalendar components:fromDate:]`.
         * @param unit_flags Argument converted to the Objective-C parameter of the same role.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        DateComponents components(CalendarUnit unit_flags, const Date& date) const;
        /**
         * @brief Calls `-[NSCalendar components:fromDate:toDate:options:]`.
         * @param unit_flags Argument converted to the Objective-C parameter of the same role.
         * @param starting_date Argument converted to the Objective-C parameter of the same role.
         * @param result_date Argument converted to the Objective-C parameter of the same role.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        DateComponents components(CalendarUnit unit_flags, const Date& starting_date, const Date& result_date, CalendarOptions opts) const;
        /**
         * @brief Calls `-[NSCalendar components:fromDateComponents:toDateComponents:options:]`.
         * @details This API returns the difference between two dates specified as date components. For units which are not specified in each NSDateComponents, but required to specify an absolute date, the base value of the unit is assumed. For example, for an NSDateComponents with just a Year and a Month specified, a Day of 1, and an Hour, Minute, Second, and Nanosecond of 0 are assumed. Calendrical calculations with unspecified Year or Year value prior to the start of a calendar are not advised. For each date components object, if its time zone property is set, that time zone is used for it; if the calendar property is set, that is used rather than the receiving calendar, and if both the calendar and time zone are set, the time zone property value overrides the time zone of the calendar property. No options are currently defined; pass 0.
         * @param unit_flags Argument converted to the Objective-C parameter of the same role.
         * @param starting_date_comp Argument converted to the Objective-C parameter of the same role.
         * @param result_date_comp Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        DateComponents components(CalendarUnit unit_flags, const DateComponents& starting_date_comp, const DateComponents& result_date_comp, CalendarOptions options) const;
        /**
         * @brief Calls `-[NSCalendar componentsInTimeZone:fromDate:]`.
         * @details This API returns all the date components of a date, as if in a given time zone (instead of the receiving calendar's time zone). The time zone overrides the time zone of the NSCalendar for the purposes of this calculation. Note: if you want "date information in a given time zone" in order to display it, you should use NSDateFormatter to format the date.
         * @param timezone Argument converted to the Objective-C parameter of the same role.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        DateComponents components_in_time_zone(const TimeZone& timezone, const Date& date) const;
        /**
         * @brief Calls `-[NSCalendar date:matchesComponents:]`.
         * @details This API returns YES if the date has all the matched components. Otherwise, it returns NO. It is useful to test the return value of the -nextDateAfterDate:matchingUnit:value:options:, to find out if the components were obeyed or if the method had to fudge the result value due to missing time.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @param components Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool date(const Date& date, const DateComponents& components) const;
        /**
         * @brief Calls `-[NSCalendar dateByAddingComponents:toDate:options:]`.
         * @param comps Argument converted to the Objective-C parameter of the same role.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Date date_by_adding_components(const DateComponents& comps, const Date& date, CalendarOptions opts) const;
        /**
         * @brief Calls `-[NSCalendar dateByAddingUnit:value:toDate:options:]`.
         * @details This API returns a new NSDate object representing the date calculated by adding an amount of a specific component to a given date. The NSCalendarWrapComponents option specifies if the component should be incremented and wrap around to zero/one on overflow, and should not cause higher units to be incremented.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Date date_by_adding_unit(CalendarUnit unit, std::int64_t value, const Date& date, CalendarOptions options) const;
        /**
         * @brief Calls `-[NSCalendar dateBySettingHour:minute:second:ofDate:options:]`.
         * @details This API returns a new NSDate object representing the date calculated by setting hour, minute, and second to a given time. If no such time exists, the next available time is returned (which could, for example, be in a different day than the nominal target date). The intent is to return a date on the same day as the original date argument. This may result in a date which is earlier than the given date, of course.
         * @param h Argument converted to the Objective-C parameter of the same role.
         * @param m Argument converted to the Objective-C parameter of the same role.
         * @param s Argument converted to the Objective-C parameter of the same role.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Date date_by_setting_hour(std::int64_t h, std::int64_t m, std::int64_t s, const Date& date, CalendarOptions opts) const;
        /**
         * @brief Calls `-[NSCalendar dateBySettingUnit:value:ofDate:options:]`.
         * @details This API returns a new NSDate object representing the date calculated by setting a specific component to a given time, and trying to keep lower components the same. If the unit already has that value, this may result in a date which is the same as the given date. Changing a component's value often will require higher or coupled components to change as well. For example, setting the Weekday to Thursday usually will require the Day component to change its value, and possibly the Month and Year as well. If no such time exists, the next available time is returned (which could, for example, be in a different day, week, month, ... than the nominal target date). Setting a component to something which would be inconsistent forces other units to change; for example, setting the Weekday to Thursday probably shifts the Day and possibly Month and Year. The specific behaviors here are as yet unspecified; for example, if I change the weekday to Thursday, does that move forward to the next, backward to the previous, or to the nearest Thursday? A likely rule is that the algorithm will try to produce a result which is in the next-larger unit to the one given (there's a table of this mapping at the top of this document). So for the "set to Thursday" example, find the Thursday in the Week in which the given date resides (which could be a forwards or backwards move, and not necessarily the nearest Thursday). For forwards or backwards behavior, one can use the -nextDateAfterDate:matchingUnit:value:options: method above.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @param v Argument converted to the Objective-C parameter of the same role.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Date date_by_setting_unit(CalendarUnit unit, std::int64_t v, const Date& date, CalendarOptions opts) const;
        /**
         * @brief Calls `-[NSCalendar dateFromComponents:]`.
         * @param comps Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Date date_from_components(const DateComponents& comps) const;
        /**
         * @brief Calls `-[NSCalendar dateWithEra:year:month:day:hour:minute:second:nanosecond:]`.
         * @details Create a date with given components. Current era is assumed.
         * @param era_value Argument converted to the Objective-C parameter of the same role.
         * @param year_value Argument converted to the Objective-C parameter of the same role.
         * @param month_value Argument converted to the Objective-C parameter of the same role.
         * @param day_value Argument converted to the Objective-C parameter of the same role.
         * @param hour_value Argument converted to the Objective-C parameter of the same role.
         * @param minute_value Argument converted to the Objective-C parameter of the same role.
         * @param second_value Argument converted to the Objective-C parameter of the same role.
         * @param nanosecond_value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Date date_with_era(std::int64_t era_value, std::int64_t year_value, std::int64_t month_value, std::int64_t day_value, std::int64_t hour_value, std::int64_t minute_value, std::int64_t second_value, std::int64_t nanosecond_value) const;
        /**
         * @brief Calls `-[NSCalendar enumerateDatesStartingAfterDate:matchingComponents:options:usingBlock:]`.
         * @details This method computes the dates which match (or most closely match) a given set of components, and calls the block once for each of them, until the enumeration is stopped. There will be at least one intervening date which does not match all the components (or the given date itself must not match) between the given date and any result. If the NSCalendarSearchBackwards option is used, this method finds the previous match before the given date. The intent is that the same matches as for a forwards search will be found (that is, if you are enumerating forwards or backwards for each hour with minute "27", the seconds in the date you will get in forwards search would obviously be 00, and the same will be true in a backwards search in order to implement this rule. Similarly for DST backwards jumps which repeats times, you'll get the first match by default, where "first" is defined from the point of view of searching forwards. So, when searching backwards looking for a particular hour, with no minute and second specified, you don't get a minute and second of 59:59 for the matching hour (which would be the nominal first match within a given hour, given the other rules here, when searching backwards). If the NSCalendarMatchStrictly option is used, the algorithm travels as far forward or backward as necessary looking for a match, but there are ultimately implementation-defined limits in how far distant the search will go. If the NSCalendarMatchStrictly option is not specified, the algorithm searches up to the end of the next instance of the next higher unit to the highest specified unit in the NSDateComponents argument. If you want to find the next Feb 29 in the Gregorian calendar, for example, you have to specify the NSCalendarMatchStrictly option to guarantee finding it. If an exact match is not possible, and requested with the NSCalendarMatchStrictly option, nil is passed to the block and the enumeration ends. (Logically, since an exact match searches indefinitely into the future, if no match is found there's no point in continuing the enumeration.) If the NSCalendarMatchStrictly option is NOT used, exactly one option from the set {NSCalendarMatchPreviousTimePreservingSmallerUnits, NSCalendarMatchNextTimePreservingSmallerUnits, NSCalendarMatchNextTime} must be specified, or an illegal argument exception will be thrown. If the NSCalendarMatchPreviousTimePreservingSmallerUnits option is specified, and there is no matching time before the end of the next instance of the next higher unit to the highest specified unit in the NSDateComponents argument, the method will return the previous existing value of the missing unit and preserves the lower units' values (e.g., no 2:37am results in 1:37am, if that exists). If the NSCalendarMatchNextTimePreservingSmallerUnits option is specified, and there is no matching time before the end of the next instance of the next higher unit to the highest specified unit in the NSDateComponents argument, the method will return the next existing value of the missing unit and preserves the lower units' values (e.g., no 2:37am results in 3:37am, if that exists). If the NSCalendarMatchNextTime option is specified, and there is no matching time before the end of the next instance of the next higher unit to the highest specified unit in the NSDateComponents argument, the method will return the next existing time which exists (e.g., no 2:37am results in 3:00am, if that exists). If the NSCalendarMatchFirst option is specified, and there are two or more matching times (all the components are the same, including isLeapMonth) before the end of the next instance of the next higher unit to the highest specified unit in the NSDateComponents argument, the method will return the first occurrence. If the NSCalendarMatchLast option is specified, and there are two or more matching times (all the components are the same, including isLeapMonth) before the end of the next instance of the next higher unit to the highest specified unit in the NSDateComponents argument, the method will return the last occurrence. If neither the NSCalendarMatchFirst or NSCalendarMatchLast option is specified, the default behavior is to act as if NSCalendarMatchFirst was specified. There is no option to return middle occurrences of more than two occurrences of a matching time, if such exist. Result dates have an integer number of seconds (as if 0 was specified for the nanoseconds property of the NSDateComponents matching parameter), unless a value was set in the nanoseconds property, in which case the result date will have that number of nanoseconds (or as close as possible with floating point numbers). The enumeration is stopped by setting stop = YES in the block and return. It is not necessary to set stop to NO to keep the enumeration going.
         * @param start Argument converted to the Objective-C parameter of the same role.
         * @param comps Argument converted to the Objective-C parameter of the same role.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_dates_starting_after_date(const Date& start, const DateComponents& comps, CalendarOptions opts, std::function<void(Date, bool, bool&)> block) const;
        /**
         * @brief Calls `-[NSCalendar getEra:year:month:day:fromDate:]`.
         * @details This API is a convenience for getting era, year, month, and day of a given date. Pass NULL for a NSInteger pointer parameter if you don't care about that value.
         * @param era_value_pointer Argument converted to the Objective-C parameter of the same role.
         * @param year_value_pointer Argument converted to the Objective-C parameter of the same role.
         * @param month_value_pointer Argument converted to the Objective-C parameter of the same role.
         * @param day_value_pointer Argument converted to the Objective-C parameter of the same role.
         * @param date Argument converted to the Objective-C parameter of the same role.
         */
        void get_era(std::int64_t* era_value_pointer, std::int64_t* year_value_pointer, std::int64_t* month_value_pointer, std::int64_t* day_value_pointer, const Date& date) const;
        /**
         * @brief Calls `-[NSCalendar getHour:minute:second:nanosecond:fromDate:]`.
         * @details This API is a convenience for getting hour, minute, second, and nanoseconds of a given date. Pass NULL for a NSInteger pointer parameter if you don't care about that value.
         * @param hour_value_pointer Argument converted to the Objective-C parameter of the same role.
         * @param minute_value_pointer Argument converted to the Objective-C parameter of the same role.
         * @param second_value_pointer Argument converted to the Objective-C parameter of the same role.
         * @param nanosecond_value_pointer Argument converted to the Objective-C parameter of the same role.
         * @param date Argument converted to the Objective-C parameter of the same role.
         */
        void get_hour(std::int64_t* hour_value_pointer, std::int64_t* minute_value_pointer, std::int64_t* second_value_pointer, std::int64_t* nanosecond_value_pointer, const Date& date) const;
        /**
         * @brief Calls `-[NSCalendar isDate:equalToDate:toUnitGranularity:]`.
         * @details This API compares the given dates down to the given unit, reporting them equal if they are the same in the given unit and all larger units.
         * @param date1 Argument converted to the Objective-C parameter of the same role.
         * @param date2 Argument converted to the Objective-C parameter of the same role.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_date(const Date& date1, const Date& date2, CalendarUnit unit) const;
        /**
         * @brief Calls `-[NSCalendar isDate:inSameDayAsDate:]`.
         * @details This API compares the Days of the given dates, reporting them equal if they are in the same Day.
         * @param date1 Argument converted to the Objective-C parameter of the same role.
         * @param date2 Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_date(const Date& date1, const Date& date2) const;
        /**
         * @brief Calls `-[NSCalendar isDateInToday:]`.
         * @details This API reports if the date is within "today".
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_date_in_today(const Date& date) const;
        /**
         * @brief Calls `-[NSCalendar isDateInTomorrow:]`.
         * @details This API reports if the date is within "tomorrow".
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_date_in_tomorrow(const Date& date) const;
        /**
         * @brief Calls `-[NSCalendar isDateInWeekend:]`.
         * @details This API reports if the date is within a weekend period, as defined by the calendar and calendar's locale.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_date_in_weekend(const Date& date) const;
        /**
         * @brief Calls `-[NSCalendar isDateInYesterday:]`.
         * @details This API reports if the date is within "yesterday".
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_date_in_yesterday(const Date& date) const;
        /**
         * @brief Calls `-[NSCalendar maximumRangeOfUnit:]`.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range maximum_range_of_unit(CalendarUnit unit) const;
        /**
         * @brief Calls `-[NSCalendar minimumRangeOfUnit:]`.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range minimum_range_of_unit(CalendarUnit unit) const;
        /**
         * @brief Calls `-[NSCalendar nextDateAfterDate:matchingComponents:options:]`.
         * @details This method computes the next date which matches (or most closely matches) a given set of components. The general semantics follow those of the -enumerateDatesStartingAfterDate:... method above. To compute a sequence of results, use the -enumerateDatesStartingAfterDate:... method above, rather than looping and calling this method with the previous loop iteration's result.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @param comps Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Date next_date_after_date(const Date& date, const DateComponents& comps, CalendarOptions options) const;
        /**
         * @brief Calls `-[NSCalendar nextDateAfterDate:matchingHour:minute:second:options:]`.
         * @details This API returns a new NSDate object representing the date found which matches the given hour, minute, and second values. The general semantics follow those of the -enumerateDatesStartingAfterDate:... method above. To compute a sequence of results, use the -enumerateDatesStartingAfterDate:... method above, rather than looping and calling this method with the previous loop iteration's result.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @param hour_value Argument converted to the Objective-C parameter of the same role.
         * @param minute_value Argument converted to the Objective-C parameter of the same role.
         * @param second_value Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Date next_date_after_date(const Date& date, std::int64_t hour_value, std::int64_t minute_value, std::int64_t second_value, CalendarOptions options) const;
        /**
         * @brief Calls `-[NSCalendar nextDateAfterDate:matchingUnit:value:options:]`.
         * @details This API returns a new NSDate object representing the date found which matches a specific component value. The general semantics follow those of the -enumerateDatesStartingAfterDate:... method above. To compute a sequence of results, use the -enumerateDatesStartingAfterDate:... method above, rather than looping and calling this method with the previous loop iteration's result.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Date next_date_after_date(const Date& date, CalendarUnit unit, std::int64_t value, CalendarOptions options) const;
        /**
         * @brief Calls `-[NSCalendar nextWeekendStartDate:interval:options:afterDate:]`.
         * @details Returns the range of the next weekend, via two by-reference parameters, which starts strictly after the given date. The NSCalendarSearchBackwards option can be used to find the previous weekend range strictly before the date. Returns NO if there are no such things as weekend in the calendar and its locale. Note that a given entire Day within a calendar is not necessarily all in a weekend or not; weekends can start in the middle of a Day in some calendars and locales.
         * @param datep Argument converted to the Objective-C parameter of the same role.
         * @param tip Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool next_weekend_start_date(Date& datep, double* tip, CalendarOptions options, const Date& date) const;
        /**
         * @brief Calls `-[NSCalendar ordinalityOfUnit:inUnit:forDate:]`.
         * @param smaller Argument converted to the Objective-C parameter of the same role.
         * @param larger Argument converted to the Objective-C parameter of the same role.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t ordinality_of_unit(CalendarUnit smaller, CalendarUnit larger, const Date& date) const;
        /**
         * @brief Calls `-[NSCalendar rangeOfUnit:inUnit:forDate:]`.
         * @param smaller Argument converted to the Objective-C parameter of the same role.
         * @param larger Argument converted to the Objective-C parameter of the same role.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range range_of_unit(CalendarUnit smaller, CalendarUnit larger, const Date& date) const;
        /**
         * @brief Calls `-[NSCalendar rangeOfUnit:startDate:interval:forDate:]`.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @param datep Argument converted to the Objective-C parameter of the same role.
         * @param tip Argument converted to the Objective-C parameter of the same role.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool range_of_unit(CalendarUnit unit, Date& datep, double* tip, const Date& date) const;
        /**
         * @brief Calls `-[NSCalendar rangeOfWeekendStartDate:interval:containingDate:]`.
         * @details Find the range of the weekend around the given date, returned via two by-reference parameters. Returns NO if the given date is not in a weekend. Note that a given entire Day within a calendar is not necessarily all in a weekend or not; weekends can start in the middle of a Day in some calendars and locales.
         * @param datep Argument converted to the Objective-C parameter of the same role.
         * @param tip Argument converted to the Objective-C parameter of the same role.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool range_of_weekend_start_date(Date& datep, double* tip, const Date& date) const;
        /**
         * @brief Calls `-[NSCalendar startOfDayForDate:]`.
         * @details This API returns the first moment date of a given date. Pass in [NSDate date], for example, if you want the start of "today". If there were two midnights, it returns the first. If there was none, it returns the first moment that did exist.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Date start_of_day_for_date(const Date& date) const;
        /**
         * @brief Returns the `AMSymbol` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::string am_symbol() const;
        /**
         * @brief Returns the `PMSymbol` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::string pm_symbol() const;
        /**
         * @brief Returns the `autoupdatingCurrentCalendar` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        static Calendar autoupdating_current_calendar();
        /**
         * @brief Returns the `calendarIdentifier` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::string calendar_identifier() const;
        /**
         * @brief Returns the `currentCalendar` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        static Calendar current_calendar();
        /**
         * @brief Returns the `eraSymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> era_symbols() const;
        /**
         * @brief Returns the `firstWeekday` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::uint64_t first_weekday() const;
        /**
         * @brief Sets the `firstWeekday` property of `NSCalendar`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_first_weekday(std::uint64_t value) const;
        /**
         * @brief Returns the `locale` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        Locale locale() const;
        /**
         * @brief Sets the `locale` property of `NSCalendar`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_locale(const Locale& value) const;
        /**
         * @brief Returns the `longEraSymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> long_era_symbols() const;
        /**
         * @brief Returns the `minimumDaysInFirstWeek` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::uint64_t minimum_days_in_first_week() const;
        /**
         * @brief Sets the `minimumDaysInFirstWeek` property of `NSCalendar`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_minimum_days_in_first_week(std::uint64_t value) const;
        /**
         * @brief Returns the `monthSymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> month_symbols() const;
        /**
         * @brief Returns the `quarterSymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> quarter_symbols() const;
        /**
         * @brief Returns the `shortMonthSymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> short_month_symbols() const;
        /**
         * @brief Returns the `shortQuarterSymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> short_quarter_symbols() const;
        /**
         * @brief Returns the `shortStandaloneMonthSymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> short_standalone_month_symbols() const;
        /**
         * @brief Returns the `shortStandaloneQuarterSymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> short_standalone_quarter_symbols() const;
        /**
         * @brief Returns the `shortStandaloneWeekdaySymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> short_standalone_weekday_symbols() const;
        /**
         * @brief Returns the `shortWeekdaySymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> short_weekday_symbols() const;
        /**
         * @brief Returns the `standaloneMonthSymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> standalone_month_symbols() const;
        /**
         * @brief Returns the `standaloneQuarterSymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> standalone_quarter_symbols() const;
        /**
         * @brief Returns the `standaloneWeekdaySymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> standalone_weekday_symbols() const;
        /**
         * @brief Returns the `timeZone` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        TimeZone time_zone() const;
        /**
         * @brief Sets the `timeZone` property of `NSCalendar`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_time_zone(const TimeZone& value) const;
        /**
         * @brief Returns the `veryShortMonthSymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> very_short_month_symbols() const;
        /**
         * @brief Returns the `veryShortStandaloneMonthSymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> very_short_standalone_month_symbols() const;
        /**
         * @brief Returns the `veryShortStandaloneWeekdaySymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> very_short_standalone_weekday_symbols() const;
        /**
         * @brief Returns the `veryShortWeekdaySymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> very_short_weekday_symbols() const;
        /**
         * @brief Returns the `weekdaySymbols` property of `NSCalendar`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> weekday_symbols() const;
    };
}
