#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text_field_cell.h"
#include "types.h"

namespace cocoon
{
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSTableHeaderCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TextFieldCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TableHeaderCell table_header_cell;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TableHeaderCell table_header_cell{};
     * table_header_cell.draw_sort_indicator_with_frame({{0, 0}, {100, 100}}, cocoon::View(), true, 1);
     * table_header_cell.sort_indicator_rect_for_bounds({{0, 0}, {100, 100}});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstableheadercell
     */
    class TableHeaderCell : public TextFieldCell
    {
    public:
        /// @brief Creates a new `NSTableHeaderCell` instance and returns a handle to it.
        explicit TableHeaderCell();
        /// @brief Creates a null handle that refers to no native object.
        TableHeaderCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TableHeaderCell(Adopt adopt);
        /**
     * @brief Calls `-[NSTableHeaderCell drawSortIndicatorWithFrame:inView:ascending:priority:]`.
     * @details Draws a sorting indicator given a cellFrame. If priority is 0, this is the primary sort indicator. If ascending is YES, a "^" indicator will be drawn. Override this routine to customimze the sorting UI.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     * @param ascending Argument converted to the Objective-C parameter of the same role.
     * @param priority Argument converted to the Objective-C parameter of the same role.
     */
        void draw_sort_indicator_with_frame(const Rect& cell_frame, const View& control_view, bool ascending, std::int64_t priority) const;
        /**
     * @brief Calls `-[NSTableHeaderCell sortIndicatorRectForBounds:]`.
     * @details Returns the location to display the sorting indicator given the cellFrame.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect sort_indicator_rect_for_bounds(const Rect& rect) const;
    };
}
