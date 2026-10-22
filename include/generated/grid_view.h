#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class GridCell;
    class GridColumn;
    class GridRow;
    class View;

    /**
     * @brief A grid layout (NSGridView).
     * @details NSGridView is a layout container for aligning views in spreadsheet-like rows & columns, indexed from the top left starting at 0. Rows and columns are sized to fit their largest content (unless an explicit size has been set), but all cells in a given column will be the same width and all cells in a row will be the same height. NSGridPlacement is used to specify the positioning of the contentView within the cell. The content placement can be configured separately for the X & Y axes to align the content with either edge or to center it. Placement properties on rows, columns, and cells default to 'inherited' so that the grid-level properties will effect all cells. Content placement can be overridden for individual rows, columns, or cells by simply changing the appropriate property to a value other than 'inherited'.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * cocoon::GridView grid;
     * grid.add_row({cocoon::View(cocoon::Label("Name")), cocoon::View(cocoon::TextField())});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::GridView grid_view{};
     * grid_view.set_column_spacing(1);
     * auto column_spacing = grid_view.column_spacing();
     * grid_view.set_row_alignment(cocoon::GridRowAlignment::Inherited);
     * auto row_alignment = grid_view.row_alignment();
     * grid_view.set_row_spacing(1);
     * auto row_spacing = grid_view.row_spacing();
     * grid_view.cell_at_column_index(1, 1);
     * grid_view.cell_for_view(cocoon::View());
     * grid_view.column_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsgridview
     */
    class GridView : public View
    {
    public:
        /// @brief Creates a new `NSGridView` instance and returns a handle to it.
        explicit GridView();
        /// @brief Creates a new `NSGridView` instance and returns a handle to it.
        explicit GridView(const Rect& frame_rect);
        /// @brief Creates a new `NSGridView` instance and returns a handle to it.
        explicit GridView(std::int64_t column_count, std::int64_t row_count);
        /// @brief Creates a new `NSGridView` instance and returns a handle to it.
        explicit GridView(const std::vector<std::vector<View>>& rows);
        /// @brief Creates a null handle that refers to no native object.
        GridView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit GridView(Adopt adopt);
        /**
         * @brief Calls `-[NSGridView addColumnWithViews:]`.
         * @param views Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        GridColumn add_column_with_views(const std::vector<View>& views) const;
        /**
         * @brief Calls `-[NSGridView addRowWithViews:]`.
         * @param views Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        GridRow add_row_with_views(const std::vector<View>& views) const;
        /**
         * @brief Calls `-[NSGridView cellAtColumnIndex:rowIndex:]`.
         * @param column_index Argument converted to the Objective-C parameter of the same role.
         * @param row_index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        GridCell cell_at_column_index(std::int64_t column_index, std::int64_t row_index) const;
        /**
         * @brief Calls `-[NSGridView cellForView:]`.
         * @param view Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        GridCell cell_for_view(const View& view) const;
        /**
         * @brief Calls `-[NSGridView columnAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        GridColumn column_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSGridView indexOfColumn:]`.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t index_of_column(const GridColumn& column) const;
        /**
         * @brief Calls `-[NSGridView indexOfRow:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t index_of_row(const GridRow& row) const;
        /**
         * @brief Calls `-[NSGridView insertColumnAtIndex:withViews:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @param views Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        GridColumn insert_column_at_index(std::int64_t index, const std::vector<View>& views) const;
        /**
         * @brief Calls `-[NSGridView insertRowAtIndex:withViews:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @param views Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        GridRow insert_row_at_index(std::int64_t index, const std::vector<View>& views) const;
        /**
         * @brief Calls `-[NSGridView mergeCellsInHorizontalRange:verticalRange:]`.
         * @param h_range Argument converted to the Objective-C parameter of the same role.
         * @param v_range Argument converted to the Objective-C parameter of the same role.
         */
        void merge_cells_in_horizontal_range(const Range& h_range, const Range& v_range) const;
        /**
         * @brief Calls `-[NSGridView moveColumnAtIndex:toIndex:]`.
         * @param from_index Argument converted to the Objective-C parameter of the same role.
         * @param to_index Argument converted to the Objective-C parameter of the same role.
         */
        void move_column_at_index(std::int64_t from_index, std::int64_t to_index) const;
        /**
         * @brief Calls `-[NSGridView moveRowAtIndex:toIndex:]`.
         * @param from_index Argument converted to the Objective-C parameter of the same role.
         * @param to_index Argument converted to the Objective-C parameter of the same role.
         */
        void move_row_at_index(std::int64_t from_index, std::int64_t to_index) const;
        /**
         * @brief Calls `-[NSGridView removeColumnAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void remove_column_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSGridView removeRowAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void remove_row_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSGridView rowAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        GridRow row_at_index(std::int64_t index) const;
        /**
         * @brief Returns the `columnSpacing` property of `NSGridView`.
         * @return The converted Objective-C result.
         */
        double column_spacing() const;
        /**
         * @brief Sets the `columnSpacing` property of `NSGridView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_column_spacing(double value) const;
        /**
         * @brief Returns the `numberOfColumns` property of `NSGridView`.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_columns() const;
        /**
         * @brief Returns the `numberOfRows` property of `NSGridView`.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_rows() const;
        /**
         * @brief Returns the `rowAlignment` property of `NSGridView`.
         * @return The converted Objective-C result.
         */
        GridRowAlignment row_alignment() const;
        /**
         * @brief Sets the `rowAlignment` property of `NSGridView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_row_alignment(GridRowAlignment value) const;
        /**
         * @brief Returns the `rowSpacing` property of `NSGridView`.
         * @return The converted Objective-C result.
         */
        double row_spacing() const;
        /**
         * @brief Sets the `rowSpacing` property of `NSGridView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_row_spacing(double value) const;
        /**
         * @brief Returns the `xPlacement` property of `NSGridView`.
         * @return The converted Objective-C result.
         */
        GridCellPlacement x_placement() const;
        /**
         * @brief Sets the `xPlacement` property of `NSGridView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_x_placement(GridCellPlacement value) const;
        /**
         * @brief Returns the `yPlacement` property of `NSGridView`.
         * @return The converted Objective-C result.
         */
        GridCellPlacement y_placement() const;
        /**
         * @brief Sets the `yPlacement` property of `NSGridView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_y_placement(GridCellPlacement value) const;
        /// @brief Convenience helper `add_row` provided by cocoon.
        void add_row(const std::vector<View>& views) const;
    };
}
