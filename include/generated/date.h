#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSDate` (Foundation).
     * @details A representation of a specific point in time, independent of any calendar or time zone. In Swift, use this type when you need reference semantics or other Foundation-specific behavior. ''NSDate'' objects encapsulate a single point in time, independent of any particular calendrical system or time zone. Date objects are immutable, representing an invariant time interval relative to an absolute reference date (00:00:00 UTC on 1 January 2001). The ''NSDate'' class provides methods for comparing dates, calculating the time interval between two dates, and creating a new date from a time interval relative to another date. ''NSDate'' objects can be used in conjunction with ''DateFormatter'' objects to create localized representations of dates and times, as well as with ''NSCalendar'' objects to perform calendar arithmetic. ''NSDate'' is toll-free bridged with its Core Foundation counterpart, \<doc://com.apple.documentation/documentation/corefoundation/cfdate>. See [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2) for more information on toll-free bridging. > Important: > The Swift overlay to the Foundation framework provides the ''Date'' structure, which bridges to the ''NSDate'' class. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>. \#\#\# Subclassing Notes You might subclass ''NSDate'' in order to make it easier to work with a particular calendrical system, or to work with date and time values with a finer temporal granularity. \#\#\#\# Methods to Override and Other Requirements If you want to subclass ''NSDate'' to obtain behavior different than that provided by the private or public subclasses, you must: - Declare a suitable instance variable to hold the date and time value (relative to an absolute reference date) - Override the ''timeIntervalSinceReferenceDate-property'' instance method to provide the correct date and time value based on your instance variable - Override ''init(timeIntervalSinceReferenceDate:)'', one of the designated initializer methods - If creating a subclass that represents a calendrical system, define methods that partition past and future periods into the units of this calendar - Implement the methods required by the ''NSCopying'' and [NSCoding](https://developer.apple.com/library/archive/documentation/Swift/Conceptual/BuildingCocoaApps/WritingSwiftClassesWithObjective-CBehavior.html\#//apple_ref/doc/uid/TP40014216-CH5-ID152) protocols, because ''NSDate'' adopts these protocols \#\#\#\# Special Considerations Your subclass may use a different reference date than the absolute reference date used by ''NSDate'' (00:00:00 UTC on 1 January 2001). If it does, it must still use the absolute reference date in its implementations of the methods ''timeIntervalSinceReferenceDate-property'' and ''init(timeIntervalSinceReferenceDate:)''. That is, the reference date referred to in the titles of these methods is the absolute reference date. If you do not use the absolute reference date in these methods, comparisons between ''NSDate'' objects of your subclass and 'NSDate' objects of a private subclass will not work.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Date date;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Date date{};
     * auto made_0 = cocoon::Date::date();
     * auto made_1 = cocoon::Date::date_with_time_interval(1, cocoon::Date());
     * date.compare(cocoon::Date());
     * date.date_by_adding_time_interval(1);
     * date.earlier_date(cocoon::Date());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdate
     */
    class Date : public Object
    {
    public:
        /// @brief Creates a new `NSDate` instance and returns a handle to it.
        explicit Date(double secs_to_be_added, const Date& date);
        /// @brief Creates a new `NSDate` instance and returns a handle to it.
        explicit Date(double secs);
        /// @brief Creates a new `NSDate` instance and returns a handle to it.
        explicit Date();
        /// @brief Creates a null handle that refers to no native object.
        Date(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Date(Adopt adopt);
        /**
     * @brief Calls `-[NSDate compare:]`.
     * @details Indicates the temporal ordering of the receiver and another given date. - Parameter other: The date with which to compare the receiver. This value must not be 'nil'. If the value is 'nil', the behavior is undefined and may change in future versions of macOS. - Returns: 'NSOrderedSame' if the two dates are exactly equal, 'NSOrderedDescending' if the receiver is later in time than 'other', and 'NSOrderedAscending' if the receiver is earlier in time than 'other'. This method detects sub-second differences between dates. If you want to compare dates with a less fine granularity, use 'timeIntervalSinceDate:' to compare the two dates.
     * @param other Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ComparisonResult compare(const Date& other) const;
        /**
     * @brief Calls `+[NSDate date]`.
     * @details Creates and returns a new date object set to the current date and time. This method uses the default initializer method for the class, 'init'.
     * @return The converted Objective-C result.
     */
        static Date date();
        /**
     * @brief Calls `-[NSDate dateByAddingTimeInterval:]`.
     * @details Returns a new date object that is set to a given number of seconds relative to the receiver. - Parameter ti: The number of seconds to add to the receiver. Use a negative value for seconds to have the returned object specify a date before the receiver. - Returns: A new 'NSDate' object that is set to 'seconds' seconds relative to the receiver. The date returned might have a representation different from the receiver's.
     * @param ti Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Date date_by_adding_time_interval(double ti) const;
        /**
     * @brief Calls `+[NSDate dateWithTimeInterval:sinceDate:]`.
     * @details Creates and returns a date object set to a given number of seconds from the specified date. - Parameter secsToBeAdded: The number of seconds to add to 'date'. Use a negative argument to specify a date and time before 'date'. - Parameter date: The date. - Returns: An 'NSDate' object set to 'secsToBeAdded' seconds from 'date'.
     * @param secs_to_be_added Argument converted to the Objective-C parameter of the same role.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Date date_with_time_interval(double secs_to_be_added, const Date& date);
        /**
     * @brief Calls `+[NSDate dateWithTimeIntervalSince1970:]`.
     * @details Creates and returns a date object set to the given number of seconds from 00:00:00 UTC on 1 January 1970. - Parameter secs: The number of seconds from the reference date (00:00:00 UTC on 1 January 1970) for the new date. Use a negative argument to specify a date and time before the reference date. - Returns: An 'NSDate' object set to 'secs' seconds from the reference date. This method is useful for creating 'NSDate' objects from 'time_t' values returned by BSD system functions.
     * @param secs Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Date date_with_time_interval_since1970(double secs);
        /**
     * @brief Calls `+[NSDate dateWithTimeIntervalSinceNow:]`.
     * @details Creates and returns a date object set to a given number of seconds from the current date and time. - Parameter secs: The number of seconds from the current date and time for the new date. Use a negative value to specify a date before the current date. - Returns: An 'NSDate' object set to 'secs' seconds from the current date and time.
     * @param secs Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Date date_with_time_interval_since_now(double secs);
        /**
     * @brief Calls `+[NSDate dateWithTimeIntervalSinceReferenceDate:]`.
     * @details Creates and returns a date object set to a given number of seconds from 00:00:00 UTC on 1 January 2001. - Parameter ti: The number of seconds from the absolute reference date (00:00:00 UTC on 1 January 2001) for the new date. Use a negative argument to specify a date and time before the reference date. - Returns: An 'NSDate' object set to 'ti' seconds from the absolute reference date.
     * @param ti Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Date date_with_time_interval_since_reference_date(double ti);
        /**
     * @brief Calls `-[NSDate descriptionWithLocale:]`.
     * @details Returns a string representation of the date using the given locale. - Parameter locale: An 'NSLocale' object. If you pass 'nil', 'NSDate' formats the date in the same way as the 'description' property. - Returns: A string representation of the receiver, using the given locale, or if the locale argument is 'nil', in the international format 'YYYY-MM-DD HH:MM:SS +/-HHMM', where '+/-HHMM' represents the time zone offset in hours and minutes from UTC (for example, "2001-03-24 10:45:32 +0600").
     * @param locale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string description_with_locale(const Object& locale) const;
        /**
     * @brief Calls `-[NSDate earlierDate:]`.
     * @details Returns the earlier of the receiver and another given date. - Parameter anotherDate: The date with which to compare the receiver. - Returns: The earlier of the receiver and 'anotherDate', determined using 'timeIntervalSinceDate:'. If the receiver and 'anotherDate' represent the same date, returns the receiver.
     * @param another_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Date earlier_date(const Date& another_date) const;
        /**
     * @brief Calls `-[NSDate isEqualToDate:]`.
     * @details Returns a Boolean value that indicates whether a given object is a date that is exactly equal the receiver. - Parameter otherDate: The date to compare with the receiver. - Returns: 'YES' if the 'otherDate' is an 'NSDate' object and is exactly equal to the receiver, otherwise 'NO'. This method detects sub-second differences between dates. If you want to compare dates with a less fine granularity, use 'timeIntervalSinceDate:' to compare the two dates.
     * @param other_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_equal_to_date(const Date& other_date) const;
        /**
     * @brief Calls `-[NSDate laterDate:]`.
     * @details Returns the later of the receiver and another given date. - Parameter anotherDate: The date with which to compare the receiver. - Returns: The later of the receiver and 'anotherDate', determined using 'timeIntervalSinceDate:'. If the receiver and 'anotherDate' represent the same date, returns the receiver.
     * @param another_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Date later_date(const Date& another_date) const;
        /**
     * @brief Calls `-[NSDate timeIntervalSinceDate:]`.
     * @details Returns the interval between the receiver and another given date. - Parameter anotherDate: The date with which to compare the receiver. You must pass a non-'nil' date object. - Returns: The interval between the receiver and the 'anotherDate' parameter. If the receiver is earlier than 'anotherDate', the return value is negative. If 'anotherDate' is 'nil', the results are undefined.
     * @param another_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double time_interval_since_date(const Date& another_date) const;
        /**
     * @brief Returns the `description` property of `NSDate`.
     * @details A string representation of the date object. The representation is useful for debugging only. There are a number of options to acquire a formatted string for a date including: date formatters (see 'NSDateFormatter'), and the 'NSDate' methods 'descriptionWithLocale:'.
     * @return The converted Objective-C result.
     */
        std::string description() const;
        /**
     * @brief Returns the `distantFuture` property of `NSDate`.
     * @details A date object representing a date in the distant future. You can pass this value when an 'NSDate' object is required to have the date argument essentially ignored. For example, the 'NSWindow' method 'nextEventMatchingMask:untilDate:inMode:dequeue:' returns 'nil' if an event specified in the event mask does not happen before the specified date. You can use the object returned by 'distantFuture' as the date argument to wait indefinitely for the event to occur.
     * @return The converted Objective-C result.
     */
        static Date distant_future();
        /**
     * @brief Returns the `distantPast` property of `NSDate`.
     * @details A date object representing a date in the distant past. You can use this object as a control date, a guaranteed temporal boundary.
     * @return The converted Objective-C result.
     */
        static Date distant_past();
        /**
     * @brief Returns the `now` property of `NSDate`.
     * @details The current date and time, as of the time of access. This is equivalent to initializing a new instance with 'NSDate()' (or '[[NSDate alloc] init]' in Objective-C). The 'NSDate' instance doesn't automatically update its time after you retrieve it.
     * @return The converted Objective-C result.
     */
        static Date now();
        /**
     * @brief Returns the `timeIntervalSince1970` property of `NSDate`.
     * @details The interval between the date object and 00:00:00 UTC on 1 January 1970. This property's value is negative if the date object is earlier than 00:00:00 UTC on 1 January 1970.
     * @return The converted Objective-C result.
     */
        double time_interval_since1970() const;
        /**
     * @brief Returns the `timeIntervalSinceNow` property of `NSDate`.
     * @details The interval between the date object and the current date and time. If the date object is earlier than the current date and time, this property's value is negative.
     * @return The converted Objective-C result.
     */
        double time_interval_since_now() const;
        /**
     * @brief Returns the `timeIntervalSinceReferenceDate` property of `NSDate`.
     * @details The interval between the date object and 00:00:00 UTC on 1 January 2001. This property's value is negative if the date object is earlier than the system's absolute reference date (00:00:00 UTC on 1 January 2001).
     * @return The converted Objective-C result.
     */
        double time_interval_since_reference_date() const;
    };
}
