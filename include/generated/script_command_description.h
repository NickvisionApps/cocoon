#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class ScriptCommand;

    /**
     * @brief C++ handle for the Objective-C class `NSScriptCommandDescription` (Foundation).
     * @details A script command that a macOS app supports. A scriptable application provides scriptability information that describes the commands and objects scripters can use in scripts that target the application. An application's scripting information is collected automatically by an instance of ''NSScriptSuiteRegistry'', which creates an 'NSScriptCommandDescription' for each command it finds, caches these objects in memory, and installs a command handler for each command. A script command instance stores the name, class, argument types, and return type of a command. For example, commands in AppleScript's Core suite include 'clone', 'count', 'create', 'delete', 'exists', and 'move'. The public methods of 'NSScriptCommandDescription' are used primarily by Cocoa's built-in scripting support in responding to Apple events that target the application. Although you can subclass the 'NSScriptCommandDescription' class, it is unlikely that you would need to do so, or to create instances of it.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScriptCommandDescription script_command_description(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScriptCommandDescription script_command_description(nullptr);
     * script_command_description.apple_event_code_for_argument_with_name("text");
     * script_command_description.create_command_instance();
     * script_command_description.is_optional_argument_with_name("text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsscriptcommanddescription
     */
    class ScriptCommandDescription : public Object
    {
    public:
        /// @brief Creates a new `NSScriptCommandDescription` instance and returns a handle to it.
        explicit ScriptCommandDescription(const std::string& suite_name, const std::string& command_name, const std::vector<std::pair<Object, Object>>& command_declaration);
        ScriptCommandDescription();
        /// @brief Creates a null handle that refers to no native object.
        ScriptCommandDescription(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScriptCommandDescription(Adopt adopt);
        /**
         * @brief Calls `-[NSScriptCommandDescription appleEventCodeForArgumentWithName:]`.
         * @details Returns the Apple event code for the specified command argument of the receiver. - Parameter argumentName: The argument name (used as a key) for which to obtain the corresponding Apple event code. - Returns: The code for the specified argument.
         * @param argument_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        unsigned int apple_event_code_for_argument_with_name(const std::string& argument_name) const;
        /**
         * @brief Calls `-[NSScriptCommandDescription createCommandInstance]`.
         * @details Creates and returns an instance of the command object described by the receiver. - Returns: The command object, instantiated from ''NSScriptCommand'' or a subclass.
         * @return The converted Objective-C result.
         */
        ScriptCommand create_command_instance() const;
        /**
         * @brief Calls `-[NSScriptCommandDescription isOptionalArgumentWithName:]`.
         * @details Returns a Boolean value that indicates whether the command argument identified by the specified argument key is an optional argument. - Parameter argumentName: Argument name (used as a key) that identifies the command argument to examine. - Returns: 'true' if the specified argument exists and is optional; otherwise, 'false'.
         * @param argument_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_optional_argument_with_name(const std::string& argument_name) const;
        /**
         * @brief Calls `-[NSScriptCommandDescription typeForArgumentWithName:]`.
         * @details Returns the type of the command argument identified by the specified key. - Parameter argumentName: Argument name (used as a key) that identifies the command argument to examine. - Returns: The type of the specified command argument. Returns 'nil' if there is no such argument.
         * @param argument_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string type_for_argument_with_name(const std::string& argument_name) const;
        /**
         * @brief Returns the `appleEventClassCode` property of `NSScriptCommandDescription`.
         * @details The four-character code for the Apple event class of the receiver's command. In an Apple event that specifies a script command, two four character codes -- the event class and event ID -- together identify the command. You use this property to obtain the event class. You use ''NSScriptCommandDescription/appleEventCode'' to obtain the event ID. For example, commands in AppleScript's Core suite, such as 'clone', 'count', and 'create', have an event class code of ''core''. This code and the event ID code returned by ''appleEventCode'' together specify the necessary information for identifying and dispatching an Apple event.
         * @return The converted Objective-C result.
         */
        unsigned int apple_event_class_code() const;
        /**
         * @brief Returns the `appleEventCode` property of `NSScriptCommandDescription`.
         * @details The four-character code for the Apple event ID of the receiver's command. This value, together with the event class code returned by ''NSScriptCommandDescription/appleEventClassCode'', specifies the necessary information for identifying and dispatching an Apple event.
         * @return The converted Objective-C result.
         */
        unsigned int apple_event_code() const;
        /**
         * @brief Returns the `appleEventCodeForReturnType` property of `NSScriptCommandDescription`.
         * @details The Apple event code that identifies the command's return type.
         * @return The converted Objective-C result.
         */
        unsigned int apple_event_code_for_return_type() const;
        /**
         * @brief Returns the `argumentNames` property of `NSScriptCommandDescription`.
         * @details The names (or keys) for all arguments of the receiver's command. If there are no arguments for the command, returns an empty array.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> argument_names() const;
        /**
         * @brief Returns the `commandClassName` property of `NSScriptCommandDescription`.
         * @details The name of the class that will be instantiated to handle the command. The Objective-C class name (for example, '"NSGetCommand"'). This is always ''NSScriptCommand'' or a subclass.
         * @return The converted Objective-C result.
         */
        std::string command_class_name() const;
        /**
         * @brief Returns the `commandName` property of `NSScriptCommandDescription`.
         * @details The name of the command. The command name as it appears in the application's scriptability information; may be different from what is displayed to the scripter.
         * @return The converted Objective-C result.
         */
        std::string command_name() const;
        /**
         * @brief Returns the `returnType` property of `NSScriptCommandDescription`.
         * @details The return type of the command. The receiver's command return type (for example, '"NSNumber"' or '"NSDictionary"'), or 'nil' if the described command is not declared to return a result.
         * @return The converted Objective-C result.
         */
        std::string return_type() const;
        /**
         * @brief Returns the `suiteName` property of `NSScriptCommandDescription`.
         * @details The name of the suite that contains the command described by the receiver. Within an application's scriptability information, named suites contain related sets of information.
         * @return The converted Objective-C result.
         */
        std::string suite_name() const;
    };
}
