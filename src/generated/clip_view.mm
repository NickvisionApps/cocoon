#include "generated/clip_view.h"
#include "internal.h"

namespace cocoon
{
    ClipView::ClipView() : ClipView(Adopt{cocoon::internal::retain([[::NSClipView alloc] init])})
    {
    }

    ClipView::ClipView(std::nullptr_t) : View(nullptr)
    {
    }

    ClipView::ClipView(Adopt adopt) : View(adopt)
    {
    }

    bool ClipView::autoscroll(const Event& event) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSClipView>(this) autoscroll:cocoon::internal::native<::NSEvent>(event)]);
    }

    Rect ClipView::constrain_bounds_rect(const Rect& proposed_bounds) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSClipView>(this) constrainBoundsRect:cocoon::internal::to(proposed_bounds)]);
    }

    void ClipView::scroll_to_point(const Point& new_origin) const
    {
        [cocoon::internal::ns<::NSClipView>(this) scrollToPoint:cocoon::internal::to(new_origin)];
    }

    void ClipView::view_bounds_changed(const Notification& notification) const
    {
        [cocoon::internal::ns<::NSClipView>(this) viewBoundsChanged:cocoon::internal::native<::NSNotification>(notification)];
    }

    void ClipView::view_frame_changed(const Notification& notification) const
    {
        [cocoon::internal::ns<::NSClipView>(this) viewFrameChanged:cocoon::internal::native<::NSNotification>(notification)];
    }

    bool ClipView::automatically_adjusts_content_insets() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSClipView>(this) automaticallyAdjustsContentInsets]);
    }

    void ClipView::set_automatically_adjusts_content_insets(bool value) const
    {
        [cocoon::internal::ns<::NSClipView>(this) setAutomaticallyAdjustsContentInsets:static_cast<::BOOL>(value)];
    }

    Color ClipView::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSClipView>(this) backgroundColor]);
    }

    void ClipView::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSClipView>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    Insets ClipView::content_insets() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSClipView>(this) contentInsets]);
    }

    void ClipView::set_content_insets(const Insets& value) const
    {
        [cocoon::internal::ns<::NSClipView>(this) setContentInsets:cocoon::internal::to(value)];
    }

    Cursor ClipView::document_cursor() const
    {
        return cocoon::internal::wrap<Cursor>([cocoon::internal::ns<::NSClipView>(this) documentCursor]);
    }

    void ClipView::set_document_cursor(const Cursor& value) const
    {
        [cocoon::internal::ns<::NSClipView>(this) setDocumentCursor:cocoon::internal::native<::NSCursor>(value)];
    }

    Rect ClipView::document_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSClipView>(this) documentRect]);
    }

    View ClipView::document_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSClipView>(this) documentView]);
    }

    void ClipView::set_document_view(const View& value) const
    {
        [cocoon::internal::ns<::NSClipView>(this) setDocumentView:cocoon::internal::native<::NSView>(value)];
    }

    Rect ClipView::document_visible_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSClipView>(this) documentVisibleRect]);
    }

    bool ClipView::draws_background() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSClipView>(this) drawsBackground]);
    }

    void ClipView::set_draws_background(bool value) const
    {
        [cocoon::internal::ns<::NSClipView>(this) setDrawsBackground:static_cast<::BOOL>(value)];
    }
}
