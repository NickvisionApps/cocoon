#pragma once

#include "generated/enums.h"
#include "generated/script_command.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSCloseCommand` (Foundation).
     * @details A command that closes one or more scriptable objects. An instance of 'NSCloseCommand' closes the specified scriptable object or objects—typically a document or window (and its associated document, if any). The command may optionally specify a location to save in and how to handle modified documents (by automatically saving changes, not saving them, or asking the user). 'NSCloseCommand' is part of Cocoa's built-in scripting support. It works automatically to support the 'close' command through key-value coding. Most applications don't need to subclass 'NSCloseCommand' or call its methods.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptCommand.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CloseCommand close_command;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsclosecommand
     */
    class CloseCommand : public ScriptCommand
    {
    public:
        /// @brief Creates a new `NSCloseCommand` instance and returns a handle to it.
        explicit CloseCommand();
        /// @brief Creates a null handle that refers to no native object.
        CloseCommand(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CloseCommand(Adopt adopt);
        /**
     * @brief Returns the `saveOptions` property of `NSCloseCommand`.
     * @details The save options specified by the command.
     * @return The converted Objective-C result.
     */
        SaveOptions save_options() const;
    };
}
