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
         * @param text_ranges Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextSelection text_selection_with_text_ranges(const std::vector<TextRange>& text_ranges) const;
        /**
         * @brief Returns the `affinity` property of `NSTextSelection`.
         * @return The converted Objective-C result.
         */
        TextSelectionAffinity affinity() const;
        /**
         * @brief Returns the `anchorPositionOffset` property of `NSTextSelection`.
         * @return The converted Objective-C result.
         */
        double anchor_position_offset() const;
        /**
         * @brief Sets the `anchorPositionOffset` property of `NSTextSelection`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_anchor_position_offset(double value) const;
        /**
         * @brief Returns the `granularity` property of `NSTextSelection`.
         * @return The converted Objective-C result.
         */
        TextSelectionGranularity granularity() const;
        /**
         * @brief Returns the `logical` property of `NSTextSelection`.
         * @return The converted Objective-C result.
         */
        bool is_logical() const;
        /**
         * @brief Sets the `logical` property of `NSTextSelection`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_logical(bool value) const;
        /**
         * @brief Returns the `secondarySelectionLocation` property of `NSTextSelection`.
         * @return The converted Objective-C result.
         */
        Object secondary_selection_location() const;
        /**
         * @brief Sets the `secondarySelectionLocation` property of `NSTextSelection`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_secondary_selection_location(const Object& value) const;
        /**
         * @brief Returns the `textRanges` property of `NSTextSelection`.
         * @return The converted Objective-C result.
         */
        std::vector<TextRange> text_ranges() const;
        /**
         * @brief Returns the `transient` property of `NSTextSelection`.
         * @return The converted Objective-C result.
         */
        bool is_transient() const;
        /**
         * @brief Returns the `typingAttributes` property of `NSTextSelection`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> typing_attributes() const;
        /**
         * @brief Sets the `typingAttributes` property of `NSTextSelection`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_typing_attributes(const std::map<std::string, Object>& value) const;
    };
}
