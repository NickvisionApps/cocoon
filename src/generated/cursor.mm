#include "generated/cursor.h"
#include "internal.h"

namespace cocoon
{
    Cursor::Cursor(const Image& new_image, const Point& point) : Cursor(Adopt{cocoon::internal::retain([[::NSCursor alloc] initWithImage:cocoon::internal::native<::NSImage>(new_image) hotSpot:cocoon::internal::to(point)])})
    {
    }

    Cursor::Cursor() : Cursor(Adopt{cocoon::internal::retain([[::NSCursor alloc] init])})
    {
    }

    Cursor::Cursor(std::nullptr_t) : Object(nullptr)
    {
    }

    Cursor::Cursor(Adopt adopt) : Object(adopt)
    {
    }

    Cursor Cursor::column_resize_cursor_in_directions(HorizontalDirections directions)
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor columnResizeCursorInDirections:static_cast<::NSHorizontalDirections>(directions)]);
    }

    Cursor Cursor::frame_resize_cursor_from_position(CursorFrameResizePosition position, CursorFrameResizeDirections directions)
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor frameResizeCursorFromPosition:static_cast<::NSCursorFrameResizePosition>(position) inDirections:static_cast<::NSCursorFrameResizeDirections>(directions)]);
    }

    void Cursor::hide()
    {
        [::NSCursor hide];
    }

    void Cursor::pop() const
    {
        [cocoon::internal::ns<::NSCursor>(this) pop];
    }

    void Cursor::push() const
    {
        [cocoon::internal::ns<::NSCursor>(this) push];
    }

    Cursor Cursor::row_resize_cursor_in_directions(VerticalDirections directions)
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor rowResizeCursorInDirections:static_cast<::NSVerticalDirections>(directions)]);
    }

    void Cursor::set() const
    {
        [cocoon::internal::ns<::NSCursor>(this) set];
    }

    void Cursor::set_hidden_until_mouse_moves(bool flag)
    {
        [::NSCursor setHiddenUntilMouseMoves:static_cast<::BOOL>(flag)];
    }

    void Cursor::unhide()
    {
        [::NSCursor unhide];
    }

    Cursor Cursor::i_beam_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor IBeamCursor]);
    }

    Cursor Cursor::i_beam_cursor_for_vertical_layout()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor IBeamCursorForVerticalLayout]);
    }

    Cursor Cursor::arrow_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor arrowCursor]);
    }

    Cursor Cursor::closed_hand_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor closedHandCursor]);
    }

    Cursor Cursor::column_resize_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor columnResizeCursor]);
    }

    Cursor Cursor::contextual_menu_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor contextualMenuCursor]);
    }

    Cursor Cursor::crosshair_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor crosshairCursor]);
    }

    Cursor Cursor::current_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor currentCursor]);
    }

    Cursor Cursor::current_system_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor currentSystemCursor]);
    }

    Cursor Cursor::disappearing_item_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor disappearingItemCursor]);
    }

    Cursor Cursor::drag_copy_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor dragCopyCursor]);
    }

    Cursor Cursor::drag_link_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor dragLinkCursor]);
    }

    Point Cursor::hot_spot() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCursor>(this) hotSpot]);
    }

    Image Cursor::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSCursor>(this) image]);
    }

    Cursor Cursor::open_hand_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor openHandCursor]);
    }

    Cursor Cursor::operation_not_allowed_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor operationNotAllowedCursor]);
    }

    Cursor Cursor::pointing_hand_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor pointingHandCursor]);
    }

    Cursor Cursor::resize_down_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor resizeDownCursor]);
    }

    Cursor Cursor::resize_left_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor resizeLeftCursor]);
    }

    Cursor Cursor::resize_left_right_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor resizeLeftRightCursor]);
    }

    Cursor Cursor::resize_right_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor resizeRightCursor]);
    }

    Cursor Cursor::resize_up_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor resizeUpCursor]);
    }

    Cursor Cursor::resize_up_down_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor resizeUpDownCursor]);
    }

    Cursor Cursor::row_resize_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor rowResizeCursor]);
    }

    Cursor Cursor::zoom_in_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor zoomInCursor]);
    }

    Cursor Cursor::zoom_out_cursor()
    {
        return cocoon::internal::wrap<Cursor>([::NSCursor zoomOutCursor]);
    }
}
