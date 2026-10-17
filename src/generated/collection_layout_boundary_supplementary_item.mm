#include "generated/collection_layout_boundary_supplementary_item.h"
#include "internal.h"

namespace cocoon
{
    CollectionLayoutBoundarySupplementaryItem::CollectionLayoutBoundarySupplementaryItem() : CollectionLayoutSupplementaryItem(nullptr)
    {
    }

    CollectionLayoutBoundarySupplementaryItem::CollectionLayoutBoundarySupplementaryItem(std::nullptr_t) : CollectionLayoutSupplementaryItem(nullptr)
    {
    }

    CollectionLayoutBoundarySupplementaryItem::CollectionLayoutBoundarySupplementaryItem(Adopt adopt) : CollectionLayoutSupplementaryItem(adopt)
    {
    }

    CollectionLayoutBoundarySupplementaryItem CollectionLayoutBoundarySupplementaryItem::boundary_supplementary_item_with_layout_size(const CollectionLayoutSize& layout_size, const std::string& element_kind, RectAlignment alignment)
    {
        return cocoon::internal::wrap<CollectionLayoutBoundarySupplementaryItem>([::NSCollectionLayoutBoundarySupplementaryItem boundarySupplementaryItemWithLayoutSize:cocoon::internal::native<::NSCollectionLayoutSize>(layout_size) elementKind:cocoon::internal::to(element_kind) alignment:static_cast<::NSRectAlignment>(alignment)]);
    }

    CollectionLayoutBoundarySupplementaryItem CollectionLayoutBoundarySupplementaryItem::boundary_supplementary_item_with_layout_size(const CollectionLayoutSize& layout_size, const std::string& element_kind, RectAlignment alignment, const Point& absolute_offset)
    {
        return cocoon::internal::wrap<CollectionLayoutBoundarySupplementaryItem>([::NSCollectionLayoutBoundarySupplementaryItem boundarySupplementaryItemWithLayoutSize:cocoon::internal::native<::NSCollectionLayoutSize>(layout_size) elementKind:cocoon::internal::to(element_kind) alignment:static_cast<::NSRectAlignment>(alignment) absoluteOffset:cocoon::internal::to(absolute_offset)]);
    }

    RectAlignment CollectionLayoutBoundarySupplementaryItem::alignment() const
    {
        return static_cast<RectAlignment>([cocoon::internal::ns<::NSCollectionLayoutBoundarySupplementaryItem>(this) alignment]);
    }

    bool CollectionLayoutBoundarySupplementaryItem::extends_boundary() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionLayoutBoundarySupplementaryItem>(this) extendsBoundary]);
    }

    void CollectionLayoutBoundarySupplementaryItem::set_extends_boundary(bool value) const
    {
        [cocoon::internal::ns<::NSCollectionLayoutBoundarySupplementaryItem>(this) setExtendsBoundary:static_cast<::BOOL>(value)];
    }

    Point CollectionLayoutBoundarySupplementaryItem::offset() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionLayoutBoundarySupplementaryItem>(this) offset]);
    }

    bool CollectionLayoutBoundarySupplementaryItem::pin_to_visible_bounds() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionLayoutBoundarySupplementaryItem>(this) pinToVisibleBounds]);
    }

    void CollectionLayoutBoundarySupplementaryItem::set_pin_to_visible_bounds(bool value) const
    {
        [cocoon::internal::ns<::NSCollectionLayoutBoundarySupplementaryItem>(this) setPinToVisibleBounds:static_cast<::BOOL>(value)];
    }
}
