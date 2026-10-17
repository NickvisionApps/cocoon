#include "generated/font.h"
#include "internal.h"

namespace cocoon
{
    Font::Font() : Font(Adopt{cocoon::internal::retain([[::NSFont alloc] init])})
    {
    }

    Font::Font(std::nullptr_t) : Object(nullptr)
    {
    }

    Font::Font(Adopt adopt) : Object(adopt)
    {
    }

    Size Font::advancement_for_cg_glyph(std::uint16_t glyph) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFont>(this) advancementForCGGlyph:static_cast<::CGGlyph>(glyph)]);
    }

    Size Font::advancement_for_glyph(unsigned int glyph) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFont>(this) advancementForGlyph:static_cast<::NSGlyph>(glyph)]);
    }

    Font Font::bold_system_font_of_size(double font_size)
    {
        return cocoon::internal::wrap<Font>([::NSFont boldSystemFontOfSize:static_cast<::CGFloat>(font_size)]);
    }

    Rect Font::bounding_rect_for_cg_glyph(std::uint16_t glyph) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFont>(this) boundingRectForCGGlyph:static_cast<::CGGlyph>(glyph)]);
    }

    Rect Font::bounding_rect_for_glyph(unsigned int glyph) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFont>(this) boundingRectForGlyph:static_cast<::NSGlyph>(glyph)]);
    }

    Font Font::control_content_font_of_size(double font_size)
    {
        return cocoon::internal::wrap<Font>([::NSFont controlContentFontOfSize:static_cast<::CGFloat>(font_size)]);
    }

    Font Font::font_with_descriptor(const FontDescriptor& font_descriptor, double font_size)
    {
        return cocoon::internal::wrap<Font>([::NSFont fontWithDescriptor:cocoon::internal::native<::NSFontDescriptor>(font_descriptor) size:static_cast<::CGFloat>(font_size)]);
    }

    Font Font::font_with_descriptor(const FontDescriptor& font_descriptor, const AffineTransform& text_transform)
    {
        return cocoon::internal::wrap<Font>([::NSFont fontWithDescriptor:cocoon::internal::native<::NSFontDescriptor>(font_descriptor) textTransform:cocoon::internal::native<::NSAffineTransform>(text_transform)]);
    }

    Font Font::font_with_name(const std::string& font_name, const double* font_matrix)
    {
        return cocoon::internal::wrap<Font>([::NSFont fontWithName:cocoon::internal::to(font_name) matrix:(const ::CGFloat*)(font_matrix)]);
    }

    Font Font::font_with_name(const std::string& font_name, double font_size)
    {
        return cocoon::internal::wrap<Font>([::NSFont fontWithName:cocoon::internal::to(font_name) size:static_cast<::CGFloat>(font_size)]);
    }

    Font Font::font_with_size(double font_size) const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSFont>(this) fontWithSize:static_cast<::CGFloat>(font_size)]);
    }

    void Font::get_advancements(Size* advancements, const std::uint16_t* glyphs, std::uint64_t glyph_count) const
    {
        [cocoon::internal::ns<::NSFont>(this) getAdvancements:(::NSSizeArray)(advancements) forCGGlyphs:(const ::CGGlyph*)(glyphs)count:static_cast<::NSUInteger>(glyph_count)];
    }

    void Font::get_advancements(Size* advancements, const unsigned int* glyphs, std::uint64_t glyph_count) const
    {
        [cocoon::internal::ns<::NSFont>(this) getAdvancements:(::NSSizeArray)(advancements) forGlyphs:(const ::NSGlyph*)(glyphs)count:static_cast<::NSUInteger>(glyph_count)];
    }

    void Font::get_advancements(Size* advancements, const void* packed_glyphs, std::uint64_t length) const
    {
        [cocoon::internal::ns<::NSFont>(this) getAdvancements:(::NSSizeArray)(advancements) forPackedGlyphs:packed_glyphs length:static_cast<::NSUInteger>(length)];
    }

    void Font::get_bounding_rects(Rect* bounds, const std::uint16_t* glyphs, std::uint64_t glyph_count) const
    {
        [cocoon::internal::ns<::NSFont>(this) getBoundingRects:(::NSRectArray)(bounds) forCGGlyphs:(const ::CGGlyph*)(glyphs)count:static_cast<::NSUInteger>(glyph_count)];
    }

    void Font::get_bounding_rects(Rect* bounds, const unsigned int* glyphs, std::uint64_t glyph_count) const
    {
        [cocoon::internal::ns<::NSFont>(this) getBoundingRects:(::NSRectArray)(bounds) forGlyphs:(const ::NSGlyph*)(glyphs)count:static_cast<::NSUInteger>(glyph_count)];
    }

    unsigned int Font::glyph_with_name(const std::string& name) const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSFont>(this) glyphWithName:cocoon::internal::to(name)]);
    }

    Font Font::label_font_of_size(double font_size)
    {
        return cocoon::internal::wrap<Font>([::NSFont labelFontOfSize:static_cast<::CGFloat>(font_size)]);
    }

    Font Font::menu_bar_font_of_size(double font_size)
    {
        return cocoon::internal::wrap<Font>([::NSFont menuBarFontOfSize:static_cast<::CGFloat>(font_size)]);
    }

    Font Font::menu_font_of_size(double font_size)
    {
        return cocoon::internal::wrap<Font>([::NSFont menuFontOfSize:static_cast<::CGFloat>(font_size)]);
    }

    Font Font::message_font_of_size(double font_size)
    {
        return cocoon::internal::wrap<Font>([::NSFont messageFontOfSize:static_cast<::CGFloat>(font_size)]);
    }

    Font Font::monospaced_digit_system_font_of_size(double font_size, double weight)
    {
        return cocoon::internal::wrap<Font>([::NSFont monospacedDigitSystemFontOfSize:static_cast<::CGFloat>(font_size) weight:static_cast<::NSFontWeight>(weight)]);
    }

    Font Font::monospaced_system_font_of_size(double font_size, double weight)
    {
        return cocoon::internal::wrap<Font>([::NSFont monospacedSystemFontOfSize:static_cast<::CGFloat>(font_size) weight:static_cast<::NSFontWeight>(weight)]);
    }

    Font Font::palette_font_of_size(double font_size)
    {
        return cocoon::internal::wrap<Font>([::NSFont paletteFontOfSize:static_cast<::CGFloat>(font_size)]);
    }

    Font Font::preferred_font_for_text_style(const std::string& style, const std::map<std::string, Object>& options)
    {
        return cocoon::internal::wrap<Font>([::NSFont preferredFontForTextStyle:cocoon::internal::to(style)
                                                          options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                    {
                                                                                        return cocoon::internal::to(k);
                                                                                    },
                                                                                    [](const Object& v) -> id
                                                                                    {
                                                                                        return cocoon::internal::native_id(v);
                                                                                    })]);
    }

    Font Font::screen_font_with_rendering_mode(FontRenderingMode rendering_mode) const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSFont>(this) screenFontWithRenderingMode:static_cast<::NSFontRenderingMode>(rendering_mode)]);
    }

    void Font::set() const
    {
        [cocoon::internal::ns<::NSFont>(this) set];
    }

    void Font::set_in_context(const GraphicsContext& graphics_context) const
    {
        [cocoon::internal::ns<::NSFont>(this) setInContext:cocoon::internal::native<::NSGraphicsContext>(graphics_context)];
    }

    void Font::set_user_fixed_pitch_font(const Font& font)
    {
        [::NSFont setUserFixedPitchFont:cocoon::internal::native<::NSFont>(font)];
    }

    void Font::set_user_font(const Font& font)
    {
        [::NSFont setUserFont:cocoon::internal::native<::NSFont>(font)];
    }

    Font Font::system_font_of_size(double font_size)
    {
        return cocoon::internal::wrap<Font>([::NSFont systemFontOfSize:static_cast<::CGFloat>(font_size)]);
    }

    Font Font::system_font_of_size(double font_size, double weight)
    {
        return cocoon::internal::wrap<Font>([::NSFont systemFontOfSize:static_cast<::CGFloat>(font_size) weight:static_cast<::NSFontWeight>(weight)]);
    }

    Font Font::system_font_of_size(double font_size, double weight, double width)
    {
        return cocoon::internal::wrap<Font>([::NSFont systemFontOfSize:static_cast<::CGFloat>(font_size) weight:static_cast<::NSFontWeight>(weight) width:static_cast<::NSFontWidth>(width)]);
    }

    double Font::system_font_size_for_control_size(ControlSize control_size)
    {
        return static_cast<double>([::NSFont systemFontSizeForControlSize:static_cast<::NSControlSize>(control_size)]);
    }

    Font Font::title_bar_font_of_size(double font_size)
    {
        return cocoon::internal::wrap<Font>([::NSFont titleBarFontOfSize:static_cast<::CGFloat>(font_size)]);
    }

    Font Font::tool_tips_font_of_size(double font_size)
    {
        return cocoon::internal::wrap<Font>([::NSFont toolTipsFontOfSize:static_cast<::CGFloat>(font_size)]);
    }

    Font Font::user_fixed_pitch_font_of_size(double font_size)
    {
        return cocoon::internal::wrap<Font>([::NSFont userFixedPitchFontOfSize:static_cast<::CGFloat>(font_size)]);
    }

    Font Font::user_font_of_size(double font_size)
    {
        return cocoon::internal::wrap<Font>([::NSFont userFontOfSize:static_cast<::CGFloat>(font_size)]);
    }

    double Font::ascender() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSFont>(this) ascender]);
    }

    Rect Font::bounding_rect_for_font() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFont>(this) boundingRectForFont]);
    }

    double Font::cap_height() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSFont>(this) capHeight]);
    }

    CharacterSet Font::covered_character_set() const
    {
        return cocoon::internal::wrap<CharacterSet>([cocoon::internal::ns<::NSFont>(this) coveredCharacterSet]);
    }

    double Font::descender() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSFont>(this) descender]);
    }

    std::string Font::display_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFont>(this) displayName]);
    }

    std::string Font::family_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFont>(this) familyName]);
    }

    bool Font::is_fixed_pitch() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFont>(this) isFixedPitch]);
    }

    FontDescriptor Font::font_descriptor() const
    {
        return cocoon::internal::wrap<FontDescriptor>([cocoon::internal::ns<::NSFont>(this) fontDescriptor]);
    }

    std::string Font::font_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFont>(this) fontName]);
    }

    double Font::italic_angle() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSFont>(this) italicAngle]);
    }

    double Font::label_font_size()
    {
        return static_cast<double>([::NSFont labelFontSize]);
    }

    double Font::leading() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSFont>(this) leading]);
    }

    const double* Font::matrix() const
    {
        return (const double*)([cocoon::internal::ns<::NSFont>(this) matrix]);
    }

    Size Font::maximum_advancement() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFont>(this) maximumAdvancement]);
    }

    std::uint64_t Font::most_compatible_string_encoding() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSFont>(this) mostCompatibleStringEncoding]);
    }

    std::uint64_t Font::number_of_glyphs() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSFont>(this) numberOfGlyphs]);
    }

    double Font::point_size() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSFont>(this) pointSize]);
    }

    Font Font::printer_font() const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSFont>(this) printerFont]);
    }

    FontRenderingMode Font::rendering_mode() const
    {
        return static_cast<FontRenderingMode>([cocoon::internal::ns<::NSFont>(this) renderingMode]);
    }

    Font Font::screen_font() const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSFont>(this) screenFont]);
    }

    double Font::small_system_font_size()
    {
        return static_cast<double>([::NSFont smallSystemFontSize]);
    }

    double Font::system_font_size()
    {
        return static_cast<double>([::NSFont systemFontSize]);
    }

    AffineTransform Font::text_transform() const
    {
        return cocoon::internal::wrap<AffineTransform>([cocoon::internal::ns<::NSFont>(this) textTransform]);
    }

    double Font::underline_position() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSFont>(this) underlinePosition]);
    }

    double Font::underline_thickness() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSFont>(this) underlineThickness]);
    }

    bool Font::is_vertical() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFont>(this) isVertical]);
    }

    Font Font::vertical_font() const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSFont>(this) verticalFont]);
    }

    double Font::x_height() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSFont>(this) xHeight]);
    }
}
