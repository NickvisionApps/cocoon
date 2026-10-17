#include "generated/table_header_view.h"
#include "internal.h"

namespace cocoon
{
    TableHeaderView::TableHeaderView() : TableHeaderView(Adopt{cocoon::internal::retain([[::NSTableHeaderView alloc] init])})
    {
    }

    TableHeaderView::TableHeaderView(std::nullptr_t) : View(nullptr)
    {
    }

    TableHeaderView::TableHeaderView(Adopt adopt) : View(adopt)
    {
    }

    std::int64_t TableHeaderView::column_at_point(const Point& point) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableHeaderView>(this) columnAtPoint:cocoon::internal::to(point)]);
    }

    Rect TableHeaderView::header_rect_of_column(std::int64_t column) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTableHeaderView>(this) headerRectOfColumn:static_cast<::NSInteger>(column)]);
    }

    std::int64_t TableHeaderView::dragged_column() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableHeaderView>(this) draggedColumn]);
    }

    double TableHeaderView::dragged_distance() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTableHeaderView>(this) draggedDistance]);
    }

    std::int64_t TableHeaderView::resized_column() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableHeaderView>(this) resizedColumn]);
    }

    TableView TableHeaderView::table_view() const
    {
        return cocoon::internal::wrap<TableView>([cocoon::internal::ns<::NSTableHeaderView>(this) tableView]);
    }

    void TableHeaderView::set_table_view(const TableView& value) const
    {
        [cocoon::internal::ns<::NSTableHeaderView>(this) setTableView:cocoon::internal::native<::NSTableView>(value)];
    }
}
