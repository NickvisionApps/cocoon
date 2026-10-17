#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/responder.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Appearance;
    class Notification;
    class ToolbarItem;
    class View;
    class ViewController;
    class Window;

    /**
     * @brief C++ handle for the Objective-C class `NSPopover` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Responder.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Popover popover;
     * popover.set_animates(true);
     * popover.did_detach().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Popover popover{};
     * popover.set_animates(true);
     * auto animates = popover.animates();
     * popover.set_appearance(cocoon::Appearance());
     * auto appearance = popover.appearance();
     * popover.set_behavior(cocoon::PopoverBehavior::ApplicationDefined);
     * auto behavior = popover.behavior();
     * popover.close();
     * popover.show_relative_to_rect({{0, 0}, {100, 100}}, cocoon::View(), cocoon::RectEdge::MinX);
     * popover.show_relative_to_toolbar_item(cocoon::ToolbarItem());
     * popover.did_detach().connect([]() {});
     * popover.will_show().connect([](cocoon::Notification a0) {});
     * popover.did_show().connect([](cocoon::Notification a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspopover
     */
    class Popover : public Responder
    {
    public:
        /// @brief Creates a new `NSPopover` instance and returns a handle to it.
        explicit Popover();
        /// @brief Creates a null handle that refers to no native object.
        Popover(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Popover(Adopt adopt);
        /**
     * @brief Calls `-[NSPopover close]`.
     * @details Forces the popover to close without consulting its delegate. Any popovers nested within the popovers will also receive a close message. When a window is closed in response to the -close message being sent, all of its popovers will be closed. The popover will animate out when closed (unless the animates property is set to NO).
     */
        void close() const;
        /**
     * @brief Calls `-[NSPopover performClose:]`.
     * @details Attempts to close the popover. The popover will not be closed if it has a delegate and the delegate returns NO to -popoverShouldClose: (or if the popover's class implements -popoverShouldClose: to return NO). The operation will fail if it is displaying a nested popover, or if it has a child window. A window will attempt to close its popovers when it receives a -performClose: message. The popover will animate out when closed (unless the animates property is set to NO).
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void perform_close(const Object& sender) const;
        /**
     * @brief Calls `-[NSPopover showRelativeToRect:ofView:preferredEdge:]`.
     * @details Shows the popover anchored to the specified view. The popover will animate onscreen and eventually animate offscreen when it is closed (unless the property 'animates' is set to 'NO'). - Parameters: - positioningRect: The rectangle within 'positioningView' relative to which the popover should be positioned. Normally set to the bounds of 'positioningView'. May be an empty rectangle, which will default to the bounds of 'positioningView'. - positioningView: The view relative to which the popover should be positioned. Causes the method to raise 'NSInvalidArgumentException' if 'nil'. - preferredEdge: The edge of 'positioningView' the popover should prefer to be anchored to (respects to the '-isFlipped' state of 'positioningView'). The current (but not guaranteed) behavior is that AppKit will place the anchor towards the 'preferredEdge' of the 'positioningRect' unless such a placement would cause the popover not to fit on the screen of 'positioningView'. If the anchor cannot be placed towards the 'preferredEdge', AppKit will (in the current implementation) attempt to place the anchor on the opposite side of the 'positioningRect'. If that cannot be done, AppKit will attempt to place the anchor on a remaining side of the popover, and failing that will center the popover on the screen, causing it to (at least temporarily) lose its anchor. - Note: This method will throw a 'NSInvalidArgumentException' if view is 'nil' or if 'view' is not in a window, or if the popover’s behavior is 'NSPopoverBehaviorSemitransient' and the popover’s 'positioningView' is in a popover or child window. It will throw a 'NSInternalInconsistencyException' if the popover’s content view controller (or the view controller’s view) is 'nil'. If the popover is already being shown, this method will update to be associated with the new 'view' and 'positioningRect' passed. - Note: If the positioning view isn’t visible (its window isn’t visible, or the positioning rect is outside of its visible rect), this method does nothing.
     * @param positioning_rect Argument converted to the Objective-C parameter of the same role.
     * @param positioning_view Argument converted to the Objective-C parameter of the same role.
     * @param preferred_edge Argument converted to the Objective-C parameter of the same role.
     */
        void show_relative_to_rect(const Rect& positioning_rect, const View& positioning_view, RectEdge preferred_edge) const;
        /**
     * @brief Calls `-[NSPopover showRelativeToToolbarItem:]`.
     * @details Shows the popover positioned relative to \\c toolbarItem . When the item is in the overflow menu, the popover will be presented from another appropriate affordance in the window. See the comments in \\c -showRelativeToRect:ofView:preferredEdge: for the popover behavior. This method will throw an \\c NSInvalidArgumentException if it cannot locate the toolbar item. This could happen because the item is not in a toolbar, or because the toolbar is not in a window.
     * @param toolbar_item Argument converted to the Objective-C parameter of the same role.
     */
        void show_relative_to_toolbar_item(const ToolbarItem& toolbar_item) const;
        /**
     * @brief Returns the `animates` property of `NSPopover`.
     * @details Should the popover be animated when it shows, closes, or appears to transition to a detachable window. This property also controls whether the popover animates when the content view or content size changes. AppKit does not guarantee which behaviors will be animated or that this property will be respected; it is regarded as a hint. The default value is YES.
     * @return The converted Objective-C result.
     */
        bool animates() const;
        /**
     * @brief Sets the `animates` property of `NSPopover`.
     * @details Should the popover be animated when it shows, closes, or appears to transition to a detachable window. This property also controls whether the popover animates when the content view or content size changes. AppKit does not guarantee which behaviors will be animated or that this property will be respected; it is regarded as a hint. The default value is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_animates(bool value) const;
        /**
     * @brief Returns the `appearance` property of `NSPopover`.
     * @details The appearance of the popover. The popover's contentView will inherit this appearance. The default effective appearance is the NSAppearanceNameVibrantLight appearance. If nil is set, nil will be returned, and the effective appearance will return to the default. To prevent conflicts with the previous appearance property, this is only available for apps that target 10.10 and higher.
     * @return The converted Objective-C result.
     */
        Appearance appearance() const;
        /**
     * @brief Sets the `appearance` property of `NSPopover`.
     * @details The appearance of the popover. The popover's contentView will inherit this appearance. The default effective appearance is the NSAppearanceNameVibrantLight appearance. If nil is set, nil will be returned, and the effective appearance will return to the default. To prevent conflicts with the previous appearance property, this is only available for apps that target 10.10 and higher.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_appearance(const Appearance& value) const;
        /**
     * @brief Returns the `behavior` property of `NSPopover`.
     * @details The behavior of the popover. The default behavior is NSPopoverBehaviorApplicationDefined. See the declaration of NSPopoverBehavior above for more information about popover behaviors.
     * @return The converted Objective-C result.
     */
        PopoverBehavior behavior() const;
        /**
     * @brief Sets the `behavior` property of `NSPopover`.
     * @details The behavior of the popover. The default behavior is NSPopoverBehaviorApplicationDefined. See the declaration of NSPopoverBehavior above for more information about popover behaviors.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_behavior(PopoverBehavior value) const;
        /**
     * @brief Returns the `contentSize` property of `NSPopover`.
     * @details The content size of the popover. The popover's content size is set to match the size of the content view when the content view controller is set. Changes to the content size of the popover will animate while the popover is shown (provided animates is YES).
     * @return The converted Objective-C result.
     */
        Size content_size() const;
        /**
     * @brief Sets the `contentSize` property of `NSPopover`.
     * @details The content size of the popover. The popover's content size is set to match the size of the content view when the content view controller is set. Changes to the content size of the popover will animate while the popover is shown (provided animates is YES).
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_size(const Size& value) const;
        /**
     * @brief Returns the `contentViewController` property of `NSPopover`.
     * @details The view controller that manages the content of the popover. The default value is nil. You must set the content view controller of the popover to a non-nil value before the popover is shown. Changes to the popover's content view controller while the popover is shown will animate (provided animates is YES).
     * @return The converted Objective-C result.
     */
        ViewController content_view_controller() const;
        /**
     * @brief Sets the `contentViewController` property of `NSPopover`.
     * @details The view controller that manages the content of the popover. The default value is nil. You must set the content view controller of the popover to a non-nil value before the popover is shown. Changes to the popover's content view controller while the popover is shown will animate (provided animates is YES).
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_view_controller(const ViewController& value) const;
        /**
     * @brief Returns the `detached` property of `NSPopover`.
     * @details Returns \\c YES if the window is detached to an implicitly created detached window, \\c NO otherwise. This method does not apply when the popover is detached to a window returned with \\c -detachableWindowForPopover:.
     * @return The converted Objective-C result.
     */
        bool is_detached() const;
        /**
     * @brief Returns the `effectiveAppearance` property of `NSPopover`.
     * @return The converted Objective-C result.
     */
        Appearance effective_appearance() const;
        /**
     * @brief Returns the `hasFullSizeContent` property of `NSPopover`.
     * @details If 'YES', the 'contentViewController''s view will extend into the chevron region of the popover. That view's 'safeAreaInsets' will be adjusted accordingly such that anchoring any subviews to its 'safeAreaLayoutGuide' will result in constraining to the unclipped content area of the popover. The default value for this property is 'NO'. The full size content will extend to the containing window's frame, along all edges. Anything outside the popover will be clipped. ------------------------- ------------------------- ------------------------- ------------------------- | /\\ | | | | | | | | /-------- ---------\\ | | /-------------------\\ | | /-------------------\\ | | /-------------------\\ | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | > | | \< | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | \\-------------------/ | | \\-------- ---------/ | | \\-------------------/ | | \\-------------------/ | | | | \\/ | | | | | ------------------------- ------------------------- ------------------------- -------------------------
     * @return The converted Objective-C result.
     */
        bool has_full_size_content() const;
        /**
     * @brief Sets the `hasFullSizeContent` property of `NSPopover`.
     * @details If 'YES', the 'contentViewController''s view will extend into the chevron region of the popover. That view's 'safeAreaInsets' will be adjusted accordingly such that anchoring any subviews to its 'safeAreaLayoutGuide' will result in constraining to the unclipped content area of the popover. The default value for this property is 'NO'. The full size content will extend to the containing window's frame, along all edges. Anything outside the popover will be clipped. ------------------------- ------------------------- ------------------------- ------------------------- | /\\ | | | | | | | | /-------- ---------\\ | | /-------------------\\ | | /-------------------\\ | | /-------------------\\ | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | > | | \< | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | \\-------------------/ | | \\-------- ---------/ | | \\-------------------/ | | \\-------------------/ | | | | \\/ | | | | | ------------------------- ------------------------- ------------------------- -------------------------
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_has_full_size_content(bool value) const;
        /**
     * @brief Returns the `positioningRect` property of `NSPopover`.
     * @details Popovers are positioned relative to a positioning view and are automatically moved when the location or size of the positioning view changes. Sometimes it is desirable to position popovers relative to a rectangle within the positioning view. In this case, you must update the positioningRect binding whenever this rectangle changes, or use the positioningRect binding so AppKit can re-position the popover when appropriate.
     * @return The converted Objective-C result.
     */
        Rect positioning_rect() const;
        /**
     * @brief Sets the `positioningRect` property of `NSPopover`.
     * @details Popovers are positioned relative to a positioning view and are automatically moved when the location or size of the positioning view changes. Sometimes it is desirable to position popovers relative to a rectangle within the positioning view. In this case, you must update the positioningRect binding whenever this rectangle changes, or use the positioningRect binding so AppKit can re-position the popover when appropriate.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_positioning_rect(const Rect& value) const;
        /**
     * @brief Returns the `shown` property of `NSPopover`.
     * @details YES if the popover is being shown, NO otherwise. The popover is considered to be shown from the point when -showRelativeToRect:ofView:preferredEdge: is invoked until the popover is closed in response to an invocation of either -close or -performClose:.
     * @return The converted Objective-C result.
     */
        bool is_shown() const;
        /// @brief Signal for the delegate/data-source method behind `should_close`; connect a callback with `should_close().connect(...)`.
        Signal<Popover, bool()> should_close() const
        {
            return Signal<Popover, bool()>(handle(), "should_close");
        }
        /// @brief Signal for the delegate/data-source method behind `should_detach`; connect a callback with `should_detach().connect(...)`.
        Signal<Popover, bool()> should_detach() const
        {
            return Signal<Popover, bool()>(handle(), "should_detach");
        }
        /// @brief Signal for the delegate/data-source method behind `did_detach`; connect a callback with `did_detach().connect(...)`.
        Signal<Popover, void()> did_detach() const
        {
            return Signal<Popover, void()>(handle(), "did_detach");
        }
        /// @brief Signal for the delegate/data-source method behind `detachable_window_for_popover`; connect a callback with `detachable_window_for_popover().connect(...)`.
        Signal<Popover, Window()> detachable_window_for_popover() const
        {
            return Signal<Popover, Window()>(handle(), "detachable_window_for_popover");
        }
        /// @brief Signal for the delegate/data-source method behind `will_show`; connect a callback with `will_show().connect(...)`.
        Signal<Popover, void(Notification)> will_show() const
        {
            return Signal<Popover, void(Notification)>(handle(), "will_show");
        }
        /// @brief Signal for the delegate/data-source method behind `did_show`; connect a callback with `did_show().connect(...)`.
        Signal<Popover, void(Notification)> did_show() const
        {
            return Signal<Popover, void(Notification)>(handle(), "did_show");
        }
        /// @brief Signal for the delegate/data-source method behind `will_close`; connect a callback with `will_close().connect(...)`.
        Signal<Popover, void(Notification)> will_close() const
        {
            return Signal<Popover, void(Notification)>(handle(), "will_close");
        }
        /// @brief Signal for the delegate/data-source method behind `did_close`; connect a callback with `did_close().connect(...)`.
        Signal<Popover, void(Notification)> did_close() const
        {
            return Signal<Popover, void(Notification)>(handle(), "did_close");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
