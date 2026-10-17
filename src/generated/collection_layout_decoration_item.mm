#include "generated/collection_layout_decoration_item.h"
#include "internal.h"

namespace cocoon
{
    CollectionLayoutDecorationItem::CollectionLayoutDecorationItem() : CollectionLayoutItem(nullptr)
    {
    }

    CollectionLayoutDecorationItem::CollectionLayoutDecorationItem(std::nullptr_t) : CollectionLayoutItem(nullptr)
    {
    }

    CollectionLayoutDecorationItem::CollectionLayoutDecorationItem(Adopt adopt) : CollectionLayoutItem(adopt)
    {
    }

    CollectionLayoutDecorationItem CollectionLayoutDecorationItem::background_decoration_item_with_element_kind(const std::string& element_kind)
    {
        return cocoon::internal::wrap<CollectionLayoutDecorationItem>([::NSCollectionLayoutDecorationItem backgroundDecorationItemWithElementKind:cocoon::internal::to(element_kind)]);
    }

    std::string CollectionLayoutDecorationItem::element_kind() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionLayoutDecorationItem>(this) elementKind]);
    }

    std::int64_t CollectionLayoutDecorationItem::z_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCollectionLayoutDecorationItem>(this) zIndex]);
    }

    void CollectionLayoutDecorationItem::set_z_index(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSCollectionLayoutDecorationItem>(this) setZIndex:static_cast<::NSInteger>(value)];
    }
}
