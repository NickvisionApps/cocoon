#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class GridColumn;
    class GridRow;
    class LayoutConstraint;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSGridCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::GridCell grid_cell;
     * grid_cell.set_content_view(cocoon::View());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::GridCell grid_cell{};
     * grid_cell.set_content_view(cocoon::View());
     * auto content_view = grid_cell.content_view();
     * grid_cell.set_row_alignment(cocoon::GridRowAlignment::Inherited);
     * auto row_alignment = grid_cell.row_alignment();
     * grid_cell.set_x_placement(cocoon::GridCellPlacement::Inherited);
     * auto x_placement = grid_cell.x_placement();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsgridcell
     */
    class GridCell : public Object
    {
    public:
        /// @brief Creates a new `NSGridCell` instance and returns a handle to it.
        explicit GridCell();
        /// @brief Creates a null handle that refers to no native object.
        GridCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit GridCell(Adopt adopt);
        /**
         * @brief Returns the `column` property of `NSGridCell`.
         * @return The converted Objective-C result.
         */
        GridColumn column() const;
        /**
         * @brief Returns the `contentView` property of `NSGridCell`.
         * @return The converted Objective-C result.
         */
        View content_view() const;
        /**
         * @brief Sets the `contentView` property of `NSGridCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_content_view(const View& value) const;
        /**
         * @brief Returns the `customPlacementConstraints` property of `NSGridCell`.
         * @return The converted Objective-C result.
         */
        std::vector<LayoutConstraint> custom_placement_constraints() const;
        /**
         * @brief Sets the `customPlacementConstraints` property of `NSGridCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_custom_placement_constraints(const std::vector<LayoutConstraint>& value) const;
        /**
         * @brief Returns the `emptyContentView` property of `NSGridCell`.
         * @return The converted Objective-C result.
         */
        static View empty_content_view();
        /**
         * @brief Returns the `row` property of `NSGridCell`.
         * @return The converted Objective-C result.
         */
        GridRow row() const;
        /**
         * @brief Returns the `rowAlignment` property of `NSGridCell`.
         * @return The converted Objective-C result.
         */
        GridRowAlignment row_alignment() const;
        /**
         * @brief Sets the `rowAlignment` property of `NSGridCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_row_alignment(GridRowAlignment value) const;
        /**
         * @brief Returns the `xPlacement` property of `NSGridCell`.
         * @return The converted Objective-C result.
         */
        GridCellPlacement x_placement() const;
        /**
         * @brief Sets the `xPlacement` property of `NSGridCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_x_placement(GridCellPlacement value) const;
        /**
         * @brief Returns the `yPlacement` property of `NSGridCell`.
         * @return The converted Objective-C result.
         */
        GridCellPlacement y_placement() const;
        /**
         * @brief Sets the `yPlacement` property of `NSGridCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_y_placement(GridCellPlacement value) const;
    };
}
