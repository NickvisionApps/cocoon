#include "generated/ats_typesetter.h"
#include "internal.h"

namespace cocoon
{
    ATSTypesetter::ATSTypesetter() : ATSTypesetter(Adopt{cocoon::internal::retain([[::NSATSTypesetter alloc] init])})
    {
    }

    ATSTypesetter::ATSTypesetter(std::nullptr_t) : Typesetter(nullptr)
    {
    }

    ATSTypesetter::ATSTypesetter(Adopt adopt) : Typesetter(adopt)
    {
    }

    Rect ATSTypesetter::bounding_box_for_control_glyph_at_index(std::uint64_t glyph_index, const TextContainer& text_container, const Rect& proposed_rect, const Point& glyph_position, std::uint64_t char_index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSATSTypesetter>(this) boundingBoxForControlGlyphAtIndex:static_cast<::NSUInteger>(glyph_index) forTextContainer:cocoon::internal::native<::NSTextContainer>(text_container) proposedLineFragment:cocoon::internal::to(proposed_rect) glyphPosition:cocoon::internal::to(glyph_position) characterIndex:static_cast<::NSUInteger>(char_index)]);
    }

    void ATSTypesetter::get_line_fragment_rect(Rect* line_fragment_rect, Rect* line_fragment_used_rect, const Range& paragraph_separator_glyph_range, const Point& line_origin) const
    {
        [cocoon::internal::ns<::NSATSTypesetter>(this) getLineFragmentRect:(::NSRect*)(line_fragment_rect) usedRect:(::NSRect*)(line_fragment_used_rect)forParagraphSeparatorGlyphRange:cocoon::internal::to(paragraph_separator_glyph_range) atProposedOrigin:cocoon::internal::to(line_origin)];
    }

    unsigned int ATSTypesetter::hyphen_character_for_glyph_at_index(std::uint64_t glyph_index) const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSATSTypesetter>(this) hyphenCharacterForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    float ATSTypesetter::hyphenation_factor_for_glyph_at_index(std::uint64_t glyph_index) const
    {
        return static_cast<float>([cocoon::internal::ns<::NSATSTypesetter>(this) hyphenationFactorForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    std::uint64_t ATSTypesetter::layout_paragraph_at_point(Point* line_fragment_origin) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSATSTypesetter>(this) layoutParagraphAtPoint:(::NSPoint*)(line_fragment_origin)]);
    }

    double ATSTypesetter::line_spacing_after_glyph_at_index(std::uint64_t glyph_index, const Rect& rect) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSATSTypesetter>(this) lineSpacingAfterGlyphAtIndex:static_cast<::NSUInteger>(glyph_index) withProposedLineFragmentRect:cocoon::internal::to(rect)]);
    }

    double ATSTypesetter::paragraph_spacing_after_glyph_at_index(std::uint64_t glyph_index, const Rect& rect) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSATSTypesetter>(this) paragraphSpacingAfterGlyphAtIndex:static_cast<::NSUInteger>(glyph_index) withProposedLineFragmentRect:cocoon::internal::to(rect)]);
    }

    double ATSTypesetter::paragraph_spacing_before_glyph_at_index(std::uint64_t glyph_index, const Rect& rect) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSATSTypesetter>(this) paragraphSpacingBeforeGlyphAtIndex:static_cast<::NSUInteger>(glyph_index) withProposedLineFragmentRect:cocoon::internal::to(rect)]);
    }

    void ATSTypesetter::set_hard_invalidation(bool flag, const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSATSTypesetter>(this) setHardInvalidation:static_cast<::BOOL>(flag) forGlyphRange:cocoon::internal::to(glyph_range)];
    }

    void ATSTypesetter::set_paragraph_glyph_range(const Range& paragraph_range, const Range& paragraph_separator_range) const
    {
        [cocoon::internal::ns<::NSATSTypesetter>(this) setParagraphGlyphRange:cocoon::internal::to(paragraph_range) separatorGlyphRange:cocoon::internal::to(paragraph_separator_range)];
    }

    bool ATSTypesetter::should_break_line_by_hyphenating_before_character_at_index(std::uint64_t char_index) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSATSTypesetter>(this) shouldBreakLineByHyphenatingBeforeCharacterAtIndex:static_cast<::NSUInteger>(char_index)]);
    }

    bool ATSTypesetter::should_break_line_by_word_before_character_at_index(std::uint64_t char_index) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSATSTypesetter>(this) shouldBreakLineByWordBeforeCharacterAtIndex:static_cast<::NSUInteger>(char_index)]);
    }

    Font ATSTypesetter::substitute_font_for_font(const Font& original_font) const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSATSTypesetter>(this) substituteFontForFont:cocoon::internal::native<::NSFont>(original_font)]);
    }

    TextTab ATSTypesetter::text_tab_for_glyph_location(double glyph_location, WritingDirection direction, double max_location) const
    {
        return cocoon::internal::wrap<TextTab>([cocoon::internal::ns<::NSATSTypesetter>(this) textTabForGlyphLocation:static_cast<::CGFloat>(glyph_location) writingDirection:static_cast<::NSWritingDirection>(direction) maxLocation:static_cast<::CGFloat>(max_location)]);
    }

    void ATSTypesetter::will_set_line_fragment_rect(Rect* line_rect, const Range& glyph_range, Rect* used_rect, double* baseline_offset) const
    {
        [cocoon::internal::ns<::NSATSTypesetter>(this) willSetLineFragmentRect:(::NSRect*)(line_rect) forGlyphRange:cocoon::internal::to(glyph_range) usedRect:(::NSRect*)(used_rect)baselineOffset:(::CGFloat*)(baseline_offset)];
    }

    AttributedString ATSTypesetter::attributed_string() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSATSTypesetter>(this) attributedString]);
    }

    void ATSTypesetter::set_attributed_string(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSATSTypesetter>(this) setAttributedString:cocoon::internal::native<::NSAttributedString>(value)];
    }

    bool ATSTypesetter::bidi_processing_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSATSTypesetter>(this) bidiProcessingEnabled]);
    }

    void ATSTypesetter::set_bidi_processing_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSATSTypesetter>(this) setBidiProcessingEnabled:static_cast<::BOOL>(value)];
    }

    TextContainer ATSTypesetter::current_text_container() const
    {
        return cocoon::internal::wrap<TextContainer>([cocoon::internal::ns<::NSATSTypesetter>(this) currentTextContainer]);
    }

    float ATSTypesetter::hyphenation_factor() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSATSTypesetter>(this) hyphenationFactor]);
    }

    void ATSTypesetter::set_hyphenation_factor(float value) const
    {
        [cocoon::internal::ns<::NSATSTypesetter>(this) setHyphenationFactor:static_cast<float>(value)];
    }

    LayoutManager ATSTypesetter::layout_manager() const
    {
        return cocoon::internal::wrap<LayoutManager>([cocoon::internal::ns<::NSATSTypesetter>(this) layoutManager]);
    }

    double ATSTypesetter::line_fragment_padding() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSATSTypesetter>(this) lineFragmentPadding]);
    }

    void ATSTypesetter::set_line_fragment_padding(double value) const
    {
        [cocoon::internal::ns<::NSATSTypesetter>(this) setLineFragmentPadding:static_cast<::CGFloat>(value)];
    }

    Range ATSTypesetter::paragraph_glyph_range() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSATSTypesetter>(this) paragraphGlyphRange]);
    }

    Range ATSTypesetter::paragraph_separator_glyph_range() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSATSTypesetter>(this) paragraphSeparatorGlyphRange]);
    }

    ATSTypesetter ATSTypesetter::shared_typesetter()
    {
        return cocoon::internal::wrap<ATSTypesetter>([::NSATSTypesetter sharedTypesetter]);
    }

    TypesetterBehavior ATSTypesetter::typesetter_behavior() const
    {
        return static_cast<TypesetterBehavior>([cocoon::internal::ns<::NSATSTypesetter>(this) typesetterBehavior]);
    }

    void ATSTypesetter::set_typesetter_behavior(TypesetterBehavior value) const
    {
        [cocoon::internal::ns<::NSATSTypesetter>(this) setTypesetterBehavior:static_cast<::NSTypesetterBehavior>(value)];
    }

    bool ATSTypesetter::uses_font_leading() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSATSTypesetter>(this) usesFontLeading]);
    }

    void ATSTypesetter::set_uses_font_leading(bool value) const
    {
        [cocoon::internal::ns<::NSATSTypesetter>(this) setUsesFontLeading:static_cast<::BOOL>(value)];
    }
}
