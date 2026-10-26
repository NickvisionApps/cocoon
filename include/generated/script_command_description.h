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
         * @details Return the four character code that identifies in Apple events the declared type of the named argument in instances of the described command.
         * @param argument_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        unsigned int apple_event_code_for_argument_with_name(const std::string& argument_name) const;
        /**
         * @brief Calls `-[NSScriptCommandDescription createCommandInstance]`.
         * @details Create an instance of the described command.
         * @return The converted Objective-C result.
         */
        ScriptCommand create_command_instance() const;
        /**
         * @brief Calls `-[NSScriptCommandDescription isOptionalArgumentWithName:]`.
         * @details Return YES if the named argument is declared to be optional, NO otherwise.
         * @param argument_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_optional_argument_with_name(const std::string& argument_name) const;
        /**
         * @brief Calls `-[NSScriptCommandDescription typeForArgumentWithName:]`.
         * @details Return the declared type of the named argument in instances of the described command.
         * @param argument_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string type_for_argument_with_name(const std::string& argument_name) const;
        /**
         * @brief Returns the `appleEventClassCode` property of `NSScriptCommandDescription`.
         * @details Return the four character codes that identify the command in Apple events.
         * @return The converted Objective-C result.
         */
        unsigned int apple_event_class_code() const;
        /**
         * @brief Returns the `appleEventCode` property of `NSScriptCommandDescription`.
         * @return The converted Objective-C result.
         */
        unsigned int apple_event_code() const;
        /**
         * @brief Returns the `appleEventCodeForReturnType` property of `NSScriptCommandDescription`.
         * @details Return the four character code that identifies in Apple events the declared type of the result of execution of the described command.
         * @return The converted Objective-C result.
         */
        unsigned int apple_event_code_for_return_type() const;
        /**
         * @brief Returns the `argumentNames` property of `NSScriptCommandDescription`.
         * @details Return the strings valid for use as keys into argument dictionaries in instances of the described command.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> argument_names() const;
        /**
         * @brief Returns the `commandClassName` property of `NSScriptCommandDescription`.
         * @details Return the Objective-C class name for instances of the described command.
         * @return The converted Objective-C result.
         */
        std::string command_class_name() const;
        /**
         * @brief Returns the `commandName` property of `NSScriptCommandDescription`.
         * @return The converted Objective-C result.
         */
        std::string command_name() const;
        /**
         * @brief Returns the `returnType` property of `NSScriptCommandDescription`.
         * @details Return the declared type name for the result of execution of the described command, or nil if the described command is not declared to return a result.
         * @return The converted Objective-C result.
         */
        std::string return_type() const;
        /**
         * @brief Returns the `suiteName` property of `NSScriptCommandDescription`.
         * @details Return the suite name or command name provided at initialization time.
         * @return The converted Objective-C result.
         */
        std::string suite_name() const;
    };
}
