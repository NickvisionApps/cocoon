#include "generated/attributed_string_markdown_parsing_options.h"
#include "internal.h"

namespace cocoon
{
    AttributedStringMarkdownParsingOptions::AttributedStringMarkdownParsingOptions() : AttributedStringMarkdownParsingOptions(Adopt{cocoon::internal::retain([[::NSAttributedStringMarkdownParsingOptions alloc] init])})
    {
    }

    AttributedStringMarkdownParsingOptions::AttributedStringMarkdownParsingOptions(std::nullptr_t) : Object(nullptr)
    {
    }

    AttributedStringMarkdownParsingOptions::AttributedStringMarkdownParsingOptions(Adopt adopt) : Object(adopt)
    {
    }

    bool AttributedStringMarkdownParsingOptions::allows_extended_attributes() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSAttributedStringMarkdownParsingOptions>(this) allowsExtendedAttributes]);
    }

    void AttributedStringMarkdownParsingOptions::set_allows_extended_attributes(bool value) const
    {
        [cocoon::internal::ns<::NSAttributedStringMarkdownParsingOptions>(this) setAllowsExtendedAttributes:static_cast<::BOOL>(value)];
    }

    bool AttributedStringMarkdownParsingOptions::applies_source_position_attributes() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSAttributedStringMarkdownParsingOptions>(this) appliesSourcePositionAttributes]);
    }

    void AttributedStringMarkdownParsingOptions::set_applies_source_position_attributes(bool value) const
    {
        [cocoon::internal::ns<::NSAttributedStringMarkdownParsingOptions>(this) setAppliesSourcePositionAttributes:static_cast<::BOOL>(value)];
    }

    AttributedStringMarkdownParsingFailurePolicy AttributedStringMarkdownParsingOptions::failure_policy() const
    {
        return static_cast<AttributedStringMarkdownParsingFailurePolicy>([cocoon::internal::ns<::NSAttributedStringMarkdownParsingOptions>(this) failurePolicy]);
    }

    void AttributedStringMarkdownParsingOptions::set_failure_policy(AttributedStringMarkdownParsingFailurePolicy value) const
    {
        [cocoon::internal::ns<::NSAttributedStringMarkdownParsingOptions>(this) setFailurePolicy:static_cast<::NSAttributedStringMarkdownParsingFailurePolicy>(value)];
    }

    AttributedStringMarkdownInterpretedSyntax AttributedStringMarkdownParsingOptions::interpreted_syntax() const
    {
        return static_cast<AttributedStringMarkdownInterpretedSyntax>([cocoon::internal::ns<::NSAttributedStringMarkdownParsingOptions>(this) interpretedSyntax]);
    }

    void AttributedStringMarkdownParsingOptions::set_interpreted_syntax(AttributedStringMarkdownInterpretedSyntax value) const
    {
        [cocoon::internal::ns<::NSAttributedStringMarkdownParsingOptions>(this) setInterpretedSyntax:static_cast<::NSAttributedStringMarkdownInterpretedSyntax>(value)];
    }

    std::string AttributedStringMarkdownParsingOptions::language_code() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAttributedStringMarkdownParsingOptions>(this) languageCode]);
    }

    void AttributedStringMarkdownParsingOptions::set_language_code(const std::string& value) const
    {
        [cocoon::internal::ns<::NSAttributedStringMarkdownParsingOptions>(this) setLanguageCode:cocoon::internal::to(value)];
    }
}
