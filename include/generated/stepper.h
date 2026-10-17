#pragma once

#include "generated/control.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief A stepper control (NSStepper).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * cocoon::Stepper stepper;
     * stepper.set_max_value(10);
     * stepper.value_changed().connect([](double value) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Stepper stepper{};
     * stepper.set_autorepeat(true);
     * auto autorepeat = stepper.autorepeat();
     * stepper.set_increment(1);
     * auto increment = stepper.increment();
     * stepper.set_max_value(1);
     * auto max_value = stepper.max_value();
     * stepper.value_changed().connect([](double a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsstepper
     */
    class Stepper : public Control
    {
    public:
        /// @brief Creates a new `NSStepper` instance and returns a handle to it.
        explicit Stepper();
        /// @brief Creates a null handle that refers to no native object.
        Stepper(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Stepper(Adopt adopt);
        /**
     * @brief Returns the `autorepeat` property of `NSStepper`.
     * @return The converted Objective-C result.
     */
        bool autorepeat() const;
        /**
     * @brief Sets the `autorepeat` property of `NSStepper`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_autorepeat(bool value) const;
        /**
     * @brief Returns the `increment` property of `NSStepper`.
     * @return The converted Objective-C result.
     */
        double increment() const;
        /**
     * @brief Sets the `increment` property of `NSStepper`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_increment(double value) const;
        /**
     * @brief Returns the `maxValue` property of `NSStepper`.
     * @return The converted Objective-C result.
     */
        double max_value() const;
        /**
     * @brief Sets the `maxValue` property of `NSStepper`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_max_value(double value) const;
        /**
     * @brief Returns the `minValue` property of `NSStepper`.
     * @return The converted Objective-C result.
     */
        double min_value() const;
        /**
     * @brief Sets the `minValue` property of `NSStepper`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_min_value(double value) const;
        /**
     * @brief Returns the `valueWraps` property of `NSStepper`.
     * @return The converted Objective-C result.
     */
        bool value_wraps() const;
        /**
     * @brief Sets the `valueWraps` property of `NSStepper`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_value_wraps(bool value) const;
        /// @brief Convenience helper `value` provided by cocoon.
        double value() const;
        /// @brief Convenience helper `set_value` provided by cocoon.
        void set_value(double value) const;
        /// @brief Signal `value_changed`: connect a callback with `value_changed().connect(...)`.
        Signal<Stepper, void(double)> value_changed() const
        {
            return Signal<Stepper, void(double)>(handle(), "value_changed");
        }

    protected:
        static void bind_action_(void* native);
    };
}
