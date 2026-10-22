#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CollectionView;
    class CollectionViewItem;
    class DiffableDataSourceSnapshotBase;
    class IndexPath;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionViewDiffableDataSource` (AppKit).
     * @details NSCollectionViewDiffableDataSource offers an identifier-based interface for providing an NSCollectionView's content. It automatically performs the inserts, deletes, and moves necessary to transition an NSCollectionView from one model-state snapshot to another.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Use the typed template @ref CollectionViewDiffableDataSource to supply SectionIdentifierType, ItemIdentifierType.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionViewDiffableDataSourceBase collection_view_diffable_data_source_base(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionViewDiffableDataSourceBase collection_view_diffable_data_source_base(nullptr);
     * collection_view_diffable_data_source_base.item_identifier_for_index_path(cocoon::IndexPath());
     * collection_view_diffable_data_source_base.snapshot();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionviewdiffabledatasource
     */
    class CollectionViewDiffableDataSourceBase : public Object
    {
    public:
        /// @brief Creates a new `NSCollectionViewDiffableDataSource` instance and returns a handle to it.
        explicit CollectionViewDiffableDataSourceBase(const CollectionView& collection_view, std::function<CollectionViewItem(CollectionView, IndexPath, Object)> item_provider);
        CollectionViewDiffableDataSourceBase();
        /// @brief Creates a null handle that refers to no native object.
        CollectionViewDiffableDataSourceBase(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionViewDiffableDataSourceBase(Adopt adopt);
        /**
         * @brief Calls `-[NSCollectionViewDiffableDataSource applySnapshot:animatingDifferences:]`.
         * @param snapshot Argument converted to the Objective-C parameter of the same role.
         * @param animating_differences Argument converted to the Objective-C parameter of the same role.
         */
        void apply_snapshot(const DiffableDataSourceSnapshotBase& snapshot, bool animating_differences) const;
        /**
         * @brief Calls `-[NSCollectionViewDiffableDataSource indexPathForItemIdentifier:]`.
         * @param identifier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        IndexPath index_path_for_item_identifier(const Object& identifier) const;
        /**
         * @brief Calls `-[NSCollectionViewDiffableDataSource itemIdentifierForIndexPath:]`.
         * @param index_path Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object item_identifier_for_index_path(const IndexPath& index_path) const;
        /**
         * @brief Calls `-[NSCollectionViewDiffableDataSource snapshot]`.
         * @return The converted Objective-C result.
         */
        DiffableDataSourceSnapshotBase snapshot() const;
        /**
         * @brief Returns the `supplementaryViewProvider` property of `NSCollectionViewDiffableDataSource`.
         * @return The converted Objective-C result.
         */
        std::function<View(CollectionView, std::string, IndexPath)> supplementary_view_provider() const;
        /**
         * @brief Sets the `supplementaryViewProvider` property of `NSCollectionViewDiffableDataSource`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_supplementary_view_provider(std::function<View(CollectionView, std::string, IndexPath)> value) const;
    };

    template <class SectionIdentifierType, class ItemIdentifierType>
    class CollectionViewDiffableDataSource : public CollectionViewDiffableDataSourceBase
    {
    public:
        using CollectionViewDiffableDataSourceBase::CollectionViewDiffableDataSourceBase;
        CollectionViewDiffableDataSource() : CollectionViewDiffableDataSourceBase()
        {
        }
        CollectionViewDiffableDataSource(const CollectionViewDiffableDataSourceBase& other) : CollectionViewDiffableDataSourceBase(other)
        {
        }
        using CollectionViewDiffableDataSourceBase::apply_snapshot;
        using CollectionViewDiffableDataSourceBase::index_path_for_item_identifier;
        using CollectionViewDiffableDataSourceBase::item_identifier_for_index_path;
        using CollectionViewDiffableDataSourceBase::set_supplementary_view_provider;
        using CollectionViewDiffableDataSourceBase::snapshot;
        using CollectionViewDiffableDataSourceBase::supplementary_view_provider;
        auto index_path_for_item_identifier(const ItemIdentifierType& identifier) const
        {
            return CollectionViewDiffableDataSourceBase::index_path_for_item_identifier(cocoon::box(identifier));
        }
        auto item_identifier_for_index_path(const IndexPath& index_path) const
        {
            return cocoon::unbox<ItemIdentifierType>(CollectionViewDiffableDataSourceBase::item_identifier_for_index_path(index_path));
        }
    };
}
