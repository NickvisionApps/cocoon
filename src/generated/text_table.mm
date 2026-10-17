#include "generated/text_table.h"
#include "internal.h"

namespace cocoon
{
    TextTable::TextTable() : TextTable(Adopt{cocoon::internal::retain([[::NSTextTable alloc] init])})
    {
    }

    TextTable::TextTable(std::nullptr_t) : TextBlock(nullptr)
    {
    }

    TextTable::TextTable(Adopt adopt) : TextBlock(adopt)
    {
    }

    Rect TextTable::bounds_rect_for_block(const TextTableBlock& block, const Rect& content_rect, const Rect& rect, const TextContainer& text_container, const Range& char_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextTable>(this) boundsRectForBlock:cocoon::internal::native<::NSTextTableBlock>(block) contentRect:cocoon::internal::to(content_rect) inRect:cocoon::internal::to(rect) textContainer:cocoon::internal::native<::NSTextContainer>(text_container) characterRange:cocoon::internal::to(char_range)]);
    }

    void TextTable::draw_background_for_block(const TextTableBlock& block, const Rect& frame_rect, const View& control_view, const Range& char_range, const LayoutManager& layout_manager) const
    {
        [cocoon::internal::ns<::NSTextTable>(this) drawBackgroundForBlock:cocoon::internal::native<::NSTextTableBlock>(block) withFrame:cocoon::internal::to(frame_rect) inView:cocoon::internal::native<::NSView>(control_view) characterRange:cocoon::internal::to(char_range) layoutManager:cocoon::internal::native<::NSLayoutManager>(layout_manager)];
    }

    Rect TextTable::rect_for_block(const TextTableBlock& block, const Point& starting_point, const Rect& rect, const TextContainer& text_container, const Range& char_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextTable>(this) rectForBlock:cocoon::internal::native<::NSTextTableBlock>(block) layoutAtPoint:cocoon::internal::to(starting_point) inRect:cocoon::internal::to(rect) textContainer:cocoon::internal::native<::NSTextContainer>(text_container) characterRange:cocoon::internal::to(char_range)]);
    }

    bool TextTable::collapses_borders() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextTable>(this) collapsesBorders]);
    }

    void TextTable::set_collapses_borders(bool value) const
    {
        [cocoon::internal::ns<::NSTextTable>(this) setCollapsesBorders:static_cast<::BOOL>(value)];
    }

    bool TextTable::hides_empty_cells() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextTable>(this) hidesEmptyCells]);
    }

    void TextTable::set_hides_empty_cells(bool value) const
    {
        [cocoon::internal::ns<::NSTextTable>(this) setHidesEmptyCells:static_cast<::BOOL>(value)];
    }

    TextTableLayoutAlgorithm TextTable::layout_algorithm() const
    {
        return static_cast<TextTableLayoutAlgorithm>([cocoon::internal::ns<::NSTextTable>(this) layoutAlgorithm]);
    }

    void TextTable::set_layout_algorithm(TextTableLayoutAlgorithm value) const
    {
        [cocoon::internal::ns<::NSTextTable>(this) setLayoutAlgorithm:static_cast<::NSTextTableLayoutAlgorithm>(value)];
    }

    std::int64_t TextTable::number_of_columns() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTextTable>(this) numberOfColumns]);
    }

    void TextTable::set_number_of_columns(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSTextTable>(this) setNumberOfColumns:static_cast<::NSInteger>(value)];
    }
}
