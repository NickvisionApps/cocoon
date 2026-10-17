#include "generated/ubiquitous_key_value_store.h"
#include "internal.h"

namespace cocoon
{
    UbiquitousKeyValueStore::UbiquitousKeyValueStore() : UbiquitousKeyValueStore(Adopt{cocoon::internal::retain([[::NSUbiquitousKeyValueStore alloc] init])})
    {
    }

    UbiquitousKeyValueStore::UbiquitousKeyValueStore(std::nullptr_t) : Object(nullptr)
    {
    }

    UbiquitousKeyValueStore::UbiquitousKeyValueStore(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<Object> UbiquitousKeyValueStore::array_for_key(const std::string& a_key) const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) arrayForKey:cocoon::internal::to(a_key)], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    bool UbiquitousKeyValueStore::bool_for_key(const std::string& a_key) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) boolForKey:cocoon::internal::to(a_key)]);
    }

    std::vector<std::uint8_t> UbiquitousKeyValueStore::data_for_key(const std::string& a_key) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) dataForKey:cocoon::internal::to(a_key)]);
    }

    std::map<std::string, Object> UbiquitousKeyValueStore::dictionary_for_key(const std::string& a_key) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) dictionaryForKey:cocoon::internal::to(a_key)], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    double UbiquitousKeyValueStore::double_for_key(const std::string& a_key) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) doubleForKey:cocoon::internal::to(a_key)]);
    }

    std::int64_t UbiquitousKeyValueStore::long_long_for_key(const std::string& a_key) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) longLongForKey:cocoon::internal::to(a_key)]);
    }

    Object UbiquitousKeyValueStore::object_for_key(const std::string& a_key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) objectForKey:cocoon::internal::to(a_key)]);
    }

    void UbiquitousKeyValueStore::remove_object_for_key(const std::string& a_key) const
    {
        [cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) removeObjectForKey:cocoon::internal::to(a_key)];
    }

    void UbiquitousKeyValueStore::set_array(const std::vector<Object>& an_array, const std::string& a_key) const
    {
        [cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) setArray:cocoon::internal::to_array(an_array, [](const Object& e) -> id
                                                                         {
                                                                             return cocoon::internal::native_id(e);
                                                                         })
                                                     forKey:cocoon::internal::to(a_key)];
    }

    void UbiquitousKeyValueStore::set_bool(bool value, const std::string& a_key) const
    {
        [cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) setBool:static_cast<::BOOL>(value) forKey:cocoon::internal::to(a_key)];
    }

    void UbiquitousKeyValueStore::set_data(const std::vector<std::uint8_t>& a_data, const std::string& a_key) const
    {
        [cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) setData:cocoon::internal::to_data(a_data) forKey:cocoon::internal::to(a_key)];
    }

    void UbiquitousKeyValueStore::set_dictionary(const std::map<std::string, Object>& a_dictionary, const std::string& a_key) const
    {
        [cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) setDictionary:cocoon::internal::to_dictionary(a_dictionary, [](const std::string& k) -> id
                                                                                   {
                                                                                       return cocoon::internal::to(k);
                                                                                   },
                                                                                   [](const Object& v) -> id
                                                                                   {
                                                                                       return cocoon::internal::native_id(v);
                                                                                   })
                                                          forKey:cocoon::internal::to(a_key)];
    }

    void UbiquitousKeyValueStore::set_double(double value, const std::string& a_key) const
    {
        [cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) setDouble:static_cast<double>(value) forKey:cocoon::internal::to(a_key)];
    }

    void UbiquitousKeyValueStore::set_long_long(std::int64_t value, const std::string& a_key) const
    {
        [cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) setLongLong:static_cast<long long>(value) forKey:cocoon::internal::to(a_key)];
    }

    void UbiquitousKeyValueStore::set_object(const Object& an_object, const std::string& a_key) const
    {
        [cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) setObject:cocoon::internal::native_id(an_object) forKey:cocoon::internal::to(a_key)];
    }

    void UbiquitousKeyValueStore::set_string(const std::string& a_string, const std::string& a_key) const
    {
        [cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) setString:cocoon::internal::to(a_string) forKey:cocoon::internal::to(a_key)];
    }

    std::string UbiquitousKeyValueStore::string_for_key(const std::string& a_key) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) stringForKey:cocoon::internal::to(a_key)]);
    }

    bool UbiquitousKeyValueStore::synchronize() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) synchronize]);
    }

    UbiquitousKeyValueStore UbiquitousKeyValueStore::default_store()
    {
        return cocoon::internal::wrap<UbiquitousKeyValueStore>([::NSUbiquitousKeyValueStore defaultStore]);
    }

    std::map<std::string, Object> UbiquitousKeyValueStore::dictionary_representation() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSUbiquitousKeyValueStore>(this) dictionaryRepresentation], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }
}
