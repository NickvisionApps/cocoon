#include "generated/attributed_string_markdown_source_position.h"
#include "internal.h"

namespace cocoon
{
    AttributedStringMarkdownSourcePosition::AttributedStringMarkdownSourcePosition(std::int64_t start_line, std::int64_t start_column, std::int64_t end_line, std::int64_t end_column) : AttributedStringMarkdownSourcePosition(Adopt{cocoon::internal::retain([[::NSAttributedStringMarkdownSourcePosition alloc] initWithStartLine:static_cast<::NSInteger>(start_line) startColumn:static_cast<::NSInteger>(start_column) endLine:static_cast<::NSInteger>(end_line) endColumn:static_cast<::NSInteger>(end_column)])})
    {
    }

    AttributedStringMarkdownSourcePosition::AttributedStringMarkdownSourcePosition() : AttributedStringMarkdownSourcePosition(Adopt{cocoon::internal::retain([[::NSAttributedStringMarkdownSourcePosition alloc] init])})
    {
    }

    AttributedStringMarkdownSourcePosition::AttributedStringMarkdownSourcePosition(std::nullptr_t) : Object(nullptr)
    {
    }

    AttributedStringMarkdownSourcePosition::AttributedStringMarkdownSourcePosition(Adopt adopt) : Object(adopt)
    {
    }

    Range AttributedStringMarkdownSourcePosition::range_in_string(const std::string& string) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAttributedStringMarkdownSourcePosition>(this) rangeInString:cocoon::internal::to(string)]);
    }

    std::int64_t AttributedStringMarkdownSourcePosition::end_column() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSAttributedStringMarkdownSourcePosition>(this) endColumn]);
    }

    std::int64_t AttributedStringMarkdownSourcePosition::end_line() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSAttributedStringMarkdownSourcePosition>(this) endLine]);
    }

    std::int64_t AttributedStringMarkdownSourcePosition::start_column() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSAttributedStringMarkdownSourcePosition>(this) startColumn]);
    }

    std::int64_t AttributedStringMarkdownSourcePosition::start_line() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSAttributedStringMarkdownSourcePosition>(this) startLine]);
    }
}
