#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text_element.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class TextRange;

    /**
     * @brief C++ handle for the Objective-C class `NSTextParagraph` (AppKit).
     * @details A class that represents a single paragraph backed by an attributed string as the contents.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TextElement.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextParagraph text_paragraph;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextparagraph
     */
    class TextParagraph : public TextElement
    {
    public:
        /// @brief Creates a new `NSTextParagraph` instance and returns a handle to it.
        explicit TextParagraph(const AttributedString& attributed_string);
        /// @brief Creates a new `NSTextParagraph` instance and returns a handle to it.
        explicit TextParagraph();
        /// @brief Creates a null handle that refers to no native object.
        TextParagraph(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextParagraph(Adopt adopt);
        /**
     * @brief Returns the `attributedString` property of `NSTextParagraph`.
     * @details The source attributed string.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_string() const;
        /**
     * @brief Returns the `paragraphContentRange` property of `NSTextParagraph`.
     * @details The range of the paragraph's content within the document. The paragraph's content is the text up to but not including the paragraph separator. Together with ''paragraphSeparatorRange'', this range covers the entire ''NSTextElement/elementRange''.
     * @return The converted Objective-C result.
     */
        TextRange paragraph_content_range() const;
        /**
     * @brief Returns the `paragraphSeparatorRange` property of `NSTextParagraph`.
     * @details The range of the paragraph separator within the document. Together with ''paragraphContentRange'', this range covers the entire ''NSTextElement/elementRange''.
     * @return The converted Objective-C result.
     */
        TextRange paragraph_separator_range() const;
    };
}
