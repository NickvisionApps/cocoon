#include "generated/view.h"
#include "internal.h"

namespace cocoon
{
    View::View() : View(Adopt{cocoon::internal::retain([[NSView alloc] init])})
    {
    }

    View::View(const Rect& frame_rect) : View(Adopt{cocoon::internal::retain([[::NSView alloc] initWithFrame:cocoon::internal::to(frame_rect)])})
    {
    }

    View::View(std::nullptr_t) : Responder(nullptr)
    {
    }

    View::View(Adopt adopt) : Responder(adopt)
    {
    }

    bool View::accepts_first_mouse(const Event& event) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) acceptsFirstMouse:cocoon::internal::native<::NSEvent>(event)]);
    }

    void View::add_constraint(const LayoutConstraint& constraint) const
    {
        [cocoon::internal::ns<::NSView>(this) addConstraint:cocoon::internal::native<::NSLayoutConstraint>(constraint)];
    }

    void View::add_constraints(const std::vector<LayoutConstraint>& constraints) const
    {
        [cocoon::internal::ns<::NSView>(this) addConstraints:cocoon::internal::to_array(constraints, [](const LayoutConstraint& e) -> id
                                                            {
                                                                return cocoon::internal::native<::NSLayoutConstraint>(e);
                                                            })];
    }

    void View::add_cursor_rect(const Rect& rect, const Cursor& object) const
    {
        [cocoon::internal::ns<::NSView>(this) addCursorRect:cocoon::internal::to(rect) cursor:cocoon::internal::native<::NSCursor>(object)];
    }

    void View::add_gesture_recognizer(const GestureRecognizer& gesture_recognizer) const
    {
        [cocoon::internal::ns<::NSView>(this) addGestureRecognizer:cocoon::internal::native<::NSGestureRecognizer>(gesture_recognizer)];
    }

    void View::add_layout_guide(const LayoutGuide& guide) const
    {
        [cocoon::internal::ns<::NSView>(this) addLayoutGuide:cocoon::internal::native<::NSLayoutGuide>(guide)];
    }

    void View::add_subview(const View& view, WindowOrderingMode place, const View& other_view) const
    {
        [cocoon::internal::ns<::NSView>(this) addSubview:cocoon::internal::native<::NSView>(view) positioned:static_cast<::NSWindowOrderingMode>(place) relativeTo:cocoon::internal::native<::NSView>(other_view)];
    }

    std::int64_t View::add_tool_tip_rect(const Rect& rect, const Object& owner, void* data) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSView>(this) addToolTipRect:cocoon::internal::to(rect) owner:cocoon::internal::native_id(owner) userData:data]);
    }

    void View::add_tracking_area(const TrackingArea& tracking_area) const
    {
        [cocoon::internal::ns<::NSView>(this) addTrackingArea:cocoon::internal::native<::NSTrackingArea>(tracking_area)];
    }

    std::int64_t View::add_tracking_rect(const Rect& rect, const Object& owner, void* data, bool flag) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSView>(this) addTrackingRect:cocoon::internal::to(rect) owner:cocoon::internal::native_id(owner) userData:data assumeInside:static_cast<::BOOL>(flag)]);
    }

    void View::adjust_page_height_new(double* new_bottom, double old_top, double old_bottom, double bottom_limit) const
    {
        [cocoon::internal::ns<::NSView>(this) adjustPageHeightNew:(::CGFloat*)(new_bottom) top:static_cast<::CGFloat>(old_top) bottom:static_cast<::CGFloat>(old_bottom) limit:static_cast<::CGFloat>(bottom_limit)];
    }

    void View::adjust_page_width_new(double* new_right, double old_left, double old_right, double right_limit) const
    {
        [cocoon::internal::ns<::NSView>(this) adjustPageWidthNew:(::CGFloat*)(new_right) left:static_cast<::CGFloat>(old_left) right:static_cast<::CGFloat>(old_right) limit:static_cast<::CGFloat>(right_limit)];
    }

    Rect View::adjust_scroll(const Rect& new_visible) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) adjustScroll:cocoon::internal::to(new_visible)]);
    }

    Rect View::alignment_rect_for_frame(const Rect& frame) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) alignmentRectForFrame:cocoon::internal::to(frame)]);
    }

    View View::ancestor_shared_with_view(const View& view) const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSView>(this) ancestorSharedWithView:cocoon::internal::native<::NSView>(view)]);
    }

    bool View::autoscroll(const Event& event) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) autoscroll:cocoon::internal::native<::NSEvent>(event)]);
    }

    Rect View::backing_aligned_rect(const Rect& rect, AlignmentOptions options) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) backingAlignedRect:cocoon::internal::to(rect) options:static_cast<::NSAlignmentOptions>(options)]);
    }

    void View::begin_document() const
    {
        [cocoon::internal::ns<::NSView>(this) beginDocument];
    }

    DraggingSession View::begin_dragging_session_with_items(const std::vector<DraggingItem>& items, const Event& event, const Object& source) const
    {
        return cocoon::internal::wrap<DraggingSession>([cocoon::internal::ns<::NSView>(this) beginDraggingSessionWithItems:cocoon::internal::to_array(items, [](const DraggingItem& e) -> id
                                                                                                            {
                                                                                                                return cocoon::internal::native<::NSDraggingItem>(e);
                                                                                                            })
                                                                                         event:cocoon::internal::native<::NSEvent>(event)
                                                                                        source:cocoon::internal::native_id(source)]);
    }

    DraggingSession View::begin_dragging_session_with_items(const std::vector<DraggingItem>& items, const GestureRecognizer& gesture, const Object& source) const
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::wrap<DraggingSession>([cocoon::internal::ns<::NSView>(this) beginDraggingSessionWithItems:cocoon::internal::to_array(items, [](const DraggingItem& e) -> id
                                                                                                                {
                                                                                                                    return cocoon::internal::native<::NSDraggingItem>(e);
                                                                                                                })
                                                                                           gesture:cocoon::internal::native<::NSGestureRecognizer>(gesture)
                                                                                            source:cocoon::internal::native_id(source)]);
        }
        return DraggingSession(nullptr);
    }

    void View::begin_page_in_rect(const Rect& rect, const Point& location) const
    {
        [cocoon::internal::ns<::NSView>(this) beginPageInRect:cocoon::internal::to(rect) atPlacement:cocoon::internal::to(location)];
    }

    BitmapImageRep View::bitmap_image_rep_for_caching_display_in_rect(const Rect& rect) const
    {
        return cocoon::internal::wrap<BitmapImageRep>([cocoon::internal::ns<::NSView>(this) bitmapImageRepForCachingDisplayInRect:cocoon::internal::to(rect)]);
    }

    void View::cache_display_in_rect(const Rect& rect, const BitmapImageRep& bitmap_image_rep) const
    {
        [cocoon::internal::ns<::NSView>(this) cacheDisplayInRect:cocoon::internal::to(rect) toBitmapImageRep:cocoon::internal::native<::NSBitmapImageRep>(bitmap_image_rep)];
    }

    Rect View::center_scan_rect(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) centerScanRect:cocoon::internal::to(rect)]);
    }

    std::vector<LayoutConstraint> View::constraints_affecting_layout_for_orientation(ConstraintOrientation orientation) const
    {
        return cocoon::internal::from_array<LayoutConstraint>([cocoon::internal::ns<::NSView>(this) constraintsAffectingLayoutForOrientation:static_cast<::NSLayoutConstraintOrientation>(orientation)], [](id e) -> LayoutConstraint
                                                {
                                                    return cocoon::internal::wrap<LayoutConstraint>((::NSLayoutConstraint*)e);
                                                });
    }

    float View::content_compression_resistance_priority_for_orientation(ConstraintOrientation orientation) const
    {
        return static_cast<float>([cocoon::internal::ns<::NSView>(this) contentCompressionResistancePriorityForOrientation:static_cast<::NSLayoutConstraintOrientation>(orientation)]);
    }

    float View::content_hugging_priority_for_orientation(ConstraintOrientation orientation) const
    {
        return static_cast<float>([cocoon::internal::ns<::NSView>(this) contentHuggingPriorityForOrientation:static_cast<::NSLayoutConstraintOrientation>(orientation)]);
    }

    Point View::convert_point(const Point& point, const View& view) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) convertPoint:cocoon::internal::to(point) fromView:cocoon::internal::native<::NSView>(view)]);
    }

    Point View::convert_point_from_backing(const Point& point) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) convertPointFromBacking:cocoon::internal::to(point)]);
    }

    Point View::convert_point_from_layer(const Point& point) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) convertPointFromLayer:cocoon::internal::to(point)]);
    }

    Point View::convert_point_to_backing(const Point& point) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) convertPointToBacking:cocoon::internal::to(point)]);
    }

    Point View::convert_point_to_layer(const Point& point) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) convertPointToLayer:cocoon::internal::to(point)]);
    }

    Rect View::convert_rect(const Rect& rect, const View& view) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) convertRect:cocoon::internal::to(rect) fromView:cocoon::internal::native<::NSView>(view)]);
    }

    Rect View::convert_rect_from_backing(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) convertRectFromBacking:cocoon::internal::to(rect)]);
    }

    Rect View::convert_rect_from_layer(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) convertRectFromLayer:cocoon::internal::to(rect)]);
    }

    Rect View::convert_rect_to_backing(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) convertRectToBacking:cocoon::internal::to(rect)]);
    }

    Rect View::convert_rect_to_layer(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) convertRectToLayer:cocoon::internal::to(rect)]);
    }

    Size View::convert_size(const Size& size, const View& view) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) convertSize:cocoon::internal::to(size) fromView:cocoon::internal::native<::NSView>(view)]);
    }

    Size View::convert_size_from_backing(const Size& size) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) convertSizeFromBacking:cocoon::internal::to(size)]);
    }

    Size View::convert_size_from_layer(const Size& size) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) convertSizeFromLayer:cocoon::internal::to(size)]);
    }

    Size View::convert_size_to_backing(const Size& size) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) convertSizeToBacking:cocoon::internal::to(size)]);
    }

    Size View::convert_size_to_layer(const Size& size) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) convertSizeToLayer:cocoon::internal::to(size)]);
    }

    std::vector<std::uint8_t> View::data_with_eps_inside_rect(const Rect& rect) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSView>(this) dataWithEPSInsideRect:cocoon::internal::to(rect)]);
    }

    std::vector<std::uint8_t> View::data_with_pdf_inside_rect(const Rect& rect) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSView>(this) dataWithPDFInsideRect:cocoon::internal::to(rect)]);
    }

    void View::did_add_subview(const View& subview) const
    {
        [cocoon::internal::ns<::NSView>(this) didAddSubview:cocoon::internal::native<::NSView>(subview)];
    }

    void View::did_close_menu(const Menu& menu, const Event& event) const
    {
        [cocoon::internal::ns<::NSView>(this) didCloseMenu:cocoon::internal::native<::NSMenu>(menu) withEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void View::discard_cursor_rects() const
    {
        [cocoon::internal::ns<::NSView>(this) discardCursorRects];
    }

    void View::display() const
    {
        [cocoon::internal::ns<::NSView>(this) display];
    }

    void View::display_if_needed() const
    {
        [cocoon::internal::ns<::NSView>(this) displayIfNeeded];
    }

    void View::display_if_needed_ignoring_opacity() const
    {
        [cocoon::internal::ns<::NSView>(this) displayIfNeededIgnoringOpacity];
    }

    void View::display_if_needed_in_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSView>(this) displayIfNeededInRect:cocoon::internal::to(rect)];
    }

    void View::display_if_needed_in_rect_ignoring_opacity(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSView>(this) displayIfNeededInRectIgnoringOpacity:cocoon::internal::to(rect)];
    }

    Object View::display_link_with_target(const Object& target, const std::string& selector) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSView>(this) displayLinkWithTarget:cocoon::internal::native_id(target) selector:NSSelectorFromString(cocoon::internal::to(selector))]);
    }

    void View::display_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSView>(this) displayRect:cocoon::internal::to(rect)];
    }

    void View::display_rect_ignoring_opacity(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSView>(this) displayRectIgnoringOpacity:cocoon::internal::to(rect)];
    }

    void View::display_rect_ignoring_opacity(const Rect& rect, const GraphicsContext& context) const
    {
        [cocoon::internal::ns<::NSView>(this) displayRectIgnoringOpacity:cocoon::internal::to(rect) inContext:cocoon::internal::native<::NSGraphicsContext>(context)];
    }

    void View::draw_focus_ring_mask() const
    {
        [cocoon::internal::ns<::NSView>(this) drawFocusRingMask];
    }

    void View::draw_page_border_with_size(const Size& border_size) const
    {
        [cocoon::internal::ns<::NSView>(this) drawPageBorderWithSize:cocoon::internal::to(border_size)];
    }

    void View::draw_rect(const Rect& dirty_rect) const
    {
        [cocoon::internal::ns<::NSView>(this) drawRect:cocoon::internal::to(dirty_rect)];
    }

    Insets View::edge_insets_for_layout_region(const ViewLayoutRegion& layout_region) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) edgeInsetsForLayoutRegion:cocoon::internal::native<::NSViewLayoutRegion>(layout_region)]);
    }

    void View::end_document() const
    {
        [cocoon::internal::ns<::NSView>(this) endDocument];
    }

    void View::end_page() const
    {
        [cocoon::internal::ns<::NSView>(this) endPage];
    }

    bool View::enter_full_screen_mode(const Screen& screen, const std::map<std::string, Object>& options) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) enterFullScreenMode:cocoon::internal::native<::NSScreen>(screen)
                                                                 withOptions:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                               {
                                                                                                   return cocoon::internal::to(k);
                                                                                               },
                                                                                               [](const Object& v) -> id
                                                                                               {
                                                                                                   return cocoon::internal::native_id(v);
                                                                                               })]);
    }

    void View::exercise_ambiguity_in_layout() const
    {
        [cocoon::internal::ns<::NSView>(this) exerciseAmbiguityInLayout];
    }

    void View::exit_full_screen_mode_with_options(const std::map<std::string, Object>& options) const
    {
        [cocoon::internal::ns<::NSView>(this) exitFullScreenModeWithOptions:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                {
                                                                                    return cocoon::internal::to(k);
                                                                                },
                                                                                [](const Object& v) -> id
                                                                                {
                                                                                    return cocoon::internal::native_id(v);
                                                                                })];
    }

    Rect View::frame_for_alignment_rect(const Rect& alignment_rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) frameForAlignmentRect:cocoon::internal::to(alignment_rect)]);
    }

    void View::get_rects_being_drawn(Rect** rects, std::int64_t* count) const
    {
        [cocoon::internal::ns<::NSView>(this) getRectsBeingDrawn:(const ::NSRect**)(rects) count:(::NSInteger*)(count)];
    }

    void View::get_rects_exposed_during_live_resize(Rect* exposed_rects, std::int64_t* count) const
    {
        [cocoon::internal::ns<::NSView>(this) getRectsExposedDuringLiveResize:(::NSRect*)(exposed_rects) count:(::NSInteger*)(count)];
    }

    View View::hit_test(const Point& point) const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSView>(this) hitTest:cocoon::internal::to(point)]);
    }

    void View::invalidate_corner_configuration() const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSView>(this) invalidateCornerConfiguration];
        }
    }

    void View::invalidate_intrinsic_content_size() const
    {
        [cocoon::internal::ns<::NSView>(this) invalidateIntrinsicContentSize];
    }

    bool View::is_descendant_of(const View& view) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) isDescendantOf:cocoon::internal::native<::NSView>(view)]);
    }

    bool View::knows_page_range(Range* range) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) knowsPageRange:(::NSRangePointer)(range)]);
    }

    void View::layout() const
    {
        [cocoon::internal::ns<::NSView>(this) layout];
    }

    LayoutGuide View::layout_guide_for_layout_region(const ViewLayoutRegion& layout_region) const
    {
        return cocoon::internal::wrap<LayoutGuide>([cocoon::internal::ns<::NSView>(this) layoutGuideForLayoutRegion:cocoon::internal::native<::NSViewLayoutRegion>(layout_region)]);
    }

    void View::layout_subtree_if_needed() const
    {
        [cocoon::internal::ns<::NSView>(this) layoutSubtreeIfNeeded];
    }

    Point View::location_of_print_rect(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) locationOfPrintRect:cocoon::internal::to(rect)]);
    }

    CALayer View::make_backing_layer() const
    {
        return cocoon::internal::wrap<CALayer>([cocoon::internal::ns<::NSView>(this) makeBackingLayer]);
    }

    Menu View::menu_for_event(const Event& event) const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSView>(this) menuForEvent:cocoon::internal::native<::NSEvent>(event)]);
    }

    bool View::mouse(const Point& point, const Rect& rect) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) mouse:cocoon::internal::to(point) inRect:cocoon::internal::to(rect)]);
    }

    bool View::needs_to_draw_rect(const Rect& rect) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) needsToDrawRect:cocoon::internal::to(rect)]);
    }

    void View::note_focus_ring_mask_changed() const
    {
        [cocoon::internal::ns<::NSView>(this) noteFocusRingMaskChanged];
    }

    bool View::perform_key_equivalent(const Event& event) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) performKeyEquivalent:cocoon::internal::native<::NSEvent>(event)]);
    }

    void View::prepare_content_in_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSView>(this) prepareContentInRect:cocoon::internal::to(rect)];
    }

    void View::prepare_for_reuse() const
    {
        [cocoon::internal::ns<::NSView>(this) prepareForReuse];
    }

    void View::print(const Object& sender) const
    {
        [cocoon::internal::ns<::NSView>(this) print:cocoon::internal::native_id(sender)];
    }

    Rect View::rect_for_layout_region(const ViewLayoutRegion& layout_region) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) rectForLayoutRegion:cocoon::internal::native<::NSViewLayoutRegion>(layout_region)]);
    }

    Rect View::rect_for_page(std::int64_t page) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) rectForPage:static_cast<::NSInteger>(page)]);
    }

    Rect View::rect_for_smart_magnification_at_point(const Point& location, const Rect& visible_rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) rectForSmartMagnificationAtPoint:cocoon::internal::to(location) inRect:cocoon::internal::to(visible_rect)]);
    }

    void View::reflect_scrolled_clip_view(const ClipView& clip_view) const
    {
        [cocoon::internal::ns<::NSView>(this) reflectScrolledClipView:cocoon::internal::native<::NSClipView>(clip_view)];
    }

    void View::register_for_dragged_types(const std::vector<std::string>& new_types) const
    {
        [cocoon::internal::ns<::NSView>(this) registerForDraggedTypes:cocoon::internal::to_array(new_types, [](const std::string& e) -> id
                                                                     {
                                                                         return cocoon::internal::to(e);
                                                                     })];
    }

    void View::remove_all_tool_tips() const
    {
        [cocoon::internal::ns<::NSView>(this) removeAllToolTips];
    }

    void View::remove_constraint(const LayoutConstraint& constraint) const
    {
        [cocoon::internal::ns<::NSView>(this) removeConstraint:cocoon::internal::native<::NSLayoutConstraint>(constraint)];
    }

    void View::remove_constraints(const std::vector<LayoutConstraint>& constraints) const
    {
        [cocoon::internal::ns<::NSView>(this) removeConstraints:cocoon::internal::to_array(constraints, [](const LayoutConstraint& e) -> id
                                                               {
                                                                   return cocoon::internal::native<::NSLayoutConstraint>(e);
                                                               })];
    }

    void View::remove_cursor_rect(const Rect& rect, const Cursor& object) const
    {
        [cocoon::internal::ns<::NSView>(this) removeCursorRect:cocoon::internal::to(rect) cursor:cocoon::internal::native<::NSCursor>(object)];
    }

    void View::remove_from_superview() const
    {
        [cocoon::internal::ns<::NSView>(this) removeFromSuperview];
    }

    void View::remove_from_superview_without_needing_display() const
    {
        [cocoon::internal::ns<::NSView>(this) removeFromSuperviewWithoutNeedingDisplay];
    }

    void View::remove_gesture_recognizer(const GestureRecognizer& gesture_recognizer) const
    {
        [cocoon::internal::ns<::NSView>(this) removeGestureRecognizer:cocoon::internal::native<::NSGestureRecognizer>(gesture_recognizer)];
    }

    void View::remove_layout_guide(const LayoutGuide& guide) const
    {
        [cocoon::internal::ns<::NSView>(this) removeLayoutGuide:cocoon::internal::native<::NSLayoutGuide>(guide)];
    }

    void View::remove_tool_tip(std::int64_t tag) const
    {
        [cocoon::internal::ns<::NSView>(this) removeToolTip:static_cast<::NSToolTipTag>(tag)];
    }

    void View::remove_tracking_area(const TrackingArea& tracking_area) const
    {
        [cocoon::internal::ns<::NSView>(this) removeTrackingArea:cocoon::internal::native<::NSTrackingArea>(tracking_area)];
    }

    void View::remove_tracking_rect(std::int64_t tag) const
    {
        [cocoon::internal::ns<::NSView>(this) removeTrackingRect:static_cast<::NSTrackingRectTag>(tag)];
    }

    void View::replace_subview(const View& old_view, const View& new_view) const
    {
        [cocoon::internal::ns<::NSView>(this) replaceSubview:cocoon::internal::native<::NSView>(old_view) with:cocoon::internal::native<::NSView>(new_view)];
    }

    void View::reset_cursor_rects() const
    {
        [cocoon::internal::ns<::NSView>(this) resetCursorRects];
    }

    void View::resize_subviews_with_old_size(const Size& old_size) const
    {
        [cocoon::internal::ns<::NSView>(this) resizeSubviewsWithOldSize:cocoon::internal::to(old_size)];
    }

    void View::resize_with_old_superview_size(const Size& old_size) const
    {
        [cocoon::internal::ns<::NSView>(this) resizeWithOldSuperviewSize:cocoon::internal::to(old_size)];
    }

    void View::rotate_by_angle(double angle) const
    {
        [cocoon::internal::ns<::NSView>(this) rotateByAngle:static_cast<::CGFloat>(angle)];
    }

    void View::ruler_view(const RulerView& ruler, const RulerMarker& marker) const
    {
        [cocoon::internal::ns<::NSView>(this) rulerView:cocoon::internal::native<::NSRulerView>(ruler) didAddMarker:cocoon::internal::native<::NSRulerMarker>(marker)];
    }

    void View::ruler_view(const RulerView& ruler, const Event& event) const
    {
        [cocoon::internal::ns<::NSView>(this) rulerView:cocoon::internal::native<::NSRulerView>(ruler) handleMouseDown:cocoon::internal::native<::NSEvent>(event)];
    }

    double View::ruler_view(const RulerView& ruler, const Point& point) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSView>(this) rulerView:cocoon::internal::native<::NSRulerView>(ruler) locationForPoint:cocoon::internal::to(point)]);
    }

    Point View::ruler_view(const RulerView& ruler, double point) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) rulerView:cocoon::internal::native<::NSRulerView>(ruler) pointForLocation:static_cast<::CGFloat>(point)]);
    }

    double View::ruler_view(const RulerView& ruler, const RulerMarker& marker, double location) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSView>(this) rulerView:cocoon::internal::native<::NSRulerView>(ruler) willAddMarker:cocoon::internal::native<::NSRulerMarker>(marker) atLocation:static_cast<::CGFloat>(location)]);
    }

    void View::ruler_view(const RulerView& ruler, const View& new_client) const
    {
        [cocoon::internal::ns<::NSView>(this) rulerView:cocoon::internal::native<::NSRulerView>(ruler) willSetClientView:cocoon::internal::native<::NSView>(new_client)];
    }

    void View::scale_unit_square_to_size(const Size& new_unit_size) const
    {
        [cocoon::internal::ns<::NSView>(this) scaleUnitSquareToSize:cocoon::internal::to(new_unit_size)];
    }

    void View::scroll_clip_view(const ClipView& clip_view, const Point& point) const
    {
        [cocoon::internal::ns<::NSView>(this) scrollClipView:cocoon::internal::native<::NSClipView>(clip_view) toPoint:cocoon::internal::to(point)];
    }

    void View::scroll_point(const Point& point) const
    {
        [cocoon::internal::ns<::NSView>(this) scrollPoint:cocoon::internal::to(point)];
    }

    bool View::scroll_rect_to_visible(const Rect& rect) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) scrollRectToVisible:cocoon::internal::to(rect)]);
    }

    void View::set_bounds_origin(const Point& new_origin) const
    {
        [cocoon::internal::ns<::NSView>(this) setBoundsOrigin:cocoon::internal::to(new_origin)];
    }

    void View::set_bounds_size(const Size& new_size) const
    {
        [cocoon::internal::ns<::NSView>(this) setBoundsSize:cocoon::internal::to(new_size)];
    }

    void View::set_content_compression_resistance_priority(float priority, ConstraintOrientation orientation) const
    {
        [cocoon::internal::ns<::NSView>(this) setContentCompressionResistancePriority:static_cast<::NSLayoutPriority>(priority) forOrientation:static_cast<::NSLayoutConstraintOrientation>(orientation)];
    }

    void View::set_content_hugging_priority(float priority, ConstraintOrientation orientation) const
    {
        [cocoon::internal::ns<::NSView>(this) setContentHuggingPriority:static_cast<::NSLayoutPriority>(priority) forOrientation:static_cast<::NSLayoutConstraintOrientation>(orientation)];
    }

    void View::set_frame_origin(const Point& new_origin) const
    {
        [cocoon::internal::ns<::NSView>(this) setFrameOrigin:cocoon::internal::to(new_origin)];
    }

    void View::set_frame_size(const Size& new_size) const
    {
        [cocoon::internal::ns<::NSView>(this) setFrameSize:cocoon::internal::to(new_size)];
    }

    void View::set_keyboard_focus_ring_needs_display_in_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSView>(this) setKeyboardFocusRingNeedsDisplayInRect:cocoon::internal::to(rect)];
    }

    void View::set_needs_display_in_rect(const Rect& invalid_rect) const
    {
        [cocoon::internal::ns<::NSView>(this) setNeedsDisplayInRect:cocoon::internal::to(invalid_rect)];
    }

    bool View::should_delay_window_ordering_for_event(const Event& event) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) shouldDelayWindowOrderingForEvent:cocoon::internal::native<::NSEvent>(event)]);
    }

    void View::show_definition_for_attributed_string(const AttributedString& attr_string, const Point& text_baseline_origin) const
    {
        [cocoon::internal::ns<::NSView>(this) showDefinitionForAttributedString:cocoon::internal::native<::NSAttributedString>(attr_string) atPoint:cocoon::internal::to(text_baseline_origin)];
    }

    void View::show_definition_for_attributed_string(const AttributedString& attr_string, const Range& target_range, const std::map<std::string, Object>& options, std::function<Point(Range)> origin_provider) const
    {
        [cocoon::internal::ns<::NSView>(this) showDefinitionForAttributedString:cocoon::internal::native<::NSAttributedString>(attr_string)
                                                            range:cocoon::internal::to(target_range)
                                                          options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                    {
                                                                                        return cocoon::internal::to(k);
                                                                                    },
                                                                                    [](const Object& v) -> id
                                                                                    {
                                                                                        return cocoon::internal::native_id(v);
                                                                                    })
                                           baselineOriginProvider:(origin_provider ? (::NSPoint(^)(::NSRange)) ^ ::NSPoint(::NSRange a103_0) { auto __r = origin_provider(cocoon::internal::from(a103_0)); return cocoon::internal::to(__r); } : (::NSPoint(^)(::NSRange))nil)];
    }

    void View::sort_subviews_using_function(ComparisonResult (*compare)(void*, void*, void*), void* context) const
    {
        [cocoon::internal::ns<::NSView>(this) sortSubviewsUsingFunction:(::NSComparisonResult (*)(__kindof ::NSView*, __kindof ::NSView*, void*))(compare) context:context];
    }

    void View::translate_origin_to_point(const Point& translation) const
    {
        [cocoon::internal::ns<::NSView>(this) translateOriginToPoint:cocoon::internal::to(translation)];
    }

    void View::translate_rects_needing_display_in_rect(const Rect& clip_rect, const Size& delta) const
    {
        [cocoon::internal::ns<::NSView>(this) translateRectsNeedingDisplayInRect:cocoon::internal::to(clip_rect) by:cocoon::internal::to(delta)];
    }

    void View::unregister_dragged_types() const
    {
        [cocoon::internal::ns<::NSView>(this) unregisterDraggedTypes];
    }

    void View::update_constraints() const
    {
        [cocoon::internal::ns<::NSView>(this) updateConstraints];
    }

    void View::update_constraints_for_subtree_if_needed() const
    {
        [cocoon::internal::ns<::NSView>(this) updateConstraintsForSubtreeIfNeeded];
    }

    void View::update_layer() const
    {
        [cocoon::internal::ns<::NSView>(this) updateLayer];
    }

    void View::update_tracking_areas() const
    {
        [cocoon::internal::ns<::NSView>(this) updateTrackingAreas];
    }

    void View::view_did_change_backing_properties() const
    {
        [cocoon::internal::ns<::NSView>(this) viewDidChangeBackingProperties];
    }

    void View::view_did_change_effective_appearance() const
    {
        [cocoon::internal::ns<::NSView>(this) viewDidChangeEffectiveAppearance];
    }

    void View::view_did_change_effective_corner_radii() const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSView>(this) viewDidChangeEffectiveCornerRadii];
        }
    }

    void View::view_did_end_live_resize() const
    {
        [cocoon::internal::ns<::NSView>(this) viewDidEndLiveResize];
    }

    void View::view_did_hide() const
    {
        [cocoon::internal::ns<::NSView>(this) viewDidHide];
    }

    void View::view_did_move_to_superview() const
    {
        [cocoon::internal::ns<::NSView>(this) viewDidMoveToSuperview];
    }

    void View::view_did_move_to_window() const
    {
        [cocoon::internal::ns<::NSView>(this) viewDidMoveToWindow];
    }

    void View::view_did_unhide() const
    {
        [cocoon::internal::ns<::NSView>(this) viewDidUnhide];
    }

    void View::view_will_draw() const
    {
        [cocoon::internal::ns<::NSView>(this) viewWillDraw];
    }

    void View::view_will_move_to_superview(const View& new_superview) const
    {
        [cocoon::internal::ns<::NSView>(this) viewWillMoveToSuperview:cocoon::internal::native<::NSView>(new_superview)];
    }

    void View::view_will_move_to_window(const Window& new_window) const
    {
        [cocoon::internal::ns<::NSView>(this) viewWillMoveToWindow:cocoon::internal::native<::NSWindow>(new_window)];
    }

    void View::view_will_start_live_resize() const
    {
        [cocoon::internal::ns<::NSView>(this) viewWillStartLiveResize];
    }

    View View::view_with_tag(std::int64_t tag) const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSView>(this) viewWithTag:static_cast<::NSInteger>(tag)]);
    }

    void View::will_open_menu(const Menu& menu, const Event& event) const
    {
        [cocoon::internal::ns<::NSView>(this) willOpenMenu:cocoon::internal::native<::NSMenu>(menu) withEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void View::will_remove_subview(const View& subview) const
    {
        [cocoon::internal::ns<::NSView>(this) willRemoveSubview:cocoon::internal::native<::NSView>(subview)];
    }

    void View::write_eps_inside_rect(const Rect& rect, const Pasteboard& pasteboard) const
    {
        [cocoon::internal::ns<::NSView>(this) writeEPSInsideRect:cocoon::internal::to(rect) toPasteboard:cocoon::internal::native<::NSPasteboard>(pasteboard)];
    }

    void View::write_pdf_inside_rect(const Rect& rect, const Pasteboard& pasteboard) const
    {
        [cocoon::internal::ns<::NSView>(this) writePDFInsideRect:cocoon::internal::to(rect) toPasteboard:cocoon::internal::native<::NSPasteboard>(pasteboard)];
    }

    Insets View::additional_safe_area_insets() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) additionalSafeAreaInsets]);
    }

    void View::set_additional_safe_area_insets(const Insets& value) const
    {
        [cocoon::internal::ns<::NSView>(this) setAdditionalSafeAreaInsets:cocoon::internal::to(value)];
    }

    Insets View::alignment_rect_insets() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) alignmentRectInsets]);
    }

    TouchTypeMask View::allowed_touch_types() const
    {
        return static_cast<TouchTypeMask>([cocoon::internal::ns<::NSView>(this) allowedTouchTypes]);
    }

    void View::set_allowed_touch_types(TouchTypeMask value) const
    {
        [cocoon::internal::ns<::NSView>(this) setAllowedTouchTypes:static_cast<::NSTouchTypeMask>(value)];
    }

    bool View::allows_vibrancy() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) allowsVibrancy]);
    }

    double View::alpha_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSView>(this) alphaValue]);
    }

    void View::set_alpha_value(double value) const
    {
        [cocoon::internal::ns<::NSView>(this) setAlphaValue:static_cast<::CGFloat>(value)];
    }

    bool View::autoresizes_subviews() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) autoresizesSubviews]);
    }

    void View::set_autoresizes_subviews(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setAutoresizesSubviews:static_cast<::BOOL>(value)];
    }

    AutoresizingMaskOptions View::autoresizing_mask() const
    {
        return static_cast<AutoresizingMaskOptions>([cocoon::internal::ns<::NSView>(this) autoresizingMask]);
    }

    void View::set_autoresizing_mask(AutoresizingMaskOptions value) const
    {
        [cocoon::internal::ns<::NSView>(this) setAutoresizingMask:static_cast<::NSAutoresizingMaskOptions>(value)];
    }

    std::vector<Object> View::background_filters() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSView>(this) backgroundFilters], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    void View::set_background_filters(const std::vector<Object>& value) const
    {
        [cocoon::internal::ns<::NSView>(this) setBackgroundFilters:cocoon::internal::to_array(value, [](const Object& e) -> id
                                                                  {
                                                                      return cocoon::internal::native_id(e);
                                                                  })];
    }

    double View::baseline_offset_from_bottom() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSView>(this) baselineOffsetFromBottom]);
    }

    LayoutYAxisAnchor View::bottom_anchor() const
    {
        return cocoon::internal::wrap<LayoutYAxisAnchor>([cocoon::internal::ns<::NSView>(this) bottomAnchor]);
    }

    Rect View::bounds() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) bounds]);
    }

    void View::set_bounds(const Rect& value) const
    {
        [cocoon::internal::ns<::NSView>(this) setBounds:cocoon::internal::to(value)];
    }

    double View::bounds_rotation() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSView>(this) boundsRotation]);
    }

    void View::set_bounds_rotation(double value) const
    {
        [cocoon::internal::ns<::NSView>(this) setBoundsRotation:static_cast<::CGFloat>(value)];
    }

    bool View::can_become_key_view() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) canBecomeKeyView]);
    }

    bool View::can_draw_concurrently() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) canDrawConcurrently]);
    }

    void View::set_can_draw_concurrently(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setCanDrawConcurrently:static_cast<::BOOL>(value)];
    }

    bool View::can_draw_subviews_into_layer() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) canDrawSubviewsIntoLayer]);
    }

    void View::set_can_draw_subviews_into_layer(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setCanDrawSubviewsIntoLayer:static_cast<::BOOL>(value)];
    }

    CandidateListTouchBarItemBase View::candidate_list_touch_bar_item() const
    {
        return cocoon::internal::wrap<CandidateListTouchBarItemBase>([cocoon::internal::ns<::NSView>(this) candidateListTouchBarItem]);
    }

    LayoutXAxisAnchor View::center_x_anchor() const
    {
        return cocoon::internal::wrap<LayoutXAxisAnchor>([cocoon::internal::ns<::NSView>(this) centerXAnchor]);
    }

    LayoutYAxisAnchor View::center_y_anchor() const
    {
        return cocoon::internal::wrap<LayoutYAxisAnchor>([cocoon::internal::ns<::NSView>(this) centerYAnchor]);
    }

    bool View::clips_to_bounds() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) clipsToBounds]);
    }

    void View::set_clips_to_bounds(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setClipsToBounds:static_cast<::BOOL>(value)];
    }

    bool View::is_compatible_with_responsive_scrolling()
    {
        return static_cast<bool>([::NSView isCompatibleWithResponsiveScrolling]);
    }

    Object View::compositing_filter() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSView>(this) compositingFilter]);
    }

    void View::set_compositing_filter(const Object& value) const
    {
        [cocoon::internal::ns<::NSView>(this) setCompositingFilter:cocoon::internal::native_id(value)];
    }

    std::vector<LayoutConstraint> View::constraints() const
    {
        return cocoon::internal::from_array<LayoutConstraint>([cocoon::internal::ns<::NSView>(this) constraints], [](id e) -> LayoutConstraint
                                                {
                                                    return cocoon::internal::wrap<LayoutConstraint>((::NSLayoutConstraint*)e);
                                                });
    }

    std::vector<Object> View::content_filters() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSView>(this) contentFilters], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    void View::set_content_filters(const std::vector<Object>& value) const
    {
        [cocoon::internal::ns<::NSView>(this) setContentFilters:cocoon::internal::to_array(value, [](const Object& e) -> id
                                                               {
                                                                   return cocoon::internal::native_id(e);
                                                               })];
    }

    ViewCornerConfiguration View::corner_configuration() const
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::wrap<ViewCornerConfiguration>([cocoon::internal::ns<::NSView>(this) cornerConfiguration]);
        }
        return ViewCornerConfiguration(nullptr);
    }

    FocusRingType View::default_focus_ring_type()
    {
        return static_cast<FocusRingType>([::NSView defaultFocusRingType]);
    }

    Menu View::default_menu()
    {
        return cocoon::internal::wrap<Menu>([::NSView defaultMenu]);
    }

    bool View::is_drawing_find_indicator() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) isDrawingFindIndicator]);
    }

    ViewCornerRadii View::effective_corner_radii() const
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::wrap<ViewCornerRadii>([cocoon::internal::ns<::NSView>(this) effectiveCornerRadii]);
        }
        return ViewCornerRadii(nullptr);
    }

    MenuItem View::enclosing_menu_item() const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSView>(this) enclosingMenuItem]);
    }

    ScrollView View::enclosing_scroll_view() const
    {
        return cocoon::internal::wrap<ScrollView>([cocoon::internal::ns<::NSView>(this) enclosingScrollView]);
    }

    ViewExclusiveGestureBehavior View::exclusive_gesture_behavior() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<ViewExclusiveGestureBehavior>([cocoon::internal::ns<::NSView>(this) exclusiveGestureBehavior]);
        }
        return {};
    }

    void View::set_exclusive_gesture_behavior(ViewExclusiveGestureBehavior value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSView>(this) setExclusiveGestureBehavior:static_cast<::NSViewExclusiveGestureBehavior>(value)];
        }
    }

    LayoutYAxisAnchor View::first_baseline_anchor() const
    {
        return cocoon::internal::wrap<LayoutYAxisAnchor>([cocoon::internal::ns<::NSView>(this) firstBaselineAnchor]);
    }

    double View::first_baseline_offset_from_top() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSView>(this) firstBaselineOffsetFromTop]);
    }

    Size View::fitting_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) fittingSize]);
    }

    bool View::is_flipped() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) isFlipped]);
    }

    Rect View::focus_ring_mask_bounds() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) focusRingMaskBounds]);
    }

    FocusRingType View::focus_ring_type() const
    {
        return static_cast<FocusRingType>([cocoon::internal::ns<::NSView>(this) focusRingType]);
    }

    void View::set_focus_ring_type(FocusRingType value) const
    {
        [cocoon::internal::ns<::NSView>(this) setFocusRingType:static_cast<::NSFocusRingType>(value)];
    }

    View View::focus_view()
    {
        return cocoon::internal::wrap<View>([::NSView focusView]);
    }

    Rect View::frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) frame]);
    }

    void View::set_frame(const Rect& value) const
    {
        [cocoon::internal::ns<::NSView>(this) setFrame:cocoon::internal::to(value)];
    }

    double View::frame_center_rotation() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSView>(this) frameCenterRotation]);
    }

    void View::set_frame_center_rotation(double value) const
    {
        [cocoon::internal::ns<::NSView>(this) setFrameCenterRotation:static_cast<::CGFloat>(value)];
    }

    double View::frame_rotation() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSView>(this) frameRotation]);
    }

    void View::set_frame_rotation(double value) const
    {
        [cocoon::internal::ns<::NSView>(this) setFrameRotation:static_cast<::CGFloat>(value)];
    }

    std::vector<GestureRecognizer> View::gesture_recognizers() const
    {
        return cocoon::internal::from_array<GestureRecognizer>([cocoon::internal::ns<::NSView>(this) gestureRecognizers], [](id e) -> GestureRecognizer
                                                 {
                                                     return cocoon::internal::wrap<GestureRecognizer>((::NSGestureRecognizer*)e);
                                                 });
    }

    void View::set_gesture_recognizers(const std::vector<GestureRecognizer>& value) const
    {
        [cocoon::internal::ns<::NSView>(this) setGestureRecognizers:cocoon::internal::to_array(value, [](const GestureRecognizer& e) -> id
                                                                   {
                                                                       return cocoon::internal::native<::NSGestureRecognizer>(e);
                                                                   })];
    }

    bool View::has_ambiguous_layout() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) hasAmbiguousLayout]);
    }

    double View::height_adjust_limit() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSView>(this) heightAdjustLimit]);
    }

    LayoutDimension View::height_anchor() const
    {
        return cocoon::internal::wrap<LayoutDimension>([cocoon::internal::ns<::NSView>(this) heightAnchor]);
    }

    bool View::is_hidden() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) isHidden]);
    }

    void View::set_hidden(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setHidden:static_cast<::BOOL>(value)];
    }

    bool View::is_hidden_or_has_hidden_ancestor() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) isHiddenOrHasHiddenAncestor]);
    }

    bool View::is_horizontal_content_size_constraint_active() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) isHorizontalContentSizeConstraintActive]);
    }

    void View::set_horizontal_content_size_constraint_active(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setHorizontalContentSizeConstraintActive:static_cast<::BOOL>(value)];
    }

    bool View::is_in_full_screen_mode() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) isInFullScreenMode]);
    }

    bool View::in_live_resize() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) inLiveResize]);
    }

    TextInputContext View::input_context() const
    {
        return cocoon::internal::wrap<TextInputContext>([cocoon::internal::ns<::NSView>(this) inputContext]);
    }

    Size View::intrinsic_content_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) intrinsicContentSize]);
    }

    LayoutYAxisAnchor View::last_baseline_anchor() const
    {
        return cocoon::internal::wrap<LayoutYAxisAnchor>([cocoon::internal::ns<::NSView>(this) lastBaselineAnchor]);
    }

    double View::last_baseline_offset_from_bottom() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSView>(this) lastBaselineOffsetFromBottom]);
    }

    CALayer View::layer() const
    {
        return cocoon::internal::wrap<CALayer>([cocoon::internal::ns<::NSView>(this) layer]);
    }

    void View::set_layer(const CALayer& value) const
    {
        [cocoon::internal::ns<::NSView>(this) setLayer:cocoon::internal::native<::CALayer>(value)];
    }

    ViewLayerContentsPlacement View::layer_contents_placement() const
    {
        return static_cast<ViewLayerContentsPlacement>([cocoon::internal::ns<::NSView>(this) layerContentsPlacement]);
    }

    void View::set_layer_contents_placement(ViewLayerContentsPlacement value) const
    {
        [cocoon::internal::ns<::NSView>(this) setLayerContentsPlacement:static_cast<::NSViewLayerContentsPlacement>(value)];
    }

    ViewLayerContentsRedrawPolicy View::layer_contents_redraw_policy() const
    {
        return static_cast<ViewLayerContentsRedrawPolicy>([cocoon::internal::ns<::NSView>(this) layerContentsRedrawPolicy]);
    }

    void View::set_layer_contents_redraw_policy(ViewLayerContentsRedrawPolicy value) const
    {
        [cocoon::internal::ns<::NSView>(this) setLayerContentsRedrawPolicy:static_cast<::NSViewLayerContentsRedrawPolicy>(value)];
    }

    bool View::layer_uses_core_image_filters() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) layerUsesCoreImageFilters]);
    }

    void View::set_layer_uses_core_image_filters(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setLayerUsesCoreImageFilters:static_cast<::BOOL>(value)];
    }

    std::vector<LayoutGuide> View::layout_guides() const
    {
        return cocoon::internal::from_array<LayoutGuide>([cocoon::internal::ns<::NSView>(this) layoutGuides], [](id e) -> LayoutGuide
                                           {
                                               return cocoon::internal::wrap<LayoutGuide>((::NSLayoutGuide*)e);
                                           });
    }

    LayoutGuide View::layout_margins_guide() const
    {
        return cocoon::internal::wrap<LayoutGuide>([cocoon::internal::ns<::NSView>(this) layoutMarginsGuide]);
    }

    LayoutXAxisAnchor View::leading_anchor() const
    {
        return cocoon::internal::wrap<LayoutXAxisAnchor>([cocoon::internal::ns<::NSView>(this) leadingAnchor]);
    }

    LayoutXAxisAnchor View::left_anchor() const
    {
        return cocoon::internal::wrap<LayoutXAxisAnchor>([cocoon::internal::ns<::NSView>(this) leftAnchor]);
    }

    bool View::mouse_down_can_move_window() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) mouseDownCanMoveWindow]);
    }

    bool View::needs_display() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) needsDisplay]);
    }

    void View::set_needs_display(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setNeedsDisplay:static_cast<::BOOL>(value)];
    }

    bool View::needs_layout() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) needsLayout]);
    }

    void View::set_needs_layout(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setNeedsLayout:static_cast<::BOOL>(value)];
    }

    bool View::needs_panel_to_become_key() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) needsPanelToBecomeKey]);
    }

    bool View::needs_update_constraints() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) needsUpdateConstraints]);
    }

    void View::set_needs_update_constraints(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setNeedsUpdateConstraints:static_cast<::BOOL>(value)];
    }

    View View::next_key_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSView>(this) nextKeyView]);
    }

    void View::set_next_key_view(const View& value) const
    {
        [cocoon::internal::ns<::NSView>(this) setNextKeyView:cocoon::internal::native<::NSView>(value)];
    }

    View View::next_valid_key_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSView>(this) nextValidKeyView]);
    }

    bool View::is_opaque() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) isOpaque]);
    }

    View View::opaque_ancestor() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSView>(this) opaqueAncestor]);
    }

    AttributedString View::page_footer() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSView>(this) pageFooter]);
    }

    AttributedString View::page_header() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSView>(this) pageHeader]);
    }

    bool View::posts_bounds_changed_notifications() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) postsBoundsChangedNotifications]);
    }

    void View::set_posts_bounds_changed_notifications(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setPostsBoundsChangedNotifications:static_cast<::BOOL>(value)];
    }

    bool View::posts_frame_changed_notifications() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) postsFrameChangedNotifications]);
    }

    void View::set_posts_frame_changed_notifications(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setPostsFrameChangedNotifications:static_cast<::BOOL>(value)];
    }

    bool View::prefers_compact_control_size_metrics() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) prefersCompactControlSizeMetrics]);
    }

    void View::set_prefers_compact_control_size_metrics(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setPrefersCompactControlSizeMetrics:static_cast<::BOOL>(value)];
    }

    Rect View::prepared_content_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) preparedContentRect]);
    }

    void View::set_prepared_content_rect(const Rect& value) const
    {
        [cocoon::internal::ns<::NSView>(this) setPreparedContentRect:cocoon::internal::to(value)];
    }

    bool View::preserves_content_during_live_resize() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) preservesContentDuringLiveResize]);
    }

    PressureConfiguration View::pressure_configuration() const
    {
        return cocoon::internal::wrap<PressureConfiguration>([cocoon::internal::ns<::NSView>(this) pressureConfiguration]);
    }

    void View::set_pressure_configuration(const PressureConfiguration& value) const
    {
        [cocoon::internal::ns<::NSView>(this) setPressureConfiguration:cocoon::internal::native<::NSPressureConfiguration>(value)];
    }

    View View::previous_key_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSView>(this) previousKeyView]);
    }

    View View::previous_valid_key_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSView>(this) previousValidKeyView]);
    }

    std::string View::print_job_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) printJobTitle]);
    }

    Rect View::rect_preserved_during_live_resize() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) rectPreservedDuringLiveResize]);
    }

    std::vector<std::string> View::registered_dragged_types() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSView>(this) registeredDraggedTypes], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    bool View::requires_constraint_based_layout()
    {
        return static_cast<bool>([::NSView requiresConstraintBasedLayout]);
    }

    LayoutXAxisAnchor View::right_anchor() const
    {
        return cocoon::internal::wrap<LayoutXAxisAnchor>([cocoon::internal::ns<::NSView>(this) rightAnchor]);
    }

    bool View::is_rotated_from_base() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) isRotatedFromBase]);
    }

    bool View::is_rotated_or_scaled_from_base() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) isRotatedOrScaledFromBase]);
    }

    Insets View::safe_area_insets() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) safeAreaInsets]);
    }

    LayoutGuide View::safe_area_layout_guide() const
    {
        return cocoon::internal::wrap<LayoutGuide>([cocoon::internal::ns<::NSView>(this) safeAreaLayoutGuide]);
    }

    Rect View::safe_area_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) safeAreaRect]);
    }

    Shadow View::shadow() const
    {
        return cocoon::internal::wrap<Shadow>([cocoon::internal::ns<::NSView>(this) shadow]);
    }

    void View::set_shadow(const Shadow& value) const
    {
        [cocoon::internal::ns<::NSView>(this) setShadow:cocoon::internal::native<::NSShadow>(value)];
    }

    std::vector<View> View::subviews() const
    {
        return cocoon::internal::from_array<View>([cocoon::internal::ns<::NSView>(this) subviews], [](id e) -> View
                                    {
                                        return cocoon::internal::wrap<View>((::NSView*)e);
                                    });
    }

    void View::set_subviews(const std::vector<View>& value) const
    {
        [cocoon::internal::ns<::NSView>(this) setSubviews:cocoon::internal::to_array(value, [](const View& e) -> id
                                                         {
                                                             return cocoon::internal::native<::NSView>(e);
                                                         })];
    }

    View View::superview() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSView>(this) superview]);
    }

    std::int64_t View::tag() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSView>(this) tag]);
    }

    TextSelectionManager View::text_selection_manager() const
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::wrap<TextSelectionManager>([cocoon::internal::ns<::NSView>(this) textSelectionManager]);
        }
        return TextSelectionManager(nullptr);
    }

    void View::set_text_selection_manager(const TextSelectionManager& value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSView>(this) setTextSelectionManager:cocoon::internal::native<::NSTextSelectionManager>(value)];
        }
    }

    std::string View::tool_tip() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) toolTip]);
    }

    void View::set_tool_tip(const std::string& value) const
    {
        [cocoon::internal::ns<::NSView>(this) setToolTip:cocoon::internal::to(value)];
    }

    LayoutYAxisAnchor View::top_anchor() const
    {
        return cocoon::internal::wrap<LayoutYAxisAnchor>([cocoon::internal::ns<::NSView>(this) topAnchor]);
    }

    std::vector<TrackingArea> View::tracking_areas() const
    {
        return cocoon::internal::from_array<TrackingArea>([cocoon::internal::ns<::NSView>(this) trackingAreas], [](id e) -> TrackingArea
                                            {
                                                return cocoon::internal::wrap<TrackingArea>((::NSTrackingArea*)e);
                                            });
    }

    LayoutXAxisAnchor View::trailing_anchor() const
    {
        return cocoon::internal::wrap<LayoutXAxisAnchor>([cocoon::internal::ns<::NSView>(this) trailingAnchor]);
    }

    bool View::translates_autoresizing_mask_into_constraints() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) translatesAutoresizingMaskIntoConstraints]);
    }

    void View::set_translates_autoresizing_mask_into_constraints(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setTranslatesAutoresizingMaskIntoConstraints:static_cast<::BOOL>(value)];
    }

    UserInterfaceLayoutDirection View::user_interface_layout_direction() const
    {
        return static_cast<UserInterfaceLayoutDirection>([cocoon::internal::ns<::NSView>(this) userInterfaceLayoutDirection]);
    }

    void View::set_user_interface_layout_direction(UserInterfaceLayoutDirection value) const
    {
        [cocoon::internal::ns<::NSView>(this) setUserInterfaceLayoutDirection:static_cast<::NSUserInterfaceLayoutDirection>(value)];
    }

    bool View::is_vertical_content_size_constraint_active() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) isVerticalContentSizeConstraintActive]);
    }

    void View::set_vertical_content_size_constraint_active(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setVerticalContentSizeConstraintActive:static_cast<::BOOL>(value)];
    }

    Rect View::visible_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSView>(this) visibleRect]);
    }

    bool View::wants_default_clipping() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) wantsDefaultClipping]);
    }

    bool View::wants_layer() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) wantsLayer]);
    }

    void View::set_wants_layer(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setWantsLayer:static_cast<::BOOL>(value)];
    }

    bool View::wants_resting_touches() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) wantsRestingTouches]);
    }

    void View::set_wants_resting_touches(bool value) const
    {
        [cocoon::internal::ns<::NSView>(this) setWantsRestingTouches:static_cast<::BOOL>(value)];
    }

    bool View::wants_update_layer() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSView>(this) wantsUpdateLayer]);
    }

    double View::width_adjust_limit() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSView>(this) widthAdjustLimit]);
    }

    LayoutDimension View::width_anchor() const
    {
        return cocoon::internal::wrap<LayoutDimension>([cocoon::internal::ns<::NSView>(this) widthAnchor]);
    }

    Window View::window() const
    {
        return cocoon::internal::wrap<Window>([cocoon::internal::ns<::NSView>(this) window]);
    }

    WritingToolsCoordinator View::writing_tools_coordinator() const
    {
        return cocoon::internal::wrap<WritingToolsCoordinator>([cocoon::internal::ns<::NSView>(this) writingToolsCoordinator]);
    }

    void View::set_writing_tools_coordinator(const WritingToolsCoordinator& value) const
    {
        [cocoon::internal::ns<::NSView>(this) setWritingToolsCoordinator:cocoon::internal::native<::NSWritingToolsCoordinator>(value)];
    }

    void View::add_subview(const View& child) const
    {
        cocoon::internal::native<NSView>(child).translatesAutoresizingMaskIntoConstraints = NO;
        [cocoon::internal::ns<NSView>(this) addSubview:cocoon::internal::native<NSView>(child)];
    }

    void View::pin_to_superview(const Insets& insets) const
    {
        NSView* native = cocoon::internal::ns<NSView>(this);
        NSView* superview = native.superview;
        if (!superview)
        {
            return;
        }
        [NSLayoutConstraint activateConstraints:@[
            [native.topAnchor constraintEqualToAnchor:superview.topAnchor
                                             constant:insets.top],
            [native.leadingAnchor constraintEqualToAnchor:superview.leadingAnchor
                                                 constant:insets.left],
            [superview.trailingAnchor constraintEqualToAnchor:native.trailingAnchor
                                                     constant:insets.right],
            [superview.bottomAnchor constraintEqualToAnchor:native.bottomAnchor
                                                   constant:insets.bottom],
        ]];
    }

    void View::pin_to_safe_area(const Insets& insets) const
    {
        NSView* native = cocoon::internal::ns<NSView>(this);
        NSView* superview = native.superview;
        if (!superview)
        {
            return;
        }
        NSLayoutGuide* guide = superview.safeAreaLayoutGuide;
        [NSLayoutConstraint activateConstraints:@[
            [native.topAnchor constraintEqualToAnchor:guide.topAnchor
                                             constant:insets.top],
            [native.leadingAnchor constraintEqualToAnchor:guide.leadingAnchor
                                                 constant:insets.left],
            [guide.trailingAnchor constraintEqualToAnchor:native.trailingAnchor
                                                 constant:insets.right],
            [guide.bottomAnchor constraintEqualToAnchor:native.bottomAnchor
                                               constant:insets.bottom],
        ]];
    }

    void View::center_in_superview() const
    {
        NSView* native = cocoon::internal::ns<NSView>(this);
        NSView* superview = native.superview;
        if (!superview)
        {
            return;
        }
        [NSLayoutConstraint activateConstraints:@[
            [native.centerXAnchor constraintEqualToAnchor:superview.centerXAnchor],
            [native.centerYAnchor constraintEqualToAnchor:superview.centerYAnchor],
        ]];
    }

    void View::set_fixed_width(double width) const
    {
        [[cocoon::internal::ns<NSView>(this).widthAnchor constraintEqualToConstant:width] setActive:YES];
    }

    void View::set_fixed_height(double height) const
    {
        [[cocoon::internal::ns<NSView>(this).heightAnchor constraintEqualToConstant:height] setActive:YES];
    }

    void View::set_fixed_size(double width, double height) const
    {
        set_fixed_width(width);
        set_fixed_height(height);
    }

    void View::set_minimum_size(double width, double height) const
    {
        NSView* native = cocoon::internal::ns<NSView>(this);
        [[native.widthAnchor constraintGreaterThanOrEqualToConstant:width] setActive:YES];
        [[native.heightAnchor constraintGreaterThanOrEqualToConstant:height] setActive:YES];
    }

    void View::set_maximum_size(double width, double height) const
    {
        NSView* native = cocoon::internal::ns<NSView>(this);
        [[native.widthAnchor constraintLessThanOrEqualToConstant:width] setActive:YES];
        [[native.heightAnchor constraintLessThanOrEqualToConstant:height] setActive:YES];
    }

    void View::set_background_color(const Color& color) const
    {
        NSView* native = cocoon::internal::ns<NSView>(this);
        native.wantsLayer = YES;
        native.layer.backgroundColor = color.is_null() ? nil : cocoon::internal::native<NSColor>(color).CGColor;
    }

    void View::set_layer_corner_radius(double radius) const
    {
        NSView* native = cocoon::internal::ns<NSView>(this);
        native.wantsLayer = YES;
        native.layer.cornerRadius = radius;
        native.layer.masksToBounds = radius > 0;
    }
}
