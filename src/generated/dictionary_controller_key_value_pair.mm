#include "generated/dictionary_controller_key_value_pair.h"
#include "internal.h"

namespace cocoon
{
    DictionaryControllerKeyValuePair::DictionaryControllerKeyValuePair() : Object(nullptr)
    {
    }

    DictionaryControllerKeyValuePair::DictionaryControllerKeyValuePair(std::nullptr_t) : Object(nullptr)
    {
    }

    DictionaryControllerKeyValuePair::DictionaryControllerKeyValuePair(Adopt adopt) : Object(adopt)
    {
    }

    bool DictionaryControllerKeyValuePair::is_explicitly_included() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDictionaryControllerKeyValuePair>(this) isExplicitlyIncluded]);
    }

    std::string DictionaryControllerKeyValuePair::key() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDictionaryControllerKeyValuePair>(this) key]);
    }

    void DictionaryControllerKeyValuePair::set_key(const std::string& value) const
    {
        [cocoon::internal::ns<::NSDictionaryControllerKeyValuePair>(this) setKey:cocoon::internal::to(value)];
    }

    std::string DictionaryControllerKeyValuePair::localized_key() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDictionaryControllerKeyValuePair>(this) localizedKey]);
    }

    void DictionaryControllerKeyValuePair::set_localized_key(const std::string& value) const
    {
        [cocoon::internal::ns<::NSDictionaryControllerKeyValuePair>(this) setLocalizedKey:cocoon::internal::to(value)];
    }

    Object DictionaryControllerKeyValuePair::value() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSDictionaryControllerKeyValuePair>(this) value]);
    }

    void DictionaryControllerKeyValuePair::set_value(const Object& value) const
    {
        [cocoon::internal::ns<::NSDictionaryControllerKeyValuePair>(this) setValue:cocoon::internal::native_id(value)];
    }
}
