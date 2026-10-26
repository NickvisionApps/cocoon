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
         * @param text_range Argument converted to the Objective-C parameter of the same role.
         * @param for_editing_text_selection Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextRange adjusted_range_from_range(const TextRange& text_range, bool for_editing_text_selection) const;
        /**
         * @brief Calls `-[NSTextContentStorage attributedStringForTextElement:]`.
         * @param text_element Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AttributedString attributed_string_for_text_element(const TextElement& text_element) const;
        /**
         * @brief Calls `-[NSTextContentStorage locationFromLocation:withOffset:]`.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @param offset Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object location_from_location(const Object& location, std::int64_t offset) const;
        /**
         * @brief Calls `-[NSTextContentStorage offsetFromLocation:toLocation:]`.
         * @param from Argument converted to the Objective-C parameter of the same role.
         * @param to Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t offset_from_location(const Object& from, const Object& to) const;
        /**
         * @brief Calls `-[NSTextContentStorage textElementForAttributedString:]`.
         * @param attributed_string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextElement text_element_for_attributed_string(const AttributedString& attributed_string) const;
        /**
         * @brief Returns the `attributedString` property of `NSTextContentStorage`.
         * @return The converted Objective-C result.
         */
        AttributedString attributed_string() const;
        /**
         * @brief Sets the `attributedString` property of `NSTextContentStorage`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_attributed_string(const AttributedString& value) const;
        /**
         * @brief Returns the `includesTextListMarkers` property of `NSTextContentStorage`.
         * @return The converted Objective-C result.
         */
        bool includes_text_list_markers() const;
        /**
         * @brief Sets the `includesTextListMarkers` property of `NSTextContentStorage`.
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
