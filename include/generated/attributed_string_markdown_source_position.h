#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSAttributedStringMarkdownSourcePosition` (Foundation).
     * @details The position of attributed string text in its original Markdown source string.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::AttributedStringMarkdownSourcePosition attributed_string_markdown_source_position;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::AttributedStringMarkdownSourcePosition attributed_string_markdown_source_position{};
     * attributed_string_markdown_source_position.range_in_string("text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsattributedstringmarkdownsourceposition
     */
    class AttributedStringMarkdownSourcePosition : public Object
    {
    public:
        /// @brief Creates a new `NSAttributedStringMarkdownSourcePosition` instance and returns a handle to it.
        explicit AttributedStringMarkdownSourcePosition(std::int64_t start_line, std::int64_t start_column, std::int64_t end_line, std::int64_t end_column);
        /// @brief Creates a new `NSAttributedStringMarkdownSourcePosition` instance and returns a handle to it.
        explicit AttributedStringMarkdownSourcePosition();
        /// @brief Creates a null handle that refers to no native object.
        AttributedStringMarkdownSourcePosition(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit AttributedStringMarkdownSourcePosition(Adopt adopt);
        /**
         * @brief Calls `-[NSAttributedStringMarkdownSourcePosition rangeInString:]`.
         * @details Returns a range indicating the source portion within a Markdown string. Use this method to access the marked-up region of 'string' with an 'NSRange', rather than making manual calculations based on row and column values. - Parameter string: The Markdown source string that this source position object refers to. - Returns: A range that represents the source portion within a source Markdown string.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range range_in_string(const std::string& string) const;
        /**
         * @brief Returns the `endColumn` property of `NSAttributedStringMarkdownSourcePosition`.
         * @details The column where the text ends in the Markdown source. Uses 1-based counting. Columns represent UTF-8 indices; for multi-byte characters, the column indicates the first byte.
         * @return The converted Objective-C result.
         */
        std::int64_t end_column() const;
        /**
         * @brief Returns the `endLine` property of `NSAttributedStringMarkdownSourcePosition`.
         * @details The line where the text ends in the Markdown source. Uses 1-based counting.
         * @return The converted Objective-C result.
         */
        std::int64_t end_line() const;
        /**
         * @brief Returns the `startColumn` property of `NSAttributedStringMarkdownSourcePosition`.
         * @details The column where the text begins in the Markdown source. Uses 1-based counting. Columns represent UTF-8 indices; for multi-byte characters, the column indicates the first byte.
         * @return The converted Objective-C result.
         */
        std::int64_t start_column() const;
        /**
         * @brief Returns the `startLine` property of `NSAttributedStringMarkdownSourcePosition`.
         * @details The line where the text begins in the Markdown source. Uses 1-based counting.
         * @return The converted Objective-C result.
         */
        std::int64_t start_line() const;
    };
}
