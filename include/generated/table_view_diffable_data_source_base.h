#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class DiffableDataSourceSnapshotBase;
    class TableColumn;
    class TableRowView;
    class TableView;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSTableViewDiffableDataSource` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Use the typed template @ref TableViewDiffableDataSource to supply SectionIdentifierType, ItemIdentifierType.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TableViewDiffableDataSourceBase table_view_diffable_data_source_base(nullptr);  // null handle; instances normally come from other API calls
     * table_view_diffable_data_source_base.set_default_row_animation(cocoon::TableViewAnimationOptions::EffectNone);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TableViewDiffableDataSourceBase table_view_diffable_data_source_base(nullptr);
     * table_view_diffable_data_source_base.set_default_row_animation(cocoon::TableViewAnimationOptions::EffectNone);
     * auto default_row_animation = table_view_diffable_data_source_base.default_row_animation();
     * table_view_diffable_data_source_base.item_identifier_for_row(1);
     * table_view_diffable_data_source_base.section_identifier_for_row(1);
     * table_view_diffable_data_source_base.snapshot();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstableviewdiffabledatasource
     */
    class TableViewDiffableDataSourceBase : public Object
    {
    public:
        /// @brief Creates a new `NSTableViewDiffableDataSource` instance and returns a handle to it.
        explicit TableViewDiffableDataSourceBase(const TableView& table_view, std::function<View(TableView, TableColumn, std::int64_t, Object)> cell_provider);
        TableViewDiffableDataSourceBase();
        /// @brief Creates a null handle that refers to no native object.
        TableViewDiffableDataSourceBase(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TableViewDiffableDataSourceBase(Adopt adopt);
        /**
     * @brief Calls `-[NSTableViewDiffableDataSource applySnapshot:animatingDifferences:]`.
     * @param snapshot Argument converted to the Objective-C parameter of the same role.
     * @param animating_differences Argument converted to the Objective-C parameter of the same role.
     */
        void apply_snapshot(const DiffableDataSourceSnapshotBase& snapshot, bool animating_differences) const;
        /**
     * @brief Calls `-[NSTableViewDiffableDataSource applySnapshot:animatingDifferences:completion:]`.
     * @param snapshot Argument converted to the Objective-C parameter of the same role.
     * @param animating_differences Argument converted to the Objective-C parameter of the same role.
     * @param completion Argument converted to the Objective-C parameter of the same role.
     */
        void apply_snapshot(const DiffableDataSourceSnapshotBase& snapshot, bool animating_differences, std::function<void()> completion) const;
        /**
     * @brief Calls `-[NSTableViewDiffableDataSource itemIdentifierForRow:]`.
     * @param row Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object item_identifier_for_row(std::int64_t row) const;
        /**
     * @brief Calls `-[NSTableViewDiffableDataSource rowForItemIdentifier:]`.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t row_for_item_identifier(const Object& identifier) const;
        /**
     * @brief Calls `-[NSTableViewDiffableDataSource rowForSectionIdentifier:]`.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t row_for_section_identifier(const Object& identifier) const;
        /**
     * @brief Calls `-[NSTableViewDiffableDataSource sectionIdentifierForRow:]`.
     * @param row Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object section_identifier_for_row(std::int64_t row) const;
        /**
     * @brief Calls `-[NSTableViewDiffableDataSource snapshot]`.
     * @return The converted Objective-C result.
     */
        DiffableDataSourceSnapshotBase snapshot() const;
        /**
     * @brief Returns the `defaultRowAnimation` property of `NSTableViewDiffableDataSource`.
     * @return The converted Objective-C result.
     */
        TableViewAnimationOptions default_row_animation() const;
        /**
     * @brief Sets the `defaultRowAnimation` property of `NSTableViewDiffableDataSource`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_row_animation(TableViewAnimationOptions value) const;
        /**
     * @brief Returns the `rowViewProvider` property of `NSTableViewDiffableDataSource`.
     * @return The converted Objective-C result.
     */
        std::function<TableRowView(TableView, std::int64_t, Object)> row_view_provider() const;
        /**
     * @brief Sets the `rowViewProvider` property of `NSTableViewDiffableDataSource`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_row_view_provider(std::function<TableRowView(TableView, std::int64_t, Object)> value) const;
        /**
     * @brief Returns the `sectionHeaderViewProvider` property of `NSTableViewDiffableDataSource`.
     * @return The converted Objective-C result.
     */
        std::function<View(TableView, std::int64_t, Object)> section_header_view_provider() const;
        /**
     * @brief Sets the `sectionHeaderViewProvider` property of `NSTableViewDiffableDataSource`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_section_header_view_provider(std::function<View(TableView, std::int64_t, Object)> value) const;
    };

    template <class SectionIdentifierType, class ItemIdentifierType>
    class TableViewDiffableDataSource : public TableViewDiffableDataSourceBase
    {
    public:
        using TableViewDiffableDataSourceBase::TableViewDiffableDataSourceBase;
        TableViewDiffableDataSource() : TableViewDiffableDataSourceBase()
        {
        }
        TableViewDiffableDataSource(const TableViewDiffableDataSourceBase& other) : TableViewDiffableDataSourceBase(other)
        {
        }
        using TableViewDiffableDataSourceBase::apply_snapshot;
        using TableViewDiffableDataSourceBase::default_row_animation;
        using TableViewDiffableDataSourceBase::item_identifier_for_row;
        using TableViewDiffableDataSourceBase::row_for_item_identifier;
        using TableViewDiffableDataSourceBase::row_for_section_identifier;
        using TableViewDiffableDataSourceBase::row_view_provider;
        using TableViewDiffableDataSourceBase::section_header_view_provider;
        using TableViewDiffableDataSourceBase::section_identifier_for_row;
        using TableViewDiffableDataSourceBase::set_default_row_animation;
        using TableViewDiffableDataSourceBase::set_row_view_provider;
        using TableViewDiffableDataSourceBase::set_section_header_view_provider;
        using TableViewDiffableDataSourceBase::snapshot;
        auto item_identifier_for_row(std::int64_t row) const
        {
            return cocoon::unbox<ItemIdentifierType>(TableViewDiffableDataSourceBase::item_identifier_for_row(row));
        }
        auto row_for_item_identifier(const ItemIdentifierType& identifier) const
        {
            return TableViewDiffableDataSourceBase::row_for_item_identifier(cocoon::box(identifier));
        }
        auto row_for_section_identifier(const SectionIdentifierType& identifier) const
        {
            return TableViewDiffableDataSourceBase::row_for_section_identifier(cocoon::box(identifier));
        }
        auto section_identifier_for_row(std::int64_t row) const
        {
            return cocoon::unbox<SectionIdentifierType>(TableViewDiffableDataSourceBase::section_identifier_for_row(row));
        }
    };
}
