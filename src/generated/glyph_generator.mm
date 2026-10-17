#include "generated/glyph_generator.h"
#include "internal.h"

namespace cocoon
{
    GlyphGenerator::GlyphGenerator() : GlyphGenerator(Adopt{cocoon::internal::retain([[::NSGlyphGenerator alloc] init])})
    {
    }

    GlyphGenerator::GlyphGenerator(std::nullptr_t) : Object(nullptr)
    {
    }

    GlyphGenerator::GlyphGenerator(Adopt adopt) : Object(adopt)
    {
    }

    void GlyphGenerator::generate_glyphs_for_glyph_storage(const Object& glyph_storage, std::uint64_t n_chars, std::uint64_t* glyph_index, std::uint64_t* char_index) const
    {
        [cocoon::internal::ns<::NSGlyphGenerator>(this) generateGlyphsForGlyphStorage:cocoon::internal::native_id(glyph_storage) desiredNumberOfCharacters:static_cast<::NSUInteger>(n_chars) glyphIndex:(::NSUInteger*)(glyph_index)characterIndex:(::NSUInteger*)(char_index)];
    }

    GlyphGenerator GlyphGenerator::shared_glyph_generator()
    {
        return cocoon::internal::wrap<GlyphGenerator>([::NSGlyphGenerator sharedGlyphGenerator]);
    }
}
