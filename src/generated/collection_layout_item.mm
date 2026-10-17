#include "generated/collection_layout_item.h"
#include "internal.h"

namespace cocoon
{
    CollectionLayoutItem::CollectionLayoutItem() : Object(nullptr)
    {
    }

    CollectionLayoutItem::CollectionLayoutItem(std::nullptr_t) : Object(nullptr)
    {
    }

    CollectionLayoutItem::CollectionLayoutItem(Adopt adopt) : Object(adopt)
    {
    }

    CollectionLayoutItem CollectionLayoutItem::item_with_layout_size(const CollectionLayoutSize& layout_size)
    {
        return cocoon::internal::wrap<CollectionLayoutItem>([::NSCollectionLayoutItem itemWithLayoutSize:cocoon::internal::native<::NSCollectionLayoutSize>(layout_size)]);
    }

    CollectionLayoutItem CollectionLayoutItem::item_with_layout_size(const CollectionLayoutSize& layout_size, const std::vector<CollectionLayoutSupplementaryItem>& supplementary_items)
    {
        return cocoon::internal::wrap<CollectionLayoutItem>([::NSCollectionLayoutItem itemWithLayoutSize:cocoon::internal::native<::NSCollectionLayoutSize>(layout_size)
                                                                                      supplementaryItems:cocoon::internal::to_array(supplementary_items, [](const CollectionLayoutSupplementaryItem& e) -> id
                                                                                                                                    {
                                                                                                                                        return cocoon::internal::native<::NSCollectionLayoutSupplementaryItem>(e);
                                                                                                                                    })]);
    }

    DirectionalEdgeInsets CollectionLayoutItem::content_insets() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionLayoutItem>(this) contentInsets]);
    }

    void CollectionLayoutItem::set_content_insets(const DirectionalEdgeInsets& value) const
    {
        [cocoon::internal::ns<::NSCollectionLayoutItem>(this) setContentInsets:cocoon::internal::to(value)];
    }

    CollectionLayoutEdgeSpacing CollectionLayoutItem::edge_spacing() const
    {
        return cocoon::internal::wrap<CollectionLayoutEdgeSpacing>([cocoon::internal::ns<::NSCollectionLayoutItem>(this) edgeSpacing]);
    }

    void CollectionLayoutItem::set_edge_spacing(const CollectionLayoutEdgeSpacing& value) const
    {
        [cocoon::internal::ns<::NSCollectionLayoutItem>(this) setEdgeSpacing:cocoon::internal::native<::NSCollectionLayoutEdgeSpacing>(value)];
    }

    CollectionLayoutSize CollectionLayoutItem::layout_size() const
    {
        return cocoon::internal::wrap<CollectionLayoutSize>([cocoon::internal::ns<::NSCollectionLayoutItem>(this) layoutSize]);
    }

    std::vector<CollectionLayoutSupplementaryItem> CollectionLayoutItem::supplementary_items() const
    {
        return cocoon::internal::from_array<CollectionLayoutSupplementaryItem>([cocoon::internal::ns<::NSCollectionLayoutItem>(this) supplementaryItems], [](id e) -> CollectionLayoutSupplementaryItem
                                                                               {
                                                                                   return cocoon::internal::wrap<CollectionLayoutSupplementaryItem>((::NSCollectionLayoutSupplementaryItem*)e);
                                                                               });
    }
}
