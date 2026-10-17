#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class UserNotification;

    /**
     * @brief C++ handle for the Objective-C class `NSUserNotificationCenter` (Foundation).
     * @details An object that delivers notifications from apps to the user. \@DeprecationSummary { Use the \<doc://com.apple.documentation/documentation/usernotifications> framework instead. } When a user notification's delivery date has been reached, or it's manually delivered, the notification center may display the notification to the user. The user notification center reserves the right to decide if a delivered user notification is presented to the user. For example, it may suppress the notification if the application is already frontmost (the delegate can override this action). The application can check the result of this decision by examining the ''NSUserNotification/isPresented'' property of a delivered user notification. ''NSUserNotification'' instances the 'NSUserNotificationCenter' are tracking will be in one of two states: scheduled or delivered. A scheduled user notification has a ''NSUserNotification/deliveryDate''. On that delivery date, the notification will move from being scheduled to being delivered. Note that the user notification may be displayed later than the delivery date depending on many factors. A delivered user notification has an ''NSUserNotification/actualDeliveryDate''. That's the date when it moved from being scheduled to delivered, or when it was manually delivered using the ''deliver(:)'' method. The application and the user notification center are both ultimately subject to the user's preferences. If the user decides to hide all alerts from your application, the 'presented' property will still behave as above, but the user won't see any animation or hear any sound. The ''NSUserNotificationCenterDelegate'' provides more information about the delivered user notification and allows forcing the display of a user notification even if the application is frontmost. > Note: > It the user wakes more than 15 minutes after a scheduled notification is scheduled to fire, it's discarded. If the notification repeats with an interval less than 15 minutes, then it expires in 1 minute. Expired notifications are just discarded, unless they repeat, in which case, they stay in the scheduled list and just fire again later. > Important: > Many of the NSUserNotificationCenter class's methods involve talking to a server process, so calling them repeatedly can have a negative effect on performance. \#\#\# Threading Information The 'NSUserNotificationCenter' class and the ''NSUserNotification'' class are both thread safe.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UserNotificationCenter user_notification_center;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::UserNotificationCenter user_notification_center{};
     * user_notification_center.deliver_notification(cocoon::UserNotification());
     * user_notification_center.remove_all_delivered_notifications();
     * user_notification_center.remove_delivered_notification(cocoon::UserNotification());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsusernotificationcenter
     */
    class UserNotificationCenter : public Object
    {
    public:
        /// @brief Creates a new `NSUserNotificationCenter` instance and returns a handle to it.
        explicit UserNotificationCenter();
        /// @brief Creates a null handle that refers to no native object.
        UserNotificationCenter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UserNotificationCenter(Adopt adopt);
        /**
     * @brief Calls `-[NSUserNotificationCenter deliverNotification:]`.
     * @details Deliver the specified user notification. - Parameters: - notification: The user notification. The notification will be presented to the user (subject to the user's preferences). The 'presented' property of the 'NSUserNotification' object will always be set to 'YES' if a notification is delivered using this method.
     * @param notification Argument converted to the Objective-C parameter of the same role.
     */
        void deliver_notification(const UserNotification& notification) const;
        /**
     * @brief Calls `-[NSUserNotificationCenter removeAllDeliveredNotifications]`.
     * @details Remove all delivered user notifications from the user notification center.
     */
        void remove_all_delivered_notifications() const;
        /**
     * @brief Calls `-[NSUserNotificationCenter removeDeliveredNotification:]`.
     * @details Remove a delivered user notification from the user notification center. - Parameters: - notification: The user notification. If the user notification is not in the delivered notifications list, nothing happens.
     * @param notification Argument converted to the Objective-C parameter of the same role.
     */
        void remove_delivered_notification(const UserNotification& notification) const;
        /**
     * @brief Calls `-[NSUserNotificationCenter removeScheduledNotification:]`.
     * @details Removes the specified user notification from the scheduled notifications. - Parameters: - notification: The user notification. If the user notification's 'deliveryDate' occurs before the cancellation finishes, the notification may still be delivered. If the notification is not in the scheduled list, nothing happens.
     * @param notification Argument converted to the Objective-C parameter of the same role.
     */
        void remove_scheduled_notification(const UserNotification& notification) const;
        /**
     * @brief Calls `-[NSUserNotificationCenter scheduleNotification:]`.
     * @details Schedules the specified user notification. - Parameters: - notification: The user notification. Scheduled notifications are added to the end of the notification queue.
     * @param notification Argument converted to the Objective-C parameter of the same role.
     */
        void schedule_notification(const UserNotification& notification) const;
        /**
     * @brief Returns the `defaultUserNotificationCenter` property of `NSUserNotificationCenter`.
     * @details Returns the default user notification center.
     * @return The converted Objective-C result.
     */
        static UserNotificationCenter default_user_notification_center();
        /**
     * @brief Returns the `deliveredNotifications` property of `NSUserNotificationCenter`.
     * @details An array of all user notifications delivered to the notification center. The number of notifications the user actually sees in the user interface may be less than the size of this array. Note that these may or may not have been actually presented to the user. See the 'presented' property in the 'NSUserNotification' class.
     * @return The converted Objective-C result.
     */
        std::vector<UserNotification> delivered_notifications() const;
        /**
     * @brief Returns the `scheduledNotifications` property of `NSUserNotificationCenter`.
     * @details Specifies an array of scheduled user notifications that have not yet been delivered. Newly scheduled notifications are added to the end of the array. You may also bulk-schedule notifications by setting this array. Bulk setting new scheduled notifications unschedules existing notifications.
     * @return The converted Objective-C result.
     */
        std::vector<UserNotification> scheduled_notifications() const;
        /**
     * @brief Sets the `scheduledNotifications` property of `NSUserNotificationCenter`.
     * @details Specifies an array of scheduled user notifications that have not yet been delivered. Newly scheduled notifications are added to the end of the array. You may also bulk-schedule notifications by setting this array. Bulk setting new scheduled notifications unschedules existing notifications.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_scheduled_notifications(const std::vector<UserNotification>& value) const;
    };
}
