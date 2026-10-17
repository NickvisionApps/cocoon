#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Notification;
    class OperationQueue;

    /**
     * @brief C++ handle for the Objective-C class `NSNotificationCenter` (Foundation).
     * @details A notification dispatch mechanism that enables the broadcast of information to registered observers. Callers register with a notification center to receive one or both of the following: ''NSNotification'' objects, when working in Objective-C or with frameworks that only support ''NSNotification''. Objects register with a notification center to receive notifications (''NSNotification'' objects) using the ''addObserver(:selector:name:object:)'' or ''addObserver(forName:object:queue:using:)'' methods, specifying a notification name and optionally a source object. When a caller adds itself as an observer, it specifies which notifications it should receive. ''MainActorMessage'' and ''AsyncMessage'' instances for use with Swift code, providing strong typing, appropriate actor isolation, and a more idiomatic Swift experience. Callers register with the notification center using the various flavors of the 'addObserver(of:for:using:)' method, specifying either a message type or a convenience ''MessageIdentifier'' to identify the notification messages to receive. See \<doc:notification-center-messages> for more information about this API. Callers may add observers for many different notifications, or even the same notification name or message type as produced by different source objects. Each running app has a ''default'' notification center, and you can create new notification centers to organize communications in particular contexts. A notification center can deliver notifications only within a single program. On macOS, if you want to post a notification to other processes or receive notifications from other processes, use ''DistributedNotificationCenter'' instead.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::NotificationCenter notification_center;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::NotificationCenter notification_center{};
     * notification_center.post_notification(cocoon::Notification());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsnotificationcenter
     */
    class NotificationCenter : public Object
    {
    public:
        /// @brief Creates a new `NSNotificationCenter` instance and returns a handle to it.
        explicit NotificationCenter();
        /// @brief Creates a null handle that refers to no native object.
        NotificationCenter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit NotificationCenter(Adopt adopt);
        /**
     * @brief Calls `-[NSNotificationCenter addObserver:selector:name:object:]`.
     * @details Adds an entry to the notification center to call the provided selector with the notification. - Parameters: - observer: Object registering as an observer. - aSelector: Selector that specifies the message the receiver sends the observer when posting the notification. The method must have one and only one argument (an instance of 'NSNotification'). - aName: The name of the notification for which to register the observer; that is, only notifications with this name are used to add the block to the operation queue. Pass 'nil' to receive notifications with any name. - anObject: The object whose notifications the observer wants to receive; that is, only notifications sent by this sender are delivered to the observer. Pass 'nil' to receive notifications from any sender.
     * @param observer Argument converted to the Objective-C parameter of the same role.
     * @param a_selector Argument converted to the Objective-C parameter of the same role.
     * @param a_name Argument converted to the Objective-C parameter of the same role.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     */
        void add_observer(const Object& observer, const std::string& a_selector, const std::string& a_name, const Object& an_object) const;
        /**
     * @brief Calls `-[NSNotificationCenter addObserverForName:object:queue:usingBlock:]`.
     * @details Adds an entry to the notification center to receive notifications that passed to the provided block. - Parameters: - name: The name of the notification for which to register the observer. Pass 'nil' to receive notifications with any name. - obj: The object whose notifications the observer wants to receive. Pass 'nil' to receive notifications from any sender. - queue: The operation queue to which the block is added. Pass 'nil' to run the block synchronously on the posting thread. - block: The block to be executed when the notification is received. - Returns: An opaque object to act as the observer, which you use to deregister the observer with ''removeObserver:''.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     * @param queue Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object add_observer_for_name(const std::string& name, const Object& obj, const OperationQueue& queue, std::function<void(Notification)> block) const;
        /**
     * @brief Calls `-[NSNotificationCenter postNotification:]`.
     * @details Posts a given notification to the notification center. - Parameter notification: The notification to post.
     * @param notification Argument converted to the Objective-C parameter of the same role.
     */
        void post_notification(const Notification& notification) const;
        /**
     * @brief Calls `-[NSNotificationCenter postNotificationName:object:]`.
     * @details Creates a notification with a given name and sender and posts it to the notification center. - Parameters: - aName: The name of the notification. - anObject: The object posting the notification.
     * @param a_name Argument converted to the Objective-C parameter of the same role.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     */
        void post_notification_name(const std::string& a_name, const Object& an_object) const;
        /**
     * @brief Calls `-[NSNotificationCenter postNotificationName:object:userInfo:]`.
     * @details Creates a notification with a given name, sender, and information and posts it to the notification center. - Parameters: - aName: The name of the notification. - anObject: The object posting the notification. - aUserInfo: Optional information about the notification.
     * @param a_name Argument converted to the Objective-C parameter of the same role.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     * @param a_user_info Argument converted to the Objective-C parameter of the same role.
     */
        void post_notification_name(const std::string& a_name, const Object& an_object, const std::vector<std::pair<Object, Object>>& a_user_info) const;
        /**
     * @brief Calls `-[NSNotificationCenter removeObserver:]`.
     * @details Removes all entries specifying an observer from the notification center's dispatch table. - Parameter observer: The notification observer to remove.
     * @param observer Argument converted to the Objective-C parameter of the same role.
     */
        void remove_observer(const Object& observer) const;
        /**
     * @brief Calls `-[NSNotificationCenter removeObserver:name:object:]`.
     * @details Removes matching entries from the notification center's dispatch table. - Parameters: - observer: The notification observer to remove. - aName: The name of the notification to remove from the dispatch table. Pass 'nil' to remove all entries for the observer. - anObject: The sender to remove from the dispatch table. Pass 'nil' to remove the observer regardless of the sender.
     * @param observer Argument converted to the Objective-C parameter of the same role.
     * @param a_name Argument converted to the Objective-C parameter of the same role.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     */
        void remove_observer(const Object& observer, const std::string& a_name, const Object& an_object) const;
        /**
     * @brief Returns the `defaultCenter` property of `NSNotificationCenter`.
     * @details The app's default notification center.
     * @return The converted Objective-C result.
     */
        static NotificationCenter default_center();
    };
}
