#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Cell;
    class Event;
    class Font;
    class Formatter;
    class Text;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSControl` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Control control;
     * control.set_action("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Control control{};
     * control.set_action("text");
     * auto action = control.action();
     * control.set_alignment(cocoon::TextAlignment::Left);
     * auto alignment = control.alignment();
     * control.set_allows_expansion_tool_tips(true);
     * auto allows_expansion_tool_tips = control.allows_expansion_tool_tips();
     * control.abort_editing();
     * control.current_editor();
     * control.draw_cell(cocoon::Cell());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscontrol
     */
    class Control : public View
    {
    public:
        /// @brief Creates a new `NSControl` instance and returns a handle to it.
        explicit Control(const Rect& frame_rect);
        /// @brief Creates a new `NSControl` instance and returns a handle to it.
        explicit Control();
        /// @brief Creates a null handle that refers to no native object.
        Control(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Control(Adopt adopt);
        using View::tag;
        /**
     * @brief Calls `-[NSControl abortEditing]`.
     * @return The converted Objective-C result.
     */
        bool abort_editing() const;
        /**
     * @brief Calls `-[NSControl addTarget:action:forControlEvents:]`.
     * @details Associates a target object and action method with one or more control events. You can call this method multiple times to specify multiple target-action pairs for a particular event. Passing 'nil' as the target routes the action message up the responder chain. The control does not retain the target.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @param control_events Argument converted to the Objective-C parameter of the same role.
     */
        void add_target(const Object& target, const std::string& action, ControlEvents control_events) const;
        /**
     * @brief Calls `-[NSControl currentEditor]`.
     * @return The converted Objective-C result.
     */
        Text current_editor() const;
        /**
     * @brief Calls `-[NSControl drawCell:]`.
     * @param cell Argument converted to the Objective-C parameter of the same role.
     */
        void draw_cell(const Cell& cell) const;
        /**
     * @brief Calls `-[NSControl drawCellInside:]`.
     * @param cell Argument converted to the Objective-C parameter of the same role.
     */
        void draw_cell_inside(const Cell& cell) const;
        /**
     * @brief Calls `-[NSControl drawWithExpansionFrame:inView:]`.
     * @details Allows the control to perform custom expansion tool tip drawing. Note that the view may be different from the original view that the text appeared in.
     * @param content_frame Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     */
        void draw_with_expansion_frame(const Rect& content_frame, const View& view) const;
        /**
     * @brief Calls `-[NSControl editWithFrame:editor:delegate:event:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param text_obj Argument converted to the Objective-C parameter of the same role.
     * @param delegate Argument converted to the Objective-C parameter of the same role.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void edit_with_frame(const Rect& rect, const Text& text_obj, const Object& delegate, const Event& event) const;
        /**
     * @brief Calls `-[NSControl endEditing:]`.
     * @param text_obj Argument converted to the Objective-C parameter of the same role.
     */
        void end_editing(const Text& text_obj) const;
        /**
     * @brief Calls `-[NSControl expansionFrameWithFrame:]`.
     * @details Allows the control to return an expansion tool tip frame if contentFrame is too small for the entire contents in the view. When the mouse is hovered over the text in certain controls, the full contents will be shown in a special floating tool tip view. If the frame is not too small, return an empty rect, and no expansion tool tip view will be shown. By default, NSControl returns NSZeroRect, while some subclasses (such as NSTextField) will return the proper frame when required.
     * @param content_frame Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect expansion_frame_with_frame(const Rect& content_frame) const;
        /**
     * @brief Calls `-[NSControl invalidateIntrinsicContentSizeForCell:]`.
     * @param cell Argument converted to the Objective-C parameter of the same role.
     */
        void invalidate_intrinsic_content_size_for_cell(const Cell& cell) const;
        /**
     * @brief Calls `-[NSControl performClick:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void perform_click(const Object& sender) const;
        /**
     * @brief Calls `-[NSControl removeTarget:action:forControlEvents:]`.
     * @details Stops the delivery of the specified events to the given target object. Pass 'nil' as the action to remove all actions for the target.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @param control_events Argument converted to the Objective-C parameter of the same role.
     */
        void remove_target(const Object& target, const std::string& action, ControlEvents control_events) const;
        /**
     * @brief Calls `-[NSControl selectCell:]`.
     * @param cell Argument converted to the Objective-C parameter of the same role.
     */
        void select_cell(const Cell& cell) const;
        /**
     * @brief Calls `-[NSControl selectWithFrame:editor:delegate:start:length:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param text_obj Argument converted to the Objective-C parameter of the same role.
     * @param delegate Argument converted to the Objective-C parameter of the same role.
     * @param sel_start Argument converted to the Objective-C parameter of the same role.
     * @param sel_length Argument converted to the Objective-C parameter of the same role.
     */
        void select_with_frame(const Rect& rect, const Text& text_obj, const Object& delegate, std::int64_t sel_start, std::int64_t sel_length) const;
        /**
     * @brief Calls `-[NSControl selectedCell]`.
     * @return The converted Objective-C result.
     */
        Cell selected_cell() const;
        /**
     * @brief Calls `-[NSControl selectedTag]`.
     * @return The converted Objective-C result.
     */
        std::int64_t selected_tag() const;
        /**
     * @brief Calls `-[NSControl sendAction:to:]`.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool send_action(const std::string& action, const Object& target) const;
        /**
     * @brief Calls `-[NSControl sendActionOn:]`.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t send_action_on(EventMask mask) const;
        /**
     * @brief Calls `-[NSControl sizeThatFits:]`.
     * @param size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Size size_that_fits(const Size& size) const;
        /**
     * @brief Calls `-[NSControl sizeToFit]`.
     */
        void size_to_fit() const;
        /**
     * @brief Calls `-[NSControl takeDoubleValueFrom:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void take_double_value_from(const Object& sender) const;
        /**
     * @brief Calls `-[NSControl takeFloatValueFrom:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void take_float_value_from(const Object& sender) const;
        /**
     * @brief Calls `-[NSControl takeIntValueFrom:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void take_int_value_from(const Object& sender) const;
        /**
     * @brief Calls `-[NSControl takeIntegerValueFrom:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void take_integer_value_from(const Object& sender) const;
        /**
     * @brief Calls `-[NSControl takeObjectValueFrom:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void take_object_value_from(const Object& sender) const;
        /**
     * @brief Calls `-[NSControl takeStringValueFrom:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void take_string_value_from(const Object& sender) const;
        /**
     * @brief Calls `-[NSControl updateCell:]`.
     * @param cell Argument converted to the Objective-C parameter of the same role.
     */
        void update_cell(const Cell& cell) const;
        /**
     * @brief Calls `-[NSControl updateCellInside:]`.
     * @param cell Argument converted to the Objective-C parameter of the same role.
     */
        void update_cell_inside(const Cell& cell) const;
        /**
     * @brief Calls `-[NSControl validateEditing]`.
     */
        void validate_editing() const;
        /**
     * @brief Returns the `action` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        std::string action() const;
        /**
     * @brief Sets the `action` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_action(const std::string& value) const;
        /**
     * @brief Returns the `alignment` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        TextAlignment alignment() const;
        /**
     * @brief Sets the `alignment` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alignment(TextAlignment value) const;
        /**
     * @brief Returns the `allowsExpansionToolTips` property of `NSControl`.
     * @details Gets and sets the ability for expansion tool tips to be shown or not. Expansion tooltips are automatically shown when the cell can not show the full content. This is controlled by the NSCell API expansionFrameWithFrame:inView: and is drawn by drawWithExpansionFrame:inView:. The default value is NO. This value is encoded along with the control. In general, it is recommended to turn this on for NSTextFields in a View Based NSTableView.
     * @return The converted Objective-C result.
     */
        bool allows_expansion_tool_tips() const;
        /**
     * @brief Sets the `allowsExpansionToolTips` property of `NSControl`.
     * @details Gets and sets the ability for expansion tool tips to be shown or not. Expansion tooltips are automatically shown when the cell can not show the full content. This is controlled by the NSCell API expansionFrameWithFrame:inView: and is drawn by drawWithExpansionFrame:inView:. The default value is NO. This value is encoded along with the control. In general, it is recommended to turn this on for NSTextFields in a View Based NSTableView.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_expansion_tool_tips(bool value) const;
        /**
     * @brief Returns the `attributedStringValue` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_string_value() const;
        /**
     * @brief Sets the `attributedStringValue` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_string_value(const AttributedString& value) const;
        /**
     * @brief Returns the `baseWritingDirection` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        WritingDirection base_writing_direction() const;
        /**
     * @brief Sets the `baseWritingDirection` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_base_writing_direction(WritingDirection value) const;
        /**
     * @brief Returns the `cell` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        Cell cell() const;
        /**
     * @brief Sets the `cell` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_cell(const Cell& value) const;
        /**
     * @brief Returns the `cellClass` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        static std::string cell_class();
        /**
     * @brief Sets the `cellClass` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_cell_class(const std::string& value);
        /**
     * @brief Returns the `continuous` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        bool is_continuous() const;
        /**
     * @brief Sets the `continuous` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_continuous(bool value) const;
        /**
     * @brief Returns the `controlSize` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        ControlSize control_size() const;
        /**
     * @brief Sets the `controlSize` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_control_size(ControlSize value) const;
        /**
     * @brief Returns the `doubleValue` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        double double_value() const;
        /**
     * @brief Sets the `doubleValue` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_double_value(double value) const;
        /**
     * @brief Returns the `enabled` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        bool is_enabled() const;
        /**
     * @brief Sets the `enabled` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_enabled(bool value) const;
        /**
     * @brief Returns the `floatValue` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        float float_value() const;
        /**
     * @brief Sets the `floatValue` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_float_value(float value) const;
        /**
     * @brief Returns the `font` property of `NSControl`.
     * @details The following methods apply only to controls with apparent textual content of some sort (buttons with labels, textfields, etc.).
     * @return The converted Objective-C result.
     */
        Font font() const;
        /**
     * @brief Sets the `font` property of `NSControl`.
     * @details The following methods apply only to controls with apparent textual content of some sort (buttons with labels, textfields, etc.).
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_font(const Font& value) const;
        /**
     * @brief Returns the `formatter` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        Formatter formatter() const;
        /**
     * @brief Sets the `formatter` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_formatter(const Formatter& value) const;
        /**
     * @brief Returns the `highlighted` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        bool is_highlighted() const;
        /**
     * @brief Sets the `highlighted` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_highlighted(bool value) const;
        /**
     * @brief Returns the `ignoresMultiClick` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        bool ignores_multi_click() const;
        /**
     * @brief Sets the `ignoresMultiClick` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_ignores_multi_click(bool value) const;
        /**
     * @brief Returns the `intValue` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        int int_value() const;
        /**
     * @brief Sets the `intValue` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_int_value(int value) const;
        /**
     * @brief Returns the `integerValue` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        std::int64_t integer_value() const;
        /**
     * @brief Sets the `integerValue` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_integer_value(std::int64_t value) const;
        /**
     * @brief Returns the `lineBreakMode` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        LineBreakMode line_break_mode() const;
        /**
     * @brief Sets the `lineBreakMode` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_break_mode(LineBreakMode value) const;
        /**
     * @brief Returns the `objectValue` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        Object object_value() const;
        /**
     * @brief Sets the `objectValue` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_object_value(const Object& value) const;
        /**
     * @brief Returns the `refusesFirstResponder` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        bool refuses_first_responder() const;
        /**
     * @brief Sets the `refusesFirstResponder` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_refuses_first_responder(bool value) const;
        /**
     * @brief Returns the `stringValue` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        std::string string_value() const;
        /**
     * @brief Sets the `stringValue` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_string_value(const std::string& value) const;
        /**
     * @brief Returns the `tag` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        std::int64_t tag() const;
        /**
     * @brief Sets the `tag` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tag(std::int64_t value) const;
        /**
     * @brief Returns the `target` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        Object target() const;
        /**
     * @brief Sets the `target` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_target(const Object& value) const;
        /**
     * @brief Returns the `usesSingleLineMode` property of `NSControl`.
     * @return The converted Objective-C result.
     */
        bool uses_single_line_mode() const;
        /**
     * @brief Sets the `usesSingleLineMode` property of `NSControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_single_line_mode(bool value) const;
    };
}
