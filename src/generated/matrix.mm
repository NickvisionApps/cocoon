#include "generated/matrix.h"
#include "internal.h"

@interface AKMatrixDelegate : NSObject <NSMatrixDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKMatrixDelegate

- (void)controlTextDidBeginEditing:(NSNotification*)obj
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Matrix, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "control_text_did_begin_editing", cocoon::internal::wrap<cocoon::Notification>(obj));
}

- (void)controlTextDidEndEditing:(NSNotification*)obj
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Matrix, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "control_text_did_end_editing", cocoon::internal::wrap<cocoon::Notification>(obj));
}

- (void)controlTextDidChange:(NSNotification*)obj
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Matrix, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "control_text_did_change", cocoon::internal::wrap<cocoon::Notification>(obj));
}

- (BOOL)control:(NSControl*)control textShouldBeginEditing:(NSText*)fieldEditor
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Matrix, bool(cocoon::Text)>::emit((__bridge void*)strongHost, "control_text_should_begin_editing", cocoon::internal::wrap<cocoon::Text>(fieldEditor));
    return static_cast<::BOOL>(__r);
}

- (BOOL)control:(NSControl*)control textShouldEndEditing:(NSText*)fieldEditor
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Matrix, bool(cocoon::Text)>::emit((__bridge void*)strongHost, "control_text_should_end_editing", cocoon::internal::wrap<cocoon::Text>(fieldEditor));
    return static_cast<::BOOL>(__r);
}

- (BOOL)control:(NSControl*)control didFailToFormatString:(NSString*)string errorDescription:(NSString*)error
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Matrix, bool(std::string, std::string)>::emit((__bridge void*)strongHost, "did_fail_to_format_string_error_description", cocoon::internal::from(string), cocoon::internal::from(error));
    return static_cast<::BOOL>(__r);
}

- (void)control:(NSControl*)control didFailToValidatePartialString:(NSString*)string errorDescription:(NSString*)error
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Matrix, void(std::string, std::string)>::emit((__bridge void*)strongHost, "did_fail_to_validate_partial_string_error_description", cocoon::internal::from(string), cocoon::internal::from(error));
}

- (BOOL)control:(NSControl*)control isValidObject:(id)obj
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Matrix, bool(cocoon::Object)>::emit((__bridge void*)strongHost, "is_valid_object", cocoon::internal::wrap<cocoon::Object>(obj));
    return static_cast<::BOOL>(__r);
}

- (BOOL)control:(NSControl*)control textView:(NSTextView*)textView doCommandBySelector:(SEL)commandSelector
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Matrix, bool(cocoon::TextView, std::string)>::emit((__bridge void*)strongHost, "text_view_do_command_by_selector", cocoon::internal::wrap<cocoon::TextView>(textView), cocoon::internal::from(NSStringFromSelector(commandSelector)));
    return static_cast<::BOOL>(__r);
}

- (NSArray<NSString*>*)control:(NSControl*)control textView:(NSTextView*)textView completions:(NSArray<NSString*>*)words forPartialWordRange:(NSRange)charRange indexOfSelectedItem:(NSInteger*)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Matrix, std::vector<std::string>(cocoon::TextView, std::vector<std::string>, cocoon::Range, std::int64_t*)>::emit((__bridge void*)strongHost, "text_view_completions_for_partial_word_range_index_of_selected_item", cocoon::internal::wrap<cocoon::TextView>(textView), cocoon::internal::from_array<std::string>(words, [](id e) -> std::string
                                                                                                                                                                                                                                                                                                                                                         {
                                                                                                                                                                                                                                                                                                                                                             return cocoon::internal::from((NSString*)e);
                                                                                                                                                                                                                                                                                                                                                         }),
                                                                                                                                                        cocoon::internal::from(charRange), (std::int64_t*)(index));
    return cocoon::internal::to_array(__r, [](const std::string& e) -> id
                                      {
                                          return cocoon::internal::to(e);
                                      });
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(controlTextDidBeginEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::Matrix, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "control_text_did_begin_editing");
    }
    if (selector == @selector(controlTextDidEndEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::Matrix, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "control_text_did_end_editing");
    }
    if (selector == @selector(controlTextDidChange:))
    {
        return strongHost && cocoon::Signal<cocoon::Matrix, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "control_text_did_change");
    }
    if (selector == @selector(control:textShouldBeginEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::Matrix, bool(cocoon::Text)>::connected((__bridge void*)strongHost, "control_text_should_begin_editing");
    }
    if (selector == @selector(control:textShouldEndEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::Matrix, bool(cocoon::Text)>::connected((__bridge void*)strongHost, "control_text_should_end_editing");
    }
    if (selector == @selector(control:didFailToFormatString:errorDescription:))
    {
        return strongHost && cocoon::Signal<cocoon::Matrix, bool(std::string, std::string)>::connected((__bridge void*)strongHost, "did_fail_to_format_string_error_description");
    }
    if (selector == @selector(control:didFailToValidatePartialString:errorDescription:))
    {
        return strongHost && cocoon::Signal<cocoon::Matrix, void(std::string, std::string)>::connected((__bridge void*)strongHost, "did_fail_to_validate_partial_string_error_description");
    }
    if (selector == @selector(control:isValidObject:))
    {
        return strongHost && cocoon::Signal<cocoon::Matrix, bool(cocoon::Object)>::connected((__bridge void*)strongHost, "is_valid_object");
    }
    if (selector == @selector(control:textView:doCommandBySelector:))
    {
        return strongHost && cocoon::Signal<cocoon::Matrix, bool(cocoon::TextView, std::string)>::connected((__bridge void*)strongHost, "text_view_do_command_by_selector");
    }
    if (selector == @selector(control:textView:completions:forPartialWordRange:indexOfSelectedItem:))
    {
        return strongHost && cocoon::Signal<cocoon::Matrix, std::vector<std::string>(cocoon::TextView, std::vector<std::string>, cocoon::Range, std::int64_t*)>::connected((__bridge void*)strongHost, "text_view_completions_for_partial_word_range_index_of_selected_item");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    Matrix::Matrix(const Rect& frame_rect) : Matrix(Adopt{cocoon::internal::retain([[::NSMatrix alloc] initWithFrame:cocoon::internal::to(frame_rect)])})
    {
        Matrix::install_delegate_delegate_(handle());
    }

    Matrix::Matrix(const Rect& frame_rect, MatrixMode mode, const std::string& factory_id, std::int64_t rows_high, std::int64_t cols_wide) : Matrix(Adopt{cocoon::internal::retain([[::NSMatrix alloc] initWithFrame:cocoon::internal::to(frame_rect) mode:static_cast<::NSMatrixMode>(mode) cellClass:NSClassFromString(cocoon::internal::to(factory_id)) numberOfRows:static_cast<::NSInteger>(rows_high) numberOfColumns:static_cast<::NSInteger>(cols_wide)])})
    {
        Matrix::install_delegate_delegate_(handle());
    }

    Matrix::Matrix(const Rect& frame_rect, MatrixMode mode, const Cell& cell, std::int64_t rows_high, std::int64_t cols_wide) : Matrix(Adopt{cocoon::internal::retain([[::NSMatrix alloc] initWithFrame:cocoon::internal::to(frame_rect) mode:static_cast<::NSMatrixMode>(mode) prototype:cocoon::internal::native<::NSCell>(cell) numberOfRows:static_cast<::NSInteger>(rows_high) numberOfColumns:static_cast<::NSInteger>(cols_wide)])})
    {
        Matrix::install_delegate_delegate_(handle());
    }

    Matrix::Matrix() : Matrix(Adopt{cocoon::internal::retain([[::NSMatrix alloc] init])})
    {
        Matrix::install_delegate_delegate_(handle());
    }

    Matrix::Matrix(std::nullptr_t) : Control(nullptr)
    {
    }

    Matrix::Matrix(Adopt adopt) : Control(adopt)
    {
    }

    bool Matrix::accepts_first_mouse(const Event& event) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) acceptsFirstMouse:cocoon::internal::native<::NSEvent>(event)]);
    }

    void Matrix::add_column() const
    {
        [cocoon::internal::ns<::NSMatrix>(this) addColumn];
    }

    void Matrix::add_column_with_cells(const std::vector<Cell>& new_cells) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) addColumnWithCells:cocoon::internal::to_array(new_cells, [](const Cell& e) -> id
                                                                                              {
                                                                                                  return cocoon::internal::native<::NSCell>(e);
                                                                                              })];
    }

    void Matrix::add_row() const
    {
        [cocoon::internal::ns<::NSMatrix>(this) addRow];
    }

    void Matrix::add_row_with_cells(const std::vector<Cell>& new_cells) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) addRowWithCells:cocoon::internal::to_array(new_cells, [](const Cell& e) -> id
                                                                                           {
                                                                                               return cocoon::internal::native<::NSCell>(e);
                                                                                           })];
    }

    Cell Matrix::cell_at_row(std::int64_t row, std::int64_t col) const
    {
        return cocoon::internal::wrap<Cell>([cocoon::internal::ns<::NSMatrix>(this) cellAtRow:static_cast<::NSInteger>(row) column:static_cast<::NSInteger>(col)]);
    }

    Rect Matrix::cell_frame_at_row(std::int64_t row, std::int64_t col) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMatrix>(this) cellFrameAtRow:static_cast<::NSInteger>(row) column:static_cast<::NSInteger>(col)]);
    }

    Cell Matrix::cell_with_tag(std::int64_t tag) const
    {
        return cocoon::internal::wrap<Cell>([cocoon::internal::ns<::NSMatrix>(this) cellWithTag:static_cast<::NSInteger>(tag)]);
    }

    void Matrix::deselect_all_cells() const
    {
        [cocoon::internal::ns<::NSMatrix>(this) deselectAllCells];
    }

    void Matrix::deselect_selected_cell() const
    {
        [cocoon::internal::ns<::NSMatrix>(this) deselectSelectedCell];
    }

    void Matrix::draw_cell_at_row(std::int64_t row, std::int64_t col) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) drawCellAtRow:static_cast<::NSInteger>(row) column:static_cast<::NSInteger>(col)];
    }

    void Matrix::get_number_of_rows(std::int64_t* row_count, std::int64_t* col_count) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) getNumberOfRows:(::NSInteger*)(row_count) columns:(::NSInteger*)(col_count)];
    }

    bool Matrix::get_row(std::int64_t* row, std::int64_t* col, const Point& point) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) getRow:(::NSInteger*)(row) column:(::NSInteger*)(col)forPoint:cocoon::internal::to(point)]);
    }

    bool Matrix::get_row(std::int64_t* row, std::int64_t* col, const Cell& cell) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) getRow:(::NSInteger*)(row) column:(::NSInteger*)(col)ofCell:cocoon::internal::native<::NSCell>(cell)]);
    }

    void Matrix::highlight_cell(bool flag, std::int64_t row, std::int64_t col) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) highlightCell:static_cast<::BOOL>(flag) atRow:static_cast<::NSInteger>(row) column:static_cast<::NSInteger>(col)];
    }

    void Matrix::insert_column(std::int64_t column) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) insertColumn:static_cast<::NSInteger>(column)];
    }

    void Matrix::insert_column(std::int64_t column, const std::vector<Cell>& new_cells) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) insertColumn:static_cast<::NSInteger>(column)
                                                   withCells:cocoon::internal::to_array(new_cells, [](const Cell& e) -> id
                                                                                        {
                                                                                            return cocoon::internal::native<::NSCell>(e);
                                                                                        })];
    }

    void Matrix::insert_row(std::int64_t row) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) insertRow:static_cast<::NSInteger>(row)];
    }

    void Matrix::insert_row(std::int64_t row, const std::vector<Cell>& new_cells) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) insertRow:static_cast<::NSInteger>(row)
                                                withCells:cocoon::internal::to_array(new_cells, [](const Cell& e) -> id
                                                                                     {
                                                                                         return cocoon::internal::native<::NSCell>(e);
                                                                                     })];
    }

    Cell Matrix::make_cell_at_row(std::int64_t row, std::int64_t col) const
    {
        return cocoon::internal::wrap<Cell>([cocoon::internal::ns<::NSMatrix>(this) makeCellAtRow:static_cast<::NSInteger>(row) column:static_cast<::NSInteger>(col)]);
    }

    void Matrix::mouse_down(const Event& event) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) mouseDown:cocoon::internal::native<::NSEvent>(event)];
    }

    bool Matrix::perform_key_equivalent(const Event& event) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) performKeyEquivalent:cocoon::internal::native<::NSEvent>(event)]);
    }

    void Matrix::put_cell(const Cell& new_cell, std::int64_t row, std::int64_t col) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) putCell:cocoon::internal::native<::NSCell>(new_cell) atRow:static_cast<::NSInteger>(row) column:static_cast<::NSInteger>(col)];
    }

    void Matrix::remove_column(std::int64_t col) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) removeColumn:static_cast<::NSInteger>(col)];
    }

    void Matrix::remove_row(std::int64_t row) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) removeRow:static_cast<::NSInteger>(row)];
    }

    void Matrix::renew_rows(std::int64_t new_rows, std::int64_t new_cols) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) renewRows:static_cast<::NSInteger>(new_rows) columns:static_cast<::NSInteger>(new_cols)];
    }

    void Matrix::reset_cursor_rects() const
    {
        [cocoon::internal::ns<::NSMatrix>(this) resetCursorRects];
    }

    void Matrix::scroll_cell_to_visible_at_row(std::int64_t row, std::int64_t col) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) scrollCellToVisibleAtRow:static_cast<::NSInteger>(row) column:static_cast<::NSInteger>(col)];
    }

    void Matrix::select_all(const Object& sender) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) selectAll:cocoon::internal::native_id(sender)];
    }

    void Matrix::select_cell_at_row(std::int64_t row, std::int64_t col) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) selectCellAtRow:static_cast<::NSInteger>(row) column:static_cast<::NSInteger>(col)];
    }

    bool Matrix::select_cell_with_tag(std::int64_t tag) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) selectCellWithTag:static_cast<::NSInteger>(tag)]);
    }

    void Matrix::select_text(const Object& sender) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) selectText:cocoon::internal::native_id(sender)];
    }

    Cell Matrix::select_text_at_row(std::int64_t row, std::int64_t col) const
    {
        return cocoon::internal::wrap<Cell>([cocoon::internal::ns<::NSMatrix>(this) selectTextAtRow:static_cast<::NSInteger>(row) column:static_cast<::NSInteger>(col)]);
    }

    bool Matrix::send_action() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) sendAction]);
    }

    void Matrix::send_action(const std::string& selector, const Object& object, bool flag) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) sendAction:NSSelectorFromString(cocoon::internal::to(selector)) to:cocoon::internal::native_id(object) forAllCells:static_cast<::BOOL>(flag)];
    }

    void Matrix::send_double_action() const
    {
        [cocoon::internal::ns<::NSMatrix>(this) sendDoubleAction];
    }

    void Matrix::set_scrollable(bool flag) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setScrollable:static_cast<::BOOL>(flag)];
    }

    void Matrix::set_selection_from(std::int64_t start_pos, std::int64_t end_pos, std::int64_t anchor_pos, bool lit) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setSelectionFrom:static_cast<::NSInteger>(start_pos) to:static_cast<::NSInteger>(end_pos) anchor:static_cast<::NSInteger>(anchor_pos) highlight:static_cast<::BOOL>(lit)];
    }

    void Matrix::set_state(std::int64_t value, std::int64_t row, std::int64_t col) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setState:static_cast<::NSInteger>(value) atRow:static_cast<::NSInteger>(row) column:static_cast<::NSInteger>(col)];
    }

    void Matrix::set_tool_tip(const std::string& tool_tip_string, const Cell& cell) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setToolTip:cocoon::internal::to(tool_tip_string) forCell:cocoon::internal::native<::NSCell>(cell)];
    }

    void Matrix::set_validate_size(bool flag) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setValidateSize:static_cast<::BOOL>(flag)];
    }

    void Matrix::size_to_cells() const
    {
        [cocoon::internal::ns<::NSMatrix>(this) sizeToCells];
    }

    void Matrix::sort_using_function(std::int64_t (*compare)(void*, void*, void*), void* context) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) sortUsingFunction:(::NSInteger (*)(id, id, void*))(compare) context:context];
    }

    void Matrix::sort_using_selector(const std::string& comparator) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) sortUsingSelector:NSSelectorFromString(cocoon::internal::to(comparator))];
    }

    void Matrix::text_did_begin_editing(const Notification& notification) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) textDidBeginEditing:cocoon::internal::native<::NSNotification>(notification)];
    }

    void Matrix::text_did_change(const Notification& notification) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) textDidChange:cocoon::internal::native<::NSNotification>(notification)];
    }

    void Matrix::text_did_end_editing(const Notification& notification) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) textDidEndEditing:cocoon::internal::native<::NSNotification>(notification)];
    }

    bool Matrix::text_should_begin_editing(const Text& text_object) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) textShouldBeginEditing:cocoon::internal::native<::NSText>(text_object)]);
    }

    bool Matrix::text_should_end_editing(const Text& text_object) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) textShouldEndEditing:cocoon::internal::native<::NSText>(text_object)]);
    }

    std::string Matrix::tool_tip_for_cell(const Cell& cell) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMatrix>(this) toolTipForCell:cocoon::internal::native<::NSCell>(cell)]);
    }

    bool Matrix::allows_empty_selection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) allowsEmptySelection]);
    }

    void Matrix::set_allows_empty_selection(bool value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setAllowsEmptySelection:static_cast<::BOOL>(value)];
    }

    bool Matrix::autorecalculates_cell_size() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) autorecalculatesCellSize]);
    }

    void Matrix::set_autorecalculates_cell_size(bool value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setAutorecalculatesCellSize:static_cast<::BOOL>(value)];
    }

    bool Matrix::is_autoscroll() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) isAutoscroll]);
    }

    void Matrix::set_autoscroll(bool value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setAutoscroll:static_cast<::BOOL>(value)];
    }

    bool Matrix::autosizes_cells() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) autosizesCells]);
    }

    void Matrix::set_autosizes_cells(bool value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setAutosizesCells:static_cast<::BOOL>(value)];
    }

    Color Matrix::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSMatrix>(this) backgroundColor]);
    }

    void Matrix::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    Color Matrix::cell_background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSMatrix>(this) cellBackgroundColor]);
    }

    void Matrix::set_cell_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setCellBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    std::string Matrix::cell_class() const
    {
        return cocoon::internal::from(NSStringFromClass([cocoon::internal::ns<::NSMatrix>(this) cellClass]));
    }

    void Matrix::set_cell_class(const std::string& value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setCellClass:NSClassFromString(cocoon::internal::to(value))];
    }

    Size Matrix::cell_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMatrix>(this) cellSize]);
    }

    void Matrix::set_cell_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setCellSize:cocoon::internal::to(value)];
    }

    std::vector<Cell> Matrix::cells() const
    {
        return cocoon::internal::from_array<Cell>([cocoon::internal::ns<::NSMatrix>(this) cells], [](id e) -> Cell
                                                  {
                                                      return cocoon::internal::wrap<Cell>((::NSCell*)e);
                                                  });
    }

    std::string Matrix::double_action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSMatrix>(this) doubleAction]));
    }

    void Matrix::set_double_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setDoubleAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    bool Matrix::draws_background() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) drawsBackground]);
    }

    void Matrix::set_draws_background(bool value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setDrawsBackground:static_cast<::BOOL>(value)];
    }

    bool Matrix::draws_cell_background() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) drawsCellBackground]);
    }

    void Matrix::set_draws_cell_background(bool value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setDrawsCellBackground:static_cast<::BOOL>(value)];
    }

    Size Matrix::intercell_spacing() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMatrix>(this) intercellSpacing]);
    }

    void Matrix::set_intercell_spacing(const Size& value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setIntercellSpacing:cocoon::internal::to(value)];
    }

    Cell Matrix::key_cell() const
    {
        return cocoon::internal::wrap<Cell>([cocoon::internal::ns<::NSMatrix>(this) keyCell]);
    }

    void Matrix::set_key_cell(const Cell& value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setKeyCell:cocoon::internal::native<::NSCell>(value)];
    }

    MatrixMode Matrix::mode() const
    {
        return static_cast<MatrixMode>([cocoon::internal::ns<::NSMatrix>(this) mode]);
    }

    void Matrix::set_mode(MatrixMode value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setMode:static_cast<::NSMatrixMode>(value)];
    }

    std::int64_t Matrix::mouse_down_flags() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMatrix>(this) mouseDownFlags]);
    }

    std::int64_t Matrix::number_of_columns() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMatrix>(this) numberOfColumns]);
    }

    std::int64_t Matrix::number_of_rows() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMatrix>(this) numberOfRows]);
    }

    Cell Matrix::prototype() const
    {
        return cocoon::internal::wrap<Cell>([cocoon::internal::ns<::NSMatrix>(this) prototype]);
    }

    void Matrix::set_prototype(const Cell& value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setPrototype:cocoon::internal::native<::NSCell>(value)];
    }

    Cell Matrix::selected_cell() const
    {
        return cocoon::internal::wrap<Cell>([cocoon::internal::ns<::NSMatrix>(this) selectedCell]);
    }

    std::vector<Cell> Matrix::selected_cells() const
    {
        return cocoon::internal::from_array<Cell>([cocoon::internal::ns<::NSMatrix>(this) selectedCells], [](id e) -> Cell
                                                  {
                                                      return cocoon::internal::wrap<Cell>((::NSCell*)e);
                                                  });
    }

    std::int64_t Matrix::selected_column() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMatrix>(this) selectedColumn]);
    }

    std::int64_t Matrix::selected_row() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMatrix>(this) selectedRow]);
    }

    bool Matrix::is_selection_by_rect() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) isSelectionByRect]);
    }

    void Matrix::set_selection_by_rect(bool value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setSelectionByRect:static_cast<::BOOL>(value)];
    }

    bool Matrix::tab_key_traverses_cells() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMatrix>(this) tabKeyTraversesCells]);
    }

    void Matrix::set_tab_key_traverses_cells(bool value) const
    {
        [cocoon::internal::ns<::NSMatrix>(this) setTabKeyTraversesCells:static_cast<::BOOL>(value)];
    }

    void Matrix::install_delegate_delegate_(void* native)
    {
        ::NSMatrix* host = (__bridge ::NSMatrix*)native;
        AKMatrixDelegate* delegate = [[AKMatrixDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSMatrix* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSMatrix* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
