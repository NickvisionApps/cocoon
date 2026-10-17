#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSPressureConfiguration` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PressureConfiguration pressure_configuration;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PressureConfiguration pressure_configuration{};
     * pressure_configuration.set();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspressureconfiguration
     */
    class PressureConfiguration : public Object
    {
    public:
        /// @brief Creates a new `NSPressureConfiguration` instance and returns a handle to it.
        explicit PressureConfiguration(PressureBehavior pressure_behavior);
        /// @brief Creates a new `NSPressureConfiguration` instance and returns a handle to it.
        explicit PressureConfiguration();
        /// @brief Creates a null handle that refers to no native object.
        PressureConfiguration(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PressureConfiguration(Adopt adopt);
        /**
     * @brief Calls `-[NSPressureConfiguration set]`.
     * @details Sets the configuration; it will automatically be reset on mouse up or gesture end. Only takes effect during a mouse drag or pressure event sequence. However, if your application is slow to respond to the mouseDown event, the user may complete the mouse click sequence before this configuration can take effect. When possible you should configure the pressure behavior before the mouse down via NSView's pressureConfiguration property.
     */
        void set() const;
        /**
     * @brief Returns the `pressureBehavior` property of `NSPressureConfiguration`.
     * @return The converted Objective-C result.
     */
        PressureBehavior pressure_behavior() const;
    };
}
