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
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void add_attribute(const std::string& name, const Object& value, const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString addAttributes:range:]`.
     * @param attrs Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void add_attributes(const std::map<std::string, Object>& attrs, const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString appendAttributedString:]`.
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
     */
        void begin_editing() const;
        /**
     * @brief Calls `-[NSMutableAttributedString deleteCharactersInRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void delete_characters_in_range(const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString endEditing]`.
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
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void remove_attribute(const std::string& name, const Range& range) const;
        /**
     * @brief Calls `-[NSMutableAttributedString replaceCharactersInRange:withAttributedString:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param attr_string Argument converted to the Objective-C parameter of the same role.
     */
        void replace_characters_in_range(const Range& range, const AttributedString& attr_string) const;
        /**
     * @brief Calls `-[NSMutableAttributedString replaceCharactersInRange:withString:]`.
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
     * @param attr_string Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_string(const AttributedString& attr_string) const;
        /**
     * @brief Calls `-[NSMutableAttributedString setAttributes:range:]`.
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
     * @return The converted Objective-C result.
     */
        std::string mutable_string() const;
    };
}
