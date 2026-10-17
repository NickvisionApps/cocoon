#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSAttributedStringMarkdownParsingOptions` (Foundation).
     * @details Options that affect the parsing of Markdown content into an attributed string.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::AttributedStringMarkdownParsingOptions attributed_string_markdown_parsing_options;
     * attributed_string_markdown_parsing_options.set_allows_extended_attributes(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::AttributedStringMarkdownParsingOptions attributed_string_markdown_parsing_options{};
     * attributed_string_markdown_parsing_options.set_allows_extended_attributes(true);
     * auto allows_extended_attributes = attributed_string_markdown_parsing_options.allows_extended_attributes();
     * attributed_string_markdown_parsing_options.set_applies_source_position_attributes(true);
     * auto applies_source_position_attributes = attributed_string_markdown_parsing_options.applies_source_position_attributes();
     * attributed_string_markdown_parsing_options.set_failure_policy(cocoon::AttributedStringMarkdownParsingFailurePolicy::Error);
     * auto failure_policy = attributed_string_markdown_parsing_options.failure_policy();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsattributedstringmarkdownparsingoptions
     */
    class AttributedStringMarkdownParsingOptions : public Object
    {
    public:
        /// @brief Creates a new `NSAttributedStringMarkdownParsingOptions` instance and returns a handle to it.
        explicit AttributedStringMarkdownParsingOptions();
        /// @brief Creates a null handle that refers to no native object.
        AttributedStringMarkdownParsingOptions(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit AttributedStringMarkdownParsingOptions(Adopt adopt);
        /**
     * @brief Returns the `allowsExtendedAttributes` property of `NSAttributedStringMarkdownParsingOptions`.
     * @details A Boolean value that indicates whether parsing allows extensions to Markdown that specify extended attributes. Defaults to 'NO' (only parse CommonMark syntax).
     * @return The converted Objective-C result.
     */
        bool allows_extended_attributes() const;
        /**
     * @brief Sets the `allowsExtendedAttributes` property of `NSAttributedStringMarkdownParsingOptions`.
     * @details A Boolean value that indicates whether parsing allows extensions to Markdown that specify extended attributes. Defaults to 'NO' (only parse CommonMark syntax).
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_extended_attributes(bool value) const;
        /**
     * @brief Returns the `appliesSourcePositionAttributes` property of `NSAttributedStringMarkdownParsingOptions`.
     * @details A Boolean value that indicates whether parsing applies attributes that indicate the position of attributed text in the original Markdown string.
     * @return The converted Objective-C result.
     */
        bool applies_source_position_attributes() const;
        /**
     * @brief Sets the `appliesSourcePositionAttributes` property of `NSAttributedStringMarkdownParsingOptions`.
     * @details A Boolean value that indicates whether parsing applies attributes that indicate the position of attributed text in the original Markdown string.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_applies_source_position_attributes(bool value) const;
        /**
     * @brief Returns the `failurePolicy` property of `NSAttributedStringMarkdownParsingOptions`.
     * @details The policy for handling a parsing failure. The default is 'NSAttributedStringMarkdownParsingFailureReturnError'.
     * @return The converted Objective-C result.
     */
        AttributedStringMarkdownParsingFailurePolicy failure_policy() const;
        /**
     * @brief Sets the `failurePolicy` property of `NSAttributedStringMarkdownParsingOptions`.
     * @details The policy for handling a parsing failure. The default is 'NSAttributedStringMarkdownParsingFailureReturnError'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_failure_policy(AttributedStringMarkdownParsingFailurePolicy value) const;
        /**
     * @brief Returns the `interpretedSyntax` property of `NSAttributedStringMarkdownParsingOptions`.
     * @details The syntax for interpreting a Markdown string. If your Markdown data uses syntax that this setting excludes, the parser still parses it and includes its text in the final result. However, the relevant text won't have attributes.
     * @return The converted Objective-C result.
     */
        AttributedStringMarkdownInterpretedSyntax interpreted_syntax() const;
        /**
     * @brief Sets the `interpretedSyntax` property of `NSAttributedStringMarkdownParsingOptions`.
     * @details The syntax for interpreting a Markdown string. If your Markdown data uses syntax that this setting excludes, the parser still parses it and includes its text in the final result. However, the relevant text won't have attributes.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_interpreted_syntax(AttributedStringMarkdownInterpretedSyntax value) const;
        /**
     * @brief Returns the `languageCode` property of `NSAttributedStringMarkdownParsingOptions`.
     * @details The BCP-47 language code for this document. If not 'nil', the 'NSLanguageIdentifierAttributeName' attribute will be applied to any range in the returned string that doesn't otherwise specify a language attribute. The default is 'nil', which applies no attributes.
     * @return The converted Objective-C result.
     */
        std::string language_code() const;
        /**
     * @brief Sets the `languageCode` property of `NSAttributedStringMarkdownParsingOptions`.
     * @details The BCP-47 language code for this document. If not 'nil', the 'NSLanguageIdentifierAttributeName' attribute will be applied to any range in the returned string that doesn't otherwise specify a language attribute. The default is 'nil', which applies no attributes.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_language_code(const std::string& value) const;
    };
}
