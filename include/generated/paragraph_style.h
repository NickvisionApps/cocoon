#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class TextList;
    class TextTab;

    /**
     * @brief C++ handle for the Objective-C class `NSParagraphStyle` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ParagraphStyle paragraph_style;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsparagraphstyle
     */
    class ParagraphStyle : public Object
    {
    public:
        /// @brief Creates a new `NSParagraphStyle` instance and returns a handle to it.
        explicit ParagraphStyle();
        /// @brief Creates a null handle that refers to no native object.
        ParagraphStyle(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ParagraphStyle(Adopt adopt);
        /**
         * @brief Calls `+[NSParagraphStyle defaultWritingDirectionForLanguage:]`.
         * @param language_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static WritingDirection default_writing_direction_for_language(const std::string& language_name);
        /**
         * @brief Returns the `allowsDefaultTighteningForTruncation` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        bool allows_default_tightening_for_truncation() const;
        /**
         * @brief Returns the `baseWritingDirection` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        WritingDirection base_writing_direction() const;
        /**
         * @brief Returns the `defaultParagraphStyle` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        static ParagraphStyle default_paragraph_style();
        /**
         * @brief Returns the `defaultTabInterval` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        double default_tab_interval() const;
        /**
         * @brief Returns the `firstLineHeadIndent` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        double first_line_head_indent() const;
        /**
         * @brief Returns the `headIndent` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        double head_indent() const;
        /**
         * @brief Returns the `hyphenationFactor` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        float hyphenation_factor() const;
        /**
         * @brief Returns the `lineBreakMode` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        LineBreakMode line_break_mode() const;
        /**
         * @brief Returns the `lineBreakStrategy` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        LineBreakStrategy line_break_strategy() const;
        /**
         * @brief Returns the `lineHeightMultiple` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        double line_height_multiple() const;
        /**
         * @brief Returns the `lineSpacing` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        double line_spacing() const;
        /**
         * @brief Returns the `maximumLineHeight` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        double maximum_line_height() const;
        /**
         * @brief Returns the `minimumLineHeight` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        double minimum_line_height() const;
        /**
         * @brief Returns the `paragraphSpacing` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        double paragraph_spacing() const;
        /**
         * @brief Returns the `paragraphSpacingBefore` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        double paragraph_spacing_before() const;
        /**
         * @brief Returns the `tabStops` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        std::vector<TextTab> tab_stops() const;
        /**
         * @brief Returns the `tailIndent` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        double tail_indent() const;
        /**
         * @brief Returns the `textLists` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        std::vector<TextList> text_lists() const;
        /**
         * @brief Returns the `usesDefaultHyphenation` property of `NSParagraphStyle`.
         * @return The converted Objective-C result.
         */
        bool uses_default_hyphenation() const;
    };
}
