#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSInputManager` (AppKit).
     * @details NSInputManager is deprecated in Mac OS X 10.6. Use NSTextInputContext instead.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::InputManager input_manager;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsinputmanager
     */
    class InputManager : public Object
    {
    public:
        /// @brief Creates a new `NSInputManager` instance and returns a handle to it.
        explicit InputManager();
        /// @brief Creates a null handle that refers to no native object.
        InputManager(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit InputManager(Adopt adopt);
    };
}
