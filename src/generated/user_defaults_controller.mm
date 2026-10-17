#include "generated/user_defaults_controller.h"
#include "internal.h"

namespace cocoon
{
    UserDefaultsController::UserDefaultsController(const UserDefaults& defaults, const std::map<std::string, Object>& initial_values) : UserDefaultsController(Adopt{cocoon::internal::retain([[::NSUserDefaultsController alloc] initWithDefaults:cocoon::internal::native<::NSUserDefaults>(defaults)
                                                                                                                                                                                                                       initialValues:cocoon::internal::to_dictionary(initial_values, [](const std::string& k) -> id
                                                                                                                                                                                                                                                       {
                                                                                                                                                                                                                                                           return cocoon::internal::to(k);
                                                                                                                                                                                                                                                       },
                                                                                                                                                                                                                                                       [](const Object& v) -> id
                                                                                                                                                                                                                                                       {
                                                                                                                                                                                                                                                           return cocoon::internal::native_id(v);
                                                                                                                                                                                                                                                       })])})
    {
    }

    UserDefaultsController::UserDefaultsController() : UserDefaultsController(Adopt{cocoon::internal::retain([[::NSUserDefaultsController alloc] init])})
    {
    }

    UserDefaultsController::UserDefaultsController(std::nullptr_t) : Controller(nullptr)
    {
    }

    UserDefaultsController::UserDefaultsController(Adopt adopt) : Controller(adopt)
    {
    }

    void UserDefaultsController::revert(const Object& sender) const
    {
        [cocoon::internal::ns<::NSUserDefaultsController>(this) revert:cocoon::internal::native_id(sender)];
    }

    void UserDefaultsController::revert_to_initial_values(const Object& sender) const
    {
        [cocoon::internal::ns<::NSUserDefaultsController>(this) revertToInitialValues:cocoon::internal::native_id(sender)];
    }

    void UserDefaultsController::save(const Object& sender) const
    {
        [cocoon::internal::ns<::NSUserDefaultsController>(this) save:cocoon::internal::native_id(sender)];
    }

    bool UserDefaultsController::applies_immediately() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserDefaultsController>(this) appliesImmediately]);
    }

    void UserDefaultsController::set_applies_immediately(bool value) const
    {
        [cocoon::internal::ns<::NSUserDefaultsController>(this) setAppliesImmediately:static_cast<::BOOL>(value)];
    }

    UserDefaults UserDefaultsController::defaults() const
    {
        return cocoon::internal::wrap<UserDefaults>([cocoon::internal::ns<::NSUserDefaultsController>(this) defaults]);
    }

    bool UserDefaultsController::has_unapplied_changes() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserDefaultsController>(this) hasUnappliedChanges]);
    }

    std::map<std::string, Object> UserDefaultsController::initial_values() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSUserDefaultsController>(this) initialValues], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    void UserDefaultsController::set_initial_values(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSUserDefaultsController>(this) setInitialValues:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                     {
                                                                                         return cocoon::internal::to(k);
                                                                                     },
                                                                                     [](const Object& v) -> id
                                                                                     {
                                                                                         return cocoon::internal::native_id(v);
                                                                                     })];
    }

    UserDefaultsController UserDefaultsController::shared_user_defaults_controller()
    {
        return cocoon::internal::wrap<UserDefaultsController>([::NSUserDefaultsController sharedUserDefaultsController]);
    }

    Object UserDefaultsController::values() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSUserDefaultsController>(this) values]);
    }
}
