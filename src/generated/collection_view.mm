#include "generated/collection_view.h"
#include "internal.h"

@interface AKCollectionViewDataSourceDelegate : NSObject <NSCollectionViewDataSource>
{
@public
    __weak id host;
}
@end

@implementation AKCollectionViewDataSourceDelegate

- (NSInteger)collectionView:(NSCollectionView*)collectionView numberOfItemsInSection:(NSInteger)section
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, std::int64_t(std::int64_t)>::emit((__bridge void*)strongHost, "collection_view_number_of_items_in_section", static_cast<std::int64_t>(section));
    return static_cast<::NSInteger>(__r);
}

- (NSCollectionViewItem*)collectionView:(NSCollectionView*)collectionView itemForRepresentedObjectAtIndexPath:(NSIndexPath*)indexPath
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, cocoon::CollectionViewItem(cocoon::IndexPath)>::emit((__bridge void*)strongHost, "item_for_represented_object_at_index_path", cocoon::internal::wrap<cocoon::IndexPath>(indexPath));
    return cocoon::internal::native<::NSCollectionViewItem>(__r);
}

- (NSInteger)numberOfSectionsInCollectionView:(NSCollectionView*)collectionView
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, std::int64_t()>::emit((__bridge void*)strongHost, "number_of_sections_in_collection_view");
    return static_cast<::NSInteger>(__r);
}

- (NSView*)collectionView:(NSCollectionView*)collectionView viewForSupplementaryElementOfKind:(NSCollectionViewSupplementaryElementKind)kind atIndexPath:(NSIndexPath*)indexPath
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, cocoon::View(std::string, cocoon::IndexPath)>::emit((__bridge void*)strongHost, "view_for_supplementary_element_of_kind_at_index_path", cocoon::internal::from(kind), cocoon::internal::wrap<cocoon::IndexPath>(indexPath));
    return cocoon::internal::native<::NSView>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(collectionView:numberOfItemsInSection:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, std::int64_t(std::int64_t)>::connected((__bridge void*)strongHost, "collection_view_number_of_items_in_section");
    }
    if (selector == @selector(collectionView:itemForRepresentedObjectAtIndexPath:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, cocoon::CollectionViewItem(cocoon::IndexPath)>::connected((__bridge void*)strongHost, "item_for_represented_object_at_index_path");
    }
    if (selector == @selector(numberOfSectionsInCollectionView:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, std::int64_t()>::connected((__bridge void*)strongHost, "number_of_sections_in_collection_view");
    }
    if (selector == @selector(collectionView:viewForSupplementaryElementOfKind:atIndexPath:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, cocoon::View(std::string, cocoon::IndexPath)>::connected((__bridge void*)strongHost, "view_for_supplementary_element_of_kind_at_index_path");
    }
    return [super respondsToSelector:selector];
}

@end

@interface AKCollectionViewDelegate : NSObject <NSCollectionViewDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKCollectionViewDelegate

- (BOOL)collectionView:(NSCollectionView*)collectionView canDragItemsAtIndexPaths:(NSSet<NSIndexPath*>*)indexPaths withEvent:(NSEvent*)event
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, bool(std::vector<cocoon::IndexPath>, cocoon::Event)>::emit((__bridge void*)strongHost, "can_drag_items_at_index_paths_with_event", cocoon::internal::from_array<cocoon::IndexPath>([indexPaths allObjects], [](id e) -> cocoon::IndexPath
                                                                                                                                                                                                                                         {
                                                                                                                                                                                                                                             return cocoon::internal::wrap<cocoon::IndexPath>((::NSIndexPath*)e);
                                                                                                                                                                                                                                         }),
                                                                                                                 cocoon::internal::wrap<cocoon::Event>(event));
    return static_cast<::BOOL>(__r);
}

- (BOOL)collectionView:(NSCollectionView*)collectionView canDragItemsAtIndexes:(NSIndexSet*)indexes withEvent:(NSEvent*)event
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, bool(cocoon::IndexSet, cocoon::Event)>::emit((__bridge void*)strongHost, "can_drag_items_at_indexes_with_event", cocoon::internal::wrap<cocoon::IndexSet>(indexes), cocoon::internal::wrap<cocoon::Event>(event));
    return static_cast<::BOOL>(__r);
}

- (NSImage*)collectionView:(NSCollectionView*)collectionView draggingImageForItemsAtIndexPaths:(NSSet<NSIndexPath*>*)indexPaths withEvent:(NSEvent*)event offset:(NSPointPointer)dragImageOffset
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, cocoon::Image(std::vector<cocoon::IndexPath>, cocoon::Event, cocoon::Point*)>::emit((__bridge void*)strongHost, "dragging_image_for_items_at_index_paths_with_event_offset", cocoon::internal::from_array<cocoon::IndexPath>([indexPaths allObjects], [](id e) -> cocoon::IndexPath
                                                                                                                                                                                                                                                                                   {
                                                                                                                                                                                                                                                                                       return cocoon::internal::wrap<cocoon::IndexPath>((::NSIndexPath*)e);
                                                                                                                                                                                                                                                                                   }),
                                                                                                                                          cocoon::internal::wrap<cocoon::Event>(event), (cocoon::Point*)(dragImageOffset));
    return cocoon::internal::native<::NSImage>(__r);
}

- (NSImage*)collectionView:(NSCollectionView*)collectionView draggingImageForItemsAtIndexes:(NSIndexSet*)indexes withEvent:(NSEvent*)event offset:(NSPointPointer)dragImageOffset
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, cocoon::Image(cocoon::IndexSet, cocoon::Event, cocoon::Point*)>::emit((__bridge void*)strongHost, "dragging_image_for_items_at_indexes_with_event_offset", cocoon::internal::wrap<cocoon::IndexSet>(indexes), cocoon::internal::wrap<cocoon::Event>(event), (cocoon::Point*)(dragImageOffset));
    return cocoon::internal::native<::NSImage>(__r);
}

- (NSDragOperation)collectionView:(NSCollectionView*)collectionView validateDrop:(id<NSDraggingInfo>)draggingInfo proposedIndexPath:(NSIndexPath**)proposedDropIndexPath dropOperation:(NSCollectionViewDropOperation*)proposedDropOperation
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    cocoon::IndexPath __v_proposedDropIndexPath = proposedDropIndexPath ? cocoon::internal::wrap<cocoon::IndexPath>(*proposedDropIndexPath) : cocoon::IndexPath();
    auto __r = cocoon::Signal<cocoon::CollectionView, cocoon::DragOperation(cocoon::Object, cocoon::IndexPath&, cocoon::CollectionViewDropOperation*)>::emit((__bridge void*)strongHost, "validate_drop_proposed_index_path_drop_operation", cocoon::internal::wrap<cocoon::Object>(draggingInfo), __v_proposedDropIndexPath, (cocoon::CollectionViewDropOperation*)(proposedDropOperation));
    if (proposedDropIndexPath)
    {
        *proposedDropIndexPath = cocoon::internal::native<::NSIndexPath>(__v_proposedDropIndexPath);
    }
    return static_cast<::NSDragOperation>(__r);
}

- (NSDragOperation)collectionView:(NSCollectionView*)collectionView validateDrop:(id<NSDraggingInfo>)draggingInfo proposedIndex:(NSInteger*)proposedDropIndex dropOperation:(NSCollectionViewDropOperation*)proposedDropOperation
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, cocoon::DragOperation(cocoon::Object, std::int64_t*, cocoon::CollectionViewDropOperation*)>::emit((__bridge void*)strongHost, "validate_drop_proposed_index_drop_operation", cocoon::internal::wrap<cocoon::Object>(draggingInfo), (std::int64_t*)(proposedDropIndex), (cocoon::CollectionViewDropOperation*)(proposedDropOperation));
    return static_cast<::NSDragOperation>(__r);
}

- (BOOL)collectionView:(NSCollectionView*)collectionView acceptDrop:(id<NSDraggingInfo>)draggingInfo indexPath:(NSIndexPath*)indexPath dropOperation:(NSCollectionViewDropOperation)dropOperation
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, bool(cocoon::Object, cocoon::IndexPath, cocoon::CollectionViewDropOperation)>::emit((__bridge void*)strongHost, "accept_drop_index_path_drop_operation", cocoon::internal::wrap<cocoon::Object>(draggingInfo), cocoon::internal::wrap<cocoon::IndexPath>(indexPath), static_cast<cocoon::CollectionViewDropOperation>(dropOperation));
    return static_cast<::BOOL>(__r);
}

- (BOOL)collectionView:(NSCollectionView*)collectionView acceptDrop:(id<NSDraggingInfo>)draggingInfo index:(NSInteger)index dropOperation:(NSCollectionViewDropOperation)dropOperation
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, bool(cocoon::Object, std::int64_t, cocoon::CollectionViewDropOperation)>::emit((__bridge void*)strongHost, "accept_drop_index_drop_operation", cocoon::internal::wrap<cocoon::Object>(draggingInfo), static_cast<std::int64_t>(index), static_cast<cocoon::CollectionViewDropOperation>(dropOperation));
    return static_cast<::BOOL>(__r);
}

- (id<NSPasteboardWriting>)collectionView:(NSCollectionView*)collectionView pasteboardWriterForItemAtIndexPath:(NSIndexPath*)indexPath
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, cocoon::Object(cocoon::IndexPath)>::emit((__bridge void*)strongHost, "pasteboard_writer_for_item_at_index_path", cocoon::internal::wrap<cocoon::IndexPath>(indexPath));
    return cocoon::internal::native_id(__r);
}

- (id<NSPasteboardWriting>)collectionView:(NSCollectionView*)collectionView pasteboardWriterForItemAtIndex:(NSUInteger)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, cocoon::Object(std::uint64_t)>::emit((__bridge void*)strongHost, "pasteboard_writer_for_item_at_index", static_cast<std::uint64_t>(index));
    return cocoon::internal::native_id(__r);
}

- (void)collectionView:(NSCollectionView*)collectionView draggingSession:(NSDraggingSession*)session willBeginAtPoint:(NSPoint)screenPoint forItemsAtIndexPaths:(NSSet<NSIndexPath*>*)indexPaths
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CollectionView, void(cocoon::DraggingSession, cocoon::Point, std::vector<cocoon::IndexPath>)>::emit((__bridge void*)strongHost, "dragging_session_will_begin_at_point_for_items_at_index_paths", cocoon::internal::wrap<cocoon::DraggingSession>(session), cocoon::internal::from(screenPoint), cocoon::internal::from_array<cocoon::IndexPath>([indexPaths allObjects], [](id e) -> cocoon::IndexPath
                                                                                                                                                                                                                                                                                                                                                                           {
                                                                                                                                                                                                                                                                                                                                                                               return cocoon::internal::wrap<cocoon::IndexPath>((::NSIndexPath*)e);
                                                                                                                                                                                                                                                                                                                                                                           }));
}

- (void)collectionView:(NSCollectionView*)collectionView draggingSession:(NSDraggingSession*)session willBeginAtPoint:(NSPoint)screenPoint forItemsAtIndexes:(NSIndexSet*)indexes
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CollectionView, void(cocoon::DraggingSession, cocoon::Point, cocoon::IndexSet)>::emit((__bridge void*)strongHost, "dragging_session_will_begin_at_point_for_items_at_indexes", cocoon::internal::wrap<cocoon::DraggingSession>(session), cocoon::internal::from(screenPoint), cocoon::internal::wrap<cocoon::IndexSet>(indexes));
}

- (void)collectionView:(NSCollectionView*)collectionView draggingSession:(NSDraggingSession*)session endedAtPoint:(NSPoint)screenPoint dragOperation:(NSDragOperation)operation
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CollectionView, void(cocoon::DraggingSession, cocoon::Point, cocoon::DragOperation)>::emit((__bridge void*)strongHost, "dragging_session_ended_at_point_drag_operation", cocoon::internal::wrap<cocoon::DraggingSession>(session), cocoon::internal::from(screenPoint), static_cast<cocoon::DragOperation>(operation));
}

- (void)collectionView:(NSCollectionView*)collectionView updateDraggingItemsForDrag:(id<NSDraggingInfo>)draggingInfo
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CollectionView, void(cocoon::Object)>::emit((__bridge void*)strongHost, "update_dragging_items_for_drag", cocoon::internal::wrap<cocoon::Object>(draggingInfo));
}

- (NSSet<NSIndexPath*>*)collectionView:(NSCollectionView*)collectionView shouldChangeItemsAtIndexPaths:(NSSet<NSIndexPath*>*)indexPaths toHighlightState:(NSCollectionViewItemHighlightState)highlightState
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, std::vector<cocoon::IndexPath>(std::vector<cocoon::IndexPath>, cocoon::CollectionViewItemHighlightState)>::emit((__bridge void*)strongHost, "should_change_items_at_index_paths_to_highlight_state", cocoon::internal::from_array<cocoon::IndexPath>([indexPaths allObjects], [](id e) -> cocoon::IndexPath
                                                                                                                                                                                                                                                                                                           {
                                                                                                                                                                                                                                                                                                               return cocoon::internal::wrap<cocoon::IndexPath>((::NSIndexPath*)e);
                                                                                                                                                                                                                                                                                                           }),
                                                                                                                                                                      static_cast<cocoon::CollectionViewItemHighlightState>(highlightState));
    return [NSSet setWithArray:cocoon::internal::to_array(__r, [](const cocoon::IndexPath& e) -> id
                                                          {
                                                              return cocoon::internal::native<::NSIndexPath>(e);
                                                          })];
}

- (void)collectionView:(NSCollectionView*)collectionView didChangeItemsAtIndexPaths:(NSSet<NSIndexPath*>*)indexPaths toHighlightState:(NSCollectionViewItemHighlightState)highlightState
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CollectionView, void(std::vector<cocoon::IndexPath>, cocoon::CollectionViewItemHighlightState)>::emit((__bridge void*)strongHost, "did_change_items_at_index_paths_to_highlight_state", cocoon::internal::from_array<cocoon::IndexPath>([indexPaths allObjects], [](id e) -> cocoon::IndexPath
                                                                                                                                                                                                                                                                   {
                                                                                                                                                                                                                                                                       return cocoon::internal::wrap<cocoon::IndexPath>((::NSIndexPath*)e);
                                                                                                                                                                                                                                                                   }),
                                                                                                                                 static_cast<cocoon::CollectionViewItemHighlightState>(highlightState));
}

- (NSSet<NSIndexPath*>*)collectionView:(NSCollectionView*)collectionView shouldSelectItemsAtIndexPaths:(NSSet<NSIndexPath*>*)indexPaths
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, std::vector<cocoon::IndexPath>(std::vector<cocoon::IndexPath>)>::emit((__bridge void*)strongHost, "should_select_items_at_index_paths", cocoon::internal::from_array<cocoon::IndexPath>([indexPaths allObjects], [](id e) -> cocoon::IndexPath
                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                  return cocoon::internal::wrap<cocoon::IndexPath>((::NSIndexPath*)e);
                                                                                                                                                                                                                                              }));
    return [NSSet setWithArray:cocoon::internal::to_array(__r, [](const cocoon::IndexPath& e) -> id
                                                          {
                                                              return cocoon::internal::native<::NSIndexPath>(e);
                                                          })];
}

- (NSSet<NSIndexPath*>*)collectionView:(NSCollectionView*)collectionView shouldDeselectItemsAtIndexPaths:(NSSet<NSIndexPath*>*)indexPaths
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, std::vector<cocoon::IndexPath>(std::vector<cocoon::IndexPath>)>::emit((__bridge void*)strongHost, "should_deselect_items_at_index_paths", cocoon::internal::from_array<cocoon::IndexPath>([indexPaths allObjects], [](id e) -> cocoon::IndexPath
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                    return cocoon::internal::wrap<cocoon::IndexPath>((::NSIndexPath*)e);
                                                                                                                                                                                                                                                }));
    return [NSSet setWithArray:cocoon::internal::to_array(__r, [](const cocoon::IndexPath& e) -> id
                                                          {
                                                              return cocoon::internal::native<::NSIndexPath>(e);
                                                          })];
}

- (void)collectionView:(NSCollectionView*)collectionView didSelectItemsAtIndexPaths:(NSSet<NSIndexPath*>*)indexPaths
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CollectionView, void(std::vector<cocoon::IndexPath>)>::emit((__bridge void*)strongHost, "did_select_items_at_index_paths", cocoon::internal::from_array<cocoon::IndexPath>([indexPaths allObjects], [](id e) -> cocoon::IndexPath
                                                                                                                                                                                                      {
                                                                                                                                                                                                          return cocoon::internal::wrap<cocoon::IndexPath>((::NSIndexPath*)e);
                                                                                                                                                                                                      }));
}

- (void)collectionView:(NSCollectionView*)collectionView didDeselectItemsAtIndexPaths:(NSSet<NSIndexPath*>*)indexPaths
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CollectionView, void(std::vector<cocoon::IndexPath>)>::emit((__bridge void*)strongHost, "did_deselect_items_at_index_paths", cocoon::internal::from_array<cocoon::IndexPath>([indexPaths allObjects], [](id e) -> cocoon::IndexPath
                                                                                                                                                                                                        {
                                                                                                                                                                                                            return cocoon::internal::wrap<cocoon::IndexPath>((::NSIndexPath*)e);
                                                                                                                                                                                                        }));
}

- (void)collectionView:(NSCollectionView*)collectionView willDisplayItem:(NSCollectionViewItem*)item forRepresentedObjectAtIndexPath:(NSIndexPath*)indexPath
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CollectionView, void(cocoon::CollectionViewItem, cocoon::IndexPath)>::emit((__bridge void*)strongHost, "will_display_item_for_represented_object_at_index_path", cocoon::internal::wrap<cocoon::CollectionViewItem>(item), cocoon::internal::wrap<cocoon::IndexPath>(indexPath));
}

- (void)collectionView:(NSCollectionView*)collectionView willDisplaySupplementaryView:(NSView*)view forElementKind:(NSCollectionViewSupplementaryElementKind)elementKind atIndexPath:(NSIndexPath*)indexPath
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CollectionView, void(cocoon::View, std::string, cocoon::IndexPath)>::emit((__bridge void*)strongHost, "will_display_supplementary_view_for_element_kind_at_index_path", cocoon::internal::wrap<cocoon::View>(view), cocoon::internal::from(elementKind), cocoon::internal::wrap<cocoon::IndexPath>(indexPath));
}

- (void)collectionView:(NSCollectionView*)collectionView didEndDisplayingItem:(NSCollectionViewItem*)item forRepresentedObjectAtIndexPath:(NSIndexPath*)indexPath
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CollectionView, void(cocoon::CollectionViewItem, cocoon::IndexPath)>::emit((__bridge void*)strongHost, "did_end_displaying_item_for_represented_object_at_index_path", cocoon::internal::wrap<cocoon::CollectionViewItem>(item), cocoon::internal::wrap<cocoon::IndexPath>(indexPath));
}

- (void)collectionView:(NSCollectionView*)collectionView didEndDisplayingSupplementaryView:(NSView*)view forElementOfKind:(NSCollectionViewSupplementaryElementKind)elementKind atIndexPath:(NSIndexPath*)indexPath
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CollectionView, void(cocoon::View, std::string, cocoon::IndexPath)>::emit((__bridge void*)strongHost, "did_end_displaying_supplementary_view_for_element_of_kind_at_index_path", cocoon::internal::wrap<cocoon::View>(view), cocoon::internal::from(elementKind), cocoon::internal::wrap<cocoon::IndexPath>(indexPath));
}

- (NSCollectionViewTransitionLayout*)collectionView:(NSCollectionView*)collectionView transitionLayoutForOldLayout:(NSCollectionViewLayout*)fromLayout newLayout:(NSCollectionViewLayout*)toLayout
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CollectionView, cocoon::CollectionViewTransitionLayout(cocoon::CollectionViewLayout, cocoon::CollectionViewLayout)>::emit((__bridge void*)strongHost, "transition_layout_for_old_layout_new_layout", cocoon::internal::wrap<cocoon::CollectionViewLayout>(fromLayout), cocoon::internal::wrap<cocoon::CollectionViewLayout>(toLayout));
    return cocoon::internal::native<::NSCollectionViewTransitionLayout>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(collectionView:canDragItemsAtIndexPaths:withEvent:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, bool(std::vector<cocoon::IndexPath>, cocoon::Event)>::connected((__bridge void*)strongHost, "can_drag_items_at_index_paths_with_event");
    }
    if (selector == @selector(collectionView:canDragItemsAtIndexes:withEvent:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, bool(cocoon::IndexSet, cocoon::Event)>::connected((__bridge void*)strongHost, "can_drag_items_at_indexes_with_event");
    }
    if (selector == @selector(collectionView:draggingImageForItemsAtIndexPaths:withEvent:offset:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, cocoon::Image(std::vector<cocoon::IndexPath>, cocoon::Event, cocoon::Point*)>::connected((__bridge void*)strongHost, "dragging_image_for_items_at_index_paths_with_event_offset");
    }
    if (selector == @selector(collectionView:draggingImageForItemsAtIndexes:withEvent:offset:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, cocoon::Image(cocoon::IndexSet, cocoon::Event, cocoon::Point*)>::connected((__bridge void*)strongHost, "dragging_image_for_items_at_indexes_with_event_offset");
    }
    if (selector == @selector(collectionView:validateDrop:proposedIndexPath:dropOperation:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, cocoon::DragOperation(cocoon::Object, cocoon::IndexPath&, cocoon::CollectionViewDropOperation*)>::connected((__bridge void*)strongHost, "validate_drop_proposed_index_path_drop_operation");
    }
    if (selector == @selector(collectionView:validateDrop:proposedIndex:dropOperation:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, cocoon::DragOperation(cocoon::Object, std::int64_t*, cocoon::CollectionViewDropOperation*)>::connected((__bridge void*)strongHost, "validate_drop_proposed_index_drop_operation");
    }
    if (selector == @selector(collectionView:acceptDrop:indexPath:dropOperation:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, bool(cocoon::Object, cocoon::IndexPath, cocoon::CollectionViewDropOperation)>::connected((__bridge void*)strongHost, "accept_drop_index_path_drop_operation");
    }
    if (selector == @selector(collectionView:acceptDrop:index:dropOperation:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, bool(cocoon::Object, std::int64_t, cocoon::CollectionViewDropOperation)>::connected((__bridge void*)strongHost, "accept_drop_index_drop_operation");
    }
    if (selector == @selector(collectionView:pasteboardWriterForItemAtIndexPath:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, cocoon::Object(cocoon::IndexPath)>::connected((__bridge void*)strongHost, "pasteboard_writer_for_item_at_index_path");
    }
    if (selector == @selector(collectionView:pasteboardWriterForItemAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, cocoon::Object(std::uint64_t)>::connected((__bridge void*)strongHost, "pasteboard_writer_for_item_at_index");
    }
    if (selector == @selector(collectionView:draggingSession:willBeginAtPoint:forItemsAtIndexPaths:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, void(cocoon::DraggingSession, cocoon::Point, std::vector<cocoon::IndexPath>)>::connected((__bridge void*)strongHost, "dragging_session_will_begin_at_point_for_items_at_index_paths");
    }
    if (selector == @selector(collectionView:draggingSession:willBeginAtPoint:forItemsAtIndexes:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, void(cocoon::DraggingSession, cocoon::Point, cocoon::IndexSet)>::connected((__bridge void*)strongHost, "dragging_session_will_begin_at_point_for_items_at_indexes");
    }
    if (selector == @selector(collectionView:draggingSession:endedAtPoint:dragOperation:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, void(cocoon::DraggingSession, cocoon::Point, cocoon::DragOperation)>::connected((__bridge void*)strongHost, "dragging_session_ended_at_point_drag_operation");
    }
    if (selector == @selector(collectionView:updateDraggingItemsForDrag:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, void(cocoon::Object)>::connected((__bridge void*)strongHost, "update_dragging_items_for_drag");
    }
    if (selector == @selector(collectionView:shouldChangeItemsAtIndexPaths:toHighlightState:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, std::vector<cocoon::IndexPath>(std::vector<cocoon::IndexPath>, cocoon::CollectionViewItemHighlightState)>::connected((__bridge void*)strongHost, "should_change_items_at_index_paths_to_highlight_state");
    }
    if (selector == @selector(collectionView:didChangeItemsAtIndexPaths:toHighlightState:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, void(std::vector<cocoon::IndexPath>, cocoon::CollectionViewItemHighlightState)>::connected((__bridge void*)strongHost, "did_change_items_at_index_paths_to_highlight_state");
    }
    if (selector == @selector(collectionView:shouldSelectItemsAtIndexPaths:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, std::vector<cocoon::IndexPath>(std::vector<cocoon::IndexPath>)>::connected((__bridge void*)strongHost, "should_select_items_at_index_paths");
    }
    if (selector == @selector(collectionView:shouldDeselectItemsAtIndexPaths:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, std::vector<cocoon::IndexPath>(std::vector<cocoon::IndexPath>)>::connected((__bridge void*)strongHost, "should_deselect_items_at_index_paths");
    }
    if (selector == @selector(collectionView:didSelectItemsAtIndexPaths:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, void(std::vector<cocoon::IndexPath>)>::connected((__bridge void*)strongHost, "did_select_items_at_index_paths");
    }
    if (selector == @selector(collectionView:didDeselectItemsAtIndexPaths:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, void(std::vector<cocoon::IndexPath>)>::connected((__bridge void*)strongHost, "did_deselect_items_at_index_paths");
    }
    if (selector == @selector(collectionView:willDisplayItem:forRepresentedObjectAtIndexPath:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, void(cocoon::CollectionViewItem, cocoon::IndexPath)>::connected((__bridge void*)strongHost, "will_display_item_for_represented_object_at_index_path");
    }
    if (selector == @selector(collectionView:willDisplaySupplementaryView:forElementKind:atIndexPath:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, void(cocoon::View, std::string, cocoon::IndexPath)>::connected((__bridge void*)strongHost, "will_display_supplementary_view_for_element_kind_at_index_path");
    }
    if (selector == @selector(collectionView:didEndDisplayingItem:forRepresentedObjectAtIndexPath:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, void(cocoon::CollectionViewItem, cocoon::IndexPath)>::connected((__bridge void*)strongHost, "did_end_displaying_item_for_represented_object_at_index_path");
    }
    if (selector == @selector(collectionView:didEndDisplayingSupplementaryView:forElementOfKind:atIndexPath:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, void(cocoon::View, std::string, cocoon::IndexPath)>::connected((__bridge void*)strongHost, "did_end_displaying_supplementary_view_for_element_of_kind_at_index_path");
    }
    if (selector == @selector(collectionView:transitionLayoutForOldLayout:newLayout:))
    {
        return strongHost && cocoon::Signal<cocoon::CollectionView, cocoon::CollectionViewTransitionLayout(cocoon::CollectionViewLayout, cocoon::CollectionViewLayout)>::connected((__bridge void*)strongHost, "transition_layout_for_old_layout_new_layout");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    CollectionView::CollectionView() : CollectionView(Adopt{cocoon::internal::retain([[::NSCollectionView alloc] init])})
    {
        CollectionView::install_data_source_delegate_(handle());
        CollectionView::install_delegate_delegate_(handle());
    }

    CollectionView::CollectionView(std::nullptr_t) : View(nullptr)
    {
    }

    CollectionView::CollectionView(Adopt adopt) : View(adopt)
    {
    }

    void CollectionView::delete_items_at_index_paths(const std::vector<IndexPath>& index_paths) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) deleteItemsAtIndexPaths:[NSSet setWithArray:cocoon::internal::to_array(index_paths, [](const IndexPath& e) -> id
                                                                                                                               {
                                                                                                                                   return cocoon::internal::native<::NSIndexPath>(e);
                                                                                                                               })]];
    }

    void CollectionView::delete_sections(const IndexSet& sections) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) deleteSections:cocoon::internal::native<::NSIndexSet>(sections)];
    }

    void CollectionView::deselect_all(const Object& sender) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) deselectAll:cocoon::internal::native_id(sender)];
    }

    void CollectionView::deselect_items_at_index_paths(const std::vector<IndexPath>& index_paths) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) deselectItemsAtIndexPaths:[NSSet setWithArray:cocoon::internal::to_array(index_paths, [](const IndexPath& e) -> id
                                                                                                                                 {
                                                                                                                                     return cocoon::internal::native<::NSIndexPath>(e);
                                                                                                                                 })]];
    }

    Image CollectionView::dragging_image_for_items_at_index_paths(const std::vector<IndexPath>& index_paths, const Event& event, Point* drag_image_offset) const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSCollectionView>(this) draggingImageForItemsAtIndexPaths:[NSSet setWithArray:cocoon::internal::to_array(index_paths, [](const IndexPath& e) -> id
                                                                                                                                                                              {
                                                                                                                                                                                  return cocoon::internal::native<::NSIndexPath>(e);
                                                                                                                                                                              })]
                                                                                                                     withEvent:cocoon::internal::native<::NSEvent>(event)
                                                                                                                        offset:(::NSPointPointer)(drag_image_offset)]);
    }

    Image CollectionView::dragging_image_for_items_at_indexes(const IndexSet& indexes, const Event& event, Point* drag_image_offset) const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSCollectionView>(this) draggingImageForItemsAtIndexes:cocoon::internal::native<::NSIndexSet>(indexes) withEvent:cocoon::internal::native<::NSEvent>(event) offset:(::NSPointPointer)(drag_image_offset)]);
    }

    Rect CollectionView::frame_for_item_at_index(std::uint64_t index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionView>(this) frameForItemAtIndex:static_cast<::NSUInteger>(index)]);
    }

    Rect CollectionView::frame_for_item_at_index(std::uint64_t index, std::uint64_t number_of_items) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionView>(this) frameForItemAtIndex:static_cast<::NSUInteger>(index) withNumberOfItems:static_cast<::NSUInteger>(number_of_items)]);
    }

    IndexPath CollectionView::index_path_for_item(const CollectionViewItem& item) const
    {
        return cocoon::internal::wrap<IndexPath>([cocoon::internal::ns<::NSCollectionView>(this) indexPathForItem:cocoon::internal::native<::NSCollectionViewItem>(item)]);
    }

    IndexPath CollectionView::index_path_for_item_at_point(const Point& point) const
    {
        return cocoon::internal::wrap<IndexPath>([cocoon::internal::ns<::NSCollectionView>(this) indexPathForItemAtPoint:cocoon::internal::to(point)]);
    }

    std::vector<IndexPath> CollectionView::index_paths_for_visible_items() const
    {
        return cocoon::internal::from_array<IndexPath>([[cocoon::internal::ns<::NSCollectionView>(this) indexPathsForVisibleItems] allObjects], [](id e) -> IndexPath
                                                       {
                                                           return cocoon::internal::wrap<IndexPath>((::NSIndexPath*)e);
                                                       });
    }

    std::vector<IndexPath> CollectionView::index_paths_for_visible_supplementary_elements_of_kind(const std::string& element_kind) const
    {
        return cocoon::internal::from_array<IndexPath>([[cocoon::internal::ns<::NSCollectionView>(this) indexPathsForVisibleSupplementaryElementsOfKind:cocoon::internal::to(element_kind)] allObjects], [](id e) -> IndexPath
                                                       {
                                                           return cocoon::internal::wrap<IndexPath>((::NSIndexPath*)e);
                                                       });
    }

    void CollectionView::insert_items_at_index_paths(const std::vector<IndexPath>& index_paths) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) insertItemsAtIndexPaths:[NSSet setWithArray:cocoon::internal::to_array(index_paths, [](const IndexPath& e) -> id
                                                                                                                               {
                                                                                                                                   return cocoon::internal::native<::NSIndexPath>(e);
                                                                                                                               })]];
    }

    void CollectionView::insert_sections(const IndexSet& sections) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) insertSections:cocoon::internal::native<::NSIndexSet>(sections)];
    }

    CollectionViewItem CollectionView::item_at_index(std::uint64_t index) const
    {
        return cocoon::internal::wrap<CollectionViewItem>([cocoon::internal::ns<::NSCollectionView>(this) itemAtIndex:static_cast<::NSUInteger>(index)]);
    }

    CollectionViewItem CollectionView::item_at_index_path(const IndexPath& index_path) const
    {
        return cocoon::internal::wrap<CollectionViewItem>([cocoon::internal::ns<::NSCollectionView>(this) itemAtIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    CollectionViewLayoutAttributes CollectionView::layout_attributes_for_item_at_index_path(const IndexPath& index_path) const
    {
        return cocoon::internal::wrap<CollectionViewLayoutAttributes>([cocoon::internal::ns<::NSCollectionView>(this) layoutAttributesForItemAtIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    CollectionViewLayoutAttributes CollectionView::layout_attributes_for_supplementary_element_of_kind(const std::string& kind, const IndexPath& index_path) const
    {
        return cocoon::internal::wrap<CollectionViewLayoutAttributes>([cocoon::internal::ns<::NSCollectionView>(this) layoutAttributesForSupplementaryElementOfKind:cocoon::internal::to(kind) atIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    CollectionViewItem CollectionView::make_item_with_identifier(const std::string& identifier, const IndexPath& index_path) const
    {
        return cocoon::internal::wrap<CollectionViewItem>([cocoon::internal::ns<::NSCollectionView>(this) makeItemWithIdentifier:cocoon::internal::to(identifier) forIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    View CollectionView::make_supplementary_view_of_kind(const std::string& element_kind, const std::string& identifier, const IndexPath& index_path) const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSCollectionView>(this) makeSupplementaryViewOfKind:cocoon::internal::to(element_kind) withIdentifier:cocoon::internal::to(identifier) forIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    void CollectionView::move_item_at_index_path(const IndexPath& index_path, const IndexPath& new_index_path) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) moveItemAtIndexPath:cocoon::internal::native<::NSIndexPath>(index_path) toIndexPath:cocoon::internal::native<::NSIndexPath>(new_index_path)];
    }

    void CollectionView::move_section(std::int64_t section, std::int64_t new_section) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) moveSection:static_cast<::NSInteger>(section) toSection:static_cast<::NSInteger>(new_section)];
    }

    std::int64_t CollectionView::number_of_items_in_section(std::int64_t section) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCollectionView>(this) numberOfItemsInSection:static_cast<::NSInteger>(section)]);
    }

    void CollectionView::perform_batch_updates(std::function<void()> updates, std::function<void(bool)> completion_handler) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) performBatchUpdates:(updates ? (void (^)(void)) ^ void() { updates(); } : (void (^)(void))nil) completionHandler:(completion_handler ? (void (^)(BOOL)) ^ void(::BOOL a13_0) { completion_handler(static_cast<bool>(a13_0)); } : (void (^)(BOOL))nil)];
    }

    void CollectionView::register_class(const std::string& item_class, const std::string& identifier) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) registerClass:NSClassFromString(cocoon::internal::to(item_class)) forItemWithIdentifier:cocoon::internal::to(identifier)];
    }

    void CollectionView::register_class(const std::string& view_class, const std::string& kind, const std::string& identifier) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) registerClass:NSClassFromString(cocoon::internal::to(view_class)) forSupplementaryViewOfKind:cocoon::internal::to(kind) withIdentifier:cocoon::internal::to(identifier)];
    }

    void CollectionView::register_nib(const Nib& nib, const std::string& identifier) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) registerNib:cocoon::internal::native<::NSNib>(nib) forItemWithIdentifier:cocoon::internal::to(identifier)];
    }

    void CollectionView::register_nib(const Nib& nib, const std::string& kind, const std::string& identifier) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) registerNib:cocoon::internal::native<::NSNib>(nib) forSupplementaryViewOfKind:cocoon::internal::to(kind) withIdentifier:cocoon::internal::to(identifier)];
    }

    void CollectionView::reload_data() const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) reloadData];
    }

    void CollectionView::reload_items_at_index_paths(const std::vector<IndexPath>& index_paths) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) reloadItemsAtIndexPaths:[NSSet setWithArray:cocoon::internal::to_array(index_paths, [](const IndexPath& e) -> id
                                                                                                                               {
                                                                                                                                   return cocoon::internal::native<::NSIndexPath>(e);
                                                                                                                               })]];
    }

    void CollectionView::reload_sections(const IndexSet& sections) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) reloadSections:cocoon::internal::native<::NSIndexSet>(sections)];
    }

    void CollectionView::scroll_to_items_at_index_paths(const std::vector<IndexPath>& index_paths, CollectionViewScrollPosition scroll_position) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) scrollToItemsAtIndexPaths:[NSSet setWithArray:cocoon::internal::to_array(index_paths, [](const IndexPath& e) -> id
                                                                                                                                 {
                                                                                                                                     return cocoon::internal::native<::NSIndexPath>(e);
                                                                                                                                 })]
                                                                   scrollPosition:static_cast<::NSCollectionViewScrollPosition>(scroll_position)];
    }

    void CollectionView::select_all(const Object& sender) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) selectAll:cocoon::internal::native_id(sender)];
    }

    void CollectionView::select_items_at_index_paths(const std::vector<IndexPath>& index_paths, CollectionViewScrollPosition scroll_position) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) selectItemsAtIndexPaths:[NSSet setWithArray:cocoon::internal::to_array(index_paths, [](const IndexPath& e) -> id
                                                                                                                               {
                                                                                                                                   return cocoon::internal::native<::NSIndexPath>(e);
                                                                                                                               })]
                                                                 scrollPosition:static_cast<::NSCollectionViewScrollPosition>(scroll_position)];
    }

    void CollectionView::set_dragging_source_operation_mask(DragOperation drag_operation_mask, bool local_destination) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) setDraggingSourceOperationMask:static_cast<::NSDragOperation>(drag_operation_mask) forLocal:static_cast<::BOOL>(local_destination)];
    }

    View CollectionView::supplementary_view_for_element_kind(const std::string& element_kind, const IndexPath& index_path) const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSCollectionView>(this) supplementaryViewForElementKind:cocoon::internal::to(element_kind) atIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    void CollectionView::toggle_section_collapse(const Object& sender) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) toggleSectionCollapse:cocoon::internal::native_id(sender)];
    }

    std::vector<CollectionViewItem> CollectionView::visible_items() const
    {
        return cocoon::internal::from_array<CollectionViewItem>([cocoon::internal::ns<::NSCollectionView>(this) visibleItems], [](id e) -> CollectionViewItem
                                                                {
                                                                    return cocoon::internal::wrap<CollectionViewItem>((::NSCollectionViewItem*)e);
                                                                });
    }

    std::vector<View> CollectionView::visible_supplementary_views_of_kind(const std::string& element_kind) const
    {
        return cocoon::internal::from_array<View>([cocoon::internal::ns<::NSCollectionView>(this) visibleSupplementaryViewsOfKind:cocoon::internal::to(element_kind)], [](id e) -> View
                                                  {
                                                      return cocoon::internal::wrap<View>((::NSView*)e);
                                                  });
    }

    bool CollectionView::allows_empty_selection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionView>(this) allowsEmptySelection]);
    }

    void CollectionView::set_allows_empty_selection(bool value) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) setAllowsEmptySelection:static_cast<::BOOL>(value)];
    }

    bool CollectionView::allows_multiple_selection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionView>(this) allowsMultipleSelection]);
    }

    void CollectionView::set_allows_multiple_selection(bool value) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) setAllowsMultipleSelection:static_cast<::BOOL>(value)];
    }

    std::vector<Color> CollectionView::background_colors() const
    {
        return cocoon::internal::from_array<Color>([cocoon::internal::ns<::NSCollectionView>(this) backgroundColors], [](id e) -> Color
                                                   {
                                                       return cocoon::internal::wrap<Color>((::NSColor*)e);
                                                   });
    }

    void CollectionView::set_background_colors(const std::vector<Color>& value) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) setBackgroundColors:cocoon::internal::to_array(value, [](const Color& e) -> id
                                                                                                       {
                                                                                                           return cocoon::internal::native<::NSColor>(e);
                                                                                                       })];
    }

    View CollectionView::background_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSCollectionView>(this) backgroundView]);
    }

    void CollectionView::set_background_view(const View& value) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) setBackgroundView:cocoon::internal::native<::NSView>(value)];
    }

    bool CollectionView::background_view_scrolls_with_content() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionView>(this) backgroundViewScrollsWithContent]);
    }

    void CollectionView::set_background_view_scrolls_with_content(bool value) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) setBackgroundViewScrollsWithContent:static_cast<::BOOL>(value)];
    }

    CollectionViewLayout CollectionView::collection_view_layout() const
    {
        return cocoon::internal::wrap<CollectionViewLayout>([cocoon::internal::ns<::NSCollectionView>(this) collectionViewLayout]);
    }

    void CollectionView::set_collection_view_layout(const CollectionViewLayout& value) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) setCollectionViewLayout:cocoon::internal::native<::NSCollectionViewLayout>(value)];
    }

    std::vector<Object> CollectionView::content() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSCollectionView>(this) content], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    void CollectionView::set_content(const std::vector<Object>& value) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) setContent:cocoon::internal::to_array(value, [](const Object& e) -> id
                                                                                              {
                                                                                                  return cocoon::internal::native_id(e);
                                                                                              })];
    }

    bool CollectionView::is_first_responder() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionView>(this) isFirstResponder]);
    }

    std::int64_t CollectionView::number_of_sections() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCollectionView>(this) numberOfSections]);
    }

    Object CollectionView::prefetch_data_source() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSCollectionView>(this) prefetchDataSource]);
    }

    void CollectionView::set_prefetch_data_source(const Object& value) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) setPrefetchDataSource:cocoon::internal::native_id(value)];
    }

    bool CollectionView::is_selectable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionView>(this) isSelectable]);
    }

    void CollectionView::set_selectable(bool value) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) setSelectable:static_cast<::BOOL>(value)];
    }

    std::vector<IndexPath> CollectionView::selection_index_paths() const
    {
        return cocoon::internal::from_array<IndexPath>([[cocoon::internal::ns<::NSCollectionView>(this) selectionIndexPaths] allObjects], [](id e) -> IndexPath
                                                       {
                                                           return cocoon::internal::wrap<IndexPath>((::NSIndexPath*)e);
                                                       });
    }

    void CollectionView::set_selection_index_paths(const std::vector<IndexPath>& value) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) setSelectionIndexPaths:[NSSet setWithArray:cocoon::internal::to_array(value, [](const IndexPath& e) -> id
                                                                                                                              {
                                                                                                                                  return cocoon::internal::native<::NSIndexPath>(e);
                                                                                                                              })]];
    }

    IndexSet CollectionView::selection_indexes() const
    {
        return cocoon::internal::wrap<IndexSet>([cocoon::internal::ns<::NSCollectionView>(this) selectionIndexes]);
    }

    void CollectionView::set_selection_indexes(const IndexSet& value) const
    {
        [cocoon::internal::ns<::NSCollectionView>(this) setSelectionIndexes:cocoon::internal::native<::NSIndexSet>(value)];
    }

    void CollectionView::install_data_source_delegate_(void* native)
    {
        ::NSCollectionView* host = (__bridge ::NSCollectionView*)native;
        AKCollectionViewDataSourceDelegate* delegate = [[AKCollectionViewDataSourceDelegate alloc] init];
        delegate->host = host;
        host.dataSource = delegate;
        __weak::NSCollectionView* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSCollectionView* strongHost = weakHost;
            strongHost.dataSource = nil;
            strongHost.dataSource = delegate;
        });
    }

    void CollectionView::install_delegate_delegate_(void* native)
    {
        ::NSCollectionView* host = (__bridge ::NSCollectionView*)native;
        AKCollectionViewDelegate* delegate = [[AKCollectionViewDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSCollectionView* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSCollectionView* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
