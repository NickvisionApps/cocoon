#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class UserNotification;

    /**
     * @brief C++ handle for the Objective-C class `NSUserNotificationCenter` (Foundation).
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
     * @param notification Argument converted to the Objective-C parameter of the same role.
     */
        void deliver_notification(const UserNotification& notification) const;
        /**
     * @brief Calls `-[NSUserNotificationCenter removeAllDeliveredNotifications]`.
     */
        void remove_all_delivered_notifications() const;
        /**
     * @brief Calls `-[NSUserNotificationCenter removeDeliveredNotification:]`.
     * @param notification Argument converted to the Objective-C parameter of the same role.
     */
        void remove_delivered_notification(const UserNotification& notification) const;
        /**
     * @brief Calls `-[NSUserNotificationCenter removeScheduledNotification:]`.
     * @param notification Argument converted to the Objective-C parameter of the same role.
     */
        void remove_scheduled_notification(const UserNotification& notification) const;
        /**
     * @brief Calls `-[NSUserNotificationCenter scheduleNotification:]`.
     * @param notification Argument converted to the Objective-C parameter of the same role.
     */
        void schedule_notification(const UserNotification& notification) const;
        /**
     * @brief Returns the `defaultUserNotificationCenter` property of `NSUserNotificationCenter`.
     * @return The converted Objective-C result.
     */
        static UserNotificationCenter default_user_notification_center();
        /**
     * @brief Returns the `deliveredNotifications` property of `NSUserNotificationCenter`.
     * @return The converted Objective-C result.
     */
        std::vector<UserNotification> delivered_notifications() const;
        /**
     * @brief Returns the `scheduledNotifications` property of `NSUserNotificationCenter`.
     * @return The converted Objective-C result.
     */
        std::vector<UserNotification> scheduled_notifications() const;
        /**
     * @brief Sets the `scheduledNotifications` property of `NSUserNotificationCenter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_scheduled_notifications(const std::vector<UserNotification>& value) const;
    };
}
