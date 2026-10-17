#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUserNotificationAction` (Foundation).
     * @details An action that the user can take in response to receiving a notification. \@DeprecationSummary { Use the \<doc://com.apple.documentation/documentation/usernotifications> framework instead. } User notifications can specify one or more actions to show to the user by using the ''NSUserNotification/additionalActivationAction'' or ''NSUserNotification/additionalActions'' properties. ''NSUserNotificationAction'' objects contain the localized title shown to the user and an identifier used to differentiate between presented actions.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UserNotificationAction user_notification_action;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::UserNotificationAction user_notification_action{};
     * auto made_0 = cocoon::UserNotificationAction::action_with_identifier("text", "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsusernotificationaction
     */
    class UserNotificationAction : public Object
    {
    public:
        /// @brief Creates a new `NSUserNotificationAction` instance and returns a handle to it.
        explicit UserNotificationAction();
        /// @brief Creates a null handle that refers to no native object.
        UserNotificationAction(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UserNotificationAction(Adopt adopt);
        /**
     * @brief Calls `+[NSUserNotificationAction actionWithIdentifier:title:]`.
     * @details Creates a user notification action with a specified identifier and title. - Parameters: - identifier: The identifier for the action. - title: A localized string suitable for display to the user.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static UserNotificationAction action_with_identifier(const std::string& identifier, const std::string& title);
        /**
     * @brief Returns the `identifier` property of `NSUserNotificationAction`.
     * @details The identifier for the user notification action.
     * @return The converted Objective-C result.
     */
        std::string identifier() const;
        /**
     * @brief Returns the `title` property of `NSUserNotificationAction`.
     * @details The localized title shown to the user.
     * @return The converted Objective-C result.
     */
        std::string title() const;
    };
}
