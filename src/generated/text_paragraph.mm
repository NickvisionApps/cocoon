#include "generated/text_paragraph.h"
#include "internal.h"

namespace cocoon
{
    TextParagraph::TextParagraph(const AttributedString& attributed_string) : TextParagraph(Adopt{cocoon::internal::retain([[::NSTextParagraph alloc] initWithAttributedString:cocoon::internal::native<::NSAttributedString>(attributed_string)])})
    {
    }

    TextParagraph::TextParagraph() : TextParagraph(Adopt{cocoon::internal::retain([[::NSTextParagraph alloc] init])})
    {
    }

    TextParagraph::TextParagraph(std::nullptr_t) : TextElement(nullptr)
    {
    }

    TextParagraph::TextParagraph(Adopt adopt) : TextElement(adopt)
    {
    }

    AttributedString TextParagraph::attributed_string() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSTextParagraph>(this) attributedString]);
    }

    TextRange TextParagraph::paragraph_content_range() const
    {
        return cocoon::internal::wrap<TextRange>([cocoon::internal::ns<::NSTextParagraph>(this) paragraphContentRange]);
    }

    TextRange TextParagraph::paragraph_separator_range() const
    {
        return cocoon::internal::wrap<TextRange>([cocoon::internal::ns<::NSTextParagraph>(this) paragraphSeparatorRange]);
    }
}
