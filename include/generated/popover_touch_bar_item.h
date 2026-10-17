#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/touch_bar_item.h"
#include "types.h"

namespace cocoon
{
    class GestureRecognizer;
    class Image;
    class TouchBar;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSPopoverTouchBarItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TouchBarItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PopoverTouchBarItem popover_touch_bar_item(nullptr);  // null handle; instances normally come from other API calls
     * popover_touch_bar_item.set_collapsed_representation(cocoon::View());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PopoverTouchBarItem popover_touch_bar_item(nullptr);
     * popover_touch_bar_item.set_collapsed_representation(cocoon::View());
     * auto collapsed_representation = popover_touch_bar_item.collapsed_representation();
     * popover_touch_bar_item.set_collapsed_representation_image(cocoon::Image());
     * auto collapsed_representation_image = popover_touch_bar_item.collapsed_representation_image();
     * popover_touch_bar_item.set_collapsed_representation_label("text");
     * auto collapsed_representation_label = popover_touch_bar_item.collapsed_representation_label();
     * popover_touch_bar_item.make_standard_activate_popover_gesture_recognizer();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspopovertouchbaritem
     */
    class PopoverTouchBarItem : public TouchBarItem
    {
    public:
        PopoverTouchBarItem();
        /// @brief Creates a null handle that refers to no native object.
        PopoverTouchBarItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PopoverTouchBarItem(Adopt adopt);
        using TouchBarItem::customization_label;
        /**
     * @brief Calls `-[NSPopoverTouchBarItem dismissPopover:]`.
     * @details This method will restore the previously visible main NSTouchBar. This method can be invoked explicitly to order out a popover if interacting with an item inside it should close it.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void dismiss_popover(const Object& sender) const;
        /**
     * @brief Calls `-[NSPopoverTouchBarItem makeStandardActivatePopoverGestureRecognizer]`.
     * @details Returns a new gesture recognizer, already wired up to send this popover -showPopover:. It is the callers responsibility to attach this GR to a custom collapsedRepresentation view
     * @return The converted Objective-C result.
     */
        GestureRecognizer make_standard_activate_popover_gesture_recognizer() const;
        /**
     * @brief Calls `-[NSPopoverTouchBarItem showPopover:]`.
     * @details Replaces the main NSTouchBar with this item's popover NSTouchBar. If this item is not visible, this method will have no effect. If this item ceases to be visible, the popover NSTouchBar will automatically be ordered out.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void show_popover(const Object& sender) const;
        /**
     * @brief Returns the `collapsedRepresentation` property of `NSPopoverTouchBarItem`.
     * @details The view displayed when the item is in its hosted NSTouchBar. By default, this is an NSButton whose target is this popover item, whose action is showPopover:, and whose image and title are bound to this item's collapsedRepresentationImage and collapsedRepresentationLabel respectively. This property is archived.
     * @return The converted Objective-C result.
     */
        View collapsed_representation() const;
        /**
     * @brief Sets the `collapsedRepresentation` property of `NSPopoverTouchBarItem`.
     * @details The view displayed when the item is in its hosted NSTouchBar. By default, this is an NSButton whose target is this popover item, whose action is showPopover:, and whose image and title are bound to this item's collapsedRepresentationImage and collapsedRepresentationLabel respectively. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_collapsed_representation(const View& value) const;
        /**
     * @brief Returns the `collapsedRepresentationImage` property of `NSPopoverTouchBarItem`.
     * @return The converted Objective-C result.
     */
        Image collapsed_representation_image() const;
        /**
     * @brief Sets the `collapsedRepresentationImage` property of `NSPopoverTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_collapsed_representation_image(const Image& value) const;
        /**
     * @brief Returns the `collapsedRepresentationLabel` property of `NSPopoverTouchBarItem`.
     * @details The localized string displayed by the button used by default for the default collapsed representation. If the collapsedRepresentation button has been replaced by a different view, this property may not have any effect. This property is archived.
     * @return The converted Objective-C result.
     */
        std::string collapsed_representation_label() const;
        /**
     * @brief Sets the `collapsedRepresentationLabel` property of `NSPopoverTouchBarItem`.
     * @details The localized string displayed by the button used by default for the default collapsed representation. If the collapsedRepresentation button has been replaced by a different view, this property may not have any effect. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_collapsed_representation_label(const std::string& value) const;
        /**
     * @brief Returns the `customizationLabel` property of `NSPopoverTouchBarItem`.
     * @details The localized string labelling this item during user customization. The default value is the empty string. This property is archived.
     * @return The converted Objective-C result.
     */
        std::string customization_label() const;
        /**
     * @brief Sets the `customizationLabel` property of `NSPopoverTouchBarItem`.
     * @details The localized string labelling this item during user customization. The default value is the empty string. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_customization_label(const std::string& value) const;
        /**
     * @brief Returns the `popoverTouchBar` property of `NSPopoverTouchBarItem`.
     * @details The NSTouchBar displayed when this item is "popped." By default this is an empty bar that cannot be customized. This property is archived.
     * @return The converted Objective-C result.
     */
        TouchBar popover_touch_bar() const;
        /**
     * @brief Sets the `popoverTouchBar` property of `NSPopoverTouchBarItem`.
     * @details The NSTouchBar displayed when this item is "popped." By default this is an empty bar that cannot be customized. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_popover_touch_bar(const TouchBar& value) const;
        /**
     * @brief Returns the `pressAndHoldTouchBar` property of `NSPopoverTouchBarItem`.
     * @details An NSTouchBar to be used exclusively for press-and-hold popovers. This NSTouchBar can be the same as the one used for "popoverTouchBar" property, but does not have to be. When non-nil this NSTouchBar will be displayed while the user holds their finger down on the collapsed representation and released when the user raises their finger. This tracking behavior is automatic, but popovers with custom collapsed representations will still need to send -showPopover: to start tracking. This property is archived.
     * @return The converted Objective-C result.
     */
        TouchBar press_and_hold_touch_bar() const;
        /**
     * @brief Sets the `pressAndHoldTouchBar` property of `NSPopoverTouchBarItem`.
     * @details An NSTouchBar to be used exclusively for press-and-hold popovers. This NSTouchBar can be the same as the one used for "popoverTouchBar" property, but does not have to be. When non-nil this NSTouchBar will be displayed while the user holds their finger down on the collapsed representation and released when the user raises their finger. This tracking behavior is automatic, but popovers with custom collapsed representations will still need to send -showPopover: to start tracking. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_press_and_hold_touch_bar(const TouchBar& value) const;
        /**
     * @brief Returns the `showsCloseButton` property of `NSPopoverTouchBarItem`.
     * @details When YES, automatically displays a close button in the popover. When NO it is the responsibility of the client to dismiss the popover.
     * @return The converted Objective-C result.
     */
        bool shows_close_button() const;
        /**
     * @brief Sets the `showsCloseButton` property of `NSPopoverTouchBarItem`.
     * @details When YES, automatically displays a close button in the popover. When NO it is the responsibility of the client to dismiss the popover.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_close_button(bool value) const;
    };
}
