#include "generated/user_notification.h"
#include "internal.h"

namespace cocoon
{
    UserNotification::UserNotification() : UserNotification(Adopt{cocoon::internal::retain([[::NSUserNotification alloc] init])})
    {
    }

    UserNotification::UserNotification(std::nullptr_t) : Object(nullptr)
    {
    }

    UserNotification::UserNotification(Adopt adopt) : Object(adopt)
    {
    }

    std::string UserNotification::action_button_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUserNotification>(this) actionButtonTitle]);
    }

    void UserNotification::set_action_button_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setActionButtonTitle:cocoon::internal::to(value)];
    }

    UserNotificationActivationType UserNotification::activation_type() const
    {
        return static_cast<UserNotificationActivationType>([cocoon::internal::ns<::NSUserNotification>(this) activationType]);
    }

    Date UserNotification::actual_delivery_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSUserNotification>(this) actualDeliveryDate]);
    }

    std::vector<UserNotificationAction> UserNotification::additional_actions() const
    {
        return cocoon::internal::from_array<UserNotificationAction>([cocoon::internal::ns<::NSUserNotification>(this) additionalActions], [](id e) -> UserNotificationAction
                                                                    {
                                                                        return cocoon::internal::wrap<UserNotificationAction>((::NSUserNotificationAction*)e);
                                                                    });
    }

    void UserNotification::set_additional_actions(const std::vector<UserNotificationAction>& value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setAdditionalActions:cocoon::internal::to_array(value, [](const UserNotificationAction& e) -> id
                                                                                                          {
                                                                                                              return cocoon::internal::native<::NSUserNotificationAction>(e);
                                                                                                          })];
    }

    UserNotificationAction UserNotification::additional_activation_action() const
    {
        return cocoon::internal::wrap<UserNotificationAction>([cocoon::internal::ns<::NSUserNotification>(this) additionalActivationAction]);
    }

    Image UserNotification::content_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSUserNotification>(this) contentImage]);
    }

    void UserNotification::set_content_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setContentImage:cocoon::internal::native<::NSImage>(value)];
    }

    Date UserNotification::delivery_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSUserNotification>(this) deliveryDate]);
    }

    void UserNotification::set_delivery_date(const Date& value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setDeliveryDate:cocoon::internal::native<::NSDate>(value)];
    }

    DateComponents UserNotification::delivery_repeat_interval() const
    {
        return cocoon::internal::wrap<DateComponents>([cocoon::internal::ns<::NSUserNotification>(this) deliveryRepeatInterval]);
    }

    void UserNotification::set_delivery_repeat_interval(const DateComponents& value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setDeliveryRepeatInterval:cocoon::internal::native<::NSDateComponents>(value)];
    }

    TimeZone UserNotification::delivery_time_zone() const
    {
        return cocoon::internal::wrap<TimeZone>([cocoon::internal::ns<::NSUserNotification>(this) deliveryTimeZone]);
    }

    void UserNotification::set_delivery_time_zone(const TimeZone& value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setDeliveryTimeZone:cocoon::internal::native<::NSTimeZone>(value)];
    }

    bool UserNotification::has_action_button() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserNotification>(this) hasActionButton]);
    }

    void UserNotification::set_has_action_button(bool value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setHasActionButton:static_cast<::BOOL>(value)];
    }

    bool UserNotification::has_reply_button() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserNotification>(this) hasReplyButton]);
    }

    void UserNotification::set_has_reply_button(bool value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setHasReplyButton:static_cast<::BOOL>(value)];
    }

    std::string UserNotification::identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUserNotification>(this) identifier]);
    }

    void UserNotification::set_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setIdentifier:cocoon::internal::to(value)];
    }

    std::string UserNotification::informative_text() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUserNotification>(this) informativeText]);
    }

    void UserNotification::set_informative_text(const std::string& value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setInformativeText:cocoon::internal::to(value)];
    }

    std::string UserNotification::other_button_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUserNotification>(this) otherButtonTitle]);
    }

    void UserNotification::set_other_button_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setOtherButtonTitle:cocoon::internal::to(value)];
    }

    bool UserNotification::is_presented() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserNotification>(this) isPresented]);
    }

    bool UserNotification::is_remote() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserNotification>(this) isRemote]);
    }

    AttributedString UserNotification::response() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSUserNotification>(this) response]);
    }

    std::string UserNotification::response_placeholder() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUserNotification>(this) responsePlaceholder]);
    }

    void UserNotification::set_response_placeholder(const std::string& value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setResponsePlaceholder:cocoon::internal::to(value)];
    }

    std::string UserNotification::sound_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUserNotification>(this) soundName]);
    }

    void UserNotification::set_sound_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setSoundName:cocoon::internal::to(value)];
    }

    std::string UserNotification::subtitle() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUserNotification>(this) subtitle]);
    }

    void UserNotification::set_subtitle(const std::string& value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setSubtitle:cocoon::internal::to(value)];
    }

    std::string UserNotification::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUserNotification>(this) title]);
    }

    void UserNotification::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setTitle:cocoon::internal::to(value)];
    }

    std::map<std::string, Object> UserNotification::user_info() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSUserNotification>(this) userInfo], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void UserNotification::set_user_info(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSUserNotification>(this) setUserInfo:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                                      {
                                                                                                          return cocoon::internal::to(k);
                                                                                                      },
                                                                                                      [](const Object& v) -> id
                                                                                                      {
                                                                                                          return cocoon::internal::native_id(v);
                                                                                                      })];
    }
}
