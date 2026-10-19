#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text_block.h"
#include "types.h"

namespace cocoon
{
    class LayoutManager;
    class TextContainer;
    class TextTableBlock;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSTextTable` (AppKit).
     * @details NSTextTable represents a table as a whole.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TextBlock.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextTable text_table;
     * text_table.set_collapses_borders(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextTable text_table{};
     * text_table.set_collapses_borders(true);
     * auto collapses_borders = text_table.collapses_borders();
     * text_table.set_hides_empty_cells(true);
     * auto hides_empty_cells = text_table.hides_empty_cells();
     * text_table.set_layout_algorithm(cocoon::TextTableLayoutAlgorithm::AutomaticLayoutAlgorithm);
     * auto layout_algorithm = text_table.layout_algorithm();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstexttable
     */
    class TextTable : public TextBlock
    {
    public:
        /// @brief Creates a new `NSTextTable` instance and returns a handle to it.
        explicit TextTable();
        /// @brief Creates a null handle that refers to no native object.
        TextTable(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextTable(Adopt adopt);
        /**
     * @brief Calls `-[NSTextTable boundsRectForBlock:contentRect:inRect:textContainer:characterRange:]`.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @param content_rect Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param text_container Argument converted to the Objective-C parameter of the same role.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect bounds_rect_for_block(const TextTableBlock& block, const Rect& content_rect, const Rect& rect, const TextContainer& text_container, const Range& char_range) const;
        /**
     * @brief Calls `-[NSTextTable drawBackgroundForBlock:withFrame:inView:characterRange:layoutManager:]`.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @param frame_rect Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     * @param layout_manager Argument converted to the Objective-C parameter of the same role.
     */
        void draw_background_for_block(const TextTableBlock& block, const Rect& frame_rect, const View& control_view, const Range& char_range, const LayoutManager& layout_manager) const;
        /**
     * @brief Calls `-[NSTextTable rectForBlock:layoutAtPoint:inRect:textContainer:characterRange:]`.
     * @details An NSTextTableBlock delegates its layout and drawing operations to its enclosing table, using the following NSTextTable methods.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @param starting_point Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param text_container Argument converted to the Objective-C parameter of the same role.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect rect_for_block(const TextTableBlock& block, const Point& starting_point, const Rect& rect, const TextContainer& text_container, const Range& char_range) const;
        /**
     * @brief Returns the `collapsesBorders` property of `NSTextTable`.
     * @return The converted Objective-C result.
     */
        bool collapses_borders() const;
        /**
     * @brief Sets the `collapsesBorders` property of `NSTextTable`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_collapses_borders(bool value) const;
        /**
     * @brief Returns the `hidesEmptyCells` property of `NSTextTable`.
     * @return The converted Objective-C result.
     */
        bool hides_empty_cells() const;
        /**
     * @brief Sets the `hidesEmptyCells` property of `NSTextTable`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hides_empty_cells(bool value) const;
        /**
     * @brief Returns the `layoutAlgorithm` property of `NSTextTable`.
     * @return The converted Objective-C result.
     */
        TextTableLayoutAlgorithm layout_algorithm() const;
        /**
     * @brief Sets the `layoutAlgorithm` property of `NSTextTable`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_layout_algorithm(TextTableLayoutAlgorithm value) const;
        /**
     * @brief Returns the `numberOfColumns` property of `NSTextTable`.
     * @details These methods control the basic parameters of the table.
     * @return The converted Objective-C result.
     */
        std::uint64_t number_of_columns() const;
        /**
     * @brief Sets the `numberOfColumns` property of `NSTextTable`.
     * @details These methods control the basic parameters of the table.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_number_of_columns(std::uint64_t value) const;
    };
}
