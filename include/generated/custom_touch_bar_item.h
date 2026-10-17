#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/touch_bar_item.h"
#include "types.h"

namespace cocoon
{
    class View;
    class ViewController;

    /**
     * @brief C++ handle for the Objective-C class `NSCustomTouchBarItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TouchBarItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CustomTouchBarItem custom_touch_bar_item(nullptr);  // null handle; instances normally come from other API calls
     * custom_touch_bar_item.set_customization_label("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CustomTouchBarItem custom_touch_bar_item(nullptr);
     * custom_touch_bar_item.set_customization_label("text");
     * auto customization_label = custom_touch_bar_item.customization_label();
     * custom_touch_bar_item.set_view(cocoon::View());
     * auto view = custom_touch_bar_item.view();
     * custom_touch_bar_item.set_view_controller(cocoon::ViewController());
     * auto view_controller = custom_touch_bar_item.view_controller();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscustomtouchbaritem
     */
    class CustomTouchBarItem : public TouchBarItem
    {
    public:
        CustomTouchBarItem();
        /// @brief Creates a null handle that refers to no native object.
        CustomTouchBarItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CustomTouchBarItem(Adopt adopt);
        using TouchBarItem::customization_label;
        using TouchBarItem::view;
        using TouchBarItem::view_controller;
        /**
     * @brief Returns the `customizationLabel` property of `NSCustomTouchBarItem`.
     * @details The localized string labelling this item during user customization. The default value is the empty string. This property is archived.
     * @return The converted Objective-C result.
     */
        std::string customization_label() const;
        /**
     * @brief Sets the `customizationLabel` property of `NSCustomTouchBarItem`.
     * @details The localized string labelling this item during user customization. The default value is the empty string. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_customization_label(const std::string& value) const;
        /**
     * @brief Returns the `view` property of `NSCustomTouchBarItem`.
     * @details A view to be displayed in the NSTouchBar in the location corresponding to this item. By default, the getter for this property will return this item's view controller's view. If this property is set explicitly, the view controller will be set to nil. This property is archived.
     * @return The converted Objective-C result.
     */
        View view() const;
        /**
     * @brief Sets the `view` property of `NSCustomTouchBarItem`.
     * @details A view to be displayed in the NSTouchBar in the location corresponding to this item. By default, the getter for this property will return this item's view controller's view. If this property is set explicitly, the view controller will be set to nil. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_view(const View& value) const;
        /**
     * @brief Returns the `viewController` property of `NSCustomTouchBarItem`.
     * @details A view controller whose view is to be displayed in the NSTouchBar in the location corresponding to this item. By default, this property is nil. When set, this item's view property will automatically return the view associated with this view controller. This property is archived.
     * @return The converted Objective-C result.
     */
        ViewController view_controller() const;
        /**
     * @brief Sets the `viewController` property of `NSCustomTouchBarItem`.
     * @details A view controller whose view is to be displayed in the NSTouchBar in the location corresponding to this item. By default, this property is nil. When set, this item's view property will automatically return the view associated with this view controller. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_view_controller(const ViewController& value) const;
    };
}
