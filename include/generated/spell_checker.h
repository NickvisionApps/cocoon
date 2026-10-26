#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Menu;
    class Orthography;
    class Panel;
    class TextCheckingResult;
    class View;
    class ViewController;

    /**
     * @brief C++ handle for the Objective-C class `NSSpellChecker` (AppKit).
     * @details The NSSpellChecker object is used by a client (e.g. a document in an application) to spell-check a given NSString. There is only one NSSpellChecker instance per application (since spell-checking is interactive and you only have one mouse and one keyboard). The string being spell-checked need only be valid for the duration of the call to checkSpellingOfString:... or countWordsInString:. The usual usage of this is to implement a checkSpelling: method in an object that has text to check, then, upon receiving checkSpelling:, the object calls [[NSSpellChecker sharedInstance] checkSpellingOfString:...] with an NSString object consisting of the text that should be checked. The caller is responsible for selecting the misspelled word that is found and for updating the panel UI if desired with the updateSpellPanelWithMisspelledWord: method.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SpellChecker spell_checker;
     * spell_checker.set_accessory_view(cocoon::View());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SpellChecker spell_checker{};
     * spell_checker.set_accessory_view(cocoon::View());
     * auto accessory_view = spell_checker.accessory_view();
     * spell_checker.set_automatically_identifies_languages(true);
     * auto automatically_identifies_languages = spell_checker.automatically_identifies_languages();
     * spell_checker.set_substitutions_panel_accessory_view_controller(cocoon::ViewController());
     * auto substitutions_panel_accessory_view_controller = spell_checker.substitutions_panel_accessory_view_controller();
     * spell_checker.check_spelling_of_string("text", 1);
     * spell_checker.close_spell_document_with_tag(1);
     * spell_checker.count_words_in_string("text", "text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsspellchecker
     */
    class SpellChecker : public Object
    {
    public:
        /// @brief Creates a new `NSSpellChecker` instance and returns a handle to it.
        explicit SpellChecker();
        /// @brief Creates a null handle that refers to no native object.
        SpellChecker(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SpellChecker(Adopt adopt);
        /**
         * @brief Calls `-[NSSpellChecker checkGrammarOfString:startingAt:language:wrap:inSpellDocumentWithTag:details:]`.
         * @details Initiates a grammar-check of a string. Returns the range of the first flagged sentence (or similar grammatical unit), and optionally an array of dictionaries describing details within this sentence. Keys in the details dictionaries are described in Foundation/NSSpellServer.h.
         * @param string_to_check Argument converted to the Objective-C parameter of the same role.
         * @param starting_offset Argument converted to the Objective-C parameter of the same role.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @param wrap_flag Argument converted to the Objective-C parameter of the same role.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         * @param details Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range check_grammar_of_string(const std::string& string_to_check, std::int64_t starting_offset, const std::string& language, bool wrap_flag, std::int64_t tag, std::vector<std::map<std::string, Object>>& details) const;
        /**
         * @brief Calls `-[NSSpellChecker checkSpellingOfString:startingAt:]`.
         * @param string_to_check Argument converted to the Objective-C parameter of the same role.
         * @param starting_offset Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range check_spelling_of_string(const std::string& string_to_check, std::int64_t starting_offset) const;
        /**
         * @brief Calls `-[NSSpellChecker checkSpellingOfString:startingAt:language:wrap:inSpellDocumentWithTag:wordCount:]`.
         * @details Initiates a spell-check of a string. Returns the range of the first misspelled word (and optionally the wordCount by reference).
         * @param string_to_check Argument converted to the Objective-C parameter of the same role.
         * @param starting_offset Argument converted to the Objective-C parameter of the same role.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @param wrap_flag Argument converted to the Objective-C parameter of the same role.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         * @param word_count Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range check_spelling_of_string(const std::string& string_to_check, std::int64_t starting_offset, const std::string& language, bool wrap_flag, std::int64_t tag, std::int64_t* word_count) const;
        /**
         * @brief Calls `-[NSSpellChecker checkString:range:types:options:inSpellDocumentWithTag:orthography:wordCount:]`.
         * @details Requests unified text checking for the given range of the given string. The checkingTypes should be a bitmask of checking types from NSTextCheckingResult.h, describing which types of checking are desired. The options dictionary allows clients to pass in options for certain types of checking. The orthography and wordCount arguments will return by reference these two attributes of the range as a whole, while the return value is an array of NSTextCheckingResult objects describing particular items found during checking and their individual ranges, sorted by range origin, then range end, then result type.
         * @param string_to_check Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param checking_types Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         * @param orthography Argument converted to the Objective-C parameter of the same role.
         * @param word_count Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<TextCheckingResult> check_string(const std::string& string_to_check, const Range& range, std::uint64_t checking_types, const std::map<std::string, Object>& options, std::int64_t tag, Orthography& orthography, std::int64_t* word_count) const;
        /**
         * @brief Calls `-[NSSpellChecker closeSpellDocumentWithTag:]`.
         * @details When a document closes, it should notify the NSSpellChecker via closeSpellDocumentWithTag: so that any associated data such as its ignored word list can be cleaned up.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         */
        void close_spell_document_with_tag(std::int64_t tag) const;
        /**
         * @brief Calls `-[NSSpellChecker completionsForPartialWordRange:inString:language:inSpellDocumentWithTag:]`.
         * @details Returns an array of strings, in the order in which they should be presented, representing complete words that the user might be trying to type when starting by typing the partial word at the given range in the given string.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> completions_for_partial_word_range(const Range& range, const std::string& string, const std::string& language, std::int64_t tag) const;
        /**
         * @brief Calls `-[NSSpellChecker correctionForWordRange:inString:language:inSpellDocumentWithTag:]`.
         * @details If a word is misspelled, this will return a single proposed correction, if one is available. Correction functionality is available starting in 10.6 as part of unified text checking, but for convenience this method makes it available separately starting in 10.7.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string correction_for_word_range(const Range& range, const std::string& string, const std::string& language, std::int64_t tag) const;
        /**
         * @brief Calls `-[NSSpellChecker countWordsInString:language:]`.
         * @details Just counts the words without checking spelling. Returns -1 if counting words isn't supported by the spell server selected.
         * @param string_to_count Argument converted to the Objective-C parameter of the same role.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t count_words_in_string(const std::string& string_to_count, const std::string& language) const;
        /**
         * @brief Calls `-[NSSpellChecker deletesAutospaceBetweenString:andString:language:]`.
         * @details In some cases the space automatically inserted after an accepted candidate should be deleted when the next text is typed (e.g. if it is a period or comma). This method allows clients to recognize these cases in a standardized way.
         * @param preceding_string Argument converted to the Objective-C parameter of the same role.
         * @param following_string Argument converted to the Objective-C parameter of the same role.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool deletes_autospace_between_string(const std::string& preceding_string, const std::string& following_string, const std::string& language) const;
        /**
         * @brief Calls `-[NSSpellChecker dismissCorrectionIndicatorForView:]`.
         * @param view Argument converted to the Objective-C parameter of the same role.
         */
        void dismiss_correction_indicator_for_view(const View& view) const;
        /**
         * @brief Calls `-[NSSpellChecker guessesForWordRange:inString:language:inSpellDocumentWithTag:]`.
         * @details This method returns multiple proposed alternatives for a given word, whether it is misspelled or not, in the order in which they should be presented.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> guesses_for_word_range(const Range& range, const std::string& string, const std::string& language, std::int64_t tag) const;
        /**
         * @brief Calls `-[NSSpellChecker hasLearnedWord:]`.
         * @param word Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool has_learned_word(const std::string& word) const;
        /**
         * @brief Calls `-[NSSpellChecker ignoreWord:inSpellDocumentWithTag:]`.
         * @details This method should be called from the client's implementation of -ignoreSpelling:
         * @param word_to_ignore Argument converted to the Objective-C parameter of the same role.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         */
        void ignore_word(const std::string& word_to_ignore, std::int64_t tag) const;
        /**
         * @brief Calls `-[NSSpellChecker ignoredWordsInSpellDocumentWithTag:]`.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> ignored_words_in_spell_document_with_tag(std::int64_t tag) const;
        /**
         * @brief Calls `-[NSSpellChecker language]`.
         * @details Use of the following methods is discouraged; ordinarily language identification should be allowed to take place automatically, or else a specific language should be passed in to the methods that take such an argument, if the language is known in advance. -setLanguage: allows programmatic setting of the language to spell-check in, for compatibility use if other methods are called with no language specified. -setLanguage: accepts any of the language formats used by NSBundle, and tries to find the closest match among the available languages. If -setLanguage: has been called, then -language will return that match; otherwise, it will return Multilingual if there is more than one element in -userPreferredLanguages, or the one element in that array if there is only one.
         * @return The converted Objective-C result.
         */
        std::string language() const;
        /**
         * @brief Calls `-[NSSpellChecker languageForWordRange:inString:orthography:]`.
         * @details Clients who have an NSOrthography from NSTextCheckingTypeOrthography checking and wish to determine a specific language from it for a particular word, for example to pass in to -guessesForWordRange:inString:language:inSpellDocumentWithTag:, -correctionForWordRange:inString:language:inSpellDocumentWithTag:, or -completionsForPartialWordRange:inString:language:inSpellDocumentWithTag:, should use this method to obtain it.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param orthography Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string language_for_word_range(const Range& range, const std::string& string, const Orthography& orthography) const;
        /**
         * @brief Calls `-[NSSpellChecker learnWord:]`.
         * @details These allow clients to programmatically instruct the spellchecker to learn and unlearn words, and to determine whether a word has been learned (and hence can potentially be unlearned).
         * @param word Argument converted to the Objective-C parameter of the same role.
         */
        void learn_word(const std::string& word) const;
        /**
         * @brief Calls `-[NSSpellChecker menuForResult:string:options:atLocation:inView:]`.
         * @details Provides a menu containing contextual menu items suitable for certain kinds of detected results (notably date/time/address results). The options dictionary allows clients to pass in information associated with the document.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @param checked_string Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @param view Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Menu menu_for_result(const TextCheckingResult& result, const std::string& checked_string, const std::map<std::string, Object>& options, const Point& location, const View& view) const;
        /**
         * @brief Calls `-[NSSpellChecker preventsAutocorrectionBeforeString:language:]`.
         * @details In some cases the next typing should prevent a pending correction (if it is an \@, for example). This method allows clients to recognize these cases in a standardized way.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool prevents_autocorrection_before_string(const std::string& string, const std::string& language) const;
        /**
         * @brief Calls `-[NSSpellChecker recordResponse:toCorrection:forWord:language:inSpellDocumentWithTag:]`.
         * @param response Argument converted to the Objective-C parameter of the same role.
         * @param correction Argument converted to the Objective-C parameter of the same role.
         * @param word Argument converted to the Objective-C parameter of the same role.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         */
        void record_response(CorrectionResponse response, const std::string& correction, const std::string& word, const std::string& language, std::int64_t tag) const;
        /**
         * @brief Calls `-[NSSpellChecker requestCandidatesForSelectedRange:inString:types:options:inSpellDocumentWithTag:completionHandler:]`.
         * @details Requests candidate generation in the background. The return value is a monotonically increasing sequence number that can be used to keep track of requests in flight. The completion handler will be called (in an arbitrary context) when results are available, with the sequence number and results.
         * @param selected_range Argument converted to the Objective-C parameter of the same role.
         * @param string_to_check Argument converted to the Objective-C parameter of the same role.
         * @param checking_types Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t request_candidates_for_selected_range(const Range& selected_range, const std::string& string_to_check, std::uint64_t checking_types, const std::map<std::string, Object>& options, std::int64_t tag, std::function<void(std::int64_t, std::vector<TextCheckingResult>)> completion_handler) const;
        /**
         * @brief Calls `-[NSSpellChecker requestCheckingOfString:range:types:options:inSpellDocumentWithTag:completionHandler:]`.
         * @details Requests unified text checking in the background. The return value is a monotonically increasing sequence number that can be used to keep track of requests in flight. The completion handler will be called (in an arbitrary context) when results are available, with the sequence number and results. The arguments and results are otherwise the same as for the previous method.
         * @param string_to_check Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param checking_types Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t request_checking_of_string(const std::string& string_to_check, const Range& range, std::uint64_t checking_types, const std::map<std::string, Object>& options, std::int64_t tag, std::function<void(std::int64_t, std::vector<TextCheckingResult>, Orthography, std::int64_t)> completion_handler) const;
        /**
         * @brief Calls `-[NSSpellChecker setIgnoredWords:inSpellDocumentWithTag:]`.
         * @param words Argument converted to the Objective-C parameter of the same role.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         */
        void set_ignored_words(const std::vector<std::string>& words, std::int64_t tag) const;
        /**
         * @brief Calls `-[NSSpellChecker setLanguage:]`.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool set_language(const std::string& language) const;
        /**
         * @brief Calls `-[NSSpellChecker setWordFieldStringValue:]`.
         * @details Allows programmatic setting of the misspelled word field.
         * @param string Argument converted to the Objective-C parameter of the same role.
         */
        void set_word_field_string_value(const std::string& string) const;
        /**
         * @brief Calls `-[NSSpellChecker showCorrectionIndicatorOfType:primaryString:alternativeStrings:forStringInRect:view:completionHandler:]`.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param primary_string Argument converted to the Objective-C parameter of the same role.
         * @param alternative_strings Argument converted to the Objective-C parameter of the same role.
         * @param rect_of_typed_string Argument converted to the Objective-C parameter of the same role.
         * @param view Argument converted to the Objective-C parameter of the same role.
         * @param completion_block Argument converted to the Objective-C parameter of the same role.
         */
        void show_correction_indicator_of_type(CorrectionIndicatorType type, const std::string& primary_string, const std::vector<std::string>& alternative_strings, const Rect& rect_of_typed_string, const View& view, std::function<void(std::string)> completion_block) const;
        /**
         * @brief Calls `-[NSSpellChecker showInlinePredictionForCandidates:client:]`.
         * @details Clients may use this to cause inline prediction candidates to be shown. The candidates passed in should come from calling requestCandidates with the NSTextCheckingGenerateInlinePredictionsKey option set. The inline prediction (if any) will be sent to the client for display using NSTextInputClient methods.
         * @param candidates Argument converted to the Objective-C parameter of the same role.
         * @param client Argument converted to the Objective-C parameter of the same role.
         */
        void show_inline_prediction_for_candidates(const std::vector<TextCheckingResult>& candidates, const Object& client) const;
        /**
         * @brief Calls `+[NSSpellChecker uniqueSpellDocumentTag]`.
         * @details Returns a guaranteed unique tag to use as the spell document tag for a document. You should use this method to generate tags, if possible, to avoid collisions with other objects that can be spell checked.
         * @return The converted Objective-C result.
         */
        static std::int64_t unique_spell_document_tag();
        /**
         * @brief Calls `-[NSSpellChecker unlearnWord:]`.
         * @param word Argument converted to the Objective-C parameter of the same role.
         */
        void unlearn_word(const std::string& word) const;
        /**
         * @brief Calls `-[NSSpellChecker updatePanels]`.
         * @details This method should be called when a client changes some relevant setting, such as what kind of spelling, grammar checking, or substitutions it uses.
         */
        void update_panels() const;
        /**
         * @brief Calls `-[NSSpellChecker updateSpellingPanelWithGrammarString:detail:]`.
         * @details The checkGrammarOfString:... method return the range of the sentence (or equivalent grammatical unit) with grammar issues, and an array of details describing the individual issues. It is up to the client to select one of those details in their document and to cause the spelling panel to update itself to reflect the found issue. Clients should call updateSpellingPanelWithGrammarString:detail: to inform the spelling panel of this. The string should be the entire sentence, i.e., the substring corresponding to the overall range returned by checkGrammarOfString:..., and the detail should be one of the elements of the details array.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param detail Argument converted to the Objective-C parameter of the same role.
         */
        void update_spelling_panel_with_grammar_string(const std::string& string, const std::map<std::string, Object>& detail) const;
        /**
         * @brief Calls `-[NSSpellChecker updateSpellingPanelWithMisspelledWord:]`.
         * @details The checkSpellingOfString:... methods return the range of the misspelled word found. It is up to the client to select that word in their document and to cause the spelling panel to update itself to reflect the found misspelling. Clients should call updateSpellPanelWithMisspelledWord: to inform the spelling panel of the word to be displayed.
         * @param word Argument converted to the Objective-C parameter of the same role.
         */
        void update_spelling_panel_with_misspelled_word(const std::string& word) const;
        /**
         * @brief Calls `-[NSSpellChecker userQuotesArrayForLanguage:]`.
         * @details Methods for obtaining the default values for NSTextCheckingQuotesKey and NSTextCheckingReplacementsKey.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> user_quotes_array_for_language(const std::string& language) const;
        /**
         * @brief Returns the `accessoryView` property of `NSSpellChecker`.
         * @return The converted Objective-C result.
         */
        View accessory_view() const;
        /**
         * @brief Sets the `accessoryView` property of `NSSpellChecker`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_accessory_view(const View& value) const;
        /**
         * @brief Returns the `automaticCapitalizationEnabled` property of `NSSpellChecker`.
         * @return The converted Objective-C result.
         */
        static bool is_automatic_capitalization_enabled();
        /**
         * @brief Returns the `automaticDashSubstitutionEnabled` property of `NSSpellChecker`.
         * @return The converted Objective-C result.
         */
        static bool is_automatic_dash_substitution_enabled();
        /**
         * @brief Returns the `automaticInlinePredictionEnabled` property of `NSSpellChecker`.
         * @return The converted Objective-C result.
         */
        static bool is_automatic_inline_prediction_enabled();
        /**
         * @brief Returns the `automaticPeriodSubstitutionEnabled` property of `NSSpellChecker`.
         * @return The converted Objective-C result.
         */
        static bool is_automatic_period_substitution_enabled();
        /**
         * @brief Returns the `automaticQuoteSubstitutionEnabled` property of `NSSpellChecker`.
         * @return The converted Objective-C result.
         */
        static bool is_automatic_quote_substitution_enabled();
        /**
         * @brief Returns the `automaticSpellingCorrectionEnabled` property of `NSSpellChecker`.
         * @return The converted Objective-C result.
         */
        static bool is_automatic_spelling_correction_enabled();
        /**
         * @brief Returns the `automaticTextCompletionEnabled` property of `NSSpellChecker`.
         * @return The converted Objective-C result.
         */
        static bool is_automatic_text_completion_enabled();
        /**
         * @brief Returns the `automaticTextReplacementEnabled` property of `NSSpellChecker`.
         * @details These methods allow clients to determine the global user preference settings for automatic text replacement, spelling correction, quote substitution, dash substitution, autocapitalization, double-space-to-period substitution, text completion, and inline prediction. Text views by default will follow these automatically, but clients may override that by programmatically setting the values on the text view. These methods will be useful for non-text view clients and others who wish to keep track of the settings. Notifications are available (see below) when the settings change.
         * @return The converted Objective-C result.
         */
        static bool is_automatic_text_replacement_enabled();
        /**
         * @brief Returns the `automaticallyIdentifiesLanguages` property of `NSSpellChecker`.
         * @return The converted Objective-C result.
         */
        bool automatically_identifies_languages() const;
        /**
         * @brief Sets the `automaticallyIdentifiesLanguages` property of `NSSpellChecker`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatically_identifies_languages(bool value) const;
        /**
         * @brief Returns the `availableLanguages` property of `NSSpellChecker`.
         * @details Entries in the availableLanguages list are all available spellchecking languages in user preference order, as described in the spellchecker's info dictionary, usually language abbreviations such as en_US. The userPreferredLanguages will be a subset of the availableLanguages, as selected by the user for use with spellchecking, in preference order. If automaticallyIdentifiesLanguages is YES, then text checking will automatically use these as appropriate; otherwise, it will use the language set by setLanguage:. The older checkSpellingOfString:... and checkGrammarOfString:... methods will use the language set by setLanguage:, if they are called with a nil language argument.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> available_languages() const;
        /**
         * @brief Returns the `sharedSpellChecker` property of `NSSpellChecker`.
         * @details Only one per application.
         * @return The converted Objective-C result.
         */
        static SpellChecker shared_spell_checker();
        /**
         * @brief Returns the `sharedSpellCheckerExists` property of `NSSpellChecker`.
         * @return The converted Objective-C result.
         */
        static bool shared_spell_checker_exists();
        /**
         * @brief Returns the `spellingPanel` property of `NSSpellChecker`.
         * @details Set and get attributes of the spelling and grammar panel.
         * @return The converted Objective-C result.
         */
        Panel spelling_panel() const;
        /**
         * @brief Returns the `substitutionsPanel` property of `NSSpellChecker`.
         * @details Set and get attributes of the substitutions panel.
         * @return The converted Objective-C result.
         */
        Panel substitutions_panel() const;
        /**
         * @brief Returns the `substitutionsPanelAccessoryViewController` property of `NSSpellChecker`.
         * @return The converted Objective-C result.
         */
        ViewController substitutions_panel_accessory_view_controller() const;
        /**
         * @brief Sets the `substitutionsPanelAccessoryViewController` property of `NSSpellChecker`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_substitutions_panel_accessory_view_controller(const ViewController& value) const;
        /**
         * @brief Returns the `userPreferredLanguages` property of `NSSpellChecker`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> user_preferred_languages() const;
        /**
         * @brief Returns the `userReplacementsDictionary` property of `NSSpellChecker`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, std::string> user_replacements_dictionary() const;
    };
}
