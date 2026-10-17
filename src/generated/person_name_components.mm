#include "generated/person_name_components.h"
#include "internal.h"

namespace cocoon
{
    PersonNameComponents::PersonNameComponents() : PersonNameComponents(Adopt{cocoon::internal::retain([[::NSPersonNameComponents alloc] init])})
    {
    }

    PersonNameComponents::PersonNameComponents(std::nullptr_t) : Object(nullptr)
    {
    }

    PersonNameComponents::PersonNameComponents(Adopt adopt) : Object(adopt)
    {
    }

    std::string PersonNameComponents::family_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPersonNameComponents>(this) familyName]);
    }

    void PersonNameComponents::set_family_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPersonNameComponents>(this) setFamilyName:cocoon::internal::to(value)];
    }

    std::string PersonNameComponents::given_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPersonNameComponents>(this) givenName]);
    }

    void PersonNameComponents::set_given_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPersonNameComponents>(this) setGivenName:cocoon::internal::to(value)];
    }

    std::string PersonNameComponents::middle_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPersonNameComponents>(this) middleName]);
    }

    void PersonNameComponents::set_middle_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPersonNameComponents>(this) setMiddleName:cocoon::internal::to(value)];
    }

    std::string PersonNameComponents::name_prefix() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPersonNameComponents>(this) namePrefix]);
    }

    void PersonNameComponents::set_name_prefix(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPersonNameComponents>(this) setNamePrefix:cocoon::internal::to(value)];
    }

    std::string PersonNameComponents::name_suffix() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPersonNameComponents>(this) nameSuffix]);
    }

    void PersonNameComponents::set_name_suffix(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPersonNameComponents>(this) setNameSuffix:cocoon::internal::to(value)];
    }

    std::string PersonNameComponents::nickname() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPersonNameComponents>(this) nickname]);
    }

    void PersonNameComponents::set_nickname(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPersonNameComponents>(this) setNickname:cocoon::internal::to(value)];
    }

    PersonNameComponents PersonNameComponents::phonetic_representation() const
    {
        return cocoon::internal::wrap<PersonNameComponents>([cocoon::internal::ns<::NSPersonNameComponents>(this) phoneticRepresentation]);
    }

    void PersonNameComponents::set_phonetic_representation(const PersonNameComponents& value) const
    {
        [cocoon::internal::ns<::NSPersonNameComponents>(this) setPhoneticRepresentation:cocoon::internal::native<::NSPersonNameComponents>(value)];
    }
}
