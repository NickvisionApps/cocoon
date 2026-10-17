#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/typesetter.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Font;
    class LayoutManager;
    class TextContainer;
    class TextTab;

    /**
     * @brief C++ handle for the Objective-C class `NSATSTypesetter` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Typesetter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ATSTypesetter ats_typesetter;
     * ats_typesetter.set_attributed_string(cocoon::AttributedString());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ATSTypesetter ats_typesetter{};
     * ats_typesetter.set_attributed_string(cocoon::AttributedString());
     * auto attributed_string = ats_typesetter.attributed_string();
     * ats_typesetter.set_bidi_processing_enabled(true);
     * auto bidi_processing_enabled = ats_typesetter.bidi_processing_enabled();
     * ats_typesetter.set_hyphenation_factor(1);
     * auto hyphenation_factor = ats_typesetter.hyphenation_factor();
     * ats_typesetter.bounding_box_for_control_glyph_at_index(1, cocoon::TextContainer(), {{0, 0}, {100, 100}}, {0, 0}, 1);
     * ats_typesetter.hyphen_character_for_glyph_at_index(1);
     * ats_typesetter.hyphenation_factor_for_glyph_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsatstypesetter
     */
    class ATSTypesetter : public Typesetter
    {
    public:
        /// @brief Creates a new `NSATSTypesetter` instance and returns a handle to it.
        explicit ATSTypesetter();
        /// @brief Creates a null handle that refers to no native object.
        ATSTypesetter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ATSTypesetter(Adopt adopt);
        using Typesetter::attributed_string;
        using Typesetter::bidi_processing_enabled;
        using Typesetter::bounding_box_for_control_glyph_at_index;
        using Typesetter::current_text_container;
        using Typesetter::get_line_fragment_rect;
        using Typesetter::hyphen_character_for_glyph_at_index;
        using Typesetter::hyphenation_factor;
        using Typesetter::hyphenation_factor_for_glyph_at_index;
        using Typesetter::layout_manager;
        using Typesetter::layout_paragraph_at_point;
        using Typesetter::line_fragment_padding;
        using Typesetter::line_spacing_after_glyph_at_index;
        using Typesetter::paragraph_glyph_range;
        using Typesetter::paragraph_separator_glyph_range;
        using Typesetter::paragraph_spacing_after_glyph_at_index;
        using Typesetter::paragraph_spacing_before_glyph_at_index;
        using Typesetter::set_attributed_string;
        using Typesetter::set_bidi_processing_enabled;
        using Typesetter::set_hard_invalidation;
        using Typesetter::set_hyphenation_factor;
        using Typesetter::set_line_fragment_padding;
        using Typesetter::set_paragraph_glyph_range;
        using Typesetter::set_typesetter_behavior;
        using Typesetter::set_uses_font_leading;
        using Typesetter::should_break_line_by_hyphenating_before_character_at_index;
        using Typesetter::should_break_line_by_word_before_character_at_index;
        using Typesetter::substitute_font_for_font;
        using Typesetter::text_tab_for_glyph_location;
        using Typesetter::typesetter_behavior;
        using Typesetter::uses_font_leading;
        using Typesetter::will_set_line_fragment_rect;
        /**
     * @brief Calls `-[NSATSTypesetter boundingBoxForControlGlyphAtIndex:forTextContainer:proposedLineFragment:glyphPosition:characterIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param text_container Argument converted to the Objective-C parameter of the same role.
     * @param proposed_rect Argument converted to the Objective-C parameter of the same role.
     * @param glyph_position Argument converted to the Objective-C parameter of the same role.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect bounding_box_for_control_glyph_at_index(std::uint64_t glyph_index, const TextContainer& text_container, const Rect& proposed_rect, const Point& glyph_position, std::uint64_t char_index) const;
        /**
     * @brief Calls `-[NSATSTypesetter getLineFragmentRect:usedRect:forParagraphSeparatorGlyphRange:atProposedOrigin:]`.
     * @param line_fragment_rect Argument converted to the Objective-C parameter of the same role.
     * @param line_fragment_used_rect Argument converted to the Objective-C parameter of the same role.
     * @param paragraph_separator_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param line_origin Argument converted to the Objective-C parameter of the same role.
     */
        void get_line_fragment_rect(Rect* line_fragment_rect, Rect* line_fragment_used_rect, const Range& paragraph_separator_glyph_range, const Point& line_origin) const;
        /**
     * @brief Calls `-[NSATSTypesetter hyphenCharacterForGlyphAtIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        unsigned int hyphen_character_for_glyph_at_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSATSTypesetter hyphenationFactorForGlyphAtIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        float hyphenation_factor_for_glyph_at_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSATSTypesetter layoutParagraphAtPoint:]`.
     * @param line_fragment_origin Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t layout_paragraph_at_point(Point* line_fragment_origin) const;
        /**
     * @brief Calls `-[NSATSTypesetter lineSpacingAfterGlyphAtIndex:withProposedLineFragmentRect:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double line_spacing_after_glyph_at_index(std::uint64_t glyph_index, const Rect& rect) const;
        /**
     * @brief Calls `-[NSATSTypesetter paragraphSpacingAfterGlyphAtIndex:withProposedLineFragmentRect:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double paragraph_spacing_after_glyph_at_index(std::uint64_t glyph_index, const Rect& rect) const;
        /**
     * @brief Calls `-[NSATSTypesetter paragraphSpacingBeforeGlyphAtIndex:withProposedLineFragmentRect:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double paragraph_spacing_before_glyph_at_index(std::uint64_t glyph_index, const Rect& rect) const;
        /**
     * @brief Calls `-[NSATSTypesetter setHardInvalidation:forGlyphRange:]`.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_hard_invalidation(bool flag, const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSATSTypesetter setParagraphGlyphRange:separatorGlyphRange:]`.
     * @param paragraph_range Argument converted to the Objective-C parameter of the same role.
     * @param paragraph_separator_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_paragraph_glyph_range(const Range& paragraph_range, const Range& paragraph_separator_range) const;
        /**
     * @brief Calls `-[NSATSTypesetter shouldBreakLineByHyphenatingBeforeCharacterAtIndex:]`.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool should_break_line_by_hyphenating_before_character_at_index(std::uint64_t char_index) const;
        /**
     * @brief Calls `-[NSATSTypesetter shouldBreakLineByWordBeforeCharacterAtIndex:]`.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool should_break_line_by_word_before_character_at_index(std::uint64_t char_index) const;
        /**
     * @brief Calls `-[NSATSTypesetter substituteFontForFont:]`.
     * @param original_font Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Font substitute_font_for_font(const Font& original_font) const;
        /**
     * @brief Calls `-[NSATSTypesetter textTabForGlyphLocation:writingDirection:maxLocation:]`.
     * @param glyph_location Argument converted to the Objective-C parameter of the same role.
     * @param direction Argument converted to the Objective-C parameter of the same role.
     * @param max_location Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TextTab text_tab_for_glyph_location(double glyph_location, WritingDirection direction, double max_location) const;
        /**
     * @brief Calls `-[NSATSTypesetter willSetLineFragmentRect:forGlyphRange:usedRect:baselineOffset:]`.
     * @param line_rect Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param used_rect Argument converted to the Objective-C parameter of the same role.
     * @param baseline_offset Argument converted to the Objective-C parameter of the same role.
     */
        void will_set_line_fragment_rect(Rect* line_rect, const Range& glyph_range, Rect* used_rect, double* baseline_offset) const;
        /**
     * @brief Returns the `attributedString` property of `NSATSTypesetter`.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_string() const;
        /**
     * @brief Sets the `attributedString` property of `NSATSTypesetter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_string(const AttributedString& value) const;
        /**
     * @brief Returns the `bidiProcessingEnabled` property of `NSATSTypesetter`.
     * @return The converted Objective-C result.
     */
        bool bidi_processing_enabled() const;
        /**
     * @brief Sets the `bidiProcessingEnabled` property of `NSATSTypesetter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bidi_processing_enabled(bool value) const;
        /**
     * @brief Returns the `currentTextContainer` property of `NSATSTypesetter`.
     * @return The converted Objective-C result.
     */
        TextContainer current_text_container() const;
        /**
     * @brief Returns the `hyphenationFactor` property of `NSATSTypesetter`.
     * @return The converted Objective-C result.
     */
        float hyphenation_factor() const;
        /**
     * @brief Sets the `hyphenationFactor` property of `NSATSTypesetter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hyphenation_factor(float value) const;
        /**
     * @brief Returns the `layoutManager` property of `NSATSTypesetter`.
     * @return The converted Objective-C result.
     */
        LayoutManager layout_manager() const;
        /**
     * @brief Returns the `lineFragmentPadding` property of `NSATSTypesetter`.
     * @return The converted Objective-C result.
     */
        double line_fragment_padding() const;
        /**
     * @brief Sets the `lineFragmentPadding` property of `NSATSTypesetter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_fragment_padding(double value) const;
        /**
     * @brief Returns the `paragraphGlyphRange` property of `NSATSTypesetter`.
     * @return The converted Objective-C result.
     */
        Range paragraph_glyph_range() const;
        /**
     * @brief Returns the `paragraphSeparatorGlyphRange` property of `NSATSTypesetter`.
     * @return The converted Objective-C result.
     */
        Range paragraph_separator_glyph_range() const;
        /**
     * @brief Returns the `sharedTypesetter` property of `NSATSTypesetter`.
     * @return The converted Objective-C result.
     */
        static ATSTypesetter shared_typesetter();
        /**
     * @brief Returns the `typesetterBehavior` property of `NSATSTypesetter`.
     * @return The converted Objective-C result.
     */
        TypesetterBehavior typesetter_behavior() const;
        /**
     * @brief Sets the `typesetterBehavior` property of `NSATSTypesetter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_typesetter_behavior(TypesetterBehavior value) const;
        /**
     * @brief Returns the `usesFontLeading` property of `NSATSTypesetter`.
     * @return The converted Objective-C result.
     */
        bool uses_font_leading() const;
        /**
     * @brief Sets the `usesFontLeading` property of `NSATSTypesetter`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_font_leading(bool value) const;
    };
}
