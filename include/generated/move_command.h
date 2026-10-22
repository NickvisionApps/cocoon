#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/script_command.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ScriptObjectSpecifier;

    /**
     * @brief C++ handle for the Objective-C class `NSMoveCommand` (Foundation).
     * @details A command that moves one or more scriptable objects. An instance of 'NSMoveCommand' moves the specified scriptable object or objects; for example, it may move words to a new location in a document or a file to a new directory. 'NSMoveCommand' is part of Cocoa's built-in scripting support. It works automatically to support the 'move' AppleScript command through key-value coding. Most applications don't need to subclass 'NSMoveCommand' or invoke its methods. However, for circumstances where you might choose to subclass this command, see "Modifying a Standard Command" in [Script Commands](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_script_cmds/SAppsScriptCmds.html\#//apple_ref/doc/uid/20001242) in [Cocoa Scripting Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_intro/SAppsIntro.html\#//apple_ref/doc/uid/TP40002164). When an instance of 'NSMoveCommand' is executed, it does not make copies of moved objects. It removes objects from the source container or containers, then inserts them into the destination container.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptCommand.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MoveCommand move_command;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MoveCommand move_command{};
     * move_command.set_receivers_specifier(cocoon::ScriptObjectSpecifier());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmovecommand
     */
    class MoveCommand : public ScriptCommand
    {
    public:
        /// @brief Creates a new `NSMoveCommand` instance and returns a handle to it.
        explicit MoveCommand();
        /// @brief Creates a null handle that refers to no native object.
        MoveCommand(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MoveCommand(Adopt adopt);
        using ScriptCommand::set_receivers_specifier;
        /**
         * @brief Calls `-[NSMoveCommand setReceiversSpecifier:]`.
         * @details Splits off the inner-most child specifier from the receivers specifier.
         * @param receivers_ref Argument converted to the Objective-C parameter of the same role.
         */
        void set_receivers_specifier(const ScriptObjectSpecifier& receivers_ref) const;
        /**
         * @brief Returns the `keySpecifier` property of `NSMoveCommand`.
         * @details The key specifier for the move operation.
         * @return The converted Objective-C result.
         */
        ScriptObjectSpecifier key_specifier() const;
    };
}
