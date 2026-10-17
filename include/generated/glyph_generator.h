#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSGlyphGenerator` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::GlyphGenerator glyph_generator;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsglyphgenerator
     */
    class GlyphGenerator : public Object
    {
    public:
        /// @brief Creates a new `NSGlyphGenerator` instance and returns a handle to it.
        explicit GlyphGenerator();
        /// @brief Creates a null handle that refers to no native object.
        GlyphGenerator(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit GlyphGenerator(Adopt adopt);
        /**
     * @brief Calls `-[NSGlyphGenerator generateGlyphsForGlyphStorage:desiredNumberOfCharacters:glyphIndex:characterIndex:]`.
     * @param glyph_storage Argument converted to the Objective-C parameter of the same role.
     * @param n_chars Argument converted to the Objective-C parameter of the same role.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     */
        void generate_glyphs_for_glyph_storage(const Object& glyph_storage, std::uint64_t n_chars, std::uint64_t* glyph_index, std::uint64_t* char_index) const;
        /**
     * @brief Returns the `sharedGlyphGenerator` property of `NSGlyphGenerator`.
     * @return The converted Objective-C result.
     */
        static GlyphGenerator shared_glyph_generator();
    };
}
