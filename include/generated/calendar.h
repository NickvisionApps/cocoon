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
     * @details A definition of the relationships between calendar units and absolute points in time, providing features for calculation and comparison of dates. In Swift, this object bridges to ''Calendar''; use ''NSCalendar'' when you need reference semantics or other Foundation-specific behavior. ''NSCalendar'' objects encapsulate information about systems of reckoning time in which the beginning, length, and divisions of a year are defined. They provide information about the calendar and support for calendrical computations such as determining the range of a given calendrical unit and adding units to a given absolute time. ''NSCalendar'' is toll-free bridged with its Core Foundation counterpart, \<doc://com.apple.documentation/documentation/corefoundation/cfcalendar>. See [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2) for more information on toll-free bridging. > Important: > The Swift overlay to the Foundation framework provides the ''Calendar'' structure, which bridges to the ''NSCalendar'' class. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>. \#\#\# Locales and Calendars Most locales use the most widely used civil calendar, called the Gregorian calendar (''Identifier/gregorian''), but there remain exceptions to this trend. For example: - In Saudi Arabia, some locales use primarily the Islamic Umm al-Qura calendar (''Identifier/islamicUmmAlQura''). - In Ethiopia, some locales use primarily the Ethiopian calendar (''Identifier/ethiopicAmeteMihret'' or ''Identifier/ethiopicAmeteAlem''). - In Iran and Afghanistan, some locales use primarily the Persian calendar (''Identifier/persian''). - In Thailand, some locales use primarily the Buddhist calendar (''Identifier/buddhist''). Other locales use another calendar alongside the Gregorian calendar. For example: - India also uses the Indian national calendar (''Identifier/indian''). - Israel also uses the Hebrew calendar (''Identifier/hebrew''). - China mainland and other regions also use the Chinese calendar (''Identifier/chinese''), primarily to calculate astronomical date and Chinese traditional holidays. - Japan also uses the Japanese calendar (''Identifier/japanese''), primarily to add year names. Independent of any particular locale, certain calendars are used primarily to calculate dates for religious observances. Among these are the Buddhist (''Identifier/buddhist''), Coptic (''Identifier/coptic''), Hebrew (''Identifier/hebrew''), and Islamic (''Identifier/islamic'') calendars. \#\#\# How NSCalendar Models the Gregorian Calendar The Gregorian calendar was first introduced in 1582, as a replacement for the Julian Calendar. According to the Julian calendar, a leap day is added to February for any year with a number divisible by 4, which results in an annual disparity of 11 minutes, or 1 day every 128 years. The Gregorian calendar revised the rules for leap day calculation, by skipping the leap day for any year with a number divisible by 100, unless that year number is also divisible by 400, resulting in an annual disparity of only 26 seconds, or 1 day every 3323 years. To transition from the Julian calendar to the Gregorian calendar, 10 days were dropped from the Gregorian calendar (October 5–14). After the Gregorian calendar was introduced, many regions continued to use the Julian calendar, with Turkey being the last country or region to adopt the Gregorian calendar, in 1926. As a result of the staggered adoption, the transition period for regions at the time of adoption have different start dates and a different number of skipped days to account for the additional disparity from leap day calculations. ''NSCalendar'' models the behavior of a proleptic Gregorian calendar (as defined by ISO 8601:2004), which extends the Gregorian calendar backward in time from the date of its introduction. This behavior should be taken into account when working with dates created before the transition period of the affected locales. \#\#\# Calendar Arithmetic To do calendar arithmetic, you use ''NSDate'' objects in conjunction with a calendar. For example, to convert between a decomposed date in one calendar and another calendar, you must first convert the decomposed elements into a date using the first calendar, then decompose it using the second. ''NSDate'' provides the absolute scale and epoch (reference point) for dates and times, which can then be rendered into a particular calendar, for calendrical computations or user display. Two ''NSCalendar'' methods that return a date object, ''date(from:)'', ''date(byAdding:to:options:)'', take as a parameter an ''NSDateComponents'' object that describes the calendrical components required for the computation. You can provide as many components as you need (or choose to). When there is incomplete information to compute an absolute time, default values similar to '0' and '1' are usually chosen by a calendar, but this is a calendar-specific choice. If you provide inconsistent information, calendar-specific disambiguation is performed (which may involve ignoring one or more of the parameters). Related methods (''components(:from:)'' and ''components(:from:to:options:)-84y5w'') take a bit mask parameter that specifies which components to calculate when returning an ''NSDateComponents'' object. The bit mask is composed of ''Unit'' constants (see 'Constants'). In a calendar, day, week, weekday, month, and year numbers are generally 1-based, but there may be calendar-specific exceptions. Ordinal numbers, where they occur, are 1-based. Some calendars represented by this API may have to map their basic unit concepts into year/month/week/day/… nomenclature. For example, a calendar composed of 4 quarters in a year instead of 12 months uses the month unit to represent quarters. The particular values of the unit are defined by each calendar, and are not necessarily consistent with values for that unit in another calendar.
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
     * @details The date components representing a given date.
     * @param unit_flags Argument converted to the Objective-C parameter of the same role.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DateComponents components(CalendarUnit unit_flags, const Date& date) const;
        /**
     * @brief Calls `-[NSCalendar components:fromDate:toDate:options:]`.
     * @details Returns the difference between two supplied dates as date components. The result is lossy if there is not a small enough unit requested to hold the full precision of the difference. Some operations can be ambiguous, and the behavior of the computation is calendar-specific, but generally larger components will be computed before smaller components; for example, in the Gregorian calendar a result might be 1 month and 5 days instead of, for example, 0 months and 35 days. The resulting component values may be negative if 'resultDate' is before 'startDate'. Note that some computations can take a relatively long time. - Parameters: - unitFlags: Specifies the components for the returned 'NSDateComponents' object. - startingDate: The start date for the calculation. - resultDate: The end date for the calculation. - opts: Options for the calculation. If you specify ''NSCalendar/Options/wrapComponents'', the specified components are incremented and wrap around to zero/one on overflow, but do not cause higher units to be incremented. - Returns: An 'NSDateComponents' object whose components are specified by 'unitFlags' and calculated from the difference between the 'resultDate' and 'startDate'. Returns 'nil' if either date falls outside the defined range of the receiver or if the computation cannot be performed.
     * @param unit_flags Argument converted to the Objective-C parameter of the same role.
     * @param starting_date Argument converted to the Objective-C parameter of the same role.
     * @param result_date Argument converted to the Objective-C parameter of the same role.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DateComponents components(CalendarUnit unit_flags, const Date& starting_date, const Date& result_date, CalendarOptions opts) const;
        /**
     * @brief Calls `-[NSCalendar components:fromDateComponents:toDateComponents:options:]`.
     * @details Returns the difference between start and end dates given as date components. If an 'NSDateComponents' object does not specify a value for a calendar unit required to determine an absolute date, the base value of that unit is assumed. For example, given an 'NSDateComponents' object with only a 'year' and a 'month' specified, the resulting 'NSDate' object would be constructed using a 'day' value of '1' and 'hour', 'minute', 'second' and 'nanosecond' values of '0'. Passing an 'NSDateComponents' argument with an unspecified 'era' or 'year' value is not advised. If an 'NSDateComponents' object's 'timeZone' property is set, the time zone property value will be used in the calculation. If an 'NSDateComponents' object's 'calendar' property is set, the calendar property value will be used instead of the receiving calendar. If both an 'NSDateComponents' object's 'timeZone' and 'calendar' properties are set, the time zone property value overrides the time zone of the calendar property value. - Parameters: - unitFlags: Specifies the components for the returned 'NSDateComponents' object. - startingDateComp: The start date for the calculation as an 'NSDateComponents' object. - resultDateComp: The end date for the calculation as an 'NSDateComponents' object. - options: The options parameter is currently unused. - Returns: An 'NSDateComponents' object whose components are specified by 'unitFlags' and calculated from the difference between the 'startingDateComp' and 'resultDateComp'. Returns 'nil' if either date falls outside the defined range of the receiver or if the computation cannot be performed.
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
     * @details A date representing the absolute time calculated by adding given components to a given date.
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
     * @details Returns a new date representing the date calculated by setting a specific component of a given date to a given value, while trying to keep lower components the same. Changing a component's value often requires higher or coupled components to change as well. For example, setting the 'weekday' to "Thursday" will require the 'day' component to change its value, and possibly the 'month' and 'year' as well. If no such time exists, the next available date is returned, which may be on a different calendar day. - Parameters: - unit: The unit to set with the given value. For possible values, see ''NSCalendar/Unit''. - v: The value to set for the given calendar unit. - date: The date to use to perform the calculation. - opts: Options for the calculation. For possible values, see ''NSCalendar/Options''. - Returns: A new 'NSDate' instance representing the date calculated by setting a specific component of a given date to a given value. If the unit already has that value, this may result in a date which is the same as the given date.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @param v Argument converted to the Objective-C parameter of the same role.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Date date_by_setting_unit(CalendarUnit unit, std::int64_t v, const Date& date, CalendarOptions opts) const;
        /**
     * @brief Calls `-[NSCalendar dateFromComponents:]`.
     * @details A date created from the specified components.
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
     * @details Computes the dates that match (or most closely match) a given set of components, and calls the block once for each of them, until the enumeration is stopped. If you specify a strict matching option (''NSCalendar/Options/matchStrictly''), this method searches as far as necessary looking for a match, up to an implementation-defined limit. If an exact match is not possible, 'nil' is passed to the 'date' argument of the block, and the enumeration is stopped. Otherwise, this method searches as far as the next instance of the next highest calendar unit in the given 'NSDateComponents' object. If you do not specify a strict matching option, you must specify one of ''NSCalendar/Options/matchPreviousTimePreservingSmallerUnits'', ''NSCalendar/Options/matchNextTimePreservingSmallerUnits'', or ''NSCalendar/Options/matchNextTime'', or an illegal argument exception will be thrown. - Parameters: - start: The date for which to perform the calculation. - comps: The date components to match. If no components are specified, the enumeration will not be executed. - opts: Options for the enumeration. For possible values, see ''NSCalendar/Options''. - block: The block to apply to each enumerated date. The block takes three arguments: the enumerated date, whether the date exactly matches the specified date components, and a reference to a Boolean value that the block can set to 'YES' to stop the enumeration.
     * @param start Argument converted to the Objective-C parameter of the same role.
     * @param comps Argument converted to the Objective-C parameter of the same role.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_dates_starting_after_date(const Date& start, const DateComponents& comps, CalendarOptions opts, std::function<void(Date, bool, bool&)> block) const;
        /**
     * @brief Calls `-[NSCalendar getEra:year:month:day:fromDate:]`.
     * @details Returns the era, year, month, and day of a given date. Pass 'NULL' for a 'NSInteger' pointer parameter if you don't care about that value.
     * @param era_value_pointer Argument converted to the Objective-C parameter of the same role.
     * @param year_value_pointer Argument converted to the Objective-C parameter of the same role.
     * @param month_value_pointer Argument converted to the Objective-C parameter of the same role.
     * @param day_value_pointer Argument converted to the Objective-C parameter of the same role.
     * @param date Argument converted to the Objective-C parameter of the same role.
     */
        void get_era(std::int64_t* era_value_pointer, std::int64_t* year_value_pointer, std::int64_t* month_value_pointer, std::int64_t* day_value_pointer, const Date& date) const;
        /**
     * @brief Calls `-[NSCalendar getHour:minute:second:nanosecond:fromDate:]`.
     * @details Returns the hour, minute, second, and nanoseconds of a given date. Pass 'NULL' for a 'NSInteger' pointer parameter if you don't care about that value.
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
     * @details The maximum range limits of the values that a given unit can take on.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range maximum_range_of_unit(CalendarUnit unit) const;
        /**
     * @brief Calls `-[NSCalendar minimumRangeOfUnit:]`.
     * @details The minimum range limits of the values that a given unit can take on.
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
     * @details Returns by reference the starting date and time interval range of the next weekend period after a given date. Note that a particular calendar day may not necessarily fall entirely within a weekend period, as weekends can start in the middle of a day in some calendars and locales. The 'NSCalendarSearchBackwards' option can be used to find the previous weekend range strictly before the date. Returns 'NO' if there are no such things as weekends in the calendar and its locale. - Parameters: - datep: Upon return, contains the starting date of the next weekend period. - tip: Upon return, contains the time interval of the next weekend period. - options: Options for the calculation. If you specify ''NSCalendar/Options/searchBackwards'', the starting date and time interval range of the preceding weekend period will be returned by reference instead. - date: The date for which to perform the calculation. - Returns: 'NO' if the calendar and locale do not have the concept of a weekend, otherwise 'YES'.
     * @param datep Argument converted to the Objective-C parameter of the same role.
     * @param tip Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool next_weekend_start_date(Date& datep, double* tip, CalendarOptions options, const Date& date) const;
        /**
     * @brief Calls `-[NSCalendar ordinalityOfUnit:inUnit:forDate:]`.
     * @details The ordinal number of a smaller calendar unit within a specified larger calendar unit for a specified absolute time.
     * @param smaller Argument converted to the Objective-C parameter of the same role.
     * @param larger Argument converted to the Objective-C parameter of the same role.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t ordinality_of_unit(CalendarUnit smaller, CalendarUnit larger, const Date& date) const;
        /**
     * @brief Calls `-[NSCalendar rangeOfUnit:inUnit:forDate:]`.
     * @details The range of absolute time values that a smaller calendar unit can take on in a larger calendar unit for a specified absolute time.
     * @param smaller Argument converted to the Objective-C parameter of the same role.
     * @param larger Argument converted to the Objective-C parameter of the same role.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range range_of_unit(CalendarUnit smaller, CalendarUnit larger, const Date& date) const;
        /**
     * @brief Calls `-[NSCalendar rangeOfUnit:startDate:interval:forDate:]`.
     * @details The starting time and duration of a given calendar unit that contains a given date.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @param datep Argument converted to the Objective-C parameter of the same role.
     * @param tip Argument converted to the Objective-C parameter of the same role.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool range_of_unit(CalendarUnit unit, Date& datep, double* tip, const Date& date) const;
        /**
     * @brief Calls `-[NSCalendar rangeOfWeekendStartDate:interval:containingDate:]`.
     * @details Returns whether a given date falls within a weekend period, and if so, returns by reference the start date and time interval of the weekend range. Note that a particular calendar day may not necessarily fall entirely within a weekend period, as weekends can start in the middle of a day in some calendars and locales. - Parameters: - datep: Upon return, contains the starting date of the weekend period. - tip: Upon return, contains the time interval of the weekend period. - date: The date to use to perform the calculation. - Returns: 'YES' if the given date falls within a weekend period, otherwise 'NO'.
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
     * @details The AM symbol for this calendar.
     * @return The converted Objective-C result.
     */
        std::string am_symbol() const;
        /**
     * @brief Returns the `PMSymbol` property of `NSCalendar`.
     * @details The PM symbol for this calendar.
     * @return The converted Objective-C result.
     */
        std::string pm_symbol() const;
        /**
     * @brief Returns the `autoupdatingCurrentCalendar` property of `NSCalendar`.
     * @details A calendar that tracks changes to user's preferred calendar. Settings you get from this calendar do change as the user's settings change. Note that if you cache values based on the calendar or related information those caches will of course not be automatically updated by the updating of the calendar object.
     * @return The converted Objective-C result.
     */
        static Calendar autoupdating_current_calendar();
        /**
     * @brief Returns the `calendarIdentifier` property of `NSCalendar`.
     * @details An identifier for the calendar.
     * @return The converted Objective-C result.
     */
        std::string calendar_identifier() const;
        /**
     * @brief Returns the `currentCalendar` property of `NSCalendar`.
     * @details The user's current calendar. The returned calendar is formed from the settings for the current user's chosen system locale overlaid with any custom settings the user has specified in System Preferences. Settings you get from this calendar do not change as System Preferences are changed.
     * @return The converted Objective-C result.
     */
        static Calendar current_calendar();
        /**
     * @brief Returns the `eraSymbols` property of `NSCalendar`.
     * @details A list of era symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> era_symbols() const;
        /**
     * @brief Returns the `firstWeekday` property of `NSCalendar`.
     * @details The index of the first weekday for the calendar.
     * @return The converted Objective-C result.
     */
        std::uint64_t first_weekday() const;
        /**
     * @brief Sets the `firstWeekday` property of `NSCalendar`.
     * @details The index of the first weekday for the calendar.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_first_weekday(std::uint64_t value) const;
        /**
     * @brief Returns the `locale` property of `NSCalendar`.
     * @details The locale for the calendar.
     * @return The converted Objective-C result.
     */
        Locale locale() const;
        /**
     * @brief Sets the `locale` property of `NSCalendar`.
     * @details The locale for the calendar.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_locale(const Locale& value) const;
        /**
     * @brief Returns the `longEraSymbols` property of `NSCalendar`.
     * @details The long era symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> long_era_symbols() const;
        /**
     * @brief Returns the `minimumDaysInFirstWeek` property of `NSCalendar`.
     * @details The minimum number of days in the first week of the calendar.
     * @return The converted Objective-C result.
     */
        std::uint64_t minimum_days_in_first_week() const;
        /**
     * @brief Sets the `minimumDaysInFirstWeek` property of `NSCalendar`.
     * @details The minimum number of days in the first week of the calendar.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_days_in_first_week(std::uint64_t value) const;
        /**
     * @brief Returns the `monthSymbols` property of `NSCalendar`.
     * @details The list of month symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> month_symbols() const;
        /**
     * @brief Returns the `quarterSymbols` property of `NSCalendar`.
     * @details The list of quarter symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> quarter_symbols() const;
        /**
     * @brief Returns the `shortMonthSymbols` property of `NSCalendar`.
     * @details The list of short month symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_month_symbols() const;
        /**
     * @brief Returns the `shortQuarterSymbols` property of `NSCalendar`.
     * @details The list of short quarter symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_quarter_symbols() const;
        /**
     * @brief Returns the `shortStandaloneMonthSymbols` property of `NSCalendar`.
     * @details The list of short standalone month symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_standalone_month_symbols() const;
        /**
     * @brief Returns the `shortStandaloneQuarterSymbols` property of `NSCalendar`.
     * @details The list of short standalone quarter symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_standalone_quarter_symbols() const;
        /**
     * @brief Returns the `shortStandaloneWeekdaySymbols` property of `NSCalendar`.
     * @details The list of short standalone weekday symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_standalone_weekday_symbols() const;
        /**
     * @brief Returns the `shortWeekdaySymbols` property of `NSCalendar`.
     * @details The list of short weekday symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> short_weekday_symbols() const;
        /**
     * @brief Returns the `standaloneMonthSymbols` property of `NSCalendar`.
     * @details The list of standalone month symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> standalone_month_symbols() const;
        /**
     * @brief Returns the `standaloneQuarterSymbols` property of `NSCalendar`.
     * @details The list of standalone quarter symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> standalone_quarter_symbols() const;
        /**
     * @brief Returns the `standaloneWeekdaySymbols` property of `NSCalendar`.
     * @details The list of standalone weekday symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> standalone_weekday_symbols() const;
        /**
     * @brief Returns the `timeZone` property of `NSCalendar`.
     * @details The time zone for the calendar.
     * @return The converted Objective-C result.
     */
        TimeZone time_zone() const;
        /**
     * @brief Sets the `timeZone` property of `NSCalendar`.
     * @details The time zone for the calendar.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_time_zone(const TimeZone& value) const;
        /**
     * @brief Returns the `veryShortMonthSymbols` property of `NSCalendar`.
     * @details The list of very short month symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> very_short_month_symbols() const;
        /**
     * @brief Returns the `veryShortStandaloneMonthSymbols` property of `NSCalendar`.
     * @details The list of very short standalone month symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> very_short_standalone_month_symbols() const;
        /**
     * @brief Returns the `veryShortStandaloneWeekdaySymbols` property of `NSCalendar`.
     * @details The list of very short standalone weekday symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> very_short_standalone_weekday_symbols() const;
        /**
     * @brief Returns the `veryShortWeekdaySymbols` property of `NSCalendar`.
     * @details The list of very short weekday symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> very_short_weekday_symbols() const;
        /**
     * @brief Returns the `weekdaySymbols` property of `NSCalendar`.
     * @details The list of weekday symbols for this calendar.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> weekday_symbols() const;
    };
}
