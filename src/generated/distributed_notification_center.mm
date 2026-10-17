#include "generated/distributed_notification_center.h"
#include "internal.h"

namespace cocoon
{
    DistributedNotificationCenter::DistributedNotificationCenter() : DistributedNotificationCenter(Adopt{cocoon::internal::retain([[::NSDistributedNotificationCenter alloc] init])})
    {
    }

    DistributedNotificationCenter::DistributedNotificationCenter(std::nullptr_t) : NotificationCenter(nullptr)
    {
    }

    DistributedNotificationCenter::DistributedNotificationCenter(Adopt adopt) : NotificationCenter(adopt)
    {
    }

    void DistributedNotificationCenter::add_observer(const Object& observer, const std::string& a_selector, const std::string& a_name, const std::string& an_object) const
    {
        [cocoon::internal::ns<::NSDistributedNotificationCenter>(this) addObserver:cocoon::internal::native_id(observer) selector:NSSelectorFromString(cocoon::internal::to(a_selector)) name:cocoon::internal::to(a_name) object:cocoon::internal::to(an_object)];
    }

    void DistributedNotificationCenter::add_observer(const Object& observer, const std::string& selector, const std::string& name, const std::string& object, NotificationSuspensionBehavior suspension_behavior) const
    {
        [cocoon::internal::ns<::NSDistributedNotificationCenter>(this) addObserver:cocoon::internal::native_id(observer) selector:NSSelectorFromString(cocoon::internal::to(selector)) name:cocoon::internal::to(name) object:cocoon::internal::to(object) suspensionBehavior:static_cast<::NSNotificationSuspensionBehavior>(suspension_behavior)];
    }

    DistributedNotificationCenter DistributedNotificationCenter::default_center()
    {
        return cocoon::internal::wrap<DistributedNotificationCenter>([::NSDistributedNotificationCenter defaultCenter]);
    }

    DistributedNotificationCenter DistributedNotificationCenter::notification_center_for_type(const std::string& notification_center_type)
    {
        return cocoon::internal::wrap<DistributedNotificationCenter>([::NSDistributedNotificationCenter notificationCenterForType:cocoon::internal::to(notification_center_type)]);
    }

    void DistributedNotificationCenter::post_notification_name(const std::string& a_name, const std::string& an_object) const
    {
        [cocoon::internal::ns<::NSDistributedNotificationCenter>(this) postNotificationName:cocoon::internal::to(a_name) object:cocoon::internal::to(an_object)];
    }

    void DistributedNotificationCenter::post_notification_name(const std::string& a_name, const std::string& an_object, const std::vector<std::pair<Object, Object>>& a_user_info) const
    {
        [cocoon::internal::ns<::NSDistributedNotificationCenter>(this) postNotificationName:cocoon::internal::to(a_name)
                                                                       object:cocoon::internal::to(an_object)
                                                                     userInfo:cocoon::internal::to_dictionary(a_user_info, [](const Object& k) -> id
                                                                                                {
                                                                                                    return cocoon::internal::native_id(k);
                                                                                                },
                                                                                                [](const Object& v) -> id
                                                                                                {
                                                                                                    return cocoon::internal::native_id(v);
                                                                                                })];
    }

    void DistributedNotificationCenter::post_notification_name(const std::string& name, const std::string& object, const std::vector<std::pair<Object, Object>>& user_info, bool deliver_immediately) const
    {
        [cocoon::internal::ns<::NSDistributedNotificationCenter>(this) postNotificationName:cocoon::internal::to(name)
                                                                       object:cocoon::internal::to(object)
                                                                     userInfo:cocoon::internal::to_dictionary(user_info, [](const Object& k) -> id
                                                                                                {
                                                                                                    return cocoon::internal::native_id(k);
                                                                                                },
                                                                                                [](const Object& v) -> id
                                                                                                {
                                                                                                    return cocoon::internal::native_id(v);
                                                                                                })
                                                           deliverImmediately:static_cast<::BOOL>(deliver_immediately)];
    }

    void DistributedNotificationCenter::post_notification_name(const std::string& name, const std::string& object, const std::vector<std::pair<Object, Object>>& user_info, DistributedNotificationOptions options) const
    {
        [cocoon::internal::ns<::NSDistributedNotificationCenter>(this) postNotificationName:cocoon::internal::to(name)
                                                                       object:cocoon::internal::to(object)
                                                                     userInfo:cocoon::internal::to_dictionary(user_info, [](const Object& k) -> id
                                                                                                {
                                                                                                    return cocoon::internal::native_id(k);
                                                                                                },
                                                                                                [](const Object& v) -> id
                                                                                                {
                                                                                                    return cocoon::internal::native_id(v);
                                                                                                })
                                                                      options:static_cast<::NSDistributedNotificationOptions>(options)];
    }

    void DistributedNotificationCenter::remove_observer(const Object& observer, const std::string& a_name, const std::string& an_object) const
    {
        [cocoon::internal::ns<::NSDistributedNotificationCenter>(this) removeObserver:cocoon::internal::native_id(observer) name:cocoon::internal::to(a_name) object:cocoon::internal::to(an_object)];
    }

    bool DistributedNotificationCenter::suspended() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDistributedNotificationCenter>(this) suspended]);
    }

    void DistributedNotificationCenter::set_suspended(bool value) const
    {
        [cocoon::internal::ns<::NSDistributedNotificationCenter>(this) setSuspended:static_cast<::BOOL>(value)];
    }
}
