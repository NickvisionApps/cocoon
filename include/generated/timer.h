#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class Invocation;

    /**
     * @brief C++ handle for the Objective-C class `NSTimer` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Timer timer;
     * timer.set_fire_date(cocoon::Date());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Timer timer{};
     * timer.set_fire_date(cocoon::Date());
     * auto fire_date = timer.fire_date();
     * timer.set_tolerance(1);
     * auto tolerance = timer.tolerance();
     * auto made_0 = cocoon::Timer::scheduled_timer_with_time_interval(1, cocoon::Invocation(), true);
     * timer.fire();
     * timer.invalidate();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nstimer
     */
    class Timer : public Object
    {
    public:
        /// @brief Creates a new `NSTimer` instance and returns a handle to it.
        explicit Timer(const Date& date, double interval, bool repeats, std::function<void(Timer)> block);
        /// @brief Creates a new `NSTimer` instance and returns a handle to it.
        explicit Timer(const Date& date, double ti, const Object& t, const std::string& s, const Object& ui, bool rep);
        /// @brief Creates a new `NSTimer` instance and returns a handle to it.
        explicit Timer(double ti, const Invocation& invocation, bool yes_or_no);
        /// @brief Creates a new `NSTimer` instance and returns a handle to it.
        explicit Timer(double interval, bool repeats, std::function<void(Timer)> block);
        /// @brief Creates a new `NSTimer` instance and returns a handle to it.
        explicit Timer(double ti, const Object& a_target, const std::string& a_selector, const Object& user_info, bool yes_or_no);
        /// @brief Creates a new `NSTimer` instance and returns a handle to it.
        explicit Timer();
        /// @brief Creates a null handle that refers to no native object.
        Timer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Timer(Adopt adopt);
        /**
         * @brief Calls `-[NSTimer fire]`.
         */
        void fire() const;
        /**
         * @brief Calls `-[NSTimer invalidate]`.
         */
        void invalidate() const;
        /**
         * @brief Calls `+[NSTimer scheduledTimerWithTimeInterval:invocation:repeats:]`.
         * @param ti Argument converted to the Objective-C parameter of the same role.
         * @param invocation Argument converted to the Objective-C parameter of the same role.
         * @param yes_or_no Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Timer scheduled_timer_with_time_interval(double ti, const Invocation& invocation, bool yes_or_no);
        /**
         * @brief Calls `+[NSTimer scheduledTimerWithTimeInterval:repeats:block:]`.
         * @details Creates and returns a new NSTimer object initialized with the specified block object and schedules it on the current run loop in the default mode. - parameter: ti The number of seconds between firings of the timer. If seconds is less than or equal to 0.0, this method chooses the nonnegative value of 0.1 milliseconds instead - parameter: repeats If YES, the timer will repeatedly reschedule itself until invalidated. If NO, the timer will be invalidated after it fires. - parameter: block The execution body of the timer; the timer itself is passed as the parameter to this block when executed to aid in avoiding cyclical references
         * @param interval Argument converted to the Objective-C parameter of the same role.
         * @param repeats Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Timer scheduled_timer_with_time_interval(double interval, bool repeats, std::function<void(Timer)> block);
        /**
         * @brief Calls `+[NSTimer scheduledTimerWithTimeInterval:target:selector:userInfo:repeats:]`.
         * @param ti Argument converted to the Objective-C parameter of the same role.
         * @param a_target Argument converted to the Objective-C parameter of the same role.
         * @param a_selector Argument converted to the Objective-C parameter of the same role.
         * @param user_info Argument converted to the Objective-C parameter of the same role.
         * @param yes_or_no Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Timer scheduled_timer_with_time_interval(double ti, const Object& a_target, const std::string& a_selector, const Object& user_info, bool yes_or_no);
        /**
         * @brief Returns the `fireDate` property of `NSTimer`.
         * @return The converted Objective-C result.
         */
        Date fire_date() const;
        /**
         * @brief Sets the `fireDate` property of `NSTimer`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_fire_date(const Date& value) const;
        /**
         * @brief Returns the `timeInterval` property of `NSTimer`.
         * @return The converted Objective-C result.
         */
        double time_interval() const;
        /**
         * @brief Returns the `tolerance` property of `NSTimer`.
         * @return The converted Objective-C result.
         */
        double tolerance() const;
        /**
         * @brief Sets the `tolerance` property of `NSTimer`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tolerance(double value) const;
        /**
         * @brief Returns the `userInfo` property of `NSTimer`.
         * @return The converted Objective-C result.
         */
        Object user_info() const;
        /**
         * @brief Returns the `valid` property of `NSTimer`.
         * @return The converted Objective-C result.
         */
        bool is_valid() const;
    };
}
