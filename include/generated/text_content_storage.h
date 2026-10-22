#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text_content_manager.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class TextElement;
    class TextParagraph;
    class TextRange;

    /**
     * @brief C++ handle for the Objective-C class `NSTextContentStorage` (AppKit).
     * @details A concrete object for managing the document's text content and generating the text elements necessary for layout. An ''NSTextContentStorage'' object provides the backing store for document content. It stores the text in an attributed string object, and defaults to using an ''NSTextStorage'' object. It also maps portions of the text to ''NSTextElement'' objects to organize the text into paragraphs, lists, and other common element types found in text content. During layout, TextKit uses these elements to lay out and render the content into one or more rendering surfaces. 'NSTextContentStorage' is a concrete subclass of ''NSTextContentManager'' providing support for 'NSAttributedString' backing store. It also implements 'NSTextStorageObserving' participating as a client of 'NSTextStorage'. The facility only supports a single 'NSTextContentStorage' associated with a text storage. When ''NSTextStorage'' is non-nil, ''attributedString'' is ignored. By default, 'NSTextContentStorage' is initialized with 'NSTextStorage' as the backing store.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TextContentManager.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextContentStorage text_content_storage;
     * text_content_storage.set_attributed_string(cocoon::AttributedString());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextContentStorage text_content_storage{};
     * text_content_storage.set_attributed_string(cocoon::AttributedString());
     * auto attributed_string = text_content_storage.attributed_string();
     * text_content_storage.set_includes_text_list_markers(true);
     * auto includes_text_list_markers = text_content_storage.includes_text_list_markers();
     * text_content_storage.adjusted_range_from_range(cocoon::TextRange(), true);
     * text_content_storage.attributed_string_for_text_element(cocoon::TextElement());
     * text_content_storage.text_element_for_attributed_string(cocoon::AttributedString());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextcontentstorage
     */
    class TextContentStorage : public TextContentManager
    {
    public:
        /// @brief Creates a new `NSTextContentStorage` instance and returns a handle to it.
        explicit TextContentStorage();
        /// @brief Creates a null handle that refers to no native object.
        TextContentStorage(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextContentStorage(Adopt adopt);
        /**
         * @brief Calls `-[NSTextContentStorage adjustedRangeFromRange:forEditingTextSelection:]`.
         * @details Returns the text range, if any, in the backing store that required manual adjustment after editing. Should be implemented if the location backing store requires manual adjustment after editing. When 'textRange' is intersecting or following the current edited range, the method returns the range adjusted for the modification in the editing session. Returns 'nil' when no adjustment is necessary. - Parameters: - textRange: The range to adjust. - forEditingTextSelection: Indicates if 'textRange' is for the text selection associated with the edit session. - Returns: The adjusted range, or 'nil' if no adjustment is necessary.
         * @param text_range Argument converted to the Objective-C parameter of the same role.
         * @param for_editing_text_selection Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextRange adjusted_range_from_range(const TextRange& text_range, bool for_editing_text_selection) const;
        /**
         * @brief Calls `-[NSTextContentStorage attributedStringForTextElement:]`.
         * @details Returns a new attributed string for the text element. Returns 'nil' if 'textElement' cannot be mapped to 'NSAttributedString'. - Parameters: - textElement: The text element to convert. - Returns: An attributed string representation, or 'nil' if unmappable.
         * @param text_element Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AttributedString attributed_string_for_text_element(const TextElement& text_element) const;
        /**
         * @brief Calls `-[NSTextContentStorage locationFromLocation:withOffset:]`.
         * @details Returns a new text location object based on an existing location and offset you provide. The offset value could be positive or negative indicating the logical direction. Could return 'nil' when the inputs don't produce any legal location (i.e. out of bounds index). - Parameters: - location: The base location. - offset: The offset from the base location. - Returns: A new location, or 'nil' if the result would be out of bounds.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @param offset Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object location_from_location(const Object& location, std::int64_t offset) const;
        /**
         * @brief Calls `-[NSTextContentStorage offsetFromLocation:toLocation:]`.
         * @details Returns the number of characters between the specified locations. The return value could be positive or negative. Could return 'NSNotFound' when the offset cannot be represented in an integer value (i.e. locations are not in the same document). - Parameters: - from: The starting location. - to: The ending location. - Returns: The signed offset, or \<doc://com.apple.documentation/documentation/foundation/nsnotfound> if the locations are not in the same document.
         * @param from Argument converted to the Objective-C parameter of the same role.
         * @param to Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t offset_from_location(const Object& from, const Object& to) const;
        /**
         * @brief Calls `-[NSTextContentStorage textElementForAttributedString:]`.
         * @details Returns the text element corresponding to the attributed string. Returns 'nil' when 'attributedString' contains attributes not mappable to ''NSTextElement''. - Parameters: - attributedString: The attributed string to convert. - Returns: A text element, or 'nil' if the attributes are unmappable.
         * @param attributed_string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextElement text_element_for_attributed_string(const AttributedString& attributed_string) const;
        /**
         * @brief Returns the `attributedString` property of `NSTextContentStorage`.
         * @details An attributed string that contains the contents of the document. KVO-compliant.
         * @return The converted Objective-C result.
         */
        AttributedString attributed_string() const;
        /**
         * @brief Sets the `attributedString` property of `NSTextContentStorage`.
         * @details An attributed string that contains the contents of the document. KVO-compliant.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_attributed_string(const AttributedString& value) const;
        /**
         * @brief Returns the `includesTextListMarkers` property of `NSTextContentStorage`.
         * @details When 'true', 'NSTextContentStorage' assumes the paragraph with 'NSTextList' includes the text list marker string. Utilizes 'NSTextList.includesTextListMarkers' as the default value.
         * @return The converted Objective-C result.
         */
        bool includes_text_list_markers() const;
        /**
         * @brief Sets the `includesTextListMarkers` property of `NSTextContentStorage`.
         * @details When 'true', 'NSTextContentStorage' assumes the paragraph with 'NSTextList' includes the text list marker string. Utilizes 'NSTextList.includesTextListMarkers' as the default value.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_includes_text_list_markers(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `text_paragraph_with_range`; connect a callback with `text_paragraph_with_range().connect(...)`.
        Signal<TextContentStorage, TextParagraph(Range)> text_paragraph_with_range() const
        {
            return Signal<TextContentStorage, TextParagraph(Range)>(handle(), "text_paragraph_with_range");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
