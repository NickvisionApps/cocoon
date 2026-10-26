#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSOrthography` (Foundation).
     * @details NSOrthography is a class used to describe the linguistic content of a piece of text, especially for the purposes of spelling and grammar checking. It describes (a) which scripts the text contains, (b) a dominant language and possibly other languages for each of these scripts, and (c) a dominant script and language for the text as a whole. Scripts are uniformly described by standard four-letter tags (Latn, Grek, Cyrl, etc.) with the supertags Jpan and Kore typically used for Japanese and Korean text, Hans and Hant for Chinese text; the tag Zyyy is used if a specific script cannot be identified. Languages are uniformly described by BCP-47 tags, preferably in canonical form; the tag und is used if a specific language cannot be determined.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Orthography orthography;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Orthography orthography{};
     * auto made_0 = cocoon::Orthography::default_orthography_for_language("text");
     * orthography.dominant_language_for_script("text");
     * orthography.languages_for_script("text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsorthography
     */
    class Orthography : public Object
    {
    public:
        /// @brief Creates a new `NSOrthography` instance and returns a handle to it.
        explicit Orthography(const std::string& script, const std::map<std::string, std::vector<std::string>>& map);
        /// @brief Creates a new `NSOrthography` instance and returns a handle to it.
        explicit Orthography();
        /// @brief Creates a null handle that refers to no native object.
        Orthography(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Orthography(Adopt adopt);
        /**
         * @brief Calls `+[NSOrthography defaultOrthographyForLanguage:]`.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Orthography default_orthography_for_language(const std::string& language);
        /**
         * @brief Calls `-[NSOrthography dominantLanguageForScript:]`.
         * @param script Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string dominant_language_for_script(const std::string& script) const;
        /**
         * @brief Calls `-[NSOrthography languagesForScript:]`.
         * @details languagesForScript: returns the list of languages for the specified script, and dominantLanguageForScript: returns the first item on that list.
         * @param script Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> languages_for_script(const std::string& script) const;
        /**
         * @brief Returns the `allLanguages` property of `NSOrthography`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> all_languages() const;
        /**
         * @brief Returns the `allScripts` property of `NSOrthography`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> all_scripts() const;
        /**
         * @brief Returns the `dominantLanguage` property of `NSOrthography`.
         * @details The dominantLanguage is the first in the list of languages for the dominant script, allScripts includes the dominant script and all others appearing as keys in the language map, and allLanguages includes all languages appearing in the values of the language map.
         * @return The converted Objective-C result.
         */
        std::string dominant_language() const;
        /**
         * @brief Returns the `dominantScript` property of `NSOrthography`.
         * @details These are the primitive properties which a subclass must implement. The dominantScript should be a script tag (such as Latn, Cyrl, and so forth) and the languageMap should be a dictionary whose keys are script tags and whose values are arrays of language tags (such as en, fr, de, and so forth).
         * @return The converted Objective-C result.
         */
        std::string dominant_script() const;
        /**
         * @brief Returns the `languageMap` property of `NSOrthography`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, std::vector<std::string>> language_map() const;
    };
}
