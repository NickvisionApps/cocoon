#include "generated/user_defaults.h"
#include "internal.h"

namespace cocoon
{
    UserDefaults::UserDefaults(const std::string& suitename) : UserDefaults(Adopt{cocoon::internal::retain([[::NSUserDefaults alloc] initWithSuiteName:cocoon::internal::to(suitename)])})
    {
    }

    UserDefaults::UserDefaults() : UserDefaults(Adopt{cocoon::internal::retain([[::NSUserDefaults alloc] init])})
    {
    }

    UserDefaults::UserDefaults(std::nullptr_t) : Object(nullptr)
    {
    }

    UserDefaults::UserDefaults(Adopt adopt) : Object(adopt)
    {
    }

    URL UserDefaults::url_for_key(const std::string& default_name) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSUserDefaults>(this) URLForKey:cocoon::internal::to(default_name)]);
    }

    void UserDefaults::add_suite_named(const std::string& suite_name) const
    {
        [cocoon::internal::ns<::NSUserDefaults>(this) addSuiteNamed:cocoon::internal::to(suite_name)];
    }

    std::vector<Object> UserDefaults::array_for_key(const std::string& default_name) const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSUserDefaults>(this) arrayForKey:cocoon::internal::to(default_name)], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    bool UserDefaults::bool_for_key(const std::string& default_name) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserDefaults>(this) boolForKey:cocoon::internal::to(default_name)]);
    }

    std::vector<std::uint8_t> UserDefaults::data_for_key(const std::string& default_name) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSUserDefaults>(this) dataForKey:cocoon::internal::to(default_name)]);
    }

    std::map<std::string, Object> UserDefaults::dictionary_for_key(const std::string& default_name) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSUserDefaults>(this) dictionaryForKey:cocoon::internal::to(default_name)], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    std::map<std::string, Object> UserDefaults::dictionary_representation() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSUserDefaults>(this) dictionaryRepresentation], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    double UserDefaults::double_for_key(const std::string& default_name) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSUserDefaults>(this) doubleForKey:cocoon::internal::to(default_name)]);
    }

    float UserDefaults::float_for_key(const std::string& default_name) const
    {
        return static_cast<float>([cocoon::internal::ns<::NSUserDefaults>(this) floatForKey:cocoon::internal::to(default_name)]);
    }

    std::int64_t UserDefaults::integer_for_key(const std::string& default_name) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSUserDefaults>(this) integerForKey:cocoon::internal::to(default_name)]);
    }

    Object UserDefaults::object_for_key(const std::string& default_name) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSUserDefaults>(this) objectForKey:cocoon::internal::to(default_name)]);
    }

    bool UserDefaults::object_is_forced_for_key(const std::string& key) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserDefaults>(this) objectIsForcedForKey:cocoon::internal::to(key)]);
    }

    bool UserDefaults::object_is_forced_for_key(const std::string& key, const std::string& domain) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserDefaults>(this) objectIsForcedForKey:cocoon::internal::to(key) inDomain:cocoon::internal::to(domain)]);
    }

    std::map<std::string, Object> UserDefaults::persistent_domain_for_name(const std::string& domain_name) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSUserDefaults>(this) persistentDomainForName:cocoon::internal::to(domain_name)], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    void UserDefaults::register_defaults(const std::map<std::string, Object>& registration_dictionary) const
    {
        [cocoon::internal::ns<::NSUserDefaults>(this) registerDefaults:cocoon::internal::to_dictionary(registration_dictionary, [](const std::string& k) -> id
                                                                           {
                                                                               return cocoon::internal::to(k);
                                                                           },
                                                                           [](const Object& v) -> id
                                                                           {
                                                                               return cocoon::internal::native_id(v);
                                                                           })];
    }

    void UserDefaults::remove_object_for_key(const std::string& default_name) const
    {
        [cocoon::internal::ns<::NSUserDefaults>(this) removeObjectForKey:cocoon::internal::to(default_name)];
    }

    void UserDefaults::remove_persistent_domain_for_name(const std::string& domain_name) const
    {
        [cocoon::internal::ns<::NSUserDefaults>(this) removePersistentDomainForName:cocoon::internal::to(domain_name)];
    }

    void UserDefaults::remove_suite_named(const std::string& suite_name) const
    {
        [cocoon::internal::ns<::NSUserDefaults>(this) removeSuiteNamed:cocoon::internal::to(suite_name)];
    }

    void UserDefaults::remove_volatile_domain_for_name(const std::string& domain_name) const
    {
        [cocoon::internal::ns<::NSUserDefaults>(this) removeVolatileDomainForName:cocoon::internal::to(domain_name)];
    }

    void UserDefaults::reset_standard_user_defaults()
    {
        [::NSUserDefaults resetStandardUserDefaults];
    }

    void UserDefaults::set_bool(bool value, const std::string& default_name) const
    {
        [cocoon::internal::ns<::NSUserDefaults>(this) setBool:static_cast<::BOOL>(value) forKey:cocoon::internal::to(default_name)];
    }

    void UserDefaults::set_double(double value, const std::string& default_name) const
    {
        [cocoon::internal::ns<::NSUserDefaults>(this) setDouble:static_cast<double>(value) forKey:cocoon::internal::to(default_name)];
    }

    void UserDefaults::set_float(float value, const std::string& default_name) const
    {
        [cocoon::internal::ns<::NSUserDefaults>(this) setFloat:static_cast<float>(value) forKey:cocoon::internal::to(default_name)];
    }

    void UserDefaults::set_integer(std::int64_t value, const std::string& default_name) const
    {
        [cocoon::internal::ns<::NSUserDefaults>(this) setInteger:static_cast<::NSInteger>(value) forKey:cocoon::internal::to(default_name)];
    }

    void UserDefaults::set_object(const Object& value, const std::string& default_name) const
    {
        [cocoon::internal::ns<::NSUserDefaults>(this) setObject:cocoon::internal::native_id(value) forKey:cocoon::internal::to(default_name)];
    }

    void UserDefaults::set_persistent_domain(const std::map<std::string, Object>& domain, const std::string& domain_name) const
    {
        [cocoon::internal::ns<::NSUserDefaults>(this) setPersistentDomain:cocoon::internal::to_dictionary(domain, [](const std::string& k) -> id
                                                                              {
                                                                                  return cocoon::internal::to(k);
                                                                              },
                                                                              [](const Object& v) -> id
                                                                              {
                                                                                  return cocoon::internal::native_id(v);
                                                                              })
                                                    forName:cocoon::internal::to(domain_name)];
    }

    void UserDefaults::set_url(const URL& url, const std::string& default_name) const
    {
        [cocoon::internal::ns<::NSUserDefaults>(this) setURL:cocoon::internal::native<::NSURL>(url) forKey:cocoon::internal::to(default_name)];
    }

    void UserDefaults::set_volatile_domain(const std::map<std::string, Object>& domain, const std::string& domain_name) const
    {
        [cocoon::internal::ns<::NSUserDefaults>(this) setVolatileDomain:cocoon::internal::to_dictionary(domain, [](const std::string& k) -> id
                                                                            {
                                                                                return cocoon::internal::to(k);
                                                                            },
                                                                            [](const Object& v) -> id
                                                                            {
                                                                                return cocoon::internal::native_id(v);
                                                                            })
                                                  forName:cocoon::internal::to(domain_name)];
    }

    std::vector<std::string> UserDefaults::string_array_for_key(const std::string& default_name) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSUserDefaults>(this) stringArrayForKey:cocoon::internal::to(default_name)], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::string UserDefaults::string_for_key(const std::string& default_name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUserDefaults>(this) stringForKey:cocoon::internal::to(default_name)]);
    }

    bool UserDefaults::synchronize() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserDefaults>(this) synchronize]);
    }

    std::map<std::string, Object> UserDefaults::volatile_domain_for_name(const std::string& domain_name) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSUserDefaults>(this) volatileDomainForName:cocoon::internal::to(domain_name)], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    UserDefaults UserDefaults::standard_user_defaults()
    {
        return cocoon::internal::wrap<UserDefaults>([::NSUserDefaults standardUserDefaults]);
    }

    std::vector<std::string> UserDefaults::volatile_domain_names() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSUserDefaults>(this) volatileDomainNames], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }
}
