#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class MorphologyPronoun;

    /**
     * @brief C++ handle for the Objective-C class `NSTermOfAddress` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TermOfAddress term_of_address(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TermOfAddress term_of_address(nullptr);
     * auto made_0 = cocoon::TermOfAddress::current_user();
     * auto made_1 = cocoon::TermOfAddress::feminine();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nstermofaddress
     */
    class TermOfAddress : public Object
    {
    public:
        TermOfAddress();
        /// @brief Creates a null handle that refers to no native object.
        TermOfAddress(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TermOfAddress(Adopt adopt);
        /**
         * @brief Calls `+[NSTermOfAddress currentUser]`.
         * @details The term of address that should be used for addressing the user This term of address will only compare equal to another '+[NSTermOfAddress currentUser]'
         * @return The converted Objective-C result.
         */
        static TermOfAddress current_user();
        /**
         * @brief Calls `+[NSTermOfAddress feminine]`.
         * @details Term of address that uses feminine pronouns (e.g. she/her/hers in English), and a feminine grammatical gender when inflecting verbs and adjectives referring to the person
         * @return The converted Objective-C result.
         */
        static TermOfAddress feminine();
        /**
         * @brief Calls `+[NSTermOfAddress localizedForLanguageIdentifier:withPronouns:]`.
         * @details A term of address restricted to a given language \@param language ISO language code identifier for the language \@param pronouns A list of pronouns in the target language that can be used to refer to the person.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @param pronouns Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static TermOfAddress localized_for_language_identifier(const std::string& language, const std::vector<MorphologyPronoun>& pronouns);
        /**
         * @brief Calls `+[NSTermOfAddress masculine]`.
         * @details Term of address that uses masculine pronouns (e.g. he/him/his in English), and a masculine grammatical gender when inflecting verbs and adjectives referring to the person
         * @return The converted Objective-C result.
         */
        static TermOfAddress masculine();
        /**
         * @brief Calls `+[NSTermOfAddress neutral]`.
         * @details Term of address that uses gender-neutral pronouns (e.g. they/them/theirs in English), and an epicene grammatical gender when inflecting verbs and adjectives referring to the person
         * @return The converted Objective-C result.
         */
        static TermOfAddress neutral();
        /**
         * @brief Returns the `languageIdentifier` property of `NSTermOfAddress`.
         * @details The ISO language code if this is a localized term of address
         * @return The converted Objective-C result.
         */
        std::string language_identifier() const;
        /**
         * @brief Returns the `pronouns` property of `NSTermOfAddress`.
         * @details A list of pronouns for a localized term of address
         * @return The converted Objective-C result.
         */
        std::vector<MorphologyPronoun> pronouns() const;
    };
}
