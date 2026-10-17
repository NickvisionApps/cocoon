#include "generated/text_range.h"
#include "internal.h"

namespace cocoon
{
    TextRange::TextRange(const Object& location) : TextRange(Adopt{cocoon::internal::retain([[::NSTextRange alloc] initWithLocation:cocoon::internal::native_id(location)])})
    {
    }

    TextRange::TextRange(const Object& location, const Object& end_location) : TextRange(Adopt{cocoon::internal::retain([[::NSTextRange alloc] initWithLocation:cocoon::internal::native_id(location) endLocation:cocoon::internal::native_id(end_location)])})
    {
    }

    TextRange::TextRange() : Object(nullptr)
    {
    }

    TextRange::TextRange(std::nullptr_t) : Object(nullptr)
    {
    }

    TextRange::TextRange(Adopt adopt) : Object(adopt)
    {
    }

    bool TextRange::contains_location(const Object& location) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextRange>(this) containsLocation:cocoon::internal::native_id(location)]);
    }

    bool TextRange::contains_range(const TextRange& text_range) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextRange>(this) containsRange:cocoon::internal::native<::NSTextRange>(text_range)]);
    }

    bool TextRange::intersects_with_text_range(const TextRange& text_range) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextRange>(this) intersectsWithTextRange:cocoon::internal::native<::NSTextRange>(text_range)]);
    }

    bool TextRange::is_equal_to_text_range(const TextRange& text_range) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextRange>(this) isEqualToTextRange:cocoon::internal::native<::NSTextRange>(text_range)]);
    }

    TextRange TextRange::text_range_by_forming_union_with_text_range(const TextRange& text_range) const
    {
        return cocoon::internal::wrap<TextRange>([cocoon::internal::ns<::NSTextRange>(this) textRangeByFormingUnionWithTextRange:cocoon::internal::native<::NSTextRange>(text_range)]);
    }

    TextRange TextRange::text_range_by_intersecting_with_text_range(const TextRange& text_range) const
    {
        return cocoon::internal::wrap<TextRange>([cocoon::internal::ns<::NSTextRange>(this) textRangeByIntersectingWithTextRange:cocoon::internal::native<::NSTextRange>(text_range)]);
    }

    bool TextRange::is_empty() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextRange>(this) isEmpty]);
    }
}
