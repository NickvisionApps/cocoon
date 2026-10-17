#include "generated/text_alternatives.h"
#include "internal.h"

namespace cocoon
{
    TextAlternatives::TextAlternatives(const std::string& primary_string, const std::vector<std::string>& alternative_strings) : TextAlternatives(Adopt{cocoon::internal::retain([[::NSTextAlternatives alloc] initWithPrimaryString:cocoon::internal::to(primary_string)
                                                                                                                                                                                                                  alternativeStrings:cocoon::internal::to_array(alternative_strings, [](const std::string& e) -> id
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                    return cocoon::internal::to(e);
                                                                                                                                                                                                                                                                })])})
    {
    }

    TextAlternatives::TextAlternatives() : TextAlternatives(Adopt{cocoon::internal::retain([[::NSTextAlternatives alloc] init])})
    {
    }

    TextAlternatives::TextAlternatives(std::nullptr_t) : Object(nullptr)
    {
    }

    TextAlternatives::TextAlternatives(Adopt adopt) : Object(adopt)
    {
    }

    void TextAlternatives::note_selected_alternative_string(const std::string& alternative_string) const
    {
        [cocoon::internal::ns<::NSTextAlternatives>(this) noteSelectedAlternativeString:cocoon::internal::to(alternative_string)];
    }

    std::vector<std::string> TextAlternatives::alternative_strings() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTextAlternatives>(this) alternativeStrings], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::string TextAlternatives::primary_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextAlternatives>(this) primaryString]);
    }
}
