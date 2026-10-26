#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AdaptiveImageGlyph;
    class AttributedStringMarkdownParsingOptions;
    class FileWrapper;
    class Locale;
    class StringDrawingContext;
    class TextAttachment;
    class TextBlock;
    class TextList;
    class TextTable;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSAttributedString` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::AttributedString attributed_string;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::AttributedString attributed_string{};
     * attributed_string.attributed_string_by_inflecting_string();
     * attributed_string.bounding_rect_with_size({100, 100}, cocoon::StringDrawingOptions::UsesLineFragmentOrigin);
     * attributed_string.bounding_rect_with_size({100, 100}, cocoon::StringDrawingOptions::UsesLineFragmentOrigin, cocoon::StringDrawingContext());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsattributedstring
     */
    class AttributedString : public Object
    {
    public:
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString(const URL& markdown_file, const AttributedStringMarkdownParsingOptions& options, const URL& base_url);
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString(const std::vector<std::uint8_t>& data, const std::map<std::string, Object>& options, std::map<std::string, Object>& dict);
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString(const std::vector<std::uint8_t>& data, std::map<std::string, Object>& dict);
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString(const AttributedString& format, AttributedStringFormattingOptions options, const Locale& locale, char* arguments);
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString(const AttributedString& format, AttributedStringFormattingOptions options, const Locale& locale, const std::map<std::string, Object>& context, char* arguments);
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString(const std::vector<std::uint8_t>& data, const URL& base, std::map<std::string, Object>& dict);
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString(const std::vector<std::uint8_t>& markdown, const AttributedStringMarkdownParsingOptions& options, const URL& base_url);
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString(const std::string& markdown_string, const AttributedStringMarkdownParsingOptions& options, const URL& base_url);
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString(const FileWrapper& wrapper, std::map<std::string, Object>& dict);
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString(const std::string& str);
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString(const std::string& str, const std::map<std::string, Object>& attrs);
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString(const URL& url, const std::map<std::string, Object>& options, std::map<std::string, Object>& dict);
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString(const AdaptiveImageGlyph& adaptive_image_glyph, const std::map<std::string, Object>& attributes);
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString(const TextAttachment& attachment);
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString(const TextAttachment& attachment, const std::map<std::string, Object>& attributes);
        /// @brief Creates a new `NSAttributedString` instance and returns a handle to it.
        explicit AttributedString();
        /// @brief Creates a null handle that refers to no native object.
        AttributedString(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit AttributedString(Adopt adopt);
        /**
         * @brief Calls `-[NSAttributedString RTFDFileWrapperFromRange:documentAttributes:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param dict Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        FileWrapper rtfd_file_wrapper_from_range(const Range& range, const std::map<std::string, Object>& dict) const;
        /**
         * @brief Calls `-[NSAttributedString RTFDFromRange:documentAttributes:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param dict Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> rtfd_from_range(const Range& range, const std::map<std::string, Object>& dict) const;
        /**
         * @brief Calls `-[NSAttributedString RTFFromRange:documentAttributes:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param dict Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> rtf_from_range(const Range& range, const std::map<std::string, Object>& dict) const;
        /**
         * @brief Calls `-[NSAttributedString attribute:atIndex:effectiveRange:]`.
         * @param attr_name Argument converted to the Objective-C parameter of the same role.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object attribute(const std::string& attr_name, std::uint64_t location, Range* range) const;
        /**
         * @brief Calls `-[NSAttributedString attribute:atIndex:longestEffectiveRange:inRange:]`.
         * @param attr_name Argument converted to the Objective-C parameter of the same role.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param range_limit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object attribute(const std::string& attr_name, std::uint64_t location, Range* range, const Range& range_limit) const;
        /**
         * @brief Calls `-[NSAttributedString attributedStringByInflectingString]`.
         * @details If the string has portions tagged with NSInflectionRuleAttributeName that have no format specifiers, create a new string with those portions inflected by following the rule in the attribute.
         * @return The converted Objective-C result.
         */
        AttributedString attributed_string_by_inflecting_string() const;
        /**
         * @brief Calls `-[NSAttributedString attributedSubstringFromRange:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AttributedString attributed_substring_from_range(const Range& range) const;
        /**
         * @brief Calls `-[NSAttributedString attributesAtIndex:effectiveRange:]`.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> attributes_at_index(std::uint64_t location, Range* range) const;
        /**
         * @brief Calls `-[NSAttributedString attributesAtIndex:longestEffectiveRange:inRange:]`.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param range_limit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> attributes_at_index(std::uint64_t location, Range* range, const Range& range_limit) const;
        /**
         * @brief Calls `-[NSAttributedString boundingRectWithSize:options:]`.
         * @param size Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect bounding_rect_with_size(const Size& size, StringDrawingOptions options) const;
        /**
         * @brief Calls `-[NSAttributedString boundingRectWithSize:options:context:]`.
         * @param size Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param context Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect bounding_rect_with_size(const Size& size, StringDrawingOptions options, const StringDrawingContext& context) const;
        /**
         * @brief Calls `-[NSAttributedString containsAttachmentsInRange:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool contains_attachments_in_range(const Range& range) const;
        /**
         * @brief Calls `-[NSAttributedString dataFromRange:documentAttributes:error:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param dict Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> data_from_range(const Range& range, const std::map<std::string, Object>& dict) const;
        /**
         * @brief Calls `-[NSAttributedString docFormatFromRange:documentAttributes:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param dict Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> doc_format_from_range(const Range& range, const std::map<std::string, Object>& dict) const;
        /**
         * @brief Calls `-[NSAttributedString doubleClickAtIndex:]`.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range double_click_at_index(std::uint64_t location) const;
        /**
         * @brief Calls `-[NSAttributedString drawAtPoint:]`.
         * @param point Argument converted to the Objective-C parameter of the same role.
         */
        void draw_at_point(const Point& point) const;
        /**
         * @brief Calls `-[NSAttributedString drawInRect:]`.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         */
        void draw_in_rect(const Rect& rect) const;
        /**
         * @brief Calls `-[NSAttributedString drawWithRect:options:]`.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         */
        void draw_with_rect(const Rect& rect, StringDrawingOptions options) const;
        /**
         * @brief Calls `-[NSAttributedString drawWithRect:options:context:]`.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param context Argument converted to the Objective-C parameter of the same role.
         */
        void draw_with_rect(const Rect& rect, StringDrawingOptions options, const StringDrawingContext& context) const;
        /**
         * @brief Calls `-[NSAttributedString enumerateAttribute:inRange:options:usingBlock:]`.
         * @param attr_name Argument converted to the Objective-C parameter of the same role.
         * @param enumeration_range Argument converted to the Objective-C parameter of the same role.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_attribute(const std::string& attr_name, const Range& enumeration_range, AttributedStringEnumerationOptions opts, std::function<void(Object, Range, bool&)> block) const;
        /**
         * @brief Calls `-[NSAttributedString enumerateAttributesInRange:options:usingBlock:]`.
         * @param enumeration_range Argument converted to the Objective-C parameter of the same role.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_attributes_in_range(const Range& enumeration_range, AttributedStringEnumerationOptions opts, std::function<void(std::map<std::string, Object>, Range, bool&)> block) const;
        /**
         * @brief Calls `-[NSAttributedString fileWrapperFromRange:documentAttributes:error:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param dict Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        FileWrapper file_wrapper_from_range(const Range& range, const std::map<std::string, Object>& dict) const;
        /**
         * @brief Calls `-[NSAttributedString fontAttributesInRange:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> font_attributes_in_range(const Range& range) const;
        /**
         * @brief Calls `-[NSAttributedString isEqualToAttributedString:]`.
         * @param other Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_equal_to_attributed_string(const AttributedString& other) const;
        /**
         * @brief Calls `-[NSAttributedString itemNumberInTextList:atIndex:]`.
         * @param list Argument converted to the Objective-C parameter of the same role.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t item_number_in_text_list(const TextList& list, std::uint64_t location) const;
        /**
         * @brief Calls `-[NSAttributedString lineBreakBeforeIndex:withinRange:]`.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @param a_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t line_break_before_index(std::uint64_t location, const Range& a_range) const;
        /**
         * @brief Calls `-[NSAttributedString lineBreakByHyphenatingBeforeIndex:withinRange:]`.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @param a_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t line_break_by_hyphenating_before_index(std::uint64_t location, const Range& a_range) const;
        /**
         * @brief Calls `-[NSAttributedString nextWordFromIndex:forward:]`.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @param is_forward Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t next_word_from_index(std::uint64_t location, bool is_forward) const;
        /**
         * @brief Calls `-[NSAttributedString prefersRTFDInRange:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool prefers_rtfd_in_range(const Range& range) const;
        /**
         * @brief Calls `-[NSAttributedString rangeOfTextBlock:atIndex:]`.
         * @param block Argument converted to the Objective-C parameter of the same role.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range range_of_text_block(const TextBlock& block, std::uint64_t location) const;
        /**
         * @brief Calls `-[NSAttributedString rangeOfTextList:atIndex:]`.
         * @param list Argument converted to the Objective-C parameter of the same role.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range range_of_text_list(const TextList& list, std::uint64_t location) const;
        /**
         * @brief Calls `-[NSAttributedString rangeOfTextTable:atIndex:]`.
         * @param table Argument converted to the Objective-C parameter of the same role.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range range_of_text_table(const TextTable& table, std::uint64_t location) const;
        /**
         * @brief Calls `-[NSAttributedString rulerAttributesInRange:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> ruler_attributes_in_range(const Range& range) const;
        /**
         * @brief Calls `-[NSAttributedString size]`.
         * @return The converted Objective-C result.
         */
        Size size() const;
        /**
         * @brief Returns the `containsAttachments` property of `NSAttributedString`.
         * @return The converted Objective-C result.
         */
        bool contains_attachments() const;
        /**
         * @brief Returns the `length` property of `NSAttributedString`.
         * @return The converted Objective-C result.
         */
        std::uint64_t length() const;
        /**
         * @brief Returns the `string` property of `NSAttributedString`.
         * @return The converted Objective-C result.
         */
        std::string string() const;
        /**
         * @brief Returns the `textTypes` property of `NSAttributedString`.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> text_types();
        /**
         * @brief Returns the `textUnfilteredTypes` property of `NSAttributedString`.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> text_unfiltered_types();
    };
}
