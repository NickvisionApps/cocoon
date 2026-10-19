#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/script_command.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSQuitCommand` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptCommand.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::QuitCommand quit_command;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsquitcommand
     */
    class QuitCommand : public ScriptCommand
    {
    public:
        /// @brief Creates a new `NSQuitCommand` instance and returns a handle to it.
        explicit QuitCommand();
        /// @brief Creates a null handle that refers to no native object.
        QuitCommand(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit QuitCommand(Adopt adopt);
        /**
     * @brief Returns the `saveOptions` property of `NSQuitCommand`.
     * @return The converted Objective-C result.
     */
        SaveOptions save_options() const;
    };
}
