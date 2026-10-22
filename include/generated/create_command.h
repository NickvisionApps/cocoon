#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/script_command.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ScriptClassDescription;

    /**
     * @brief C++ handle for the Objective-C class `NSCreateCommand` (Foundation).
     * @details A command that creates a scriptable object. An instance of 'NSCreateCommand' creates the specified scriptable object (such as a document), optionally supplying the new object with the specified attributes. This command corresponds to AppleScript's 'make' command. 'NSCreateCommand' is part of Cocoa's built-in scripting support. Most applications don't need to subclass 'NSCreateCommand' or invoke its methods. When an instance of 'NSCreateCommand' is executed, it creates a new object using '[[theClassToBeCreated allocWithZone:NULL] init]' (where 'theClassToBeCreated' is the class of the object to be created), unless the command has a 'with data' argument. In the latter case, the new object is created by invoking '[[NSScriptCoercionHandler sharedCoercionHandler] coerceValue:theDataAsAnObject toClass:theClassToBeCreated]'. Any properties specified by a 'with properties' argument are then set in the new object using '-setScriptingProperties:'. If an 'NSCreateCommand' object with no argument corresponding to the 'at' parameter is executed (for example, 'tell application "Mail" to make new mailbox with properties {name:"testFolder"}'), and the receiver of the command (not necessarily the application object) has a to-many relationship to objects of the class to be instantiated, and the class description for the receiving class returns \<doc://com.apple.documentation/documentation/swift/false> when sent an 'isLocationRequiredToCreateForKey:' message, the 'NSCreateCommand' object creates a new object and sends the receiver an \<doc://com.apple.documentation/documentation/objectivec/nsobject-swift.class/insertvalue(:at:inpropertywithkey:)> message to place the new object in the container. This is part of Cocoa's scripting support for inserting newly-created objects into containers without explicitly specifying a location.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptCommand.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CreateCommand create_command;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nscreatecommand
     */
    class CreateCommand : public ScriptCommand
    {
    public:
        /// @brief Creates a new `NSCreateCommand` instance and returns a handle to it.
        explicit CreateCommand();
        /// @brief Creates a null handle that refers to no native object.
        CreateCommand(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CreateCommand(Adopt adopt);
        /**
         * @brief Returns the `createClassDescription` property of `NSCreateCommand`.
         * @details The class description for the class that is to be created.
         * @return The converted Objective-C result.
         */
        ScriptClassDescription create_class_description() const;
        /**
         * @brief Returns the `resolvedKeyDictionary` property of `NSCreateCommand`.
         * @details The key dictionary with Apple event codes resolved to actual key names.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> resolved_key_dictionary() const;
    };
}
