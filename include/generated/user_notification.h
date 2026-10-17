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
     * @details A notification that can be scheduled for display in the notification center. \@DeprecationSummary { Use the \<doc://com.apple.documentation/documentation/usernotifications> framework instead. } When the system delivers a notification, information about when the notification was actually presented to the user (if at all) and other details are provided in the notification object. User applications can create ''NSUserNotification'' objects and register them with the ''NSUserNotificationCenter'' object to notify the user when an application requires attention. \#\#\# Threading Information The ''NSUserNotificationCenter'' class and the 'NSUserNotification' class are both thread safe.
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
     * @details Specifies the title of the action button displayed in the notification. This value should be localized as it is presented to the user. The string is truncated to a length appropriate for display and the property is modified to reflect the truncation.
     * @return The converted Objective-C result.
     */
        std::string action_button_title() const;
        /**
     * @brief Sets the `actionButtonTitle` property of `NSUserNotification`.
     * @details Specifies the title of the action button displayed in the notification. This value should be localized as it is presented to the user. The string is truncated to a length appropriate for display and the property is modified to reflect the truncation.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_action_button_title(const std::string& value) const;
        /**
     * @brief Returns the `activationType` property of `NSUserNotification`.
     * @details Specifies what caused a user notification to occur. This property specifies why the user notification was sent to the 'NSUserNotificationCenterDelegate' method 'userNotificationCenter:didActivateNotification:'. The supported values are described in 'NSUserNotificationActivationType'.
     * @return The converted Objective-C result.
     */
        UserNotificationActivationType activation_type() const;
        /**
     * @brief Returns the `actualDeliveryDate` property of `NSUserNotification`.
     * @details The date this notification was actually delivered. The notification center will set this value if a notification is put in the scheduled list and the delivery time arrives. If the notification is delivered directly using the 'deliverNotification:' method of the 'NSUserNotificationCenter' class, this value is set to the 'deliveryDate' value. If the 'deliveryDate' value is 'nil', this value is set to the current date. This value is used to sort the list of notifications in the user interface.
     * @return The converted Objective-C result.
     */
        Date actual_delivery_date() const;
        /**
     * @brief Returns the `additionalActions` property of `NSUserNotification`.
     * @details The actions that can be taken on a notification in addition to the default action. This array contains 'NSUserNotificationAction' objects that describe the different actions for a notification in addition to the default action described by 'actionButtonTitle'.
     * @return The converted Objective-C result.
     */
        std::vector<UserNotificationAction> additional_actions() const;
        /**
     * @brief Sets the `additionalActions` property of `NSUserNotification`.
     * @details The actions that can be taken on a notification in addition to the default action. This array contains 'NSUserNotificationAction' objects that describe the different actions for a notification in addition to the default action described by 'actionButtonTitle'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_additional_actions(const std::vector<UserNotificationAction>& value) const;
        /**
     * @brief Returns the `additionalActivationAction` property of `NSUserNotification`.
     * @details An additional action selected by the user. This property specifies an additional action selected by the user when the user notification is sent to the 'NSUserNotificationCenterDelegate' method 'userNotificationCenter:didActivateNotification:'.
     * @return The converted Objective-C result.
     */
        UserNotificationAction additional_activation_action() const;
        /**
     * @brief Returns the `contentImage` property of `NSUserNotification`.
     * @details Image shown in the content of the notification.
     * @return The converted Objective-C result.
     */
        Image content_image() const;
        /**
     * @brief Sets the `contentImage` property of `NSUserNotification`.
     * @details Image shown in the content of the notification.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_image(const Image& value) const;
        /**
     * @brief Returns the `deliveryDate` property of `NSUserNotification`.
     * @details Specifies when the notification should be delivered. The delivery date is specified in an absolute time. After a notification is delivered, it may be presented to the user.
     * @return The converted Objective-C result.
     */
        Date delivery_date() const;
        /**
     * @brief Sets the `deliveryDate` property of `NSUserNotification`.
     * @details Specifies when the notification should be delivered. The delivery date is specified in an absolute time. After a notification is delivered, it may be presented to the user.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_delivery_date(const Date& value) const;
        /**
     * @brief Returns the `deliveryRepeatInterval` property of `NSUserNotification`.
     * @details Specifies the date components that control how often a user notification is repeated. This value may be 'nil' if the notification should not repeat. The date component values are relative to the date the notification was delivered. If the calendar value of the 'deliveryRepeatInterval' is 'nil', the current calendar is used to calculate the repeat interval. For example, if a notification should repeat every hour, set the 'hour' property of the 'deliveryRepeatInterval' to '1'. This value is ignored unless the user notification is scheduled with the 'NSUserNotificationCenter' object.
     * @return The converted Objective-C result.
     */
        DateComponents delivery_repeat_interval() const;
        /**
     * @brief Sets the `deliveryRepeatInterval` property of `NSUserNotification`.
     * @details Specifies the date components that control how often a user notification is repeated. This value may be 'nil' if the notification should not repeat. The date component values are relative to the date the notification was delivered. If the calendar value of the 'deliveryRepeatInterval' is 'nil', the current calendar is used to calculate the repeat interval. For example, if a notification should repeat every hour, set the 'hour' property of the 'deliveryRepeatInterval' to '1'. This value is ignored unless the user notification is scheduled with the 'NSUserNotificationCenter' object.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_delivery_repeat_interval(const DateComponents& value) const;
        /**
     * @brief Returns the `deliveryTimeZone` property of `NSUserNotification`.
     * @details Specify the time zone to interpret the delivery date in. If this value is 'nil' and the user switches time zones, the notification center will adjust the time of presentation to account for the time zone change. If a notification should be delivered at a time in a specific time zone (regardless of whether the user switches time zones), set this value to the specific time zone, for example the current time zone.
     * @return The converted Objective-C result.
     */
        TimeZone delivery_time_zone() const;
        /**
     * @brief Sets the `deliveryTimeZone` property of `NSUserNotification`.
     * @details Specify the time zone to interpret the delivery date in. If this value is 'nil' and the user switches time zones, the notification center will adjust the time of presentation to account for the time zone change. If a notification should be delivered at a time in a specific time zone (regardless of whether the user switches time zones), set this value to the specific time zone, for example the current time zone.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_delivery_time_zone(const TimeZone& value) const;
        /**
     * @brief Returns the `hasActionButton` property of `NSUserNotification`.
     * @details A Boolean value that specifies whether the notification displays an action button. Set to 'NO' if the notification has no action button. This is the case for notifications that are purely for information and have no user action. The default value is 'YES'.
     * @return The converted Objective-C result.
     */
        bool has_action_button() const;
        /**
     * @brief Sets the `hasActionButton` property of `NSUserNotification`.
     * @details A Boolean value that specifies whether the notification displays an action button. Set to 'NO' if the notification has no action button. This is the case for notifications that are purely for information and have no user action. The default value is 'YES'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_has_action_button(bool value) const;
        /**
     * @brief Returns the `hasReplyButton` property of `NSUserNotification`.
     * @details A Boolean value that specifies whether the notification displays a reply button. Set to 'YES' if the notification has a reply button. The default value is 'NO'. If this property and 'hasActionButton' are both 'YES', the reply button is shown.
     * @return The converted Objective-C result.
     */
        bool has_reply_button() const;
        /**
     * @brief Sets the `hasReplyButton` property of `NSUserNotification`.
     * @details A Boolean value that specifies whether the notification displays a reply button. Set to 'YES' if the notification has a reply button. The default value is 'NO'. If this property and 'hasActionButton' are both 'YES', the reply button is shown.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_has_reply_button(bool value) const;
        /**
     * @brief Returns the `identifier` property of `NSUserNotification`.
     * @details A string that uniquely identifies a notification. The identifier is unique to a notification. A notification delivered with the same identifier as an existing notification replaces the existing notification rather than causing the display of a new notification.
     * @return The converted Objective-C result.
     */
        std::string identifier() const;
        /**
     * @brief Sets the `identifier` property of `NSUserNotification`.
     * @details A string that uniquely identifies a notification. The identifier is unique to a notification. A notification delivered with the same identifier as an existing notification replaces the existing notification rather than causing the display of a new notification.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_identifier(const std::string& value) const;
        /**
     * @brief Returns the `informativeText` property of `NSUserNotification`.
     * @details The body text of the notification. This value should be localized as it is presented to the user. The string is truncated to a length appropriate for display and the property is modified to reflect the truncation.
     * @return The converted Objective-C result.
     */
        std::string informative_text() const;
        /**
     * @brief Sets the `informativeText` property of `NSUserNotification`.
     * @details The body text of the notification. This value should be localized as it is presented to the user. The string is truncated to a length appropriate for display and the property is modified to reflect the truncation.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_informative_text(const std::string& value) const;
        /**
     * @brief Returns the `otherButtonTitle` property of `NSUserNotification`.
     * @details Specifies a custom title for the close button in an alert-style notification. This value should be localized as it is presented to the user. The string is truncated to a length appropriate for display and the property is modified to reflect the truncation. An empty string will cause the default localized text to be used. A 'nil' value is invalid.
     * @return The converted Objective-C result.
     */
        std::string other_button_title() const;
        /**
     * @brief Sets the `otherButtonTitle` property of `NSUserNotification`.
     * @details Specifies a custom title for the close button in an alert-style notification. This value should be localized as it is presented to the user. The string is truncated to a length appropriate for display and the property is modified to reflect the truncation. An empty string will cause the default localized text to be used. A 'nil' value is invalid.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_other_button_title(const std::string& value) const;
        /**
     * @brief Returns the `presented` property of `NSUserNotification`.
     * @details Specifies whether the user notification has been presented. In some cases, for example when your application is frontmost, the notification center may decide not to actually present a delivered notification. In that case, the value of this property is 'NO'. It is set to 'YES' if the notification was presented according to user preferences.
     * @return The converted Objective-C result.
     */
        bool is_presented() const;
        /**
     * @brief Returns the `remote` property of `NSUserNotification`.
     * @details Specifies whether the notification was generated by a push notification. If this property is 'YES' then the user notification was generated by a push notification (that is, remotely); if 'NO' it was generated locally.
     * @return The converted Objective-C result.
     */
        bool is_remote() const;
        /**
     * @brief Returns the `response` property of `NSUserNotification`.
     * @details The response with which the user responded to a notification. When the user responds to a notification, the 'NSUserNotificationCenterDelegate' method 'userNotificationCenter:didActivateNotification:' is called with the notification, the 'activationType' property set to 'NSUserNotificationActivationTypeReplied', and this property is set with the user's response.
     * @return The converted Objective-C result.
     */
        AttributedString response() const;
        /**
     * @brief Returns the `responsePlaceholder` property of `NSUserNotification`.
     * @details Optional placeholder string for inline reply field.
     * @return The converted Objective-C result.
     */
        std::string response_placeholder() const;
        /**
     * @brief Sets the `responsePlaceholder` property of `NSUserNotification`.
     * @details Optional placeholder string for inline reply field.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_response_placeholder(const std::string& value) const;
        /**
     * @brief Returns the `soundName` property of `NSUserNotification`.
     * @details Specifies the name of the sound to play when the notification is delivered. Passing the 'NSUserNotificationDefaultSoundName' constant causes the default notification center sound to be played. A value of 'nil' means no sound is played.
     * @return The converted Objective-C result.
     */
        std::string sound_name() const;
        /**
     * @brief Sets the `soundName` property of `NSUserNotification`.
     * @details Specifies the name of the sound to play when the notification is delivered. Passing the 'NSUserNotificationDefaultSoundName' constant causes the default notification center sound to be played. A value of 'nil' means no sound is played.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sound_name(const std::string& value) const;
        /**
     * @brief Returns the `subtitle` property of `NSUserNotification`.
     * @details Specifies the subtitle of the notification. This value should be localized as it is presented to the user. The string is truncated to a length appropriate for display and the property is modified to reflect the truncation.
     * @return The converted Objective-C result.
     */
        std::string subtitle() const;
        /**
     * @brief Sets the `subtitle` property of `NSUserNotification`.
     * @details Specifies the subtitle of the notification. This value should be localized as it is presented to the user. The string is truncated to a length appropriate for display and the property is modified to reflect the truncation.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_subtitle(const std::string& value) const;
        /**
     * @brief Returns the `title` property of `NSUserNotification`.
     * @details Specifies the title of the notification. This value should be localized because it is presented to the user. The string is truncated to a length appropriate for display and the property is modified to reflect the truncation.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSUserNotification`.
     * @details Specifies the title of the notification. This value should be localized because it is presented to the user. The string is truncated to a length appropriate for display and the property is modified to reflect the truncation.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
        /**
     * @brief Returns the `userInfo` property of `NSUserNotification`.
     * @details Application-specific user info that can be attached to the notification. All items must be property list types or an exception is thrown. The 'userInfo' content must be of reasonable serialized size (less than 1KB) or an exception is thrown.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> user_info() const;
        /**
     * @brief Sets the `userInfo` property of `NSUserNotification`.
     * @details Application-specific user info that can be attached to the notification. All items must be property list types or an exception is thrown. The 'userInfo' content must be of reasonable serialized size (less than 1KB) or an exception is thrown.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_user_info(const std::map<std::string, Object>& value) const;
    };
}
