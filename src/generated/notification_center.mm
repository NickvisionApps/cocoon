#include "generated/notification_center.h"
#include "internal.h"

namespace cocoon
{
    NotificationCenter::NotificationCenter() : NotificationCenter(Adopt{cocoon::internal::retain([[::NSNotificationCenter alloc] init])})
    {
    }

    NotificationCenter::NotificationCenter(std::nullptr_t) : Object(nullptr)
    {
    }

    NotificationCenter::NotificationCenter(Adopt adopt) : Object(adopt)
    {
    }

    void NotificationCenter::add_observer(const Object& observer, const std::string& a_selector, const std::string& a_name, const Object& an_object) const
    {
        [cocoon::internal::ns<::NSNotificationCenter>(this) addObserver:cocoon::internal::native_id(observer) selector:NSSelectorFromString(cocoon::internal::to(a_selector)) name:cocoon::internal::to(a_name) object:cocoon::internal::native_id(an_object)];
    }

    Object NotificationCenter::add_observer_for_name(const std::string& name, const Object& obj, const OperationQueue& queue, std::function<void(Notification)> block) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSNotificationCenter>(this) addObserverForName:cocoon::internal::to(name) object:cocoon::internal::native_id(obj) queue:cocoon::internal::native<::NSOperationQueue>(queue) usingBlock:(block ? (void (^)(::NSNotification*)) ^ void(::NSNotification * a194_0) { block(cocoon::internal::wrap<Notification>(a194_0)); } : (void (^)(::NSNotification*))nil)]);
    }

    void NotificationCenter::post_notification(const Notification& notification) const
    {
        [cocoon::internal::ns<::NSNotificationCenter>(this) postNotification:cocoon::internal::native<::NSNotification>(notification)];
    }

    void NotificationCenter::post_notification_name(const std::string& a_name, const Object& an_object) const
    {
        [cocoon::internal::ns<::NSNotificationCenter>(this) postNotificationName:cocoon::internal::to(a_name) object:cocoon::internal::native_id(an_object)];
    }

    void NotificationCenter::post_notification_name(const std::string& a_name, const Object& an_object, const std::vector<std::pair<Object, Object>>& a_user_info) const
    {
        [cocoon::internal::ns<::NSNotificationCenter>(this) postNotificationName:cocoon::internal::to(a_name)
                                                                          object:cocoon::internal::native_id(an_object)
                                                                        userInfo:cocoon::internal::to_dictionary(a_user_info, [](const Object& k) -> id
                                                                                                                 {
                                                                                                                     return cocoon::internal::native_id(k);
                                                                                                                 },
                                                                                                                 [](const Object& v) -> id
                                                                                                                 {
                                                                                                                     return cocoon::internal::native_id(v);
                                                                                                                 })];
    }

    void NotificationCenter::remove_observer(const Object& observer) const
    {
        [cocoon::internal::ns<::NSNotificationCenter>(this) removeObserver:cocoon::internal::native_id(observer)];
    }

    void NotificationCenter::remove_observer(const Object& observer, const std::string& a_name, const Object& an_object) const
    {
        [cocoon::internal::ns<::NSNotificationCenter>(this) removeObserver:cocoon::internal::native_id(observer) name:cocoon::internal::to(a_name) object:cocoon::internal::native_id(an_object)];
    }

    NotificationCenter NotificationCenter::default_center()
    {
        return cocoon::internal::wrap<NotificationCenter>([::NSNotificationCenter defaultCenter]);
    }
}
