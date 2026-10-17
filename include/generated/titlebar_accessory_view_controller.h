#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view_controller.h"
#include "types.h"

namespace cocoon
{
    class ScrollEdgeEffectStyle;

    /**
     * @brief C++ handle for the Objective-C class `NSTitlebarAccessoryViewController` (AppKit).
     * @details For use with NSWindow's API addTitlebarAccessoryViewController:, etc.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ViewController.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TitlebarAccessoryViewController titlebar_accessory_view_controller;
     * titlebar_accessory_view_controller.set_automatically_adjusts_size(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TitlebarAccessoryViewController titlebar_accessory_view_controller{};
     * titlebar_accessory_view_controller.set_automatically_adjusts_size(true);
     * auto automatically_adjusts_size = titlebar_accessory_view_controller.automatically_adjusts_size();
     * titlebar_accessory_view_controller.set_full_screen_min_height(1);
     * auto full_screen_min_height = titlebar_accessory_view_controller.full_screen_min_height();
     * titlebar_accessory_view_controller.set_hidden(true);
     * auto hidden = titlebar_accessory_view_controller.is_hidden();
     * titlebar_accessory_view_controller.view_did_appear();
     * titlebar_accessory_view_controller.view_did_disappear();
     * titlebar_accessory_view_controller.view_will_appear();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstitlebaraccessoryviewcontroller
     */
    class TitlebarAccessoryViewController : public ViewController
    {
    public:
        /// @brief Creates a new `NSTitlebarAccessoryViewController` instance and returns a handle to it.
        explicit TitlebarAccessoryViewController();
        /// @brief Creates a null handle that refers to no native object.
        TitlebarAccessoryViewController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TitlebarAccessoryViewController(Adopt adopt);
        using ViewController::view_did_appear;
        using ViewController::view_did_disappear;
        using ViewController::view_will_appear;
        /**
     * @brief Calls `-[NSTitlebarAccessoryViewController viewDidAppear]`.
     */
        void view_did_appear() const;
        /**
     * @brief Calls `-[NSTitlebarAccessoryViewController viewDidDisappear]`.
     */
        void view_did_disappear() const;
        /**
     * @brief Calls `-[NSTitlebarAccessoryViewController viewWillAppear]`.
     */
        void view_will_appear() const;
        /**
     * @brief Returns the `automaticallyAdjustsSize` property of `NSTitlebarAccessoryViewController`.
     * @details Whether the accessory should automatically size to the standard system default sizing over the view's current frame size. Only valid for accessories with a layoutAttribute of NSLayoutAttributeBottom. The default value is YES.
     * @return The converted Objective-C result.
     */
        bool automatically_adjusts_size() const;
        /**
     * @brief Sets the `automaticallyAdjustsSize` property of `NSTitlebarAccessoryViewController`.
     * @details Whether the accessory should automatically size to the standard system default sizing over the view's current frame size. Only valid for accessories with a layoutAttribute of NSLayoutAttributeBottom. The default value is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_automatically_adjusts_size(bool value) const;
        /**
     * @brief Returns the `fullScreenMinHeight` property of `NSTitlebarAccessoryViewController`.
     * @details The fullScreenMinHeight controls the visual minimum height of the view when it is in full screen. It only applies to controllers with the layoutAttribute set to NSLayoutAttributeBottom. Note that the view's height is never actually changed, and it is automatically clipped by an internal clip view. The minimum height is used when the menu bar is hidden. A minimum height of 0 will fully hide the view when the menu bar is hidden. To always show a portion of the view, set the fullScreenMinHeight to some value greater than 0. To always have the view fully shown (i.e.: a fixed height accessory view), set the fullScreenMinHeight to the view.frame.size.height (and be sure to update it if you ever change the view's height). The default value is 0.
     * @return The converted Objective-C result.
     */
        double full_screen_min_height() const;
        /**
     * @brief Sets the `fullScreenMinHeight` property of `NSTitlebarAccessoryViewController`.
     * @details The fullScreenMinHeight controls the visual minimum height of the view when it is in full screen. It only applies to controllers with the layoutAttribute set to NSLayoutAttributeBottom. Note that the view's height is never actually changed, and it is automatically clipped by an internal clip view. The minimum height is used when the menu bar is hidden. A minimum height of 0 will fully hide the view when the menu bar is hidden. To always show a portion of the view, set the fullScreenMinHeight to some value greater than 0. To always have the view fully shown (i.e.: a fixed height accessory view), set the fullScreenMinHeight to the view.frame.size.height (and be sure to update it if you ever change the view's height). The default value is 0.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_full_screen_min_height(double value) const;
        /**
     * @brief Returns the `hidden` property of `NSTitlebarAccessoryViewController`.
     * @details Indicates whether the accessory view is actually visible in the window. This property only applies to controllers set with the top or bottom layoutAttribute. When set, this property will collapse the accessory view to 0 height (animatable) but NOT remove it from the window. That way, you can easily show and hide it without difficulty. Set through the animator object to animate it.
     * @return The converted Objective-C result.
     */
        bool is_hidden() const;
        /**
     * @brief Sets the `hidden` property of `NSTitlebarAccessoryViewController`.
     * @details Indicates whether the accessory view is actually visible in the window. This property only applies to controllers set with the top or bottom layoutAttribute. When set, this property will collapse the accessory view to 0 height (animatable) but NOT remove it from the window. That way, you can easily show and hide it without difficulty. Set through the animator object to animate it.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hidden(bool value) const;
        /**
     * @brief Returns the `layoutAttribute` property of `NSTitlebarAccessoryViewController`.
     * @details The layoutAttribute defaults to NSLayoutAttributeBottom, telling the window to place this view controller's view under the titlebar. NSLayoutAttributeRight is also supported, telling the window to place the view controller's view on the right side of the window. For applications linked on Mac OS 10.11 or later, NSLayoutAttributeLeft is also supported; placing the item on the left side of the window (adjacent and to the right of the close/minimize/maximize buttons). All other values are currently invalid and will assert. A layoutAttribute == NSLayoutAttributeRight will indent toolbar items for all toolbar styles except NSToolbarStyleExpanded and NSToolbarStyleCompact. For applications linked on 10.12 and higher, NSLayoutAttributeLeading and NSLayoutAttributeTrailing can also be used to specify an abstract position that automatically flips depending on the localized language. For applications that do not link on 10.12, NSLayoutAttributeLeft will automatically flip to the Right when in a Right To Left language. For applications linked on 10.13 and higher, NSLayoutAttributeTop can also be used to specify a view that will be at the top of the titlebar area. Only one should be used per window, and if one is set the normal titlebar will not be drawn. Using the top attributed requires the window to have the NSWindowStyleMaskFullSizeContentView style mask set. The "hidden" property can be used to show and hide the view. The "hidden" property will animate the view via an alpha fade in and out if accessed through the animator proxy (such as: viewController.animator.hidden = YES). For applications linked on macOS 27.0 or higher, leading and trailing accessories are positioned within the titlebar area only (excluding the toolbar) when the window uses NSWindowToolbarStyleExpanded or NSWindowToolbarStylePreference, or when the window has no toolbar.
     * @return The converted Objective-C result.
     */
        LayoutAttribute layout_attribute() const;
        /**
     * @brief Sets the `layoutAttribute` property of `NSTitlebarAccessoryViewController`.
     * @details The layoutAttribute defaults to NSLayoutAttributeBottom, telling the window to place this view controller's view under the titlebar. NSLayoutAttributeRight is also supported, telling the window to place the view controller's view on the right side of the window. For applications linked on Mac OS 10.11 or later, NSLayoutAttributeLeft is also supported; placing the item on the left side of the window (adjacent and to the right of the close/minimize/maximize buttons). All other values are currently invalid and will assert. A layoutAttribute == NSLayoutAttributeRight will indent toolbar items for all toolbar styles except NSToolbarStyleExpanded and NSToolbarStyleCompact. For applications linked on 10.12 and higher, NSLayoutAttributeLeading and NSLayoutAttributeTrailing can also be used to specify an abstract position that automatically flips depending on the localized language. For applications that do not link on 10.12, NSLayoutAttributeLeft will automatically flip to the Right when in a Right To Left language. For applications linked on 10.13 and higher, NSLayoutAttributeTop can also be used to specify a view that will be at the top of the titlebar area. Only one should be used per window, and if one is set the normal titlebar will not be drawn. Using the top attributed requires the window to have the NSWindowStyleMaskFullSizeContentView style mask set. The "hidden" property can be used to show and hide the view. The "hidden" property will animate the view via an alpha fade in and out if accessed through the animator proxy (such as: viewController.animator.hidden = YES). For applications linked on macOS 27.0 or higher, leading and trailing accessories are positioned within the titlebar area only (excluding the toolbar) when the window uses NSWindowToolbarStyleExpanded or NSWindowToolbarStylePreference, or when the window has no toolbar.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_layout_attribute(LayoutAttribute value) const;
        /**
     * @brief Returns the `preferredScrollEdgeEffectStyle` property of `NSTitlebarAccessoryViewController`.
     * @details The titlebar accessory’s preferred effect for content scrolling behind it. To allow for a soft edge on the bottom edge of a titlebar accessory: titlebarAccessoryViewController.preferredScrollEdgeEffectStyle = NSScrollEdgeEffectStyle.softStyle;
     * @return The converted Objective-C result.
     */
        ScrollEdgeEffectStyle preferred_scroll_edge_effect_style() const;
        /**
     * @brief Sets the `preferredScrollEdgeEffectStyle` property of `NSTitlebarAccessoryViewController`.
     * @details The titlebar accessory’s preferred effect for content scrolling behind it. To allow for a soft edge on the bottom edge of a titlebar accessory: titlebarAccessoryViewController.preferredScrollEdgeEffectStyle = NSScrollEdgeEffectStyle.softStyle;
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_scroll_edge_effect_style(const ScrollEdgeEffectStyle& value) const;
    };
}
