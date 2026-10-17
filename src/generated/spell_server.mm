#include "generated/spell_server.h"
#include "internal.h"

@interface AKSpellServerDelegate : NSObject <NSSpellServerDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKSpellServerDelegate

- (NSRange)spellServer:(NSSpellServer*)sender findMisspelledWordInString:(NSString*)stringToCheck language:(NSString*)language wordCount:(NSInteger*)wordCount countOnly:(BOOL)countOnly
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SpellServer, cocoon::Range(std::string, std::string, std::int64_t*, bool)>::emit((__bridge void*)strongHost, "find_misspelled_word_in_string_language_word_count_count_only", cocoon::internal::from(stringToCheck), cocoon::internal::from(language), (std::int64_t*)(wordCount), static_cast<bool>(countOnly));
    return cocoon::internal::to(__r);
}

- (NSArray<NSString*>*)spellServer:(NSSpellServer*)sender suggestGuessesForWord:(NSString*)word inLanguage:(NSString*)language
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SpellServer, std::vector<std::string>(std::string, std::string)>::emit((__bridge void*)strongHost, "suggest_guesses_for_word_in_language", cocoon::internal::from(word), cocoon::internal::from(language));
    return cocoon::internal::to_array(__r, [](const std::string& e) -> id
                                      {
                                          return cocoon::internal::to(e);
                                      });
}

- (void)spellServer:(NSSpellServer*)sender didLearnWord:(NSString*)word inLanguage:(NSString*)language
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SpellServer, void(std::string, std::string)>::emit((__bridge void*)strongHost, "did_learn_word_in_language", cocoon::internal::from(word), cocoon::internal::from(language));
}

- (void)spellServer:(NSSpellServer*)sender didForgetWord:(NSString*)word inLanguage:(NSString*)language
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SpellServer, void(std::string, std::string)>::emit((__bridge void*)strongHost, "did_forget_word_in_language", cocoon::internal::from(word), cocoon::internal::from(language));
}

- (NSArray<NSString*>*)spellServer:(NSSpellServer*)sender suggestCompletionsForPartialWordRange:(NSRange)range inString:(NSString*)string language:(NSString*)language
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SpellServer, std::vector<std::string>(cocoon::Range, std::string, std::string)>::emit((__bridge void*)strongHost, "suggest_completions_for_partial_word_range_in_string_language", cocoon::internal::from(range), cocoon::internal::from(string), cocoon::internal::from(language));
    return cocoon::internal::to_array(__r, [](const std::string& e) -> id
                                      {
                                          return cocoon::internal::to(e);
                                      });
}

- (NSRange)spellServer:(NSSpellServer*)sender checkGrammarInString:(NSString*)stringToCheck language:(NSString*)language details:(NSArray<NSDictionary<NSString*, id>*>**)details
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    std::vector<std::map<std::string, cocoon::Object>> __v_details = details ? cocoon::internal::from_array<std::map<std::string, cocoon::Object>>(*details, [](id e) -> std::map<std::string, cocoon::Object>
                                                                                                                                                   {
                                                                                                                                                       return cocoon::internal::from_dictionary<std::map<std::string, cocoon::Object>>((NSDictionary*)e, [](id k) -> std::string
                                                                                                                                                                                                                                       {
                                                                                                                                                                                                                                           return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                       },
                                                                                                                                                                                                                                       [](id v) -> cocoon::Object
                                                                                                                                                                                                                                       {
                                                                                                                                                                                                                                           return cocoon::internal::wrap<cocoon::Object>(v);
                                                                                                                                                                                                                                       });
                                                                                                                                                   })
                                                                             : std::vector<std::map<std::string, cocoon::Object>>();
    auto __r = cocoon::Signal<cocoon::SpellServer, cocoon::Range(std::string, std::string, std::vector<std::map<std::string, cocoon::Object>>&)>::emit((__bridge void*)strongHost, "check_grammar_in_string_language_details", cocoon::internal::from(stringToCheck), cocoon::internal::from(language), __v_details);
    if (details)
    {
        *details = cocoon::internal::to_array(__v_details, [](const std::map<std::string, cocoon::Object>& e) -> id
                                              {
                                                  return cocoon::internal::to_dictionary(e, [](const std::string& k) -> id
                                                                                         {
                                                                                             return cocoon::internal::to(k);
                                                                                         },
                                                                                         [](const cocoon::Object& v) -> id
                                                                                         {
                                                                                             return cocoon::internal::native_id(v);
                                                                                         });
                                              });
    }
    return cocoon::internal::to(__r);
}

- (NSArray<NSTextCheckingResult*>*)spellServer:(NSSpellServer*)sender checkString:(NSString*)stringToCheck offset:(NSUInteger)offset types:(NSTextCheckingTypes)checkingTypes options:(NSDictionary<NSString*, id>*)options orthography:(NSOrthography*)orthography wordCount:(NSInteger*)wordCount
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SpellServer, std::vector<cocoon::TextCheckingResult>(std::string, std::uint64_t, std::uint64_t, std::map<std::string, cocoon::Object>, cocoon::Orthography, std::int64_t*)>::emit((__bridge void*)strongHost, "check_string_offset_types_options_orthography_word_count", cocoon::internal::from(stringToCheck), static_cast<std::uint64_t>(offset), static_cast<std::uint64_t>(checkingTypes), cocoon::internal::from_dictionary<std::map<std::string, cocoon::Object>>(options, [](id k) -> std::string
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               },
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               [](id v) -> cocoon::Object
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   return cocoon::internal::wrap<cocoon::Object>(v);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               }),
                                                                                                                                                                                                                        cocoon::internal::wrap<cocoon::Orthography>(orthography), (std::int64_t*)(wordCount));
    return cocoon::internal::to_array(__r, [](const cocoon::TextCheckingResult& e) -> id
                                      {
                                          return cocoon::internal::native<::NSTextCheckingResult>(e);
                                      });
}

- (void)spellServer:(NSSpellServer*)sender recordResponse:(NSUInteger)response toCorrection:(NSString*)correction forWord:(NSString*)word language:(NSString*)language
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SpellServer, void(std::uint64_t, std::string, std::string, std::string)>::emit((__bridge void*)strongHost, "record_response_to_correction_for_word_language", static_cast<std::uint64_t>(response), cocoon::internal::from(correction), cocoon::internal::from(word), cocoon::internal::from(language));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(spellServer:findMisspelledWordInString:language:wordCount:countOnly:))
    {
        return strongHost && cocoon::Signal<cocoon::SpellServer, cocoon::Range(std::string, std::string, std::int64_t*, bool)>::connected((__bridge void*)strongHost, "find_misspelled_word_in_string_language_word_count_count_only");
    }
    if (selector == @selector(spellServer:suggestGuessesForWord:inLanguage:))
    {
        return strongHost && cocoon::Signal<cocoon::SpellServer, std::vector<std::string>(std::string, std::string)>::connected((__bridge void*)strongHost, "suggest_guesses_for_word_in_language");
    }
    if (selector == @selector(spellServer:didLearnWord:inLanguage:))
    {
        return strongHost && cocoon::Signal<cocoon::SpellServer, void(std::string, std::string)>::connected((__bridge void*)strongHost, "did_learn_word_in_language");
    }
    if (selector == @selector(spellServer:didForgetWord:inLanguage:))
    {
        return strongHost && cocoon::Signal<cocoon::SpellServer, void(std::string, std::string)>::connected((__bridge void*)strongHost, "did_forget_word_in_language");
    }
    if (selector == @selector(spellServer:suggestCompletionsForPartialWordRange:inString:language:))
    {
        return strongHost && cocoon::Signal<cocoon::SpellServer, std::vector<std::string>(cocoon::Range, std::string, std::string)>::connected((__bridge void*)strongHost, "suggest_completions_for_partial_word_range_in_string_language");
    }
    if (selector == @selector(spellServer:checkGrammarInString:language:details:))
    {
        return strongHost && cocoon::Signal<cocoon::SpellServer, cocoon::Range(std::string, std::string, std::vector<std::map<std::string, cocoon::Object>>&)>::connected((__bridge void*)strongHost, "check_grammar_in_string_language_details");
    }
    if (selector == @selector(spellServer:checkString:offset:types:options:orthography:wordCount:))
    {
        return strongHost && cocoon::Signal<cocoon::SpellServer, std::vector<cocoon::TextCheckingResult>(std::string, std::uint64_t, std::uint64_t, std::map<std::string, cocoon::Object>, cocoon::Orthography, std::int64_t*)>::connected((__bridge void*)strongHost, "check_string_offset_types_options_orthography_word_count");
    }
    if (selector == @selector(spellServer:recordResponse:toCorrection:forWord:language:))
    {
        return strongHost && cocoon::Signal<cocoon::SpellServer, void(std::uint64_t, std::string, std::string, std::string)>::connected((__bridge void*)strongHost, "record_response_to_correction_for_word_language");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    SpellServer::SpellServer() : SpellServer(Adopt{cocoon::internal::retain([[::NSSpellServer alloc] init])})
    {
        SpellServer::install_delegate_delegate_(handle());
    }

    SpellServer::SpellServer(std::nullptr_t) : Object(nullptr)
    {
    }

    SpellServer::SpellServer(Adopt adopt) : Object(adopt)
    {
    }

    bool SpellServer::is_word_in_user_dictionaries(const std::string& word, bool flag) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSpellServer>(this) isWordInUserDictionaries:cocoon::internal::to(word) caseSensitive:static_cast<::BOOL>(flag)]);
    }

    bool SpellServer::register_language(const std::string& language, const std::string& vendor) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSpellServer>(this) registerLanguage:cocoon::internal::to(language) byVendor:cocoon::internal::to(vendor)]);
    }

    void SpellServer::run() const
    {
        [cocoon::internal::ns<::NSSpellServer>(this) run];
    }

    void SpellServer::install_delegate_delegate_(void* native)
    {
        ::NSSpellServer* host = (__bridge ::NSSpellServer*)native;
        AKSpellServerDelegate* delegate = [[AKSpellServerDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSSpellServer* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSSpellServer* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
