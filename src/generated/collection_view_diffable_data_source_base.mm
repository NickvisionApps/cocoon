#include "generated/collection_view_diffable_data_source_base.h"
#include "internal.h"

namespace cocoon
{
    CollectionViewDiffableDataSourceBase::CollectionViewDiffableDataSourceBase(const CollectionView& collection_view, std::function<CollectionViewItem(CollectionView, IndexPath, Object)> item_provider) : CollectionViewDiffableDataSourceBase(Adopt{cocoon::internal::retain([[::NSCollectionViewDiffableDataSource alloc] initWithCollectionView:cocoon::internal::native<::NSCollectionView>(collection_view) itemProvider:(item_provider ? (::NSCollectionViewDiffableDataSourceItemProvider) ^ ::NSCollectionViewItem * (::NSCollectionView * a23_0, ::NSIndexPath * a23_1, id a23_2) { auto __r = item_provider(cocoon::internal::wrap<CollectionView>(a23_0), cocoon::internal::wrap<IndexPath>(a23_1), cocoon::internal::wrap<Object>(a23_2)); return cocoon::internal::native<::NSCollectionViewItem>(__r); } : (::NSCollectionViewDiffableDataSourceItemProvider)nil)])})
    {
    }

    CollectionViewDiffableDataSourceBase::CollectionViewDiffableDataSourceBase() : Object(nullptr)
    {
    }

    CollectionViewDiffableDataSourceBase::CollectionViewDiffableDataSourceBase(std::nullptr_t) : Object(nullptr)
    {
    }

    CollectionViewDiffableDataSourceBase::CollectionViewDiffableDataSourceBase(Adopt adopt) : Object(adopt)
    {
    }

    void CollectionViewDiffableDataSourceBase::apply_snapshot(const DiffableDataSourceSnapshotBase& snapshot, bool animating_differences) const
    {
        [cocoon::internal::ns<::NSCollectionViewDiffableDataSource>(this) applySnapshot:cocoon::internal::native<NSDiffableDataSourceSnapshot<id, id>>(snapshot) animatingDifferences:static_cast<::BOOL>(animating_differences)];
    }

    IndexPath CollectionViewDiffableDataSourceBase::index_path_for_item_identifier(const Object& identifier) const
    {
        return cocoon::internal::wrap<IndexPath>([cocoon::internal::ns<::NSCollectionViewDiffableDataSource>(this) indexPathForItemIdentifier:cocoon::internal::native_id(identifier)]);
    }

    Object CollectionViewDiffableDataSourceBase::item_identifier_for_index_path(const IndexPath& index_path) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSCollectionViewDiffableDataSource>(this) itemIdentifierForIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    DiffableDataSourceSnapshotBase CollectionViewDiffableDataSourceBase::snapshot() const
    {
        return cocoon::internal::wrap<DiffableDataSourceSnapshotBase>([cocoon::internal::ns<::NSCollectionViewDiffableDataSource>(this) snapshot]);
    }

    std::function<View(CollectionView, std::string, IndexPath)> CollectionViewDiffableDataSourceBase::supplementary_view_provider() const
    {
        return [&]() -> std::function<View(CollectionView, std::string, IndexPath)>
        {
            auto blk = (::NSCollectionViewDiffableDataSourceSupplementaryViewProvider)([cocoon::internal::ns<::NSCollectionViewDiffableDataSource>(this) supplementaryViewProvider]);
            if (!blk)
            {
                return {};
            }
            return [blk](CollectionView a24_0, std::string a24_1, IndexPath a24_2) -> View
            {
                auto __r = blk(cocoon::internal::native<::NSCollectionView>(a24_0), cocoon::internal::to(a24_1), cocoon::internal::native<::NSIndexPath>(a24_2));
                return cocoon::internal::wrap<View>(__r);
            };
        }();
    }

    void CollectionViewDiffableDataSourceBase::set_supplementary_view_provider(std::function<View(CollectionView, std::string, IndexPath)> value) const
    {
        [cocoon::internal::ns<::NSCollectionViewDiffableDataSource>(this) setSupplementaryViewProvider:(value ? (::NSCollectionViewDiffableDataSourceSupplementaryViewProvider) ^ ::NSView * (::NSCollectionView * a25_0, NSString * a25_1, ::NSIndexPath * a25_2) { auto __r = value(cocoon::internal::wrap<CollectionView>(a25_0), cocoon::internal::from(a25_1), cocoon::internal::wrap<IndexPath>(a25_2)); return cocoon::internal::native<::NSView>(__r); } : (::NSCollectionViewDiffableDataSourceSupplementaryViewProvider)nil)];
    }
}
