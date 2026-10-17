#include "generated/table_row_view.h"
#include "internal.h"

namespace cocoon
{
    TableRowView::TableRowView() : TableRowView(Adopt{cocoon::internal::retain([[::NSTableRowView alloc] init])})
    {
    }

    TableRowView::TableRowView(std::nullptr_t) : View(nullptr)
    {
    }

    TableRowView::TableRowView(Adopt adopt) : View(adopt)
    {
    }

    void TableRowView::draw_background_in_rect(const Rect& dirty_rect) const
    {
        [cocoon::internal::ns<::NSTableRowView>(this) drawBackgroundInRect:cocoon::internal::to(dirty_rect)];
    }

    void TableRowView::draw_dragging_destination_feedback_in_rect(const Rect& dirty_rect) const
    {
        [cocoon::internal::ns<::NSTableRowView>(this) drawDraggingDestinationFeedbackInRect:cocoon::internal::to(dirty_rect)];
    }

    void TableRowView::draw_selection_in_rect(const Rect& dirty_rect) const
    {
        [cocoon::internal::ns<::NSTableRowView>(this) drawSelectionInRect:cocoon::internal::to(dirty_rect)];
    }

    void TableRowView::draw_separator_in_rect(const Rect& dirty_rect) const
    {
        [cocoon::internal::ns<::NSTableRowView>(this) drawSeparatorInRect:cocoon::internal::to(dirty_rect)];
    }

    Object TableRowView::view_at_column(std::int64_t column) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTableRowView>(this) viewAtColumn:static_cast<::NSInteger>(column)]);
    }

    Color TableRowView::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTableRowView>(this) backgroundColor]);
    }

    void TableRowView::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSTableRowView>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    TableViewDraggingDestinationFeedbackStyle TableRowView::dragging_destination_feedback_style() const
    {
        return static_cast<TableViewDraggingDestinationFeedbackStyle>([cocoon::internal::ns<::NSTableRowView>(this) draggingDestinationFeedbackStyle]);
    }

    void TableRowView::set_dragging_destination_feedback_style(TableViewDraggingDestinationFeedbackStyle value) const
    {
        [cocoon::internal::ns<::NSTableRowView>(this) setDraggingDestinationFeedbackStyle:static_cast<::NSTableViewDraggingDestinationFeedbackStyle>(value)];
    }

    bool TableRowView::is_emphasized() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableRowView>(this) isEmphasized]);
    }

    void TableRowView::set_emphasized(bool value) const
    {
        [cocoon::internal::ns<::NSTableRowView>(this) setEmphasized:static_cast<::BOOL>(value)];
    }

    bool TableRowView::is_floating() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableRowView>(this) isFloating]);
    }

    void TableRowView::set_floating(bool value) const
    {
        [cocoon::internal::ns<::NSTableRowView>(this) setFloating:static_cast<::BOOL>(value)];
    }

    bool TableRowView::is_group_row_style() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableRowView>(this) isGroupRowStyle]);
    }

    void TableRowView::set_group_row_style(bool value) const
    {
        [cocoon::internal::ns<::NSTableRowView>(this) setGroupRowStyle:static_cast<::BOOL>(value)];
    }

    double TableRowView::indentation_for_drop_operation() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTableRowView>(this) indentationForDropOperation]);
    }

    void TableRowView::set_indentation_for_drop_operation(double value) const
    {
        [cocoon::internal::ns<::NSTableRowView>(this) setIndentationForDropOperation:static_cast<::CGFloat>(value)];
    }

    BackgroundStyle TableRowView::interior_background_style() const
    {
        return static_cast<BackgroundStyle>([cocoon::internal::ns<::NSTableRowView>(this) interiorBackgroundStyle]);
    }

    bool TableRowView::is_next_row_selected() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableRowView>(this) isNextRowSelected]);
    }

    void TableRowView::set_next_row_selected(bool value) const
    {
        [cocoon::internal::ns<::NSTableRowView>(this) setNextRowSelected:static_cast<::BOOL>(value)];
    }

    std::int64_t TableRowView::number_of_columns() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTableRowView>(this) numberOfColumns]);
    }

    bool TableRowView::is_previous_row_selected() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableRowView>(this) isPreviousRowSelected]);
    }

    void TableRowView::set_previous_row_selected(bool value) const
    {
        [cocoon::internal::ns<::NSTableRowView>(this) setPreviousRowSelected:static_cast<::BOOL>(value)];
    }

    bool TableRowView::is_selected() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableRowView>(this) isSelected]);
    }

    void TableRowView::set_selected(bool value) const
    {
        [cocoon::internal::ns<::NSTableRowView>(this) setSelected:static_cast<::BOOL>(value)];
    }

    TableViewSelectionHighlightStyle TableRowView::selection_highlight_style() const
    {
        return static_cast<TableViewSelectionHighlightStyle>([cocoon::internal::ns<::NSTableRowView>(this) selectionHighlightStyle]);
    }

    void TableRowView::set_selection_highlight_style(TableViewSelectionHighlightStyle value) const
    {
        [cocoon::internal::ns<::NSTableRowView>(this) setSelectionHighlightStyle:static_cast<::NSTableViewSelectionHighlightStyle>(value)];
    }

    bool TableRowView::is_target_for_drop_operation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTableRowView>(this) isTargetForDropOperation]);
    }

    void TableRowView::set_target_for_drop_operation(bool value) const
    {
        [cocoon::internal::ns<::NSTableRowView>(this) setTargetForDropOperation:static_cast<::BOOL>(value)];
    }
}
