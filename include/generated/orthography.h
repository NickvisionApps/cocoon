#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSOrthography` (Foundation).
     * @details A description of the linguistic content of natural language text, typically used for spelling and grammar checking. Use ''NSOrthography'' objects to describe the linguistic content of a piece of text, including which scripts the text contains, a dominant language (and possibly other languages) for each script, and a dominant script and language for the text as a whole. Scripts are uniformly described by four-letter ISO 15924 script codes, such as '"Latn"', '"Grek"', and '"Cyrl"'. The supertags '"Jpan"' and '"Kore"' are typically used for Japanese and Korean text, and '"Hans"' and '"Hant"' are typically used for Chinese text. The tag '"Zyyy"' is used if a specific script cannot be identified. See [Internationalization and Localization Guide](https://developer.apple.com/library/archive/documentation/MacOSX/Conceptual/BPInternational/Introduction/Introduction.html\#//apple_ref/doc/uid/10000171i) for more information. Languages are uniformly described by BCP-47 tags (preferably in canonical form). The tag '"und"' is used if a specific language cannot be determined. You typically work with orthography objects returned from methods and properties for classes like ''NSLinguisticTagger'' and \<doc://com.apple.documentation/documentation/appkit/nsspellchecker>. \#\#\# Subclassing Notes Subclasses must override the ''dominantScript'' and ''languageMap'' properties. These properties are set using ''init(dominantScript:languageMap:)'' or ''orthographyWithDominantScript:languageMap:'' in Objective-C.
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
     * @details Creates and returns an orthography object with the default language map for the specified language. This method automatically determines the script for the specified language. - Parameter language: A BCP-47 tag identifying the language.
     * @param language Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Orthography default_orthography_for_language(const std::string& language);
        /**
     * @brief Calls `-[NSOrthography dominantLanguageForScript:]`.
     * @details Returns the dominant language for the specified script. - Parameter script: The specified script.
     * @param script Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string dominant_language_for_script(const std::string& script) const;
        /**
     * @brief Calls `-[NSOrthography languagesForScript:]`.
     * @details Returns the list of languages for the specified script. - Parameter script: The specified script.
     * @param script Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> languages_for_script(const std::string& script) const;
        /**
     * @brief Calls `+[NSOrthography orthographyWithDominantScript:languageMap:]`.
     * @details Creates and returns an orthography object with the specified dominant script and language map. - Parameter script: The dominant script. - Parameter map: A dictionary mapping ISO 15924 script codes to arrays of BCP-47 language tags.
     * @param script Argument converted to the Objective-C parameter of the same role.
     * @param map Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Orthography orthography_with_dominant_script(const std::string& script, const std::map<std::string, std::vector<std::string>>& map);
        /**
     * @brief Returns the `allLanguages` property of `NSOrthography`.
     * @details The languages appearing in values of the language map.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> all_languages() const;
        /**
     * @brief Returns the `allScripts` property of `NSOrthography`.
     * @details The scripts appearing as keys in the language map.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> all_scripts() const;
        /**
     * @brief Returns the `dominantLanguage` property of `NSOrthography`.
     * @details The first language in the list of languages for the dominant script.
     * @return The converted Objective-C result.
     */
        std::string dominant_language() const;
        /**
     * @brief Returns the `dominantScript` property of `NSOrthography`.
     * @details The dominant script for the text. The value of this property is an ISO 15924 script code, such as '"Latn"' or '"Cyrl"', that identifies the dominant script.
     * @return The converted Objective-C result.
     */
        std::string dominant_script() const;
        /**
     * @brief Returns the `languageMap` property of `NSOrthography`.
     * @details A dictionary that maps script tags to arrays of language tags. The dictionary's keys are ISO 15924 script codes (such as '"Latn"' or '"Cyrl"') and its values are arrays of BCP-47 language tags (such as '"en"', '"fr"', or '"de"').
     * @return The converted Objective-C result.
     */
        std::map<std::string, std::vector<std::string>> language_map() const;
    };
}
