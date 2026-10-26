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
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range range_in_string(const std::string& string) const;
        /**
         * @brief Returns the `endColumn` property of `NSAttributedStringMarkdownSourcePosition`.
         * @return The converted Objective-C result.
         */
        std::int64_t end_column() const;
        /**
         * @brief Returns the `endLine` property of `NSAttributedStringMarkdownSourcePosition`.
         * @return The converted Objective-C result.
         */
        std::int64_t end_line() const;
        /**
         * @brief Returns the `startColumn` property of `NSAttributedStringMarkdownSourcePosition`.
         * @return The converted Objective-C result.
         */
        std::int64_t start_column() const;
        /**
         * @brief Returns the `startLine` property of `NSAttributedStringMarkdownSourcePosition`.
         * @return The converted Objective-C result.
         */
        std::int64_t start_line() const;
    };
}
