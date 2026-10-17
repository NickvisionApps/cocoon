#include "generated/outline_view.h"
#include "internal.h"

@interface AKOutlineViewDataSourceDelegate : NSObject <NSOutlineViewDataSource>
{
@public
    __weak id host;
}
@end

@implementation AKOutlineViewDataSourceDelegate

- (NSInteger)outlineView:(NSOutlineView*)outlineView numberOfChildrenOfItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, std::int64_t(cocoon::Object)>::emit((__bridge void*)strongHost, "outline_view_number_of_children_of_item", cocoon::internal::wrap<cocoon::Object>(item));
    return static_cast<::NSInteger>(__r);
}

- (id)outlineView:(NSOutlineView*)outlineView child:(NSInteger)index ofItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, cocoon::Object(std::int64_t, cocoon::Object)>::emit((__bridge void*)strongHost, "child_of_item", static_cast<std::int64_t>(index), cocoon::internal::wrap<cocoon::Object>(item));
    return cocoon::internal::native_id(__r);
}

- (BOOL)outlineView:(NSOutlineView*)outlineView isItemExpandable:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, bool(cocoon::Object)>::emit((__bridge void*)strongHost, "is_item_expandable", cocoon::internal::wrap<cocoon::Object>(item));
    return static_cast<::BOOL>(__r);
}

- (id)outlineView:(NSOutlineView*)outlineView objectValueForTableColumn:(NSTableColumn*)tableColumn byItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, cocoon::Object(cocoon::TableColumn, cocoon::Object)>::emit((__bridge void*)strongHost, "object_value_for_table_column_by_item", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), cocoon::internal::wrap<cocoon::Object>(item));
    return cocoon::internal::native_id(__r);
}

- (void)outlineView:(NSOutlineView*)outlineView setObjectValue:(id)object forTableColumn:(NSTableColumn*)tableColumn byItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::Object, cocoon::TableColumn, cocoon::Object)>::emit((__bridge void*)strongHost, "set_object_value_for_table_column_by_item", cocoon::internal::wrap<cocoon::Object>(object), cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), cocoon::internal::wrap<cocoon::Object>(item));
}

- (id)outlineView:(NSOutlineView*)outlineView itemForPersistentObject:(id)object
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, cocoon::Object(cocoon::Object)>::emit((__bridge void*)strongHost, "item_for_persistent_object", cocoon::internal::wrap<cocoon::Object>(object));
    return cocoon::internal::native_id(__r);
}

- (id)outlineView:(NSOutlineView*)outlineView persistentObjectForItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, cocoon::Object(cocoon::Object)>::emit((__bridge void*)strongHost, "persistent_object_for_item", cocoon::internal::wrap<cocoon::Object>(item));
    return cocoon::internal::native_id(__r);
}

- (void)outlineView:(NSOutlineView*)outlineView sortDescriptorsDidChange:(NSArray<NSSortDescriptor*>*)oldDescriptors
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(std::vector<cocoon::SortDescriptor>)>::emit((__bridge void*)strongHost, "sort_descriptors_did_change", cocoon::internal::from_array<cocoon::SortDescriptor>(oldDescriptors, [](id e) -> cocoon::SortDescriptor
                                                                                                                                                                                           {
                                                                                                                                                                                               return cocoon::internal::wrap<cocoon::SortDescriptor>((::NSSortDescriptor*)e);
                                                                                                                                                                                           }));
}

- (id<NSPasteboardWriting>)outlineView:(NSOutlineView*)outlineView pasteboardWriterForItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, cocoon::Object(cocoon::Object)>::emit((__bridge void*)strongHost, "pasteboard_writer_for_item", cocoon::internal::wrap<cocoon::Object>(item));
    return cocoon::internal::native_id(__r);
}

- (void)outlineView:(NSOutlineView*)outlineView draggingSession:(NSDraggingSession*)session willBeginAtPoint:(NSPoint)screenPoint forItems:(NSArray*)draggedItems
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::DraggingSession, cocoon::Point, std::vector<cocoon::Object>)>::emit((__bridge void*)strongHost, "dragging_session_will_begin_at_point_for_items", cocoon::internal::wrap<cocoon::DraggingSession>(session), cocoon::internal::from(screenPoint), cocoon::internal::from_array<cocoon::Object>(draggedItems, [](id e) -> cocoon::Object
                                                                                                                                                                                                                                                                                                         {
                                                                                                                                                                                                                                                                                                             return cocoon::internal::wrap<cocoon::Object>(e);
                                                                                                                                                                                                                                                                                                         }));
}

- (void)outlineView:(NSOutlineView*)outlineView draggingSession:(NSDraggingSession*)session endedAtPoint:(NSPoint)screenPoint operation:(NSDragOperation)operation
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::DraggingSession, cocoon::Point, cocoon::DragOperation)>::emit((__bridge void*)strongHost, "dragging_session_ended_at_point_operation", cocoon::internal::wrap<cocoon::DraggingSession>(session), cocoon::internal::from(screenPoint), static_cast<cocoon::DragOperation>(operation));
}

- (void)outlineView:(NSOutlineView*)outlineView updateDraggingItemsForDrag:(id<NSDraggingInfo>)draggingInfo
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::Object)>::emit((__bridge void*)strongHost, "update_dragging_items_for_drag", cocoon::internal::wrap<cocoon::Object>(draggingInfo));
}

- (NSDragOperation)outlineView:(NSOutlineView*)outlineView validateDrop:(id<NSDraggingInfo>)info proposedItem:(id)item proposedChildIndex:(NSInteger)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, cocoon::DragOperation(cocoon::Object, cocoon::Object, std::int64_t)>::emit((__bridge void*)strongHost, "validate_drop_proposed_item_proposed_child_index", cocoon::internal::wrap<cocoon::Object>(info), cocoon::internal::wrap<cocoon::Object>(item), static_cast<std::int64_t>(index));
    return static_cast<::NSDragOperation>(__r);
}

- (BOOL)outlineView:(NSOutlineView*)outlineView acceptDrop:(id<NSDraggingInfo>)info item:(id)item childIndex:(NSInteger)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, bool(cocoon::Object, cocoon::Object, std::int64_t)>::emit((__bridge void*)strongHost, "accept_drop_item_child_index", cocoon::internal::wrap<cocoon::Object>(info), cocoon::internal::wrap<cocoon::Object>(item), static_cast<std::int64_t>(index));
    return static_cast<::BOOL>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(outlineView:numberOfChildrenOfItem:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, std::int64_t(cocoon::Object)>::connected((__bridge void*)strongHost, "outline_view_number_of_children_of_item");
    }
    if (selector == @selector(outlineView:child:ofItem:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, cocoon::Object(std::int64_t, cocoon::Object)>::connected((__bridge void*)strongHost, "child_of_item");
    }
    if (selector == @selector(outlineView:isItemExpandable:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, bool(cocoon::Object)>::connected((__bridge void*)strongHost, "is_item_expandable");
    }
    if (selector == @selector(outlineView:objectValueForTableColumn:byItem:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, cocoon::Object(cocoon::TableColumn, cocoon::Object)>::connected((__bridge void*)strongHost, "object_value_for_table_column_by_item");
    }
    if (selector == @selector(outlineView:setObjectValue:forTableColumn:byItem:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::Object, cocoon::TableColumn, cocoon::Object)>::connected((__bridge void*)strongHost, "set_object_value_for_table_column_by_item");
    }
    if (selector == @selector(outlineView:itemForPersistentObject:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, cocoon::Object(cocoon::Object)>::connected((__bridge void*)strongHost, "item_for_persistent_object");
    }
    if (selector == @selector(outlineView:persistentObjectForItem:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, cocoon::Object(cocoon::Object)>::connected((__bridge void*)strongHost, "persistent_object_for_item");
    }
    if (selector == @selector(outlineView:sortDescriptorsDidChange:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(std::vector<cocoon::SortDescriptor>)>::connected((__bridge void*)strongHost, "sort_descriptors_did_change");
    }
    if (selector == @selector(outlineView:pasteboardWriterForItem:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, cocoon::Object(cocoon::Object)>::connected((__bridge void*)strongHost, "pasteboard_writer_for_item");
    }
    if (selector == @selector(outlineView:draggingSession:willBeginAtPoint:forItems:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::DraggingSession, cocoon::Point, std::vector<cocoon::Object>)>::connected((__bridge void*)strongHost, "dragging_session_will_begin_at_point_for_items");
    }
    if (selector == @selector(outlineView:draggingSession:endedAtPoint:operation:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::DraggingSession, cocoon::Point, cocoon::DragOperation)>::connected((__bridge void*)strongHost, "dragging_session_ended_at_point_operation");
    }
    if (selector == @selector(outlineView:updateDraggingItemsForDrag:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::Object)>::connected((__bridge void*)strongHost, "update_dragging_items_for_drag");
    }
    if (selector == @selector(outlineView:validateDrop:proposedItem:proposedChildIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, cocoon::DragOperation(cocoon::Object, cocoon::Object, std::int64_t)>::connected((__bridge void*)strongHost, "validate_drop_proposed_item_proposed_child_index");
    }
    if (selector == @selector(outlineView:acceptDrop:item:childIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, bool(cocoon::Object, cocoon::Object, std::int64_t)>::connected((__bridge void*)strongHost, "accept_drop_item_child_index");
    }
    return [super respondsToSelector:selector];
}

@end

@interface AKOutlineViewDelegate : NSObject <NSOutlineViewDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKOutlineViewDelegate

- (void)controlTextDidBeginEditing:(NSNotification*)obj
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "control_text_did_begin_editing", cocoon::internal::wrap<cocoon::Notification>(obj));
}

- (void)controlTextDidEndEditing:(NSNotification*)obj
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "control_text_did_end_editing", cocoon::internal::wrap<cocoon::Notification>(obj));
}

- (void)controlTextDidChange:(NSNotification*)obj
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "control_text_did_change", cocoon::internal::wrap<cocoon::Notification>(obj));
}

- (BOOL)control:(NSControl*)control textShouldBeginEditing:(NSText*)fieldEditor
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool(cocoon::Text)>::emit((__bridge void*)strongHost, "text_should_begin_editing", cocoon::internal::wrap<cocoon::Text>(fieldEditor));
    return static_cast<::BOOL>(__r);
}

- (BOOL)control:(NSControl*)control textShouldEndEditing:(NSText*)fieldEditor
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool(cocoon::Text)>::emit((__bridge void*)strongHost, "text_should_end_editing", cocoon::internal::wrap<cocoon::Text>(fieldEditor));
    return static_cast<::BOOL>(__r);
}

- (BOOL)control:(NSControl*)control didFailToFormatString:(NSString*)string errorDescription:(NSString*)error
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool(std::string, std::string)>::emit((__bridge void*)strongHost, "did_fail_to_format_string_error_description", cocoon::internal::from(string), cocoon::internal::from(error));
    return static_cast<::BOOL>(__r);
}

- (void)control:(NSControl*)control didFailToValidatePartialString:(NSString*)string errorDescription:(NSString*)error
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(std::string, std::string)>::emit((__bridge void*)strongHost, "did_fail_to_validate_partial_string_error_description", cocoon::internal::from(string), cocoon::internal::from(error));
}

- (BOOL)control:(NSControl*)control isValidObject:(id)obj
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool(cocoon::Object)>::emit((__bridge void*)strongHost, "is_valid_object", cocoon::internal::wrap<cocoon::Object>(obj));
    return static_cast<::BOOL>(__r);
}

- (BOOL)control:(NSControl*)control textView:(NSTextView*)textView doCommandBySelector:(SEL)commandSelector
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool(cocoon::TextView, std::string)>::emit((__bridge void*)strongHost, "text_view_do_command_by_selector", cocoon::internal::wrap<cocoon::TextView>(textView), cocoon::internal::from(NSStringFromSelector(commandSelector)));
    return static_cast<::BOOL>(__r);
}

- (NSArray<NSString*>*)control:(NSControl*)control textView:(NSTextView*)textView completions:(NSArray<NSString*>*)words forPartialWordRange:(NSRange)charRange indexOfSelectedItem:(NSInteger*)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, std::vector<std::string>(cocoon::TextView, std::vector<std::string>, cocoon::Range, std::int64_t*)>::emit((__bridge void*)strongHost, "text_view_completions_for_partial_word_range_index_of_selected_item", cocoon::internal::wrap<cocoon::TextView>(textView), cocoon::internal::from_array<std::string>(words, [](id e) -> std::string
                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                    return cocoon::internal::from((NSString*)e);
                                                                                                                                                                                                                                                                                                                                }),
                                                                                                                                                           cocoon::internal::from(charRange), (std::int64_t*)(index));
    return cocoon::internal::to_array(__r, [](const std::string& e) -> id
                        {
                            return cocoon::internal::to(e);
                        });
}

- (NSView*)outlineView:(NSOutlineView*)outlineView viewForTableColumn:(NSTableColumn*)tableColumn item:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, cocoon::View(cocoon::TableColumn, cocoon::Object)>::emit((__bridge void*)strongHost, "view_for_table_column_item", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), cocoon::internal::wrap<cocoon::Object>(item));
    return cocoon::internal::native<::NSView>(__r);
}

- (NSTableRowView*)outlineView:(NSOutlineView*)outlineView rowViewForItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, cocoon::TableRowView(cocoon::Object)>::emit((__bridge void*)strongHost, "row_view_for_item", cocoon::internal::wrap<cocoon::Object>(item));
    return cocoon::internal::native<::NSTableRowView>(__r);
}

- (void)outlineView:(NSOutlineView*)outlineView didAddRowView:(NSTableRowView*)rowView forRow:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::TableRowView, std::int64_t)>::emit((__bridge void*)strongHost, "did_add_row_view_for_row", cocoon::internal::wrap<cocoon::TableRowView>(rowView), static_cast<std::int64_t>(row));
}

- (void)outlineView:(NSOutlineView*)outlineView didRemoveRowView:(NSTableRowView*)rowView forRow:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::TableRowView, std::int64_t)>::emit((__bridge void*)strongHost, "did_remove_row_view_for_row", cocoon::internal::wrap<cocoon::TableRowView>(rowView), static_cast<std::int64_t>(row));
}

- (void)outlineView:(NSOutlineView*)outlineView willDisplayCell:(id)cell forTableColumn:(NSTableColumn*)tableColumn item:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::Object, cocoon::TableColumn, cocoon::Object)>::emit((__bridge void*)strongHost, "will_display_cell_for_table_column_item", cocoon::internal::wrap<cocoon::Object>(cell), cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), cocoon::internal::wrap<cocoon::Object>(item));
}

- (BOOL)outlineView:(NSOutlineView*)outlineView shouldEditTableColumn:(NSTableColumn*)tableColumn item:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, bool(cocoon::TableColumn, cocoon::Object)>::emit((__bridge void*)strongHost, "should_edit_table_column_item", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), cocoon::internal::wrap<cocoon::Object>(item));
    return static_cast<::BOOL>(__r);
}

- (BOOL)selectionShouldChangeInOutlineView:(NSOutlineView*)outlineView
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, bool()>::emit((__bridge void*)strongHost, "selection_should_change_in_outline_view");
    return static_cast<::BOOL>(__r);
}

- (BOOL)outlineView:(NSOutlineView*)outlineView shouldSelectItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, bool(cocoon::Object)>::emit((__bridge void*)strongHost, "should_select_item", cocoon::internal::wrap<cocoon::Object>(item));
    return static_cast<::BOOL>(__r);
}

- (NSIndexSet*)outlineView:(NSOutlineView*)outlineView selectionIndexesForProposedSelection:(NSIndexSet*)proposedSelectionIndexes
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, cocoon::IndexSet(cocoon::IndexSet)>::emit((__bridge void*)strongHost, "selection_indexes_for_proposed_selection", cocoon::internal::wrap<cocoon::IndexSet>(proposedSelectionIndexes));
    return cocoon::internal::native<::NSIndexSet>(__r);
}

- (BOOL)outlineView:(NSOutlineView*)outlineView shouldSelectTableColumn:(NSTableColumn*)tableColumn
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, bool(cocoon::TableColumn)>::emit((__bridge void*)strongHost, "should_select_table_column", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn));
    return static_cast<::BOOL>(__r);
}

- (void)outlineView:(NSOutlineView*)outlineView mouseDownInHeaderOfTableColumn:(NSTableColumn*)tableColumn
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::TableColumn)>::emit((__bridge void*)strongHost, "mouse_down_in_header_of_table_column", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn));
}

- (void)outlineView:(NSOutlineView*)outlineView didClickTableColumn:(NSTableColumn*)tableColumn
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::TableColumn)>::emit((__bridge void*)strongHost, "did_click_table_column", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn));
}

- (void)outlineView:(NSOutlineView*)outlineView didDragTableColumn:(NSTableColumn*)tableColumn
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::TableColumn)>::emit((__bridge void*)strongHost, "did_drag_table_column", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn));
}

- (NSString*)outlineView:(NSOutlineView*)outlineView toolTipForCell:(NSCell*)cell rect:(NSRectPointer)rect tableColumn:(NSTableColumn*)tableColumn item:(id)item mouseLocation:(NSPoint)mouseLocation
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, std::string(cocoon::Cell, cocoon::Rect*, cocoon::TableColumn, cocoon::Object, cocoon::Point)>::emit((__bridge void*)strongHost, "tool_tip_for_cell_rect_table_column_item_mouse_location", cocoon::internal::wrap<cocoon::Cell>(cell), (cocoon::Rect*)(rect), cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), cocoon::internal::wrap<cocoon::Object>(item), cocoon::internal::from(mouseLocation));
    return cocoon::internal::to(__r);
}

- (CGFloat)outlineView:(NSOutlineView*)outlineView heightOfRowByItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, double(cocoon::Object)>::emit((__bridge void*)strongHost, "height_of_row_by_item", cocoon::internal::wrap<cocoon::Object>(item));
    return static_cast<::CGFloat>(__r);
}

- (NSTintConfiguration*)outlineView:(NSOutlineView*)outlineView tintConfigurationForItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, cocoon::TintConfiguration(cocoon::Object)>::emit((__bridge void*)strongHost, "tint_configuration_for_item", cocoon::internal::wrap<cocoon::Object>(item));
    return cocoon::internal::native<::NSTintConfiguration>(__r);
}

- (NSString*)outlineView:(NSOutlineView*)outlineView typeSelectStringForTableColumn:(NSTableColumn*)tableColumn item:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, std::string(cocoon::TableColumn, cocoon::Object)>::emit((__bridge void*)strongHost, "type_select_string_for_table_column_item", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), cocoon::internal::wrap<cocoon::Object>(item));
    return cocoon::internal::to(__r);
}

- (id)outlineView:(NSOutlineView*)outlineView nextTypeSelectMatchFromItem:(id)startItem toItem:(id)endItem forString:(NSString*)searchString
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, cocoon::Object(cocoon::Object, cocoon::Object, std::string)>::emit((__bridge void*)strongHost, "next_type_select_match_from_item_to_item_for_string", cocoon::internal::wrap<cocoon::Object>(startItem), cocoon::internal::wrap<cocoon::Object>(endItem), cocoon::internal::from(searchString));
    return cocoon::internal::native_id(__r);
}

- (BOOL)outlineView:(NSOutlineView*)outlineView shouldTypeSelectForEvent:(NSEvent*)event withCurrentSearchString:(NSString*)searchString
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, bool(cocoon::Event, std::string)>::emit((__bridge void*)strongHost, "should_type_select_for_event_with_current_search_string", cocoon::internal::wrap<cocoon::Event>(event), cocoon::internal::from(searchString));
    return static_cast<::BOOL>(__r);
}

- (BOOL)outlineView:(NSOutlineView*)outlineView shouldShowCellExpansionForTableColumn:(NSTableColumn*)tableColumn item:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, bool(cocoon::TableColumn, cocoon::Object)>::emit((__bridge void*)strongHost, "should_show_cell_expansion_for_table_column_item", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), cocoon::internal::wrap<cocoon::Object>(item));
    return static_cast<::BOOL>(__r);
}

- (BOOL)outlineView:(NSOutlineView*)outlineView shouldTrackCell:(NSCell*)cell forTableColumn:(NSTableColumn*)tableColumn item:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, bool(cocoon::Cell, cocoon::TableColumn, cocoon::Object)>::emit((__bridge void*)strongHost, "should_track_cell_for_table_column_item", cocoon::internal::wrap<cocoon::Cell>(cell), cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), cocoon::internal::wrap<cocoon::Object>(item));
    return static_cast<::BOOL>(__r);
}

- (NSCell*)outlineView:(NSOutlineView*)outlineView dataCellForTableColumn:(NSTableColumn*)tableColumn item:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, cocoon::Cell(cocoon::TableColumn, cocoon::Object)>::emit((__bridge void*)strongHost, "data_cell_for_table_column_item", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), cocoon::internal::wrap<cocoon::Object>(item));
    return cocoon::internal::native<::NSCell>(__r);
}

- (BOOL)outlineView:(NSOutlineView*)outlineView isGroupItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, bool(cocoon::Object)>::emit((__bridge void*)strongHost, "is_group_item", cocoon::internal::wrap<cocoon::Object>(item));
    return static_cast<::BOOL>(__r);
}

- (BOOL)outlineView:(NSOutlineView*)outlineView shouldExpandItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, bool(cocoon::Object)>::emit((__bridge void*)strongHost, "should_expand_item", cocoon::internal::wrap<cocoon::Object>(item));
    return static_cast<::BOOL>(__r);
}

- (BOOL)outlineView:(NSOutlineView*)outlineView shouldCollapseItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, bool(cocoon::Object)>::emit((__bridge void*)strongHost, "should_collapse_item", cocoon::internal::wrap<cocoon::Object>(item));
    return static_cast<::BOOL>(__r);
}

- (void)outlineView:(NSOutlineView*)outlineView willDisplayOutlineCell:(id)cell forTableColumn:(NSTableColumn*)tableColumn item:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::Object, cocoon::TableColumn, cocoon::Object)>::emit((__bridge void*)strongHost, "will_display_outline_cell_for_table_column_item", cocoon::internal::wrap<cocoon::Object>(cell), cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), cocoon::internal::wrap<cocoon::Object>(item));
}

- (CGFloat)outlineView:(NSOutlineView*)outlineView sizeToFitWidthOfColumn:(NSInteger)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, double(std::int64_t)>::emit((__bridge void*)strongHost, "size_to_fit_width_of_column", static_cast<std::int64_t>(column));
    return static_cast<::CGFloat>(__r);
}

- (BOOL)outlineView:(NSOutlineView*)outlineView shouldReorderColumn:(NSInteger)columnIndex toColumn:(NSInteger)newColumnIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, bool(std::int64_t, std::int64_t)>::emit((__bridge void*)strongHost, "should_reorder_column_to_column", static_cast<std::int64_t>(columnIndex), static_cast<std::int64_t>(newColumnIndex));
    return static_cast<::BOOL>(__r);
}

- (BOOL)outlineView:(NSOutlineView*)outlineView shouldShowOutlineCellForItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, bool(cocoon::Object)>::emit((__bridge void*)strongHost, "should_show_outline_cell_for_item", cocoon::internal::wrap<cocoon::Object>(item));
    return static_cast<::BOOL>(__r);
}

- (BOOL)outlineView:(NSOutlineView*)outlineView userCanChangeVisibilityOfTableColumn:(NSTableColumn*)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::OutlineView, bool(cocoon::TableColumn)>::emit((__bridge void*)strongHost, "user_can_change_visibility_of_table_column", cocoon::internal::wrap<cocoon::TableColumn>(column));
    return static_cast<::BOOL>(__r);
}

- (void)outlineView:(NSOutlineView*)outlineView userDidChangeVisibilityOfTableColumns:(NSArray<NSTableColumn*>*)columns
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(std::vector<cocoon::TableColumn>)>::emit((__bridge void*)strongHost, "user_did_change_visibility_of_table_columns", cocoon::internal::from_array<cocoon::TableColumn>(columns, [](id e) -> cocoon::TableColumn
                                                                                                                                                                                                     {
                                                                                                                                                                                                         return cocoon::internal::wrap<cocoon::TableColumn>((::NSTableColumn*)e);
                                                                                                                                                                                                     }));
}

- (void)outlineViewSelectionDidChange:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "selection_did_change", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)outlineViewColumnDidMove:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "column_did_move", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)outlineViewColumnDidResize:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "column_did_resize", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)outlineViewSelectionIsChanging:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "selection_is_changing", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)outlineViewItemWillExpand:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "item_will_expand", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)outlineViewItemDidExpand:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "item_did_expand", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)outlineViewItemWillCollapse:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "item_will_collapse", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)outlineViewItemDidCollapse:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "item_did_collapse", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(controlTextDidBeginEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "control_text_did_begin_editing");
    }
    if (selector == @selector(controlTextDidEndEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "control_text_did_end_editing");
    }
    if (selector == @selector(controlTextDidChange:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "control_text_did_change");
    }
    if (selector == @selector(control:textShouldBeginEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool(cocoon::Text)>::connected((__bridge void*)strongHost, "text_should_begin_editing");
    }
    if (selector == @selector(control:textShouldEndEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool(cocoon::Text)>::connected((__bridge void*)strongHost, "text_should_end_editing");
    }
    if (selector == @selector(control:didFailToFormatString:errorDescription:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool(std::string, std::string)>::connected((__bridge void*)strongHost, "did_fail_to_format_string_error_description");
    }
    if (selector == @selector(control:didFailToValidatePartialString:errorDescription:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(std::string, std::string)>::connected((__bridge void*)strongHost, "did_fail_to_validate_partial_string_error_description");
    }
    if (selector == @selector(control:isValidObject:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool(cocoon::Object)>::connected((__bridge void*)strongHost, "is_valid_object");
    }
    if (selector == @selector(control:textView:doCommandBySelector:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool(cocoon::TextView, std::string)>::connected((__bridge void*)strongHost, "text_view_do_command_by_selector");
    }
    if (selector == @selector(control:textView:completions:forPartialWordRange:indexOfSelectedItem:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, std::vector<std::string>(cocoon::TextView, std::vector<std::string>, cocoon::Range, std::int64_t*)>::connected((__bridge void*)strongHost, "text_view_completions_for_partial_word_range_index_of_selected_item");
    }
    if (selector == @selector(outlineView:viewForTableColumn:item:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, cocoon::View(cocoon::TableColumn, cocoon::Object)>::connected((__bridge void*)strongHost, "view_for_table_column_item");
    }
    if (selector == @selector(outlineView:rowViewForItem:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, cocoon::TableRowView(cocoon::Object)>::connected((__bridge void*)strongHost, "row_view_for_item");
    }
    if (selector == @selector(outlineView:didAddRowView:forRow:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::TableRowView, std::int64_t)>::connected((__bridge void*)strongHost, "did_add_row_view_for_row");
    }
    if (selector == @selector(outlineView:didRemoveRowView:forRow:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::TableRowView, std::int64_t)>::connected((__bridge void*)strongHost, "did_remove_row_view_for_row");
    }
    if (selector == @selector(outlineView:willDisplayCell:forTableColumn:item:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::Object, cocoon::TableColumn, cocoon::Object)>::connected((__bridge void*)strongHost, "will_display_cell_for_table_column_item");
    }
    if (selector == @selector(outlineView:shouldEditTableColumn:item:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, bool(cocoon::TableColumn, cocoon::Object)>::connected((__bridge void*)strongHost, "should_edit_table_column_item");
    }
    if (selector == @selector(selectionShouldChangeInOutlineView:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, bool()>::connected((__bridge void*)strongHost, "selection_should_change_in_outline_view");
    }
    if (selector == @selector(outlineView:shouldSelectItem:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, bool(cocoon::Object)>::connected((__bridge void*)strongHost, "should_select_item");
    }
    if (selector == @selector(outlineView:selectionIndexesForProposedSelection:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, cocoon::IndexSet(cocoon::IndexSet)>::connected((__bridge void*)strongHost, "selection_indexes_for_proposed_selection");
    }
    if (selector == @selector(outlineView:shouldSelectTableColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, bool(cocoon::TableColumn)>::connected((__bridge void*)strongHost, "should_select_table_column");
    }
    if (selector == @selector(outlineView:mouseDownInHeaderOfTableColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::TableColumn)>::connected((__bridge void*)strongHost, "mouse_down_in_header_of_table_column");
    }
    if (selector == @selector(outlineView:didClickTableColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::TableColumn)>::connected((__bridge void*)strongHost, "did_click_table_column");
    }
    if (selector == @selector(outlineView:didDragTableColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::TableColumn)>::connected((__bridge void*)strongHost, "did_drag_table_column");
    }
    if (selector == @selector(outlineView:toolTipForCell:rect:tableColumn:item:mouseLocation:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, std::string(cocoon::Cell, cocoon::Rect*, cocoon::TableColumn, cocoon::Object, cocoon::Point)>::connected((__bridge void*)strongHost, "tool_tip_for_cell_rect_table_column_item_mouse_location");
    }
    if (selector == @selector(outlineView:heightOfRowByItem:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, double(cocoon::Object)>::connected((__bridge void*)strongHost, "height_of_row_by_item");
    }
    if (selector == @selector(outlineView:tintConfigurationForItem:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, cocoon::TintConfiguration(cocoon::Object)>::connected((__bridge void*)strongHost, "tint_configuration_for_item");
    }
    if (selector == @selector(outlineView:typeSelectStringForTableColumn:item:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, std::string(cocoon::TableColumn, cocoon::Object)>::connected((__bridge void*)strongHost, "type_select_string_for_table_column_item");
    }
    if (selector == @selector(outlineView:nextTypeSelectMatchFromItem:toItem:forString:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, cocoon::Object(cocoon::Object, cocoon::Object, std::string)>::connected((__bridge void*)strongHost, "next_type_select_match_from_item_to_item_for_string");
    }
    if (selector == @selector(outlineView:shouldTypeSelectForEvent:withCurrentSearchString:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, bool(cocoon::Event, std::string)>::connected((__bridge void*)strongHost, "should_type_select_for_event_with_current_search_string");
    }
    if (selector == @selector(outlineView:shouldShowCellExpansionForTableColumn:item:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, bool(cocoon::TableColumn, cocoon::Object)>::connected((__bridge void*)strongHost, "should_show_cell_expansion_for_table_column_item");
    }
    if (selector == @selector(outlineView:shouldTrackCell:forTableColumn:item:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, bool(cocoon::Cell, cocoon::TableColumn, cocoon::Object)>::connected((__bridge void*)strongHost, "should_track_cell_for_table_column_item");
    }
    if (selector == @selector(outlineView:dataCellForTableColumn:item:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, cocoon::Cell(cocoon::TableColumn, cocoon::Object)>::connected((__bridge void*)strongHost, "data_cell_for_table_column_item");
    }
    if (selector == @selector(outlineView:isGroupItem:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, bool(cocoon::Object)>::connected((__bridge void*)strongHost, "is_group_item");
    }
    if (selector == @selector(outlineView:shouldExpandItem:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, bool(cocoon::Object)>::connected((__bridge void*)strongHost, "should_expand_item");
    }
    if (selector == @selector(outlineView:shouldCollapseItem:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, bool(cocoon::Object)>::connected((__bridge void*)strongHost, "should_collapse_item");
    }
    if (selector == @selector(outlineView:willDisplayOutlineCell:forTableColumn:item:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::Object, cocoon::TableColumn, cocoon::Object)>::connected((__bridge void*)strongHost, "will_display_outline_cell_for_table_column_item");
    }
    if (selector == @selector(outlineView:sizeToFitWidthOfColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, double(std::int64_t)>::connected((__bridge void*)strongHost, "size_to_fit_width_of_column");
    }
    if (selector == @selector(outlineView:shouldReorderColumn:toColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, bool(std::int64_t, std::int64_t)>::connected((__bridge void*)strongHost, "should_reorder_column_to_column");
    }
    if (selector == @selector(outlineView:shouldShowOutlineCellForItem:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, bool(cocoon::Object)>::connected((__bridge void*)strongHost, "should_show_outline_cell_for_item");
    }
    if (selector == @selector(outlineView:userCanChangeVisibilityOfTableColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, bool(cocoon::TableColumn)>::connected((__bridge void*)strongHost, "user_can_change_visibility_of_table_column");
    }
    if (selector == @selector(outlineView:userDidChangeVisibilityOfTableColumns:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(std::vector<cocoon::TableColumn>)>::connected((__bridge void*)strongHost, "user_did_change_visibility_of_table_columns");
    }
    if (selector == @selector(outlineViewSelectionDidChange:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "selection_did_change");
    }
    if (selector == @selector(outlineViewColumnDidMove:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "column_did_move");
    }
    if (selector == @selector(outlineViewColumnDidResize:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "column_did_resize");
    }
    if (selector == @selector(outlineViewSelectionIsChanging:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "selection_is_changing");
    }
    if (selector == @selector(outlineViewItemWillExpand:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "item_will_expand");
    }
    if (selector == @selector(outlineViewItemDidExpand:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "item_did_expand");
    }
    if (selector == @selector(outlineViewItemWillCollapse:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "item_will_collapse");
    }
    if (selector == @selector(outlineViewItemDidCollapse:))
    {
        return strongHost && cocoon::Signal<cocoon::OutlineView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "item_did_collapse");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    OutlineView::OutlineView() : OutlineView(Adopt{cocoon::internal::retain([[::NSOutlineView alloc] init])})
    {
        OutlineView::install_data_source_delegate_(handle());
        OutlineView::install_delegate_delegate_(handle());
    }

    OutlineView::OutlineView(std::nullptr_t) : TableView(nullptr)
    {
    }

    OutlineView::OutlineView(Adopt adopt) : TableView(adopt)
    {
    }

    Object OutlineView::child(std::int64_t index, const Object& item) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSOutlineView>(this) child:static_cast<::NSInteger>(index) ofItem:cocoon::internal::native_id(item)]);
    }

    std::int64_t OutlineView::child_index_for_item(const Object& item) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSOutlineView>(this) childIndexForItem:cocoon::internal::native_id(item)]);
    }

    void OutlineView::collapse_item(const Object& item) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) collapseItem:cocoon::internal::native_id(item)];
    }

    void OutlineView::collapse_item(const Object& item, bool collapse_children) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) collapseItem:cocoon::internal::native_id(item) collapseChildren:static_cast<::BOOL>(collapse_children)];
    }

    void OutlineView::expand_item(const Object& item) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) expandItem:cocoon::internal::native_id(item)];
    }

    void OutlineView::expand_item(const Object& item, bool expand_children) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) expandItem:cocoon::internal::native_id(item) expandChildren:static_cast<::BOOL>(expand_children)];
    }

    Rect OutlineView::frame_of_outline_cell_at_row(std::int64_t row) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSOutlineView>(this) frameOfOutlineCellAtRow:static_cast<::NSInteger>(row)]);
    }

    void OutlineView::insert_items_at_indexes(const IndexSet& indexes, const Object& parent, TableViewAnimationOptions animation_options) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) insertItemsAtIndexes:cocoon::internal::native<::NSIndexSet>(indexes) inParent:cocoon::internal::native_id(parent) withAnimation:static_cast<::NSTableViewAnimationOptions>(animation_options)];
    }

    bool OutlineView::is_expandable(const Object& item) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOutlineView>(this) isExpandable:cocoon::internal::native_id(item)]);
    }

    bool OutlineView::is_item_expanded(const Object& item) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOutlineView>(this) isItemExpanded:cocoon::internal::native_id(item)]);
    }

    Object OutlineView::item_at_row(std::int64_t row) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSOutlineView>(this) itemAtRow:static_cast<::NSInteger>(row)]);
    }

    std::int64_t OutlineView::level_for_item(const Object& item) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSOutlineView>(this) levelForItem:cocoon::internal::native_id(item)]);
    }

    std::int64_t OutlineView::level_for_row(std::int64_t row) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSOutlineView>(this) levelForRow:static_cast<::NSInteger>(row)]);
    }

    void OutlineView::move_item_at_index(std::int64_t from_index, const Object& old_parent, std::int64_t to_index, const Object& new_parent) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) moveItemAtIndex:static_cast<::NSInteger>(from_index) inParent:cocoon::internal::native_id(old_parent) toIndex:static_cast<::NSInteger>(to_index) inParent:cocoon::internal::native_id(new_parent)];
    }

    std::int64_t OutlineView::number_of_children_of_item(const Object& item) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSOutlineView>(this) numberOfChildrenOfItem:cocoon::internal::native_id(item)]);
    }

    Object OutlineView::parent_for_item(const Object& item) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSOutlineView>(this) parentForItem:cocoon::internal::native_id(item)]);
    }

    void OutlineView::reload_item(const Object& item) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) reloadItem:cocoon::internal::native_id(item)];
    }

    void OutlineView::reload_item(const Object& item, bool reload_children) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) reloadItem:cocoon::internal::native_id(item) reloadChildren:static_cast<::BOOL>(reload_children)];
    }

    void OutlineView::remove_items_at_indexes(const IndexSet& indexes, const Object& parent, TableViewAnimationOptions animation_options) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) removeItemsAtIndexes:cocoon::internal::native<::NSIndexSet>(indexes) inParent:cocoon::internal::native_id(parent) withAnimation:static_cast<::NSTableViewAnimationOptions>(animation_options)];
    }

    std::int64_t OutlineView::row_for_item(const Object& item) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSOutlineView>(this) rowForItem:cocoon::internal::native_id(item)]);
    }

    void OutlineView::set_drop_item(const Object& item, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) setDropItem:cocoon::internal::native_id(item) dropChildIndex:static_cast<::NSInteger>(index)];
    }

    bool OutlineView::should_collapse_auto_expanded_items_for_deposited(bool deposited) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOutlineView>(this) shouldCollapseAutoExpandedItemsForDeposited:static_cast<::BOOL>(deposited)]);
    }

    bool OutlineView::autoresizes_outline_column() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOutlineView>(this) autoresizesOutlineColumn]);
    }

    void OutlineView::set_autoresizes_outline_column(bool value) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) setAutoresizesOutlineColumn:static_cast<::BOOL>(value)];
    }

    bool OutlineView::autosave_expanded_items() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOutlineView>(this) autosaveExpandedItems]);
    }

    void OutlineView::set_autosave_expanded_items(bool value) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) setAutosaveExpandedItems:static_cast<::BOOL>(value)];
    }

    bool OutlineView::indentation_marker_follows_cell() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOutlineView>(this) indentationMarkerFollowsCell]);
    }

    void OutlineView::set_indentation_marker_follows_cell(bool value) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) setIndentationMarkerFollowsCell:static_cast<::BOOL>(value)];
    }

    double OutlineView::indentation_per_level() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSOutlineView>(this) indentationPerLevel]);
    }

    void OutlineView::set_indentation_per_level(double value) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) setIndentationPerLevel:static_cast<::CGFloat>(value)];
    }

    TableColumn OutlineView::outline_table_column() const
    {
        return cocoon::internal::wrap<TableColumn>([cocoon::internal::ns<::NSOutlineView>(this) outlineTableColumn]);
    }

    void OutlineView::set_outline_table_column(const TableColumn& value) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) setOutlineTableColumn:cocoon::internal::native<::NSTableColumn>(value)];
    }

    bool OutlineView::strongly_references_items() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOutlineView>(this) stronglyReferencesItems]);
    }

    void OutlineView::set_strongly_references_items(bool value) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) setStronglyReferencesItems:static_cast<::BOOL>(value)];
    }

    UserInterfaceLayoutDirection OutlineView::user_interface_layout_direction() const
    {
        return static_cast<UserInterfaceLayoutDirection>([cocoon::internal::ns<::NSOutlineView>(this) userInterfaceLayoutDirection]);
    }

    void OutlineView::set_user_interface_layout_direction(UserInterfaceLayoutDirection value) const
    {
        [cocoon::internal::ns<::NSOutlineView>(this) setUserInterfaceLayoutDirection:static_cast<::NSUserInterfaceLayoutDirection>(value)];
    }

    void OutlineView::install_data_source_delegate_(void* native)
    {
        ::NSOutlineView* host = (__bridge ::NSOutlineView*)native;
        AKOutlineViewDataSourceDelegate* delegate = [[AKOutlineViewDataSourceDelegate alloc] init];
        delegate->host = host;
        host.dataSource = delegate;
        __weak::NSOutlineView* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSOutlineView* strongHost = weakHost;
            strongHost.dataSource = nil;
            strongHost.dataSource = delegate;
        });
    }

    void OutlineView::install_delegate_delegate_(void* native)
    {
        ::NSOutlineView* host = (__bridge ::NSOutlineView*)native;
        AKOutlineViewDelegate* delegate = [[AKOutlineViewDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSOutlineView* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSOutlineView* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
