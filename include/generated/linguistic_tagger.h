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
     * @details Analyze natural language text to tag part of speech and lexical class, identify names, perform lemmatization, and determine the language and script. \@DeprecationSummary { Use the \<doc://com.apple.documentation/documentation/naturallanguage> framework instead. } ''NSLinguisticTagger'' provides a uniform interface to a variety of natural language processing functionality with support for many different languages and scripts. You can use this class to segment natural language text into paragraphs, sentences, or words, and tag information about those segments, such as part of speech, lexical class, lemma, script, and language. When you create a linguistic tagger, you specify what kind of information you're interested in by passing one or more ''NSLinguisticTagScheme'' values. Set the ''string'' property to the natural language text you want to analyze, and the linguistic tagger processes it according to the specified tag schemes. You can then enumerate over the tags in a specified range, using the methods described in Enumerating Linguistic Tags, to get the information requested for a given scheme and unit. \#\#\# Thread Safety A single instance of ''NSLinguisticTagger'' should not be used simultaneously from multiple threads.
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
         * @details Returns the tag schemes available for a particular language on the current device. - Parameters: - language: A BCP-47 tag identifying the language. For example, "en" for English or "zh-Hans" for Chinese written using the Simplified Chinese script. - Returns: The available tag schemes. For possible values, see 'NSLinguisticTagScheme'. This is a convenience method for calling 'availableTagSchemesForUnit:language:', passing 'NSLinguisticTaggerUnitWord' as the linguistic unit.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> available_tag_schemes_for_language(const std::string& language);
        /**
         * @brief Calls `+[NSLinguisticTagger availableTagSchemesForUnit:language:]`.
         * @details Returns the tag schemes available for a particular unit and language on the current device. - Parameters: - unit: The linguistic unit. For possible values, see 'NSLinguisticTaggerUnit'. - language: A BCP-47 tag identifying the language. For example, "en" for English or "zh-Hans" for Chinese written using the Simplified Chinese script. - Returns: The supported tag schemes. For possible values, see 'NSLinguisticTagScheme'.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> available_tag_schemes_for_unit(LinguisticTaggerUnit unit, const std::string& language);
        /**
         * @brief Calls `+[NSLinguisticTagger dominantLanguageForString:]`.
         * @details Returns the dominant language for the specified string. - Parameters: - string: The string for which the dominant language is determined. - Returns: The BCP-47 tag identifying the dominant language of the string, or the tag "und" if a specific language cannot be determined. This is a convenience method for creating a new linguistic tagger, setting the 'string' property, and getting the 'dominantLanguage' property.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string dominant_language_for_string(const std::string& string);
        /**
         * @brief Calls `+[NSLinguisticTagger enumerateTagsForString:range:unit:scheme:options:orthography:usingBlock:]`.
         * @details Enumerates over a given string and calls the specified block for each tag. - Parameters: - string: The string to enumerate over. - range: The range to analyze. - unit: The linguistic unit. For possible values, see 'NSLinguisticTaggerUnit'. - scheme: The tag scheme. For possible values, see 'NSLinguisticTagScheme'. - options: The linguistic tagger options to use. - orthography: The orthography of the string. If unspecified, the orthography is automatically detected. - block: The block to apply to ranges of the string. The block takes a tag, a token range, and a stop pointer as arguments. This is a convenience method for initializing a linguistic tagger, setting the 'string' property, and calling 'enumerateTagsInRange:unit:scheme:options:usingBlock:'. If you analyze the same string more than once, you should create a linguistic tagger object instead of calling this method.
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
         * @details Enumerates over a given range of the string and calls the specified block for each tag. - Parameters: - range: The range to analyze. - tagScheme: The tag scheme. For possible values, see 'NSLinguisticTagScheme'. - opts: The linguistic tagger options to use. - block: The block to apply to ranges of the string. The block takes a tag, a token range, a sentence range, and a stop pointer as arguments. This is a convenience method for calling 'enumerateTagsInRange:unit:scheme:options:usingBlock:', passing 'NSLinguisticTaggerUnitWord' as the linguistic unit.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param tag_scheme Argument converted to the Objective-C parameter of the same role.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_tags_in_range(const Range& range, const std::string& tag_scheme, LinguisticTaggerOptions opts, std::function<void(std::string, Range, Range, bool&)> block) const;
        /**
         * @brief Calls `-[NSLinguisticTagger enumerateTagsInRange:unit:scheme:options:usingBlock:]`.
         * @details Enumerates over a given range of the string for a particular unit and calls the specified block for each tag. - Parameters: - range: The range to analyze. - unit: The linguistic unit. For possible values, see 'NSLinguisticTaggerUnit'. - scheme: The tag scheme. For possible values, see 'NSLinguisticTagScheme'. - options: The linguistic tagger options to use. - block: The block to apply to ranges of the string. The block takes a tag, a token range, and a stop pointer as arguments. This method's block is called for all tokens intersecting a given range, supplying tags and ranges.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @param scheme Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_tags_in_range(const Range& range, LinguisticTaggerUnit unit, const std::string& scheme, LinguisticTaggerOptions options, std::function<void(std::string, Range, bool&)> block) const;
        /**
         * @brief Calls `-[NSLinguisticTagger orthographyAtIndex:effectiveRange:]`.
         * @details Returns the orthography at the index and also returns the effective range. - Parameters: - charIndex: The character index to begin examination. - effectiveRange: An NSRangePointer that, upon completion, contains the range of the orthography containing 'charIndex'. - Returns: The orthography for the location.
         * @param char_index Argument converted to the Objective-C parameter of the same role.
         * @param effective_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Orthography orthography_at_index(std::uint64_t char_index, Range* effective_range) const;
        /**
         * @brief Calls `-[NSLinguisticTagger possibleTagsAtIndex:scheme:tokenRange:sentenceRange:scores:]`.
         * @details Returns an array of possible tags for the given scheme at the specified range, supplying matching scores. - Parameters: - charIndex: The position of the initial character. - tagScheme: The tag scheme. See 'NSLinguisticTagScheme' for possible values. - tokenRange: The token range. - sentenceRange: The range of the sentence. - scores: Returns by reference an array of numeric scores indicating the likelihood that the range matches the tag scheme. - Returns: Returns an array of possible tags for the tag scheme at the specified location, starting with the most likely tag scheme. Calling this method is not recommended; for most use cases, this information is not as useful as what is provided by the methods described in Enumerating Linguistic Tags and Getting Linguistic Tags.
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
         * @details Returns a range covering all sentences intersecting the given range. - Parameters: - range: The character range. - Returns: Returns the range of the sentence. This is a convenience method for calling 'tokenRangeAtIndex:unit:', passing 'NSLinguisticTaggerUnitSentence' as the unit and the first position of the provided range.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range sentence_range_for_range(const Range& range) const;
        /**
         * @brief Calls `-[NSLinguisticTagger setOrthography:range:]`.
         * @details Sets the orthography for the specified range. - Parameters: - orthography: The orthography. - range: The range. If the orthography of the linguistic tagger is not set, it will determine it automatically from the contents of the text. You should call this method only if you know the orthography of the text by some other means.
         * @param orthography Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         */
        void set_orthography(const Orthography& orthography, const Range& range) const;
        /**
         * @brief Calls `-[NSLinguisticTagger stringEditedInRange:changeInLength:]`.
         * @details Notifies the linguistic tagger that the string (if mutable) has changed as specified by the parameters. - Parameters: - newRange: The range in the final string that was edited. - delta: The change in length.
         * @param new_range Argument converted to the Objective-C parameter of the same role.
         * @param delta Argument converted to the Objective-C parameter of the same role.
         */
        void string_edited_in_range(const Range& new_range, std::int64_t delta) const;
        /**
         * @brief Calls `-[NSLinguisticTagger tagAtIndex:scheme:tokenRange:sentenceRange:]`.
         * @details Returns a tag for a single scheme at the specified character position. - Parameters: - charIndex: The position of the initial character. - scheme: The tag scheme. See 'NSLinguisticTagScheme' for the possible values. - tokenRange: A pointer to the token range. - sentenceRange: A pointer to the range of the sentence. - Returns: Returns the tag for the requested tag scheme, or 'nil'. If a tag is returned, this function returns by reference the range of the token to 'tokenRange', and the range of the enclosing sentence to 'sentenceRange', if applicable. This is a convenience method for calling 'tagAtIndex:unit:scheme:tokenRange:' and passing 'NSLinguisticTaggerUnitWord' as the linguistic unit.
         * @param char_index Argument converted to the Objective-C parameter of the same role.
         * @param scheme Argument converted to the Objective-C parameter of the same role.
         * @param token_range Argument converted to the Objective-C parameter of the same role.
         * @param sentence_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string tag_at_index(std::uint64_t char_index, const std::string& scheme, Range* token_range, Range* sentence_range) const;
        /**
         * @brief Calls `-[NSLinguisticTagger tagAtIndex:unit:scheme:tokenRange:]`.
         * @details Returns a tag for a single scheme, for a given linguistic unit, at the specified character position. - Parameters: - charIndex: The position of the initial character. - unit: The linguistic unit. See 'NSLinguisticTaggerUnit' for possible values. - scheme: The tag scheme. See 'NSLinguisticTagScheme' for possible values. - tokenRange: A pointer to the token range. - Returns: Returns the tag for the requested tag scheme and linguistic unit, or 'nil'. If a tag is returned, this function returns by reference the range of the token to 'tokenRange'.
         * @param char_index Argument converted to the Objective-C parameter of the same role.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @param scheme Argument converted to the Objective-C parameter of the same role.
         * @param token_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string tag_at_index(std::uint64_t char_index, LinguisticTaggerUnit unit, const std::string& scheme, Range* token_range) const;
        /**
         * @brief Calls `+[NSLinguisticTagger tagForString:atIndex:unit:scheme:orthography:tokenRange:]`.
         * @details Returns a tag for a single scheme, for a given linguistic unit, at the specified character position in a string. - Parameters: - string: The string to analyze. - charIndex: The position of the initial character. - unit: The linguistic unit. See 'NSLinguisticTaggerUnit' for possible values. - scheme: The tag scheme. See 'NSLinguisticTagScheme' for possible values. - orthography: The orthography of the string. If unspecified, the orthography is automatically detected. - tokenRange: A pointer to the token range. - Returns: Returns the tag for the requested tag scheme and linguistic unit, or 'nil'. This is a convenience method for initializing a linguistic tagger, setting the 'string' property, and calling 'tagAtIndex:unit:scheme:tokenRange:'. If you analyze the same string more than once, you should create a linguistic tagger object instead of calling this method.
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
         * @details Returns an array of linguistic tags and token ranges for a given string and linguistic unit. - Parameters: - string: The string to analyze. - range: The range from which to return tags. - unit: The linguistic unit. See 'NSLinguisticTaggerUnit' for possible values. - scheme: The tag scheme. See 'NSLinguisticTagScheme' for possible values. - options: The linguistic tagger options to use. - orthography: The orthography of the string. If unspecified, the orthography is automatically detected. - tokenRanges: Returns by reference an array of token ranges. - Returns: An array of the tags in the requested range. This is a convenience method for initializing a linguistic tagger, setting the 'string' property, and calling 'tagsInRange:unit:scheme:options:tokenRanges:'. If you analyze the same string more than once, you should create a linguistic tagger object instead of calling this method.
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
         * @details Returns an array of linguistic tags and token ranges for a given string range. - Parameters: - range: The range from which to return tags. - tagScheme: The tag scheme. See 'NSLinguisticTagScheme' for possible values. - opts: The linguistic tagger options to use. - tokenRanges: Returns by reference an array of token ranges. - Returns: An array of the tags in the requested range. This is a convenience method for calling 'tagsInRange:unit:scheme:options:tokenRanges:' and passing 'NSLinguisticTaggerUnitWord' as the linguistic unit.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param tag_scheme Argument converted to the Objective-C parameter of the same role.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @param token_ranges Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> tags_in_range(const Range& range, const std::string& tag_scheme, LinguisticTaggerOptions opts, std::vector<Value>& token_ranges) const;
        /**
         * @brief Calls `-[NSLinguisticTagger tagsInRange:unit:scheme:options:tokenRanges:]`.
         * @details Returns an array of linguistic tags and token ranges for a given string range and linguistic unit. - Parameters: - range: The range from which to return tags. - unit: The linguistic unit. See 'NSLinguisticTaggerUnit' for possible values. - scheme: The tag scheme. See 'NSLinguisticTagScheme' for possible values. - options: The linguistic tagger options to use. - tokenRanges: Returns by reference an array of token ranges. - Returns: An array of the tags in the requested range.
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
         * @details Returns the range of the linguistic unit containing the specified character index. - Parameters: - charIndex: The character index to begin examination. - unit: The linguistic unit. For possible values, see 'NSLinguisticTaggerUnit'. - Returns: The range of the substring for the linguistic unit.
         * @param char_index Argument converted to the Objective-C parameter of the same role.
         * @param unit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range token_range_at_index(std::uint64_t char_index, LinguisticTaggerUnit unit) const;
        /**
         * @brief Returns the `dominantLanguage` property of `NSLinguisticTagger`.
         * @details Returns the dominant language of the string set for the linguistic tagger. Returns the BCP-47 tag identifying the dominant language of the string, or the tag "und" if a specific language cannot be determined.
         * @return The converted Objective-C result.
         */
        std::string dominant_language() const;
        /**
         * @brief Returns the `string` property of `NSLinguisticTagger`.
         * @details The string being analyzed by the linguistic tagger.
         * @return The converted Objective-C result.
         */
        std::string string() const;
        /**
         * @brief Sets the `string` property of `NSLinguisticTagger`.
         * @details The string being analyzed by the linguistic tagger.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_string(const std::string& value) const;
        /**
         * @brief Returns the `tagSchemes` property of `NSLinguisticTagger`.
         * @details Returns the tag schemes configured for this linguistic tagger.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> tag_schemes() const;
    };
}
