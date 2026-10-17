#include "generated/table_header_cell.h"
#include "internal.h"

namespace cocoon
{
    TableHeaderCell::TableHeaderCell() : TableHeaderCell(Adopt{cocoon::internal::retain([[::NSTableHeaderCell alloc] init])})
    {
    }

    TableHeaderCell::TableHeaderCell(std::nullptr_t) : TextFieldCell(nullptr)
    {
    }

    TableHeaderCell::TableHeaderCell(Adopt adopt) : TextFieldCell(adopt)
    {
    }

    void TableHeaderCell::draw_sort_indicator_with_frame(const Rect& cell_frame, const View& control_view, bool ascending, std::int64_t priority) const
    {
        [cocoon::internal::ns<::NSTableHeaderCell>(this) drawSortIndicatorWithFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(control_view) ascending:static_cast<::BOOL>(ascending) priority:static_cast<::NSInteger>(priority)];
    }

    Rect TableHeaderCell::sort_indicator_rect_for_bounds(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTableHeaderCell>(this) sortIndicatorRectForBounds:cocoon::internal::to(rect)]);
    }
}
