#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/table_view.h"
#include "types.h"

namespace cocoon
{
    class Cell;
    class DraggingSession;
    class Event;
    class IndexSet;
    class Notification;
    class SortDescriptor;
    class TableColumn;
    class TableRowView;
    class Text;
    class TextView;
    class TintConfiguration;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSOutlineView` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TableView.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::OutlineView outline_view;
     * outline_view.set_autoresizes_outline_column(true);
     * outline_view.set_object_value_for_table_column_by_item().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::OutlineView outline_view{};
     * outline_view.set_autoresizes_outline_column(true);
     * auto autoresizes_outline_column = outline_view.autoresizes_outline_column();
     * outline_view.set_autosave_expanded_items(true);
     * auto autosave_expanded_items = outline_view.autosave_expanded_items();
     * outline_view.set_indentation_marker_follows_cell(true);
     * auto indentation_marker_follows_cell = outline_view.indentation_marker_follows_cell();
     * outline_view.frame_of_outline_cell_at_row(1);
     * outline_view.item_at_row(1);
     * outline_view.level_for_row(1);
     * outline_view.set_object_value_for_table_column_by_item().connect([](cocoon::Object a0, cocoon::TableColumn a1, cocoon::Object a2) {});
     * outline_view.sort_descriptors_did_change().connect([](std::vector<cocoon::SortDescriptor> a0) {});
     * outline_view.dragging_session_will_begin_at_point_for_items().connect([](cocoon::DraggingSession a0, cocoon::Point a1, std::vector<cocoon::Object> a2) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsoutlineview
     */
    class OutlineView : public TableView
    {
    public:
        /// @brief Creates a new `NSOutlineView` instance and returns a handle to it.
        explicit OutlineView();
        /// @brief Creates a null handle that refers to no native object.
        OutlineView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit OutlineView(Adopt adopt);
        using TableView::set_user_interface_layout_direction;
        using TableView::user_interface_layout_direction;
        /**
         * @brief Calls `-[NSOutlineView child:ofItem:]`.
         * @details Returns the child item for a given parent item. This is mostly useful for static outline views where the data was encoded at design time, however, it will work for both static and non-static outline views. This may call out to the datasource, if required.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @param item Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object child(std::int64_t index, const Object& item) const;
        /**
         * @brief Calls `-[NSOutlineView childIndexForItem:]`.
         * @details Returns the child index of 'item' within its parent. The performance of this method is O(1) at best and O(n) at worst.
         * @param item Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t child_index_for_item(const Object& item) const;
        /**
         * @brief Calls `-[NSOutlineView collapseItem:]`.
         * @details Calls collapseItem:collapseChildren with 'collapseChildren == NO'
         * @param item Argument converted to the Objective-C parameter of the same role.
         */
        void collapse_item(const Object& item) const;
        /**
         * @brief Calls `-[NSOutlineView collapseItem:collapseChildren:]`.
         * @details Collapses 'item' and all children if 'collapseChildren' is YES. On 10.5 and higher, passing 'nil' for 'item' will collapse each item under the root.
         * @param item Argument converted to the Objective-C parameter of the same role.
         * @param collapse_children Argument converted to the Objective-C parameter of the same role.
         */
        void collapse_item(const Object& item, bool collapse_children) const;
        /**
         * @brief Calls `-[NSOutlineView expandItem:]`.
         * @details Calls expandItem:expandChildren with 'expandChildren == NO'
         * @param item Argument converted to the Objective-C parameter of the same role.
         */
        void expand_item(const Object& item) const;
        /**
         * @brief Calls `-[NSOutlineView expandItem:expandChildren:]`.
         * @details Expands 'item', if not already expanded, and all children if 'expandChildren' is YES. On 10.5 and higher, passing 'nil' for 'item' will expand each item under the root.
         * @param item Argument converted to the Objective-C parameter of the same role.
         * @param expand_children Argument converted to the Objective-C parameter of the same role.
         */
        void expand_item(const Object& item, bool expand_children) const;
        /**
         * @brief Calls `-[NSOutlineView frameOfOutlineCellAtRow:]`.
         * @details Returns the frame of the outline cell for a particular row, considering the current indentation and indentationMarkerFollowsCell value. If 'row' is not an expandable row, it will return NSZeroRect. This method can be overridden by subclassers to return a custom frame for the outline button cell. If an empty rect is returned, no outline cell will be drawn for that row.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect frame_of_outline_cell_at_row(std::int64_t row) const;
        /**
         * @brief Calls `-[NSOutlineView insertItemsAtIndexes:inParent:withAnimation:]`.
         * @details This method parallels TableView's -insertRowIndexes:withAnimation:, and is used in a way similar to NSMutableArray's -insertObjects:atIndexes: This method inserts a new item at 'indexes' in 'parent'. 'parent' can be nil to insert items into the root of the OutlineView. The operation will not do anything if 'parent' is not expanded. The actual item values are determined by the dataSource methods -outlineView:child:ofItem: (note that this will only be called after an -endUpdates happens to ensure dataSource integrity). Calling this method multiple times within the same beginUpdates/endUpdates block is allowed; new insertions will move previously inserted new items, just like modifying an array. Inserting an index beyond what is available will throw an exception. The "Cell Based TableView" must first call -beginUpdates before calling this method. This method can also be used when "usesStaticContents=YES".
         * @param indexes Argument converted to the Objective-C parameter of the same role.
         * @param parent Argument converted to the Objective-C parameter of the same role.
         * @param animation_options Argument converted to the Objective-C parameter of the same role.
         */
        void insert_items_at_indexes(const IndexSet& indexes, const Object& parent, TableViewAnimationOptions animation_options) const;
        /**
         * @brief Calls `-[NSOutlineView isExpandable:]`.
         * @details Returns YES if 'item' is expandable and can contain other items. May call out to the delegate/datasource, if required.
         * @param item Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_expandable(const Object& item) const;
        /**
         * @brief Calls `-[NSOutlineView isItemExpanded:]`.
         * @param item Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_item_expanded(const Object& item) const;
        /**
         * @brief Calls `-[NSOutlineView itemAtRow:]`.
         * @details Item/Row translation
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object item_at_row(std::int64_t row) const;
        /**
         * @brief Calls `-[NSOutlineView levelForItem:]`.
         * @details Indentation
         * @param item Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t level_for_item(const Object& item) const;
        /**
         * @brief Calls `-[NSOutlineView levelForRow:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t level_for_row(std::int64_t row) const;
        /**
         * @brief Calls `-[NSOutlineView moveItemAtIndex:inParent:toIndex:inParent:]`.
         * @details This method parallels TableView's -moveRowAtIndex:toIndex:. The item located at 'fromIndex' is moved from the existing 'oldParent' to the given index in 'newParent'. 'newParent' can be the same as 'oldParent' to reorder an item within the same parent. This method can be called multiple times within the same beginUpdates/endUpdates block. Moving from an invalid index, or to an invalid index will throw an exception. The "Cell Based TableView" must first call -beginUpdates before calling this method. This method can also be used when "usesStaticContents=YES".
         * @param from_index Argument converted to the Objective-C parameter of the same role.
         * @param old_parent Argument converted to the Objective-C parameter of the same role.
         * @param to_index Argument converted to the Objective-C parameter of the same role.
         * @param new_parent Argument converted to the Objective-C parameter of the same role.
         */
        void move_item_at_index(std::int64_t from_index, const Object& old_parent, std::int64_t to_index, const Object& new_parent) const;
        /**
         * @brief Calls `-[NSOutlineView numberOfChildrenOfItem:]`.
         * @details Returns the number of children for a given parent item. This is mostly useful for static outline views where the data was encoded at design time; however, it will work for both static and non-static outline views. This may call out to the datasource, if required.
         * @param item Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_children_of_item(const Object& item) const;
        /**
         * @brief Calls `-[NSOutlineView parentForItem:]`.
         * @details Returns the parent for 'item', or nil, if the parent is the root.
         * @param item Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object parent_for_item(const Object& item) const;
        /**
         * @brief Calls `-[NSOutlineView reloadItem:]`.
         * @details Calls reloadItem:reloadChildren with 'reloadChildren == NO'
         * @param item Argument converted to the Objective-C parameter of the same role.
         */
        void reload_item(const Object& item) const;
        /**
         * @brief Calls `-[NSOutlineView reloadItem:reloadChildren:]`.
         * @details Reloads 'item' and all children if 'reloadChildren' is YES. On 10.5 and higher, passing 'nil' for 'item' will reload everything under the root item.
         * @param item Argument converted to the Objective-C parameter of the same role.
         * @param reload_children Argument converted to the Objective-C parameter of the same role.
         */
        void reload_item(const Object& item, bool reload_children) const;
        /**
         * @brief Calls `-[NSOutlineView removeItemsAtIndexes:inParent:withAnimation:]`.
         * @details This method parallels TableView's -removeRowsAtIndexes:withAnimation:, and is used similar to NSMutableArray's -removeObjectsAtIndexes:. The items at the given indexes will be removed from the parent. The operation will not do anything if 'parent' is not expanded. If one of the children items is expanded, then all of its children rows will also be removed. Calling this method multiple times within the same beginUpdates/endUpdates block is allowed; changes work just like modifying an array. Deleting an index beyond what is available will throw an exception. The "Cell Based TableView" must first call -beginUpdates before calling this method. This method can also be used when "usesStaticContents=YES".
         * @param indexes Argument converted to the Objective-C parameter of the same role.
         * @param parent Argument converted to the Objective-C parameter of the same role.
         * @param animation_options Argument converted to the Objective-C parameter of the same role.
         */
        void remove_items_at_indexes(const IndexSet& indexes, const Object& parent, TableViewAnimationOptions animation_options) const;
        /**
         * @brief Calls `-[NSOutlineView rowForItem:]`.
         * @param item Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t row_for_item(const Object& item) const;
        /**
         * @brief Calls `-[NSOutlineView setDropItem:dropChildIndex:]`.
         * @details To be used from validateDrop: in order to "re-target" the proposed drop. To specify a drop on an item I, one would specify item=I, and index=NSOutlineViewDropOnItemIndex. To specify a drop between child 2 and 3 of an item I, on would specify item=I, and index=3 (children are zero-base indexed). To specify a drop on an un-expandable item I, one would specify item=I, and index=NSOutlineViewDropOnItemIndex.
         * @param item Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void set_drop_item(const Object& item, std::int64_t index) const;
        /**
         * @brief Calls `-[NSOutlineView shouldCollapseAutoExpandedItemsForDeposited:]`.
         * @details This method returns YES to indicate that auto expanded items should return to their original collapsed state. Override this method to provide custom behavior. 'deposited' tells wether or not the drop terminated due to a successful drop (as indicated by the return value from acceptDrop:). Note that exiting the view will be treated the same as a failed drop.
         * @param deposited Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool should_collapse_auto_expanded_items_for_deposited(bool deposited) const;
        /**
         * @brief Returns the `autoresizesOutlineColumn` property of `NSOutlineView`.
         * @details If autoresizesOutlineColumn is YES, then the outlineTableColumn will automatically resize when there is a new expanded child at a particular depth level. The default value is YES.
         * @return The converted Objective-C result.
         */
        bool autoresizes_outline_column() const;
        /**
         * @brief Sets the `autoresizesOutlineColumn` property of `NSOutlineView`.
         * @details If autoresizesOutlineColumn is YES, then the outlineTableColumn will automatically resize when there is a new expanded child at a particular depth level. The default value is YES.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_autoresizes_outline_column(bool value) const;
        /**
         * @brief Returns the `autosaveExpandedItems` property of `NSOutlineView`.
         * @details Persistence. The value for autosaveExpandedItems is saved out in the nib file on Mac OS 10.5 or higher. The default value is NO. Calling setAutosaveExpandedItems:YES requires you to implement outlineView:itemForPersistentObject: and outlineView:persistentObjectForItem:.
         * @return The converted Objective-C result.
         */
        bool autosave_expanded_items() const;
        /**
         * @brief Sets the `autosaveExpandedItems` property of `NSOutlineView`.
         * @details Persistence. The value for autosaveExpandedItems is saved out in the nib file on Mac OS 10.5 or higher. The default value is NO. Calling setAutosaveExpandedItems:YES requires you to implement outlineView:itemForPersistentObject: and outlineView:persistentObjectForItem:.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_autosave_expanded_items(bool value) const;
        /**
         * @brief Returns the `indentationMarkerFollowsCell` property of `NSOutlineView`.
         * @details The indentation marker is the visual indicator that shows an item is expandable (i.e. disclosure triangle). The default value is YES.
         * @return The converted Objective-C result.
         */
        bool indentation_marker_follows_cell() const;
        /**
         * @brief Sets the `indentationMarkerFollowsCell` property of `NSOutlineView`.
         * @details The indentation marker is the visual indicator that shows an item is expandable (i.e. disclosure triangle). The default value is YES.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_indentation_marker_follows_cell(bool value) const;
        /**
         * @brief Returns the `indentationPerLevel` property of `NSOutlineView`.
         * @details Controls the amount of indentation per level. Negative values are ignored, and only integral values are accepted. The default value is 16.0. An indentationPerLevel of 0 can be used to eliminate all indentation and make an NSOutlineView appear more like an NSTableView.
         * @return The converted Objective-C result.
         */
        double indentation_per_level() const;
        /**
         * @brief Sets the `indentationPerLevel` property of `NSOutlineView`.
         * @details Controls the amount of indentation per level. Negative values are ignored, and only integral values are accepted. The default value is 16.0. An indentationPerLevel of 0 can be used to eliminate all indentation and make an NSOutlineView appear more like an NSTableView.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_indentation_per_level(double value) const;
        /**
         * @brief Returns the `outlineTableColumn` property of `NSOutlineView`.
         * @details The 'outlineTableColumn' is the column that displays data in a hierarchical fashion, indented one identationlevel per level, decorated with indentation marker (disclosure triangle) on rows that are expandable. A nil 'outlineTableColumn' is silently ignored. On 10.5 and higher, this value is saved in encodeWithCoder: and restored in initWithCoder:.
         * @return The converted Objective-C result.
         */
        TableColumn outline_table_column() const;
        /**
         * @brief Sets the `outlineTableColumn` property of `NSOutlineView`.
         * @details The 'outlineTableColumn' is the column that displays data in a hierarchical fashion, indented one identationlevel per level, decorated with indentation marker (disclosure triangle) on rows that are expandable. A nil 'outlineTableColumn' is silently ignored. On 10.5 and higher, this value is saved in encodeWithCoder: and restored in initWithCoder:.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_outline_table_column(const TableColumn& value) const;
        /**
         * @brief Returns the `stronglyReferencesItems` property of `NSOutlineView`.
         * @details When YES, the NSOutlineView will retain and release the objects returned to it from the dataSource (outlineView:child:ofItem:). When NO, it only treats the objects as opaque items and assume the client has a retain on them. The default value is YES for applications linked on 10.12 and later, and NO for previous applications. This value is not encoded in the nib, and must be explicitly set to NO in code if one requires the legacy behavior and is linking on 10.12 and later. In general, this is required if the items themselves create a retain cycle.
         * @return The converted Objective-C result.
         */
        bool strongly_references_items() const;
        /**
         * @brief Sets the `stronglyReferencesItems` property of `NSOutlineView`.
         * @details When YES, the NSOutlineView will retain and release the objects returned to it from the dataSource (outlineView:child:ofItem:). When NO, it only treats the objects as opaque items and assume the client has a retain on them. The default value is YES for applications linked on 10.12 and later, and NO for previous applications. This value is not encoded in the nib, and must be explicitly set to NO in code if one requires the legacy behavior and is linking on 10.12 and later. In general, this is required if the items themselves create a retain cycle.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_strongly_references_items(bool value) const;
        /**
         * @brief Returns the `userInterfaceLayoutDirection` property of `NSOutlineView`.
         * @details Get and set the user interface layout direction. When set to NSUserInterfaceLayoutDirectionRightToLeft, the Outline View will show the disclosure triangle to the right of the cell instead of the left. This method is available for NSOutlineView on 10.7 and higher.
         * @return The converted Objective-C result.
         */
        UserInterfaceLayoutDirection user_interface_layout_direction() const;
        /**
         * @brief Sets the `userInterfaceLayoutDirection` property of `NSOutlineView`.
         * @details Get and set the user interface layout direction. When set to NSUserInterfaceLayoutDirectionRightToLeft, the Outline View will show the disclosure triangle to the right of the cell instead of the left. This method is available for NSOutlineView on 10.7 and higher.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_user_interface_layout_direction(UserInterfaceLayoutDirection value) const;
        /// @brief Signal for the delegate/data-source method behind `outline_view_number_of_children_of_item`; connect a callback with `outline_view_number_of_children_of_item().connect(...)`.
        Signal<OutlineView, std::int64_t(Object)> outline_view_number_of_children_of_item() const
        {
            return Signal<OutlineView, std::int64_t(Object)>(handle(), "outline_view_number_of_children_of_item");
        }
        /// @brief Signal for the delegate/data-source method behind `child_of_item`; connect a callback with `child_of_item().connect(...)`.
        Signal<OutlineView, Object(std::int64_t, Object)> child_of_item() const
        {
            return Signal<OutlineView, Object(std::int64_t, Object)>(handle(), "child_of_item");
        }
        /// @brief Signal for the delegate/data-source method behind `is_item_expandable`; connect a callback with `is_item_expandable().connect(...)`.
        Signal<OutlineView, bool(Object)> is_item_expandable() const
        {
            return Signal<OutlineView, bool(Object)>(handle(), "is_item_expandable");
        }
        /// @brief Signal for the delegate/data-source method behind `object_value_for_table_column_by_item`; connect a callback with `object_value_for_table_column_by_item().connect(...)`.
        Signal<OutlineView, Object(TableColumn, Object)> object_value_for_table_column_by_item() const
        {
            return Signal<OutlineView, Object(TableColumn, Object)>(handle(), "object_value_for_table_column_by_item");
        }
        /// @brief Signal for the delegate/data-source method behind `set_object_value_for_table_column_by_item`; connect a callback with `set_object_value_for_table_column_by_item().connect(...)`.
        Signal<OutlineView, void(Object, TableColumn, Object)> set_object_value_for_table_column_by_item() const
        {
            return Signal<OutlineView, void(Object, TableColumn, Object)>(handle(), "set_object_value_for_table_column_by_item");
        }
        /// @brief Signal for the delegate/data-source method behind `item_for_persistent_object`; connect a callback with `item_for_persistent_object().connect(...)`.
        Signal<OutlineView, Object(Object)> item_for_persistent_object() const
        {
            return Signal<OutlineView, Object(Object)>(handle(), "item_for_persistent_object");
        }
        /// @brief Signal for the delegate/data-source method behind `persistent_object_for_item`; connect a callback with `persistent_object_for_item().connect(...)`.
        Signal<OutlineView, Object(Object)> persistent_object_for_item() const
        {
            return Signal<OutlineView, Object(Object)>(handle(), "persistent_object_for_item");
        }
        /// @brief Signal for the delegate/data-source method behind `sort_descriptors_did_change`; connect a callback with `sort_descriptors_did_change().connect(...)`.
        Signal<OutlineView, void(std::vector<SortDescriptor>)> sort_descriptors_did_change() const
        {
            return Signal<OutlineView, void(std::vector<SortDescriptor>)>(handle(), "sort_descriptors_did_change");
        }
        /// @brief Signal for the delegate/data-source method behind `pasteboard_writer_for_item`; connect a callback with `pasteboard_writer_for_item().connect(...)`.
        Signal<OutlineView, Object(Object)> pasteboard_writer_for_item() const
        {
            return Signal<OutlineView, Object(Object)>(handle(), "pasteboard_writer_for_item");
        }
        /// @brief Signal for the delegate/data-source method behind `dragging_session_will_begin_at_point_for_items`; connect a callback with `dragging_session_will_begin_at_point_for_items().connect(...)`.
        Signal<OutlineView, void(DraggingSession, Point, std::vector<Object>)> dragging_session_will_begin_at_point_for_items() const
        {
            return Signal<OutlineView, void(DraggingSession, Point, std::vector<Object>)>(handle(), "dragging_session_will_begin_at_point_for_items");
        }
        /// @brief Signal for the delegate/data-source method behind `dragging_session_ended_at_point_operation`; connect a callback with `dragging_session_ended_at_point_operation().connect(...)`.
        Signal<OutlineView, void(DraggingSession, Point, DragOperation)> dragging_session_ended_at_point_operation() const
        {
            return Signal<OutlineView, void(DraggingSession, Point, DragOperation)>(handle(), "dragging_session_ended_at_point_operation");
        }
        /// @brief Signal for the delegate/data-source method behind `update_dragging_items_for_drag`; connect a callback with `update_dragging_items_for_drag().connect(...)`.
        Signal<OutlineView, void(Object)> update_dragging_items_for_drag() const
        {
            return Signal<OutlineView, void(Object)>(handle(), "update_dragging_items_for_drag");
        }
        /// @brief Signal for the delegate/data-source method behind `validate_drop_proposed_item_proposed_child_index`; connect a callback with `validate_drop_proposed_item_proposed_child_index().connect(...)`.
        Signal<OutlineView, DragOperation(Object, Object, std::int64_t)> validate_drop_proposed_item_proposed_child_index() const
        {
            return Signal<OutlineView, DragOperation(Object, Object, std::int64_t)>(handle(), "validate_drop_proposed_item_proposed_child_index");
        }
        /// @brief Signal for the delegate/data-source method behind `accept_drop_item_child_index`; connect a callback with `accept_drop_item_child_index().connect(...)`.
        Signal<OutlineView, bool(Object, Object, std::int64_t)> accept_drop_item_child_index() const
        {
            return Signal<OutlineView, bool(Object, Object, std::int64_t)>(handle(), "accept_drop_item_child_index");
        }
        /// @brief Signal for the delegate/data-source method behind `view_for_table_column_item`; connect a callback with `view_for_table_column_item().connect(...)`.
        Signal<OutlineView, View(TableColumn, Object)> view_for_table_column_item() const
        {
            return Signal<OutlineView, View(TableColumn, Object)>(handle(), "view_for_table_column_item");
        }
        /// @brief Signal for the delegate/data-source method behind `row_view_for_item`; connect a callback with `row_view_for_item().connect(...)`.
        Signal<OutlineView, TableRowView(Object)> row_view_for_item() const
        {
            return Signal<OutlineView, TableRowView(Object)>(handle(), "row_view_for_item");
        }
        /// @brief Signal for the delegate/data-source method behind `did_add_row_view_for_row`; connect a callback with `did_add_row_view_for_row().connect(...)`.
        Signal<OutlineView, void(TableRowView, std::int64_t)> did_add_row_view_for_row() const
        {
            return Signal<OutlineView, void(TableRowView, std::int64_t)>(handle(), "did_add_row_view_for_row");
        }
        /// @brief Signal for the delegate/data-source method behind `did_remove_row_view_for_row`; connect a callback with `did_remove_row_view_for_row().connect(...)`.
        Signal<OutlineView, void(TableRowView, std::int64_t)> did_remove_row_view_for_row() const
        {
            return Signal<OutlineView, void(TableRowView, std::int64_t)>(handle(), "did_remove_row_view_for_row");
        }
        /// @brief Signal for the delegate/data-source method behind `will_display_cell_for_table_column_item`; connect a callback with `will_display_cell_for_table_column_item().connect(...)`.
        Signal<OutlineView, void(Object, TableColumn, Object)> will_display_cell_for_table_column_item() const
        {
            return Signal<OutlineView, void(Object, TableColumn, Object)>(handle(), "will_display_cell_for_table_column_item");
        }
        /// @brief Signal for the delegate/data-source method behind `should_edit_table_column_item`; connect a callback with `should_edit_table_column_item().connect(...)`.
        Signal<OutlineView, bool(TableColumn, Object)> should_edit_table_column_item() const
        {
            return Signal<OutlineView, bool(TableColumn, Object)>(handle(), "should_edit_table_column_item");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_should_change_in_outline_view`; connect a callback with `selection_should_change_in_outline_view().connect(...)`.
        Signal<OutlineView, bool()> selection_should_change_in_outline_view() const
        {
            return Signal<OutlineView, bool()>(handle(), "selection_should_change_in_outline_view");
        }
        /// @brief Signal for the delegate/data-source method behind `should_select_item`; connect a callback with `should_select_item().connect(...)`.
        Signal<OutlineView, bool(Object)> should_select_item() const
        {
            return Signal<OutlineView, bool(Object)>(handle(), "should_select_item");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_indexes_for_proposed_selection`; connect a callback with `selection_indexes_for_proposed_selection().connect(...)`.
        Signal<OutlineView, IndexSet(IndexSet)> selection_indexes_for_proposed_selection() const
        {
            return Signal<OutlineView, IndexSet(IndexSet)>(handle(), "selection_indexes_for_proposed_selection");
        }
        /// @brief Signal for the delegate/data-source method behind `should_select_table_column`; connect a callback with `should_select_table_column().connect(...)`.
        Signal<OutlineView, bool(TableColumn)> should_select_table_column() const
        {
            return Signal<OutlineView, bool(TableColumn)>(handle(), "should_select_table_column");
        }
        /// @brief Signal for the delegate/data-source method behind `mouse_down_in_header_of_table_column`; connect a callback with `mouse_down_in_header_of_table_column().connect(...)`.
        Signal<OutlineView, void(TableColumn)> mouse_down_in_header_of_table_column() const
        {
            return Signal<OutlineView, void(TableColumn)>(handle(), "mouse_down_in_header_of_table_column");
        }
        /// @brief Signal for the delegate/data-source method behind `did_click_table_column`; connect a callback with `did_click_table_column().connect(...)`.
        Signal<OutlineView, void(TableColumn)> did_click_table_column() const
        {
            return Signal<OutlineView, void(TableColumn)>(handle(), "did_click_table_column");
        }
        /// @brief Signal for the delegate/data-source method behind `did_drag_table_column`; connect a callback with `did_drag_table_column().connect(...)`.
        Signal<OutlineView, void(TableColumn)> did_drag_table_column() const
        {
            return Signal<OutlineView, void(TableColumn)>(handle(), "did_drag_table_column");
        }
        /// @brief Signal for the delegate/data-source method behind `tool_tip_for_cell_rect_table_column_item_mouse_location`; connect a callback with `tool_tip_for_cell_rect_table_column_item_mouse_location().connect(...)`.
        Signal<OutlineView, std::string(Cell, Rect*, TableColumn, Object, Point)> tool_tip_for_cell_rect_table_column_item_mouse_location() const
        {
            return Signal<OutlineView, std::string(Cell, Rect*, TableColumn, Object, Point)>(handle(), "tool_tip_for_cell_rect_table_column_item_mouse_location");
        }
        /// @brief Signal for the delegate/data-source method behind `height_of_row_by_item`; connect a callback with `height_of_row_by_item().connect(...)`.
        Signal<OutlineView, double(Object)> height_of_row_by_item() const
        {
            return Signal<OutlineView, double(Object)>(handle(), "height_of_row_by_item");
        }
        /// @brief Signal for the delegate/data-source method behind `tint_configuration_for_item`; connect a callback with `tint_configuration_for_item().connect(...)`.
        Signal<OutlineView, TintConfiguration(Object)> tint_configuration_for_item() const
        {
            return Signal<OutlineView, TintConfiguration(Object)>(handle(), "tint_configuration_for_item");
        }
        /// @brief Signal for the delegate/data-source method behind `type_select_string_for_table_column_item`; connect a callback with `type_select_string_for_table_column_item().connect(...)`.
        Signal<OutlineView, std::string(TableColumn, Object)> type_select_string_for_table_column_item() const
        {
            return Signal<OutlineView, std::string(TableColumn, Object)>(handle(), "type_select_string_for_table_column_item");
        }
        /// @brief Signal for the delegate/data-source method behind `next_type_select_match_from_item_to_item_for_string`; connect a callback with `next_type_select_match_from_item_to_item_for_string().connect(...)`.
        Signal<OutlineView, Object(Object, Object, std::string)> next_type_select_match_from_item_to_item_for_string() const
        {
            return Signal<OutlineView, Object(Object, Object, std::string)>(handle(), "next_type_select_match_from_item_to_item_for_string");
        }
        /// @brief Signal for the delegate/data-source method behind `should_type_select_for_event_with_current_search_string`; connect a callback with `should_type_select_for_event_with_current_search_string().connect(...)`.
        Signal<OutlineView, bool(Event, std::string)> should_type_select_for_event_with_current_search_string() const
        {
            return Signal<OutlineView, bool(Event, std::string)>(handle(), "should_type_select_for_event_with_current_search_string");
        }
        /// @brief Signal for the delegate/data-source method behind `should_show_cell_expansion_for_table_column_item`; connect a callback with `should_show_cell_expansion_for_table_column_item().connect(...)`.
        Signal<OutlineView, bool(TableColumn, Object)> should_show_cell_expansion_for_table_column_item() const
        {
            return Signal<OutlineView, bool(TableColumn, Object)>(handle(), "should_show_cell_expansion_for_table_column_item");
        }
        /// @brief Signal for the delegate/data-source method behind `should_track_cell_for_table_column_item`; connect a callback with `should_track_cell_for_table_column_item().connect(...)`.
        Signal<OutlineView, bool(Cell, TableColumn, Object)> should_track_cell_for_table_column_item() const
        {
            return Signal<OutlineView, bool(Cell, TableColumn, Object)>(handle(), "should_track_cell_for_table_column_item");
        }
        /// @brief Signal for the delegate/data-source method behind `data_cell_for_table_column_item`; connect a callback with `data_cell_for_table_column_item().connect(...)`.
        Signal<OutlineView, Cell(TableColumn, Object)> data_cell_for_table_column_item() const
        {
            return Signal<OutlineView, Cell(TableColumn, Object)>(handle(), "data_cell_for_table_column_item");
        }
        /// @brief Signal for the delegate/data-source method behind `is_group_item`; connect a callback with `is_group_item().connect(...)`.
        Signal<OutlineView, bool(Object)> is_group_item() const
        {
            return Signal<OutlineView, bool(Object)>(handle(), "is_group_item");
        }
        /// @brief Signal for the delegate/data-source method behind `should_expand_item`; connect a callback with `should_expand_item().connect(...)`.
        Signal<OutlineView, bool(Object)> should_expand_item() const
        {
            return Signal<OutlineView, bool(Object)>(handle(), "should_expand_item");
        }
        /// @brief Signal for the delegate/data-source method behind `should_collapse_item`; connect a callback with `should_collapse_item().connect(...)`.
        Signal<OutlineView, bool(Object)> should_collapse_item() const
        {
            return Signal<OutlineView, bool(Object)>(handle(), "should_collapse_item");
        }
        /// @brief Signal for the delegate/data-source method behind `will_display_outline_cell_for_table_column_item`; connect a callback with `will_display_outline_cell_for_table_column_item().connect(...)`.
        Signal<OutlineView, void(Object, TableColumn, Object)> will_display_outline_cell_for_table_column_item() const
        {
            return Signal<OutlineView, void(Object, TableColumn, Object)>(handle(), "will_display_outline_cell_for_table_column_item");
        }
        /// @brief Signal for the delegate/data-source method behind `size_to_fit_width_of_column`; connect a callback with `size_to_fit_width_of_column().connect(...)`.
        Signal<OutlineView, double(std::int64_t)> size_to_fit_width_of_column() const
        {
            return Signal<OutlineView, double(std::int64_t)>(handle(), "size_to_fit_width_of_column");
        }
        /// @brief Signal for the delegate/data-source method behind `should_reorder_column_to_column`; connect a callback with `should_reorder_column_to_column().connect(...)`.
        Signal<OutlineView, bool(std::int64_t, std::int64_t)> should_reorder_column_to_column() const
        {
            return Signal<OutlineView, bool(std::int64_t, std::int64_t)>(handle(), "should_reorder_column_to_column");
        }
        /// @brief Signal for the delegate/data-source method behind `should_show_outline_cell_for_item`; connect a callback with `should_show_outline_cell_for_item().connect(...)`.
        Signal<OutlineView, bool(Object)> should_show_outline_cell_for_item() const
        {
            return Signal<OutlineView, bool(Object)>(handle(), "should_show_outline_cell_for_item");
        }
        /// @brief Signal for the delegate/data-source method behind `user_can_change_visibility_of_table_column`; connect a callback with `user_can_change_visibility_of_table_column().connect(...)`.
        Signal<OutlineView, bool(TableColumn)> user_can_change_visibility_of_table_column() const
        {
            return Signal<OutlineView, bool(TableColumn)>(handle(), "user_can_change_visibility_of_table_column");
        }
        /// @brief Signal for the delegate/data-source method behind `user_did_change_visibility_of_table_columns`; connect a callback with `user_did_change_visibility_of_table_columns().connect(...)`.
        Signal<OutlineView, void(std::vector<TableColumn>)> user_did_change_visibility_of_table_columns() const
        {
            return Signal<OutlineView, void(std::vector<TableColumn>)>(handle(), "user_did_change_visibility_of_table_columns");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_did_change`; connect a callback with `selection_did_change().connect(...)`.
        Signal<OutlineView, void(Notification)> selection_did_change() const
        {
            return Signal<OutlineView, void(Notification)>(handle(), "selection_did_change");
        }
        /// @brief Signal for the delegate/data-source method behind `column_did_move`; connect a callback with `column_did_move().connect(...)`.
        Signal<OutlineView, void(Notification)> column_did_move() const
        {
            return Signal<OutlineView, void(Notification)>(handle(), "column_did_move");
        }
        /// @brief Signal for the delegate/data-source method behind `column_did_resize`; connect a callback with `column_did_resize().connect(...)`.
        Signal<OutlineView, void(Notification)> column_did_resize() const
        {
            return Signal<OutlineView, void(Notification)>(handle(), "column_did_resize");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_is_changing`; connect a callback with `selection_is_changing().connect(...)`.
        Signal<OutlineView, void(Notification)> selection_is_changing() const
        {
            return Signal<OutlineView, void(Notification)>(handle(), "selection_is_changing");
        }
        /// @brief Signal for the delegate/data-source method behind `item_will_expand`; connect a callback with `item_will_expand().connect(...)`.
        Signal<OutlineView, void(Notification)> item_will_expand() const
        {
            return Signal<OutlineView, void(Notification)>(handle(), "item_will_expand");
        }
        /// @brief Signal for the delegate/data-source method behind `item_did_expand`; connect a callback with `item_did_expand().connect(...)`.
        Signal<OutlineView, void(Notification)> item_did_expand() const
        {
            return Signal<OutlineView, void(Notification)>(handle(), "item_did_expand");
        }
        /// @brief Signal for the delegate/data-source method behind `item_will_collapse`; connect a callback with `item_will_collapse().connect(...)`.
        Signal<OutlineView, void(Notification)> item_will_collapse() const
        {
            return Signal<OutlineView, void(Notification)>(handle(), "item_will_collapse");
        }
        /// @brief Signal for the delegate/data-source method behind `item_did_collapse`; connect a callback with `item_did_collapse().connect(...)`.
        Signal<OutlineView, void(Notification)> item_did_collapse() const
        {
            return Signal<OutlineView, void(Notification)>(handle(), "item_did_collapse");
        }

    protected:
        static void install_data_source_delegate_(void* native);
        static void install_delegate_delegate_(void* native);
    };
}
