#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class TableView;

    /**
     * @brief C++ handle for the Objective-C class `NSTableHeaderView` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TableHeaderView table_header_view;
     * table_header_view.set_table_view(cocoon::TableView());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TableHeaderView table_header_view{};
     * table_header_view.set_table_view(cocoon::TableView());
     * auto table_view = table_header_view.table_view();
     * table_header_view.column_at_point({0, 0});
     * table_header_view.header_rect_of_column(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstableheaderview
     */
    class TableHeaderView : public View
    {
    public:
        /// @brief Creates a new `NSTableHeaderView` instance and returns a handle to it.
        explicit TableHeaderView();
        /// @brief Creates a null handle that refers to no native object.
        TableHeaderView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TableHeaderView(Adopt adopt);
        /**
     * @brief Calls `-[NSTableHeaderView columnAtPoint:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t column_at_point(const Point& point) const;
        /**
     * @brief Calls `-[NSTableHeaderView headerRectOfColumn:]`.
     * @param column Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect header_rect_of_column(std::int64_t column) const;
        /**
     * @brief Returns the `draggedColumn` property of `NSTableHeaderView`.
     * @return The converted Objective-C result.
     */
        std::int64_t dragged_column() const;
        /**
     * @brief Returns the `draggedDistance` property of `NSTableHeaderView`.
     * @return The converted Objective-C result.
     */
        double dragged_distance() const;
        /**
     * @brief Returns the `resizedColumn` property of `NSTableHeaderView`.
     * @return The converted Objective-C result.
     */
        std::int64_t resized_column() const;
        /**
     * @brief Returns the `tableView` property of `NSTableHeaderView`.
     * @return The converted Objective-C result.
     */
        TableView table_view() const;
        /**
     * @brief Sets the `tableView` property of `NSTableHeaderView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_table_view(const TableView& value) const;
    };
}
