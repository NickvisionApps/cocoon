#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/paragraph_style.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ParagraphStyle;
    class TextBlock;
    class TextList;
    class TextTab;

    /**
     * @brief C++ handle for the Objective-C class `NSMutableParagraphStyle` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ParagraphStyle.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MutableParagraphStyle mutable_paragraph_style;
     * mutable_paragraph_style.set_alignment(cocoon::TextAlignment::Left);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MutableParagraphStyle mutable_paragraph_style{};
     * mutable_paragraph_style.set_alignment(cocoon::TextAlignment::Left);
     * auto alignment = mutable_paragraph_style.alignment();
     * mutable_paragraph_style.set_allows_default_tightening_for_truncation(true);
     * auto allows_default_tightening_for_truncation = mutable_paragraph_style.allows_default_tightening_for_truncation();
     * mutable_paragraph_style.set_base_writing_direction(cocoon::WritingDirection::Natural);
     * auto base_writing_direction = mutable_paragraph_style.base_writing_direction();
     * mutable_paragraph_style.add_tab_stop(cocoon::TextTab());
     * mutable_paragraph_style.remove_tab_stop(cocoon::TextTab());
     * mutable_paragraph_style.set_paragraph_style(cocoon::ParagraphStyle());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsmutableparagraphstyle
     */
    class MutableParagraphStyle : public ParagraphStyle
    {
    public:
        /// @brief Creates a new `NSMutableParagraphStyle` instance and returns a handle to it.
        explicit MutableParagraphStyle();
        /// @brief Creates a null handle that refers to no native object.
        MutableParagraphStyle(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MutableParagraphStyle(Adopt adopt);
        using ParagraphStyle::alignment;
        using ParagraphStyle::allows_default_tightening_for_truncation;
        using ParagraphStyle::base_writing_direction;
        using ParagraphStyle::default_tab_interval;
        using ParagraphStyle::first_line_head_indent;
        using ParagraphStyle::head_indent;
        using ParagraphStyle::header_level;
        using ParagraphStyle::hyphenation_factor;
        using ParagraphStyle::line_break_mode;
        using ParagraphStyle::line_break_strategy;
        using ParagraphStyle::line_height_multiple;
        using ParagraphStyle::line_spacing;
        using ParagraphStyle::maximum_line_height;
        using ParagraphStyle::minimum_line_height;
        using ParagraphStyle::paragraph_spacing;
        using ParagraphStyle::paragraph_spacing_before;
        using ParagraphStyle::tab_stops;
        using ParagraphStyle::tail_indent;
        using ParagraphStyle::text_blocks;
        using ParagraphStyle::text_lists;
        using ParagraphStyle::tightening_factor_for_truncation;
        using ParagraphStyle::uses_default_hyphenation;
        /**
     * @brief Calls `-[NSMutableParagraphStyle addTabStop:]`.
     * @details Adds the specified tab stop to the paragraph. \#\# See Also - ''tabStops''
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     */
        void add_tab_stop(const TextTab& an_object) const;
        /**
     * @brief Calls `-[NSMutableParagraphStyle removeTabStop:]`.
     * @details Removes the first text tab with a location and type equal to the specified tab stop. \#\# See Also - ''tabStops''
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     */
        void remove_tab_stop(const TextTab& an_object) const;
        /**
     * @brief Calls `-[NSMutableParagraphStyle setParagraphStyle:]`.
     * @details Replaces the subattributes of the paragraph with those in the specified paragraph style object.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     */
        void set_paragraph_style(const ParagraphStyle& obj) const;
        /**
     * @brief Returns the `alignment` property of `NSMutableParagraphStyle`.
     * @details The text alignment of the paragraph.
     * @return The converted Objective-C result.
     */
        TextAlignment alignment() const;
        /**
     * @brief Sets the `alignment` property of `NSMutableParagraphStyle`.
     * @details The text alignment of the paragraph.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alignment(TextAlignment value) const;
        /**
     * @brief Returns the `allowsDefaultTighteningForTruncation` property of `NSMutableParagraphStyle`.
     * @details A Boolean value that indicates whether the system tightens intercharacter spacing before truncating text. When this property is set to \<doc://com.apple.documentation/documentation/swift/true>, the system tries to reduce the space between characters before truncating characters. The system performs this tightening in cases where the text would not otherwise fit in the available space. The maximum amount of tightening performed by the system is dependent on the font, line width, and other factors. The default value of this property is \<doc://com.apple.documentation/documentation/swift/false>.
     * @return The converted Objective-C result.
     */
        bool allows_default_tightening_for_truncation() const;
        /**
     * @brief Sets the `allowsDefaultTighteningForTruncation` property of `NSMutableParagraphStyle`.
     * @details A Boolean value that indicates whether the system tightens intercharacter spacing before truncating text. When this property is set to \<doc://com.apple.documentation/documentation/swift/true>, the system tries to reduce the space between characters before truncating characters. The system performs this tightening in cases where the text would not otherwise fit in the available space. The maximum amount of tightening performed by the system is dependent on the font, line width, and other factors. The default value of this property is \<doc://com.apple.documentation/documentation/swift/false>.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_default_tightening_for_truncation(bool value) const;
        /**
     * @brief Returns the `baseWritingDirection` property of `NSMutableParagraphStyle`.
     * @details The base writing direction for the paragraph. If you specify ''NSWritingDirection/natural'', the consumer of the value must resolve the writing direction based on the paragraph contents using the Unicode Bidi Algorithm.
     * @return The converted Objective-C result.
     */
        WritingDirection base_writing_direction() const;
        /**
     * @brief Sets the `baseWritingDirection` property of `NSMutableParagraphStyle`.
     * @details The base writing direction for the paragraph. If you specify ''NSWritingDirection/natural'', the consumer of the value must resolve the writing direction based on the paragraph contents using the Unicode Bidi Algorithm.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_base_writing_direction(WritingDirection value) const;
        /**
     * @brief Returns the `defaultTabInterval` property of `NSMutableParagraphStyle`.
     * @details A number used as the document's default tab spacing. This property represents the default tab interval in points. The system places tabs after the last specified in ''tabStops'' at integer multiples of this distance (if positive). Default value is '0.0'.
     * @return The converted Objective-C result.
     */
        double default_tab_interval() const;
        /**
     * @brief Sets the `defaultTabInterval` property of `NSMutableParagraphStyle`.
     * @details A number used as the document's default tab spacing. This property represents the default tab interval in points. The system places tabs after the last specified in ''tabStops'' at integer multiples of this distance (if positive). Default value is '0.0'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_tab_interval(double value) const;
        /**
     * @brief Returns the `firstLineHeadIndent` property of `NSMutableParagraphStyle`.
     * @details The indentation of the first line of the paragraph. This property contains the distance (in points) from the leading margin of a text container to the beginning of the paragraph's first line. This value is always nonnegative.
     * @return The converted Objective-C result.
     */
        double first_line_head_indent() const;
        /**
     * @brief Sets the `firstLineHeadIndent` property of `NSMutableParagraphStyle`.
     * @details The indentation of the first line of the paragraph. This property contains the distance (in points) from the leading margin of a text container to the beginning of the paragraph's first line. This value is always nonnegative.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_first_line_head_indent(double value) const;
        /**
     * @brief Returns the `headIndent` property of `NSMutableParagraphStyle`.
     * @details The indentation of the paragraph's lines other than the first. This property contains the distance (in points) from the leading margin of a text container to the beginning of lines other than the first. This value is always nonnegative.
     * @return The converted Objective-C result.
     */
        double head_indent() const;
        /**
     * @brief Sets the `headIndent` property of `NSMutableParagraphStyle`.
     * @details The indentation of the paragraph's lines other than the first. This property contains the distance (in points) from the leading margin of a text container to the beginning of lines other than the first. This value is always nonnegative.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_head_indent(double value) const;
        /**
     * @brief Returns the `headerLevel` property of `NSMutableParagraphStyle`.
     * @details The paragraph's header level for HTML generation. Should be set to '0' (the default value) if the paragraph is not a header, or from 1 through 6 if the paragraph is to be treated as a header.
     * @return The converted Objective-C result.
     */
        std::int64_t header_level() const;
        /**
     * @brief Sets the `headerLevel` property of `NSMutableParagraphStyle`.
     * @details The paragraph's header level for HTML generation. Should be set to '0' (the default value) if the paragraph is not a header, or from 1 through 6 if the paragraph is to be treated as a header.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_header_level(std::int64_t value) const;
        /**
     * @brief Returns the `hyphenationFactor` property of `NSMutableParagraphStyle`.
     * @details The paragraph's threshold for hyphenation. Valid values lie between '0.0' and '1.0' inclusive. The default value is '0.0'. Hyphenation is attempted when the ratio of the text width (as broken without hyphenation) to the width of the line fragment is less than the hyphenation factor. When the paragraph's hyphenation factor is '0.0', the text layout manager's hyphenation factor is used instead. When both are '0.0', hyphenation is disabled. This property detects the user-selected language by examining the first item in 'preferredLanguages'. \#\# See Also - \<doc://com.apple.documentation/documentation/coretext/kCTLanguageAttributeName>
     * @return The converted Objective-C result.
     */
        float hyphenation_factor() const;
        /**
     * @brief Sets the `hyphenationFactor` property of `NSMutableParagraphStyle`.
     * @details The paragraph's threshold for hyphenation. Valid values lie between '0.0' and '1.0' inclusive. The default value is '0.0'. Hyphenation is attempted when the ratio of the text width (as broken without hyphenation) to the width of the line fragment is less than the hyphenation factor. When the paragraph's hyphenation factor is '0.0', the text layout manager's hyphenation factor is used instead. When both are '0.0', hyphenation is disabled. This property detects the user-selected language by examining the first item in 'preferredLanguages'. \#\# See Also - \<doc://com.apple.documentation/documentation/coretext/kCTLanguageAttributeName>
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hyphenation_factor(float value) const;
        /**
     * @brief Returns the `lineBreakMode` property of `NSMutableParagraphStyle`.
     * @details The mode for breaking lines in the paragraph. This property controls how the text system lays out lines that don't fit in its container, such as by truncating with an ellipsis (…) or clipping the text. This is different from ''NSParagraphStyle/LineBreakStrategy'', which controls where the system places line breaks in a paragraph.
     * @return The converted Objective-C result.
     */
        LineBreakMode line_break_mode() const;
        /**
     * @brief Sets the `lineBreakMode` property of `NSMutableParagraphStyle`.
     * @details The mode for breaking lines in the paragraph. This property controls how the text system lays out lines that don't fit in its container, such as by truncating with an ellipsis (…) or clipping the text. This is different from ''NSParagraphStyle/LineBreakStrategy'', which controls where the system places line breaks in a paragraph.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_break_mode(LineBreakMode value) const;
        /**
     * @brief Returns the `lineBreakStrategy` property of `NSMutableParagraphStyle`.
     * @details The strategies that the text system may use to break lines while laying out the paragraph. Line-break strategies are collections of options the system uses to determine where to break lines in a paragraph. This is different from ''NSParagraphStyle/lineBreakMode'', which controls how to lay out lines of text that don't fit in a container. The system ignores this property if the paragraph style's ''NSParagraphStyle/lineBreakMode'' property specifies a mode that doesn't support multiple lines, such as ''NSLineBreakMode/byClipping''. The default value is ''NSLineBreakStrategy/NSLineBreakStrategyNone''.
     * @return The converted Objective-C result.
     */
        LineBreakStrategy line_break_strategy() const;
        /**
     * @brief Sets the `lineBreakStrategy` property of `NSMutableParagraphStyle`.
     * @details The strategies that the text system may use to break lines while laying out the paragraph. Line-break strategies are collections of options the system uses to determine where to break lines in a paragraph. This is different from ''NSParagraphStyle/lineBreakMode'', which controls how to lay out lines of text that don't fit in a container. The system ignores this property if the paragraph style's ''NSParagraphStyle/lineBreakMode'' property specifies a mode that doesn't support multiple lines, such as ''NSLineBreakMode/byClipping''. The default value is ''NSLineBreakStrategy/NSLineBreakStrategyNone''.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_break_strategy(LineBreakStrategy value) const;
        /**
     * @brief Returns the `lineHeightMultiple` property of `NSMutableParagraphStyle`.
     * @details The line height multiple. The natural line height of the receiver is multiplied by this factor (if positive) before being constrained by minimum and maximum line height. The default value of this property is '0.0'.
     * @return The converted Objective-C result.
     */
        double line_height_multiple() const;
        /**
     * @brief Sets the `lineHeightMultiple` property of `NSMutableParagraphStyle`.
     * @details The line height multiple. The natural line height of the receiver is multiplied by this factor (if positive) before being constrained by minimum and maximum line height. The default value of this property is '0.0'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_height_multiple(double value) const;
        /**
     * @brief Returns the `lineSpacing` property of `NSMutableParagraphStyle`.
     * @details The distance in points between the bottom of one line fragment and the top of the next. This value is always nonnegative. This value is included in the line fragment heights in the text layout manager.
     * @return The converted Objective-C result.
     */
        double line_spacing() const;
        /**
     * @brief Sets the `lineSpacing` property of `NSMutableParagraphStyle`.
     * @details The distance in points between the bottom of one line fragment and the top of the next. This value is always nonnegative. This value is included in the line fragment heights in the text layout manager.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_spacing(double value) const;
        /**
     * @brief Returns the `maximumLineHeight` property of `NSMutableParagraphStyle`.
     * @details The paragraph's maximum line height. This property contains the maximum height in points that any line in the receiver will occupy, regardless of the font size or size of any attached graphic. This value is always nonnegative. The default value is '0'. Glyphs and graphics exceeding this height will overlap neighboring lines; however, a maximum height of '0' implies no line height limit. Although this limit applies to the line itself, line spacing adds extra space between adjacent lines.
     * @return The converted Objective-C result.
     */
        double maximum_line_height() const;
        /**
     * @brief Sets the `maximumLineHeight` property of `NSMutableParagraphStyle`.
     * @details The paragraph's maximum line height. This property contains the maximum height in points that any line in the receiver will occupy, regardless of the font size or size of any attached graphic. This value is always nonnegative. The default value is '0'. Glyphs and graphics exceeding this height will overlap neighboring lines; however, a maximum height of '0' implies no line height limit. Although this limit applies to the line itself, line spacing adds extra space between adjacent lines.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_line_height(double value) const;
        /**
     * @brief Returns the `minimumLineHeight` property of `NSMutableParagraphStyle`.
     * @details The paragraph's minimum line height. This property contains the minimum height in points that any line in the receiver will occupy, regardless of the font size or size of any attached graphic. This value must be nonnegative.
     * @return The converted Objective-C result.
     */
        double minimum_line_height() const;
        /**
     * @brief Sets the `minimumLineHeight` property of `NSMutableParagraphStyle`.
     * @details The paragraph's minimum line height. This property contains the minimum height in points that any line in the receiver will occupy, regardless of the font size or size of any attached graphic. This value must be nonnegative.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_line_height(double value) const;
        /**
     * @brief Returns the `paragraphSpacing` property of `NSMutableParagraphStyle`.
     * @details The space after the end of the paragraph. This property contains the space (measured in points) added at the end of the paragraph to separate it from the following paragraph. This value must be nonnegative. The space between paragraphs is determined by adding the previous paragraph's 'paragraphSpacing' and the current paragraph's ''NSMutableParagraphStyle/paragraphSpacingBefore''.
     * @return The converted Objective-C result.
     */
        double paragraph_spacing() const;
        /**
     * @brief Sets the `paragraphSpacing` property of `NSMutableParagraphStyle`.
     * @details The space after the end of the paragraph. This property contains the space (measured in points) added at the end of the paragraph to separate it from the following paragraph. This value must be nonnegative. The space between paragraphs is determined by adding the previous paragraph's 'paragraphSpacing' and the current paragraph's ''NSMutableParagraphStyle/paragraphSpacingBefore''.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_paragraph_spacing(double value) const;
        /**
     * @brief Returns the `paragraphSpacingBefore` property of `NSMutableParagraphStyle`.
     * @details The distance between the paragraph's top and the beginning of its text content. This property contains the space (measured in points) between the paragraph's top and the beginning of its text content. The default value of this property is '0.0'.
     * @return The converted Objective-C result.
     */
        double paragraph_spacing_before() const;
        /**
     * @brief Sets the `paragraphSpacingBefore` property of `NSMutableParagraphStyle`.
     * @details The distance between the paragraph's top and the beginning of its text content. This property contains the space (measured in points) between the paragraph's top and the beginning of its text content. The default value of this property is '0.0'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_paragraph_spacing_before(double value) const;
        /**
     * @brief Returns the `tabStops` property of `NSMutableParagraphStyle`.
     * @details The text tab objects that represent the paragraph's tab stops. The ''NSTextTab'' objects, sorted by location, define the tab stops for the paragraph style. The default value is an array of 12 left-aligned tabs at 28-point intervals.
     * @return The converted Objective-C result.
     */
        std::vector<TextTab> tab_stops() const;
        /**
     * @brief Sets the `tabStops` property of `NSMutableParagraphStyle`.
     * @details The text tab objects that represent the paragraph's tab stops. The ''NSTextTab'' objects, sorted by location, define the tab stops for the paragraph style. The default value is an array of 12 left-aligned tabs at 28-point intervals.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tab_stops(const std::vector<TextTab>& value) const;
        /**
     * @brief Returns the `tailIndent` property of `NSMutableParagraphStyle`.
     * @details The trailing indentation of the paragraph. If positive, this value is the distance from the leading margin (for example, the left margin in left-to-right text). If '0' or negative, it's the distance from the trailing margin. For example, a paragraph style designed to fit exactly in a 2-inch wide container has a head indent of '0.0' and a tail indent of '0.0'. One designed to fit with a quarter-inch margin has a head indent of '0.25' and a tail indent of '–0.25'.
     * @return The converted Objective-C result.
     */
        double tail_indent() const;
        /**
     * @brief Sets the `tailIndent` property of `NSMutableParagraphStyle`.
     * @details The trailing indentation of the paragraph. If positive, this value is the distance from the leading margin (for example, the left margin in left-to-right text). If '0' or negative, it's the distance from the trailing margin. For example, a paragraph style designed to fit exactly in a 2-inch wide container has a head indent of '0.0' and a tail indent of '0.0'. One designed to fit with a quarter-inch margin has a head indent of '0.25' and a tail indent of '–0.25'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tail_indent(double value) const;
        /**
     * @brief Returns the `textBlocks` property of `NSMutableParagraphStyle`.
     * @details The text blocks that contain the paragraph.
     * @return The converted Objective-C result.
     */
        std::vector<TextBlock> text_blocks() const;
        /**
     * @brief Sets the `textBlocks` property of `NSMutableParagraphStyle`.
     * @details The text blocks that contain the paragraph.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_blocks(const std::vector<TextBlock>& value) const;
        /**
     * @brief Returns the `textLists` property of `NSMutableParagraphStyle`.
     * @details The text lists that contain the paragraph.
     * @return The converted Objective-C result.
     */
        std::vector<TextList> text_lists() const;
        /**
     * @brief Sets the `textLists` property of `NSMutableParagraphStyle`.
     * @details The text lists that contain the paragraph.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_lists(const std::vector<TextList>& value) const;
        /**
     * @brief Returns the `tighteningFactorForTruncation` property of `NSMutableParagraphStyle`.
     * @details The threshold for using tightening as an alternative to truncation. When the line break mode specifies truncation, the text system will attempt to tighten inter-character spacing as an alternative to truncation, provided that the ratio of the text width to the line fragment width does not exceed '1.0 + tighteningFactorForTruncation'. Otherwise the text will be truncated at a location determined by the line break mode. The default value is '0.0' for apps linked against 10.11 and later SDK. This property is ignored when ''allowsDefaultTighteningForTruncation'' is 'true'. Explicitly setting this property to '0.0' has a side effect of also setting ''allowsDefaultTighteningForTruncation'' to 'false'.
     * @return The converted Objective-C result.
     */
        float tightening_factor_for_truncation() const;
        /**
     * @brief Sets the `tighteningFactorForTruncation` property of `NSMutableParagraphStyle`.
     * @details The threshold for using tightening as an alternative to truncation. When the line break mode specifies truncation, the text system will attempt to tighten inter-character spacing as an alternative to truncation, provided that the ratio of the text width to the line fragment width does not exceed '1.0 + tighteningFactorForTruncation'. Otherwise the text will be truncated at a location determined by the line break mode. The default value is '0.0' for apps linked against 10.11 and later SDK. This property is ignored when ''allowsDefaultTighteningForTruncation'' is 'true'. Explicitly setting this property to '0.0' has a side effect of also setting ''allowsDefaultTighteningForTruncation'' to 'false'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tightening_factor_for_truncation(float value) const;
        /**
     * @brief Returns the `usesDefaultHyphenation` property of `NSMutableParagraphStyle`.
     * @details A Boolean value that indicates whether the paragraph style uses the system hyphenation settings. The system determines the exact hyphenation logic dynamically by examining the layout context such as language, platform, etc. When 'true', it affects the return value from ''hyphenationFactor'' when the property is set to '0.0'.
     * @return The converted Objective-C result.
     */
        bool uses_default_hyphenation() const;
        /**
     * @brief Sets the `usesDefaultHyphenation` property of `NSMutableParagraphStyle`.
     * @details A Boolean value that indicates whether the paragraph style uses the system hyphenation settings. The system determines the exact hyphenation logic dynamically by examining the layout context such as language, platform, etc. When 'true', it affects the return value from ''hyphenationFactor'' when the property is set to '0.0'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_default_hyphenation(bool value) const;
    };
}
