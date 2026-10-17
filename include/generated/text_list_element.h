#pragma once

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
        explicit TextListElement();
        /// @brief Creates a null handle that refers to no native object.
        TextListElement(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextListElement(Adopt adopt);
        using TextElement::child_elements;
        using TextElement::parent_element;
        using TextParagraph::attributed_string;
        /**
     * @brief Calls `+[NSTextListElement textListElementWithChildElements:textList:nestingLevel:]`.
     * @details Creates a text list element with the list elements and nesting level you provide. Raises an exception when 'nestingLevel \< 0'. - Parameters: - children: An array of ''NSTextListElement'' elements. - textList: The ''NSTextList'' to add elements to. - nestingLevel: An integer value that describes the level of nesting of these elements. - Returns: 'nil' if 'children.count' is zero.
     * @param children Argument converted to the Objective-C parameter of the same role.
     * @param text_list Argument converted to the Objective-C parameter of the same role.
     * @param nesting_level Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextListElement text_list_element_with_child_elements(const std::vector<TextListElement>& children, const TextList& text_list, std::int64_t nesting_level);
        /**
     * @brief Calls `+[NSTextListElement textListElementWithContents:markerAttributes:textList:childElements:]`.
     * @details Creates a text list element with the list elements, nesting level, and marker attributes you provide. - Parameters: - contents: An \<doc://com.apple.documentation/documentation/foundation/nsattributedstring> that contains the contents of the text list element. - markerAttributes: A dictionary of \<doc://com.apple.documentation/documentation/foundation/nsattributedstring/key> keys and values that describe the marker attributes. - textList: The ''NSTextList'' to add elements to. - children: An array of ''NSTextListElement'' elements.
     * @param contents Argument converted to the Objective-C parameter of the same role.
     * @param marker_attributes Argument converted to the Objective-C parameter of the same role.
     * @param text_list Argument converted to the Objective-C parameter of the same role.
     * @param children Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextListElement text_list_element_with_contents(const AttributedString& contents, const std::map<std::string, Object>& marker_attributes, const TextList& text_list, const std::vector<TextListElement>& children);
        /**
     * @brief Returns the `attributedString` property of `NSTextListElement`.
     * @details An attributed string that represents the string the framework displays for this element taking into account markers and the indentation level of the list element. Derived from ''contents'' and ''textList'' configured with the text list element's position inside the tree. Overrides 'NSTextParagraph.attributedString'.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_string() const;
        /**
     * @brief Returns the `childElements` property of `NSTextListElement`.
     * @details An array that contains child text elements.
     * @return The converted Objective-C result.
     */
        std::vector<TextListElement> child_elements() const;
        /**
     * @brief Returns the `contents` property of `NSTextListElement`.
     * @details The text list element contents without markers and formatting.
     * @return The converted Objective-C result.
     */
        AttributedString contents() const;
        /**
     * @brief Returns the `markerAttributes` property of `NSTextListElement`.
     * @details A dictionary of attributed string keys and values that represent the list's marker attributes.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> marker_attributes() const;
        /**
     * @brief Returns the `parentElement` property of `NSTextListElement`.
     * @details A text list element that refers to the enclosing text list element.
     * @return The converted Objective-C result.
     */
        TextListElement parent_element() const;
        /**
     * @brief Returns the `textList` property of `NSTextListElement`.
     * @details The value that represents the text list.
     * @return The converted Objective-C result.
     */
        TextList text_list() const;
    };
}
