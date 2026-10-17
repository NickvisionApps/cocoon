#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSInputServer` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::InputServer input_server;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsinputserver
     */
    class InputServer : public Object
    {
    public:
        /// @brief Creates a new `NSInputServer` instance and returns a handle to it.
        explicit InputServer();
        /// @brief Creates a null handle that refers to no native object.
        InputServer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit InputServer(Adopt adopt);
    };
}
