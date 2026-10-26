#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text_paragraph.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class TextList;

    /**
     * @brief C++ handle for the Objective-C class `NSTextListElement` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TextParagraph.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextListElement text_list_element;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextlistelement
     */
    class TextListElement : public TextParagraph
    {
    public:
        /// @brief Creates a new `NSTextListElement` instance and returns a handle to it.
        explicit TextListElement(const TextListElement& parent, const TextList& text_list, const AttributedString& contents, const std::map<std::string, Object>& marker_attributes, const std::vector<TextListElement>& children);
        /// @brief Creates a new `NSTextListElement` instance and returns a handle to it.
        explicit TextListElement(const std::vector<TextListElement>& children, const TextList& text_list, std::int64_t nesting_level);
        /// @brief Creates a new `NSTextListElement` instance and returns a handle to it.
        explicit TextListElement(const AttributedString& contents, const std::map<std::string, Object>& marker_attributes, const TextList& text_list, const std::vector<TextListElement>& children);
        /// @brief Creates a new `NSTextListElement` instance and returns a handle to it.
        explicit TextListElement();
        /// @brief Creates a null handle that refers to no native object.
        TextListElement(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextListElement(Adopt adopt);
        using TextElement::child_elements;
        using TextElement::parent_element;
        using TextParagraph::attributed_string;
        /**
         * @brief Returns the `attributedString` property of `NSTextListElement`.
         * @return The converted Objective-C result.
         */
        AttributedString attributed_string() const;
        /**
         * @brief Returns the `childElements` property of `NSTextListElement`.
         * @return The converted Objective-C result.
         */
        std::vector<TextListElement> child_elements() const;
        /**
         * @brief Returns the `contents` property of `NSTextListElement`.
         * @return The converted Objective-C result.
         */
        AttributedString contents() const;
        /**
         * @brief Returns the `markerAttributes` property of `NSTextListElement`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> marker_attributes() const;
        /**
         * @brief Returns the `parentElement` property of `NSTextListElement`.
         * @return The converted Objective-C result.
         */
        TextListElement parent_element() const;
        /**
         * @brief Returns the `textList` property of `NSTextListElement`.
         * @return The converted Objective-C result.
         */
        TextList text_list() const;
    };
}
