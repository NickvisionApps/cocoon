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
     * @details A class that represents a line fragment as a single textual layout and rendering unit inside a text layout fragment.
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
         * @details Returns the character index for the point inside the line fragment coordinate system. - Parameters: - point: A \<doc://com.apple.documentation/documentation/corefoundation/cgpoint> in the line fragment coordinate system. - Returns: The character index nearest to the point.
         * @param point Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t character_index_for_point(const Point& point) const;
        /**
         * @brief Calls `-[NSTextLineFragment drawAtPoint:inContext:]`.
         * @details Renders the line fragment contents at the specified point. The origin can be specified as '(CGRectGetMinX(typographicBounds), CGRectGetMinY(typographicBounds))' relative to the parent layout fragment coordinate system. - Parameters: - point: The origin as a \<doc://com.apple.documentation/documentation/corefoundation/cgpoint>. - context: The graphics context to draw into.
         * @param point Argument converted to the Objective-C parameter of the same role.
         * @param context Argument converted to the Objective-C parameter of the same role.
         */
        void draw_at_point(const Point& point, const CGContext& context) const;
        /**
         * @brief Calls `-[NSTextLineFragment fractionOfDistanceThroughGlyphForPoint:]`.
         * @details Returns the fraction of the distance through the glyph for the point. The fraction of distance is from the upstream edge. - Parameters: - point: A \<doc://com.apple.documentation/documentation/corefoundation/cgpoint> in the line fragment coordinate system. - Returns: A value between 0.0 and 1.0 indicating the fraction through the glyph.
         * @param point Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double fraction_of_distance_through_glyph_for_point(const Point& point) const;
        /**
         * @brief Calls `-[NSTextLineFragment locationForCharacterAtIndex:]`.
         * @details Returns the location of the character at the specified index. The location is on the upstream edge of the glyph, in the coordinate system relative to the line fragment origin. - Parameters: - index: The character index within this line fragment. - Returns: A \<doc://com.apple.documentation/documentation/corefoundation/cgpoint> on the upstream edge of the glyph, in the coordinate system relative to the line fragment origin.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Point location_for_character_at_index(std::int64_t index) const;
        /**
         * @brief Returns the `attributedString` property of `NSTextLineFragment`.
         * @details The source attributed string.
         * @return The converted Objective-C result.
         */
        AttributedString attributed_string() const;
        /**
         * @brief Returns the `characterRange` property of `NSTextLineFragment`.
         * @details The string range for the source attributed string corresponding to this line fragment.
         * @return The converted Objective-C result.
         */
        Range character_range() const;
        /**
         * @brief Returns the `glyphOrigin` property of `NSTextLineFragment`.
         * @details The rendering origin for the leftmost glyph in the line fragment coordinate system.
         * @return The converted Objective-C result.
         */
        Point glyph_origin() const;
        /**
         * @brief Returns the `typographicBounds` property of `NSTextLineFragment`.
         * @details The typographic bounds specifying the dimensions of the line fragment for laying out line fragments to each other. The origin value is offset from the beginning of the line fragment group belonging to the parent layout fragment.
         * @return The converted Objective-C result.
         */
        Rect typographic_bounds() const;
    };
}
