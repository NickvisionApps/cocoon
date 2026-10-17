#include "generated/text_list.h"
#include "internal.h"

namespace cocoon
{
    TextList::TextList(const std::string& marker_format, std::uint64_t options) : TextList(Adopt{cocoon::internal::retain([[::NSTextList alloc] initWithMarkerFormat:cocoon::internal::to(marker_format) options:static_cast<::NSUInteger>(options)])})
    {
    }

    TextList::TextList(const std::string& marker_format, TextListOptions options, std::int64_t starting_item_number) : TextList(Adopt{cocoon::internal::retain([[::NSTextList alloc] initWithMarkerFormat:cocoon::internal::to(marker_format) options:static_cast<::NSTextListOptions>(options) startingItemNumber:static_cast<::NSInteger>(starting_item_number)])})
    {
    }

    TextList::TextList() : TextList(Adopt{cocoon::internal::retain([[::NSTextList alloc] init])})
    {
    }

    TextList::TextList(std::nullptr_t) : Object(nullptr)
    {
    }

    TextList::TextList(Adopt adopt) : Object(adopt)
    {
    }

    std::string TextList::marker_for_item_number(std::int64_t item_number) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextList>(this) markerForItemNumber:static_cast<::NSInteger>(item_number)]);
    }

    bool TextList::includes_text_list_markers()
    {
        return static_cast<bool>([::NSTextList includesTextListMarkers]);
    }

    TextListOptions TextList::list_options() const
    {
        return static_cast<TextListOptions>([cocoon::internal::ns<::NSTextList>(this) listOptions]);
    }

    std::string TextList::marker_format() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextList>(this) markerFormat]);
    }

    bool TextList::is_ordered() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextList>(this) isOrdered]);
    }

    std::int64_t TextList::starting_item_number() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTextList>(this) startingItemNumber]);
    }

    void TextList::set_starting_item_number(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSTextList>(this) setStartingItemNumber:static_cast<::NSInteger>(value)];
    }
}
