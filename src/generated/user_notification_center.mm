#include "generated/user_notification_center.h"
#include "internal.h"

namespace cocoon
{
    UserNotificationCenter::UserNotificationCenter() : UserNotificationCenter(Adopt{cocoon::internal::retain([[::NSUserNotificationCenter alloc] init])})
    {
    }

    UserNotificationCenter::UserNotificationCenter(std::nullptr_t) : Object(nullptr)
    {
    }

    UserNotificationCenter::UserNotificationCenter(Adopt adopt) : Object(adopt)
    {
    }

    void UserNotificationCenter::deliver_notification(const UserNotification& notification) const
    {
        [cocoon::internal::ns<::NSUserNotificationCenter>(this) deliverNotification:cocoon::internal::native<::NSUserNotification>(notification)];
    }

    void UserNotificationCenter::remove_all_delivered_notifications() const
    {
        [cocoon::internal::ns<::NSUserNotificationCenter>(this) removeAllDeliveredNotifications];
    }

    void UserNotificationCenter::remove_delivered_notification(const UserNotification& notification) const
    {
        [cocoon::internal::ns<::NSUserNotificationCenter>(this) removeDeliveredNotification:cocoon::internal::native<::NSUserNotification>(notification)];
    }

    void UserNotificationCenter::remove_scheduled_notification(const UserNotification& notification) const
    {
        [cocoon::internal::ns<::NSUserNotificationCenter>(this) removeScheduledNotification:cocoon::internal::native<::NSUserNotification>(notification)];
    }

    void UserNotificationCenter::schedule_notification(const UserNotification& notification) const
    {
        [cocoon::internal::ns<::NSUserNotificationCenter>(this) scheduleNotification:cocoon::internal::native<::NSUserNotification>(notification)];
    }

    UserNotificationCenter UserNotificationCenter::default_user_notification_center()
    {
        return cocoon::internal::wrap<UserNotificationCenter>([::NSUserNotificationCenter defaultUserNotificationCenter]);
    }

    std::vector<UserNotification> UserNotificationCenter::delivered_notifications() const
    {
        return cocoon::internal::from_array<UserNotification>([cocoon::internal::ns<::NSUserNotificationCenter>(this) deliveredNotifications], [](id e) -> UserNotification
                                                              {
                                                                  return cocoon::internal::wrap<UserNotification>((::NSUserNotification*)e);
                                                              });
    }

    std::vector<UserNotification> UserNotificationCenter::scheduled_notifications() const
    {
        return cocoon::internal::from_array<UserNotification>([cocoon::internal::ns<::NSUserNotificationCenter>(this) scheduledNotifications], [](id e) -> UserNotification
                                                              {
                                                                  return cocoon::internal::wrap<UserNotification>((::NSUserNotification*)e);
                                                              });
    }

    void UserNotificationCenter::set_scheduled_notifications(const std::vector<UserNotification>& value) const
    {
        [cocoon::internal::ns<::NSUserNotificationCenter>(this) setScheduledNotifications:cocoon::internal::to_array(value, [](const UserNotification& e) -> id
                                                                                                                     {
                                                                                                                         return cocoon::internal::native<::NSUserNotification>(e);
                                                                                                                     })];
    }
}
