#include "generated/term_of_address.h"
#include "internal.h"

namespace cocoon
{
    TermOfAddress::TermOfAddress() : Object(nullptr)
    {
    }

    TermOfAddress::TermOfAddress(std::nullptr_t) : Object(nullptr)
    {
    }

    TermOfAddress::TermOfAddress(Adopt adopt) : Object(adopt)
    {
    }

    TermOfAddress TermOfAddress::current_user()
    {
        return cocoon::internal::wrap<TermOfAddress>([::NSTermOfAddress currentUser]);
    }

    TermOfAddress TermOfAddress::feminine()
    {
        return cocoon::internal::wrap<TermOfAddress>([::NSTermOfAddress feminine]);
    }

    TermOfAddress TermOfAddress::localized_for_language_identifier(const std::string& language, const std::vector<MorphologyPronoun>& pronouns)
    {
        return cocoon::internal::wrap<TermOfAddress>([::NSTermOfAddress localizedForLanguageIdentifier:cocoon::internal::to(language)
                                                                            withPronouns:cocoon::internal::to_array(pronouns, [](const MorphologyPronoun& e) -> id
                                                                                                      {
                                                                                                          return cocoon::internal::native<::NSMorphologyPronoun>(e);
                                                                                                      })]);
    }

    TermOfAddress TermOfAddress::masculine()
    {
        return cocoon::internal::wrap<TermOfAddress>([::NSTermOfAddress masculine]);
    }

    TermOfAddress TermOfAddress::neutral()
    {
        return cocoon::internal::wrap<TermOfAddress>([::NSTermOfAddress neutral]);
    }

    std::string TermOfAddress::language_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTermOfAddress>(this) languageIdentifier]);
    }

    std::vector<MorphologyPronoun> TermOfAddress::pronouns() const
    {
        return cocoon::internal::from_array<MorphologyPronoun>([cocoon::internal::ns<::NSTermOfAddress>(this) pronouns], [](id e) -> MorphologyPronoun
                                                 {
                                                     return cocoon::internal::wrap<MorphologyPronoun>((::NSMorphologyPronoun*)e);
                                                 });
    }
}
