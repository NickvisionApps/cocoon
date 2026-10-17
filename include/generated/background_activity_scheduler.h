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
     * @details A task scheduler suitable for low priority operations that can run in the background. Use an ''NSBackgroundActivityScheduler'' object to schedule an arbitrary maintenance or background task. It's similar to an ''Timer'' object, in that it lets you schedule a repeating or non-repeating task. However, ''NSBackgroundActivityScheduler'' gives the system flexibility to determine the most efficient time to execute based on energy usage, thermal conditions, and CPU use. For example, use an ''NSBackgroundActivityScheduler'' object to schedule: - Automatic saves - Backups - Data maintenance - Periodic content fetches - Installation of updates - Activities occurring in intervals of 10 minutes or more - Any other deferrable task For information about performing non-deferrable tasks efficiently, see [Specify Nondeferrable Background Activities](https://developer.apple.com/library/archive/documentation/Performance/Conceptual/power_efficiency_guidelines_osx/SchedulingBackgroundActivity.html\#//apple_ref/doc/uid/TP40013929-CH32-SW10) in [Energy Efficiency Guide for Mac Apps](https://developer.apple.com/library/archive/documentation/Performance/Conceptual/power_efficiency_guidelines_osx/index.html\#//apple_ref/doc/uid/TP40013929). > Note: > The ''NSBackgroundActivityScheduler'' class interfaces with the XPC Activity API. However, your app doesn't need to be an XPC service in order to use ''NSBackgroundActivityScheduler''. \#\#\# Create a Scheduler To initialize a scheduler, call ''init(identifier:)'' for 'NSBackgroundActivityScheduler', and pass it a unique identifier string in reverse DNS notation ('nil' and zero-length strings are not allowed) that remains constant across launches of your application. \@TabNavigator { \@Tab("Swift") { '''swift let activity = NSBackgroundActivityScheduler(identifier: "com.example.MyApp.updatecheck") ''' } \@Tab("Objective-C") { '''objc NSBackgroundActivityScheduler activity = [[NSBackgroundActivityScheduler alloc] initWithIdentifier:\@"com.example.MyApp.updatecheck"]; ''' } } > Note: > The system uses this unique identifier to track the number of times the activity has run and to improve the heuristics for deciding when to run it again in the future. \#\#\# Configure Scheduler Properties Configure the scheduler with any of the following scheduling properties: - ''repeats''—If set to \<doc://com.apple.documentation/documentation/swift/true>, the activity is rescheduled at the specified interval after finishing. - ''interval''—For repeating schedulers, the average interval between invocations of the activity. For nonrepeating schedulers, 'interval' is the suggested interval of time between scheduling the activity and the invocation of the activity. - ''tolerance''—The amount of time before or after the nominal fire date when the activity should be invoked. The nominal fire date is calculated by using the interval combined with the previous fire date or the time when the activity is started. These two properties create a window in time, during which the activity may be scheduled. The system will more aggressively schedule the activity as it nears the end of the grace period after the nominal fire date. The default value is half the interval. - ''qualityOfService''—The default value is 'NSQualityOfServiceBackground'. If you upgrade the quality of service above this level, the system schedules the activity more aggressively. The default value is the recommended value for most activities. For information on quality of service, see [Prioritize Work at the Task Level](https://developer.apple.com/library/archive/documentation/Performance/Conceptual/power_efficiency_guidelines_osx/PrioritizeWorkAtTheTaskLevel.html\#//apple_ref/doc/uid/TP40013929-CH35) in [Energy Efficiency Guide for Mac Apps](https://developer.apple.com/library/archive/documentation/Performance/Conceptual/power_efficiency_guidelines_osx/index.html\#//apple_ref/doc/uid/TP40013929). The next three code examples demonstrate different scheduling scenarios. Scheduling an activity to fire in the next 10 minutes \@TabNavigator { \@Tab("Swift") { '''swift activity.tolerance = 10 60 ''' } \@Tab("Objective-C") { '''objc activity.tolerance = 10 60; ''' } } Scheduling an activity to fire between 15 and 45 minutes from now \@TabNavigator { \@Tab("Swift") { '''swift activity.interval = 30 60 activity.tolerance = 15 60 ''' } \@Tab("Objective-C") { '''objc activity.interval = 30 60; activity.tolerance = 15 60; ''' } } Scheduling an activity to fire once each hour \@TabNavigator { \@Tab("Swift") { '''swift activity.repeats = true activity.interval = 60 60 ''' } \@Tab("Objective-C") { '''objc activity.repeats = YES; activity.interval = 60 60; ''' } } \#\#\# Schedule Activity with scheduleWithBlock: When you're ready to schedule the activity, call 'scheduleWithBlock:' and provide a block of code to execute when the scheduler runs, as shown in the following example. The block will be called on a serial background queue appropriate for the level of quality of service specified. The system automatically uses the ''ProcessInfo/beginActivity(options:reason:)'' method (of ''ProcessInfo'') while invoking the block, choosing appropriate options based on the specified quality of service. When your block is called, it's passed a completion handler as an argument. Configure the block to invoke this handler, passing it a result of type ''Result'' to indicate whether the activity finished (''Result/finished'') or should be deferred (''Result/deferred'') and rescheduled for a later time. Failure to invoke the completion handler results in the activity not being rescheduled. For work that will be deferred and rescheduled, the block may optionally adjust scheduler properties, such as ''interval'' or ''tolerance'', before calling the completion handler. Scheduling background activity \@TabNavigator { \@Tab("Swift") { '''swift activity.scheduleWithBlock() { (completion: NSBackgroundActivityCompletionHandler) in // Perform the activity self.completion(NSBackgroundActivityResult.Finished) } ''' } \@Tab("Objective-C") { '''objc [activity scheduleWithBlock:^(NSBackgroundActivityCompletionHandler completion) { // Perform the activity self.completion(NSBackgroundActivityResultFinished); }]; ''' } } \#\#\# Detect Whether to Defer Activity It's conceivable that while a lengthy activity is running, conditions may change, resulting in the activity now requiring deferral. For example, perhaps the user has unplugged the Mac and it's now running on battery power. Your activity can call ''shouldDefer'' to determine whether this has occurred. A value of \<doc://com.apple.documentation/documentation/swift/true> indicates that the block should finish what it's currently doing and invoke its completion handler with a value of ''Result/deferred''. See the following example. Detecting deferred background activity \@TabNavigator { \@Tab("Swift") { '''swift if activity.shouldDefer { // Wrap up processing and prepare to defer activity self.completion(NSBackgroundActivityResult.Deferred) } else { // Continue processing self.completion(NSBackgroundActivityResult.Finished) } ''' } \@Tab("Objective-C") { '''objc if ([activity shouldDefer]) { // Wrap up processing and prepare to defer activity self.completion(NSBackgroundActivityResultDeferred); } else { // Continue processing self.completion(NSBackgroundActivityResultFinished); }; ''' } } \#\#\# Stop Activity Call ''invalidate()'' to stop scheduling an activity, as shown in the following example. Stopping background activity \@TabNavigator { \@Tab("Swift") { '''swift activity.invalidate() ''' } \@Tab("Objective-C") { '''objc [activity invalidate]; ''' } } > Note: > When an activity is stopped, a block that's currently executing will still finish executing.
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
     * @details Prevents the background activity from being scheduled again. When 'invalidate' is used to stop an activity that is currently executing, the activity will still finish executing.
     */
        void invalidate() const;
        /**
     * @brief Calls `-[NSBackgroundActivityScheduler scheduleWithBlock:]`.
     * @details Begins scheduling the background activity. - Parameters: - block: A block of code to execute when the scheduler runs. This block will be called on a serial background queue appropriate for the level of quality of service specified. See 'qualityOfService'. When your block is called, it's passed a completion handler as an argument. Configure the block to invoke this handler, passing it a result of type 'NSBackgroundActivityResult' to indicate whether the activity finished ('NSBackgroundActivityResultFinished') or should be deferred ('NSBackgroundActivityResultDeferred') and rescheduled for a later time. Failure to invoke the completion handler results in the activity not being rescheduled. For work that will be deferred and rescheduled, the block may optionally adjust scheduler properties, such as 'interval' or 'tolerance', before calling the completion handler.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void schedule_with_block(std::function<void(std::function<void(BackgroundActivityResult)>)> block) const;
        /**
     * @brief Returns the `identifier` property of `NSBackgroundActivityScheduler`.
     * @details A unique reverse DNS notation string, such as 'com.example.MyApp.updatecheck', that identifies the activity. This string should remain constant for an activity across launches of your app because the system uses this unique identifier to track the number of times the activity has run and to improve the heuristics for deciding when to run it again in the future. 'nil' and zero-length strings are not allowed.
     * @return The converted Objective-C result.
     */
        std::string identifier() const;
        /**
     * @brief Returns the `interval` property of `NSBackgroundActivityScheduler`.
     * @details An integer providing a suggested interval between scheduling and invoking the activity. For repeating activities, the value of this property is also the suggested interval between invocations.
     * @return The converted Objective-C result.
     */
        double interval() const;
        /**
     * @brief Sets the `interval` property of `NSBackgroundActivityScheduler`.
     * @details An integer providing a suggested interval between scheduling and invoking the activity. For repeating activities, the value of this property is also the suggested interval between invocations.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_interval(double value) const;
        /**
     * @brief Returns the `qualityOfService` property of `NSBackgroundActivityScheduler`.
     * @details A value of type 'NSQualityOfService', which controls how aggressively the system schedules the activity. The default value is 'NSQualityOfServiceBackground'. If you upgrade the quality of service above this level, the system schedules the activity more aggressively. The default value is the recommended value for most activities.
     * @return The converted Objective-C result.
     */
        QualityOfService quality_of_service() const;
        /**
     * @brief Sets the `qualityOfService` property of `NSBackgroundActivityScheduler`.
     * @details A value of type 'NSQualityOfService', which controls how aggressively the system schedules the activity. The default value is 'NSQualityOfServiceBackground'. If you upgrade the quality of service above this level, the system schedules the activity more aggressively. The default value is the recommended value for most activities.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_quality_of_service(QualityOfService value) const;
        /**
     * @brief Returns the `repeats` property of `NSBackgroundActivityScheduler`.
     * @details A Boolean value indicating whether the activity should be rescheduled after it completes. The default value for this property is 'NO'.
     * @return The converted Objective-C result.
     */
        bool repeats() const;
        /**
     * @brief Sets the `repeats` property of `NSBackgroundActivityScheduler`.
     * @details A Boolean value indicating whether the activity should be rescheduled after it completes. The default value for this property is 'NO'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_repeats(bool value) const;
        /**
     * @brief Returns the `shouldDefer` property of `NSBackgroundActivityScheduler`.
     * @details A Boolean value indicating whether your app should stop performing background activity and resume at a more optimal time. Your app can check the 'shouldDefer' property while executing scheduled background activity. If this property contains a value of 'YES', system conditions have changed since the time the activity started and deferral is recommended. For example, perhaps the user unplugged the Mac and it's now running on battery power. In this case, your app should finish what it's currently doing, save its state, and invoke its completion handler with a value of 'NSBackgroundActivityResultDeferred'. The system will invoke your activity again at a more optimal time, and your app can restore its previous state and resume where it left off.
     * @return The converted Objective-C result.
     */
        bool should_defer() const;
        /**
     * @brief Returns the `tolerance` property of `NSBackgroundActivityScheduler`.
     * @details A value of type 'NSTimeInterval', which specifies a range of time during which the background activity may occur. A nominal fire date for scheduled background activity is calculated based on a combination of the 'interval' property value and the time the activity began or the last execution date. The 'tolerance' property specifies a grace period -- a range of time before and after the nominal fire date, during which the activity may be invoked. As the activity nears the end of its grace period, the system schedules the activity more aggressively. The default tolerance period is half the value of the 'interval' property.
     * @return The converted Objective-C result.
     */
        double tolerance() const;
        /**
     * @brief Sets the `tolerance` property of `NSBackgroundActivityScheduler`.
     * @details A value of type 'NSTimeInterval', which specifies a range of time during which the background activity may occur. A nominal fire date for scheduled background activity is calculated based on a combination of the 'interval' property value and the time the activity began or the last execution date. The 'tolerance' property specifies a grace period -- a range of time before and after the nominal fire date, during which the activity may be invoked. As the activity nears the end of its grace period, the system schedules the activity more aggressively. The default tolerance period is half the value of the 'interval' property.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tolerance(double value) const;
    };
}
