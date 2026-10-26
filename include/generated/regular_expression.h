#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class TextCheckingResult;

    /**
     * @brief C++ handle for the Objective-C class `NSRegularExpression` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::RegularExpression regular_expression;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::RegularExpression regular_expression{};
     * regular_expression.replacement_string_for_result(cocoon::TextCheckingResult(), "text", 1, "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsregularexpression
     */
    class RegularExpression : public Object
    {
    public:
        /// @brief Creates a new `NSRegularExpression` instance and returns a handle to it.
        explicit RegularExpression(const std::string& pattern, RegularExpressionOptions options);
        /// @brief Creates a new `NSRegularExpression` instance and returns a handle to it.
        explicit RegularExpression();
        /// @brief Creates a null handle that refers to no native object.
        RegularExpression(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit RegularExpression(Adopt adopt);
        /**
         * @brief Calls `-[NSRegularExpression enumerateMatchesInString:options:range:usingBlock:]`.
         * @details The fundamental matching method on NSRegularExpression is a block iterator. There are several additional convenience methods, for returning all matches at once, the number of matches, the first match, or the range of the first match. Each match is specified by an instance of NSTextCheckingResult (of type NSTextCheckingTypeRegularExpression) in which the overall match range is given by the range property (equivalent to rangeAtIndex:0) and any capture group ranges are given by rangeAtIndex: for indexes from 1 to numberOfCaptureGroups. {NSNotFound, 0} is used if a particular capture group does not participate in the match.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_matches_in_string(const std::string& string, MatchingOptions options, const Range& range, std::function<void(TextCheckingResult, MatchingFlags, bool&)> block) const;
        /**
         * @brief Calls `+[NSRegularExpression escapedPatternForString:]`.
         * @details This class method will produce a string by adding backslash escapes as necessary to the given string, to escape any characters that would otherwise be treated as pattern metacharacters.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string escaped_pattern_for_string(const std::string& string);
        /**
         * @brief Calls `+[NSRegularExpression escapedTemplateForString:]`.
         * @details This class method will produce a string by adding backslash escapes as necessary to the given string, to escape any characters that would otherwise be treated as template metacharacters.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string escaped_template_for_string(const std::string& string);
        /**
         * @brief Calls `-[NSRegularExpression firstMatchInString:options:range:]`.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextCheckingResult first_match_in_string(const std::string& string, MatchingOptions options, const Range& range) const;
        /**
         * @brief Calls `-[NSRegularExpression matchesInString:options:range:]`.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<TextCheckingResult> matches_in_string(const std::string& string, MatchingOptions options, const Range& range) const;
        /**
         * @brief Calls `-[NSRegularExpression numberOfMatchesInString:options:range:]`.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t number_of_matches_in_string(const std::string& string, MatchingOptions options, const Range& range) const;
        /**
         * @brief Calls `-[NSRegularExpression rangeOfFirstMatchInString:options:range:]`.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range range_of_first_match_in_string(const std::string& string, MatchingOptions options, const Range& range) const;
        /**
         * @brief Calls `-[NSRegularExpression replaceMatchesInString:options:range:withTemplate:]`.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param templ Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t replace_matches_in_string(const std::string& string, MatchingOptions options, const Range& range, const std::string& templ) const;
        /**
         * @brief Calls `-[NSRegularExpression replacementStringForResult:inString:offset:template:]`.
         * @details For clients implementing their own replace functionality, this is a method to perform the template substitution for a single result, given the string from which the result was matched, an offset to be added to the location of the result in the string (for example, in case modifications to the string moved the result since it was matched), and a replacement template.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param offset Argument converted to the Objective-C parameter of the same role.
         * @param templ Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string replacement_string_for_result(const TextCheckingResult& result, const std::string& string, std::int64_t offset, const std::string& templ) const;
        /**
         * @brief Calls `-[NSRegularExpression stringByReplacingMatchesInString:options:range:withTemplate:]`.
         * @details NSRegularExpression also provides find-and-replace methods for both immutable and mutable strings. The replacement is treated as a template, with $0 being replaced by the contents of the matched range, $1 by the contents of the first capture group, and so on. Additional digits beyond the maximum required to represent the number of capture groups will be treated as ordinary characters, as will a $ not followed by digits. Backslash will escape both $ and itself.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param templ Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_by_replacing_matches_in_string(const std::string& string, MatchingOptions options, const Range& range, const std::string& templ) const;
        /**
         * @brief Returns the `numberOfCaptureGroups` property of `NSRegularExpression`.
         * @return The converted Objective-C result.
         */
        std::uint64_t number_of_capture_groups() const;
        /**
         * @brief Returns the `options` property of `NSRegularExpression`.
         * @return The converted Objective-C result.
         */
        RegularExpressionOptions options() const;
        /**
         * @brief Returns the `pattern` property of `NSRegularExpression`.
         * @return The converted Objective-C result.
         */
        std::string pattern() const;
    };
}
