#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Color;
    class DraggingImageComponent;
    class Event;
    class Font;
    class Formatter;
    class Image;
    class Menu;
    class Text;
    class TextView;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Cell cell;
     * cell.set_action("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Cell cell{};
     * cell.set_action("text");
     * auto action = cell.action();
     * cell.set_alignment(cocoon::TextAlignment::Left);
     * auto alignment = cell.alignment();
     * cell.set_allows_editing_text_attributes(true);
     * auto allows_editing_text_attributes = cell.allows_editing_text_attributes();
     * cell.calc_draw_info({{0, 0}, {100, 100}});
     * cell.cell_attribute(cocoon::CellAttribute::CellDisabled);
     * cell.cell_size_for_bounds({{0, 0}, {100, 100}});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscell
     */
    class Cell : public Object
    {
    public:
        /// @brief Creates a new `NSCell` instance and returns a handle to it.
        explicit Cell(const Image& image);
        /// @brief Creates a new `NSCell` instance and returns a handle to it.
        explicit Cell(const std::string& string);
        /// @brief Creates a new `NSCell` instance and returns a handle to it.
        explicit Cell();
        /// @brief Creates a null handle that refers to no native object.
        Cell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Cell(Adopt adopt);
        /**
     * @brief Calls `+[NSCell _bulletStringForString:bulletCharacter:]`.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @param bullet_char Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string _bullet_string_for_string(const std::string& string, std::uint16_t bullet_char);
        /**
     * @brief Calls `-[NSCell calcDrawInfo:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        void calc_draw_info(const Rect& rect) const;
        /**
     * @brief Calls `-[NSCell cellAttribute:]`.
     * @param parameter Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t cell_attribute(CellAttribute parameter) const;
        /**
     * @brief Calls `-[NSCell cellSizeForBounds:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Size cell_size_for_bounds(const Rect& rect) const;
        /**
     * @brief Calls `-[NSCell compare:]`.
     * @param other_cell Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ComparisonResult compare(const Object& other_cell) const;
        /**
     * @brief Calls `-[NSCell continueTracking:at:inView:]`.
     * @param last_point Argument converted to the Objective-C parameter of the same role.
     * @param current_point Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool continue_tracking(const Point& last_point, const Point& current_point, const View& control_view) const;
        /**
     * @brief Calls `-[NSCell draggingImageComponentsWithFrame:inView:]`.
     * @details Multi-image Drag Support. The default implementation will return an array of up to two NSDraggingImageComponent instances -- one for the image portion and another for the text portion (if appropriate). This method can be subclassed and overridden to provide a custom set of NSDraggingImageComponents to create the drag image for the cell. This method is generally used by NSTableView/NSOutlineView.
     * @param frame Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<DraggingImageComponent> dragging_image_components_with_frame(const Rect& frame, const View& view) const;
        /**
     * @brief Calls `-[NSCell drawFocusRingMaskWithFrame:inView:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     */
        void draw_focus_ring_mask_with_frame(const Rect& cell_frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSCell drawInteriorWithFrame:inView:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     */
        void draw_interior_with_frame(const Rect& cell_frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSCell drawWithExpansionFrame:inView:]`.
     * @details Allows the cell to perform custom expansion tool tip drawing. Note that the view may be different from the original view that the cell appeared in. By default, NSCell simply calls drawWithFrame:inView:.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     */
        void draw_with_expansion_frame(const Rect& cell_frame, const View& view) const;
        /**
     * @brief Calls `-[NSCell drawWithFrame:inView:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     */
        void draw_with_frame(const Rect& cell_frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSCell drawingRectForBounds:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect drawing_rect_for_bounds(const Rect& rect) const;
        /**
     * @brief Calls `-[NSCell editWithFrame:inView:editor:delegate:event:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     * @param text_obj Argument converted to the Objective-C parameter of the same role.
     * @param delegate Argument converted to the Objective-C parameter of the same role.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void edit_with_frame(const Rect& rect, const View& control_view, const Text& text_obj, const Object& delegate, const Event& event) const;
        /**
     * @brief Calls `-[NSCell endEditing:]`.
     * @param text_obj Argument converted to the Objective-C parameter of the same role.
     */
        void end_editing(const Text& text_obj) const;
        /**
     * @brief Calls `-[NSCell expansionFrameWithFrame:inView:]`.
     * @details Allows the cell to return an expansion cell frame if cellFrame is too small for the entire contents in the view. When the mouse is hovered over the cell in certain controls, the full cell contents will be shown in a special floating tool tip view. If the frame is not too small, return an empty rect, and no expansion tool tip view will be shown. By default, NSCell returns NSZeroRect, while some subclasses (such as NSTextFieldCell) will return the proper frame when required.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect expansion_frame_with_frame(const Rect& cell_frame, const View& view) const;
        /**
     * @brief Calls `-[NSCell fieldEditorForView:]`.
     * @details Returns a custom field editor for editing inside controlView. This is an override point for NSCell subclasses designed to work with its own custom field editor. This message is sent to the selected cell of controlView in -[NSWindow fieldEditor:forObject:]. Returning non-nil from this method indicates skipping the standard field editor querying processes including -windowWillReturnFieldEditor:toObject: delegation. The default NSCell implementation returns nil. The field editor returned from this method should have isFieldEditor == YES.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TextView field_editor_for_view(const View& control_view) const;
        /**
     * @brief Calls `-[NSCell focusRingMaskBoundsForFrame:inView:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect focus_ring_mask_bounds_for_frame(const Rect& cell_frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSCell getPeriodicDelay:interval:]`.
     * @param delay Argument converted to the Objective-C parameter of the same role.
     * @param interval Argument converted to the Objective-C parameter of the same role.
     */
        void get_periodic_delay(float* delay, float* interval) const;
        /**
     * @brief Calls `-[NSCell highlight:withFrame:inView:]`.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     */
        void highlight(bool flag, const Rect& cell_frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSCell highlightColorWithFrame:inView:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Color highlight_color_with_frame(const Rect& cell_frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSCell hitTestForEvent:inRect:ofView:]`.
     * @details Return hit testing information for the cell. Use a bit-wise mask to look for a specific value when calling the method. Generally, this should be overridden by custom NSCell subclasses to return the correct result. Currently, it is called by some multi-cell views, such as NSTableView. By default, NSCell will look at the cell type and do the following: NSImageCellType: If the image exists, and the event point is in the image return NSCellHitContentArea, else NSCellHitNone. NSTextCellType (also applies to NSTextFieldCell): If there is text: If the event point hits in the text, return NSCellHitContentArea. Additionally, if the cell is enabled return NSCellHitContentArea | NSCellHitEditableTextArea. If there is not text: Returns NSCellHitNone. NSNullCellType (this is the default that applies to non text or image cells who don't override hitTestForEvent:): Return NSCellHitContentArea by default. If the cell not disabled, and it would track, return NSCellHitContentArea | NSCellHitTrackableArea.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CellHitResult hit_test_for_event(const Event& event, const Rect& cell_frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSCell imageRectForBounds:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect image_rect_for_bounds(const Rect& rect) const;
        /**
     * @brief Calls `-[NSCell menuForEvent:inRect:ofView:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Menu menu_for_event(const Event& event, const Rect& cell_frame, const View& view) const;
        /**
     * @brief Calls `-[NSCell performClick:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void perform_click(const Object& sender) const;
        /**
     * @brief Calls `-[NSCell resetCursorRect:inView:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     */
        void reset_cursor_rect(const Rect& cell_frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSCell selectWithFrame:inView:editor:delegate:start:length:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     * @param text_obj Argument converted to the Objective-C parameter of the same role.
     * @param delegate Argument converted to the Objective-C parameter of the same role.
     * @param sel_start Argument converted to the Objective-C parameter of the same role.
     * @param sel_length Argument converted to the Objective-C parameter of the same role.
     */
        void select_with_frame(const Rect& rect, const View& control_view, const Text& text_obj, const Object& delegate, std::int64_t sel_start, std::int64_t sel_length) const;
        /**
     * @brief Calls `-[NSCell sendActionOn:]`.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t send_action_on(EventMask mask) const;
        /**
     * @brief Calls `-[NSCell setCellAttribute:to:]`.
     * @param parameter Argument converted to the Objective-C parameter of the same role.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_cell_attribute(CellAttribute parameter, std::int64_t value) const;
        /**
     * @brief Calls `-[NSCell setNextState]`.
     * @details \@property (readonly) NSInteger nextState; / get next state state in cycle
     */
        void set_next_state() const;
        /**
     * @brief Calls `-[NSCell setUpFieldEditorAttributes:]`.
     * @param text_obj Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Text set_up_field_editor_attributes(const Text& text_obj) const;
        /**
     * @brief Calls `-[NSCell startTrackingAt:inView:]`.
     * @param start_point Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool start_tracking_at(const Point& start_point, const View& control_view) const;
        /**
     * @brief Calls `-[NSCell stopTracking:at:inView:mouseIsUp:]`.
     * @param last_point Argument converted to the Objective-C parameter of the same role.
     * @param stop_point Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     */
        void stop_tracking(const Point& last_point, const Point& stop_point, const View& control_view, bool flag) const;
        /**
     * @brief Calls `-[NSCell takeDoubleValueFrom:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void take_double_value_from(const Object& sender) const;
        /**
     * @brief Calls `-[NSCell takeFloatValueFrom:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void take_float_value_from(const Object& sender) const;
        /**
     * @brief Calls `-[NSCell takeIntValueFrom:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void take_int_value_from(const Object& sender) const;
        /**
     * @brief Calls `-[NSCell takeIntegerValueFrom:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void take_integer_value_from(const Object& sender) const;
        /**
     * @brief Calls `-[NSCell takeObjectValueFrom:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void take_object_value_from(const Object& sender) const;
        /**
     * @brief Calls `-[NSCell takeStringValueFrom:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void take_string_value_from(const Object& sender) const;
        /**
     * @brief Calls `-[NSCell titleRectForBounds:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect title_rect_for_bounds(const Rect& rect) const;
        /**
     * @brief Calls `-[NSCell trackMouse:inRect:ofView:untilMouseUp:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool track_mouse(const Event& event, const Rect& cell_frame, const View& control_view, bool flag) const;
        /**
     * @brief Returns the `acceptsFirstResponder` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool accepts_first_responder() const;
        /**
     * @brief Returns the `action` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        std::string action() const;
        /**
     * @brief Sets the `action` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_action(const std::string& value) const;
        /**
     * @brief Returns the `alignment` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        TextAlignment alignment() const;
        /**
     * @brief Sets the `alignment` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alignment(TextAlignment value) const;
        /**
     * @brief Returns the `allowsEditingTextAttributes` property of `NSCell`.
     * @details These methods determine whether the user can modify text attributes and import graphics in a rich cell. Note that whatever these flags are, cells can still contain attributed text if programmatically set.
     * @return The converted Objective-C result.
     */
        bool allows_editing_text_attributes() const;
        /**
     * @brief Sets the `allowsEditingTextAttributes` property of `NSCell`.
     * @details These methods determine whether the user can modify text attributes and import graphics in a rich cell. Note that whatever these flags are, cells can still contain attributed text if programmatically set.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_editing_text_attributes(bool value) const;
        /**
     * @brief Returns the `allowsMixedState` property of `NSCell`.
     * @details \@interface NSCell(NSCellMixedState) / allow button to have mixed state value
     * @return The converted Objective-C result.
     */
        bool allows_mixed_state() const;
        /**
     * @brief Sets the `allowsMixedState` property of `NSCell`.
     * @details \@interface NSCell(NSCellMixedState) / allow button to have mixed state value
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_mixed_state(bool value) const;
        /**
     * @brief Returns the `allowsUndo` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool allows_undo() const;
        /**
     * @brief Sets the `allowsUndo` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_undo(bool value) const;
        /**
     * @brief Returns the `attributedStringValue` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_string_value() const;
        /**
     * @brief Sets the `attributedStringValue` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_string_value(const AttributedString& value) const;
        /**
     * @brief Returns the `backgroundStyle` property of `NSCell`.
     * @details Describes the surface the cell is drawn onto in -[NSCell drawWithFrame:inView:]. A control typically sets this before it asks the cell to draw. A cell may draw differently based on background characteristics. For example, a tableview drawing a cell in a selected row might call [cell setBackgroundStyle:NSBackgroundStyleEmphasized]. A text cell might decide to render its text using alternateSelectedControlTextColor as a result.
     * @return The converted Objective-C result.
     */
        BackgroundStyle background_style() const;
        /**
     * @brief Sets the `backgroundStyle` property of `NSCell`.
     * @details Describes the surface the cell is drawn onto in -[NSCell drawWithFrame:inView:]. A control typically sets this before it asks the cell to draw. A cell may draw differently based on background characteristics. For example, a tableview drawing a cell in a selected row might call [cell setBackgroundStyle:NSBackgroundStyleEmphasized]. A text cell might decide to render its text using alternateSelectedControlTextColor as a result.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_style(BackgroundStyle value) const;
        /**
     * @brief Returns the `baseWritingDirection` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        WritingDirection base_writing_direction() const;
        /**
     * @brief Sets the `baseWritingDirection` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_base_writing_direction(WritingDirection value) const;
        /**
     * @brief Returns the `bezeled` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool is_bezeled() const;
        /**
     * @brief Sets the `bezeled` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bezeled(bool value) const;
        /**
     * @brief Returns the `bordered` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool is_bordered() const;
        /**
     * @brief Sets the `bordered` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bordered(bool value) const;
        /**
     * @brief Returns the `cellSize` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        Size cell_size() const;
        /**
     * @brief Returns the `continuous` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool is_continuous() const;
        /**
     * @brief Sets the `continuous` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_continuous(bool value) const;
        /**
     * @brief Returns the `controlSize` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        ControlSize control_size() const;
        /**
     * @brief Sets the `controlSize` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_control_size(ControlSize value) const;
        /**
     * @brief Returns the `controlView` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        View control_view() const;
        /**
     * @brief Sets the `controlView` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_control_view(const View& value) const;
        /**
     * @brief Returns the `defaultFocusRingType` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        static FocusRingType default_focus_ring_type();
        /**
     * @brief Returns the `defaultMenu` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        static Menu default_menu();
        /**
     * @brief Returns the `doubleValue` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        double double_value() const;
        /**
     * @brief Sets the `doubleValue` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_double_value(double value) const;
        /**
     * @brief Returns the `editable` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool is_editable() const;
        /**
     * @brief Sets the `editable` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_editable(bool value) const;
        /**
     * @brief Returns the `enabled` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool is_enabled() const;
        /**
     * @brief Sets the `enabled` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_enabled(bool value) const;
        /**
     * @brief Returns the `floatValue` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        float float_value() const;
        /**
     * @brief Sets the `floatValue` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_float_value(float value) const;
        /**
     * @brief Returns the `focusRingType` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        FocusRingType focus_ring_type() const;
        /**
     * @brief Sets the `focusRingType` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_focus_ring_type(FocusRingType value) const;
        /**
     * @brief Returns the `font` property of `NSCell`.
     * @details \@property BOOL wraps; / If YES, sets scrollable to NO
     * @return The converted Objective-C result.
     */
        Font font() const;
        /**
     * @brief Sets the `font` property of `NSCell`.
     * @details \@property BOOL wraps; / If YES, sets scrollable to NO
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_font(const Font& value) const;
        /**
     * @brief Returns the `formatter` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        Formatter formatter() const;
        /**
     * @brief Sets the `formatter` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_formatter(const Formatter& value) const;
        /**
     * @brief Returns the `hasValidObjectValue` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool has_valid_object_value() const;
        /**
     * @brief Returns the `highlighted` property of `NSCell`.
     * @details \@property (getter=isScrollable) BOOL scrollable; / If YES, sets wraps to NO
     * @return The converted Objective-C result.
     */
        bool is_highlighted() const;
        /**
     * @brief Sets the `highlighted` property of `NSCell`.
     * @details \@property (getter=isScrollable) BOOL scrollable; / If YES, sets wraps to NO
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_highlighted(bool value) const;
        /**
     * @brief Returns the `image` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        Image image() const;
        /**
     * @brief Sets the `image` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image(const Image& value) const;
        /**
     * @brief Returns the `importsGraphics` property of `NSCell`.
     * @details \@property BOOL allowsEditingTextAttributes; / If NO, also clears setImportsGraphics:
     * @return The converted Objective-C result.
     */
        bool imports_graphics() const;
        /**
     * @brief Sets the `importsGraphics` property of `NSCell`.
     * @details \@property BOOL allowsEditingTextAttributes; / If NO, also clears setImportsGraphics:
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_imports_graphics(bool value) const;
        /**
     * @brief Returns the `intValue` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        int int_value() const;
        /**
     * @brief Sets the `intValue` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_int_value(int value) const;
        /**
     * @brief Returns the `integerValue` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        std::int64_t integer_value() const;
        /**
     * @brief Sets the `integerValue` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_integer_value(std::int64_t value) const;
        /**
     * @brief Returns the `interiorBackgroundStyle` property of `NSCell`.
     * @details Describes the surface drawn onto in -[NSCell drawInteriorWithFrame:inView:]. This is often the same as the backgroundStyle, but a button that draws a bezel would have a different interiorBackgroundStyle. This is both an override point and a useful method to call. A button that draws a custom bezel would override this to describe that surface. A cell that has custom interior drawing might query this method to help pick an image that looks good on the cell. Calling this method gives you some independence from changes in framework art style.
     * @return The converted Objective-C result.
     */
        BackgroundStyle interior_background_style() const;
        /**
     * @brief Returns the `keyEquivalent` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        std::string key_equivalent() const;
        /**
     * @brief Returns the `lineBreakMode` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        LineBreakMode line_break_mode() const;
        /**
     * @brief Sets the `lineBreakMode` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_break_mode(LineBreakMode value) const;
        /**
     * @brief Returns the `menu` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        Menu menu() const;
        /**
     * @brief Sets the `menu` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_menu(const Menu& value) const;
        /**
     * @brief Returns the `mouseDownFlags` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        std::int64_t mouse_down_flags() const;
        /**
     * @brief Returns the `nextState` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        std::int64_t next_state() const;
        /**
     * @brief Returns the `objectValue` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        Object object_value() const;
        /**
     * @brief Sets the `objectValue` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_object_value(const Object& value) const;
        /**
     * @brief Returns the `opaque` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool is_opaque() const;
        /**
     * @brief Returns the `prefersTrackingUntilMouseUp` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        static bool prefers_tracking_until_mouse_up();
        /**
     * @brief Returns the `refusesFirstResponder` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool refuses_first_responder() const;
        /**
     * @brief Sets the `refusesFirstResponder` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_refuses_first_responder(bool value) const;
        /**
     * @brief Returns the `representedObject` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        Object represented_object() const;
        /**
     * @brief Sets the `representedObject` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_represented_object(const Object& value) const;
        /**
     * @brief Returns the `scrollable` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool is_scrollable() const;
        /**
     * @brief Sets the `scrollable` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_scrollable(bool value) const;
        /**
     * @brief Returns the `selectable` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool is_selectable() const;
        /**
     * @brief Sets the `selectable` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selectable(bool value) const;
        /**
     * @brief Returns the `sendsActionOnEndEditing` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool sends_action_on_end_editing() const;
        /**
     * @brief Sets the `sendsActionOnEndEditing` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sends_action_on_end_editing(bool value) const;
        /**
     * @brief Returns the `showsFirstResponder` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool shows_first_responder() const;
        /**
     * @brief Sets the `showsFirstResponder` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_first_responder(bool value) const;
        /**
     * @brief Returns the `state` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        ControlState state() const;
        /**
     * @brief Sets the `state` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_state(ControlState value) const;
        /**
     * @brief Returns the `stringValue` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        std::string string_value() const;
        /**
     * @brief Sets the `stringValue` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_string_value(const std::string& value) const;
        /**
     * @brief Returns the `tag` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        std::int64_t tag() const;
        /**
     * @brief Sets the `tag` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tag(std::int64_t value) const;
        /**
     * @brief Returns the `target` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        Object target() const;
        /**
     * @brief Sets the `target` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_target(const Object& value) const;
        /**
     * @brief Returns the `title` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
        /**
     * @brief Returns the `truncatesLastVisibleLine` property of `NSCell`.
     * @details Truncates and adds the ellipsis character to the last visible line if the text doesn't fit into the cell bounds. The setting is ignored if -lineBreakMode is neither NSLineBreakByWordWrapping nor NSLineBreakByCharWrapping.
     * @return The converted Objective-C result.
     */
        bool truncates_last_visible_line() const;
        /**
     * @brief Sets the `truncatesLastVisibleLine` property of `NSCell`.
     * @details Truncates and adds the ellipsis character to the last visible line if the text doesn't fit into the cell bounds. The setting is ignored if -lineBreakMode is neither NSLineBreakByWordWrapping nor NSLineBreakByCharWrapping.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_truncates_last_visible_line(bool value) const;
        /**
     * @brief Returns the `type` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        CellType type() const;
        /**
     * @brief Sets the `type` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_type(CellType value) const;
        /**
     * @brief Returns the `userInterfaceLayoutDirection` property of `NSCell`.
     * @details Bi-directional User Interface. It specifies the general UI layout flow directions.
     * @return The converted Objective-C result.
     */
        UserInterfaceLayoutDirection user_interface_layout_direction() const;
        /**
     * @brief Sets the `userInterfaceLayoutDirection` property of `NSCell`.
     * @details Bi-directional User Interface. It specifies the general UI layout flow directions.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_user_interface_layout_direction(UserInterfaceLayoutDirection value) const;
        /**
     * @brief Returns the `usesSingleLineMode` property of `NSCell`.
     * @details Tells the text cell to layout/render its content in single-line. If YES, the cell ignores the return value from -wraps, interprets NSLineBreakByWordWrapping and NSLineBreakByCharWrapping from -lineBreakMode as NSLineBreakByClipping, and configures the field editor to ignore key binding commands that insert paragraph/line separators. Also, the field editor bound to a single line cell filters paragraph/line separator insertion from user actions. Cells in the single line mode use the fixed baseline layout. The text baseline position is determined solely by the control size regardless of content font style/size.
     * @return The converted Objective-C result.
     */
        bool uses_single_line_mode() const;
        /**
     * @brief Sets the `usesSingleLineMode` property of `NSCell`.
     * @details Tells the text cell to layout/render its content in single-line. If YES, the cell ignores the return value from -wraps, interprets NSLineBreakByWordWrapping and NSLineBreakByCharWrapping from -lineBreakMode as NSLineBreakByClipping, and configures the field editor to ignore key binding commands that insert paragraph/line separators. Also, the field editor bound to a single line cell filters paragraph/line separator insertion from user actions. Cells in the single line mode use the fixed baseline layout. The text baseline position is determined solely by the control size regardless of content font style/size.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_single_line_mode(bool value) const;
        /**
     * @brief Returns the `wantsNotificationForMarkedText` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool wants_notification_for_marked_text() const;
        /**
     * @brief Returns the `wraps` property of `NSCell`.
     * @return The converted Objective-C result.
     */
        bool wraps() const;
        /**
     * @brief Sets the `wraps` property of `NSCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_wraps(bool value) const;
    };
}
