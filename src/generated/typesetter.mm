#include "generated/typesetter.h"
#include "internal.h"

namespace cocoon
{
    Typesetter::Typesetter() : Typesetter(Adopt{cocoon::internal::retain([[::NSTypesetter alloc] init])})
    {
    }

    Typesetter::Typesetter(std::nullptr_t) : Object(nullptr)
    {
    }

    Typesetter::Typesetter(Adopt adopt) : Object(adopt)
    {
    }

    TypesetterControlCharacterAction Typesetter::action_for_control_character_at_index(std::uint64_t char_index) const
    {
        return static_cast<TypesetterControlCharacterAction>([cocoon::internal::ns<::NSTypesetter>(this) actionForControlCharacterAtIndex:static_cast<::NSUInteger>(char_index)]);
    }

    double Typesetter::baseline_offset_in_layout_manager(const LayoutManager& layout_mgr, std::uint64_t glyph_index) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTypesetter>(this) baselineOffsetInLayoutManager:cocoon::internal::native<::NSLayoutManager>(layout_mgr) glyphIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    void Typesetter::begin_line_with_glyph_at_index(std::uint64_t glyph_index) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) beginLineWithGlyphAtIndex:static_cast<::NSUInteger>(glyph_index)];
    }

    void Typesetter::begin_paragraph() const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) beginParagraph];
    }

    Rect Typesetter::bounding_box_for_control_glyph_at_index(std::uint64_t glyph_index, const TextContainer& text_container, const Rect& proposed_rect, const Point& glyph_position, std::uint64_t char_index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTypesetter>(this) boundingBoxForControlGlyphAtIndex:static_cast<::NSUInteger>(glyph_index) forTextContainer:cocoon::internal::native<::NSTextContainer>(text_container) proposedLineFragment:cocoon::internal::to(proposed_rect) glyphPosition:cocoon::internal::to(glyph_position) characterIndex:static_cast<::NSUInteger>(char_index)]);
    }

    Range Typesetter::character_range_for_glyph_range(const Range& glyph_range, Range* actual_glyph_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTypesetter>(this) characterRangeForGlyphRange:cocoon::internal::to(glyph_range) actualGlyphRange:(::NSRangePointer)(actual_glyph_range)]);
    }

    void Typesetter::end_line_with_glyph_range(const Range& line_glyph_range) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) endLineWithGlyphRange:cocoon::internal::to(line_glyph_range)];
    }

    void Typesetter::end_paragraph() const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) endParagraph];
    }

    void Typesetter::get_line_fragment_rect(Rect* line_fragment_rect, Rect* line_fragment_used_rect, const Range& paragraph_separator_glyph_range, const Point& line_origin) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) getLineFragmentRect:(::NSRectPointer)(line_fragment_rect) usedRect:(::NSRectPointer)(line_fragment_used_rect)forParagraphSeparatorGlyphRange:cocoon::internal::to(paragraph_separator_glyph_range) atProposedOrigin:cocoon::internal::to(line_origin)];
    }

    void Typesetter::get_line_fragment_rect(Rect* line_fragment_rect, Rect* line_fragment_used_rect, Rect* remaining_rect, std::uint64_t starting_glyph_index, const Rect& proposed_rect, double line_spacing, double paragraph_spacing_before, double paragraph_spacing_after) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) getLineFragmentRect:(::NSRectPointer)(line_fragment_rect) usedRect:(::NSRectPointer)(line_fragment_used_rect)remainingRect:(::NSRectPointer)(remaining_rect)forStartingGlyphAtIndex:static_cast<::NSUInteger>(starting_glyph_index) proposedRect:cocoon::internal::to(proposed_rect) lineSpacing:static_cast<::CGFloat>(line_spacing) paragraphSpacingBefore:static_cast<::CGFloat>(paragraph_spacing_before) paragraphSpacingAfter:static_cast<::CGFloat>(paragraph_spacing_after)];
    }

    Range Typesetter::glyph_range_for_character_range(const Range& char_range, Range* actual_char_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTypesetter>(this) glyphRangeForCharacterRange:cocoon::internal::to(char_range) actualCharacterRange:(::NSRangePointer)(actual_char_range)]);
    }

    unsigned int Typesetter::hyphen_character_for_glyph_at_index(std::uint64_t glyph_index) const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSTypesetter>(this) hyphenCharacterForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    float Typesetter::hyphenation_factor_for_glyph_at_index(std::uint64_t glyph_index) const
    {
        return static_cast<float>([cocoon::internal::ns<::NSTypesetter>(this) hyphenationFactorForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    Range Typesetter::layout_characters_in_range(const Range& character_range, const LayoutManager& layout_manager, std::uint64_t max_num_lines) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTypesetter>(this) layoutCharactersInRange:cocoon::internal::to(character_range) forLayoutManager:cocoon::internal::native<::NSLayoutManager>(layout_manager) maximumNumberOfLineFragments:static_cast<::NSUInteger>(max_num_lines)]);
    }

    void Typesetter::layout_glyphs_in_layout_manager(const LayoutManager& layout_manager, std::uint64_t start_glyph_index, std::uint64_t max_num_lines, std::uint64_t* next_glyph) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) layoutGlyphsInLayoutManager:cocoon::internal::native<::NSLayoutManager>(layout_manager) startingAtGlyphIndex:static_cast<::NSUInteger>(start_glyph_index) maxNumberOfLineFragments:static_cast<::NSUInteger>(max_num_lines) nextGlyphIndex:(::NSUInteger*)(next_glyph)];
    }

    std::uint64_t Typesetter::layout_paragraph_at_point(Point* line_fragment_origin) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSTypesetter>(this) layoutParagraphAtPoint:(::NSPointPointer)(line_fragment_origin)]);
    }

    double Typesetter::line_spacing_after_glyph_at_index(std::uint64_t glyph_index, const Rect& rect) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTypesetter>(this) lineSpacingAfterGlyphAtIndex:static_cast<::NSUInteger>(glyph_index) withProposedLineFragmentRect:cocoon::internal::to(rect)]);
    }

    double Typesetter::paragraph_spacing_after_glyph_at_index(std::uint64_t glyph_index, const Rect& rect) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTypesetter>(this) paragraphSpacingAfterGlyphAtIndex:static_cast<::NSUInteger>(glyph_index) withProposedLineFragmentRect:cocoon::internal::to(rect)]);
    }

    double Typesetter::paragraph_spacing_before_glyph_at_index(std::uint64_t glyph_index, const Rect& rect) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTypesetter>(this) paragraphSpacingBeforeGlyphAtIndex:static_cast<::NSUInteger>(glyph_index) withProposedLineFragmentRect:cocoon::internal::to(rect)]);
    }

    Size Typesetter::printing_adjustment_in_layout_manager(const LayoutManager& layout_mgr, const Range& nominally_spaced_glyphs_range, const std::uint8_t* packed_glyphs, std::uint64_t packed_glyphs_count)
    {
        return cocoon::internal::from([::NSTypesetter printingAdjustmentInLayoutManager:cocoon::internal::native<::NSLayoutManager>(layout_mgr) forNominallySpacedGlyphRange:cocoon::internal::to(nominally_spaced_glyphs_range) packedGlyphs:(const unsigned char*)(packed_glyphs)count:static_cast<::NSUInteger>(packed_glyphs_count)]);
    }

    void Typesetter::set_attachment_size(const Size& attachment_size, const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) setAttachmentSize:cocoon::internal::to(attachment_size) forGlyphRange:cocoon::internal::to(glyph_range)];
    }

    void Typesetter::set_bidi_levels(std::uint8_t* levels, const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) setBidiLevels:(const ::uint8_t*)(levels) forGlyphRange:cocoon::internal::to(glyph_range)];
    }

    void Typesetter::set_draws_outside_line_fragment(bool flag, const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) setDrawsOutsideLineFragment:static_cast<::BOOL>(flag) forGlyphRange:cocoon::internal::to(glyph_range)];
    }

    void Typesetter::set_hard_invalidation(bool flag, const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) setHardInvalidation:static_cast<::BOOL>(flag) forGlyphRange:cocoon::internal::to(glyph_range)];
    }

    void Typesetter::set_line_fragment_rect(const Rect& fragment_rect, const Range& glyph_range, const Rect& used_rect, double baseline_offset) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) setLineFragmentRect:cocoon::internal::to(fragment_rect) forGlyphRange:cocoon::internal::to(glyph_range) usedRect:cocoon::internal::to(used_rect) baselineOffset:static_cast<::CGFloat>(baseline_offset)];
    }

    void Typesetter::set_location(const Point& location, double* advancements, const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) setLocation:cocoon::internal::to(location) withAdvancements:(const ::CGFloat*)(advancements)forStartOfGlyphRange:cocoon::internal::to(glyph_range)];
    }

    void Typesetter::set_not_shown_attribute(bool flag, const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) setNotShownAttribute:static_cast<::BOOL>(flag) forGlyphRange:cocoon::internal::to(glyph_range)];
    }

    void Typesetter::set_paragraph_glyph_range(const Range& paragraph_range, const Range& paragraph_separator_range) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) setParagraphGlyphRange:cocoon::internal::to(paragraph_range) separatorGlyphRange:cocoon::internal::to(paragraph_separator_range)];
    }

    Object Typesetter::shared_system_typesetter_for_behavior(TypesetterBehavior behavior)
    {
        return cocoon::internal::wrap<Object>([::NSTypesetter sharedSystemTypesetterForBehavior:static_cast<::NSTypesetterBehavior>(behavior)]);
    }

    bool Typesetter::should_break_line_by_hyphenating_before_character_at_index(std::uint64_t char_index) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTypesetter>(this) shouldBreakLineByHyphenatingBeforeCharacterAtIndex:static_cast<::NSUInteger>(char_index)]);
    }

    bool Typesetter::should_break_line_by_word_before_character_at_index(std::uint64_t char_index) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTypesetter>(this) shouldBreakLineByWordBeforeCharacterAtIndex:static_cast<::NSUInteger>(char_index)]);
    }

    Font Typesetter::substitute_font_for_font(const Font& original_font) const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSTypesetter>(this) substituteFontForFont:cocoon::internal::native<::NSFont>(original_font)]);
    }

    TextTab Typesetter::text_tab_for_glyph_location(double glyph_location, WritingDirection direction, double max_location) const
    {
        return cocoon::internal::wrap<TextTab>([cocoon::internal::ns<::NSTypesetter>(this) textTabForGlyphLocation:static_cast<::CGFloat>(glyph_location) writingDirection:static_cast<::NSWritingDirection>(direction) maxLocation:static_cast<::CGFloat>(max_location)]);
    }

    void Typesetter::will_set_line_fragment_rect(Rect* line_rect, const Range& glyph_range, Rect* used_rect, double* baseline_offset) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) willSetLineFragmentRect:(::NSRectPointer)(line_rect) forGlyphRange:cocoon::internal::to(glyph_range) usedRect:(::NSRectPointer)(used_rect)baselineOffset:(::CGFloat*)(baseline_offset)];
    }

    AttributedString Typesetter::attributed_string() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSTypesetter>(this) attributedString]);
    }

    void Typesetter::set_attributed_string(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) setAttributedString:cocoon::internal::native<::NSAttributedString>(value)];
    }

    std::map<std::string, Object> Typesetter::attributes_for_extra_line_fragment() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSTypesetter>(this) attributesForExtraLineFragment], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    bool Typesetter::bidi_processing_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTypesetter>(this) bidiProcessingEnabled]);
    }

    void Typesetter::set_bidi_processing_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) setBidiProcessingEnabled:static_cast<::BOOL>(value)];
    }

    ParagraphStyle Typesetter::current_paragraph_style() const
    {
        return cocoon::internal::wrap<ParagraphStyle>([cocoon::internal::ns<::NSTypesetter>(this) currentParagraphStyle]);
    }

    TextContainer Typesetter::current_text_container() const
    {
        return cocoon::internal::wrap<TextContainer>([cocoon::internal::ns<::NSTypesetter>(this) currentTextContainer]);
    }

    TypesetterBehavior Typesetter::default_typesetter_behavior()
    {
        return static_cast<TypesetterBehavior>([::NSTypesetter defaultTypesetterBehavior]);
    }

    float Typesetter::hyphenation_factor() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSTypesetter>(this) hyphenationFactor]);
    }

    void Typesetter::set_hyphenation_factor(float value) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) setHyphenationFactor:static_cast<float>(value)];
    }

    LayoutManager Typesetter::layout_manager() const
    {
        return cocoon::internal::wrap<LayoutManager>([cocoon::internal::ns<::NSTypesetter>(this) layoutManager]);
    }

    double Typesetter::line_fragment_padding() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTypesetter>(this) lineFragmentPadding]);
    }

    void Typesetter::set_line_fragment_padding(double value) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) setLineFragmentPadding:static_cast<::CGFloat>(value)];
    }

    Range Typesetter::paragraph_character_range() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTypesetter>(this) paragraphCharacterRange]);
    }

    Range Typesetter::paragraph_glyph_range() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTypesetter>(this) paragraphGlyphRange]);
    }

    Range Typesetter::paragraph_separator_character_range() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTypesetter>(this) paragraphSeparatorCharacterRange]);
    }

    Range Typesetter::paragraph_separator_glyph_range() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTypesetter>(this) paragraphSeparatorGlyphRange]);
    }

    Typesetter Typesetter::shared_system_typesetter()
    {
        return cocoon::internal::wrap<Typesetter>([::NSTypesetter sharedSystemTypesetter]);
    }

    std::vector<TextContainer> Typesetter::text_containers() const
    {
        return cocoon::internal::from_array<TextContainer>([cocoon::internal::ns<::NSTypesetter>(this) textContainers], [](id e) -> TextContainer
                                                           {
                                                               return cocoon::internal::wrap<TextContainer>((::NSTextContainer*)e);
                                                           });
    }

    TypesetterBehavior Typesetter::typesetter_behavior() const
    {
        return static_cast<TypesetterBehavior>([cocoon::internal::ns<::NSTypesetter>(this) typesetterBehavior]);
    }

    void Typesetter::set_typesetter_behavior(TypesetterBehavior value) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) setTypesetterBehavior:static_cast<::NSTypesetterBehavior>(value)];
    }

    bool Typesetter::uses_font_leading() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTypesetter>(this) usesFontLeading]);
    }

    void Typesetter::set_uses_font_leading(bool value) const
    {
        [cocoon::internal::ns<::NSTypesetter>(this) setUsesFontLeading:static_cast<::BOOL>(value)];
    }
}
