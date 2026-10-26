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
         * @param observer Argument converted to the Objective-C parameter of the same role.
         * @param a_selector Argument converted to the Objective-C parameter of the same role.
         * @param a_name Argument converted to the Objective-C parameter of the same role.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         */
        void add_observer(const Object& observer, const std::string& a_selector, const std::string& a_name, const std::string& an_object) const;
        /**
         * @brief Calls `-[NSDistributedNotificationCenter addObserver:selector:name:object:suspensionBehavior:]`.
         * @param observer Argument converted to the Objective-C parameter of the same role.
         * @param selector Argument converted to the Objective-C parameter of the same role.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @param suspension_behavior Argument converted to the Objective-C parameter of the same role.
         */
        void add_observer(const Object& observer, const std::string& selector, const std::string& name, const std::string& object, NotificationSuspensionBehavior suspension_behavior) const;
        /**
         * @brief Calls `+[NSDistributedNotificationCenter defaultCenter]`.
         * @return The converted Objective-C result.
         */
        static DistributedNotificationCenter default_center();
        /**
         * @brief Calls `+[NSDistributedNotificationCenter notificationCenterForType:]`.
         * @param notification_center_type Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static DistributedNotificationCenter notification_center_for_type(const std::string& notification_center_type);
        /**
         * @brief Calls `-[NSDistributedNotificationCenter postNotificationName:object:]`.
         * @param a_name Argument converted to the Objective-C parameter of the same role.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         */
        void post_notification_name(const std::string& a_name, const std::string& an_object) const;
        /**
         * @brief Calls `-[NSDistributedNotificationCenter postNotificationName:object:userInfo:]`.
         * @param a_name Argument converted to the Objective-C parameter of the same role.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         * @param a_user_info Argument converted to the Objective-C parameter of the same role.
         */
        void post_notification_name(const std::string& a_name, const std::string& an_object, const std::vector<std::pair<Object, Object>>& a_user_info) const;
        /**
         * @brief Calls `-[NSDistributedNotificationCenter postNotificationName:object:userInfo:deliverImmediately:]`.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @param user_info Argument converted to the Objective-C parameter of the same role.
         * @param deliver_immediately Argument converted to the Objective-C parameter of the same role.
         */
        void post_notification_name(const std::string& name, const std::string& object, const std::vector<std::pair<Object, Object>>& user_info, bool deliver_immediately) const;
        /**
         * @brief Calls `-[NSDistributedNotificationCenter postNotificationName:object:userInfo:options:]`.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @param user_info Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         */
        void post_notification_name(const std::string& name, const std::string& object, const std::vector<std::pair<Object, Object>>& user_info, DistributedNotificationOptions options) const;
        /**
         * @brief Calls `-[NSDistributedNotificationCenter removeObserver:name:object:]`.
         * @param observer Argument converted to the Objective-C parameter of the same role.
         * @param a_name Argument converted to the Objective-C parameter of the same role.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         */
        void remove_observer(const Object& observer, const std::string& a_name, const std::string& an_object) const;
        /**
         * @brief Returns the `suspended` property of `NSDistributedNotificationCenter`.
         * @return The converted Objective-C result.
         */
        bool suspended() const;
        /**
         * @brief Sets the `suspended` property of `NSDistributedNotificationCenter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_suspended(bool value) const;
    };
}
