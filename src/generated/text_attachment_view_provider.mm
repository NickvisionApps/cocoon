#include "generated/text_attachment_view_provider.h"
#include "internal.h"

namespace cocoon
{
    TextAttachmentViewProvider::TextAttachmentViewProvider(const TextAttachment& text_attachment, const View& parent_view, const TextLayoutManager& text_layout_manager, const Object& location) : TextAttachmentViewProvider(Adopt{cocoon::internal::retain([[::NSTextAttachmentViewProvider alloc] initWithTextAttachment:cocoon::internal::native<::NSTextAttachment>(text_attachment) parentView:cocoon::internal::native<::NSView>(parent_view) textLayoutManager:cocoon::internal::native<::NSTextLayoutManager>(text_layout_manager) location:cocoon::internal::native_id(location)])})
    {
    }

    TextAttachmentViewProvider::TextAttachmentViewProvider() : Object(nullptr)
    {
    }

    TextAttachmentViewProvider::TextAttachmentViewProvider(std::nullptr_t) : Object(nullptr)
    {
    }

    TextAttachmentViewProvider::TextAttachmentViewProvider(Adopt adopt) : Object(adopt)
    {
    }

    Rect TextAttachmentViewProvider::attachment_bounds_for_attributes(const std::map<std::string, Object>& attributes, const Object& location, const TextContainer& text_container, const Rect& proposed_line_fragment, const Point& position) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextAttachmentViewProvider>(this) attachmentBoundsForAttributes:cocoon::internal::to_dictionary(attributes, [](const std::string& k) -> id
                                                                                                                                                                {
                                                                                                                                                                    return cocoon::internal::to(k);
                                                                                                                                                                },
                                                                                                                                                                [](const Object& v) -> id
                                                                                                                                                                {
                                                                                                                                                                    return cocoon::internal::native_id(v);
                                                                                                                                                                })
                                                                                                                       location:cocoon::internal::native_id(location)
                                                                                                                  textContainer:cocoon::internal::native<::NSTextContainer>(text_container)
                                                                                                           proposedLineFragment:cocoon::internal::to(proposed_line_fragment)
                                                                                                                       position:cocoon::internal::to(position)]);
    }

    void TextAttachmentViewProvider::load_view() const
    {
        [cocoon::internal::ns<::NSTextAttachmentViewProvider>(this) loadView];
    }

    TextAttachment TextAttachmentViewProvider::text_attachment() const
    {
        return cocoon::internal::wrap<TextAttachment>([cocoon::internal::ns<::NSTextAttachmentViewProvider>(this) textAttachment]);
    }

    TextLayoutManager TextAttachmentViewProvider::text_layout_manager() const
    {
        return cocoon::internal::wrap<TextLayoutManager>([cocoon::internal::ns<::NSTextAttachmentViewProvider>(this) textLayoutManager]);
    }

    bool TextAttachmentViewProvider::tracks_text_attachment_view_bounds() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextAttachmentViewProvider>(this) tracksTextAttachmentViewBounds]);
    }

    void TextAttachmentViewProvider::set_tracks_text_attachment_view_bounds(bool value) const
    {
        [cocoon::internal::ns<::NSTextAttachmentViewProvider>(this) setTracksTextAttachmentViewBounds:static_cast<::BOOL>(value)];
    }

    View TextAttachmentViewProvider::view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSTextAttachmentViewProvider>(this) view]);
    }

    void TextAttachmentViewProvider::set_view(const View& value) const
    {
        [cocoon::internal::ns<::NSTextAttachmentViewProvider>(this) setView:cocoon::internal::native<::NSView>(value)];
    }
}
