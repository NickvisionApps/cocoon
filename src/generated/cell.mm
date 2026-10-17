#include "generated/cell.h"
#include "internal.h"

namespace cocoon
{
    Cell::Cell(const Image& image) : Cell(Adopt{cocoon::internal::retain([[::NSCell alloc] initImageCell:cocoon::internal::native<::NSImage>(image)])})
    {
    }

    Cell::Cell(const std::string& string) : Cell(Adopt{cocoon::internal::retain([[::NSCell alloc] initTextCell:cocoon::internal::to(string)])})
    {
    }

    Cell::Cell() : Cell(Adopt{cocoon::internal::retain([[::NSCell alloc] init])})
    {
    }

    Cell::Cell(std::nullptr_t) : Object(nullptr)
    {
    }

    Cell::Cell(Adopt adopt) : Object(adopt)
    {
    }

    std::string Cell::_bullet_string_for_string(const std::string& string, std::uint16_t bullet_char)
    {
        return cocoon::internal::from([::NSCell _bulletStringForString:cocoon::internal::to(string) bulletCharacter:static_cast<::unichar>(bullet_char)]);
    }

    void Cell::calc_draw_info(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSCell>(this) calcDrawInfo:cocoon::internal::to(rect)];
    }

    std::int64_t Cell::cell_attribute(CellAttribute parameter) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCell>(this) cellAttribute:static_cast<::NSCellAttribute>(parameter)]);
    }

    Size Cell::cell_size_for_bounds(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCell>(this) cellSizeForBounds:cocoon::internal::to(rect)]);
    }

    ComparisonResult Cell::compare(const Object& other_cell) const
    {
        return static_cast<ComparisonResult>([cocoon::internal::ns<::NSCell>(this) compare:cocoon::internal::native_id(other_cell)]);
    }

    bool Cell::continue_tracking(const Point& last_point, const Point& current_point, const View& control_view) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) continueTracking:cocoon::internal::to(last_point) at:cocoon::internal::to(current_point) inView:cocoon::internal::native<::NSView>(control_view)]);
    }

    std::vector<DraggingImageComponent> Cell::dragging_image_components_with_frame(const Rect& frame, const View& view) const
    {
        return cocoon::internal::from_array<DraggingImageComponent>([cocoon::internal::ns<::NSCell>(this) draggingImageComponentsWithFrame:cocoon::internal::to(frame) inView:cocoon::internal::native<::NSView>(view)], [](id e) -> DraggingImageComponent
                                                                    {
                                                                        return cocoon::internal::wrap<DraggingImageComponent>((::NSDraggingImageComponent*)e);
                                                                    });
    }

    void Cell::draw_focus_ring_mask_with_frame(const Rect& cell_frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSCell>(this) drawFocusRingMaskWithFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(control_view)];
    }

    void Cell::draw_interior_with_frame(const Rect& cell_frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSCell>(this) drawInteriorWithFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(control_view)];
    }

    void Cell::draw_with_expansion_frame(const Rect& cell_frame, const View& view) const
    {
        [cocoon::internal::ns<::NSCell>(this) drawWithExpansionFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(view)];
    }

    void Cell::draw_with_frame(const Rect& cell_frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSCell>(this) drawWithFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(control_view)];
    }

    Rect Cell::drawing_rect_for_bounds(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCell>(this) drawingRectForBounds:cocoon::internal::to(rect)]);
    }

    void Cell::edit_with_frame(const Rect& rect, const View& control_view, const Text& text_obj, const Object& delegate, const Event& event) const
    {
        [cocoon::internal::ns<::NSCell>(this) editWithFrame:cocoon::internal::to(rect) inView:cocoon::internal::native<::NSView>(control_view) editor:cocoon::internal::native<::NSText>(text_obj) delegate:cocoon::internal::native_id(delegate) event:cocoon::internal::native<::NSEvent>(event)];
    }

    void Cell::end_editing(const Text& text_obj) const
    {
        [cocoon::internal::ns<::NSCell>(this) endEditing:cocoon::internal::native<::NSText>(text_obj)];
    }

    Rect Cell::expansion_frame_with_frame(const Rect& cell_frame, const View& view) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCell>(this) expansionFrameWithFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(view)]);
    }

    TextView Cell::field_editor_for_view(const View& control_view) const
    {
        return cocoon::internal::wrap<TextView>([cocoon::internal::ns<::NSCell>(this) fieldEditorForView:cocoon::internal::native<::NSView>(control_view)]);
    }

    Rect Cell::focus_ring_mask_bounds_for_frame(const Rect& cell_frame, const View& control_view) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCell>(this) focusRingMaskBoundsForFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(control_view)]);
    }

    void Cell::get_periodic_delay(float* delay, float* interval) const
    {
        [cocoon::internal::ns<::NSCell>(this) getPeriodicDelay:(float*)(delay) interval:(float*)(interval)];
    }

    void Cell::highlight(bool flag, const Rect& cell_frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSCell>(this) highlight:static_cast<::BOOL>(flag) withFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(control_view)];
    }

    Color Cell::highlight_color_with_frame(const Rect& cell_frame, const View& control_view) const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSCell>(this) highlightColorWithFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(control_view)]);
    }

    CellHitResult Cell::hit_test_for_event(const Event& event, const Rect& cell_frame, const View& control_view) const
    {
        return static_cast<CellHitResult>([cocoon::internal::ns<::NSCell>(this) hitTestForEvent:cocoon::internal::native<::NSEvent>(event) inRect:cocoon::internal::to(cell_frame) ofView:cocoon::internal::native<::NSView>(control_view)]);
    }

    Rect Cell::image_rect_for_bounds(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCell>(this) imageRectForBounds:cocoon::internal::to(rect)]);
    }

    Menu Cell::menu_for_event(const Event& event, const Rect& cell_frame, const View& view) const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSCell>(this) menuForEvent:cocoon::internal::native<::NSEvent>(event) inRect:cocoon::internal::to(cell_frame) ofView:cocoon::internal::native<::NSView>(view)]);
    }

    void Cell::perform_click(const Object& sender) const
    {
        [cocoon::internal::ns<::NSCell>(this) performClick:cocoon::internal::native_id(sender)];
    }

    void Cell::reset_cursor_rect(const Rect& cell_frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSCell>(this) resetCursorRect:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(control_view)];
    }

    void Cell::select_with_frame(const Rect& rect, const View& control_view, const Text& text_obj, const Object& delegate, std::int64_t sel_start, std::int64_t sel_length) const
    {
        [cocoon::internal::ns<::NSCell>(this) selectWithFrame:cocoon::internal::to(rect) inView:cocoon::internal::native<::NSView>(control_view) editor:cocoon::internal::native<::NSText>(text_obj) delegate:cocoon::internal::native_id(delegate) start:static_cast<::NSInteger>(sel_start) length:static_cast<::NSInteger>(sel_length)];
    }

    std::int64_t Cell::send_action_on(EventMask mask) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCell>(this) sendActionOn:static_cast<::NSEventMask>(mask)]);
    }

    void Cell::set_cell_attribute(CellAttribute parameter, std::int64_t value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setCellAttribute:static_cast<::NSCellAttribute>(parameter) to:static_cast<::NSInteger>(value)];
    }

    void Cell::set_next_state() const
    {
        [cocoon::internal::ns<::NSCell>(this) setNextState];
    }

    Text Cell::set_up_field_editor_attributes(const Text& text_obj) const
    {
        return cocoon::internal::wrap<Text>([cocoon::internal::ns<::NSCell>(this) setUpFieldEditorAttributes:cocoon::internal::native<::NSText>(text_obj)]);
    }

    bool Cell::start_tracking_at(const Point& start_point, const View& control_view) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) startTrackingAt:cocoon::internal::to(start_point) inView:cocoon::internal::native<::NSView>(control_view)]);
    }

    void Cell::stop_tracking(const Point& last_point, const Point& stop_point, const View& control_view, bool flag) const
    {
        [cocoon::internal::ns<::NSCell>(this) stopTracking:cocoon::internal::to(last_point) at:cocoon::internal::to(stop_point) inView:cocoon::internal::native<::NSView>(control_view) mouseIsUp:static_cast<::BOOL>(flag)];
    }

    void Cell::take_double_value_from(const Object& sender) const
    {
        [cocoon::internal::ns<::NSCell>(this) takeDoubleValueFrom:cocoon::internal::native_id(sender)];
    }

    void Cell::take_float_value_from(const Object& sender) const
    {
        [cocoon::internal::ns<::NSCell>(this) takeFloatValueFrom:cocoon::internal::native_id(sender)];
    }

    void Cell::take_int_value_from(const Object& sender) const
    {
        [cocoon::internal::ns<::NSCell>(this) takeIntValueFrom:cocoon::internal::native_id(sender)];
    }

    void Cell::take_integer_value_from(const Object& sender) const
    {
        [cocoon::internal::ns<::NSCell>(this) takeIntegerValueFrom:cocoon::internal::native_id(sender)];
    }

    void Cell::take_object_value_from(const Object& sender) const
    {
        [cocoon::internal::ns<::NSCell>(this) takeObjectValueFrom:cocoon::internal::native_id(sender)];
    }

    void Cell::take_string_value_from(const Object& sender) const
    {
        [cocoon::internal::ns<::NSCell>(this) takeStringValueFrom:cocoon::internal::native_id(sender)];
    }

    Rect Cell::title_rect_for_bounds(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCell>(this) titleRectForBounds:cocoon::internal::to(rect)]);
    }

    bool Cell::track_mouse(const Event& event, const Rect& cell_frame, const View& control_view, bool flag) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) trackMouse:cocoon::internal::native<::NSEvent>(event) inRect:cocoon::internal::to(cell_frame) ofView:cocoon::internal::native<::NSView>(control_view) untilMouseUp:static_cast<::BOOL>(flag)]);
    }

    bool Cell::accepts_first_responder() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) acceptsFirstResponder]);
    }

    std::string Cell::action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSCell>(this) action]));
    }

    void Cell::set_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    TextAlignment Cell::alignment() const
    {
        return static_cast<TextAlignment>([cocoon::internal::ns<::NSCell>(this) alignment]);
    }

    void Cell::set_alignment(TextAlignment value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setAlignment:static_cast<::NSTextAlignment>(value)];
    }

    bool Cell::allows_editing_text_attributes() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) allowsEditingTextAttributes]);
    }

    void Cell::set_allows_editing_text_attributes(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setAllowsEditingTextAttributes:static_cast<::BOOL>(value)];
    }

    bool Cell::allows_mixed_state() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) allowsMixedState]);
    }

    void Cell::set_allows_mixed_state(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setAllowsMixedState:static_cast<::BOOL>(value)];
    }

    bool Cell::allows_undo() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) allowsUndo]);
    }

    void Cell::set_allows_undo(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setAllowsUndo:static_cast<::BOOL>(value)];
    }

    AttributedString Cell::attributed_string_value() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSCell>(this) attributedStringValue]);
    }

    void Cell::set_attributed_string_value(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setAttributedStringValue:cocoon::internal::native<::NSAttributedString>(value)];
    }

    BackgroundStyle Cell::background_style() const
    {
        return static_cast<BackgroundStyle>([cocoon::internal::ns<::NSCell>(this) backgroundStyle]);
    }

    void Cell::set_background_style(BackgroundStyle value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setBackgroundStyle:static_cast<::NSBackgroundStyle>(value)];
    }

    WritingDirection Cell::base_writing_direction() const
    {
        return static_cast<WritingDirection>([cocoon::internal::ns<::NSCell>(this) baseWritingDirection]);
    }

    void Cell::set_base_writing_direction(WritingDirection value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setBaseWritingDirection:static_cast<::NSWritingDirection>(value)];
    }

    bool Cell::is_bezeled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) isBezeled]);
    }

    void Cell::set_bezeled(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setBezeled:static_cast<::BOOL>(value)];
    }

    bool Cell::is_bordered() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) isBordered]);
    }

    void Cell::set_bordered(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setBordered:static_cast<::BOOL>(value)];
    }

    Size Cell::cell_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCell>(this) cellSize]);
    }

    bool Cell::is_continuous() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) isContinuous]);
    }

    void Cell::set_continuous(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setContinuous:static_cast<::BOOL>(value)];
    }

    ControlSize Cell::control_size() const
    {
        return static_cast<ControlSize>([cocoon::internal::ns<::NSCell>(this) controlSize]);
    }

    void Cell::set_control_size(ControlSize value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setControlSize:static_cast<::NSControlSize>(value)];
    }

    View Cell::control_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSCell>(this) controlView]);
    }

    void Cell::set_control_view(const View& value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setControlView:cocoon::internal::native<::NSView>(value)];
    }

    FocusRingType Cell::default_focus_ring_type()
    {
        return static_cast<FocusRingType>([::NSCell defaultFocusRingType]);
    }

    Menu Cell::default_menu()
    {
        return cocoon::internal::wrap<Menu>([::NSCell defaultMenu]);
    }

    double Cell::double_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSCell>(this) doubleValue]);
    }

    void Cell::set_double_value(double value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setDoubleValue:static_cast<double>(value)];
    }

    bool Cell::is_editable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) isEditable]);
    }

    void Cell::set_editable(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setEditable:static_cast<::BOOL>(value)];
    }

    bool Cell::is_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) isEnabled]);
    }

    void Cell::set_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setEnabled:static_cast<::BOOL>(value)];
    }

    float Cell::float_value() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSCell>(this) floatValue]);
    }

    void Cell::set_float_value(float value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setFloatValue:static_cast<float>(value)];
    }

    FocusRingType Cell::focus_ring_type() const
    {
        return static_cast<FocusRingType>([cocoon::internal::ns<::NSCell>(this) focusRingType]);
    }

    void Cell::set_focus_ring_type(FocusRingType value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setFocusRingType:static_cast<::NSFocusRingType>(value)];
    }

    Font Cell::font() const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSCell>(this) font]);
    }

    void Cell::set_font(const Font& value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setFont:cocoon::internal::native<::NSFont>(value)];
    }

    Formatter Cell::formatter() const
    {
        return cocoon::internal::wrap<Formatter>([cocoon::internal::ns<::NSCell>(this) formatter]);
    }

    void Cell::set_formatter(const Formatter& value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setFormatter:cocoon::internal::native<::NSFormatter>(value)];
    }

    bool Cell::has_valid_object_value() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) hasValidObjectValue]);
    }

    bool Cell::is_highlighted() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) isHighlighted]);
    }

    void Cell::set_highlighted(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setHighlighted:static_cast<::BOOL>(value)];
    }

    Image Cell::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSCell>(this) image]);
    }

    void Cell::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }

    bool Cell::imports_graphics() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) importsGraphics]);
    }

    void Cell::set_imports_graphics(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setImportsGraphics:static_cast<::BOOL>(value)];
    }

    int Cell::int_value() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSCell>(this) intValue]);
    }

    void Cell::set_int_value(int value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setIntValue:static_cast<int>(value)];
    }

    std::int64_t Cell::integer_value() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCell>(this) integerValue]);
    }

    void Cell::set_integer_value(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setIntegerValue:static_cast<::NSInteger>(value)];
    }

    BackgroundStyle Cell::interior_background_style() const
    {
        return static_cast<BackgroundStyle>([cocoon::internal::ns<::NSCell>(this) interiorBackgroundStyle]);
    }

    std::string Cell::key_equivalent() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCell>(this) keyEquivalent]);
    }

    LineBreakMode Cell::line_break_mode() const
    {
        return static_cast<LineBreakMode>([cocoon::internal::ns<::NSCell>(this) lineBreakMode]);
    }

    void Cell::set_line_break_mode(LineBreakMode value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setLineBreakMode:static_cast<::NSLineBreakMode>(value)];
    }

    Menu Cell::menu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSCell>(this) menu]);
    }

    void Cell::set_menu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setMenu:cocoon::internal::native<::NSMenu>(value)];
    }

    std::int64_t Cell::mouse_down_flags() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCell>(this) mouseDownFlags]);
    }

    std::int64_t Cell::next_state() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCell>(this) nextState]);
    }

    Object Cell::object_value() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSCell>(this) objectValue]);
    }

    void Cell::set_object_value(const Object& value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setObjectValue:cocoon::internal::native_id(value)];
    }

    bool Cell::is_opaque() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) isOpaque]);
    }

    bool Cell::prefers_tracking_until_mouse_up()
    {
        return static_cast<bool>([::NSCell prefersTrackingUntilMouseUp]);
    }

    bool Cell::refuses_first_responder() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) refusesFirstResponder]);
    }

    void Cell::set_refuses_first_responder(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setRefusesFirstResponder:static_cast<::BOOL>(value)];
    }

    Object Cell::represented_object() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSCell>(this) representedObject]);
    }

    void Cell::set_represented_object(const Object& value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setRepresentedObject:cocoon::internal::native_id(value)];
    }

    bool Cell::is_scrollable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) isScrollable]);
    }

    void Cell::set_scrollable(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setScrollable:static_cast<::BOOL>(value)];
    }

    bool Cell::is_selectable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) isSelectable]);
    }

    void Cell::set_selectable(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setSelectable:static_cast<::BOOL>(value)];
    }

    bool Cell::sends_action_on_end_editing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) sendsActionOnEndEditing]);
    }

    void Cell::set_sends_action_on_end_editing(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setSendsActionOnEndEditing:static_cast<::BOOL>(value)];
    }

    bool Cell::shows_first_responder() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) showsFirstResponder]);
    }

    void Cell::set_shows_first_responder(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setShowsFirstResponder:static_cast<::BOOL>(value)];
    }

    ControlState Cell::state() const
    {
        return static_cast<ControlState>([cocoon::internal::ns<::NSCell>(this) state]);
    }

    void Cell::set_state(ControlState value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setState:static_cast<NSControlStateValue>(value)];
    }

    std::string Cell::string_value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCell>(this) stringValue]);
    }

    void Cell::set_string_value(const std::string& value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setStringValue:cocoon::internal::to(value)];
    }

    std::int64_t Cell::tag() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCell>(this) tag]);
    }

    void Cell::set_tag(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setTag:static_cast<::NSInteger>(value)];
    }

    Object Cell::target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSCell>(this) target]);
    }

    void Cell::set_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setTarget:cocoon::internal::native_id(value)];
    }

    std::string Cell::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCell>(this) title]);
    }

    void Cell::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setTitle:cocoon::internal::to(value)];
    }

    bool Cell::truncates_last_visible_line() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) truncatesLastVisibleLine]);
    }

    void Cell::set_truncates_last_visible_line(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setTruncatesLastVisibleLine:static_cast<::BOOL>(value)];
    }

    CellType Cell::type() const
    {
        return static_cast<CellType>([cocoon::internal::ns<::NSCell>(this) type]);
    }

    void Cell::set_type(CellType value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setType:static_cast<::NSCellType>(value)];
    }

    UserInterfaceLayoutDirection Cell::user_interface_layout_direction() const
    {
        return static_cast<UserInterfaceLayoutDirection>([cocoon::internal::ns<::NSCell>(this) userInterfaceLayoutDirection]);
    }

    void Cell::set_user_interface_layout_direction(UserInterfaceLayoutDirection value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setUserInterfaceLayoutDirection:static_cast<::NSUserInterfaceLayoutDirection>(value)];
    }

    bool Cell::uses_single_line_mode() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) usesSingleLineMode]);
    }

    void Cell::set_uses_single_line_mode(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setUsesSingleLineMode:static_cast<::BOOL>(value)];
    }

    bool Cell::wants_notification_for_marked_text() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) wantsNotificationForMarkedText]);
    }

    bool Cell::wraps() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCell>(this) wraps]);
    }

    void Cell::set_wraps(bool value) const
    {
        [cocoon::internal::ns<::NSCell>(this) setWraps:static_cast<::BOOL>(value)];
    }
}
