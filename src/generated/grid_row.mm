#include "generated/grid_row.h"
#include "internal.h"

namespace cocoon
{
    GridRow::GridRow() : GridRow(Adopt{cocoon::internal::retain([[::NSGridRow alloc] init])})
    {
    }

    GridRow::GridRow(std::nullptr_t) : Object(nullptr)
    {
    }

    GridRow::GridRow(Adopt adopt) : Object(adopt)
    {
    }

    GridCell GridRow::cell_at_index(std::int64_t index) const
    {
        return cocoon::internal::wrap<GridCell>([cocoon::internal::ns<::NSGridRow>(this) cellAtIndex:static_cast<::NSInteger>(index)]);
    }

    void GridRow::merge_cells_in_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSGridRow>(this) mergeCellsInRange:cocoon::internal::to(range)];
    }

    double GridRow::bottom_padding() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSGridRow>(this) bottomPadding]);
    }

    void GridRow::set_bottom_padding(double value) const
    {
        [cocoon::internal::ns<::NSGridRow>(this) setBottomPadding:static_cast<::CGFloat>(value)];
    }

    GridView GridRow::grid_view() const
    {
        return cocoon::internal::wrap<GridView>([cocoon::internal::ns<::NSGridRow>(this) gridView]);
    }

    double GridRow::height() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSGridRow>(this) height]);
    }

    void GridRow::set_height(double value) const
    {
        [cocoon::internal::ns<::NSGridRow>(this) setHeight:static_cast<::CGFloat>(value)];
    }

    bool GridRow::is_hidden() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGridRow>(this) isHidden]);
    }

    void GridRow::set_hidden(bool value) const
    {
        [cocoon::internal::ns<::NSGridRow>(this) setHidden:static_cast<::BOOL>(value)];
    }

    std::int64_t GridRow::number_of_cells() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSGridRow>(this) numberOfCells]);
    }

    GridRowAlignment GridRow::row_alignment() const
    {
        return static_cast<GridRowAlignment>([cocoon::internal::ns<::NSGridRow>(this) rowAlignment]);
    }

    void GridRow::set_row_alignment(GridRowAlignment value) const
    {
        [cocoon::internal::ns<::NSGridRow>(this) setRowAlignment:static_cast<::NSGridRowAlignment>(value)];
    }

    double GridRow::top_padding() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSGridRow>(this) topPadding]);
    }

    void GridRow::set_top_padding(double value) const
    {
        [cocoon::internal::ns<::NSGridRow>(this) setTopPadding:static_cast<::CGFloat>(value)];
    }

    GridCellPlacement GridRow::y_placement() const
    {
        return static_cast<GridCellPlacement>([cocoon::internal::ns<::NSGridRow>(this) yPlacement]);
    }

    void GridRow::set_y_placement(GridCellPlacement value) const
    {
        [cocoon::internal::ns<::NSGridRow>(this) setYPlacement:static_cast<::NSGridCellPlacement>(value)];
    }
}
