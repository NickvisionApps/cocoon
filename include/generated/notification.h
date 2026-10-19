#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSNotification` (Foundation).
     * @details Notifications
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
     * @param a_name Argument converted to the Objective-C parameter of the same role.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Notification notification_with_name(const std::string& a_name, const Object& an_object);
        /**
     * @brief Calls `+[NSNotification notificationWithName:object:userInfo:]`.
     * @param a_name Argument converted to the Objective-C parameter of the same role.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     * @param a_user_info Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Notification notification_with_name(const std::string& a_name, const Object& an_object, const std::vector<std::pair<Object, Object>>& a_user_info);
        /**
     * @brief Returns the `name` property of `NSNotification`.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Returns the `object` property of `NSNotification`.
     * @return The converted Objective-C result.
     */
        Object object() const;
        /**
     * @brief Returns the `userInfo` property of `NSNotification`.
     * @return The converted Objective-C result.
     */
        std::vector<std::pair<Object, Object>> user_info() const;
    };
}
