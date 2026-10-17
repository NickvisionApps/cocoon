#include "generated/browser.h"
#include "internal.h"

@interface AKBrowserDelegate : NSObject <NSBrowserDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKBrowserDelegate

- (NSInteger)browser:(NSBrowser*)sender numberOfRowsInColumn:(NSInteger)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, std::int64_t(std::int64_t)>::emit((__bridge void*)strongHost, "number_of_rows_in_column", static_cast<std::int64_t>(column));
    return static_cast<::NSInteger>(__r);
}

- (void)browser:(NSBrowser*)sender createRowsForColumn:(NSInteger)column inMatrix:(NSMatrix*)matrix
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Browser, void(std::int64_t, cocoon::Matrix)>::emit((__bridge void*)strongHost, "create_rows_for_column_in_matrix", static_cast<std::int64_t>(column), cocoon::internal::wrap<cocoon::Matrix>(matrix));
}

- (NSInteger)browser:(NSBrowser*)browser numberOfChildrenOfItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, std::int64_t(cocoon::Object)>::emit((__bridge void*)strongHost, "number_of_children_of_item", cocoon::internal::wrap<cocoon::Object>(item));
    return static_cast<::NSInteger>(__r);
}

- (id)browser:(NSBrowser*)browser child:(NSInteger)index ofItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, cocoon::Object(std::int64_t, cocoon::Object)>::emit((__bridge void*)strongHost, "child_of_item", static_cast<std::int64_t>(index), cocoon::internal::wrap<cocoon::Object>(item));
    return cocoon::internal::native_id(__r);
}

- (BOOL)browser:(NSBrowser*)browser isLeafItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, bool(cocoon::Object)>::emit((__bridge void*)strongHost, "browser_is_leaf_item", cocoon::internal::wrap<cocoon::Object>(item));
    return static_cast<::BOOL>(__r);
}

- (id)browser:(NSBrowser*)browser objectValueForItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, cocoon::Object(cocoon::Object)>::emit((__bridge void*)strongHost, "object_value_for_item", cocoon::internal::wrap<cocoon::Object>(item));
    return cocoon::internal::native_id(__r);
}

- (CGFloat)browser:(NSBrowser*)browser heightOfRow:(NSInteger)row inColumn:(NSInteger)columnIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, double(std::int64_t, std::int64_t)>::emit((__bridge void*)strongHost, "height_of_row_in_column", static_cast<std::int64_t>(row), static_cast<std::int64_t>(columnIndex));
    return static_cast<::CGFloat>(__r);
}

- (id)rootItemForBrowser:(NSBrowser*)browser
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, cocoon::Object()>::emit((__bridge void*)strongHost, "root_item_for_browser");
    return cocoon::internal::native_id(__r);
}

- (void)browser:(NSBrowser*)browser setObjectValue:(id)object forItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Browser, void(cocoon::Object, cocoon::Object)>::emit((__bridge void*)strongHost, "set_object_value_for_item", cocoon::internal::wrap<cocoon::Object>(object), cocoon::internal::wrap<cocoon::Object>(item));
}

- (BOOL)browser:(NSBrowser*)browser shouldEditItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, bool(cocoon::Object)>::emit((__bridge void*)strongHost, "should_edit_item", cocoon::internal::wrap<cocoon::Object>(item));
    return static_cast<::BOOL>(__r);
}

- (void)browser:(NSBrowser*)sender willDisplayCell:(id)cell atRow:(NSInteger)row column:(NSInteger)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Browser, void(cocoon::Object, std::int64_t, std::int64_t)>::emit((__bridge void*)strongHost, "will_display_cell_at_row_column", cocoon::internal::wrap<cocoon::Object>(cell), static_cast<std::int64_t>(row), static_cast<std::int64_t>(column));
}

- (NSString*)browser:(NSBrowser*)sender titleOfColumn:(NSInteger)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, std::string(std::int64_t)>::emit((__bridge void*)strongHost, "browser_title_of_column", static_cast<std::int64_t>(column));
    return cocoon::internal::to(__r);
}

- (BOOL)browser:(NSBrowser*)sender selectCellWithString:(NSString*)title inColumn:(NSInteger)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, bool(std::string, std::int64_t)>::emit((__bridge void*)strongHost, "select_cell_with_string_in_column", cocoon::internal::from(title), static_cast<std::int64_t>(column));
    return static_cast<::BOOL>(__r);
}

- (BOOL)browser:(NSBrowser*)sender selectRow:(NSInteger)row inColumn:(NSInteger)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, bool(std::int64_t, std::int64_t)>::emit((__bridge void*)strongHost, "select_row_in_column", static_cast<std::int64_t>(row), static_cast<std::int64_t>(column));
    return static_cast<::BOOL>(__r);
}

- (BOOL)browser:(NSBrowser*)sender isColumnValid:(NSInteger)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, bool(std::int64_t)>::emit((__bridge void*)strongHost, "is_column_valid", static_cast<std::int64_t>(column));
    return static_cast<::BOOL>(__r);
}

- (void)browserWillScroll:(NSBrowser*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Browser, void()>::emit((__bridge void*)strongHost, "will_scroll");
}

- (void)browserDidScroll:(NSBrowser*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Browser, void()>::emit((__bridge void*)strongHost, "did_scroll");
}

- (CGFloat)browser:(NSBrowser*)browser shouldSizeColumn:(NSInteger)columnIndex forUserResize:(BOOL)forUserResize toWidth:(CGFloat)suggestedWidth
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, double(std::int64_t, bool, double)>::emit((__bridge void*)strongHost, "should_size_column_for_user_resize_to_width", static_cast<std::int64_t>(columnIndex), static_cast<bool>(forUserResize), static_cast<double>(suggestedWidth));
    return static_cast<::CGFloat>(__r);
}

- (CGFloat)browser:(NSBrowser*)browser sizeToFitWidthOfColumn:(NSInteger)columnIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, double(std::int64_t)>::emit((__bridge void*)strongHost, "size_to_fit_width_of_column", static_cast<std::int64_t>(columnIndex));
    return static_cast<::CGFloat>(__r);
}

- (void)browserColumnConfigurationDidChange:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Browser, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "column_configuration_did_change", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (BOOL)browser:(NSBrowser*)browser shouldShowCellExpansionForRow:(NSInteger)row column:(NSInteger)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, bool(std::int64_t, std::int64_t)>::emit((__bridge void*)strongHost, "should_show_cell_expansion_for_row_column", static_cast<std::int64_t>(row), static_cast<std::int64_t>(column));
    return static_cast<::BOOL>(__r);
}

#ifdef COCOON_MACOS_27
- (id<NSPasteboardWriting>)browser:(NSBrowser*)browser pasteboardWriterForRow:(NSInteger)row column:(NSInteger)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, cocoon::Object(std::int64_t, std::int64_t)>::emit((__bridge void*)strongHost, "pasteboard_writer_for_row_column", static_cast<std::int64_t>(row), static_cast<std::int64_t>(column));
    return cocoon::internal::native_id(__r);
}

#endif

#ifdef COCOON_MACOS_27
- (void)browser:(NSBrowser*)browser draggingSession:(NSDraggingSession*)session willBeginAtPoint:(NSPoint)screenPoint forRowsWithIndexes:(NSIndexSet*)rowIndexes column:(NSInteger)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Browser, void(cocoon::DraggingSession, cocoon::Point, cocoon::IndexSet, std::int64_t)>::emit((__bridge void*)strongHost, "dragging_session_will_begin_at_point_for_rows_with_indexes_column", cocoon::internal::wrap<cocoon::DraggingSession>(session), cocoon::internal::from(screenPoint), cocoon::internal::wrap<cocoon::IndexSet>(rowIndexes), static_cast<std::int64_t>(column));
}

#endif

#ifdef COCOON_MACOS_27
- (void)browser:(NSBrowser*)browser draggingSession:(NSDraggingSession*)session endedAtPoint:(NSPoint)screenPoint operation:(NSDragOperation)operation
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Browser, void(cocoon::DraggingSession, cocoon::Point, cocoon::DragOperation)>::emit((__bridge void*)strongHost, "dragging_session_ended_at_point_operation", cocoon::internal::wrap<cocoon::DraggingSession>(session), cocoon::internal::from(screenPoint), static_cast<cocoon::DragOperation>(operation));
}

#endif

- (BOOL)browser:(NSBrowser*)browser writeRowsWithIndexes:(NSIndexSet*)rowIndexes inColumn:(NSInteger)column toPasteboard:(NSPasteboard*)pasteboard
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, bool(cocoon::IndexSet, std::int64_t, cocoon::Pasteboard)>::emit((__bridge void*)strongHost, "write_rows_with_indexes_in_column_to_pasteboard", cocoon::internal::wrap<cocoon::IndexSet>(rowIndexes), static_cast<std::int64_t>(column), cocoon::internal::wrap<cocoon::Pasteboard>(pasteboard));
    return static_cast<::BOOL>(__r);
}

- (BOOL)browser:(NSBrowser*)browser canDragRowsWithIndexes:(NSIndexSet*)rowIndexes inColumn:(NSInteger)column withEvent:(NSEvent*)event
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, bool(cocoon::IndexSet, std::int64_t, cocoon::Event)>::emit((__bridge void*)strongHost, "can_drag_rows_with_indexes_in_column_with_event", cocoon::internal::wrap<cocoon::IndexSet>(rowIndexes), static_cast<std::int64_t>(column), cocoon::internal::wrap<cocoon::Event>(event));
    return static_cast<::BOOL>(__r);
}

- (NSImage*)browser:(NSBrowser*)browser draggingImageForRowsWithIndexes:(NSIndexSet*)rowIndexes inColumn:(NSInteger)column withEvent:(NSEvent*)event offset:(NSPointPointer)dragImageOffset
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, cocoon::Image(cocoon::IndexSet, std::int64_t, cocoon::Event, cocoon::Point*)>::emit((__bridge void*)strongHost, "dragging_image_for_rows_with_indexes_in_column_with_event_offset", cocoon::internal::wrap<cocoon::IndexSet>(rowIndexes), static_cast<std::int64_t>(column), cocoon::internal::wrap<cocoon::Event>(event), (cocoon::Point*)(dragImageOffset));
    return cocoon::internal::native<::NSImage>(__r);
}

- (NSDragOperation)browser:(NSBrowser*)browser validateDrop:(id<NSDraggingInfo>)info proposedRow:(NSInteger*)row column:(NSInteger*)column dropOperation:(NSBrowserDropOperation*)dropOperation
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, cocoon::DragOperation(cocoon::Object, std::int64_t*, std::int64_t*, cocoon::BrowserDropOperation*)>::emit((__bridge void*)strongHost, "validate_drop_proposed_row_column_drop_operation", cocoon::internal::wrap<cocoon::Object>(info), (std::int64_t*)(row), (std::int64_t*)(column), (cocoon::BrowserDropOperation*)(dropOperation));
    return static_cast<::NSDragOperation>(__r);
}

- (BOOL)browser:(NSBrowser*)browser acceptDrop:(id<NSDraggingInfo>)info atRow:(NSInteger)row column:(NSInteger)column dropOperation:(NSBrowserDropOperation)dropOperation
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, bool(cocoon::Object, std::int64_t, std::int64_t, cocoon::BrowserDropOperation)>::emit((__bridge void*)strongHost, "accept_drop_at_row_column_drop_operation", cocoon::internal::wrap<cocoon::Object>(info), static_cast<std::int64_t>(row), static_cast<std::int64_t>(column), static_cast<cocoon::BrowserDropOperation>(dropOperation));
    return static_cast<::BOOL>(__r);
}

- (NSString*)browser:(NSBrowser*)browser typeSelectStringForRow:(NSInteger)row inColumn:(NSInteger)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, std::string(std::int64_t, std::int64_t)>::emit((__bridge void*)strongHost, "type_select_string_for_row_in_column", static_cast<std::int64_t>(row), static_cast<std::int64_t>(column));
    return cocoon::internal::to(__r);
}

- (BOOL)browser:(NSBrowser*)browser shouldTypeSelectForEvent:(NSEvent*)event withCurrentSearchString:(NSString*)searchString
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, bool(cocoon::Event, std::string)>::emit((__bridge void*)strongHost, "should_type_select_for_event_with_current_search_string", cocoon::internal::wrap<cocoon::Event>(event), cocoon::internal::from(searchString));
    return static_cast<::BOOL>(__r);
}

- (NSInteger)browser:(NSBrowser*)browser nextTypeSelectMatchFromRow:(NSInteger)startRow toRow:(NSInteger)endRow inColumn:(NSInteger)column forString:(NSString*)searchString
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, std::int64_t(std::int64_t, std::int64_t, std::int64_t, std::string)>::emit((__bridge void*)strongHost, "next_type_select_match_from_row_to_row_in_column_for_string", static_cast<std::int64_t>(startRow), static_cast<std::int64_t>(endRow), static_cast<std::int64_t>(column), cocoon::internal::from(searchString));
    return static_cast<::NSInteger>(__r);
}

- (NSViewController*)browser:(NSBrowser*)browser previewViewControllerForLeafItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, cocoon::ViewController(cocoon::Object)>::emit((__bridge void*)strongHost, "preview_view_controller_for_leaf_item", cocoon::internal::wrap<cocoon::Object>(item));
    return cocoon::internal::native<::NSViewController>(__r);
}

- (NSViewController*)browser:(NSBrowser*)browser headerViewControllerForItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, cocoon::ViewController(cocoon::Object)>::emit((__bridge void*)strongHost, "header_view_controller_for_item", cocoon::internal::wrap<cocoon::Object>(item));
    return cocoon::internal::native<::NSViewController>(__r);
}

- (void)browser:(NSBrowser*)browser didChangeLastColumn:(NSInteger)oldLastColumn toColumn:(NSInteger)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Browser, void(std::int64_t, std::int64_t)>::emit((__bridge void*)strongHost, "did_change_last_column_to_column", static_cast<std::int64_t>(oldLastColumn), static_cast<std::int64_t>(column));
}

- (NSIndexSet*)browser:(NSBrowser*)browser selectionIndexesForProposedSelection:(NSIndexSet*)proposedSelectionIndexes inColumn:(NSInteger)column
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Browser, cocoon::IndexSet(cocoon::IndexSet, std::int64_t)>::emit((__bridge void*)strongHost, "selection_indexes_for_proposed_selection_in_column", cocoon::internal::wrap<cocoon::IndexSet>(proposedSelectionIndexes), static_cast<std::int64_t>(column));
    return cocoon::internal::native<::NSIndexSet>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(browser:numberOfRowsInColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, std::int64_t(std::int64_t)>::connected((__bridge void*)strongHost, "number_of_rows_in_column");
    }
    if (selector == @selector(browser:createRowsForColumn:inMatrix:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, void(std::int64_t, cocoon::Matrix)>::connected((__bridge void*)strongHost, "create_rows_for_column_in_matrix");
    }
    if (selector == @selector(browser:numberOfChildrenOfItem:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, std::int64_t(cocoon::Object)>::connected((__bridge void*)strongHost, "number_of_children_of_item");
    }
    if (selector == @selector(browser:child:ofItem:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, cocoon::Object(std::int64_t, cocoon::Object)>::connected((__bridge void*)strongHost, "child_of_item");
    }
    if (selector == @selector(browser:isLeafItem:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, bool(cocoon::Object)>::connected((__bridge void*)strongHost, "browser_is_leaf_item");
    }
    if (selector == @selector(browser:objectValueForItem:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, cocoon::Object(cocoon::Object)>::connected((__bridge void*)strongHost, "object_value_for_item");
    }
    if (selector == @selector(browser:heightOfRow:inColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, double(std::int64_t, std::int64_t)>::connected((__bridge void*)strongHost, "height_of_row_in_column");
    }
    if (selector == @selector(rootItemForBrowser:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, cocoon::Object()>::connected((__bridge void*)strongHost, "root_item_for_browser");
    }
    if (selector == @selector(browser:setObjectValue:forItem:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, void(cocoon::Object, cocoon::Object)>::connected((__bridge void*)strongHost, "set_object_value_for_item");
    }
    if (selector == @selector(browser:shouldEditItem:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, bool(cocoon::Object)>::connected((__bridge void*)strongHost, "should_edit_item");
    }
    if (selector == @selector(browser:willDisplayCell:atRow:column:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, void(cocoon::Object, std::int64_t, std::int64_t)>::connected((__bridge void*)strongHost, "will_display_cell_at_row_column");
    }
    if (selector == @selector(browser:titleOfColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, std::string(std::int64_t)>::connected((__bridge void*)strongHost, "browser_title_of_column");
    }
    if (selector == @selector(browser:selectCellWithString:inColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, bool(std::string, std::int64_t)>::connected((__bridge void*)strongHost, "select_cell_with_string_in_column");
    }
    if (selector == @selector(browser:selectRow:inColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, bool(std::int64_t, std::int64_t)>::connected((__bridge void*)strongHost, "select_row_in_column");
    }
    if (selector == @selector(browser:isColumnValid:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, bool(std::int64_t)>::connected((__bridge void*)strongHost, "is_column_valid");
    }
    if (selector == @selector(browserWillScroll:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, void()>::connected((__bridge void*)strongHost, "will_scroll");
    }
    if (selector == @selector(browserDidScroll:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, void()>::connected((__bridge void*)strongHost, "did_scroll");
    }
    if (selector == @selector(browser:shouldSizeColumn:forUserResize:toWidth:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, double(std::int64_t, bool, double)>::connected((__bridge void*)strongHost, "should_size_column_for_user_resize_to_width");
    }
    if (selector == @selector(browser:sizeToFitWidthOfColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, double(std::int64_t)>::connected((__bridge void*)strongHost, "size_to_fit_width_of_column");
    }
    if (selector == @selector(browserColumnConfigurationDidChange:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "column_configuration_did_change");
    }
    if (selector == @selector(browser:shouldShowCellExpansionForRow:column:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, bool(std::int64_t, std::int64_t)>::connected((__bridge void*)strongHost, "should_show_cell_expansion_for_row_column");
    }
#ifdef COCOON_MACOS_27
    if (selector == @selector(browser:pasteboardWriterForRow:column:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, cocoon::Object(std::int64_t, std::int64_t)>::connected((__bridge void*)strongHost, "pasteboard_writer_for_row_column");
    }
#endif

#ifdef COCOON_MACOS_27
    if (selector == @selector(browser:draggingSession:willBeginAtPoint:forRowsWithIndexes:column:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, void(cocoon::DraggingSession, cocoon::Point, cocoon::IndexSet, std::int64_t)>::connected((__bridge void*)strongHost, "dragging_session_will_begin_at_point_for_rows_with_indexes_column");
    }
#endif

#ifdef COCOON_MACOS_27
    if (selector == @selector(browser:draggingSession:endedAtPoint:operation:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, void(cocoon::DraggingSession, cocoon::Point, cocoon::DragOperation)>::connected((__bridge void*)strongHost, "dragging_session_ended_at_point_operation");
    }
#endif

    if (selector == @selector(browser:writeRowsWithIndexes:inColumn:toPasteboard:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, bool(cocoon::IndexSet, std::int64_t, cocoon::Pasteboard)>::connected((__bridge void*)strongHost, "write_rows_with_indexes_in_column_to_pasteboard");
    }
    if (selector == @selector(browser:canDragRowsWithIndexes:inColumn:withEvent:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, bool(cocoon::IndexSet, std::int64_t, cocoon::Event)>::connected((__bridge void*)strongHost, "can_drag_rows_with_indexes_in_column_with_event");
    }
    if (selector == @selector(browser:draggingImageForRowsWithIndexes:inColumn:withEvent:offset:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, cocoon::Image(cocoon::IndexSet, std::int64_t, cocoon::Event, cocoon::Point*)>::connected((__bridge void*)strongHost, "dragging_image_for_rows_with_indexes_in_column_with_event_offset");
    }
    if (selector == @selector(browser:validateDrop:proposedRow:column:dropOperation:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, cocoon::DragOperation(cocoon::Object, std::int64_t*, std::int64_t*, cocoon::BrowserDropOperation*)>::connected((__bridge void*)strongHost, "validate_drop_proposed_row_column_drop_operation");
    }
    if (selector == @selector(browser:acceptDrop:atRow:column:dropOperation:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, bool(cocoon::Object, std::int64_t, std::int64_t, cocoon::BrowserDropOperation)>::connected((__bridge void*)strongHost, "accept_drop_at_row_column_drop_operation");
    }
    if (selector == @selector(browser:typeSelectStringForRow:inColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, std::string(std::int64_t, std::int64_t)>::connected((__bridge void*)strongHost, "type_select_string_for_row_in_column");
    }
    if (selector == @selector(browser:shouldTypeSelectForEvent:withCurrentSearchString:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, bool(cocoon::Event, std::string)>::connected((__bridge void*)strongHost, "should_type_select_for_event_with_current_search_string");
    }
    if (selector == @selector(browser:nextTypeSelectMatchFromRow:toRow:inColumn:forString:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, std::int64_t(std::int64_t, std::int64_t, std::int64_t, std::string)>::connected((__bridge void*)strongHost, "next_type_select_match_from_row_to_row_in_column_for_string");
    }
    if (selector == @selector(browser:previewViewControllerForLeafItem:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, cocoon::ViewController(cocoon::Object)>::connected((__bridge void*)strongHost, "preview_view_controller_for_leaf_item");
    }
    if (selector == @selector(browser:headerViewControllerForItem:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, cocoon::ViewController(cocoon::Object)>::connected((__bridge void*)strongHost, "header_view_controller_for_item");
    }
    if (selector == @selector(browser:didChangeLastColumn:toColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, void(std::int64_t, std::int64_t)>::connected((__bridge void*)strongHost, "did_change_last_column_to_column");
    }
    if (selector == @selector(browser:selectionIndexesForProposedSelection:inColumn:))
    {
        return strongHost && cocoon::Signal<cocoon::Browser, cocoon::IndexSet(cocoon::IndexSet, std::int64_t)>::connected((__bridge void*)strongHost, "selection_indexes_for_proposed_selection_in_column");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    Browser::Browser() : Browser(Adopt{cocoon::internal::retain([[::NSBrowser alloc] init])})
    {
        Browser::install_delegate_delegate_(handle());
    }

    Browser::Browser(std::nullptr_t) : Control(nullptr)
    {
    }

    Browser::Browser(Adopt adopt) : Control(adopt)
    {
    }

    void Browser::add_column() const
    {
        [cocoon::internal::ns<::NSBrowser>(this) addColumn];
    }

    bool Browser::can_drag_rows_with_indexes(const IndexSet& row_indexes, std::int64_t column, const Event& event) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) canDragRowsWithIndexes:cocoon::internal::native<::NSIndexSet>(row_indexes) inColumn:static_cast<::NSInteger>(column) withEvent:cocoon::internal::native<::NSEvent>(event)]);
    }

    double Browser::column_content_width_for_column_width(double column_width) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSBrowser>(this) columnContentWidthForColumnWidth:static_cast<::CGFloat>(column_width)]);
    }

    double Browser::column_width_for_column_content_width(double column_content_width) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSBrowser>(this) columnWidthForColumnContentWidth:static_cast<::CGFloat>(column_content_width)]);
    }

    double Browser::default_column_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSBrowser>(this) defaultColumnWidth]);
    }

    void Browser::do_click(const Object& sender) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) doClick:cocoon::internal::native_id(sender)];
    }

    void Browser::do_double_click(const Object& sender) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) doDoubleClick:cocoon::internal::native_id(sender)];
    }

    Image Browser::dragging_image_for_rows_with_indexes(const IndexSet& row_indexes, std::int64_t column, const Event& event, Point* drag_image_offset) const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSBrowser>(this) draggingImageForRowsWithIndexes:cocoon::internal::native<::NSIndexSet>(row_indexes) inColumn:static_cast<::NSInteger>(column) withEvent:cocoon::internal::native<::NSEvent>(event) offset:(::NSPointPointer)(drag_image_offset)]);
    }

    void Browser::draw_title_of_column(std::int64_t column, const Rect& rect) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) drawTitleOfColumn:static_cast<::NSInteger>(column) inRect:cocoon::internal::to(rect)];
    }

    void Browser::edit_item_at_index_path(const IndexPath& index_path, const Event& event, bool select) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) editItemAtIndexPath:cocoon::internal::native<::NSIndexPath>(index_path) withEvent:cocoon::internal::native<::NSEvent>(event) select:static_cast<::BOOL>(select)];
    }

    Rect Browser::frame_of_column(std::int64_t column) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBrowser>(this) frameOfColumn:static_cast<::NSInteger>(column)]);
    }

    Rect Browser::frame_of_inside_of_column(std::int64_t column) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBrowser>(this) frameOfInsideOfColumn:static_cast<::NSInteger>(column)]);
    }

    Rect Browser::frame_of_row(std::int64_t row, std::int64_t column) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBrowser>(this) frameOfRow:static_cast<::NSInteger>(row) inColumn:static_cast<::NSInteger>(column)]);
    }

    bool Browser::get_row(std::int64_t* row, std::int64_t* column, const Point& point) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) getRow:(::NSInteger*)(row) column:(::NSInteger*)(column)forPoint:cocoon::internal::to(point)]);
    }

    IndexPath Browser::index_path_for_column(std::int64_t column) const
    {
        return cocoon::internal::wrap<IndexPath>([cocoon::internal::ns<::NSBrowser>(this) indexPathForColumn:static_cast<::NSInteger>(column)]);
    }

    bool Browser::is_leaf_item(const Object& item) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) isLeafItem:cocoon::internal::native_id(item)]);
    }

    Object Browser::item_at_index_path(const IndexPath& index_path) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSBrowser>(this) itemAtIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    Object Browser::item_at_row(std::int64_t row, std::int64_t column) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSBrowser>(this) itemAtRow:static_cast<::NSInteger>(row) inColumn:static_cast<::NSInteger>(column)]);
    }

    void Browser::load_column_zero() const
    {
        [cocoon::internal::ns<::NSBrowser>(this) loadColumnZero];
    }

    Object Browser::loaded_cell_at_row(std::int64_t row, std::int64_t col) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSBrowser>(this) loadedCellAtRow:static_cast<::NSInteger>(row) column:static_cast<::NSInteger>(col)]);
    }

    void Browser::note_height_of_rows_with_indexes_changed(const IndexSet& index_set, std::int64_t column_index) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) noteHeightOfRowsWithIndexesChanged:cocoon::internal::native<::NSIndexSet>(index_set) inColumn:static_cast<::NSInteger>(column_index)];
    }

    Object Browser::parent_for_items_in_column(std::int64_t column) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSBrowser>(this) parentForItemsInColumn:static_cast<::NSInteger>(column)]);
    }

    std::string Browser::path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBrowser>(this) path]);
    }

    std::string Browser::path_to_column(std::int64_t column) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBrowser>(this) pathToColumn:static_cast<::NSInteger>(column)]);
    }

    void Browser::reload_column(std::int64_t column) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) reloadColumn:static_cast<::NSInteger>(column)];
    }

    void Browser::reload_data_for_row_indexes(const IndexSet& row_indexes, std::int64_t column) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) reloadDataForRowIndexes:cocoon::internal::native<::NSIndexSet>(row_indexes) inColumn:static_cast<::NSInteger>(column)];
    }

    void Browser::remove_saved_columns_with_autosave_name(const std::string& name)
    {
        [::NSBrowser removeSavedColumnsWithAutosaveName:cocoon::internal::to(name)];
    }

    void Browser::scroll_column_to_visible(std::int64_t column) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) scrollColumnToVisible:static_cast<::NSInteger>(column)];
    }

    void Browser::scroll_columns_left_by(std::int64_t shift_amount) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) scrollColumnsLeftBy:static_cast<::NSInteger>(shift_amount)];
    }

    void Browser::scroll_columns_right_by(std::int64_t shift_amount) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) scrollColumnsRightBy:static_cast<::NSInteger>(shift_amount)];
    }

    void Browser::scroll_row_to_visible(std::int64_t row, std::int64_t column) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) scrollRowToVisible:static_cast<::NSInteger>(row) inColumn:static_cast<::NSInteger>(column)];
    }

    void Browser::select_all(const Object& sender) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) selectAll:cocoon::internal::native_id(sender)];
    }

    void Browser::select_row(std::int64_t row, std::int64_t column) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) selectRow:static_cast<::NSInteger>(row) inColumn:static_cast<::NSInteger>(column)];
    }

    void Browser::select_row_indexes(const IndexSet& indexes, std::int64_t column) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) selectRowIndexes:cocoon::internal::native<::NSIndexSet>(indexes) inColumn:static_cast<::NSInteger>(column)];
    }

    Object Browser::selected_cell_in_column(std::int64_t column) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSBrowser>(this) selectedCellInColumn:static_cast<::NSInteger>(column)]);
    }

    std::int64_t Browser::selected_row_in_column(std::int64_t column) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBrowser>(this) selectedRowInColumn:static_cast<::NSInteger>(column)]);
    }

    IndexSet Browser::selected_row_indexes_in_column(std::int64_t column) const
    {
        return cocoon::internal::wrap<IndexSet>([cocoon::internal::ns<::NSBrowser>(this) selectedRowIndexesInColumn:static_cast<::NSInteger>(column)]);
    }

    bool Browser::send_action() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) sendAction]);
    }

    void Browser::set_cell_class(const std::string& factory_id) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setCellClass:NSClassFromString(cocoon::internal::to(factory_id))];
    }

    void Browser::set_default_column_width(double column_width) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setDefaultColumnWidth:static_cast<::CGFloat>(column_width)];
    }

    void Browser::set_dragging_source_operation_mask(DragOperation mask, bool is_local) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setDraggingSourceOperationMask:static_cast<::NSDragOperation>(mask) forLocal:static_cast<::BOOL>(is_local)];
    }

    bool Browser::set_path(const std::string& path) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) setPath:cocoon::internal::to(path)]);
    }

    void Browser::set_title(const std::string& string, std::int64_t column) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setTitle:cocoon::internal::to(string) ofColumn:static_cast<::NSInteger>(column)];
    }

    void Browser::set_width(double column_width, std::int64_t column_index) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setWidth:static_cast<::CGFloat>(column_width) ofColumn:static_cast<::NSInteger>(column_index)];
    }

    void Browser::tile() const
    {
        [cocoon::internal::ns<::NSBrowser>(this) tile];
    }

    Rect Browser::title_frame_of_column(std::int64_t column) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBrowser>(this) titleFrameOfColumn:static_cast<::NSInteger>(column)]);
    }

    std::string Browser::title_of_column(std::int64_t column) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBrowser>(this) titleOfColumn:static_cast<::NSInteger>(column)]);
    }

    void Browser::validate_visible_columns() const
    {
        [cocoon::internal::ns<::NSBrowser>(this) validateVisibleColumns];
    }

    double Browser::width_of_column(std::int64_t column) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSBrowser>(this) widthOfColumn:static_cast<::NSInteger>(column)]);
    }

    bool Browser::allows_branch_selection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) allowsBranchSelection]);
    }

    void Browser::set_allows_branch_selection(bool value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setAllowsBranchSelection:static_cast<::BOOL>(value)];
    }

    bool Browser::allows_empty_selection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) allowsEmptySelection]);
    }

    void Browser::set_allows_empty_selection(bool value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setAllowsEmptySelection:static_cast<::BOOL>(value)];
    }

    bool Browser::allows_multiple_selection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) allowsMultipleSelection]);
    }

    void Browser::set_allows_multiple_selection(bool value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setAllowsMultipleSelection:static_cast<::BOOL>(value)];
    }

    bool Browser::allows_type_select() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) allowsTypeSelect]);
    }

    void Browser::set_allows_type_select(bool value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setAllowsTypeSelect:static_cast<::BOOL>(value)];
    }

    bool Browser::autohides_scroller() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) autohidesScroller]);
    }

    void Browser::set_autohides_scroller(bool value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setAutohidesScroller:static_cast<::BOOL>(value)];
    }

    Color Browser::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSBrowser>(this) backgroundColor]);
    }

    void Browser::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    std::string Browser::cell_class()
    {
        return cocoon::internal::from(NSStringFromClass([::NSBrowser cellClass]));
    }

    Object Browser::cell_prototype() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSBrowser>(this) cellPrototype]);
    }

    void Browser::set_cell_prototype(const Object& value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setCellPrototype:cocoon::internal::native_id(value)];
    }

    std::int64_t Browser::clicked_column() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBrowser>(this) clickedColumn]);
    }

    std::int64_t Browser::clicked_row() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBrowser>(this) clickedRow]);
    }

    BrowserColumnResizingType Browser::column_resizing_type() const
    {
        return static_cast<BrowserColumnResizingType>([cocoon::internal::ns<::NSBrowser>(this) columnResizingType]);
    }

    void Browser::set_column_resizing_type(BrowserColumnResizingType value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setColumnResizingType:static_cast<::NSBrowserColumnResizingType>(value)];
    }

    std::string Browser::columns_autosave_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBrowser>(this) columnsAutosaveName]);
    }

    void Browser::set_columns_autosave_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setColumnsAutosaveName:cocoon::internal::to(value)];
    }

    std::string Browser::double_action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSBrowser>(this) doubleAction]));
    }

    void Browser::set_double_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setDoubleAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    std::int64_t Browser::first_visible_column() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBrowser>(this) firstVisibleColumn]);
    }

    bool Browser::has_horizontal_scroller() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) hasHorizontalScroller]);
    }

    void Browser::set_has_horizontal_scroller(bool value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setHasHorizontalScroller:static_cast<::BOOL>(value)];
    }

    std::int64_t Browser::last_column() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBrowser>(this) lastColumn]);
    }

    void Browser::set_last_column(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setLastColumn:static_cast<::NSInteger>(value)];
    }

    std::int64_t Browser::last_visible_column() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBrowser>(this) lastVisibleColumn]);
    }

    bool Browser::is_loaded() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) isLoaded]);
    }

    std::int64_t Browser::max_visible_columns() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBrowser>(this) maxVisibleColumns]);
    }

    void Browser::set_max_visible_columns(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setMaxVisibleColumns:static_cast<::NSInteger>(value)];
    }

    double Browser::min_column_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSBrowser>(this) minColumnWidth]);
    }

    void Browser::set_min_column_width(double value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setMinColumnWidth:static_cast<::CGFloat>(value)];
    }

    std::int64_t Browser::number_of_visible_columns() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBrowser>(this) numberOfVisibleColumns]);
    }

    std::string Browser::path_separator() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBrowser>(this) pathSeparator]);
    }

    void Browser::set_path_separator(const std::string& value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setPathSeparator:cocoon::internal::to(value)];
    }

    bool Browser::prefers_all_column_user_resizing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) prefersAllColumnUserResizing]);
    }

    void Browser::set_prefers_all_column_user_resizing(bool value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setPrefersAllColumnUserResizing:static_cast<::BOOL>(value)];
    }

    bool Browser::reuses_columns() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) reusesColumns]);
    }

    void Browser::set_reuses_columns(bool value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setReusesColumns:static_cast<::BOOL>(value)];
    }

    double Browser::row_height() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSBrowser>(this) rowHeight]);
    }

    void Browser::set_row_height(double value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setRowHeight:static_cast<::CGFloat>(value)];
    }

    Object Browser::selected_cell() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSBrowser>(this) selectedCell]);
    }

    std::vector<Cell> Browser::selected_cells() const
    {
        return cocoon::internal::from_array<Cell>([cocoon::internal::ns<::NSBrowser>(this) selectedCells], [](id e) -> Cell
                                                  {
                                                      return cocoon::internal::wrap<Cell>((::NSCell*)e);
                                                  });
    }

    std::int64_t Browser::selected_column() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBrowser>(this) selectedColumn]);
    }

    IndexPath Browser::selection_index_path() const
    {
        return cocoon::internal::wrap<IndexPath>([cocoon::internal::ns<::NSBrowser>(this) selectionIndexPath]);
    }

    void Browser::set_selection_index_path(const IndexPath& value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setSelectionIndexPath:cocoon::internal::native<::NSIndexPath>(value)];
    }

    std::vector<IndexPath> Browser::selection_index_paths() const
    {
        return cocoon::internal::from_array<IndexPath>([cocoon::internal::ns<::NSBrowser>(this) selectionIndexPaths], [](id e) -> IndexPath
                                                       {
                                                           return cocoon::internal::wrap<IndexPath>((::NSIndexPath*)e);
                                                       });
    }

    void Browser::set_selection_index_paths(const std::vector<IndexPath>& value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setSelectionIndexPaths:cocoon::internal::to_array(value, [](const IndexPath& e) -> id
                                                                                                   {
                                                                                                       return cocoon::internal::native<::NSIndexPath>(e);
                                                                                                   })];
    }

    bool Browser::sends_action_on_arrow_keys() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) sendsActionOnArrowKeys]);
    }

    void Browser::set_sends_action_on_arrow_keys(bool value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setSendsActionOnArrowKeys:static_cast<::BOOL>(value)];
    }

    bool Browser::separates_columns() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) separatesColumns]);
    }

    void Browser::set_separates_columns(bool value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setSeparatesColumns:static_cast<::BOOL>(value)];
    }

    bool Browser::takes_title_from_previous_column() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) takesTitleFromPreviousColumn]);
    }

    void Browser::set_takes_title_from_previous_column(bool value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setTakesTitleFromPreviousColumn:static_cast<::BOOL>(value)];
    }

    double Browser::title_height() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSBrowser>(this) titleHeight]);
    }

    bool Browser::is_titled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowser>(this) isTitled]);
    }

    void Browser::set_titled(bool value) const
    {
        [cocoon::internal::ns<::NSBrowser>(this) setTitled:static_cast<::BOOL>(value)];
    }

    void Browser::install_delegate_delegate_(void* native)
    {
        ::NSBrowser* host = (__bridge ::NSBrowser*)native;
        AKBrowserDelegate* delegate = [[AKBrowserDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSBrowser* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSBrowser* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
