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
     * @details A timer that fires after a certain time interval has elapsed, sending a specified message to a target object. Timers work in conjunction with run loops. Run loops maintain strong references to their timers, so you don't have to maintain your own strong reference to a timer after you have added it to a run loop. To use a timer effectively, you should be aware of how run loops operate. See [Threading Programming Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/Multithreading/Introduction/Introduction.html\#//apple_ref/doc/uid/10000057i) for more information. A timer is not a real-time mechanism. If a timer's firing time occurs during a long run loop callout or while the run loop is in a mode that isn't monitoring the timer, the timer doesn't fire until the next time the run loop checks the timer. Therefore, the actual time at which a timer fires can be significantly later. See also \<doc:\#Timer-Tolerance>. ''Timer'' is toll-free bridged with its Core Foundation counterpart, \<doc://com.apple.documentation/documentation/corefoundation/cfrunlooptimer>. See [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2) for more information. \#\#\# Comparing Repeating and Nonrepeating Timers You specify whether a timer is repeating or nonrepeating at creation time. A nonrepeating timer fires once and then invalidates itself automatically, thereby preventing the timer from firing again. By contrast, a repeating timer fires and then reschedules itself on the same run loop. A repeating timer always schedules itself based on the scheduled firing time, as opposed to the actual firing time. For example, if a timer is scheduled to fire at a particular time and every 5 seconds after that, the scheduled firing time will always fall on the original 5-second time intervals, even if the actual firing time gets delayed. If the firing time is delayed so far that it passes one or more of the scheduled firing times, the timer is fired only once for that time period; the timer is then rescheduled, after firing, for the next scheduled firing time in the future. \#\#\# Timer Tolerance In iOS 7 and later and macOS 10.9 and later, you can specify a tolerance for a timer (''tolerance''). This flexibility in when a timer fires improves the system's ability to optimize for increased power savings and responsiveness. The timer may fire at any time between its scheduled fire date and the scheduled fire date plus the tolerance. The timer doesn't fire before the scheduled fire date. For repeating timers, the next fire date is calculated from the original fire date regardless of tolerance applied at individual fire times, to avoid drift. The default value is zero, which means no additional tolerance is applied. The system reserves the right to apply a small amount of tolerance to certain timers regardless of the value of the ''tolerance'' property. As the user of the timer, you can determine the appropriate tolerance for a timer. A general rule, set the tolerance to at least 10\% of the interval, for a repeating timer. Even a small amount of tolerance has significant positive impact on the power usage of your application. The system may enforce a maximum value for the tolerance. \#\#\# Scheduling Timers in Run Loops You can register a timer in only one run loop at a time, although it can be added to multiple run loop modes within that run loop. There are three ways to create a timer: - Use the ''scheduledTimer(timeInterval:invocation:repeats:)'' or ''scheduledTimer(timeInterval:target:selector:userInfo:repeats:)'' class method to create the timer and schedule it on the current run loop in the default mode. - Use the ''init(timeInterval:invocation:repeats:)'' or ''init(timeInterval:target:selector:userInfo:repeats:)'' class method to create the timer object without scheduling it on a run loop. (After creating it, you must add the timer to a run loop manually by calling the ''RunLoop/add(:forMode:)-392ag'' method of the corresponding ''RunLoop'' object.) - Allocate the timer and initialize it using the ''init(fireAt:interval:target:selector:userInfo:repeats:)'' method. (After creating it, you must add the timer to a run loop manually by calling the ''RunLoop/add(:forMode:)-392ag'' method of the corresponding ''RunLoop'' object.) Once scheduled on a run loop, the timer fires at the specified interval until it is invalidated. A nonrepeating timer invalidates itself immediately after it fires. However, for a repeating timer, you must invalidate the timer object yourself by calling its ''invalidate()'' method. Calling this method requests the removal of the timer from the current run loop; as a result, you should always call the ''invalidate()'' method from the same thread on which the timer was installed. Invalidating the timer immediately disables it so that it no longer affects the run loop. The run loop then removes the timer (and the strong reference it had to the timer), either just before the ''invalidate()'' method returns or at some later point. Once invalidated, timer objects cannot be reused. After a repeating timer fires, it schedules the next firing for the nearest future date that is an integer multiple of the timer interval after the last scheduled fire date, within the specified ''tolerance''. If the time taken to call out to perform a selector or invocation is longer than the specified interval, the timer schedules only the next firing; that is, the timer doesn't attempt to compensate for any missed firings that would have occurred while calling the specified selector or invocation. \#\#\# Subclassing Notes Do not subclass ''Timer''.
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
         * @details Causes the timer's message to be sent to its target. You can use this method to fire a repeating timer without interrupting its regular firing schedule. If the timer is non-repeating, it is automatically invalidated after firing, even if its scheduled fire date has not arrived.
         */
        void fire() const;
        /**
         * @brief Calls `-[NSTimer invalidate]`.
         * @details Stops the timer from ever firing again and requests its removal from its run loop. This method is the only way to remove a timer from an 'NSRunLoop' object. The 'NSRunLoop' object removes its strong reference to the timer, either just before the -invalidate method returns or at some later point. If it was configured with target and user info objects, the receiver removes its strong references to those objects as well. You must send this message from the thread on which the timer was installed. If you send this message from another thread, the input source associated with the timer may not be removed from its run loop, which could prevent the thread from exiting properly.
         */
        void invalidate() const;
        /**
         * @brief Calls `+[NSTimer scheduledTimerWithTimeInterval:invocation:repeats:]`.
         * @details Creates a new timer and schedules it on the current run loop in the default mode. After 'ti' seconds have elapsed, the timer fires, invoking 'invocation'. - Parameters: - ti: The number of seconds between firings of the timer. If 'ti' is less than or equal to '0.0', this method chooses the nonnegative value of '0.0001' seconds instead. - invocation: The invocation to use when the timer fires. The invocation object maintains a strong reference to its arguments until the timer is invalidated. - yesOrNo: If 'YES', the timer will repeatedly reschedule itself until invalidated. If 'NO', the timer will be invalidated after it fires. - Returns: A new 'NSTimer' object, configured according to the specified parameters.
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
         * @details Creates a timer and schedules it on the current run loop in the default mode. After 'ti' seconds have elapsed, the timer fires, sending the message 'aSelector' to 'target'. - Parameters: - ti: The number of seconds between firings of the timer. If 'ti' is less than or equal to '0.0', this method chooses the nonnegative value of '0.0001' seconds instead. - aTarget: The object to which to send the message specified by 'aSelector' when the timer fires. The timer maintains a strong reference to 'target' until it (the timer) is invalidated. - aSelector: The message to send to 'target' when the timer fires. - userInfo: The user info for the timer. The timer maintains a strong reference to this object until it (the timer) is invalidated. This parameter may be 'nil'. - yesOrNo: If 'YES', the timer will repeatedly reschedule itself until invalidated. If 'NO', the timer will be invalidated after it fires. - Returns: A new 'NSTimer' object, configured according to the specified parameters.
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
         * @details The date at which the timer will fire. If the timer is no longer valid, the last date at which the timer fired. You can set this property to adjust the firing time of a repeating timer. Although resetting a timer's next firing time is a relatively expensive operation, it may be more efficient in some situations. For example, you could use it in situations where you want to repeat an action multiple times in the future, but at irregular time intervals. Adjusting the firing time of a single timer would likely incur less expense than creating multiple timer objects, scheduling each one on a run loop, and then destroying them. You should not change the fire date of a timer that has been invalidated, which includes non-repeating timers that have already fired. You could potentially change the fire date of a non-repeating timer that had not yet fired, although you should always do so from the thread to which the timer is attached to avoid potential race conditions.
         * @return The converted Objective-C result.
         */
        Date fire_date() const;
        /**
         * @brief Sets the `fireDate` property of `NSTimer`.
         * @details The date at which the timer will fire. If the timer is no longer valid, the last date at which the timer fired. You can set this property to adjust the firing time of a repeating timer. Although resetting a timer's next firing time is a relatively expensive operation, it may be more efficient in some situations. For example, you could use it in situations where you want to repeat an action multiple times in the future, but at irregular time intervals. Adjusting the firing time of a single timer would likely incur less expense than creating multiple timer objects, scheduling each one on a run loop, and then destroying them. You should not change the fire date of a timer that has been invalidated, which includes non-repeating timers that have already fired. You could potentially change the fire date of a non-repeating timer that had not yet fired, although you should always do so from the thread to which the timer is attached to avoid potential race conditions.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_fire_date(const Date& value) const;
        /**
         * @brief Returns the `timeInterval` property of `NSTimer`.
         * @details The timer's time interval, in seconds. If the timer is non-repeating, returns '0' even if a time interval was set.
         * @return The converted Objective-C result.
         */
        double time_interval() const;
        /**
         * @brief Returns the `tolerance` property of `NSTimer`.
         * @details The amount of time after the scheduled fire date that the timer may fire. The default value is zero, which means no additional tolerance is applied. Setting a tolerance for a timer allows it to fire later than the scheduled fire date. Allowing the system flexibility in when a timer fires increases the ability of the system to optimize for increased power savings and responsiveness. The timer may fire at any time between its scheduled fire date and the scheduled fire date plus the tolerance. The timer will not fire before the scheduled fire date. For repeating timers, the next fire date is calculated from the original fire date regardless of tolerance applied at individual fire times, to avoid drift. The system reserves the right to apply a small amount of tolerance to certain timers regardless of the value of this property.
         * @return The converted Objective-C result.
         */
        double tolerance() const;
        /**
         * @brief Sets the `tolerance` property of `NSTimer`.
         * @details The amount of time after the scheduled fire date that the timer may fire. The default value is zero, which means no additional tolerance is applied. Setting a tolerance for a timer allows it to fire later than the scheduled fire date. Allowing the system flexibility in when a timer fires increases the ability of the system to optimize for increased power savings and responsiveness. The timer may fire at any time between its scheduled fire date and the scheduled fire date plus the tolerance. The timer will not fire before the scheduled fire date. For repeating timers, the next fire date is calculated from the original fire date regardless of tolerance applied at individual fire times, to avoid drift. The system reserves the right to apply a small amount of tolerance to certain timers regardless of the value of this property.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tolerance(double value) const;
        /**
         * @brief Returns the `userInfo` property of `NSTimer`.
         * @details The receiver's 'userInfo' object. Do not access this property after the timer is invalidated. Use the 'isValid' method to test whether the timer is valid.
         * @return The converted Objective-C result.
         */
        Object user_info() const;
        /**
         * @brief Returns the `valid` property of `NSTimer`.
         * @details A Boolean value that indicates whether the timer is currently valid. 'YES' if the receiver is still capable of firing or 'NO' if the timer has been invalidated and is no longer capable of firing.
         * @return The converted Objective-C result.
         */
        bool is_valid() const;
    };
}
