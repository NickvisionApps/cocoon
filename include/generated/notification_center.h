#pragma once

#include "generated/availability.h"
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
     * @details Notification Center
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
         * @param observer Argument converted to the Objective-C parameter of the same role.
         * @param a_selector Argument converted to the Objective-C parameter of the same role.
         * @param a_name Argument converted to the Objective-C parameter of the same role.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         */
        void add_observer(const Object& observer, const std::string& a_selector, const std::string& a_name, const Object& an_object) const;
        /**
         * @brief Calls `-[NSNotificationCenter addObserverForName:object:queue:usingBlock:]`.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param obj Argument converted to the Objective-C parameter of the same role.
         * @param queue Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object add_observer_for_name(const std::string& name, const Object& obj, const OperationQueue& queue, std::function<void(Notification)> block) const;
        /**
         * @brief Calls `-[NSNotificationCenter postNotification:]`.
         * @param notification Argument converted to the Objective-C parameter of the same role.
         */
        void post_notification(const Notification& notification) const;
        /**
         * @brief Calls `-[NSNotificationCenter postNotificationName:object:]`.
         * @param a_name Argument converted to the Objective-C parameter of the same role.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         */
        void post_notification_name(const std::string& a_name, const Object& an_object) const;
        /**
         * @brief Calls `-[NSNotificationCenter postNotificationName:object:userInfo:]`.
         * @param a_name Argument converted to the Objective-C parameter of the same role.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         * @param a_user_info Argument converted to the Objective-C parameter of the same role.
         */
        void post_notification_name(const std::string& a_name, const Object& an_object, const std::vector<std::pair<Object, Object>>& a_user_info) const;
        /**
         * @brief Calls `-[NSNotificationCenter removeObserver:]`.
         * @param observer Argument converted to the Objective-C parameter of the same role.
         */
        void remove_observer(const Object& observer) const;
        /**
         * @brief Calls `-[NSNotificationCenter removeObserver:name:object:]`.
         * @param observer Argument converted to the Objective-C parameter of the same role.
         * @param a_name Argument converted to the Objective-C parameter of the same role.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         */
        void remove_observer(const Object& observer, const std::string& a_name, const Object& an_object) const;
        /**
         * @brief Returns the `defaultCenter` property of `NSNotificationCenter`.
         * @return The converted Objective-C result.
         */
        static NotificationCenter default_center();
    };
}
