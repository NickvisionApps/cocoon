#include "generated/grid_cell.h"
#include "internal.h"

namespace cocoon
{
    GridCell::GridCell() : GridCell(Adopt{cocoon::internal::retain([[::NSGridCell alloc] init])})
    {
    }

    GridCell::GridCell(std::nullptr_t) : Object(nullptr)
    {
    }

    GridCell::GridCell(Adopt adopt) : Object(adopt)
    {
    }

    GridColumn GridCell::column() const
    {
        return cocoon::internal::wrap<GridColumn>([cocoon::internal::ns<::NSGridCell>(this) column]);
    }

    View GridCell::content_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSGridCell>(this) contentView]);
    }

    void GridCell::set_content_view(const View& value) const
    {
        [cocoon::internal::ns<::NSGridCell>(this) setContentView:cocoon::internal::native<::NSView>(value)];
    }

    std::vector<LayoutConstraint> GridCell::custom_placement_constraints() const
    {
        return cocoon::internal::from_array<LayoutConstraint>([cocoon::internal::ns<::NSGridCell>(this) customPlacementConstraints], [](id e) -> LayoutConstraint
                                                {
                                                    return cocoon::internal::wrap<LayoutConstraint>((::NSLayoutConstraint*)e);
                                                });
    }

    void GridCell::set_custom_placement_constraints(const std::vector<LayoutConstraint>& value) const
    {
        [cocoon::internal::ns<::NSGridCell>(this) setCustomPlacementConstraints:cocoon::internal::to_array(value, [](const LayoutConstraint& e) -> id
                                                                               {
                                                                                   return cocoon::internal::native<::NSLayoutConstraint>(e);
                                                                               })];
    }

    View GridCell::empty_content_view()
    {
        return cocoon::internal::wrap<View>([::NSGridCell emptyContentView]);
    }

    GridRow GridCell::row() const
    {
        return cocoon::internal::wrap<GridRow>([cocoon::internal::ns<::NSGridCell>(this) row]);
    }

    GridRowAlignment GridCell::row_alignment() const
    {
        return static_cast<GridRowAlignment>([cocoon::internal::ns<::NSGridCell>(this) rowAlignment]);
    }

    void GridCell::set_row_alignment(GridRowAlignment value) const
    {
        [cocoon::internal::ns<::NSGridCell>(this) setRowAlignment:static_cast<::NSGridRowAlignment>(value)];
    }

    GridCellPlacement GridCell::x_placement() const
    {
        return static_cast<GridCellPlacement>([cocoon::internal::ns<::NSGridCell>(this) xPlacement]);
    }

    void GridCell::set_x_placement(GridCellPlacement value) const
    {
        [cocoon::internal::ns<::NSGridCell>(this) setXPlacement:static_cast<::NSGridCellPlacement>(value)];
    }

    GridCellPlacement GridCell::y_placement() const
    {
        return static_cast<GridCellPlacement>([cocoon::internal::ns<::NSGridCell>(this) yPlacement]);
    }

    void GridCell::set_y_placement(GridCellPlacement value) const
    {
        [cocoon::internal::ns<::NSGridCell>(this) setYPlacement:static_cast<::NSGridCellPlacement>(value)];
    }
}
