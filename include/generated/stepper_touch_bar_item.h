#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/touch_bar_item.h"
#include "types.h"

namespace cocoon
{
    class Formatter;

    /**
     * @brief C++ handle for the Objective-C class `NSStepperTouchBarItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TouchBarItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::StepperTouchBarItem stepper_touch_bar_item{"text", cocoon::Formatter()};
     * stepper_touch_bar_item.set_action("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::StepperTouchBarItem stepper_touch_bar_item{"text", cocoon::Formatter()};
     * stepper_touch_bar_item.set_action("text");
     * auto action = stepper_touch_bar_item.action();
     * stepper_touch_bar_item.set_customization_label("text");
     * auto customization_label = stepper_touch_bar_item.customization_label();
     * stepper_touch_bar_item.set_increment(1);
     * auto increment = stepper_touch_bar_item.increment();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssteppertouchbaritem
     */
    class StepperTouchBarItem : public TouchBarItem
    {
    public:
        /// @brief Creates a new `NSStepperTouchBarItem` instance and returns a handle to it.
        explicit StepperTouchBarItem(const std::string& identifier, std::function<void(Rect, double)> drawing_handler);
        /// @brief Creates a new `NSStepperTouchBarItem` instance and returns a handle to it.
        explicit StepperTouchBarItem(const std::string& identifier, const Formatter& formatter);
        StepperTouchBarItem();
        /// @brief Creates a null handle that refers to no native object.
        StepperTouchBarItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit StepperTouchBarItem(Adopt adopt);
        using TouchBarItem::customization_label;
        /**
     * @brief Returns the `action` property of `NSStepperTouchBarItem`.
     * @details The action-message selector associated with the stepper.
     * @return The converted Objective-C result.
     */
        std::string action() const;
        /**
     * @brief Sets the `action` property of `NSStepperTouchBarItem`.
     * @details The action-message selector associated with the stepper.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_action(const std::string& value) const;
        /**
     * @brief Returns the `customizationLabel` property of `NSStepperTouchBarItem`.
     * @details The localized string labeling this item during user customization. The default value is empty string.
     * @return The converted Objective-C result.
     */
        std::string customization_label() const;
        /**
     * @brief Sets the `customizationLabel` property of `NSStepperTouchBarItem`.
     * @details The localized string labeling this item during user customization. The default value is empty string.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_customization_label(const std::string& value) const;
        /**
     * @brief Returns the `increment` property of `NSStepperTouchBarItem`.
     * @details The stepper's increment value. The default value is '1.0'.
     * @return The converted Objective-C result.
     */
        double increment() const;
        /**
     * @brief Sets the `increment` property of `NSStepperTouchBarItem`.
     * @details The stepper's increment value. The default value is '1.0'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_increment(double value) const;
        /**
     * @brief Returns the `maxValue` property of `NSStepperTouchBarItem`.
     * @details The stepper's maximum value. The default is '59.0'.
     * @return The converted Objective-C result.
     */
        double max_value() const;
        /**
     * @brief Sets the `maxValue` property of `NSStepperTouchBarItem`.
     * @details The stepper's maximum value. The default is '59.0'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_max_value(double value) const;
        /**
     * @brief Returns the `minValue` property of `NSStepperTouchBarItem`.
     * @details The stepper's minimum value. The default is '0.0'.
     * @return The converted Objective-C result.
     */
        double min_value() const;
        /**
     * @brief Sets the `minValue` property of `NSStepperTouchBarItem`.
     * @details The stepper's minimum value. The default is '0.0'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_min_value(double value) const;
        /**
     * @brief Returns the `target` property of `NSStepperTouchBarItem`.
     * @details The target object that receives action messages from the stepper.
     * @return The converted Objective-C result.
     */
        Object target() const;
        /**
     * @brief Sets the `target` property of `NSStepperTouchBarItem`.
     * @details The target object that receives action messages from the stepper.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_target(const Object& value) const;
        /**
     * @brief Returns the `value` property of `NSStepperTouchBarItem`.
     * @details The current value of the stepper.
     * @return The converted Objective-C result.
     */
        double value() const;
        /**
     * @brief Sets the `value` property of `NSStepperTouchBarItem`.
     * @details The current value of the stepper.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_value(double value) const;
    };
}
