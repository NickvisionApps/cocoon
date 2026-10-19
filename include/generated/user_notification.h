#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Date;
    class DateComponents;
    class Image;
    class TimeZone;
    class UserNotificationAction;

    /**
     * @brief C++ handle for the Objective-C class `NSUserNotification` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UserNotification user_notification;
     * user_notification.set_action_button_title("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::UserNotification user_notification{};
     * user_notification.set_action_button_title("text");
     * auto action_button_title = user_notification.action_button_title();
     * user_notification.set_content_image(cocoon::Image());
     * auto content_image = user_notification.content_image();
     * user_notification.set_delivery_date(cocoon::Date());
     * auto delivery_date = user_notification.delivery_date();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsusernotification
     */
    class UserNotification : public Object
    {
    public:
        /// @brief Creates a new `NSUserNotification` instance and returns a handle to it.
        explicit UserNotification();
        /// @brief Creates a null handle that refers to no native object.
        UserNotification(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UserNotification(Adopt adopt);
        /**
     * @brief Returns the `actionButtonTitle` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        std::string action_button_title() const;
        /**
     * @brief Sets the `actionButtonTitle` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_action_button_title(const std::string& value) const;
        /**
     * @brief Returns the `activationType` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        UserNotificationActivationType activation_type() const;
        /**
     * @brief Returns the `actualDeliveryDate` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        Date actual_delivery_date() const;
        /**
     * @brief Returns the `additionalActions` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        std::vector<UserNotificationAction> additional_actions() const;
        /**
     * @brief Sets the `additionalActions` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_additional_actions(const std::vector<UserNotificationAction>& value) const;
        /**
     * @brief Returns the `additionalActivationAction` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        UserNotificationAction additional_activation_action() const;
        /**
     * @brief Returns the `contentImage` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        Image content_image() const;
        /**
     * @brief Sets the `contentImage` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_image(const Image& value) const;
        /**
     * @brief Returns the `deliveryDate` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        Date delivery_date() const;
        /**
     * @brief Sets the `deliveryDate` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_delivery_date(const Date& value) const;
        /**
     * @brief Returns the `deliveryRepeatInterval` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        DateComponents delivery_repeat_interval() const;
        /**
     * @brief Sets the `deliveryRepeatInterval` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_delivery_repeat_interval(const DateComponents& value) const;
        /**
     * @brief Returns the `deliveryTimeZone` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        TimeZone delivery_time_zone() const;
        /**
     * @brief Sets the `deliveryTimeZone` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_delivery_time_zone(const TimeZone& value) const;
        /**
     * @brief Returns the `hasActionButton` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        bool has_action_button() const;
        /**
     * @brief Sets the `hasActionButton` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_has_action_button(bool value) const;
        /**
     * @brief Returns the `hasReplyButton` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        bool has_reply_button() const;
        /**
     * @brief Sets the `hasReplyButton` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_has_reply_button(bool value) const;
        /**
     * @brief Returns the `identifier` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        std::string identifier() const;
        /**
     * @brief Sets the `identifier` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_identifier(const std::string& value) const;
        /**
     * @brief Returns the `informativeText` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        std::string informative_text() const;
        /**
     * @brief Sets the `informativeText` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_informative_text(const std::string& value) const;
        /**
     * @brief Returns the `otherButtonTitle` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        std::string other_button_title() const;
        /**
     * @brief Sets the `otherButtonTitle` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_other_button_title(const std::string& value) const;
        /**
     * @brief Returns the `presented` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        bool is_presented() const;
        /**
     * @brief Returns the `remote` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        bool is_remote() const;
        /**
     * @brief Returns the `response` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        AttributedString response() const;
        /**
     * @brief Returns the `responsePlaceholder` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        std::string response_placeholder() const;
        /**
     * @brief Sets the `responsePlaceholder` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_response_placeholder(const std::string& value) const;
        /**
     * @brief Returns the `soundName` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        std::string sound_name() const;
        /**
     * @brief Sets the `soundName` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sound_name(const std::string& value) const;
        /**
     * @brief Returns the `subtitle` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        std::string subtitle() const;
        /**
     * @brief Sets the `subtitle` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_subtitle(const std::string& value) const;
        /**
     * @brief Returns the `title` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
        /**
     * @brief Returns the `userInfo` property of `NSUserNotification`.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> user_info() const;
        /**
     * @brief Sets the `userInfo` property of `NSUserNotification`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_user_info(const std::map<std::string, Object>& value) const;
    };
}
