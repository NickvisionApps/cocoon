#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class LayoutManager;
    class TextContainer;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSTextBlock` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextBlock text_block;
     * text_block.set_background_color(cocoon::Color());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextBlock text_block{};
     * text_block.set_background_color(cocoon::Color());
     * auto background_color = text_block.background_color();
     * text_block.set_vertical_alignment(cocoon::TextBlockVerticalAlignment::Top);
     * auto vertical_alignment = text_block.vertical_alignment();
     * text_block.border_color_for_edge(cocoon::RectEdge::MinX);
     * text_block.border_color_for_rect_edge(cocoon::CGRectEdge::MinXEdge);
     * text_block.set_border_color(cocoon::Color());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextblock
     */
    class TextBlock : public Object
    {
    public:
        /// @brief Creates a new `NSTextBlock` instance and returns a handle to it.
        explicit TextBlock();
        /// @brief Creates a null handle that refers to no native object.
        TextBlock(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextBlock(Adopt adopt);
        /**
         * @brief Calls `-[NSTextBlock borderColorForEdge:]`.
         * @param edge Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Color border_color_for_edge(RectEdge edge) const;
#ifdef COCOON_MACOS_27
        /**
         * @brief Calls `-[NSTextBlock borderColorForRectEdge:]`.
         * @param rect_edge Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Color border_color_for_rect_edge(CGRectEdge rect_edge) const;
#endif

        /**
         * @brief Calls `-[NSTextBlock boundsRectForContentRect:inRect:textContainer:characterRange:]`.
         * @param content_rect Argument converted to the Objective-C parameter of the same role.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @param text_container Argument converted to the Objective-C parameter of the same role.
         * @param char_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect bounds_rect_for_content_rect(const Rect& content_rect, const Rect& rect, const TextContainer& text_container, const Range& char_range) const;
        /**
         * @brief Calls `-[NSTextBlock drawBackgroundWithFrame:inView:characterRange:layoutManager:]`.
         * @details This method will be called during drawing to draw any colors and other decorations before the text is drawn.
         * @param frame_rect Argument converted to the Objective-C parameter of the same role.
         * @param control_view Argument converted to the Objective-C parameter of the same role.
         * @param char_range Argument converted to the Objective-C parameter of the same role.
         * @param layout_manager Argument converted to the Objective-C parameter of the same role.
         */
        void draw_background_with_frame(const Rect& frame_rect, const View& control_view, const Range& char_range, const LayoutManager& layout_manager) const;
        /**
         * @brief Calls `-[NSTextBlock rectForLayoutAtPoint:inRect:textContainer:characterRange:]`.
         * @details These methods will be called during layout to determine the size and position of the block. The first will be called before the block is laid out to determine the rect within which glyphs should be laid. The second will be called after the block is laid out to determine the rect the block occupies with borders and margins.
         * @param starting_point Argument converted to the Objective-C parameter of the same role.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @param text_container Argument converted to the Objective-C parameter of the same role.
         * @param char_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect rect_for_layout_at_point(const Point& starting_point, const Rect& rect, const TextContainer& text_container, const Range& char_range) const;
        /**
         * @brief Calls `-[NSTextBlock setBorderColor:]`.
         * @param color Argument converted to the Objective-C parameter of the same role.
         */
        void set_border_color(const Color& color) const;
        /**
         * @brief Calls `-[NSTextBlock setBorderColor:forEdge:]`.
         * @param color Argument converted to the Objective-C parameter of the same role.
         * @param edge Argument converted to the Objective-C parameter of the same role.
         */
        void set_border_color(const Color& color, RectEdge edge) const;
#ifdef COCOON_MACOS_27
        /**
         * @brief Calls `-[NSTextBlock setBorderColor:rectEdge:]`.
         * @param border_color Argument converted to the Objective-C parameter of the same role.
         * @param rect_edge Argument converted to the Objective-C parameter of the same role.
         */
        void set_border_color(const Color& border_color, CGRectEdge rect_edge) const;
#endif

        /**
         * @brief Calls `-[NSTextBlock setContentWidth:type:]`.
         * @details Convenience methods for content width in particular, using the above methods with dimension == NSTextBlockWidth
         * @param content_width Argument converted to the Objective-C parameter of the same role.
         * @param type Argument converted to the Objective-C parameter of the same role.
         */
        void set_content_width(double content_width, TextBlockValueType type) const;
        /**
         * @brief Calls `-[NSTextBlock setValue:type:forDimension:]`.
         * @details Content size
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param dimension Argument converted to the Objective-C parameter of the same role.
         */
        void set_value(double value, TextBlockValueType type, TextBlockDimension dimension) const;
        /**
         * @brief Calls `-[NSTextBlock setWidth:type:forLayer:]`.
         * @details Margin, border, and padding
         * @param width Argument converted to the Objective-C parameter of the same role.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param layer Argument converted to the Objective-C parameter of the same role.
         */
        void set_width(double width, TextBlockValueType type, TextBlockLayer layer) const;
        /**
         * @brief Calls `-[NSTextBlock setWidth:type:forLayer:edge:]`.
         * @param val Argument converted to the Objective-C parameter of the same role.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param layer Argument converted to the Objective-C parameter of the same role.
         * @param edge Argument converted to the Objective-C parameter of the same role.
         */
        void set_width(double val, TextBlockValueType type, TextBlockLayer layer, RectEdge edge) const;
#ifdef COCOON_MACOS_27
        /**
         * @brief Calls `-[NSTextBlock setWidth:type:forLayer:rectEdge:]`.
         * @param width Argument converted to the Objective-C parameter of the same role.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param layer Argument converted to the Objective-C parameter of the same role.
         * @param rect_edge Argument converted to the Objective-C parameter of the same role.
         */
        void set_width(double width, TextBlockValueType type, TextBlockLayer layer, CGRectEdge rect_edge) const;
#endif

        /**
         * @brief Calls `-[NSTextBlock valueForDimension:]`.
         * @param dimension Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double value_for_dimension(TextBlockDimension dimension) const;
        /**
         * @brief Calls `-[NSTextBlock valueTypeForDimension:]`.
         * @param dimension Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextBlockValueType value_type_for_dimension(TextBlockDimension dimension) const;
        /**
         * @brief Calls `-[NSTextBlock widthForLayer:edge:]`.
         * @param layer Argument converted to the Objective-C parameter of the same role.
         * @param edge Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double width_for_layer(TextBlockLayer layer, RectEdge edge) const;
#ifdef COCOON_MACOS_27
        /**
         * @brief Calls `-[NSTextBlock widthForLayer:rectEdge:]`.
         * @param layer Argument converted to the Objective-C parameter of the same role.
         * @param rect_edge Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double width_for_layer(TextBlockLayer layer, CGRectEdge rect_edge) const;
#endif

        /**
         * @brief Calls `-[NSTextBlock widthValueTypeForLayer:edge:]`.
         * @param layer Argument converted to the Objective-C parameter of the same role.
         * @param edge Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextBlockValueType width_value_type_for_layer(TextBlockLayer layer, RectEdge edge) const;
#ifdef COCOON_MACOS_27
        /**
         * @brief Calls `-[NSTextBlock widthValueTypeForLayer:rectEdge:]`.
         * @param layer Argument converted to the Objective-C parameter of the same role.
         * @param rect_edge Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextBlockValueType width_value_type_for_layer(TextBlockLayer layer, CGRectEdge rect_edge) const;
#endif

        /**
         * @brief Returns the `backgroundColor` property of `NSTextBlock`.
         * @details Colors
         * @return The converted Objective-C result.
         */
        Color background_color() const;
        /**
         * @brief Sets the `backgroundColor` property of `NSTextBlock`.
         * @details Colors
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_background_color(const Color& value) const;
        /**
         * @brief Returns the `contentWidth` property of `NSTextBlock`.
         * @return The converted Objective-C result.
         */
        double content_width() const;
        /**
         * @brief Returns the `contentWidthValueType` property of `NSTextBlock`.
         * @return The converted Objective-C result.
         */
        TextBlockValueType content_width_value_type() const;
        /**
         * @brief Returns the `verticalAlignment` property of `NSTextBlock`.
         * @details Alignment
         * @return The converted Objective-C result.
         */
        TextBlockVerticalAlignment vertical_alignment() const;
        /**
         * @brief Sets the `verticalAlignment` property of `NSTextBlock`.
         * @details Alignment
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_vertical_alignment(TextBlockVerticalAlignment value) const;
    };
}
