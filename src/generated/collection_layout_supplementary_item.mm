#include "generated/collection_layout_supplementary_item.h"
#include "internal.h"

namespace cocoon
{
    CollectionLayoutSupplementaryItem::CollectionLayoutSupplementaryItem() : CollectionLayoutItem(nullptr)
    {
    }

    CollectionLayoutSupplementaryItem::CollectionLayoutSupplementaryItem(std::nullptr_t) : CollectionLayoutItem(nullptr)
    {
    }

    CollectionLayoutSupplementaryItem::CollectionLayoutSupplementaryItem(Adopt adopt) : CollectionLayoutItem(adopt)
    {
    }

    CollectionLayoutSupplementaryItem CollectionLayoutSupplementaryItem::supplementary_item_with_layout_size(const CollectionLayoutSize& layout_size, const std::string& element_kind, const CollectionLayoutAnchor& container_anchor)
    {
        return cocoon::internal::wrap<CollectionLayoutSupplementaryItem>([::NSCollectionLayoutSupplementaryItem supplementaryItemWithLayoutSize:cocoon::internal::native<::NSCollectionLayoutSize>(layout_size) elementKind:cocoon::internal::to(element_kind) containerAnchor:cocoon::internal::native<::NSCollectionLayoutAnchor>(container_anchor)]);
    }

    CollectionLayoutSupplementaryItem CollectionLayoutSupplementaryItem::supplementary_item_with_layout_size(const CollectionLayoutSize& layout_size, const std::string& element_kind, const CollectionLayoutAnchor& container_anchor, const CollectionLayoutAnchor& item_anchor)
    {
        return cocoon::internal::wrap<CollectionLayoutSupplementaryItem>([::NSCollectionLayoutSupplementaryItem supplementaryItemWithLayoutSize:cocoon::internal::native<::NSCollectionLayoutSize>(layout_size) elementKind:cocoon::internal::to(element_kind) containerAnchor:cocoon::internal::native<::NSCollectionLayoutAnchor>(container_anchor) itemAnchor:cocoon::internal::native<::NSCollectionLayoutAnchor>(item_anchor)]);
    }

    CollectionLayoutAnchor CollectionLayoutSupplementaryItem::container_anchor() const
    {
        return cocoon::internal::wrap<CollectionLayoutAnchor>([cocoon::internal::ns<::NSCollectionLayoutSupplementaryItem>(this) containerAnchor]);
    }

    std::string CollectionLayoutSupplementaryItem::element_kind() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionLayoutSupplementaryItem>(this) elementKind]);
    }

    CollectionLayoutAnchor CollectionLayoutSupplementaryItem::item_anchor() const
    {
        return cocoon::internal::wrap<CollectionLayoutAnchor>([cocoon::internal::ns<::NSCollectionLayoutSupplementaryItem>(this) itemAnchor]);
    }

    std::int64_t CollectionLayoutSupplementaryItem::z_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCollectionLayoutSupplementaryItem>(this) zIndex]);
    }

    void CollectionLayoutSupplementaryItem::set_z_index(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSCollectionLayoutSupplementaryItem>(this) setZIndex:static_cast<::NSInteger>(value)];
    }
}
