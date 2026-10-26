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
         * @param notification Argument converted to the Objective-C parameter of the same role.
         * @param coalesce_mask Argument converted to the Objective-C parameter of the same role.
         */
        void dequeue_notifications_matching(const Notification& notification, std::uint64_t coalesce_mask) const;
        /**
         * @brief Calls `-[NSNotificationQueue enqueueNotification:postingStyle:]`.
         * @param notification Argument converted to the Objective-C parameter of the same role.
         * @param posting_style Argument converted to the Objective-C parameter of the same role.
         */
        void enqueue_notification(const Notification& notification, PostingStyle posting_style) const;
        /**
         * @brief Calls `-[NSNotificationQueue enqueueNotification:postingStyle:coalesceMask:forModes:]`.
         * @param notification Argument converted to the Objective-C parameter of the same role.
         * @param posting_style Argument converted to the Objective-C parameter of the same role.
         * @param coalesce_mask Argument converted to the Objective-C parameter of the same role.
         * @param modes Argument converted to the Objective-C parameter of the same role.
         */
        void enqueue_notification(const Notification& notification, PostingStyle posting_style, NotificationCoalescing coalesce_mask, const std::vector<std::string>& modes) const;
        /**
         * @brief Returns the `defaultQueue` property of `NSNotificationQueue`.
         * @return The converted Objective-C result.
         */
        static NotificationQueue default_queue();
    };
}
