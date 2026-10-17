#include "generated/control.h"
#include "internal.h"

namespace cocoon
{
    Control::Control(const Rect& frame_rect) : Control(Adopt{cocoon::internal::retain([[::NSControl alloc] initWithFrame:cocoon::internal::to(frame_rect)])})
    {
    }

    Control::Control() : Control(Adopt{cocoon::internal::retain([[::NSControl alloc] init])})
    {
    }

    Control::Control(std::nullptr_t) : View(nullptr)
    {
    }

    Control::Control(Adopt adopt) : View(adopt)
    {
    }

    bool Control::abort_editing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSControl>(this) abortEditing]);
    }

    Text Control::current_editor() const
    {
        return cocoon::internal::wrap<Text>([cocoon::internal::ns<::NSControl>(this) currentEditor]);
    }

    void Control::draw_cell(const Cell& cell) const
    {
        [cocoon::internal::ns<::NSControl>(this) drawCell:cocoon::internal::native<::NSCell>(cell)];
    }

    void Control::draw_cell_inside(const Cell& cell) const
    {
        [cocoon::internal::ns<::NSControl>(this) drawCellInside:cocoon::internal::native<::NSCell>(cell)];
    }

    void Control::draw_with_expansion_frame(const Rect& content_frame, const View& view) const
    {
        [cocoon::internal::ns<::NSControl>(this) drawWithExpansionFrame:cocoon::internal::to(content_frame) inView:cocoon::internal::native<::NSView>(view)];
    }

    void Control::edit_with_frame(const Rect& rect, const Text& text_obj, const Object& delegate, const Event& event) const
    {
        [cocoon::internal::ns<::NSControl>(this) editWithFrame:cocoon::internal::to(rect) editor:cocoon::internal::native<::NSText>(text_obj) delegate:cocoon::internal::native_id(delegate) event:cocoon::internal::native<::NSEvent>(event)];
    }

    void Control::end_editing(const Text& text_obj) const
    {
        [cocoon::internal::ns<::NSControl>(this) endEditing:cocoon::internal::native<::NSText>(text_obj)];
    }

    Rect Control::expansion_frame_with_frame(const Rect& content_frame) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSControl>(this) expansionFrameWithFrame:cocoon::internal::to(content_frame)]);
    }

    void Control::invalidate_intrinsic_content_size_for_cell(const Cell& cell) const
    {
        [cocoon::internal::ns<::NSControl>(this) invalidateIntrinsicContentSizeForCell:cocoon::internal::native<::NSCell>(cell)];
    }

    void Control::perform_click(const Object& sender) const
    {
        [cocoon::internal::ns<::NSControl>(this) performClick:cocoon::internal::native_id(sender)];
    }

    void Control::select_cell(const Cell& cell) const
    {
        [cocoon::internal::ns<::NSControl>(this) selectCell:cocoon::internal::native<::NSCell>(cell)];
    }

    void Control::select_with_frame(const Rect& rect, const Text& text_obj, const Object& delegate, std::int64_t sel_start, std::int64_t sel_length) const
    {
        [cocoon::internal::ns<::NSControl>(this) selectWithFrame:cocoon::internal::to(rect) editor:cocoon::internal::native<::NSText>(text_obj) delegate:cocoon::internal::native_id(delegate) start:static_cast<::NSInteger>(sel_start) length:static_cast<::NSInteger>(sel_length)];
    }

    Cell Control::selected_cell() const
    {
        return cocoon::internal::wrap<Cell>([cocoon::internal::ns<::NSControl>(this) selectedCell]);
    }

    std::int64_t Control::selected_tag() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSControl>(this) selectedTag]);
    }

    bool Control::send_action(const std::string& action, const Object& target) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSControl>(this) sendAction:NSSelectorFromString(cocoon::internal::to(action)) to:cocoon::internal::native_id(target)]);
    }

    std::int64_t Control::send_action_on(EventMask mask) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSControl>(this) sendActionOn:static_cast<::NSEventMask>(mask)]);
    }

    Size Control::size_that_fits(const Size& size) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSControl>(this) sizeThatFits:cocoon::internal::to(size)]);
    }

    void Control::size_to_fit() const
    {
        [cocoon::internal::ns<::NSControl>(this) sizeToFit];
    }

    void Control::take_double_value_from(const Object& sender) const
    {
        [cocoon::internal::ns<::NSControl>(this) takeDoubleValueFrom:cocoon::internal::native_id(sender)];
    }

    void Control::take_float_value_from(const Object& sender) const
    {
        [cocoon::internal::ns<::NSControl>(this) takeFloatValueFrom:cocoon::internal::native_id(sender)];
    }

    void Control::take_int_value_from(const Object& sender) const
    {
        [cocoon::internal::ns<::NSControl>(this) takeIntValueFrom:cocoon::internal::native_id(sender)];
    }

    void Control::take_integer_value_from(const Object& sender) const
    {
        [cocoon::internal::ns<::NSControl>(this) takeIntegerValueFrom:cocoon::internal::native_id(sender)];
    }

    void Control::take_object_value_from(const Object& sender) const
    {
        [cocoon::internal::ns<::NSControl>(this) takeObjectValueFrom:cocoon::internal::native_id(sender)];
    }

    void Control::take_string_value_from(const Object& sender) const
    {
        [cocoon::internal::ns<::NSControl>(this) takeStringValueFrom:cocoon::internal::native_id(sender)];
    }

    void Control::update_cell(const Cell& cell) const
    {
        [cocoon::internal::ns<::NSControl>(this) updateCell:cocoon::internal::native<::NSCell>(cell)];
    }

    void Control::update_cell_inside(const Cell& cell) const
    {
        [cocoon::internal::ns<::NSControl>(this) updateCellInside:cocoon::internal::native<::NSCell>(cell)];
    }

    void Control::validate_editing() const
    {
        [cocoon::internal::ns<::NSControl>(this) validateEditing];
    }

    std::string Control::action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSControl>(this) action]));
    }

    void Control::set_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    TextAlignment Control::alignment() const
    {
        return static_cast<TextAlignment>([cocoon::internal::ns<::NSControl>(this) alignment]);
    }

    void Control::set_alignment(TextAlignment value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setAlignment:static_cast<::NSTextAlignment>(value)];
    }

    bool Control::allows_expansion_tool_tips() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSControl>(this) allowsExpansionToolTips]);
    }

    void Control::set_allows_expansion_tool_tips(bool value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setAllowsExpansionToolTips:static_cast<::BOOL>(value)];
    }

    AttributedString Control::attributed_string_value() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSControl>(this) attributedStringValue]);
    }

    void Control::set_attributed_string_value(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setAttributedStringValue:cocoon::internal::native<::NSAttributedString>(value)];
    }

    WritingDirection Control::base_writing_direction() const
    {
        return static_cast<WritingDirection>([cocoon::internal::ns<::NSControl>(this) baseWritingDirection]);
    }

    void Control::set_base_writing_direction(WritingDirection value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setBaseWritingDirection:static_cast<::NSWritingDirection>(value)];
    }

    Cell Control::cell() const
    {
        return cocoon::internal::wrap<Cell>([cocoon::internal::ns<::NSControl>(this) cell]);
    }

    void Control::set_cell(const Cell& value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setCell:cocoon::internal::native<::NSCell>(value)];
    }

    std::string Control::cell_class()
    {
        return cocoon::internal::from(NSStringFromClass([::NSControl cellClass]));
    }

    void Control::set_cell_class(const std::string& value)
    {
        [::NSControl setCellClass:NSClassFromString(cocoon::internal::to(value))];
    }

    bool Control::is_continuous() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSControl>(this) isContinuous]);
    }

    void Control::set_continuous(bool value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setContinuous:static_cast<::BOOL>(value)];
    }

    ControlSize Control::control_size() const
    {
        return static_cast<ControlSize>([cocoon::internal::ns<::NSControl>(this) controlSize]);
    }

    void Control::set_control_size(ControlSize value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setControlSize:static_cast<::NSControlSize>(value)];
    }

    double Control::double_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSControl>(this) doubleValue]);
    }

    void Control::set_double_value(double value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setDoubleValue:static_cast<double>(value)];
    }

    bool Control::is_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSControl>(this) isEnabled]);
    }

    void Control::set_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setEnabled:static_cast<::BOOL>(value)];
    }

    float Control::float_value() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSControl>(this) floatValue]);
    }

    void Control::set_float_value(float value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setFloatValue:static_cast<float>(value)];
    }

    Font Control::font() const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSControl>(this) font]);
    }

    void Control::set_font(const Font& value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setFont:cocoon::internal::native<::NSFont>(value)];
    }

    Formatter Control::formatter() const
    {
        return cocoon::internal::wrap<Formatter>([cocoon::internal::ns<::NSControl>(this) formatter]);
    }

    void Control::set_formatter(const Formatter& value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setFormatter:cocoon::internal::native<::NSFormatter>(value)];
    }

    bool Control::is_highlighted() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSControl>(this) isHighlighted]);
    }

    void Control::set_highlighted(bool value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setHighlighted:static_cast<::BOOL>(value)];
    }

    bool Control::ignores_multi_click() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSControl>(this) ignoresMultiClick]);
    }

    void Control::set_ignores_multi_click(bool value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setIgnoresMultiClick:static_cast<::BOOL>(value)];
    }

    int Control::int_value() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSControl>(this) intValue]);
    }

    void Control::set_int_value(int value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setIntValue:static_cast<int>(value)];
    }

    std::int64_t Control::integer_value() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSControl>(this) integerValue]);
    }

    void Control::set_integer_value(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setIntegerValue:static_cast<::NSInteger>(value)];
    }

    LineBreakMode Control::line_break_mode() const
    {
        return static_cast<LineBreakMode>([cocoon::internal::ns<::NSControl>(this) lineBreakMode]);
    }

    void Control::set_line_break_mode(LineBreakMode value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setLineBreakMode:static_cast<::NSLineBreakMode>(value)];
    }

    Object Control::object_value() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSControl>(this) objectValue]);
    }

    void Control::set_object_value(const Object& value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setObjectValue:cocoon::internal::native_id(value)];
    }

    bool Control::refuses_first_responder() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSControl>(this) refusesFirstResponder]);
    }

    void Control::set_refuses_first_responder(bool value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setRefusesFirstResponder:static_cast<::BOOL>(value)];
    }

    std::string Control::string_value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSControl>(this) stringValue]);
    }

    void Control::set_string_value(const std::string& value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setStringValue:cocoon::internal::to(value)];
    }

    std::int64_t Control::tag() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSControl>(this) tag]);
    }

    void Control::set_tag(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setTag:static_cast<::NSInteger>(value)];
    }

    Object Control::target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSControl>(this) target]);
    }

    void Control::set_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setTarget:cocoon::internal::native_id(value)];
    }

    bool Control::uses_single_line_mode() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSControl>(this) usesSingleLineMode]);
    }

    void Control::set_uses_single_line_mode(bool value) const
    {
        [cocoon::internal::ns<::NSControl>(this) setUsesSingleLineMode:static_cast<::BOOL>(value)];
    }
}
