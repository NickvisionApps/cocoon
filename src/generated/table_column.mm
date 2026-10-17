#include "generated/table_column.h"
#include "internal.h"

namespace cocoon
{
    TableColumn::TableColumn(const std::string& identifier) : TableColumn(Adopt{cocoon::internal::retain([[::NSTableColumn alloc] initWithIdentifier:cocoon::internal::to(identifier)])})
    {
    }

    TableColumn::TableColumn() : TableColumn(Adopt{cocoon::internal::retain([[::NSTableColumn alloc] init])})
    {
    }

    TableColumn::TableColumn(std::nullptr_t) : Object(nullptr)
    {
    }

    TableColumn::TableColumn(Adopt adopt) : Object(adopt)
    {
    }

    Object TableColumn::data_cell_for_row(std::int64_t row) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTableColumn>(this) dataCellForRow:static_cast<::NSInteger>(row)]);
    }

    void TableColumn::size_to_fit() const
    {
        [cocoon::internal::ns<::NSTableColumn>(this) sizeToFit];
    }

    Object TableColumn::data_cell() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTableColumn>(this) dataCell]);
    }

    void TableColumn::set_data_cell(const Object& value) const
    {
        [cocoon::internal::ns<::NSTableColumn>(this) setDataCell:cocoon::internal::native_id(value)];
    }

    bool TableColumn::is_editable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableColumn>(this) isEditable]);
    }

    void TableColumn::set_editable(bool value) const
    {
        [cocoon::internal::ns<::NSTableColumn>(this) setEditable:static_cast<::BOOL>(value)];
    }

    TableHeaderCell TableColumn::header_cell() const
    {
        return cocoon::internal::wrap<TableHeaderCell>([cocoon::internal::ns<::NSTableColumn>(this) headerCell]);
    }

    void TableColumn::set_header_cell(const TableHeaderCell& value) const
    {
        [cocoon::internal::ns<::NSTableColumn>(this) setHeaderCell:cocoon::internal::native<::NSTableHeaderCell>(value)];
    }

    std::string TableColumn::header_tool_tip() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTableColumn>(this) headerToolTip]);
    }

    void TableColumn::set_header_tool_tip(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTableColumn>(this) setHeaderToolTip:cocoon::internal::to(value)];
    }

    bool TableColumn::is_hidden() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableColumn>(this) isHidden]);
    }

    void TableColumn::set_hidden(bool value) const
    {
        [cocoon::internal::ns<::NSTableColumn>(this) setHidden:static_cast<::BOOL>(value)];
    }

    std::string TableColumn::identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTableColumn>(this) identifier]);
    }

    void TableColumn::set_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTableColumn>(this) setIdentifier:cocoon::internal::to(value)];
    }

    double TableColumn::max_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTableColumn>(this) maxWidth]);
    }

    void TableColumn::set_max_width(double value) const
    {
        [cocoon::internal::ns<::NSTableColumn>(this) setMaxWidth:static_cast<::CGFloat>(value)];
    }

    double TableColumn::min_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTableColumn>(this) minWidth]);
    }

    void TableColumn::set_min_width(double value) const
    {
        [cocoon::internal::ns<::NSTableColumn>(this) setMinWidth:static_cast<::CGFloat>(value)];
    }

    TableColumnResizingOptions TableColumn::resizing_mask() const
    {
        return static_cast<TableColumnResizingOptions>([cocoon::internal::ns<::NSTableColumn>(this) resizingMask]);
    }

    void TableColumn::set_resizing_mask(TableColumnResizingOptions value) const
    {
        [cocoon::internal::ns<::NSTableColumn>(this) setResizingMask:static_cast<::NSTableColumnResizingOptions>(value)];
    }

    SortDescriptor TableColumn::sort_descriptor_prototype() const
    {
        return cocoon::internal::wrap<SortDescriptor>([cocoon::internal::ns<::NSTableColumn>(this) sortDescriptorPrototype]);
    }

    void TableColumn::set_sort_descriptor_prototype(const SortDescriptor& value) const
    {
        [cocoon::internal::ns<::NSTableColumn>(this) setSortDescriptorPrototype:cocoon::internal::native<::NSSortDescriptor>(value)];
    }

    TableView TableColumn::table_view() const
    {
        return cocoon::internal::wrap<TableView>([cocoon::internal::ns<::NSTableColumn>(this) tableView]);
    }

    void TableColumn::set_table_view(const TableView& value) const
    {
        [cocoon::internal::ns<::NSTableColumn>(this) setTableView:cocoon::internal::native<::NSTableView>(value)];
    }

    std::string TableColumn::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTableColumn>(this) title]);
    }

    void TableColumn::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTableColumn>(this) setTitle:cocoon::internal::to(value)];
    }

    double TableColumn::width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTableColumn>(this) width]);
    }

    void TableColumn::set_width(double value) const
    {
        [cocoon::internal::ns<::NSTableColumn>(this) setWidth:static_cast<::CGFloat>(value)];
    }
}
