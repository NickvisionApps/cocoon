#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Orthography;
    class Value;

    /**
     * @brief C++ handle for the Objective-C class `NSLinguisticTagger` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::LinguisticTagger linguistic_tagger;
     * linguistic_tagger.set_string("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::LinguisticTagger linguistic_tagger{};
     * linguistic_tagger.set_string("text");
     * auto string = linguistic_tagger.string();
     * linguistic_tagger.token_range_at_index(1, cocoon::LinguisticTaggerUnit::Word);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nslinguistictagger
     */
    class LinguisticTagger : public Object
    {
    public:
        /// @brief Creates a new `NSLinguisticTagger` instance and returns a handle to it.
        explicit LinguisticTagger(const std::vector<std::string>& tag_schemes, std::uint64_t opts);
        /// @brief Creates a new `NSLinguisticTagger` instance and returns a handle to it.
        explicit LinguisticTagger();
        /// @brief Creates a null handle that refers to no native object.
        LinguisticTagger(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit LinguisticTagger(Adopt adopt);
        /**
     * @brief Calls `+[NSLinguisticTagger availableTagSchemesForLanguage:]`.
     * @details Clients wishing to know the tag schemes supported in NSLinguisticTagger for a particular language at the word level may query them with this method. The language should be specified using a standard abbreviation as with NSOrthography.
     * @param language Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> available_tag_schemes_for_language(const std::string& language);
        /**
     * @brief Calls `+[NSLinguisticTagger availableTagSchemesForUnit:language:]`.
     * @details Clients wishing to know the tag schemes supported in NSLinguisticTagger for a particular unit and language may query them with this method. The language should be specified using a standard BCP-47 language tag as with NSOrthography.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @param language Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> available_tag_schemes_for_unit(LinguisticTaggerUnit unit, const std::string& language);
        /**
     * @brief Calls `+[NSLinguisticTagger dominantLanguageForString:]`.
     * @details The following class methods are conveniences for clients who wish to perform a single analysis on a string without having to create an instance of NSLinguisticTagger. If more than one tagging operation is needed on a given string, it is more efficient to use an explicit NSLinguisticTagger instance.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string dominant_language_for_string(const std::string& string);
        /**
     * @brief Calls `+[NSLinguisticTagger enumerateTagsForString:range:unit:scheme:options:orthography:usingBlock:]`.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @param scheme Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param orthography Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        static void enumerate_tags_for_string(const std::string& string, const Range& range, LinguisticTaggerUnit unit, const std::string& scheme, LinguisticTaggerOptions options, const Orthography& orthography, std::function<void(std::string, Range, bool&)> block);
        /**
     * @brief Calls `-[NSLinguisticTagger enumerateTagsInRange:scheme:options:usingBlock:]`.
     * @details Methods that do not specify a unit act at the word level.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param tag_scheme Argument converted to the Objective-C parameter of the same role.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_tags_in_range(const Range& range, const std::string& tag_scheme, LinguisticTaggerOptions opts, std::function<void(std::string, Range, Range, bool&)> block) const;
        /**
     * @brief Calls `-[NSLinguisticTagger enumerateTagsInRange:unit:scheme:options:usingBlock:]`.
     * @details The tagger will segment the string as needed into tokens for the given unit, and return those ranges along with a tag for any scheme in its array of tag schemes. The fundamental tagging method on NSLinguisticTagger is a block iterator, that iterates over all tokens intersecting a given range, supplying tags and ranges. There are several additional convenience methods, for obtaining a sentence range, information about a single token, or for obtaining information about all tokens intersecting a given range at once, in arrays. In each case, the charIndex or range passed in must not extend beyond the end of the tagger's string, or the methods will raise an exception. Note that a given instance of NSLinguisticTagger should not be used from more than one thread simultaneously.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @param scheme Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_tags_in_range(const Range& range, LinguisticTaggerUnit unit, const std::string& scheme, LinguisticTaggerOptions options, std::function<void(std::string, Range, bool&)> block) const;
        /**
     * @brief Calls `-[NSLinguisticTagger orthographyAtIndex:effectiveRange:]`.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @param effective_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Orthography orthography_at_index(std::uint64_t char_index, Range* effective_range) const;
        /**
     * @brief Calls `-[NSLinguisticTagger possibleTagsAtIndex:scheme:tokenRange:sentenceRange:scores:]`.
     * @details Deprecated method for obtaining a list of possible tags for the token at a given index.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @param tag_scheme Argument converted to the Objective-C parameter of the same role.
     * @param token_range Argument converted to the Objective-C parameter of the same role.
     * @param sentence_range Argument converted to the Objective-C parameter of the same role.
     * @param scores Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> possible_tags_at_index(std::uint64_t char_index, const std::string& tag_scheme, Range* token_range, Range* sentence_range, std::vector<Value>& scores) const;
        /**
     * @brief Calls `-[NSLinguisticTagger sentenceRangeForRange:]`.
     * @details Returns a range covering all sentences intersecting the given range.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range sentence_range_for_range(const Range& range) const;
        /**
     * @brief Calls `-[NSLinguisticTagger setOrthography:range:]`.
     * @details If clients know the orthography for a given portion of the string, they may supply it to the tagger. Otherwise, the tagger will infer the language from the contents of the text. In each case, the charIndex or range passed in must not extend beyond the end of the tagger's string, or the methods will raise an exception.
     * @param orthography Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void set_orthography(const Orthography& orthography, const Range& range) const;
        /**
     * @brief Calls `-[NSLinguisticTagger stringEditedInRange:changeInLength:]`.
     * @details If the string attached to the tagger is mutable, this method must be called to inform the tagger whenever the string changes. The newRange is the range in the final string which was explicitly edited, and delta is the change in length from the previous version to the current version of the string. Alternatively, the client may call setString: again to reset all information about the string, but this has the disadvantage of not preserving information about portions of the string that have not changed.
     * @param new_range Argument converted to the Objective-C parameter of the same role.
     * @param delta Argument converted to the Objective-C parameter of the same role.
     */
        void string_edited_in_range(const Range& new_range, std::int64_t delta) const;
        /**
     * @brief Calls `-[NSLinguisticTagger tagAtIndex:scheme:tokenRange:sentenceRange:]`.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @param scheme Argument converted to the Objective-C parameter of the same role.
     * @param token_range Argument converted to the Objective-C parameter of the same role.
     * @param sentence_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string tag_at_index(std::uint64_t char_index, const std::string& scheme, Range* token_range, Range* sentence_range) const;
        /**
     * @brief Calls `-[NSLinguisticTagger tagAtIndex:unit:scheme:tokenRange:]`.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @param scheme Argument converted to the Objective-C parameter of the same role.
     * @param token_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string tag_at_index(std::uint64_t char_index, LinguisticTaggerUnit unit, const std::string& scheme, Range* token_range) const;
        /**
     * @brief Calls `+[NSLinguisticTagger tagForString:atIndex:unit:scheme:orthography:tokenRange:]`.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @param scheme Argument converted to the Objective-C parameter of the same role.
     * @param orthography Argument converted to the Objective-C parameter of the same role.
     * @param token_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string tag_for_string(const std::string& string, std::uint64_t char_index, LinguisticTaggerUnit unit, const std::string& scheme, const Orthography& orthography, Range* token_range);
        /**
     * @brief Calls `+[NSLinguisticTagger tagsForString:range:unit:scheme:options:orthography:tokenRanges:]`.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @param scheme Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param orthography Argument converted to the Objective-C parameter of the same role.
     * @param token_ranges Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> tags_for_string(const std::string& string, const Range& range, LinguisticTaggerUnit unit, const std::string& scheme, LinguisticTaggerOptions options, const Orthography& orthography, std::vector<Value>& token_ranges);
        /**
     * @brief Calls `-[NSLinguisticTagger tagsInRange:scheme:options:tokenRanges:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param tag_scheme Argument converted to the Objective-C parameter of the same role.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param token_ranges Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> tags_in_range(const Range& range, const std::string& tag_scheme, LinguisticTaggerOptions opts, std::vector<Value>& token_ranges) const;
        /**
     * @brief Calls `-[NSLinguisticTagger tagsInRange:unit:scheme:options:tokenRanges:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @param scheme Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param token_ranges Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> tags_in_range(const Range& range, LinguisticTaggerUnit unit, const std::string& scheme, LinguisticTaggerOptions options, std::vector<Value>& token_ranges) const;
        /**
     * @brief Calls `-[NSLinguisticTagger tokenRangeAtIndex:unit:]`.
     * @details Returns the range corresponding to the token for the given unit that contains the given character index.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range token_range_at_index(std::uint64_t char_index, LinguisticTaggerUnit unit) const;
        /**
     * @brief Returns the `dominantLanguage` property of `NSLinguisticTagger`.
     * @details Returns the top identified language (if any) for the entire string. Convenience for tagAtIndex: with NSLinguisticTagSchemeLanguage and NSLinguisticTaggerUnitDocument.
     * @return The converted Objective-C result.
     */
        std::string dominant_language() const;
        /**
     * @brief Returns the `string` property of `NSLinguisticTagger`.
     * @return The converted Objective-C result.
     */
        std::string string() const;
        /**
     * @brief Sets the `string` property of `NSLinguisticTagger`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_string(const std::string& value) const;
        /**
     * @brief Returns the `tagSchemes` property of `NSLinguisticTagger`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> tag_schemes() const;
    };
}
