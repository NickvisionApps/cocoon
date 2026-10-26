#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text_block.h"
#include "types.h"

namespace cocoon
{
    class TextTable;

    /**
     * @brief C++ handle for the Objective-C class `NSTextTableBlock` (AppKit).
     * @details NSTextTableBlock is a subclass of NSTextBlock used for a block that appears as a cell in a text table.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TextBlock.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextTableBlock text_table_block;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstexttableblock
     */
    class TextTableBlock : public TextBlock
    {
    public:
        /// @brief Creates a new `NSTextTableBlock` instance and returns a handle to it.
        explicit TextTableBlock(const TextTable& table, std::int64_t row, std::int64_t row_span, std::int64_t col, std::int64_t col_span);
        /// @brief Creates a new `NSTextTableBlock` instance and returns a handle to it.
        explicit TextTableBlock();
        /// @brief Creates a null handle that refers to no native object.
        TextTableBlock(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextTableBlock(Adopt adopt);
        /**
         * @brief Returns the `columnSpan` property of `NSTextTableBlock`.
         * @return The converted Objective-C result.
         */
        std::int64_t column_span() const;
        /**
         * @brief Returns the `rowSpan` property of `NSTextTableBlock`.
         * @return The converted Objective-C result.
         */
        std::int64_t row_span() const;
        /**
         * @brief Returns the `startingColumn` property of `NSTextTableBlock`.
         * @return The converted Objective-C result.
         */
        std::int64_t starting_column() const;
        /**
         * @brief Returns the `startingRow` property of `NSTextTableBlock`.
         * @return The converted Objective-C result.
         */
        std::int64_t starting_row() const;
        /**
         * @brief Returns the `table` property of `NSTextTableBlock`.
         * @details These methods determine the block's role in its enclosing table.
         * @return The converted Objective-C result.
         */
        TextTable table() const;
    };
}
