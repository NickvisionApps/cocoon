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
    class Notification;
    class Text;
    class TextView;

    /**
     * @brief C++ handle for the Objective-C class `NSMatrix` (AppKit).
     * @details NSMatrix is deprecated and will be unsupported in future releases. For radio button grouping, sibling radio buttons that share the same action will operate in an exclusive mode.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Matrix matrix;
     * matrix.set_allows_empty_selection(true);
     * matrix.control_text_did_begin_editing().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Matrix matrix{};
     * matrix.set_allows_empty_selection(true);
     * auto allows_empty_selection = matrix.allows_empty_selection();
     * matrix.set_autorecalculates_cell_size(true);
     * auto autorecalculates_cell_size = matrix.autorecalculates_cell_size();
     * matrix.set_autoscroll(true);
     * auto autoscroll = matrix.is_autoscroll();
     * matrix.accepts_first_mouse(cocoon::Event());
     * matrix.add_column();
     * matrix.add_row();
     * matrix.control_text_did_begin_editing().connect([](cocoon::Notification a0) {});
     * matrix.control_text_did_end_editing().connect([](cocoon::Notification a0) {});
     * matrix.control_text_did_change().connect([](cocoon::Notification a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsmatrix
     */
    class Matrix : public Control
    {
    public:
        /// @brief Creates a new `NSMatrix` instance and returns a handle to it.
        explicit Matrix(const Rect& frame_rect);
        /// @brief Creates a new `NSMatrix` instance and returns a handle to it.
        explicit Matrix(const Rect& frame_rect, MatrixMode mode, const std::string& factory_id, std::int64_t rows_high, std::int64_t cols_wide);
        /// @brief Creates a new `NSMatrix` instance and returns a handle to it.
        explicit Matrix(const Rect& frame_rect, MatrixMode mode, const Cell& cell, std::int64_t rows_high, std::int64_t cols_wide);
        /// @brief Creates a new `NSMatrix` instance and returns a handle to it.
        explicit Matrix();
        /// @brief Creates a null handle that refers to no native object.
        Matrix(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Matrix(Adopt adopt);
        using Control::cell_class;
        using Control::selected_cell;
        using Control::send_action;
        using Control::set_cell_class;
        using Responder::mouse_down;
        using View::accepts_first_mouse;
        using View::perform_key_equivalent;
        using View::reset_cursor_rects;
        using View::set_background_color;
        using View::set_tool_tip;
        /**
         * @brief Calls `-[NSMatrix acceptsFirstMouse:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool accepts_first_mouse(const Event& event) const;
        /**
         * @brief Calls `-[NSMatrix addColumn]`.
         */
        void add_column() const;
        /**
         * @brief Calls `-[NSMatrix addColumnWithCells:]`.
         * @param new_cells Argument converted to the Objective-C parameter of the same role.
         */
        void add_column_with_cells(const std::vector<Cell>& new_cells) const;
        /**
         * @brief Calls `-[NSMatrix addRow]`.
         */
        void add_row() const;
        /**
         * @brief Calls `-[NSMatrix addRowWithCells:]`.
         * @param new_cells Argument converted to the Objective-C parameter of the same role.
         */
        void add_row_with_cells(const std::vector<Cell>& new_cells) const;
        /**
         * @brief Calls `-[NSMatrix cellAtRow:column:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param col Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Cell cell_at_row(std::int64_t row, std::int64_t col) const;
        /**
         * @brief Calls `-[NSMatrix cellFrameAtRow:column:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param col Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect cell_frame_at_row(std::int64_t row, std::int64_t col) const;
        /**
         * @brief Calls `-[NSMatrix cellWithTag:]`.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Cell cell_with_tag(std::int64_t tag) const;
        /**
         * @brief Calls `-[NSMatrix deselectAllCells]`.
         */
        void deselect_all_cells() const;
        /**
         * @brief Calls `-[NSMatrix deselectSelectedCell]`.
         */
        void deselect_selected_cell() const;
        /**
         * @brief Calls `-[NSMatrix drawCellAtRow:column:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param col Argument converted to the Objective-C parameter of the same role.
         */
        void draw_cell_at_row(std::int64_t row, std::int64_t col) const;
        /**
         * @brief Calls `-[NSMatrix getNumberOfRows:columns:]`.
         * @param row_count Argument converted to the Objective-C parameter of the same role.
         * @param col_count Argument converted to the Objective-C parameter of the same role.
         */
        void get_number_of_rows(std::int64_t* row_count, std::int64_t* col_count) const;
        /**
         * @brief Calls `-[NSMatrix getRow:column:forPoint:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param col Argument converted to the Objective-C parameter of the same role.
         * @param point Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool get_row(std::int64_t* row, std::int64_t* col, const Point& point) const;
        /**
         * @brief Calls `-[NSMatrix getRow:column:ofCell:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param col Argument converted to the Objective-C parameter of the same role.
         * @param cell Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool get_row(std::int64_t* row, std::int64_t* col, const Cell& cell) const;
        /**
         * @brief Calls `-[NSMatrix highlightCell:atRow:column:]`.
         * @param flag Argument converted to the Objective-C parameter of the same role.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param col Argument converted to the Objective-C parameter of the same role.
         */
        void highlight_cell(bool flag, std::int64_t row, std::int64_t col) const;
        /**
         * @brief Calls `-[NSMatrix insertColumn:]`.
         * @param column Argument converted to the Objective-C parameter of the same role.
         */
        void insert_column(std::int64_t column) const;
        /**
         * @brief Calls `-[NSMatrix insertColumn:withCells:]`.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @param new_cells Argument converted to the Objective-C parameter of the same role.
         */
        void insert_column(std::int64_t column, const std::vector<Cell>& new_cells) const;
        /**
         * @brief Calls `-[NSMatrix insertRow:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         */
        void insert_row(std::int64_t row) const;
        /**
         * @brief Calls `-[NSMatrix insertRow:withCells:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param new_cells Argument converted to the Objective-C parameter of the same role.
         */
        void insert_row(std::int64_t row, const std::vector<Cell>& new_cells) const;
        /**
         * @brief Calls `-[NSMatrix makeCellAtRow:column:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param col Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Cell make_cell_at_row(std::int64_t row, std::int64_t col) const;
        /**
         * @brief Calls `-[NSMatrix mouseDown:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void mouse_down(const Event& event) const;
        /**
         * @brief Calls `-[NSMatrix performKeyEquivalent:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool perform_key_equivalent(const Event& event) const;
        /**
         * @brief Calls `-[NSMatrix putCell:atRow:column:]`.
         * @param new_cell Argument converted to the Objective-C parameter of the same role.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param col Argument converted to the Objective-C parameter of the same role.
         */
        void put_cell(const Cell& new_cell, std::int64_t row, std::int64_t col) const;
        /**
         * @brief Calls `-[NSMatrix removeColumn:]`.
         * @param col Argument converted to the Objective-C parameter of the same role.
         */
        void remove_column(std::int64_t col) const;
        /**
         * @brief Calls `-[NSMatrix removeRow:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         */
        void remove_row(std::int64_t row) const;
        /**
         * @brief Calls `-[NSMatrix renewRows:columns:]`.
         * @param new_rows Argument converted to the Objective-C parameter of the same role.
         * @param new_cols Argument converted to the Objective-C parameter of the same role.
         */
        void renew_rows(std::int64_t new_rows, std::int64_t new_cols) const;
        /**
         * @brief Calls `-[NSMatrix resetCursorRects]`.
         */
        void reset_cursor_rects() const;
        /**
         * @brief Calls `-[NSMatrix scrollCellToVisibleAtRow:column:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param col Argument converted to the Objective-C parameter of the same role.
         */
        void scroll_cell_to_visible_at_row(std::int64_t row, std::int64_t col) const;
        /**
         * @brief Calls `-[NSMatrix selectAll:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void select_all(const Object& sender) const;
        /**
         * @brief Calls `-[NSMatrix selectCellAtRow:column:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param col Argument converted to the Objective-C parameter of the same role.
         */
        void select_cell_at_row(std::int64_t row, std::int64_t col) const;
        /**
         * @brief Calls `-[NSMatrix selectCellWithTag:]`.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool select_cell_with_tag(std::int64_t tag) const;
        /**
         * @brief Calls `-[NSMatrix selectText:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void select_text(const Object& sender) const;
        /**
         * @brief Calls `-[NSMatrix selectTextAtRow:column:]`.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param col Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Cell select_text_at_row(std::int64_t row, std::int64_t col) const;
        /**
         * @brief Calls `-[NSMatrix sendAction]`.
         * @return The converted Objective-C result.
         */
        bool send_action() const;
        /**
         * @brief Calls `-[NSMatrix sendAction:to:forAllCells:]`.
         * @param selector Argument converted to the Objective-C parameter of the same role.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @param flag Argument converted to the Objective-C parameter of the same role.
         */
        void send_action(const std::string& selector, const Object& object, bool flag) const;
        /**
         * @brief Calls `-[NSMatrix sendDoubleAction]`.
         */
        void send_double_action() const;
        /**
         * @brief Calls `-[NSMatrix setScrollable:]`.
         * @param flag Argument converted to the Objective-C parameter of the same role.
         */
        void set_scrollable(bool flag) const;
        /**
         * @brief Calls `-[NSMatrix setSelectionFrom:to:anchor:highlight:]`.
         * @param start_pos Argument converted to the Objective-C parameter of the same role.
         * @param end_pos Argument converted to the Objective-C parameter of the same role.
         * @param anchor_pos Argument converted to the Objective-C parameter of the same role.
         * @param lit Argument converted to the Objective-C parameter of the same role.
         */
        void set_selection_from(std::int64_t start_pos, std::int64_t end_pos, std::int64_t anchor_pos, bool lit) const;
        /**
         * @brief Calls `-[NSMatrix setState:atRow:column:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param col Argument converted to the Objective-C parameter of the same role.
         */
        void set_state(std::int64_t value, std::int64_t row, std::int64_t col) const;
        /**
         * @brief Calls `-[NSMatrix setToolTip:forCell:]`.
         * @param tool_tip_string Argument converted to the Objective-C parameter of the same role.
         * @param cell Argument converted to the Objective-C parameter of the same role.
         */
        void set_tool_tip(const std::string& tool_tip_string, const Cell& cell) const;
        /**
         * @brief Calls `-[NSMatrix setValidateSize:]`.
         * @param flag Argument converted to the Objective-C parameter of the same role.
         */
        void set_validate_size(bool flag) const;
        /**
         * @brief Calls `-[NSMatrix sizeToCells]`.
         */
        void size_to_cells() const;
        /**
         * @brief Calls `-[NSMatrix sortUsingFunction:context:]`.
         * @param compare Argument converted to the Objective-C parameter of the same role.
         * @param context Argument converted to the Objective-C parameter of the same role.
         */
        void sort_using_function(std::int64_t (*compare)(void*, void*, void*), void* context) const;
        /**
         * @brief Calls `-[NSMatrix sortUsingSelector:]`.
         * @param comparator Argument converted to the Objective-C parameter of the same role.
         */
        void sort_using_selector(const std::string& comparator) const;
        /**
         * @brief Calls `-[NSMatrix textDidBeginEditing:]`.
         * @param notification Argument converted to the Objective-C parameter of the same role.
         */
        void text_did_begin_editing(const Notification& notification) const;
        /**
         * @brief Calls `-[NSMatrix textDidChange:]`.
         * @param notification Argument converted to the Objective-C parameter of the same role.
         */
        void text_did_change(const Notification& notification) const;
        /**
         * @brief Calls `-[NSMatrix textDidEndEditing:]`.
         * @param notification Argument converted to the Objective-C parameter of the same role.
         */
        void text_did_end_editing(const Notification& notification) const;
        /**
         * @brief Calls `-[NSMatrix textShouldBeginEditing:]`.
         * @param text_object Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool text_should_begin_editing(const Text& text_object) const;
        /**
         * @brief Calls `-[NSMatrix textShouldEndEditing:]`.
         * @param text_object Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool text_should_end_editing(const Text& text_object) const;
        /**
         * @brief Calls `-[NSMatrix toolTipForCell:]`.
         * @param cell Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string tool_tip_for_cell(const Cell& cell) const;
        /**
         * @brief Returns the `allowsEmptySelection` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        bool allows_empty_selection() const;
        /**
         * @brief Sets the `allowsEmptySelection` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_empty_selection(bool value) const;
        /**
         * @brief Returns the `autorecalculatesCellSize` property of `NSMatrix`.
         * @details Determine whether the receiver autorecalculates its cellSize. The default is NO. If set to YES, then the receiver will adjust its cellSize to accommodate its largest cell. Changing the cellSize does not directly affect the frame of the receiver; however it does affect the intrinsic content size, which may cause the receiver to resize under autolayout. The default is NO. When using autolayout, you typically want this to be set to YES.
         * @return The converted Objective-C result.
         */
        bool autorecalculates_cell_size() const;
        /**
         * @brief Sets the `autorecalculatesCellSize` property of `NSMatrix`.
         * @details Determine whether the receiver autorecalculates its cellSize. The default is NO. If set to YES, then the receiver will adjust its cellSize to accommodate its largest cell. Changing the cellSize does not directly affect the frame of the receiver; however it does affect the intrinsic content size, which may cause the receiver to resize under autolayout. The default is NO. When using autolayout, you typically want this to be set to YES.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_autorecalculates_cell_size(bool value) const;
        /**
         * @brief Returns the `autoscroll` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        bool is_autoscroll() const;
        /**
         * @brief Sets the `autoscroll` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_autoscroll(bool value) const;
        /**
         * @brief Returns the `autosizesCells` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        bool autosizes_cells() const;
        /**
         * @brief Sets the `autosizesCells` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_autosizes_cells(bool value) const;
        /**
         * @brief Returns the `backgroundColor` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        Color background_color() const;
        /**
         * @brief Sets the `backgroundColor` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_background_color(const Color& value) const;
        /**
         * @brief Returns the `cellBackgroundColor` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        Color cell_background_color() const;
        /**
         * @brief Sets the `cellBackgroundColor` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_cell_background_color(const Color& value) const;
        /**
         * @brief Returns the `cellClass` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        std::string cell_class() const;
        /**
         * @brief Sets the `cellClass` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_cell_class(const std::string& value) const;
        /**
         * @brief Returns the `cellSize` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        Size cell_size() const;
        /**
         * @brief Sets the `cellSize` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_cell_size(const Size& value) const;
        /**
         * @brief Returns the `cells` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        std::vector<Cell> cells() const;
        /**
         * @brief Returns the `doubleAction` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        std::string double_action() const;
        /**
         * @brief Sets the `doubleAction` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_double_action(const std::string& value) const;
        /**
         * @brief Returns the `drawsBackground` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        bool draws_background() const;
        /**
         * @brief Sets the `drawsBackground` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_draws_background(bool value) const;
        /**
         * @brief Returns the `drawsCellBackground` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        bool draws_cell_background() const;
        /**
         * @brief Sets the `drawsCellBackground` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_draws_cell_background(bool value) const;
        /**
         * @brief Returns the `intercellSpacing` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        Size intercell_spacing() const;
        /**
         * @brief Sets the `intercellSpacing` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_intercell_spacing(const Size& value) const;
        /**
         * @brief Returns the `keyCell` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        Cell key_cell() const;
        /**
         * @brief Sets the `keyCell` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_key_cell(const Cell& value) const;
        /**
         * @brief Returns the `mode` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        MatrixMode mode() const;
        /**
         * @brief Sets the `mode` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_mode(MatrixMode value) const;
        /**
         * @brief Returns the `mouseDownFlags` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        std::int64_t mouse_down_flags() const;
        /**
         * @brief Returns the `numberOfColumns` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_columns() const;
        /**
         * @brief Returns the `numberOfRows` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_rows() const;
        /**
         * @brief Returns the `prototype` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        Cell prototype() const;
        /**
         * @brief Sets the `prototype` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_prototype(const Cell& value) const;
        /**
         * @brief Returns the `selectedCell` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        Cell selected_cell() const;
        /**
         * @brief Returns the `selectedCells` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        std::vector<Cell> selected_cells() const;
        /**
         * @brief Returns the `selectedColumn` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        std::int64_t selected_column() const;
        /**
         * @brief Returns the `selectedRow` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        std::int64_t selected_row() const;
        /**
         * @brief Returns the `selectionByRect` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        bool is_selection_by_rect() const;
        /**
         * @brief Sets the `selectionByRect` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_selection_by_rect(bool value) const;
        /**
         * @brief Returns the `tabKeyTraversesCells` property of `NSMatrix`.
         * @return The converted Objective-C result.
         */
        bool tab_key_traverses_cells() const;
        /**
         * @brief Sets the `tabKeyTraversesCells` property of `NSMatrix`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tab_key_traverses_cells(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `control_text_did_begin_editing`; connect a callback with `control_text_did_begin_editing().connect(...)`.
        Signal<Matrix, void(Notification)> control_text_did_begin_editing() const
        {
            return Signal<Matrix, void(Notification)>(handle(), "control_text_did_begin_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `control_text_did_end_editing`; connect a callback with `control_text_did_end_editing().connect(...)`.
        Signal<Matrix, void(Notification)> control_text_did_end_editing() const
        {
            return Signal<Matrix, void(Notification)>(handle(), "control_text_did_end_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `control_text_did_change`; connect a callback with `control_text_did_change().connect(...)`.
        Signal<Matrix, void(Notification)> control_text_did_change() const
        {
            return Signal<Matrix, void(Notification)>(handle(), "control_text_did_change");
        }
        /// @brief Signal for the delegate/data-source method behind `control_text_should_begin_editing`; connect a callback with `control_text_should_begin_editing().connect(...)`.
        Signal<Matrix, bool(Text)> control_text_should_begin_editing() const
        {
            return Signal<Matrix, bool(Text)>(handle(), "control_text_should_begin_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `control_text_should_end_editing`; connect a callback with `control_text_should_end_editing().connect(...)`.
        Signal<Matrix, bool(Text)> control_text_should_end_editing() const
        {
            return Signal<Matrix, bool(Text)>(handle(), "control_text_should_end_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `did_fail_to_format_string_error_description`; connect a callback with `did_fail_to_format_string_error_description().connect(...)`.
        Signal<Matrix, bool(std::string, std::string)> did_fail_to_format_string_error_description() const
        {
            return Signal<Matrix, bool(std::string, std::string)>(handle(), "did_fail_to_format_string_error_description");
        }
        /// @brief Signal for the delegate/data-source method behind `did_fail_to_validate_partial_string_error_description`; connect a callback with `did_fail_to_validate_partial_string_error_description().connect(...)`.
        Signal<Matrix, void(std::string, std::string)> did_fail_to_validate_partial_string_error_description() const
        {
            return Signal<Matrix, void(std::string, std::string)>(handle(), "did_fail_to_validate_partial_string_error_description");
        }
        /// @brief Signal for the delegate/data-source method behind `is_valid_object`; connect a callback with `is_valid_object().connect(...)`.
        Signal<Matrix, bool(Object)> is_valid_object() const
        {
            return Signal<Matrix, bool(Object)>(handle(), "is_valid_object");
        }
        /// @brief Signal for the delegate/data-source method behind `text_view_do_command_by_selector`; connect a callback with `text_view_do_command_by_selector().connect(...)`.
        Signal<Matrix, bool(TextView, std::string)> text_view_do_command_by_selector() const
        {
            return Signal<Matrix, bool(TextView, std::string)>(handle(), "text_view_do_command_by_selector");
        }
        /// @brief Signal for the delegate/data-source method behind `text_view_completions_for_partial_word_range_index_of_selected_item`; connect a callback with `text_view_completions_for_partial_word_range_index_of_selected_item().connect(...)`.
        Signal<Matrix, std::vector<std::string>(TextView, std::vector<std::string>, Range, std::int64_t*)> text_view_completions_for_partial_word_range_index_of_selected_item() const
        {
            return Signal<Matrix, std::vector<std::string>(TextView, std::vector<std::string>, Range, std::int64_t*)>(handle(), "text_view_completions_for_partial_word_range_index_of_selected_item");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
