#include "generated/text_layout_fragment.h"
#include "internal.h"

namespace cocoon
{
    TextLayoutFragment::TextLayoutFragment(const TextElement& text_element, const TextRange& range_in_element) : TextLayoutFragment(Adopt{cocoon::internal::retain([[::NSTextLayoutFragment alloc] initWithTextElement:cocoon::internal::native<::NSTextElement>(text_element) range:cocoon::internal::native<::NSTextRange>(range_in_element)])})
    {
    }

    TextLayoutFragment::TextLayoutFragment() : Object(nullptr)
    {
    }

    TextLayoutFragment::TextLayoutFragment(std::nullptr_t) : Object(nullptr)
    {
    }

    TextLayoutFragment::TextLayoutFragment(Adopt adopt) : Object(adopt)
    {
    }

    void TextLayoutFragment::draw_at_point(const Point& point, const CGContext& context) const
    {
        [cocoon::internal::ns<::NSTextLayoutFragment>(this) drawAtPoint:cocoon::internal::to(point) inContext:((::CGContextRef)(context).handle())];
    }

    Rect TextLayoutFragment::frame_for_text_attachment_at_location(const Object& location) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextLayoutFragment>(this) frameForTextAttachmentAtLocation:cocoon::internal::native_id(location)]);
    }

    void TextLayoutFragment::invalidate_layout() const
    {
        [cocoon::internal::ns<::NSTextLayoutFragment>(this) invalidateLayout];
    }

    TextLineFragment TextLayoutFragment::text_line_fragment_for_text_location(const Object& text_location, bool is_upstream_affinity) const
    {
        return cocoon::internal::wrap<TextLineFragment>([cocoon::internal::ns<::NSTextLayoutFragment>(this) textLineFragmentForTextLocation:cocoon::internal::native_id(text_location) isUpstreamAffinity:static_cast<::BOOL>(is_upstream_affinity)]);
    }

    TextLineFragment TextLayoutFragment::text_line_fragment_for_vertical_offset(double vertical_offset, bool requires_exact_match) const
    {
        return cocoon::internal::wrap<TextLineFragment>([cocoon::internal::ns<::NSTextLayoutFragment>(this) textLineFragmentForVerticalOffset:static_cast<::CGFloat>(vertical_offset) requiresExactMatch:static_cast<::BOOL>(requires_exact_match)]);
    }

    double TextLayoutFragment::bottom_margin() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextLayoutFragment>(this) bottomMargin]);
    }

    Rect TextLayoutFragment::layout_fragment_frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextLayoutFragment>(this) layoutFragmentFrame]);
    }

    OperationQueue TextLayoutFragment::layout_queue() const
    {
        return cocoon::internal::wrap<OperationQueue>([cocoon::internal::ns<::NSTextLayoutFragment>(this) layoutQueue]);
    }

    void TextLayoutFragment::set_layout_queue(const OperationQueue& value) const
    {
        [cocoon::internal::ns<::NSTextLayoutFragment>(this) setLayoutQueue:cocoon::internal::native<::NSOperationQueue>(value)];
    }

    double TextLayoutFragment::leading_padding() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextLayoutFragment>(this) leadingPadding]);
    }

    TextRange TextLayoutFragment::range_in_element() const
    {
        return cocoon::internal::wrap<TextRange>([cocoon::internal::ns<::NSTextLayoutFragment>(this) rangeInElement]);
    }

    Rect TextLayoutFragment::rendering_surface_bounds() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextLayoutFragment>(this) renderingSurfaceBounds]);
    }

    TextLayoutFragmentState TextLayoutFragment::state() const
    {
        return static_cast<TextLayoutFragmentState>([cocoon::internal::ns<::NSTextLayoutFragment>(this) state]);
    }

    std::vector<TextAttachmentViewProvider> TextLayoutFragment::text_attachment_view_providers() const
    {
        return cocoon::internal::from_array<TextAttachmentViewProvider>([cocoon::internal::ns<::NSTextLayoutFragment>(this) textAttachmentViewProviders], [](id e) -> TextAttachmentViewProvider
                                                                        {
                                                                            return cocoon::internal::wrap<TextAttachmentViewProvider>((::NSTextAttachmentViewProvider*)e);
                                                                        });
    }

    TextElement TextLayoutFragment::text_element() const
    {
        return cocoon::internal::wrap<TextElement>([cocoon::internal::ns<::NSTextLayoutFragment>(this) textElement]);
    }

    TextLayoutManager TextLayoutFragment::text_layout_manager() const
    {
        return cocoon::internal::wrap<TextLayoutManager>([cocoon::internal::ns<::NSTextLayoutFragment>(this) textLayoutManager]);
    }

    std::vector<TextLineFragment> TextLayoutFragment::text_line_fragments() const
    {
        return cocoon::internal::from_array<TextLineFragment>([cocoon::internal::ns<::NSTextLayoutFragment>(this) textLineFragments], [](id e) -> TextLineFragment
                                                              {
                                                                  return cocoon::internal::wrap<TextLineFragment>((::NSTextLineFragment*)e);
                                                              });
    }

    double TextLayoutFragment::top_margin() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextLayoutFragment>(this) topMargin]);
    }

    double TextLayoutFragment::trailing_padding() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextLayoutFragment>(this) trailingPadding]);
    }
}
