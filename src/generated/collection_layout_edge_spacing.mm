#include "generated/collection_layout_edge_spacing.h"
#include "internal.h"

namespace cocoon
{
    CollectionLayoutEdgeSpacing::CollectionLayoutEdgeSpacing() : Object(nullptr)
    {
    }

    CollectionLayoutEdgeSpacing::CollectionLayoutEdgeSpacing(std::nullptr_t) : Object(nullptr)
    {
    }

    CollectionLayoutEdgeSpacing::CollectionLayoutEdgeSpacing(Adopt adopt) : Object(adopt)
    {
    }

    CollectionLayoutEdgeSpacing CollectionLayoutEdgeSpacing::spacing_for_leading(const CollectionLayoutSpacing& leading, const CollectionLayoutSpacing& top, const CollectionLayoutSpacing& trailing, const CollectionLayoutSpacing& bottom)
    {
        return cocoon::internal::wrap<CollectionLayoutEdgeSpacing>([::NSCollectionLayoutEdgeSpacing spacingForLeading:cocoon::internal::native<::NSCollectionLayoutSpacing>(leading) top:cocoon::internal::native<::NSCollectionLayoutSpacing>(top) trailing:cocoon::internal::native<::NSCollectionLayoutSpacing>(trailing) bottom:cocoon::internal::native<::NSCollectionLayoutSpacing>(bottom)]);
    }

    CollectionLayoutSpacing CollectionLayoutEdgeSpacing::bottom() const
    {
        return cocoon::internal::wrap<CollectionLayoutSpacing>([cocoon::internal::ns<::NSCollectionLayoutEdgeSpacing>(this) bottom]);
    }

    CollectionLayoutSpacing CollectionLayoutEdgeSpacing::leading() const
    {
        return cocoon::internal::wrap<CollectionLayoutSpacing>([cocoon::internal::ns<::NSCollectionLayoutEdgeSpacing>(this) leading]);
    }

    CollectionLayoutSpacing CollectionLayoutEdgeSpacing::top() const
    {
        return cocoon::internal::wrap<CollectionLayoutSpacing>([cocoon::internal::ns<::NSCollectionLayoutEdgeSpacing>(this) top]);
    }

    CollectionLayoutSpacing CollectionLayoutEdgeSpacing::trailing() const
    {
        return cocoon::internal::wrap<CollectionLayoutSpacing>([cocoon::internal::ns<::NSCollectionLayoutEdgeSpacing>(this) trailing]);
    }
}
