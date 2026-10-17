#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class TextBlock;
    class TextList;
    class TextTab;

    /**
     * @brief C++ handle for the Objective-C class `NSParagraphStyle` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ParagraphStyle paragraph_style;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsparagraphstyle
     */
    class ParagraphStyle : public Object
    {
    public:
        /// @brief Creates a new `NSParagraphStyle` instance and returns a handle to it.
        explicit ParagraphStyle();
        /// @brief Creates a null handle that refers to no native object.
        ParagraphStyle(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ParagraphStyle(Adopt adopt);
        /**
     * @brief Calls `+[NSParagraphStyle defaultWritingDirectionForLanguage:]`.
     * @details Returns the default writing direction for the specified language. - Parameters: - languageName: The language specified in ISO language region format. Can be 'nil' to return a default writing direction derived from the user's defaults database. - Returns: The default writing direction.
     * @param language_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static WritingDirection default_writing_direction_for_language(const std::string& language_name);
        /**
     * @brief Returns the `alignment` property of `NSParagraphStyle`.
     * @details The text alignment of the paragraph.
     * @return The converted Objective-C result.
     */
        TextAlignment alignment() const;
        /**
     * @brief Returns the `allowsDefaultTighteningForTruncation` property of `NSParagraphStyle`.
     * @details A Boolean value that indicates whether the system tightens character spacing before truncating text. When this property is \<doc://com.apple.documentation/documentation/swift/true>, the system tries to reduce the space between characters before truncating characters. The system performs this tightening in cases where the text wouldn't otherwise fit in the available space. The maximum amount of tightening performed by the system is dependent on the font, line width, and other factors. The default value of this property is \<doc://com.apple.documentation/documentation/swift/false>.
     * @return The converted Objective-C result.
     */
        bool allows_default_tightening_for_truncation() const;
        /**
     * @brief Returns the `baseWritingDirection` property of `NSParagraphStyle`.
     * @details The base writing direction for the paragraph. If the value of this property is ''NSWritingDirection/natural'', the consumer of the value must resolve the writing direction based on the paragraph contents using the Unicode Bidi Algorithm.
     * @return The converted Objective-C result.
     */
        WritingDirection base_writing_direction() const;
        /**
     * @brief Returns the `defaultParagraphStyle` property of `NSParagraphStyle`.
     * @details The default paragraph style. The default paragraph style has the following default values: | Subattribute | Default | |---|---| | Alignment | 'NSNaturalTextAlignment' | | Tab stops | 12 left-aligned tabs, spaced by '28.0' points | | Line break mode | 'NSLineBreakByWordWrapping' | | All others | '0.0' | See individual method descriptions for explanations of each subattribute.
     * @return The converted Objective-C result.
     */
        static ParagraphStyle default_paragraph_style();
        /**
     * @brief Returns the `defaultTabInterval` property of `NSParagraphStyle`.
     * @details The documentwide default tab interval. This property represents the default tab interval in points. Tabs after the last specified in ''NSParagraphStyle/tabStops'' are placed at integer multiples of this distance (if positive). Default value is '0.0'.
     * @return The converted Objective-C result.
     */
        double default_tab_interval() const;
        /**
     * @brief Returns the `firstLineHeadIndent` property of `NSParagraphStyle`.
     * @details The indentation of the first line of the paragraph. This property contains the distance (in points) from the leading margin of a text container to the beginning of the paragraph's first line. This value is always nonnegative.
     * @return The converted Objective-C result.
     */
        double first_line_head_indent() const;
        /**
     * @brief Returns the `headIndent` property of `NSParagraphStyle`.
     * @details The indentation of the paragraph's lines other than the first. This property contains the distance (in points) from the leading margin of a text container to the beginning of lines other than the first. This value is always nonnegative.
     * @return The converted Objective-C result.
     */
        double head_indent() const;
        /**
     * @brief Returns the `headerLevel` property of `NSParagraphStyle`.
     * @details The paragraph's header level for HTML generation. Should be set to '0' (the default value) if the paragraph is not a header, or from 1 through 6 if the paragraph is to be treated as a header.
     * @return The converted Objective-C result.
     */
        std::int64_t header_level() const;
        /**
     * @brief Returns the `hyphenationFactor` property of `NSParagraphStyle`.
     * @details The paragraph's threshold for hyphenation. The system attempts hyphenation when the ratio of the text width (as broken without hyphenation) to the width of the line fragment is less than the hyphenation factor. When the paragraph's hyphenation factor is '0.0', the system uses the text layout manager's hyphenation factor instead. The system disables hyphenation when both are '0.0'. This property detects the user-selected language by examining the first item in \<doc://com.apple.documentation/documentation/foundation/nslocale/1415614-preferredlanguages>. \#\# See Also - \<doc://com.apple.documentation/documentation/coretext/kCTLanguageAttributeName>
     * @return The converted Objective-C result.
     */
        float hyphenation_factor() const;
        /**
     * @brief Returns the `lineBreakMode` property of `NSParagraphStyle`.
     * @details The mode for breaking lines in the paragraph that don't fit within a container. This property controls how the text system lays out lines that don't fit in its container, such as by truncating with an ellipsis (…) or clipping the text. This is different from ''NSParagraphStyle/LineBreakStrategy'', which controls where the system places line breaks in a paragraph.
     * @return The converted Objective-C result.
     */
        LineBreakMode line_break_mode() const;
        /**
     * @brief Returns the `lineBreakStrategy` property of `NSParagraphStyle`.
     * @details The strategy for breaking lines while laying out paragraphs. Line-break strategies are collections of options the system uses to determine where to break lines in a paragraph. This is different from ''NSParagraphStyle/lineBreakMode'', which controls how to lay out lines of text that don't fit in a container. The system ignores this property if the paragraph style's ''NSParagraphStyle/lineBreakMode'' property specifies a mode that doesn't support multiple lines, such as ''NSLineBreakMode/byClipping''. The default value is ''NSLineBreakStrategy/NSLineBreakStrategyNone''.
     * @return The converted Objective-C result.
     */
        LineBreakStrategy line_break_strategy() const;
        /**
     * @brief Returns the `lineHeightMultiple` property of `NSParagraphStyle`.
     * @details The line height multiple. The framework multiplies the natural line height of the receiver by this factor (if positive), and constrains the resulting value by the minimum and maximum line height. The default value of this property is '0.0'.
     * @return The converted Objective-C result.
     */
        double line_height_multiple() const;
        /**
     * @brief Returns the `lineSpacing` property of `NSParagraphStyle`.
     * @details The distance in points between the bottom of one line fragment and the top of the next. This value is always nonnegative. The text layout manager uses this value in the line fragment height.
     * @return The converted Objective-C result.
     */
        double line_spacing() const;
        /**
     * @brief Returns the `maximumLineHeight` property of `NSParagraphStyle`.
     * @details The paragraph's maximum line height. This property contains the maximum height in points that any line in the receiver occupies, regardless of the font size or size of any attached graphic. This value is always nonnegative. The default value is '0'. Glyphs and graphics exceeding this height overlap neighboring lines; however, a maximum height of '0' implies no line height limit. Although this limit applies to the line itself, line spacing adds extra space between adjacent lines.
     * @return The converted Objective-C result.
     */
        double maximum_line_height() const;
        /**
     * @brief Returns the `minimumLineHeight` property of `NSParagraphStyle`.
     * @details The paragraph's minimum line height. This property contains the minimum height in points that any line in the receiver occupies, regardless of the font size or size of any attached graphic. This value is always nonnegative.
     * @return The converted Objective-C result.
     */
        double minimum_line_height() const;
        /**
     * @brief Returns the `paragraphSpacing` property of `NSParagraphStyle`.
     * @details Distance between the bottom of this paragraph and top of next. This property contains the space (measured in points) between paragraphs. This value is always nonnegative. The framework determines the space between paragraphs by adding the previous paragraph's 'paragraphSpacing' and the current paragraph's ''NSParagraphStyle/paragraphSpacingBefore''.
     * @return The converted Objective-C result.
     */
        double paragraph_spacing() const;
        /**
     * @brief Returns the `paragraphSpacingBefore` property of `NSParagraphStyle`.
     * @details The distance between the paragraph's top and the beginning of its text content. This property contains the space (measured in points) between the current and previous paragraphs. The default value of this property is '0.0'.
     * @return The converted Objective-C result.
     */
        double paragraph_spacing_before() const;
        /**
     * @brief Returns the `tabStops` property of `NSParagraphStyle`.
     * @details The text tab objects that represent the paragraph's tab stops. The ''NSTextTab'' objects, sorted by location, define the tab stops for the paragraph style. The default value is an array of 12 left-aligned tabs at 28-point intervals.
     * @return The converted Objective-C result.
     */
        std::vector<TextTab> tab_stops() const;
        /**
     * @brief Returns the `tailIndent` property of `NSParagraphStyle`.
     * @details The trailing indentation of the paragraph. If positive, this value is the distance from the leading margin (for example, the left margin in left-to-right text). If '0' or negative, it's the distance from the trailing margin. For example, a paragraph style designed to fit exactly in a two-inch wide container has a head indent of '0.0' and a tail indent of '0.0'. One designed to fit with a quarter-inch margin has a head indent of '0.25' and a tail indent of '–0.25'.
     * @return The converted Objective-C result.
     */
        double tail_indent() const;
        /**
     * @brief Returns the `textBlocks` property of `NSParagraphStyle`.
     * @details The text blocks that contain the paragraph, nested from outermost to innermost.
     * @return The converted Objective-C result.
     */
        std::vector<TextBlock> text_blocks() const;
        /**
     * @brief Returns the `textLists` property of `NSParagraphStyle`.
     * @details The text lists that contain the paragraph, nested from outermost to innermost.
     * @return The converted Objective-C result.
     */
        std::vector<TextList> text_lists() const;
        /**
     * @brief Returns the `tighteningFactorForTruncation` property of `NSParagraphStyle`.
     * @details The threshold for using tightening as an alternative to truncation. When the line break mode specifies truncation, the text system will attempt to tighten inter-character spacing as an alternative to truncation, provided that the ratio of the text width to the line fragment width does not exceed '1.0 + tighteningFactorForTruncation'. Otherwise the text will be truncated at a location determined by the line break mode. The default value is '0.0' for apps linked against 10.11 and later SDK. This property is ignored when ''allowsDefaultTighteningForTruncation'' is 'true'. Explicitly setting this property to '0.0' has a side effect of also setting ''allowsDefaultTighteningForTruncation'' to 'false'.
     * @return The converted Objective-C result.
     */
        float tightening_factor_for_truncation() const;
        /**
     * @brief Returns the `usesDefaultHyphenation` property of `NSParagraphStyle`.
     * @details A Boolean value that indicates whether the paragraph style uses the system hyphenation settings. The system determines the exact hyphenation logic dynamically by examining the layout context such as language, platform, etc. When 'true', it affects the return value from ''hyphenationFactor'' when the property is set to '0.0'.
     * @return The converted Objective-C result.
     */
        bool uses_default_hyphenation() const;
    };
}
