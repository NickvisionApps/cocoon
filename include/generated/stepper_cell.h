#pragma once

#include "generated/action_cell.h"
#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSStepperCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ActionCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::StepperCell stepper_cell;
     * stepper_cell.set_autorepeat(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::StepperCell stepper_cell{};
     * stepper_cell.set_autorepeat(true);
     * auto autorepeat = stepper_cell.autorepeat();
     * stepper_cell.set_increment(1);
     * auto increment = stepper_cell.increment();
     * stepper_cell.set_max_value(1);
     * auto max_value = stepper_cell.max_value();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssteppercell
     */
    class StepperCell : public ActionCell
    {
    public:
        /// @brief Creates a new `NSStepperCell` instance and returns a handle to it.
        explicit StepperCell();
        /// @brief Creates a null handle that refers to no native object.
        StepperCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit StepperCell(Adopt adopt);
        /**
     * @brief Returns the `autorepeat` property of `NSStepperCell`.
     * @return The converted Objective-C result.
     */
        bool autorepeat() const;
        /**
     * @brief Sets the `autorepeat` property of `NSStepperCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_autorepeat(bool value) const;
        /**
     * @brief Returns the `increment` property of `NSStepperCell`.
     * @return The converted Objective-C result.
     */
        double increment() const;
        /**
     * @brief Sets the `increment` property of `NSStepperCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_increment(double value) const;
        /**
     * @brief Returns the `maxValue` property of `NSStepperCell`.
     * @return The converted Objective-C result.
     */
        double max_value() const;
        /**
     * @brief Sets the `maxValue` property of `NSStepperCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_max_value(double value) const;
        /**
     * @brief Returns the `minValue` property of `NSStepperCell`.
     * @return The converted Objective-C result.
     */
        double min_value() const;
        /**
     * @brief Sets the `minValue` property of `NSStepperCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_min_value(double value) const;
        /**
     * @brief Returns the `valueWraps` property of `NSStepperCell`.
     * @return The converted Objective-C result.
     */
        bool value_wraps() const;
        /**
     * @brief Sets the `valueWraps` property of `NSStepperCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_value_wraps(bool value) const;
    };
}
