#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Font;

    /**
     * @brief C++ handle for the Objective-C class `NSGlyphInfo` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::GlyphInfo glyph_info;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::GlyphInfo glyph_info{};
     * auto made_0 = cocoon::GlyphInfo::glyph_info_with_cg_glyph(1, cocoon::Font(), "text");
     * auto made_1 = cocoon::GlyphInfo::glyph_info_with_character_identifier(1, cocoon::CharacterCollection::IdentityMappingCharacterCollection, "text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsglyphinfo
     */
    class GlyphInfo : public Object
    {
    public:
        /// @brief Creates a new `NSGlyphInfo` instance and returns a handle to it.
        explicit GlyphInfo();
        /// @brief Creates a null handle that refers to no native object.
        GlyphInfo(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit GlyphInfo(Adopt adopt);
        /**
     * @brief Calls `+[NSGlyphInfo glyphInfoWithCGGlyph:forFont:baseString:]`.
     * @param glyph Argument converted to the Objective-C parameter of the same role.
     * @param font Argument converted to the Objective-C parameter of the same role.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static GlyphInfo glyph_info_with_cg_glyph(std::uint16_t glyph, const Font& font, const std::string& string);
        /**
     * @brief Calls `+[NSGlyphInfo glyphInfoWithCharacterIdentifier:collection:baseString:]`.
     * @param cid Argument converted to the Objective-C parameter of the same role.
     * @param character_collection Argument converted to the Objective-C parameter of the same role.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static GlyphInfo glyph_info_with_character_identifier(std::uint64_t cid, CharacterCollection character_collection, const std::string& string);
        /**
     * @brief Calls `+[NSGlyphInfo glyphInfoWithGlyph:forFont:baseString:]`.
     * @param glyph Argument converted to the Objective-C parameter of the same role.
     * @param font Argument converted to the Objective-C parameter of the same role.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static GlyphInfo glyph_info_with_glyph(unsigned int glyph, const Font& font, const std::string& string);
        /**
     * @brief Calls `+[NSGlyphInfo glyphInfoWithGlyphName:forFont:baseString:]`.
     * @param glyph_name Argument converted to the Objective-C parameter of the same role.
     * @param font Argument converted to the Objective-C parameter of the same role.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static GlyphInfo glyph_info_with_glyph_name(const std::string& glyph_name, const Font& font, const std::string& string);
        /**
     * @brief Returns the `baseString` property of `NSGlyphInfo`.
     * @return The converted Objective-C result.
     */
        std::string base_string() const;
        /**
     * @brief Returns the `characterCollection` property of `NSGlyphInfo`.
     * @return The converted Objective-C result.
     */
        CharacterCollection character_collection() const;
        /**
     * @brief Returns the `characterIdentifier` property of `NSGlyphInfo`.
     * @return The converted Objective-C result.
     */
        std::uint64_t character_identifier() const;
        /**
     * @brief Returns the `glyphID` property of `NSGlyphInfo`.
     * @return The converted Objective-C result.
     */
        std::uint16_t glyph_id() const;
        /**
     * @brief Returns the `glyphName` property of `NSGlyphInfo`.
     * @return The converted Objective-C result.
     */
        std::string glyph_name() const;
    };
}
