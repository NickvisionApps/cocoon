#include "generated/user_notification_action.h"
#include "internal.h"

namespace cocoon
{
    UserNotificationAction::UserNotificationAction() : UserNotificationAction(Adopt{cocoon::internal::retain([[::NSUserNotificationAction alloc] init])})
    {
    }

    UserNotificationAction::UserNotificationAction(std::nullptr_t) : Object(nullptr)
    {
    }

    UserNotificationAction::UserNotificationAction(Adopt adopt) : Object(adopt)
    {
    }

    UserNotificationAction UserNotificationAction::action_with_identifier(const std::string& identifier, const std::string& title)
    {
        return cocoon::internal::wrap<UserNotificationAction>([::NSUserNotificationAction actionWithIdentifier:cocoon::internal::to(identifier) title:cocoon::internal::to(title)]);
    }

    std::string UserNotificationAction::identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUserNotificationAction>(this) identifier]);
    }

    std::string UserNotificationAction::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUserNotificationAction>(this) title]);
    }
}
