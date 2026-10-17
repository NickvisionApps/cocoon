#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class GridCell;
    class GridView;

    /**
     * @brief C++ handle for the Objective-C class `NSGridRow` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::GridRow grid_row;
     * grid_row.set_bottom_padding(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::GridRow grid_row{};
     * grid_row.set_bottom_padding(1);
     * auto bottom_padding = grid_row.bottom_padding();
     * grid_row.set_height(1);
     * auto height = grid_row.height();
     * grid_row.set_hidden(true);
     * auto hidden = grid_row.is_hidden();
     * grid_row.cell_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsgridrow
     */
    class GridRow : public Object
    {
    public:
        /// @brief Creates a new `NSGridRow` instance and returns a handle to it.
        explicit GridRow();
        /// @brief Creates a null handle that refers to no native object.
        GridRow(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit GridRow(Adopt adopt);
        /**
     * @brief Calls `-[NSGridRow cellAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        GridCell cell_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSGridRow mergeCellsInRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void merge_cells_in_range(const Range& range) const;
        /**
     * @brief Returns the `bottomPadding` property of `NSGridRow`.
     * @return The converted Objective-C result.
     */
        double bottom_padding() const;
        /**
     * @brief Sets the `bottomPadding` property of `NSGridRow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bottom_padding(double value) const;
        /**
     * @brief Returns the `gridView` property of `NSGridRow`.
     * @return The converted Objective-C result.
     */
        GridView grid_view() const;
        /**
     * @brief Returns the `height` property of `NSGridRow`.
     * @return The converted Objective-C result.
     */
        double height() const;
        /**
     * @brief Sets the `height` property of `NSGridRow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_height(double value) const;
        /**
     * @brief Returns the `hidden` property of `NSGridRow`.
     * @return The converted Objective-C result.
     */
        bool is_hidden() const;
        /**
     * @brief Sets the `hidden` property of `NSGridRow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hidden(bool value) const;
        /**
     * @brief Returns the `numberOfCells` property of `NSGridRow`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_cells() const;
        /**
     * @brief Returns the `rowAlignment` property of `NSGridRow`.
     * @return The converted Objective-C result.
     */
        GridRowAlignment row_alignment() const;
        /**
     * @brief Sets the `rowAlignment` property of `NSGridRow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_row_alignment(GridRowAlignment value) const;
        /**
     * @brief Returns the `topPadding` property of `NSGridRow`.
     * @return The converted Objective-C result.
     */
        double top_padding() const;
        /**
     * @brief Sets the `topPadding` property of `NSGridRow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_top_padding(double value) const;
        /**
     * @brief Returns the `yPlacement` property of `NSGridRow`.
     * @return The converted Objective-C result.
     */
        GridCellPlacement y_placement() const;
        /**
     * @brief Sets the `yPlacement` property of `NSGridRow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_y_placement(GridCellPlacement value) const;
    };
}
