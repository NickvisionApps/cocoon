#include "generated/text_finder.h"
#include "internal.h"

namespace cocoon
{
    TextFinder::TextFinder() : TextFinder(Adopt{cocoon::internal::retain([[::NSTextFinder alloc] init])})
    {
    }

    TextFinder::TextFinder(std::nullptr_t) : Object(nullptr)
    {
    }

    TextFinder::TextFinder(Adopt adopt) : Object(adopt)
    {
    }

    void TextFinder::cancel_find_indicator() const
    {
        [cocoon::internal::ns<::NSTextFinder>(this) cancelFindIndicator];
    }

    void TextFinder::draw_incremental_match_highlight_in_rect(const Rect& rect)
    {
        [::NSTextFinder drawIncrementalMatchHighlightInRect:cocoon::internal::to(rect)];
    }

    void TextFinder::note_client_string_will_change() const
    {
        [cocoon::internal::ns<::NSTextFinder>(this) noteClientStringWillChange];
    }

    void TextFinder::perform_action(TextFinderAction op) const
    {
        [cocoon::internal::ns<::NSTextFinder>(this) performAction:static_cast<::NSTextFinderAction>(op)];
    }

    bool TextFinder::validate_action(TextFinderAction op) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextFinder>(this) validateAction:static_cast<::NSTextFinderAction>(op)]);
    }

    Object TextFinder::client() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTextFinder>(this) client]);
    }

    void TextFinder::set_client(const Object& value) const
    {
        [cocoon::internal::ns<::NSTextFinder>(this) setClient:cocoon::internal::native_id(value)];
    }

    Object TextFinder::find_bar_container() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTextFinder>(this) findBarContainer]);
    }

    void TextFinder::set_find_bar_container(const Object& value) const
    {
        [cocoon::internal::ns<::NSTextFinder>(this) setFindBarContainer:cocoon::internal::native_id(value)];
    }

    bool TextFinder::find_indicator_needs_update() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextFinder>(this) findIndicatorNeedsUpdate]);
    }

    void TextFinder::set_find_indicator_needs_update(bool value) const
    {
        [cocoon::internal::ns<::NSTextFinder>(this) setFindIndicatorNeedsUpdate:static_cast<::BOOL>(value)];
    }

    std::vector<Value> TextFinder::incremental_match_ranges() const
    {
        return cocoon::internal::from_array<Value>([cocoon::internal::ns<::NSTextFinder>(this) incrementalMatchRanges], [](id e) -> Value
                                     {
                                         return cocoon::internal::wrap<Value>((::NSValue*)e);
                                     });
    }

    bool TextFinder::is_incremental_searching_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextFinder>(this) isIncrementalSearchingEnabled]);
    }

    void TextFinder::set_incremental_searching_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSTextFinder>(this) setIncrementalSearchingEnabled:static_cast<::BOOL>(value)];
    }

    bool TextFinder::incremental_searching_should_dim_content_view() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextFinder>(this) incrementalSearchingShouldDimContentView]);
    }

    void TextFinder::set_incremental_searching_should_dim_content_view(bool value) const
    {
        [cocoon::internal::ns<::NSTextFinder>(this) setIncrementalSearchingShouldDimContentView:static_cast<::BOOL>(value)];
    }
}
