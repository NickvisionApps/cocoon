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
    class Event;
    class Image;
    class IndexPath;
    class IndexSet;
    class Matrix;
    class Notification;
    class Pasteboard;
    class ViewController;

    /**
     * @brief C++ handle for the Objective-C class `NSBrowser` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Browser browser;
     * browser.set_allows_branch_selection(true);
     * browser.create_rows_for_column_in_matrix().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Browser browser{};
     * browser.set_allows_branch_selection(true);
     * auto allows_branch_selection = browser.allows_branch_selection();
     * browser.set_allows_empty_selection(true);
     * auto allows_empty_selection = browser.allows_empty_selection();
     * browser.set_allows_multiple_selection(true);
     * auto allows_multiple_selection = browser.allows_multiple_selection();
     * browser.add_column();
     * browser.can_drag_rows_with_indexes(cocoon::IndexSet(), 1, cocoon::Event());
     * browser.column_content_width_for_column_width(1);
     * browser.create_rows_for_column_in_matrix().connect([](std::int64_t a0, cocoon::Matrix a1) {});
     * browser.set_object_value_for_item().connect([](cocoon::Object a0, cocoon::Object a1) {});
     * browser.will_display_cell_at_row_column().connect([](cocoon::Object a0, std::int64_t a1, std::int64_t a2) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsbrowser
     */
    class Browser : public Control
    {
    public:
        /// @brief Creates a new `NSBrowser` instance and returns a handle to it.
        explicit Browser();
        /// @brief Creates a null handle that refers to no native object.
        Browser(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Browser(Adopt adopt);
        using Control::cell_class;
        using Control::selected_cell;
        using Control::send_action;
        using Control::set_cell_class;
        using View::set_background_color;
        /**
         * @brief Calls `-[NSBrowser addColumn]`.
         * @details Adds a column at the end. To remove columns, use -setLastColumn:
         */
        void add_column() const;
        /**
         * @brief Calls `-[NSBrowser canDragRowsWithIndexes:inColumn:withEvent:]`.
         * @details The return value indicates whether the receiver can attempt to initiate a drag for the given event. You can override this method and return NO to disallow initiating drags at the location in the given event. By default, the method will return YES if rowIndexes contains at least one item, and each item is enabled. If the equivalent delegate method is present, it will be preferred over this method, and you can safely call this method from your delegate.
         * @param row_indexes Argument converted to the Objective-C parameter of the same role.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @param event Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool can_drag_rows_with_indexes(const IndexSet& row_indexes, std::int64_t column, const Event& event) const;
        /**
         * @brief Calls `-[NSBrowser columnContentWidthForColumnWidth:]`.
         * @param column_width Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double column_content_width_for_column_width(double column_width) const;
        /**
         * @brief Calls `-[NSBrowser columnWidthForColumnContentWidth:]`.
         * @details These methods convert between column width (the column's scrollview), and the content width (the matrix in the scrollview). For example, to guarantee that 16 pixels of your browser cell are always visible, call [browser setMinColumnWidth:[browser columnWidthForColumnContentWidth:16]]
         * @param column_content_width Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double column_width_for_column_content_width(double column_content_width) const;
        /**
         * @brief Calls `-[NSBrowser defaultColumnWidth]`.
         * @return The converted Objective-C result.
         */
        double default_column_width() const;
        /**
         * @brief Calls `-[NSBrowser doClick:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void do_click(const Object& sender) const;
        /**
         * @brief Calls `-[NSBrowser doDoubleClick:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void do_double_click(const Object& sender) const;
        /**
         * @brief Calls `-[NSBrowser draggingImageForRowsWithIndexes:inColumn:withEvent:offset:]`.
         * @details This method computes and returns an image to use for dragging. You can override this to return a custom drag image, or call it to get the default drag image from the delegate method. 'rowIndexes' are the indexes of the cells being dragged in matrix 'column'. 'event' is a reference to the mouse down event that began the drag. 'dragImageOffset' is an in/out parameter. This method will be called with dragImageOffset set to NSZeroPoint, but it can be modified to re-position the returned image. A dragImageOffset of NSZeroPoint will cause the image to be centered under the mouse. By default, an image will be created that contain the visible cells within 'rowIndexes'. If the equivalent delegate method is present, it will be preferred over this method, and you can safely call this method from your delegate.
         * @param row_indexes Argument converted to the Objective-C parameter of the same role.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @param event Argument converted to the Objective-C parameter of the same role.
         * @param drag_image_offset Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Image dragging_image_for_rows_with_indexes(const IndexSet& row_indexes, std::int64_t column, const Event& event, Point* drag_image_offset) const;
        /**
         * @brief Calls `-[NSBrowser drawTitleOfColumn:inRect:]`.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         */
        void draw_title_of_column(std::int64_t column, const Rect& rect) const;
        /**
         * @brief Calls `-[NSBrowser editItemAtIndexPath:withEvent:select:]`.
         * @details Begins editing the item at the specified path. event may be nil if programmatically editing. The cell's contents will be selected if select is YES. Overriding this method will not affect the editing behavior of the browser.
         * @param index_path Argument converted to the Objective-C parameter of the same role.
         * @param event Argument converted to the Objective-C parameter of the same role.
         * @param select Argument converted to the Objective-C parameter of the same role.
         */
        void edit_item_at_index_path(const IndexPath& index_path, const Event& event, bool select) const;
        /**
         * @brief Calls `-[NSBrowser frameOfColumn:]`.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect frame_of_column(std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser frameOfInsideOfColumn:]`.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect frame_of_inside_of_column(std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser frameOfRow:inColumn:]`.
         * @details Returns the frame of the row at 'row' / 'column' including the area for the expandable arrow. The returned NSRect is in the NSBrowser coordinate space.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect frame_of_row(std::int64_t row, std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser getRow:column:forPoint:]`.
         * @details Finds the row and column located at 'point', returning YES if both can be found. If a row does not exist at 'point', then -1 is set for the row. If a column does not exist at 'point', then -1 is set for the column. 'point' is expected to be in the NSBrowser's coordinate system.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @param point Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool get_row(std::int64_t* row, std::int64_t* column, const Point& point) const;
        /**
         * @brief Calls `-[NSBrowser indexPathForColumn:]`.
         * @details Returns the index path of the item whose children are displayed in the given column. This method can only be used if the delegate implements the item data source methods.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        IndexPath index_path_for_column(std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser isLeafItem:]`.
         * @details Returns whether the given item is a leaf item. This method can only be used if the delegate implements the item data source methods.
         * @param item Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_leaf_item(const Object& item) const;
        /**
         * @brief Calls `-[NSBrowser itemAtIndexPath:]`.
         * @details Returns the item at the given index path. This method can only be used if the delegate implements the item data source methods. The indexPath must be displayable in the browser.
         * @param index_path Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object item_at_index_path(const IndexPath& index_path) const;
        /**
         * @brief Calls `-[NSBrowser itemAtRow:inColumn:]`.
         * @details Returns the item located at 'row' in 'column'.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object item_at_row(std::int64_t row, std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser loadColumnZero]`.
         */
        void load_column_zero() const;
        /**
         * @brief Calls `-[NSBrowser loadedCellAtRow:column:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param col Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object loaded_cell_at_row(std::int64_t row, std::int64_t col) const;
        /**
         * @brief Calls `-[NSBrowser noteHeightOfRowsWithIndexesChanged:inColumn:]`.
         * @details If the delegate implements -browser:heightOfRow:inColumn:, this method immediately re-tiles the browser columns using row heights it provides.
         * @param index_set Argument converted to the Objective-C parameter of the same role.
         * @param column_index Argument converted to the Objective-C parameter of the same role.
         */
        void note_height_of_rows_with_indexes_changed(const IndexSet& index_set, std::int64_t column_index) const;
        /**
         * @brief Calls `-[NSBrowser parentForItemsInColumn:]`.
         * @details Returns the item that contains all children located in 'column'. In other words, it is the parent item for that column.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object parent_for_items_in_column(std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser path]`.
         * @return The converted Objective-C result.
         */
        std::string path() const;
        /**
         * @brief Calls `-[NSBrowser pathToColumn:]`.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string path_to_column(std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser reloadColumn:]`.
         * @param column Argument converted to the Objective-C parameter of the same role.
         */
        void reload_column(std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser reloadDataForRowIndexes:inColumn:]`.
         * @details Updates a particular set of rows in 'column'. For rows that are visible, appropriate dataSource and delegate methods will be called and the row will be redrawn. For browsers that support variable row heights, the row height will not be re-queried from the delegate. This method can only be used if the delegate implements the item data source methods.
         * @param row_indexes Argument converted to the Objective-C parameter of the same role.
         * @param column Argument converted to the Objective-C parameter of the same role.
         */
        void reload_data_for_row_indexes(const IndexSet& row_indexes, std::int64_t column) const;
        /**
         * @brief Calls `+[NSBrowser removeSavedColumnsWithAutosaveName:]`.
         * @details Removes the column data stored under name from the applications user defaults.
         * @param name Argument converted to the Objective-C parameter of the same role.
         */
        static void remove_saved_columns_with_autosave_name(const std::string& name);
        /**
         * @brief Calls `-[NSBrowser scrollColumnToVisible:]`.
         * @param column Argument converted to the Objective-C parameter of the same role.
         */
        void scroll_column_to_visible(std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser scrollColumnsLeftBy:]`.
         * @param shift_amount Argument converted to the Objective-C parameter of the same role.
         */
        void scroll_columns_left_by(std::int64_t shift_amount) const;
        /**
         * @brief Calls `-[NSBrowser scrollColumnsRightBy:]`.
         * @param shift_amount Argument converted to the Objective-C parameter of the same role.
         */
        void scroll_columns_right_by(std::int64_t shift_amount) const;
        /**
         * @brief Calls `-[NSBrowser scrollRowToVisible:inColumn:]`.
         * @details Scrolls 'row' to be visible within 'column'. 'column' will not be scrolled visible. To scroll 'column' to visible, first call -[browser scrollColumnToVisible:column].
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param column Argument converted to the Objective-C parameter of the same role.
         */
        void scroll_row_to_visible(std::int64_t row, std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser selectAll:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void select_all(const Object& sender) const;
        /**
         * @brief Calls `-[NSBrowser selectRow:inColumn:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param column Argument converted to the Objective-C parameter of the same role.
         */
        void select_row(std::int64_t row, std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser selectRowIndexes:inColumn:]`.
         * @details Sets the selected row 'indexes' in the matrix located at 'column'.
         * @param indexes Argument converted to the Objective-C parameter of the same role.
         * @param column Argument converted to the Objective-C parameter of the same role.
         */
        void select_row_indexes(const IndexSet& indexes, std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser selectedCellInColumn:]`.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object selected_cell_in_column(std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser selectedRowInColumn:]`.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t selected_row_in_column(std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser selectedRowIndexesInColumn:]`.
         * @details Returns the selected cell indexes in the matrix located at 'column'.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        IndexSet selected_row_indexes_in_column(std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser sendAction]`.
         * @return The converted Objective-C result.
         */
        bool send_action() const;
        /**
         * @brief Calls `-[NSBrowser setCellClass:]`.
         * @param factory_id Argument converted to the Objective-C parameter of the same role.
         */
        void set_cell_class(const std::string& factory_id) const;
        /**
         * @brief Calls `-[NSBrowser setDefaultColumnWidth:]`.
         * @details Persistently sets the default width for new columns which don't otherwise have initial width from either defaults or the delegate. This method replaces -setWidth:ofColumn: with a columnIndex of -1.
         * @param column_width Argument converted to the Objective-C parameter of the same role.
         */
        void set_default_column_width(double column_width) const;
        /**
         * @brief Calls `-[NSBrowser setDraggingSourceOperationMask:forLocal:]`.
         * @details Configures the value returned from -draggingSourceOperationMaskForLocal:. An isLocal value of YES indicates that 'mask' applies when the destination object is in the same application. By default, NSDragOperationEvery will be returned. An isLocal value of NO indicates that 'mask' applies when the destination object in an application outside the receiver's application. By default, NSDragOperationNone is returned. NSBrowser will save the values you set for each isLocal setting. You typically will invoke this method, and not override it.
         * @param mask Argument converted to the Objective-C parameter of the same role.
         * @param is_local Argument converted to the Objective-C parameter of the same role.
         */
        void set_dragging_source_operation_mask(DragOperation mask, bool is_local) const;
        /**
         * @brief Calls `-[NSBrowser setPath:]`.
         * @param path Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool set_path(const std::string& path) const;
        /**
         * @brief Calls `-[NSBrowser setTitle:ofColumn:]`.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param column Argument converted to the Objective-C parameter of the same role.
         */
        void set_title(const std::string& string, std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser setWidth:ofColumn:]`.
         * @details setWidth:ofColumn: does nothing if columnResizingType is NSBrowserAutoColumnResizing. Otherwise, Sets the width of the specified column. Due to binary compatibility constraints, you may still set the default width for new columns by passing a columnIndex of -1; you are encouraged to use -setDefaultColumnWidth: instead. NSBrowserColumnConfigurationDidChangeNotification will be posted (not immediately) if necessary. The receiver will autosave its column configuration if necessary.
         * @param column_width Argument converted to the Objective-C parameter of the same role.
         * @param column_index Argument converted to the Objective-C parameter of the same role.
         */
        void set_width(double column_width, std::int64_t column_index) const;
        /**
         * @brief Calls `-[NSBrowser tile]`.
         */
        void tile() const;
        /**
         * @brief Calls `-[NSBrowser titleFrameOfColumn:]`.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect title_frame_of_column(std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser titleOfColumn:]`.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string title_of_column(std::int64_t column) const;
        /**
         * @brief Calls `-[NSBrowser validateVisibleColumns]`.
         */
        void validate_visible_columns() const;
        /**
         * @brief Calls `-[NSBrowser widthOfColumn:]`.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double width_of_column(std::int64_t column) const;
        /**
         * @brief Returns the `allowsBranchSelection` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        bool allows_branch_selection() const;
        /**
         * @brief Sets the `allowsBranchSelection` property of `NSBrowser`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_branch_selection(bool value) const;
        /**
         * @brief Returns the `allowsEmptySelection` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        bool allows_empty_selection() const;
        /**
         * @brief Sets the `allowsEmptySelection` property of `NSBrowser`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_empty_selection(bool value) const;
        /**
         * @brief Returns the `allowsMultipleSelection` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        bool allows_multiple_selection() const;
        /**
         * @brief Sets the `allowsMultipleSelection` property of `NSBrowser`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_multiple_selection(bool value) const;
        /**
         * @brief Returns the `allowsTypeSelect` property of `NSBrowser`.
         * @details Allow type selection in this NSBrowser. The default for 'allowsTypeSelect' is YES.
         * @return The converted Objective-C result.
         */
        bool allows_type_select() const;
        /**
         * @brief Sets the `allowsTypeSelect` property of `NSBrowser`.
         * @details Allow type selection in this NSBrowser. The default for 'allowsTypeSelect' is YES.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_type_select(bool value) const;
        /**
         * @brief Returns the `autohidesScroller` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        bool autohides_scroller() const;
        /**
         * @brief Sets the `autohidesScroller` property of `NSBrowser`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_autohides_scroller(bool value) const;
        /**
         * @brief Returns the `backgroundColor` property of `NSBrowser`.
         * @details The background color to be drawn. By default, it will be set [NSColor whiteColor]. You can use [NSColor clearColor] to make the background transparent. NSBrowser will return YES from isOpaque if the backgroundColor has an alphaComponent of 1.0 and it doesn't have a title, otherwise, it will return NO. Calling setBackgroundColor: will cause all NSMatrix instances have setDrawsBackground:NO be called in order for the NSBrowser's background color to show through. When drawing with the background color, NSCompositeSourceOver is used for the compositing operation.
         * @return The converted Objective-C result.
         */
        Color background_color() const;
        /**
         * @brief Sets the `backgroundColor` property of `NSBrowser`.
         * @details The background color to be drawn. By default, it will be set [NSColor whiteColor]. You can use [NSColor clearColor] to make the background transparent. NSBrowser will return YES from isOpaque if the backgroundColor has an alphaComponent of 1.0 and it doesn't have a title, otherwise, it will return NO. Calling setBackgroundColor: will cause all NSMatrix instances have setDrawsBackground:NO be called in order for the NSBrowser's background color to show through. When drawing with the background color, NSCompositeSourceOver is used for the compositing operation.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_background_color(const Color& value) const;
        /**
         * @brief Returns the `cellClass` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        static std::string cell_class();
        /**
         * @brief Returns the `cellPrototype` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        Object cell_prototype() const;
        /**
         * @brief Sets the `cellPrototype` property of `NSBrowser`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_cell_prototype(const Object& value) const;
        /**
         * @brief Returns the `clickedColumn` property of `NSBrowser`.
         * @details Returns the column and row clicked on to display a context menu. These methods will return -1 when no menu is active.
         * @return The converted Objective-C result.
         */
        std::int64_t clicked_column() const;
        /**
         * @brief Returns the `clickedRow` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        std::int64_t clicked_row() const;
        /**
         * @brief Returns the `columnResizingType` property of `NSBrowser`.
         * @details Default is NSBrowserAutoColumnResizing. This setting is persistent.
         * @return The converted Objective-C result.
         */
        BrowserColumnResizingType column_resizing_type() const;
        /**
         * @brief Sets the `columnResizingType` property of `NSBrowser`.
         * @details Default is NSBrowserAutoColumnResizing. This setting is persistent.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_column_resizing_type(BrowserColumnResizingType value) const;
        /**
         * @brief Returns the `columnsAutosaveName` property of `NSBrowser`.
         * @details Sets the name used to automatically save the receivers column configuration. This setting is persistent. If name is different from the current name, this method also reads in the saved column configuration for the new name and applies the values to the browser. Column configuration is defined as an array of column content widths. One width is saved for each level the user has reached. That is, browser saves column width based on depth, not based on unique paths. To do more complex column persistence, you should register for NSBrowserColumnConfigurationDidChangeNotifications and handle persistence yourself.
         * @return The converted Objective-C result.
         */
        std::string columns_autosave_name() const;
        /**
         * @brief Sets the `columnsAutosaveName` property of `NSBrowser`.
         * @details Sets the name used to automatically save the receivers column configuration. This setting is persistent. If name is different from the current name, this method also reads in the saved column configuration for the new name and applies the values to the browser. Column configuration is defined as an array of column content widths. One width is saved for each level the user has reached. That is, browser saves column width based on depth, not based on unique paths. To do more complex column persistence, you should register for NSBrowserColumnConfigurationDidChangeNotifications and handle persistence yourself.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_columns_autosave_name(const std::string& value) const;
        /**
         * @brief Returns the `doubleAction` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        std::string double_action() const;
        /**
         * @brief Sets the `doubleAction` property of `NSBrowser`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_double_action(const std::string& value) const;
        /**
         * @brief Returns the `firstVisibleColumn` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        std::int64_t first_visible_column() const;
        /**
         * @brief Returns the `hasHorizontalScroller` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        bool has_horizontal_scroller() const;
        /**
         * @brief Sets the `hasHorizontalScroller` property of `NSBrowser`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_has_horizontal_scroller(bool value) const;
        /**
         * @brief Returns the `lastColumn` property of `NSBrowser`.
         * @details Returns the last loaded column. This is equal to the total number of columns minus 1. When setting. 'column' must be equal to or less than -lastColumn. To add more columns, use -addColumn.
         * @return The converted Objective-C result.
         */
        std::int64_t last_column() const;
        /**
         * @brief Sets the `lastColumn` property of `NSBrowser`.
         * @details Returns the last loaded column. This is equal to the total number of columns minus 1. When setting. 'column' must be equal to or less than -lastColumn. To add more columns, use -addColumn.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_last_column(std::int64_t value) const;
        /**
         * @brief Returns the `lastVisibleColumn` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        std::int64_t last_visible_column() const;
        /**
         * @brief Returns the `loaded` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        bool is_loaded() const;
        /**
         * @brief Returns the `maxVisibleColumns` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        std::int64_t max_visible_columns() const;
        /**
         * @brief Sets the `maxVisibleColumns` property of `NSBrowser`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_max_visible_columns(std::int64_t value) const;
        /**
         * @brief Returns the `minColumnWidth` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        double min_column_width() const;
        /**
         * @brief Sets the `minColumnWidth` property of `NSBrowser`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_min_column_width(double value) const;
        /**
         * @brief Returns the `numberOfVisibleColumns` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_visible_columns() const;
        /**
         * @brief Returns the `pathSeparator` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        std::string path_separator() const;
        /**
         * @brief Sets the `pathSeparator` property of `NSBrowser`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_path_separator(const std::string& value) const;
        /**
         * @brief Returns the `prefersAllColumnUserResizing` property of `NSBrowser`.
         * @details Default is NO. This setting is persistent. This setting only applies to NSBrowserUserColumnResizing type browsers. If YES, the browser defaults to resizing all columns simultaneously, otherwise it defaults to single column resizing. Holding down the option key while resizing switches the type of resizing used.
         * @return The converted Objective-C result.
         */
        bool prefers_all_column_user_resizing() const;
        /**
         * @brief Sets the `prefersAllColumnUserResizing` property of `NSBrowser`.
         * @details Default is NO. This setting is persistent. This setting only applies to NSBrowserUserColumnResizing type browsers. If YES, the browser defaults to resizing all columns simultaneously, otherwise it defaults to single column resizing. Holding down the option key while resizing switches the type of resizing used.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_prefers_all_column_user_resizing(bool value) const;
        /**
         * @brief Returns the `reusesColumns` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        bool reuses_columns() const;
        /**
         * @brief Sets the `reusesColumns` property of `NSBrowser`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_reuses_columns(bool value) const;
        /**
         * @brief Returns the `rowHeight` property of `NSBrowser`.
         * @details Get and set the rowHeight. The value must be greater than 0. Calling -setRowHeight: with a non-pixel aligning (fractional) value will be forced to a pixel aligning (integral) value. For variable row height browsers (ones that have the delegate implement -browser:heightOfRow:column:), -rowHeight will be used to draw alternating rows past the last row in each browser column. The default value is 17.0. Note: The rowHeight methods are only valid when using the item delegate methods introduced in Mac OS 10.6. (see NSObject(NSBrowserDelegate)). An exception is thrown if using the older matrix delegate methods
         * @return The converted Objective-C result.
         */
        double row_height() const;
        /**
         * @brief Sets the `rowHeight` property of `NSBrowser`.
         * @details Get and set the rowHeight. The value must be greater than 0. Calling -setRowHeight: with a non-pixel aligning (fractional) value will be forced to a pixel aligning (integral) value. For variable row height browsers (ones that have the delegate implement -browser:heightOfRow:column:), -rowHeight will be used to draw alternating rows past the last row in each browser column. The default value is 17.0. Note: The rowHeight methods are only valid when using the item delegate methods introduced in Mac OS 10.6. (see NSObject(NSBrowserDelegate)). An exception is thrown if using the older matrix delegate methods
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_row_height(double value) const;
        /**
         * @brief Returns the `selectedCell` property of `NSBrowser`.
         * @details For the item based browser, selectedCell returns the prepared cell at the selected row in the selected column.
         * @return The converted Objective-C result.
         */
        Object selected_cell() const;
        /**
         * @brief Returns the `selectedCells` property of `NSBrowser`.
         * @details For the item based browser, selectedCells returns a copy of all prepared cells in the selected row in the selected column
         * @return The converted Objective-C result.
         */
        std::vector<Cell> selected_cells() const;
        /**
         * @brief Returns the `selectedColumn` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        std::int64_t selected_column() const;
        /**
         * @brief Returns the `selectionIndexPath` property of `NSBrowser`.
         * @details Returns the index path of the item selected in the browser, or nil if there is no selection. The setter sets the browser's selection to the item at path. Throws an exception if the path is invalid. This method can only be used if the delegate implements the item data source methods.
         * @return The converted Objective-C result.
         */
        IndexPath selection_index_path() const;
        /**
         * @brief Sets the `selectionIndexPath` property of `NSBrowser`.
         * @details Returns the index path of the item selected in the browser, or nil if there is no selection. The setter sets the browser's selection to the item at path. Throws an exception if the path is invalid. This method can only be used if the delegate implements the item data source methods.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_selection_index_path(const IndexPath& value) const;
        /**
         * @brief Returns the `selectionIndexPaths` property of `NSBrowser`.
         * @details Returns the index paths of all items selected in the browser. The setter sets the browser's selection to the specified index paths. Throws an exception if any of the paths are invalid. This method can only be used if the delegate implements the item data source methods.
         * @return The converted Objective-C result.
         */
        std::vector<IndexPath> selection_index_paths() const;
        /**
         * @brief Sets the `selectionIndexPaths` property of `NSBrowser`.
         * @details Returns the index paths of all items selected in the browser. The setter sets the browser's selection to the specified index paths. Throws an exception if any of the paths are invalid. This method can only be used if the delegate implements the item data source methods.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_selection_index_paths(const std::vector<IndexPath>& value) const;
        /**
         * @brief Returns the `sendsActionOnArrowKeys` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        bool sends_action_on_arrow_keys() const;
        /**
         * @brief Sets the `sendsActionOnArrowKeys` property of `NSBrowser`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_sends_action_on_arrow_keys(bool value) const;
        /**
         * @brief Returns the `separatesColumns` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        bool separates_columns() const;
        /**
         * @brief Sets the `separatesColumns` property of `NSBrowser`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_separates_columns(bool value) const;
        /**
         * @brief Returns the `takesTitleFromPreviousColumn` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        bool takes_title_from_previous_column() const;
        /**
         * @brief Sets the `takesTitleFromPreviousColumn` property of `NSBrowser`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_takes_title_from_previous_column(bool value) const;
        /**
         * @brief Returns the `titleHeight` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        double title_height() const;
        /**
         * @brief Returns the `titled` property of `NSBrowser`.
         * @return The converted Objective-C result.
         */
        bool is_titled() const;
        /**
         * @brief Sets the `titled` property of `NSBrowser`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_titled(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `number_of_rows_in_column`; connect a callback with `number_of_rows_in_column().connect(...)`.
        Signal<Browser, std::int64_t(std::int64_t)> number_of_rows_in_column() const
        {
            return Signal<Browser, std::int64_t(std::int64_t)>(handle(), "number_of_rows_in_column");
        }
        /// @brief Signal for the delegate/data-source method behind `create_rows_for_column_in_matrix`; connect a callback with `create_rows_for_column_in_matrix().connect(...)`.
        Signal<Browser, void(std::int64_t, Matrix)> create_rows_for_column_in_matrix() const
        {
            return Signal<Browser, void(std::int64_t, Matrix)>(handle(), "create_rows_for_column_in_matrix");
        }
        /// @brief Signal for the delegate/data-source method behind `number_of_children_of_item`; connect a callback with `number_of_children_of_item().connect(...)`.
        Signal<Browser, std::int64_t(Object)> number_of_children_of_item() const
        {
            return Signal<Browser, std::int64_t(Object)>(handle(), "number_of_children_of_item");
        }
        /// @brief Signal for the delegate/data-source method behind `child_of_item`; connect a callback with `child_of_item().connect(...)`.
        Signal<Browser, Object(std::int64_t, Object)> child_of_item() const
        {
            return Signal<Browser, Object(std::int64_t, Object)>(handle(), "child_of_item");
        }
        /// @brief Signal for the delegate/data-source method behind `browser_is_leaf_item`; connect a callback with `browser_is_leaf_item().connect(...)`.
        Signal<Browser, bool(Object)> browser_is_leaf_item() const
        {
            return Signal<Browser, bool(Object)>(handle(), "browser_is_leaf_item");
        }
        /// @brief Signal for the delegate/data-source method behind `object_value_for_item`; connect a callback with `object_value_for_item().connect(...)`.
        Signal<Browser, Object(Object)> object_value_for_item() const
        {
            return Signal<Browser, Object(Object)>(handle(), "object_value_for_item");
        }
        /// @brief Signal for the delegate/data-source method behind `height_of_row_in_column`; connect a callback with `height_of_row_in_column().connect(...)`.
        Signal<Browser, double(std::int64_t, std::int64_t)> height_of_row_in_column() const
        {
            return Signal<Browser, double(std::int64_t, std::int64_t)>(handle(), "height_of_row_in_column");
        }
        /// @brief Signal for the delegate/data-source method behind `root_item_for_browser`; connect a callback with `root_item_for_browser().connect(...)`.
        Signal<Browser, Object()> root_item_for_browser() const
        {
            return Signal<Browser, Object()>(handle(), "root_item_for_browser");
        }
        /// @brief Signal for the delegate/data-source method behind `set_object_value_for_item`; connect a callback with `set_object_value_for_item().connect(...)`.
        Signal<Browser, void(Object, Object)> set_object_value_for_item() const
        {
            return Signal<Browser, void(Object, Object)>(handle(), "set_object_value_for_item");
        }
        /// @brief Signal for the delegate/data-source method behind `should_edit_item`; connect a callback with `should_edit_item().connect(...)`.
        Signal<Browser, bool(Object)> should_edit_item() const
        {
            return Signal<Browser, bool(Object)>(handle(), "should_edit_item");
        }
        /// @brief Signal for the delegate/data-source method behind `will_display_cell_at_row_column`; connect a callback with `will_display_cell_at_row_column().connect(...)`.
        Signal<Browser, void(Object, std::int64_t, std::int64_t)> will_display_cell_at_row_column() const
        {
            return Signal<Browser, void(Object, std::int64_t, std::int64_t)>(handle(), "will_display_cell_at_row_column");
        }
        /// @brief Signal for the delegate/data-source method behind `browser_title_of_column`; connect a callback with `browser_title_of_column().connect(...)`.
        Signal<Browser, std::string(std::int64_t)> browser_title_of_column() const
        {
            return Signal<Browser, std::string(std::int64_t)>(handle(), "browser_title_of_column");
        }
        /// @brief Signal for the delegate/data-source method behind `select_cell_with_string_in_column`; connect a callback with `select_cell_with_string_in_column().connect(...)`.
        Signal<Browser, bool(std::string, std::int64_t)> select_cell_with_string_in_column() const
        {
            return Signal<Browser, bool(std::string, std::int64_t)>(handle(), "select_cell_with_string_in_column");
        }
        /// @brief Signal for the delegate/data-source method behind `select_row_in_column`; connect a callback with `select_row_in_column().connect(...)`.
        Signal<Browser, bool(std::int64_t, std::int64_t)> select_row_in_column() const
        {
            return Signal<Browser, bool(std::int64_t, std::int64_t)>(handle(), "select_row_in_column");
        }
        /// @brief Signal for the delegate/data-source method behind `is_column_valid`; connect a callback with `is_column_valid().connect(...)`.
        Signal<Browser, bool(std::int64_t)> is_column_valid() const
        {
            return Signal<Browser, bool(std::int64_t)>(handle(), "is_column_valid");
        }
        /// @brief Signal for the delegate/data-source method behind `will_scroll`; connect a callback with `will_scroll().connect(...)`.
        Signal<Browser, void()> will_scroll() const
        {
            return Signal<Browser, void()>(handle(), "will_scroll");
        }
        /// @brief Signal for the delegate/data-source method behind `did_scroll`; connect a callback with `did_scroll().connect(...)`.
        Signal<Browser, void()> did_scroll() const
        {
            return Signal<Browser, void()>(handle(), "did_scroll");
        }
        /// @brief Signal for the delegate/data-source method behind `should_size_column_for_user_resize_to_width`; connect a callback with `should_size_column_for_user_resize_to_width().connect(...)`.
        Signal<Browser, double(std::int64_t, bool, double)> should_size_column_for_user_resize_to_width() const
        {
            return Signal<Browser, double(std::int64_t, bool, double)>(handle(), "should_size_column_for_user_resize_to_width");
        }
        /// @brief Signal for the delegate/data-source method behind `size_to_fit_width_of_column`; connect a callback with `size_to_fit_width_of_column().connect(...)`.
        Signal<Browser, double(std::int64_t)> size_to_fit_width_of_column() const
        {
            return Signal<Browser, double(std::int64_t)>(handle(), "size_to_fit_width_of_column");
        }
        /// @brief Signal for the delegate/data-source method behind `column_configuration_did_change`; connect a callback with `column_configuration_did_change().connect(...)`.
        Signal<Browser, void(Notification)> column_configuration_did_change() const
        {
            return Signal<Browser, void(Notification)>(handle(), "column_configuration_did_change");
        }
        /// @brief Signal for the delegate/data-source method behind `should_show_cell_expansion_for_row_column`; connect a callback with `should_show_cell_expansion_for_row_column().connect(...)`.
        Signal<Browser, bool(std::int64_t, std::int64_t)> should_show_cell_expansion_for_row_column() const
        {
            return Signal<Browser, bool(std::int64_t, std::int64_t)>(handle(), "should_show_cell_expansion_for_row_column");
        }
        /// @brief Signal for the delegate/data-source method behind `write_rows_with_indexes_in_column_to_pasteboard`; connect a callback with `write_rows_with_indexes_in_column_to_pasteboard().connect(...)`.
        Signal<Browser, bool(IndexSet, std::int64_t, Pasteboard)> write_rows_with_indexes_in_column_to_pasteboard() const
        {
            return Signal<Browser, bool(IndexSet, std::int64_t, Pasteboard)>(handle(), "write_rows_with_indexes_in_column_to_pasteboard");
        }
        /// @brief Signal for the delegate/data-source method behind `can_drag_rows_with_indexes_in_column_with_event`; connect a callback with `can_drag_rows_with_indexes_in_column_with_event().connect(...)`.
        Signal<Browser, bool(IndexSet, std::int64_t, Event)> can_drag_rows_with_indexes_in_column_with_event() const
        {
            return Signal<Browser, bool(IndexSet, std::int64_t, Event)>(handle(), "can_drag_rows_with_indexes_in_column_with_event");
        }
        /// @brief Signal for the delegate/data-source method behind `dragging_image_for_rows_with_indexes_in_column_with_event_offset`; connect a callback with `dragging_image_for_rows_with_indexes_in_column_with_event_offset().connect(...)`.
        Signal<Browser, Image(IndexSet, std::int64_t, Event, Point*)> dragging_image_for_rows_with_indexes_in_column_with_event_offset() const
        {
            return Signal<Browser, Image(IndexSet, std::int64_t, Event, Point*)>(handle(), "dragging_image_for_rows_with_indexes_in_column_with_event_offset");
        }
        /// @brief Signal for the delegate/data-source method behind `validate_drop_proposed_row_column_drop_operation`; connect a callback with `validate_drop_proposed_row_column_drop_operation().connect(...)`.
        Signal<Browser, DragOperation(Object, std::int64_t*, std::int64_t*, BrowserDropOperation*)> validate_drop_proposed_row_column_drop_operation() const
        {
            return Signal<Browser, DragOperation(Object, std::int64_t*, std::int64_t*, BrowserDropOperation*)>(handle(), "validate_drop_proposed_row_column_drop_operation");
        }
        /// @brief Signal for the delegate/data-source method behind `accept_drop_at_row_column_drop_operation`; connect a callback with `accept_drop_at_row_column_drop_operation().connect(...)`.
        Signal<Browser, bool(Object, std::int64_t, std::int64_t, BrowserDropOperation)> accept_drop_at_row_column_drop_operation() const
        {
            return Signal<Browser, bool(Object, std::int64_t, std::int64_t, BrowserDropOperation)>(handle(), "accept_drop_at_row_column_drop_operation");
        }
        /// @brief Signal for the delegate/data-source method behind `type_select_string_for_row_in_column`; connect a callback with `type_select_string_for_row_in_column().connect(...)`.
        Signal<Browser, std::string(std::int64_t, std::int64_t)> type_select_string_for_row_in_column() const
        {
            return Signal<Browser, std::string(std::int64_t, std::int64_t)>(handle(), "type_select_string_for_row_in_column");
        }
        /// @brief Signal for the delegate/data-source method behind `should_type_select_for_event_with_current_search_string`; connect a callback with `should_type_select_for_event_with_current_search_string().connect(...)`.
        Signal<Browser, bool(Event, std::string)> should_type_select_for_event_with_current_search_string() const
        {
            return Signal<Browser, bool(Event, std::string)>(handle(), "should_type_select_for_event_with_current_search_string");
        }
        /// @brief Signal for the delegate/data-source method behind `next_type_select_match_from_row_to_row_in_column_for_string`; connect a callback with `next_type_select_match_from_row_to_row_in_column_for_string().connect(...)`.
        Signal<Browser, std::int64_t(std::int64_t, std::int64_t, std::int64_t, std::string)> next_type_select_match_from_row_to_row_in_column_for_string() const
        {
            return Signal<Browser, std::int64_t(std::int64_t, std::int64_t, std::int64_t, std::string)>(handle(), "next_type_select_match_from_row_to_row_in_column_for_string");
        }
        /// @brief Signal for the delegate/data-source method behind `preview_view_controller_for_leaf_item`; connect a callback with `preview_view_controller_for_leaf_item().connect(...)`.
        Signal<Browser, ViewController(Object)> preview_view_controller_for_leaf_item() const
        {
            return Signal<Browser, ViewController(Object)>(handle(), "preview_view_controller_for_leaf_item");
        }
        /// @brief Signal for the delegate/data-source method behind `header_view_controller_for_item`; connect a callback with `header_view_controller_for_item().connect(...)`.
        Signal<Browser, ViewController(Object)> header_view_controller_for_item() const
        {
            return Signal<Browser, ViewController(Object)>(handle(), "header_view_controller_for_item");
        }
        /// @brief Signal for the delegate/data-source method behind `did_change_last_column_to_column`; connect a callback with `did_change_last_column_to_column().connect(...)`.
        Signal<Browser, void(std::int64_t, std::int64_t)> did_change_last_column_to_column() const
        {
            return Signal<Browser, void(std::int64_t, std::int64_t)>(handle(), "did_change_last_column_to_column");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_indexes_for_proposed_selection_in_column`; connect a callback with `selection_indexes_for_proposed_selection_in_column().connect(...)`.
        Signal<Browser, IndexSet(IndexSet, std::int64_t)> selection_indexes_for_proposed_selection_in_column() const
        {
            return Signal<Browser, IndexSet(IndexSet, std::int64_t)>(handle(), "selection_indexes_for_proposed_selection_in_column");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
