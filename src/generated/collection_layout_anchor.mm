#include "generated/collection_layout_anchor.h"
#include "internal.h"

namespace cocoon
{
    CollectionLayoutAnchor::CollectionLayoutAnchor() : Object(nullptr)
    {
    }

    CollectionLayoutAnchor::CollectionLayoutAnchor(std::nullptr_t) : Object(nullptr)
    {
    }

    CollectionLayoutAnchor::CollectionLayoutAnchor(Adopt adopt) : Object(adopt)
    {
    }

    CollectionLayoutAnchor CollectionLayoutAnchor::layout_anchor_with_edges(DirectionalRectEdge edges)
    {
        return cocoon::internal::wrap<CollectionLayoutAnchor>([::NSCollectionLayoutAnchor layoutAnchorWithEdges:static_cast<::NSDirectionalRectEdge>(edges)]);
    }

    CollectionLayoutAnchor CollectionLayoutAnchor::layout_anchor_with_edges(DirectionalRectEdge edges, const Point& absolute_offset)
    {
        return cocoon::internal::wrap<CollectionLayoutAnchor>([::NSCollectionLayoutAnchor layoutAnchorWithEdges:static_cast<::NSDirectionalRectEdge>(edges) absoluteOffset:cocoon::internal::to(absolute_offset)]);
    }

    DirectionalRectEdge CollectionLayoutAnchor::edges() const
    {
        return static_cast<DirectionalRectEdge>([cocoon::internal::ns<::NSCollectionLayoutAnchor>(this) edges]);
    }

    bool CollectionLayoutAnchor::is_absolute_offset() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionLayoutAnchor>(this) isAbsoluteOffset]);
    }

    bool CollectionLayoutAnchor::is_fractional_offset() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionLayoutAnchor>(this) isFractionalOffset]);
    }

    Point CollectionLayoutAnchor::offset() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionLayoutAnchor>(this) offset]);
    }
}
