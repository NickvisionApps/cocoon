#include "generated/text_line_fragment.h"
#include "internal.h"

namespace cocoon
{
    TextLineFragment::TextLineFragment(const AttributedString& attributed_string, const Range& range) : TextLineFragment(Adopt{cocoon::internal::retain([[::NSTextLineFragment alloc] initWithAttributedString:cocoon::internal::native<::NSAttributedString>(attributed_string) range:cocoon::internal::to(range)])})
    {
    }

    TextLineFragment::TextLineFragment(const std::string& string, const std::map<std::string, Object>& attributes, const Range& range) : TextLineFragment(Adopt{cocoon::internal::retain([[::NSTextLineFragment alloc] initWithString:cocoon::internal::to(string)
                                                                                                                                                                                                                           attributes:cocoon::internal::to_dictionary(attributes, [](const std::string& k) -> id
                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                          return cocoon::internal::to(k);
                                                                                                                                                                                                                                                                      },
                                                                                                                                                                                                                                                                      [](const Object& v) -> id
                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                          return cocoon::internal::native_id(v);
                                                                                                                                                                                                                                                                      })
                                                                                                                                                                                                                                range:cocoon::internal::to(range)])})
    {
    }

    TextLineFragment::TextLineFragment() : Object(nullptr)
    {
    }

    TextLineFragment::TextLineFragment(std::nullptr_t) : Object(nullptr)
    {
    }

    TextLineFragment::TextLineFragment(Adopt adopt) : Object(adopt)
    {
    }

    std::int64_t TextLineFragment::character_index_for_point(const Point& point) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTextLineFragment>(this) characterIndexForPoint:cocoon::internal::to(point)]);
    }

    void TextLineFragment::draw_at_point(const Point& point, const CGContext& context) const
    {
        [cocoon::internal::ns<::NSTextLineFragment>(this) drawAtPoint:cocoon::internal::to(point) inContext:((::CGContextRef)(context).handle())];
    }

    double TextLineFragment::fraction_of_distance_through_glyph_for_point(const Point& point) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextLineFragment>(this) fractionOfDistanceThroughGlyphForPoint:cocoon::internal::to(point)]);
    }

    Point TextLineFragment::location_for_character_at_index(std::int64_t index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextLineFragment>(this) locationForCharacterAtIndex:static_cast<::NSInteger>(index)]);
    }

    AttributedString TextLineFragment::attributed_string() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSTextLineFragment>(this) attributedString]);
    }

    Range TextLineFragment::character_range() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextLineFragment>(this) characterRange]);
    }

    Point TextLineFragment::glyph_origin() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextLineFragment>(this) glyphOrigin]);
    }

    Rect TextLineFragment::typographic_bounds() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextLineFragment>(this) typographicBounds]);
    }
}
