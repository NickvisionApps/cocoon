#include "generated/collection_layout_group_custom_item.h"
#include "internal.h"

namespace cocoon
{
    CollectionLayoutGroupCustomItem::CollectionLayoutGroupCustomItem() : Object(nullptr)
    {
    }

    CollectionLayoutGroupCustomItem::CollectionLayoutGroupCustomItem(std::nullptr_t) : Object(nullptr)
    {
    }

    CollectionLayoutGroupCustomItem::CollectionLayoutGroupCustomItem(Adopt adopt) : Object(adopt)
    {
    }

    CollectionLayoutGroupCustomItem CollectionLayoutGroupCustomItem::custom_item_with_frame(const Rect& frame)
    {
        return cocoon::internal::wrap<CollectionLayoutGroupCustomItem>([::NSCollectionLayoutGroupCustomItem customItemWithFrame:cocoon::internal::to(frame)]);
    }

    CollectionLayoutGroupCustomItem CollectionLayoutGroupCustomItem::custom_item_with_frame(const Rect& frame, std::int64_t z_index)
    {
        return cocoon::internal::wrap<CollectionLayoutGroupCustomItem>([::NSCollectionLayoutGroupCustomItem customItemWithFrame:cocoon::internal::to(frame) zIndex:static_cast<::NSInteger>(z_index)]);
    }

    Rect CollectionLayoutGroupCustomItem::frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionLayoutGroupCustomItem>(this) frame]);
    }

    std::int64_t CollectionLayoutGroupCustomItem::z_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCollectionLayoutGroupCustomItem>(this) zIndex]);
    }
}
