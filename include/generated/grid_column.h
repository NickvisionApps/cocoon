#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class GridCell;
    class GridView;

    /**
     * @brief C++ handle for the Objective-C class `NSGridColumn` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::GridColumn grid_column;
     * grid_column.set_hidden(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::GridColumn grid_column{};
     * grid_column.set_hidden(true);
     * auto hidden = grid_column.is_hidden();
     * grid_column.set_leading_padding(1);
     * auto leading_padding = grid_column.leading_padding();
     * grid_column.set_trailing_padding(1);
     * auto trailing_padding = grid_column.trailing_padding();
     * grid_column.cell_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsgridcolumn
     */
    class GridColumn : public Object
    {
    public:
        /// @brief Creates a new `NSGridColumn` instance and returns a handle to it.
        explicit GridColumn();
        /// @brief Creates a null handle that refers to no native object.
        GridColumn(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit GridColumn(Adopt adopt);
        /**
     * @brief Calls `-[NSGridColumn cellAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        GridCell cell_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSGridColumn mergeCellsInRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void merge_cells_in_range(const Range& range) const;
        /**
     * @brief Returns the `gridView` property of `NSGridColumn`.
     * @return The converted Objective-C result.
     */
        GridView grid_view() const;
        /**
     * @brief Returns the `hidden` property of `NSGridColumn`.
     * @return The converted Objective-C result.
     */
        bool is_hidden() const;
        /**
     * @brief Sets the `hidden` property of `NSGridColumn`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hidden(bool value) const;
        /**
     * @brief Returns the `leadingPadding` property of `NSGridColumn`.
     * @return The converted Objective-C result.
     */
        double leading_padding() const;
        /**
     * @brief Sets the `leadingPadding` property of `NSGridColumn`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_leading_padding(double value) const;
        /**
     * @brief Returns the `numberOfCells` property of `NSGridColumn`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_cells() const;
        /**
     * @brief Returns the `trailingPadding` property of `NSGridColumn`.
     * @return The converted Objective-C result.
     */
        double trailing_padding() const;
        /**
     * @brief Sets the `trailingPadding` property of `NSGridColumn`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_trailing_padding(double value) const;
        /**
     * @brief Returns the `width` property of `NSGridColumn`.
     * @return The converted Objective-C result.
     */
        double width() const;
        /**
     * @brief Sets the `width` property of `NSGridColumn`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_width(double value) const;
        /**
     * @brief Returns the `xPlacement` property of `NSGridColumn`.
     * @return The converted Objective-C result.
     */
        GridCellPlacement x_placement() const;
        /**
     * @brief Sets the `xPlacement` property of `NSGridColumn`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_x_placement(GridCellPlacement value) const;
    };
}
