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
     * @brief C++ handle for the Objective-C class `NSSplitViewItemAccessoryViewController` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ViewController.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SplitViewItemAccessoryViewController split_view_item_accessory_view_controller;
     * split_view_item_accessory_view_controller.set_automatically_applies_content_insets(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SplitViewItemAccessoryViewController split_view_item_accessory_view_controller{};
     * split_view_item_accessory_view_controller.set_automatically_applies_content_insets(true);
     * auto automatically_applies_content_insets = split_view_item_accessory_view_controller.automatically_applies_content_insets();
     * split_view_item_accessory_view_controller.set_hidden(true);
     * auto hidden = split_view_item_accessory_view_controller.is_hidden();
     * split_view_item_accessory_view_controller.set_preferred_scroll_edge_effect_style(cocoon::ScrollEdgeEffectStyle());
     * auto preferred_scroll_edge_effect_style = split_view_item_accessory_view_controller.preferred_scroll_edge_effect_style();
     * split_view_item_accessory_view_controller.view_did_appear();
     * split_view_item_accessory_view_controller.view_did_disappear();
     * split_view_item_accessory_view_controller.view_will_appear();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssplitviewitemaccessoryviewcontroller
     */
    class SplitViewItemAccessoryViewController : public ViewController
    {
    public:
        /// @brief Creates a new `NSSplitViewItemAccessoryViewController` instance and returns a handle to it.
        explicit SplitViewItemAccessoryViewController();
        /// @brief Creates a null handle that refers to no native object.
        SplitViewItemAccessoryViewController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SplitViewItemAccessoryViewController(Adopt adopt);
        using ViewController::view_did_appear;
        using ViewController::view_did_disappear;
        using ViewController::view_will_appear;
        using ViewController::view_will_disappear;
        /**
         * @brief Calls `-[NSSplitViewItemAccessoryViewController viewDidAppear]`.
         */
        void view_did_appear() const;
        /**
         * @brief Calls `-[NSSplitViewItemAccessoryViewController viewDidDisappear]`.
         */
        void view_did_disappear() const;
        /**
         * @brief Calls `-[NSSplitViewItemAccessoryViewController viewWillAppear]`.
         */
        void view_will_appear() const;
        /**
         * @brief Calls `-[NSSplitViewItemAccessoryViewController viewWillDisappear]`.
         */
        void view_will_disappear() const;
        /**
         * @brief Returns the `automaticallyAppliesContentInsets` property of `NSSplitViewItemAccessoryViewController`.
         * @details Whether or not standard content insets should be applied to the view. Defaults to YES.
         * @return The converted Objective-C result.
         */
        bool automatically_applies_content_insets() const;
        /**
         * @brief Sets the `automaticallyAppliesContentInsets` property of `NSSplitViewItemAccessoryViewController`.
         * @details Whether or not standard content insets should be applied to the view. Defaults to YES.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatically_applies_content_insets(bool value) const;
        /**
         * @brief Returns the `hidden` property of `NSSplitViewItemAccessoryViewController`.
         * @details When set, this property will collapse the accessory view to 0 height (animatable) but not remove it from the window. Set through the animator object to animate it.
         * @return The converted Objective-C result.
         */
        bool is_hidden() const;
        /**
         * @brief Sets the `hidden` property of `NSSplitViewItemAccessoryViewController`.
         * @details When set, this property will collapse the accessory view to 0 height (animatable) but not remove it from the window. Set through the animator object to animate it.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_hidden(bool value) const;
        /**
         * @brief Returns the `preferredScrollEdgeEffectStyle` property of `NSSplitViewItemAccessoryViewController`.
         * @details The split view item accessory’s preferred effect for content scrolling behind it. To allow for a soft edge on the interior edge of a titlebar accessory: splitViewItemAccessoryViewController.preferredScrollEdgeEffectStyle = NSScrollEdgeEffectStyle.softStyle;
         * @return The converted Objective-C result.
         */
        ScrollEdgeEffectStyle preferred_scroll_edge_effect_style() const;
        /**
         * @brief Sets the `preferredScrollEdgeEffectStyle` property of `NSSplitViewItemAccessoryViewController`.
         * @details The split view item accessory’s preferred effect for content scrolling behind it. To allow for a soft edge on the interior edge of a titlebar accessory: splitViewItemAccessoryViewController.preferredScrollEdgeEffectStyle = NSScrollEdgeEffectStyle.softStyle;
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_preferred_scroll_edge_effect_style(const ScrollEdgeEffectStyle& value) const;
    };
}
