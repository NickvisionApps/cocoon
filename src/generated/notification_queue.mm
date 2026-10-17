#include "generated/notification_queue.h"
#include "internal.h"

namespace cocoon
{
    NotificationQueue::NotificationQueue(const NotificationCenter& notification_center) : NotificationQueue(Adopt{cocoon::internal::retain([[::NSNotificationQueue alloc] initWithNotificationCenter:cocoon::internal::native<::NSNotificationCenter>(notification_center)])})
    {
    }

    NotificationQueue::NotificationQueue() : NotificationQueue(Adopt{cocoon::internal::retain([[::NSNotificationQueue alloc] init])})
    {
    }

    NotificationQueue::NotificationQueue(std::nullptr_t) : Object(nullptr)
    {
    }

    NotificationQueue::NotificationQueue(Adopt adopt) : Object(adopt)
    {
    }

    void NotificationQueue::dequeue_notifications_matching(const Notification& notification, std::uint64_t coalesce_mask) const
    {
        [cocoon::internal::ns<::NSNotificationQueue>(this) dequeueNotificationsMatching:cocoon::internal::native<::NSNotification>(notification) coalesceMask:static_cast<::NSUInteger>(coalesce_mask)];
    }

    void NotificationQueue::enqueue_notification(const Notification& notification, PostingStyle posting_style) const
    {
        [cocoon::internal::ns<::NSNotificationQueue>(this) enqueueNotification:cocoon::internal::native<::NSNotification>(notification) postingStyle:static_cast<::NSPostingStyle>(posting_style)];
    }

    void NotificationQueue::enqueue_notification(const Notification& notification, PostingStyle posting_style, NotificationCoalescing coalesce_mask, const std::vector<std::string>& modes) const
    {
        [cocoon::internal::ns<::NSNotificationQueue>(this) enqueueNotification:cocoon::internal::native<::NSNotification>(notification)
                                                                  postingStyle:static_cast<::NSPostingStyle>(posting_style)
                                                                  coalesceMask:static_cast<::NSNotificationCoalescing>(coalesce_mask)
                                                                      forModes:cocoon::internal::to_array(modes, [](const std::string& e) -> id
                                                                                                          {
                                                                                                              return cocoon::internal::to(e);
                                                                                                          })];
    }

    NotificationQueue NotificationQueue::default_queue()
    {
        return cocoon::internal::wrap<NotificationQueue>([::NSNotificationQueue defaultQueue]);
    }
}
