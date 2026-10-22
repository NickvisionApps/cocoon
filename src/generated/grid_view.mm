#include "generated/grid_view.h"
#include "internal.h"

namespace cocoon
{
    GridView::GridView() : GridView(Adopt{cocoon::internal::retain([[NSGridView alloc] init])})
    {
    }

    GridView::GridView(const Rect& frame_rect) : GridView(Adopt{cocoon::internal::retain([[::NSGridView alloc] initWithFrame:cocoon::internal::to(frame_rect)])})
    {
    }

    GridView::GridView(std::int64_t column_count, std::int64_t row_count) : GridView(Adopt{cocoon::internal::retain([::NSGridView gridViewWithNumberOfColumns:static_cast<::NSInteger>(column_count) rows:static_cast<::NSInteger>(row_count)])})
    {
    }

    GridView::GridView(const std::vector<std::vector<View>>& rows) : GridView(Adopt{cocoon::internal::retain([::NSGridView gridViewWithViews:cocoon::internal::to_array(rows, [](const std::vector<View>& e) -> id
                                                                                                                                                                        {
                                                                                                                                                                            return cocoon::internal::to_array(e, [](const View& e) -> id
                                                                                                                                                                                                              {
                                                                                                                                                                                                                  return cocoon::internal::native<::NSView>(e);
                                                                                                                                                                                                              });
                                                                                                                                                                        })])})
    {
    }

    GridView::GridView(std::nullptr_t) : View(nullptr)
    {
    }

    GridView::GridView(Adopt adopt) : View(adopt)
    {
    }

    GridColumn GridView::add_column_with_views(const std::vector<View>& views) const
    {
        return cocoon::internal::wrap<GridColumn>([cocoon::internal::ns<::NSGridView>(this) addColumnWithViews:cocoon::internal::to_array(views, [](const View& e) -> id
                                                                                                                                          {
                                                                                                                                              return cocoon::internal::native<::NSView>(e);
                                                                                                                                          })]);
    }

    GridRow GridView::add_row_with_views(const std::vector<View>& views) const
    {
        return cocoon::internal::wrap<GridRow>([cocoon::internal::ns<::NSGridView>(this) addRowWithViews:cocoon::internal::to_array(views, [](const View& e) -> id
                                                                                                                                    {
                                                                                                                                        return cocoon::internal::native<::NSView>(e);
                                                                                                                                    })]);
    }

    GridCell GridView::cell_at_column_index(std::int64_t column_index, std::int64_t row_index) const
    {
        return cocoon::internal::wrap<GridCell>([cocoon::internal::ns<::NSGridView>(this) cellAtColumnIndex:static_cast<::NSInteger>(column_index) rowIndex:static_cast<::NSInteger>(row_index)]);
    }

    GridCell GridView::cell_for_view(const View& view) const
    {
        return cocoon::internal::wrap<GridCell>([cocoon::internal::ns<::NSGridView>(this) cellForView:cocoon::internal::native<::NSView>(view)]);
    }

    GridColumn GridView::column_at_index(std::int64_t index) const
    {
        return cocoon::internal::wrap<GridColumn>([cocoon::internal::ns<::NSGridView>(this) columnAtIndex:static_cast<::NSInteger>(index)]);
    }

    std::int64_t GridView::index_of_column(const GridColumn& column) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSGridView>(this) indexOfColumn:cocoon::internal::native<::NSGridColumn>(column)]);
    }

    std::int64_t GridView::index_of_row(const GridRow& row) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSGridView>(this) indexOfRow:cocoon::internal::native<::NSGridRow>(row)]);
    }

    GridColumn GridView::insert_column_at_index(std::int64_t index, const std::vector<View>& views) const
    {
        return cocoon::internal::wrap<GridColumn>([cocoon::internal::ns<::NSGridView>(this) insertColumnAtIndex:static_cast<::NSInteger>(index)
                                                                                                      withViews:cocoon::internal::to_array(views, [](const View& e) -> id
                                                                                                                                           {
                                                                                                                                               return cocoon::internal::native<::NSView>(e);
                                                                                                                                           })]);
    }

    GridRow GridView::insert_row_at_index(std::int64_t index, const std::vector<View>& views) const
    {
        return cocoon::internal::wrap<GridRow>([cocoon::internal::ns<::NSGridView>(this) insertRowAtIndex:static_cast<::NSInteger>(index)
                                                                                                withViews:cocoon::internal::to_array(views, [](const View& e) -> id
                                                                                                                                     {
                                                                                                                                         return cocoon::internal::native<::NSView>(e);
                                                                                                                                     })]);
    }

    void GridView::merge_cells_in_horizontal_range(const Range& h_range, const Range& v_range) const
    {
        [cocoon::internal::ns<::NSGridView>(this) mergeCellsInHorizontalRange:cocoon::internal::to(h_range) verticalRange:cocoon::internal::to(v_range)];
    }

    void GridView::move_column_at_index(std::int64_t from_index, std::int64_t to_index) const
    {
        [cocoon::internal::ns<::NSGridView>(this) moveColumnAtIndex:static_cast<::NSInteger>(from_index) toIndex:static_cast<::NSInteger>(to_index)];
    }

    void GridView::move_row_at_index(std::int64_t from_index, std::int64_t to_index) const
    {
        [cocoon::internal::ns<::NSGridView>(this) moveRowAtIndex:static_cast<::NSInteger>(from_index) toIndex:static_cast<::NSInteger>(to_index)];
    }

    void GridView::remove_column_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSGridView>(this) removeColumnAtIndex:static_cast<::NSInteger>(index)];
    }

    void GridView::remove_row_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSGridView>(this) removeRowAtIndex:static_cast<::NSInteger>(index)];
    }

    GridRow GridView::row_at_index(std::int64_t index) const
    {
        return cocoon::internal::wrap<GridRow>([cocoon::internal::ns<::NSGridView>(this) rowAtIndex:static_cast<::NSInteger>(index)]);
    }

    double GridView::column_spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSGridView>(this) columnSpacing]);
    }

    void GridView::set_column_spacing(double value) const
    {
        [cocoon::internal::ns<::NSGridView>(this) setColumnSpacing:static_cast<::CGFloat>(value)];
    }

    std::int64_t GridView::number_of_columns() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSGridView>(this) numberOfColumns]);
    }

    std::int64_t GridView::number_of_rows() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSGridView>(this) numberOfRows]);
    }

    GridRowAlignment GridView::row_alignment() const
    {
        return static_cast<GridRowAlignment>([cocoon::internal::ns<::NSGridView>(this) rowAlignment]);
    }

    void GridView::set_row_alignment(GridRowAlignment value) const
    {
        [cocoon::internal::ns<::NSGridView>(this) setRowAlignment:static_cast<::NSGridRowAlignment>(value)];
    }

    double GridView::row_spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSGridView>(this) rowSpacing]);
    }

    void GridView::set_row_spacing(double value) const
    {
        [cocoon::internal::ns<::NSGridView>(this) setRowSpacing:static_cast<::CGFloat>(value)];
    }

    GridCellPlacement GridView::x_placement() const
    {
        return static_cast<GridCellPlacement>([cocoon::internal::ns<::NSGridView>(this) xPlacement]);
    }

    void GridView::set_x_placement(GridCellPlacement value) const
    {
        [cocoon::internal::ns<::NSGridView>(this) setXPlacement:static_cast<::NSGridCellPlacement>(value)];
    }

    GridCellPlacement GridView::y_placement() const
    {
        return static_cast<GridCellPlacement>([cocoon::internal::ns<::NSGridView>(this) yPlacement]);
    }

    void GridView::set_y_placement(GridCellPlacement value) const
    {
        [cocoon::internal::ns<::NSGridView>(this) setYPlacement:static_cast<::NSGridCellPlacement>(value)];
    }

    void GridView::add_row(const std::vector<View>& views) const
    {
        NSMutableArray<NSView*>* row = [NSMutableArray arrayWithCapacity:views.size()];
        for (const View& view : views)
        {
            [row addObject:view.is_null() ? NSGridCell.emptyContentView : cocoon::internal::native<NSView>(view)];
        }
        [cocoon::internal::ns<NSGridView>(this) addRowWithViews:row];
    }
}
