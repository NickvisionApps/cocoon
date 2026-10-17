#include "generated/collection_view_update_item.h"
#include "internal.h"

namespace cocoon
{
    CollectionViewUpdateItem::CollectionViewUpdateItem() : CollectionViewUpdateItem(Adopt{cocoon::internal::retain([[::NSCollectionViewUpdateItem alloc] init])})
    {
    }

    CollectionViewUpdateItem::CollectionViewUpdateItem(std::nullptr_t) : Object(nullptr)
    {
    }

    CollectionViewUpdateItem::CollectionViewUpdateItem(Adopt adopt) : Object(adopt)
    {
    }

    IndexPath CollectionViewUpdateItem::index_path_after_update() const
    {
        return cocoon::internal::wrap<IndexPath>([cocoon::internal::ns<::NSCollectionViewUpdateItem>(this) indexPathAfterUpdate]);
    }

    IndexPath CollectionViewUpdateItem::index_path_before_update() const
    {
        return cocoon::internal::wrap<IndexPath>([cocoon::internal::ns<::NSCollectionViewUpdateItem>(this) indexPathBeforeUpdate]);
    }

    CollectionUpdateAction CollectionViewUpdateItem::update_action() const
    {
        return static_cast<CollectionUpdateAction>([cocoon::internal::ns<::NSCollectionViewUpdateItem>(this) updateAction]);
    }
}
