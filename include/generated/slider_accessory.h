#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Image;
    class SliderAccessoryBehavior;

    /**
     * @brief C++ handle for the Objective-C class `NSSliderAccessory` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SliderAccessory slider_accessory;
     * slider_accessory.set_behavior(cocoon::SliderAccessoryBehavior());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SliderAccessory slider_accessory{};
     * slider_accessory.set_behavior(cocoon::SliderAccessoryBehavior());
     * auto behavior = slider_accessory.behavior();
     * slider_accessory.set_enabled(true);
     * auto enabled = slider_accessory.is_enabled();
     * auto made_0 = cocoon::SliderAccessory::accessory_with_image(cocoon::Image());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsslideraccessory
     */
    class SliderAccessory : public Object
    {
    public:
        /// @brief Creates a new `NSSliderAccessory` instance and returns a handle to it.
        explicit SliderAccessory();
        /// @brief Creates a null handle that refers to no native object.
        SliderAccessory(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SliderAccessory(Adopt adopt);
        /**
         * @brief Calls `+[NSSliderAccessory accessoryWithImage:]`.
         * @param image Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static SliderAccessory accessory_with_image(const Image& image);
        /**
         * @brief Returns the `behavior` property of `NSSliderAccessory`.
         * @details The effect on interaction with the accessory. The default value is 'automaticBehavior'.
         * @return The converted Objective-C result.
         */
        SliderAccessoryBehavior behavior() const;
        /**
         * @brief Sets the `behavior` property of `NSSliderAccessory`.
         * @details The effect on interaction with the accessory. The default value is 'automaticBehavior'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_behavior(const SliderAccessoryBehavior& value) const;
        /**
         * @brief Returns the `enabled` property of `NSSliderAccessory`.
         * @details Determines whether or not the accessory is interactive and draws with an enabled appearance. Defaults to 'true'.
         * @return The converted Objective-C result.
         */
        bool is_enabled() const;
        /**
         * @brief Sets the `enabled` property of `NSSliderAccessory`.
         * @details Determines whether or not the accessory is interactive and draws with an enabled appearance. Defaults to 'true'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_enabled(bool value) const;
    };
}
