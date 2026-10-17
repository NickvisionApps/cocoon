#include "generated/text_element.h"
#include "internal.h"

namespace cocoon
{
    TextElement::TextElement(const TextContentManager& text_content_manager) : TextElement(Adopt{cocoon::internal::retain([[::NSTextElement alloc] initWithTextContentManager:cocoon::internal::native<::NSTextContentManager>(text_content_manager)])})
    {
    }

    TextElement::TextElement() : TextElement(Adopt{cocoon::internal::retain([[::NSTextElement alloc] init])})
    {
    }

    TextElement::TextElement(std::nullptr_t) : Object(nullptr)
    {
    }

    TextElement::TextElement(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<TextElement> TextElement::child_elements() const
    {
        return cocoon::internal::from_array<TextElement>([cocoon::internal::ns<::NSTextElement>(this) childElements], [](id e) -> TextElement
                                                         {
                                                             return cocoon::internal::wrap<TextElement>((::NSTextElement*)e);
                                                         });
    }

    TextRange TextElement::element_range() const
    {
        return cocoon::internal::wrap<TextRange>([cocoon::internal::ns<::NSTextElement>(this) elementRange]);
    }

    void TextElement::set_element_range(const TextRange& value) const
    {
        [cocoon::internal::ns<::NSTextElement>(this) setElementRange:cocoon::internal::native<::NSTextRange>(value)];
    }

    bool TextElement::is_represented_element() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextElement>(this) isRepresentedElement]);
    }

    TextElement TextElement::parent_element() const
    {
        return cocoon::internal::wrap<TextElement>([cocoon::internal::ns<::NSTextElement>(this) parentElement]);
    }

    TextContentManager TextElement::text_content_manager() const
    {
        return cocoon::internal::wrap<TextContentManager>([cocoon::internal::ns<::NSTextElement>(this) textContentManager]);
    }

    void TextElement::set_text_content_manager(const TextContentManager& value) const
    {
        [cocoon::internal::ns<::NSTextElement>(this) setTextContentManager:cocoon::internal::native<::NSTextContentManager>(value)];
    }
}
