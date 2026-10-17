#pragma once

#include "generated/availability.h"
#include "generated/control.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Cell;
    class Color;
    class DraggingSession;
    class Event;
    class Image;
    class IndexSet;
    class Nib;
    class Notification;
    class SortDescriptor;
    class TableColumn;
    class TableHeaderView;
    class TableRowView;
    class TableViewRowAction;
    class Text;
    class TextView;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSTableView` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TableView table_view;
     * table_view.set_allows_column_reordering(true);
     * table_view.set_object_value_for_table_column_row().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TableView table_view{};
     * table_view.set_allows_column_reordering(true);
     * auto allows_column_reordering = table_view.allows_column_reordering();
     * table_view.set_allows_column_resizing(true);
     * auto allows_column_resizing = table_view.allows_column_resizing();
     * table_view.set_allows_column_selection(true);
     * auto allows_column_selection = table_view.allows_column_selection();
     * table_view.add_table_column(cocoon::TableColumn());
     * table_view.begin_updates();
     * table_view.can_drag_rows_with_indexes(cocoon::IndexSet(), {0, 0});
     * table_view.set_object_value_for_table_column_row().connect([](cocoon::Object a0, cocoon::TableColumn a1, std::int64_t a2) {});
     * table_view.sort_descriptors_did_change().connect([](std::vector<cocoon::SortDescriptor> a0) {});
     * table_view.dragging_session_will_begin_at_point_for_row_indexes().connect([](cocoon::DraggingSession a0, cocoon::Point a1, cocoon::IndexSet a2) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstableview
     */
    class TableView : public Control
    {
    public:
        /// @brief Creates a new `NSTableView` instance and returns a handle to it.
        explicit TableView(const Rect& frame_rect);
        /// @brief Creates a new `NSTableView` instance and returns a handle to it.
        explicit TableView();
        /// @brief Creates a null handle that refers to no native object.
        TableView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TableView(Adopt adopt);
        using Control::size_to_fit;
        using View::set_background_color;
        using View::set_user_interface_layout_direction;
        using View::user_interface_layout_direction;
        /**
     * @brief Calls `-[NSTableView addTableColumn:]`.
     * @details Adds 'tableColumn' to the end of the -tableColumns array and retiles the tableView. 'tableColumn' must be non-nil, otherwise an exception will be raised.
     * @param table_column Argument converted to the Objective-C parameter of the same role.
     */
        void add_table_column(const TableColumn& table_column) const;
        /**
     * @brief Calls `-[NSTableView beginUpdates]`.
     * @details View Based TableView: Multiple row changes (inserts/deletes/moves/scrolling) can be animated simultaneously by surrounding calls around a beginUpdates/endUpdates pair. When changing rows, the prior state before -beginUpdates is the starting point assumed for all deletion and move calls. Calls are nestable. -selectedRowIndexes is properly maintained based on the series of inserts/deletes/moves. If a selected row is deleted, a selection changed notification will happen after endUpdates is called. It is not necessary to call beginUpdates/endUpdates if only one insertion/deletion/move is happening. Note that these methods should be called to reflect changes in your model; they do not make any underlying model changes. Cell Based TableView: Any row modifications must first be wrapped in a -beginUpdates/-endUpdates block -- this is required to properly maintain state and to allow animations to happen.
     */
        void begin_updates() const;
        /**
     * @brief Calls `-[NSTableView canDragRowsWithIndexes:atPoint:]`.
     * @details The return value indicates whether the receiver can attempt to initiate a row drag at 'mouseDownPoint'. Return NO to disallow initiating drags at the given location. For applications linked on and after Leopard, NSCell hit testing will determine if a row can be dragged or not. Custom cells should properly implement [NSCell(NSCellHitTest) hitTestForEvent:inRect:ofView]; see NSCell.h for more information. NSTableView will not begin a drag if cell returns NSCellHitTrackableArea (ie: NSButtonCells).
     * @param row_indexes Argument converted to the Objective-C parameter of the same role.
     * @param mouse_down_point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool can_drag_rows_with_indexes(const IndexSet& row_indexes, const Point& mouse_down_point) const;
        /**
     * @brief Calls `-[NSTableView columnAtPoint:]`.
     * @details Returns the column index at 'point', or -1 if 'point' is outside of all table columns.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t column_at_point(const Point& point) const;
        /**
     * @brief Calls `-[NSTableView columnForView:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t column_for_view(const View& view) const;
        /**
     * @brief Calls `-[NSTableView columnIndexesInRect:]`.
     * @details Returns the indexes for columns in 'rect'. NSTableColumns which have -isHidden == YES are not returned. If 'rect' is empty, no indexes will be returned. Introduced in Mac OS 10.5.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        IndexSet column_indexes_in_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSTableView columnWithIdentifier:]`.
     * @details Returns the first index of the NSTableColumn instance with the -identifier that isEqual to 'identifier'. Returns -1 if 'identifier' can not be found. In 10.7, the identifier was changed from NSString to id.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t column_with_identifier(const std::string& identifier) const;
        /**
     * @brief Calls `-[NSTableView deselectAll:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void deselect_all(const Object& sender) const;
        /**
     * @brief Calls `-[NSTableView deselectColumn:]`.
     * @param column Argument converted to the Objective-C parameter of the same role.
     */
        void deselect_column(std::int64_t column) const;
        /**
     * @brief Calls `-[NSTableView deselectRow:]`.
     * @param row Argument converted to the Objective-C parameter of the same role.
     */
        void deselect_row(std::int64_t row) const;
        /**
     * @brief Calls `-[NSTableView didAddRowView:forRow:]`.
     * @details View Based TableView: The subclass can implement this method to be alerted when a new 'rowView' has been added to the table. At this point, the subclass can choose to add in extra views, or modify any properties on 'rowView'. Be sure to call 'super'.
     * @param row_view Argument converted to the Objective-C parameter of the same role.
     * @param row Argument converted to the Objective-C parameter of the same role.
     */
        void did_add_row_view(const TableRowView& row_view, std::int64_t row) const;
        /**
     * @brief Calls `-[NSTableView didRemoveRowView:forRow:]`.
     * @details View Based TableView: The subclass can implement this method to be alerted when 'rowView' has been removed from the table. The removed 'rowView' may be reused by the table, so any additionally inserted views should be removed at this point. A 'row' parameter is included. 'row' will be '-1' for rows that are being deleted from the table, and no longer have a valid row, otherwise it will be the valid row that is being removed due to it being moved off screen. Be sure to call 'super'.
     * @param row_view Argument converted to the Objective-C parameter of the same role.
     * @param row Argument converted to the Objective-C parameter of the same role.
     */
        void did_remove_row_view(const TableRowView& row_view, std::int64_t row) const;
        /**
     * @brief Calls `-[NSTableView dragImageForRowsWithIndexes:tableColumns:event:offset:]`.
     * @details This method computes and returns an image to use for dragging. Override this to return a custom image. 'dragRows' represents the rows participating in the drag. 'tableColumns' represent the columns that should be in the output image. Note that drawing may be clipped to the visible rows, and columns. 'dragEvent' is a reference to the mouse down event that began the drag. 'dragImageOffset' is an in/out parameter. This method will be called with dragImageOffset set to NSZeroPoint, but it can be modified to re-position the returned image. A dragImageOffset of NSZeroPoint will cause the image to be centered under the mouse. Compatability Note: This method replaces dragImageForRows:event:dragImageOffset:. If present, this is used instead of the deprecated method.
     * @param drag_rows Argument converted to the Objective-C parameter of the same role.
     * @param table_columns Argument converted to the Objective-C parameter of the same role.
     * @param drag_event Argument converted to the Objective-C parameter of the same role.
     * @param drag_image_offset Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Image drag_image_for_rows_with_indexes(const IndexSet& drag_rows, const std::vector<TableColumn>& table_columns, const Event& drag_event, Point* drag_image_offset) const;
        /**
     * @brief Calls `-[NSTableView drawBackgroundInClipRect:]`.
     * @details Override to customize background drawing.
     * @param clip_rect Argument converted to the Objective-C parameter of the same role.
     */
        void draw_background_in_clip_rect(const Rect& clip_rect) const;
        /**
     * @brief Calls `-[NSTableView drawGridInClipRect:]`.
     * @details Override to customize grid drawing.
     * @param clip_rect Argument converted to the Objective-C parameter of the same role.
     */
        void draw_grid_in_clip_rect(const Rect& clip_rect) const;
        /**
     * @brief Calls `-[NSTableView drawRow:clipRect:]`.
     * @details View Based TableView: This method should not be subclassed or overridden for a "View Based TableView". Instead, row drawing customization can be done by subclassing NSTableRowView. Cell Based TableView: This method can be overriden to customize drawing for 'row'.
     * @param row Argument converted to the Objective-C parameter of the same role.
     * @param clip_rect Argument converted to the Objective-C parameter of the same role.
     */
        void draw_row(std::int64_t row, const Rect& clip_rect) const;
        /**
     * @brief Calls `-[NSTableView editColumn:row:withEvent:select:]`.
     * @details View Based TableView: This method attempts to make the view at 'column/row' the first responder, which will begin editing if the view supports editing. Cell Based TableView: This method edits the NSCell located at 'column/row' by calling the following NSCell method: - (void)editWithFrame:(NSRect)rect inView:(NSView )controlView editor:(NSText )textObj delegate:(id)delegate event:(NSEvent )event; or, if 'select' is YES: - (void)selectWithFrame:(NSRect)rect inView:(NSView )controlView editor:(NSText )textObj delegate:(id)delegate start:(NSInteger)selStart length:(NSInteger)selLength;
     * @param column Argument converted to the Objective-C parameter of the same role.
     * @param row Argument converted to the Objective-C parameter of the same role.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param select Argument converted to the Objective-C parameter of the same role.
     */
        void edit_column(std::int64_t column, std::int64_t row, const Event& event, bool select) const;
        /**
     * @brief Calls `-[NSTableView endUpdates]`.
     */
        void end_updates() const;
        /**
     * @brief Calls `-[NSTableView enumerateAvailableRowViewsUsingBlock:]`.
     * @details Enumerates all available NSTableRowViews. This includes all views in the -visibleRect, however, it may also include ones that are "in flight" due to animations or other various attributes of the table.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_available_row_views_using_block(std::function<void(TableRowView, std::int64_t)> handler) const;
        /**
     * @brief Calls `-[NSTableView frameOfCellAtColumn:row:]`.
     * @details Returns the frame of the cell at 'row' / 'column'. If the 'row' is a "full width" row, the frame returned will be equal to the width of the row. If the NSTableColumn at 'column' has -isHidden == YES, or if the values are outside acceptable ranges, NSZeroRect is returned.
     * @param column Argument converted to the Objective-C parameter of the same role.
     * @param row Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect frame_of_cell_at_column(std::int64_t column, std::int64_t row) const;
        /**
     * @brief Calls `-[NSTableView hideRowsAtIndexes:withAnimation:]`.
     * @details View Based TableView: API to hide and unhide rows. Sometimes, it is better or easier to simply hide a row instead of permanently removing it from the table. Hiding it allows the model to not change, but the UI to appear as though it doesn't exist. Hidden rows will have a zero height, and not be selectable by the user (but can still be programmatically selected). Be aware that hiding a selected row will leave it selected. Hiding a row will call the delegate methods tableView:didRemoveRowView:forRow:, and unhiding will subsequently call tableView:didAddRowView:forRow:.
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     * @param row_animation Argument converted to the Objective-C parameter of the same role.
     */
        void hide_rows_at_indexes(const IndexSet& indexes, TableViewAnimationOptions row_animation) const;
        /**
     * @brief Calls `-[NSTableView highlightSelectionInClipRect:]`.
     * @details View Based TableView: This method should not be subclassed or overridden for a "View Based TableView". Instead, row drawing customization can be done by subclassing NSTableRowView. Cell Based TableView: This method can be overriden to customize selection highlighting. 10.10: This method will not be called if the selectionHighlightStyle is set to NSTableViewSelectionHighlightStyleSourceList.
     * @param clip_rect Argument converted to the Objective-C parameter of the same role.
     */
        void highlight_selection_in_clip_rect(const Rect& clip_rect) const;
        /**
     * @brief Calls `-[NSTableView indicatorImageInTableColumn:]`.
     * @param table_column Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Image indicator_image_in_table_column(const TableColumn& table_column) const;
        /**
     * @brief Calls `-[NSTableView insertRowsAtIndexes:withAnimation:]`.
     * @details Inserts a new rows located at the final positions passed to by 'indexes'. This is similar to NSMutableArray's -insertObjects:atIndexes: The -numberOfRows in the TableView will automatically be increased by the count in 'indexes'. Calling this method multiple times within the same beginUpdates/endUpdates block is allowed, and changes are processed incrementally. This method should not be called for NSOutlineView (use -insertItemsAtIndexes:inParent:withAnimation: instead). The "Cell Based TableView" must first call -beginUpdates before calling this method. This method can also be used when "usesStaticContents=YES".
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     * @param animation_options Argument converted to the Objective-C parameter of the same role.
     */
        void insert_rows_at_indexes(const IndexSet& indexes, TableViewAnimationOptions animation_options) const;
        /**
     * @brief Calls `-[NSTableView isColumnSelected:]`.
     * @param column Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_column_selected(std::int64_t column) const;
        /**
     * @brief Calls `-[NSTableView isRowSelected:]`.
     * @param row Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_row_selected(std::int64_t row) const;
        /**
     * @brief Calls `-[NSTableView makeViewWithIdentifier:owner:]`.
     * @details View Based TableView: Returns an autoreleased view with a particular 'identifier'. Typically the 'identifier' is associated with a particular "cell view" in IB. The TableView will automatically instantiate the embedded view with the provided owner. This method will typically be called by the delegate in -viewForTableColumn:row:, but it can also be overridden to provide custom views for a particular 'identifier'. This method may also return a reused view with the same 'identifier' that was no longer available on screen. 'identifier' can not be nil. Note that 'owner' will get an 'awakeFromNib:' call each time the object is instantiated.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @param owner Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        View make_view_with_identifier(const std::string& identifier, const Object& owner) const;
        /**
     * @brief Calls `-[NSTableView moveColumn:toColumn:]`.
     * @details Moves the the tableColumn at 'oldIndex' to 'newIndex'. 'oldIndex' and 'newIndex' must be in the range: 0 to [tableView numberOfColumns]-1, otherwise an exception will be raised.
     * @param old_index Argument converted to the Objective-C parameter of the same role.
     * @param new_index Argument converted to the Objective-C parameter of the same role.
     */
        void move_column(std::int64_t old_index, std::int64_t new_index) const;
        /**
     * @brief Calls `-[NSTableView moveRowAtIndex:toIndex:]`.
     * @details Moves a row from the prior 'oldIndex' to 'newIndex' in an animated fashion (if needed). This is similar to removing a row at 'oldIndex' and inserting it back at 'newIndex', except the same view is used and simply has its position updated to the new location. This method can be called multiple times within the same beginUpdates/endUpdates block. This method should not be called for NSOutlineView (use -moveItemAtIndex:inParent:toIndex:inParent: instead). The "Cell Based TableView" must first call -beginUpdates before calling this method. This method can also be used when "usesStaticContents=YES".
     * @param old_index Argument converted to the Objective-C parameter of the same role.
     * @param new_index Argument converted to the Objective-C parameter of the same role.
     */
        void move_row_at_index(std::int64_t old_index, std::int64_t new_index) const;
        /**
     * @brief Calls `-[NSTableView noteHeightOfRowsWithIndexesChanged:]`.
     * @details If the delegate implements -tableView:heightOfRow:, this method immediately re-tiles the table view using row heights it provides.
     * @param index_set Argument converted to the Objective-C parameter of the same role.
     */
        void note_height_of_rows_with_indexes_changed(const IndexSet& index_set) const;
        /**
     * @brief Calls `-[NSTableView noteNumberOfRowsChanged]`.
     * @details Cell Based TableView: This method tells the table that there may be more (or less) rows available and to reload state based on that information. View Based TableView: This method can only be used to increase or decrease the number of rows in the table. The table will query the datasource for the new number of rows, and properly insert (or remove) rows at the end of the table as necessary with an animation. This method does NOT work for NSOutlineView, and should not be called.
     */
        void note_number_of_rows_changed() const;
        /**
     * @brief Calls `-[NSTableView rectOfColumn:]`.
     * @details Returns the rectangle for 'column'. Returns NSZeroRect if the NSTableColumn at 'column' has -isHidden == YES, or if 'column' is less than 0, or if 'column' is greater than or equal to the number of columns in the NSTableView.
     * @param column Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect rect_of_column(std::int64_t column) const;
        /**
     * @brief Calls `-[NSTableView rectOfRow:]`.
     * @details Returns the rectange for 'row'. If 'row' is \< 0 or >= [self numberOfRows], then NSZeroRect is returned.
     * @param row Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect rect_of_row(std::int64_t row) const;
        /**
     * @brief Calls `-[NSTableView registerNib:forIdentifier:]`.
     * @details View Based TableView: Registers (or associates) the 'nib' with 'identifier' so the table can instantiate views from it when a view with 'identifier' is requested. Generally, this means one calls -makeViewWithIdentifier:'identifier' owner:, and there was no NIB created at design time for this particular table view that could be found. This allows dynamic loading of nibs that can be associated with the table. To remove a previously associated NIB for a given identifier, pass in 'nil' for the nib value.
     * @param nib Argument converted to the Objective-C parameter of the same role.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     */
        void register_nib(const Nib& nib, const std::string& identifier) const;
        /**
     * @brief Calls `-[NSTableView reloadData]`.
     * @details Reloads the table. View Based TableView: This drops all known views, and row heights, and lazily reloads all information. The selected rows are not maintained. To properly maintain selection, use the insert/remove/move API.
     */
        void reload_data() const;
        /**
     * @brief Calls `-[NSTableView reloadDataForRowIndexes:columnIndexes:]`.
     * @details Updates a particular row of cells for a given set of 'rowIndexes' in 'columnIndexes'. For cells that are visible, appropriate dataSource and delegate methods will be called and the cells will be redrawn. For tables that support variable row heights, the row height will not be re-queried from the delegate; -noteHeightOfRowsWithIndexesChanged: should be used if a row height change is required.
     * @param row_indexes Argument converted to the Objective-C parameter of the same role.
     * @param column_indexes Argument converted to the Objective-C parameter of the same role.
     */
        void reload_data_for_row_indexes(const IndexSet& row_indexes, const IndexSet& column_indexes) const;
        /**
     * @brief Calls `-[NSTableView removeRowsAtIndexes:withAnimation:]`.
     * @details Removes a row currently at each row in 'indexes'. This is similar to NSMutableArray's -removeObjectsAtIndexes:. The row indexes should be with respect to the current state displayed in the TableView, and not the final state (since the rows do not exist in the final state). The -numberOfRows in the TableView will automatically be decreased by the count in 'indexes'. Calling this method multiple times within the same beginUpdates/endUpdates block is allowed, and changes are processed incrementally. This method should not be called for NSOutlineView (use -removeItemsAtIndexes:inParent:withAnimation: instead). The "Cell Based TableView" must first call -beginUpdates before calling this method. This method can also be used when "usesStaticContents=YES".
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     * @param animation_options Argument converted to the Objective-C parameter of the same role.
     */
        void remove_rows_at_indexes(const IndexSet& indexes, TableViewAnimationOptions animation_options) const;
        /**
     * @brief Calls `-[NSTableView removeTableColumn:]`.
     * @details Removes 'tableColumn' from the -tableColumns array and retiles the tableView.
     * @param table_column Argument converted to the Objective-C parameter of the same role.
     */
        void remove_table_column(const TableColumn& table_column) const;
        /**
     * @brief Calls `-[NSTableView rowAtPoint:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t row_at_point(const Point& point) const;
        /**
     * @brief Calls `-[NSTableView rowForView:]`.
     * @details View Based TableView: Access to the row/column for a particular view. Returns -1 if the view is not an instance of, or a subview of NSTableRowView. This is typically needed in the action method for an NSButton (or NSControl) to find out what row (and column) the action should be performed on. The implementation is O(n) where n is the number of visible rows, so this method should generally not be called within a loop.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t row_for_view(const View& view) const;
        /**
     * @brief Calls `-[NSTableView rowViewAtRow:makeIfNecessary:]`.
     * @param row Argument converted to the Objective-C parameter of the same role.
     * @param make_if_necessary Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TableRowView row_view_at_row(std::int64_t row, bool make_if_necessary) const;
        /**
     * @brief Calls `-[NSTableView rowsInRect:]`.
     * @details Returns the range of rows in 'rect'. If 'rect' is empty, or if there are no rows, an empty range will be returned. If 'rect' is outside of -[NSTableView bounds], 'rect' will be intersected to only look in the bounds.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range rows_in_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSTableView scrollColumnToVisible:]`.
     * @param column Argument converted to the Objective-C parameter of the same role.
     */
        void scroll_column_to_visible(std::int64_t column) const;
        /**
     * @brief Calls `-[NSTableView scrollRowToVisible:]`.
     * @param row Argument converted to the Objective-C parameter of the same role.
     */
        void scroll_row_to_visible(std::int64_t row) const;
        /**
     * @brief Calls `-[NSTableView selectAll:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void select_all(const Object& sender) const;
        /**
     * @brief Calls `-[NSTableView selectColumnIndexes:byExtendingSelection:]`.
     * @details Sets the column selection using the indexes. Selection is set/extended based on the extend flag. Compatability Note: This method replaces selectColumn:byExtendingSelection: If a subclasser implements only the deprecated single-index method (selectColumn:byExtendingSelection:), the single-index method will be invoked for each index. If a subclasser implements the multi-index method (selectColumnIndexes:byExtendingSelection:), the deprecated single-index version method will not be used. This allows subclassers already overriding the single-index method to still receive a selection message. Note: to avoid cycles, subclassers of this method and single-index method should not call each other.
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     * @param extend Argument converted to the Objective-C parameter of the same role.
     */
        void select_column_indexes(const IndexSet& indexes, bool extend) const;
        /**
     * @brief Calls `-[NSTableView selectRowIndexes:byExtendingSelection:]`.
     * @details Sets the row selection using 'indexes'. Selection is set/extended based on the extend flag. On 10.5 and greater, selectRowIndexes:byExtendingSelection: will allow you to progrmatically select more than one index, regardless of the allowsMultipleSelection and allowsEmptySelection options set on the table. View Based TableViews: This method is animatable by using the animator proxy. IE: [tableView.animator selectRowIndexes:.. byExtendingSelection:..]; Compatability Note: This method replaces selectRow:byExtendingSelection: If a subclasser implements only the deprecated single-index method (selectRow:byExtendingSelection:), the single-index method will be invoked for each index. If a subclasser implements the multi-index method (selectRowIndexes:byExtendingSelection:), the deprecated single-index version method will not be used. This allows subclassers already overriding the single-index method to still receive a selection message. Note: to avoid cycles, subclassers of this method and single-index method should not call each other.
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     * @param extend Argument converted to the Objective-C parameter of the same role.
     */
        void select_row_indexes(const IndexSet& indexes, bool extend) const;
        /**
     * @brief Calls `-[NSTableView setDraggingSourceOperationMask:forLocal:]`.
     * @details Configures the default value returned from -draggingSourceOperationMaskForLocal:. An isLocal value of YES indicates that 'mask' applies when the destination object is in the same application. A isLocal value of NO indicates that 'mask' applies when the destination object in an application outside the receiver's application. NSTableView will archive the values you set for each isLocal setting.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @param is_local Argument converted to the Objective-C parameter of the same role.
     */
        void set_dragging_source_operation_mask(DragOperation mask, bool is_local) const;
        /**
     * @brief Calls `-[NSTableView setDropRow:dropOperation:]`.
     * @details To be used from validateDrop: if you wish to "re-target" the proposed drop. To specify a drop on the second row, one would specify row=2, and dropOperation=NSTableViewDropOn. To specify a drop below the last row, one would specify row=[tableView numberOfRows], and dropOperation=NSTableViewDropAbove. To specify a drop on the entire tableview, one would specify row=-1 and dropOperation=NSTableViewDropOn.
     * @param row Argument converted to the Objective-C parameter of the same role.
     * @param drop_operation Argument converted to the Objective-C parameter of the same role.
     */
        void set_drop_row(std::int64_t row, TableViewDropOperation drop_operation) const;
        /**
     * @brief Calls `-[NSTableView setIndicatorImage:inTableColumn:]`.
     * @details Support for little "indicator" images in table header cells.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param table_column Argument converted to the Objective-C parameter of the same role.
     */
        void set_indicator_image(const Image& image, const TableColumn& table_column) const;
        /**
     * @brief Calls `-[NSTableView sizeLastColumnToFit]`.
     */
        void size_last_column_to_fit() const;
        /**
     * @brief Calls `-[NSTableView sizeToFit]`.
     */
        void size_to_fit() const;
        /**
     * @brief Calls `-[NSTableView tableColumnWithIdentifier:]`.
     * @details Returns the first NSTableColumn instance with the -identifier that isEqual to 'identifier'. Returns nil if 'identifier' can not be found. In 10.7, the identifier was changed from NSString to id.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TableColumn table_column_with_identifier(const std::string& identifier) const;
        /**
     * @brief Calls `-[NSTableView tile]`.
     * @details Causes the table to tile in size appropriate for the content. This method will be called automatically when necessary, and generally does not need to be called.
     */
        void tile() const;
        /**
     * @brief Calls `-[NSTableView unhideRowsAtIndexes:withAnimation:]`.
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     * @param row_animation Argument converted to the Objective-C parameter of the same role.
     */
        void unhide_rows_at_indexes(const IndexSet& indexes, TableViewAnimationOptions row_animation) const;
        /**
     * @brief Calls `-[NSTableView viewAtColumn:row:makeIfNecessary:]`.
     * @details View Based TableView: Access to a view (or row view) for a particular 'row' / 'column'. Returns 'nil' if there is no view at that location. An exception will be thrown if 'row' is not within the numberOfRows. The returned result is always an 'id' for easy assignment to local types, however, -viewAtColumn:row: will always return an NSView, and rowViewAtRow: will always return an NSTableRowView (or subclass thereof). The returned result should generally not be held onto for longer than the current run loop cycle. This method will first attempt to return a currently displayed view in the visible area. If there is no visible view, and makeIfNecessary is YES, a prepared temporary view is returned. If makeIfNecessary is NO, and the view is not visible, nil will be returned. In general, makeIfNecessary should be YES if you require a resulting view, and NO if you only want to update properties on a view only if it is available (generally this means it is visible).
     * @param column Argument converted to the Objective-C parameter of the same role.
     * @param row Argument converted to the Objective-C parameter of the same role.
     * @param make_if_necessary Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        View view_at_column(std::int64_t column, std::int64_t row, bool make_if_necessary) const;
        /**
     * @brief Returns the `allowsColumnReordering` property of `NSTableView`.
     * @details Get and set the allowsColumnReordering. Controls whether or not columns can be drag-reordered. The default value is YES.
     * @return The converted Objective-C result.
     */
        bool allows_column_reordering() const;
        /**
     * @brief Sets the `allowsColumnReordering` property of `NSTableView`.
     * @details Get and set the allowsColumnReordering. Controls whether or not columns can be drag-reordered. The default value is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_column_reordering(bool value) const;
        /**
     * @brief Returns the `allowsColumnResizing` property of `NSTableView`.
     * @details Get and set the allowsColumnResizing. Controls whether the user can attempt to resize columns by dragging between headers. If flag is YES the user can resize columns; if flag is NO the user can't. Columns can only be resized if a column allows user resizing. See -[NSTableColumn setResizingMask:] for more details. You can always change columns programmatically regardless of this setting. The default value is YES.
     * @return The converted Objective-C result.
     */
        bool allows_column_resizing() const;
        /**
     * @brief Sets the `allowsColumnResizing` property of `NSTableView`.
     * @details Get and set the allowsColumnResizing. Controls whether the user can attempt to resize columns by dragging between headers. If flag is YES the user can resize columns; if flag is NO the user can't. Columns can only be resized if a column allows user resizing. See -[NSTableColumn setResizingMask:] for more details. You can always change columns programmatically regardless of this setting. The default value is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_column_resizing(bool value) const;
        /**
     * @brief Returns the `allowsColumnSelection` property of `NSTableView`.
     * @details Get and set allowsColumnSelection. If -allowsColumnSelection is YES, clicking on column headers can select that column (which is reflected in -selectedColumnIndexes). The default value is NO.
     * @return The converted Objective-C result.
     */
        bool allows_column_selection() const;
        /**
     * @brief Sets the `allowsColumnSelection` property of `NSTableView`.
     * @details Get and set allowsColumnSelection. If -allowsColumnSelection is YES, clicking on column headers can select that column (which is reflected in -selectedColumnIndexes). The default value is NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_column_selection(bool value) const;
        /**
     * @brief Returns the `allowsEmptySelection` property of `NSTableView`.
     * @details Get and set allowsEmptySelection. If -allowsEmptySelection is YES, all rows can be deselected by the user. Otherwise, it is enforced that one row must be left selected at any given time. The default value is YES.
     * @return The converted Objective-C result.
     */
        bool allows_empty_selection() const;
        /**
     * @brief Sets the `allowsEmptySelection` property of `NSTableView`.
     * @details Get and set allowsEmptySelection. If -allowsEmptySelection is YES, all rows can be deselected by the user. Otherwise, it is enforced that one row must be left selected at any given time. The default value is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_empty_selection(bool value) const;
        /**
     * @brief Returns the `allowsMultipleSelection` property of `NSTableView`.
     * @details Get and set allowsMultipleSelection. If -allowsMultipleSelection is YES, multiple items can be selected in various ways (modifier-clicking items, shift-arrow selection extending, etc). The default value is NO.
     * @return The converted Objective-C result.
     */
        bool allows_multiple_selection() const;
        /**
     * @brief Sets the `allowsMultipleSelection` property of `NSTableView`.
     * @details Get and set allowsMultipleSelection. If -allowsMultipleSelection is YES, multiple items can be selected in various ways (modifier-clicking items, shift-arrow selection extending, etc). The default value is NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_multiple_selection(bool value) const;
        /**
     * @brief Returns the `allowsTypeSelect` property of `NSTableView`.
     * @details Allow type selection in this tableView. The default value is YES.
     * @return The converted Objective-C result.
     */
        bool allows_type_select() const;
        /**
     * @brief Sets the `allowsTypeSelect` property of `NSTableView`.
     * @details Allow type selection in this tableView. The default value is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_type_select(bool value) const;
        /**
     * @brief Returns the `autosaveName` property of `NSTableView`.
     * @details On Mac OS 13.0 and higher, changing the autosaveName property from one value to another will automatically persist autosave data for the old value before changing to the new value. Setting autosaveName to nil removes the persistence data for the previously set autosaveName.
     * @return The converted Objective-C result.
     */
        std::string autosave_name() const;
        /**
     * @brief Sets the `autosaveName` property of `NSTableView`.
     * @details On Mac OS 13.0 and higher, changing the autosaveName property from one value to another will automatically persist autosave data for the old value before changing to the new value. Setting autosaveName to nil removes the persistence data for the previously set autosaveName.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_autosave_name(const std::string& value) const;
        /**
     * @brief Returns the `autosaveTableColumns` property of `NSTableView`.
     * @details On Mac OS 10.4 and higher, the NSTableColumn width and location is saved. On Mac OS 10.5 and higher, the NSTableColumn 'isHidden' state is also saved. The 'autosaveName' must be set for 'autosaveTableColumns' to take effect.
     * @return The converted Objective-C result.
     */
        bool autosave_table_columns() const;
        /**
     * @brief Sets the `autosaveTableColumns` property of `NSTableView`.
     * @details On Mac OS 10.4 and higher, the NSTableColumn width and location is saved. On Mac OS 10.5 and higher, the NSTableColumn 'isHidden' state is also saved. The 'autosaveName' must be set for 'autosaveTableColumns' to take effect.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_autosave_table_columns(bool value) const;
        /**
     * @brief Returns the `backgroundColor` property of `NSTableView`.
     * @details Get and set the backgroundColor. On Mac OS 10.5 and higher, the alpha portion of 'color' is properly used when drawing the backgroundColor. To have a transparent tableView, set the backgroundColor to [NSColor clearColor], and set the enclosing NSScrollView to not draw its background with: [[tableView enclosingScrollView] setDrawsBackground:NO]. NSTableView uses NSCompositeSourceOver when drawing the background color. The default value is [NSColor controlBackgroundColor].
     * @return The converted Objective-C result.
     */
        Color background_color() const;
        /**
     * @brief Sets the `backgroundColor` property of `NSTableView`.
     * @details Get and set the backgroundColor. On Mac OS 10.5 and higher, the alpha portion of 'color' is properly used when drawing the backgroundColor. To have a transparent tableView, set the backgroundColor to [NSColor clearColor], and set the enclosing NSScrollView to not draw its background with: [[tableView enclosingScrollView] setDrawsBackground:NO]. NSTableView uses NSCompositeSourceOver when drawing the background color. The default value is [NSColor controlBackgroundColor].
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_color(const Color& value) const;
        /**
     * @brief Returns the `clickedColumn` property of `NSTableView`.
     * @return The converted Objective-C result.
     */
        std::int64_t clicked_column() const;
        /**
     * @brief Returns the `clickedRow` property of `NSTableView`.
     * @return The converted Objective-C result.
     */
        std::int64_t clicked_row() const;
        /**
     * @brief Returns the `columnAutoresizingStyle` property of `NSTableView`.
     * @details Get and set the columnAutoresizingStyle. This controls resizing in response to a tableView frame size change, usually done by dragging a window larger that has an auto-resized tableView inside it. The default value is NSTableViewLastColumnOnlyAutoresizingStyle. Compatability Note: This method replaces -setAutoresizesAllColumnsToFit: on 10.4 and higher.
     * @return The converted Objective-C result.
     */
        TableViewColumnAutoresizingStyle column_autoresizing_style() const;
        /**
     * @brief Sets the `columnAutoresizingStyle` property of `NSTableView`.
     * @details Get and set the columnAutoresizingStyle. This controls resizing in response to a tableView frame size change, usually done by dragging a window larger that has an auto-resized tableView inside it. The default value is NSTableViewLastColumnOnlyAutoresizingStyle. Compatability Note: This method replaces -setAutoresizesAllColumnsToFit: on 10.4 and higher.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_column_autoresizing_style(TableViewColumnAutoresizingStyle value) const;
        /**
     * @brief Returns the `cornerView` property of `NSTableView`.
     * @details Get and set the cornerView. The cornerView is the view that appears directly to the right of the headerView above the vertical NSScroller. The scroller must be present for the cornerView to be shown. Calling -setCornerView: may have the side effect of tiling the enclosingScrollView to accommodate the size change. The default value is an internal class that properly fills in the corner.
     * @return The converted Objective-C result.
     */
        View corner_view() const;
        /**
     * @brief Sets the `cornerView` property of `NSTableView`.
     * @details Get and set the cornerView. The cornerView is the view that appears directly to the right of the headerView above the vertical NSScroller. The scroller must be present for the cornerView to be shown. Calling -setCornerView: may have the side effect of tiling the enclosingScrollView to accommodate the size change. The default value is an internal class that properly fills in the corner.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_corner_view(const View& value) const;
        /**
     * @brief Returns the `doubleAction` property of `NSTableView`.
     * @return The converted Objective-C result.
     */
        std::string double_action() const;
        /**
     * @brief Sets the `doubleAction` property of `NSTableView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_double_action(const std::string& value) const;
        /**
     * @brief Returns the `draggingDestinationFeedbackStyle` property of `NSTableView`.
     * @details Gets and sets the dragging destination feedback style. The default value is NSTableViewDraggingDestinationFeedbackStyleRegular for all tables. However, changing the -selectionHighlightStyle to NSTableViewSelectionHighlightStyleSourceList will automatically change the -draggingDestinationFeedbackStyle to NSTableViewDraggingDestinationFeedbackStyleSourceList.
     * @return The converted Objective-C result.
     */
        TableViewDraggingDestinationFeedbackStyle dragging_destination_feedback_style() const;
        /**
     * @brief Sets the `draggingDestinationFeedbackStyle` property of `NSTableView`.
     * @details Gets and sets the dragging destination feedback style. The default value is NSTableViewDraggingDestinationFeedbackStyleRegular for all tables. However, changing the -selectionHighlightStyle to NSTableViewSelectionHighlightStyleSourceList will automatically change the -draggingDestinationFeedbackStyle to NSTableViewDraggingDestinationFeedbackStyleSourceList.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_dragging_destination_feedback_style(TableViewDraggingDestinationFeedbackStyle value) const;
        /**
     * @brief Returns the `editedColumn` property of `NSTableView`.
     * @details Cell Based TableView: Returns the column and row that is being edited. editedRow will be -1 if there is no editing session happening. editedColumn will be -1 if there is no editing session, or the currently edited row is a "full width" row. View Based TableView: Not applicable. Subviews are responsible for editing.
     * @return The converted Objective-C result.
     */
        std::int64_t edited_column() const;
        /**
     * @brief Returns the `editedRow` property of `NSTableView`.
     * @return The converted Objective-C result.
     */
        std::int64_t edited_row() const;
        /**
     * @brief Returns the `effectiveRowSizeStyle` property of `NSTableView`.
     * @details Returns the effective row size style for the table. If the rowSizeStyle is NSTableViewRowSizeStyleDefault, then this method returns the default size for this particular table.
     * @return The converted Objective-C result.
     */
        TableViewRowSizeStyle effective_row_size_style() const;
        /**
     * @brief Returns the `effectiveStyle` property of `NSTableView`.
     * @details The effective style when style is NSTableViewStyleAutomatic. Otherwise, it returns the same value as style.
     * @return The converted Objective-C result.
     */
        TableViewStyle effective_style() const;
        /**
     * @brief Returns the `floatsGroupRows` property of `NSTableView`.
     * @details View Based TableView: Group rows can optionally appear floating. Group rows are rows that the delegate responds YES to tableView:isGroupRow:. NSOutlineView will only float expandable group rows that are expanded. The default value is YES. This property is encoded and decoded in the nib.
     * @return The converted Objective-C result.
     */
        bool floats_group_rows() const;
        /**
     * @brief Sets the `floatsGroupRows` property of `NSTableView`.
     * @details View Based TableView: Group rows can optionally appear floating. Group rows are rows that the delegate responds YES to tableView:isGroupRow:. NSOutlineView will only float expandable group rows that are expanded. The default value is YES. This property is encoded and decoded in the nib.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_floats_group_rows(bool value) const;
        /**
     * @brief Returns the `gridColor` property of `NSTableView`.
     * @details Get and set the gridColor. This value is only used when the gridStyleMask is not equal to NSTableViewGridNone. The default value is [NSColor gridColor].
     * @return The converted Objective-C result.
     */
        Color grid_color() const;
        /**
     * @brief Sets the `gridColor` property of `NSTableView`.
     * @details Get and set the gridColor. This value is only used when the gridStyleMask is not equal to NSTableViewGridNone. The default value is [NSColor gridColor].
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_grid_color(const Color& value) const;
        /**
     * @brief Returns the `gridStyleMask` property of `NSTableView`.
     * @details Get and set the gridStyleMask. Values can be bitwise or'ed together, however, only one horizontal style can be used at a time. The default value is NSTableViewGridNone.
     * @return The converted Objective-C result.
     */
        TableViewGridLineStyle grid_style_mask() const;
        /**
     * @brief Sets the `gridStyleMask` property of `NSTableView`.
     * @details Get and set the gridStyleMask. Values can be bitwise or'ed together, however, only one horizontal style can be used at a time. The default value is NSTableViewGridNone.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_grid_style_mask(TableViewGridLineStyle value) const;
        /**
     * @brief Returns the `headerView` property of `NSTableView`.
     * @details Get and set the headerView. Calling -setHeaderView:nil will remove the headerView. Calling -setHeaderView: may have the side effect of tiling the enclosingScrollView to accommodate the size change. The default value is a new NSTableHeaderView instance.
     * @return The converted Objective-C result.
     */
        TableHeaderView header_view() const;
        /**
     * @brief Sets the `headerView` property of `NSTableView`.
     * @details Get and set the headerView. Calling -setHeaderView:nil will remove the headerView. Calling -setHeaderView: may have the side effect of tiling the enclosingScrollView to accommodate the size change. The default value is a new NSTableHeaderView instance.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_header_view(const TableHeaderView& value) const;
        /**
     * @brief Returns the `hiddenRowIndexes` property of `NSTableView`.
     * @details Returns the indexes that are currently hidden. Indexes are hidden by calling hideRowsAtIndexes:. Sometimes during drag and drop operations certain indexes will be automatically hidden.
     * @return The converted Objective-C result.
     */
        IndexSet hidden_row_indexes() const;
        /**
     * @brief Returns the `highlightedTableColumn` property of `NSTableView`.
     * @details Support for highlightable column header, for use with row selection.
     * @return The converted Objective-C result.
     */
        TableColumn highlighted_table_column() const;
        /**
     * @brief Sets the `highlightedTableColumn` property of `NSTableView`.
     * @details Support for highlightable column header, for use with row selection.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_highlighted_table_column(const TableColumn& value) const;
        /**
     * @brief Returns the `intercellSpacing` property of `NSTableView`.
     * @details Get and set the intercellSpacing. This is the spacing that appears between cells. The default value is NSMakeSize(3, 2).
     * @return The converted Objective-C result.
     */
        Size intercell_spacing() const;
        /**
     * @brief Sets the `intercellSpacing` property of `NSTableView`.
     * @details Get and set the intercellSpacing. This is the spacing that appears between cells. The default value is NSMakeSize(3, 2).
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_intercell_spacing(const Size& value) const;
        /**
     * @brief Returns the `numberOfColumns` property of `NSTableView`.
     * @details Simply a cover method to return the number of NSTableColumn instances in the NSTableView. Includes columns that are -isHidden.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_columns() const;
        /**
     * @brief Returns the `numberOfRows` property of `NSTableView`.
     * @details Returns the numberOfRows. It may call to the dataSource to acquire the count. numberOfRows will return 0 if there are no visible columns.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_rows() const;
        /**
     * @brief Returns the `numberOfSelectedColumns` property of `NSTableView`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_selected_columns() const;
        /**
     * @brief Returns the `numberOfSelectedRows` property of `NSTableView`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_selected_rows() const;
        /**
     * @brief Returns the `registeredNibsByIdentifier` property of `NSTableView`.
     * @details View Based TableView: Returns a dictionary of all registered nibs. The keys are the identifier, and the value is the NSNib that is registered.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Nib> registered_nibs_by_identifier() const;
        /**
     * @brief Returns the `rowActionsVisible` property of `NSTableView`.
     * @details View Based TableView: rowActionsVisible can be queried to determine if the "row actions" (see: tableView:rowActionsForRow:edge:) are visible or not. Set rowActionsVisible=NO to hide the row actions. Setting rowActionsVisible=YES is currently not supported and will throw an exception. This property is not encoded in the nib.
     * @return The converted Objective-C result.
     */
        bool row_actions_visible() const;
        /**
     * @brief Sets the `rowActionsVisible` property of `NSTableView`.
     * @details View Based TableView: rowActionsVisible can be queried to determine if the "row actions" (see: tableView:rowActionsForRow:edge:) are visible or not. Set rowActionsVisible=NO to hide the row actions. Setting rowActionsVisible=YES is currently not supported and will throw an exception. This property is not encoded in the nib.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_row_actions_visible(bool value) const;
        /**
     * @brief Returns the `rowHeight` property of `NSTableView`.
     * @details Get and set the rowHeight. The value must be greater than 0. Calling -setRowHeight: with a non-pixel aligning (fractional) value will be forced to a pixel aligning (integral) value. For variable row height tableViews (ones that have the delegate implement -tableView:heightOfRow:), -rowHeight will be used to draw alternating rows past the last row in the tableView. The actual -rectOfRow: is equal to the -rowHeight plus the intercellSpacing.height. The default value is 17.0 for applications linked on 10.5 and higher (the height acceptable for [NSFont systemFontSize]). The default value is 16.0 for 10.4 and lower. Group rows will follow the system defined height.
     * @return The converted Objective-C result.
     */
        double row_height() const;
        /**
     * @brief Sets the `rowHeight` property of `NSTableView`.
     * @details Get and set the rowHeight. The value must be greater than 0. Calling -setRowHeight: with a non-pixel aligning (fractional) value will be forced to a pixel aligning (integral) value. For variable row height tableViews (ones that have the delegate implement -tableView:heightOfRow:), -rowHeight will be used to draw alternating rows past the last row in the tableView. The actual -rectOfRow: is equal to the -rowHeight plus the intercellSpacing.height. The default value is 17.0 for applications linked on 10.5 and higher (the height acceptable for [NSFont systemFontSize]). The default value is 16.0 for 10.4 and lower. Group rows will follow the system defined height.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_row_height(double value) const;
        /**
     * @brief Returns the `rowSizeStyle` property of `NSTableView`.
     * @details Get and set the rowSizeStyle. The default value is NSTableViewRowSizeStyleCustom, which allows the table to behave as it traditionally has. If the value is not NSTableViewRowSizeStyleCustom, then all three sizes must be properly supported by the view or cell. Changing the rowSizeStyle will automatically update the rowHeight if NSTableViewRowSizeStyleCustom is not used, and the rowHeight should not be changed. It is a recommendation that the variable row height delegate method should generally NOT be implemented when using a non-custom style, and instead the standard provided row heights should be used.
     * @return The converted Objective-C result.
     */
        TableViewRowSizeStyle row_size_style() const;
        /**
     * @brief Sets the `rowSizeStyle` property of `NSTableView`.
     * @details Get and set the rowSizeStyle. The default value is NSTableViewRowSizeStyleCustom, which allows the table to behave as it traditionally has. If the value is not NSTableViewRowSizeStyleCustom, then all three sizes must be properly supported by the view or cell. Changing the rowSizeStyle will automatically update the rowHeight if NSTableViewRowSizeStyleCustom is not used, and the rowHeight should not be changed. It is a recommendation that the variable row height delegate method should generally NOT be implemented when using a non-custom style, and instead the standard provided row heights should be used.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_row_size_style(TableViewRowSizeStyle value) const;
        /**
     * @brief Returns the `selectedColumn` property of `NSTableView`.
     * @return The converted Objective-C result.
     */
        std::int64_t selected_column() const;
        /**
     * @brief Returns the `selectedColumnIndexes` property of `NSTableView`.
     * @return The converted Objective-C result.
     */
        IndexSet selected_column_indexes() const;
        /**
     * @brief Returns the `selectedRow` property of `NSTableView`.
     * @return The converted Objective-C result.
     */
        std::int64_t selected_row() const;
        /**
     * @brief Returns the `selectedRowIndexes` property of `NSTableView`.
     * @return The converted Objective-C result.
     */
        IndexSet selected_row_indexes() const;
        /**
     * @brief Returns the `selectionHighlightStyle` property of `NSTableView`.
     * @details Gets and sets the current selection highlight style. The default value is NSTableViewSelectionHighlightStyleRegular.
     * @return The converted Objective-C result.
     */
        TableViewSelectionHighlightStyle selection_highlight_style() const;
        /**
     * @brief Sets the `selectionHighlightStyle` property of `NSTableView`.
     * @details Gets and sets the current selection highlight style. The default value is NSTableViewSelectionHighlightStyleRegular.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selection_highlight_style(TableViewSelectionHighlightStyle value) const;
        /**
     * @brief Returns the `sortDescriptors` property of `NSTableView`.
     * @details Sorting Support The array of sort descriptors is archived. Sort descriptors will persist along with other column information if an -autosaveName is set. Calling -setSortDescriptors: may have the side effect of calling -tableView:sortDescriptorsDidChange: on the -dataSource/
     * @return The converted Objective-C result.
     */
        std::vector<SortDescriptor> sort_descriptors() const;
        /**
     * @brief Sets the `sortDescriptors` property of `NSTableView`.
     * @details Sorting Support The array of sort descriptors is archived. Sort descriptors will persist along with other column information if an -autosaveName is set. Calling -setSortDescriptors: may have the side effect of calling -tableView:sortDescriptorsDidChange: on the -dataSource/
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sort_descriptors(const std::vector<SortDescriptor>& value) const;
        /**
     * @brief Returns the `style` property of `NSTableView`.
     * @details The table view style. Defaults to NSTableViewStyleAutomatic
     * @return The converted Objective-C result.
     */
        TableViewStyle style() const;
        /**
     * @brief Sets the `style` property of `NSTableView`.
     * @details The table view style. Defaults to NSTableViewStyleAutomatic
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_style(TableViewStyle value) const;
        /**
     * @brief Returns the `tableColumns` property of `NSTableView`.
     * @details Returns a reference to the array of NSTableColumn instances in the NSTableView. Includes columns that are -isHidden. It is recommended to make a copy of the array if you are going to manipulate the NSTableView by using -addTableColumn:, -removeTableColumn: or -moveColumn:toColumn:.
     * @return The converted Objective-C result.
     */
        std::vector<TableColumn> table_columns() const;
        /**
     * @brief Returns the `userInterfaceLayoutDirection` property of `NSTableView`.
     * @details Get and set the user interface layout direction. When set to NSUserInterfaceLayoutDirectionRightToLeft, the Table View will flip the visual order of the table columns, while the logical order remains as it was. For applications linked against 10.11 or earlier, NSTableView will ignore this property and always render in left-to-right.
     * @return The converted Objective-C result.
     */
        UserInterfaceLayoutDirection user_interface_layout_direction() const;
        /**
     * @brief Sets the `userInterfaceLayoutDirection` property of `NSTableView`.
     * @details Get and set the user interface layout direction. When set to NSUserInterfaceLayoutDirectionRightToLeft, the Table View will flip the visual order of the table columns, while the logical order remains as it was. For applications linked against 10.11 or earlier, NSTableView will ignore this property and always render in left-to-right.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_user_interface_layout_direction(UserInterfaceLayoutDirection value) const;
        /**
     * @brief Returns the `usesAlternatingRowBackgroundColors` property of `NSTableView`.
     * @details Get and set the use of alternatingRowBackgroundColors. This configures the table to use either the standard alternating row colors, or a solid color for its background. The default value is NO.
     * @return The converted Objective-C result.
     */
        bool uses_alternating_row_background_colors() const;
        /**
     * @brief Sets the `usesAlternatingRowBackgroundColors` property of `NSTableView`.
     * @details Get and set the use of alternatingRowBackgroundColors. This configures the table to use either the standard alternating row colors, or a solid color for its background. The default value is NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_alternating_row_background_colors(bool value) const;
        /**
     * @brief Returns the `usesAutomaticRowHeights` property of `NSTableView`.
     * @details View Based TableViews: When set to YES, the table will utilize autolayout for the row heights. Set the rowHeight property to provide an estimated row height for views that are not yet loaded. This is not required, but it is recommended in order to provide a proper estimate for the scroll bars. The delegate method -tableView:heightOfRow: can still be used to provide a more specific estimated row height. Note that a rowView's height is set to the rowHeight plus intercellSpacing.height, so an estimated rowHeight should have the intercellSpacing.height subtracted from it. The default value is NO. This value is encoded.
     * @return The converted Objective-C result.
     */
        bool uses_automatic_row_heights() const;
        /**
     * @brief Sets the `usesAutomaticRowHeights` property of `NSTableView`.
     * @details View Based TableViews: When set to YES, the table will utilize autolayout for the row heights. Set the rowHeight property to provide an estimated row height for views that are not yet loaded. This is not required, but it is recommended in order to provide a proper estimate for the scroll bars. The delegate method -tableView:heightOfRow: can still be used to provide a more specific estimated row height. Note that a rowView's height is set to the rowHeight plus intercellSpacing.height, so an estimated rowHeight should have the intercellSpacing.height subtracted from it. The default value is NO. This value is encoded.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_automatic_row_heights(bool value) const;
        /**
     * @brief Returns the `usesStaticContents` property of `NSTableView`.
     * @details View Based TableView: The table view keeps all views added to the table around while usesStaticContents=YES. Views can be removed by calling removeRowsAtIndexes:withAnimation:. The datasource does not need to implement numberOfRowsInTableView: when usesStaticContents=YES. Static views are encoded and decoded with the table view. Views can also dynamically be inserted into the table view by using insertRowIndexes:withAnimation:, however, this requires an implementation of tableView:viewForTableColumn:row: to provide the newly inserted view, which is then kept around statically.
     * @return The converted Objective-C result.
     */
        bool uses_static_contents() const;
        /**
     * @brief Sets the `usesStaticContents` property of `NSTableView`.
     * @details View Based TableView: The table view keeps all views added to the table around while usesStaticContents=YES. Views can be removed by calling removeRowsAtIndexes:withAnimation:. The datasource does not need to implement numberOfRowsInTableView: when usesStaticContents=YES. Static views are encoded and decoded with the table view. Views can also dynamically be inserted into the table view by using insertRowIndexes:withAnimation:, however, this requires an implementation of tableView:viewForTableColumn:row: to provide the newly inserted view, which is then kept around statically.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_static_contents(bool value) const;
        /**
     * @brief Returns the `verticalMotionCanBeginDrag` property of `NSTableView`.
     * @details Get and set verticalMotionCanBeginDrag. If -verticalMotionCanBeginDrag is YES, then click + a vertical drag of the mouse will drag the clicked item(s). If NO, it will do a "drag select". The default value is YES.
     * @return The converted Objective-C result.
     */
        bool vertical_motion_can_begin_drag() const;
        /**
     * @brief Sets the `verticalMotionCanBeginDrag` property of `NSTableView`.
     * @details Get and set verticalMotionCanBeginDrag. If -verticalMotionCanBeginDrag is YES, then click + a vertical drag of the mouse will drag the clicked item(s). If NO, it will do a "drag select". The default value is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_vertical_motion_can_begin_drag(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `number_of_rows_in_table_view`; connect a callback with `number_of_rows_in_table_view().connect(...)`.
        Signal<TableView, std::int64_t()> number_of_rows_in_table_view() const
        {
            return Signal<TableView, std::int64_t()>(handle(), "number_of_rows_in_table_view");
        }
        /// @brief Signal for the delegate/data-source method behind `object_value_for_table_column_row`; connect a callback with `object_value_for_table_column_row().connect(...)`.
        Signal<TableView, Object(TableColumn, std::int64_t)> object_value_for_table_column_row() const
        {
            return Signal<TableView, Object(TableColumn, std::int64_t)>(handle(), "object_value_for_table_column_row");
        }
        /// @brief Signal for the delegate/data-source method behind `set_object_value_for_table_column_row`; connect a callback with `set_object_value_for_table_column_row().connect(...)`.
        Signal<TableView, void(Object, TableColumn, std::int64_t)> set_object_value_for_table_column_row() const
        {
            return Signal<TableView, void(Object, TableColumn, std::int64_t)>(handle(), "set_object_value_for_table_column_row");
        }
        /// @brief Signal for the delegate/data-source method behind `sort_descriptors_did_change`; connect a callback with `sort_descriptors_did_change().connect(...)`.
        Signal<TableView, void(std::vector<SortDescriptor>)> sort_descriptors_did_change() const
        {
            return Signal<TableView, void(std::vector<SortDescriptor>)>(handle(), "sort_descriptors_did_change");
        }
        /// @brief Signal for the delegate/data-source method behind `pasteboard_writer_for_row`; connect a callback with `pasteboard_writer_for_row().connect(...)`.
        Signal<TableView, Object(std::int64_t)> pasteboard_writer_for_row() const
        {
            return Signal<TableView, Object(std::int64_t)>(handle(), "pasteboard_writer_for_row");
        }
        /// @brief Signal for the delegate/data-source method behind `dragging_session_will_begin_at_point_for_row_indexes`; connect a callback with `dragging_session_will_begin_at_point_for_row_indexes().connect(...)`.
        Signal<TableView, void(DraggingSession, Point, IndexSet)> dragging_session_will_begin_at_point_for_row_indexes() const
        {
            return Signal<TableView, void(DraggingSession, Point, IndexSet)>(handle(), "dragging_session_will_begin_at_point_for_row_indexes");
        }
        /// @brief Signal for the delegate/data-source method behind `dragging_session_ended_at_point_operation`; connect a callback with `dragging_session_ended_at_point_operation().connect(...)`.
        Signal<TableView, void(DraggingSession, Point, DragOperation)> dragging_session_ended_at_point_operation() const
        {
            return Signal<TableView, void(DraggingSession, Point, DragOperation)>(handle(), "dragging_session_ended_at_point_operation");
        }
        /// @brief Signal for the delegate/data-source method behind `update_dragging_items_for_drag`; connect a callback with `update_dragging_items_for_drag().connect(...)`.
        Signal<TableView, void(Object)> update_dragging_items_for_drag() const
        {
            return Signal<TableView, void(Object)>(handle(), "update_dragging_items_for_drag");
        }
        /// @brief Signal for the delegate/data-source method behind `validate_drop_proposed_row_proposed_drop_operation`; connect a callback with `validate_drop_proposed_row_proposed_drop_operation().connect(...)`.
        Signal<TableView, DragOperation(Object, std::int64_t, TableViewDropOperation)> validate_drop_proposed_row_proposed_drop_operation() const
        {
            return Signal<TableView, DragOperation(Object, std::int64_t, TableViewDropOperation)>(handle(), "validate_drop_proposed_row_proposed_drop_operation");
        }
        /// @brief Signal for the delegate/data-source method behind `accept_drop_row_drop_operation`; connect a callback with `accept_drop_row_drop_operation().connect(...)`.
        Signal<TableView, bool(Object, std::int64_t, TableViewDropOperation)> accept_drop_row_drop_operation() const
        {
            return Signal<TableView, bool(Object, std::int64_t, TableViewDropOperation)>(handle(), "accept_drop_row_drop_operation");
        }
        /// @brief Signal for the delegate/data-source method behind `control_text_did_begin_editing`; connect a callback with `control_text_did_begin_editing().connect(...)`.
        Signal<TableView, void(Notification)> control_text_did_begin_editing() const
        {
            return Signal<TableView, void(Notification)>(handle(), "control_text_did_begin_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `control_text_did_end_editing`; connect a callback with `control_text_did_end_editing().connect(...)`.
        Signal<TableView, void(Notification)> control_text_did_end_editing() const
        {
            return Signal<TableView, void(Notification)>(handle(), "control_text_did_end_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `control_text_did_change`; connect a callback with `control_text_did_change().connect(...)`.
        Signal<TableView, void(Notification)> control_text_did_change() const
        {
            return Signal<TableView, void(Notification)>(handle(), "control_text_did_change");
        }
        /// @brief Signal for the delegate/data-source method behind `text_should_begin_editing`; connect a callback with `text_should_begin_editing().connect(...)`.
        Signal<TableView, bool(Text)> text_should_begin_editing() const
        {
            return Signal<TableView, bool(Text)>(handle(), "text_should_begin_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `text_should_end_editing`; connect a callback with `text_should_end_editing().connect(...)`.
        Signal<TableView, bool(Text)> text_should_end_editing() const
        {
            return Signal<TableView, bool(Text)>(handle(), "text_should_end_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `did_fail_to_format_string_error_description`; connect a callback with `did_fail_to_format_string_error_description().connect(...)`.
        Signal<TableView, bool(std::string, std::string)> did_fail_to_format_string_error_description() const
        {
            return Signal<TableView, bool(std::string, std::string)>(handle(), "did_fail_to_format_string_error_description");
        }
        /// @brief Signal for the delegate/data-source method behind `did_fail_to_validate_partial_string_error_description`; connect a callback with `did_fail_to_validate_partial_string_error_description().connect(...)`.
        Signal<TableView, void(std::string, std::string)> did_fail_to_validate_partial_string_error_description() const
        {
            return Signal<TableView, void(std::string, std::string)>(handle(), "did_fail_to_validate_partial_string_error_description");
        }
        /// @brief Signal for the delegate/data-source method behind `is_valid_object`; connect a callback with `is_valid_object().connect(...)`.
        Signal<TableView, bool(Object)> is_valid_object() const
        {
            return Signal<TableView, bool(Object)>(handle(), "is_valid_object");
        }
        /// @brief Signal for the delegate/data-source method behind `text_view_do_command_by_selector`; connect a callback with `text_view_do_command_by_selector().connect(...)`.
        Signal<TableView, bool(TextView, std::string)> text_view_do_command_by_selector() const
        {
            return Signal<TableView, bool(TextView, std::string)>(handle(), "text_view_do_command_by_selector");
        }
        /// @brief Signal for the delegate/data-source method behind `text_view_completions_for_partial_word_range_index_of_selected_item`; connect a callback with `text_view_completions_for_partial_word_range_index_of_selected_item().connect(...)`.
        Signal<TableView, std::vector<std::string>(TextView, std::vector<std::string>, Range, std::int64_t*)> text_view_completions_for_partial_word_range_index_of_selected_item() const
        {
            return Signal<TableView, std::vector<std::string>(TextView, std::vector<std::string>, Range, std::int64_t*)>(handle(), "text_view_completions_for_partial_word_range_index_of_selected_item");
        }
        /// @brief Signal for the delegate/data-source method behind `view_for_table_column_row`; connect a callback with `view_for_table_column_row().connect(...)`.
        Signal<TableView, View(TableColumn, std::int64_t)> view_for_table_column_row() const
        {
            return Signal<TableView, View(TableColumn, std::int64_t)>(handle(), "view_for_table_column_row");
        }
        /// @brief Signal for the delegate/data-source method behind `row_view_for_row`; connect a callback with `row_view_for_row().connect(...)`.
        Signal<TableView, TableRowView(std::int64_t)> row_view_for_row() const
        {
            return Signal<TableView, TableRowView(std::int64_t)>(handle(), "row_view_for_row");
        }
        /// @brief Signal for the delegate/data-source method behind `did_add_row_view_for_row`; connect a callback with `did_add_row_view_for_row().connect(...)`.
        Signal<TableView, void(TableRowView, std::int64_t)> did_add_row_view_for_row() const
        {
            return Signal<TableView, void(TableRowView, std::int64_t)>(handle(), "did_add_row_view_for_row");
        }
        /// @brief Signal for the delegate/data-source method behind `did_remove_row_view_for_row`; connect a callback with `did_remove_row_view_for_row().connect(...)`.
        Signal<TableView, void(TableRowView, std::int64_t)> did_remove_row_view_for_row() const
        {
            return Signal<TableView, void(TableRowView, std::int64_t)>(handle(), "did_remove_row_view_for_row");
        }
        /// @brief Signal for the delegate/data-source method behind `will_display_cell_for_table_column_row`; connect a callback with `will_display_cell_for_table_column_row().connect(...)`.
        Signal<TableView, void(Object, TableColumn, std::int64_t)> will_display_cell_for_table_column_row() const
        {
            return Signal<TableView, void(Object, TableColumn, std::int64_t)>(handle(), "will_display_cell_for_table_column_row");
        }
        /// @brief Signal for the delegate/data-source method behind `should_edit_table_column_row`; connect a callback with `should_edit_table_column_row().connect(...)`.
        Signal<TableView, bool(TableColumn, std::int64_t)> should_edit_table_column_row() const
        {
            return Signal<TableView, bool(TableColumn, std::int64_t)>(handle(), "should_edit_table_column_row");
        }
        /// @brief Signal for the delegate/data-source method behind `tool_tip_for_cell_rect_table_column_row_mouse_location`; connect a callback with `tool_tip_for_cell_rect_table_column_row_mouse_location().connect(...)`.
        Signal<TableView, std::string(Cell, Rect*, TableColumn, std::int64_t, Point)> tool_tip_for_cell_rect_table_column_row_mouse_location() const
        {
            return Signal<TableView, std::string(Cell, Rect*, TableColumn, std::int64_t, Point)>(handle(), "tool_tip_for_cell_rect_table_column_row_mouse_location");
        }
        /// @brief Signal for the delegate/data-source method behind `should_show_cell_expansion_for_table_column_row`; connect a callback with `should_show_cell_expansion_for_table_column_row().connect(...)`.
        Signal<TableView, bool(TableColumn, std::int64_t)> should_show_cell_expansion_for_table_column_row() const
        {
            return Signal<TableView, bool(TableColumn, std::int64_t)>(handle(), "should_show_cell_expansion_for_table_column_row");
        }
        /// @brief Signal for the delegate/data-source method behind `should_track_cell_for_table_column_row`; connect a callback with `should_track_cell_for_table_column_row().connect(...)`.
        Signal<TableView, bool(Cell, TableColumn, std::int64_t)> should_track_cell_for_table_column_row() const
        {
            return Signal<TableView, bool(Cell, TableColumn, std::int64_t)>(handle(), "should_track_cell_for_table_column_row");
        }
        /// @brief Signal for the delegate/data-source method behind `data_cell_for_table_column_row`; connect a callback with `data_cell_for_table_column_row().connect(...)`.
        Signal<TableView, Cell(TableColumn, std::int64_t)> data_cell_for_table_column_row() const
        {
            return Signal<TableView, Cell(TableColumn, std::int64_t)>(handle(), "data_cell_for_table_column_row");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_should_change_in_table_view`; connect a callback with `selection_should_change_in_table_view().connect(...)`.
        Signal<TableView, bool()> selection_should_change_in_table_view() const
        {
            return Signal<TableView, bool()>(handle(), "selection_should_change_in_table_view");
        }
        /// @brief Signal for the delegate/data-source method behind `should_select_row`; connect a callback with `should_select_row().connect(...)`.
        Signal<TableView, bool(std::int64_t)> should_select_row() const
        {
            return Signal<TableView, bool(std::int64_t)>(handle(), "should_select_row");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_indexes_for_proposed_selection`; connect a callback with `selection_indexes_for_proposed_selection().connect(...)`.
        Signal<TableView, IndexSet(IndexSet)> selection_indexes_for_proposed_selection() const
        {
            return Signal<TableView, IndexSet(IndexSet)>(handle(), "selection_indexes_for_proposed_selection");
        }
        /// @brief Signal for the delegate/data-source method behind `should_select_table_column`; connect a callback with `should_select_table_column().connect(...)`.
        Signal<TableView, bool(TableColumn)> should_select_table_column() const
        {
            return Signal<TableView, bool(TableColumn)>(handle(), "should_select_table_column");
        }
        /// @brief Signal for the delegate/data-source method behind `mouse_down_in_header_of_table_column`; connect a callback with `mouse_down_in_header_of_table_column().connect(...)`.
        Signal<TableView, void(TableColumn)> mouse_down_in_header_of_table_column() const
        {
            return Signal<TableView, void(TableColumn)>(handle(), "mouse_down_in_header_of_table_column");
        }
        /// @brief Signal for the delegate/data-source method behind `did_click_table_column`; connect a callback with `did_click_table_column().connect(...)`.
        Signal<TableView, void(TableColumn)> did_click_table_column() const
        {
            return Signal<TableView, void(TableColumn)>(handle(), "did_click_table_column");
        }
        /// @brief Signal for the delegate/data-source method behind `did_drag_table_column`; connect a callback with `did_drag_table_column().connect(...)`.
        Signal<TableView, void(TableColumn)> did_drag_table_column() const
        {
            return Signal<TableView, void(TableColumn)>(handle(), "did_drag_table_column");
        }
        /// @brief Signal for the delegate/data-source method behind `height_of_row`; connect a callback with `height_of_row().connect(...)`.
        Signal<TableView, double(std::int64_t)> height_of_row() const
        {
            return Signal<TableView, double(std::int64_t)>(handle(), "height_of_row");
        }
        /// @brief Signal for the delegate/data-source method behind `type_select_string_for_table_column_row`; connect a callback with `type_select_string_for_table_column_row().connect(...)`.
        Signal<TableView, std::string(TableColumn, std::int64_t)> type_select_string_for_table_column_row() const
        {
            return Signal<TableView, std::string(TableColumn, std::int64_t)>(handle(), "type_select_string_for_table_column_row");
        }
        /// @brief Signal for the delegate/data-source method behind `next_type_select_match_from_row_to_row_for_string`; connect a callback with `next_type_select_match_from_row_to_row_for_string().connect(...)`.
        Signal<TableView, std::int64_t(std::int64_t, std::int64_t, std::string)> next_type_select_match_from_row_to_row_for_string() const
        {
            return Signal<TableView, std::int64_t(std::int64_t, std::int64_t, std::string)>(handle(), "next_type_select_match_from_row_to_row_for_string");
        }
        /// @brief Signal for the delegate/data-source method behind `should_type_select_for_event_with_current_search_string`; connect a callback with `should_type_select_for_event_with_current_search_string().connect(...)`.
        Signal<TableView, bool(Event, std::string)> should_type_select_for_event_with_current_search_string() const
        {
            return Signal<TableView, bool(Event, std::string)>(handle(), "should_type_select_for_event_with_current_search_string");
        }
        /// @brief Signal for the delegate/data-source method behind `is_group_row`; connect a callback with `is_group_row().connect(...)`.
        Signal<TableView, bool(std::int64_t)> is_group_row() const
        {
            return Signal<TableView, bool(std::int64_t)>(handle(), "is_group_row");
        }
        /// @brief Signal for the delegate/data-source method behind `size_to_fit_width_of_column`; connect a callback with `size_to_fit_width_of_column().connect(...)`.
        Signal<TableView, double(std::int64_t)> size_to_fit_width_of_column() const
        {
            return Signal<TableView, double(std::int64_t)>(handle(), "size_to_fit_width_of_column");
        }
        /// @brief Signal for the delegate/data-source method behind `should_reorder_column_to_column`; connect a callback with `should_reorder_column_to_column().connect(...)`.
        Signal<TableView, bool(std::int64_t, std::int64_t)> should_reorder_column_to_column() const
        {
            return Signal<TableView, bool(std::int64_t, std::int64_t)>(handle(), "should_reorder_column_to_column");
        }
        /// @brief Signal for the delegate/data-source method behind `row_actions_for_row_edge`; connect a callback with `row_actions_for_row_edge().connect(...)`.
        Signal<TableView, std::vector<TableViewRowAction>(std::int64_t, TableRowActionEdge)> row_actions_for_row_edge() const
        {
            return Signal<TableView, std::vector<TableViewRowAction>(std::int64_t, TableRowActionEdge)>(handle(), "row_actions_for_row_edge");
        }
        /// @brief Signal for the delegate/data-source method behind `user_can_change_visibility_of_table_column`; connect a callback with `user_can_change_visibility_of_table_column().connect(...)`.
        Signal<TableView, bool(TableColumn)> user_can_change_visibility_of_table_column() const
        {
            return Signal<TableView, bool(TableColumn)>(handle(), "user_can_change_visibility_of_table_column");
        }
        /// @brief Signal for the delegate/data-source method behind `user_did_change_visibility_of_table_columns`; connect a callback with `user_did_change_visibility_of_table_columns().connect(...)`.
        Signal<TableView, void(std::vector<TableColumn>)> user_did_change_visibility_of_table_columns() const
        {
            return Signal<TableView, void(std::vector<TableColumn>)>(handle(), "user_did_change_visibility_of_table_columns");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_did_change`; connect a callback with `selection_did_change().connect(...)`.
        Signal<TableView, void(Notification)> selection_did_change() const
        {
            return Signal<TableView, void(Notification)>(handle(), "selection_did_change");
        }
        /// @brief Signal for the delegate/data-source method behind `column_did_move`; connect a callback with `column_did_move().connect(...)`.
        Signal<TableView, void(Notification)> column_did_move() const
        {
            return Signal<TableView, void(Notification)>(handle(), "column_did_move");
        }
        /// @brief Signal for the delegate/data-source method behind `column_did_resize`; connect a callback with `column_did_resize().connect(...)`.
        Signal<TableView, void(Notification)> column_did_resize() const
        {
            return Signal<TableView, void(Notification)>(handle(), "column_did_resize");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_is_changing`; connect a callback with `selection_is_changing().connect(...)`.
        Signal<TableView, void(Notification)> selection_is_changing() const
        {
            return Signal<TableView, void(Notification)>(handle(), "selection_is_changing");
        }

    protected:
        static void install_data_source_delegate_(void* native);
        static void install_delegate_delegate_(void* native);
    };
}
