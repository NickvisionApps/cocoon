#include "generated/scroll_view.h"
#include "internal.h"

namespace cocoon
{
    ScrollView::ScrollView() : ScrollView(Adopt{cocoon::internal::retain([[NSScrollView alloc] init])})
    {
    }

    ScrollView::ScrollView(const Rect& frame_rect) : ScrollView(Adopt{cocoon::internal::retain([[::NSScrollView alloc] initWithFrame:cocoon::internal::to(frame_rect)])})
    {
    }

    ScrollView::ScrollView(std::nullptr_t) : View(nullptr)
    {
    }

    ScrollView::ScrollView(Adopt adopt) : View(adopt)
    {
    }

    void ScrollView::add_floating_subview(const View& view, EventGestureAxis axis) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) addFloatingSubview:cocoon::internal::native<::NSView>(view) forAxis:static_cast<::NSEventGestureAxis>(axis)];
    }

    Size ScrollView::content_size_for_frame_size(const Size& f_size, const std::string& horizontal_scroller_class, const std::string& vertical_scroller_class, BorderType type, ControlSize control_size, ScrollerStyle scroller_style)
    {
        return cocoon::internal::from([::NSScrollView contentSizeForFrameSize:cocoon::internal::to(f_size) horizontalScrollerClass:NSClassFromString(cocoon::internal::to(horizontal_scroller_class)) verticalScrollerClass:NSClassFromString(cocoon::internal::to(vertical_scroller_class)) borderType:static_cast<::NSBorderType>(type) controlSize:static_cast<::NSControlSize>(control_size) scrollerStyle:static_cast<::NSScrollerStyle>(scroller_style)]);
    }

    void ScrollView::flash_scrollers() const
    {
        [cocoon::internal::ns<::NSScrollView>(this) flashScrollers];
    }

    Size ScrollView::frame_size_for_content_size(const Size& c_size, const std::string& horizontal_scroller_class, const std::string& vertical_scroller_class, BorderType type, ControlSize control_size, ScrollerStyle scroller_style)
    {
        return cocoon::internal::from([::NSScrollView frameSizeForContentSize:cocoon::internal::to(c_size) horizontalScrollerClass:NSClassFromString(cocoon::internal::to(horizontal_scroller_class)) verticalScrollerClass:NSClassFromString(cocoon::internal::to(vertical_scroller_class)) borderType:static_cast<::NSBorderType>(type) controlSize:static_cast<::NSControlSize>(control_size) scrollerStyle:static_cast<::NSScrollerStyle>(scroller_style)]);
    }

    void ScrollView::magnify_to_fit_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) magnifyToFitRect:cocoon::internal::to(rect)];
    }

    void ScrollView::reflect_scrolled_clip_view(const ClipView& c_view) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) reflectScrolledClipView:cocoon::internal::native<::NSClipView>(c_view)];
    }

    void ScrollView::scroll_wheel(const Event& event) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) scrollWheel:cocoon::internal::native<::NSEvent>(event)];
    }

    void ScrollView::set_magnification(double magnification, const Point& point) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setMagnification:static_cast<::CGFloat>(magnification) centeredAtPoint:cocoon::internal::to(point)];
    }

    void ScrollView::tile() const
    {
        [cocoon::internal::ns<::NSScrollView>(this) tile];
    }

    bool ScrollView::allows_magnification() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrollView>(this) allowsMagnification]);
    }

    void ScrollView::set_allows_magnification(bool value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setAllowsMagnification:static_cast<::BOOL>(value)];
    }

    bool ScrollView::autohides_scrollers() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrollView>(this) autohidesScrollers]);
    }

    void ScrollView::set_autohides_scrollers(bool value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setAutohidesScrollers:static_cast<::BOOL>(value)];
    }

    bool ScrollView::automatically_adjusts_content_insets() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrollView>(this) automaticallyAdjustsContentInsets]);
    }

    void ScrollView::set_automatically_adjusts_content_insets(bool value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setAutomaticallyAdjustsContentInsets:static_cast<::BOOL>(value)];
    }

    Color ScrollView::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSScrollView>(this) backgroundColor]);
    }

    void ScrollView::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    BorderType ScrollView::border_type() const
    {
        return static_cast<BorderType>([cocoon::internal::ns<::NSScrollView>(this) borderType]);
    }

    void ScrollView::set_border_type(BorderType value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setBorderType:static_cast<::NSBorderType>(value)];
    }

    Insets ScrollView::content_insets() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScrollView>(this) contentInsets]);
    }

    void ScrollView::set_content_insets(const Insets& value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setContentInsets:cocoon::internal::to(value)];
    }

    Size ScrollView::content_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScrollView>(this) contentSize]);
    }

    ClipView ScrollView::content_view() const
    {
        return cocoon::internal::wrap<ClipView>([cocoon::internal::ns<::NSScrollView>(this) contentView]);
    }

    void ScrollView::set_content_view(const ClipView& value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setContentView:cocoon::internal::native<::NSClipView>(value)];
    }

    Cursor ScrollView::document_cursor() const
    {
        return cocoon::internal::wrap<Cursor>([cocoon::internal::ns<::NSScrollView>(this) documentCursor]);
    }

    void ScrollView::set_document_cursor(const Cursor& value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setDocumentCursor:cocoon::internal::native<::NSCursor>(value)];
    }

    View ScrollView::document_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSScrollView>(this) documentView]);
    }

    void ScrollView::set_document_view(const View& value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setDocumentView:cocoon::internal::native<::NSView>(value)];
    }

    Rect ScrollView::document_visible_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScrollView>(this) documentVisibleRect]);
    }

    bool ScrollView::draws_background() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrollView>(this) drawsBackground]);
    }

    void ScrollView::set_draws_background(bool value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setDrawsBackground:static_cast<::BOOL>(value)];
    }

    ScrollViewFindBarPosition ScrollView::find_bar_position() const
    {
        return static_cast<ScrollViewFindBarPosition>([cocoon::internal::ns<::NSScrollView>(this) findBarPosition]);
    }

    void ScrollView::set_find_bar_position(ScrollViewFindBarPosition value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setFindBarPosition:static_cast<::NSScrollViewFindBarPosition>(value)];
    }

    bool ScrollView::has_horizontal_ruler() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrollView>(this) hasHorizontalRuler]);
    }

    void ScrollView::set_has_horizontal_ruler(bool value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setHasHorizontalRuler:static_cast<::BOOL>(value)];
    }

    bool ScrollView::has_horizontal_scroller() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrollView>(this) hasHorizontalScroller]);
    }

    void ScrollView::set_has_horizontal_scroller(bool value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setHasHorizontalScroller:static_cast<::BOOL>(value)];
    }

    bool ScrollView::has_vertical_ruler() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrollView>(this) hasVerticalRuler]);
    }

    void ScrollView::set_has_vertical_ruler(bool value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setHasVerticalRuler:static_cast<::BOOL>(value)];
    }

    bool ScrollView::has_vertical_scroller() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrollView>(this) hasVerticalScroller]);
    }

    void ScrollView::set_has_vertical_scroller(bool value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setHasVerticalScroller:static_cast<::BOOL>(value)];
    }

    double ScrollView::horizontal_line_scroll() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSScrollView>(this) horizontalLineScroll]);
    }

    void ScrollView::set_horizontal_line_scroll(double value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setHorizontalLineScroll:static_cast<::CGFloat>(value)];
    }

    double ScrollView::horizontal_page_scroll() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSScrollView>(this) horizontalPageScroll]);
    }

    void ScrollView::set_horizontal_page_scroll(double value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setHorizontalPageScroll:static_cast<::CGFloat>(value)];
    }

    RulerView ScrollView::horizontal_ruler_view() const
    {
        return cocoon::internal::wrap<RulerView>([cocoon::internal::ns<::NSScrollView>(this) horizontalRulerView]);
    }

    void ScrollView::set_horizontal_ruler_view(const RulerView& value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setHorizontalRulerView:cocoon::internal::native<::NSRulerView>(value)];
    }

    ScrollElasticity ScrollView::horizontal_scroll_elasticity() const
    {
        return static_cast<ScrollElasticity>([cocoon::internal::ns<::NSScrollView>(this) horizontalScrollElasticity]);
    }

    void ScrollView::set_horizontal_scroll_elasticity(ScrollElasticity value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setHorizontalScrollElasticity:static_cast<::NSScrollElasticity>(value)];
    }

    Scroller ScrollView::horizontal_scroller() const
    {
        return cocoon::internal::wrap<Scroller>([cocoon::internal::ns<::NSScrollView>(this) horizontalScroller]);
    }

    void ScrollView::set_horizontal_scroller(const Scroller& value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setHorizontalScroller:cocoon::internal::native<::NSScroller>(value)];
    }

    double ScrollView::line_scroll() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSScrollView>(this) lineScroll]);
    }

    void ScrollView::set_line_scroll(double value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setLineScroll:static_cast<::CGFloat>(value)];
    }

    double ScrollView::magnification() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSScrollView>(this) magnification]);
    }

    void ScrollView::set_magnification(double value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setMagnification:static_cast<::CGFloat>(value)];
    }

    double ScrollView::max_magnification() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSScrollView>(this) maxMagnification]);
    }

    void ScrollView::set_max_magnification(double value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setMaxMagnification:static_cast<::CGFloat>(value)];
    }

#ifdef COCOON_MACOS_27
    std::int64_t ScrollView::maximum_number_of_touches_for_scrolling() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<std::int64_t>([cocoon::internal::ns<::NSScrollView>(this) maximumNumberOfTouchesForScrolling]);
        }
        return {};
    }

#endif
#ifdef COCOON_MACOS_27
    void ScrollView::set_maximum_number_of_touches_for_scrolling(std::int64_t value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSScrollView>(this) setMaximumNumberOfTouchesForScrolling:static_cast<::NSInteger>(value)];
        }
    }

#endif
    double ScrollView::min_magnification() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSScrollView>(this) minMagnification]);
    }

    void ScrollView::set_min_magnification(double value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setMinMagnification:static_cast<::CGFloat>(value)];
    }

#ifdef COCOON_MACOS_27
    std::int64_t ScrollView::minimum_number_of_touches_for_scrolling() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<std::int64_t>([cocoon::internal::ns<::NSScrollView>(this) minimumNumberOfTouchesForScrolling]);
        }
        return {};
    }

#endif
#ifdef COCOON_MACOS_27
    void ScrollView::set_minimum_number_of_touches_for_scrolling(std::int64_t value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSScrollView>(this) setMinimumNumberOfTouchesForScrolling:static_cast<::NSInteger>(value)];
        }
    }

#endif
    double ScrollView::page_scroll() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSScrollView>(this) pageScroll]);
    }

    void ScrollView::set_page_scroll(double value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setPageScroll:static_cast<::CGFloat>(value)];
    }

#ifdef COCOON_MACOS_27
    RefreshController ScrollView::refresh_controller() const
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::wrap<RefreshController>([cocoon::internal::ns<::NSScrollView>(this) refreshController]);
        }
        return RefreshController(nullptr);
    }

#endif
#ifdef COCOON_MACOS_27
    void ScrollView::set_refresh_controller(const RefreshController& value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSScrollView>(this) setRefreshController:cocoon::internal::native<::NSRefreshController>(value)];
        }
    }

#endif
    std::string ScrollView::ruler_view_class()
    {
        return cocoon::internal::from(NSStringFromClass([::NSScrollView rulerViewClass]));
    }

    void ScrollView::set_ruler_view_class(const std::string& value)
    {
        [::NSScrollView setRulerViewClass:NSClassFromString(cocoon::internal::to(value))];
    }

    bool ScrollView::rulers_visible() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrollView>(this) rulersVisible]);
    }

    void ScrollView::set_rulers_visible(bool value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setRulersVisible:static_cast<::BOOL>(value)];
    }

#ifdef COCOON_MACOS_27
    GestureRecognizer ScrollView::scroll_gesture_for_relationships() const
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::wrap<GestureRecognizer>([cocoon::internal::ns<::NSScrollView>(this) scrollGestureForRelationships]);
        }
        return GestureRecognizer(nullptr);
    }

#endif
    Insets ScrollView::scroller_insets() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScrollView>(this) scrollerInsets]);
    }

    void ScrollView::set_scroller_insets(const Insets& value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setScrollerInsets:cocoon::internal::to(value)];
    }

    ScrollerKnobStyle ScrollView::scroller_knob_style() const
    {
        return static_cast<ScrollerKnobStyle>([cocoon::internal::ns<::NSScrollView>(this) scrollerKnobStyle]);
    }

    void ScrollView::set_scroller_knob_style(ScrollerKnobStyle value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setScrollerKnobStyle:static_cast<::NSScrollerKnobStyle>(value)];
    }

    ScrollerStyle ScrollView::scroller_style() const
    {
        return static_cast<ScrollerStyle>([cocoon::internal::ns<::NSScrollView>(this) scrollerStyle]);
    }

    void ScrollView::set_scroller_style(ScrollerStyle value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setScrollerStyle:static_cast<::NSScrollerStyle>(value)];
    }

    bool ScrollView::scrolls_dynamically() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrollView>(this) scrollsDynamically]);
    }

    void ScrollView::set_scrolls_dynamically(bool value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setScrollsDynamically:static_cast<::BOOL>(value)];
    }

#ifdef COCOON_MACOS_27
    bool ScrollView::is_touch_scrolling_enabled() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<bool>([cocoon::internal::ns<::NSScrollView>(this) isTouchScrollingEnabled]);
        }
        return {};
    }

#endif
#ifdef COCOON_MACOS_27
    void ScrollView::set_touch_scrolling_enabled(bool value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSScrollView>(this) setTouchScrollingEnabled:static_cast<::BOOL>(value)];
        }
    }

#endif
    bool ScrollView::uses_predominant_axis_scrolling() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrollView>(this) usesPredominantAxisScrolling]);
    }

    void ScrollView::set_uses_predominant_axis_scrolling(bool value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setUsesPredominantAxisScrolling:static_cast<::BOOL>(value)];
    }

    double ScrollView::vertical_line_scroll() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSScrollView>(this) verticalLineScroll]);
    }

    void ScrollView::set_vertical_line_scroll(double value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setVerticalLineScroll:static_cast<::CGFloat>(value)];
    }

    double ScrollView::vertical_page_scroll() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSScrollView>(this) verticalPageScroll]);
    }

    void ScrollView::set_vertical_page_scroll(double value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setVerticalPageScroll:static_cast<::CGFloat>(value)];
    }

    RulerView ScrollView::vertical_ruler_view() const
    {
        return cocoon::internal::wrap<RulerView>([cocoon::internal::ns<::NSScrollView>(this) verticalRulerView]);
    }

    void ScrollView::set_vertical_ruler_view(const RulerView& value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setVerticalRulerView:cocoon::internal::native<::NSRulerView>(value)];
    }

    ScrollElasticity ScrollView::vertical_scroll_elasticity() const
    {
        return static_cast<ScrollElasticity>([cocoon::internal::ns<::NSScrollView>(this) verticalScrollElasticity]);
    }

    void ScrollView::set_vertical_scroll_elasticity(ScrollElasticity value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setVerticalScrollElasticity:static_cast<::NSScrollElasticity>(value)];
    }

    Scroller ScrollView::vertical_scroller() const
    {
        return cocoon::internal::wrap<Scroller>([cocoon::internal::ns<::NSScrollView>(this) verticalScroller]);
    }

    void ScrollView::set_vertical_scroller(const Scroller& value) const
    {
        [cocoon::internal::ns<::NSScrollView>(this) setVerticalScroller:cocoon::internal::native<::NSScroller>(value)];
    }
}
