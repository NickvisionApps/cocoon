#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class SortDescriptor;
    class TableHeaderCell;
    class TableView;

    /**
     * @brief C++ handle for the Objective-C class `NSTableColumn` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TableColumn table_column;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TableColumn table_column{};
     * table_column.set_editable(true);
     * auto editable = table_column.is_editable();
     * table_column.set_header_cell(cocoon::TableHeaderCell());
     * auto header_cell = table_column.header_cell();
     * table_column.set_header_tool_tip("text");
     * auto header_tool_tip = table_column.header_tool_tip();
     * table_column.data_cell_for_row(1);
     * table_column.size_to_fit();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstablecolumn
     */
    class TableColumn : public Object
    {
    public:
        /// @brief Creates a new `NSTableColumn` instance and returns a handle to it.
        explicit TableColumn(const std::string& identifier);
        /// @brief Creates a new `NSTableColumn` instance and returns a handle to it.
        explicit TableColumn();
        /// @brief Creates a null handle that refers to no native object.
        TableColumn(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TableColumn(Adopt adopt);
        /**
     * @brief Calls `-[NSTableColumn dataCellForRow:]`.
     * @param row Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object data_cell_for_row(std::int64_t row) const;
        /**
     * @brief Calls `-[NSTableColumn sizeToFit]`.
     */
        void size_to_fit() const;
        /**
     * @brief Returns the `dataCell` property of `NSTableColumn`.
     * @details Cell-based NSTableViews are deprecated in Mac OS 10.10. Use view-based NSTableViews instead.
     * @return The converted Objective-C result.
     */
        Object data_cell() const;
        /**
     * @brief Sets the `dataCell` property of `NSTableColumn`.
     * @details Cell-based NSTableViews are deprecated in Mac OS 10.10. Use view-based NSTableViews instead.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_data_cell(const Object& value) const;
        /**
     * @brief Returns the `editable` property of `NSTableColumn`.
     * @details Gets and sets the editability state of this NSTableColumn. The default value is YES. When an NSTableView wants to start editing a dataCell, the following happens: 1. Check [tableColumn isEditable]. If that returns YES, check the (optional) delegate method with tableView:shouldEditTableColumn:row:. If that returns YES, check the [dataCell isEnabled] and [isEnabled isSelectable] states before attempting to edit.
     * @return The converted Objective-C result.
     */
        bool is_editable() const;
        /**
     * @brief Sets the `editable` property of `NSTableColumn`.
     * @details Gets and sets the editability state of this NSTableColumn. The default value is YES. When an NSTableView wants to start editing a dataCell, the following happens: 1. Check [tableColumn isEditable]. If that returns YES, check the (optional) delegate method with tableView:shouldEditTableColumn:row:. If that returns YES, check the [dataCell isEnabled] and [isEnabled isSelectable] states before attempting to edit.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_editable(bool value) const;
        /**
     * @brief Returns the `headerCell` property of `NSTableColumn`.
     * @details Gets and sets the headerCell associated with this NSTableColumn. 'cell' must be non nil, and should be a member of the NSTableHeaderCell class. The 'headerCell' is a strong reference, and will be retained.
     * @return The converted Objective-C result.
     */
        TableHeaderCell header_cell() const;
        /**
     * @brief Sets the `headerCell` property of `NSTableColumn`.
     * @details Gets and sets the headerCell associated with this NSTableColumn. 'cell' must be non nil, and should be a member of the NSTableHeaderCell class. The 'headerCell' is a strong reference, and will be retained.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_header_cell(const TableHeaderCell& value) const;
        /**
     * @brief Returns the `headerToolTip` property of `NSTableColumn`.
     * @details Get and set the Tool Tip for the NSTableColumn header that appears when hovering the mouse over the header for the NSTableColumn. The default value is 'nil', meaning there is no headerToolTip.
     * @return The converted Objective-C result.
     */
        std::string header_tool_tip() const;
        /**
     * @brief Sets the `headerToolTip` property of `NSTableColumn`.
     * @details Get and set the Tool Tip for the NSTableColumn header that appears when hovering the mouse over the header for the NSTableColumn. The default value is 'nil', meaning there is no headerToolTip.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_header_tool_tip(const std::string& value) const;
        /**
     * @brief Returns the `hidden` property of `NSTableColumn`.
     * @details Determines if the column is hidden or not. The isHidden value is stored out when the NSTableView automatically saves out NSTableColumn state. Note that columns which are hidden still exist in the the -[NSTableView tableColumns] array and -[NSTableView numberOfColumns] includes columns which are hidden. The default value is NO, meaning the NSTableColumn will not be hidden.
     * @return The converted Objective-C result.
     */
        bool is_hidden() const;
        /**
     * @brief Sets the `hidden` property of `NSTableColumn`.
     * @details Determines if the column is hidden or not. The isHidden value is stored out when the NSTableView automatically saves out NSTableColumn state. Note that columns which are hidden still exist in the the -[NSTableView tableColumns] array and -[NSTableView numberOfColumns] includes columns which are hidden. The default value is NO, meaning the NSTableColumn will not be hidden.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hidden(bool value) const;
        /**
     * @brief Returns the `identifier` property of `NSTableColumn`.
     * @details Gets and sets the string identifier associated with the NSTableColumn. 'identifier' will be copied. Prior to 10.7, the type was 'id', but was changed to 'NSString ' for NSUserInterfaceItemIdentification.
     * @return The converted Objective-C result.
     */
        std::string identifier() const;
        /**
     * @brief Sets the `identifier` property of `NSTableColumn`.
     * @details Gets and sets the string identifier associated with the NSTableColumn. 'identifier' will be copied. Prior to 10.7, the type was 'id', but was changed to 'NSString ' for NSUserInterfaceItemIdentification.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_identifier(const std::string& value) const;
        /**
     * @brief Returns the `maxWidth` property of `NSTableColumn`.
     * @details Gets and sets the maximum width of the NSTableColumn. The default for is MAXFLOAT on Leopard and higher. If -[self width] is greater than the 'maxWidth' value when -setMaxWidth: is called, the width will automatically be decreased to the maxWidth and [tableView tile] will be called.
     * @return The converted Objective-C result.
     */
        double max_width() const;
        /**
     * @brief Sets the `maxWidth` property of `NSTableColumn`.
     * @details Gets and sets the maximum width of the NSTableColumn. The default for is MAXFLOAT on Leopard and higher. If -[self width] is greater than the 'maxWidth' value when -setMaxWidth: is called, the width will automatically be decreased to the maxWidth and [tableView tile] will be called.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_max_width(double value) const;
        /**
     * @brief Returns the `minWidth` property of `NSTableColumn`.
     * @details Gets and sets the minimum width of the NSTableColumn. The default for is 10.0. If -[self width] is less than the 'minWidth' value when -setMinWidth: is called, the width will automatically be increased to the minWidth and [tableView tile] will be called. Note that if the NSTableColumn is the outlineTableColumn of an NSOutlineView, minWidth will return the maximum of the value set and NSOutlineView.indentationPerLevel.
     * @return The converted Objective-C result.
     */
        double min_width() const;
        /**
     * @brief Sets the `minWidth` property of `NSTableColumn`.
     * @details Gets and sets the minimum width of the NSTableColumn. The default for is 10.0. If -[self width] is less than the 'minWidth' value when -setMinWidth: is called, the width will automatically be increased to the minWidth and [tableView tile] will be called. Note that if the NSTableColumn is the outlineTableColumn of an NSOutlineView, minWidth will return the maximum of the value set and NSOutlineView.indentationPerLevel.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_min_width(double value) const;
        /**
     * @brief Returns the `resizingMask` property of `NSTableColumn`.
     * @return The converted Objective-C result.
     */
        TableColumnResizingOptions resizing_mask() const;
        /**
     * @brief Sets the `resizingMask` property of `NSTableColumn`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_resizing_mask(TableColumnResizingOptions value) const;
        /**
     * @brief Returns the `sortDescriptorPrototype` property of `NSTableColumn`.
     * @details A column is considered sortable if it has a sortDescriptorPrototype. This prototype defines several things about the columns sorting. The prototype's ascending value defines the default sorting direction. Its key defines an arbitrary attribute which helps clients identify what to sort, while the selector defines how to sort. Note that, it is not required that the key be the same as the identifier. However, the key must be unique from the key used by other columns. The sortDescriptor is archived.
     * @return The converted Objective-C result.
     */
        SortDescriptor sort_descriptor_prototype() const;
        /**
     * @brief Sets the `sortDescriptorPrototype` property of `NSTableColumn`.
     * @details A column is considered sortable if it has a sortDescriptorPrototype. This prototype defines several things about the columns sorting. The prototype's ascending value defines the default sorting direction. Its key defines an arbitrary attribute which helps clients identify what to sort, while the selector defines how to sort. Note that, it is not required that the key be the same as the identifier. However, the key must be unique from the key used by other columns. The sortDescriptor is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sort_descriptor_prototype(const SortDescriptor& value) const;
        /**
     * @brief Returns the `tableView` property of `NSTableColumn`.
     * @return The converted Objective-C result.
     */
        TableView table_view() const;
        /**
     * @brief Sets the `tableView` property of `NSTableColumn`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_table_view(const TableView& value) const;
        /**
     * @brief Returns the `title` property of `NSTableColumn`.
     * @details Provides access to the title of this column header.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSTableColumn`.
     * @details Provides access to the title of this column header.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
        /**
     * @brief Returns the `width` property of `NSTableColumn`.
     * @details Gets and sets the current width of the NSTableColumn. The default for is 100.0. Calling setWidth: with a width that is less than the minWidth or larger than the maxWidth will automatically be constrained to minWidth or maxWidth as appropriate.
     * @return The converted Objective-C result.
     */
        double width() const;
        /**
     * @brief Sets the `width` property of `NSTableColumn`.
     * @details Gets and sets the current width of the NSTableColumn. The default for is 100.0. Calling setWidth: with a width that is less than the minWidth or larger than the maxWidth will automatically be constrained to minWidth or maxWidth as appropriate.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_width(double value) const;
    };
}
