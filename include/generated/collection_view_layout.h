#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CollectionView;
    class CollectionViewLayoutAttributes;
    class CollectionViewLayoutInvalidationContext;
    class CollectionViewUpdateItem;
    class IndexPath;
    class Nib;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionViewLayout` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionViewLayout collection_view_layout;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionViewLayout collection_view_layout{};
     * collection_view_layout.final_layout_attributes_for_disappearing_decoration_element_of_kind("text", cocoon::IndexPath());
     * collection_view_layout.final_layout_attributes_for_disappearing_item_at_index_path(cocoon::IndexPath());
     * collection_view_layout.final_layout_attributes_for_disappearing_supplementary_element_of_kind("text", cocoon::IndexPath());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionviewlayout
     */
    class CollectionViewLayout : public Object
    {
    public:
        /// @brief Creates a new `NSCollectionViewLayout` instance and returns a handle to it.
        explicit CollectionViewLayout(const std::string& element_kind, const IndexPath& decoration_index_path);
        /// @brief Creates a new `NSCollectionViewLayout` instance and returns a handle to it.
        explicit CollectionViewLayout(const IndexPath& item_index_path);
        /// @brief Creates a new `NSCollectionViewLayout` instance and returns a handle to it.
        explicit CollectionViewLayout();
        /// @brief Creates a null handle that refers to no native object.
        CollectionViewLayout(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionViewLayout(Adopt adopt);
        /**
     * @brief Calls `-[NSCollectionViewLayout finalLayoutAttributesForDisappearingDecorationElementOfKind:atIndexPath:]`.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @param decoration_index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CollectionViewLayoutAttributes final_layout_attributes_for_disappearing_decoration_element_of_kind(const std::string& element_kind, const IndexPath& decoration_index_path) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout finalLayoutAttributesForDisappearingItemAtIndexPath:]`.
     * @param item_index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CollectionViewLayoutAttributes final_layout_attributes_for_disappearing_item_at_index_path(const IndexPath& item_index_path) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout finalLayoutAttributesForDisappearingSupplementaryElementOfKind:atIndexPath:]`.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @param element_index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CollectionViewLayoutAttributes final_layout_attributes_for_disappearing_supplementary_element_of_kind(const std::string& element_kind, const IndexPath& element_index_path) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout finalizeAnimatedBoundsChange]`.
     */
        void finalize_animated_bounds_change() const;
        /**
     * @brief Calls `-[NSCollectionViewLayout finalizeCollectionViewUpdates]`.
     */
        void finalize_collection_view_updates() const;
        /**
     * @brief Calls `-[NSCollectionViewLayout finalizeLayoutTransition]`.
     */
        void finalize_layout_transition() const;
        /**
     * @brief Calls `-[NSCollectionViewLayout indexPathsToDeleteForDecorationViewOfKind:]`.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<IndexPath> index_paths_to_delete_for_decoration_view_of_kind(const std::string& element_kind) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout indexPathsToDeleteForSupplementaryViewOfKind:]`.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<IndexPath> index_paths_to_delete_for_supplementary_view_of_kind(const std::string& element_kind) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout indexPathsToInsertForDecorationViewOfKind:]`.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<IndexPath> index_paths_to_insert_for_decoration_view_of_kind(const std::string& element_kind) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout indexPathsToInsertForSupplementaryViewOfKind:]`.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<IndexPath> index_paths_to_insert_for_supplementary_view_of_kind(const std::string& element_kind) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout invalidateLayout]`.
     * @details Call -invalidateLayout to indicate that the collection view needs to requery the layout information. Subclasses must always call super if they override.
     */
        void invalidate_layout() const;
        /**
     * @brief Calls `-[NSCollectionViewLayout invalidateLayoutWithContext:]`.
     * @param context Argument converted to the Objective-C parameter of the same role.
     */
        void invalidate_layout_with_context(const CollectionViewLayoutInvalidationContext& context) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout invalidationContextForBoundsChange:]`.
     * @param new_bounds Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CollectionViewLayoutInvalidationContext invalidation_context_for_bounds_change(const Rect& new_bounds) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout invalidationContextForPreferredLayoutAttributes:withOriginalAttributes:]`.
     * @param preferred_attributes Argument converted to the Objective-C parameter of the same role.
     * @param original_attributes Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CollectionViewLayoutInvalidationContext invalidation_context_for_preferred_layout_attributes(const CollectionViewLayoutAttributes& preferred_attributes, const CollectionViewLayoutAttributes& original_attributes) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout layoutAttributesForDecorationViewOfKind:atIndexPath:]`.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CollectionViewLayoutAttributes layout_attributes_for_decoration_view_of_kind(const std::string& element_kind, const IndexPath& index_path) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout layoutAttributesForDropTargetAtPoint:]`.
     * @details Returns an NSCollectionViewLayoutAttributes instance that identifies an appropriate proposed drop target from the given hover point. If the point is between items, the returned layout attributes may describe an inter-item gap, which is distinguished by having a representedElementCategory of NSCollectionElementCategoryInterItemGap, and a representedElementKind of NSCollectionElementKindInterItemGapIndicator. Its "frame" provides a bounding box for the gap, that will be used to position and size a drop target indicator, and its "indexPath" identifies the proposed "insert before" position. The frame might not contain the given point, if the insertion indicator should lie elsewhere. (For example, when a vertical Flow layout hit-tests a gap between rows, it may suggest an insertion gap to the left of the lower row's first item.) Subclasses should override this method to return appropriate results based on their knowledge of the particular layout. This method should return nil if no suitable drop target can be inferred from the given point.
     * @param point_in_collection_view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CollectionViewLayoutAttributes layout_attributes_for_drop_target_at_point(const Point& point_in_collection_view) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout layoutAttributesForElementsInRect:]`.
     * @details NSCollectionView calls these four methods to determine the layout information. Implement -layoutAttributesForElementsInRect: to return layout attributes for for supplementary or decoration views, or to perform layout in an as-needed-on-screen fashion. Additionally, all layout subclasses should implement -layoutAttributesForItemAtIndexPath: to return layout attributes instances on demand for specific index paths. If the layout supports any supplementary or decoration view types, it should also implement the respective atIndexPath: methods for those types. During a batch update (-[NSCollectionView performBatchUpdates:completionHandler:], or a diffable data source's -applySnapshot:animatingDifferences:completion:), -layoutAttributesForItemAtIndexPath: must return non-nil attributes for every item that still exists after the update. Returning nil for such an item is a programming error and will raise an assertion. This normally means the layout's backing data (for example a section provider) or the data source's contents were changed out of step with the update; apply those changes as part of the update rather than before it.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<CollectionViewLayoutAttributes> layout_attributes_for_elements_in_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout layoutAttributesForInterItemGapBeforeIndexPath:]`.
     * @details Returns an NSCollectionViewLayoutAttributes instance that describes the inter-item gap preceding the given item indexPath. You may pass an indexPath whose "item" index equals the number of items in the section, to request a description of the gap after the last item. The result has a representedElementCategory of NSCollectionElementCategoryInterItemGap, and a representedElementKind of NSCollectionElementKindInterItemGapIndicator. Subclasses should override this method to return appropriate results based on their knowledge of the particular layout.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CollectionViewLayoutAttributes layout_attributes_for_inter_item_gap_before_index_path(const IndexPath& index_path) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout layoutAttributesForItemAtIndexPath:]`.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CollectionViewLayoutAttributes layout_attributes_for_item_at_index_path(const IndexPath& index_path) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout layoutAttributesForSupplementaryViewOfKind:atIndexPath:]`.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CollectionViewLayoutAttributes layout_attributes_for_supplementary_view_of_kind(const std::string& element_kind, const IndexPath& index_path) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout prepareForAnimatedBoundsChange:]`.
     * @param old_bounds Argument converted to the Objective-C parameter of the same role.
     */
        void prepare_for_animated_bounds_change(const Rect& old_bounds) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout prepareForCollectionViewUpdates:]`.
     * @param update_items Argument converted to the Objective-C parameter of the same role.
     */
        void prepare_for_collection_view_updates(const std::vector<CollectionViewUpdateItem>& update_items) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout prepareForTransitionFromLayout:]`.
     * @param old_layout Argument converted to the Objective-C parameter of the same role.
     */
        void prepare_for_transition_from_layout(const CollectionViewLayout& old_layout) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout prepareForTransitionToLayout:]`.
     * @param new_layout Argument converted to the Objective-C parameter of the same role.
     */
        void prepare_for_transition_to_layout(const CollectionViewLayout& new_layout) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout prepareLayout]`.
     * @details The collection view calls -prepareLayout once at its first layout as the first message to the layout instance. The collection view calls -prepareLayout again after layout is invalidated and before requerying the layout information. Subclasses should always call super if they override.
     */
        void prepare_layout() const;
        /**
     * @brief Calls `-[NSCollectionViewLayout registerClass:forDecorationViewOfKind:]`.
     * @param view_class Argument converted to the Objective-C parameter of the same role.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     */
        void register_class(const std::string& view_class, const std::string& element_kind) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout registerNib:forDecorationViewOfKind:]`.
     * @param nib Argument converted to the Objective-C parameter of the same role.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     */
        void register_nib(const Nib& nib, const std::string& element_kind) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout shouldInvalidateLayoutForBoundsChange:]`.
     * @param new_bounds Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool should_invalidate_layout_for_bounds_change(const Rect& new_bounds) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout shouldInvalidateLayoutForPreferredLayoutAttributes:withOriginalAttributes:]`.
     * @param preferred_attributes Argument converted to the Objective-C parameter of the same role.
     * @param original_attributes Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool should_invalidate_layout_for_preferred_layout_attributes(const CollectionViewLayoutAttributes& preferred_attributes, const CollectionViewLayoutAttributes& original_attributes) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout targetContentOffsetForProposedContentOffset:]`.
     * @param proposed_content_offset Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point target_content_offset_for_proposed_content_offset(const Point& proposed_content_offset) const;
        /**
     * @brief Calls `-[NSCollectionViewLayout targetContentOffsetForProposedContentOffset:withScrollingVelocity:]`.
     * @param proposed_content_offset Argument converted to the Objective-C parameter of the same role.
     * @param velocity Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point target_content_offset_for_proposed_content_offset(const Point& proposed_content_offset, const Point& velocity) const;
        /**
     * @brief Returns the `collectionView` property of `NSCollectionViewLayout`.
     * @details Methods in this class are meant to be overridden and will be called by its collection view to gather layout information. To get the truth on the current state of the collection view, call methods on NSCollectionView rather than these.
     * @return The converted Objective-C result.
     */
        CollectionView collection_view() const;
        /**
     * @brief Returns the `collectionViewContentSize` property of `NSCollectionViewLayout`.
     * @return The converted Objective-C result.
     */
        Size collection_view_content_size() const;
        /**
     * @brief Returns the `invalidationContextClass` property of `NSCollectionViewLayout`.
     * @return The converted Objective-C result.
     */
        static std::string invalidation_context_class();
        /**
     * @brief Returns the `layoutAttributesClass` property of `NSCollectionViewLayout`.
     * @return The converted Objective-C result.
     */
        static std::string layout_attributes_class();
    };
}
