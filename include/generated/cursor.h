#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Image;

    /**
     * @brief C++ handle for the Objective-C class `NSCursor` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Cursor cursor;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Cursor cursor{};
     * auto made_0 = cocoon::Cursor::column_resize_cursor_in_directions(cocoon::HorizontalDirections::Left);
     * auto made_1 = cocoon::Cursor::frame_resize_cursor_from_position(cocoon::CursorFrameResizePosition::Top, cocoon::CursorFrameResizeDirections::Inward);
     * cursor.pop();
     * cursor.push();
     * cursor.set();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscursor
     */
    class Cursor : public Object
    {
    public:
        /// @brief Creates a new `NSCursor` instance and returns a handle to it.
        explicit Cursor(const Image& new_image, const Point& point);
        /// @brief Creates a new `NSCursor` instance and returns a handle to it.
        explicit Cursor();
        /// @brief Creates a null handle that refers to no native object.
        Cursor(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Cursor(Adopt adopt);
        /**
     * @brief Calls `+[NSCursor columnResizeCursorInDirections:]`.
     * @details Returns the cursor for resizing a column (vertical divider) in the specified directions. - Parameter directions: The direction in which a column can be resized.
     * @param directions Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Cursor column_resize_cursor_in_directions(HorizontalDirections directions);
        /**
     * @brief Calls `+[NSCursor frameResizeCursorFromPosition:inDirections:]`.
     * @details Returns the cursor for resizing a rectangular frame from the specified edge or corner. - Parameters: - position: The position along the perimeter of a rectangular frame (its edges and corners) from which it’s resized. - directions: The directions in which a rectangular frame can be resized.
     * @param position Argument converted to the Objective-C parameter of the same role.
     * @param directions Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Cursor frame_resize_cursor_from_position(CursorFrameResizePosition position, CursorFrameResizeDirections directions);
        /**
     * @brief Calls `+[NSCursor hide]`.
     */
        static void hide();
        /**
     * @brief Calls `-[NSCursor pop]`.
     */
        void pop() const;
        /**
     * @brief Calls `-[NSCursor push]`.
     */
        void push() const;
        /**
     * @brief Calls `+[NSCursor rowResizeCursorInDirections:]`.
     * @details Returns the cursor for resizing a row (horizontal divider) in the specified directions. - Parameter directions: The direction in which a row can be resized.
     * @param directions Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Cursor row_resize_cursor_in_directions(VerticalDirections directions);
        /**
     * @brief Calls `-[NSCursor set]`.
     */
        void set() const;
        /**
     * @brief Calls `+[NSCursor setHiddenUntilMouseMoves:]`.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     */
        static void set_hidden_until_mouse_moves(bool flag);
        /**
     * @brief Calls `+[NSCursor unhide]`.
     */
        static void unhide();
        /**
     * @brief Returns the `IBeamCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor i_beam_cursor();
        /**
     * @brief Returns the `IBeamCursorForVerticalLayout` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor i_beam_cursor_for_vertical_layout();
        /**
     * @brief Returns the `arrowCursor` property of `NSCursor`.
     * @details Returns the default cursor, the arrow cursor. - Discussion: The default cursor, a slanted arrow with its hot spot at the tip. The arrow cursor is the one you’re used to seeing over buttons, scrollers, and many other objects in the window system.
     * @return The converted Objective-C result.
     */
        static Cursor arrow_cursor();
        /**
     * @brief Returns the `closedHandCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor closed_hand_cursor();
        /**
     * @brief Returns the `columnResizeCursor` property of `NSCursor`.
     * @details Returns the cursor for resizing a column (vertical divider) in either direction.
     * @return The converted Objective-C result.
     */
        static Cursor column_resize_cursor();
        /**
     * @brief Returns the `contextualMenuCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor contextual_menu_cursor();
        /**
     * @brief Returns the `crosshairCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor crosshair_cursor();
        /**
     * @brief Returns the `currentCursor` property of `NSCursor`.
     * @details Returns the application’s current cursor. - Note: This isn’t necessarily the cursor that is currently being displayed, as the system may be showing the cursor for another running application.
     * @return The converted Objective-C result.
     */
        static Cursor current_cursor();
        /**
     * @brief Returns the `currentSystemCursor` property of `NSCursor`.
     * @details This property will always be 'nil' in a future version of macOS.
     * @return The converted Objective-C result.
     */
        static Cursor current_system_cursor();
        /**
     * @brief Returns the `disappearingItemCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor disappearing_item_cursor();
        /**
     * @brief Returns the `dragCopyCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor drag_copy_cursor();
        /**
     * @brief Returns the `dragLinkCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor drag_link_cursor();
        /**
     * @brief Returns the `hotSpot` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        Point hot_spot() const;
        /**
     * @brief Returns the `image` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        Image image() const;
        /**
     * @brief Returns the `openHandCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor open_hand_cursor();
        /**
     * @brief Returns the `operationNotAllowedCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor operation_not_allowed_cursor();
        /**
     * @brief Returns the `pointingHandCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor pointing_hand_cursor();
        /**
     * @brief Returns the `resizeDownCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor resize_down_cursor();
        /**
     * @brief Returns the `resizeLeftCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor resize_left_cursor();
        /**
     * @brief Returns the `resizeLeftRightCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor resize_left_right_cursor();
        /**
     * @brief Returns the `resizeRightCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor resize_right_cursor();
        /**
     * @brief Returns the `resizeUpCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor resize_up_cursor();
        /**
     * @brief Returns the `resizeUpDownCursor` property of `NSCursor`.
     * @return The converted Objective-C result.
     */
        static Cursor resize_up_down_cursor();
        /**
     * @brief Returns the `rowResizeCursor` property of `NSCursor`.
     * @details Returns the cursor for resizing a row (horizontal divider) in either direction.
     * @return The converted Objective-C result.
     */
        static Cursor row_resize_cursor();
        /**
     * @brief Returns the `zoomInCursor` property of `NSCursor`.
     * @details Returns the zoom-in cursor. - Note: This cursor is used to indicate zooming in on (magnifying) a canvas or object.
     * @return The converted Objective-C result.
     */
        static Cursor zoom_in_cursor();
        /**
     * @brief Returns the `zoomOutCursor` property of `NSCursor`.
     * @details Returns the zoom-out cursor. - Note: This cursor is used to indicate zooming out of a canvas or object.
     * @return The converted Objective-C result.
     */
        static Cursor zoom_out_cursor();
    };
}
