#include "generated/layout_manager.h"
#include "internal.h"

@interface AKLayoutManagerDelegate : NSObject <NSLayoutManagerDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKLayoutManagerDelegate

- (NSUInteger)layoutManager:(NSLayoutManager*)layoutManager shouldGenerateGlyphs:(CGGlyph*)glyphs properties:(NSGlyphProperty*)props characterIndexes:(NSUInteger*)charIndexes font:(NSFont*)aFont forGlyphRange:(NSRange)glyphRange
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::LayoutManager, std::uint64_t(const std::uint16_t*, const cocoon::GlyphProperty*, const std::uint64_t*, cocoon::Font, cocoon::Range)>::emit((__bridge void*)strongHost, "should_generate_glyphs_properties_character_indexes_font_for_glyph_range", (const std::uint16_t*)(glyphs), (const cocoon::GlyphProperty*)(props), (const std::uint64_t*)(charIndexes), cocoon::internal::wrap<cocoon::Font>(aFont), cocoon::internal::from(glyphRange));
    return static_cast<::NSUInteger>(__r);
}

- (CGFloat)layoutManager:(NSLayoutManager*)layoutManager lineSpacingAfterGlyphAtIndex:(NSUInteger)glyphIndex withProposedLineFragmentRect:(NSRect)rect
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::LayoutManager, double(std::uint64_t, cocoon::Rect)>::emit((__bridge void*)strongHost, "line_spacing_after_glyph_at_index_with_proposed_line_fragment_rect", static_cast<std::uint64_t>(glyphIndex), cocoon::internal::from(rect));
    return static_cast<::CGFloat>(__r);
}

- (CGFloat)layoutManager:(NSLayoutManager*)layoutManager paragraphSpacingBeforeGlyphAtIndex:(NSUInteger)glyphIndex withProposedLineFragmentRect:(NSRect)rect
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::LayoutManager, double(std::uint64_t, cocoon::Rect)>::emit((__bridge void*)strongHost, "paragraph_spacing_before_glyph_at_index_with_proposed_line_fragment_rect", static_cast<std::uint64_t>(glyphIndex), cocoon::internal::from(rect));
    return static_cast<::CGFloat>(__r);
}

- (CGFloat)layoutManager:(NSLayoutManager*)layoutManager paragraphSpacingAfterGlyphAtIndex:(NSUInteger)glyphIndex withProposedLineFragmentRect:(NSRect)rect
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::LayoutManager, double(std::uint64_t, cocoon::Rect)>::emit((__bridge void*)strongHost, "paragraph_spacing_after_glyph_at_index_with_proposed_line_fragment_rect", static_cast<std::uint64_t>(glyphIndex), cocoon::internal::from(rect));
    return static_cast<::CGFloat>(__r);
}

- (NSControlCharacterAction)layoutManager:(NSLayoutManager*)layoutManager shouldUseAction:(NSControlCharacterAction)action forControlCharacterAtIndex:(NSUInteger)charIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::LayoutManager, cocoon::ControlCharacterAction(cocoon::ControlCharacterAction, std::uint64_t)>::emit((__bridge void*)strongHost, "should_use_action_for_control_character_at_index", static_cast<cocoon::ControlCharacterAction>(action), static_cast<std::uint64_t>(charIndex));
    return static_cast<::NSControlCharacterAction>(__r);
}

- (BOOL)layoutManager:(NSLayoutManager*)layoutManager shouldBreakLineByWordBeforeCharacterAtIndex:(NSUInteger)charIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::LayoutManager, bool(std::uint64_t)>::emit((__bridge void*)strongHost, "should_break_line_by_word_before_character_at_index", static_cast<std::uint64_t>(charIndex));
    return static_cast<::BOOL>(__r);
}

- (BOOL)layoutManager:(NSLayoutManager*)layoutManager shouldBreakLineByHyphenatingBeforeCharacterAtIndex:(NSUInteger)charIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::LayoutManager, bool(std::uint64_t)>::emit((__bridge void*)strongHost, "should_break_line_by_hyphenating_before_character_at_index", static_cast<std::uint64_t>(charIndex));
    return static_cast<::BOOL>(__r);
}

- (NSRect)layoutManager:(NSLayoutManager*)layoutManager boundingBoxForControlGlyphAtIndex:(NSUInteger)glyphIndex forTextContainer:(NSTextContainer*)textContainer proposedLineFragment:(NSRect)proposedRect glyphPosition:(NSPoint)glyphPosition characterIndex:(NSUInteger)charIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::LayoutManager, cocoon::Rect(std::uint64_t, cocoon::TextContainer, cocoon::Rect, cocoon::Point, std::uint64_t)>::emit((__bridge void*)strongHost, "bounding_box_for_control_glyph_at_index_for_text_container_proposed_line_fragment_glyph_position_character_index", static_cast<std::uint64_t>(glyphIndex), cocoon::internal::wrap<cocoon::TextContainer>(textContainer), cocoon::internal::from(proposedRect), cocoon::internal::from(glyphPosition), static_cast<std::uint64_t>(charIndex));
    return cocoon::internal::to(__r);
}

- (BOOL)layoutManager:(NSLayoutManager*)layoutManager shouldSetLineFragmentRect:(NSRect*)lineFragmentRect lineFragmentUsedRect:(NSRect*)lineFragmentUsedRect baselineOffset:(CGFloat*)baselineOffset inTextContainer:(NSTextContainer*)textContainer forGlyphRange:(NSRange)glyphRange
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::LayoutManager, bool(cocoon::Rect*, cocoon::Rect*, double*, cocoon::TextContainer, cocoon::Range)>::emit((__bridge void*)strongHost, "should_set_line_fragment_rect_line_fragment_used_rect_baseline_offset_in_text_container_for_glyph_range", (cocoon::Rect*)(lineFragmentRect), (cocoon::Rect*)(lineFragmentUsedRect), (double*)(baselineOffset), cocoon::internal::wrap<cocoon::TextContainer>(textContainer), cocoon::internal::from(glyphRange));
    return static_cast<::BOOL>(__r);
}

- (void)layoutManagerDidInvalidateLayout:(NSLayoutManager*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::LayoutManager, void()>::emit((__bridge void*)strongHost, "did_invalidate_layout");
}

- (void)layoutManager:(NSLayoutManager*)layoutManager didCompleteLayoutForTextContainer:(NSTextContainer*)textContainer atEnd:(BOOL)layoutFinishedFlag
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::LayoutManager, void(cocoon::TextContainer, bool)>::emit((__bridge void*)strongHost, "did_complete_layout_for_text_container_at_end", cocoon::internal::wrap<cocoon::TextContainer>(textContainer), static_cast<bool>(layoutFinishedFlag));
}

- (void)layoutManager:(NSLayoutManager*)layoutManager textContainer:(NSTextContainer*)textContainer didChangeGeometryFromSize:(NSSize)oldSize
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::LayoutManager, void(cocoon::TextContainer, cocoon::Size)>::emit((__bridge void*)strongHost, "text_container_did_change_geometry_from_size", cocoon::internal::wrap<cocoon::TextContainer>(textContainer), cocoon::internal::from(oldSize));
}

- (NSDictionary<NSAttributedStringKey, id>*)layoutManager:(NSLayoutManager*)layoutManager shouldUseTemporaryAttributes:(NSDictionary<NSAttributedStringKey, id>*)attrs forDrawingToScreen:(BOOL)toScreen atCharacterIndex:(NSUInteger)charIndex effectiveRange:(NSRangePointer)effectiveCharRange
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::LayoutManager, std::map<std::string, cocoon::Object>(std::map<std::string, cocoon::Object>, bool, std::uint64_t, cocoon::Range*)>::emit((__bridge void*)strongHost, "should_use_temporary_attributes_for_drawing_to_screen_at_character_index_effective_range", cocoon::internal::from_dictionary<std::map<std::string, cocoon::Object>>(attrs, [](id k) -> std::string
                                                                                                                                                                                                                                                                                                                                                                               {
                                                                                                                                                                                                                                                                                                                                                                                   return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                                                                                                                                                               },
                                                                                                                                                                                                                                                                                                                                                                               [](id v) -> cocoon::Object
                                                                                                                                                                                                                                                                                                                                                                               {
                                                                                                                                                                                                                                                                                                                                                                                   return cocoon::internal::wrap<cocoon::Object>(v);
                                                                                                                                                                                                                                                                                                                                                                               }),
                                                                                                                                                                              static_cast<bool>(toScreen), static_cast<std::uint64_t>(charIndex), (cocoon::Range*)(effectiveCharRange));
    return cocoon::internal::to_dictionary(__r, [](const std::string& k) -> id
                                           {
                                               return cocoon::internal::to(k);
                                           },
                                           [](const cocoon::Object& v) -> id
                                           {
                                               return cocoon::internal::native_id(v);
                                           });
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(layoutManager:shouldGenerateGlyphs:properties:characterIndexes:font:forGlyphRange:))
    {
        return strongHost && cocoon::Signal<cocoon::LayoutManager, std::uint64_t(const std::uint16_t*, const cocoon::GlyphProperty*, const std::uint64_t*, cocoon::Font, cocoon::Range)>::connected((__bridge void*)strongHost, "should_generate_glyphs_properties_character_indexes_font_for_glyph_range");
    }
    if (selector == @selector(layoutManager:lineSpacingAfterGlyphAtIndex:withProposedLineFragmentRect:))
    {
        return strongHost && cocoon::Signal<cocoon::LayoutManager, double(std::uint64_t, cocoon::Rect)>::connected((__bridge void*)strongHost, "line_spacing_after_glyph_at_index_with_proposed_line_fragment_rect");
    }
    if (selector == @selector(layoutManager:paragraphSpacingBeforeGlyphAtIndex:withProposedLineFragmentRect:))
    {
        return strongHost && cocoon::Signal<cocoon::LayoutManager, double(std::uint64_t, cocoon::Rect)>::connected((__bridge void*)strongHost, "paragraph_spacing_before_glyph_at_index_with_proposed_line_fragment_rect");
    }
    if (selector == @selector(layoutManager:paragraphSpacingAfterGlyphAtIndex:withProposedLineFragmentRect:))
    {
        return strongHost && cocoon::Signal<cocoon::LayoutManager, double(std::uint64_t, cocoon::Rect)>::connected((__bridge void*)strongHost, "paragraph_spacing_after_glyph_at_index_with_proposed_line_fragment_rect");
    }
    if (selector == @selector(layoutManager:shouldUseAction:forControlCharacterAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::LayoutManager, cocoon::ControlCharacterAction(cocoon::ControlCharacterAction, std::uint64_t)>::connected((__bridge void*)strongHost, "should_use_action_for_control_character_at_index");
    }
    if (selector == @selector(layoutManager:shouldBreakLineByWordBeforeCharacterAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::LayoutManager, bool(std::uint64_t)>::connected((__bridge void*)strongHost, "should_break_line_by_word_before_character_at_index");
    }
    if (selector == @selector(layoutManager:shouldBreakLineByHyphenatingBeforeCharacterAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::LayoutManager, bool(std::uint64_t)>::connected((__bridge void*)strongHost, "should_break_line_by_hyphenating_before_character_at_index");
    }
    if (selector == @selector(layoutManager:boundingBoxForControlGlyphAtIndex:forTextContainer:proposedLineFragment:glyphPosition:characterIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::LayoutManager, cocoon::Rect(std::uint64_t, cocoon::TextContainer, cocoon::Rect, cocoon::Point, std::uint64_t)>::connected((__bridge void*)strongHost, "bounding_box_for_control_glyph_at_index_for_text_container_proposed_line_fragment_glyph_position_character_index");
    }
    if (selector == @selector(layoutManager:shouldSetLineFragmentRect:lineFragmentUsedRect:baselineOffset:inTextContainer:forGlyphRange:))
    {
        return strongHost && cocoon::Signal<cocoon::LayoutManager, bool(cocoon::Rect*, cocoon::Rect*, double*, cocoon::TextContainer, cocoon::Range)>::connected((__bridge void*)strongHost, "should_set_line_fragment_rect_line_fragment_used_rect_baseline_offset_in_text_container_for_glyph_range");
    }
    if (selector == @selector(layoutManagerDidInvalidateLayout:))
    {
        return strongHost && cocoon::Signal<cocoon::LayoutManager, void()>::connected((__bridge void*)strongHost, "did_invalidate_layout");
    }
    if (selector == @selector(layoutManager:didCompleteLayoutForTextContainer:atEnd:))
    {
        return strongHost && cocoon::Signal<cocoon::LayoutManager, void(cocoon::TextContainer, bool)>::connected((__bridge void*)strongHost, "did_complete_layout_for_text_container_at_end");
    }
    if (selector == @selector(layoutManager:textContainer:didChangeGeometryFromSize:))
    {
        return strongHost && cocoon::Signal<cocoon::LayoutManager, void(cocoon::TextContainer, cocoon::Size)>::connected((__bridge void*)strongHost, "text_container_did_change_geometry_from_size");
    }
    if (selector == @selector(layoutManager:shouldUseTemporaryAttributes:forDrawingToScreen:atCharacterIndex:effectiveRange:))
    {
        return strongHost && cocoon::Signal<cocoon::LayoutManager, std::map<std::string, cocoon::Object>(std::map<std::string, cocoon::Object>, bool, std::uint64_t, cocoon::Range*)>::connected((__bridge void*)strongHost, "should_use_temporary_attributes_for_drawing_to_screen_at_character_index_effective_range");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    LayoutManager::LayoutManager() : LayoutManager(Adopt{cocoon::internal::retain([[::NSLayoutManager alloc] init])})
    {
        LayoutManager::install_delegate_delegate_(handle());
    }

    LayoutManager::LayoutManager(std::nullptr_t) : Object(nullptr)
    {
    }

    LayoutManager::LayoutManager(Adopt adopt) : Object(adopt)
    {
    }

    std::uint16_t LayoutManager::cg_glyph_at_index(std::uint64_t glyph_index) const
    {
        return static_cast<std::uint16_t>([cocoon::internal::ns<::NSLayoutManager>(this) CGGlyphAtIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    std::uint16_t LayoutManager::cg_glyph_at_index(std::uint64_t glyph_index, bool* is_valid_index) const
    {
        return static_cast<std::uint16_t>([cocoon::internal::ns<::NSLayoutManager>(this) CGGlyphAtIndex:static_cast<::NSUInteger>(glyph_index) isValidIndex:(BOOL*)(is_valid_index)]);
    }

    void LayoutManager::add_temporary_attribute(const std::string& attr_name, const Object& value, const Range& char_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) addTemporaryAttribute:cocoon::internal::to(attr_name) value:cocoon::internal::native_id(value) forCharacterRange:cocoon::internal::to(char_range)];
    }

    void LayoutManager::add_temporary_attributes(const std::map<std::string, Object>& attrs, const Range& char_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) addTemporaryAttributes:cocoon::internal::to_dictionary(attrs, [](const std::string& k) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::to(k);
                                                                                                              },
                                                                                                              [](const Object& v) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::native_id(v);
                                                                                                              })
                                                            forCharacterRange:cocoon::internal::to(char_range)];
    }

    void LayoutManager::add_text_container(const TextContainer& container) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) addTextContainer:cocoon::internal::native<::NSTextContainer>(container)];
    }

    Size LayoutManager::attachment_size_for_glyph_at_index(std::uint64_t glyph_index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) attachmentSizeForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    Rect LayoutManager::bounding_rect_for_glyph_range(const Range& glyph_range, const TextContainer& container) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) boundingRectForGlyphRange:cocoon::internal::to(glyph_range) inTextContainer:cocoon::internal::native<::NSTextContainer>(container)]);
    }

    Rect LayoutManager::bounds_rect_for_text_block(const TextBlock& block, std::uint64_t glyph_index, Range* effective_glyph_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) boundsRectForTextBlock:cocoon::internal::native<::NSTextBlock>(block) atIndex:static_cast<::NSUInteger>(glyph_index) effectiveRange:(::NSRangePointer)(effective_glyph_range)]);
    }

    Rect LayoutManager::bounds_rect_for_text_block(const TextBlock& block, const Range& glyph_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) boundsRectForTextBlock:cocoon::internal::native<::NSTextBlock>(block) glyphRange:cocoon::internal::to(glyph_range)]);
    }

    std::uint64_t LayoutManager::character_index_for_glyph_at_index(std::uint64_t glyph_index) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSLayoutManager>(this) characterIndexForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    std::uint64_t LayoutManager::character_index_for_point(const Point& point, const TextContainer& container, double* partial_fraction) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSLayoutManager>(this) characterIndexForPoint:cocoon::internal::to(point) inTextContainer:cocoon::internal::native<::NSTextContainer>(container) fractionOfDistanceBetweenInsertionPoints:(::CGFloat*)(partial_fraction)]);
    }

    Range LayoutManager::character_range_for_glyph_range(const Range& glyph_range, Range* actual_glyph_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) characterRangeForGlyphRange:cocoon::internal::to(glyph_range) actualGlyphRange:(::NSRangePointer)(actual_glyph_range)]);
    }

    double LayoutManager::default_baseline_offset_for_font(const Font& the_font) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSLayoutManager>(this) defaultBaselineOffsetForFont:cocoon::internal::native<::NSFont>(the_font)]);
    }

    double LayoutManager::default_line_height_for_font(const Font& the_font) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSLayoutManager>(this) defaultLineHeightForFont:cocoon::internal::native<::NSFont>(the_font)]);
    }

    void LayoutManager::draw_background_for_glyph_range(const Range& glyphs_to_show, const Point& origin) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) drawBackgroundForGlyphRange:cocoon::internal::to(glyphs_to_show) atPoint:cocoon::internal::to(origin)];
    }

    void LayoutManager::draw_glyphs_for_glyph_range(const Range& glyphs_to_show, const Point& origin) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) drawGlyphsForGlyphRange:cocoon::internal::to(glyphs_to_show) atPoint:cocoon::internal::to(origin)];
    }

    void LayoutManager::draw_strikethrough_for_glyph_range(const Range& glyph_range, UnderlineStyle strikethrough_val, double baseline_offset, const Rect& line_rect, const Range& line_glyph_range, const Point& container_origin) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) drawStrikethroughForGlyphRange:cocoon::internal::to(glyph_range) strikethroughType:static_cast<::NSUnderlineStyle>(strikethrough_val) baselineOffset:static_cast<::CGFloat>(baseline_offset) lineFragmentRect:cocoon::internal::to(line_rect) lineFragmentGlyphRange:cocoon::internal::to(line_glyph_range) containerOrigin:cocoon::internal::to(container_origin)];
    }

    void LayoutManager::draw_underline_for_glyph_range(const Range& glyph_range, UnderlineStyle underline_val, double baseline_offset, const Rect& line_rect, const Range& line_glyph_range, const Point& container_origin) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) drawUnderlineForGlyphRange:cocoon::internal::to(glyph_range) underlineType:static_cast<::NSUnderlineStyle>(underline_val) baselineOffset:static_cast<::CGFloat>(baseline_offset) lineFragmentRect:cocoon::internal::to(line_rect) lineFragmentGlyphRange:cocoon::internal::to(line_glyph_range) containerOrigin:cocoon::internal::to(container_origin)];
    }

    bool LayoutManager::draws_outside_line_fragment_for_glyph_at_index(std::uint64_t glyph_index) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutManager>(this) drawsOutsideLineFragmentForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    void LayoutManager::ensure_glyphs_for_character_range(const Range& char_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) ensureGlyphsForCharacterRange:cocoon::internal::to(char_range)];
    }

    void LayoutManager::ensure_glyphs_for_glyph_range(const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) ensureGlyphsForGlyphRange:cocoon::internal::to(glyph_range)];
    }

    void LayoutManager::ensure_layout_for_bounding_rect(const Rect& bounds, const TextContainer& container) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) ensureLayoutForBoundingRect:cocoon::internal::to(bounds) inTextContainer:cocoon::internal::native<::NSTextContainer>(container)];
    }

    void LayoutManager::ensure_layout_for_character_range(const Range& char_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) ensureLayoutForCharacterRange:cocoon::internal::to(char_range)];
    }

    void LayoutManager::ensure_layout_for_glyph_range(const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) ensureLayoutForGlyphRange:cocoon::internal::to(glyph_range)];
    }

    void LayoutManager::ensure_layout_for_text_container(const TextContainer& container) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) ensureLayoutForTextContainer:cocoon::internal::native<::NSTextContainer>(container)];
    }

    void LayoutManager::enumerate_enclosing_rects_for_glyph_range(const Range& glyph_range, const Range& selected_range, const TextContainer& text_container, std::function<void(Rect, bool&)> block) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) enumerateEnclosingRectsForGlyphRange:cocoon::internal::to(glyph_range) withinSelectedGlyphRange:cocoon::internal::to(selected_range) inTextContainer:cocoon::internal::native<::NSTextContainer>(text_container) usingBlock:(block ? (void (^)(::NSRect, BOOL*)) ^ void(::NSRect a266_0, ::BOOL * a266_1) { bool __o266_1 = a266_1 ? static_cast<bool>(*a266_1) : bool(); block(cocoon::internal::from(a266_0), __o266_1); if (a266_1) { *a266_1 = static_cast<::BOOL>(__o266_1); } } : (void (^)(::NSRect, BOOL*))nil)];
    }

    void LayoutManager::enumerate_line_fragments_for_glyph_range(const Range& glyph_range, std::function<void(Rect, Rect, TextContainer, Range, bool&)> block) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) enumerateLineFragmentsForGlyphRange:cocoon::internal::to(glyph_range) usingBlock:(block ? (void (^)(::NSRect, ::NSRect, ::NSTextContainer*, ::NSRange, BOOL*)) ^ void(::NSRect a267_0, ::NSRect a267_1, ::NSTextContainer * a267_2, ::NSRange a267_3, ::BOOL * a267_4) { bool __o267_4 = a267_4 ? static_cast<bool>(*a267_4) : bool(); block(cocoon::internal::from(a267_0), cocoon::internal::from(a267_1), cocoon::internal::wrap<TextContainer>(a267_2), cocoon::internal::from(a267_3), __o267_4); if (a267_4) { *a267_4 = static_cast<::BOOL>(__o267_4); } } : (void (^)(::NSRect, ::NSRect, ::NSTextContainer*, ::NSRange, BOOL*))nil)];
    }

    void LayoutManager::fill_background_rect_array(const Rect* rect_array, std::uint64_t rect_count, const Range& char_range, const Color& color) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) fillBackgroundRectArray:(const ::NSRect*)(rect_array) count:static_cast<::NSUInteger>(rect_count) forCharacterRange:cocoon::internal::to(char_range) color:cocoon::internal::native<::NSColor>(color)];
    }

    std::uint64_t LayoutManager::first_unlaid_character_index() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSLayoutManager>(this) firstUnlaidCharacterIndex]);
    }

    std::uint64_t LayoutManager::first_unlaid_glyph_index() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSLayoutManager>(this) firstUnlaidGlyphIndex]);
    }

    double LayoutManager::fraction_of_distance_through_glyph_for_point(const Point& point, const TextContainer& container) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSLayoutManager>(this) fractionOfDistanceThroughGlyphForPoint:cocoon::internal::to(point) inTextContainer:cocoon::internal::native<::NSTextContainer>(container)]);
    }

    void LayoutManager::get_first_unlaid_character_index(std::uint64_t* char_index, std::uint64_t* glyph_index) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) getFirstUnlaidCharacterIndex:(::NSUInteger*)(char_index) glyphIndex:(::NSUInteger*)(glyph_index)];
    }

    std::uint64_t LayoutManager::get_glyphs_in_range(const Range& glyph_range, std::uint16_t* glyph_buffer, GlyphProperty* props, std::uint64_t* char_index_buffer, std::uint8_t* bidi_level_buffer) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSLayoutManager>(this) getGlyphsInRange:cocoon::internal::to(glyph_range) glyphs:(::CGGlyph*)(glyph_buffer)properties:(::NSGlyphProperty*)(props)characterIndexes:(::NSUInteger*)(char_index_buffer)bidiLevels:(unsigned char*)(bidi_level_buffer)]);
    }

    std::uint64_t LayoutManager::get_line_fragment_insertion_points_for_character_at_index(std::uint64_t char_index, bool a_flag, bool d_flag, double* positions, std::uint64_t* char_indexes) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSLayoutManager>(this) getLineFragmentInsertionPointsForCharacterAtIndex:static_cast<::NSUInteger>(char_index) alternatePositions:static_cast<::BOOL>(a_flag) inDisplayOrder:static_cast<::BOOL>(d_flag) positions:(::CGFloat*)(positions)characterIndexes:(::NSUInteger*)(char_indexes)]);
    }

    unsigned int LayoutManager::glyph_at_index(std::uint64_t glyph_index) const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSLayoutManager>(this) glyphAtIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    unsigned int LayoutManager::glyph_at_index(std::uint64_t glyph_index, bool* is_valid_index) const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSLayoutManager>(this) glyphAtIndex:static_cast<::NSUInteger>(glyph_index) isValidIndex:(BOOL*)(is_valid_index)]);
    }

    std::uint64_t LayoutManager::glyph_index_for_character_at_index(std::uint64_t char_index) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSLayoutManager>(this) glyphIndexForCharacterAtIndex:static_cast<::NSUInteger>(char_index)]);
    }

    std::uint64_t LayoutManager::glyph_index_for_point(const Point& point, const TextContainer& container) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSLayoutManager>(this) glyphIndexForPoint:cocoon::internal::to(point) inTextContainer:cocoon::internal::native<::NSTextContainer>(container)]);
    }

    std::uint64_t LayoutManager::glyph_index_for_point(const Point& point, const TextContainer& container, double* partial_fraction) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSLayoutManager>(this) glyphIndexForPoint:cocoon::internal::to(point) inTextContainer:cocoon::internal::native<::NSTextContainer>(container) fractionOfDistanceThroughGlyph:(::CGFloat*)(partial_fraction)]);
    }

    Range LayoutManager::glyph_range_for_bounding_rect(const Rect& bounds, const TextContainer& container) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) glyphRangeForBoundingRect:cocoon::internal::to(bounds) inTextContainer:cocoon::internal::native<::NSTextContainer>(container)]);
    }

    Range LayoutManager::glyph_range_for_bounding_rect_without_additional_layout(const Rect& bounds, const TextContainer& container) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) glyphRangeForBoundingRectWithoutAdditionalLayout:cocoon::internal::to(bounds) inTextContainer:cocoon::internal::native<::NSTextContainer>(container)]);
    }

    Range LayoutManager::glyph_range_for_character_range(const Range& char_range, Range* actual_char_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) glyphRangeForCharacterRange:cocoon::internal::to(char_range) actualCharacterRange:(::NSRangePointer)(actual_char_range)]);
    }

    Range LayoutManager::glyph_range_for_text_container(const TextContainer& container) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) glyphRangeForTextContainer:cocoon::internal::native<::NSTextContainer>(container)]);
    }

    void LayoutManager::insert_text_container(const TextContainer& container, std::uint64_t index) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) insertTextContainer:cocoon::internal::native<::NSTextContainer>(container) atIndex:static_cast<::NSUInteger>(index)];
    }

    void LayoutManager::invalidate_display_for_character_range(const Range& char_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) invalidateDisplayForCharacterRange:cocoon::internal::to(char_range)];
    }

    void LayoutManager::invalidate_display_for_glyph_range(const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) invalidateDisplayForGlyphRange:cocoon::internal::to(glyph_range)];
    }

    void LayoutManager::invalidate_glyphs_for_character_range(const Range& char_range, std::int64_t delta, Range* actual_char_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) invalidateGlyphsForCharacterRange:cocoon::internal::to(char_range) changeInLength:static_cast<::NSInteger>(delta) actualCharacterRange:(::NSRangePointer)(actual_char_range)];
    }

    void LayoutManager::invalidate_layout_for_character_range(const Range& char_range, Range* actual_char_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) invalidateLayoutForCharacterRange:cocoon::internal::to(char_range) actualCharacterRange:(::NSRangePointer)(actual_char_range)];
    }

    bool LayoutManager::is_valid_glyph_index(std::uint64_t glyph_index) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutManager>(this) isValidGlyphIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    bool LayoutManager::layout_manager_owns_first_responder_in_window(const Window& window) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutManager>(this) layoutManagerOwnsFirstResponderInWindow:cocoon::internal::native<::NSWindow>(window)]);
    }

    Rect LayoutManager::layout_rect_for_text_block(const TextBlock& block, std::uint64_t glyph_index, Range* effective_glyph_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) layoutRectForTextBlock:cocoon::internal::native<::NSTextBlock>(block) atIndex:static_cast<::NSUInteger>(glyph_index) effectiveRange:(::NSRangePointer)(effective_glyph_range)]);
    }

    Rect LayoutManager::layout_rect_for_text_block(const TextBlock& block, const Range& glyph_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) layoutRectForTextBlock:cocoon::internal::native<::NSTextBlock>(block) glyphRange:cocoon::internal::to(glyph_range)]);
    }

    Rect LayoutManager::line_fragment_rect_for_glyph_at_index(std::uint64_t glyph_index, Range* effective_glyph_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) lineFragmentRectForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index) effectiveRange:(::NSRangePointer)(effective_glyph_range)]);
    }

    Rect LayoutManager::line_fragment_rect_for_glyph_at_index(std::uint64_t glyph_index, Range* effective_glyph_range, bool flag) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) lineFragmentRectForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index) effectiveRange:(::NSRangePointer)(effective_glyph_range)withoutAdditionalLayout:static_cast<::BOOL>(flag)]);
    }

    Rect LayoutManager::line_fragment_used_rect_for_glyph_at_index(std::uint64_t glyph_index, Range* effective_glyph_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) lineFragmentUsedRectForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index) effectiveRange:(::NSRangePointer)(effective_glyph_range)]);
    }

    Rect LayoutManager::line_fragment_used_rect_for_glyph_at_index(std::uint64_t glyph_index, Range* effective_glyph_range, bool flag) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) lineFragmentUsedRectForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index) effectiveRange:(::NSRangePointer)(effective_glyph_range)withoutAdditionalLayout:static_cast<::BOOL>(flag)]);
    }

    Point LayoutManager::location_for_glyph_at_index(std::uint64_t glyph_index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) locationForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    bool LayoutManager::not_shown_attribute_for_glyph_at_index(std::uint64_t glyph_index) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutManager>(this) notShownAttributeForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    void LayoutManager::process_editing_for_text_storage(const TextStorage& text_storage, TextStorageEditActions edit_mask, const Range& new_char_range, std::int64_t delta, const Range& invalidated_char_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) processEditingForTextStorage:cocoon::internal::native<::NSTextStorage>(text_storage) edited:static_cast<::NSTextStorageEditActions>(edit_mask) range:cocoon::internal::to(new_char_range) changeInLength:static_cast<::NSInteger>(delta) invalidatedRange:cocoon::internal::to(invalidated_char_range)];
    }

    GlyphProperty LayoutManager::property_for_glyph_at_index(std::uint64_t glyph_index) const
    {
        return static_cast<GlyphProperty>([cocoon::internal::ns<::NSLayoutManager>(this) propertyForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    Range LayoutManager::range_of_nominally_spaced_glyphs_containing_index(std::uint64_t glyph_index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) rangeOfNominallySpacedGlyphsContainingIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    Rect* LayoutManager::rect_array_for_character_range(const Range& char_range, const Range& sel_char_range, const TextContainer& container, std::uint64_t* rect_count) const
    {
        return (Rect*)([cocoon::internal::ns<::NSLayoutManager>(this) rectArrayForCharacterRange:cocoon::internal::to(char_range) withinSelectedCharacterRange:cocoon::internal::to(sel_char_range) inTextContainer:cocoon::internal::native<::NSTextContainer>(container) rectCount:(::NSUInteger*)(rect_count)]);
    }

    Rect* LayoutManager::rect_array_for_glyph_range(const Range& glyph_range, const Range& sel_glyph_range, const TextContainer& container, std::uint64_t* rect_count) const
    {
        return (Rect*)([cocoon::internal::ns<::NSLayoutManager>(this) rectArrayForGlyphRange:cocoon::internal::to(glyph_range) withinSelectedGlyphRange:cocoon::internal::to(sel_glyph_range) inTextContainer:cocoon::internal::native<::NSTextContainer>(container) rectCount:(::NSUInteger*)(rect_count)]);
    }

    void LayoutManager::remove_temporary_attribute(const std::string& attr_name, const Range& char_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) removeTemporaryAttribute:cocoon::internal::to(attr_name) forCharacterRange:cocoon::internal::to(char_range)];
    }

    void LayoutManager::remove_text_container_at_index(std::uint64_t index) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) removeTextContainerAtIndex:static_cast<::NSUInteger>(index)];
    }

    void LayoutManager::replace_text_storage(const TextStorage& new_text_storage) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) replaceTextStorage:cocoon::internal::native<::NSTextStorage>(new_text_storage)];
    }

    View LayoutManager::ruler_accessory_view_for_text_view(const TextView& view, const ParagraphStyle& style, const RulerView& ruler, bool is_enabled) const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSLayoutManager>(this) rulerAccessoryViewForTextView:cocoon::internal::native<::NSTextView>(view) paragraphStyle:cocoon::internal::native<::NSParagraphStyle>(style) ruler:cocoon::internal::native<::NSRulerView>(ruler) enabled:static_cast<::BOOL>(is_enabled)]);
    }

    std::vector<RulerMarker> LayoutManager::ruler_markers_for_text_view(const TextView& view, const ParagraphStyle& style, const RulerView& ruler) const
    {
        return cocoon::internal::from_array<RulerMarker>([cocoon::internal::ns<::NSLayoutManager>(this) rulerMarkersForTextView:cocoon::internal::native<::NSTextView>(view) paragraphStyle:cocoon::internal::native<::NSParagraphStyle>(style) ruler:cocoon::internal::native<::NSRulerView>(ruler)], [](id e) -> RulerMarker
                                                         {
                                                             return cocoon::internal::wrap<RulerMarker>((::NSRulerMarker*)e);
                                                         });
    }

    void LayoutManager::set_attachment_size(const Size& attachment_size, const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setAttachmentSize:cocoon::internal::to(attachment_size) forGlyphRange:cocoon::internal::to(glyph_range)];
    }

    void LayoutManager::set_bounds_rect(const Rect& rect, const TextBlock& block, const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setBoundsRect:cocoon::internal::to(rect) forTextBlock:cocoon::internal::native<::NSTextBlock>(block) glyphRange:cocoon::internal::to(glyph_range)];
    }

    void LayoutManager::set_draws_outside_line_fragment(bool flag, std::uint64_t glyph_index) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setDrawsOutsideLineFragment:static_cast<::BOOL>(flag) forGlyphAtIndex:static_cast<::NSUInteger>(glyph_index)];
    }

    void LayoutManager::set_extra_line_fragment_rect(const Rect& fragment_rect, const Rect& used_rect, const TextContainer& container) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setExtraLineFragmentRect:cocoon::internal::to(fragment_rect) usedRect:cocoon::internal::to(used_rect) textContainer:cocoon::internal::native<::NSTextContainer>(container)];
    }

    void LayoutManager::set_glyphs(const std::uint16_t* glyphs, const GlyphProperty* props, const std::uint64_t* char_indexes, const Font& a_font, const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setGlyphs:(const ::CGGlyph*)(glyphs) properties:(const ::NSGlyphProperty*)(props)characterIndexes:(const ::NSUInteger*)(char_indexes)font:cocoon::internal::native<::NSFont>(a_font) forGlyphRange:cocoon::internal::to(glyph_range)];
    }

    void LayoutManager::set_layout_rect(const Rect& rect, const TextBlock& block, const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setLayoutRect:cocoon::internal::to(rect) forTextBlock:cocoon::internal::native<::NSTextBlock>(block) glyphRange:cocoon::internal::to(glyph_range)];
    }

    void LayoutManager::set_line_fragment_rect(const Rect& fragment_rect, const Range& glyph_range, const Rect& used_rect) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setLineFragmentRect:cocoon::internal::to(fragment_rect) forGlyphRange:cocoon::internal::to(glyph_range) usedRect:cocoon::internal::to(used_rect)];
    }

    void LayoutManager::set_location(const Point& location, const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setLocation:cocoon::internal::to(location) forStartOfGlyphRange:cocoon::internal::to(glyph_range)];
    }

    void LayoutManager::set_not_shown_attribute(bool flag, std::uint64_t glyph_index) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setNotShownAttribute:static_cast<::BOOL>(flag) forGlyphAtIndex:static_cast<::NSUInteger>(glyph_index)];
    }

    void LayoutManager::set_temporary_attributes(const std::map<std::string, Object>& attrs, const Range& char_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setTemporaryAttributes:cocoon::internal::to_dictionary(attrs, [](const std::string& k) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::to(k);
                                                                                                              },
                                                                                                              [](const Object& v) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::native_id(v);
                                                                                                              })
                                                            forCharacterRange:cocoon::internal::to(char_range)];
    }

    void LayoutManager::set_text_container(const TextContainer& container, const Range& glyph_range) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setTextContainer:cocoon::internal::native<::NSTextContainer>(container) forGlyphRange:cocoon::internal::to(glyph_range)];
    }

    void LayoutManager::show_attachment_cell(const Cell& cell, const Rect& rect, std::uint64_t attachment_index) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) showAttachmentCell:cocoon::internal::native<::NSCell>(cell) inRect:cocoon::internal::to(rect) characterIndex:static_cast<::NSUInteger>(attachment_index)];
    }

    void LayoutManager::show_cg_glyphs(const std::uint16_t* glyphs, const Point* positions, std::int64_t glyph_count, const Font& font, const AffineTransform3& text_matrix, const std::map<std::string, Object>& attributes, const CGContext& cg_context) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) showCGGlyphs:(const ::CGGlyph*)(glyphs)
                                                          positions:(const ::CGPoint*)(positions)count:static_cast<::NSInteger>(glyph_count)
                                                               font:cocoon::internal::native<::NSFont>(font)
                                                         textMatrix:cocoon::internal::to(text_matrix)
                                                         attributes:cocoon::internal::to_dictionary(attributes, [](const std::string& k) -> id
                                                                                                    {
                                                                                                        return cocoon::internal::to(k);
                                                                                                    },
                                                                                                    [](const Object& v) -> id
                                                                                                    {
                                                                                                        return cocoon::internal::native_id(v);
                                                                                                    })
                                                          inContext:((::CGContextRef)(cg_context).handle())];
    }

    void LayoutManager::strikethrough_glyph_range(const Range& glyph_range, UnderlineStyle strikethrough_val, const Rect& line_rect, const Range& line_glyph_range, const Point& container_origin) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) strikethroughGlyphRange:cocoon::internal::to(glyph_range) strikethroughType:static_cast<::NSUnderlineStyle>(strikethrough_val) lineFragmentRect:cocoon::internal::to(line_rect) lineFragmentGlyphRange:cocoon::internal::to(line_glyph_range) containerOrigin:cocoon::internal::to(container_origin)];
    }

    Object LayoutManager::temporary_attribute(const std::string& attr_name, std::uint64_t location, Range* range) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSLayoutManager>(this) temporaryAttribute:cocoon::internal::to(attr_name) atCharacterIndex:static_cast<::NSUInteger>(location) effectiveRange:(::NSRangePointer)(range)]);
    }

    Object LayoutManager::temporary_attribute(const std::string& attr_name, std::uint64_t location, Range* range, const Range& range_limit) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSLayoutManager>(this) temporaryAttribute:cocoon::internal::to(attr_name) atCharacterIndex:static_cast<::NSUInteger>(location) longestEffectiveRange:(::NSRangePointer)(range)inRange:cocoon::internal::to(range_limit)]);
    }

    std::map<std::string, Object> LayoutManager::temporary_attributes_at_character_index(std::uint64_t char_index, Range* effective_char_range) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSLayoutManager>(this) temporaryAttributesAtCharacterIndex:static_cast<::NSUInteger>(char_index) effectiveRange:(::NSRangePointer)(effective_char_range)], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    std::map<std::string, Object> LayoutManager::temporary_attributes_at_character_index(std::uint64_t location, Range* range, const Range& range_limit) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSLayoutManager>(this) temporaryAttributesAtCharacterIndex:static_cast<::NSUInteger>(location) longestEffectiveRange:(::NSRangePointer)(range)inRange:cocoon::internal::to(range_limit)], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void LayoutManager::text_container_changed_geometry(const TextContainer& container) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) textContainerChangedGeometry:cocoon::internal::native<::NSTextContainer>(container)];
    }

    void LayoutManager::text_container_changed_text_view(const TextContainer& container) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) textContainerChangedTextView:cocoon::internal::native<::NSTextContainer>(container)];
    }

    TextContainer LayoutManager::text_container_for_glyph_at_index(std::uint64_t glyph_index, Range* effective_glyph_range) const
    {
        return cocoon::internal::wrap<TextContainer>([cocoon::internal::ns<::NSLayoutManager>(this) textContainerForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index) effectiveRange:(::NSRangePointer)(effective_glyph_range)]);
    }

    TextContainer LayoutManager::text_container_for_glyph_at_index(std::uint64_t glyph_index, Range* effective_glyph_range, bool flag) const
    {
        return cocoon::internal::wrap<TextContainer>([cocoon::internal::ns<::NSLayoutManager>(this) textContainerForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index) effectiveRange:(::NSRangePointer)(effective_glyph_range)withoutAdditionalLayout:static_cast<::BOOL>(flag)]);
    }

    Range LayoutManager::truncated_glyph_range_in_line_fragment_for_glyph_at_index(std::uint64_t glyph_index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) truncatedGlyphRangeInLineFragmentForGlyphAtIndex:static_cast<::NSUInteger>(glyph_index)]);
    }

    void LayoutManager::underline_glyph_range(const Range& glyph_range, UnderlineStyle underline_val, const Rect& line_rect, const Range& line_glyph_range, const Point& container_origin) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) underlineGlyphRange:cocoon::internal::to(glyph_range) underlineType:static_cast<::NSUnderlineStyle>(underline_val) lineFragmentRect:cocoon::internal::to(line_rect) lineFragmentGlyphRange:cocoon::internal::to(line_glyph_range) containerOrigin:cocoon::internal::to(container_origin)];
    }

    Rect LayoutManager::used_rect_for_text_container(const TextContainer& container) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) usedRectForTextContainer:cocoon::internal::native<::NSTextContainer>(container)]);
    }

    bool LayoutManager::allows_non_contiguous_layout() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutManager>(this) allowsNonContiguousLayout]);
    }

    void LayoutManager::set_allows_non_contiguous_layout(bool value) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setAllowsNonContiguousLayout:static_cast<::BOOL>(value)];
    }

    bool LayoutManager::background_layout_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutManager>(this) backgroundLayoutEnabled]);
    }

    void LayoutManager::set_background_layout_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setBackgroundLayoutEnabled:static_cast<::BOOL>(value)];
    }

    ImageScaling LayoutManager::default_attachment_scaling() const
    {
        return static_cast<ImageScaling>([cocoon::internal::ns<::NSLayoutManager>(this) defaultAttachmentScaling]);
    }

    void LayoutManager::set_default_attachment_scaling(ImageScaling value) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setDefaultAttachmentScaling:static_cast<::NSImageScaling>(value)];
    }

    Rect LayoutManager::extra_line_fragment_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) extraLineFragmentRect]);
    }

    TextContainer LayoutManager::extra_line_fragment_text_container() const
    {
        return cocoon::internal::wrap<TextContainer>([cocoon::internal::ns<::NSLayoutManager>(this) extraLineFragmentTextContainer]);
    }

    Rect LayoutManager::extra_line_fragment_used_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLayoutManager>(this) extraLineFragmentUsedRect]);
    }

    TextView LayoutManager::first_text_view() const
    {
        return cocoon::internal::wrap<TextView>([cocoon::internal::ns<::NSLayoutManager>(this) firstTextView]);
    }

    GlyphGenerator LayoutManager::glyph_generator() const
    {
        return cocoon::internal::wrap<GlyphGenerator>([cocoon::internal::ns<::NSLayoutManager>(this) glyphGenerator]);
    }

    void LayoutManager::set_glyph_generator(const GlyphGenerator& value) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setGlyphGenerator:cocoon::internal::native<::NSGlyphGenerator>(value)];
    }

    bool LayoutManager::has_non_contiguous_layout() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutManager>(this) hasNonContiguousLayout]);
    }

    bool LayoutManager::limits_layout_for_suspicious_contents() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutManager>(this) limitsLayoutForSuspiciousContents]);
    }

    void LayoutManager::set_limits_layout_for_suspicious_contents(bool value) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setLimitsLayoutForSuspiciousContents:static_cast<::BOOL>(value)];
    }

    std::uint64_t LayoutManager::number_of_glyphs() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSLayoutManager>(this) numberOfGlyphs]);
    }

    bool LayoutManager::shows_control_characters() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutManager>(this) showsControlCharacters]);
    }

    void LayoutManager::set_shows_control_characters(bool value) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setShowsControlCharacters:static_cast<::BOOL>(value)];
    }

    bool LayoutManager::shows_invisible_characters() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutManager>(this) showsInvisibleCharacters]);
    }

    void LayoutManager::set_shows_invisible_characters(bool value) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setShowsInvisibleCharacters:static_cast<::BOOL>(value)];
    }

    std::vector<TextContainer> LayoutManager::text_containers() const
    {
        return cocoon::internal::from_array<TextContainer>([cocoon::internal::ns<::NSLayoutManager>(this) textContainers], [](id e) -> TextContainer
                                                           {
                                                               return cocoon::internal::wrap<TextContainer>((::NSTextContainer*)e);
                                                           });
    }

    TextStorage LayoutManager::text_storage() const
    {
        return cocoon::internal::wrap<TextStorage>([cocoon::internal::ns<::NSLayoutManager>(this) textStorage]);
    }

    void LayoutManager::set_text_storage(const TextStorage& value) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setTextStorage:cocoon::internal::native<::NSTextStorage>(value)];
    }

    TextView LayoutManager::text_view_for_beginning_of_selection() const
    {
        return cocoon::internal::wrap<TextView>([cocoon::internal::ns<::NSLayoutManager>(this) textViewForBeginningOfSelection]);
    }

    Typesetter LayoutManager::typesetter() const
    {
        return cocoon::internal::wrap<Typesetter>([cocoon::internal::ns<::NSLayoutManager>(this) typesetter]);
    }

    void LayoutManager::set_typesetter(const Typesetter& value) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setTypesetter:cocoon::internal::native<::NSTypesetter>(value)];
    }

    TypesetterBehavior LayoutManager::typesetter_behavior() const
    {
        return static_cast<TypesetterBehavior>([cocoon::internal::ns<::NSLayoutManager>(this) typesetterBehavior]);
    }

    void LayoutManager::set_typesetter_behavior(TypesetterBehavior value) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setTypesetterBehavior:static_cast<::NSTypesetterBehavior>(value)];
    }

    bool LayoutManager::uses_default_hyphenation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutManager>(this) usesDefaultHyphenation]);
    }

    void LayoutManager::set_uses_default_hyphenation(bool value) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setUsesDefaultHyphenation:static_cast<::BOOL>(value)];
    }

    bool LayoutManager::uses_font_leading() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLayoutManager>(this) usesFontLeading]);
    }

    void LayoutManager::set_uses_font_leading(bool value) const
    {
        [cocoon::internal::ns<::NSLayoutManager>(this) setUsesFontLeading:static_cast<::BOOL>(value)];
    }

    void LayoutManager::install_delegate_delegate_(void* native)
    {
        ::NSLayoutManager* host = (__bridge ::NSLayoutManager*)native;
        AKLayoutManagerDelegate* delegate = [[AKLayoutManagerDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSLayoutManager* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSLayoutManager* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
