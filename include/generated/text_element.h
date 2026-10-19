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
     * @return The converted Objective-C result.
     */
        std::vector<TextElement> child_elements() const;
        /**
     * @brief Returns the `elementRange` property of `NSTextElement`.
     * @return The converted Objective-C result.
     */
        TextRange element_range() const;
        /**
     * @brief Sets the `elementRange` property of `NSTextElement`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_element_range(const TextRange& value) const;
        /**
     * @brief Returns the `isRepresentedElement` property of `NSTextElement`.
     * @return The converted Objective-C result.
     */
        bool is_represented_element() const;
        /**
     * @brief Returns the `parentElement` property of `NSTextElement`.
     * @return The converted Objective-C result.
     */
        TextElement parent_element() const;
        /**
     * @brief Returns the `textContentManager` property of `NSTextElement`.
     * @return The converted Objective-C result.
     */
        TextContentManager text_content_manager() const;
        /**
     * @brief Sets the `textContentManager` property of `NSTextElement`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_content_manager(const TextContentManager& value) const;
    };
}
