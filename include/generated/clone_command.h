#pragma once

#include "generated/enums.h"
#include "generated/script_command.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ScriptObjectSpecifier;

    /**
     * @brief C++ handle for the Objective-C class `NSCloneCommand` (Foundation).
     * @details A command that clones one or more scriptable objects. An instance of 'NSCloneCommand' clones the specified scriptable object or objects (such as words, paragraphs, images, and so on) and inserts them in the specified location, or the default location if no location is specified. The cloned scriptable objects typically correspond to objects in the application, but aren't required to. This command corresponds to AppleScript's 'duplicate' command. 'NSCloneCommand' is part of Cocoa's built-in scripting support. It works automatically to support the 'duplicate' command through key-value coding. Most applications don't need to subclass 'NSCloneCommand' or invoke its methods. When an instance of 'NSCloneCommand' is executed, it clones the specified objects by sending them \<doc://com.apple.documentation/documentation/objectivec/nsobject-swift.class/copywithzone:> messages.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptCommand.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CloneCommand clone_command;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CloneCommand clone_command{};
     * clone_command.set_receivers_specifier(cocoon::ScriptObjectSpecifier());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsclonecommand
     */
    class CloneCommand : public ScriptCommand
    {
    public:
        /// @brief Creates a new `NSCloneCommand` instance and returns a handle to it.
        explicit CloneCommand();
        /// @brief Creates a null handle that refers to no native object.
        CloneCommand(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CloneCommand(Adopt adopt);
        using ScriptCommand::set_receivers_specifier;
        /**
     * @brief Calls `-[NSCloneCommand setReceiversSpecifier:]`.
     * @details Splits off the inner-most child specifier from the receivers specifier.
     * @param receivers_ref Argument converted to the Objective-C parameter of the same role.
     */
        void set_receivers_specifier(const ScriptObjectSpecifier& receivers_ref) const;
        /**
     * @brief Returns the `keySpecifier` property of `NSCloneCommand`.
     * @details The key specifier for the clone operation.
     * @return The converted Objective-C result.
     */
        ScriptObjectSpecifier key_specifier() const;
    };
}
