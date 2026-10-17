#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Notification;
    class NotificationCenter;

    /**
     * @brief C++ handle for the Objective-C class `NSNotificationQueue` (Foundation).
     * @details A notification center buffer. Whereas a notification center distributes notifications when posted, notifications placed into the queue can be delayed until the end of the current pass through the run loop or until the run loop is idle. Duplicate notifications can be coalesced so that only one notification is sent although multiple notifications are posted. A notification queue maintains notifications in first in, first out (FIFO) order. When a notification moves to the front of the queue, the queue posts it to the notification center, which in turn dispatches the notification to all objects registered as observers. Every thread has a default notification queue, which is associated with the default notification center for the process. You can create your own notification queues and have multiple queues per center and thread.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::NotificationQueue notification_queue;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::NotificationQueue notification_queue{};
     * notification_queue.dequeue_notifications_matching(cocoon::Notification(), 1);
     * notification_queue.enqueue_notification(cocoon::Notification(), cocoon::PostingStyle::WhenIdle);
     * notification_queue.enqueue_notification(cocoon::Notification(), cocoon::PostingStyle::WhenIdle, cocoon::NotificationCoalescing::NotificationNoCoalescing, {"a", "b"});
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsnotificationqueue
     */
    class NotificationQueue : public Object
    {
    public:
        /// @brief Creates a new `NSNotificationQueue` instance and returns a handle to it.
        explicit NotificationQueue(const NotificationCenter& notification_center);
        /// @brief Creates a new `NSNotificationQueue` instance and returns a handle to it.
        explicit NotificationQueue();
        /// @brief Creates a null handle that refers to no native object.
        NotificationQueue(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit NotificationQueue(Adopt adopt);
        /**
     * @brief Calls `-[NSNotificationQueue dequeueNotificationsMatching:coalesceMask:]`.
     * @details Removes all notifications from the queue that match a provided notification using provided matching criteria.
     * @param notification Argument converted to the Objective-C parameter of the same role.
     * @param coalesce_mask Argument converted to the Objective-C parameter of the same role.
     */
        void dequeue_notifications_matching(const Notification& notification, std::uint64_t coalesce_mask) const;
        /**
     * @brief Calls `-[NSNotificationQueue enqueueNotification:postingStyle:]`.
     * @details Adds a notification to the notification queue with a specified posting style.
     * @param notification Argument converted to the Objective-C parameter of the same role.
     * @param posting_style Argument converted to the Objective-C parameter of the same role.
     */
        void enqueue_notification(const Notification& notification, PostingStyle posting_style) const;
        /**
     * @brief Calls `-[NSNotificationQueue enqueueNotification:postingStyle:coalesceMask:forModes:]`.
     * @details Adds a notification to the notification queue with a specified posting style, criteria for coalescing, and run loop mode. The notification queue will only post the notification to its notification center if the run loop is in one of the modes provided in the array. The modes parameter may be nil, in which case it defaults to NSDefaultRunLoopMode.
     * @param notification Argument converted to the Objective-C parameter of the same role.
     * @param posting_style Argument converted to the Objective-C parameter of the same role.
     * @param coalesce_mask Argument converted to the Objective-C parameter of the same role.
     * @param modes Argument converted to the Objective-C parameter of the same role.
     */
        void enqueue_notification(const Notification& notification, PostingStyle posting_style, NotificationCoalescing coalesce_mask, const std::vector<std::string>& modes) const;
        /**
     * @brief Returns the `defaultQueue` property of `NSNotificationQueue`.
     * @details Returns the default notification queue for the current thread. This notification queue uses the default notification center.
     * @return The converted Objective-C result.
     */
        static NotificationQueue default_queue();
    };
}
