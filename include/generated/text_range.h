#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSTextRange` (AppKit).
     * @details A class that represents a contiguous range between two locations inside document contents. An 'NSTextRange' consists of the starting and terminating locations. There the two basic properties: ''location'' and ''endLocation'', respectively. The terminating ''location'', ''endLocation'', is directly following the last location in the range. For example, a location contains a range if '(range.location \<= location) && (location \< range.endLocation)' is 'true'.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextRange text_range(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextRange text_range(nullptr);
     * text_range.contains_range(cocoon::TextRange());
     * text_range.intersects_with_text_range(cocoon::TextRange());
     * text_range.is_equal_to_text_range(cocoon::TextRange());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextrange
     */
    class TextRange : public Object
    {
    public:
        /// @brief Creates a new `NSTextRange` instance and returns a handle to it.
        explicit TextRange(const Object& location);
        /// @brief Creates a new `NSTextRange` instance and returns a handle to it.
        explicit TextRange(const Object& location, const Object& end_location);
        TextRange();
        /// @brief Creates a null handle that refers to no native object.
        TextRange(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextRange(Adopt adopt);
        /**
         * @brief Calls `-[NSTextRange containsLocation:]`.
         * @details Determines if the text location you specify is in the current text range. - Parameters: - location: An ''NSTextLocation''. - Returns: Returns 'true' if the location is in the range otherwise 'false' .
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool contains_location(const Object& location) const;
        /**
         * @brief Calls `-[NSTextRange containsRange:]`.
         * @details Determines if the text range you specify is in the current text range. - Parameters: - textRange: An ''NSTextRange''. - Returns: Returns 'true' if the range you provide is in the current range; otherwise 'false'.
         * @param text_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool contains_range(const TextRange& text_range) const;
        /**
         * @brief Calls `-[NSTextRange intersectsWithTextRange:]`.
         * @details Determines if two ranges intersect. - Parameters: - textRange: The range used to compare against the current range to evaluate for differences. - Returns: Returns 'true' if the ranges intersect.
         * @param text_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool intersects_with_text_range(const TextRange& text_range) const;
        /**
         * @brief Calls `-[NSTextRange isEqualToTextRange:]`.
         * @details Compares two text ranges. - Parameters: - textRange: The range used to compare against the current range to evaluate for differences. - Returns: Returns 'true' if the ranges are equal.
         * @param text_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_equal_to_text_range(const TextRange& text_range) const;
        /**
         * @brief Calls `-[NSTextRange textRangeByFormingUnionWithTextRange:]`.
         * @details Returns a new text range by forming the union with the text range you provide. - Parameters: - textRange: The range to use to create the union. - Returns: An ''NSTextRange'' that represent the union of the two ranges.
         * @param text_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextRange text_range_by_forming_union_with_text_range(const TextRange& text_range) const;
        /**
         * @brief Calls `-[NSTextRange textRangeByIntersectingWithTextRange:]`.
         * @details Returns the range, if any, where two text ranges intersect. - Parameters: - textRange: The range used to compare against the current range to evaluate for differences. - Returns: An \<doc://com.apple.documentation/documentation/foundation/nsrange> that represents the intersection of the ranges, or 'nil' if they don't intersect.
         * @param text_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextRange text_range_by_intersecting_with_text_range(const TextRange& text_range) const;
        /**
         * @brief Returns the `empty` property of `NSTextRange`.
         * @details Returns whether the text range is empty.
         * @return The converted Objective-C result.
         */
        bool is_empty() const;
    };
}
