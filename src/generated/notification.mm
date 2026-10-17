#include "generated/notification.h"
#include "internal.h"

namespace cocoon
{
    Notification::Notification(const std::string& name, const Object& object, const std::vector<std::pair<Object, Object>>& user_info) : Notification(Adopt{cocoon::internal::retain([[::NSNotification alloc] initWithName:cocoon::internal::to(name)
                                                                                                                                                                                                                     object:cocoon::internal::native_id(object)
                                                                                                                                                                                                                   userInfo:cocoon::internal::to_dictionary(user_info, [](const Object& k) -> id
                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                return cocoon::internal::native_id(k);
                                                                                                                                                                                                                                                            },
                                                                                                                                                                                                                                                            [](const Object& v) -> id
                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                return cocoon::internal::native_id(v);
                                                                                                                                                                                                                                                            })])})
    {
    }

    Notification::Notification() : Notification(Adopt{cocoon::internal::retain([[::NSNotification alloc] init])})
    {
    }

    Notification::Notification(std::nullptr_t) : Object(nullptr)
    {
    }

    Notification::Notification(Adopt adopt) : Object(adopt)
    {
    }

    Notification Notification::notification_with_name(const std::string& a_name, const Object& an_object)
    {
        return cocoon::internal::wrap<Notification>([::NSNotification notificationWithName:cocoon::internal::to(a_name) object:cocoon::internal::native_id(an_object)]);
    }

    Notification Notification::notification_with_name(const std::string& a_name, const Object& an_object, const std::vector<std::pair<Object, Object>>& a_user_info)
    {
        return cocoon::internal::wrap<Notification>([::NSNotification notificationWithName:cocoon::internal::to(a_name)
                                                                                    object:cocoon::internal::native_id(an_object)
                                                                                  userInfo:cocoon::internal::to_dictionary(a_user_info, [](const Object& k) -> id
                                                                                                                           {
                                                                                                                               return cocoon::internal::native_id(k);
                                                                                                                           },
                                                                                                                           [](const Object& v) -> id
                                                                                                                           {
                                                                                                                               return cocoon::internal::native_id(v);
                                                                                                                           })]);
    }

    std::string Notification::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNotification>(this) name]);
    }

    Object Notification::object() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSNotification>(this) object]);
    }

    std::vector<std::pair<Object, Object>> Notification::user_info() const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>([cocoon::internal::ns<::NSNotification>(this) userInfo], [](id k) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(k);
                                                                                         },
                                                                                         [](id v) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(v);
                                                                                         });
    }
}
