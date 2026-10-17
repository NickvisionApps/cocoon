#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/touch_bar_item.h"
#include "types.h"

namespace cocoon
{
    class Slider;
    class SliderAccessory;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSSliderTouchBarItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TouchBarItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SliderTouchBarItem slider_touch_bar_item(nullptr);  // null handle; instances normally come from other API calls
     * slider_touch_bar_item.set_action("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SliderTouchBarItem slider_touch_bar_item(nullptr);
     * slider_touch_bar_item.set_action("text");
     * auto action = slider_touch_bar_item.action();
     * slider_touch_bar_item.set_customization_label("text");
     * auto customization_label = slider_touch_bar_item.customization_label();
     * slider_touch_bar_item.set_double_value(1);
     * auto double_value = slider_touch_bar_item.double_value();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsslidertouchbaritem
     */
    class SliderTouchBarItem : public TouchBarItem
    {
    public:
        SliderTouchBarItem();
        /// @brief Creates a null handle that refers to no native object.
        SliderTouchBarItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SliderTouchBarItem(Adopt adopt);
        using TouchBarItem::customization_label;
        using TouchBarItem::view;
        /**
     * @brief Returns the `action` property of `NSSliderTouchBarItem`.
     * @details The action of the item, called when the slider or accessories receive user interaction.
     * @return The converted Objective-C result.
     */
        std::string action() const;
        /**
     * @brief Sets the `action` property of `NSSliderTouchBarItem`.
     * @details The action of the item, called when the slider or accessories receive user interaction.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_action(const std::string& value) const;
        /**
     * @brief Returns the `customizationLabel` property of `NSSliderTouchBarItem`.
     * @details The localized string labeling this item during user customization. The default value is empty string.
     * @return The converted Objective-C result.
     */
        std::string customization_label() const;
        /**
     * @brief Sets the `customizationLabel` property of `NSSliderTouchBarItem`.
     * @details The localized string labeling this item during user customization. The default value is empty string.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_customization_label(const std::string& value) const;
        /**
     * @brief Returns the `doubleValue` property of `NSSliderTouchBarItem`.
     * @details The double value of the control
     * @return The converted Objective-C result.
     */
        double double_value() const;
        /**
     * @brief Sets the `doubleValue` property of `NSSliderTouchBarItem`.
     * @details The double value of the control
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_double_value(double value) const;
        /**
     * @brief Returns the `label` property of `NSSliderTouchBarItem`.
     * @details The text label displayed along with the slider. If set to nil, the label will not have space reserved in the item.
     * @return The converted Objective-C result.
     */
        std::string label() const;
        /**
     * @brief Sets the `label` property of `NSSliderTouchBarItem`.
     * @details The text label displayed along with the slider. If set to nil, the label will not have space reserved in the item.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_label(const std::string& value) const;
        /**
     * @brief Returns the `maximumSliderWidth` property of `NSSliderTouchBarItem`.
     * @return The converted Objective-C result.
     */
        double maximum_slider_width() const;
        /**
     * @brief Sets the `maximumSliderWidth` property of `NSSliderTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_slider_width(double value) const;
        /**
     * @brief Returns the `maximumValueAccessory` property of `NSSliderTouchBarItem`.
     * @details The accessory that appears on the end of the slider with the maximum value
     * @return The converted Objective-C result.
     */
        SliderAccessory maximum_value_accessory() const;
        /**
     * @brief Sets the `maximumValueAccessory` property of `NSSliderTouchBarItem`.
     * @details The accessory that appears on the end of the slider with the maximum value
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_value_accessory(const SliderAccessory& value) const;
        /**
     * @brief Returns the `minimumSliderWidth` property of `NSSliderTouchBarItem`.
     * @details The width boundaries of the slider track of this item. The system defines the default minimum. The maximum defaults to MAXFLOAT
     * @return The converted Objective-C result.
     */
        double minimum_slider_width() const;
        /**
     * @brief Sets the `minimumSliderWidth` property of `NSSliderTouchBarItem`.
     * @details The width boundaries of the slider track of this item. The system defines the default minimum. The maximum defaults to MAXFLOAT
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_slider_width(double value) const;
        /**
     * @brief Returns the `minimumValueAccessory` property of `NSSliderTouchBarItem`.
     * @details The accessory that appears on the end of the slider with the minimum value
     * @return The converted Objective-C result.
     */
        SliderAccessory minimum_value_accessory() const;
        /**
     * @brief Sets the `minimumValueAccessory` property of `NSSliderTouchBarItem`.
     * @details The accessory that appears on the end of the slider with the minimum value
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_value_accessory(const SliderAccessory& value) const;
        /**
     * @brief Returns the `slider` property of `NSSliderTouchBarItem`.
     * @details The slider displayed by the bar item. It is automatically created, but can be set to a custom subclass. doubleValue, minValue, maxValue, etc can all be read and set through the slider.
     * @return The converted Objective-C result.
     */
        Slider slider() const;
        /**
     * @brief Sets the `slider` property of `NSSliderTouchBarItem`.
     * @details The slider displayed by the bar item. It is automatically created, but can be set to a custom subclass. doubleValue, minValue, maxValue, etc can all be read and set through the slider.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_slider(const Slider& value) const;
        /**
     * @brief Returns the `target` property of `NSSliderTouchBarItem`.
     * @details The target of the item, notified when the slider or accessories receive user interaction.
     * @return The converted Objective-C result.
     */
        Object target() const;
        /**
     * @brief Sets the `target` property of `NSSliderTouchBarItem`.
     * @details The target of the item, notified when the slider or accessories receive user interaction.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_target(const Object& value) const;
        /**
     * @brief Returns the `valueAccessoryWidth` property of `NSSliderTouchBarItem`.
     * @details The width of the value accessories. Defaults to '.default', but can be set to '.wide' or a custom value.
     * @return The converted Objective-C result.
     */
        double value_accessory_width() const;
        /**
     * @brief Sets the `valueAccessoryWidth` property of `NSSliderTouchBarItem`.
     * @details The width of the value accessories. Defaults to '.default', but can be set to '.wide' or a custom value.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_value_accessory_width(double value) const;
        /**
     * @brief Returns the `view` property of `NSSliderTouchBarItem`.
     * @return The converted Objective-C result.
     */
        View view() const;
    };
}
