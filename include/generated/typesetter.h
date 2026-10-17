#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Font;
    class LayoutManager;
    class ParagraphStyle;
    class TextContainer;
    class TextTab;

    /**
     * @brief C++ handle for the Objective-C class `NSTypesetter` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Typesetter typesetter;
     * typesetter.set_attributed_string(cocoon::AttributedString());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Typesetter typesetter{};
     * typesetter.set_attributed_string(cocoon::AttributedString());
     * auto attributed_string = typesetter.attributed_string();
     * typesetter.set_bidi_processing_enabled(true);
     * auto bidi_processing_enabled = typesetter.bidi_processing_enabled();
     * typesetter.set_hyphenation_factor(1);
     * auto hyphenation_factor = typesetter.hyphenation_factor();
     * typesetter.action_for_control_character_at_index(1);
     * typesetter.baseline_offset_in_layout_manager(cocoon::LayoutManager(), 1);
     * typesetter.begin_line_with_glyph_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstypesetter
     */
    class Typesetter : public Object
    {
    public:
        /// @brief Creates a new `NSTypesetter` instance and returns a handle to it.
        explicit Typesetter();
        /// @brief Creates a null handle that refers to no native object.
        Typesetter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Typesetter(Adopt adopt);
        /**
     * @brief Calls `-[NSTypesetter actionForControlCharacterAtIndex:]`.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TypesetterControlCharacterAction action_for_control_character_at_index(std::uint64_t char_index) const;
        /**
     * @brief Calls `-[NSTypesetter baselineOffsetInLayoutManager:glyphIndex:]`.
     * @param layout_mgr Argument converted to the Objective-C parameter of the same role.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double baseline_offset_in_layout_manager(const LayoutManager& layout_mgr, std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSTypesetter beginLineWithGlyphAtIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     */
        void begin_line_with_glyph_at_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSTypesetter beginParagraph]`.
     * @details Layout parameter setup
     */
        void begin_paragraph() const;
        /**
     * @brief Calls `-[NSTypesetter boundingBoxForControlGlyphAtIndex:forTextContainer:proposedLineFragment:glyphPosition:characterIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param text_container Argument converted to the Objective-C parameter of the same role.
     * @param proposed_rect Argument converted to the Objective-C parameter of the same role.
     * @param glyph_position Argument converted to the Objective-C parameter of the same role.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect bounding_box_for_control_glyph_at_index(std::uint64_t glyph_index, const TextContainer& text_container, const Rect& proposed_rect, const Point& glyph_position, std::uint64_t char_index) const;
        /**
     * @brief Calls `-[NSTypesetter characterRangeForGlyphRange:actualGlyphRange:]`.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param actual_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range character_range_for_glyph_range(const Range& glyph_range, Range* actual_glyph_range) const;
        /**
     * @brief Calls `-[NSTypesetter endLineWithGlyphRange:]`.
     * @param line_glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void end_line_with_glyph_range(const Range& line_glyph_range) const;
        /**
     * @brief Calls `-[NSTypesetter endParagraph]`.
     */
        void end_paragraph() const;
        /**
     * @brief Calls `-[NSTypesetter getLineFragmentRect:usedRect:forParagraphSeparatorGlyphRange:atProposedOrigin:]`.
     * @details This method calculates the line fragment rect/line fragment used rect for blank lines. theParagraphSeparatorGlyphRange with length == 0 indicates extra line fragment.
     * @param line_fragment_rect Argument converted to the Objective-C parameter of the same role.
     * @param line_fragment_used_rect Argument converted to the Objective-C parameter of the same role.
     * @param paragraph_separator_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param line_origin Argument converted to the Objective-C parameter of the same role.
     */
        void get_line_fragment_rect(Rect* line_fragment_rect, Rect* line_fragment_used_rect, const Range& paragraph_separator_glyph_range, const Point& line_origin) const;
        /**
     * @brief Calls `-[NSTypesetter getLineFragmentRect:usedRect:remainingRect:forStartingGlyphAtIndex:proposedRect:lineSpacing:paragraphSpacingBefore:paragraphSpacingAfter:]`.
     * @details Calculates line fragment rect, line fragment used rect, and remaining rect for a line fragment starting at glyph index startingGlyphIndex with proposedRect. The height is determined using lineSpacing, paragraphSpacingBefore, and paragraphSpacingAfter as well as proposedRect. The width for lineFragmentUsedRect is set to the lineFragmentRect width. In the standard implementation, paragraph spacing is included in the line fragment rect but not the line fragment used rect; line spacing is included in both.
     * @param line_fragment_rect Argument converted to the Objective-C parameter of the same role.
     * @param line_fragment_used_rect Argument converted to the Objective-C parameter of the same role.
     * @param remaining_rect Argument converted to the Objective-C parameter of the same role.
     * @param starting_glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param proposed_rect Argument converted to the Objective-C parameter of the same role.
     * @param line_spacing Argument converted to the Objective-C parameter of the same role.
     * @param paragraph_spacing_before Argument converted to the Objective-C parameter of the same role.
     * @param paragraph_spacing_after Argument converted to the Objective-C parameter of the same role.
     */
        void get_line_fragment_rect(Rect* line_fragment_rect, Rect* line_fragment_used_rect, Rect* remaining_rect, std::uint64_t starting_glyph_index, const Rect& proposed_rect, double line_spacing, double paragraph_spacing_before, double paragraph_spacing_after) const;
        /**
     * @brief Calls `-[NSTypesetter glyphRangeForCharacterRange:actualCharacterRange:]`.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     * @param actual_char_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range glyph_range_for_character_range(const Range& char_range, Range* actual_char_range) const;
        /**
     * @brief Calls `-[NSTypesetter hyphenCharacterForGlyphAtIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        unsigned int hyphen_character_for_glyph_at_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSTypesetter hyphenationFactorForGlyphAtIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        float hyphenation_factor_for_glyph_at_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSTypesetter layoutCharactersInRange:forLayoutManager:maximumNumberOfLineFragments:]`.
     * @details Layouts characters in characterRange for layoutManager. The method returns the actual character range that the receiving NSTypesetter processed. The layout process can be interrupted when the number of line fragments exceeds maxNumLines. Specify NSUIntegerMax for unlimited number of line fragments.
     * @param character_range Argument converted to the Objective-C parameter of the same role.
     * @param layout_manager Argument converted to the Objective-C parameter of the same role.
     * @param max_num_lines Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range layout_characters_in_range(const Range& character_range, const LayoutManager& layout_manager, std::uint64_t max_num_lines) const;
        /**
     * @brief Calls `-[NSTypesetter layoutGlyphsInLayoutManager:startingAtGlyphIndex:maxNumberOfLineFragments:nextGlyphIndex:]`.
     * @details Actually lay out glyphs starting at the given index. The given number of line fragments will be generated as long as the NSGlyphStorage doesn't run out of glyphs. nextGlyph will be set to the index of the next glyph that needs to be laid out. New applications should use -layoutCharactersInRange:forLayoutManager:maximumNumberOfLineFragments: instead.
     * @param layout_manager Argument converted to the Objective-C parameter of the same role.
     * @param start_glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param max_num_lines Argument converted to the Objective-C parameter of the same role.
     * @param next_glyph Argument converted to the Objective-C parameter of the same role.
     */
        void layout_glyphs_in_layout_manager(const LayoutManager& layout_manager, std::uint64_t start_glyph_index, std::uint64_t max_num_lines, std::uint64_t* next_glyph) const;
        /**
     * @brief Calls `-[NSTypesetter layoutParagraphAtPoint:]`.
     * @details lineFragmentOrigin specifies the upper-left corner of line fragment rect. On return, set to the next origin. The method returns the next glyph index. Usually the index right after paragraph separator but can be inside the paragraph range (i.e. text container exhaustion). Concrete subclasses must implement this method. A concrete implementation must invoke -beginParagraph, -endParagraph, -beginLineWithGlyphAtIndex: and -endLineWithGlyphRange:.
     * @param line_fragment_origin Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t layout_paragraph_at_point(Point* line_fragment_origin) const;
        /**
     * @brief Calls `-[NSTypesetter lineSpacingAfterGlyphAtIndex:withProposedLineFragmentRect:]`.
     * @details Line/paragraph spacing
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double line_spacing_after_glyph_at_index(std::uint64_t glyph_index, const Rect& rect) const;
        /**
     * @brief Calls `-[NSTypesetter paragraphSpacingAfterGlyphAtIndex:withProposedLineFragmentRect:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double paragraph_spacing_after_glyph_at_index(std::uint64_t glyph_index, const Rect& rect) const;
        /**
     * @brief Calls `-[NSTypesetter paragraphSpacingBeforeGlyphAtIndex:withProposedLineFragmentRect:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double paragraph_spacing_before_glyph_at_index(std::uint64_t glyph_index, const Rect& rect) const;
        /**
     * @brief Calls `+[NSTypesetter printingAdjustmentInLayoutManager:forNominallySpacedGlyphRange:packedGlyphs:count:]`.
     * @details Returns the offset to be applied to the glyph in question when printing.
     * @param layout_mgr Argument converted to the Objective-C parameter of the same role.
     * @param nominally_spaced_glyphs_range Argument converted to the Objective-C parameter of the same role.
     * @param packed_glyphs Argument converted to the Objective-C parameter of the same role.
     * @param packed_glyphs_count Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Size printing_adjustment_in_layout_manager(const LayoutManager& layout_mgr, const Range& nominally_spaced_glyphs_range, const std::uint8_t* packed_glyphs, std::uint64_t packed_glyphs_count);
        /**
     * @brief Calls `-[NSTypesetter setAttachmentSize:forGlyphRange:]`.
     * @param attachment_size Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_attachment_size(const Size& attachment_size, const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSTypesetter setBidiLevels:forGlyphRange:]`.
     * @param levels Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_bidi_levels(std::uint8_t* levels, const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSTypesetter setDrawsOutsideLineFragment:forGlyphRange:]`.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_draws_outside_line_fragment(bool flag, const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSTypesetter setHardInvalidation:forGlyphRange:]`.
     * @details Forces NSLayoutManager to invalidate glyph cache in range when invalidating layout.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_hard_invalidation(bool flag, const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSTypesetter setLineFragmentRect:forGlyphRange:usedRect:baselineOffset:]`.
     * @param fragment_rect Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param used_rect Argument converted to the Objective-C parameter of the same role.
     * @param baseline_offset Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_fragment_rect(const Rect& fragment_rect, const Range& glyph_range, const Rect& used_rect, double baseline_offset) const;
        /**
     * @brief Calls `-[NSTypesetter setLocation:withAdvancements:forStartOfGlyphRange:]`.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @param advancements Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_location(const Point& location, double* advancements, const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSTypesetter setNotShownAttribute:forGlyphRange:]`.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_not_shown_attribute(bool flag, const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSTypesetter setParagraphGlyphRange:separatorGlyphRange:]`.
     * @param paragraph_range Argument converted to the Objective-C parameter of the same role.
     * @param paragraph_separator_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_paragraph_glyph_range(const Range& paragraph_range, const Range& paragraph_separator_range) const;
        /**
     * @brief Calls `+[NSTypesetter sharedSystemTypesetterForBehavior:]`.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object shared_system_typesetter_for_behavior(TypesetterBehavior behavior);
        /**
     * @brief Calls `-[NSTypesetter shouldBreakLineByHyphenatingBeforeCharacterAtIndex:]`.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool should_break_line_by_hyphenating_before_character_at_index(std::uint64_t char_index) const;
        /**
     * @brief Calls `-[NSTypesetter shouldBreakLineByWordBeforeCharacterAtIndex:]`.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool should_break_line_by_word_before_character_at_index(std::uint64_t char_index) const;
        /**
     * @brief Calls `-[NSTypesetter substituteFontForFont:]`.
     * @details Screen/printer font mapping
     * @param original_font Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Font substitute_font_for_font(const Font& original_font) const;
        /**
     * @brief Calls `-[NSTypesetter textTabForGlyphLocation:writingDirection:maxLocation:]`.
     * @details Returns an NSTextTab instance for glyphLocation from the current text tab array. glyphLocation must be in the base typesetter coordinate (should not include line fragment rect origin and lineFragmentPadding). direction should be either NSWritingDirectionLeftToRight or NSWritingDirectionRightToLeft. maxLocation specifies the maximum location a glyph can be assigned in the base typesetter coordinate.
     * @param glyph_location Argument converted to the Objective-C parameter of the same role.
     * @param direction Argument converted to the Objective-C parameter of the same role.
     * @param max_location Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TextTab text_tab_for_glyph_location(double glyph_location, WritingDirection direction, double max_location) const;
        /**
     * @brief Calls `-[NSTypesetter willSetLineFragmentRect:forGlyphRange:usedRect:baselineOffset:]`.
     * @param line_rect Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param used_rect Argument converted to the Objective-C parameter of the same role.
     * @param baseline_offset Argument converted to the Objective-C parameter of the same role.
     */
        void will_set_line_fragment_rect(Rect* line_rect, const Range& glyph_range, Rect* used_rect, double* baseline_offset) const;
        /**
     * @brief Returns the `attributedString` property of `NSTypesetter`.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_string() const;
        /**
     * @brief Sets the `attributedString` property of `NSTypesetter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_string(const AttributedString& value) const;
        /**
     * @brief Returns the `attributesForExtraLineFragment` property of `NSTypesetter`.
     * @details This method returns the attributes used to layout the extra line fragment. The default implementation tries to use -[NSTextView typingAttributes] if possible; otherwise, uses attributes for the last character.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> attributes_for_extra_line_fragment() const;
        /**
     * @brief Returns the `bidiProcessingEnabled` property of `NSTypesetter`.
     * @details Controls whether to perform bi-directional processing. You can disable the layout stage if you know the parapgraph does not need this stage (i.e. the backing-store is in the display order).
     * @return The converted Objective-C result.
     */
        bool bidi_processing_enabled() const;
        /**
     * @brief Sets the `bidiProcessingEnabled` property of `NSTypesetter`.
     * @details Controls whether to perform bi-directional processing. You can disable the layout stage if you know the parapgraph does not need this stage (i.e. the backing-store is in the display order).
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bidi_processing_enabled(bool value) const;
        /**
     * @brief Returns the `currentParagraphStyle` property of `NSTypesetter`.
     * @return The converted Objective-C result.
     */
        ParagraphStyle current_paragraph_style() const;
        /**
     * @brief Returns the `currentTextContainer` property of `NSTypesetter`.
     * @return The converted Objective-C result.
     */
        TextContainer current_text_container() const;
        /**
     * @brief Returns the `defaultTypesetterBehavior` property of `NSTypesetter`.
     * @return The converted Objective-C result.
     */
        static TypesetterBehavior default_typesetter_behavior();
        /**
     * @brief Returns the `hyphenationFactor` property of `NSTypesetter`.
     * @details Controls hyphenation factor. The value should be between 0.0 and 1.0.
     * @return The converted Objective-C result.
     */
        float hyphenation_factor() const;
        /**
     * @brief Sets the `hyphenationFactor` property of `NSTypesetter`.
     * @details Controls hyphenation factor. The value should be between 0.0 and 1.0.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hyphenation_factor(float value) const;
        /**
     * @brief Returns the `layoutManager` property of `NSTypesetter`.
     * @details Friend class accessors
     * @return The converted Objective-C result.
     */
        LayoutManager layout_manager() const;
        /**
     * @brief Returns the `lineFragmentPadding` property of `NSTypesetter`.
     * @details Controls padding at both ends of line fragment.
     * @return The converted Objective-C result.
     */
        double line_fragment_padding() const;
        /**
     * @brief Sets the `lineFragmentPadding` property of `NSTypesetter`.
     * @details Controls padding at both ends of line fragment.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_fragment_padding(double value) const;
        /**
     * @brief Returns the `paragraphCharacterRange` property of `NSTypesetter`.
     * @return The converted Objective-C result.
     */
        Range paragraph_character_range() const;
        /**
     * @brief Returns the `paragraphGlyphRange` property of `NSTypesetter`.
     * @return The converted Objective-C result.
     */
        Range paragraph_glyph_range() const;
        /**
     * @brief Returns the `paragraphSeparatorCharacterRange` property of `NSTypesetter`.
     * @return The converted Objective-C result.
     */
        Range paragraph_separator_character_range() const;
        /**
     * @brief Returns the `paragraphSeparatorGlyphRange` property of `NSTypesetter`.
     * @return The converted Objective-C result.
     */
        Range paragraph_separator_glyph_range() const;
        /**
     * @brief Returns the `sharedSystemTypesetter` property of `NSTypesetter`.
     * @details Factory methods
     * @return The converted Objective-C result.
     */
        static Typesetter shared_system_typesetter();
        /**
     * @brief Returns the `textContainers` property of `NSTypesetter`.
     * @return The converted Objective-C result.
     */
        std::vector<TextContainer> text_containers() const;
        /**
     * @brief Returns the `typesetterBehavior` property of `NSTypesetter`.
     * @details Controls various typesetting behavior for backward compatibility
     * @return The converted Objective-C result.
     */
        TypesetterBehavior typesetter_behavior() const;
        /**
     * @brief Sets the `typesetterBehavior` property of `NSTypesetter`.
     * @details Controls various typesetting behavior for backward compatibility
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_typesetter_behavior(TypesetterBehavior value) const;
        /**
     * @brief Returns the `usesFontLeading` property of `NSTypesetter`.
     * @details Controls whether leading value specified by fonts affects line spacing
     * @return The converted Objective-C result.
     */
        bool uses_font_leading() const;
        /**
     * @brief Sets the `usesFontLeading` property of `NSTypesetter`.
     * @details Controls whether leading value specified by fonts affects line spacing
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_font_leading(bool value) const;
    };
}
