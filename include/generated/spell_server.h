#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Orthography;
    class TextCheckingResult;

    /**
     * @brief C++ handle for the Objective-C class `NSSpellServer` (Foundation).
     * @details A server that your app uses to provide a spell checker service to other apps running in the system. A service provider is an application that declares its availability in a standard way, so that any other applications that wish to use it can do so. If you build a spelling checker that makes use of the ''NSSpellServer'' class and list it as an available service, then users of any application that makes use of \<doc://com.apple.documentation/documentation/appkit/nsspellchecker> or includes a Services menu will see your spelling checker as one of the available dictionaries.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SpellServer spell_server;
     * spell_server.did_learn_word_in_language().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SpellServer spell_server{};
     * spell_server.is_word_in_user_dictionaries("text", true);
     * spell_server.register_language("text", "text");
     * spell_server.run();
     * spell_server.did_learn_word_in_language().connect([](std::string a0, std::string a1) {});
     * spell_server.did_forget_word_in_language().connect([](std::string a0, std::string a1) {});
     * spell_server.record_response_to_correction_for_word_language().connect([](std::uint64_t a0, std::string a1, std::string a2, std::string a3) {});
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsspellserver
     */
    class SpellServer : public Object
    {
    public:
        /// @brief Creates a new `NSSpellServer` instance and returns a handle to it.
        explicit SpellServer();
        /// @brief Creates a null handle that refers to no native object.
        SpellServer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SpellServer(Adopt adopt);
        /**
     * @brief Calls `-[NSSpellServer isWordInUserDictionaries:caseSensitive:]`.
     * @details Indicates whether a given word is in the user's list of learned words, regardless of the language.
     * @param word Argument converted to the Objective-C parameter of the same role.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_word_in_user_dictionaries(const std::string& word, bool flag) const;
        /**
     * @brief Calls `-[NSSpellServer registerLanguage:byVendor:]`.
     * @details Registers the given language for the receiver with the given vendor name.
     * @param language Argument converted to the Objective-C parameter of the same role.
     * @param vendor Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool register_language(const std::string& language, const std::string& vendor) const;
        /**
     * @brief Calls `-[NSSpellServer run]`.
     * @details Causes the receiver to start listening for spell-checking requests.
     */
        void run() const;
        /// @brief Signal for the delegate/data-source method behind `find_misspelled_word_in_string_language_word_count_count_only`; connect a callback with `find_misspelled_word_in_string_language_word_count_count_only().connect(...)`.
        Signal<SpellServer, Range(std::string, std::string, std::int64_t*, bool)> find_misspelled_word_in_string_language_word_count_count_only() const
        {
            return Signal<SpellServer, Range(std::string, std::string, std::int64_t*, bool)>(handle(), "find_misspelled_word_in_string_language_word_count_count_only");
        }
        /// @brief Signal for the delegate/data-source method behind `suggest_guesses_for_word_in_language`; connect a callback with `suggest_guesses_for_word_in_language().connect(...)`.
        Signal<SpellServer, std::vector<std::string>(std::string, std::string)> suggest_guesses_for_word_in_language() const
        {
            return Signal<SpellServer, std::vector<std::string>(std::string, std::string)>(handle(), "suggest_guesses_for_word_in_language");
        }
        /// @brief Signal for the delegate/data-source method behind `did_learn_word_in_language`; connect a callback with `did_learn_word_in_language().connect(...)`.
        Signal<SpellServer, void(std::string, std::string)> did_learn_word_in_language() const
        {
            return Signal<SpellServer, void(std::string, std::string)>(handle(), "did_learn_word_in_language");
        }
        /// @brief Signal for the delegate/data-source method behind `did_forget_word_in_language`; connect a callback with `did_forget_word_in_language().connect(...)`.
        Signal<SpellServer, void(std::string, std::string)> did_forget_word_in_language() const
        {
            return Signal<SpellServer, void(std::string, std::string)>(handle(), "did_forget_word_in_language");
        }
        /// @brief Signal for the delegate/data-source method behind `suggest_completions_for_partial_word_range_in_string_language`; connect a callback with `suggest_completions_for_partial_word_range_in_string_language().connect(...)`.
        Signal<SpellServer, std::vector<std::string>(Range, std::string, std::string)> suggest_completions_for_partial_word_range_in_string_language() const
        {
            return Signal<SpellServer, std::vector<std::string>(Range, std::string, std::string)>(handle(), "suggest_completions_for_partial_word_range_in_string_language");
        }
        /// @brief Signal for the delegate/data-source method behind `check_grammar_in_string_language_details`; connect a callback with `check_grammar_in_string_language_details().connect(...)`.
        Signal<SpellServer, Range(std::string, std::string, std::vector<std::map<std::string, Object>>&)> check_grammar_in_string_language_details() const
        {
            return Signal<SpellServer, Range(std::string, std::string, std::vector<std::map<std::string, Object>>&)>(handle(), "check_grammar_in_string_language_details");
        }
        /// @brief Signal for the delegate/data-source method behind `check_string_offset_types_options_orthography_word_count`; connect a callback with `check_string_offset_types_options_orthography_word_count().connect(...)`.
        Signal<SpellServer, std::vector<TextCheckingResult>(std::string, std::uint64_t, std::uint64_t, std::map<std::string, Object>, Orthography, std::int64_t*)> check_string_offset_types_options_orthography_word_count() const
        {
            return Signal<SpellServer, std::vector<TextCheckingResult>(std::string, std::uint64_t, std::uint64_t, std::map<std::string, Object>, Orthography, std::int64_t*)>(handle(), "check_string_offset_types_options_orthography_word_count");
        }
        /// @brief Signal for the delegate/data-source method behind `record_response_to_correction_for_word_language`; connect a callback with `record_response_to_correction_for_word_language().connect(...)`.
        Signal<SpellServer, void(std::uint64_t, std::string, std::string, std::string)> record_response_to_correction_for_word_language() const
        {
            return Signal<SpellServer, void(std::uint64_t, std::string, std::string, std::string)>(handle(), "record_response_to_correction_for_word_language");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
