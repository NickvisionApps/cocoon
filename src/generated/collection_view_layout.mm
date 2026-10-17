#include "generated/collection_view_layout.h"
#include "internal.h"

namespace cocoon
{
    CollectionViewLayout::CollectionViewLayout(const std::string& element_kind, const IndexPath& decoration_index_path) : CollectionViewLayout(Adopt{cocoon::internal::retain([[::NSCollectionViewLayout alloc] initialLayoutAttributesForAppearingDecorationElementOfKind:cocoon::internal::to(element_kind) atIndexPath:cocoon::internal::native<::NSIndexPath>(decoration_index_path)])})
    {
    }

    CollectionViewLayout::CollectionViewLayout(const IndexPath& item_index_path) : CollectionViewLayout(Adopt{cocoon::internal::retain([[::NSCollectionViewLayout alloc] initialLayoutAttributesForAppearingItemAtIndexPath:cocoon::internal::native<::NSIndexPath>(item_index_path)])})
    {
    }

    CollectionViewLayout::CollectionViewLayout() : CollectionViewLayout(Adopt{cocoon::internal::retain([[::NSCollectionViewLayout alloc] init])})
    {
    }

    CollectionViewLayout::CollectionViewLayout(std::nullptr_t) : Object(nullptr)
    {
    }

    CollectionViewLayout::CollectionViewLayout(Adopt adopt) : Object(adopt)
    {
    }

    CollectionViewLayoutAttributes CollectionViewLayout::final_layout_attributes_for_disappearing_decoration_element_of_kind(const std::string& element_kind, const IndexPath& decoration_index_path) const
    {
        return cocoon::internal::wrap<CollectionViewLayoutAttributes>([cocoon::internal::ns<::NSCollectionViewLayout>(this) finalLayoutAttributesForDisappearingDecorationElementOfKind:cocoon::internal::to(element_kind) atIndexPath:cocoon::internal::native<::NSIndexPath>(decoration_index_path)]);
    }

    CollectionViewLayoutAttributes CollectionViewLayout::final_layout_attributes_for_disappearing_item_at_index_path(const IndexPath& item_index_path) const
    {
        return cocoon::internal::wrap<CollectionViewLayoutAttributes>([cocoon::internal::ns<::NSCollectionViewLayout>(this) finalLayoutAttributesForDisappearingItemAtIndexPath:cocoon::internal::native<::NSIndexPath>(item_index_path)]);
    }

    CollectionViewLayoutAttributes CollectionViewLayout::final_layout_attributes_for_disappearing_supplementary_element_of_kind(const std::string& element_kind, const IndexPath& element_index_path) const
    {
        return cocoon::internal::wrap<CollectionViewLayoutAttributes>([cocoon::internal::ns<::NSCollectionViewLayout>(this) finalLayoutAttributesForDisappearingSupplementaryElementOfKind:cocoon::internal::to(element_kind) atIndexPath:cocoon::internal::native<::NSIndexPath>(element_index_path)]);
    }

    void CollectionViewLayout::finalize_animated_bounds_change() const
    {
        [cocoon::internal::ns<::NSCollectionViewLayout>(this) finalizeAnimatedBoundsChange];
    }

    void CollectionViewLayout::finalize_collection_view_updates() const
    {
        [cocoon::internal::ns<::NSCollectionViewLayout>(this) finalizeCollectionViewUpdates];
    }

    void CollectionViewLayout::finalize_layout_transition() const
    {
        [cocoon::internal::ns<::NSCollectionViewLayout>(this) finalizeLayoutTransition];
    }

    std::vector<IndexPath> CollectionViewLayout::index_paths_to_delete_for_decoration_view_of_kind(const std::string& element_kind) const
    {
        return cocoon::internal::from_array<IndexPath>([[cocoon::internal::ns<::NSCollectionViewLayout>(this) indexPathsToDeleteForDecorationViewOfKind:cocoon::internal::to(element_kind)] allObjects], [](id e) -> IndexPath
                                         {
                                             return cocoon::internal::wrap<IndexPath>((::NSIndexPath*)e);
                                         });
    }

    std::vector<IndexPath> CollectionViewLayout::index_paths_to_delete_for_supplementary_view_of_kind(const std::string& element_kind) const
    {
        return cocoon::internal::from_array<IndexPath>([[cocoon::internal::ns<::NSCollectionViewLayout>(this) indexPathsToDeleteForSupplementaryViewOfKind:cocoon::internal::to(element_kind)] allObjects], [](id e) -> IndexPath
                                         {
                                             return cocoon::internal::wrap<IndexPath>((::NSIndexPath*)e);
                                         });
    }

    std::vector<IndexPath> CollectionViewLayout::index_paths_to_insert_for_decoration_view_of_kind(const std::string& element_kind) const
    {
        return cocoon::internal::from_array<IndexPath>([[cocoon::internal::ns<::NSCollectionViewLayout>(this) indexPathsToInsertForDecorationViewOfKind:cocoon::internal::to(element_kind)] allObjects], [](id e) -> IndexPath
                                         {
                                             return cocoon::internal::wrap<IndexPath>((::NSIndexPath*)e);
                                         });
    }

    std::vector<IndexPath> CollectionViewLayout::index_paths_to_insert_for_supplementary_view_of_kind(const std::string& element_kind) const
    {
        return cocoon::internal::from_array<IndexPath>([[cocoon::internal::ns<::NSCollectionViewLayout>(this) indexPathsToInsertForSupplementaryViewOfKind:cocoon::internal::to(element_kind)] allObjects], [](id e) -> IndexPath
                                         {
                                             return cocoon::internal::wrap<IndexPath>((::NSIndexPath*)e);
                                         });
    }

    void CollectionViewLayout::invalidate_layout() const
    {
        [cocoon::internal::ns<::NSCollectionViewLayout>(this) invalidateLayout];
    }

    void CollectionViewLayout::invalidate_layout_with_context(const CollectionViewLayoutInvalidationContext& context) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayout>(this) invalidateLayoutWithContext:cocoon::internal::native<::NSCollectionViewLayoutInvalidationContext>(context)];
    }

    CollectionViewLayoutInvalidationContext CollectionViewLayout::invalidation_context_for_bounds_change(const Rect& new_bounds) const
    {
        return cocoon::internal::wrap<CollectionViewLayoutInvalidationContext>([cocoon::internal::ns<::NSCollectionViewLayout>(this) invalidationContextForBoundsChange:cocoon::internal::to(new_bounds)]);
    }

    CollectionViewLayoutInvalidationContext CollectionViewLayout::invalidation_context_for_preferred_layout_attributes(const CollectionViewLayoutAttributes& preferred_attributes, const CollectionViewLayoutAttributes& original_attributes) const
    {
        return cocoon::internal::wrap<CollectionViewLayoutInvalidationContext>([cocoon::internal::ns<::NSCollectionViewLayout>(this) invalidationContextForPreferredLayoutAttributes:cocoon::internal::native<::NSCollectionViewLayoutAttributes>(preferred_attributes) withOriginalAttributes:cocoon::internal::native<::NSCollectionViewLayoutAttributes>(original_attributes)]);
    }

    CollectionViewLayoutAttributes CollectionViewLayout::layout_attributes_for_decoration_view_of_kind(const std::string& element_kind, const IndexPath& index_path) const
    {
        return cocoon::internal::wrap<CollectionViewLayoutAttributes>([cocoon::internal::ns<::NSCollectionViewLayout>(this) layoutAttributesForDecorationViewOfKind:cocoon::internal::to(element_kind) atIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    CollectionViewLayoutAttributes CollectionViewLayout::layout_attributes_for_drop_target_at_point(const Point& point_in_collection_view) const
    {
        return cocoon::internal::wrap<CollectionViewLayoutAttributes>([cocoon::internal::ns<::NSCollectionViewLayout>(this) layoutAttributesForDropTargetAtPoint:cocoon::internal::to(point_in_collection_view)]);
    }

    std::vector<CollectionViewLayoutAttributes> CollectionViewLayout::layout_attributes_for_elements_in_rect(const Rect& rect) const
    {
        return cocoon::internal::from_array<CollectionViewLayoutAttributes>([cocoon::internal::ns<::NSCollectionViewLayout>(this) layoutAttributesForElementsInRect:cocoon::internal::to(rect)], [](id e) -> CollectionViewLayoutAttributes
                                                              {
                                                                  return cocoon::internal::wrap<CollectionViewLayoutAttributes>((::NSCollectionViewLayoutAttributes*)e);
                                                              });
    }

    CollectionViewLayoutAttributes CollectionViewLayout::layout_attributes_for_inter_item_gap_before_index_path(const IndexPath& index_path) const
    {
        return cocoon::internal::wrap<CollectionViewLayoutAttributes>([cocoon::internal::ns<::NSCollectionViewLayout>(this) layoutAttributesForInterItemGapBeforeIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    CollectionViewLayoutAttributes CollectionViewLayout::layout_attributes_for_item_at_index_path(const IndexPath& index_path) const
    {
        return cocoon::internal::wrap<CollectionViewLayoutAttributes>([cocoon::internal::ns<::NSCollectionViewLayout>(this) layoutAttributesForItemAtIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    CollectionViewLayoutAttributes CollectionViewLayout::layout_attributes_for_supplementary_view_of_kind(const std::string& element_kind, const IndexPath& index_path) const
    {
        return cocoon::internal::wrap<CollectionViewLayoutAttributes>([cocoon::internal::ns<::NSCollectionViewLayout>(this) layoutAttributesForSupplementaryViewOfKind:cocoon::internal::to(element_kind) atIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    void CollectionViewLayout::prepare_for_animated_bounds_change(const Rect& old_bounds) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayout>(this) prepareForAnimatedBoundsChange:cocoon::internal::to(old_bounds)];
    }

    void CollectionViewLayout::prepare_for_collection_view_updates(const std::vector<CollectionViewUpdateItem>& update_items) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayout>(this) prepareForCollectionViewUpdates:cocoon::internal::to_array(update_items, [](const CollectionViewUpdateItem& e) -> id
                                                                                             {
                                                                                                 return cocoon::internal::native<::NSCollectionViewUpdateItem>(e);
                                                                                             })];
    }

    void CollectionViewLayout::prepare_for_transition_from_layout(const CollectionViewLayout& old_layout) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayout>(this) prepareForTransitionFromLayout:cocoon::internal::native<::NSCollectionViewLayout>(old_layout)];
    }

    void CollectionViewLayout::prepare_for_transition_to_layout(const CollectionViewLayout& new_layout) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayout>(this) prepareForTransitionToLayout:cocoon::internal::native<::NSCollectionViewLayout>(new_layout)];
    }

    void CollectionViewLayout::prepare_layout() const
    {
        [cocoon::internal::ns<::NSCollectionViewLayout>(this) prepareLayout];
    }

    void CollectionViewLayout::register_class(const std::string& view_class, const std::string& element_kind) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayout>(this) registerClass:NSClassFromString(cocoon::internal::to(view_class)) forDecorationViewOfKind:cocoon::internal::to(element_kind)];
    }

    void CollectionViewLayout::register_nib(const Nib& nib, const std::string& element_kind) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayout>(this) registerNib:cocoon::internal::native<::NSNib>(nib) forDecorationViewOfKind:cocoon::internal::to(element_kind)];
    }

    bool CollectionViewLayout::should_invalidate_layout_for_bounds_change(const Rect& new_bounds) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionViewLayout>(this) shouldInvalidateLayoutForBoundsChange:cocoon::internal::to(new_bounds)]);
    }

    bool CollectionViewLayout::should_invalidate_layout_for_preferred_layout_attributes(const CollectionViewLayoutAttributes& preferred_attributes, const CollectionViewLayoutAttributes& original_attributes) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionViewLayout>(this) shouldInvalidateLayoutForPreferredLayoutAttributes:cocoon::internal::native<::NSCollectionViewLayoutAttributes>(preferred_attributes) withOriginalAttributes:cocoon::internal::native<::NSCollectionViewLayoutAttributes>(original_attributes)]);
    }

    Point CollectionViewLayout::target_content_offset_for_proposed_content_offset(const Point& proposed_content_offset) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewLayout>(this) targetContentOffsetForProposedContentOffset:cocoon::internal::to(proposed_content_offset)]);
    }

    Point CollectionViewLayout::target_content_offset_for_proposed_content_offset(const Point& proposed_content_offset, const Point& velocity) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewLayout>(this) targetContentOffsetForProposedContentOffset:cocoon::internal::to(proposed_content_offset) withScrollingVelocity:cocoon::internal::to(velocity)]);
    }

    CollectionView CollectionViewLayout::collection_view() const
    {
        return cocoon::internal::wrap<CollectionView>([cocoon::internal::ns<::NSCollectionViewLayout>(this) collectionView]);
    }

    Size CollectionViewLayout::collection_view_content_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewLayout>(this) collectionViewContentSize]);
    }

    std::string CollectionViewLayout::invalidation_context_class()
    {
        return cocoon::internal::from(NSStringFromClass([::NSCollectionViewLayout invalidationContextClass]));
    }

    std::string CollectionViewLayout::layout_attributes_class()
    {
        return cocoon::internal::from(NSStringFromClass([::NSCollectionViewLayout layoutAttributesClass]));
    }
}
