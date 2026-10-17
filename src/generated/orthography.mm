#include "generated/orthography.h"
#include "internal.h"

namespace cocoon
{
    Orthography::Orthography(const std::string& script, const std::map<std::string, std::vector<std::string>>& map) : Orthography(Adopt{cocoon::internal::retain([[::NSOrthography alloc] initWithDominantScript:cocoon::internal::to(script)
                                                                                                                                                                                       languageMap:cocoon::internal::to_dictionary(map, [](const std::string& k) -> id
                                                                                                                                                                                                                     {
                                                                                                                                                                                                                         return cocoon::internal::to(k);
                                                                                                                                                                                                                     },
                                                                                                                                                                                                                     [](const std::vector<std::string>& v) -> id
                                                                                                                                                                                                                     {
                                                                                                                                                                                                                         return cocoon::internal::to_array(v, [](const std::string& e) -> id
                                                                                                                                                                                                                                             {
                                                                                                                                                                                                                                                 return cocoon::internal::to(e);
                                                                                                                                                                                                                                             });
                                                                                                                                                                                                                     })])})
    {
    }

    Orthography::Orthography() : Orthography(Adopt{cocoon::internal::retain([[::NSOrthography alloc] init])})
    {
    }

    Orthography::Orthography(std::nullptr_t) : Object(nullptr)
    {
    }

    Orthography::Orthography(Adopt adopt) : Object(adopt)
    {
    }

    Orthography Orthography::default_orthography_for_language(const std::string& language)
    {
        return cocoon::internal::wrap<Orthography>([::NSOrthography defaultOrthographyForLanguage:cocoon::internal::to(language)]);
    }

    std::string Orthography::dominant_language_for_script(const std::string& script) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSOrthography>(this) dominantLanguageForScript:cocoon::internal::to(script)]);
    }

    std::vector<std::string> Orthography::languages_for_script(const std::string& script) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSOrthography>(this) languagesForScript:cocoon::internal::to(script)], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    Orthography Orthography::orthography_with_dominant_script(const std::string& script, const std::map<std::string, std::vector<std::string>>& map)
    {
        return cocoon::internal::wrap<Orthography>([::NSOrthography orthographyWithDominantScript:cocoon::internal::to(script)
                                                                        languageMap:cocoon::internal::to_dictionary(map, [](const std::string& k) -> id
                                                                                                      {
                                                                                                          return cocoon::internal::to(k);
                                                                                                      },
                                                                                                      [](const std::vector<std::string>& v) -> id
                                                                                                      {
                                                                                                          return cocoon::internal::to_array(v, [](const std::string& e) -> id
                                                                                                                              {
                                                                                                                                  return cocoon::internal::to(e);
                                                                                                                              });
                                                                                                      })]);
    }

    std::vector<std::string> Orthography::all_languages() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSOrthography>(this) allLanguages], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Orthography::all_scripts() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSOrthography>(this) allScripts], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::string Orthography::dominant_language() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSOrthography>(this) dominantLanguage]);
    }

    std::string Orthography::dominant_script() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSOrthography>(this) dominantScript]);
    }

    std::map<std::string, std::vector<std::string>> Orthography::language_map() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::vector<std::string>>>([cocoon::internal::ns<::NSOrthography>(this) languageMap], [](id k) -> std::string
                                                                                    {
                                                                                        return cocoon::internal::from((NSString*)k);
                                                                                    },
                                                                                    [](id v) -> std::vector<std::string>
                                                                                    {
                                                                                        return cocoon::internal::from_array<std::string>((NSArray*)v, [](id e) -> std::string
                                                                                                                           {
                                                                                                                               return cocoon::internal::from((NSString*)e);
                                                                                                                           });
                                                                                    });
    }
}
