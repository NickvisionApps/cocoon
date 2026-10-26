#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSBackgroundActivityScheduler` (Foundation).
     * @details This class provides a Cocoa-level interface to the XPC Activity API (see xpc/activity.h). It is used to schedule maintenance or background kinds of tasks. These activities are run by the OS at a time that best accommodates system-wide factors like energy, thermal conditions, and CPU usage. If you have activities that run at an interval measured in 10s of minutes or more, then use this class to schedule those activities.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::BackgroundActivityScheduler background_activity_scheduler;
     * background_activity_scheduler.set_interval(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::BackgroundActivityScheduler background_activity_scheduler{};
     * background_activity_scheduler.set_interval(1);
     * auto interval = background_activity_scheduler.interval();
     * background_activity_scheduler.set_quality_of_service(cocoon::QualityOfService::UserInteractive);
     * auto quality_of_service = background_activity_scheduler.quality_of_service();
     * background_activity_scheduler.set_repeats(true);
     * auto repeats = background_activity_scheduler.repeats();
     * background_activity_scheduler.invalidate();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsbackgroundactivityscheduler
     */
    class BackgroundActivityScheduler : public Object
    {
    public:
        /// @brief Creates a new `NSBackgroundActivityScheduler` instance and returns a handle to it.
        explicit BackgroundActivityScheduler(const std::string& identifier);
        /// @brief Creates a new `NSBackgroundActivityScheduler` instance and returns a handle to it.
        explicit BackgroundActivityScheduler();
        /// @brief Creates a null handle that refers to no native object.
        BackgroundActivityScheduler(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit BackgroundActivityScheduler(Adopt adopt);
        /**
         * @brief Calls `-[NSBackgroundActivityScheduler invalidate]`.
         * @details Stop scheduling the activity. Any currently executing block will still complete.
         */
        void invalidate() const;
        /**
         * @brief Calls `-[NSBackgroundActivityScheduler scheduleWithBlock:]`.
         * @details Begin scheduling the activity. All properties should be setup by this point. The block will be called on a serial background queue appropriate for the level of quality of service specified. The system will automatically use NSProcessInfo's -beginActivityWithOptions:reason: API while invoking the block, choosing options appropriate for the desired quality of service. When you are done with the work, be sure to invoke the completionHandler block given to you as an argument to your block. You can pass in a kind of NSBackgroundActivityResult to indicate if the work has been finished or if you are deferring the rest of the work (see -shouldDefer). If you fail to invoke the completionHandler then your activity will never be rescheduled. When invoking the completionHandler, the system will set the schedule the next invocation. If you want to adjust the properties of your scheduler (e.g., the interval or tolerance), do this before invoking the completion block.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void schedule_with_block(std::function<void(std::function<void(BackgroundActivityResult)>)> block) const;
        /**
         * @brief Returns the `identifier` property of `NSBackgroundActivityScheduler`.
         * @details The identifier this object was initialized with.
         * @return The converted Objective-C result.
         */
        std::string identifier() const;
        /**
         * @brief Returns the `interval` property of `NSBackgroundActivityScheduler`.
         * @details If this activity is repeating, then this property describes the average interval of seconds between invocations of this activity. If the activity is not repeating, then this property is the suggested interval of time between scheduling the activity and the invocation of the activity.
         * @return The converted Objective-C result.
         */
        double interval() const;
        /**
         * @brief Sets the `interval` property of `NSBackgroundActivityScheduler`.
         * @details If this activity is repeating, then this property describes the average interval of seconds between invocations of this activity. If the activity is not repeating, then this property is the suggested interval of time between scheduling the activity and the invocation of the activity.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_interval(double value) const;
        /**
         * @brief Returns the `qualityOfService` property of `NSBackgroundActivityScheduler`.
         * @details Default value is NSQualityOfServiceBackground. If you upgrade the quality of service above this level, the system will more aggressively schedule this activity. The default value is the recommended value for most activities.
         * @return The converted Objective-C result.
         */
        QualityOfService quality_of_service() const;
        /**
         * @brief Sets the `qualityOfService` property of `NSBackgroundActivityScheduler`.
         * @details Default value is NSQualityOfServiceBackground. If you upgrade the quality of service above this level, the system will more aggressively schedule this activity. The default value is the recommended value for most activities.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_quality_of_service(QualityOfService value) const;
        /**
         * @brief Returns the `repeats` property of `NSBackgroundActivityScheduler`.
         * @details The default value is NO. If set to YES, then the activity will be rescheduled after finishing at the specified interval.
         * @return The converted Objective-C result.
         */
        bool repeats() const;
        /**
         * @brief Sets the `repeats` property of `NSBackgroundActivityScheduler`.
         * @details The default value is NO. If set to YES, then the activity will be rescheduled after finishing at the specified interval.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_repeats(bool value) const;
        /**
         * @brief Returns the `shouldDefer` property of `NSBackgroundActivityScheduler`.
         * @details You can call this method occasionally during execution of your activity to determine if system conditions have changed such that it is no longer a good time to run this activity. If the result of this method is YES, then you should wrap up current state. Once you are done saving your state, invoke the completionHandler block (the argument to your scheduled block) with the NSBackgroundActivityResultDeferred constant. The system will invoke your activity block again at a later, more appropriate time. At that point you can read your state and continue the work.
         * @return The converted Objective-C result.
         */
        bool should_defer() const;
        /**
         * @brief Returns the `tolerance` property of `NSBackgroundActivityScheduler`.
         * @details Specifies the number of seconds before or after the nominal fire date when the activity should be invoked. The nominal fire date is calculated by using the interval combined with the previous fire date or the time when the activity is started. These two properties create a window in time during which the activity may be scheduled. The system will more aggresively schedule the activity as it nears the end of the grace period after the nominal fire date. The default value is 1/2 the interval.
         * @return The converted Objective-C result.
         */
        double tolerance() const;
        /**
         * @brief Sets the `tolerance` property of `NSBackgroundActivityScheduler`.
         * @details Specifies the number of seconds before or after the nominal fire date when the activity should be invoked. The nominal fire date is calculated by using the interval combined with the previous fire date or the time when the activity is started. These two properties create a window in time during which the activity may be scheduled. The system will more aggresively schedule the activity as it nears the end of the grace period after the nominal fire date. The default value is 1/2 the interval.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tolerance(double value) const;
    };
}
