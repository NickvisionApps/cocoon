#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSDate` (Foundation).
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
     * @param other Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ComparisonResult compare(const Date& other) const;
        /**
     * @brief Calls `+[NSDate date]`.
     * @return The converted Objective-C result.
     */
        static Date date();
        /**
     * @brief Calls `-[NSDate dateByAddingTimeInterval:]`.
     * @param ti Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Date date_by_adding_time_interval(double ti) const;
        /**
     * @brief Calls `+[NSDate dateWithTimeInterval:sinceDate:]`.
     * @param secs_to_be_added Argument converted to the Objective-C parameter of the same role.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Date date_with_time_interval(double secs_to_be_added, const Date& date);
        /**
     * @brief Calls `+[NSDate dateWithTimeIntervalSince1970:]`.
     * @param secs Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Date date_with_time_interval_since1970(double secs);
        /**
     * @brief Calls `+[NSDate dateWithTimeIntervalSinceNow:]`.
     * @param secs Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Date date_with_time_interval_since_now(double secs);
        /**
     * @brief Calls `+[NSDate dateWithTimeIntervalSinceReferenceDate:]`.
     * @param ti Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Date date_with_time_interval_since_reference_date(double ti);
        /**
     * @brief Calls `-[NSDate descriptionWithLocale:]`.
     * @param locale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string description_with_locale(const Object& locale) const;
        /**
     * @brief Calls `-[NSDate earlierDate:]`.
     * @param another_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Date earlier_date(const Date& another_date) const;
        /**
     * @brief Calls `-[NSDate isEqualToDate:]`.
     * @param other_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_equal_to_date(const Date& other_date) const;
        /**
     * @brief Calls `-[NSDate laterDate:]`.
     * @param another_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Date later_date(const Date& another_date) const;
        /**
     * @brief Calls `-[NSDate timeIntervalSinceDate:]`.
     * @param another_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double time_interval_since_date(const Date& another_date) const;
        /**
     * @brief Returns the `description` property of `NSDate`.
     * @return The converted Objective-C result.
     */
        std::string description() const;
        /**
     * @brief Returns the `distantFuture` property of `NSDate`.
     * @return The converted Objective-C result.
     */
        static Date distant_future();
        /**
     * @brief Returns the `distantPast` property of `NSDate`.
     * @return The converted Objective-C result.
     */
        static Date distant_past();
        /**
     * @brief Returns the `now` property of `NSDate`.
     * @return The converted Objective-C result.
     */
        static Date now();
        /**
     * @brief Returns the `timeIntervalSince1970` property of `NSDate`.
     * @return The converted Objective-C result.
     */
        double time_interval_since1970() const;
        /**
     * @brief Returns the `timeIntervalSinceNow` property of `NSDate`.
     * @return The converted Objective-C result.
     */
        double time_interval_since_now() const;
        /**
     * @brief Returns the `timeIntervalSinceReferenceDate` property of `NSDate`.
     * @return The converted Objective-C result.
     */
        double time_interval_since_reference_date() const;
    };
}
