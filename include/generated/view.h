#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/responder.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class BitmapImageRep;
    class CALayer;
    class CandidateListTouchBarItemBase;
    class ClipView;
    class Color;
    class Cursor;
    class DraggingItem;
    class DraggingSession;
    class Event;
    class GestureRecognizer;
    class GraphicsContext;
    class LayoutConstraint;
    class LayoutDimension;
    class LayoutGuide;
    class LayoutXAxisAnchor;
    class LayoutYAxisAnchor;
    class Menu;
    class MenuItem;
    class Pasteboard;
    class PressureConfiguration;
    class RulerMarker;
    class RulerView;
    class Screen;
    class ScrollView;
    class Shadow;
    class TextInputContext;
    class TrackingArea;
    class ViewLayoutRegion;
    class Window;
    class WritingToolsCoordinator;

    /**
     * @brief The base of all views (NSView): hierarchy, geometry, Auto Layout helpers and appearance.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Responder.
     *
     * @par Example
     * @code
     * cocoon::View container;
     * cocoon::Button button("Press");
     * container.add_subview(button);
     * button.pin_to_superview(cocoon::Insets(12));
     * container.set_background_color(cocoon::Color(0.1, 0.2, 0.3));
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::View view{};
     * view.set_additional_safe_area_insets(cocoon::Insets(8));
     * auto additional_safe_area_insets = view.additional_safe_area_insets();
     * view.set_allowed_touch_types(cocoon::TouchTypeMask::Direct);
     * auto allowed_touch_types = view.allowed_touch_types();
     * view.set_alpha_value(1);
     * auto alpha_value = view.alpha_value();
     * view.accepts_first_mouse(cocoon::Event());
     * view.add_constraint(cocoon::LayoutConstraint());
     * view.add_cursor_rect({{0, 0}, {100, 100}}, cocoon::Cursor());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsview
     */
    class View : public Responder
    {
    public:
        /// @brief Creates a new `NSView` instance and returns a handle to it.
        explicit View();
        /// @brief Creates a new `NSView` instance and returns a handle to it.
        explicit View(const Rect& frame_rect);
        /// @brief Creates a null handle that refers to no native object.
        View(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit View(Adopt adopt);
        using Responder::perform_key_equivalent;
        /**
     * @brief Calls `-[NSView acceptsFirstMouse:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool accepts_first_mouse(const Event& event) const;
        /**
     * @brief Calls `-[NSView addConstraint:]`.
     * @param constraint Argument converted to the Objective-C parameter of the same role.
     */
        void add_constraint(const LayoutConstraint& constraint) const;
        /**
     * @brief Calls `-[NSView addConstraints:]`.
     * @param constraints Argument converted to the Objective-C parameter of the same role.
     */
        void add_constraints(const std::vector<LayoutConstraint>& constraints) const;
        /**
     * @brief Calls `-[NSView addCursorRect:cursor:]`.
     * @details The following methods are soft deprecated. Use the above NSTrackingArea API instead
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void add_cursor_rect(const Rect& rect, const Cursor& object) const;
        /**
     * @brief Calls `-[NSView addGestureRecognizer:]`.
     * @param gesture_recognizer Argument converted to the Objective-C parameter of the same role.
     */
        void add_gesture_recognizer(const GestureRecognizer& gesture_recognizer) const;
        /**
     * @brief Calls `-[NSView addLayoutGuide:]`.
     * @param guide Argument converted to the Objective-C parameter of the same role.
     */
        void add_layout_guide(const LayoutGuide& guide) const;
        /**
     * @brief Calls `-[NSView addSubview:positioned:relativeTo:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param place Argument converted to the Objective-C parameter of the same role.
     * @param other_view Argument converted to the Objective-C parameter of the same role.
     */
        void add_subview(const View& view, WindowOrderingMode place, const View& other_view) const;
        /**
     * @brief Calls `-[NSView addToolTipRect:owner:userData:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param owner Argument converted to the Objective-C parameter of the same role.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t add_tool_tip_rect(const Rect& rect, const Object& owner, void* data) const;
        /**
     * @brief Calls `-[NSView addTrackingArea:]`.
     * @details The following methods are meant to be invoked, and probably don't need to be overridden
     * @param tracking_area Argument converted to the Objective-C parameter of the same role.
     */
        void add_tracking_area(const TrackingArea& tracking_area) const;
        /**
     * @brief Calls `-[NSView addTrackingRect:owner:userData:assumeInside:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param owner Argument converted to the Objective-C parameter of the same role.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t add_tracking_rect(const Rect& rect, const Object& owner, void* data, bool flag) const;
        /**
     * @brief Calls `-[NSView adjustPageHeightNew:top:bottom:limit:]`.
     * @param new_bottom Argument converted to the Objective-C parameter of the same role.
     * @param old_top Argument converted to the Objective-C parameter of the same role.
     * @param old_bottom Argument converted to the Objective-C parameter of the same role.
     * @param bottom_limit Argument converted to the Objective-C parameter of the same role.
     */
        void adjust_page_height_new(double* new_bottom, double old_top, double old_bottom, double bottom_limit) const;
        /**
     * @brief Calls `-[NSView adjustPageWidthNew:left:right:limit:]`.
     * @param new_right Argument converted to the Objective-C parameter of the same role.
     * @param old_left Argument converted to the Objective-C parameter of the same role.
     * @param old_right Argument converted to the Objective-C parameter of the same role.
     * @param right_limit Argument converted to the Objective-C parameter of the same role.
     */
        void adjust_page_width_new(double* new_right, double old_left, double old_right, double right_limit) const;
        /**
     * @brief Calls `-[NSView adjustScroll:]`.
     * @param new_visible Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect adjust_scroll(const Rect& new_visible) const;
        /**
     * @brief Calls `-[NSView alignmentRectForFrame:]`.
     * @param frame Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect alignment_rect_for_frame(const Rect& frame) const;
        /**
     * @brief Calls `-[NSView ancestorSharedWithView:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        View ancestor_shared_with_view(const View& view) const;
        /**
     * @brief Calls `-[NSView autoscroll:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool autoscroll(const Event& event) const;
        /**
     * @brief Calls `-[NSView backingAlignedRect:options:]`.
     * @details Uses NSIntegralRectWithOptions() to produce a backing store pixel aligned rectangle from the given input rectangle in local view coordinates.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect backing_aligned_rect(const Rect& rect, AlignmentOptions options) const;
        /**
     * @brief Calls `-[NSView beginDocument]`.
     */
        void begin_document() const;
        /**
     * @brief Calls `-[NSView beginDraggingSessionWithItems:event:source:]`.
     * @details Starts a dragging session with a group of NSDraggingItems. The frame property of each NSDraggingItem must be in the view's coordinate system. The images may animate (flock) from thier initial layout into a system defined formation. Flocking or may not be done immediately. (see NSDraggingSession's flockOnBeginDrag. The visible area of the view is used as the clip rect.
     * @param items Argument converted to the Objective-C parameter of the same role.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param source Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DraggingSession begin_dragging_session_with_items(const std::vector<DraggingItem>& items, const Event& event, const Object& source) const;
        /**
     * @brief Calls `-[NSView beginPageInRect:atPlacement:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param location Argument converted to the Objective-C parameter of the same role.
     */
        void begin_page_in_rect(const Rect& rect, const Point& location) const;
        /**
     * @brief Calls `-[NSView bitmapImageRepForCachingDisplayInRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        BitmapImageRep bitmap_image_rep_for_caching_display_in_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView cacheDisplayInRect:toBitmapImageRep:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param bitmap_image_rep Argument converted to the Objective-C parameter of the same role.
     */
        void cache_display_in_rect(const Rect& rect, const BitmapImageRep& bitmap_image_rep) const;
        /**
     * @brief Calls `-[NSView centerScanRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect center_scan_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView constraintsAffectingLayoutForOrientation:]`.
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<LayoutConstraint> constraints_affecting_layout_for_orientation(ConstraintOrientation orientation) const;
        /**
     * @brief Calls `-[NSView contentCompressionResistancePriorityForOrientation:]`.
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        float content_compression_resistance_priority_for_orientation(ConstraintOrientation orientation) const;
        /**
     * @brief Calls `-[NSView contentHuggingPriorityForOrientation:]`.
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        float content_hugging_priority_for_orientation(ConstraintOrientation orientation) const;
        /**
     * @brief Calls `-[NSView convertPoint:fromView:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point convert_point(const Point& point, const View& view) const;
        /**
     * @brief Calls `-[NSView convertPointFromBacking:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point convert_point_from_backing(const Point& point) const;
        /**
     * @brief Calls `-[NSView convertPointFromLayer:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point convert_point_from_layer(const Point& point) const;
        /**
     * @brief Calls `-[NSView convertPointToBacking:]`.
     * @details New methods for converting to and from backing store pixels
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point convert_point_to_backing(const Point& point) const;
        /**
     * @brief Calls `-[NSView convertPointToLayer:]`.
     * @details Use these methods to transform geometry between a view's interior (bounds) coordinate space and its layer's interior coordinate space. The layer's space is virtual, and doesn't take into account the layer's contentsScale setting. For conversion between view space and layer pixels, use -convert(Point/Size/Rect)(To/From)Backing: instead.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point convert_point_to_layer(const Point& point) const;
        /**
     * @brief Calls `-[NSView convertRect:fromView:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect convert_rect(const Rect& rect, const View& view) const;
        /**
     * @brief Calls `-[NSView convertRectFromBacking:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect convert_rect_from_backing(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView convertRectFromLayer:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect convert_rect_from_layer(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView convertRectToBacking:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect convert_rect_to_backing(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView convertRectToLayer:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect convert_rect_to_layer(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView convertSize:fromView:]`.
     * @param size Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Size convert_size(const Size& size, const View& view) const;
        /**
     * @brief Calls `-[NSView convertSizeFromBacking:]`.
     * @param size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Size convert_size_from_backing(const Size& size) const;
        /**
     * @brief Calls `-[NSView convertSizeFromLayer:]`.
     * @param size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Size convert_size_from_layer(const Size& size) const;
        /**
     * @brief Calls `-[NSView convertSizeToBacking:]`.
     * @param size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Size convert_size_to_backing(const Size& size) const;
        /**
     * @brief Calls `-[NSView convertSizeToLayer:]`.
     * @param size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Size convert_size_to_layer(const Size& size) const;
        /**
     * @brief Calls `-[NSView dataWithEPSInsideRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> data_with_eps_inside_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView dataWithPDFInsideRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> data_with_pdf_inside_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView didAddSubview:]`.
     * @param subview Argument converted to the Objective-C parameter of the same role.
     */
        void did_add_subview(const View& subview) const;
        /**
     * @brief Calls `-[NSView didCloseMenu:withEvent:]`.
     * @details A contextual menu shown from the receiving view has been closed. This is only called if the menu had been opened and the view previously received \\c -willOpenMenu:withEvent:. The view should update any visual state in response — such as removing a temporary selection. \\param menu The contextual menu that was open on the view \\param event The event that caused the menu to close. This may be nil if there is no specific event that triggered the closing.
     * @param menu Argument converted to the Objective-C parameter of the same role.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void did_close_menu(const Menu& menu, const Event& event) const;
        /**
     * @brief Calls `-[NSView discardCursorRects]`.
     */
        void discard_cursor_rects() const;
        /**
     * @brief Calls `-[NSView display]`.
     */
        void display() const;
        /**
     * @brief Calls `-[NSView displayIfNeeded]`.
     */
        void display_if_needed() const;
        /**
     * @brief Calls `-[NSView displayIfNeededIgnoringOpacity]`.
     */
        void display_if_needed_ignoring_opacity() const;
        /**
     * @brief Calls `-[NSView displayIfNeededInRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        void display_if_needed_in_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView displayIfNeededInRectIgnoringOpacity:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        void display_if_needed_in_rect_ignoring_opacity(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView displayLinkWithTarget:selector:]`.
     * @details Returns a new display link whose callback will be invoked in-sync with the display the view is on. If the view is hidden, or not on any display, the callback will not be invoked.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param selector Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object display_link_with_target(const Object& target, const std::string& selector) const;
        /**
     * @brief Calls `-[NSView displayRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        void display_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView displayRectIgnoringOpacity:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        void display_rect_ignoring_opacity(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView displayRectIgnoringOpacity:inContext:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param context Argument converted to the Objective-C parameter of the same role.
     */
        void display_rect_ignoring_opacity(const Rect& rect, const GraphicsContext& context) const;
        /**
     * @brief Calls `-[NSView drawFocusRingMask]`.
     */
        void draw_focus_ring_mask() const;
        /**
     * @brief Calls `-[NSView drawPageBorderWithSize:]`.
     * @param border_size Argument converted to the Objective-C parameter of the same role.
     */
        void draw_page_border_with_size(const Size& border_size) const;
        /**
     * @brief Calls `-[NSView drawRect:]`.
     * @param dirty_rect Argument converted to the Objective-C parameter of the same role.
     */
        void draw_rect(const Rect& dirty_rect) const;
        /**
     * @brief Calls `-[NSView edgeInsetsForLayoutRegion:]`.
     * @param layout_region Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Insets edge_insets_for_layout_region(const ViewLayoutRegion& layout_region) const;
        /**
     * @brief Calls `-[NSView endDocument]`.
     */
        void end_document() const;
        /**
     * @brief Calls `-[NSView endPage]`.
     */
        void end_page() const;
        /**
     * @brief Calls `-[NSView enterFullScreenMode:withOptions:]`.
     * @param screen Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool enter_full_screen_mode(const Screen& screen, const std::map<std::string, Object>& options) const;
        /**
     * @brief Calls `-[NSView exerciseAmbiguityInLayout]`.
     */
        void exercise_ambiguity_in_layout() const;
        /**
     * @brief Calls `-[NSView exitFullScreenModeWithOptions:]`.
     * @param options Argument converted to the Objective-C parameter of the same role.
     */
        void exit_full_screen_mode_with_options(const std::map<std::string, Object>& options) const;
        /**
     * @brief Calls `-[NSView frameForAlignmentRect:]`.
     * @param alignment_rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect frame_for_alignment_rect(const Rect& alignment_rect) const;
        /**
     * @brief Calls `-[NSView getRectsBeingDrawn:count:]`.
     * @param rects Argument converted to the Objective-C parameter of the same role.
     * @param count Argument converted to the Objective-C parameter of the same role.
     */
        void get_rects_being_drawn(Rect** rects, std::int64_t* count) const;
        /**
     * @brief Calls `-[NSView getRectsExposedDuringLiveResize:count:]`.
     * @details On return from -getRectsExposedDuringLiveResize, exposedRects indicates the parts of the view that are newly exposed (at most 4 rects). count indicates how many rects are in the exposedRects list
     * @param exposed_rects Argument converted to the Objective-C parameter of the same role.
     * @param count Argument converted to the Objective-C parameter of the same role.
     */
        void get_rects_exposed_during_live_resize(Rect* exposed_rects, std::int64_t* count) const;
        /**
     * @brief Calls `-[NSView hitTest:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        View hit_test(const Point& point) const;
        /**
     * @brief Calls `-[NSView invalidateIntrinsicContentSize]`.
     */
        void invalidate_intrinsic_content_size() const;
        /**
     * @brief Calls `-[NSView isDescendantOf:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_descendant_of(const View& view) const;
        /**
     * @brief Calls `-[NSView knowsPageRange:]`.
     * @details Pagination
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool knows_page_range(Range* range) const;
        /**
     * @brief Calls `-[NSView layout]`.
     */
        void layout() const;
        /**
     * @brief Calls `-[NSView layoutGuideForLayoutRegion:]`.
     * @param layout_region Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        LayoutGuide layout_guide_for_layout_region(const ViewLayoutRegion& layout_region) const;
        /**
     * @brief Calls `-[NSView layoutSubtreeIfNeeded]`.
     */
        void layout_subtree_if_needed() const;
        /**
     * @brief Calls `-[NSView locationOfPrintRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point location_of_print_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView makeBackingLayer]`.
     * @return The converted Objective-C result.
     */
        CALayer make_backing_layer() const;
        /**
     * @brief Calls `-[NSView menuForEvent:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Menu menu_for_event(const Event& event) const;
        /**
     * @brief Calls `-[NSView mouse:inRect:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool mouse(const Point& point, const Rect& rect) const;
        /**
     * @brief Calls `-[NSView needsToDrawRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool needs_to_draw_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView noteFocusRingMaskChanged]`.
     */
        void note_focus_ring_mask_changed() const;
        /**
     * @brief Calls `-[NSView performKeyEquivalent:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool perform_key_equivalent(const Event& event) const;
        /**
     * @brief Calls `-[NSView prepareContentInRect:]`.
     * @details Called by NSView with a 'rect' for a recommended area that should be fully rendered for overdraw. Override this method and bring in additional subviews and pre-cached content for the 'rect' in order to perform responsive scrolling. Calling super may be required for some subclasses (such as NSTableView and NSOutlineView), so in general, super should always be called. To suppress overdraw for a particular view (such as NSTableView), override this method and call [super prepareContentInRect:[self visibleRect]].
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        void prepare_content_in_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView prepareForReuse]`.
     * @details The View Based NSTableView allows views to be reused. Sometimes it is necessary to prepare a view with some initial state before it is to be reused. This method can be overridden to allow a view to be prepared back to the default state. Override this method to do the preparation. By default, NSView will do some setup, such as setting the view to not be hidden and have a 1.0 alpha. It is important to call super to get this work done. This method was made public in 10.9, but exists back to 10.7.
     */
        void prepare_for_reuse() const;
        /**
     * @brief Calls `-[NSView print:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void print(const Object& sender) const;
        /**
     * @brief Calls `-[NSView rectForLayoutRegion:]`.
     * @param layout_region Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect rect_for_layout_region(const ViewLayoutRegion& layout_region) const;
        /**
     * @brief Calls `-[NSView rectForPage:]`.
     * @param page Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect rect_for_page(std::int64_t page) const;
        /**
     * @brief Calls `-[NSView rectForSmartMagnificationAtPoint:inRect:]`.
     * @details Return the complete rect of the most appropriate content grouping at the specified location. For example, if your content is divided into three columns, return the entire rect of the column that contains the location. NSScrollView will attempt to magnify such that the width fits inside the scroll view while remaining within the minMagnification, maxMagnification range. If your content layout is sub-divided further than one level deep (for example, two boxes that each contain multiple text boxes), then use the visibleRect parameter to determine when to provide the rect of a sub-grouping. Always return a rect for the appropriate grouping. If there is no deeper content grouping, return the rect for the deepest grouping. NSScrollView will determine when to pan, magnify in, and magnify out. Return NSZeroRect for the default behavior.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @param visible_rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect rect_for_smart_magnification_at_point(const Point& location, const Rect& visible_rect) const;
        /**
     * @brief Calls `-[NSView reflectScrolledClipView:]`.
     * @param clip_view Argument converted to the Objective-C parameter of the same role.
     */
        void reflect_scrolled_clip_view(const ClipView& clip_view) const;
        /**
     * @brief Calls `-[NSView registerForDraggedTypes:]`.
     * @param new_types Argument converted to the Objective-C parameter of the same role.
     */
        void register_for_dragged_types(const std::vector<std::string>& new_types) const;
        /**
     * @brief Calls `-[NSView removeAllToolTips]`.
     */
        void remove_all_tool_tips() const;
        /**
     * @brief Calls `-[NSView removeConstraint:]`.
     * @param constraint Argument converted to the Objective-C parameter of the same role.
     */
        void remove_constraint(const LayoutConstraint& constraint) const;
        /**
     * @brief Calls `-[NSView removeConstraints:]`.
     * @param constraints Argument converted to the Objective-C parameter of the same role.
     */
        void remove_constraints(const std::vector<LayoutConstraint>& constraints) const;
        /**
     * @brief Calls `-[NSView removeCursorRect:cursor:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void remove_cursor_rect(const Rect& rect, const Cursor& object) const;
        /**
     * @brief Calls `-[NSView removeFromSuperview]`.
     */
        void remove_from_superview() const;
        /**
     * @brief Calls `-[NSView removeFromSuperviewWithoutNeedingDisplay]`.
     */
        void remove_from_superview_without_needing_display() const;
        /**
     * @brief Calls `-[NSView removeGestureRecognizer:]`.
     * @param gesture_recognizer Argument converted to the Objective-C parameter of the same role.
     */
        void remove_gesture_recognizer(const GestureRecognizer& gesture_recognizer) const;
        /**
     * @brief Calls `-[NSView removeLayoutGuide:]`.
     * @param guide Argument converted to the Objective-C parameter of the same role.
     */
        void remove_layout_guide(const LayoutGuide& guide) const;
        /**
     * @brief Calls `-[NSView removeToolTip:]`.
     * @param tag Argument converted to the Objective-C parameter of the same role.
     */
        void remove_tool_tip(std::int64_t tag) const;
        /**
     * @brief Calls `-[NSView removeTrackingArea:]`.
     * @param tracking_area Argument converted to the Objective-C parameter of the same role.
     */
        void remove_tracking_area(const TrackingArea& tracking_area) const;
        /**
     * @brief Calls `-[NSView removeTrackingRect:]`.
     * @param tag Argument converted to the Objective-C parameter of the same role.
     */
        void remove_tracking_rect(std::int64_t tag) const;
        /**
     * @brief Calls `-[NSView replaceSubview:with:]`.
     * @param old_view Argument converted to the Objective-C parameter of the same role.
     * @param new_view Argument converted to the Objective-C parameter of the same role.
     */
        void replace_subview(const View& old_view, const View& new_view) const;
        /**
     * @brief Calls `-[NSView resetCursorRects]`.
     */
        void reset_cursor_rects() const;
        /**
     * @brief Calls `-[NSView resizeSubviewsWithOldSize:]`.
     * @param old_size Argument converted to the Objective-C parameter of the same role.
     */
        void resize_subviews_with_old_size(const Size& old_size) const;
        /**
     * @brief Calls `-[NSView resizeWithOldSuperviewSize:]`.
     * @param old_size Argument converted to the Objective-C parameter of the same role.
     */
        void resize_with_old_superview_size(const Size& old_size) const;
        /**
     * @brief Calls `-[NSView rotateByAngle:]`.
     * @param angle Argument converted to the Objective-C parameter of the same role.
     */
        void rotate_by_angle(double angle) const;
        /**
     * @brief Calls `-[NSView rulerView:didAddMarker:]`.
     * @param ruler Argument converted to the Objective-C parameter of the same role.
     * @param marker Argument converted to the Objective-C parameter of the same role.
     */
        void ruler_view(const RulerView& ruler, const RulerMarker& marker) const;
        /**
     * @brief Calls `-[NSView rulerView:handleMouseDown:]`.
     * @param ruler Argument converted to the Objective-C parameter of the same role.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void ruler_view(const RulerView& ruler, const Event& event) const;
        /**
     * @brief Calls `-[NSView rulerView:locationForPoint:]`.
     * @param ruler Argument converted to the Objective-C parameter of the same role.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double ruler_view(const RulerView& ruler, const Point& point) const;
        /**
     * @brief Calls `-[NSView rulerView:pointForLocation:]`.
     * @param ruler Argument converted to the Objective-C parameter of the same role.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point ruler_view(const RulerView& ruler, double point) const;
        /**
     * @brief Calls `-[NSView rulerView:willAddMarker:atLocation:]`.
     * @param ruler Argument converted to the Objective-C parameter of the same role.
     * @param marker Argument converted to the Objective-C parameter of the same role.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double ruler_view(const RulerView& ruler, const RulerMarker& marker, double location) const;
        /**
     * @brief Calls `-[NSView rulerView:willSetClientView:]`.
     * @param ruler Argument converted to the Objective-C parameter of the same role.
     * @param new_client Argument converted to the Objective-C parameter of the same role.
     */
        void ruler_view(const RulerView& ruler, const View& new_client) const;
        /**
     * @brief Calls `-[NSView scaleUnitSquareToSize:]`.
     * @param new_unit_size Argument converted to the Objective-C parameter of the same role.
     */
        void scale_unit_square_to_size(const Size& new_unit_size) const;
        /**
     * @brief Calls `-[NSView scrollClipView:toPoint:]`.
     * @param clip_view Argument converted to the Objective-C parameter of the same role.
     * @param point Argument converted to the Objective-C parameter of the same role.
     */
        void scroll_clip_view(const ClipView& clip_view, const Point& point) const;
        /**
     * @brief Calls `-[NSView scrollPoint:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     */
        void scroll_point(const Point& point) const;
        /**
     * @brief Calls `-[NSView scrollRectToVisible:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool scroll_rect_to_visible(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView setBoundsOrigin:]`.
     * @param new_origin Argument converted to the Objective-C parameter of the same role.
     */
        void set_bounds_origin(const Point& new_origin) const;
        /**
     * @brief Calls `-[NSView setBoundsSize:]`.
     * @param new_size Argument converted to the Objective-C parameter of the same role.
     */
        void set_bounds_size(const Size& new_size) const;
        /**
     * @brief Calls `-[NSView setContentCompressionResistancePriority:forOrientation:]`.
     * @param priority Argument converted to the Objective-C parameter of the same role.
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_compression_resistance_priority(float priority, ConstraintOrientation orientation) const;
        /**
     * @brief Calls `-[NSView setContentHuggingPriority:forOrientation:]`.
     * @param priority Argument converted to the Objective-C parameter of the same role.
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_hugging_priority(float priority, ConstraintOrientation orientation) const;
        /**
     * @brief Calls `-[NSView setFrameOrigin:]`.
     * @param new_origin Argument converted to the Objective-C parameter of the same role.
     */
        void set_frame_origin(const Point& new_origin) const;
        /**
     * @brief Calls `-[NSView setFrameSize:]`.
     * @param new_size Argument converted to the Objective-C parameter of the same role.
     */
        void set_frame_size(const Size& new_size) const;
        /**
     * @brief Calls `-[NSView setKeyboardFocusRingNeedsDisplayInRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        void set_keyboard_focus_ring_needs_display_in_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSView setNeedsDisplayInRect:]`.
     * @param invalid_rect Argument converted to the Objective-C parameter of the same role.
     */
        void set_needs_display_in_rect(const Rect& invalid_rect) const;
        /**
     * @brief Calls `-[NSView shouldDelayWindowOrderingForEvent:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool should_delay_window_ordering_for_event(const Event& event) const;
        /**
     * @brief Calls `-[NSView showDefinitionForAttributedString:atPoint:]`.
     * @details Shows a window that displays the definition (or other subject depending on available dictionaries) of the specified attributed string. This method can be used for implementing the same functionality as NSTextView's 'Look Up in Dictionary' contextual menu on a custom view. textBaselineOrigin specifies the baseline origin of attrString in the receiver view coordinate system. If a small overlay window is selected as default presentation (see NSDefinitionPresentationTypeKey option for details), the overlay text would be rendered starting from the location. Otherwise, 'Dictionary' application will be invoked to show the definition of the specified string. This method is equivalent to using showDefinitionForAttributedString:range:options:baselineOriginProvider: and passing attrString with the whole range, nil options, and an originProvider which returns textBaselineOrigin.
     * @param attr_string Argument converted to the Objective-C parameter of the same role.
     * @param text_baseline_origin Argument converted to the Objective-C parameter of the same role.
     */
        void show_definition_for_attributed_string(const AttributedString& attr_string, const Point& text_baseline_origin) const;
        /**
     * @brief Calls `-[NSView showDefinitionForAttributedString:range:options:baselineOriginProvider:]`.
     * @details Takes a whole attributed string with the target range (normally, this is the selected range), and shows a window displaying the definition of the specified range. The caller can pass a zero-length range and the appropriate range will be auto-detected around the range's offset. That's the recommended approach when there is no selection. This method also an 'options' dictionary containing options described below as key-value pairs (can be nil). Except when NSDefinitionPresentationTypeKey with NSDefinitionPresentationTypeDictionaryApplication is specified in options, the caller must supply an originProvider Block which returns the baseline origin of the first character at proposed adjustedRange in the receiver view coordinate system. If the receiver is an NSTextView, both attrString and originProvider may be nil, in which case the text view will automatically supply values suitable for displaying definitions for the specified range within its text content. This method does not cause scrolling, so clients should perform any necessary scrolling before calling this method.
     * @param attr_string Argument converted to the Objective-C parameter of the same role.
     * @param target_range Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param origin_provider Argument converted to the Objective-C parameter of the same role.
     */
        void show_definition_for_attributed_string(const AttributedString& attr_string, const Range& target_range, const std::map<std::string, Object>& options, std::function<Point(Range)> origin_provider) const;
        /**
     * @brief Calls `-[NSView sortSubviewsUsingFunction:context:]`.
     * @param compare Argument converted to the Objective-C parameter of the same role.
     * @param context Argument converted to the Objective-C parameter of the same role.
     */
        void sort_subviews_using_function(ComparisonResult (*compare)(void*, void*, void*), void* context) const;
        /**
     * @brief Calls `-[NSView translateOriginToPoint:]`.
     * @param translation Argument converted to the Objective-C parameter of the same role.
     */
        void translate_origin_to_point(const Point& translation) const;
        /**
     * @brief Calls `-[NSView translateRectsNeedingDisplayInRect:by:]`.
     * @param clip_rect Argument converted to the Objective-C parameter of the same role.
     * @param delta Argument converted to the Objective-C parameter of the same role.
     */
        void translate_rects_needing_display_in_rect(const Rect& clip_rect, const Size& delta) const;
        /**
     * @brief Calls `-[NSView unregisterDraggedTypes]`.
     */
        void unregister_dragged_types() const;
        /**
     * @brief Calls `-[NSView updateConstraints]`.
     */
        void update_constraints() const;
        /**
     * @brief Calls `-[NSView updateConstraintsForSubtreeIfNeeded]`.
     */
        void update_constraints_for_subtree_if_needed() const;
        /**
     * @brief Calls `-[NSView updateLayer]`.
     * @details Layer Backed Views: If the view responds YES to wantsUpdateLayer, then updateLayer will be called as opposed to drawRect:. This method should be used for better performance; it is faster to directly set the layer.contents with a shared image and inform it how to stretch with the layer.contentsCenter property instead of drawing into a context with drawRect:. In general, one should also set the layerContentsRedrawPolicy to an appropriate value in the init method (frequently NSViewLayerContentsRedrawOnSetNeedsDisplay is desired). To signal a refresh of the layer contents, one will then call [view setNeedsDisplay:YES], and -updateLayer will be lazily called when the layer needs its contents. One should not alter geometry or add/remove subviews (or layers) during this method. To add subviews (or layers) use -layout. -layout will still be called even if autolayout is not enabled, and wantsUpdateLayer returns YES.
     */
        void update_layer() const;
        /**
     * @brief Calls `-[NSView updateTrackingAreas]`.
     * @details updateTrackingAreas should be overridden to remove out of date tracking areas and add recomputed tracking areas, and should call super.
     */
        void update_tracking_areas() const;
        /**
     * @brief Calls `-[NSView viewDidChangeBackingProperties]`.
     */
        void view_did_change_backing_properties() const;
        /**
     * @brief Calls `-[NSView viewDidChangeEffectiveAppearance]`.
     * @details Override point for reacting to the effective appearance of the receiver changing. At this point 'effectiveAppearance' property reflects the new appearance.
     */
        void view_did_change_effective_appearance() const;
        /**
     * @brief Calls `-[NSView viewDidEndLiveResize]`.
     * @details A view receives viewWillEndLiveResize after the frame is last changed for a live resize. It is important to call [super viewDidEndLiveResize].
     */
        void view_did_end_live_resize() const;
        /**
     * @brief Calls `-[NSView viewDidHide]`.
     */
        void view_did_hide() const;
        /**
     * @brief Calls `-[NSView viewDidMoveToSuperview]`.
     */
        void view_did_move_to_superview() const;
        /**
     * @brief Calls `-[NSView viewDidMoveToWindow]`.
     */
        void view_did_move_to_window() const;
        /**
     * @brief Calls `-[NSView viewDidUnhide]`.
     */
        void view_did_unhide() const;
        /**
     * @brief Calls `-[NSView viewWillDraw]`.
     */
        void view_will_draw() const;
        /**
     * @brief Calls `-[NSView viewWillMoveToSuperview:]`.
     * @param new_superview Argument converted to the Objective-C parameter of the same role.
     */
        void view_will_move_to_superview(const View& new_superview) const;
        /**
     * @brief Calls `-[NSView viewWillMoveToWindow:]`.
     * @details NOTE: In general, it is good practice to call 'super' for the viewWill and viewDid methods. Some AppKit subclasses, such as NSTableView, depend on this behavior, and calling super is required for things to work properly.
     * @param new_window Argument converted to the Objective-C parameter of the same role.
     */
        void view_will_move_to_window(const Window& new_window) const;
        /**
     * @brief Calls `-[NSView viewWillStartLiveResize]`.
     * @details A view receives viewWillStartLiveResize before the frame is first changed for a live resize. It is important to call [super viewWillStartLiveResize] to allow AppKit to do any internal work it needs.
     */
        void view_will_start_live_resize() const;
        /**
     * @brief Calls `-[NSView viewWithTag:]`.
     * @param tag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        View view_with_tag(std::int64_t tag) const;
        /**
     * @brief Calls `-[NSView willOpenMenu:withEvent:]`.
     * @details A contextual menu is being opened from the receiving view. The view should update any visual state in response — such as making a selection. \\param menu The contextual menu that is being opened on the view \\param event The event that caused the menu to open.
     * @param menu Argument converted to the Objective-C parameter of the same role.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void will_open_menu(const Menu& menu, const Event& event) const;
        /**
     * @brief Calls `-[NSView willRemoveSubview:]`.
     * @param subview Argument converted to the Objective-C parameter of the same role.
     */
        void will_remove_subview(const View& subview) const;
        /**
     * @brief Calls `-[NSView writeEPSInsideRect:toPasteboard:]`.
     * @details EPS/PDF generation
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param pasteboard Argument converted to the Objective-C parameter of the same role.
     */
        void write_eps_inside_rect(const Rect& rect, const Pasteboard& pasteboard) const;
        /**
     * @brief Calls `-[NSView writePDFInsideRect:toPasteboard:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param pasteboard Argument converted to the Objective-C parameter of the same role.
     */
        void write_pdf_inside_rect(const Rect& rect, const Pasteboard& pasteboard) const;
        /**
     * @brief Returns the `additionalSafeAreaInsets` property of `NSView`.
     * @details Configurable insets added to insets inherited from the superview (if any), and contributing to self.safeAreaInsets.
     * @return The converted Objective-C result.
     */
        Insets additional_safe_area_insets() const;
        /**
     * @brief Sets the `additionalSafeAreaInsets` property of `NSView`.
     * @details Configurable insets added to insets inherited from the superview (if any), and contributing to self.safeAreaInsets.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_additional_safe_area_insets(const Insets& value) const;
        /**
     * @brief Returns the `alignmentRectInsets` property of `NSView`.
     * @return The converted Objective-C result.
     */
        Insets alignment_rect_insets() const;
        /**
     * @brief Returns the `allowedTouchTypes` property of `NSView`.
     * @details Defaults to NSTouchTypeDirect if linked on or after 10_12, 0 otherwise
     * @return The converted Objective-C result.
     */
        TouchTypeMask allowed_touch_types() const;
        /**
     * @brief Sets the `allowedTouchTypes` property of `NSView`.
     * @details Defaults to NSTouchTypeDirect if linked on or after 10_12, 0 otherwise
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allowed_touch_types(TouchTypeMask value) const;
        /**
     * @brief Returns the `allowsVibrancy` property of `NSView`.
     * @details allowsVibrancy is queried when a vibrant appearance is used on a view hierarchy. When allowsVibrancy returns YES, the view will have an appropriate measure taken to ensure it is vibrant on top of its given material. Specific subclasses, such as NSControl, will answer this question based on the artwork they draw for a given appearance.
     * @return The converted Objective-C result.
     */
        bool allows_vibrancy() const;
        /**
     * @brief Returns the `alphaValue` property of `NSView`.
     * @return The converted Objective-C result.
     */
        double alpha_value() const;
        /**
     * @brief Sets the `alphaValue` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alpha_value(double value) const;
        /**
     * @brief Returns the `autoresizesSubviews` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool autoresizes_subviews() const;
        /**
     * @brief Sets the `autoresizesSubviews` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_autoresizes_subviews(bool value) const;
        /**
     * @brief Returns the `autoresizingMask` property of `NSView`.
     * @return The converted Objective-C result.
     */
        AutoresizingMaskOptions autoresizing_mask() const;
        /**
     * @brief Sets the `autoresizingMask` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_autoresizing_mask(AutoresizingMaskOptions value) const;
        /**
     * @brief Returns the `backgroundFilters` property of `NSView`.
     * @return The converted Objective-C result.
     */
        std::vector<Object> background_filters() const;
        /**
     * @brief Sets the `backgroundFilters` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_filters(const std::vector<Object>& value) const;
        /**
     * @brief Returns the `baselineOffsetFromBottom` property of `NSView`.
     * @return The converted Objective-C result.
     */
        double baseline_offset_from_bottom() const;
        /**
     * @brief Returns the `bottomAnchor` property of `NSView`.
     * @return The converted Objective-C result.
     */
        LayoutYAxisAnchor bottom_anchor() const;
        /**
     * @brief Returns the `bounds` property of `NSView`.
     * @return The converted Objective-C result.
     */
        Rect bounds() const;
        /**
     * @brief Sets the `bounds` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bounds(const Rect& value) const;
        /**
     * @brief Returns the `boundsRotation` property of `NSView`.
     * @return The converted Objective-C result.
     */
        double bounds_rotation() const;
        /**
     * @brief Sets the `boundsRotation` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bounds_rotation(double value) const;
        /**
     * @brief Returns the `canBecomeKeyView` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool can_become_key_view() const;
        /**
     * @brief Returns the `canDrawConcurrently` property of `NSView`.
     * @details Reports whether AppKit may invoke the view's -drawRect: method on a background thread, where it would otherwise be invoked on the main thread. Defaults to NO.
     * @return The converted Objective-C result.
     */
        bool can_draw_concurrently() const;
        /**
     * @brief Sets the `canDrawConcurrently` property of `NSView`.
     * @details Reports whether AppKit may invoke the view's -drawRect: method on a background thread, where it would otherwise be invoked on the main thread. Defaults to NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_can_draw_concurrently(bool value) const;
        /**
     * @brief Returns the `canDrawSubviewsIntoLayer` property of `NSView`.
     * @details When canDrawSubviewsIntoLayer is set to YES, and the view is layer-backed (either explicitly with -wantsLayer=YES, or by having a parent view that is layer-backed), the layer will draw all subviews into this view's layer, and each subview will not get an individual layer (the exception to this is a subview which has wantsLayer explicitly set to YES). This is useful for layer-backing a complex set of views that can not be refactored to take advantage of proper resizing and -wantsUpdateLayer==YES. If canDrawSubviewsIntoLayer is YES, the value returned from wantsUpdateLayer will be ignored, and the layer will always have drawRect: invoked to get the layer's contents. The default value is NO. NOTE: These methods should NOT be overridden, and the setter should always be used.
     * @return The converted Objective-C result.
     */
        bool can_draw_subviews_into_layer() const;
        /**
     * @brief Sets the `canDrawSubviewsIntoLayer` property of `NSView`.
     * @details When canDrawSubviewsIntoLayer is set to YES, and the view is layer-backed (either explicitly with -wantsLayer=YES, or by having a parent view that is layer-backed), the layer will draw all subviews into this view's layer, and each subview will not get an individual layer (the exception to this is a subview which has wantsLayer explicitly set to YES). This is useful for layer-backing a complex set of views that can not be refactored to take advantage of proper resizing and -wantsUpdateLayer==YES. If canDrawSubviewsIntoLayer is YES, the value returned from wantsUpdateLayer will be ignored, and the layer will always have drawRect: invoked to get the layer's contents. The default value is NO. NOTE: These methods should NOT be overridden, and the setter should always be used.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_can_draw_subviews_into_layer(bool value) const;
        /**
     * @brief Returns the `candidateListTouchBarItem` property of `NSView`.
     * @return The converted Objective-C result.
     */
        CandidateListTouchBarItemBase candidate_list_touch_bar_item() const;
        /**
     * @brief Returns the `centerXAnchor` property of `NSView`.
     * @return The converted Objective-C result.
     */
        LayoutXAxisAnchor center_x_anchor() const;
        /**
     * @brief Returns the `centerYAnchor` property of `NSView`.
     * @return The converted Objective-C result.
     */
        LayoutYAxisAnchor center_y_anchor() const;
        /**
     * @brief Returns the `clipsToBounds` property of `NSView`.
     * @details Defaults to NO on macOS 14 and later. Defaults to YES on previous releases. Note some classes (like NSClipView) set their own default values differently than NSView itself.
     * @return The converted Objective-C result.
     */
        bool clips_to_bounds() const;
        /**
     * @brief Sets the `clipsToBounds` property of `NSView`.
     * @details Defaults to NO on macOS 14 and later. Defaults to YES on previous releases. Note some classes (like NSClipView) set their own default values differently than NSView itself.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_clips_to_bounds(bool value) const;
        /**
     * @brief Returns the `compatibleWithResponsiveScrolling` property of `NSView`.
     * @details A subclass of any NSScrollView, NSClipView or the NSScrollView's documentView can override this method to verify that its customizations are compatible with 10.9's responsive scrolling behavior. By default, AppKit assumes that a ScrollView is responsive scrolling compatible if it and its clipview and document view do not override certain methods such as -scrollWheel: (See documentation for the expanded list). However, these views may still opt into responsive scrolling if they work with the new scrolling behavior by overriding and returning YES for this method. Likewise, the same set of views may return NO to explicitly opt out of responsive scrolling.
     * @return The converted Objective-C result.
     */
        static bool is_compatible_with_responsive_scrolling();
        /**
     * @brief Returns the `compositingFilter` property of `NSView`.
     * @return The converted Objective-C result.
     */
        Object compositing_filter() const;
        /**
     * @brief Sets the `compositingFilter` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_compositing_filter(const Object& value) const;
        /**
     * @brief Returns the `constraints` property of `NSView`.
     * @return The converted Objective-C result.
     */
        std::vector<LayoutConstraint> constraints() const;
        /**
     * @brief Returns the `contentFilters` property of `NSView`.
     * @return The converted Objective-C result.
     */
        std::vector<Object> content_filters() const;
        /**
     * @brief Sets the `contentFilters` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_filters(const std::vector<Object>& value) const;
        /**
     * @brief Returns the `defaultFocusRingType` property of `NSView`.
     * @return The converted Objective-C result.
     */
        static FocusRingType default_focus_ring_type();
        /**
     * @brief Returns the `defaultMenu` property of `NSView`.
     * @return The converted Objective-C result.
     */
        static Menu default_menu();
        /**
     * @brief Returns the `drawingFindIndicator` property of `NSView`.
     * @details When this method returns YES, the receiver or one of its ancestors is being drawn for a find indicator, meaning the receiver should draw so its contents will be easily readable.
     * @return The converted Objective-C result.
     */
        bool is_drawing_find_indicator() const;
        /**
     * @brief Returns the `enclosingMenuItem` property of `NSView`.
     * @return The converted Objective-C result.
     */
        MenuItem enclosing_menu_item() const;
        /**
     * @brief Returns the `enclosingScrollView` property of `NSView`.
     * @details The nearest ancestor scroll view that contains the current view as part of its document view. - Note: If the current view is not embedded inside a scroll view, the value of this property is 'nil'. This property does not contain the current view if the current view is itself a scroll view. It always contains an ancestor scroll view.
     * @return The converted Objective-C result.
     */
        ScrollView enclosing_scroll_view() const;
        /**
     * @brief Returns the `firstBaselineAnchor` property of `NSView`.
     * @return The converted Objective-C result.
     */
        LayoutYAxisAnchor first_baseline_anchor() const;
        /**
     * @brief Returns the `firstBaselineOffsetFromTop` property of `NSView`.
     * @return The converted Objective-C result.
     */
        double first_baseline_offset_from_top() const;
        /**
     * @brief Returns the `fittingSize` property of `NSView`.
     * @return The converted Objective-C result.
     */
        Size fitting_size() const;
        /**
     * @brief Returns the `flipped` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool is_flipped() const;
        /**
     * @brief Returns the `focusRingMaskBounds` property of `NSView`.
     * @return The converted Objective-C result.
     */
        Rect focus_ring_mask_bounds() const;
        /**
     * @brief Returns the `focusRingType` property of `NSView`.
     * @return The converted Objective-C result.
     */
        FocusRingType focus_ring_type() const;
        /**
     * @brief Sets the `focusRingType` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_focus_ring_type(FocusRingType value) const;
        /**
     * @brief Returns the `focusView` property of `NSView`.
     * @return The converted Objective-C result.
     */
        static View focus_view();
        /**
     * @brief Returns the `frame` property of `NSView`.
     * @return The converted Objective-C result.
     */
        Rect frame() const;
        /**
     * @brief Sets the `frame` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_frame(const Rect& value) const;
        /**
     * @brief Returns the `frameCenterRotation` property of `NSView`.
     * @return The converted Objective-C result.
     */
        double frame_center_rotation() const;
        /**
     * @brief Sets the `frameCenterRotation` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_frame_center_rotation(double value) const;
        /**
     * @brief Returns the `frameRotation` property of `NSView`.
     * @return The converted Objective-C result.
     */
        double frame_rotation() const;
        /**
     * @brief Sets the `frameRotation` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_frame_rotation(double value) const;
        /**
     * @brief Returns the `gestureRecognizers` property of `NSView`.
     * @return The converted Objective-C result.
     */
        std::vector<GestureRecognizer> gesture_recognizers() const;
        /**
     * @brief Sets the `gestureRecognizers` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_gesture_recognizers(const std::vector<GestureRecognizer>& value) const;
        /**
     * @brief Returns the `hasAmbiguousLayout` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool has_ambiguous_layout() const;
        /**
     * @brief Returns the `heightAdjustLimit` property of `NSView`.
     * @return The converted Objective-C result.
     */
        double height_adjust_limit() const;
        /**
     * @brief Returns the `heightAnchor` property of `NSView`.
     * @return The converted Objective-C result.
     */
        LayoutDimension height_anchor() const;
        /**
     * @brief Returns the `hidden` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool is_hidden() const;
        /**
     * @brief Sets the `hidden` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hidden(bool value) const;
        /**
     * @brief Returns the `hiddenOrHasHiddenAncestor` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool is_hidden_or_has_hidden_ancestor() const;
        /**
     * @brief Returns the `horizontalContentSizeConstraintActive` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool is_horizontal_content_size_constraint_active() const;
        /**
     * @brief Sets the `horizontalContentSizeConstraintActive` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_horizontal_content_size_constraint_active(bool value) const;
        /**
     * @brief Returns the `inFullScreenMode` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool is_in_full_screen_mode() const;
        /**
     * @brief Returns the `inLiveResize` property of `NSView`.
     * @details inLiveResize can be called at any time to determine if the window is performing a live resize or not. Drawing optimizations can be done when the view is being live-resized.
     * @return The converted Objective-C result.
     */
        bool in_live_resize() const;
        /**
     * @brief Returns the `inputContext` property of `NSView`.
     * @details Returns NSTextInputContext object for the receiver. Returns nil if the receiver doesn't conform to NSTextInputClient protocol.
     * @return The converted Objective-C result.
     */
        TextInputContext input_context() const;
        /**
     * @brief Returns the `intrinsicContentSize` property of `NSView`.
     * @return The converted Objective-C result.
     */
        Size intrinsic_content_size() const;
        /**
     * @brief Returns the `lastBaselineAnchor` property of `NSView`.
     * @return The converted Objective-C result.
     */
        LayoutYAxisAnchor last_baseline_anchor() const;
        /**
     * @brief Returns the `lastBaselineOffsetFromBottom` property of `NSView`.
     * @return The converted Objective-C result.
     */
        double last_baseline_offset_from_bottom() const;
        /**
     * @brief Returns the `layer` property of `NSView`.
     * @details Get and set the CALayer for this view. The layer is not encoded by the view.
     * @return The converted Objective-C result.
     */
        CALayer layer() const;
        /**
     * @brief Sets the `layer` property of `NSView`.
     * @details Get and set the CALayer for this view. The layer is not encoded by the view.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_layer(const CALayer& value) const;
        /**
     * @brief Returns the `layerContentsPlacement` property of `NSView`.
     * @return The converted Objective-C result.
     */
        ViewLayerContentsPlacement layer_contents_placement() const;
        /**
     * @brief Sets the `layerContentsPlacement` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_layer_contents_placement(ViewLayerContentsPlacement value) const;
        /**
     * @brief Returns the `layerContentsRedrawPolicy` property of `NSView`.
     * @details Get and set how the layer should redraw when resizing and redisplaying. Prior to 10.8, the default value was always set to NSViewLayerContentsRedrawDuringViewResize when an AppKit managed layer was created. In 10.8 and higher, the value is initialized to the appropriate thing for each individual AppKit view. Generally, the default value is NSViewLayerContentsRedrawOnSetNeedsDisplay if the view responds YES to -wantsUpdateLayer. Otherwise, the value is usually NSViewLayerContentsRedrawDuringViewResize, indicating that the view needs to redraw on each step of an animation via a setFrame: change. On 10.8, the value is not encoded by the view.
     * @return The converted Objective-C result.
     */
        ViewLayerContentsRedrawPolicy layer_contents_redraw_policy() const;
        /**
     * @brief Sets the `layerContentsRedrawPolicy` property of `NSView`.
     * @details Get and set how the layer should redraw when resizing and redisplaying. Prior to 10.8, the default value was always set to NSViewLayerContentsRedrawDuringViewResize when an AppKit managed layer was created. In 10.8 and higher, the value is initialized to the appropriate thing for each individual AppKit view. Generally, the default value is NSViewLayerContentsRedrawOnSetNeedsDisplay if the view responds YES to -wantsUpdateLayer. Otherwise, the value is usually NSViewLayerContentsRedrawDuringViewResize, indicating that the view needs to redraw on each step of an animation via a setFrame: change. On 10.8, the value is not encoded by the view.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_layer_contents_redraw_policy(ViewLayerContentsRedrawPolicy value) const;
        /**
     * @brief Returns the `layerUsesCoreImageFilters` property of `NSView`.
     * @details If you have set a custom layer on your view, and it (or one of its sublayers) uses CIFilters, you should set this. You do not need to set this if you are using the backgroundFilters, compositingFilter, or contentFilters properties below. See the release notes for more information.
     * @return The converted Objective-C result.
     */
        bool layer_uses_core_image_filters() const;
        /**
     * @brief Sets the `layerUsesCoreImageFilters` property of `NSView`.
     * @details If you have set a custom layer on your view, and it (or one of its sublayers) uses CIFilters, you should set this. You do not need to set this if you are using the backgroundFilters, compositingFilter, or contentFilters properties below. See the release notes for more information.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_layer_uses_core_image_filters(bool value) const;
        /**
     * @brief Returns the `layoutGuides` property of `NSView`.
     * @return The converted Objective-C result.
     */
        std::vector<LayoutGuide> layout_guides() const;
        /**
     * @brief Returns the `layoutMarginsGuide` property of `NSView`.
     * @details This layout guide provides the recommended amount of padding for content inside a view.
     * @return The converted Objective-C result.
     */
        LayoutGuide layout_margins_guide() const;
        /**
     * @brief Returns the `leadingAnchor` property of `NSView`.
     * @return The converted Objective-C result.
     */
        LayoutXAxisAnchor leading_anchor() const;
        /**
     * @brief Returns the `leftAnchor` property of `NSView`.
     * @return The converted Objective-C result.
     */
        LayoutXAxisAnchor left_anchor() const;
        /**
     * @brief Returns the `mouseDownCanMoveWindow` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool mouse_down_can_move_window() const;
        /**
     * @brief Returns the `needsDisplay` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool needs_display() const;
        /**
     * @brief Sets the `needsDisplay` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_needs_display(bool value) const;
        /**
     * @brief Returns the `needsLayout` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool needs_layout() const;
        /**
     * @brief Sets the `needsLayout` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_needs_layout(bool value) const;
        /**
     * @brief Returns the `needsPanelToBecomeKey` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool needs_panel_to_become_key() const;
        /**
     * @brief Returns the `needsUpdateConstraints` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool needs_update_constraints() const;
        /**
     * @brief Sets the `needsUpdateConstraints` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_needs_update_constraints(bool value) const;
        /**
     * @brief Returns the `nextKeyView` property of `NSView`.
     * @return The converted Objective-C result.
     */
        View next_key_view() const;
        /**
     * @brief Sets the `nextKeyView` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_next_key_view(const View& value) const;
        /**
     * @brief Returns the `nextValidKeyView` property of `NSView`.
     * @return The converted Objective-C result.
     */
        View next_valid_key_view() const;
        /**
     * @brief Returns the `opaque` property of `NSView`.
     * @details A hint as to whether or not this view draws its contents completely opaque or not. Opaque content drawing can allow some optimizations to happen. The default value is NO.
     * @return The converted Objective-C result.
     */
        bool is_opaque() const;
        /**
     * @brief Returns the `opaqueAncestor` property of `NSView`.
     * @return The converted Objective-C result.
     */
        View opaque_ancestor() const;
        /**
     * @brief Returns the `pageFooter` property of `NSView`.
     * @return The converted Objective-C result.
     */
        AttributedString page_footer() const;
        /**
     * @brief Returns the `pageHeader` property of `NSView`.
     * @return The converted Objective-C result.
     */
        AttributedString page_header() const;
        /**
     * @brief Returns the `postsBoundsChangedNotifications` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool posts_bounds_changed_notifications() const;
        /**
     * @brief Sets the `postsBoundsChangedNotifications` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_posts_bounds_changed_notifications(bool value) const;
        /**
     * @brief Returns the `postsFrameChangedNotifications` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool posts_frame_changed_notifications() const;
        /**
     * @brief Sets the `postsFrameChangedNotifications` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_posts_frame_changed_notifications(bool value) const;
        /**
     * @brief Returns the `prefersCompactControlSizeMetrics` property of `NSView`.
     * @details When this property is true, any NSControls in the view or its descendants will be sized with compact metrics compatible with macOS 15 and earlier. Defaults to false
     * @return The converted Objective-C result.
     */
        bool prefers_compact_control_size_metrics() const;
        /**
     * @brief Sets the `prefersCompactControlSizeMetrics` property of `NSView`.
     * @details When this property is true, any NSControls in the view or its descendants will be sized with compact metrics compatible with macOS 15 and earlier. Defaults to false
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_prefers_compact_control_size_metrics(bool value) const;
        /**
     * @brief Returns the `preparedContentRect` property of `NSView`.
     * @details The preparedContentRect is the area of the NSView that has full content coverage. In general, this should be called with the area that is filled in fully with views. Set this with a value equal to the visibleRect to have overdraw start from the visibleRect and automatically grow larger on idle, as is needed for optimal system performance. The result of preparedContentRect may include the visibleRect, and may not include it if the previously prepared area has been scrolled away.
     * @return The converted Objective-C result.
     */
        Rect prepared_content_rect() const;
        /**
     * @brief Sets the `preparedContentRect` property of `NSView`.
     * @details The preparedContentRect is the area of the NSView that has full content coverage. In general, this should be called with the area that is filled in fully with views. Set this with a value equal to the visibleRect to have overdraw start from the visibleRect and automatically grow larger on idle, as is needed for optimal system performance. The result of preparedContentRect may include the visibleRect, and may not include it if the previously prepared area has been scrolled away.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_prepared_content_rect(const Rect& value) const;
        /**
     * @brief Returns the `preservesContentDuringLiveResize` property of `NSView`.
     * @details A view that returns YES for -preservesContentDuringLiveResize is responsible for invalidating its own dirty rects during live resize
     * @return The converted Objective-C result.
     */
        bool preserves_content_during_live_resize() const;
        /**
     * @brief Returns the `pressureConfiguration` property of `NSView`.
     * @return The converted Objective-C result.
     */
        PressureConfiguration pressure_configuration() const;
        /**
     * @brief Sets the `pressureConfiguration` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_pressure_configuration(const PressureConfiguration& value) const;
        /**
     * @brief Returns the `previousKeyView` property of `NSView`.
     * @return The converted Objective-C result.
     */
        View previous_key_view() const;
        /**
     * @brief Returns the `previousValidKeyView` property of `NSView`.
     * @return The converted Objective-C result.
     */
        View previous_valid_key_view() const;
        /**
     * @brief Returns the `printJobTitle` property of `NSView`.
     * @details Returns print job title. Default implementation first tries its window's NSDocument (displayName), then window's title
     * @return The converted Objective-C result.
     */
        std::string print_job_title() const;
        /**
     * @brief Returns the `rectPreservedDuringLiveResize` property of `NSView`.
     * @details -rectPreservedDuringLiveResize indicates the rect the view previously occupied, in the current coordinate system of the view
     * @return The converted Objective-C result.
     */
        Rect rect_preserved_during_live_resize() const;
        /**
     * @brief Returns the `registeredDraggedTypes` property of `NSView`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> registered_dragged_types() const;
        /**
     * @brief Returns the `requiresConstraintBasedLayout` property of `NSView`.
     * @return The converted Objective-C result.
     */
        static bool requires_constraint_based_layout();
        /**
     * @brief Returns the `rightAnchor` property of `NSView`.
     * @return The converted Objective-C result.
     */
        LayoutXAxisAnchor right_anchor() const;
        /**
     * @brief Returns the `rotatedFromBase` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool is_rotated_from_base() const;
        /**
     * @brief Returns the `rotatedOrScaledFromBase` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool is_rotated_or_scaled_from_base() const;
        /**
     * @brief Returns the `safeAreaInsets` property of `NSView`.
     * @details Indicates the potentially-obscured distance from each edge of the view (e.g, not behind the window title bar, etc., if present).
     * @return The converted Objective-C result.
     */
        Insets safe_area_insets() const;
        /**
     * @brief Returns the `safeAreaLayoutGuide` property of `NSView`.
     * @details This layout guide reflects the safe area for this view (i.e., the frame minus safeAreaInsets), and provides a convenient way to arrange content relative to the safe area using auto layout.
     * @return The converted Objective-C result.
     */
        LayoutGuide safe_area_layout_guide() const;
        /**
     * @brief Returns the `safeAreaRect` property of `NSView`.
     * @details The safe area for this view expressed as a rectangle in the view's coordinate space.
     * @return The converted Objective-C result.
     */
        Rect safe_area_rect() const;
        /**
     * @brief Returns the `shadow` property of `NSView`.
     * @return The converted Objective-C result.
     */
        Shadow shadow() const;
        /**
     * @brief Sets the `shadow` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shadow(const Shadow& value) const;
        /**
     * @brief Returns the `subviews` property of `NSView`.
     * @return The converted Objective-C result.
     */
        std::vector<View> subviews() const;
        /**
     * @brief Sets the `subviews` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_subviews(const std::vector<View>& value) const;
        /**
     * @brief Returns the `superview` property of `NSView`.
     * @return The converted Objective-C result.
     */
        View superview() const;
        /**
     * @brief Returns the `tag` property of `NSView`.
     * @return The converted Objective-C result.
     */
        std::int64_t tag() const;
        /**
     * @brief Returns the `toolTip` property of `NSView`.
     * @return The converted Objective-C result.
     */
        std::string tool_tip() const;
        /**
     * @brief Sets the `toolTip` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tool_tip(const std::string& value) const;
        /**
     * @brief Returns the `topAnchor` property of `NSView`.
     * @return The converted Objective-C result.
     */
        LayoutYAxisAnchor top_anchor() const;
        /**
     * @brief Returns the `trackingAreas` property of `NSView`.
     * @return The converted Objective-C result.
     */
        std::vector<TrackingArea> tracking_areas() const;
        /**
     * @brief Returns the `trailingAnchor` property of `NSView`.
     * @return The converted Objective-C result.
     */
        LayoutXAxisAnchor trailing_anchor() const;
        /**
     * @brief Returns the `translatesAutoresizingMaskIntoConstraints` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool translates_autoresizing_mask_into_constraints() const;
        /**
     * @brief Sets the `translatesAutoresizingMaskIntoConstraints` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_translates_autoresizing_mask_into_constraints(bool value) const;
        /**
     * @brief Returns the `userInterfaceLayoutDirection` property of `NSView`.
     * @details Get and set the user interface layout direction. By default, a basic NSView may not respect the User Interface Layout Direction that is uniquely set on it, and it is up to the developer and supporting subclasses to correctly implement a Right To Left layout implementation. The default value is set to [NSApp userInterfaceLayoutDirection].
     * @return The converted Objective-C result.
     */
        UserInterfaceLayoutDirection user_interface_layout_direction() const;
        /**
     * @brief Sets the `userInterfaceLayoutDirection` property of `NSView`.
     * @details Get and set the user interface layout direction. By default, a basic NSView may not respect the User Interface Layout Direction that is uniquely set on it, and it is up to the developer and supporting subclasses to correctly implement a Right To Left layout implementation. The default value is set to [NSApp userInterfaceLayoutDirection].
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_user_interface_layout_direction(UserInterfaceLayoutDirection value) const;
        /**
     * @brief Returns the `verticalContentSizeConstraintActive` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool is_vertical_content_size_constraint_active() const;
        /**
     * @brief Sets the `verticalContentSizeConstraintActive` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_vertical_content_size_constraint_active(bool value) const;
        /**
     * @brief Returns the `visibleRect` property of `NSView`.
     * @details The portion of the view that isn’t clipped by its superviews. \@discussion Visibility, as reflected by this property, doesn’t account for whether other view or window objects overlap the current view or whether the current view is installed in a window at all. This value of this property is 'NSZeroRect' if the current view is effectively hidden. \@discussion During a printing operation, the visible rectangle is further clipped to the page being imaged.
     * @return The converted Objective-C result.
     */
        Rect visible_rect() const;
        /**
     * @brief Returns the `wantsDefaultClipping` property of `NSView`.
     * @return The converted Objective-C result.
     */
        bool wants_default_clipping() const;
        /**
     * @brief Returns the `wantsLayer` property of `NSView`.
     * @details Indicates if this view should be a "Layer Backed View". When layer backed, all subviews will subsequently also have a layer set on them (however, wantsLayer will only be YES on views that have had it explicitly set). Contents for a layer are specified in one of two ways: if -wantsUpdateLayer returns YES, then one can directly update the layer's contents (or other properties) in -updateLayer. If -wantsUpdateLayer returns NO, then the layer's contents is filled with whatever is drawn by -drawRect:
     * @return The converted Objective-C result.
     */
        bool wants_layer() const;
        /**
     * @brief Sets the `wantsLayer` property of `NSView`.
     * @details Indicates if this view should be a "Layer Backed View". When layer backed, all subviews will subsequently also have a layer set on them (however, wantsLayer will only be YES on views that have had it explicitly set). Contents for a layer are specified in one of two ways: if -wantsUpdateLayer returns YES, then one can directly update the layer's contents (or other properties) in -updateLayer. If -wantsUpdateLayer returns NO, then the layer's contents is filled with whatever is drawn by -drawRect:
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_wants_layer(bool value) const;
        /**
     * @brief Returns the `wantsRestingTouches` property of `NSView`.
     * @details In some cases, the user may rest a thumb or other touch on the device. By default, these touches are not delivered and are not included in the event's set of touches. Touches may transition in and out of resting at any time. Unless the view wants restingTouches, began / ended events are simlulated as touches transition from resting to active and vice versa.
     * @return The converted Objective-C result.
     */
        bool wants_resting_touches() const;
        /**
     * @brief Sets the `wantsRestingTouches` property of `NSView`.
     * @details In some cases, the user may rest a thumb or other touch on the device. By default, these touches are not delivered and are not included in the event's set of touches. Touches may transition in and out of resting at any time. Unless the view wants restingTouches, began / ended events are simlulated as touches transition from resting to active and vice versa.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_wants_resting_touches(bool value) const;
        /**
     * @brief Returns the `wantsUpdateLayer` property of `NSView`.
     * @details Layer Backed Views: Return YES if this view supports directly setting the layer properties (such as the contents and backgroundColor) as opposed to filling in the contents with a drawRect: implementation. Most AppKit controls return YES if there is no subclassing involved that would alter the drawing appearance. It will return NO for views that do have subclassing that AppKit does not know about (such as, overriding drawRect:, or other drawing methods).
     * @return The converted Objective-C result.
     */
        bool wants_update_layer() const;
        /**
     * @brief Returns the `widthAdjustLimit` property of `NSView`.
     * @return The converted Objective-C result.
     */
        double width_adjust_limit() const;
        /**
     * @brief Returns the `widthAnchor` property of `NSView`.
     * @return The converted Objective-C result.
     */
        LayoutDimension width_anchor() const;
        /**
     * @brief Returns the `window` property of `NSView`.
     * @return The converted Objective-C result.
     */
        Window window() const;
        /**
     * @brief Returns the `writingToolsCoordinator` property of `NSView`.
     * @return The converted Objective-C result.
     */
        WritingToolsCoordinator writing_tools_coordinator() const;
        /**
     * @brief Sets the `writingToolsCoordinator` property of `NSView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_writing_tools_coordinator(const WritingToolsCoordinator& value) const;
        /// @brief Convenience helper `add_subview` provided by cocoon.
        void add_subview(const View& child) const;
        /// @brief Convenience helper `pin_to_superview` provided by cocoon.
        void pin_to_superview(const Insets& insets = {}) const;
        /// @brief Convenience helper `pin_to_safe_area` provided by cocoon.
        void pin_to_safe_area(const Insets& insets = {}) const;
        /// @brief Convenience helper `center_in_superview` provided by cocoon.
        void center_in_superview() const;
        /// @brief Convenience helper `set_fixed_width` provided by cocoon.
        void set_fixed_width(double width) const;
        /// @brief Convenience helper `set_fixed_height` provided by cocoon.
        void set_fixed_height(double height) const;
        /// @brief Convenience helper `set_fixed_size` provided by cocoon.
        void set_fixed_size(double width, double height) const;
        /// @brief Convenience helper `set_minimum_size` provided by cocoon.
        void set_minimum_size(double width, double height) const;
        /// @brief Convenience helper `set_maximum_size` provided by cocoon.
        void set_maximum_size(double width, double height) const;
        /// @brief Convenience helper `set_background_color` provided by cocoon.
        void set_background_color(const Color& color) const;
        /// @brief Convenience helper `set_layer_corner_radius` provided by cocoon.
        void set_layer_corner_radius(double radius) const;
    };
}
