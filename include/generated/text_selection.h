#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class TextRange;

    /**
     * @brief C++ handle for the Objective-C class `NSTextSelection` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextSelection text_selection{cocoon::TextRange(), cocoon::TextSelectionAffinity::Upstream, cocoon::TextSelectionGranularity::Character};
     * text_selection.set_anchor_position_offset(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextSelection text_selection{cocoon::TextRange(), cocoon::TextSelectionAffinity::Upstream, cocoon::TextSelectionGranularity::Character};
     * text_selection.set_anchor_position_offset(1);
     * auto anchor_position_offset = text_selection.anchor_position_offset();
     * text_selection.set_logical(true);
     * auto logical = text_selection.is_logical();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextselection
     */
    class TextSelection : public Object
    {
    public:
        /// @brief Creates a new `NSTextSelection` instance and returns a handle to it.
        explicit TextSelection(const Object& location, TextSelectionAffinity affinity);
        /// @brief Creates a new `NSTextSelection` instance and returns a handle to it.
        explicit TextSelection(const TextRange& range, TextSelectionAffinity affinity, TextSelectionGranularity granularity);
        /// @brief Creates a new `NSTextSelection` instance and returns a handle to it.
        explicit TextSelection(const std::vector<TextRange>& text_ranges, TextSelectionAffinity affinity, TextSelectionGranularity granularity);
        TextSelection();
        /// @brief Creates a null handle that refers to no native object.
        TextSelection(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextSelection(Adopt adopt);
        /**
         * @brief Calls `-[NSTextSelection textSelectionWithTextRanges:]`.
         * @details Returns a copy of this selection, replacing the text ranges with the ones you provide. All other attributes remain the same. - Parameters: - textRanges: The new text ranges for the returned selection. - Returns: A new ''NSTextSelection'' with the updated ranges.
         * @param text_ranges Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextSelection text_selection_with_text_ranges(const std::vector<TextRange>& text_ranges) const;
        /**
         * @brief Returns the `affinity` property of `NSTextSelection`.
         * @details Either upstream or downstream selection. 'NSTextSelectionAffinityDownstream' by default. For a 0-length selection, it describes the visual location of the text cursor between the head of line containing the selection location (downstream) or tail of the previous line (upstream). For a selection with contents, it describes the logical direction of the non-anchored edge of the selection.
         * @return The converted Objective-C result.
         */
        TextSelectionAffinity affinity() const;
        /**
         * @brief Returns the `anchorPositionOffset` property of `NSTextSelection`.
         * @details The anchor position offset from the beginning of a line fragment in visual order. That is, from the left for a horizontal line fragment and from the top for a vertical. Navigating between lines uses this point when the current line fragment associated with the selection is shorter than the next line visited. The default value is '0.0'.
         * @return The converted Objective-C result.
         */
        double anchor_position_offset() const;
        /**
         * @brief Sets the `anchorPositionOffset` property of `NSTextSelection`.
         * @details The anchor position offset from the beginning of a line fragment in visual order. That is, from the left for a horizontal line fragment and from the top for a vertical. Navigating between lines uses this point when the current line fragment associated with the selection is shorter than the next line visited. The default value is '0.0'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_anchor_position_offset(double value) const;
        /**
         * @brief Returns the `granularity` property of `NSTextSelection`.
         * @details The granularity of the selection. 'NSTextSelectionGranularityCharacter' by default. Extending operations should modify the selection by the granularity.
         * @return The converted Objective-C result.
         */
        TextSelectionGranularity granularity() const;
        /**
         * @brief Returns the `logical` property of `NSTextSelection`.
         * @details A Boolean value indicating whether the selection should be interpreted as logical or visual.
         * @return The converted Objective-C result.
         */
        bool is_logical() const;
        /**
         * @brief Sets the `logical` property of `NSTextSelection`.
         * @details A Boolean value indicating whether the selection should be interpreted as logical or visual.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_logical(bool value) const;
        /**
         * @brief Returns the `secondarySelectionLocation` property of `NSTextSelection`.
         * @details The secondary character location when the user taps or clicks at a directional boundary. Setting a non-nil location has a side effect of making ''logical'' 'false'.
         * @return The converted Objective-C result.
         */
        Object secondary_selection_location() const;
        /**
         * @brief Sets the `secondarySelectionLocation` property of `NSTextSelection`.
         * @details The secondary character location when the user taps or clicks at a directional boundary. Setting a non-nil location has a side effect of making ''logical'' 'false'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_secondary_selection_location(const Object& value) const;
        /**
         * @brief Returns the `textRanges` property of `NSTextSelection`.
         * @details An array of disjoint logical ranges in the selection. The array must be logically ordered. When editing, all ranges in a text selection constitute a single insertion point.
         * @return The converted Objective-C result.
         */
        std::vector<TextRange> text_ranges() const;
        /**
         * @brief Returns the `transient` property of `NSTextSelection`.
         * @details A Boolean value indicating whether this is a transient text selection during drag handling.
         * @return The converted Objective-C result.
         */
        bool is_transient() const;
        /**
         * @brief Returns the `typingAttributes` property of `NSTextSelection`.
         * @details The template attributes used for characters replacing the contents of this selection.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> typing_attributes() const;
        /**
         * @brief Sets the `typingAttributes` property of `NSTextSelection`.
         * @details The template attributes used for characters replacing the contents of this selection.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_typing_attributes(const std::map<std::string, Object>& value) const;
    };
}
