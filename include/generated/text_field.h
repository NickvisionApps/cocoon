#pragma once

#include "generated/availability.h"
#include "generated/control.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Color;
    class Notification;
    class Text;
    class TextCheckingResult;
    class TextView;

    /**
     * @brief An editable single line text field (NSTextField).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * cocoon::TextField field;
     * field.set_placeholder_string("Name");
     * field.text_changed().connect([](const std::string& text) {});
     * field.editing_finished().connect([] {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextField text_field{"text"};
     * text_field.set_allows_character_picker_touch_bar_item(true);
     * auto allows_character_picker_touch_bar_item = text_field.allows_character_picker_touch_bar_item();
     * text_field.set_allows_default_tightening_for_truncation(true);
     * auto allows_default_tightening_for_truncation = text_field.allows_default_tightening_for_truncation();
     * text_field.set_allows_editing_text_attributes(true);
     * auto allows_editing_text_attributes = text_field.allows_editing_text_attributes();
     * auto made_0 = cocoon::TextField::label_with_attributed_string(cocoon::AttributedString());
     * auto made_1 = cocoon::TextField::label_with_string("text");
     * text_field.text_did_begin_editing(cocoon::Notification());
     * text_field.text_did_change(cocoon::Notification());
     * text_field.text_did_end_editing(cocoon::Notification());
     * text_field.editing_finished().connect([]() {});
     * text_field.text_changed().connect([](std::string a0) {});
     * text_field.control_text_did_begin_editing().connect([](cocoon::Notification a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextfield
     */
    class TextField : public Control
    {
    public:
        /// @brief Creates a new `NSTextField` instance and returns a handle to it.
        explicit TextField(const std::string& text = "");
        /// @brief Creates a null handle that refers to no native object.
        TextField(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextField(Adopt adopt);
        using Responder::accepts_first_responder;
        using View::set_background_color;
        /**
     * @brief Calls `+[NSTextField labelWithAttributedString:]`.
     * @details Creates a non-editable, non-selectable text field that displays attributed text. The line break mode of this field is determined by the attributed string's NSParagraphStyle attribute. \@param attributedStringValue The attributed string to display in the field. \@return An initialized text field object.
     * @param attributed_string_value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextField label_with_attributed_string(const AttributedString& attributed_string_value);
        /**
     * @brief Calls `+[NSTextField labelWithString:]`.
     * @details Creates a non-wrapping, non-editable, non-selectable text field that displays text in the default system font. \@param stringValue The title text to display in the field. \@return An initialized text field object.
     * @param string_value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextField label_with_string(const std::string& string_value);
        /**
     * @brief Calls `-[NSTextField selectText:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void select_text(const Object& sender) const;
        /**
     * @brief Calls `-[NSTextField textDidBeginEditing:]`.
     * @param notification Argument converted to the Objective-C parameter of the same role.
     */
        void text_did_begin_editing(const Notification& notification) const;
        /**
     * @brief Calls `-[NSTextField textDidChange:]`.
     * @param notification Argument converted to the Objective-C parameter of the same role.
     */
        void text_did_change(const Notification& notification) const;
        /**
     * @brief Calls `-[NSTextField textDidEndEditing:]`.
     * @param notification Argument converted to the Objective-C parameter of the same role.
     */
        void text_did_end_editing(const Notification& notification) const;
        /**
     * @brief Calls `+[NSTextField textFieldWithString:]`.
     * @details Creates a non-wrapping editable text field. \@param stringValue The initial contents of the text field, or empty string for an initially empty text field. \@return An initialized text field object.
     * @param string_value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextField text_field_with_string(const std::string& string_value);
        /**
     * @brief Calls `-[NSTextField textShouldBeginEditing:]`.
     * @param text_object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool text_should_begin_editing(const Text& text_object) const;
        /**
     * @brief Calls `-[NSTextField textShouldEndEditing:]`.
     * @param text_object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool text_should_end_editing(const Text& text_object) const;
        /**
     * @brief Calls `+[NSTextField wrappingLabelWithString:]`.
     * @details Creates a wrapping, non-editable, selectable text field that displays text in the default system font. \@param stringValue The title text to display in the field. \@return An initialized text field object.
     * @param string_value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextField wrapping_label_with_string(const std::string& string_value);
        /**
     * @brief Returns the `acceptsFirstResponder` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        bool accepts_first_responder() const;
        /**
     * @brief Returns the `allowsCharacterPickerTouchBarItem` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        bool allows_character_picker_touch_bar_item() const;
        /**
     * @brief Sets the `allowsCharacterPickerTouchBarItem` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_character_picker_touch_bar_item(bool value) const;
        /**
     * @brief Returns the `allowsDefaultTighteningForTruncation` property of `NSTextField`.
     * @details Maps to -[NSParagraphStyle allowsDefaultTighteningForTruncation] in rendering and sizing the text field. Ignored when the content value is an attributed string.
     * @return The converted Objective-C result.
     */
        bool allows_default_tightening_for_truncation() const;
        /**
     * @brief Sets the `allowsDefaultTighteningForTruncation` property of `NSTextField`.
     * @details Maps to -[NSParagraphStyle allowsDefaultTighteningForTruncation] in rendering and sizing the text field. Ignored when the content value is an attributed string.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_default_tightening_for_truncation(bool value) const;
        /**
     * @brief Returns the `allowsEditingTextAttributes` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        bool allows_editing_text_attributes() const;
        /**
     * @brief Sets the `allowsEditingTextAttributes` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_editing_text_attributes(bool value) const;
        /**
     * @brief Returns the `allowsWritingTools` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        bool allows_writing_tools() const;
        /**
     * @brief Sets the `allowsWritingTools` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_writing_tools(bool value) const;
        /**
     * @brief Returns the `allowsWritingToolsAffordance` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        bool allows_writing_tools_affordance() const;
        /**
     * @brief Sets the `allowsWritingToolsAffordance` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_writing_tools_affordance(bool value) const;
        /**
     * @brief Returns the `automaticTextCompletionEnabled` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        bool is_automatic_text_completion_enabled() const;
        /**
     * @brief Sets the `automaticTextCompletionEnabled` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_automatic_text_completion_enabled(bool value) const;
        /**
     * @brief Returns the `backgroundColor` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        Color background_color() const;
        /**
     * @brief Sets the `backgroundColor` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_color(const Color& value) const;
        /**
     * @brief Returns the `bezelStyle` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        TextFieldBezelStyle bezel_style() const;
        /**
     * @brief Sets the `bezelStyle` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bezel_style(TextFieldBezelStyle value) const;
        /**
     * @brief Returns the `bezeled` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        bool is_bezeled() const;
        /**
     * @brief Sets the `bezeled` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bezeled(bool value) const;
        /**
     * @brief Returns the `bordered` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        bool is_bordered() const;
        /**
     * @brief Sets the `bordered` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bordered(bool value) const;
        /**
     * @brief Returns the `drawsBackground` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        bool draws_background() const;
        /**
     * @brief Sets the `drawsBackground` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_draws_background(bool value) const;
        /**
     * @brief Returns the `editable` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        bool is_editable() const;
        /**
     * @brief Sets the `editable` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_editable(bool value) const;
        /**
     * @brief Returns the `importsGraphics` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        bool imports_graphics() const;
        /**
     * @brief Sets the `importsGraphics` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_imports_graphics(bool value) const;
        /**
     * @brief Returns the `lineBreakStrategy` property of `NSTextField`.
     * @details Specifies the line break strategies that may be used for laying out the text in this text field. If this property is not set, the default for non-editable and selectable text fields is NSLineBreakStrategyStandard and the default for editable text fields is NSLineBreakStrategyNone. If the text field contains an attributed string value with paragraph style(s) that specify a set of line break strategies, the set of strategies in the paragraph style(s) will be used instead of the set of strategies defined by this property.
     * @return The converted Objective-C result.
     */
        LineBreakStrategy line_break_strategy() const;
        /**
     * @brief Sets the `lineBreakStrategy` property of `NSTextField`.
     * @details Specifies the line break strategies that may be used for laying out the text in this text field. If this property is not set, the default for non-editable and selectable text fields is NSLineBreakStrategyStandard and the default for editable text fields is NSLineBreakStrategyNone. If the text field contains an attributed string value with paragraph style(s) that specify a set of line break strategies, the set of strategies in the paragraph style(s) will be used instead of the set of strategies defined by this property.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_break_strategy(LineBreakStrategy value) const;
        /**
     * @brief Returns the `maximumNumberOfLines` property of `NSTextField`.
     * @details For text that wraps (see NSCell’s lineBreakMode), this property determines the maximum number of lines to display. A value of 0 means there is no limit, which is the default, and the text fills the cell’s bounds. If the text reaches the number of lines allowed, or the height of the container cannot accommodate the number of lines needed, the text will be clipped (or truncated if truncatesLastVisibleLine is set). The value of this property also affects -[NSControl sizeThatFits:], -[NSView fittingSize] and -[NSView intrinsicContentSize]. Most importantly, if the value of this property is not 1, multiple lines may be used to find the field’s intrinsicContentSize. Prior to 10.11, the intrinsicContentSize would be determined as if the maximumNumberOfLines was 1.
     * @return The converted Objective-C result.
     */
        std::int64_t maximum_number_of_lines() const;
        /**
     * @brief Sets the `maximumNumberOfLines` property of `NSTextField`.
     * @details For text that wraps (see NSCell’s lineBreakMode), this property determines the maximum number of lines to display. A value of 0 means there is no limit, which is the default, and the text fills the cell’s bounds. If the text reaches the number of lines allowed, or the height of the container cannot accommodate the number of lines needed, the text will be clipped (or truncated if truncatesLastVisibleLine is set). The value of this property also affects -[NSControl sizeThatFits:], -[NSView fittingSize] and -[NSView intrinsicContentSize]. Most importantly, if the value of this property is not 1, multiple lines may be used to find the field’s intrinsicContentSize. Prior to 10.11, the intrinsicContentSize would be determined as if the maximumNumberOfLines was 1.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_number_of_lines(std::int64_t value) const;
        /**
     * @brief Returns the `placeholderAttributedString` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        AttributedString placeholder_attributed_string() const;
        /**
     * @brief Sets the `placeholderAttributedString` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_placeholder_attributed_string(const AttributedString& value) const;
        /**
     * @brief Returns the `placeholderAttributedStrings` property of `NSTextField`.
     * @details An array of NSStrings that will be animated to cycle through one by one when the textField is first responder. No animation happend when there is only string in the array, or when text field is not first responder. The text field's placeholderString property points to the first string in placeholderStrings.
     * @return The converted Objective-C result.
     */
        std::vector<AttributedString> placeholder_attributed_strings() const;
        /**
     * @brief Sets the `placeholderAttributedStrings` property of `NSTextField`.
     * @details An array of NSStrings that will be animated to cycle through one by one when the textField is first responder. No animation happend when there is only string in the array, or when text field is not first responder. The text field's placeholderString property points to the first string in placeholderStrings.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_placeholder_attributed_strings(const std::vector<AttributedString>& value) const;
        /**
     * @brief Returns the `placeholderString` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        std::string placeholder_string() const;
        /**
     * @brief Sets the `placeholderString` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_placeholder_string(const std::string& value) const;
        /**
     * @brief Returns the `placeholderStrings` property of `NSTextField`.
     * @details An array of NSStrings that will be animated to cycle through one by one when the textField is first responder. No animation happend when there is only string in the array, or when text field is not first responder. The text field's placeholderString property points to the first string in placeholderStrings.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> placeholder_strings() const;
        /**
     * @brief Sets the `placeholderStrings` property of `NSTextField`.
     * @details An array of NSStrings that will be animated to cycle through one by one when the textField is first responder. No animation happend when there is only string in the array, or when text field is not first responder. The text field's placeholderString property points to the first string in placeholderStrings.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_placeholder_strings(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `preferredMaxLayoutWidth` property of `NSTextField`.
     * @details The preferredMaxLayoutWidth determines the maximum width of the intrinsicContentSize. If the text field wraps, the intrinsic height will be large enough to show the entire text contents at that width. The default is 0, which implies no maximum preferred width.
     * @return The converted Objective-C result.
     */
        double preferred_max_layout_width() const;
        /**
     * @brief Sets the `preferredMaxLayoutWidth` property of `NSTextField`.
     * @details The preferredMaxLayoutWidth determines the maximum width of the intrinsicContentSize. If the text field wraps, the intrinsic height will be large enough to show the entire text contents at that width. The default is 0, which implies no maximum preferred width.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_max_layout_width(double value) const;
        /**
     * @brief Returns the `resolvesNaturalAlignmentWithBaseWritingDirection` property of `NSTextField`.
     * @details Specifies the behavior for resolving ''NSTextAlignment/natural'' to the visual alignment. When set to 'true', the resolved visual alignment is determined by the resolved base writing direction; otherwise, it is using the user’s preferred language. The default value is 'false'.
     * @return The converted Objective-C result.
     */
        bool resolves_natural_alignment_with_base_writing_direction() const;
        /**
     * @brief Sets the `resolvesNaturalAlignmentWithBaseWritingDirection` property of `NSTextField`.
     * @details Specifies the behavior for resolving ''NSTextAlignment/natural'' to the visual alignment. When set to 'true', the resolved visual alignment is determined by the resolved base writing direction; otherwise, it is using the user’s preferred language. The default value is 'false'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_resolves_natural_alignment_with_base_writing_direction(bool value) const;
        /**
     * @brief Returns the `selectable` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        bool is_selectable() const;
        /**
     * @brief Sets the `selectable` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selectable(bool value) const;
        /**
     * @brief Returns the `textColor` property of `NSTextField`.
     * @return The converted Objective-C result.
     */
        Color text_color() const;
        /**
     * @brief Sets the `textColor` property of `NSTextField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_color(const Color& value) const;
        /// @brief Signal `editing_finished`: connect a callback with `editing_finished().connect(...)`.
        Signal<TextField, void()> editing_finished() const
        {
            return Signal<TextField, void()>(handle(), "editing_finished");
        }
        /// @brief Signal `text_changed`: connect a callback with `text_changed().connect(...)`.
        Signal<TextField, void(std::string)> text_changed() const
        {
            return Signal<TextField, void(std::string)>(handle(), "text_changed");
        }
        /// @brief Signal for the delegate/data-source method behind `control_text_did_begin_editing`; connect a callback with `control_text_did_begin_editing().connect(...)`.
        Signal<TextField, void(Notification)> control_text_did_begin_editing() const
        {
            return Signal<TextField, void(Notification)>(handle(), "control_text_did_begin_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `control_text_did_end_editing`; connect a callback with `control_text_did_end_editing().connect(...)`.
        Signal<TextField, void(Notification)> control_text_did_end_editing() const
        {
            return Signal<TextField, void(Notification)>(handle(), "control_text_did_end_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `control_text_did_change`; connect a callback with `control_text_did_change().connect(...)`.
        Signal<TextField, void(Notification)> control_text_did_change() const
        {
            return Signal<TextField, void(Notification)>(handle(), "control_text_did_change");
        }
        /// @brief Signal for the delegate/data-source method behind `control_text_should_begin_editing`; connect a callback with `control_text_should_begin_editing().connect(...)`.
        Signal<TextField, bool(Text)> control_text_should_begin_editing() const
        {
            return Signal<TextField, bool(Text)>(handle(), "control_text_should_begin_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `control_text_should_end_editing`; connect a callback with `control_text_should_end_editing().connect(...)`.
        Signal<TextField, bool(Text)> control_text_should_end_editing() const
        {
            return Signal<TextField, bool(Text)>(handle(), "control_text_should_end_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `did_fail_to_format_string_error_description`; connect a callback with `did_fail_to_format_string_error_description().connect(...)`.
        Signal<TextField, bool(std::string, std::string)> did_fail_to_format_string_error_description() const
        {
            return Signal<TextField, bool(std::string, std::string)>(handle(), "did_fail_to_format_string_error_description");
        }
        /// @brief Signal for the delegate/data-source method behind `did_fail_to_validate_partial_string_error_description`; connect a callback with `did_fail_to_validate_partial_string_error_description().connect(...)`.
        Signal<TextField, void(std::string, std::string)> did_fail_to_validate_partial_string_error_description() const
        {
            return Signal<TextField, void(std::string, std::string)>(handle(), "did_fail_to_validate_partial_string_error_description");
        }
        /// @brief Signal for the delegate/data-source method behind `is_valid_object`; connect a callback with `is_valid_object().connect(...)`.
        Signal<TextField, bool(Object)> is_valid_object() const
        {
            return Signal<TextField, bool(Object)>(handle(), "is_valid_object");
        }
        /// @brief Signal for the delegate/data-source method behind `text_view_do_command_by_selector`; connect a callback with `text_view_do_command_by_selector().connect(...)`.
        Signal<TextField, bool(TextView, std::string)> text_view_do_command_by_selector() const
        {
            return Signal<TextField, bool(TextView, std::string)>(handle(), "text_view_do_command_by_selector");
        }
        /// @brief Signal for the delegate/data-source method behind `text_view_completions_for_partial_word_range_index_of_selected_item`; connect a callback with `text_view_completions_for_partial_word_range_index_of_selected_item().connect(...)`.
        Signal<TextField, std::vector<std::string>(TextView, std::vector<std::string>, Range, std::int64_t*)> text_view_completions_for_partial_word_range_index_of_selected_item() const
        {
            return Signal<TextField, std::vector<std::string>(TextView, std::vector<std::string>, Range, std::int64_t*)>(handle(), "text_view_completions_for_partial_word_range_index_of_selected_item");
        }
        /// @brief Signal for the delegate/data-source method behind `text_view_candidates_for_selected_range`; connect a callback with `text_view_candidates_for_selected_range().connect(...)`.
        Signal<TextField, std::vector<Object>(TextView, Range)> text_view_candidates_for_selected_range() const
        {
            return Signal<TextField, std::vector<Object>(TextView, Range)>(handle(), "text_view_candidates_for_selected_range");
        }
        /// @brief Signal for the delegate/data-source method behind `text_field_text_view_candidates_for_selected_range`; connect a callback with `text_field_text_view_candidates_for_selected_range().connect(...)`.
        Signal<TextField, std::vector<TextCheckingResult>(TextView, std::vector<TextCheckingResult>, Range)> text_field_text_view_candidates_for_selected_range() const
        {
            return Signal<TextField, std::vector<TextCheckingResult>(TextView, std::vector<TextCheckingResult>, Range)>(handle(), "text_field_text_view_candidates_for_selected_range");
        }
        /// @brief Signal for the delegate/data-source method behind `text_view_should_select_candidate_at_index`; connect a callback with `text_view_should_select_candidate_at_index().connect(...)`.
        Signal<TextField, bool(TextView, std::uint64_t)> text_view_should_select_candidate_at_index() const
        {
            return Signal<TextField, bool(TextView, std::uint64_t)>(handle(), "text_view_should_select_candidate_at_index");
        }

    protected:
        static void bind_action_(void* native);
        static void bind_others_(void* native);
        static void install_delegate_delegate_(void* native);
    };
}
