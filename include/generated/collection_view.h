#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class CollectionViewItem;
    class CollectionViewLayout;
    class CollectionViewLayoutAttributes;
    class CollectionViewTransitionLayout;
    class Color;
    class DraggingSession;
    class Event;
    class Image;
    class IndexPath;
    class IndexSet;
    class Nib;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionView` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionView collection_view;
     * collection_view.set_allows_empty_selection(true);
     * collection_view.dragging_session_will_begin_at_point_for_items_at_index_paths().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionView collection_view{};
     * collection_view.set_allows_empty_selection(true);
     * auto allows_empty_selection = collection_view.allows_empty_selection();
     * collection_view.set_allows_multiple_selection(true);
     * auto allows_multiple_selection = collection_view.allows_multiple_selection();
     * collection_view.set_background_view(cocoon::View());
     * auto background_view = collection_view.background_view();
     * collection_view.delete_sections(cocoon::IndexSet());
     * collection_view.frame_for_item_at_index(1);
     * collection_view.frame_for_item_at_index(1, 1);
     * collection_view.dragging_session_will_begin_at_point_for_items_at_index_paths().connect([](cocoon::DraggingSession a0, cocoon::Point a1, std::vector<cocoon::IndexPath> a2) {});
     * collection_view.dragging_session_will_begin_at_point_for_items_at_indexes().connect([](cocoon::DraggingSession a0, cocoon::Point a1, cocoon::IndexSet a2) {});
     * collection_view.dragging_session_ended_at_point_drag_operation().connect([](cocoon::DraggingSession a0, cocoon::Point a1, cocoon::DragOperation a2) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionview
     */
    class CollectionView : public View
    {
    public:
        /// @brief Creates a new `NSCollectionView` instance and returns a handle to it.
        explicit CollectionView();
        /// @brief Creates a null handle that refers to no native object.
        CollectionView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionView(Adopt adopt);
        /**
     * @brief Calls `-[NSCollectionView deleteItemsAtIndexPaths:]`.
     * @details Use this method to remove items from the collection view. You might do this when you remove the represented objects from your data source object or in response to user interactions with the collection view. The collection view updates the layout of the remaining items to account for the deletions, animating the remaining items into position as needed. You can also call this method from a block passed to the performBatchUpdates:completionHandler: method when you want to animate multiple separate changes into place at the same time. See the description of that method for more information. Raises an exception if "indexPaths" is nil.
     * @param index_paths Argument converted to the Objective-C parameter of the same role.
     */
        void delete_items_at_index_paths(const std::vector<IndexPath>& index_paths) const;
        /**
     * @brief Calls `-[NSCollectionView deleteSections:]`.
     * @details Use this method to remove the sections and their items from the collection view. You might do this when you remove the sections from your data source object or in response to user interactions with the collection view. The collection view updates the layout of the remaining sections and items to account for the deletions, animating the remaining items into position as needed. You can also call this method from a block passed to the performBatchUpdates:completionHandler: method when you want to animate multiple separate changes into place at the same time. See the description of that method for more information. Raises an exception if "sections" is nil.
     * @param sections Argument converted to the Objective-C parameter of the same role.
     */
        void delete_sections(const IndexSet& sections) const;
        /**
     * @brief Calls `-[NSCollectionView deselectAll:]`.
     * @details Clears the CollectionView's selection (if any), if and only if it is "selectable", and notifies the CollectionView's delegate about any newly deselected items. If "selectable" is NO, this action silently does nothing (and its associated user interface item does not validate).
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void deselect_all(const Object& sender) const;
        /**
     * @brief Calls `-[NSCollectionView deselectItemsAtIndexPaths:]`.
     * @details Removes the specified items from the selection, potentially in an animated way. This method does not cause any selection-related delegate methods to be invoked. To animate the view property changes that indicate deselected state, use [[collectionView animator] deselectItemsAtIndexPaths:].
     * @param index_paths Argument converted to the Objective-C parameter of the same role.
     */
        void deselect_items_at_index_paths(const std::vector<IndexPath>& index_paths) const;
        /**
     * @brief Calls `-[NSCollectionView draggingImageForItemsAtIndexPaths:withEvent:offset:]`.
     * @details This method computes and returns an image to use for dragging. You can override this to return a custom drag image, or call it from the delegate method to get the default drag image. 'indexPaths' contains the NSIndexPaths of the items being dragged. 'event' is a reference to the mouse down event that began the drag. 'dragImageOffset' is an in/out parameter. This method will be called with dragImageOffset set to NSZeroPoint, but it can be modified to re-position the returned image. A dragImageOffset of NSZeroPoint will cause the image to be centered under the mouse. By default, an image will be created that contains a rendering of the visible portions of the views for each item. If the delegate implements the equivalent delegate method, it will be preferred over this method.
     * @param index_paths Argument converted to the Objective-C parameter of the same role.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param drag_image_offset Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Image dragging_image_for_items_at_index_paths(const std::vector<IndexPath>& index_paths, const Event& event, Point* drag_image_offset) const;
        /**
     * @brief Calls `-[NSCollectionView draggingImageForItemsAtIndexes:withEvent:offset:]`.
     * @details This is an older variant of -draggingImageForItemsAtIndexPaths:withEvent:offset:. It assumes all of the indexes are in section 0. New code should use -draggingImageForItemsAtIndexPaths:withEvent:offset: instead.
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param drag_image_offset Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Image dragging_image_for_items_at_indexes(const IndexSet& indexes, const Event& event, Point* drag_image_offset) const;
        /**
     * @brief Calls `-[NSCollectionView frameForItemAtIndex:]`.
     * @details Returns the frame calculated by the receiver where it intends to place the subview for the NSCollectionViewItem at the given index. You can use this method in the draggingImage methods to determine which views are in the visible portion of the enclosing scroll view. Overriding this method will have no effect on the receiver's subview layout. For apps that target OS X 10.11 and later, you may want to use -layoutAttributesForItemAtIndexPath: instead, which provides more than just the item's frame. This method raises an exception if invoked for a CollectionView that has more than one section. Use -layoutAttributesForItemAtIndexPath: instead.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect frame_for_item_at_index(std::uint64_t index) const;
        /**
     * @brief Calls `-[NSCollectionView frameForItemAtIndex:withNumberOfItems:]`.
     * @details Returns the frame calculated by the receiver where it would place a subview for an NSCollectionViewItem at the given index in a collection with the given number of items. You should use this method when updating NSDraggingItem frames when your collection is a drag destination. You should not use -frameForItemAtIndex:, since a drag and drop operation may change the number of items in the collection, which affects the layout of the item views. This method raises an exception if invoked for a CollectionView that has more than one section. Use -layoutAttributesForItemAtIndexPath: instead.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @param number_of_items Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect frame_for_item_at_index(std::uint64_t index, std::uint64_t number_of_items) const;
        /**
     * @brief Calls `-[NSCollectionView indexPathForItem:]`.
     * @details Returns the index path of the specified item (or nil if the specified item is not in the collection view).
     * @param item Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        IndexPath index_path_for_item(const CollectionViewItem& item) const;
        /**
     * @brief Calls `-[NSCollectionView indexPathForItemAtPoint:]`.
     * @details Returns the index path of the item at the specified point in the collection view. This method relies on the layout information provided by the associated layout object to determine which item contains the point. It does not take opacity of the item's displayed content at that point into account.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        IndexPath index_path_for_item_at_point(const Point& point) const;
        /**
     * @brief Calls `-[NSCollectionView indexPathsForVisibleItems]`.
     * @details Returns the index paths of the items that are currently displayed by the CollectionView. Note that these indexPaths correspond to the same items as "visibleItems", and thus may include items whose views fall outside the CollectionView's current "visibleRect".
     * @return The converted Objective-C result.
     */
        std::vector<IndexPath> index_paths_for_visible_items() const;
        /**
     * @brief Calls `-[NSCollectionView indexPathsForVisibleSupplementaryElementsOfKind:]`.
     * @details Returns the index paths of the supplementary views of the given elementKind that are currently displayed by the CollectionView. Note that these indexPaths correspond to the same supplementary views that "visibleSupplementaryViewsOfKind:" reports, and thus may include supplementary views that fall outside the CollectionView's current "visibleRect".
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<IndexPath> index_paths_for_visible_supplementary_elements_of_kind(const std::string& element_kind) const;
        /**
     * @brief Calls `-[NSCollectionView insertItemsAtIndexPaths:]`.
     * @details Call this method to insert one or more new items into the collection view. You might do this when your data source object receives data for new items or in response to user interactions with the collection view. The collection view gets the layout information for the new items as part of calling this method. And if the layout information indicates that the items should appear onscreen, the collection view asks your data source to provide the appropriate views, animating them into position as needed. You can also call this method from a block passed to the performBatchUpdates:completionHandler: method when you want to animate multiple separate changes into place at the same time. See the description of that method for more information. Raises an exception if "indexPaths" is nil.
     * @param index_paths Argument converted to the Objective-C parameter of the same role.
     */
        void insert_items_at_index_paths(const std::vector<IndexPath>& index_paths) const;
        /**
     * @brief Calls `-[NSCollectionView insertSections:]`.
     * @details Use this method to insert one or more sections into the collection view. This method adds the sections, and it is up to your data source to report the number of items in each section when asked for the information. The collection view then uses that information to get updated layout attributes for the newly inserted sections and items. If the insertions cause a change in the collection view’s visible content, those changes are animated into place. You can also call this method from a block passed to the performBatchUpdates:completionHandler: method when you want to animate multiple separate changes into place at the same time. See the description of that method for more information. Raises an exception if "sections" is nil.
     * @param sections Argument converted to the Objective-C parameter of the same role.
     */
        void insert_sections(const IndexSet& sections) const;
        /**
     * @brief Calls `-[NSCollectionView itemAtIndex:]`.
     * @details (Soft-Deprecated) Returns the NSCollectionViewItem associated with the represented object at the given index. Sending this to a CollectionView that has more than one section raises an exception. Use -itemAtIndexPath: instead.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CollectionViewItem item_at_index(std::uint64_t index) const;
        /**
     * @brief Calls `-[NSCollectionView itemAtIndexPath:]`.
     * @details Returns the NSCollectionViewItem (if any) associated with the represented object at the given indexPath. This method returns nil if the CollectionView isn't currently maintaining an NSCollectionViewItem instance for the given indexPath, as may be the case if the specified item is outside the CollectionView's visibleRect.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CollectionViewItem item_at_index_path(const IndexPath& index_path) const;
        /**
     * @brief Calls `-[NSCollectionView layoutAttributesForItemAtIndexPath:]`.
     * @details Returns the layout information for the item at the specified index path (or nil if no such item exists). Use this method to retrieve the layout information for a particular item. You should always use this method instead of querying the layout object directly.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CollectionViewLayoutAttributes layout_attributes_for_item_at_index_path(const IndexPath& index_path) const;
        /**
     * @brief Calls `-[NSCollectionView layoutAttributesForSupplementaryElementOfKind:atIndexPath:]`.
     * @details Returns the layout information for the specified supplementary view. Use this method to retrieve the layout information for a particular supplementary view. You should always use this method instead of querying the layout object directly.
     * @param kind Argument converted to the Objective-C parameter of the same role.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CollectionViewLayoutAttributes layout_attributes_for_supplementary_element_of_kind(const std::string& kind, const IndexPath& index_path) const;
        /**
     * @brief Calls `-[NSCollectionView makeItemWithIdentifier:forIndexPath:]`.
     * @details Call this method from your data source object when asked to provide a new item for the collection view. This method dequeues an existing item if one is available or creates a new one based on the nib file or class you previously registered. If you have not registered a nib file or class for the given identifier, CollectionView will try to load a nib file named identifier.nib, or (failing that) find and instantiate an NSCollectionViewItem subclass named "identifier". If a new item must be created from a class, this method initializes the item by invoking its -init method. For nib-based items, this method loads the item from the provided nib file. If an existing item was available for reuse, this method invokes the item's -prepareForReuse method instead.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CollectionViewItem make_item_with_identifier(const std::string& identifier, const IndexPath& index_path) const;
        /**
     * @brief Calls `-[NSCollectionView makeSupplementaryViewOfKind:withIdentifier:forIndexPath:]`.
     * @details Call this method from your data source object when asked to provide a new supplementary view for the collection view. This method dequeues an existing view if one is available or creates a new one based on the nib file or class you previously registered. If you have not registered a nib file or class for the given identifier, CollectionView will try to load a nib file named identifier.nib, or (failing that) find and instantiate an NSView subclass named "identifier". If a new view must be created from a class, this method initializes the view by invoking its -initWithFrame: method. For nib-based views, this method loads the view from the provided nib file. If an existing view was available for reuse, this method invokes the view's -prepareForReuse method instead.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        View make_supplementary_view_of_kind(const std::string& element_kind, const std::string& identifier, const IndexPath& index_path) const;
        /**
     * @brief Calls `-[NSCollectionView moveItemAtIndexPath:toIndexPath:]`.
     * @details Use this method to reorganize existing data items. You might do this when you rearrange the represented objects within your data source object or in response to user interactions with the collection view. You can move items between sections or within the same section. The collection view updates the layout as needed to account for the move, animating items into position as needed. You can also call this method from a block passed to the performBatchUpdates:completionHandler: method when you want to animate multiple separate changes into place at the same time. See the description of that method for more information. Raises an exception if "indexPath" or "newIndexPath" is nil.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @param new_index_path Argument converted to the Objective-C parameter of the same role.
     */
        void move_item_at_index_path(const IndexPath& index_path, const IndexPath& new_index_path) const;
        /**
     * @brief Calls `-[NSCollectionView moveSection:toSection:]`.
     * @details Use this method to reorganize existing sections and their contained items. You might do this when you rearrange sections within your data source object or in response to user interactions with the collection view. The collection view updates the layout as needed to account for the move, animating new views into position as needed. You can also call this method from a block passed to the performBatchUpdates:completionHandler: method when you want to animate multiple separate changes into place at the same time. See the description of that method for more information.
     * @param section Argument converted to the Objective-C parameter of the same role.
     * @param new_section Argument converted to the Objective-C parameter of the same role.
     */
        void move_section(std::int64_t section, std::int64_t new_section) const;
        /**
     * @brief Calls `-[NSCollectionView numberOfItemsInSection:]`.
     * @details Returns the number of items in the specified "section".
     * @param section Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_items_in_section(std::int64_t section) const;
        /**
     * @brief Calls `-[NSCollectionView performBatchUpdates:completionHandler:]`.
     * @details Animates multiple insert, delete, reload, and move operations as a group. You can use this method in cases where you want to make multiple changes to the collection view in one single animated operation, as opposed to in several separate animations. You might use this method to insert, delete, reload or move items or use it to change the layout parameters associated with one or more items. Use the block passed in the "updates" parameter to specify all of the operations you want to perform. Deletes are processed before inserts in batch operations. This means the indexes for the insertions are processed relative to the indexes of the state before the batch operation, and the indexes for the deletions are processed relative to the indexes of the state after all the insertions in the batch operation. Invocations of this method can be nested.
     * @param updates Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void perform_batch_updates(std::function<void()> updates, std::function<void(bool)> completion_handler) const;
        /**
     * @brief Calls `-[NSCollectionView registerClass:forItemWithIdentifier:]`.
     * @details For each item identifier that the collection view will use, register either a nib or class from which to instantiate an item, or provide a nib file or class whose name matches the identifier you plan to use. If a nib is registered, it must contain exactly one top-level NSCollectionViewItem. If a class is registered instead of a nib, it will be instantiated via alloc/init.
     * @param item_class Argument converted to the Objective-C parameter of the same role.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     */
        void register_class(const std::string& item_class, const std::string& identifier) const;
        /**
     * @brief Calls `-[NSCollectionView registerClass:forSupplementaryViewOfKind:withIdentifier:]`.
     * @details For each supplementary view identifier that the collection view will use, register either a nib or class from which to instantiate a view, or provide a nib file or class whose name matches the identifier you plan to use. If a nib is registered, it must contain exactly one top-level view, that conforms to the NSCollectionViewElement protocol. If a class is registered instead of a nib, it will be instantiated via alloc/initWithFrame:.
     * @param view_class Argument converted to the Objective-C parameter of the same role.
     * @param kind Argument converted to the Objective-C parameter of the same role.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     */
        void register_class(const std::string& view_class, const std::string& kind, const std::string& identifier) const;
        /**
     * @brief Calls `-[NSCollectionView registerNib:forItemWithIdentifier:]`.
     * @param nib Argument converted to the Objective-C parameter of the same role.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     */
        void register_nib(const Nib& nib, const std::string& identifier) const;
        /**
     * @brief Calls `-[NSCollectionView registerNib:forSupplementaryViewOfKind:withIdentifier:]`.
     * @param nib Argument converted to the Objective-C parameter of the same role.
     * @param kind Argument converted to the Objective-C parameter of the same role.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     */
        void register_nib(const Nib& nib, const std::string& kind, const std::string& identifier) const;
        /**
     * @brief Calls `-[NSCollectionView reloadData]`.
     * @details Call this method to reload all of the items in the collection view. This causes the collection view to discard any currently visible items and redisplay them. For efficiency, the collection view only displays those items and supplementary views that are visible. If the collection data shrinks as a result of the reload, the collection view adjusts its scroll position accordingly. You should not call this method in the middle of animation blocks where items are being inserted or deleted. Insertions and deletions automatically cause the table’s data to be updated appropriately.
     */
        void reload_data() const;
        /**
     * @brief Calls `-[NSCollectionView reloadItemsAtIndexPaths:]`.
     * @details Call this method to selectively reload only the specified objects. This causes the collection view to discard any items associated with those objects and redisplay them. Raises an exception if "indexPaths" is nil.
     * @param index_paths Argument converted to the Objective-C parameter of the same role.
     */
        void reload_items_at_index_paths(const std::vector<IndexPath>& index_paths) const;
        /**
     * @brief Calls `-[NSCollectionView reloadSections:]`.
     * @details Call this method to selectively reload only the objects in the specified sections. This causes the collection view to discard any items associated with those objects and redisplay them. Raises an exception if "sections" is nil.
     * @param sections Argument converted to the Objective-C parameter of the same role.
     */
        void reload_sections(const IndexSet& sections) const;
        /**
     * @brief Calls `-[NSCollectionView scrollToItemsAtIndexPaths:scrollPosition:]`.
     * @details Scrolls the collection view contents until the bounding box of the specified items is visible. The final position of that bounding box within the scrollable area is determined by "scrollPosition". To request an animated scroll, use [[collectionView animator] scrollToItemsAtIndexPaths:scrollPosition:]. You can use NSAnimationContext's completionHandler provisions to notify you when the animated scroll has finished.
     * @param index_paths Argument converted to the Objective-C parameter of the same role.
     * @param scroll_position Argument converted to the Objective-C parameter of the same role.
     */
        void scroll_to_items_at_index_paths(const std::vector<IndexPath>& index_paths, CollectionViewScrollPosition scroll_position) const;
        /**
     * @brief Calls `-[NSCollectionView selectAll:]`.
     * @details Selects all of the CollectionView's items, if and only if it is "selectable" and it "allowsMultipleSelection", and notifies the CollectionView's delegate about any newly selected items. If either "selectable" or "allowsMultipleSelection" is NO, this action silently does nothing (and its associated user interface item does not validate).
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void select_all(const Object& sender) const;
        /**
     * @brief Calls `-[NSCollectionView selectItemsAtIndexPaths:scrollPosition:]`.
     * @details Adds the specified items to the selection, and optionally scrolls their bounding box into view according to the value of "scrollPosition". This method does not cause any selection-related delegate methods to be invoked. To animate the scroll (if any) and the view property changes that indicate selected state, use [[collectionView animator] selectItemsAtIndexPaths:scrollPosition:].
     * @param index_paths Argument converted to the Objective-C parameter of the same role.
     * @param scroll_position Argument converted to the Objective-C parameter of the same role.
     */
        void select_items_at_index_paths(const std::vector<IndexPath>& index_paths, CollectionViewScrollPosition scroll_position) const;
        /**
     * @brief Calls `-[NSCollectionView setDraggingSourceOperationMask:forLocal:]`.
     * @details Configures the value returned from -draggingSourceOperationMaskForLocal:. An isLocal value of YES indicates that 'dragOperationMask' applies when the destination object is in the same application. By default, NSDragOperationEvery will be returned. An isLocal value of NO indicates that 'dragOperationMask' applies when the destination object is in an application outside the receiver's application. By default, NSDragOperationNone is returned. NSCollectionView will save the values you set for each isLocal setting. You typically will invoke this method, and not override it.
     * @param drag_operation_mask Argument converted to the Objective-C parameter of the same role.
     * @param local_destination Argument converted to the Objective-C parameter of the same role.
     */
        void set_dragging_source_operation_mask(DragOperation drag_operation_mask, bool local_destination) const;
        /**
     * @brief Calls `-[NSCollectionView supplementaryViewForElementKind:atIndexPath:]`.
     * @details Returns the supplementary view (if any) of the given elementKind that's associated with the given indexPath. Returns nil if no such supplementary view is currently instantiated.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        View supplementary_view_for_element_kind(const std::string& element_kind, const IndexPath& index_path) const;
        /**
     * @brief Calls `-[NSCollectionView toggleSectionCollapse:]`.
     * @details Toggles collapse of the CollectionView section that the sender resides in. Typically you'll wire this action from a section header view's "sectionCollapse" button. (See the NSCollectionViewSectionHeaderView protocol.)
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void toggle_section_collapse(const Object& sender) const;
        /**
     * @brief Calls `-[NSCollectionView visibleItems]`.
     * @details Returns the NSCollectionViewItems that the CollectionView has instantiated and is managing as currently active. Each such item is associated with an item indexPath, and its view is part of the currently displayed view hierarchy. Note that this list may include items whose views fall outside the CollectionView's current visibleRect (for example, recently visible items that have been scrolled out of view, or items that the CollectionView anticipates may soon be visible). To determine which of these items may actually be visible to the user, test each item.view.frame for intersection with the CollectionView's visibleRect.
     * @return The converted Objective-C result.
     */
        std::vector<CollectionViewItem> visible_items() const;
        /**
     * @brief Calls `-[NSCollectionView visibleSupplementaryViewsOfKind:]`.
     * @details Returns the supplementary views that the CollectionView has instantiated and is managing as currently active. Each such supplementary view is associated with an indexPath, and is part of the currently displayed view hierarchy. Note that this list may include supplementary views that fall outside the CollectionView's current visibleRect (for example, recently visible section header or footer views that have been scrolled out of view, or section header or footer views that the CollectionView anticipates may soon be visible). To determine which of these views may actually be visible to the user, test each view.frame for intersection with the CollectionView's visibleRect.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<View> visible_supplementary_views_of_kind(const std::string& element_kind) const;
        /**
     * @brief Returns the `allowsEmptySelection` property of `NSCollectionView`.
     * @details Whether the CollectionView allows its selection to become empty. Defaults to YES. When this is set to NO and "selectable" is YES, the CollectionView will attempt to always leave at least one item selected, when the CollectionView has at least one item.
     * @return The converted Objective-C result.
     */
        bool allows_empty_selection() const;
        /**
     * @brief Sets the `allowsEmptySelection` property of `NSCollectionView`.
     * @details Whether the CollectionView allows its selection to become empty. Defaults to YES. When this is set to NO and "selectable" is YES, the CollectionView will attempt to always leave at least one item selected, when the CollectionView has at least one item.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_empty_selection(bool value) const;
        /**
     * @brief Returns the `allowsMultipleSelection` property of `NSCollectionView`.
     * @details Whether the user can simultaneously select multiple items in the CollectionView. Defaults to NO, which means only one item at a time (or none) may be selected. Changing this from YES to NO causes the CollectionView's selection to be reduced to the selected item with the lowest index in the section with the lowest index, if more than one item was selected.
     * @return The converted Objective-C result.
     */
        bool allows_multiple_selection() const;
        /**
     * @brief Sets the `allowsMultipleSelection` property of `NSCollectionView`.
     * @details Whether the user can simultaneously select multiple items in the CollectionView. Defaults to NO, which means only one item at a time (or none) may be selected. Changing this from YES to NO causes the CollectionView's selection to be reduced to the selected item with the lowest index in the section with the lowest index, if more than one item was selected.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_multiple_selection(bool value) const;
        /**
     * @brief Returns the `backgroundColors` property of `NSCollectionView`.
     * @details The first background color in the array is used as the background of the entire collection view. Passing nil resets the background colors back to the default.
     * @return The converted Objective-C result.
     */
        std::vector<Color> background_colors() const;
        /**
     * @brief Sets the `backgroundColors` property of `NSCollectionView`.
     * @details The first background color in the array is used as the background of the entire collection view. Passing nil resets the background colors back to the default.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_colors(const std::vector<Color>& value) const;
        /**
     * @brief Returns the `backgroundView` property of `NSCollectionView`.
     * @details An optional background view that's positioned underneath all of the CollectionView's content. Defaults to nil. The backgroundView's scrolling behavior and frame are determined by the "backgroundViewScrollsWithContent" property, as described below. If "backgroundColors" are also specified for the CollectionView, backgroundColor[0] is drawn anywhere the backgroundView's content allows it to show through.
     * @return The converted Objective-C result.
     */
        View background_view() const;
        /**
     * @brief Sets the `backgroundView` property of `NSCollectionView`.
     * @details An optional background view that's positioned underneath all of the CollectionView's content. Defaults to nil. The backgroundView's scrolling behavior and frame are determined by the "backgroundViewScrollsWithContent" property, as described below. If "backgroundColors" are also specified for the CollectionView, backgroundColor[0] is drawn anywhere the backgroundView's content allows it to show through.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_view(const View& value) const;
        /**
     * @brief Returns the `backgroundViewScrollsWithContent` property of `NSCollectionView`.
     * @details When YES, the CollectionView's backgroundView (if any) will match the CollectionView's frame and scroll with the CollectionView's items and other content. When NO (the default, compatible with the behavior on OS X 10.11), the backgroundView is made to fill the CollectionView's visible area, and remains stationary when the CollectionView's content is scrolled. Archived with the CollectionView's other persistent properties.
     * @return The converted Objective-C result.
     */
        bool background_view_scrolls_with_content() const;
        /**
     * @brief Sets the `backgroundViewScrollsWithContent` property of `NSCollectionView`.
     * @details When YES, the CollectionView's backgroundView (if any) will match the CollectionView's frame and scroll with the CollectionView's items and other content. When NO (the default, compatible with the behavior on OS X 10.11), the backgroundView is made to fill the CollectionView's visible area, and remains stationary when the CollectionView's content is scrolled. Archived with the CollectionView's other persistent properties.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_view_scrolls_with_content(bool value) const;
        /**
     * @brief Returns the `collectionViewLayout` property of `NSCollectionView`.
     * @details The layout object that determines how the NSCollectionView's items will be sized and positioned. Defaults to an instance of NSCollectionViewGridLayout whose maxNumberOfRows, maxNumberOfColumns, minItemSize, maxItemSize, and backgroundColors properties mirror the NSCollectionView's. Replace this object, or change the values of its parameters, to change the layout. collectionViewLayout may be set to nil for an NSCollectionView that is not using the dataSource-based API. To get an animated transition to the new layout, use [[collectionView animator] setCollectionViewLayout:]. You can use NSAnimationContext's completionHandler provisions to notify you when the transition is complete.
     * @return The converted Objective-C result.
     */
        CollectionViewLayout collection_view_layout() const;
        /**
     * @brief Sets the `collectionViewLayout` property of `NSCollectionView`.
     * @details The layout object that determines how the NSCollectionView's items will be sized and positioned. Defaults to an instance of NSCollectionViewGridLayout whose maxNumberOfRows, maxNumberOfColumns, minItemSize, maxItemSize, and backgroundColors properties mirror the NSCollectionView's. Replace this object, or change the values of its parameters, to change the layout. collectionViewLayout may be set to nil for an NSCollectionView that is not using the dataSource-based API. To get an animated transition to the new layout, use [[collectionView animator] setCollectionViewLayout:]. You can use NSAnimationContext's completionHandler provisions to notify you when the transition is complete.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_collection_view_layout(const CollectionViewLayout& value) const;
        /**
     * @brief Returns the `content` property of `NSCollectionView`.
     * @details The array of model objects that will be shown as "items" in this CollectionView. The objects may be of any type(s). If you prefer not to give the CollectionView a "dataSource", you can set its "content" property explicitly, or bind the CollectionView's NSContentBinding to an NSArrayController's arrangedObjects property, to provide the CollectionView with its model objects. A CollectionView whose content is provided in this way cannot have more than one section. Each corresponding "item" instantiated by the CollectionView will have its representedObject property wired to the corresponding model object from this "content" array. Attempts to set "content" to nil are ignored on OS X 10.10 and earlier. On OS X 10.11 and later, setting "content" to nil raises an exception. (Set "content" to an empty NSArray instead, if you want to empty the CollectionView.)
     * @return The converted Objective-C result.
     */
        std::vector<Object> content() const;
        /**
     * @brief Sets the `content` property of `NSCollectionView`.
     * @details The array of model objects that will be shown as "items" in this CollectionView. The objects may be of any type(s). If you prefer not to give the CollectionView a "dataSource", you can set its "content" property explicitly, or bind the CollectionView's NSContentBinding to an NSArrayController's arrangedObjects property, to provide the CollectionView with its model objects. A CollectionView whose content is provided in this way cannot have more than one section. Each corresponding "item" instantiated by the CollectionView will have its representedObject property wired to the corresponding model object from this "content" array. Attempts to set "content" to nil are ignored on OS X 10.10 and earlier. On OS X 10.11 and later, setting "content" to nil raises an exception. (Set "content" to an empty NSArray instead, if you want to empty the CollectionView.)
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content(const std::vector<Object>& value) const;
        /**
     * @brief Returns the `firstResponder` property of `NSCollectionView`.
     * @details Whether the CollectionView is its window's current firstResponder. This bindable property is useful for determining appropriate appearance for selected items.
     * @return The converted Objective-C result.
     */
        bool is_first_responder() const;
        /**
     * @brief Returns the `numberOfSections` property of `NSCollectionView`.
     * @details The number of sections displayed by the collection view.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_sections() const;
        /**
     * @brief Returns the `prefetchDataSource` property of `NSCollectionView`.
     * @details An optional assistant to the CollectionView's 'dataSource' (potentially the same object), that receives notifications conducive to managing item data pre-fetching.
     * @return The converted Objective-C result.
     */
        Object prefetch_data_source() const;
        /**
     * @brief Sets the `prefetchDataSource` property of `NSCollectionView`.
     * @details An optional assistant to the CollectionView's 'dataSource' (potentially the same object), that receives notifications conducive to managing item data pre-fetching.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_prefetch_data_source(const Object& value) const;
        /**
     * @brief Returns the `selectable` property of `NSCollectionView`.
     * @details Whether the user can select items in the CollectionView. Defaults to NO. Changing this from YES to NO clears the CollectionView's current selection (if any), causing selectionIndexes to become an empty index set.
     * @return The converted Objective-C result.
     */
        bool is_selectable() const;
        /**
     * @brief Sets the `selectable` property of `NSCollectionView`.
     * @details Whether the user can select items in the CollectionView. Defaults to NO. Changing this from YES to NO clears the CollectionView's current selection (if any), causing selectionIndexes to become an empty index set.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selectable(bool value) const;
        /**
     * @brief Returns the `selectionIndexPaths` property of `NSCollectionView`.
     * @details A set of of NSIndexPath values, that identify the currently selected items by (section,indexInSection). When using the new NSCollectionView APIs on 10.11 and later, use this property instead of "selectionIndexes". You can change the set of selected items by setting this property. To request an animated transition of affected items between their selected and deselected appearances, you can set this property via the CollectionView's "animator" proxy: [[collectionView animator] setSelectionIndexPaths:newIndexPaths]. CollectionView will raise an exception if any of the given indexPaths is out-of-bounds. This property is Key-Value Observable.
     * @return The converted Objective-C result.
     */
        std::vector<IndexPath> selection_index_paths() const;
        /**
     * @brief Sets the `selectionIndexPaths` property of `NSCollectionView`.
     * @details A set of of NSIndexPath values, that identify the currently selected items by (section,indexInSection). When using the new NSCollectionView APIs on 10.11 and later, use this property instead of "selectionIndexes". You can change the set of selected items by setting this property. To request an animated transition of affected items between their selected and deselected appearances, you can set this property via the CollectionView's "animator" proxy: [[collectionView animator] setSelectionIndexPaths:newIndexPaths]. CollectionView will raise an exception if any of the given indexPaths is out-of-bounds. This property is Key-Value Observable.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selection_index_paths(const std::vector<IndexPath>& value) const;
        /**
     * @brief Returns the `selectionIndexes` property of `NSCollectionView`.
     * @details (Soft-Deprecated) The indexes of the items that are currently "selected", indicating that user operations should target the "content" objects having these indexes. Getting or setting this property raises an exception on 10.11 and later, if the CollectionView has more than one section. Use "selectionIndexPaths" instead.
     * @return The converted Objective-C result.
     */
        IndexSet selection_indexes() const;
        /**
     * @brief Sets the `selectionIndexes` property of `NSCollectionView`.
     * @details (Soft-Deprecated) The indexes of the items that are currently "selected", indicating that user operations should target the "content" objects having these indexes. Getting or setting this property raises an exception on 10.11 and later, if the CollectionView has more than one section. Use "selectionIndexPaths" instead.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selection_indexes(const IndexSet& value) const;
        /// @brief Signal for the delegate/data-source method behind `collection_view_number_of_items_in_section`; connect a callback with `collection_view_number_of_items_in_section().connect(...)`.
        Signal<CollectionView, std::int64_t(std::int64_t)> collection_view_number_of_items_in_section() const
        {
            return Signal<CollectionView, std::int64_t(std::int64_t)>(handle(), "collection_view_number_of_items_in_section");
        }
        /// @brief Signal for the delegate/data-source method behind `item_for_represented_object_at_index_path`; connect a callback with `item_for_represented_object_at_index_path().connect(...)`.
        Signal<CollectionView, CollectionViewItem(IndexPath)> item_for_represented_object_at_index_path() const
        {
            return Signal<CollectionView, CollectionViewItem(IndexPath)>(handle(), "item_for_represented_object_at_index_path");
        }
        /// @brief Signal for the delegate/data-source method behind `number_of_sections_in_collection_view`; connect a callback with `number_of_sections_in_collection_view().connect(...)`.
        Signal<CollectionView, std::int64_t()> number_of_sections_in_collection_view() const
        {
            return Signal<CollectionView, std::int64_t()>(handle(), "number_of_sections_in_collection_view");
        }
        /// @brief Signal for the delegate/data-source method behind `view_for_supplementary_element_of_kind_at_index_path`; connect a callback with `view_for_supplementary_element_of_kind_at_index_path().connect(...)`.
        Signal<CollectionView, View(std::string, IndexPath)> view_for_supplementary_element_of_kind_at_index_path() const
        {
            return Signal<CollectionView, View(std::string, IndexPath)>(handle(), "view_for_supplementary_element_of_kind_at_index_path");
        }
        /// @brief Signal for the delegate/data-source method behind `can_drag_items_at_index_paths_with_event`; connect a callback with `can_drag_items_at_index_paths_with_event().connect(...)`.
        Signal<CollectionView, bool(std::vector<IndexPath>, Event)> can_drag_items_at_index_paths_with_event() const
        {
            return Signal<CollectionView, bool(std::vector<IndexPath>, Event)>(handle(), "can_drag_items_at_index_paths_with_event");
        }
        /// @brief Signal for the delegate/data-source method behind `can_drag_items_at_indexes_with_event`; connect a callback with `can_drag_items_at_indexes_with_event().connect(...)`.
        Signal<CollectionView, bool(IndexSet, Event)> can_drag_items_at_indexes_with_event() const
        {
            return Signal<CollectionView, bool(IndexSet, Event)>(handle(), "can_drag_items_at_indexes_with_event");
        }
        /// @brief Signal for the delegate/data-source method behind `dragging_image_for_items_at_index_paths_with_event_offset`; connect a callback with `dragging_image_for_items_at_index_paths_with_event_offset().connect(...)`.
        Signal<CollectionView, Image(std::vector<IndexPath>, Event, Point*)> dragging_image_for_items_at_index_paths_with_event_offset() const
        {
            return Signal<CollectionView, Image(std::vector<IndexPath>, Event, Point*)>(handle(), "dragging_image_for_items_at_index_paths_with_event_offset");
        }
        /// @brief Signal for the delegate/data-source method behind `dragging_image_for_items_at_indexes_with_event_offset`; connect a callback with `dragging_image_for_items_at_indexes_with_event_offset().connect(...)`.
        Signal<CollectionView, Image(IndexSet, Event, Point*)> dragging_image_for_items_at_indexes_with_event_offset() const
        {
            return Signal<CollectionView, Image(IndexSet, Event, Point*)>(handle(), "dragging_image_for_items_at_indexes_with_event_offset");
        }
        /// @brief Signal for the delegate/data-source method behind `validate_drop_proposed_index_path_drop_operation`; connect a callback with `validate_drop_proposed_index_path_drop_operation().connect(...)`.
        Signal<CollectionView, DragOperation(Object, IndexPath&, CollectionViewDropOperation*)> validate_drop_proposed_index_path_drop_operation() const
        {
            return Signal<CollectionView, DragOperation(Object, IndexPath&, CollectionViewDropOperation*)>(handle(), "validate_drop_proposed_index_path_drop_operation");
        }
        /// @brief Signal for the delegate/data-source method behind `validate_drop_proposed_index_drop_operation`; connect a callback with `validate_drop_proposed_index_drop_operation().connect(...)`.
        Signal<CollectionView, DragOperation(Object, std::int64_t*, CollectionViewDropOperation*)> validate_drop_proposed_index_drop_operation() const
        {
            return Signal<CollectionView, DragOperation(Object, std::int64_t*, CollectionViewDropOperation*)>(handle(), "validate_drop_proposed_index_drop_operation");
        }
        /// @brief Signal for the delegate/data-source method behind `accept_drop_index_path_drop_operation`; connect a callback with `accept_drop_index_path_drop_operation().connect(...)`.
        Signal<CollectionView, bool(Object, IndexPath, CollectionViewDropOperation)> accept_drop_index_path_drop_operation() const
        {
            return Signal<CollectionView, bool(Object, IndexPath, CollectionViewDropOperation)>(handle(), "accept_drop_index_path_drop_operation");
        }
        /// @brief Signal for the delegate/data-source method behind `accept_drop_index_drop_operation`; connect a callback with `accept_drop_index_drop_operation().connect(...)`.
        Signal<CollectionView, bool(Object, std::int64_t, CollectionViewDropOperation)> accept_drop_index_drop_operation() const
        {
            return Signal<CollectionView, bool(Object, std::int64_t, CollectionViewDropOperation)>(handle(), "accept_drop_index_drop_operation");
        }
        /// @brief Signal for the delegate/data-source method behind `pasteboard_writer_for_item_at_index_path`; connect a callback with `pasteboard_writer_for_item_at_index_path().connect(...)`.
        Signal<CollectionView, Object(IndexPath)> pasteboard_writer_for_item_at_index_path() const
        {
            return Signal<CollectionView, Object(IndexPath)>(handle(), "pasteboard_writer_for_item_at_index_path");
        }
        /// @brief Signal for the delegate/data-source method behind `pasteboard_writer_for_item_at_index`; connect a callback with `pasteboard_writer_for_item_at_index().connect(...)`.
        Signal<CollectionView, Object(std::uint64_t)> pasteboard_writer_for_item_at_index() const
        {
            return Signal<CollectionView, Object(std::uint64_t)>(handle(), "pasteboard_writer_for_item_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `dragging_session_will_begin_at_point_for_items_at_index_paths`; connect a callback with `dragging_session_will_begin_at_point_for_items_at_index_paths().connect(...)`.
        Signal<CollectionView, void(DraggingSession, Point, std::vector<IndexPath>)> dragging_session_will_begin_at_point_for_items_at_index_paths() const
        {
            return Signal<CollectionView, void(DraggingSession, Point, std::vector<IndexPath>)>(handle(), "dragging_session_will_begin_at_point_for_items_at_index_paths");
        }
        /// @brief Signal for the delegate/data-source method behind `dragging_session_will_begin_at_point_for_items_at_indexes`; connect a callback with `dragging_session_will_begin_at_point_for_items_at_indexes().connect(...)`.
        Signal<CollectionView, void(DraggingSession, Point, IndexSet)> dragging_session_will_begin_at_point_for_items_at_indexes() const
        {
            return Signal<CollectionView, void(DraggingSession, Point, IndexSet)>(handle(), "dragging_session_will_begin_at_point_for_items_at_indexes");
        }
        /// @brief Signal for the delegate/data-source method behind `dragging_session_ended_at_point_drag_operation`; connect a callback with `dragging_session_ended_at_point_drag_operation().connect(...)`.
        Signal<CollectionView, void(DraggingSession, Point, DragOperation)> dragging_session_ended_at_point_drag_operation() const
        {
            return Signal<CollectionView, void(DraggingSession, Point, DragOperation)>(handle(), "dragging_session_ended_at_point_drag_operation");
        }
        /// @brief Signal for the delegate/data-source method behind `update_dragging_items_for_drag`; connect a callback with `update_dragging_items_for_drag().connect(...)`.
        Signal<CollectionView, void(Object)> update_dragging_items_for_drag() const
        {
            return Signal<CollectionView, void(Object)>(handle(), "update_dragging_items_for_drag");
        }
        /// @brief Signal for the delegate/data-source method behind `should_change_items_at_index_paths_to_highlight_state`; connect a callback with `should_change_items_at_index_paths_to_highlight_state().connect(...)`.
        Signal<CollectionView, std::vector<IndexPath>(std::vector<IndexPath>, CollectionViewItemHighlightState)> should_change_items_at_index_paths_to_highlight_state() const
        {
            return Signal<CollectionView, std::vector<IndexPath>(std::vector<IndexPath>, CollectionViewItemHighlightState)>(handle(), "should_change_items_at_index_paths_to_highlight_state");
        }
        /// @brief Signal for the delegate/data-source method behind `did_change_items_at_index_paths_to_highlight_state`; connect a callback with `did_change_items_at_index_paths_to_highlight_state().connect(...)`.
        Signal<CollectionView, void(std::vector<IndexPath>, CollectionViewItemHighlightState)> did_change_items_at_index_paths_to_highlight_state() const
        {
            return Signal<CollectionView, void(std::vector<IndexPath>, CollectionViewItemHighlightState)>(handle(), "did_change_items_at_index_paths_to_highlight_state");
        }
        /// @brief Signal for the delegate/data-source method behind `should_select_items_at_index_paths`; connect a callback with `should_select_items_at_index_paths().connect(...)`.
        Signal<CollectionView, std::vector<IndexPath>(std::vector<IndexPath>)> should_select_items_at_index_paths() const
        {
            return Signal<CollectionView, std::vector<IndexPath>(std::vector<IndexPath>)>(handle(), "should_select_items_at_index_paths");
        }
        /// @brief Signal for the delegate/data-source method behind `should_deselect_items_at_index_paths`; connect a callback with `should_deselect_items_at_index_paths().connect(...)`.
        Signal<CollectionView, std::vector<IndexPath>(std::vector<IndexPath>)> should_deselect_items_at_index_paths() const
        {
            return Signal<CollectionView, std::vector<IndexPath>(std::vector<IndexPath>)>(handle(), "should_deselect_items_at_index_paths");
        }
        /// @brief Signal for the delegate/data-source method behind `did_select_items_at_index_paths`; connect a callback with `did_select_items_at_index_paths().connect(...)`.
        Signal<CollectionView, void(std::vector<IndexPath>)> did_select_items_at_index_paths() const
        {
            return Signal<CollectionView, void(std::vector<IndexPath>)>(handle(), "did_select_items_at_index_paths");
        }
        /// @brief Signal for the delegate/data-source method behind `did_deselect_items_at_index_paths`; connect a callback with `did_deselect_items_at_index_paths().connect(...)`.
        Signal<CollectionView, void(std::vector<IndexPath>)> did_deselect_items_at_index_paths() const
        {
            return Signal<CollectionView, void(std::vector<IndexPath>)>(handle(), "did_deselect_items_at_index_paths");
        }
        /// @brief Signal for the delegate/data-source method behind `will_display_item_for_represented_object_at_index_path`; connect a callback with `will_display_item_for_represented_object_at_index_path().connect(...)`.
        Signal<CollectionView, void(CollectionViewItem, IndexPath)> will_display_item_for_represented_object_at_index_path() const
        {
            return Signal<CollectionView, void(CollectionViewItem, IndexPath)>(handle(), "will_display_item_for_represented_object_at_index_path");
        }
        /// @brief Signal for the delegate/data-source method behind `will_display_supplementary_view_for_element_kind_at_index_path`; connect a callback with `will_display_supplementary_view_for_element_kind_at_index_path().connect(...)`.
        Signal<CollectionView, void(View, std::string, IndexPath)> will_display_supplementary_view_for_element_kind_at_index_path() const
        {
            return Signal<CollectionView, void(View, std::string, IndexPath)>(handle(), "will_display_supplementary_view_for_element_kind_at_index_path");
        }
        /// @brief Signal for the delegate/data-source method behind `did_end_displaying_item_for_represented_object_at_index_path`; connect a callback with `did_end_displaying_item_for_represented_object_at_index_path().connect(...)`.
        Signal<CollectionView, void(CollectionViewItem, IndexPath)> did_end_displaying_item_for_represented_object_at_index_path() const
        {
            return Signal<CollectionView, void(CollectionViewItem, IndexPath)>(handle(), "did_end_displaying_item_for_represented_object_at_index_path");
        }
        /// @brief Signal for the delegate/data-source method behind `did_end_displaying_supplementary_view_for_element_of_kind_at_index_path`; connect a callback with `did_end_displaying_supplementary_view_for_element_of_kind_at_index_path().connect(...)`.
        Signal<CollectionView, void(View, std::string, IndexPath)> did_end_displaying_supplementary_view_for_element_of_kind_at_index_path() const
        {
            return Signal<CollectionView, void(View, std::string, IndexPath)>(handle(), "did_end_displaying_supplementary_view_for_element_of_kind_at_index_path");
        }
        /// @brief Signal for the delegate/data-source method behind `transition_layout_for_old_layout_new_layout`; connect a callback with `transition_layout_for_old_layout_new_layout().connect(...)`.
        Signal<CollectionView, CollectionViewTransitionLayout(CollectionViewLayout, CollectionViewLayout)> transition_layout_for_old_layout_new_layout() const
        {
            return Signal<CollectionView, CollectionViewTransitionLayout(CollectionViewLayout, CollectionViewLayout)>(handle(), "transition_layout_for_old_layout_new_layout");
        }

    protected:
        static void install_data_source_delegate_(void* native);
        static void install_delegate_delegate_(void* native);
    };
}
