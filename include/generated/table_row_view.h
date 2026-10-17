#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class Color;

    /**
     * @brief C++ handle for the Objective-C class `NSTableRowView` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TableRowView table_row_view;
     * table_row_view.set_background_color(cocoon::Color());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TableRowView table_row_view{};
     * table_row_view.set_background_color(cocoon::Color());
     * auto background_color = table_row_view.background_color();
     * table_row_view.set_dragging_destination_feedback_style(cocoon::TableViewDraggingDestinationFeedbackStyle::None);
     * auto dragging_destination_feedback_style = table_row_view.dragging_destination_feedback_style();
     * table_row_view.set_emphasized(true);
     * auto emphasized = table_row_view.is_emphasized();
     * table_row_view.draw_background_in_rect({{0, 0}, {100, 100}});
     * table_row_view.draw_dragging_destination_feedback_in_rect({{0, 0}, {100, 100}});
     * table_row_view.draw_selection_in_rect({{0, 0}, {100, 100}});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstablerowview
     */
    class TableRowView : public View
    {
    public:
        /// @brief Creates a new `NSTableRowView` instance and returns a handle to it.
        explicit TableRowView();
        /// @brief Creates a null handle that refers to no native object.
        TableRowView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TableRowView(Adopt adopt);
        using View::set_background_color;
        /**
     * @brief Calls `-[NSTableRowView drawBackgroundInRect:]`.
     * @details Override point to draw a custom background. 'dirtyRect' is the current dirty rect passed from -drawRect:. By default, this method draws the background color or "group row" style look. It will also draw the below look for a drop target if targetForDropOperation is YES. It is also recommended to override interiorBackgroundStyle when overriding this method.
     * @param dirty_rect Argument converted to the Objective-C parameter of the same role.
     */
        void draw_background_in_rect(const Rect& dirty_rect) const;
        /**
     * @brief Calls `-[NSTableRowView drawDraggingDestinationFeedbackInRect:]`.
     * @details Override point for drawing the dragging destination feedback when the entire row is a "drop target". 'dirtyRect' is the current dirty rect passed from -drawRect:. This method only is called if targetForDropOperation is YES, and will draw based on the properties set (such as the group row style).
     * @param dirty_rect Argument converted to the Objective-C parameter of the same role.
     */
        void draw_dragging_destination_feedback_in_rect(const Rect& dirty_rect) const;
        /**
     * @brief Calls `-[NSTableRowView drawSelectionInRect:]`.
     * @details Override point for drawing the selection. 'dirtyRect' is the current dirty rect passed from -drawRect:. This method is only called if the selection should be drawn. The selection will automatically be alpha-blended if the selection is animating in or out. The default selection drawn is dependent on the selectionHighlightStyle. It is also recommended to override interiorBackgroundStyle when overriding this method. Note: For 10.10 drawSelectionInRect: will not be called when the selectionHighlightStyle is set to NSTableViewSelectionHighlightStyleSourceList.
     * @param dirty_rect Argument converted to the Objective-C parameter of the same role.
     */
        void draw_selection_in_rect(const Rect& dirty_rect) const;
        /**
     * @brief Calls `-[NSTableRowView drawSeparatorInRect:]`.
     * @details Override point for drawing the (horizontal) separator.'dirtyRect' is the current dirty rect passed from -drawRect:. By default, the separator is only drawn if the enclosing table's gridStyleMask is set to include a horizontal separator. The separator should be drawn at the bottom of the row view, indicating a separation from this row and the next.
     * @param dirty_rect Argument converted to the Objective-C parameter of the same role.
     */
        void draw_separator_in_rect(const Rect& dirty_rect) const;
        /**
     * @brief Calls `-[NSTableRowView viewAtColumn:]`.
     * @details Provides access to the given view at a particular column. This is the only way to access cell views after the row view has been removed from the table.
     * @param column Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object view_at_column(std::int64_t column) const;
        /**
     * @brief Returns the `backgroundColor` property of `NSTableRowView`.
     * @details The backgroundColor property defaults to the Table View's backgroundColor, unless usesAlternatingRowBackgroundColors is set to YES. In that case, the colors alternate, and are automatically updated as required by insertions and deletions. The value can be customized in the delegate method -tableView:didAddRowView:forRow:. The property is animatable.
     * @return The converted Objective-C result.
     */
        Color background_color() const;
        /**
     * @brief Sets the `backgroundColor` property of `NSTableRowView`.
     * @details The backgroundColor property defaults to the Table View's backgroundColor, unless usesAlternatingRowBackgroundColors is set to YES. In that case, the colors alternate, and are automatically updated as required by insertions and deletions. The value can be customized in the delegate method -tableView:didAddRowView:forRow:. The property is animatable.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_color(const Color& value) const;
        /**
     * @brief Returns the `draggingDestinationFeedbackStyle` property of `NSTableRowView`.
     * @return The converted Objective-C result.
     */
        TableViewDraggingDestinationFeedbackStyle dragging_destination_feedback_style() const;
        /**
     * @brief Sets the `draggingDestinationFeedbackStyle` property of `NSTableRowView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_dragging_destination_feedback_style(TableViewDraggingDestinationFeedbackStyle value) const;
        /**
     * @brief Returns the `emphasized` property of `NSTableRowView`.
     * @details When emphasized is YES, the view should draw with the (typically) blue [NSColor alternateSelectedControlColor]. When NO, it should use the (typically) gray [NSColor secondarySelectedControlColor].
     * @return The converted Objective-C result.
     */
        bool is_emphasized() const;
        /**
     * @brief Sets the `emphasized` property of `NSTableRowView`.
     * @details When emphasized is YES, the view should draw with the (typically) blue [NSColor alternateSelectedControlColor]. When NO, it should use the (typically) gray [NSColor secondarySelectedControlColor].
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_emphasized(bool value) const;
        /**
     * @brief Returns the `floating` property of `NSTableRowView`.
     * @details Floating is a temporary attribute that is set when a particular group row is actually floating above other rows. The state may change dynamically based on the position of the group row. Drawing may be different for rows that are currently 'floating'. The TableView's delegate must implement tableView:isGroupRow: (or outlineView:isGroupItem:) to enable floating group rows.
     * @return The converted Objective-C result.
     */
        bool is_floating() const;
        /**
     * @brief Sets the `floating` property of `NSTableRowView`.
     * @details Floating is a temporary attribute that is set when a particular group row is actually floating above other rows. The state may change dynamically based on the position of the group row. Drawing may be different for rows that are currently 'floating'. The TableView's delegate must implement tableView:isGroupRow: (or outlineView:isGroupItem:) to enable floating group rows.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_floating(bool value) const;
        /**
     * @brief Returns the `groupRowStyle` property of `NSTableRowView`.
     * @details When groupRowStyle is set to YES, this row is a group row and will draw appropriately.
     * @return The converted Objective-C result.
     */
        bool is_group_row_style() const;
        /**
     * @brief Sets the `groupRowStyle` property of `NSTableRowView`.
     * @details When groupRowStyle is set to YES, this row is a group row and will draw appropriately.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_group_row_style(bool value) const;
        /**
     * @brief Returns the `indentationForDropOperation` property of `NSTableRowView`.
     * @return The converted Objective-C result.
     */
        double indentation_for_drop_operation() const;
        /**
     * @brief Sets the `indentationForDropOperation` property of `NSTableRowView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_indentation_for_drop_operation(double value) const;
        /**
     * @brief Returns the `interiorBackgroundStyle` property of `NSTableRowView`.
     * @details The interiorBackgroundStyle can be used as an indication of how the subviews should draw. This value is dynamically computed based on the set of properties set for the NSTableRowView. Subclassers can override this value when they draw differently based on the currently displayed properties. This method can also be called to determine what color a subview should use, or alternatively, NSControls can have the -backgroundStyle set on their cell to this value.
     * @return The converted Objective-C result.
     */
        BackgroundStyle interior_background_style() const;
        /**
     * @brief Returns the `nextRowSelected` property of `NSTableRowView`.
     * @return The converted Objective-C result.
     */
        bool is_next_row_selected() const;
        /**
     * @brief Sets the `nextRowSelected` property of `NSTableRowView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_next_row_selected(bool value) const;
        /**
     * @brief Returns the `numberOfColumns` property of `NSTableRowView`.
     * @details Provides access to the number of columns represented by views in this NSTableRowView. This may not be equal to the number of columns in the enclosing NSTableView, if this row view is a group style and has a single view that spans the entire width of the row.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_columns() const;
        /**
     * @brief Returns the `previousRowSelected` property of `NSTableRowView`.
     * @details Next and previous row selection state. Allows subclassers to draw selection differently based on the previous next row being selected. State is automatically updated by NSTableView, however, the changing of the state does not invalidate the row view. If a row view depends on this state, it should override the particular setter and call [self setNeedsDisplay:YES] before or after calling super.
     * @return The converted Objective-C result.
     */
        bool is_previous_row_selected() const;
        /**
     * @brief Sets the `previousRowSelected` property of `NSTableRowView`.
     * @details Next and previous row selection state. Allows subclassers to draw selection differently based on the previous next row being selected. State is automatically updated by NSTableView, however, the changing of the state does not invalidate the row view. If a row view depends on this state, it should override the particular setter and call [self setNeedsDisplay:YES] before or after calling super.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_previous_row_selected(bool value) const;
        /**
     * @brief Returns the `selected` property of `NSTableRowView`.
     * @details Selection state. The selection will be drawn when selected and the selectionHighlightStyle is not NSTableViewSelectionHighlightStyleNone.
     * @return The converted Objective-C result.
     */
        bool is_selected() const;
        /**
     * @brief Sets the `selected` property of `NSTableRowView`.
     * @details Selection state. The selection will be drawn when selected and the selectionHighlightStyle is not NSTableViewSelectionHighlightStyleNone.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected(bool value) const;
        /**
     * @brief Returns the `selectionHighlightStyle` property of `NSTableRowView`.
     * @details The tableView sets the selectionHighlightStyle based on its current value.
     * @return The converted Objective-C result.
     */
        TableViewSelectionHighlightStyle selection_highlight_style() const;
        /**
     * @brief Sets the `selectionHighlightStyle` property of `NSTableRowView`.
     * @details The tableView sets the selectionHighlightStyle based on its current value.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selection_highlight_style(TableViewSelectionHighlightStyle value) const;
        /**
     * @brief Returns the `targetForDropOperation` property of `NSTableRowView`.
     * @details Drag and drop state. When targetForDropOperation is set to YES, the NSTableRowView will draw a drop on indicator based on the current draggingDestinationFeedbackStyle. The indentationForDropOperation is set appropriately by NSOutlineView if the drop target row should be indented. Otherwise it is 0. On Mac OS 10.0.2, the indentation is always 0, and the feedback style is now drawn similar to selection.
     * @return The converted Objective-C result.
     */
        bool is_target_for_drop_operation() const;
        /**
     * @brief Sets the `targetForDropOperation` property of `NSTableRowView`.
     * @details Drag and drop state. When targetForDropOperation is set to YES, the NSTableRowView will draw a drop on indicator based on the current draggingDestinationFeedbackStyle. The indentationForDropOperation is set appropriately by NSOutlineView if the drop target row should be indented. Otherwise it is 0. On Mac OS 10.0.2, the indentation is always 0, and the feedback style is now drawn similar to selection.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_target_for_drop_operation(bool value) const;
    };
}
