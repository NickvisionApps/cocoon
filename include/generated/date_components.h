#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Calendar;
    class Date;
    class TimeZone;

    /**
     * @brief C++ handle for the Objective-C class `NSDateComponents` (Foundation).
     * @details An object that specifies a date or time in terms of units (such as year, month, day, hour, and minute) to be evaluated in a calendar system and time zone. In Swift, this object bridges to ''DateComponents''; use ''NSDateComponents'' when you need reference semantics or other Foundation-specific behavior. ''NSDateComponents'' encapsulates the components of a date in an extendable, object-oriented manner. It's used to specify a date by providing the temporal components that make up a date and time: hour, minutes, seconds, day, month, year, and so on. You can also use it to specify a duration of time, for example, 5 hours and 16 minutes. An ''NSDateComponents'' object is not required to define all the component fields. When a new instance of ''NSDateComponents'' is created, the date components are set to ''NSDateComponentUndefined''. > Important: > An ''NSDateComponents'' object is meaningless in itself; you need to know what calendar it is interpreted against, and you need to know whether the values are absolute values of the units, or quantities of the units. An instance of ''NSDateComponents'' is not responsible for answering questions about a date beyond the information with which it was initialized. For example, if you initialize one with May 4, 2017, its weekday is ''NSDateComponentUndefined'', not Thursday. To get the correct day of the week, you must create a suitable instance of ''NSCalendar'', create an ''NSDate'' object using ''NSCalendar/date(from:)'' and then use ''NSCalendar/components(:from:)'' to retrieve the weekday—as illustrated in the following example. \@TabNavigator { \@Tab("Swift") { '''swift let dateComponents = NSDateComponents() dateComponents.day = 4 dateComponents.month = 5 dateComponents.year = 2017 if let gregorianCalendar = NSCalendar(calendarIdentifier: .gregorian), let date = gregorianCalendar.date(from: dateComponents as DateComponents) { let weekday = gregorianCalendar.component(.weekday, from: date) print(weekday) // 5, which corresponds to Thursday in the Gregorian Calendar } ''' } \@Tab("Objective-C") { '''objc NSDateComponents dateComponents = [[NSDateComponents alloc] init]; dateComponents.day = 4; dateComponents.month = 5; dateComponents.year = 2017; NSCalendar gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian]; NSDate date = [gregorianCalendar dateFromComponents:dateComponents]; NSInteger weekday = [gregorianCalendar component:NSCalendarUnitWeekday fromDate:date]; NSLog(\@"\%d", weekday); // 5, which corresponds to Thursday in the Gregorian Calendar ''' } } For more details, see [Calendars, Date Components, and Calendar Units](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/DatesAndTimes/Articles/dtCalendars.html\#//apple_ref/doc/uid/TP40003470) in [Date and Time Programming Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/DatesAndTimes/DatesAndTimes.html\#//apple_ref/doc/uid/10000039i). > Important: > The Swift overlay to the Foundation framework provides the ''DateComponents'' structure, which bridges to the ''NSDateComponents'' class. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DateComponents date_components;
     * date_components.set_calendar(cocoon::Calendar());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DateComponents date_components{};
     * date_components.set_calendar(cocoon::Calendar());
     * auto calendar = date_components.calendar();
     * date_components.set_day(1);
     * auto day = date_components.day();
     * date_components.set_day_of_year(1);
     * auto day_of_year = date_components.day_of_year();
     * date_components.is_valid_date_in_calendar(cocoon::Calendar());
     * date_components.set_value(1, cocoon::CalendarUnit::Era);
     * date_components.value_for_component(cocoon::CalendarUnit::Era);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdatecomponents
     */
    class DateComponents : public Object
    {
    public:
        /// @brief Creates a new `NSDateComponents` instance and returns a handle to it.
        explicit DateComponents();
        /// @brief Creates a null handle that refers to no native object.
        DateComponents(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DateComponents(Adopt adopt);
        /**
         * @brief Calls `-[NSDateComponents isValidDateInCalendar:]`.
         * @details Reports whether or not the combination of properties which have been set in the receiver is a date which exists in the calendar. This method is not appropriate for use on NSDateComponents objects which are specifying relative quantities of calendar components. Except for some trivial cases (e.g., 'seconds' should be 0 - 59 in any calendar), this method is not necessarily cheap. If the time zone property is set in the NSDateComponents object, it is used.
         * @param calendar Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_valid_date_in_calendar(const Calendar& calendar) const;
        /**
         * @brief Calls `-[NSDateComponents setValue:forComponent:]`.
         * @details This API allows one to set a specific component of NSDateComponents, by enum constant value rather than property name. The calendar and timeZone and isLeapMonth properties cannot be set by this method.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         */
        void set_value(std::int64_t value, CalendarUnit unit) const;
        /**
         * @brief Calls `-[NSDateComponents valueForComponent:]`.
         * @details This API allows one to get the value of a specific component of NSDateComponents, by enum constant value rather than property name. The calendar and timeZone and isLeapMonth property values cannot be retrieved by this method.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t value_for_component(CalendarUnit unit) const;
        /**
         * @brief Returns the `calendar` property of `NSDateComponents`.
         * @details The calendar used to interpret the date components.
         * @return The converted Objective-C result.
         */
        Calendar calendar() const;
        /**
         * @brief Sets the `calendar` property of `NSDateComponents`.
         * @details The calendar used to interpret the date components.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_calendar(const Calendar& value) const;
        /**
         * @brief Returns the `date` property of `NSDateComponents`.
         * @details The date calculated from the current components using the stored calendar.
         * @return The converted Objective-C result.
         */
        Date date() const;
        /**
         * @brief Returns the `day` property of `NSDateComponents`.
         * @details The number of days.
         * @return The converted Objective-C result.
         */
        std::int64_t day() const;
        /**
         * @brief Sets the `day` property of `NSDateComponents`.
         * @details The number of days.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_day(std::int64_t value) const;
        /**
         * @brief Returns the `dayOfYear` property of `NSDateComponents`.
         * @details The day of the year value of the date components.
         * @return The converted Objective-C result.
         */
        std::int64_t day_of_year() const;
        /**
         * @brief Sets the `dayOfYear` property of `NSDateComponents`.
         * @details The day of the year value of the date components.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_day_of_year(std::int64_t value) const;
        /**
         * @brief Returns the `era` property of `NSDateComponents`.
         * @details The number of eras.
         * @return The converted Objective-C result.
         */
        std::int64_t era() const;
        /**
         * @brief Sets the `era` property of `NSDateComponents`.
         * @details The number of eras.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_era(std::int64_t value) const;
        /**
         * @brief Returns the `hour` property of `NSDateComponents`.
         * @details The number of hour units for the receiver.
         * @return The converted Objective-C result.
         */
        std::int64_t hour() const;
        /**
         * @brief Sets the `hour` property of `NSDateComponents`.
         * @details The number of hour units for the receiver.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_hour(std::int64_t value) const;
        /**
         * @brief Returns the `leapMonth` property of `NSDateComponents`.
         * @details A Boolean value that indicates whether the month is a leap month.
         * @return The converted Objective-C result.
         */
        bool is_leap_month() const;
        /**
         * @brief Sets the `leapMonth` property of `NSDateComponents`.
         * @details A Boolean value that indicates whether the month is a leap month.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_leap_month(bool value) const;
        /**
         * @brief Returns the `minute` property of `NSDateComponents`.
         * @details The number of minute units for the receiver.
         * @return The converted Objective-C result.
         */
        std::int64_t minute() const;
        /**
         * @brief Sets the `minute` property of `NSDateComponents`.
         * @details The number of minute units for the receiver.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_minute(std::int64_t value) const;
        /**
         * @brief Returns the `month` property of `NSDateComponents`.
         * @details The number of months.
         * @return The converted Objective-C result.
         */
        std::int64_t month() const;
        /**
         * @brief Sets the `month` property of `NSDateComponents`.
         * @details The number of months.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_month(std::int64_t value) const;
        /**
         * @brief Returns the `nanosecond` property of `NSDateComponents`.
         * @details The number of nanosecond units for the receiver.
         * @return The converted Objective-C result.
         */
        std::int64_t nanosecond() const;
        /**
         * @brief Sets the `nanosecond` property of `NSDateComponents`.
         * @details The number of nanosecond units for the receiver.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_nanosecond(std::int64_t value) const;
        /**
         * @brief Returns the `quarter` property of `NSDateComponents`.
         * @details The number of quarters.
         * @return The converted Objective-C result.
         */
        std::int64_t quarter() const;
        /**
         * @brief Sets the `quarter` property of `NSDateComponents`.
         * @details The number of quarters.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_quarter(std::int64_t value) const;
        /**
         * @brief Returns the `repeatedDay` property of `NSDateComponents`.
         * @return The converted Objective-C result.
         */
        bool is_repeated_day() const;
        /**
         * @brief Sets the `repeatedDay` property of `NSDateComponents`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_repeated_day(bool value) const;
        /**
         * @brief Returns the `second` property of `NSDateComponents`.
         * @details The number of second units for the receiver.
         * @return The converted Objective-C result.
         */
        std::int64_t second() const;
        /**
         * @brief Sets the `second` property of `NSDateComponents`.
         * @details The number of second units for the receiver.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_second(std::int64_t value) const;
        /**
         * @brief Returns the `timeZone` property of `NSDateComponents`.
         * @details The time zone used to interpret the date components.
         * @return The converted Objective-C result.
         */
        TimeZone time_zone() const;
        /**
         * @brief Sets the `timeZone` property of `NSDateComponents`.
         * @details The time zone used to interpret the date components.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_time_zone(const TimeZone& value) const;
        /**
         * @brief Returns the `validDate` property of `NSDateComponents`.
         * @details Reports whether or not the combination of properties which have been set in the receiver is a date which exists in the calendar. This method is not appropriate for use on NSDateComponents objects which are specifying relative quantities of calendar components. Except for some trivial cases (e.g., 'seconds' should be 0 - 59 in any calendar), this method is not necessarily cheap. If the time zone property is set in the NSDateComponents object, it is used. The calendar property must be set, or NO is returned.
         * @return The converted Objective-C result.
         */
        bool is_valid_date() const;
        /**
         * @brief Returns the `weekOfMonth` property of `NSDateComponents`.
         * @details The week number of the months.
         * @return The converted Objective-C result.
         */
        std::int64_t week_of_month() const;
        /**
         * @brief Sets the `weekOfMonth` property of `NSDateComponents`.
         * @details The week number of the months.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_week_of_month(std::int64_t value) const;
        /**
         * @brief Returns the `weekOfYear` property of `NSDateComponents`.
         * @details The ISO 8601 week date of the year.
         * @return The converted Objective-C result.
         */
        std::int64_t week_of_year() const;
        /**
         * @brief Sets the `weekOfYear` property of `NSDateComponents`.
         * @details The ISO 8601 week date of the year.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_week_of_year(std::int64_t value) const;
        /**
         * @brief Returns the `weekday` property of `NSDateComponents`.
         * @details The number of the weekdays.
         * @return The converted Objective-C result.
         */
        std::int64_t weekday() const;
        /**
         * @brief Sets the `weekday` property of `NSDateComponents`.
         * @details The number of the weekdays.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_weekday(std::int64_t value) const;
        /**
         * @brief Returns the `weekdayOrdinal` property of `NSDateComponents`.
         * @details The ordinal number of weekdays.
         * @return The converted Objective-C result.
         */
        std::int64_t weekday_ordinal() const;
        /**
         * @brief Sets the `weekdayOrdinal` property of `NSDateComponents`.
         * @details The ordinal number of weekdays.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_weekday_ordinal(std::int64_t value) const;
        /**
         * @brief Returns the `year` property of `NSDateComponents`.
         * @details The number of years.
         * @return The converted Objective-C result.
         */
        std::int64_t year() const;
        /**
         * @brief Sets the `year` property of `NSDateComponents`.
         * @details The number of years.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_year(std::int64_t value) const;
        /**
         * @brief Returns the `yearForWeekOfYear` property of `NSDateComponents`.
         * @details The ISO 8601 week-numbering year.
         * @return The converted Objective-C result.
         */
        std::int64_t year_for_week_of_year() const;
        /**
         * @brief Sets the `yearForWeekOfYear` property of `NSDateComponents`.
         * @details The ISO 8601 week-numbering year.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_year_for_week_of_year(std::int64_t value) const;
    };
}
