#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/paragraph_style.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ParagraphStyle;
    class TextList;
    class TextTab;

    /**
     * @brief C++ handle for the Objective-C class `NSMutableParagraphStyle` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ParagraphStyle.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MutableParagraphStyle mutable_paragraph_style;
     * mutable_paragraph_style.set_allows_default_tightening_for_truncation(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MutableParagraphStyle mutable_paragraph_style{};
     * mutable_paragraph_style.set_allows_default_tightening_for_truncation(true);
     * auto allows_default_tightening_for_truncation = mutable_paragraph_style.allows_default_tightening_for_truncation();
     * mutable_paragraph_style.set_base_writing_direction(cocoon::WritingDirection::Natural);
     * auto base_writing_direction = mutable_paragraph_style.base_writing_direction();
     * mutable_paragraph_style.set_default_tab_interval(1);
     * auto default_tab_interval = mutable_paragraph_style.default_tab_interval();
     * mutable_paragraph_style.add_tab_stop(cocoon::TextTab());
     * mutable_paragraph_style.remove_tab_stop(cocoon::TextTab());
     * mutable_paragraph_style.set_paragraph_style(cocoon::ParagraphStyle());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsmutableparagraphstyle
     */
    class MutableParagraphStyle : public ParagraphStyle
    {
    public:
        /// @brief Creates a new `NSMutableParagraphStyle` instance and returns a handle to it.
        explicit MutableParagraphStyle();
        /// @brief Creates a null handle that refers to no native object.
        MutableParagraphStyle(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MutableParagraphStyle(Adopt adopt);
        using ParagraphStyle::allows_default_tightening_for_truncation;
        using ParagraphStyle::base_writing_direction;
        using ParagraphStyle::default_tab_interval;
        using ParagraphStyle::first_line_head_indent;
        using ParagraphStyle::head_indent;
        using ParagraphStyle::hyphenation_factor;
        using ParagraphStyle::line_break_mode;
        using ParagraphStyle::line_break_strategy;
        using ParagraphStyle::line_height_multiple;
        using ParagraphStyle::line_spacing;
        using ParagraphStyle::maximum_line_height;
        using ParagraphStyle::minimum_line_height;
        using ParagraphStyle::paragraph_spacing;
        using ParagraphStyle::paragraph_spacing_before;
        using ParagraphStyle::tab_stops;
        using ParagraphStyle::tail_indent;
        using ParagraphStyle::text_lists;
        using ParagraphStyle::uses_default_hyphenation;
        /**
     * @brief Calls `-[NSMutableParagraphStyle addTabStop:]`.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     */
        void add_tab_stop(const TextTab& an_object) const;
        /**
     * @brief Calls `-[NSMutableParagraphStyle removeTabStop:]`.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     */
        void remove_tab_stop(const TextTab& an_object) const;
        /**
     * @brief Calls `-[NSMutableParagraphStyle setParagraphStyle:]`.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     */
        void set_paragraph_style(const ParagraphStyle& obj) const;
        /**
     * @brief Returns the `allowsDefaultTighteningForTruncation` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        bool allows_default_tightening_for_truncation() const;
        /**
     * @brief Sets the `allowsDefaultTighteningForTruncation` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_default_tightening_for_truncation(bool value) const;
        /**
     * @brief Returns the `baseWritingDirection` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        WritingDirection base_writing_direction() const;
        /**
     * @brief Sets the `baseWritingDirection` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_base_writing_direction(WritingDirection value) const;
        /**
     * @brief Returns the `defaultTabInterval` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        double default_tab_interval() const;
        /**
     * @brief Sets the `defaultTabInterval` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_tab_interval(double value) const;
        /**
     * @brief Returns the `firstLineHeadIndent` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        double first_line_head_indent() const;
        /**
     * @brief Sets the `firstLineHeadIndent` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_first_line_head_indent(double value) const;
        /**
     * @brief Returns the `headIndent` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        double head_indent() const;
        /**
     * @brief Sets the `headIndent` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_head_indent(double value) const;
        /**
     * @brief Returns the `hyphenationFactor` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        float hyphenation_factor() const;
        /**
     * @brief Sets the `hyphenationFactor` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hyphenation_factor(float value) const;
        /**
     * @brief Returns the `lineBreakMode` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        LineBreakMode line_break_mode() const;
        /**
     * @brief Sets the `lineBreakMode` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_break_mode(LineBreakMode value) const;
        /**
     * @brief Returns the `lineBreakStrategy` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        LineBreakStrategy line_break_strategy() const;
        /**
     * @brief Sets the `lineBreakStrategy` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_break_strategy(LineBreakStrategy value) const;
        /**
     * @brief Returns the `lineHeightMultiple` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        double line_height_multiple() const;
        /**
     * @brief Sets the `lineHeightMultiple` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_height_multiple(double value) const;
        /**
     * @brief Returns the `lineSpacing` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        double line_spacing() const;
        /**
     * @brief Sets the `lineSpacing` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_spacing(double value) const;
        /**
     * @brief Returns the `maximumLineHeight` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        double maximum_line_height() const;
        /**
     * @brief Sets the `maximumLineHeight` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_line_height(double value) const;
        /**
     * @brief Returns the `minimumLineHeight` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        double minimum_line_height() const;
        /**
     * @brief Sets the `minimumLineHeight` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_line_height(double value) const;
        /**
     * @brief Returns the `paragraphSpacing` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        double paragraph_spacing() const;
        /**
     * @brief Sets the `paragraphSpacing` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_paragraph_spacing(double value) const;
        /**
     * @brief Returns the `paragraphSpacingBefore` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        double paragraph_spacing_before() const;
        /**
     * @brief Sets the `paragraphSpacingBefore` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_paragraph_spacing_before(double value) const;
        /**
     * @brief Returns the `tabStops` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        std::vector<TextTab> tab_stops() const;
        /**
     * @brief Sets the `tabStops` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tab_stops(const std::vector<TextTab>& value) const;
        /**
     * @brief Returns the `tailIndent` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        double tail_indent() const;
        /**
     * @brief Sets the `tailIndent` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tail_indent(double value) const;
        /**
     * @brief Returns the `textLists` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        std::vector<TextList> text_lists() const;
        /**
     * @brief Sets the `textLists` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_lists(const std::vector<TextList>& value) const;
        /**
     * @brief Returns the `usesDefaultHyphenation` property of `NSMutableParagraphStyle`.
     * @return The converted Objective-C result.
     */
        bool uses_default_hyphenation() const;
        /**
     * @brief Sets the `usesDefaultHyphenation` property of `NSMutableParagraphStyle`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_default_hyphenation(bool value) const;
    };
}
