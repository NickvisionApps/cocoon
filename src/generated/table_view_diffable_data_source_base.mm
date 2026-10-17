#include "generated/table_view_diffable_data_source_base.h"
#include "internal.h"

namespace cocoon
{
    TableViewDiffableDataSourceBase::TableViewDiffableDataSourceBase(const TableView& table_view, std::function<View(TableView, TableColumn, std::int64_t, Object)> cell_provider) : TableViewDiffableDataSourceBase(Adopt{cocoon::internal::retain([[::NSTableViewDiffableDataSource alloc] initWithTableView:cocoon::internal::native<::NSTableView>(table_view) cellProvider:(cell_provider ? (::NSTableViewDiffableDataSourceCellProvider) ^ ::NSView * (::NSTableView * a88_0, ::NSTableColumn * a88_1, ::NSInteger a88_2, id a88_3) { auto __r = cell_provider(cocoon::internal::wrap<TableView>(a88_0), cocoon::internal::wrap<TableColumn>(a88_1), static_cast<std::int64_t>(a88_2), cocoon::internal::wrap<Object>(a88_3)); return cocoon::internal::native<::NSView>(__r); } : (::NSTableViewDiffableDataSourceCellProvider)nil)])})
    {
    }

    TableViewDiffableDataSourceBase::TableViewDiffableDataSourceBase() : Object(nullptr)
    {
    }

    TableViewDiffableDataSourceBase::TableViewDiffableDataSourceBase(std::nullptr_t) : Object(nullptr)
    {
    }

    TableViewDiffableDataSourceBase::TableViewDiffableDataSourceBase(Adopt adopt) : Object(adopt)
    {
    }

    void TableViewDiffableDataSourceBase::apply_snapshot(const DiffableDataSourceSnapshotBase& snapshot, bool animating_differences) const
    {
        [cocoon::internal::ns<::NSTableViewDiffableDataSource>(this) applySnapshot:cocoon::internal::native<::NSDiffableDataSourceSnapshot>(snapshot) animatingDifferences:static_cast<::BOOL>(animating_differences)];
    }

    void TableViewDiffableDataSourceBase::apply_snapshot(const DiffableDataSourceSnapshotBase& snapshot, bool animating_differences, std::function<void()> completion) const
    {
        [cocoon::internal::ns<::NSTableViewDiffableDataSource>(this) applySnapshot:cocoon::internal::native<::NSDiffableDataSourceSnapshot>(snapshot) animatingDifferences:static_cast<::BOOL>(animating_differences) completion:(completion ? (void (^)(void)) ^ void() { completion(); } : (void (^)(void))nil)];
    }

    Object TableViewDiffableDataSourceBase::item_identifier_for_row(std::int64_t row) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTableViewDiffableDataSource>(this) itemIdentifierForRow:static_cast<::NSInteger>(row)]);
    }

    std::int64_t TableViewDiffableDataSourceBase::row_for_item_identifier(const Object& identifier) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableViewDiffableDataSource>(this) rowForItemIdentifier:cocoon::internal::native_id(identifier)]);
    }

    std::int64_t TableViewDiffableDataSourceBase::row_for_section_identifier(const Object& identifier) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableViewDiffableDataSource>(this) rowForSectionIdentifier:cocoon::internal::native_id(identifier)]);
    }

    Object TableViewDiffableDataSourceBase::section_identifier_for_row(std::int64_t row) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTableViewDiffableDataSource>(this) sectionIdentifierForRow:static_cast<::NSInteger>(row)]);
    }

    DiffableDataSourceSnapshotBase TableViewDiffableDataSourceBase::snapshot() const
    {
        return cocoon::internal::wrap<DiffableDataSourceSnapshotBase>([cocoon::internal::ns<::NSTableViewDiffableDataSource>(this) snapshot]);
    }

    TableViewAnimationOptions TableViewDiffableDataSourceBase::default_row_animation() const
    {
        return static_cast<TableViewAnimationOptions>([cocoon::internal::ns<::NSTableViewDiffableDataSource>(this) defaultRowAnimation]);
    }

    void TableViewDiffableDataSourceBase::set_default_row_animation(TableViewAnimationOptions value) const
    {
        [cocoon::internal::ns<::NSTableViewDiffableDataSource>(this) setDefaultRowAnimation:static_cast<::NSTableViewAnimationOptions>(value)];
    }

    std::function<TableRowView(TableView, std::int64_t, Object)> TableViewDiffableDataSourceBase::row_view_provider() const
    {
        return [&]() -> std::function<TableRowView(TableView, std::int64_t, Object)>
        {
            auto blk = (::NSTableViewDiffableDataSourceRowProvider)([cocoon::internal::ns<::NSTableViewDiffableDataSource>(this) rowViewProvider]);
            if (!blk)
            {
                return {};
            }
            return [blk](TableView a89_0, std::int64_t a89_1, Object a89_2) -> TableRowView
            {
                auto __r = blk(cocoon::internal::native<::NSTableView>(a89_0), static_cast<::NSInteger>(a89_1), cocoon::internal::native_id(a89_2));
                return cocoon::internal::wrap<TableRowView>(__r);
            };
        }();
    }

    void TableViewDiffableDataSourceBase::set_row_view_provider(std::function<TableRowView(TableView, std::int64_t, Object)> value) const
    {
        [cocoon::internal::ns<::NSTableViewDiffableDataSource>(this) setRowViewProvider:(value ? (::NSTableViewDiffableDataSourceRowProvider) ^ ::NSTableRowView * (::NSTableView * a90_0, ::NSInteger a90_1, id a90_2) { auto __r = value(cocoon::internal::wrap<TableView>(a90_0), static_cast<std::int64_t>(a90_1), cocoon::internal::wrap<Object>(a90_2)); return cocoon::internal::native<::NSTableRowView>(__r); } : (::NSTableViewDiffableDataSourceRowProvider)nil)];
    }

    std::function<View(TableView, std::int64_t, Object)> TableViewDiffableDataSourceBase::section_header_view_provider() const
    {
        return [&]() -> std::function<View(TableView, std::int64_t, Object)>
        {
            auto blk = (::NSTableViewDiffableDataSourceSectionHeaderViewProvider)([cocoon::internal::ns<::NSTableViewDiffableDataSource>(this) sectionHeaderViewProvider]);
            if (!blk)
            {
                return {};
            }
            return [blk](TableView a91_0, std::int64_t a91_1, Object a91_2) -> View
            {
                auto __r = blk(cocoon::internal::native<::NSTableView>(a91_0), static_cast<::NSInteger>(a91_1), cocoon::internal::native_id(a91_2));
                return cocoon::internal::wrap<View>(__r);
            };
        }();
    }

    void TableViewDiffableDataSourceBase::set_section_header_view_provider(std::function<View(TableView, std::int64_t, Object)> value) const
    {
        [cocoon::internal::ns<::NSTableViewDiffableDataSource>(this) setSectionHeaderViewProvider:(value ? (::NSTableViewDiffableDataSourceSectionHeaderViewProvider) ^ ::NSView * (::NSTableView * a92_0, ::NSInteger a92_1, id a92_2) { auto __r = value(cocoon::internal::wrap<TableView>(a92_0), static_cast<std::int64_t>(a92_1), cocoon::internal::wrap<Object>(a92_2)); return cocoon::internal::native<::NSView>(__r); } : (::NSTableViewDiffableDataSourceSectionHeaderViewProvider)nil)];
    }
}
