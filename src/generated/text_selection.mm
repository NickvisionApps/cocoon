#include "generated/text_selection.h"
#include "internal.h"

namespace cocoon
{
    TextSelection::TextSelection(const Object& location, TextSelectionAffinity affinity) : TextSelection(Adopt{cocoon::internal::retain([[::NSTextSelection alloc] initWithLocation:cocoon::internal::native_id(location) affinity:static_cast<::NSTextSelectionAffinity>(affinity)])})
    {
    }

    TextSelection::TextSelection(const TextRange& range, TextSelectionAffinity affinity, TextSelectionGranularity granularity) : TextSelection(Adopt{cocoon::internal::retain([[::NSTextSelection alloc] initWithRange:cocoon::internal::native<::NSTextRange>(range) affinity:static_cast<::NSTextSelectionAffinity>(affinity) granularity:static_cast<::NSTextSelectionGranularity>(granularity)])})
    {
    }

    TextSelection::TextSelection(const std::vector<TextRange>& text_ranges, TextSelectionAffinity affinity, TextSelectionGranularity granularity) : TextSelection(Adopt{cocoon::internal::retain([[::NSTextSelection alloc] initWithRanges:cocoon::internal::to_array(text_ranges, [](const TextRange& e) -> id
                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                              return cocoon::internal::native<::NSTextRange>(e);
                                                                                                                                                                                                                                          })
                                                                                                                                                                                                                    affinity:static_cast<::NSTextSelectionAffinity>(affinity)
                                                                                                                                                                                                                 granularity:static_cast<::NSTextSelectionGranularity>(granularity)])})
    {
    }

    TextSelection::TextSelection() : Object(nullptr)
    {
    }

    TextSelection::TextSelection(std::nullptr_t) : Object(nullptr)
    {
    }

    TextSelection::TextSelection(Adopt adopt) : Object(adopt)
    {
    }

    TextSelection TextSelection::text_selection_with_text_ranges(const std::vector<TextRange>& text_ranges) const
    {
        return cocoon::internal::wrap<TextSelection>([cocoon::internal::ns<::NSTextSelection>(this) textSelectionWithTextRanges:cocoon::internal::to_array(text_ranges, [](const TextRange& e) -> id
                                                                                                                 {
                                                                                                                     return cocoon::internal::native<::NSTextRange>(e);
                                                                                                                 })]);
    }

    TextSelectionAffinity TextSelection::affinity() const
    {
        return static_cast<TextSelectionAffinity>([cocoon::internal::ns<::NSTextSelection>(this) affinity]);
    }

    double TextSelection::anchor_position_offset() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextSelection>(this) anchorPositionOffset]);
    }

    void TextSelection::set_anchor_position_offset(double value) const
    {
        [cocoon::internal::ns<::NSTextSelection>(this) setAnchorPositionOffset:static_cast<::CGFloat>(value)];
    }

    TextSelectionGranularity TextSelection::granularity() const
    {
        return static_cast<TextSelectionGranularity>([cocoon::internal::ns<::NSTextSelection>(this) granularity]);
    }

    bool TextSelection::is_logical() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextSelection>(this) isLogical]);
    }

    void TextSelection::set_logical(bool value) const
    {
        [cocoon::internal::ns<::NSTextSelection>(this) setLogical:static_cast<::BOOL>(value)];
    }

    Object TextSelection::secondary_selection_location() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTextSelection>(this) secondarySelectionLocation]);
    }

    void TextSelection::set_secondary_selection_location(const Object& value) const
    {
        [cocoon::internal::ns<::NSTextSelection>(this) setSecondarySelectionLocation:cocoon::internal::native_id(value)];
    }

    std::vector<TextRange> TextSelection::text_ranges() const
    {
        return cocoon::internal::from_array<TextRange>([cocoon::internal::ns<::NSTextSelection>(this) textRanges], [](id e) -> TextRange
                                         {
                                             return cocoon::internal::wrap<TextRange>((::NSTextRange*)e);
                                         });
    }

    bool TextSelection::is_transient() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextSelection>(this) isTransient]);
    }

    std::map<std::string, Object> TextSelection::typing_attributes() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSTextSelection>(this) typingAttributes], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    void TextSelection::set_typing_attributes(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSTextSelection>(this) setTypingAttributes:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                               {
                                                                                   return cocoon::internal::to(k);
                                                                               },
                                                                               [](const Object& v) -> id
                                                                               {
                                                                                   return cocoon::internal::native_id(v);
                                                                               })];
    }
}
