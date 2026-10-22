#pragma once

#include "generated/availability.h"
#include "generated/control.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Event;

    /**
     * @brief C++ handle for the Objective-C class `NSScroller` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Scroller scroller;
     * scroller.set_control_size(cocoon::ControlSize::Regular);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Scroller scroller{};
     * scroller.set_control_size(cocoon::ControlSize::Regular);
     * auto control_size = scroller.control_size();
     * scroller.set_knob_style(cocoon::ScrollerKnobStyle::Default);
     * auto knob_style = scroller.knob_style();
     * scroller.set_scroller_style(cocoon::ScrollerStyle::Legacy);
     * auto scroller_style = scroller.scroller_style();
     * scroller.check_space_for_parts();
     * scroller.draw_knob();
     * scroller.draw_knob_slot_in_rect({{0, 0}, {100, 100}}, true);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsscroller
     */
    class Scroller : public Control
    {
    public:
        /// @brief Creates a new `NSScroller` instance and returns a handle to it.
        explicit Scroller();
        /// @brief Creates a null handle that refers to no native object.
        Scroller(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Scroller(Adopt adopt);
        using Control::control_size;
        using Control::set_control_size;
        /**
         * @brief Calls `-[NSScroller checkSpaceForParts]`.
         */
        void check_space_for_parts() const;
        /**
         * @brief Calls `-[NSScroller drawKnob]`.
         */
        void draw_knob() const;
        /**
         * @brief Calls `-[NSScroller drawKnobSlotInRect:highlight:]`.
         * @param slot_rect Argument converted to the Objective-C parameter of the same role.
         * @param flag Argument converted to the Objective-C parameter of the same role.
         */
        void draw_knob_slot_in_rect(const Rect& slot_rect, bool flag) const;
        /**
         * @brief Calls `-[NSScroller rectForPart:]`.
         * @param part_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect rect_for_part(ScrollerPart part_code) const;
        /**
         * @brief Calls `+[NSScroller scrollerWidthForControlSize:scrollerStyle:]`.
         * @details Returns the width for scrollers of the receiving class, given the specified controlSize and scrollerStyle. This method should be used in preference to +scrollerWidthForControlSize:, which assumes a scrollerStyle of NSScrollerStyleLegacy, and +scrollerWidth:, which assumes that and a controlSize of NSRegularControlSize.
         * @param control_size Argument converted to the Objective-C parameter of the same role.
         * @param scroller_style Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static double scroller_width_for_control_size(ControlSize control_size, ScrollerStyle scroller_style);
        /**
         * @brief Calls `-[NSScroller setKnobProportion:]`.
         * @param proportion Argument converted to the Objective-C parameter of the same role.
         */
        void set_knob_proportion(double proportion) const;
        /**
         * @brief Calls `-[NSScroller testPart:]`.
         * @param point Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        ScrollerPart test_part(const Point& point) const;
        /**
         * @brief Calls `-[NSScroller trackKnob:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void track_knob(const Event& event) const;
        /**
         * @brief Returns the `compatibleWithOverlayScrollers` property of `NSScroller`.
         * @details A subclass of NSScroller can override this method to certify that its customizations are compatible with 10.7's new iOS-like "Overlay" scroller style and behaviors. By default, AppKit assumes that instances of NSScroller subclasses may not be compatible with the way that Overlay scrollers are presented, and falls back to the more compatible 10.6-like scroller metrics and behavior for subclassed scrollers. The recommended override technique for a subclass "MyCustomScroller" that wants to declare itself compatible with Overlay scroller presentation is: \@implementation MyCustomScroller ... + (BOOL)isCompatibleWithOverlayScrollers { return self == [MyCustomScroller class]; } In this way, compatibility will be properly assessed for both "MyCustomScroller", and for potentially unknown subclasses thereof. When it opts in in this manner, an NSScroller subclass certifies that: - It performs any appearance customization by overriding the parts-drawing methods -drawKnob and -drawKnobSlotInRect:highlight:, and not by overriding -drawRect: wholesale. (This is necessary to allow for separate knob and track fade in/out. AppKit automatically applies the necessary fade alpha to whatever is drawn by -drawKnob and -drawKnobSlotInRect:highlight:.) - It likewise performs any event-handling customization by overriding the parts-based methods -testPart: and -trackKnob:, and not by overriding -mouseDown: wholesale. - It can deal with the fact that scroller arrows no longer exist, and -rectForPart: returns empty rects for them. - It can accommodate the potentially different size and layout metrics used by Overlay scrollers.
         * @return The converted Objective-C result.
         */
        static bool is_compatible_with_overlay_scrollers();
        /**
         * @brief Returns the `controlSize` property of `NSScroller`.
         * @return The converted Objective-C result.
         */
        ControlSize control_size() const;
        /**
         * @brief Sets the `controlSize` property of `NSScroller`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_control_size(ControlSize value) const;
        /**
         * @brief Returns the `hitPart` property of `NSScroller`.
         * @return The converted Objective-C result.
         */
        ScrollerPart hit_part() const;
        /**
         * @brief Returns the `knobProportion` property of `NSScroller`.
         * @return The converted Objective-C result.
         */
        double knob_proportion() const;
        /**
         * @brief Returns the `knobStyle` property of `NSScroller`.
         * @details Accessors for the scroller's knob style. The value of this property does not affect Legacy scrollers. NSScrollerKnobStyleDefault is appropriate for a wide range of content, but in some cases choosing an alternative knob style may enhance visibility of the scroller knob atop some kinds of content.
         * @return The converted Objective-C result.
         */
        ScrollerKnobStyle knob_style() const;
        /**
         * @brief Sets the `knobStyle` property of `NSScroller`.
         * @details Accessors for the scroller's knob style. The value of this property does not affect Legacy scrollers. NSScrollerKnobStyleDefault is appropriate for a wide range of content, but in some cases choosing an alternative knob style may enhance visibility of the scroller knob atop some kinds of content.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_knob_style(ScrollerKnobStyle value) const;
        /**
         * @brief Returns the `preferredScrollerStyle` property of `NSScroller`.
         * @details Returns the style of scrollers that applications should use wherever possible. This value is determined by the Appearance preference panel's "Show scroll bars" setting for the current user, and -- when the user's preference is set to "Automatically based on input device" -- by the set of built-in and connected pointing devices and the user's scroll capability preference settings for them. The preferredScrollerStyle will therefore change over time, and applications should be prepared to adapt their user interfaces to the new scroller style if needed. In most cases, the updating is automatic: When the preferredScrollerStyle changes, AppKit notifies all NSScrollView instances, sending -setScrollerStyle: to each with the new style, which causes each NSScrollView to automatically re-tile (update its layout) to adapt to the new scroller style. Some NSScrollView instances may refuse the new scroller style setting if they cannot accommodate it for compatibility reasons (presence of accessory views or legacy scroller subclasses prevent use of Overlay scrollers), but most instances will switch to the specified new preferredScrollerStyle. Clients that wish to be notified of changes to +preferredScrollerStyle's return value can subscribe to NSPreferredScrollerStyleDidChangeNotification (declared below).
         * @return The converted Objective-C result.
         */
        static ScrollerStyle preferred_scroller_style();
        /**
         * @brief Returns the `scrollerStyle` property of `NSScroller`.
         * @details Accessors for scroller's style. For a scroller that's managed by an NSScrollView, the setter is automatically invoked by the ScrollView with the appropriate setting, according to the user's Appearance preference settings and possibly what pointing device(s) are present.
         * @return The converted Objective-C result.
         */
        ScrollerStyle scroller_style() const;
        /**
         * @brief Sets the `scrollerStyle` property of `NSScroller`.
         * @details Accessors for scroller's style. For a scroller that's managed by an NSScrollView, the setter is automatically invoked by the ScrollView with the appropriate setting, according to the user's Appearance preference settings and possibly what pointing device(s) are present.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_scroller_style(ScrollerStyle value) const;
        /**
         * @brief Returns the `usableParts` property of `NSScroller`.
         * @return The converted Objective-C result.
         */
        UsableScrollerParts usable_parts() const;
    };
}
