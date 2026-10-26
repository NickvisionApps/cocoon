#include "generated/text_block.h"
#include "internal.h"

namespace cocoon
{
    TextBlock::TextBlock() : TextBlock(Adopt{cocoon::internal::retain([[::NSTextBlock alloc] init])})
    {
    }

    TextBlock::TextBlock(std::nullptr_t) : Object(nullptr)
    {
    }

    TextBlock::TextBlock(Adopt adopt) : Object(adopt)
    {
    }

    Color TextBlock::border_color_for_edge(RectEdge edge) const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTextBlock>(this) borderColorForEdge:static_cast<::NSRectEdge>(edge)]);
    }

    Rect TextBlock::bounds_rect_for_content_rect(const Rect& content_rect, const Rect& rect, const TextContainer& text_container, const Range& char_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextBlock>(this) boundsRectForContentRect:cocoon::internal::to(content_rect) inRect:cocoon::internal::to(rect) textContainer:cocoon::internal::native<::NSTextContainer>(text_container) characterRange:cocoon::internal::to(char_range)]);
    }

    void TextBlock::draw_background_with_frame(const Rect& frame_rect, const View& control_view, const Range& char_range, const LayoutManager& layout_manager) const
    {
        [cocoon::internal::ns<::NSTextBlock>(this) drawBackgroundWithFrame:cocoon::internal::to(frame_rect) inView:cocoon::internal::native<::NSView>(control_view) characterRange:cocoon::internal::to(char_range) layoutManager:cocoon::internal::native<::NSLayoutManager>(layout_manager)];
    }

    Rect TextBlock::rect_for_layout_at_point(const Point& starting_point, const Rect& rect, const TextContainer& text_container, const Range& char_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextBlock>(this) rectForLayoutAtPoint:cocoon::internal::to(starting_point) inRect:cocoon::internal::to(rect) textContainer:cocoon::internal::native<::NSTextContainer>(text_container) characterRange:cocoon::internal::to(char_range)]);
    }

    void TextBlock::set_border_color(const Color& color) const
    {
        [cocoon::internal::ns<::NSTextBlock>(this) setBorderColor:cocoon::internal::native<::NSColor>(color)];
    }

    void TextBlock::set_border_color(const Color& color, RectEdge edge) const
    {
        [cocoon::internal::ns<::NSTextBlock>(this) setBorderColor:cocoon::internal::native<::NSColor>(color) forEdge:static_cast<::NSRectEdge>(edge)];
    }

    void TextBlock::set_content_width(double val, TextBlockValueType type) const
    {
        [cocoon::internal::ns<::NSTextBlock>(this) setContentWidth:static_cast<::CGFloat>(val) type:static_cast<::NSTextBlockValueType>(type)];
    }

    void TextBlock::set_value(double val, TextBlockValueType type, TextBlockDimension dimension) const
    {
        [cocoon::internal::ns<::NSTextBlock>(this) setValue:static_cast<::CGFloat>(val) type:static_cast<::NSTextBlockValueType>(type) forDimension:static_cast<::NSTextBlockDimension>(dimension)];
    }

    void TextBlock::set_width(double val, TextBlockValueType type, TextBlockLayer layer) const
    {
        [cocoon::internal::ns<::NSTextBlock>(this) setWidth:static_cast<::CGFloat>(val) type:static_cast<::NSTextBlockValueType>(type) forLayer:static_cast<::NSTextBlockLayer>(layer)];
    }

    void TextBlock::set_width(double val, TextBlockValueType type, TextBlockLayer layer, RectEdge edge) const
    {
        [cocoon::internal::ns<::NSTextBlock>(this) setWidth:static_cast<::CGFloat>(val) type:static_cast<::NSTextBlockValueType>(type) forLayer:static_cast<::NSTextBlockLayer>(layer) edge:static_cast<::NSRectEdge>(edge)];
    }

    double TextBlock::value_for_dimension(TextBlockDimension dimension) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextBlock>(this) valueForDimension:static_cast<::NSTextBlockDimension>(dimension)]);
    }

    TextBlockValueType TextBlock::value_type_for_dimension(TextBlockDimension dimension) const
    {
        return static_cast<TextBlockValueType>([cocoon::internal::ns<::NSTextBlock>(this) valueTypeForDimension:static_cast<::NSTextBlockDimension>(dimension)]);
    }

    double TextBlock::width_for_layer(TextBlockLayer layer, RectEdge edge) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextBlock>(this) widthForLayer:static_cast<::NSTextBlockLayer>(layer) edge:static_cast<::NSRectEdge>(edge)]);
    }

    TextBlockValueType TextBlock::width_value_type_for_layer(TextBlockLayer layer, RectEdge edge) const
    {
        return static_cast<TextBlockValueType>([cocoon::internal::ns<::NSTextBlock>(this) widthValueTypeForLayer:static_cast<::NSTextBlockLayer>(layer) edge:static_cast<::NSRectEdge>(edge)]);
    }

    Color TextBlock::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTextBlock>(this) backgroundColor]);
    }

    void TextBlock::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSTextBlock>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    double TextBlock::content_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextBlock>(this) contentWidth]);
    }

    TextBlockValueType TextBlock::content_width_value_type() const
    {
        return static_cast<TextBlockValueType>([cocoon::internal::ns<::NSTextBlock>(this) contentWidthValueType]);
    }

    TextBlockVerticalAlignment TextBlock::vertical_alignment() const
    {
        return static_cast<TextBlockVerticalAlignment>([cocoon::internal::ns<::NSTextBlock>(this) verticalAlignment]);
    }

    void TextBlock::set_vertical_alignment(TextBlockVerticalAlignment value) const
    {
        [cocoon::internal::ns<::NSTextBlock>(this) setVerticalAlignment:static_cast<::NSTextBlockVerticalAlignment>(value)];
    }
}
