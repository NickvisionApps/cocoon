#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/notification_center.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSDistributedNotificationCenter` (Foundation).
     * @details A notification dispatch mechanism that enables the broadcast of notifications across task boundaries. A ''DistributedNotificationCenter'' instance broadcasts ''NSNotification'' objects to objects in other tasks that have registered for the notification with their task's default distributed notification center. \#\#\# Principal Attributes - Notification dispatch table. See "Class at a Glance" > "Principal Attributes" in ''NotificationCenter'' for information about the dispatch table. In addition to the notification name and sender, dispatch table entries for distributed notification centers specify when the notification center delivers notifications to its observers. See the ''postNotificationName(:object:userInfo:deliverImmediately:)'' method, Suspending and Resuming Notification Delivery, and ''SuspensionBehavior'' for details. \#\#\# Commonly Used Methods - term ''default()'': Accesses the default distributed notification center. - term ''addObserver(:selector:name:object:suspensionBehavior:)'': Registers an object to receive a notification with a specified behavior when notification delivery is suspended. - term ''postNotificationName(:object:userInfo:deliverImmediately:)'': Creates and posts a notification. - term ''removeObserver(:name:object:)'': Specifies that an object no longer wants to receive certain notifications. \#\#\# Overview Each task has a default distributed notification center that you access with the ''default()'' class method. There may be different types of distributed notification centers. Currently there is a single type—'NSLocalNotificationCenterType'. This type of distributed notification center handles notifications that can be sent between tasks on a single computer. For communication between tasks on different computers, use [Distributed Objects Programming Topics](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/DistrObjects/DistrObjects.html\#//apple_ref/doc/uid/10000102i). Posting a distributed notification is an expensive operation. The notification gets sent to a system-wide server that distributes it to all the tasks that have objects registered for distributed notifications. The latency between posting the notification and the notification's arrival in another task is unbounded. In fact, when too many notifications are posted and the server's queue fills up, notifications may be dropped. Distributed notifications are delivered via a task's run loop. A task must be running a run loop in one of the "common" modes, such as 'NSDefaultRunLoopMode', to receive a distributed notification. For multithreaded applications running in macOS 10.3 and later, distributed notifications are always delivered to the main thread. For multithreaded applications running in OS X v10.2.8 and earlier, notifications are delivered to the thread that first used the distributed notifications API, which in most cases is the main thread. > Important: > 'NSDistributedNotificationCenter' does not implement a secure communications protocol. When using distributed notifications, your app should treat any data passed in the notification as untrusted. See [Security Overview](https://developer.apple.com/library/archive/documentation/Security/Conceptual/Security_Overview/Introduction/Introduction.html\#//apple_ref/doc/uid/TP30000976) for general guidance on secure coding practices. > Note: > 'NSDistributedNotificationCenter' objects should not be used to send notifications between threads within the same task. Use [Distributed Objects Programming Topics](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/DistrObjects/DistrObjects.html\#//apple_ref/doc/uid/10000102i) or the \<doc://com.apple.documentation/documentation/objectivec/nsobject-swift.class> method \<doc://com.apple.documentation/documentation/objectivec/nsobject-swift.class/performselector(onmainthread:with:waituntildone:)>, instead. You can also setup an ''Port'' object to receive and distribute messages from other threads.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref NotificationCenter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DistributedNotificationCenter distributed_notification_center;
     * distributed_notification_center.set_suspended(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DistributedNotificationCenter distributed_notification_center{};
     * distributed_notification_center.set_suspended(true);
     * auto suspended = distributed_notification_center.suspended();
     * auto made_0 = cocoon::DistributedNotificationCenter::default_center();
     * auto made_1 = cocoon::DistributedNotificationCenter::notification_center_for_type("text");
     * distributed_notification_center.post_notification_name("text", "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdistributednotificationcenter
     */
    class DistributedNotificationCenter : public NotificationCenter
    {
    public:
        /// @brief Creates a new `NSDistributedNotificationCenter` instance and returns a handle to it.
        explicit DistributedNotificationCenter();
        /// @brief Creates a null handle that refers to no native object.
        DistributedNotificationCenter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DistributedNotificationCenter(Adopt adopt);
        using NotificationCenter::add_observer;
        using NotificationCenter::default_center;
        using NotificationCenter::post_notification_name;
        using NotificationCenter::remove_observer;
        /**
     * @brief Calls `-[NSDistributedNotificationCenter addObserver:selector:name:object:]`.
     * @details Adds an entry to the notification center's dispatch table with an observer, a selector, and an optional notification name and sender. This method calls ''addObserver(:selector:name:object:suspensionBehavior:)'' passing 'NSNotificationSuspensionBehaviorCoalesce' for 'suspensionBehavior'. - Parameters: - observer: An object registering as an observer. - aSelector: A selector that the notification center sends the observer to notify when posting the notification. - aName: The name of the notification for which to register the observer. When 'nil', the notification center doesn't use a notification's name to decide whether to deliver it to the observer. - anObject: The object whose notifications the observer wants to receive. When 'nil', the notification center doesn't use a notification's sender to decide whether to deliver it to the observer.
     * @param observer Argument converted to the Objective-C parameter of the same role.
     * @param a_selector Argument converted to the Objective-C parameter of the same role.
     * @param a_name Argument converted to the Objective-C parameter of the same role.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     */
        void add_observer(const Object& observer, const std::string& a_selector, const std::string& a_name, const std::string& an_object) const;
        /**
     * @brief Calls `-[NSDistributedNotificationCenter addObserver:selector:name:object:suspensionBehavior:]`.
     * @details Adds an entry to the receiver's dispatch table with a specific observer and suspended-notifications behavior, and optional notification name and sender. The receiver does not retain 'observer'. Therefore, you should always send 'removeObserver:' or 'removeObserver:name:object:' to the receiver before releasing the observer. - Parameters: - observer: Object registering as an observer. Must not be 'nil'. - selector: Selector that specifies the message the receiver sends the observer to notify it of the notification posting. Must not be '0'. - name: The name of the notification for which to register the observer; that is, only notifications with this name are delivered to the observer. When 'nil', the notification center doesn't use a notification's name to decide whether to deliver it to the observer. - object: The object whose notifications the observer wants to receive; that is, only notifications sent by this sender are delivered to the observer. When 'nil', the notification center doesn't use a notification's sender to decide whether to deliver it to the observer. - suspensionBehavior: Notification posting behavior when notification delivery is suspended.
     * @param observer Argument converted to the Objective-C parameter of the same role.
     * @param selector Argument converted to the Objective-C parameter of the same role.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param suspension_behavior Argument converted to the Objective-C parameter of the same role.
     */
        void add_observer(const Object& observer, const std::string& selector, const std::string& name, const std::string& object, NotificationSuspensionBehavior suspension_behavior) const;
        /**
     * @brief Calls `+[NSDistributedNotificationCenter defaultCenter]`.
     * @details Returns the default distributed notification center, representing the local notification center for the computer. This method calls ''DistributedNotificationCenter/forType(:)'' with an argument of 'NSLocalNotificationCenterType'. - Returns: Default distributed notification center for the computer.
     * @return The converted Objective-C result.
     */
        static DistributedNotificationCenter default_center();
        /**
     * @brief Calls `+[NSDistributedNotificationCenter notificationCenterForType:]`.
     * @details Returns the distributed notification center for a particular notification center type. Currently only one type, 'NSLocalNotificationCenterType', is supported. - Parameter notificationCenterType: Notification center type being inquired about. - Returns: Distributed notification center for 'notificationCenterType'.
     * @param notification_center_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static DistributedNotificationCenter notification_center_for_type(const std::string& notification_center_type);
        /**
     * @brief Calls `-[NSDistributedNotificationCenter postNotificationName:object:]`.
     * @details Creates a notification, and posts it to the receiver. This method invokes ''postNotificationName(:object:userInfo:deliverImmediately:)'' with 'userInfo:nil deliverImmediately:NO'. - Parameters: - aName: Name of the notification to post. Must not be 'nil'. - anObject: Sender of the notification. May be 'nil'.
     * @param a_name Argument converted to the Objective-C parameter of the same role.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     */
        void post_notification_name(const std::string& a_name, const std::string& an_object) const;
        /**
     * @brief Calls `-[NSDistributedNotificationCenter postNotificationName:object:userInfo:]`.
     * @details Creates a notification with information, and posts it to the receiver. This method invokes ''postNotificationName(:object:userInfo:deliverImmediately:)'' with 'deliverImmediately:NO'. - Parameters: - aName: Name of the notification to post. Must not be 'nil'. - anObject: Sender of the notification. May be 'nil'. - aUserInfo: Dictionary containing additional information. May be 'nil'.
     * @param a_name Argument converted to the Objective-C parameter of the same role.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     * @param a_user_info Argument converted to the Objective-C parameter of the same role.
     */
        void post_notification_name(const std::string& a_name, const std::string& an_object, const std::vector<std::pair<Object, Object>>& a_user_info) const;
        /**
     * @brief Calls `-[NSDistributedNotificationCenter postNotificationName:object:userInfo:deliverImmediately:]`.
     * @details Creates a notification with information and an immediate-delivery specifier, and posts it to the receiver. This is the preferred method for posting notifications. The 'userInfo' dictionary is serialized as a property list, so it can be passed to another task. In the receiving task, it is deserialized back into a dictionary. - Parameters: - name: Name of the notification to post. Must not be 'nil'. - object: Sender of the notification. May be 'nil'. - userInfo: Dictionary containing additional information. May be 'nil'. - deliverImmediately: When 'NO', the receiver delivers notifications to their observers according to the suspended-notification behavior specified in the corresponding dispatch table entry. When 'YES', the receiver delivers the notification immediately to its observers.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param user_info Argument converted to the Objective-C parameter of the same role.
     * @param deliver_immediately Argument converted to the Objective-C parameter of the same role.
     */
        void post_notification_name(const std::string& name, const std::string& object, const std::vector<std::pair<Object, Object>>& user_info, bool deliver_immediately) const;
        /**
     * @brief Calls `-[NSDistributedNotificationCenter postNotificationName:object:userInfo:options:]`.
     * @details Creates a notification with information, and posts it to the receiver. The 'userInfo' dictionary is serialized as a property list, so it can be passed to another task. In the receiving task, it is deserialized back into a dictionary. - Parameters: - name: Name of the notification to post. Must not be 'nil'. - object: Sender of the notification. May be 'nil'. - userInfo: Dictionary containing additional information. May be 'nil'. - options: Specifies how the notification is posted to the task and when to deliver it to its observers.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param user_info Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     */
        void post_notification_name(const std::string& name, const std::string& object, const std::vector<std::pair<Object, Object>>& user_info, DistributedNotificationOptions options) const;
        /**
     * @brief Calls `-[NSDistributedNotificationCenter removeObserver:name:object:]`.
     * @details Removes matching entries from the receiver's dispatch table. Be sure to invoke this method before deallocating the observer object. - Parameters: - observer: Observer to remove from the dispatch table. Specify an observer to remove only entries for this observer. When 'nil', the receiver does not use notification observers as criteria for removal. - aName: Name of the notification to remove from dispatch table. Specify a notification name to remove only entries that specify this notification name. When 'nil', the receiver does not use notification names as criteria for removal. - anObject: Sender to remove from the dispatch table. Specify a notification sender to remove only entries that specify this sender. When 'nil', the receiver does not use notification senders as criteria for removal.
     * @param observer Argument converted to the Objective-C parameter of the same role.
     * @param a_name Argument converted to the Objective-C parameter of the same role.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     */
        void remove_observer(const Object& observer, const std::string& a_name, const std::string& an_object) const;
        /**
     * @brief Returns the `suspended` property of `NSDistributedNotificationCenter`.
     * @details Suspends or resumes notification delivery. Setting this to 'true' suspends notification delivery, enabling the variety of suspension behaviors enumerated in ''DistributedNotificationCenter/SuspensionBehavior''. Setting this to 'false' resumes immediate delivery of notifications. 'NSApplication' automatically suspends distributed notification delivery when the application is not active. Applications based on the Application Kit framework should let AppKit manage the suspension of notification delivery. Foundation-only programs may have occasional need to use this property.
     * @return The converted Objective-C result.
     */
        bool suspended() const;
        /**
     * @brief Sets the `suspended` property of `NSDistributedNotificationCenter`.
     * @details Suspends or resumes notification delivery. Setting this to 'true' suspends notification delivery, enabling the variety of suspension behaviors enumerated in ''DistributedNotificationCenter/SuspensionBehavior''. Setting this to 'false' resumes immediate delivery of notifications. 'NSApplication' automatically suspends distributed notification delivery when the application is not active. Applications based on the Application Kit framework should let AppKit manage the suspension of notification delivery. Foundation-only programs may have occasional need to use this property.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_suspended(bool value) const;
    };
}
