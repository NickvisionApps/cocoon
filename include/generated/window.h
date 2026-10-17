#pragma once

#include <functional>
#include "generated/enums.h"
#include "generated/responder.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Button;
    class ButtonCell;
    class CloseCommand;
    class Coder;
    class Color;
    class ColorSpace;
    class Date;
    class DockTile;
    class DraggingItem;
    class DraggingSession;
    class Error;
    class Event;
    class Image;
    class LayoutConstraint;
    class Menu;
    class Notification;
    class Number;
    class Pasteboard;
    class Responder;
    class Screen;
    class ScriptCommand;
    class Text;
    class TitlebarAccessoryViewController;
    class Toolbar;
    class URL;
    class UndoManager;
    class View;
    class ViewController;
    class WindowController;
    class WindowTab;
    class WindowTabGroup;

    /**
     * @brief A window (NSWindow). Windows stay alive while visible and are released when closed.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Responder.
     *
     * @par Example
     * @code
     * cocoon::Window window("Title", {800, 600});
     * cocoon::VStack content;
     * window.set_content(content);
     * window.set_toolbar_style(cocoon::ToolbarStyle::Unified);
     * window.will_close().connect([](cocoon::Notification) {});
     * window.show();
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Window window{"text", {100, 100}, cocoon::WindowStyle::Borderless};
     * window.set_accepts_mouse_moved_events(true);
     * auto accepts_mouse_moved_events = window.accepts_mouse_moved_events();
     * window.set_allows_automatic_window_tabbing(true);
     * auto allows_automatic_window_tabbing = window.allows_automatic_window_tabbing();
     * window.set_allows_concurrent_view_drawing(true);
     * auto allows_concurrent_view_drawing = window.allows_concurrent_view_drawing();
     * auto made_0 = cocoon::Window::window_with_content_view_controller(cocoon::ViewController());
     * window.add_child_window(cocoon::Window(), cocoon::WindowOrderingMode::Above);
     * window.add_tabbed_window(cocoon::Window(), cocoon::WindowOrderingMode::Above);
     * window.add_titlebar_accessory_view_controller(cocoon::TitlebarAccessoryViewController());
     * window.start_custom_animation_to_enter_full_screen_with_duration().connect([](double a0) {});
     * window.did_fail_to_enter_full_screen().connect([]() {});
     * window.start_custom_animation_to_exit_full_screen_with_duration().connect([](double a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nswindow
     */
    class Window : public Responder
    {
    public:
        /// @brief Creates a new `NSWindow` instance and returns a handle to it.
        explicit Window(const std::string& title = "", Size size = Size{800, 600}, WindowStyle style = WindowStyle::Titled | WindowStyle::Closable | WindowStyle::Miniaturizable | WindowStyle::Resizable);
        /// @brief Creates a new `NSWindow` instance and returns a handle to it.
        explicit Window(const Rect& content_rect, WindowStyle style, BackingStoreType backing_store_type, bool flag);
        /// @brief Creates a new `NSWindow` instance and returns a handle to it.
        explicit Window(const Rect& content_rect, WindowStyle style, BackingStoreType backing_store_type, bool flag, const Screen& screen);
        /// @brief Creates a null handle that refers to no native object.
        Window(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Window(Adopt adopt);
        using Responder::try_to_perform;
        using Responder::valid_requestor_for_send_type;
        /**
     * @brief Calls `-[NSWindow addChildWindow:ordered:]`.
     * @param child_win Argument converted to the Objective-C parameter of the same role.
     * @param place Argument converted to the Objective-C parameter of the same role.
     */
        void add_child_window(const Window& child_win, WindowOrderingMode place) const;
        /**
     * @brief Calls `-[NSWindow addTabbedWindow:ordered:]`.
     * @details This is now a cover for '-[self.tabGroup addWindow:]', which allows more precise placement.
     * @param window Argument converted to the Objective-C parameter of the same role.
     * @param ordered Argument converted to the Objective-C parameter of the same role.
     */
        void add_tabbed_window(const Window& window, WindowOrderingMode ordered) const;
        /**
     * @brief Calls `-[NSWindow addTitlebarAccessoryViewController:]`.
     * @param child_view_controller Argument converted to the Objective-C parameter of the same role.
     */
        void add_titlebar_accessory_view_controller(const TitlebarAccessoryViewController& child_view_controller) const;
        /**
     * @brief Calls `-[NSWindow anchorAttributeForOrientation:]`.
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutAttribute anchor_attribute_for_orientation(ConstraintOrientation orientation) const;
        /**
     * @brief Calls `-[NSWindow animationResizeTime:]`.
     * @details Subclasses can override \\c animationResizeTime: to control the total time for the frame change. \\c newFrame is the rect passed into \\c setFrame:display:animate:
     * @param new_frame Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double animation_resize_time(const Rect& new_frame) const;
        /**
     * @brief Calls `-[NSWindow autorecalculatesContentBorderThicknessForEdge:]`.
     * @param edge Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool autorecalculates_content_border_thickness_for_edge(RectEdge edge) const;
        /**
     * @brief Calls `-[NSWindow backingAlignedRect:options:]`.
     * @details Use 'NSIntegralRectWithOptions()' to produce a backing store pixel aligned rectangle from the given input rectangle in window coordinates.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect backing_aligned_rect(const Rect& rect, AlignmentOptions options) const;
        /**
     * @brief Calls `-[NSWindow becomeKeyWindow]`.
     * @details Informs the window that it has become the key window. This method exists as an override point. Do not invoke directly. Instead, invoke '-makeKeyWindow'.
     */
        void become_key_window() const;
        /**
     * @brief Calls `-[NSWindow becomeMainWindow]`.
     * @details Informs the window that it has become the main window. This method exists as an override point. Do not invoke directly. Instead, invoke '-makeMainWindow'.
     */
        void become_main_window() const;
        /**
     * @brief Calls `-[NSWindow beginCriticalSheet:completionHandler:]`.
     * @param sheet_window Argument converted to the Objective-C parameter of the same role.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        void begin_critical_sheet(const Window& sheet_window, std::function<void(std::int64_t)> handler) const;
        /**
     * @brief Calls `-[NSWindow beginDraggingSessionWithItems:event:source:]`.
     * @param items Argument converted to the Objective-C parameter of the same role.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param source Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DraggingSession begin_dragging_session_with_items(const std::vector<DraggingItem>& items, const Event& event, const Object& source) const;
        /**
     * @brief Calls `-[NSWindow canRepresentDisplayGamut:]`.
     * @details '-canRepresentDisplayGamut:' returns \\c YES if the colorSpace of the receiving window, and the \\c colorSpace of the screen containing that window, are capable of representing the given display gamut
     * @param display_gamut Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool can_represent_display_gamut(DisplayGamut display_gamut) const;
        /**
     * @brief Calls `-[NSWindow cascadeTopLeftFromPoint:]`.
     * @param top_left_point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point cascade_top_left_from_point(const Point& top_left_point) const;
        /**
     * @brief Calls `-[NSWindow constrainFrameRect:toScreen:]`.
     * @param frame_rect Argument converted to the Objective-C parameter of the same role.
     * @param screen Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect constrain_frame_rect(const Rect& frame_rect, const Screen& screen) const;
        /**
     * @brief Calls `-[NSWindow contentBorderThicknessForEdge:]`.
     * @param edge Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double content_border_thickness_for_edge(RectEdge edge) const;
        /**
     * @brief Calls `-[NSWindow contentRectForFrameRect:]`.
     * @param frame_rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect content_rect_for_frame_rect(const Rect& frame_rect) const;
        /**
     * @brief Calls `+[NSWindow contentRectForFrameRect:styleMask:]`.
     * @param f_rect Argument converted to the Objective-C parameter of the same role.
     * @param style Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Rect content_rect_for_frame_rect(const Rect& f_rect, WindowStyle style);
        /**
     * @brief Calls `-[NSWindow convertPointFromBacking:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point convert_point_from_backing(const Point& point) const;
        /**
     * @brief Calls `-[NSWindow convertPointFromScreen:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point convert_point_from_screen(const Point& point) const;
        /**
     * @brief Calls `-[NSWindow convertPointToBacking:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point convert_point_to_backing(const Point& point) const;
        /**
     * @brief Calls `-[NSWindow convertPointToScreen:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point convert_point_to_screen(const Point& point) const;
        /**
     * @brief Calls `-[NSWindow convertRectFromBacking:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect convert_rect_from_backing(const Rect& rect) const;
        /**
     * @brief Calls `-[NSWindow convertRectFromScreen:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect convert_rect_from_screen(const Rect& rect) const;
        /**
     * @brief Calls `-[NSWindow convertRectToBacking:]`.
     * @details Methods to convert to/from a pixel integral backing store space
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect convert_rect_to_backing(const Rect& rect) const;
        /**
     * @brief Calls `-[NSWindow convertRectToScreen:]`.
     * @details Methods to convert window coordinates to screen coordinates
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect convert_rect_to_screen(const Rect& rect) const;
        /**
     * @brief Calls `-[NSWindow dataWithEPSInsideRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> data_with_eps_inside_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSWindow dataWithPDFInsideRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> data_with_pdf_inside_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSWindow deminiaturize:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void deminiaturize(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow disableCursorRects]`.
     */
        void disable_cursor_rects() const;
        /**
     * @brief Calls `-[NSWindow disableKeyEquivalentForDefaultButtonCell]`.
     */
        void disable_key_equivalent_for_default_button_cell() const;
        /**
     * @brief Calls `-[NSWindow disableSnapshotRestoration]`.
     */
        void disable_snapshot_restoration() const;
        /**
     * @brief Calls `-[NSWindow discardCursorRects]`.
     */
        void discard_cursor_rects() const;
        /**
     * @brief Calls `-[NSWindow discardEventsMatchingMask:beforeEvent:]`.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @param last_event Argument converted to the Objective-C parameter of the same role.
     */
        void discard_events_matching_mask(EventMask mask, const Event& last_event) const;
        /**
     * @brief Calls `-[NSWindow display]`.
     */
        void display() const;
        /**
     * @brief Calls `-[NSWindow displayIfNeeded]`.
     */
        void display_if_needed() const;
        /**
     * @brief Calls `-[NSWindow displayLinkWithTarget:selector:]`.
     * @details Returns a new display link whose callback will be invoked in-sync with the display the window is on. If the window is not on any display the callback will not be invoked.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param selector Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object display_link_with_target(const Object& target, const std::string& selector) const;
        /**
     * @brief Calls `-[NSWindow dragImage:at:offset:event:pasteboard:source:slideBack:]`.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param base_location Argument converted to the Objective-C parameter of the same role.
     * @param initial_offset Argument converted to the Objective-C parameter of the same role.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param pboard Argument converted to the Objective-C parameter of the same role.
     * @param source_obj Argument converted to the Objective-C parameter of the same role.
     * @param slide_flag Argument converted to the Objective-C parameter of the same role.
     */
        void drag_image(const Image& image, const Point& base_location, const Size& initial_offset, const Event& event, const Pasteboard& pboard, const Object& source_obj, bool slide_flag) const;
        /**
     * @brief Calls `-[NSWindow enableCursorRects]`.
     */
        void enable_cursor_rects() const;
        /**
     * @brief Calls `-[NSWindow enableKeyEquivalentForDefaultButtonCell]`.
     */
        void enable_key_equivalent_for_default_button_cell() const;
        /**
     * @brief Calls `-[NSWindow enableSnapshotRestoration]`.
     */
        void enable_snapshot_restoration() const;
        /**
     * @brief Calls `-[NSWindow endEditingFor:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void end_editing_for(const Object& object) const;
        /**
     * @brief Calls `-[NSWindow endSheet:returnCode:]`.
     * @param sheet_window Argument converted to the Objective-C parameter of the same role.
     * @param return_code Argument converted to the Objective-C parameter of the same role.
     */
        void end_sheet(const Window& sheet_window, std::int64_t return_code) const;
        /**
     * @brief Calls `-[NSWindow fieldEditor:forObject:]`.
     * @param create_flag Argument converted to the Objective-C parameter of the same role.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Text field_editor(bool create_flag, const Object& object) const;
        /**
     * @brief Calls `-[NSWindow frameRectForContentRect:]`.
     * @param content_rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect frame_rect_for_content_rect(const Rect& content_rect) const;
        /**
     * @brief Calls `+[NSWindow frameRectForContentRect:styleMask:]`.
     * @param c_rect Argument converted to the Objective-C parameter of the same role.
     * @param style Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Rect frame_rect_for_content_rect(const Rect& c_rect, WindowStyle style);
        /**
     * @brief Calls `-[NSWindow handleCloseScriptCommand:]`.
     * @param command Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object handle_close_script_command(const CloseCommand& command) const;
        /**
     * @brief Calls `-[NSWindow handlePrintScriptCommand:]`.
     * @param command Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object handle_print_script_command(const ScriptCommand& command) const;
        /**
     * @brief Calls `-[NSWindow handleSaveScriptCommand:]`.
     * @param command Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object handle_save_script_command(const ScriptCommand& command) const;
        /**
     * @brief Calls `-[NSWindow insertTitlebarAccessoryViewController:atIndex:]`.
     * @param child_view_controller Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_titlebar_accessory_view_controller(const TitlebarAccessoryViewController& child_view_controller, std::int64_t index) const;
        /**
     * @brief Calls `-[NSWindow invalidateCursorRectsForView:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     */
        void invalidate_cursor_rects_for_view(const View& view) const;
        /**
     * @brief Calls `-[NSWindow invalidateShadow]`.
     */
        void invalidate_shadow() const;
        /**
     * @brief Calls `-[NSWindow layoutIfNeeded]`.
     */
        void layout_if_needed() const;
        /**
     * @brief Calls `-[NSWindow makeFirstResponder:]`.
     * @param responder Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool make_first_responder(const Responder& responder) const;
        /**
     * @brief Calls `-[NSWindow makeKeyAndOrderFront:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void make_key_and_order_front(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow makeKeyWindow]`.
     * @details Makes the window key and main if eligible, updating NSApplication's '-keyWindow' and '-mainWindow' properties.
     */
        void make_key_window() const;
        /**
     * @brief Calls `-[NSWindow makeMainWindow]`.
     * @details Makes the window main if eligible. Updates NSApplication's '-mainWindow' property.
     */
        void make_main_window() const;
        /**
     * @brief Calls `-[NSWindow mergeAllWindows:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void merge_all_windows(const Object& sender) const;
        /**
     * @brief Calls `+[NSWindow minFrameWidthWithTitle:styleMask:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @param style Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static double min_frame_width_with_title(const std::string& title, WindowStyle style);
        /**
     * @brief Calls `-[NSWindow miniaturize:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void miniaturize(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow moveTabToNewWindow:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void move_tab_to_new_window(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow nextEventMatchingMask:]`.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Event next_event_matching_mask(EventMask mask) const;
        /**
     * @brief Calls `-[NSWindow nextEventMatchingMask:untilDate:inMode:dequeue:]`.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @param expiration Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     * @param deq_flag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Event next_event_matching_mask(EventMask mask, const Date& expiration, const std::string& mode, bool deq_flag) const;
        /**
     * @brief Calls `-[NSWindow orderBack:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void order_back(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow orderFront:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void order_front(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow orderFrontRegardless]`.
     */
        void order_front_regardless() const;
        /**
     * @brief Calls `-[NSWindow orderOut:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void order_out(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow orderWindow:relativeTo:]`.
     * @param place Argument converted to the Objective-C parameter of the same role.
     * @param other_win Argument converted to the Objective-C parameter of the same role.
     */
        void order_window(WindowOrderingMode place, std::int64_t other_win) const;
        /**
     * @brief Calls `-[NSWindow performClose:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void perform_close(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow performMiniaturize:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void perform_miniaturize(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow performWindowDragWithEvent:]`.
     * @details Call to start a drag (moving the window) in the Window Server process. In general, this can be done after a mouseDown event has come in and been examined by an application or view. The view may determine it wants to allow that portion of the window to start a window drag, and can hand off the work to the Window Server process by calling this method. This allows the window to participate in space switching, and other system features. Pass the original mouseDown event to the method. The method will return right away, and a mouseUp may not get sent.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void perform_window_drag_with_event(const Event& event) const;
        /**
     * @brief Calls `-[NSWindow performZoom:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void perform_zoom(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow postEvent:atStart:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     */
        void post_event(const Event& event, bool flag) const;
        /**
     * @brief Calls `-[NSWindow print:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void print(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow recalculateKeyViewLoop]`.
     */
        void recalculate_key_view_loop() const;
        /**
     * @brief Calls `-[NSWindow registerForDraggedTypes:]`.
     * @param new_types Argument converted to the Objective-C parameter of the same role.
     */
        void register_for_dragged_types(const std::vector<std::string>& new_types) const;
        /**
     * @brief Calls `-[NSWindow removeChildWindow:]`.
     * @param child_win Argument converted to the Objective-C parameter of the same role.
     */
        void remove_child_window(const Window& child_win) const;
        /**
     * @brief Calls `+[NSWindow removeFrameUsingName:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     */
        static void remove_frame_using_name(const std::string& name);
        /**
     * @brief Calls `-[NSWindow removeTitlebarAccessoryViewControllerAtIndex:]`.
     * @details NOTE: you can use this method, or removeFromParentViewController, which ever is easier.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_titlebar_accessory_view_controller_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSWindow requestSharingOfWindow:completionHandler:]`.
     * @details \@abstract Request sharing of window. If there is an available ScreenCaptureKit sharing session, an alert will be presented asking the user to confirm the share \@param window The window to share \@param completionHandler A completion block that is called after the request finishes. \@c error The error will be non-nil if the request does not result in a window being shared. The error will be NSUserCancelledError if there is no ScreenCaptureKit session, or if the user rejects the offer to share. If sharing fails for some other reason, the error will provide the details.
     * @param window Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void request_sharing_of_window(const Window& window, std::function<void(Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSWindow requestSharingOfWindowUsingPreview:title:completionHandler:]`.
     * @details \@abstract Request sharing of window to be provided later. If there is an available ScreenCaptureKit sharing session, an alert will be presented asking the user to confirm the share. The delegate will be asked to provide the window to share via windowForSharingRequestFromWindow: \@param image An image showing a preview of the window to share \@param title The title to show in a confirmation dialog \@param completionHandler A completion block that is called after the request finishes. \@c error The error will be non-nil if the request does not result in a window being shared. The error will be NSUserCancelledError if there is no ScreenCaptureKit session, or if the user rejects the offer to share. If sharing fails for some other reason, the error will provide the details.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void request_sharing_of_window_using_preview(const Image& image, const std::string& title, std::function<void(Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSWindow resetCursorRects]`.
     */
        void reset_cursor_rects() const;
        /**
     * @brief Calls `-[NSWindow resignKeyWindow]`.
     * @details Informs the window that it has stopped being the key window. This method exists as an override point. Do not invoke directly. Windows automatically receive this message when deactivating or when another window has become key.
     */
        void resign_key_window() const;
        /**
     * @brief Calls `-[NSWindow resignMainWindow]`.
     * @details Informs the window that it has stopped being the main window. This method exists as an override point. Do not invoke directly. Windows automatically receive this message when deactivating or when another window has become main.
     */
        void resign_main_window() const;
        /**
     * @brief Calls `-[NSWindow runToolbarCustomizationPalette:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void run_toolbar_customization_palette(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow saveFrameUsingName:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     */
        void save_frame_using_name(const std::string& name) const;
        /**
     * @brief Calls `-[NSWindow selectKeyViewFollowingView:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     */
        void select_key_view_following_view(const View& view) const;
        /**
     * @brief Calls `-[NSWindow selectKeyViewPrecedingView:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     */
        void select_key_view_preceding_view(const View& view) const;
        /**
     * @brief Calls `-[NSWindow selectNextKeyView:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void select_next_key_view(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow selectNextTab:]`.
     * @details Actions that can be called to perform various tabbed window behaviors. UI that is hooked up to these items can be automatically validated by calling 'NSWindow''s \\c validateUserInterfaceItem.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void select_next_tab(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow selectPreviousKeyView:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void select_previous_key_view(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow selectPreviousTab:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void select_previous_tab(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow sendEvent:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void send_event(const Event& event) const;
        /**
     * @brief Calls `-[NSWindow setAnchorAttribute:forOrientation:]`.
     * @param attr Argument converted to the Objective-C parameter of the same role.
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     */
        void set_anchor_attribute(LayoutAttribute attr, ConstraintOrientation orientation) const;
        /**
     * @brief Calls `-[NSWindow setAutorecalculatesContentBorderThickness:forEdge:]`.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @param edge Argument converted to the Objective-C parameter of the same role.
     */
        void set_autorecalculates_content_border_thickness(bool flag, RectEdge edge) const;
        /**
     * @brief Calls `-[NSWindow setContentBorderThickness:forEdge:]`.
     * @details Indicates the thickness of a given border of the window. NSMinYEdge is the bottom edge of the window, while NSMaxYEdge is the top edge of the window. This method may throw an exception for values that don't apply to the current window styleMask; specifically, passing NSMaxYEdge for a non-textured window will always raise. The contentBorder does not include the titlebar or toolbar.
     * @param thickness Argument converted to the Objective-C parameter of the same role.
     * @param edge Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_border_thickness(double thickness, RectEdge edge) const;
        /**
     * @brief Calls `-[NSWindow setContentSize:]`.
     * @param size Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_size(const Size& size) const;
        /**
     * @brief Calls `-[NSWindow setDynamicDepthLimit:]`.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     */
        void set_dynamic_depth_limit(bool flag) const;
        /**
     * @brief Calls `-[NSWindow setFrame:display:]`.
     * @param frame_rect Argument converted to the Objective-C parameter of the same role.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     */
        void set_frame(const Rect& frame_rect, bool flag) const;
        /**
     * @brief Calls `-[NSWindow setFrame:display:animate:]`.
     * @details \\c setFrame:display:animate: is equivalent to \\c setFrame:display: if the \\c animateFlag is NO. If the \\c animationFlag is YES, this method will perform a smooth resize of the window, where the total time for the resize is specified by \\c -animationResizeTime:
     * @param frame_rect Argument converted to the Objective-C parameter of the same role.
     * @param display_flag Argument converted to the Objective-C parameter of the same role.
     * @param animate_flag Argument converted to the Objective-C parameter of the same role.
     */
        void set_frame(const Rect& frame_rect, bool display_flag, bool animate_flag) const;
        /**
     * @brief Calls `-[NSWindow setFrameAutosaveName:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_frame_autosave_name(const std::string& name) const;
        /**
     * @brief Calls `-[NSWindow setFrameFromString:]`.
     * @param string Argument converted to the Objective-C parameter of the same role.
     */
        void set_frame_from_string(const std::string& string) const;
        /**
     * @brief Calls `-[NSWindow setFrameOrigin:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     */
        void set_frame_origin(const Point& point) const;
        /**
     * @brief Calls `-[NSWindow setFrameTopLeftPoint:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     */
        void set_frame_top_left_point(const Point& point) const;
        /**
     * @brief Calls `-[NSWindow setFrameUsingName:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_frame_using_name(const std::string& name) const;
        /**
     * @brief Calls `-[NSWindow setFrameUsingName:force:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param force Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_frame_using_name(const std::string& name, bool force) const;
        /**
     * @brief Calls `-[NSWindow setIsMiniaturized:]`.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     */
        void set_is_miniaturized(bool flag) const;
        /**
     * @brief Calls `-[NSWindow setIsVisible:]`.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     */
        void set_is_visible(bool flag) const;
        /**
     * @brief Calls `-[NSWindow setIsZoomed:]`.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     */
        void set_is_zoomed(bool flag) const;
        /**
     * @brief Calls `-[NSWindow setTitleWithRepresentedFilename:]`.
     * @param filename Argument converted to the Objective-C parameter of the same role.
     */
        void set_title_with_represented_filename(const std::string& filename) const;
        /**
     * @brief Calls `-[NSWindow standardWindowButton:]`.
     * @param b Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Button standard_window_button(WindowButton b) const;
        /**
     * @brief Calls `+[NSWindow standardWindowButton:forStyleMask:]`.
     * @param b Argument converted to the Objective-C parameter of the same role.
     * @param style_mask Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Button standard_window_button(WindowButton b, WindowStyle style_mask);
        /**
     * @brief Calls `-[NSWindow toggleFullScreen:]`.
     * @details '-toggleFullScreen:' enters or exits for full screen. A window must have \\c NSWindowCollectionBehaviorFullScreenAuxiliary or \\c NSWindowCollectionBehaviorFullScreenPrimary included in the \\c collectionBehavior property; if it does not, this method may simply do nothing.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void toggle_full_screen(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow toggleTabBar:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void toggle_tab_bar(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow toggleTabOverview:]`.
     * @details Toggle the Tab Picker / Tab Overview UI which is invoked via "Show All Tabs". Performs the toggle in an animated fashion. Use 'tabGroup.isOverviewVisible' to find out if it is visible or not at a given time.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void toggle_tab_overview(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow toggleToolbarShown:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void toggle_toolbar_shown(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindow trackEventsMatchingMask:timeout:mode:handler:]`.
     * @details Tracks events matching the supplied mask with the supplied tracking handler until the tracking handler explicitly terminates tracking. Each event is removed from the event queue then passed to the tracking handler. If a matching event does not exist in the event queue, then the main thread blocks in the specified runloop mode until an event of the requested type is received or the timeout expires. If the timeout expires, the tracking handler is called with a nil event. A negative timeout is interpreted as 0. Use \\c NSEventDurationForever to never timeout. Tracking continues until 'stop' is set to \\c YES. Calls to '-nextEventMatchingMask:…' are allowed inside the trackingHandler block. This method returns once tracking is terminated.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @param timeout Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     * @param tracking_handler Argument converted to the Objective-C parameter of the same role.
     */
        void track_events_matching_mask(EventMask mask, double timeout, const std::string& mode, std::function<void(Event, bool&)> tracking_handler) const;
        /**
     * @brief Calls `-[NSWindow transferWindowSharingToWindow:completionHandler:]`.
     * @details Attempts to move window sharing (i.e. within a SharePlay session) from the receiver to another window. In response to this request, the user may choose to transfer sharing to the new window, or simply stop sharing the content. In the event of a failed transfer request, a non-'nil' error contains details about the failure. \@param window A window that is replacing the reciever in representing the user's current activity. \@param completionHandler A completion block that is called after the request finishes.
     * @param window Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void transfer_window_sharing_to_window(const Window& window, std::function<void(Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSWindow tryToPerform:with:]`.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool try_to_perform(const std::string& action, const Object& object) const;
        /**
     * @brief Calls `-[NSWindow unregisterDraggedTypes]`.
     */
        void unregister_dragged_types() const;
        /**
     * @brief Calls `-[NSWindow update]`.
     */
        void update() const;
        /**
     * @brief Calls `-[NSWindow updateConstraintsIfNeeded]`.
     */
        void update_constraints_if_needed() const;
        /**
     * @brief Calls `-[NSWindow validRequestorForSendType:returnType:]`.
     * @param send_type Argument converted to the Objective-C parameter of the same role.
     * @param return_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object valid_requestor_for_send_type(const std::string& send_type, const std::string& return_type) const;
        /**
     * @brief Calls `-[NSWindow visualizeConstraints:]`.
     * @param constraints Argument converted to the Objective-C parameter of the same role.
     */
        void visualize_constraints(const std::vector<LayoutConstraint>& constraints) const;
        /**
     * @brief Calls `+[NSWindow windowNumberAtPoint:belowWindowWithWindowNumber:]`.
     * @details '+windowNumberAtPoint:belowWindowWithWindowNumber:' returns the number of the frontmost window that would be hit by a mouseDown at the screen location "point". "windowNum" can be specified to exclude a given window along with all windows above it, and may belong to any application. If no windows are to be excluded, specify 0 for "windowNum". The windowNumber returned may correspond to a window in another application.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @param window_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::int64_t window_number_at_point(const Point& point, std::int64_t window_number);
        /**
     * @brief Calls `+[NSWindow windowNumbersWithOptions:]`.
     * @details '+windowNumbersWithOptions:' returns an autoreleased array of \\c NSNumbers containing windowNumbers for all visible windows satisfying options. If no options are specified, only visible windows belonging to the calling application and on the active space are included. If options include \\c NSWindowNumberListAllApplications, visible windows belonging to all applications are included. If options include \\c NSWindowNumberListAllSpaces, visible windows on all spaces are included. Windows on the active space are returned in z-order. Examples: To get an array of windowNumbers visible on the current space and belonging to the calling application: 'windowNumbers = [NSWindow windowNumbersWithOptions:0];' To get an array of windowNumbers visible on any space and belonging to any application: 'windowNumbers = [NSWindow windowNumbersWithOptions:NSWindowNumberListAllApplications|NSWindowNumberListAllSpaces];' To get an array of windowNumbers visible on any space and belonging to the calling application: 'windowNumbers = [NSWindow windowNumbersWithOptions:NSWindowNumberListAllSpaces];'
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<Number> window_numbers_with_options(WindowNumberListOptions options);
        /**
     * @brief Calls `+[NSWindow windowWithContentViewController:]`.
     * @details Convenience method for creating an autoreleased titled window with the given contentViewController. A basic NSWindow with the following attributes is made: titled, closable, resizable, miniaturizable. The window's title is automatically bound to the contentViewController's title. The size of the window can easily be controlled by utilizing autolayout and applying size constraints to the view (or its subviews). The window has isReleasedWhenClosed set to NO, and it must be explicitly retained to keep the window instance alive. To have it automatically be freed when it is closed, do the following: [window retain] and [window setReleasedWhenClosed:YES].
     * @param content_view_controller Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Window window_with_content_view_controller(const ViewController& content_view_controller);
        /**
     * @brief Calls `-[NSWindow zoom:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void zoom(const Object& sender) const;
        /**
     * @brief Returns the `acceptsMouseMovedEvents` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool accepts_mouse_moved_events() const;
        /**
     * @brief Sets the `acceptsMouseMovedEvents` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_accepts_mouse_moved_events(bool value) const;
        /**
     * @brief Returns the `allowsAutomaticWindowTabbing` property of `NSWindow`.
     * @details Allows automatic window tabbing when the value is \\c YES. By default, this will be set to \\c YES, but applications can explicitly opt out of all automatic tabbing by setting it to NO, and can still adopted explicit window tabbing, if desired.
     * @return The converted Objective-C result.
     */
        static bool allows_automatic_window_tabbing();
        /**
     * @brief Sets the `allowsAutomaticWindowTabbing` property of `NSWindow`.
     * @details Allows automatic window tabbing when the value is \\c YES. By default, this will be set to \\c YES, but applications can explicitly opt out of all automatic tabbing by setting it to NO, and can still adopted explicit window tabbing, if desired.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_allows_automatic_window_tabbing(bool value);
        /**
     * @brief Returns the `allowsConcurrentViewDrawing` property of `NSWindow`.
     * @details Controls whether threading of view drawing should be enabled for this window. Defaults to \\c YES. When this is set to \\c YES, AppKit's view system is allowed to perform '-drawRect:' activity for the window's views on threads other than the main thread, for views that have 'canDrawConcurrently == YES'. When this is set to \\c NO, the window's views will be drawn serially as on 10.5 and earlier, even though some of the views may have 'canDrawConcurrently == YES'.
     * @return The converted Objective-C result.
     */
        bool allows_concurrent_view_drawing() const;
        /**
     * @brief Sets the `allowsConcurrentViewDrawing` property of `NSWindow`.
     * @details Controls whether threading of view drawing should be enabled for this window. Defaults to \\c YES. When this is set to \\c YES, AppKit's view system is allowed to perform '-drawRect:' activity for the window's views on threads other than the main thread, for views that have 'canDrawConcurrently == YES'. When this is set to \\c NO, the window's views will be drawn serially as on 10.5 and earlier, even though some of the views may have 'canDrawConcurrently == YES'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_concurrent_view_drawing(bool value) const;
        /**
     * @brief Returns the `allowsToolTipsWhenApplicationIsInactive` property of `NSWindow`.
     * @details Default is \\c NO. Set to \\c YES to allow a window to display tooltips even when the application is in the background. Note that, enabling tooltips in an inactive application will cause the app to do work any time the mouse passes over the window. This can degrade system performance. Returns \\c YES if this window displays tooltips even when the application is in the background. To configure this setting you should call '-setAllowsToolTipsWhenApplicationIsInactive:' instead of overriding '-allowsToolTipsWhenApplicationIsInactive'.
     * @return The converted Objective-C result.
     */
        bool allows_tool_tips_when_application_is_inactive() const;
        /**
     * @brief Sets the `allowsToolTipsWhenApplicationIsInactive` property of `NSWindow`.
     * @details Default is \\c NO. Set to \\c YES to allow a window to display tooltips even when the application is in the background. Note that, enabling tooltips in an inactive application will cause the app to do work any time the mouse passes over the window. This can degrade system performance. Returns \\c YES if this window displays tooltips even when the application is in the background. To configure this setting you should call '-setAllowsToolTipsWhenApplicationIsInactive:' instead of overriding '-allowsToolTipsWhenApplicationIsInactive'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_tool_tips_when_application_is_inactive(bool value) const;
        /**
     * @brief Returns the `alphaValue` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        double alpha_value() const;
        /**
     * @brief Sets the `alphaValue` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alpha_value(double value) const;
        /**
     * @brief Returns the `animationBehavior` property of `NSWindow`.
     * @details Provides for per-window control over automatic orderFront/orderOut animation behaviors added in 10.7. Can be set to \\c NSWindowAnimationBehaviorNone to disable Appkit's automatic animations for a given window, or to one of the other non-Default \\c NSWindowAnimationBehavior values to override AppKit's automatic inference of appropriate animation behavior based on the window's apparent type.
     * @return The converted Objective-C result.
     */
        WindowAnimationBehavior animation_behavior() const;
        /**
     * @brief Sets the `animationBehavior` property of `NSWindow`.
     * @details Provides for per-window control over automatic orderFront/orderOut animation behaviors added in 10.7. Can be set to \\c NSWindowAnimationBehaviorNone to disable Appkit's automatic animations for a given window, or to one of the other non-Default \\c NSWindowAnimationBehavior values to override AppKit's automatic inference of appropriate animation behavior based on the window's apparent type.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_animation_behavior(WindowAnimationBehavior value) const;
        /**
     * @brief Returns the `appearanceSource` property of `NSWindow`.
     * @details If set, the receiver will inherit the appearance of that object, as well as use KVO to observe its effectiveAppearance for changes. Typically this is used for child windows that are shown from a parent window or specific view. Defaults to NSApp.
     * @return The converted Objective-C result.
     */
        Object appearance_source() const;
        /**
     * @brief Sets the `appearanceSource` property of `NSWindow`.
     * @details If set, the receiver will inherit the appearance of that object, as well as use KVO to observe its effectiveAppearance for changes. Typically this is used for child windows that are shown from a parent window or specific view. Defaults to NSApp.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_appearance_source(const Object& value) const;
        /**
     * @brief Returns the `areCursorRectsEnabled` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool are_cursor_rects_enabled() const;
        /**
     * @brief Returns the `aspectRatio` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Size aspect_ratio() const;
        /**
     * @brief Sets the `aspectRatio` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_aspect_ratio(const Size& value) const;
        /**
     * @brief Returns the `attachedSheet` property of `NSWindow`.
     * @details Returns the top-most sheet if there is one or more sheets, or nil if there is no sheet.
     * @return The converted Objective-C result.
     */
        Window attached_sheet() const;
        /**
     * @brief Returns the `autorecalculatesKeyViewLoop` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool autorecalculates_key_view_loop() const;
        /**
     * @brief Sets the `autorecalculatesKeyViewLoop` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_autorecalculates_key_view_loop(bool value) const;
        /**
     * @brief Returns the `backgroundColor` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Color background_color() const;
        /**
     * @brief Sets the `backgroundColor` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_color(const Color& value) const;
        /**
     * @brief Returns the `backingScaleFactor` property of `NSWindow`.
     * @details Returns the scale factor representing the number of backing store pixels corresponding to each linear unit in window space on this \\c NSWindow. This method is provided for rare cases when the explicit scale factor is needed. Please use '-convertToBacking:' methods whenever possible.
     * @return The converted Objective-C result.
     */
        double backing_scale_factor() const;
        /**
     * @brief Returns the `backingType` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        BackingStoreType backing_type() const;
        /**
     * @brief Sets the `backingType` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_backing_type(BackingStoreType value) const;
        /**
     * @brief Returns the `canBecomeKeyWindow` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool can_become_key_window() const;
        /**
     * @brief Returns the `canBecomeMainWindow` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool can_become_main_window() const;
        /**
     * @brief Returns the `canBecomeVisibleWithoutLogin` property of `NSWindow`.
     * @details This API controls whether the receiver is permitted onscreen before the user has logged in. This property is off by default. Alert panels and windows presented by input managers are examples of windows which should have this property set.
     * @return The converted Objective-C result.
     */
        bool can_become_visible_without_login() const;
        /**
     * @brief Sets the `canBecomeVisibleWithoutLogin` property of `NSWindow`.
     * @details This API controls whether the receiver is permitted onscreen before the user has logged in. This property is off by default. Alert panels and windows presented by input managers are examples of windows which should have this property set.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_can_become_visible_without_login(bool value) const;
        /**
     * @brief Returns the `canHide` property of `NSWindow`.
     * @details Indicates whether a window can be hidden during '-[NSApplication hide:]'. Default is \\c YES.
     * @return The converted Objective-C result.
     */
        bool can_hide() const;
        /**
     * @brief Sets the `canHide` property of `NSWindow`.
     * @details Indicates whether a window can be hidden during '-[NSApplication hide:]'. Default is \\c YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_can_hide(bool value) const;
        /**
     * @brief Returns the `cascadingReferenceFrame` property of `NSWindow`.
     * @details \@abstract The frame to use when cascading or sizing a new window based on the receiver's position or size. This may be different from 'frame' when the receiver is positioned by the system.
     * @return The converted Objective-C result.
     */
        Rect cascading_reference_frame() const;
        /**
     * @brief Returns the `childWindows` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        std::vector<Window> child_windows() const;
        /**
     * @brief Returns the `collectionBehavior` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        WindowCollectionBehavior collection_behavior() const;
        /**
     * @brief Sets the `collectionBehavior` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_collection_behavior(WindowCollectionBehavior value) const;
        /**
     * @brief Returns the `colorSpace` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        ColorSpace color_space() const;
        /**
     * @brief Sets the `colorSpace` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_color_space(const ColorSpace& value) const;
        /**
     * @brief Returns the `contentAspectRatio` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Size content_aspect_ratio() const;
        /**
     * @brief Sets the `contentAspectRatio` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_aspect_ratio(const Size& value) const;
        /**
     * @brief Returns the `contentLayoutGuide` property of `NSWindow`.
     * @details \\c contentLayoutGuide is a corollary to \\c contentLayoutRect. It can be used by autolayout constraints to automatically bind to the \\c contentLayoutRect.
     * @return The converted Objective-C result.
     */
        Object content_layout_guide() const;
        /**
     * @brief Returns the `contentLayoutRect` property of `NSWindow`.
     * @details The \\c contentLayoutRect will return the area inside the window that is for non-obscured content. Typically, this is the same thing as the 'contentView''s frame. However, for windows with the \\c NSFullSizeContentViewWindowMask set, there needs to be a way to determine the portion that is not under the toolbar. The \\c contentLayoutRect returns the portion of the layout that is not obscured under the toolbar. \\c contentLayoutRect is in window coordinates. It is KVO compliant.
     * @return The converted Objective-C result.
     */
        Rect content_layout_rect() const;
        /**
     * @brief Returns the `contentMaxSize` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Size content_max_size() const;
        /**
     * @brief Sets the `contentMaxSize` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_max_size(const Size& value) const;
        /**
     * @brief Returns the `contentMinSize` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Size content_min_size() const;
        /**
     * @brief Sets the `contentMinSize` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_min_size(const Size& value) const;
        /**
     * @brief Returns the `contentResizeIncrements` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Size content_resize_increments() const;
        /**
     * @brief Sets the `contentResizeIncrements` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_resize_increments(const Size& value) const;
        /**
     * @brief Returns the `contentView` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        View content_view() const;
        /**
     * @brief Sets the `contentView` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_view(const View& value) const;
        /**
     * @brief Returns the `contentViewController` property of `NSWindow`.
     * @details The main content view controller for the window. This provides the contentView of the window. Assigning this value will remove the existing contentView and will make the contentViewController.view the main contentView for the window. The default value is nil. The contentViewController only controls the contentView, and not the title of the window. The window title can easily be bound to the contentViewController with the following: [window bind:NSTitleBinding toObject:contentViewController withKeyPath:\@"title" options:nil]. Setting the contentViewController will cause the window to resize based on the current size of the contentViewController. Autolayout should be used to restrict the size of the window. The value of the contentViewController is encoded in the NIB. Directly assigning a contentView will clear out the contentViewController.
     * @return The converted Objective-C result.
     */
        ViewController content_view_controller() const;
        /**
     * @brief Sets the `contentViewController` property of `NSWindow`.
     * @details The main content view controller for the window. This provides the contentView of the window. Assigning this value will remove the existing contentView and will make the contentViewController.view the main contentView for the window. The default value is nil. The contentViewController only controls the contentView, and not the title of the window. The window title can easily be bound to the contentViewController with the following: [window bind:NSTitleBinding toObject:contentViewController withKeyPath:\@"title" options:nil]. Setting the contentViewController will cause the window to resize based on the current size of the contentViewController. Autolayout should be used to restrict the size of the window. The value of the contentViewController is encoded in the NIB. Directly assigning a contentView will clear out the contentViewController.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_view_controller(const ViewController& value) const;
        /**
     * @brief Returns the `currentEvent` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Event current_event() const;
        /**
     * @brief Returns the `deepestScreen` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Screen deepest_screen() const;
        /**
     * @brief Returns the `defaultButtonCell` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        ButtonCell default_button_cell() const;
        /**
     * @brief Sets the `defaultButtonCell` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_button_cell(const ButtonCell& value) const;
        /**
     * @brief Returns the `defaultDepthLimit` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        static WindowDepth default_depth_limit();
        /**
     * @brief Returns the `depthLimit` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        WindowDepth depth_limit() const;
        /**
     * @brief Sets the `depthLimit` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_depth_limit(WindowDepth value) const;
        /**
     * @brief Returns the `deviceDescription` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> device_description() const;
        /**
     * @brief Returns the `displaysWhenScreenProfileChanges` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool displays_when_screen_profile_changes() const;
        /**
     * @brief Sets the `displaysWhenScreenProfileChanges` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_displays_when_screen_profile_changes(bool value) const;
        /**
     * @brief Returns the `dockTile` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        DockTile dock_tile() const;
        /**
     * @brief Returns the `documentEdited` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_document_edited() const;
        /**
     * @brief Sets the `documentEdited` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_document_edited(bool value) const;
        /**
     * @brief Returns the `excludedFromWindowsMenu` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_excluded_from_windows_menu() const;
        /**
     * @brief Sets the `excludedFromWindowsMenu` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_excluded_from_windows_menu(bool value) const;
        /**
     * @brief Returns the `firstResponder` property of `NSWindow`.
     * @details firstResponder is Key Value Observing (KVO) compliant.
     * @return The converted Objective-C result.
     */
        Responder first_responder() const;
        /**
     * @brief Returns the `floatingPanel` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_floating_panel() const;
        /**
     * @brief Returns the `frame` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Rect frame() const;
        /**
     * @brief Returns the `frameAutosaveName` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        std::string frame_autosave_name() const;
        /**
     * @brief Returns the `hasActiveWindowSharingSession` property of `NSWindow`.
     * @details Indicates whether the receiver is the subject of an active SharePlay sharing session.
     * @return The converted Objective-C result.
     */
        bool has_active_window_sharing_session() const;
        /**
     * @brief Returns the `hasCloseBox` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool has_close_box() const;
        /**
     * @brief Returns the `hasDynamicDepthLimit` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool has_dynamic_depth_limit() const;
        /**
     * @brief Returns the `hasShadow` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool has_shadow() const;
        /**
     * @brief Sets the `hasShadow` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_has_shadow(bool value) const;
        /**
     * @brief Returns the `hasTitleBar` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool has_title_bar() const;
        /**
     * @brief Returns the `hidesOnDeactivate` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool hides_on_deactivate() const;
        /**
     * @brief Sets the `hidesOnDeactivate` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hides_on_deactivate(bool value) const;
        /**
     * @brief Returns the `ignoresMouseEvents` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool ignores_mouse_events() const;
        /**
     * @brief Sets the `ignoresMouseEvents` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_ignores_mouse_events(bool value) const;
        /**
     * @brief Returns the `inLiveResize` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool in_live_resize() const;
        /**
     * @brief Returns the `initialFirstResponder` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        View initial_first_responder() const;
        /**
     * @brief Sets the `initialFirstResponder` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_initial_first_responder(const View& value) const;
        /**
     * @brief Returns the `keyViewSelectionDirection` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        SelectionDirection key_view_selection_direction() const;
        /**
     * @brief Returns the `keyWindow` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_key_window() const;
        /**
     * @brief Returns the `level` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        std::int64_t level() const;
        /**
     * @brief Sets the `level` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_level(std::int64_t value) const;
        /**
     * @brief Returns the `mainWindow` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_main_window() const;
        /**
     * @brief Returns the `maxFullScreenContentSize` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Size max_full_screen_content_size() const;
        /**
     * @brief Sets the `maxFullScreenContentSize` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_max_full_screen_content_size(const Size& value) const;
        /**
     * @brief Returns the `maxSize` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Size max_size() const;
        /**
     * @brief Sets the `maxSize` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_max_size(const Size& value) const;
        /**
     * @brief Returns the `minFullScreenContentSize` property of `NSWindow`.
     * @details These are the min and max values for a full screen tiled window. In general, one should not need to explicitly set the min/maxFullScreenContentSize. If an application does not change its window content upon entering full screen, then the normal auto layout min and max size will be sufficient, and one should not set these values. If an application does significantly rework the UI in full screen, then it may be necessary to set a min/maxFullScreenContentSize. This size is what is used to determine if a window can fit when it is in full screen in a tile. This property may be used even if the window does not support full screen, but are implicitly opted into supporting a full screen tile based on resizing behavior and window properties (see the collectionBehavior property). By default, the system uses auto layout to determine the min and max sizes. If auto layout is not used, contentMinSize and contentMaxSize are queried.
     * @return The converted Objective-C result.
     */
        Size min_full_screen_content_size() const;
        /**
     * @brief Sets the `minFullScreenContentSize` property of `NSWindow`.
     * @details These are the min and max values for a full screen tiled window. In general, one should not need to explicitly set the min/maxFullScreenContentSize. If an application does not change its window content upon entering full screen, then the normal auto layout min and max size will be sufficient, and one should not set these values. If an application does significantly rework the UI in full screen, then it may be necessary to set a min/maxFullScreenContentSize. This size is what is used to determine if a window can fit when it is in full screen in a tile. This property may be used even if the window does not support full screen, but are implicitly opted into supporting a full screen tile based on resizing behavior and window properties (see the collectionBehavior property). By default, the system uses auto layout to determine the min and max sizes. If auto layout is not used, contentMinSize and contentMaxSize are queried.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_min_full_screen_content_size(const Size& value) const;
        /**
     * @brief Returns the `minSize` property of `NSWindow`.
     * @details NOTE: minSize/contentMinSize and maxSize/contentMaxSize are ignored when using autolayout.
     * @return The converted Objective-C result.
     */
        Size min_size() const;
        /**
     * @brief Sets the `minSize` property of `NSWindow`.
     * @details NOTE: minSize/contentMinSize and maxSize/contentMaxSize are ignored when using autolayout.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_min_size(const Size& value) const;
        /**
     * @brief Returns the `miniaturizable` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_miniaturizable() const;
        /**
     * @brief Returns the `miniaturized` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_miniaturized() const;
        /**
     * @brief Returns the `miniwindowImage` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Image miniwindow_image() const;
        /**
     * @brief Sets the `miniwindowImage` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_miniwindow_image(const Image& value) const;
        /**
     * @brief Returns the `miniwindowTitle` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        std::string miniwindow_title() const;
        /**
     * @brief Sets the `miniwindowTitle` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_miniwindow_title(const std::string& value) const;
        /**
     * @brief Returns the `modalPanel` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_modal_panel() const;
        /**
     * @brief Returns the `mouseLocationOutsideOfEventStream` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Point mouse_location_outside_of_event_stream() const;
        /**
     * @brief Returns the `movable` property of `NSWindow`.
     * @details Calling -setMovable with a flag of NO will disable server-side dragging of the window via titlebar or background. -setMovableByWindowBackground:YES is ignored on a window that returns NO from -isMovable. When a window returns NO for -isMovable, it can be assigned to a different space with its relative screen position preserved. Note that a resizable window may still be resized, and the window frame may be changed programmatically. Applications may choose to enable application-controlled window dragging after disabling server-side dragging (perhaps to achieve snapping or pinning) by handling the mouseDown/mouseDragged/mouseUp sequence in -sendEvent: in an NSWindow subclass. Note that a non movable window will also not be moved (or resized) by the system in response to a display reconfiguration.
     * @return The converted Objective-C result.
     */
        bool is_movable() const;
        /**
     * @brief Sets the `movable` property of `NSWindow`.
     * @details Calling -setMovable with a flag of NO will disable server-side dragging of the window via titlebar or background. -setMovableByWindowBackground:YES is ignored on a window that returns NO from -isMovable. When a window returns NO for -isMovable, it can be assigned to a different space with its relative screen position preserved. Note that a resizable window may still be resized, and the window frame may be changed programmatically. Applications may choose to enable application-controlled window dragging after disabling server-side dragging (perhaps to achieve snapping or pinning) by handling the mouseDown/mouseDragged/mouseUp sequence in -sendEvent: in an NSWindow subclass. Note that a non movable window will also not be moved (or resized) by the system in response to a display reconfiguration.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_movable(bool value) const;
        /**
     * @brief Returns the `movableByWindowBackground` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_movable_by_window_background() const;
        /**
     * @brief Sets the `movableByWindowBackground` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_movable_by_window_background(bool value) const;
        /**
     * @brief Returns the `occlusionState` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        WindowOcclusionState occlusion_state() const;
        /**
     * @brief Returns the `onActiveSpace` property of `NSWindow`.
     * @details Returns \\c YES if this window is associated with the active space. For visible windows, this API indicates whether the window is currently visible on the active space. For offscreen windows, it indicates whether ordering the window onscreen would make it bring it onto the active space
     * @return The converted Objective-C result.
     */
        bool is_on_active_space() const;
        /**
     * @brief Returns the `opaque` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_opaque() const;
        /**
     * @brief Sets the `opaque` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_opaque(bool value) const;
        /**
     * @brief Returns the `orderedIndex` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        std::int64_t ordered_index() const;
        /**
     * @brief Sets the `orderedIndex` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_ordered_index(std::int64_t value) const;
        /**
     * @brief Returns the `parentWindow` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Window parent_window() const;
        /**
     * @brief Sets the `parentWindow` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_parent_window(const Window& value) const;
        /**
     * @brief Returns the `preservesContentDuringLiveResize` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool preserves_content_during_live_resize() const;
        /**
     * @brief Sets the `preservesContentDuringLiveResize` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preserves_content_during_live_resize(bool value) const;
        /**
     * @brief Returns the `preventsApplicationTerminationWhenModal` property of `NSWindow`.
     * @details A Boolean value that indicates whether or not to prevent application termination when the receiving window is presented modally. The value of this property is 'YES' if the window should prevent application termination when modal; otherwise, 'NO'. The default value is 'YES'. However, note that some window subclasses and some windows created indirectly (like those created by UI frameworks like AppKit and SwiftUI), may have different default values. For example, the Open panel and toolbar customization sheets should not prevent application termination, so those windows have 'preventsApplicationTerminationWhenModal' set to 'NO'. Some 'NSAlert's, like those that are simply informational, have windows that do not prevent application termination by default. Setting this property overrides the default behavior.
     * @return The converted Objective-C result.
     */
        bool prevents_application_termination_when_modal() const;
        /**
     * @brief Sets the `preventsApplicationTerminationWhenModal` property of `NSWindow`.
     * @details A Boolean value that indicates whether or not to prevent application termination when the receiving window is presented modally. The value of this property is 'YES' if the window should prevent application termination when modal; otherwise, 'NO'. The default value is 'YES'. However, note that some window subclasses and some windows created indirectly (like those created by UI frameworks like AppKit and SwiftUI), may have different default values. For example, the Open panel and toolbar customization sheets should not prevent application termination, so those windows have 'preventsApplicationTerminationWhenModal' set to 'NO'. Some 'NSAlert's, like those that are simply informational, have windows that do not prevent application termination by default. Setting this property overrides the default behavior.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_prevents_application_termination_when_modal(bool value) const;
        /**
     * @brief Returns the `releasedWhenClosed` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_released_when_closed() const;
        /**
     * @brief Sets the `releasedWhenClosed` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_released_when_closed(bool value) const;
        /**
     * @brief Returns the `representedFilename` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        std::string represented_filename() const;
        /**
     * @brief Sets the `representedFilename` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_represented_filename(const std::string& value) const;
        /**
     * @brief Returns the `representedURL` property of `NSWindow`.
     * @details If url is not nil and its path is not empty, the window will show a document icon in the titlebar. If the url represents a filename or other resource with a known icon, that icon will be used as the document icon. Otherwise the default document icon will be used. The icon can be customized using '-[[NSWindow standardWindowButton:NSWindowDocumentIconButton] setImage:customImage]'. If url is not nil and its path is not empty, the window will have a pop-up menu which can be shown via command-click on the area containing the document icon and title. By default, this menu will display the path components of the url. The presence and contents of this menu can be controlled by the delegate method '-[window:shouldPopUpDocumentPathMenu:]' If the url is nil or has an empty path, the window will not show a document icon and will not have a pop-up menu available via command-click.
     * @return The converted Objective-C result.
     */
        URL represented_url() const;
        /**
     * @brief Sets the `representedURL` property of `NSWindow`.
     * @details If url is not nil and its path is not empty, the window will show a document icon in the titlebar. If the url represents a filename or other resource with a known icon, that icon will be used as the document icon. Otherwise the default document icon will be used. The icon can be customized using '-[[NSWindow standardWindowButton:NSWindowDocumentIconButton] setImage:customImage]'. If url is not nil and its path is not empty, the window will have a pop-up menu which can be shown via command-click on the area containing the document icon and title. By default, this menu will display the path components of the url. The presence and contents of this menu can be controlled by the delegate method '-[window:shouldPopUpDocumentPathMenu:]' If the url is nil or has an empty path, the window will not show a document icon and will not have a pop-up menu available via command-click.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_represented_url(const URL& value) const;
        /**
     * @brief Returns the `resizable` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_resizable() const;
        /**
     * @brief Returns the `resizeFlags` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        EventModifierFlags resize_flags() const;
        /**
     * @brief Returns the `resizeIncrements` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Size resize_increments() const;
        /**
     * @brief Sets the `resizeIncrements` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_resize_increments(const Size& value) const;
        /**
     * @brief Returns the `restorable` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_restorable() const;
        /**
     * @brief Sets the `restorable` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_restorable(bool value) const;
        /**
     * @brief Returns the `restorationClass` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        std::string restoration_class() const;
        /**
     * @brief Sets the `restorationClass` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_restoration_class(const std::string& value) const;
        /**
     * @brief Returns the `screen` property of `NSWindow`.
     * @details The screen property returns the best screen for the window. If the window only intersects one screen, it returns that screen. If it intersects more than one screen, then it resolves the tie through based on what space it is mostly on. It may return nil if there are no available screens, or it is completely off screen.
     * @return The converted Objective-C result.
     */
        Screen screen() const;
        /**
     * @brief Returns the `sharingType` property of `NSWindow`.
     * @details '-setSharingType:' specifies whether the window content can be read from another process. The default sharing type is \\c NSWindowSharingReadOnly, which means other processes can read the window content (eg. for window capture) but cannot modify it. If you set your window sharing type to \\c NSWindowSharingNone, so that the content cannot be captured, your window will also not be able to participate in a number of system services, so this setting should be used with caution.
     * @return The converted Objective-C result.
     */
        WindowSharingType sharing_type() const;
        /**
     * @brief Sets the `sharingType` property of `NSWindow`.
     * @details '-setSharingType:' specifies whether the window content can be read from another process. The default sharing type is \\c NSWindowSharingReadOnly, which means other processes can read the window content (eg. for window capture) but cannot modify it. If you set your window sharing type to \\c NSWindowSharingNone, so that the content cannot be captured, your window will also not be able to participate in a number of system services, so this setting should be used with caution.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sharing_type(WindowSharingType value) const;
        /**
     * @brief Returns the `sheet` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_sheet() const;
        /**
     * @brief Returns the `sheetParent` property of `NSWindow`.
     * @details Returns the window that the sheet is directly attached to. This is based on the logical attachment of the sheet, not visual attachment. This relationship exists starting when the sheet is begun (using \\c NSApplication's '-beginSheet:modalForWindow:modalDelegate:didEndSelector:contextInfo: or NSWindow's -beginSheet:completionHandler:'), and ending once it is ordered out. Returns nil if the window is not a sheet or has no sheet parent.
     * @return The converted Objective-C result.
     */
        Window sheet_parent() const;
        /**
     * @brief Returns the `sheets` property of `NSWindow`.
     * @details An ordered array of the sheets on the window. This consists of the presented sheets in top-to-bottom order, followed by queued sheets in the order they were queued. This does not include nested/sub-sheets.
     * @return The converted Objective-C result.
     */
        std::vector<Window> sheets() const;
        /**
     * @brief Returns the `showsToolbarButton` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool shows_toolbar_button() const;
        /**
     * @brief Sets the `showsToolbarButton` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_toolbar_button(bool value) const;
        /**
     * @brief Returns the `stringWithSavedFrame` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        std::string string_with_saved_frame() const;
        /**
     * @brief Returns the `styleMask` property of `NSWindow`.
     * @details \@note The styleMask can only be set on macOS 10.6 and later. Valid \\c styleMask settings have the same restrictions as the \\c styleMask passed to '-initWithContentRect:styleMask:backing:defer:'. Some \\c styleMask changes will cause the view hierarchy to be rebuilt, since there is a different subclass for the top level view of a borderless window than for the top level view of a titled window.
     * @return The converted Objective-C result.
     */
        WindowStyle style_mask() const;
        /**
     * @brief Sets the `styleMask` property of `NSWindow`.
     * @details \@note The styleMask can only be set on macOS 10.6 and later. Valid \\c styleMask settings have the same restrictions as the \\c styleMask passed to '-initWithContentRect:styleMask:backing:defer:'. Some \\c styleMask changes will cause the view hierarchy to be rebuilt, since there is a different subclass for the top level view of a borderless window than for the top level view of a titled window.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_style_mask(WindowStyle value) const;
        /**
     * @brief Returns the `subtitle` property of `NSWindow`.
     * @details Secondary text that may be displayed adjacent to or below the primary title depending on the configuration of the window. A value of empty string will remove the subtitle from the window layout.
     * @return The converted Objective-C result.
     */
        std::string subtitle() const;
        /**
     * @brief Sets the `subtitle` property of `NSWindow`.
     * @details Secondary text that may be displayed adjacent to or below the primary title depending on the configuration of the window. A value of empty string will remove the subtitle from the window layout.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_subtitle(const std::string& value) const;
        /**
     * @brief Returns the `tab` property of `NSWindow`.
     * @details Access the properties for this window when it is a tabbed window environment. See the \\c NSWindowTab header and comments for more information.
     * @return The converted Objective-C result.
     */
        WindowTab tab() const;
        /**
     * @brief Returns the `tabGroup` property of `NSWindow`.
     * @details Represents a tab group of windows. This \\c tabGroup is lazily created on demand.
     * @return The converted Objective-C result.
     */
        WindowTabGroup tab_group() const;
        /**
     * @brief Returns the `tabbedWindows` property of `NSWindow`.
     * @details This is now a cover for 'self.tabGroup.windows', but will return nil if the window is not showing a tab bar.
     * @return The converted Objective-C result.
     */
        std::vector<Window> tabbed_windows() const;
        /**
     * @brief Returns the `tabbingIdentifier` property of `NSWindow`.
     * @details Windows with the same \\c tabbingIdentifier will have the ability to be tabbed together when a window is being shown. This allows aggregation of similar windows. By default, the \\c tabbingIdentifier will be generated based on inherent window properties, such as the window class name, the delegate class name, the window controller class name, and some additional state. Windows can be explicitly made to group together by using the same \\c tabbingIdentifier.
     * @return The converted Objective-C result.
     */
        std::string tabbing_identifier() const;
        /**
     * @brief Sets the `tabbingIdentifier` property of `NSWindow`.
     * @details Windows with the same \\c tabbingIdentifier will have the ability to be tabbed together when a window is being shown. This allows aggregation of similar windows. By default, the \\c tabbingIdentifier will be generated based on inherent window properties, such as the window class name, the delegate class name, the window controller class name, and some additional state. Windows can be explicitly made to group together by using the same \\c tabbingIdentifier.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tabbing_identifier(const std::string& value) const;
        /**
     * @brief Returns the `tabbingMode` property of `NSWindow`.
     * @details Get and set the tabbing mode for this window. This should be set before a window is shown. The default value is \\c NSWindowTabbingModeAutomatic. When the value is \\c NSWindowTabbingModeAutomatic, the system will look at the \\c userTabbingPreference and automatically tab windows together based on the tabbingIdentifier, when it is appropriate to do so.
     * @return The converted Objective-C result.
     */
        WindowTabbingMode tabbing_mode() const;
        /**
     * @brief Sets the `tabbingMode` property of `NSWindow`.
     * @details Get and set the tabbing mode for this window. This should be set before a window is shown. The default value is \\c NSWindowTabbingModeAutomatic. When the value is \\c NSWindowTabbingModeAutomatic, the system will look at the \\c userTabbingPreference and automatically tab windows together based on the tabbingIdentifier, when it is appropriate to do so.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tabbing_mode(WindowTabbingMode value) const;
        /**
     * @brief Returns the `title` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
        /**
     * @brief Returns the `titleVisibility` property of `NSWindow`.
     * @details See the enum values for how this property works.
     * @return The converted Objective-C result.
     */
        TitleVisibility title_visibility() const;
        /**
     * @brief Sets the `titleVisibility` property of `NSWindow`.
     * @details See the enum values for how this property works.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title_visibility(TitleVisibility value) const;
        /**
     * @brief Returns the `titlebarAccessoryViewControllers` property of `NSWindow`.
     * @details The following methods allow you to add accessory views to the titlebar/toolbar area of a window. See NSTitlebarAccessoryViewController for more details.
     * @return The converted Objective-C result.
     */
        std::vector<TitlebarAccessoryViewController> titlebar_accessory_view_controllers() const;
        /**
     * @brief Sets the `titlebarAccessoryViewControllers` property of `NSWindow`.
     * @details The following methods allow you to add accessory views to the titlebar/toolbar area of a window. See NSTitlebarAccessoryViewController for more details.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_titlebar_accessory_view_controllers(const std::vector<TitlebarAccessoryViewController>& value) const;
        /**
     * @brief Returns the `titlebarAppearsTransparent` property of `NSWindow`.
     * @details When \\c YES, the titlebar doesn't draw its background, allowing all buttons to show through, and "click through" to happen. In general, this is only useful when \\c NSFullSizeContentViewWindowMask is set.
     * @return The converted Objective-C result.
     */
        bool titlebar_appears_transparent() const;
        /**
     * @brief Sets the `titlebarAppearsTransparent` property of `NSWindow`.
     * @details When \\c YES, the titlebar doesn't draw its background, allowing all buttons to show through, and "click through" to happen. In general, this is only useful when \\c NSFullSizeContentViewWindowMask is set.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_titlebar_appears_transparent(bool value) const;
        /**
     * @brief Returns the `titlebarSeparatorStyle` property of `NSWindow`.
     * @details Specifies the style of separator displayed between the window's titlebar and content. The default value is NSTitlebarSeparatorStyleAutomatic. Changing this value will override any preference made by 'NSSplitViewItem'.
     * @return The converted Objective-C result.
     */
        TitlebarSeparatorStyle titlebar_separator_style() const;
        /**
     * @brief Sets the `titlebarSeparatorStyle` property of `NSWindow`.
     * @details Specifies the style of separator displayed between the window's titlebar and content. The default value is NSTitlebarSeparatorStyleAutomatic. Changing this value will override any preference made by 'NSSplitViewItem'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_titlebar_separator_style(TitlebarSeparatorStyle value) const;
        /**
     * @brief Returns the `toolbar` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        Toolbar toolbar() const;
        /**
     * @brief Sets the `toolbar` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_toolbar(const Toolbar& value) const;
        /**
     * @brief Returns the `toolbarStyle` property of `NSWindow`.
     * @details Specifies how the titlebar area of the window should appear when the window displays an NSToolbar
     * @return The converted Objective-C result.
     */
        ToolbarStyle toolbar_style() const;
        /**
     * @brief Sets the `toolbarStyle` property of `NSWindow`.
     * @details Specifies how the titlebar area of the window should appear when the window displays an NSToolbar
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_toolbar_style(ToolbarStyle value) const;
        /**
     * @brief Returns the `userTabbingPreference` property of `NSWindow`.
     * @details Returns the user's tabbing preference as set in System Preferences. This value should be queried anytime a new window is made to see if the user wants to automatically show it in tabs.
     * @return The converted Objective-C result.
     */
        static WindowUserTabbingPreference user_tabbing_preference();
        /**
     * @brief Returns the `viewsNeedDisplay` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool views_need_display() const;
        /**
     * @brief Sets the `viewsNeedDisplay` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_views_need_display(bool value) const;
        /**
     * @brief Returns the `visible` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_visible() const;
        /**
     * @brief Returns the `windowController` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        WindowController window_controller() const;
        /**
     * @brief Sets the `windowController` property of `NSWindow`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_window_controller(const WindowController& value) const;
        /**
     * @brief Returns the `windowNumber` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        std::int64_t window_number() const;
        /**
     * @brief Returns the `windowTitlebarLayoutDirection` property of `NSWindow`.
     * @details Retrieve the layout direction of the window titlebar: this includes the standard window buttons (close/minimize/maximize buttons) and the title for this window. In general, this will return "right to left" (RTL) if the primary system language is RTL. The layout direction may be RTL even in applications that do not have a RTL language localization. This value should be utilized if an application uses titlebarAppearsTransparent and places controls underneath the titlebar.
     * @return The converted Objective-C result.
     */
        UserInterfaceLayoutDirection window_titlebar_layout_direction() const;
        /**
     * @brief Returns the `worksWhenModal` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool works_when_modal() const;
        /**
     * @brief Returns the `zoomable` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_zoomable() const;
        /**
     * @brief Returns the `zoomed` property of `NSWindow`.
     * @return The converted Objective-C result.
     */
        bool is_zoomed() const;
        /// @brief Convenience helper `show` provided by cocoon.
        void show() const;
        /// @brief Convenience helper `hide` provided by cocoon.
        void hide() const;
        /// @brief Convenience helper `close` provided by cocoon.
        void close() const;
        /// @brief Convenience helper `center` provided by cocoon.
        void center() const;
        /// @brief Convenience helper `minimize` provided by cocoon.
        void minimize() const;
        /// @brief Convenience helper `toggle_full_screen` provided by cocoon.
        void toggle_full_screen() const;
        /// @brief Convenience helper `raise` provided by cocoon.
        void raise() const;
        /// @brief Convenience helper `is_full_screen` provided by cocoon.
        bool is_full_screen() const;
        /// @brief Convenience helper `set_content` provided by cocoon.
        void set_content(const ViewController& controller) const;
        /// @brief Convenience helper `size` provided by cocoon.
        Size size() const;
        /// @brief Convenience helper `set_always_on_top` provided by cocoon.
        void set_always_on_top(bool always_on_top) const;
        /// @brief Convenience helper `begin_sheet` provided by cocoon.
        void begin_sheet(const Window& sheet, std::function<void()> on_finished = {}) const;
        /// @brief Convenience helper `end_sheet` provided by cocoon.
        void end_sheet(const Window& sheet) const;
        /// @brief Signal for the delegate/data-source method behind `should_close`; connect a callback with `should_close().connect(...)`.
        Signal<Window, bool()> should_close() const
        {
            return Signal<Window, bool()>(handle(), "should_close");
        }
        /// @brief Signal for the delegate/data-source method behind `will_return_field_editor_to_object`; connect a callback with `will_return_field_editor_to_object().connect(...)`.
        Signal<Window, Object(Object)> will_return_field_editor_to_object() const
        {
            return Signal<Window, Object(Object)>(handle(), "will_return_field_editor_to_object");
        }
        /// @brief Signal for the delegate/data-source method behind `will_resize_to_size`; connect a callback with `will_resize_to_size().connect(...)`.
        Signal<Window, Size(Size)> will_resize_to_size() const
        {
            return Signal<Window, Size(Size)>(handle(), "will_resize_to_size");
        }
        /// @brief Signal for the delegate/data-source method behind `will_use_standard_frame_default_frame`; connect a callback with `will_use_standard_frame_default_frame().connect(...)`.
        Signal<Window, Rect(Rect)> will_use_standard_frame_default_frame() const
        {
            return Signal<Window, Rect(Rect)>(handle(), "will_use_standard_frame_default_frame");
        }
        /// @brief Signal for the delegate/data-source method behind `should_zoom_to_frame`; connect a callback with `should_zoom_to_frame().connect(...)`.
        Signal<Window, bool(Rect)> should_zoom_to_frame() const
        {
            return Signal<Window, bool(Rect)>(handle(), "should_zoom_to_frame");
        }
        /// @brief Signal for the delegate/data-source method behind `will_return_undo_manager`; connect a callback with `will_return_undo_manager().connect(...)`.
        Signal<Window, UndoManager()> will_return_undo_manager() const
        {
            return Signal<Window, UndoManager()>(handle(), "will_return_undo_manager");
        }
        /// @brief Signal for the delegate/data-source method behind `will_position_sheet_using_rect`; connect a callback with `will_position_sheet_using_rect().connect(...)`.
        Signal<Window, Rect(Window, Rect)> will_position_sheet_using_rect() const
        {
            return Signal<Window, Rect(Window, Rect)>(handle(), "will_position_sheet_using_rect");
        }
        /// @brief Signal for the delegate/data-source method behind `should_pop_up_document_path_menu`; connect a callback with `should_pop_up_document_path_menu().connect(...)`.
        Signal<Window, bool(Menu)> should_pop_up_document_path_menu() const
        {
            return Signal<Window, bool(Menu)>(handle(), "should_pop_up_document_path_menu");
        }
        /// @brief Signal for the delegate/data-source method behind `should_drag_document_with_event_from_with_pasteboard`; connect a callback with `should_drag_document_with_event_from_with_pasteboard().connect(...)`.
        Signal<Window, bool(Event, Point, Pasteboard)> should_drag_document_with_event_from_with_pasteboard() const
        {
            return Signal<Window, bool(Event, Point, Pasteboard)>(handle(), "should_drag_document_with_event_from_with_pasteboard");
        }
        /// @brief Signal for the delegate/data-source method behind `will_use_full_screen_content_size`; connect a callback with `will_use_full_screen_content_size().connect(...)`.
        Signal<Window, Size(Size)> will_use_full_screen_content_size() const
        {
            return Signal<Window, Size(Size)>(handle(), "will_use_full_screen_content_size");
        }
        /// @brief Signal for the delegate/data-source method behind `will_use_full_screen_presentation_options`; connect a callback with `will_use_full_screen_presentation_options().connect(...)`.
        Signal<Window, ApplicationPresentationOptions(ApplicationPresentationOptions)> will_use_full_screen_presentation_options() const
        {
            return Signal<Window, ApplicationPresentationOptions(ApplicationPresentationOptions)>(handle(), "will_use_full_screen_presentation_options");
        }
        /// @brief Signal for the delegate/data-source method behind `custom_windows_to_enter_full_screen_for_window`; connect a callback with `custom_windows_to_enter_full_screen_for_window().connect(...)`.
        Signal<Window, std::vector<Window>()> custom_windows_to_enter_full_screen_for_window() const
        {
            return Signal<Window, std::vector<Window>()>(handle(), "custom_windows_to_enter_full_screen_for_window");
        }
        /// @brief Signal for the delegate/data-source method behind `start_custom_animation_to_enter_full_screen_with_duration`; connect a callback with `start_custom_animation_to_enter_full_screen_with_duration().connect(...)`.
        Signal<Window, void(double)> start_custom_animation_to_enter_full_screen_with_duration() const
        {
            return Signal<Window, void(double)>(handle(), "start_custom_animation_to_enter_full_screen_with_duration");
        }
        /// @brief Signal for the delegate/data-source method behind `did_fail_to_enter_full_screen`; connect a callback with `did_fail_to_enter_full_screen().connect(...)`.
        Signal<Window, void()> did_fail_to_enter_full_screen() const
        {
            return Signal<Window, void()>(handle(), "did_fail_to_enter_full_screen");
        }
        /// @brief Signal for the delegate/data-source method behind `custom_windows_to_exit_full_screen_for_window`; connect a callback with `custom_windows_to_exit_full_screen_for_window().connect(...)`.
        Signal<Window, std::vector<Window>()> custom_windows_to_exit_full_screen_for_window() const
        {
            return Signal<Window, std::vector<Window>()>(handle(), "custom_windows_to_exit_full_screen_for_window");
        }
        /// @brief Signal for the delegate/data-source method behind `start_custom_animation_to_exit_full_screen_with_duration`; connect a callback with `start_custom_animation_to_exit_full_screen_with_duration().connect(...)`.
        Signal<Window, void(double)> start_custom_animation_to_exit_full_screen_with_duration() const
        {
            return Signal<Window, void(double)>(handle(), "start_custom_animation_to_exit_full_screen_with_duration");
        }
        /// @brief Signal for the delegate/data-source method behind `custom_windows_to_enter_full_screen_for_window_on_screen`; connect a callback with `custom_windows_to_enter_full_screen_for_window_on_screen().connect(...)`.
        Signal<Window, std::vector<Window>(Screen)> custom_windows_to_enter_full_screen_for_window_on_screen() const
        {
            return Signal<Window, std::vector<Window>(Screen)>(handle(), "custom_windows_to_enter_full_screen_for_window_on_screen");
        }
        /// @brief Signal for the delegate/data-source method behind `start_custom_animation_to_enter_full_screen_on_screen_with_duration`; connect a callback with `start_custom_animation_to_enter_full_screen_on_screen_with_duration().connect(...)`.
        Signal<Window, void(Screen, double)> start_custom_animation_to_enter_full_screen_on_screen_with_duration() const
        {
            return Signal<Window, void(Screen, double)>(handle(), "start_custom_animation_to_enter_full_screen_on_screen_with_duration");
        }
        /// @brief Signal for the delegate/data-source method behind `did_fail_to_exit_full_screen`; connect a callback with `did_fail_to_exit_full_screen().connect(...)`.
        Signal<Window, void()> did_fail_to_exit_full_screen() const
        {
            return Signal<Window, void()>(handle(), "did_fail_to_exit_full_screen");
        }
        /// @brief Signal for the delegate/data-source method behind `will_resize_for_version_browser_with_max_preferred_size_max_allowed_size`; connect a callback with `will_resize_for_version_browser_with_max_preferred_size_max_allowed_size().connect(...)`.
        Signal<Window, Size(Size, Size)> will_resize_for_version_browser_with_max_preferred_size_max_allowed_size() const
        {
            return Signal<Window, Size(Size, Size)>(handle(), "will_resize_for_version_browser_with_max_preferred_size_max_allowed_size");
        }
        /// @brief Signal for the delegate/data-source method behind `will_encode_restorable_state`; connect a callback with `will_encode_restorable_state().connect(...)`.
        Signal<Window, void(Coder)> will_encode_restorable_state() const
        {
            return Signal<Window, void(Coder)>(handle(), "will_encode_restorable_state");
        }
        /// @brief Signal for the delegate/data-source method behind `did_decode_restorable_state`; connect a callback with `did_decode_restorable_state().connect(...)`.
        Signal<Window, void(Coder)> did_decode_restorable_state() const
        {
            return Signal<Window, void(Coder)>(handle(), "did_decode_restorable_state");
        }
        /// @brief Signal for the delegate/data-source method behind `preview_representable_activity_items_for_window`; connect a callback with `preview_representable_activity_items_for_window().connect(...)`.
        Signal<Window, std::vector<Object>()> preview_representable_activity_items_for_window() const
        {
            return Signal<Window, std::vector<Object>()>(handle(), "preview_representable_activity_items_for_window");
        }
        /// @brief Signal for the delegate/data-source method behind `for_sharing_request_from_window`; connect a callback with `for_sharing_request_from_window().connect(...)`.
        Signal<Window, Window()> for_sharing_request_from_window() const
        {
            return Signal<Window, Window()>(handle(), "for_sharing_request_from_window");
        }
        /// @brief Signal for the delegate/data-source method behind `resized`; connect a callback with `resized().connect(...)`.
        Signal<Window, void(Size)> resized() const
        {
            return Signal<Window, void(Size)>(handle(), "resized");
        }
        /// @brief Signal for the delegate/data-source method behind `did_expose`; connect a callback with `did_expose().connect(...)`.
        Signal<Window, void(Notification)> did_expose() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_expose");
        }
        /// @brief Signal for the delegate/data-source method behind `will_move`; connect a callback with `will_move().connect(...)`.
        Signal<Window, void(Notification)> will_move() const
        {
            return Signal<Window, void(Notification)>(handle(), "will_move");
        }
        /// @brief Signal for the delegate/data-source method behind `did_move`; connect a callback with `did_move().connect(...)`.
        Signal<Window, void(Notification)> did_move() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_move");
        }
        /// @brief Signal for the delegate/data-source method behind `did_become_key`; connect a callback with `did_become_key().connect(...)`.
        Signal<Window, void(Notification)> did_become_key() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_become_key");
        }
        /// @brief Signal for the delegate/data-source method behind `did_resign_key`; connect a callback with `did_resign_key().connect(...)`.
        Signal<Window, void(Notification)> did_resign_key() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_resign_key");
        }
        /// @brief Signal for the delegate/data-source method behind `did_become_main`; connect a callback with `did_become_main().connect(...)`.
        Signal<Window, void(Notification)> did_become_main() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_become_main");
        }
        /// @brief Signal for the delegate/data-source method behind `did_resign_main`; connect a callback with `did_resign_main().connect(...)`.
        Signal<Window, void(Notification)> did_resign_main() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_resign_main");
        }
        /// @brief Signal for the delegate/data-source method behind `will_close`; connect a callback with `will_close().connect(...)`.
        Signal<Window, void(Notification)> will_close() const
        {
            return Signal<Window, void(Notification)>(handle(), "will_close");
        }
        /// @brief Signal for the delegate/data-source method behind `will_miniaturize`; connect a callback with `will_miniaturize().connect(...)`.
        Signal<Window, void(Notification)> will_miniaturize() const
        {
            return Signal<Window, void(Notification)>(handle(), "will_miniaturize");
        }
        /// @brief Signal for the delegate/data-source method behind `did_miniaturize`; connect a callback with `did_miniaturize().connect(...)`.
        Signal<Window, void(Notification)> did_miniaturize() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_miniaturize");
        }
        /// @brief Signal for the delegate/data-source method behind `did_deminiaturize`; connect a callback with `did_deminiaturize().connect(...)`.
        Signal<Window, void(Notification)> did_deminiaturize() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_deminiaturize");
        }
        /// @brief Signal for the delegate/data-source method behind `did_update`; connect a callback with `did_update().connect(...)`.
        Signal<Window, void(Notification)> did_update() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_update");
        }
        /// @brief Signal for the delegate/data-source method behind `did_change_screen`; connect a callback with `did_change_screen().connect(...)`.
        Signal<Window, void(Notification)> did_change_screen() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_change_screen");
        }
        /// @brief Signal for the delegate/data-source method behind `did_change_screen_profile`; connect a callback with `did_change_screen_profile().connect(...)`.
        Signal<Window, void(Notification)> did_change_screen_profile() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_change_screen_profile");
        }
        /// @brief Signal for the delegate/data-source method behind `did_change_backing_properties`; connect a callback with `did_change_backing_properties().connect(...)`.
        Signal<Window, void(Notification)> did_change_backing_properties() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_change_backing_properties");
        }
        /// @brief Signal for the delegate/data-source method behind `will_begin_sheet`; connect a callback with `will_begin_sheet().connect(...)`.
        Signal<Window, void(Notification)> will_begin_sheet() const
        {
            return Signal<Window, void(Notification)>(handle(), "will_begin_sheet");
        }
        /// @brief Signal for the delegate/data-source method behind `did_end_sheet`; connect a callback with `did_end_sheet().connect(...)`.
        Signal<Window, void(Notification)> did_end_sheet() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_end_sheet");
        }
        /// @brief Signal for the delegate/data-source method behind `will_start_live_resize`; connect a callback with `will_start_live_resize().connect(...)`.
        Signal<Window, void(Notification)> will_start_live_resize() const
        {
            return Signal<Window, void(Notification)>(handle(), "will_start_live_resize");
        }
        /// @brief Signal for the delegate/data-source method behind `did_end_live_resize`; connect a callback with `did_end_live_resize().connect(...)`.
        Signal<Window, void(Notification)> did_end_live_resize() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_end_live_resize");
        }
        /// @brief Signal for the delegate/data-source method behind `will_enter_full_screen`; connect a callback with `will_enter_full_screen().connect(...)`.
        Signal<Window, void(Notification)> will_enter_full_screen() const
        {
            return Signal<Window, void(Notification)>(handle(), "will_enter_full_screen");
        }
        /// @brief Signal for the delegate/data-source method behind `did_enter_full_screen`; connect a callback with `did_enter_full_screen().connect(...)`.
        Signal<Window, void(Notification)> did_enter_full_screen() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_enter_full_screen");
        }
        /// @brief Signal for the delegate/data-source method behind `will_exit_full_screen`; connect a callback with `will_exit_full_screen().connect(...)`.
        Signal<Window, void(Notification)> will_exit_full_screen() const
        {
            return Signal<Window, void(Notification)>(handle(), "will_exit_full_screen");
        }
        /// @brief Signal for the delegate/data-source method behind `did_exit_full_screen`; connect a callback with `did_exit_full_screen().connect(...)`.
        Signal<Window, void(Notification)> did_exit_full_screen() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_exit_full_screen");
        }
        /// @brief Signal for the delegate/data-source method behind `will_enter_version_browser`; connect a callback with `will_enter_version_browser().connect(...)`.
        Signal<Window, void(Notification)> will_enter_version_browser() const
        {
            return Signal<Window, void(Notification)>(handle(), "will_enter_version_browser");
        }
        /// @brief Signal for the delegate/data-source method behind `did_enter_version_browser`; connect a callback with `did_enter_version_browser().connect(...)`.
        Signal<Window, void(Notification)> did_enter_version_browser() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_enter_version_browser");
        }
        /// @brief Signal for the delegate/data-source method behind `will_exit_version_browser`; connect a callback with `will_exit_version_browser().connect(...)`.
        Signal<Window, void(Notification)> will_exit_version_browser() const
        {
            return Signal<Window, void(Notification)>(handle(), "will_exit_version_browser");
        }
        /// @brief Signal for the delegate/data-source method behind `did_exit_version_browser`; connect a callback with `did_exit_version_browser().connect(...)`.
        Signal<Window, void(Notification)> did_exit_version_browser() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_exit_version_browser");
        }
        /// @brief Signal for the delegate/data-source method behind `did_change_occlusion_state`; connect a callback with `did_change_occlusion_state().connect(...)`.
        Signal<Window, void(Notification)> did_change_occlusion_state() const
        {
            return Signal<Window, void(Notification)>(handle(), "did_change_occlusion_state");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
