#include "generated/text_list_element.h"
#include "internal.h"

namespace cocoon
{
    TextListElement::TextListElement(const TextListElement& parent, const TextList& text_list, const AttributedString& contents, const std::map<std::string, Object>& marker_attributes, const std::vector<TextListElement>& children) : TextListElement(Adopt{cocoon::internal::retain([[::NSTextListElement alloc] initWithParentElement:cocoon::internal::native<::NSTextListElement>(parent)
                                                                                                                                                                                                                                                                                                                                  textList:cocoon::internal::native<::NSTextList>(text_list)
                                                                                                                                                                                                                                                                                                                                  contents:cocoon::internal::native<::NSAttributedString>(contents)
                                                                                                                                                                                                                                                                                                                          markerAttributes:cocoon::internal::to_dictionary(marker_attributes, [](const std::string& k) -> id
                                                                                                                                                                                                                                                                                                                                                                           {
                                                                                                                                                                                                                                                                                                                                                                               return cocoon::internal::to(k);
                                                                                                                                                                                                                                                                                                                                                                           },
                                                                                                                                                                                                                                                                                                                                                                           [](const Object& v) -> id
                                                                                                                                                                                                                                                                                                                                                                           {
                                                                                                                                                                                                                                                                                                                                                                               return cocoon::internal::native_id(v);
                                                                                                                                                                                                                                                                                                                                                                           })
                                                                                                                                                                                                                                                                                                                             childElements:cocoon::internal::to_array(children, [](const TextListElement& e) -> id
                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                          return cocoon::internal::native<::NSTextListElement>(e);
                                                                                                                                                                                                                                                                                                                                                                      })])})
    {
    }

    TextListElement::TextListElement() : TextListElement(Adopt{cocoon::internal::retain([[::NSTextListElement alloc] init])})
    {
    }

    TextListElement::TextListElement(std::nullptr_t) : TextParagraph(nullptr)
    {
    }

    TextListElement::TextListElement(Adopt adopt) : TextParagraph(adopt)
    {
    }

    TextListElement TextListElement::text_list_element_with_child_elements(const std::vector<TextListElement>& children, const TextList& text_list, std::int64_t nesting_level)
    {
        return cocoon::internal::wrap<TextListElement>([::NSTextListElement textListElementWithChildElements:cocoon::internal::to_array(children, [](const TextListElement& e) -> id
                                                                                                                                        {
                                                                                                                                            return cocoon::internal::native<::NSTextListElement>(e);
                                                                                                                                        })
                                                                                                    textList:cocoon::internal::native<::NSTextList>(text_list)
                                                                                                nestingLevel:static_cast<::NSInteger>(nesting_level)]);
    }

    TextListElement TextListElement::text_list_element_with_contents(const AttributedString& contents, const std::map<std::string, Object>& marker_attributes, const TextList& text_list, const std::vector<TextListElement>& children)
    {
        return cocoon::internal::wrap<TextListElement>([::NSTextListElement textListElementWithContents:cocoon::internal::native<::NSAttributedString>(contents)
                                                                                       markerAttributes:cocoon::internal::to_dictionary(marker_attributes, [](const std::string& k) -> id
                                                                                                                                        {
                                                                                                                                            return cocoon::internal::to(k);
                                                                                                                                        },
                                                                                                                                        [](const Object& v) -> id
                                                                                                                                        {
                                                                                                                                            return cocoon::internal::native_id(v);
                                                                                                                                        })
                                                                                               textList:cocoon::internal::native<::NSTextList>(text_list)
                                                                                          childElements:cocoon::internal::to_array(children, [](const TextListElement& e) -> id
                                                                                                                                   {
                                                                                                                                       return cocoon::internal::native<::NSTextListElement>(e);
                                                                                                                                   })]);
    }

    AttributedString TextListElement::attributed_string() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSTextListElement>(this) attributedString]);
    }

    std::vector<TextListElement> TextListElement::child_elements() const
    {
        return cocoon::internal::from_array<TextListElement>([cocoon::internal::ns<::NSTextListElement>(this) childElements], [](id e) -> TextListElement
                                                             {
                                                                 return cocoon::internal::wrap<TextListElement>((::NSTextListElement*)e);
                                                             });
    }

    AttributedString TextListElement::contents() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSTextListElement>(this) contents]);
    }

    std::map<std::string, Object> TextListElement::marker_attributes() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSTextListElement>(this) markerAttributes], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    TextListElement TextListElement::parent_element() const
    {
        return cocoon::internal::wrap<TextListElement>([cocoon::internal::ns<::NSTextListElement>(this) parentElement]);
    }

    TextList TextListElement::text_list() const
    {
        return cocoon::internal::wrap<TextList>([cocoon::internal::ns<::NSTextListElement>(this) textList]);
    }
}
