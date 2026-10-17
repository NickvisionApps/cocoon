#pragma once

#include "generated/enums.h"
#include "generated/script_command.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ScriptObjectSpecifier;

    /**
     * @brief C++ handle for the Objective-C class `NSDeleteCommand` (Foundation).
     * @details A command that deletes a scriptable object. An instance of 'NSDeleteCommand' deletes the specified scriptable object or objects (such as words, paragraphs, and so on). Suppose, for example, a user executes a script that sends the command 'delete the third rectangle in the first document' to the Sketch sample application (located in '/Developer/Examples/AppKit'). Cocoa creates an 'NSDeleteCommand' object to perform the operation. When the command is executed, it uses the key-value coding mechanism (by invoking 'removeValueAtIndex:fromPropertyWithKey:') to remove the specified object or objects from their container. See the description for \<doc://com.apple.documentation/documentation/objectivec/nsobject-swift.class/removevalue(at:frompropertywithkey:)> for related information. 'NSDeleteCommand' is part of Cocoa's built-in scripting support. Most applications don't need to subclass 'NSDeleteCommand' or call its methods.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptCommand.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DeleteCommand delete_command;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DeleteCommand delete_command{};
     * delete_command.set_receivers_specifier(cocoon::ScriptObjectSpecifier());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdeletecommand
     */
    class DeleteCommand : public ScriptCommand
    {
    public:
        /// @brief Creates a new `NSDeleteCommand` instance and returns a handle to it.
        explicit DeleteCommand();
        /// @brief Creates a null handle that refers to no native object.
        DeleteCommand(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DeleteCommand(Adopt adopt);
        using ScriptCommand::set_receivers_specifier;
        /**
     * @brief Calls `-[NSDeleteCommand setReceiversSpecifier:]`.
     * @details Splits off the inner-most child specifier from the receivers specifier.
     * @param receivers_ref Argument converted to the Objective-C parameter of the same role.
     */
        void set_receivers_specifier(const ScriptObjectSpecifier& receivers_ref) const;
        /**
     * @brief Returns the `keySpecifier` property of `NSDeleteCommand`.
     * @details The key specifier for the delete operation.
     * @return The converted Objective-C result.
     */
        ScriptObjectSpecifier key_specifier() const;
    };
}
