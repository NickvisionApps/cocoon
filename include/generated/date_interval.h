#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;

    /**
     * @brief C++ handle for the Objective-C class `NSDateInterval` (Foundation).
     * @details An object representing the span of time between a specific start date and end date. In Swift, this object bridges to ''DateInterval''; use ''NSDateInterval'' when you need reference semantics or other Foundation-specific behavior. An 'NSDateInterval' object represents a closed interval between two dates. The 'NSDateInterval' class provides a programmatic interface for calculating the duration of a time interval and determining whether a date falls within it, as well as comparing date intervals and checking to see whether they intersect. An 'NSDateInterval' object consists of a ''startDate'' and an ''endDate''. The ''startDate'' and ''endDate'' of a date interval can be equal, in which case its ''duration'' is '0'. However, ''endDate'' cannot occur earlier than ''startDate''. You can use the ''DateIntervalFormatter'' class to create string representations of 'NSDateInterval' objects that are suitable for display in the current locale. > Important: > The Swift overlay to the Foundation framework provides the ''DateInterval'' structure, which bridges to the 'NSDateInterval' class. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DateInterval date_interval;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DateInterval date_interval{};
     * date_interval.compare(cocoon::DateInterval());
     * date_interval.contains_date(cocoon::Date());
     * date_interval.intersection_with_date_interval(cocoon::DateInterval());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdateinterval
     */
    class DateInterval : public Object
    {
    public:
        /// @brief Creates a new `NSDateInterval` instance and returns a handle to it.
        explicit DateInterval(const Date& start_date, double duration);
        /// @brief Creates a new `NSDateInterval` instance and returns a handle to it.
        explicit DateInterval(const Date& start_date, const Date& end_date);
        /// @brief Creates a new `NSDateInterval` instance and returns a handle to it.
        explicit DateInterval();
        /// @brief Creates a null handle that refers to no native object.
        DateInterval(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DateInterval(Adopt adopt);
        /**
     * @brief Calls `-[NSDateInterval compare:]`.
     * @details If both the start dates and the durations are equal, then the intervals are considered equal and 'NSOrderedSame' is returned as the result. - Parameters: - dateInterval: The date interval with which to compare the receiver. - Returns: An 'NSComparisonResult' value that indicates the temporal ordering of the receiver and the given date interval: 'NSOrderedAscending' if the receiver's start date occurs earlier, or both start dates are equal and the receiver's duration is less. 'NSOrderedDescending' if the receiver's start date occurs later, or both start dates are equal and the receiver's duration is greater. 'NSOrderedSame' if the start dates and durations are equal.
     * @param date_interval Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ComparisonResult compare(const DateInterval& date_interval) const;
        /**
     * @brief Calls `-[NSDateInterval containsDate:]`.
     * @details Indicates whether the receiver contains the specified date. - Parameters: - date: The date for which to test membership of the date interval. - Returns: 'YES' if the receiver contains 'date'. Otherwise, 'NO'.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool contains_date(const Date& date) const;
        /**
     * @brief Calls `-[NSDateInterval intersectionWithDateInterval:]`.
     * @details Returns the intersection between the receiver and the specified date interval. - Parameters: - dateInterval: The date interval with which to calculate the intersection of the receiver. - Returns: A date interval for the intersection of the receiver and 'dateInterval', or 'nil' if no intersection occurs. Calculating the intersection of date intervals is a commutative and associative operation. The intersection of a date interval with itself is equal to itself.
     * @param date_interval Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DateInterval intersection_with_date_interval(const DateInterval& date_interval) const;
        /**
     * @brief Calls `-[NSDateInterval intersectsDateInterval:]`.
     * @details Indicates whether the receiver intersects with the specified date interval. - Parameters: - dateInterval: The date interval with which to check the receiver for intersection.
     * @param date_interval Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool intersects_date_interval(const DateInterval& date_interval) const;
        /**
     * @brief Calls `-[NSDateInterval isEqualToDateInterval:]`.
     * @details Indicates whether the receiver is equal to the specified date interval. - Parameters: - dateInterval: The date interval with which to check the receiver for equality. - Returns: 'YES' if the start date and duration of 'dateInterval' and the receiver are equal. Otherwise, 'NO'.
     * @param date_interval Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_equal_to_date_interval(const DateInterval& date_interval) const;
        /**
     * @brief Returns the `duration` property of `NSDateInterval`.
     * @details The duration of the date interval.
     * @return The converted Objective-C result.
     */
        double duration() const;
        /**
     * @brief Returns the `endDate` property of `NSDateInterval`.
     * @details The end date of the date interval.
     * @return The converted Objective-C result.
     */
        Date end_date() const;
        /**
     * @brief Returns the `startDate` property of `NSDateInterval`.
     * @details The start date of the date interval.
     * @return The converted Objective-C result.
     */
        Date start_date() const;
    };
}
