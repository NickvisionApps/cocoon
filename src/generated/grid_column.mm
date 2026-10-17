#include "generated/grid_column.h"
#include "internal.h"

namespace cocoon
{
    GridColumn::GridColumn() : GridColumn(Adopt{cocoon::internal::retain([[::NSGridColumn alloc] init])})
    {
    }

    GridColumn::GridColumn(std::nullptr_t) : Object(nullptr)
    {
    }

    GridColumn::GridColumn(Adopt adopt) : Object(adopt)
    {
    }

    GridCell GridColumn::cell_at_index(std::int64_t index) const
    {
        return cocoon::internal::wrap<GridCell>([cocoon::internal::ns<::NSGridColumn>(this) cellAtIndex:static_cast<::NSInteger>(index)]);
    }

    void GridColumn::merge_cells_in_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSGridColumn>(this) mergeCellsInRange:cocoon::internal::to(range)];
    }

    GridView GridColumn::grid_view() const
    {
        return cocoon::internal::wrap<GridView>([cocoon::internal::ns<::NSGridColumn>(this) gridView]);
    }

    bool GridColumn::is_hidden() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGridColumn>(this) isHidden]);
    }

    void GridColumn::set_hidden(bool value) const
    {
        [cocoon::internal::ns<::NSGridColumn>(this) setHidden:static_cast<::BOOL>(value)];
    }

    double GridColumn::leading_padding() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSGridColumn>(this) leadingPadding]);
    }

    void GridColumn::set_leading_padding(double value) const
    {
        [cocoon::internal::ns<::NSGridColumn>(this) setLeadingPadding:static_cast<::CGFloat>(value)];
    }

    std::int64_t GridColumn::number_of_cells() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSGridColumn>(this) numberOfCells]);
    }

    double GridColumn::trailing_padding() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSGridColumn>(this) trailingPadding]);
    }

    void GridColumn::set_trailing_padding(double value) const
    {
        [cocoon::internal::ns<::NSGridColumn>(this) setTrailingPadding:static_cast<::CGFloat>(value)];
    }

    double GridColumn::width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSGridColumn>(this) width]);
    }

    void GridColumn::set_width(double value) const
    {
        [cocoon::internal::ns<::NSGridColumn>(this) setWidth:static_cast<::CGFloat>(value)];
    }

    GridCellPlacement GridColumn::x_placement() const
    {
        return static_cast<GridCellPlacement>([cocoon::internal::ns<::NSGridColumn>(this) xPlacement]);
    }

    void GridColumn::set_x_placement(GridCellPlacement value) const
    {
        [cocoon::internal::ns<::NSGridColumn>(this) setXPlacement:static_cast<::NSGridCellPlacement>(value)];
    }
}
