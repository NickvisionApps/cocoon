#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSAttributedStringMarkdownParsingOptions` (Foundation).
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
     * @return The converted Objective-C result.
     */
        bool allows_extended_attributes() const;
        /**
     * @brief Sets the `allowsExtendedAttributes` property of `NSAttributedStringMarkdownParsingOptions`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_extended_attributes(bool value) const;
        /**
     * @brief Returns the `appliesSourcePositionAttributes` property of `NSAttributedStringMarkdownParsingOptions`.
     * @return The converted Objective-C result.
     */
        bool applies_source_position_attributes() const;
        /**
     * @brief Sets the `appliesSourcePositionAttributes` property of `NSAttributedStringMarkdownParsingOptions`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_applies_source_position_attributes(bool value) const;
        /**
     * @brief Returns the `failurePolicy` property of `NSAttributedStringMarkdownParsingOptions`.
     * @return The converted Objective-C result.
     */
        AttributedStringMarkdownParsingFailurePolicy failure_policy() const;
        /**
     * @brief Sets the `failurePolicy` property of `NSAttributedStringMarkdownParsingOptions`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_failure_policy(AttributedStringMarkdownParsingFailurePolicy value) const;
        /**
     * @brief Returns the `interpretedSyntax` property of `NSAttributedStringMarkdownParsingOptions`.
     * @return The converted Objective-C result.
     */
        AttributedStringMarkdownInterpretedSyntax interpreted_syntax() const;
        /**
     * @brief Sets the `interpretedSyntax` property of `NSAttributedStringMarkdownParsingOptions`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_interpreted_syntax(AttributedStringMarkdownInterpretedSyntax value) const;
        /**
     * @brief Returns the `languageCode` property of `NSAttributedStringMarkdownParsingOptions`.
     * @return The converted Objective-C result.
     */
        std::string language_code() const;
        /**
     * @brief Sets the `languageCode` property of `NSAttributedStringMarkdownParsingOptions`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_language_code(const std::string& value) const;
    };
}
