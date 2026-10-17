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
     * @details A string of text that manages data, layout, and stylistic information for ranges of characters to support rendering. ''NSAttributedString'' is a type you use to manage strings of stylized Unicode text. In addition to text, an attributed string contains key-value pairs known as attributes that specify additional information to apply to ranges of characters within the string. Attributed strings support many different kinds of attributes, including: - Rendering attributes that specify font, color, kern, ligature, and other details - Attributes for attachments and adaptive image glyphs - Semantic attributes such as link URLs or tool-tip information - Language attributes to support automatic gender agreement and text layout - Accessibility attributes that provide information for assistive technologies - Attributes that summarize details of the Markdown import process - Custom attributes you define for your app Use attributed strings anywhere you need styled text, or when you need to associate additional information with your text. Because ''NSAttributedString'' is an immutable type, you specify all of the text and attributes for it at creation time and can't change them later. You can create attributed strings directly from a string of characters and a dictionary of attributes. You can also create attributed strings from the contents of a file, including files that contain RTF, RTFD, HTML, Markdown, or other file formats. If you need to modify the contents of an attributed string later, use the ''NSMutableAttributedString'' type instead. If you create an ''NSAttributedString'' without any font information, the string's default font is Helvetica 12-point, which might differ from the default system font for the platform. To change the font, specify a font attribute at creation time. \#\#\# Persistence Be aware of how you persist attributed strings to and from the disk. RTF and RTFD are the preferred format for attributed strings because they offer the best fidelity for reading and writing attribute data. The RTF formats support a large number of standard attributes, and Apple extends the formats to support many Apple-specific attributes. If you define custom attributes for ranges of characters, store them separately alongside the RTF file for your text. If you work extensively with HTML content, validate the results and performance of import and export operations during testing. WebKit handles the conversion between HTML markup and attributed strings. If an HTML file contains tags or constructs that attributed strings don't support, the import process ignores them and imports what it can. When you create an attributed string from Markdown, the system adds presentation intent attributes with information about the original Markdown content. The system doesn't add style attributes to match the Markdown elements, but the system applies default style information when it renders a string with intent attributes. To change the rendering behavior of your Markdown content, remove the intent attributes and add the style attributes you prefer. > Important: > When reading or writing attributed strings, choose methods that return or throw an error, and check any errors you receive. Handling errors is the best way to detect issues with the import or export process and take corrective action. The methods for reading and writing common file formats also support document attributes. Document attributes aren't part of the attributed string itself, but accompany the text when you save it to a file. When you read a file, the system returns any document attributes that it finds. Similarly, when you write an attributed string to a file, you can specify the attributes to include. For more information about document attributes, see ''DocumentAttributeKey'' and ''DocumentReadingOptionKey''. \#\#\# System framework interoperability \<doc://com.apple.documentation/documentation/uikit/textkit> and \<doc://com.apple.documentation/documentation/coretext> use attributed strings extensively during the layout and rendering processes. These technologies use the string's text and rendering-related attributes to calculate the text metrics needed during layout. Similarly, these technologies apply those same attributes during rendering to give the text its styled appearance. The technologies use only attributes that directly affect the appearance of the text, and ignore most other attributes. For some attributes, the text system adds attributes during rendering as needed. For example, the text system provides default style attributes for text with the ''Key/link'' attribute. \<doc://com.apple.documentation/documentation/appkit> and \<doc://com.apple.documentation/documentation/uikit> also support attributed strings in several ways. Some views and controls in these frameworks have APIs that accept attributed strings, and render the string with its style information. The frameworks also add methods to the ''NSAttributedString'' class that let you draw a styled string directly in one of your custom views. Because these methods use TextKit to draw the string, they recognize the same rendering-related attributes as that technology. The ''NSAttributedString'' class and its Core Foundation counterpart, \<doc://com.apple.documentation/documentation/corefoundation/cfattributedstring>, are toll-free bridged, which means you can use the two types interchangeably in your code without losing any text or attribute information.
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
     * auto made_0 = cocoon::AttributedString::attributed_string_with_attachment(cocoon::TextAttachment());
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
     * @details Returns the value for an attribute with the specified name of the character at the specified index and, by reference, the range where the attribute applies. Raises an 'NSRangeException' if 'location' lies beyond the end of the receiver's characters. - Parameters: - attrName: The name of an attribute. - location: The index for which to return attributes. This value must not exceed the bounds of the receiver. - range: If non-'NULL', upon return contains a range over which the named attribute's value applies, or a range over which the attribute does not exist. The range isn't necessarily the maximum range covered by 'attrName', and its extent is implementation-dependent. If you need the maximum range, use 'attribute:atIndex:longestEffectiveRange:inRange:'. If you don't need this value, pass 'NULL'. - Returns: The value for the attribute named 'attrName' of the character at 'location', or 'nil' if there is no such attribute.
     * @param attr_name Argument converted to the Objective-C parameter of the same role.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object attribute(const std::string& attr_name, std::uint64_t location, Range* range) const;
        /**
     * @brief Calls `-[NSAttributedString attribute:atIndex:longestEffectiveRange:inRange:]`.
     * @details Returns the value for the attribute with the specified name of the character at the specified index and, by reference, the range where the attribute applies. Raises an 'NSRangeException' if 'location' or any part of 'rangeLimit' lies beyond the end of the receiver's characters. If you don't need the longest effective range, it's far more efficient to use 'attribute:atIndex:effectiveRange:' to retrieve the attribute value. - Parameters: - attrName: The name of an attribute. - location: The index at which to test for 'attrName'. - range: If non-'NULL', upon return contains the full range over which the value of the named attribute is the same as that at 'location', clipped to 'rangeLimit', or the full range over which the attribute does not exist. If you don't need this value, pass 'NULL'. - rangeLimit: The range over which to search for continuous presence of 'attrName'. This value must not exceed the bounds of the receiver. - Returns: The value for the attribute named 'attrName' of the character at 'location', or 'nil' if there is no such attribute.
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
     * @brief Calls `+[NSAttributedString attributedStringWithAdaptiveImageGlyph:attributes:]`.
     * @param adaptive_image_glyph Argument converted to the Objective-C parameter of the same role.
     * @param attributes Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static AttributedString attributed_string_with_adaptive_image_glyph(const AdaptiveImageGlyph& adaptive_image_glyph, const std::map<std::string, Object>& attributes);
        /**
     * @brief Calls `+[NSAttributedString attributedStringWithAttachment:]`.
     * @param attachment Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static AttributedString attributed_string_with_attachment(const TextAttachment& attachment);
        /**
     * @brief Calls `+[NSAttributedString attributedStringWithAttachment:attributes:]`.
     * @param attachment Argument converted to the Objective-C parameter of the same role.
     * @param attributes Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static AttributedString attributed_string_with_attachment(const TextAttachment& attachment, const std::map<std::string, Object>& attributes);
        /**
     * @brief Calls `-[NSAttributedString attributedSubstringFromRange:]`.
     * @details Returns an attributed string consisting of the characters and attributes within the specified range in the attributed string. Raises an 'NSRangeException' if any part of 'range' lies beyond the end of the receiver's characters. This method treats the length of the string as a valid range value that returns an empty string. - Parameter range: The range from which to create a new attributed string. 'range' must lie within the bounds of the receiver. - Returns: An 'NSAttributedString' object consisting of the characters and attributes within 'range' in the receiver.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_substring_from_range(const Range& range) const;
        /**
     * @brief Calls `-[NSAttributedString attributesAtIndex:effectiveRange:]`.
     * @details Returns the attributes for the character at the specified index. Raises an 'NSRangeException' if 'location' lies beyond the end of the receiver's characters. - Parameters: - location: The index for which to return attributes. This value must lie within the bounds of the receiver. - range: Upon return, the range over which the attributes and values are the same as those at 'location'. This range isn't necessarily the maximum range covered, and its extent is implementation-dependent. If you need the maximum range, use 'attributesAtIndex:longestEffectiveRange:inRange:'. If you don't need this value, pass 'NULL'. - Returns: The attributes for the character at 'location'.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> attributes_at_index(std::uint64_t location, Range* range) const;
        /**
     * @brief Calls `-[NSAttributedString attributesAtIndex:longestEffectiveRange:inRange:]`.
     * @details Returns the attributes for the character at the specified index and, by reference, the range where the attributes apply. Raises an 'NSRangeException' if 'location' or any part of 'rangeLimit' lies beyond the end of the receiver's characters. If you don't need the range information, it's far more efficient to use 'attributesAtIndex:effectiveRange:' to retrieve the attribute value. - Parameters: - location: The index for which to return attributes. This value must not exceed the bounds of the receiver. - range: If non-'NULL', upon return contains the maximum range over which the attributes and values are the same as those at 'location', clipped to 'rangeLimit'. - rangeLimit: The range over which to search for continuous presence of the attributes at 'location'. This value must not exceed the bounds of the receiver.
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
     * @details Executes the specified block for each range of a particular attribute in the attributed string. If this method is called by an instance of 'NSMutableAttributedString', mutation (deletion, addition, or change) is allowed only if the mutation is within the range provided to the block. After a mutation, the enumeration continues with the range immediately following the processed range, adjusting for any change in length caused by the mutation. - Parameters: - attrName: The name of the attribute to enumerate. - enumerationRange: The range over which the attribute values are enumerated. - opts: The options used by the enumeration. - block: A block to apply to ranges of the specified attribute in the attributed string.
     * @param attr_name Argument converted to the Objective-C parameter of the same role.
     * @param enumeration_range Argument converted to the Objective-C parameter of the same role.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_attribute(const std::string& attr_name, const Range& enumeration_range, AttributedStringEnumerationOptions opts, std::function<void(Object, Range, bool&)> block) const;
        /**
     * @brief Calls `-[NSAttributedString enumerateAttributesInRange:options:usingBlock:]`.
     * @details Executes the specified block for each range of attributes in the attributed string. If this method is called by an instance of 'NSMutableAttributedString', mutation (deletion, addition, or change) is allowed only if the mutation is within the range provided to the block. After a mutation, the enumeration continues with the range immediately following the processed range, adjusting for any change in length caused by the mutation. - Parameters: - enumerationRange: The range over which the attributes are enumerated. - opts: The options used by the enumeration. - block: The block to apply to ranges of attributes in the attributed string.
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
     * @details Returns a Boolean value that indicates whether the attributed string is equal to the specified string. This method performs a character-by-character comparison of the string and its attributes. The character and its attributes must be the same in both strings for the method to return 'YES'. - Parameter other: The attributed string with which to compare the receiver. - Returns: 'YES' if the text and attributes in the current string and 'other' are the same, otherwise 'NO'.
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
     * @details The length of the attributed string.
     * @return The converted Objective-C result.
     */
        std::uint64_t length() const;
        /**
     * @brief Returns the `string` property of `NSAttributedString`.
     * @details The character contents of the receiver as a string.
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
