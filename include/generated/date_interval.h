#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;

    /**
     * @brief C++ handle for the Objective-C class `NSDateInterval` (Foundation).
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
         * @details (NSComparisonResult)compare:(NSDateInterval ) prioritizes ordering by start date. If the start dates are equal, then it will order by duration. e.g. Given intervals a and b a. |-----| b. |-----| [a compare:b] would return NSOrderedAscending because a's startDate is earlier in time than b's start date. In the event that the start dates are equal, the compare method will attempt to order by duration. e.g. Given intervals c and d c. |-----| d. |---| [c compare:d] would result in NSOrderedDescending because c is longer than d. If both the start dates and the durations are equal, then the intervals are considered equal and NSOrderedSame is returned as the result.
         * @param date_interval Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        ComparisonResult compare(const DateInterval& date_interval) const;
        /**
         * @brief Calls `-[NSDateInterval containsDate:]`.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool contains_date(const Date& date) const;
        /**
         * @brief Calls `-[NSDateInterval intersectionWithDateInterval:]`.
         * @details This method returns an NSDateInterval object that represents the interval where the given date interval and the current instance intersect. In the event that there is no intersection, the method returns nil.
         * @param date_interval Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        DateInterval intersection_with_date_interval(const DateInterval& date_interval) const;
        /**
         * @brief Calls `-[NSDateInterval intersectsDateInterval:]`.
         * @param date_interval Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool intersects_date_interval(const DateInterval& date_interval) const;
        /**
         * @brief Calls `-[NSDateInterval isEqualToDateInterval:]`.
         * @param date_interval Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_equal_to_date_interval(const DateInterval& date_interval) const;
        /**
         * @brief Returns the `duration` property of `NSDateInterval`.
         * @return The converted Objective-C result.
         */
        double duration() const;
        /**
         * @brief Returns the `endDate` property of `NSDateInterval`.
         * @return The converted Objective-C result.
         */
        Date end_date() const;
        /**
         * @brief Returns the `startDate` property of `NSDateInterval`.
         * @details NSDateInterval represents a closed date interval in the form of [startDate, endDate]. It is possible for the start and end dates to be the same with a duration of 0. NSDateInterval does not support reverse intervals i.e. intervals where the duration is less than 0 and the end date occurs earlier in time than the start date.
         * @return The converted Objective-C result.
         */
        Date start_date() const;
    };
}
