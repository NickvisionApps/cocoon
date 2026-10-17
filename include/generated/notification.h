#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSNotification` (Foundation).
     * @details A container for information broadcast through a notification center to all registered observers. In Swift, this object bridges to ''Notification''; use ''NSNotification'' when you need reference semantics or other Foundation-specific behavior. A notification contains a name, an object, and an optional dictionary, and is broadcast to by instances of ''NotificationCenter'' or ''DistributedNotificationCenter''. The name is a tag identifying the notification. The object is any object that the poster of the notification wants to send to observers of that notification (typically, the object posting the notification). The dictionary stores other related objects, if any. ''NSNotification'' objects are immutable. You don't usually create your own notifications directly, but instead call the ''NotificationCenter'' methods ''NotificationCenter/post(name:object:)'' and ''NotificationCenter/post(name:object:userInfo:)''. > Important: > The Swift overlay to the Foundation framework provides the ''Notification'' structure, which bridges to the ''NSNotification'' class. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>. \#\#\# Object Comparison The objects of a notification are compared using pointer equality for local notifications. Distributed notifications use strings as their objects, and those strings are compared using \<doc://com.apple.documentation/documentation/objectivec/nsobjectprotocol/isequal(:)>, because pointer equality doesn't make sense across process boundaries. \#\#\# Creating Subclasses You can subclass ''NSNotification'' to contain information in addition to the notification name, object, and dictionary. This extra data must be agreed upon between notifiers and observers. ''NotificationCenter'' is a class cluster with no instance variables. As such, you must subclass ''NSNotification'' and override the primitive methods ''name'', ''object'', and ''userInfo''. You can choose any designated initializer you like, but be sure that your initializer does not call ''init'' on 'super' (''NSNotification'' is not meant to be instantiated directly, and its 'init' method raises an exception).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Notification notification;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsnotification
     */
    class Notification : public Object
    {
    public:
        /// @brief Creates a new `NSNotification` instance and returns a handle to it.
        explicit Notification(const std::string& name, const Object& object, const std::vector<std::pair<Object, Object>>& user_info);
        /// @brief Creates a new `NSNotification` instance and returns a handle to it.
        explicit Notification();
        /// @brief Creates a null handle that refers to no native object.
        Notification(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Notification(Adopt adopt);
        /**
     * @brief Calls `+[NSNotification notificationWithName:object:]`.
     * @details Returns a new notification object with a specified name and object. - Parameters: - aName: The name for the new notification. May not be 'nil'. - anObject: The object for the new notification.
     * @param a_name Argument converted to the Objective-C parameter of the same role.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Notification notification_with_name(const std::string& a_name, const Object& an_object);
        /**
     * @brief Calls `+[NSNotification notificationWithName:object:userInfo:]`.
     * @details Returns a notification object with a specified name, object, and user information. - Parameters: - aName: The name for the new notification. May not be 'nil'. - anObject: The object for the new notification. - aUserInfo: The user information dictionary for the new notification. May be 'nil'.
     * @param a_name Argument converted to the Objective-C parameter of the same role.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     * @param a_user_info Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Notification notification_with_name(const std::string& a_name, const Object& an_object, const std::vector<std::pair<Object, Object>>& a_user_info);
        /**
     * @brief Returns the `name` property of `NSNotification`.
     * @details The name of the notification. Typically you use this property to find out what kind of notification you are dealing with when you receive a notification. Notification names can be any string. To avoid name collisions, you might want to use a prefix that's specific to your application.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Returns the `object` property of `NSNotification`.
     * @details The object associated with the notification. This is often the object that posted this notification. It may be 'nil'. Typically you use this method to find out what object a notification applies to when you receive a notification.
     * @return The converted Objective-C result.
     */
        Object object() const;
        /**
     * @brief Returns the `userInfo` property of `NSNotification`.
     * @details The user information dictionary associated with the notification. This may be 'nil'. The user information dictionary stores any additional objects that objects receiving the notification might use.
     * @return The converted Objective-C result.
     */
        std::vector<std::pair<Object, Object>> user_info() const;
    };
}
