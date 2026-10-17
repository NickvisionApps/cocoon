#include "generated/table_view.h"
#include "internal.h"

@interface AKTableViewDataSourceDelegate : NSObject <NSTableViewDataSource>
{
@public
    __weak id host;
}
@end

@implementation AKTableViewDataSourceDelegate

- (NSInteger)numberOfRowsInTableView:(NSTableView*)tableView
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, std::int64_t()>::emit((__bridge void*)strongHost, "number_of_rows_in_table_view");
    return static_cast<::NSInteger>(__r);
}

- (id)tableView:(NSTableView*)tableView objectValueForTableColumn:(NSTableColumn*)tableColumn row:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, cocoon::Object(cocoon::TableColumn, std::int64_t)>::emit((__bridge void*)strongHost, "object_value_for_table_column_row", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), static_cast<std::int64_t>(row));
    return cocoon::internal::native_id(__r);
}

- (void)tableView:(NSTableView*)tableView setObjectValue:(id)object forTableColumn:(NSTableColumn*)tableColumn row:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::Object, cocoon::TableColumn, std::int64_t)>::emit((__bridge void*)strongHost, "set_object_value_for_table_column_row", cocoon::internal::wrap<cocoon::Object>(object), cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), static_cast<std::int64_t>(row));
}

- (void)tableView:(NSTableView*)tableView sortDescriptorsDidChange:(NSArray<NSSortDescriptor*>*)oldDescriptors
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(std::vector<cocoon::SortDescriptor>)>::emit((__bridge void*)strongHost, "sort_descriptors_did_change", cocoon::internal::from_array<cocoon::SortDescriptor>(oldDescriptors, [](id e) -> cocoon::SortDescriptor
                                                                                                                                                                                         {
                                                                                                                                                                                             return cocoon::internal::wrap<cocoon::SortDescriptor>((::NSSortDescriptor*)e);
                                                                                                                                                                                         }));
}

- (id<NSPasteboardWriting>)tableView:(NSTableView*)tableView pasteboardWriterForRow:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, cocoon::Object(std::int64_t)>::emit((__bridge void*)strongHost, "pasteboard_writer_for_row", static_cast<std::int64_t>(row));
    return cocoon::internal::native_id(__r);
}

- (void)tableView:(NSTableView*)tableView draggingSession:(NSDraggingSession*)session willBeginAtPoint:(NSPoint)screenPoint forRowIndexes:(NSIndexSet*)rowIndexes
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::DraggingSession, cocoon::Point, cocoon::IndexSet)>::emit((__bridge void*)strongHost, "dragging_session_will_begin_at_point_for_row_indexes", cocoon::internal::wrap<cocoon::DraggingSession>(session), cocoon::internal::from(screenPoint), cocoon::internal::wrap<cocoon::IndexSet>(rowIndexes));
}

- (void)tableView:(NSTableView*)tableView draggingSession:(NSDraggingSession*)session endedAtPoint:(NSPoint)screenPoint operation:(NSDragOperation)operation
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::DraggingSession, cocoon::Point, cocoon::DragOperation)>::emit((__bridge void*)strongHost, "dragging_session_ended_at_point_operation", cocoon::internal::wrap<cocoon::DraggingSession>(session), cocoon::internal::from(screenPoint), static_cast<cocoon::DragOperation>(operation));
}

- (void)tableView:(NSTableView*)tableView updateDraggingItemsForDrag:(id<NSDraggingInfo>)draggingInfo
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::Object)>::emit((__bridge void*)strongHost, "update_dragging_items_for_drag", cocoon::internal::wrap<cocoon::Object>(draggingInfo));
}

- (NSDragOperation)tableView:(NSTableView*)tableView validateDrop:(id<NSDraggingInfo>)info proposedRow:(NSInteger)row proposedDropOperation:(NSTableViewDropOperation)dropOperation
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, cocoon::DragOperation(cocoon::Object, std::int64_t, cocoon::TableViewDropOperation)>::emit((__bridge void*)strongHost, "validate_drop_proposed_row_proposed_drop_operation", cocoon::internal::wrap<cocoon::Object>(info), static_cast<std::int64_t>(row), static_cast<cocoon::TableViewDropOperation>(dropOperation));
    return static_cast<::NSDragOperation>(__r);
}

- (BOOL)tableView:(NSTableView*)tableView acceptDrop:(id<NSDraggingInfo>)info row:(NSInteger)row dropOperation:(NSTableViewDropOperation)dropOperation
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool(cocoon::Object, std::int64_t, cocoon::TableViewDropOperation)>::emit((__bridge void*)strongHost, "accept_drop_row_drop_operation", cocoon::internal::wrap<cocoon::Object>(info), static_cast<std::int64_t>(row), static_cast<cocoon::TableViewDropOperation>(dropOperation));
    return static_cast<::BOOL>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(numberOfRowsInTableView:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, std::int64_t()>::connected((__bridge void*)strongHost, "number_of_rows_in_table_view");
    }
    if (selector == @selector(tableView:objectValueForTableColumn:row:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, cocoon::Object(cocoon::TableColumn, std::int64_t)>::connected((__bridge void*)strongHost, "object_value_for_table_column_row");
    }
    if (selector == @selector(tableView:setObjectValue:forTableColumn:row:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::Object, cocoon::TableColumn, std::int64_t)>::connected((__bridge void*)strongHost, "set_object_value_for_table_column_row");
    }
    if (selector == @selector(tableView:sortDescriptorsDidChange:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(std::vector<cocoon::SortDescriptor>)>::connected((__bridge void*)strongHost, "sort_descriptors_did_change");
    }
    if (selector == @selector(tableView:pasteboardWriterForRow:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, cocoon::Object(std::int64_t)>::connected((__bridge void*)strongHost, "pasteboard_writer_for_row");
    }
    if (selector == @selector(tableView:draggingSession:willBeginAtPoint:forRowIndexes:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::DraggingSession, cocoon::Point, cocoon::IndexSet)>::connected((__bridge void*)strongHost, "dragging_session_will_begin_at_point_for_row_indexes");
    }
    if (selector == @selector(tableView:draggingSession:endedAtPoint:operation:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::DraggingSession, cocoon::Point, cocoon::DragOperation)>::connected((__bridge void*)strongHost, "dragging_session_ended_at_point_operation");
    }
    if (selector == @selector(tableView:updateDraggingItemsForDrag:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::Object)>::connected((__bridge void*)strongHost, "update_dragging_items_for_drag");
    }
    if (selector == @selector(tableView:validateDrop:proposedRow:proposedDropOperation:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, cocoon::DragOperation(cocoon::Object, std::int64_t, cocoon::TableViewDropOperation)>::connected((__bridge void*)strongHost, "validate_drop_proposed_row_proposed_drop_operation");
    }
    if (selector == @selector(tableView:acceptDrop:row:dropOperation:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool(cocoon::Object, std::int64_t, cocoon::TableViewDropOperation)>::connected((__bridge void*)strongHost, "accept_drop_row_drop_operation");
    }
    return [super respondsToSelector:selector];
}

@end

@interface AKTableViewDelegate : NSObject <NSTableViewDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKTableViewDelegate

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

- (NSView*)tableView:(NSTableView*)tableView viewForTableColumn:(NSTableColumn*)tableColumn row:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, cocoon::View(cocoon::TableColumn, std::int64_t)>::emit((__bridge void*)strongHost, "view_for_table_column_row", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), static_cast<std::int64_t>(row));
    return cocoon::internal::native<::NSView>(__r);
}

- (NSTableRowView*)tableView:(NSTableView*)tableView rowViewForRow:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, cocoon::TableRowView(std::int64_t)>::emit((__bridge void*)strongHost, "row_view_for_row", static_cast<std::int64_t>(row));
    return cocoon::internal::native<::NSTableRowView>(__r);
}

- (void)tableView:(NSTableView*)tableView didAddRowView:(NSTableRowView*)rowView forRow:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::TableRowView, std::int64_t)>::emit((__bridge void*)strongHost, "did_add_row_view_for_row", cocoon::internal::wrap<cocoon::TableRowView>(rowView), static_cast<std::int64_t>(row));
}

- (void)tableView:(NSTableView*)tableView didRemoveRowView:(NSTableRowView*)rowView forRow:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::TableRowView, std::int64_t)>::emit((__bridge void*)strongHost, "did_remove_row_view_for_row", cocoon::internal::wrap<cocoon::TableRowView>(rowView), static_cast<std::int64_t>(row));
}

- (void)tableView:(NSTableView*)tableView willDisplayCell:(id)cell forTableColumn:(NSTableColumn*)tableColumn row:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::Object, cocoon::TableColumn, std::int64_t)>::emit((__bridge void*)strongHost, "will_display_cell_for_table_column_row", cocoon::internal::wrap<cocoon::Object>(cell), cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), static_cast<std::int64_t>(row));
}

- (BOOL)tableView:(NSTableView*)tableView shouldEditTableColumn:(NSTableColumn*)tableColumn row:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool(cocoon::TableColumn, std::int64_t)>::emit((__bridge void*)strongHost, "should_edit_table_column_row", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), static_cast<std::int64_t>(row));
    return static_cast<::BOOL>(__r);
}

- (NSString*)tableView:(NSTableView*)tableView toolTipForCell:(NSCell*)cell rect:(NSRectPointer)rect tableColumn:(NSTableColumn*)tableColumn row:(NSInteger)row mouseLocation:(NSPoint)mouseLocation
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, std::string(cocoon::Cell, cocoon::Rect*, cocoon::TableColumn, std::int64_t, cocoon::Point)>::emit((__bridge void*)strongHost, "tool_tip_for_cell_rect_table_column_row_mouse_location", cocoon::internal::wrap<cocoon::Cell>(cell), (cocoon::Rect*)(rect), cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), static_cast<std::int64_t>(row), cocoon::internal::from(mouseLocation));
    return cocoon::internal::to(__r);
}

- (BOOL)tableView:(NSTableView*)tableView shouldShowCellExpansionForTableColumn:(NSTableColumn*)tableColumn row:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool(cocoon::TableColumn, std::int64_t)>::emit((__bridge void*)strongHost, "should_show_cell_expansion_for_table_column_row", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), static_cast<std::int64_t>(row));
    return static_cast<::BOOL>(__r);
}

- (BOOL)tableView:(NSTableView*)tableView shouldTrackCell:(NSCell*)cell forTableColumn:(NSTableColumn*)tableColumn row:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool(cocoon::Cell, cocoon::TableColumn, std::int64_t)>::emit((__bridge void*)strongHost, "should_track_cell_for_table_column_row", cocoon::internal::wrap<cocoon::Cell>(cell), cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), static_cast<std::int64_t>(row));
    return static_cast<::BOOL>(__r);
}

- (NSCell*)tableView:(NSTableView*)tableView dataCellForTableColumn:(NSTableColumn*)tableColumn row:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, cocoon::Cell(cocoon::TableColumn, std::int64_t)>::emit((__bridge void*)strongHost, "data_cell_for_table_column_row", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), static_cast<std::int64_t>(row));
    return cocoon::internal::native<::NSCell>(__r);
}

- (BOOL)selectionShouldChangeInTableView:(NSTableView*)tableView
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool()>::emit((__bridge void*)strongHost, "selection_should_change_in_table_view");
    return static_cast<::BOOL>(__r);
}

- (BOOL)tableView:(NSTableView*)tableView shouldSelectRow:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool(std::int64_t)>::emit((__bridge void*)strongHost, "should_select_row", static_cast<std::int64_t>(row));
    return static_cast<::BOOL>(__r);
}

- (NSIndexSet*)tableView:(NSTableView*)tableView selectionIndexesForProposedSelection:(NSIndexSet*)proposedSelectionIndexes
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, cocoon::IndexSet(cocoon::IndexSet)>::emit((__bridge void*)strongHost, "selection_indexes_for_proposed_selection", cocoon::internal::wrap<cocoon::IndexSet>(proposedSelectionIndexes));
    return cocoon::internal::native<::NSIndexSet>(__r);
}

- (BOOL)tableView:(NSTableView*)tableView shouldSelectTableColumn:(NSTableColumn*)tableColumn
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool(cocoon::TableColumn)>::emit((__bridge void*)strongHost, "should_select_table_column", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn));
    return static_cast<::BOOL>(__r);
}

- (void)tableView:(NSTableView*)tableView mouseDownInHeaderOfTableColumn:(NSTableColumn*)tableColumn
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::TableColumn)>::emit((__bridge void*)strongHost, "mouse_down_in_header_of_table_column", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn));
}

- (void)tableView:(NSTableView*)tableView didClickTableColumn:(NSTableColumn*)tableColumn
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::TableColumn)>::emit((__bridge void*)strongHost, "did_click_table_column", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn));
}

- (void)tableView:(NSTableView*)tableView didDragTableColumn:(NSTableColumn*)tableColumn
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::TableColumn)>::emit((__bridge void*)strongHost, "did_drag_table_column", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn));
}

- (CGFloat)tableView:(NSTableView*)tableView heightOfRow:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, double(std::int64_t)>::emit((__bridge void*)strongHost, "height_of_row", static_cast<std::int64_t>(row));
    return static_cast<::CGFloat>(__r);
}

- (NSString*)tableView:(NSTableView*)tableView typeSelectStringForTableColumn:(NSTableColumn*)tableColumn row:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, std::string(cocoon::TableColumn, std::int64_t)>::emit((__bridge void*)strongHost, "type_select_string_for_table_column_row", cocoon::internal::wrap<cocoon::TableColumn>(tableColumn), static_cast<std::int64_t>(row));
    return cocoon::internal::to(__r);
}

- (NSInteger)tableView:(NSTableView*)tableView nextTypeSelectMatchFromRow:(NSInteger)startRow toRow:(NSInteger)endRow forString:(NSString*)searchString
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, std::int64_t(std::int64_t, std::int64_t, std::string)>::emit((__bridge void*)strongHost, "next_type_select_match_from_row_to_row_for_string", static_cast<std::int64_t>(startRow), static_cast<std::int64_t>(endRow), cocoon::internal::from(searchString));
    return static_cast<::NSInteger>(__r);
}

- (BOOL)tableView:(NSTableView*)tableView shouldTypeSelectForEvent:(NSEvent*)event withCurrentSearchString:(NSString*)searchString
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool(cocoon::Event, std::string)>::emit((__bridge void*)strongHost, "should_type_select_for_event_with_current_search_string", cocoon::internal::wrap<cocoon::Event>(event), cocoon::internal::from(searchString));
    return static_cast<::BOOL>(__r);
}

- (BOOL)tableView:(NSTableView*)tableView isGroupRow:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool(std::int64_t)>::emit((__bridge void*)strongHost, "is_group_row", static_cast<std::int64_t>(row));
    return static_cast<::BOOL>(__r);
}

- (CGFloat)tableView:(NSTableView*)tableView sizeToFitWidthOfColumn:(NSInteger)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, double(std::int64_t)>::emit((__bridge void*)strongHost, "size_to_fit_width_of_column", static_cast<std::int64_t>(column));
    return static_cast<::CGFloat>(__r);
}

- (BOOL)tableView:(NSTableView*)tableView shouldReorderColumn:(NSInteger)columnIndex toColumn:(NSInteger)newColumnIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool(std::int64_t, std::int64_t)>::emit((__bridge void*)strongHost, "should_reorder_column_to_column", static_cast<std::int64_t>(columnIndex), static_cast<std::int64_t>(newColumnIndex));
    return static_cast<::BOOL>(__r);
}

- (NSArray<NSTableViewRowAction*>*)tableView:(NSTableView*)tableView rowActionsForRow:(NSInteger)row edge:(NSTableRowActionEdge)edge
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, std::vector<cocoon::TableViewRowAction>(std::int64_t, cocoon::TableRowActionEdge)>::emit((__bridge void*)strongHost, "row_actions_for_row_edge", static_cast<std::int64_t>(row), static_cast<cocoon::TableRowActionEdge>(edge));
    return cocoon::internal::to_array(__r, [](const cocoon::TableViewRowAction& e) -> id
                        {
                            return cocoon::internal::native<::NSTableViewRowAction>(e);
                        });
}

- (BOOL)tableView:(NSTableView*)tableView userCanChangeVisibilityOfTableColumn:(NSTableColumn*)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TableView, bool(cocoon::TableColumn)>::emit((__bridge void*)strongHost, "user_can_change_visibility_of_table_column", cocoon::internal::wrap<cocoon::TableColumn>(column));
    return static_cast<::BOOL>(__r);
}

- (void)tableView:(NSTableView*)tableView userDidChangeVisibilityOfTableColumns:(NSArray<NSTableColumn*>*)columns
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(std::vector<cocoon::TableColumn>)>::emit((__bridge void*)strongHost, "user_did_change_visibility_of_table_columns", cocoon::internal::from_array<cocoon::TableColumn>(columns, [](id e) -> cocoon::TableColumn
                                                                                                                                                                                                   {
                                                                                                                                                                                                       return cocoon::internal::wrap<cocoon::TableColumn>((::NSTableColumn*)e);
                                                                                                                                                                                                   }));
}

- (void)tableViewSelectionDidChange:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "selection_did_change", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)tableViewColumnDidMove:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "column_did_move", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)tableViewColumnDidResize:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "column_did_resize", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)tableViewSelectionIsChanging:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TableView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "selection_is_changing", cocoon::internal::wrap<cocoon::Notification>(notification));
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
    if (selector == @selector(tableView:viewForTableColumn:row:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, cocoon::View(cocoon::TableColumn, std::int64_t)>::connected((__bridge void*)strongHost, "view_for_table_column_row");
    }
    if (selector == @selector(tableView:rowViewForRow:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, cocoon::TableRowView(std::int64_t)>::connected((__bridge void*)strongHost, "row_view_for_row");
    }
    if (selector == @selector(tableView:didAddRowView:forRow:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::TableRowView, std::int64_t)>::connected((__bridge void*)strongHost, "did_add_row_view_for_row");
    }
    if (selector == @selector(tableView:didRemoveRowView:forRow:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::TableRowView, std::int64_t)>::connected((__bridge void*)strongHost, "did_remove_row_view_for_row");
    }
    if (selector == @selector(tableView:willDisplayCell:forTableColumn:row:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::Object, cocoon::TableColumn, std::int64_t)>::connected((__bridge void*)strongHost, "will_display_cell_for_table_column_row");
    }
    if (selector == @selector(tableView:shouldEditTableColumn:row:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool(cocoon::TableColumn, std::int64_t)>::connected((__bridge void*)strongHost, "should_edit_table_column_row");
    }
    if (selector == @selector(tableView:toolTipForCell:rect:tableColumn:row:mouseLocation:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, std::string(cocoon::Cell, cocoon::Rect*, cocoon::TableColumn, std::int64_t, cocoon::Point)>::connected((__bridge void*)strongHost, "tool_tip_for_cell_rect_table_column_row_mouse_location");
    }
    if (selector == @selector(tableView:shouldShowCellExpansionForTableColumn:row:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool(cocoon::TableColumn, std::int64_t)>::connected((__bridge void*)strongHost, "should_show_cell_expansion_for_table_column_row");
    }
    if (selector == @selector(tableView:shouldTrackCell:forTableColumn:row:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool(cocoon::Cell, cocoon::TableColumn, std::int64_t)>::connected((__bridge void*)strongHost, "should_track_cell_for_table_column_row");
    }
    if (selector == @selector(tableView:dataCellForTableColumn:row:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, cocoon::Cell(cocoon::TableColumn, std::int64_t)>::connected((__bridge void*)strongHost, "data_cell_for_table_column_row");
    }
    if (selector == @selector(selectionShouldChangeInTableView:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool()>::connected((__bridge void*)strongHost, "selection_should_change_in_table_view");
    }
    if (selector == @selector(tableView:shouldSelectRow:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool(std::int64_t)>::connected((__bridge void*)strongHost, "should_select_row");
    }
    if (selector == @selector(tableView:selectionIndexesForProposedSelection:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, cocoon::IndexSet(cocoon::IndexSet)>::connected((__bridge void*)strongHost, "selection_indexes_for_proposed_selection");
    }
    if (selector == @selector(tableView:shouldSelectTableColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool(cocoon::TableColumn)>::connected((__bridge void*)strongHost, "should_select_table_column");
    }
    if (selector == @selector(tableView:mouseDownInHeaderOfTableColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::TableColumn)>::connected((__bridge void*)strongHost, "mouse_down_in_header_of_table_column");
    }
    if (selector == @selector(tableView:didClickTableColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::TableColumn)>::connected((__bridge void*)strongHost, "did_click_table_column");
    }
    if (selector == @selector(tableView:didDragTableColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::TableColumn)>::connected((__bridge void*)strongHost, "did_drag_table_column");
    }
    if (selector == @selector(tableView:heightOfRow:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, double(std::int64_t)>::connected((__bridge void*)strongHost, "height_of_row");
    }
    if (selector == @selector(tableView:typeSelectStringForTableColumn:row:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, std::string(cocoon::TableColumn, std::int64_t)>::connected((__bridge void*)strongHost, "type_select_string_for_table_column_row");
    }
    if (selector == @selector(tableView:nextTypeSelectMatchFromRow:toRow:forString:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, std::int64_t(std::int64_t, std::int64_t, std::string)>::connected((__bridge void*)strongHost, "next_type_select_match_from_row_to_row_for_string");
    }
    if (selector == @selector(tableView:shouldTypeSelectForEvent:withCurrentSearchString:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool(cocoon::Event, std::string)>::connected((__bridge void*)strongHost, "should_type_select_for_event_with_current_search_string");
    }
    if (selector == @selector(tableView:isGroupRow:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool(std::int64_t)>::connected((__bridge void*)strongHost, "is_group_row");
    }
    if (selector == @selector(tableView:sizeToFitWidthOfColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, double(std::int64_t)>::connected((__bridge void*)strongHost, "size_to_fit_width_of_column");
    }
    if (selector == @selector(tableView:shouldReorderColumn:toColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool(std::int64_t, std::int64_t)>::connected((__bridge void*)strongHost, "should_reorder_column_to_column");
    }
    if (selector == @selector(tableView:rowActionsForRow:edge:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, std::vector<cocoon::TableViewRowAction>(std::int64_t, cocoon::TableRowActionEdge)>::connected((__bridge void*)strongHost, "row_actions_for_row_edge");
    }
    if (selector == @selector(tableView:userCanChangeVisibilityOfTableColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, bool(cocoon::TableColumn)>::connected((__bridge void*)strongHost, "user_can_change_visibility_of_table_column");
    }
    if (selector == @selector(tableView:userDidChangeVisibilityOfTableColumns:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(std::vector<cocoon::TableColumn>)>::connected((__bridge void*)strongHost, "user_did_change_visibility_of_table_columns");
    }
    if (selector == @selector(tableViewSelectionDidChange:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "selection_did_change");
    }
    if (selector == @selector(tableViewColumnDidMove:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "column_did_move");
    }
    if (selector == @selector(tableViewColumnDidResize:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "column_did_resize");
    }
    if (selector == @selector(tableViewSelectionIsChanging:))
    {
        return strongHost && cocoon::Signal<cocoon::TableView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "selection_is_changing");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    TableView::TableView(const Rect& frame_rect) : TableView(Adopt{cocoon::internal::retain([[::NSTableView alloc] initWithFrame:cocoon::internal::to(frame_rect)])})
    {
        TableView::install_data_source_delegate_(handle());
        TableView::install_delegate_delegate_(handle());
    }

    TableView::TableView() : TableView(Adopt{cocoon::internal::retain([[::NSTableView alloc] init])})
    {
        TableView::install_data_source_delegate_(handle());
        TableView::install_delegate_delegate_(handle());
    }

    TableView::TableView(std::nullptr_t) : Control(nullptr)
    {
    }

    TableView::TableView(Adopt adopt) : Control(adopt)
    {
    }

    void TableView::add_table_column(const TableColumn& table_column) const
    {
        [cocoon::internal::ns<::NSTableView>(this) addTableColumn:cocoon::internal::native<::NSTableColumn>(table_column)];
    }

    void TableView::begin_updates() const
    {
        [cocoon::internal::ns<::NSTableView>(this) beginUpdates];
    }

    bool TableView::can_drag_rows_with_indexes(const IndexSet& row_indexes, const Point& mouse_down_point) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) canDragRowsWithIndexes:cocoon::internal::native<::NSIndexSet>(row_indexes) atPoint:cocoon::internal::to(mouse_down_point)]);
    }

    std::int64_t TableView::column_at_point(const Point& point) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableView>(this) columnAtPoint:cocoon::internal::to(point)]);
    }

    std::int64_t TableView::column_for_view(const View& view) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableView>(this) columnForView:cocoon::internal::native<::NSView>(view)]);
    }

    IndexSet TableView::column_indexes_in_rect(const Rect& rect) const
    {
        return cocoon::internal::wrap<IndexSet>([cocoon::internal::ns<::NSTableView>(this) columnIndexesInRect:cocoon::internal::to(rect)]);
    }

    std::int64_t TableView::column_with_identifier(const std::string& identifier) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableView>(this) columnWithIdentifier:cocoon::internal::to(identifier)]);
    }

    void TableView::deselect_all(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTableView>(this) deselectAll:cocoon::internal::native_id(sender)];
    }

    void TableView::deselect_column(std::int64_t column) const
    {
        [cocoon::internal::ns<::NSTableView>(this) deselectColumn:static_cast<::NSInteger>(column)];
    }

    void TableView::deselect_row(std::int64_t row) const
    {
        [cocoon::internal::ns<::NSTableView>(this) deselectRow:static_cast<::NSInteger>(row)];
    }

    void TableView::did_add_row_view(const TableRowView& row_view, std::int64_t row) const
    {
        [cocoon::internal::ns<::NSTableView>(this) didAddRowView:cocoon::internal::native<::NSTableRowView>(row_view) forRow:static_cast<::NSInteger>(row)];
    }

    void TableView::did_remove_row_view(const TableRowView& row_view, std::int64_t row) const
    {
        [cocoon::internal::ns<::NSTableView>(this) didRemoveRowView:cocoon::internal::native<::NSTableRowView>(row_view) forRow:static_cast<::NSInteger>(row)];
    }

    Image TableView::drag_image_for_rows_with_indexes(const IndexSet& drag_rows, const std::vector<TableColumn>& table_columns, const Event& drag_event, Point* drag_image_offset) const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSTableView>(this) dragImageForRowsWithIndexes:cocoon::internal::native<::NSIndexSet>(drag_rows)
                                                                           tableColumns:cocoon::internal::to_array(table_columns, [](const TableColumn& e) -> id
                                                                                                     {
                                                                                                         return cocoon::internal::native<::NSTableColumn>(e);
                                                                                                     })
                                                                                  event:cocoon::internal::native<::NSEvent>(drag_event)
                                                                                 offset:(::NSPointPointer)(drag_image_offset)]);
    }

    void TableView::draw_background_in_clip_rect(const Rect& clip_rect) const
    {
        [cocoon::internal::ns<::NSTableView>(this) drawBackgroundInClipRect:cocoon::internal::to(clip_rect)];
    }

    void TableView::draw_grid_in_clip_rect(const Rect& clip_rect) const
    {
        [cocoon::internal::ns<::NSTableView>(this) drawGridInClipRect:cocoon::internal::to(clip_rect)];
    }

    void TableView::draw_row(std::int64_t row, const Rect& clip_rect) const
    {
        [cocoon::internal::ns<::NSTableView>(this) drawRow:static_cast<::NSInteger>(row) clipRect:cocoon::internal::to(clip_rect)];
    }

    void TableView::edit_column(std::int64_t column, std::int64_t row, const Event& event, bool select) const
    {
        [cocoon::internal::ns<::NSTableView>(this) editColumn:static_cast<::NSInteger>(column) row:static_cast<::NSInteger>(row) withEvent:cocoon::internal::native<::NSEvent>(event) select:static_cast<::BOOL>(select)];
    }

    void TableView::end_updates() const
    {
        [cocoon::internal::ns<::NSTableView>(this) endUpdates];
    }

    void TableView::enumerate_available_row_views_using_block(std::function<void(TableRowView, std::int64_t)> handler) const
    {
        [cocoon::internal::ns<::NSTableView>(this) enumerateAvailableRowViewsUsingBlock:(handler ? (void (^)(__kindof ::NSTableRowView*, ::NSInteger)) ^ void(::NSTableRowView * a86_0, ::NSInteger a86_1) { handler(cocoon::internal::wrap<TableRowView>(a86_0), static_cast<std::int64_t>(a86_1)); } : (void (^)(__kindof ::NSTableRowView*, ::NSInteger))nil)];
    }

    Rect TableView::frame_of_cell_at_column(std::int64_t column, std::int64_t row) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTableView>(this) frameOfCellAtColumn:static_cast<::NSInteger>(column) row:static_cast<::NSInteger>(row)]);
    }

    void TableView::hide_rows_at_indexes(const IndexSet& indexes, TableViewAnimationOptions row_animation) const
    {
        [cocoon::internal::ns<::NSTableView>(this) hideRowsAtIndexes:cocoon::internal::native<::NSIndexSet>(indexes) withAnimation:static_cast<::NSTableViewAnimationOptions>(row_animation)];
    }

    void TableView::highlight_selection_in_clip_rect(const Rect& clip_rect) const
    {
        [cocoon::internal::ns<::NSTableView>(this) highlightSelectionInClipRect:cocoon::internal::to(clip_rect)];
    }

    Image TableView::indicator_image_in_table_column(const TableColumn& table_column) const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSTableView>(this) indicatorImageInTableColumn:cocoon::internal::native<::NSTableColumn>(table_column)]);
    }

    void TableView::insert_rows_at_indexes(const IndexSet& indexes, TableViewAnimationOptions animation_options) const
    {
        [cocoon::internal::ns<::NSTableView>(this) insertRowsAtIndexes:cocoon::internal::native<::NSIndexSet>(indexes) withAnimation:static_cast<::NSTableViewAnimationOptions>(animation_options)];
    }

    bool TableView::is_column_selected(std::int64_t column) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) isColumnSelected:static_cast<::NSInteger>(column)]);
    }

    bool TableView::is_row_selected(std::int64_t row) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) isRowSelected:static_cast<::NSInteger>(row)]);
    }

    View TableView::make_view_with_identifier(const std::string& identifier, const Object& owner) const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSTableView>(this) makeViewWithIdentifier:cocoon::internal::to(identifier) owner:cocoon::internal::native_id(owner)]);
    }

    void TableView::move_column(std::int64_t old_index, std::int64_t new_index) const
    {
        [cocoon::internal::ns<::NSTableView>(this) moveColumn:static_cast<::NSInteger>(old_index) toColumn:static_cast<::NSInteger>(new_index)];
    }

    void TableView::move_row_at_index(std::int64_t old_index, std::int64_t new_index) const
    {
        [cocoon::internal::ns<::NSTableView>(this) moveRowAtIndex:static_cast<::NSInteger>(old_index) toIndex:static_cast<::NSInteger>(new_index)];
    }

    void TableView::note_height_of_rows_with_indexes_changed(const IndexSet& index_set) const
    {
        [cocoon::internal::ns<::NSTableView>(this) noteHeightOfRowsWithIndexesChanged:cocoon::internal::native<::NSIndexSet>(index_set)];
    }

    void TableView::note_number_of_rows_changed() const
    {
        [cocoon::internal::ns<::NSTableView>(this) noteNumberOfRowsChanged];
    }

    Rect TableView::rect_of_column(std::int64_t column) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTableView>(this) rectOfColumn:static_cast<::NSInteger>(column)]);
    }

    Rect TableView::rect_of_row(std::int64_t row) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTableView>(this) rectOfRow:static_cast<::NSInteger>(row)]);
    }

    void TableView::register_nib(const Nib& nib, const std::string& identifier) const
    {
        [cocoon::internal::ns<::NSTableView>(this) registerNib:cocoon::internal::native<::NSNib>(nib) forIdentifier:cocoon::internal::to(identifier)];
    }

    void TableView::reload_data() const
    {
        [cocoon::internal::ns<::NSTableView>(this) reloadData];
    }

    void TableView::reload_data_for_row_indexes(const IndexSet& row_indexes, const IndexSet& column_indexes) const
    {
        [cocoon::internal::ns<::NSTableView>(this) reloadDataForRowIndexes:cocoon::internal::native<::NSIndexSet>(row_indexes) columnIndexes:cocoon::internal::native<::NSIndexSet>(column_indexes)];
    }

    void TableView::remove_rows_at_indexes(const IndexSet& indexes, TableViewAnimationOptions animation_options) const
    {
        [cocoon::internal::ns<::NSTableView>(this) removeRowsAtIndexes:cocoon::internal::native<::NSIndexSet>(indexes) withAnimation:static_cast<::NSTableViewAnimationOptions>(animation_options)];
    }

    void TableView::remove_table_column(const TableColumn& table_column) const
    {
        [cocoon::internal::ns<::NSTableView>(this) removeTableColumn:cocoon::internal::native<::NSTableColumn>(table_column)];
    }

    std::int64_t TableView::row_at_point(const Point& point) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableView>(this) rowAtPoint:cocoon::internal::to(point)]);
    }

    std::int64_t TableView::row_for_view(const View& view) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableView>(this) rowForView:cocoon::internal::native<::NSView>(view)]);
    }

    TableRowView TableView::row_view_at_row(std::int64_t row, bool make_if_necessary) const
    {
        return cocoon::internal::wrap<TableRowView>([cocoon::internal::ns<::NSTableView>(this) rowViewAtRow:static_cast<::NSInteger>(row) makeIfNecessary:static_cast<::BOOL>(make_if_necessary)]);
    }

    Range TableView::rows_in_rect(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTableView>(this) rowsInRect:cocoon::internal::to(rect)]);
    }

    void TableView::scroll_column_to_visible(std::int64_t column) const
    {
        [cocoon::internal::ns<::NSTableView>(this) scrollColumnToVisible:static_cast<::NSInteger>(column)];
    }

    void TableView::scroll_row_to_visible(std::int64_t row) const
    {
        [cocoon::internal::ns<::NSTableView>(this) scrollRowToVisible:static_cast<::NSInteger>(row)];
    }

    void TableView::select_all(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTableView>(this) selectAll:cocoon::internal::native_id(sender)];
    }

    void TableView::select_column_indexes(const IndexSet& indexes, bool extend) const
    {
        [cocoon::internal::ns<::NSTableView>(this) selectColumnIndexes:cocoon::internal::native<::NSIndexSet>(indexes) byExtendingSelection:static_cast<::BOOL>(extend)];
    }

    void TableView::select_row_indexes(const IndexSet& indexes, bool extend) const
    {
        [cocoon::internal::ns<::NSTableView>(this) selectRowIndexes:cocoon::internal::native<::NSIndexSet>(indexes) byExtendingSelection:static_cast<::BOOL>(extend)];
    }

    void TableView::set_dragging_source_operation_mask(DragOperation mask, bool is_local) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setDraggingSourceOperationMask:static_cast<::NSDragOperation>(mask) forLocal:static_cast<::BOOL>(is_local)];
    }

    void TableView::set_drop_row(std::int64_t row, TableViewDropOperation drop_operation) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setDropRow:static_cast<::NSInteger>(row) dropOperation:static_cast<::NSTableViewDropOperation>(drop_operation)];
    }

    void TableView::set_indicator_image(const Image& image, const TableColumn& table_column) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setIndicatorImage:cocoon::internal::native<::NSImage>(image) inTableColumn:cocoon::internal::native<::NSTableColumn>(table_column)];
    }

    void TableView::size_last_column_to_fit() const
    {
        [cocoon::internal::ns<::NSTableView>(this) sizeLastColumnToFit];
    }

    void TableView::size_to_fit() const
    {
        [cocoon::internal::ns<::NSTableView>(this) sizeToFit];
    }

    TableColumn TableView::table_column_with_identifier(const std::string& identifier) const
    {
        return cocoon::internal::wrap<TableColumn>([cocoon::internal::ns<::NSTableView>(this) tableColumnWithIdentifier:cocoon::internal::to(identifier)]);
    }

    void TableView::tile() const
    {
        [cocoon::internal::ns<::NSTableView>(this) tile];
    }

    void TableView::unhide_rows_at_indexes(const IndexSet& indexes, TableViewAnimationOptions row_animation) const
    {
        [cocoon::internal::ns<::NSTableView>(this) unhideRowsAtIndexes:cocoon::internal::native<::NSIndexSet>(indexes) withAnimation:static_cast<::NSTableViewAnimationOptions>(row_animation)];
    }

    View TableView::view_at_column(std::int64_t column, std::int64_t row, bool make_if_necessary) const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSTableView>(this) viewAtColumn:static_cast<::NSInteger>(column) row:static_cast<::NSInteger>(row) makeIfNecessary:static_cast<::BOOL>(make_if_necessary)]);
    }

    bool TableView::allows_column_reordering() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) allowsColumnReordering]);
    }

    void TableView::set_allows_column_reordering(bool value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setAllowsColumnReordering:static_cast<::BOOL>(value)];
    }

    bool TableView::allows_column_resizing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) allowsColumnResizing]);
    }

    void TableView::set_allows_column_resizing(bool value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setAllowsColumnResizing:static_cast<::BOOL>(value)];
    }

    bool TableView::allows_column_selection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) allowsColumnSelection]);
    }

    void TableView::set_allows_column_selection(bool value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setAllowsColumnSelection:static_cast<::BOOL>(value)];
    }

    bool TableView::allows_empty_selection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) allowsEmptySelection]);
    }

    void TableView::set_allows_empty_selection(bool value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setAllowsEmptySelection:static_cast<::BOOL>(value)];
    }

    bool TableView::allows_multiple_selection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) allowsMultipleSelection]);
    }

    void TableView::set_allows_multiple_selection(bool value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setAllowsMultipleSelection:static_cast<::BOOL>(value)];
    }

    bool TableView::allows_type_select() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) allowsTypeSelect]);
    }

    void TableView::set_allows_type_select(bool value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setAllowsTypeSelect:static_cast<::BOOL>(value)];
    }

    std::string TableView::autosave_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTableView>(this) autosaveName]);
    }

    void TableView::set_autosave_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setAutosaveName:cocoon::internal::to(value)];
    }

    bool TableView::autosave_table_columns() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) autosaveTableColumns]);
    }

    void TableView::set_autosave_table_columns(bool value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setAutosaveTableColumns:static_cast<::BOOL>(value)];
    }

    Color TableView::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTableView>(this) backgroundColor]);
    }

    void TableView::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    std::int64_t TableView::clicked_column() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableView>(this) clickedColumn]);
    }

    std::int64_t TableView::clicked_row() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableView>(this) clickedRow]);
    }

    TableViewColumnAutoresizingStyle TableView::column_autoresizing_style() const
    {
        return static_cast<TableViewColumnAutoresizingStyle>([cocoon::internal::ns<::NSTableView>(this) columnAutoresizingStyle]);
    }

    void TableView::set_column_autoresizing_style(TableViewColumnAutoresizingStyle value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setColumnAutoresizingStyle:static_cast<::NSTableViewColumnAutoresizingStyle>(value)];
    }

    View TableView::corner_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSTableView>(this) cornerView]);
    }

    void TableView::set_corner_view(const View& value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setCornerView:cocoon::internal::native<::NSView>(value)];
    }

    std::string TableView::double_action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSTableView>(this) doubleAction]));
    }

    void TableView::set_double_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setDoubleAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    TableViewDraggingDestinationFeedbackStyle TableView::dragging_destination_feedback_style() const
    {
        return static_cast<TableViewDraggingDestinationFeedbackStyle>([cocoon::internal::ns<::NSTableView>(this) draggingDestinationFeedbackStyle]);
    }

    void TableView::set_dragging_destination_feedback_style(TableViewDraggingDestinationFeedbackStyle value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setDraggingDestinationFeedbackStyle:static_cast<::NSTableViewDraggingDestinationFeedbackStyle>(value)];
    }

    std::int64_t TableView::edited_column() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableView>(this) editedColumn]);
    }

    std::int64_t TableView::edited_row() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableView>(this) editedRow]);
    }

    TableViewRowSizeStyle TableView::effective_row_size_style() const
    {
        return static_cast<TableViewRowSizeStyle>([cocoon::internal::ns<::NSTableView>(this) effectiveRowSizeStyle]);
    }

    TableViewStyle TableView::effective_style() const
    {
        return static_cast<TableViewStyle>([cocoon::internal::ns<::NSTableView>(this) effectiveStyle]);
    }

    bool TableView::floats_group_rows() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) floatsGroupRows]);
    }

    void TableView::set_floats_group_rows(bool value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setFloatsGroupRows:static_cast<::BOOL>(value)];
    }

    Color TableView::grid_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTableView>(this) gridColor]);
    }

    void TableView::set_grid_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setGridColor:cocoon::internal::native<::NSColor>(value)];
    }

    TableViewGridLineStyle TableView::grid_style_mask() const
    {
        return static_cast<TableViewGridLineStyle>([cocoon::internal::ns<::NSTableView>(this) gridStyleMask]);
    }

    void TableView::set_grid_style_mask(TableViewGridLineStyle value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setGridStyleMask:static_cast<::NSTableViewGridLineStyle>(value)];
    }

    TableHeaderView TableView::header_view() const
    {
        return cocoon::internal::wrap<TableHeaderView>([cocoon::internal::ns<::NSTableView>(this) headerView]);
    }

    void TableView::set_header_view(const TableHeaderView& value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setHeaderView:cocoon::internal::native<::NSTableHeaderView>(value)];
    }

    IndexSet TableView::hidden_row_indexes() const
    {
        return cocoon::internal::wrap<IndexSet>([cocoon::internal::ns<::NSTableView>(this) hiddenRowIndexes]);
    }

    TableColumn TableView::highlighted_table_column() const
    {
        return cocoon::internal::wrap<TableColumn>([cocoon::internal::ns<::NSTableView>(this) highlightedTableColumn]);
    }

    void TableView::set_highlighted_table_column(const TableColumn& value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setHighlightedTableColumn:cocoon::internal::native<::NSTableColumn>(value)];
    }

    Size TableView::intercell_spacing() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTableView>(this) intercellSpacing]);
    }

    void TableView::set_intercell_spacing(const Size& value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setIntercellSpacing:cocoon::internal::to(value)];
    }

    std::int64_t TableView::number_of_columns() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableView>(this) numberOfColumns]);
    }

    std::int64_t TableView::number_of_rows() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableView>(this) numberOfRows]);
    }

    std::int64_t TableView::number_of_selected_columns() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableView>(this) numberOfSelectedColumns]);
    }

    std::int64_t TableView::number_of_selected_rows() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableView>(this) numberOfSelectedRows]);
    }

    std::map<std::string, Nib> TableView::registered_nibs_by_identifier() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Nib>>([cocoon::internal::ns<::NSTableView>(this) registeredNibsByIdentifier], [](id k) -> std::string
                                                               {
                                                                   return cocoon::internal::from((NSString*)k);
                                                               },
                                                               [](id v) -> Nib
                                                               {
                                                                   return cocoon::internal::wrap<Nib>((::NSNib*)v);
                                                               });
    }

    bool TableView::row_actions_visible() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) rowActionsVisible]);
    }

    void TableView::set_row_actions_visible(bool value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setRowActionsVisible:static_cast<::BOOL>(value)];
    }

    double TableView::row_height() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTableView>(this) rowHeight]);
    }

    void TableView::set_row_height(double value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setRowHeight:static_cast<::CGFloat>(value)];
    }

    TableViewRowSizeStyle TableView::row_size_style() const
    {
        return static_cast<TableViewRowSizeStyle>([cocoon::internal::ns<::NSTableView>(this) rowSizeStyle]);
    }

    void TableView::set_row_size_style(TableViewRowSizeStyle value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setRowSizeStyle:static_cast<::NSTableViewRowSizeStyle>(value)];
    }

    std::int64_t TableView::selected_column() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableView>(this) selectedColumn]);
    }

    IndexSet TableView::selected_column_indexes() const
    {
        return cocoon::internal::wrap<IndexSet>([cocoon::internal::ns<::NSTableView>(this) selectedColumnIndexes]);
    }

    std::int64_t TableView::selected_row() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableView>(this) selectedRow]);
    }

    IndexSet TableView::selected_row_indexes() const
    {
        return cocoon::internal::wrap<IndexSet>([cocoon::internal::ns<::NSTableView>(this) selectedRowIndexes]);
    }

    TableViewSelectionHighlightStyle TableView::selection_highlight_style() const
    {
        return static_cast<TableViewSelectionHighlightStyle>([cocoon::internal::ns<::NSTableView>(this) selectionHighlightStyle]);
    }

    void TableView::set_selection_highlight_style(TableViewSelectionHighlightStyle value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setSelectionHighlightStyle:static_cast<::NSTableViewSelectionHighlightStyle>(value)];
    }

    std::vector<SortDescriptor> TableView::sort_descriptors() const
    {
        return cocoon::internal::from_array<SortDescriptor>([cocoon::internal::ns<::NSTableView>(this) sortDescriptors], [](id e) -> SortDescriptor
                                              {
                                                  return cocoon::internal::wrap<SortDescriptor>((::NSSortDescriptor*)e);
                                              });
    }

    void TableView::set_sort_descriptors(const std::vector<SortDescriptor>& value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setSortDescriptors:cocoon::internal::to_array(value, [](const SortDescriptor& e) -> id
                                                                     {
                                                                         return cocoon::internal::native<::NSSortDescriptor>(e);
                                                                     })];
    }

    TableViewStyle TableView::style() const
    {
        return static_cast<TableViewStyle>([cocoon::internal::ns<::NSTableView>(this) style]);
    }

    void TableView::set_style(TableViewStyle value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setStyle:static_cast<::NSTableViewStyle>(value)];
    }

    std::vector<TableColumn> TableView::table_columns() const
    {
        return cocoon::internal::from_array<TableColumn>([cocoon::internal::ns<::NSTableView>(this) tableColumns], [](id e) -> TableColumn
                                           {
                                               return cocoon::internal::wrap<TableColumn>((::NSTableColumn*)e);
                                           });
    }

    UserInterfaceLayoutDirection TableView::user_interface_layout_direction() const
    {
        return static_cast<UserInterfaceLayoutDirection>([cocoon::internal::ns<::NSTableView>(this) userInterfaceLayoutDirection]);
    }

    void TableView::set_user_interface_layout_direction(UserInterfaceLayoutDirection value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setUserInterfaceLayoutDirection:static_cast<::NSUserInterfaceLayoutDirection>(value)];
    }

    bool TableView::uses_alternating_row_background_colors() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) usesAlternatingRowBackgroundColors]);
    }

    void TableView::set_uses_alternating_row_background_colors(bool value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setUsesAlternatingRowBackgroundColors:static_cast<::BOOL>(value)];
    }

    bool TableView::uses_automatic_row_heights() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) usesAutomaticRowHeights]);
    }

    void TableView::set_uses_automatic_row_heights(bool value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setUsesAutomaticRowHeights:static_cast<::BOOL>(value)];
    }

    bool TableView::uses_static_contents() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) usesStaticContents]);
    }

    void TableView::set_uses_static_contents(bool value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setUsesStaticContents:static_cast<::BOOL>(value)];
    }

    bool TableView::vertical_motion_can_begin_drag() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableView>(this) verticalMotionCanBeginDrag]);
    }

    void TableView::set_vertical_motion_can_begin_drag(bool value) const
    {
        [cocoon::internal::ns<::NSTableView>(this) setVerticalMotionCanBeginDrag:static_cast<::BOOL>(value)];
    }

    void TableView::install_data_source_delegate_(void* native)
    {
        ::NSTableView* host = (__bridge ::NSTableView*)native;
        AKTableViewDataSourceDelegate* delegate = [[AKTableViewDataSourceDelegate alloc] init];
        delegate->host = host;
        host.dataSource = delegate;
        __weak::NSTableView* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSTableView* strongHost = weakHost;
            strongHost.dataSource = nil;
            strongHost.dataSource = delegate;
        });
    }

    void TableView::install_delegate_delegate_(void* native)
    {
        ::NSTableView* host = (__bridge ::NSTableView*)native;
        AKTableViewDelegate* delegate = [[AKTableViewDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSTableView* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSTableView* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
