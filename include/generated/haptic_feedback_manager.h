#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSHapticFeedbackManager` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::HapticFeedbackManager haptic_feedback_manager;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nshapticfeedbackmanager
     */
    class HapticFeedbackManager : public Object
    {
    public:
        /// @brief Creates a new `NSHapticFeedbackManager` instance and returns a handle to it.
        explicit HapticFeedbackManager();
        /// @brief Creates a null handle that refers to no native object.
        HapticFeedbackManager(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit HapticFeedbackManager(Adopt adopt);
        /**
     * @brief Returns the `defaultPerformer` property of `NSHapticFeedbackManager`.
     * @details The most appropriate feedback performer for the current input device, accessibility settings and user preferences. Note: This device may change during the life of your application. Always request the defaultPerformer when you need perform feedback.
     * @return The converted Objective-C result.
     */
        static Object default_performer();
    };
}
