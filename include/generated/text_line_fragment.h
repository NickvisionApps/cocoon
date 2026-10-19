#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class CGContext;

    /**
     * @brief C++ handle for the Objective-C class `NSTextLineFragment` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextLineFragment text_line_fragment(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextLineFragment text_line_fragment(nullptr);
     * text_line_fragment.character_index_for_point({0, 0});
     * text_line_fragment.fraction_of_distance_through_glyph_for_point({0, 0});
     * text_line_fragment.location_for_character_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextlinefragment
     */
    class TextLineFragment : public Object
    {
    public:
        /// @brief Creates a new `NSTextLineFragment` instance and returns a handle to it.
        explicit TextLineFragment(const AttributedString& attributed_string, const Range& range);
        /// @brief Creates a new `NSTextLineFragment` instance and returns a handle to it.
        explicit TextLineFragment(const std::string& string, const std::map<std::string, Object>& attributes, const Range& range);
        TextLineFragment();
        /// @brief Creates a null handle that refers to no native object.
        TextLineFragment(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextLineFragment(Adopt adopt);
        /**
     * @brief Calls `-[NSTextLineFragment characterIndexForPoint:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t character_index_for_point(const Point& point) const;
        /**
     * @brief Calls `-[NSTextLineFragment drawAtPoint:inContext:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @param context Argument converted to the Objective-C parameter of the same role.
     */
        void draw_at_point(const Point& point, const CGContext& context) const;
        /**
     * @brief Calls `-[NSTextLineFragment fractionOfDistanceThroughGlyphForPoint:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double fraction_of_distance_through_glyph_for_point(const Point& point) const;
        /**
     * @brief Calls `-[NSTextLineFragment locationForCharacterAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point location_for_character_at_index(std::int64_t index) const;
        /**
     * @brief Returns the `attributedString` property of `NSTextLineFragment`.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_string() const;
        /**
     * @brief Returns the `characterRange` property of `NSTextLineFragment`.
     * @return The converted Objective-C result.
     */
        Range character_range() const;
        /**
     * @brief Returns the `glyphOrigin` property of `NSTextLineFragment`.
     * @return The converted Objective-C result.
     */
        Point glyph_origin() const;
        /**
     * @brief Returns the `typographicBounds` property of `NSTextLineFragment`.
     * @return The converted Objective-C result.
     */
        Rect typographic_bounds() const;
    };
}
