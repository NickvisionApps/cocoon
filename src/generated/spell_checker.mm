#include "generated/spell_checker.h"
#include "internal.h"

namespace cocoon
{
    SpellChecker::SpellChecker() : SpellChecker(Adopt{cocoon::internal::retain([[::NSSpellChecker alloc] init])})
    {
    }

    SpellChecker::SpellChecker(std::nullptr_t) : Object(nullptr)
    {
    }

    SpellChecker::SpellChecker(Adopt adopt) : Object(adopt)
    {
    }

    Range SpellChecker::check_grammar_of_string(const std::string& string_to_check, std::int64_t starting_offset, const std::string& language, bool wrap_flag, std::int64_t tag, std::vector<std::map<std::string, Object>>& details) const
    {
        NSArray* __v_details = nil;
        auto __r = [cocoon::internal::ns<::NSSpellChecker>(this) checkGrammarOfString:cocoon::internal::to(string_to_check) startingAt:static_cast<::NSInteger>(starting_offset) language:cocoon::internal::to(language) wrap:static_cast<::BOOL>(wrap_flag) inSpellDocumentWithTag:static_cast<::NSInteger>(tag) details:&__v_details];
        details = cocoon::internal::from_array<std::map<std::string, Object>>(__v_details, [](id e) -> std::map<std::string, Object>
                                                                              {
                                                                                  return cocoon::internal::from_dictionary<std::map<std::string, Object>>((NSDictionary*)e, [](id k) -> std::string
                                                                                                                                                          {
                                                                                                                                                              return cocoon::internal::from((NSString*)k);
                                                                                                                                                          },
                                                                                                                                                          [](id v) -> Object
                                                                                                                                                          {
                                                                                                                                                              return cocoon::internal::wrap<Object>(v);
                                                                                                                                                          });
                                                                              });
        return cocoon::internal::from(__r);
    }

    Range SpellChecker::check_spelling_of_string(const std::string& string_to_check, std::int64_t starting_offset) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSpellChecker>(this) checkSpellingOfString:cocoon::internal::to(string_to_check) startingAt:static_cast<::NSInteger>(starting_offset)]);
    }

    Range SpellChecker::check_spelling_of_string(const std::string& string_to_check, std::int64_t starting_offset, const std::string& language, bool wrap_flag, std::int64_t tag, std::int64_t* word_count) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSpellChecker>(this) checkSpellingOfString:cocoon::internal::to(string_to_check) startingAt:static_cast<::NSInteger>(starting_offset) language:cocoon::internal::to(language) wrap:static_cast<::BOOL>(wrap_flag) inSpellDocumentWithTag:static_cast<::NSInteger>(tag) wordCount:(::NSInteger*)(word_count)]);
    }

    std::vector<TextCheckingResult> SpellChecker::check_string(const std::string& string_to_check, const Range& range, std::uint64_t checking_types, const std::map<std::string, Object>& options, std::int64_t tag, Orthography& orthography, std::int64_t* word_count) const
    {
        ::NSOrthography* __v_orthography = nil;
        auto __r = [cocoon::internal::ns<::NSSpellChecker>(this) checkString:cocoon::internal::to(string_to_check)
                                                                       range:cocoon::internal::to(range)
                                                                       types:static_cast<::NSTextCheckingTypes>(checking_types)
                                                                     options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                             {
                                                                                                                 return cocoon::internal::to(k);
                                                                                                             },
                                                                                                             [](const Object& v) -> id
                                                                                                             {
                                                                                                                 return cocoon::internal::native_id(v);
                                                                                                             })
                                                      inSpellDocumentWithTag:static_cast<::NSInteger>(tag)
                                                                 orthography:&__v_orthography
                                                                   wordCount:(::NSInteger*)(word_count)];
        orthography = cocoon::internal::wrap<Orthography>(__v_orthography);
        return cocoon::internal::from_array<TextCheckingResult>(__r, [](id e) -> TextCheckingResult
                                                                {
                                                                    return cocoon::internal::wrap<TextCheckingResult>((::NSTextCheckingResult*)e);
                                                                });
    }

    void SpellChecker::close_spell_document_with_tag(std::int64_t tag) const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) closeSpellDocumentWithTag:static_cast<::NSInteger>(tag)];
    }

    std::vector<std::string> SpellChecker::completions_for_partial_word_range(const Range& range, const std::string& string, const std::string& language, std::int64_t tag) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSSpellChecker>(this) completionsForPartialWordRange:cocoon::internal::to(range) inString:cocoon::internal::to(string) language:cocoon::internal::to(language) inSpellDocumentWithTag:static_cast<::NSInteger>(tag)], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::string SpellChecker::correction_for_word_range(const Range& range, const std::string& string, const std::string& language, std::int64_t tag) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSpellChecker>(this) correctionForWordRange:cocoon::internal::to(range) inString:cocoon::internal::to(string) language:cocoon::internal::to(language) inSpellDocumentWithTag:static_cast<::NSInteger>(tag)]);
    }

    std::int64_t SpellChecker::count_words_in_string(const std::string& string_to_count, const std::string& language) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSpellChecker>(this) countWordsInString:cocoon::internal::to(string_to_count) language:cocoon::internal::to(language)]);
    }

    bool SpellChecker::deletes_autospace_between_string(const std::string& preceding_string, const std::string& following_string, const std::string& language) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSpellChecker>(this) deletesAutospaceBetweenString:cocoon::internal::to(preceding_string) andString:cocoon::internal::to(following_string) language:cocoon::internal::to(language)]);
    }

    void SpellChecker::dismiss_correction_indicator_for_view(const View& view) const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) dismissCorrectionIndicatorForView:cocoon::internal::native<::NSView>(view)];
    }

    std::vector<std::string> SpellChecker::guesses_for_word_range(const Range& range, const std::string& string, const std::string& language, std::int64_t tag) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSSpellChecker>(this) guessesForWordRange:cocoon::internal::to(range) inString:cocoon::internal::to(string) language:cocoon::internal::to(language) inSpellDocumentWithTag:static_cast<::NSInteger>(tag)], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    bool SpellChecker::has_learned_word(const std::string& word) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSpellChecker>(this) hasLearnedWord:cocoon::internal::to(word)]);
    }

#ifdef COCOON_MACOS_27
    void SpellChecker::ignore_grammar_range(const Range& grammar_range, const std::string& sentence, std::int64_t tag) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSSpellChecker>(this) ignoreGrammarRange:cocoon::internal::to(grammar_range) inSentence:cocoon::internal::to(sentence) inSpellDocumentWithTag:static_cast<::NSInteger>(tag)];
        }
    }

#endif

    void SpellChecker::ignore_word(const std::string& word_to_ignore, std::int64_t tag) const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) ignoreWord:cocoon::internal::to(word_to_ignore) inSpellDocumentWithTag:static_cast<::NSInteger>(tag)];
    }

    std::vector<std::string> SpellChecker::ignored_words_in_spell_document_with_tag(std::int64_t tag) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSSpellChecker>(this) ignoredWordsInSpellDocumentWithTag:static_cast<::NSInteger>(tag)], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::string SpellChecker::language() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSpellChecker>(this) language]);
    }

    std::string SpellChecker::language_for_word_range(const Range& range, const std::string& string, const Orthography& orthography) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSpellChecker>(this) languageForWordRange:cocoon::internal::to(range) inString:cocoon::internal::to(string) orthography:cocoon::internal::native<::NSOrthography>(orthography)]);
    }

    void SpellChecker::learn_word(const std::string& word) const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) learnWord:cocoon::internal::to(word)];
    }

    Menu SpellChecker::menu_for_result(const TextCheckingResult& result, const std::string& checked_string, const std::map<std::string, Object>& options, const Point& location, const View& view) const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSSpellChecker>(this) menuForResult:cocoon::internal::native<::NSTextCheckingResult>(result)
                                                                                                 string:cocoon::internal::to(checked_string)
                                                                                                options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                        {
                                                                                                                                            return cocoon::internal::to(k);
                                                                                                                                        },
                                                                                                                                        [](const Object& v) -> id
                                                                                                                                        {
                                                                                                                                            return cocoon::internal::native_id(v);
                                                                                                                                        })
                                                                                             atLocation:cocoon::internal::to(location)
                                                                                                 inView:cocoon::internal::native<::NSView>(view)]);
    }

    bool SpellChecker::prevents_autocorrection_before_string(const std::string& string, const std::string& language) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSpellChecker>(this) preventsAutocorrectionBeforeString:cocoon::internal::to(string) language:cocoon::internal::to(language)]);
    }

    void SpellChecker::record_response(CorrectionResponse response, const std::string& correction, const std::string& word, const std::string& language, std::int64_t tag) const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) recordResponse:static_cast<::NSCorrectionResponse>(response) toCorrection:cocoon::internal::to(correction) forWord:cocoon::internal::to(word) language:cocoon::internal::to(language) inSpellDocumentWithTag:static_cast<::NSInteger>(tag)];
    }

    std::int64_t SpellChecker::request_candidates_for_selected_range(const Range& selected_range, const std::string& string_to_check, std::uint64_t checking_types, const std::map<std::string, Object>& options, std::int64_t tag, std::function<void(std::int64_t, std::vector<TextCheckingResult>)> completion_handler) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSpellChecker>(this) requestCandidatesForSelectedRange:cocoon::internal::to(selected_range)
                                                                                                                inString:cocoon::internal::to(string_to_check)
                                                                                                                   types:static_cast<::NSTextCheckingTypes>(checking_types)
                                                                                                                 options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                                         {
                                                                                                                                                             return cocoon::internal::to(k);
                                                                                                                                                         },
                                                                                                                                                         [](const Object& v) -> id
                                                                                                                                                         {
                                                                                                                                                             return cocoon::internal::native_id(v);
                                                                                                                                                         })
                                                                                                  inSpellDocumentWithTag:static_cast<::NSInteger>(tag)
                                                                                                       completionHandler:(completion_handler ? (void (^)(::NSInteger, NSArray<NSTextCheckingResult*>*)) ^ void(::NSInteger a79_0, NSArray * a79_1) { completion_handler(static_cast<std::int64_t>(a79_0), cocoon::internal::from_array<TextCheckingResult>(a79_1, [](id e) -> TextCheckingResult
                                                                                                                                                                                                                                                                                                                                                           {
                                                                                                                                                                                                                                                                                                                                                               return cocoon::internal::wrap<TextCheckingResult>((::NSTextCheckingResult*)e);
                                                                                                                                                                                                                                                                                                                                                           })); } : (void (^)(::NSInteger, NSArray<NSTextCheckingResult*>*))nil)]);
    }

    std::int64_t SpellChecker::request_checking_of_string(const std::string& string_to_check, const Range& range, std::uint64_t checking_types, const std::map<std::string, Object>& options, std::int64_t tag, std::function<void(std::int64_t, std::vector<TextCheckingResult>, Orthography, std::int64_t)> completion_handler) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSpellChecker>(this) requestCheckingOfString:cocoon::internal::to(string_to_check)
                                                                                                         range:cocoon::internal::to(range)
                                                                                                         types:static_cast<::NSTextCheckingTypes>(checking_types)
                                                                                                       options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                               {
                                                                                                                                                   return cocoon::internal::to(k);
                                                                                                                                               },
                                                                                                                                               [](const Object& v) -> id
                                                                                                                                               {
                                                                                                                                                   return cocoon::internal::native_id(v);
                                                                                                                                               })
                                                                                        inSpellDocumentWithTag:static_cast<::NSInteger>(tag)
                                                                                             completionHandler:(completion_handler ? (void (^)(::NSInteger, NSArray<NSTextCheckingResult*>*, ::NSOrthography*, ::NSInteger)) ^ void(::NSInteger a80_0, NSArray * a80_1, ::NSOrthography * a80_2, ::NSInteger a80_3) { completion_handler(static_cast<std::int64_t>(a80_0), cocoon::internal::from_array<TextCheckingResult>(a80_1, [](id e) -> TextCheckingResult
                                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                                                return cocoon::internal::wrap<TextCheckingResult>((::NSTextCheckingResult*)e);
                                                                                                                                                                                                                                                                                                                                                                                                                            }),
                                                                                                                                                                                                                                                                                                                                         cocoon::internal::wrap<Orthography>(a80_2), static_cast<std::int64_t>(a80_3)); } : (void (^)(::NSInteger, NSArray<NSTextCheckingResult*>*, ::NSOrthography*, ::NSInteger))nil)]);
    }

    void SpellChecker::set_ignored_words(const std::vector<std::string>& words, std::int64_t tag) const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) setIgnoredWords:cocoon::internal::to_array(words, [](const std::string& e) -> id
                                                                                                 {
                                                                                                     return cocoon::internal::to(e);
                                                                                                 })
                                               inSpellDocumentWithTag:static_cast<::NSInteger>(tag)];
    }

    bool SpellChecker::set_language(const std::string& language) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSpellChecker>(this) setLanguage:cocoon::internal::to(language)]);
    }

    void SpellChecker::set_word_field_string_value(const std::string& string) const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) setWordFieldStringValue:cocoon::internal::to(string)];
    }

    void SpellChecker::show_correction_indicator_of_type(CorrectionIndicatorType type, const std::string& primary_string, const std::vector<std::string>& alternative_strings, const Rect& rect_of_typed_string, const View& view, std::function<void(std::string)> completion_block) const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) showCorrectionIndicatorOfType:static_cast<::NSCorrectionIndicatorType>(type)
                                                                      primaryString:cocoon::internal::to(primary_string)
                                                                 alternativeStrings:cocoon::internal::to_array(alternative_strings, [](const std::string& e) -> id
                                                                                                               {
                                                                                                                   return cocoon::internal::to(e);
                                                                                                               })
                                                                    forStringInRect:cocoon::internal::to(rect_of_typed_string)
                                                                               view:cocoon::internal::native<::NSView>(view)
                                                                  completionHandler:(completion_block ? (void (^)(::NSString*)) ^ void(NSString * a81_0) { completion_block(cocoon::internal::from(a81_0)); } : (void (^)(::NSString*))nil)];
    }

    void SpellChecker::show_inline_prediction_for_candidates(const std::vector<TextCheckingResult>& candidates, const Object& client) const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) showInlinePredictionForCandidates:cocoon::internal::to_array(candidates, [](const TextCheckingResult& e) -> id
                                                                                                                   {
                                                                                                                       return cocoon::internal::native<::NSTextCheckingResult>(e);
                                                                                                                   })
                                                                                 client:cocoon::internal::native_id(client)];
    }

    std::int64_t SpellChecker::unique_spell_document_tag()
    {
        return static_cast<std::int64_t>([::NSSpellChecker uniqueSpellDocumentTag]);
    }

    void SpellChecker::unlearn_word(const std::string& word) const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) unlearnWord:cocoon::internal::to(word)];
    }

    void SpellChecker::update_panels() const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) updatePanels];
    }

    void SpellChecker::update_spelling_panel_with_grammar_string(const std::string& string, const std::map<std::string, Object>& detail) const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) updateSpellingPanelWithGrammarString:cocoon::internal::to(string)
                                                                                    detail:cocoon::internal::to_dictionary(detail, [](const std::string& k) -> id
                                                                                                                           {
                                                                                                                               return cocoon::internal::to(k);
                                                                                                                           },
                                                                                                                           [](const Object& v) -> id
                                                                                                                           {
                                                                                                                               return cocoon::internal::native_id(v);
                                                                                                                           })];
    }

    void SpellChecker::update_spelling_panel_with_misspelled_word(const std::string& word) const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) updateSpellingPanelWithMisspelledWord:cocoon::internal::to(word)];
    }

    std::vector<std::string> SpellChecker::user_quotes_array_for_language(const std::string& language) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSSpellChecker>(this) userQuotesArrayForLanguage:cocoon::internal::to(language)], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    View SpellChecker::accessory_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSSpellChecker>(this) accessoryView]);
    }

    void SpellChecker::set_accessory_view(const View& value) const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) setAccessoryView:cocoon::internal::native<::NSView>(value)];
    }

    bool SpellChecker::is_automatic_capitalization_enabled()
    {
        return static_cast<bool>([::NSSpellChecker isAutomaticCapitalizationEnabled]);
    }

    bool SpellChecker::is_automatic_dash_substitution_enabled()
    {
        return static_cast<bool>([::NSSpellChecker isAutomaticDashSubstitutionEnabled]);
    }

    bool SpellChecker::is_automatic_inline_prediction_enabled()
    {
        return static_cast<bool>([::NSSpellChecker isAutomaticInlinePredictionEnabled]);
    }

    bool SpellChecker::is_automatic_period_substitution_enabled()
    {
        return static_cast<bool>([::NSSpellChecker isAutomaticPeriodSubstitutionEnabled]);
    }

    bool SpellChecker::is_automatic_quote_substitution_enabled()
    {
        return static_cast<bool>([::NSSpellChecker isAutomaticQuoteSubstitutionEnabled]);
    }

    bool SpellChecker::is_automatic_spelling_correction_enabled()
    {
        return static_cast<bool>([::NSSpellChecker isAutomaticSpellingCorrectionEnabled]);
    }

    bool SpellChecker::is_automatic_text_completion_enabled()
    {
        return static_cast<bool>([::NSSpellChecker isAutomaticTextCompletionEnabled]);
    }

    bool SpellChecker::is_automatic_text_replacement_enabled()
    {
        return static_cast<bool>([::NSSpellChecker isAutomaticTextReplacementEnabled]);
    }

    bool SpellChecker::automatically_identifies_languages() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSpellChecker>(this) automaticallyIdentifiesLanguages]);
    }

    void SpellChecker::set_automatically_identifies_languages(bool value) const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) setAutomaticallyIdentifiesLanguages:static_cast<::BOOL>(value)];
    }

    std::vector<std::string> SpellChecker::available_languages() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSSpellChecker>(this) availableLanguages], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    SpellChecker SpellChecker::shared_spell_checker()
    {
        return cocoon::internal::wrap<SpellChecker>([::NSSpellChecker sharedSpellChecker]);
    }

    bool SpellChecker::shared_spell_checker_exists()
    {
        return static_cast<bool>([::NSSpellChecker sharedSpellCheckerExists]);
    }

    Panel SpellChecker::spelling_panel() const
    {
        return cocoon::internal::wrap<Panel>([cocoon::internal::ns<::NSSpellChecker>(this) spellingPanel]);
    }

    Panel SpellChecker::substitutions_panel() const
    {
        return cocoon::internal::wrap<Panel>([cocoon::internal::ns<::NSSpellChecker>(this) substitutionsPanel]);
    }

    ViewController SpellChecker::substitutions_panel_accessory_view_controller() const
    {
        return cocoon::internal::wrap<ViewController>([cocoon::internal::ns<::NSSpellChecker>(this) substitutionsPanelAccessoryViewController]);
    }

    void SpellChecker::set_substitutions_panel_accessory_view_controller(const ViewController& value) const
    {
        [cocoon::internal::ns<::NSSpellChecker>(this) setSubstitutionsPanelAccessoryViewController:cocoon::internal::native<::NSViewController>(value)];
    }

    std::vector<std::string> SpellChecker::user_preferred_languages() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSSpellChecker>(this) userPreferredLanguages], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::map<std::string, std::string> SpellChecker::user_replacements_dictionary() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::string>>([cocoon::internal::ns<::NSSpellChecker>(this) userReplacementsDictionary], [](id k) -> std::string
                                                                                     {
                                                                                         return cocoon::internal::from((NSString*)k);
                                                                                     },
                                                                                     [](id v) -> std::string
                                                                                     {
                                                                                         return cocoon::internal::from((NSString*)v);
                                                                                     });
    }
}
