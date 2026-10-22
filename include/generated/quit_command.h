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
     * @details A command that quits the specified app. The quit command may optionally specify how to handle modified documents (automatically save changes, don't save them, or ask the user). For details, see the description for the 'quit' command in "Apple Events Sent By the Mac OS" in [How Cocoa Applications Handle Apple Events](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_handle_AEs/SAppsHandleAEs.html\#//apple_ref/doc/uid/20001239) in [Cocoa Scripting Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_intro/SAppsIntro.html\#//apple_ref/doc/uid/TP40002164). 'NSQuitCommand' is part of Cocoa's built-in scripting support. Most applications don't need to subclass 'NSQuitCommand' or call its methods.
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
         * @details The save options specified by the command.
         * @return The converted Objective-C result.
         */
        SaveOptions save_options() const;
    };
}
