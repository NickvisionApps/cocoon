#pragma once

#include "generated/attributed_string.h"
#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSMutableAttributedString` (Foundation).
     * @details A mutable string with associated attributes (such as visual style, hyperlinks, or accessibility data) for portions of its text. The 'NSMutableAttributedString' class declares additional methods for mutating the content of an attributed string. You can add and remove characters (raw strings) and attributes separately or together as attributed strings. See the class description for ''NSAttributedString'' for more information about attributed strings. 'NSMutableAttributedString' adds two primitive methods to those of 'NSAttributedString'. These primitive methods provide the basis for all the other methods in its class. The primitive ''replaceCharacters(in:with:)-6oq9r'' method replaces a range of characters with those from a string, leaving all attribute information outside that range intact. The primitive ''setAttributes(:range:)'' method sets attributes and values for a given range of characters, replacing any previous attributes and values for that range. In macOS, AppKit also uses \<doc://com.apple.documentation/documentation/appkit/nsparagraphstyle> and its subclass \<doc://com.apple.documentation/documentation/appkit/nsmutableparagraphstyle> to encapsulate the paragraph or ruler attributes used by the 'NSAttributedString' classes. Note that the default font for 'NSAttributedString' objects is Helvetica 12-point, which may differ from the macOS system font, so you may wish to create the string with non-default attributes suitable for your application using, for example, ''NSAttributedString/init(string:attributes:)''. > iOS Note: > In iOS, this class is used primarily in conjunction with the Core Text framework. 'NSMutableAttributedString' is "toll-free bridged" with its Core Foundation counterpart, \<doc://com.apple.documentation/documentation/corefoundation/cfmutableattributedstring>. See [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2) for more information.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref AttributedString.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MutableAttributedString mutable_attributed_string;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MutableAttributedString mutable_attributed_string{};
     * mutable_attributed_string.append_attributed_string(cocoon::AttributedString());
     * mutable_attributed_string.begin_editing();
     * mutable_attributed_string.end_editing();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmutableattributedstring
     */
    class MutableAttributedString : public AttributedString
    {
    public:
        /// @brief Creates a new `NSMutableAttributedString` instance and returns a handle to it.
        explicit MutableAttributedString();
        /// @brief Creates a null handle that refers to no native object.
        MutableAttributedString(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MutableAttributedString(Adopt adopt);
        /**
     * @brief Calls `-[NSMutableAttributedString addAttribute:value:range:]`.
     * @details Adds an attribute with the given name and value to the characters in the specified range. You may assign any 'name'/'value' pair you wish to a range of characters. Raises an 'NSInvalidArgumentException' if 'name' or 'value' is 'nil' and an 'NSRangeException' if any part of 'range' lies beyond the end of the receiver's characters. - Parameters: - name: A string specifying the attribute name. - value: The attribute value associated with 'name'. - range: The range of characters to which the specified attribute/value pair applies.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void add_attribute(const std::string& name, const Object& value, const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString addAttributes:range:]`.
     * @details Adds the given collection of attributes to the characters in the specified range. You may assign any name/value pair you wish to a range of characters. Raises an 'NSInvalidArgumentException' if 'attrs' is 'nil' and an 'NSRangeException' if any part of 'range' lies beyond the end of the receiver's characters. - Parameters: - attrs: A dictionary containing the attributes to add. - range: The range of characters to which the specified attributes apply.
     * @param attrs Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void add_attributes(const std::map<std::string, Object>& attrs, const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString appendAttributedString:]`.
     * @details Adds the characters and attributes of a given attributed string to the end of the receiver. - Parameter attrString: The string whose characters and attributes are added.
     * @param attr_string Argument converted to the Objective-C parameter of the same role.
     */
        void append_attributed_string(const AttributedString& attr_string) const;
        /**
     * @brief Calls `-[NSMutableAttributedString applyFontTraits:range:]`.
     * @param trait_mask Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void apply_font_traits(FontTraitMask trait_mask, const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString beginEditing]`.
     * @details Begins the buffering of changes to the string's characters and attributes. Override this method in a subclass to buffer or optimize a series of changes to the string's characters or attributes. The string continues to buffer text until you call 'endEditing', at which time it consolidates the changes and notifies observers. You can nest pairs of 'beginEditing' and 'endEditing' messages.
     */
        void begin_editing() const;
        /**
     * @brief Calls `-[NSMutableAttributedString deleteCharactersInRange:]`.
     * @details Deletes the characters in the given range along with their associated attributes. Raises an 'NSRangeException' if any part of 'range' lies beyond the end of the receiver's characters. - Parameter range: A range specifying the characters to delete.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void delete_characters_in_range(const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString endEditing]`.
     * @details Ends the buffering of changes to the string's characters and attributes. Override this method in a subclass to consolidate changes made since a previous call to 'beginEditing'. When you call this method, the string notifies observers of the changes. The default implementation of this method does nothing.
     */
        void end_editing() const;
        /**
     * @brief Calls `-[NSMutableAttributedString fixAttachmentAttributeInRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void fix_attachment_attribute_in_range(const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString fixAttributesInRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void fix_attributes_in_range(const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString fixFontAttributeInRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void fix_font_attribute_in_range(const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString fixParagraphStyleAttributeInRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void fix_paragraph_style_attribute_in_range(const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString insertAttributedString:atIndex:]`.
     * @details Inserts the characters and attributes of the given attributed string into the receiver at the given index. The new characters and attributes begin at the given index and the existing characters and attributes from the index to the end of the receiver are shifted by the length of the attributed string. Raises an 'NSRangeException' if 'loc' lies beyond the end of the receiver's characters. - Parameters: - attrString: The string whose characters and attributes are inserted. - loc: The index at which the characters and attributes are inserted.
     * @param attr_string Argument converted to the Objective-C parameter of the same role.
     * @param loc Argument converted to the Objective-C parameter of the same role.
     */
        void insert_attributed_string(const AttributedString& attr_string, std::uint64_t loc) const;
        /**
     * @brief Calls `-[NSMutableAttributedString readFromData:options:documentAttributes:error:]`.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param dict Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool read_from_data(const std::vector<std::uint8_t>& data, const std::map<std::string, Object>& opts, std::map<std::string, Object>& dict) const;
        /**
     * @brief Calls `-[NSMutableAttributedString readFromURL:options:documentAttributes:error:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param dict Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool read_from_url(const URL& url, const std::map<std::string, Object>& opts, std::map<std::string, Object>& dict) const;
        /**
     * @brief Calls `-[NSMutableAttributedString removeAttribute:range:]`.
     * @details Removes the named attribute from the characters in the specified range. Raises an 'NSRangeException' if any part of 'range' lies beyond the end of the receiver's characters. - Parameters: - name: A string specifying the attribute name to remove. - range: The range of characters from which the specified attribute is removed.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void remove_attribute(const std::string& name, const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString replaceCharactersInRange:withAttributedString:]`.
     * @details Replaces the characters and attributes in a given range with the characters and attributes of the given attributed string. Raises an 'NSRangeException' if any part of 'range' lies beyond the end of the receiver's characters. - Parameters: - range: The range of characters and attributes replaced. - attrString: The attributed string whose characters and attributes replace those in the specified range.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param attr_string Argument converted to the Objective-C parameter of the same role.
     */
        void replace_characters_in_range(const Range& range, const AttributedString& attr_string) const;
        /**
     * @brief Calls `-[NSMutableAttributedString replaceCharactersInRange:withString:]`.
     * @details Replaces the characters in the given range with the characters of the given string. The new characters inherit the attributes of the first replaced character from 'range'. Where the length of 'range' is 0, the new characters inherit the attributes of the character preceding 'range' if it has any, otherwise of the character following 'range'. Raises an 'NSRangeException' if any part of 'range' lies beyond the end of the receiver's characters. - Parameters: - range: A range specifying the characters to replace. - str: A string specifying the characters to replace those in 'range'.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param str Argument converted to the Objective-C parameter of the same role.
     */
        void replace_characters_in_range(const Range& range, const std::string& str) const;
        /**
     * @brief Calls `-[NSMutableAttributedString setAlignment:range:]`.
     * @param alignment Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void set_alignment(TextAlignment alignment, const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString setAttributedString:]`.
     * @details Replaces the receiver's entire contents with the characters and attributes of the given attributed string. - Parameter attrString: The attributed string whose characters and attributes replace those in the receiver.
     * @param attr_string Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_string(const AttributedString& attr_string) const;
        /**
     * @brief Calls `-[NSMutableAttributedString setAttributes:range:]`.
     * @details Sets the attributes for the characters in the specified range to the specified attributes. These new attributes replace any attributes previously associated with the characters in 'range'. Raises an 'NSRangeException' if any part of 'range' lies beyond the end of the receiver's characters. - Parameters: - attrs: A dictionary containing the attributes to set. - range: The range of characters whose attributes are set.
     * @param attrs Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributes(const std::map<std::string, Object>& attrs, const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString setBaseWritingDirection:range:]`.
     * @param writing_direction Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void set_base_writing_direction(WritingDirection writing_direction, const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString subscriptRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void subscript_range(const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString superscriptRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void superscript_range(const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString unscriptRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void unscript_range(const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString updateAttachmentsFromPath:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     */
        void update_attachments_from_path(const std::string& path) const;
        /**
     * @brief Returns the `mutableString` property of `NSMutableAttributedString`.
     * @details The character contents of the receiver as a mutable string object. The receiver tracks changes to this string and keeps its attribute mappings up to date.
     * @return The converted Objective-C result.
     */
        std::string mutable_string() const;
    };
}
