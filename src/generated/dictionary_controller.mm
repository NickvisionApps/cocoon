#include "generated/dictionary_controller.h"
#include "internal.h"

namespace cocoon
{
    DictionaryController::DictionaryController() : DictionaryController(Adopt{cocoon::internal::retain([[::NSDictionaryController alloc] init])})
    {
    }

    DictionaryController::DictionaryController(std::nullptr_t) : ArrayController(nullptr)
    {
    }

    DictionaryController::DictionaryController(Adopt adopt) : ArrayController(adopt)
    {
    }

    DictionaryControllerKeyValuePair DictionaryController::new_object() const
    {
        return cocoon::internal::wrap<DictionaryControllerKeyValuePair>([cocoon::internal::ns<::NSDictionaryController>(this) newObject]);
    }

    std::vector<std::string> DictionaryController::excluded_keys() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDictionaryController>(this) excludedKeys], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    void DictionaryController::set_excluded_keys(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDictionaryController>(this) setExcludedKeys:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                             {
                                                                                 return cocoon::internal::to(e);
                                                                             })];
    }

    std::vector<std::string> DictionaryController::included_keys() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDictionaryController>(this) includedKeys], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    void DictionaryController::set_included_keys(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDictionaryController>(this) setIncludedKeys:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                             {
                                                                                 return cocoon::internal::to(e);
                                                                             })];
    }

    std::string DictionaryController::initial_key() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDictionaryController>(this) initialKey]);
    }

    void DictionaryController::set_initial_key(const std::string& value) const
    {
        [cocoon::internal::ns<::NSDictionaryController>(this) setInitialKey:cocoon::internal::to(value)];
    }

    Object DictionaryController::initial_value() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSDictionaryController>(this) initialValue]);
    }

    void DictionaryController::set_initial_value(const Object& value) const
    {
        [cocoon::internal::ns<::NSDictionaryController>(this) setInitialValue:cocoon::internal::native_id(value)];
    }

    std::map<std::string, std::string> DictionaryController::localized_key_dictionary() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::string>>([cocoon::internal::ns<::NSDictionaryController>(this) localizedKeyDictionary], [](id k) -> std::string
                                                                       {
                                                                           return cocoon::internal::from((NSString*)k);
                                                                       },
                                                                       [](id v) -> std::string
                                                                       {
                                                                           return cocoon::internal::from((NSString*)v);
                                                                       });
    }

    void DictionaryController::set_localized_key_dictionary(const std::map<std::string, std::string>& value) const
    {
        [cocoon::internal::ns<::NSDictionaryController>(this) setLocalizedKeyDictionary:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                            {
                                                                                                return cocoon::internal::to(k);
                                                                                            },
                                                                                            [](const std::string& v) -> id
                                                                                            {
                                                                                                return cocoon::internal::to(v);
                                                                                            })];
    }

    std::string DictionaryController::localized_key_table() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDictionaryController>(this) localizedKeyTable]);
    }

    void DictionaryController::set_localized_key_table(const std::string& value) const
    {
        [cocoon::internal::ns<::NSDictionaryController>(this) setLocalizedKeyTable:cocoon::internal::to(value)];
    }
}
