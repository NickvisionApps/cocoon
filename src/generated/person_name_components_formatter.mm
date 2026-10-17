#include "generated/person_name_components_formatter.h"
#include "internal.h"

namespace cocoon
{
    PersonNameComponentsFormatter::PersonNameComponentsFormatter() : PersonNameComponentsFormatter(Adopt{cocoon::internal::retain([[::NSPersonNameComponentsFormatter alloc] init])})
    {
    }

    PersonNameComponentsFormatter::PersonNameComponentsFormatter(std::nullptr_t) : Formatter(nullptr)
    {
    }

    PersonNameComponentsFormatter::PersonNameComponentsFormatter(Adopt adopt) : Formatter(adopt)
    {
    }

    AttributedString PersonNameComponentsFormatter::annotated_string_from_person_name_components(const PersonNameComponents& components) const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSPersonNameComponentsFormatter>(this) annotatedStringFromPersonNameComponents:cocoon::internal::native<::NSPersonNameComponents>(components)]);
    }

    std::string PersonNameComponentsFormatter::localized_string_from_person_name_components(const PersonNameComponents& components, PersonNameComponentsFormatterStyle name_format_style, PersonNameComponentsFormatterOptions name_options)
    {
        return cocoon::internal::from([::NSPersonNameComponentsFormatter localizedStringFromPersonNameComponents:cocoon::internal::native<::NSPersonNameComponents>(components) style:static_cast<::NSPersonNameComponentsFormatterStyle>(name_format_style) options:static_cast<::NSPersonNameComponentsFormatterOptions>(name_options)]);
    }

    PersonNameComponents PersonNameComponentsFormatter::person_name_components_from_string(const std::string& string) const
    {
        return cocoon::internal::wrap<PersonNameComponents>([cocoon::internal::ns<::NSPersonNameComponentsFormatter>(this) personNameComponentsFromString:cocoon::internal::to(string)]);
    }

    std::string PersonNameComponentsFormatter::string_from_person_name_components(const PersonNameComponents& components) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPersonNameComponentsFormatter>(this) stringFromPersonNameComponents:cocoon::internal::native<::NSPersonNameComponents>(components)]);
    }

    Locale PersonNameComponentsFormatter::locale() const
    {
        return cocoon::internal::wrap<Locale>([cocoon::internal::ns<::NSPersonNameComponentsFormatter>(this) locale]);
    }

    void PersonNameComponentsFormatter::set_locale(const Locale& value) const
    {
        [cocoon::internal::ns<::NSPersonNameComponentsFormatter>(this) setLocale:cocoon::internal::native<::NSLocale>(value)];
    }

    bool PersonNameComponentsFormatter::is_phonetic() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPersonNameComponentsFormatter>(this) isPhonetic]);
    }

    void PersonNameComponentsFormatter::set_phonetic(bool value) const
    {
        [cocoon::internal::ns<::NSPersonNameComponentsFormatter>(this) setPhonetic:static_cast<::BOOL>(value)];
    }

    PersonNameComponentsFormatterStyle PersonNameComponentsFormatter::style() const
    {
        return static_cast<PersonNameComponentsFormatterStyle>([cocoon::internal::ns<::NSPersonNameComponentsFormatter>(this) style]);
    }

    void PersonNameComponentsFormatter::set_style(PersonNameComponentsFormatterStyle value) const
    {
        [cocoon::internal::ns<::NSPersonNameComponentsFormatter>(this) setStyle:static_cast<::NSPersonNameComponentsFormatterStyle>(value)];
    }
}
