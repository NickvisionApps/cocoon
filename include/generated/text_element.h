#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class TextContentManager;
    class TextRange;

    /**
     * @brief C++ handle for the Objective-C class `NSTextElement` (AppKit).
     * @details An abstract base class that represents the smallest units of text layout such as paragraphs or attachments. A text element is associated with an ''NSTextContentManager''.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextElement text_element;
     * text_element.set_element_range(cocoon::TextRange());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextElement text_element{};
     * text_element.set_element_range(cocoon::TextRange());
     * auto element_range = text_element.element_range();
     * text_element.set_text_content_manager(cocoon::TextContentManager());
     * auto text_content_manager = text_element.text_content_manager();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextelement
     */
    class TextElement : public Object
    {
    public:
        /// @brief Creates a new `NSTextElement` instance and returns a handle to it.
        explicit TextElement(const TextContentManager& text_content_manager);
        /// @brief Creates a new `NSTextElement` instance and returns a handle to it.
        explicit TextElement();
        /// @brief Creates a null handle that refers to no native object.
        TextElement(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextElement(Adopt adopt);
        /**
     * @brief Returns the `childElements` property of `NSTextElement`.
     * @details An array of zero or more child text elements. A concrete 'NSTextElement' subclass can be structured in a tree. An element can have zero or more child elements.
     * @return The converted Objective-C result.
     */
        std::vector<TextElement> child_elements() const;
        /**
     * @brief Returns the `elementRange` property of `NSTextElement`.
     * @details A range value that represents the range of the element inside the document.
     * @return The converted Objective-C result.
     */
        TextRange element_range() const;
        /**
     * @brief Sets the `elementRange` property of `NSTextElement`.
     * @details A range value that represents the range of the element inside the document.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_element_range(const TextRange& value) const;
        /**
     * @brief Returns the `isRepresentedElement` property of `NSTextElement`.
     * @details A Boolean value that indicates whether this element is in the text layout. When 'true', the element is enumerated by ''NSTextContentManager''.
     * @return The converted Objective-C result.
     */
        bool is_represented_element() const;
        /**
     * @brief Returns the `parentElement` property of `NSTextElement`.
     * @details A value that represents the parent element if this text element is a child of an enclosing element.
     * @return The converted Objective-C result.
     */
        TextElement parent_element() const;
        /**
     * @brief Returns the `textContentManager` property of `NSTextElement`.
     * @details The value that represents the current content manager. A text element can migrate between text content managers.
     * @return The converted Objective-C result.
     */
        TextContentManager text_content_manager() const;
        /**
     * @brief Sets the `textContentManager` property of `NSTextElement`.
     * @details The value that represents the current content manager. A text element can migrate between text content managers.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_content_manager(const TextContentManager& value) const;
    };
}
