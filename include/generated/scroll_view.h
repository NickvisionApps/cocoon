#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class ClipView;
    class Color;
    class Cursor;
    class Event;
    class RulerView;
    class Scroller;
    class View;

    /**
     * @brief A scrolling container (NSScrollView).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * cocoon::ScrollView scroll;
     * cocoon::VStack content;
     * scroll.set_has_vertical_scroller(true);
     * scroll.set_document_view(content);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScrollView scroll_view{};
     * scroll_view.set_allows_magnification(true);
     * auto allows_magnification = scroll_view.allows_magnification();
     * scroll_view.set_autohides_scrollers(true);
     * auto autohides_scrollers = scroll_view.autohides_scrollers();
     * scroll_view.set_automatically_adjusts_content_insets(true);
     * auto automatically_adjusts_content_insets = scroll_view.automatically_adjusts_content_insets();
     * scroll_view.add_floating_subview(cocoon::View(), cocoon::EventGestureAxis::None);
     * scroll_view.flash_scrollers();
     * scroll_view.magnify_to_fit_rect({{0, 0}, {100, 100}});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsscrollview
     */
    class ScrollView : public View
    {
    public:
        /// @brief Creates a new `NSScrollView` instance and returns a handle to it.
        explicit ScrollView();
        /// @brief Creates a new `NSScrollView` instance and returns a handle to it.
        explicit ScrollView(const Rect& frame_rect);
        /// @brief Creates a null handle that refers to no native object.
        ScrollView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScrollView(Adopt adopt);
        using Responder::scroll_wheel;
        using View::reflect_scrolled_clip_view;
        using View::set_background_color;
        /**
         * @brief Calls `-[NSScrollView addFloatingSubview:forAxis:]`.
         * @details Some subviews of the document view do not scroll like the rest of the document. Instead these views appear to float over the document (see NSTableView floating group rows). The following API makes it easier to work with these types of floating views. Note: You are responsible for keeping track of the floating views and removing them via -removeFromSuperview when they should no longer float. A view may only float on one axis at a time.
         * @param view Argument converted to the Objective-C parameter of the same role.
         * @param axis Argument converted to the Objective-C parameter of the same role.
         */
        void add_floating_subview(const View& view, EventGestureAxis axis) const;
        /**
         * @brief Calls `+[NSScrollView contentSizeForFrameSize:horizontalScrollerClass:verticalScrollerClass:borderType:controlSize:scrollerStyle:]`.
         * @details Returns the contentView frame size that yields the specified NSScrollView frame size. This method should be used in preference to the deprecated +contentSizeForFrameSize:hasHorizontalScroller:hasVerticalScroller:borderType: method, which makes assumptions about the scrollers' classes, control size, and style. The "horizontalScrollerClass" parameter should specify the class of horizontal scroller to use if the NSScrollView will have a horizontal scroller, or Nil if it will not. Likewise for the "verticalScrollerClass" parameter.
         * @param f_size Argument converted to the Objective-C parameter of the same role.
         * @param horizontal_scroller_class Argument converted to the Objective-C parameter of the same role.
         * @param vertical_scroller_class Argument converted to the Objective-C parameter of the same role.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param control_size Argument converted to the Objective-C parameter of the same role.
         * @param scroller_style Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Size content_size_for_frame_size(const Size& f_size, const std::string& horizontal_scroller_class, const std::string& vertical_scroller_class, BorderType type, ControlSize control_size, ScrollerStyle scroller_style);
        /**
         * @brief Calls `-[NSScrollView flashScrollers]`.
         * @details Applicable only to NSScrollViews that use Overlay scrollers. This method can be invoked to cause the Overlay scroller knobs to be momentarily shown.
         */
        void flash_scrollers() const;
        /**
         * @brief Calls `+[NSScrollView frameSizeForContentSize:horizontalScrollerClass:verticalScrollerClass:borderType:controlSize:scrollerStyle:]`.
         * @details Returns the NSScrollView frame size that yields the specified contentView frame size. This method should be used in preference to the deprecated +frameSizeForContentSize:hasHorizontalScroller:hasVerticalScroller:borderType:, which makes assumptions about the scrollers' classes, control size, and style. The "horizontalScrollerClass" parameter should specify the class of horizontal scroller to use if the NSScrollView will have a horizontal scroller, or Nil if it will not. Likewise for the "verticalScrollerClass" parameter.
         * @param c_size Argument converted to the Objective-C parameter of the same role.
         * @param horizontal_scroller_class Argument converted to the Objective-C parameter of the same role.
         * @param vertical_scroller_class Argument converted to the Objective-C parameter of the same role.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param control_size Argument converted to the Objective-C parameter of the same role.
         * @param scroller_style Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Size frame_size_for_content_size(const Size& c_size, const std::string& horizontal_scroller_class, const std::string& vertical_scroller_class, BorderType type, ControlSize control_size, ScrollerStyle scroller_style);
        /**
         * @brief Calls `-[NSScrollView magnifyToFitRect:]`.
         * @details Magnify content view proportionally such that the entire rect (in content view space) fits centered in the scroll view. The resulting magnification value is clipped to the minMagnification and maxMagnification values. To animate the magnification, use the object's animator.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         */
        void magnify_to_fit_rect(const Rect& rect) const;
        /**
         * @brief Calls `-[NSScrollView reflectScrolledClipView:]`.
         * @param c_view Argument converted to the Objective-C parameter of the same role.
         */
        void reflect_scrolled_clip_view(const ClipView& c_view) const;
        /**
         * @brief Calls `-[NSScrollView scrollWheel:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void scroll_wheel(const Event& event) const;
        /**
         * @brief Calls `-[NSScrollView setMagnification:centeredAtPoint:]`.
         * @details Scale the content view such that the passed in point (in content view space) remains at the same screen location once the scaling is completed. The resulting magnification value is clipped to the minMagnification and maxMagnification values. To animate the magnification, use the object's animator.
         * @param magnification Argument converted to the Objective-C parameter of the same role.
         * @param point Argument converted to the Objective-C parameter of the same role.
         */
        void set_magnification(double magnification, const Point& point) const;
        /**
         * @brief Calls `-[NSScrollView tile]`.
         */
        void tile() const;
        /**
         * @brief Returns the `allowsMagnification` property of `NSScrollView`.
         * @details Allow the user to magnify the scrollview. Note: this does not prevent the developer from manually adjusting the magnification value. If magnification exceeds either the maximum or minimum limits for magnification, and allowsMagnification is YES, the scroll view temporarily animates the content magnification just past those limits before returning to them. The default value is NO.
         * @return The converted Objective-C result.
         */
        bool allows_magnification() const;
        /**
         * @brief Sets the `allowsMagnification` property of `NSScrollView`.
         * @details Allow the user to magnify the scrollview. Note: this does not prevent the developer from manually adjusting the magnification value. If magnification exceeds either the maximum or minimum limits for magnification, and allowsMagnification is YES, the scroll view temporarily animates the content magnification just past those limits before returning to them. The default value is NO.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_magnification(bool value) const;
        /**
         * @brief Returns the `autohidesScrollers` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        bool autohides_scrollers() const;
        /**
         * @brief Sets the `autohidesScrollers` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_autohides_scrollers(bool value) const;
        /**
         * @brief Returns the `automaticallyAdjustsContentInsets` property of `NSScrollView`.
         * @details Automatically sets the scroll view's contentInsets property to account for any overlapping title bar. Defaults to YES.
         * @return The converted Objective-C result.
         */
        bool automatically_adjusts_content_insets() const;
        /**
         * @brief Sets the `automaticallyAdjustsContentInsets` property of `NSScrollView`.
         * @details Automatically sets the scroll view's contentInsets property to account for any overlapping title bar. Defaults to YES.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatically_adjusts_content_insets(bool value) const;
        /**
         * @brief Returns the `backgroundColor` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        Color background_color() const;
        /**
         * @brief Sets the `backgroundColor` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_background_color(const Color& value) const;
        /**
         * @brief Returns the `borderType` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        BorderType border_type() const;
        /**
         * @brief Sets the `borderType` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_border_type(BorderType value) const;
        /**
         * @brief Returns the `contentInsets` property of `NSScrollView`.
         * @details The distance that the sub views are inset from the enclosing scroll view during tiling. When contentInset equal to NSEdgeInsetsZero, traditional tiling is performed. That is, the rulers, headers, etc... are tiled with the contentView frame filling the remaining space. When contentInset is not equal to NSEdgeInsetsZero, the rulers, header, etc... are inset as specified. The contentView is is placed underneath these sibling views and is only inset by scroll view border and non-overlay scrollers.
         * @return The converted Objective-C result.
         */
        Insets content_insets() const;
        /**
         * @brief Sets the `contentInsets` property of `NSScrollView`.
         * @details The distance that the sub views are inset from the enclosing scroll view during tiling. When contentInset equal to NSEdgeInsetsZero, traditional tiling is performed. That is, the rulers, headers, etc... are tiled with the contentView frame filling the remaining space. When contentInset is not equal to NSEdgeInsetsZero, the rulers, header, etc... are inset as specified. The contentView is is placed underneath these sibling views and is only inset by scroll view border and non-overlay scrollers.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_content_insets(const Insets& value) const;
        /**
         * @brief Returns the `contentSize` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        Size content_size() const;
        /**
         * @brief Returns the `contentView` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        ClipView content_view() const;
        /**
         * @brief Sets the `contentView` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_content_view(const ClipView& value) const;
        /**
         * @brief Returns the `documentCursor` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        Cursor document_cursor() const;
        /**
         * @brief Sets the `documentCursor` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_document_cursor(const Cursor& value) const;
        /**
         * @brief Returns the `documentView` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        View document_view() const;
        /**
         * @brief Sets the `documentView` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_document_view(const View& value) const;
        /**
         * @brief Returns the `documentVisibleRect` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        Rect document_visible_rect() const;
        /**
         * @brief Returns the `drawsBackground` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        bool draws_background() const;
        /**
         * @brief Sets the `drawsBackground` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_draws_background(bool value) const;
        /**
         * @brief Returns the `findBarPosition` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        ScrollViewFindBarPosition find_bar_position() const;
        /**
         * @brief Sets the `findBarPosition` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_find_bar_position(ScrollViewFindBarPosition value) const;
        /**
         * @brief Returns the `hasHorizontalRuler` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        bool has_horizontal_ruler() const;
        /**
         * @brief Sets the `hasHorizontalRuler` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_has_horizontal_ruler(bool value) const;
        /**
         * @brief Returns the `hasHorizontalScroller` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        bool has_horizontal_scroller() const;
        /**
         * @brief Sets the `hasHorizontalScroller` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_has_horizontal_scroller(bool value) const;
        /**
         * @brief Returns the `hasVerticalRuler` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        bool has_vertical_ruler() const;
        /**
         * @brief Sets the `hasVerticalRuler` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_has_vertical_ruler(bool value) const;
        /**
         * @brief Returns the `hasVerticalScroller` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        bool has_vertical_scroller() const;
        /**
         * @brief Sets the `hasVerticalScroller` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_has_vertical_scroller(bool value) const;
        /**
         * @brief Returns the `horizontalLineScroll` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        double horizontal_line_scroll() const;
        /**
         * @brief Sets the `horizontalLineScroll` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_horizontal_line_scroll(double value) const;
        /**
         * @brief Returns the `horizontalPageScroll` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        double horizontal_page_scroll() const;
        /**
         * @brief Sets the `horizontalPageScroll` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_horizontal_page_scroll(double value) const;
        /**
         * @brief Returns the `horizontalRulerView` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        RulerView horizontal_ruler_view() const;
        /**
         * @brief Sets the `horizontalRulerView` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_horizontal_ruler_view(const RulerView& value) const;
        /**
         * @brief Returns the `horizontalScrollElasticity` property of `NSScrollView`.
         * @details NSScrollView can scroll its contents past its bounds to achieve an elastic effect. When set to NSScrollElasticityAutomatic, scrolling the horizontal axis beyond its document bounds only occurs if the document width is greater than the view width or, the vertical scroller is hidden and the horizontal scroller is visible. The default value is NSScrollElasticityAutomatic.
         * @return The converted Objective-C result.
         */
        ScrollElasticity horizontal_scroll_elasticity() const;
        /**
         * @brief Sets the `horizontalScrollElasticity` property of `NSScrollView`.
         * @details NSScrollView can scroll its contents past its bounds to achieve an elastic effect. When set to NSScrollElasticityAutomatic, scrolling the horizontal axis beyond its document bounds only occurs if the document width is greater than the view width or, the vertical scroller is hidden and the horizontal scroller is visible. The default value is NSScrollElasticityAutomatic.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_horizontal_scroll_elasticity(ScrollElasticity value) const;
        /**
         * @brief Returns the `horizontalScroller` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        Scroller horizontal_scroller() const;
        /**
         * @brief Sets the `horizontalScroller` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_horizontal_scroller(const Scroller& value) const;
        /**
         * @brief Returns the `lineScroll` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        double line_scroll() const;
        /**
         * @brief Sets the `lineScroll` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_line_scroll(double value) const;
        /**
         * @brief Returns the `magnification` property of `NSScrollView`.
         * @details This value determines how much the content is currently scaled. To animate the magnification, use the object's animator. The default value is 1.0
         * @return The converted Objective-C result.
         */
        double magnification() const;
        /**
         * @brief Sets the `magnification` property of `NSScrollView`.
         * @details This value determines how much the content is currently scaled. To animate the magnification, use the object's animator. The default value is 1.0
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_magnification(double value) const;
        /**
         * @brief Returns the `maxMagnification` property of `NSScrollView`.
         * @details This value determines how large the content can be magnified. It must be greater than or equal to the minimum magnification. The default value is 4.0.
         * @return The converted Objective-C result.
         */
        double max_magnification() const;
        /**
         * @brief Sets the `maxMagnification` property of `NSScrollView`.
         * @details This value determines how large the content can be magnified. It must be greater than or equal to the minimum magnification. The default value is 4.0.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_max_magnification(double value) const;
        /**
         * @brief Returns the `minMagnification` property of `NSScrollView`.
         * @details This value determines how small the content can be magnified. The default value is 0.25.
         * @return The converted Objective-C result.
         */
        double min_magnification() const;
        /**
         * @brief Sets the `minMagnification` property of `NSScrollView`.
         * @details This value determines how small the content can be magnified. The default value is 0.25.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_min_magnification(double value) const;
        /**
         * @brief Returns the `pageScroll` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        double page_scroll() const;
        /**
         * @brief Sets the `pageScroll` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_page_scroll(double value) const;
        /**
         * @brief Returns the `rulerViewClass` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        static std::string ruler_view_class();
        /**
         * @brief Sets the `rulerViewClass` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        static void set_ruler_view_class(const std::string& value);
        /**
         * @brief Returns the `rulersVisible` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        bool rulers_visible() const;
        /**
         * @brief Sets the `rulersVisible` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_rulers_visible(bool value) const;
        /**
         * @brief Returns the `scrollerInsets` property of `NSScrollView`.
         * @details The distance the scrollers are inset from the edge of the scroll view.
         * @return The converted Objective-C result.
         */
        Insets scroller_insets() const;
        /**
         * @brief Sets the `scrollerInsets` property of `NSScrollView`.
         * @details The distance the scrollers are inset from the edge of the scroll view.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_scroller_insets(const Insets& value) const;
        /**
         * @brief Returns the `scrollerKnobStyle` property of `NSScrollView`.
         * @details Applicable only to ScrolViews that use Overlay scrollers. Setting an NSScrollView's scrollerKnobStyle sets the knobStyle of its horizontalScroller and verticalScroller to match the new value. If the NSScrollView subsequently creates or is assigned a new horizontalScroller or verticalScroller, they will at that time be assigned the same knobStyle that was given to the NSScrollView.
         * @return The converted Objective-C result.
         */
        ScrollerKnobStyle scroller_knob_style() const;
        /**
         * @brief Sets the `scrollerKnobStyle` property of `NSScrollView`.
         * @details Applicable only to ScrolViews that use Overlay scrollers. Setting an NSScrollView's scrollerKnobStyle sets the knobStyle of its horizontalScroller and verticalScroller to match the new value. If the NSScrollView subsequently creates or is assigned a new horizontalScroller or verticalScroller, they will at that time be assigned the same knobStyle that was given to the NSScrollView.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_scroller_knob_style(ScrollerKnobStyle value) const;
        /**
         * @brief Returns the `scrollerStyle` property of `NSScrollView`.
         * @details An NSScrollView's scrollerStyle determines the style of scrollers that it will use. AppKit sets this property automatically at runtime, based on the user's "Show scroll bars" setting and (if relevant) the set of connected pointing devices and their configured scroll capabilities, as determined by [NSScroller preferredScrollerStyle]. Setting an NSScrollView's scrollerStyle sets the scrollerStyle of its horizontalScroller and verticalScroller to match the new value. If the NSScrollView subsequently creates or is assigned a new horizontalScroller or verticalScroller, they will at that time be assigned the same scrollerStyle that was given to the NSScrollView.
         * @return The converted Objective-C result.
         */
        ScrollerStyle scroller_style() const;
        /**
         * @brief Sets the `scrollerStyle` property of `NSScrollView`.
         * @details An NSScrollView's scrollerStyle determines the style of scrollers that it will use. AppKit sets this property automatically at runtime, based on the user's "Show scroll bars" setting and (if relevant) the set of connected pointing devices and their configured scroll capabilities, as determined by [NSScroller preferredScrollerStyle]. Setting an NSScrollView's scrollerStyle sets the scrollerStyle of its horizontalScroller and verticalScroller to match the new value. If the NSScrollView subsequently creates or is assigned a new horizontalScroller or verticalScroller, they will at that time be assigned the same scrollerStyle that was given to the NSScrollView.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_scroller_style(ScrollerStyle value) const;
        /**
         * @brief Returns the `scrollsDynamically` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        bool scrolls_dynamically() const;
        /**
         * @brief Sets the `scrollsDynamically` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_scrolls_dynamically(bool value) const;
        /**
         * @brief Returns the `usesPredominantAxisScrolling` property of `NSScrollView`.
         * @details Some content is scrollable in both the horizontal and vertical axes, but is predominantly scrolled one axis at a time. Other content (such as a drawing canvas) should scroll freely in both axes. Traditionally this is not an issue with scroll wheels since they can only scroll in one direction at a time. With scroll balls and touch surfaces, it becomes more difficult to determine the user's intention. This property helps NSScrollView determine the user's intention by specifying the type of scrolling content. When set to YES, NSScrollView will only scroll in the predominate direction the user is scrolling. The default value is YES for apps build on 10.7; NO otherwise.
         * @return The converted Objective-C result.
         */
        bool uses_predominant_axis_scrolling() const;
        /**
         * @brief Sets the `usesPredominantAxisScrolling` property of `NSScrollView`.
         * @details Some content is scrollable in both the horizontal and vertical axes, but is predominantly scrolled one axis at a time. Other content (such as a drawing canvas) should scroll freely in both axes. Traditionally this is not an issue with scroll wheels since they can only scroll in one direction at a time. With scroll balls and touch surfaces, it becomes more difficult to determine the user's intention. This property helps NSScrollView determine the user's intention by specifying the type of scrolling content. When set to YES, NSScrollView will only scroll in the predominate direction the user is scrolling. The default value is YES for apps build on 10.7; NO otherwise.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_predominant_axis_scrolling(bool value) const;
        /**
         * @brief Returns the `verticalLineScroll` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        double vertical_line_scroll() const;
        /**
         * @brief Sets the `verticalLineScroll` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_vertical_line_scroll(double value) const;
        /**
         * @brief Returns the `verticalPageScroll` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        double vertical_page_scroll() const;
        /**
         * @brief Sets the `verticalPageScroll` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_vertical_page_scroll(double value) const;
        /**
         * @brief Returns the `verticalRulerView` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        RulerView vertical_ruler_view() const;
        /**
         * @brief Sets the `verticalRulerView` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_vertical_ruler_view(const RulerView& value) const;
        /**
         * @brief Returns the `verticalScrollElasticity` property of `NSScrollView`.
         * @details NSScrollView can scroll its contents past its bounds to achieve an elastic effect. When set to NSScrollElasticityAuto, scrolling the vertical axis beyond its docment bounds occurs if any of the following are true: visible vertical scroller, content height greater than view height, horizontal scroller hidden
         * @return The converted Objective-C result.
         */
        ScrollElasticity vertical_scroll_elasticity() const;
        /**
         * @brief Sets the `verticalScrollElasticity` property of `NSScrollView`.
         * @details NSScrollView can scroll its contents past its bounds to achieve an elastic effect. When set to NSScrollElasticityAuto, scrolling the vertical axis beyond its docment bounds occurs if any of the following are true: visible vertical scroller, content height greater than view height, horizontal scroller hidden
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_vertical_scroll_elasticity(ScrollElasticity value) const;
        /**
         * @brief Returns the `verticalScroller` property of `NSScrollView`.
         * @return The converted Objective-C result.
         */
        Scroller vertical_scroller() const;
        /**
         * @brief Sets the `verticalScroller` property of `NSScrollView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_vertical_scroller(const Scroller& value) const;
    };
}
