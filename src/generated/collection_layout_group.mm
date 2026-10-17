#include "generated/collection_layout_group.h"
#include "internal.h"

namespace cocoon
{
    CollectionLayoutGroup::CollectionLayoutGroup() : CollectionLayoutItem(nullptr)
    {
    }

    CollectionLayoutGroup::CollectionLayoutGroup(std::nullptr_t) : CollectionLayoutItem(nullptr)
    {
    }

    CollectionLayoutGroup::CollectionLayoutGroup(Adopt adopt) : CollectionLayoutItem(adopt)
    {
    }

    CollectionLayoutGroup CollectionLayoutGroup::custom_group_with_layout_size(const CollectionLayoutSize& layout_size, std::function<std::vector<CollectionLayoutGroupCustomItem>(Object)> item_provider)
    {
        return cocoon::internal::wrap<CollectionLayoutGroup>([::NSCollectionLayoutGroup customGroupWithLayoutSize:cocoon::internal::native<::NSCollectionLayoutSize>(layout_size) itemProvider:(item_provider ? (::NSCollectionLayoutGroupCustomItemProvider) ^ NSArray * (id a18_0) { auto __r = item_provider(cocoon::internal::wrap<Object>(a18_0)); return cocoon::internal::to_array(__r, [](const CollectionLayoutGroupCustomItem& e) -> id { return cocoon::internal::native<::NSCollectionLayoutGroupCustomItem>(e); }); } : (::NSCollectionLayoutGroupCustomItemProvider)nil)]);
    }

    CollectionLayoutGroup CollectionLayoutGroup::horizontal_group_with_layout_size(const CollectionLayoutSize& layout_size, const CollectionLayoutItem& subitem, std::int64_t count)
    {
        return cocoon::internal::wrap<CollectionLayoutGroup>([::NSCollectionLayoutGroup horizontalGroupWithLayoutSize:cocoon::internal::native<::NSCollectionLayoutSize>(layout_size) subitem:cocoon::internal::native<::NSCollectionLayoutItem>(subitem) count:static_cast<::NSInteger>(count)]);
    }

    CollectionLayoutGroup CollectionLayoutGroup::horizontal_group_with_layout_size(const CollectionLayoutSize& layout_size, const std::vector<CollectionLayoutItem>& subitems)
    {
        return cocoon::internal::wrap<CollectionLayoutGroup>([::NSCollectionLayoutGroup horizontalGroupWithLayoutSize:cocoon::internal::native<::NSCollectionLayoutSize>(layout_size)
                                                                                               subitems:cocoon::internal::to_array(subitems, [](const CollectionLayoutItem& e) -> id
                                                                                                                     {
                                                                                                                         return cocoon::internal::native<::NSCollectionLayoutItem>(e);
                                                                                                                     })]);
    }

    CollectionLayoutGroup CollectionLayoutGroup::vertical_group_with_layout_size(const CollectionLayoutSize& layout_size, const CollectionLayoutItem& subitem, std::int64_t count)
    {
        return cocoon::internal::wrap<CollectionLayoutGroup>([::NSCollectionLayoutGroup verticalGroupWithLayoutSize:cocoon::internal::native<::NSCollectionLayoutSize>(layout_size) subitem:cocoon::internal::native<::NSCollectionLayoutItem>(subitem) count:static_cast<::NSInteger>(count)]);
    }

    CollectionLayoutGroup CollectionLayoutGroup::vertical_group_with_layout_size(const CollectionLayoutSize& layout_size, const std::vector<CollectionLayoutItem>& subitems)
    {
        return cocoon::internal::wrap<CollectionLayoutGroup>([::NSCollectionLayoutGroup verticalGroupWithLayoutSize:cocoon::internal::native<::NSCollectionLayoutSize>(layout_size)
                                                                                             subitems:cocoon::internal::to_array(subitems, [](const CollectionLayoutItem& e) -> id
                                                                                                                   {
                                                                                                                       return cocoon::internal::native<::NSCollectionLayoutItem>(e);
                                                                                                                   })]);
    }

    std::string CollectionLayoutGroup::visual_description() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionLayoutGroup>(this) visualDescription]);
    }

    CollectionLayoutSpacing CollectionLayoutGroup::inter_item_spacing() const
    {
        return cocoon::internal::wrap<CollectionLayoutSpacing>([cocoon::internal::ns<::NSCollectionLayoutGroup>(this) interItemSpacing]);
    }

    void CollectionLayoutGroup::set_inter_item_spacing(const CollectionLayoutSpacing& value) const
    {
        [cocoon::internal::ns<::NSCollectionLayoutGroup>(this) setInterItemSpacing:cocoon::internal::native<::NSCollectionLayoutSpacing>(value)];
    }

    std::vector<CollectionLayoutItem> CollectionLayoutGroup::subitems() const
    {
        return cocoon::internal::from_array<CollectionLayoutItem>([cocoon::internal::ns<::NSCollectionLayoutGroup>(this) subitems], [](id e) -> CollectionLayoutItem
                                                    {
                                                        return cocoon::internal::wrap<CollectionLayoutItem>((::NSCollectionLayoutItem*)e);
                                                    });
    }

    std::vector<CollectionLayoutSupplementaryItem> CollectionLayoutGroup::supplementary_items() const
    {
        return cocoon::internal::from_array<CollectionLayoutSupplementaryItem>([cocoon::internal::ns<::NSCollectionLayoutGroup>(this) supplementaryItems], [](id e) -> CollectionLayoutSupplementaryItem
                                                                 {
                                                                     return cocoon::internal::wrap<CollectionLayoutSupplementaryItem>((::NSCollectionLayoutSupplementaryItem*)e);
                                                                 });
    }

    void CollectionLayoutGroup::set_supplementary_items(const std::vector<CollectionLayoutSupplementaryItem>& value) const
    {
        [cocoon::internal::ns<::NSCollectionLayoutGroup>(this) setSupplementaryItems:cocoon::internal::to_array(value, [](const CollectionLayoutSupplementaryItem& e) -> id
                                                                                    {
                                                                                        return cocoon::internal::native<::NSCollectionLayoutSupplementaryItem>(e);
                                                                                    })];
    }
}
