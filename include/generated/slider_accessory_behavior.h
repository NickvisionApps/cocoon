#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class SliderAccessory;

    /**
     * @brief C++ handle for the Objective-C class `NSSliderAccessoryBehavior` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SliderAccessoryBehavior slider_accessory_behavior;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SliderAccessoryBehavior slider_accessory_behavior{};
     * slider_accessory_behavior.handle_action(cocoon::SliderAccessory());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsslideraccessorybehavior
     */
    class SliderAccessoryBehavior : public Object
    {
    public:
        /// @brief Creates a new `NSSliderAccessoryBehavior` instance and returns a handle to it.
        explicit SliderAccessoryBehavior();
        /// @brief Creates a null handle that refers to no native object.
        SliderAccessoryBehavior(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SliderAccessoryBehavior(Adopt adopt);
        /**
         * @brief Calls `+[NSSliderAccessoryBehavior behaviorWithHandler:]`.
         * @details The handler block is invoked on interaction. This variant is not codable and will assert in '-encodeWithCoder:'.
         * @param handler Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static SliderAccessoryBehavior behavior_with_handler(std::function<void(SliderAccessory)> handler);
        /**
         * @brief Calls `+[NSSliderAccessoryBehavior behaviorWithTarget:action:]`.
         * @details The action is sent to the target on interaction. \@param target An optional 'NSSliderAccessory'.
         * @param target Argument converted to the Objective-C parameter of the same role.
         * @param action Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static SliderAccessoryBehavior behavior_with_target(const Object& target, const std::string& action);
        /**
         * @brief Calls `-[NSSliderAccessoryBehavior handleAction:]`.
         * @details Override point for custom subclasses to handle interaction.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void handle_action(const SliderAccessory& sender) const;
        /**
         * @brief Returns the `automaticBehavior` property of `NSSliderAccessoryBehavior`.
         * @details The behavior is automatically picked to be the system standard, given the slider's current context. For example, NSTouchBarItems have '.valueStep' behavior.
         * @return The converted Objective-C result.
         */
        static SliderAccessoryBehavior automatic_behavior();
        /**
         * @brief Returns the `valueResetBehavior` property of `NSSliderAccessoryBehavior`.
         * @details The value of the slider is reset to the associated value for the accessory.
         * @return The converted Objective-C result.
         */
        static SliderAccessoryBehavior value_reset_behavior();
        /**
         * @brief Returns the `valueStepBehavior` property of `NSSliderAccessoryBehavior`.
         * @details The value of the slider moves towards the associated value for the accessory with by a delta of the slider's 'altIncrementValue'.
         * @return The converted Objective-C result.
         */
        static SliderAccessoryBehavior value_step_behavior();
    };
}
