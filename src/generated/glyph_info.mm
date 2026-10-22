#include "generated/glyph_info.h"
#include "internal.h"

namespace cocoon
{
    GlyphInfo::GlyphInfo(std::uint16_t glyph, const Font& font, const std::string& string) : GlyphInfo(Adopt{cocoon::internal::retain([::NSGlyphInfo glyphInfoWithCGGlyph:static_cast<::CGGlyph>(glyph) forFont:cocoon::internal::native<::NSFont>(font) baseString:cocoon::internal::to(string)])})
    {
    }

    GlyphInfo::GlyphInfo(std::uint64_t cid, CharacterCollection character_collection, const std::string& string) : GlyphInfo(Adopt{cocoon::internal::retain([::NSGlyphInfo glyphInfoWithCharacterIdentifier:static_cast<::NSUInteger>(cid) collection:static_cast<::NSCharacterCollection>(character_collection) baseString:cocoon::internal::to(string)])})
    {
    }

    GlyphInfo::GlyphInfo(unsigned int glyph, const Font& font, const std::string& string) : GlyphInfo(Adopt{cocoon::internal::retain([::NSGlyphInfo glyphInfoWithGlyph:static_cast<::NSGlyph>(glyph) forFont:cocoon::internal::native<::NSFont>(font) baseString:cocoon::internal::to(string)])})
    {
    }

    GlyphInfo::GlyphInfo(const std::string& glyph_name, const Font& font, const std::string& string) : GlyphInfo(Adopt{cocoon::internal::retain([::NSGlyphInfo glyphInfoWithGlyphName:cocoon::internal::to(glyph_name) forFont:cocoon::internal::native<::NSFont>(font) baseString:cocoon::internal::to(string)])})
    {
    }

    GlyphInfo::GlyphInfo() : GlyphInfo(Adopt{cocoon::internal::retain([[::NSGlyphInfo alloc] init])})
    {
    }

    GlyphInfo::GlyphInfo(std::nullptr_t) : Object(nullptr)
    {
    }

    GlyphInfo::GlyphInfo(Adopt adopt) : Object(adopt)
    {
    }

    std::string GlyphInfo::base_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSGlyphInfo>(this) baseString]);
    }

    CharacterCollection GlyphInfo::character_collection() const
    {
        return static_cast<CharacterCollection>([cocoon::internal::ns<::NSGlyphInfo>(this) characterCollection]);
    }

    std::uint64_t GlyphInfo::character_identifier() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSGlyphInfo>(this) characterIdentifier]);
    }

    std::uint16_t GlyphInfo::glyph_id() const
    {
        return static_cast<std::uint16_t>([cocoon::internal::ns<::NSGlyphInfo>(this) glyphID]);
    }

    std::string GlyphInfo::glyph_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSGlyphInfo>(this) glyphName]);
    }
}
