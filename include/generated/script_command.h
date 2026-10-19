#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AppleEventDescriptor;
    class ScriptCommandDescription;
    class ScriptObjectSpecifier;

    /**
     * @brief C++ handle for the Objective-C class `NSScriptCommand` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScriptCommand script_command;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScriptCommand script_command{};
     * script_command.set_receivers_specifier(cocoon::ScriptObjectSpecifier());
     * auto receivers_specifier = script_command.receivers_specifier();
     * script_command.set_script_error_expected_type_descriptor(cocoon::AppleEventDescriptor());
     * auto script_error_expected_type_descriptor = script_command.script_error_expected_type_descriptor();
     * script_command.set_script_error_number(1);
     * auto script_error_number = script_command.script_error_number();
     * auto made_0 = cocoon::ScriptCommand::current_command();
     * script_command.execute_command();
     * script_command.perform_default_implementation();
     * script_command.suspend_execution();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsscriptcommand
     */
    class ScriptCommand : public Object
    {
    public:
        /// @brief Creates a new `NSScriptCommand` instance and returns a handle to it.
        explicit ScriptCommand(const ScriptCommandDescription& command_def);
        /// @brief Creates a new `NSScriptCommand` instance and returns a handle to it.
        explicit ScriptCommand();
        /// @brief Creates a null handle that refers to no native object.
        ScriptCommand(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScriptCommand(Adopt adopt);
        /**
     * @brief Calls `+[NSScriptCommand currentCommand]`.
     * @return The converted Objective-C result.
     */
        static ScriptCommand current_command();
        /**
     * @brief Calls `-[NSScriptCommand executeCommand]`.
     * @return The converted Objective-C result.
     */
        Object execute_command() const;
        /**
     * @brief Calls `-[NSScriptCommand performDefaultImplementation]`.
     * @return The converted Objective-C result.
     */
        Object perform_default_implementation() const;
        /**
     * @brief Calls `-[NSScriptCommand resumeExecutionWithResult:]`.
     * @param result Argument converted to the Objective-C parameter of the same role.
     */
        void resume_execution_with_result(const Object& result) const;
        /**
     * @brief Calls `-[NSScriptCommand suspendExecution]`.
     */
        void suspend_execution() const;
        /**
     * @brief Returns the `appleEvent` property of `NSScriptCommand`.
     * @return The converted Objective-C result.
     */
        AppleEventDescriptor apple_event() const;
        /**
     * @brief Returns the `arguments` property of `NSScriptCommand`.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> arguments() const;
        /**
     * @brief Sets the `arguments` property of `NSScriptCommand`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_arguments(const std::map<std::string, Object>& value) const;
        /**
     * @brief Returns the `commandDescription` property of `NSScriptCommand`.
     * @return The converted Objective-C result.
     */
        ScriptCommandDescription command_description() const;
        /**
     * @brief Returns the `directParameter` property of `NSScriptCommand`.
     * @return The converted Objective-C result.
     */
        Object direct_parameter() const;
        /**
     * @brief Sets the `directParameter` property of `NSScriptCommand`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_direct_parameter(const Object& value) const;
        /**
     * @brief Returns the `evaluatedArguments` property of `NSScriptCommand`.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> evaluated_arguments() const;
        /**
     * @brief Returns the `evaluatedReceivers` property of `NSScriptCommand`.
     * @return The converted Objective-C result.
     */
        Object evaluated_receivers() const;
        /**
     * @brief Returns the `receiversSpecifier` property of `NSScriptCommand`.
     * @return The converted Objective-C result.
     */
        ScriptObjectSpecifier receivers_specifier() const;
        /**
     * @brief Sets the `receiversSpecifier` property of `NSScriptCommand`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_receivers_specifier(const ScriptObjectSpecifier& value) const;
        /**
     * @brief Returns the `scriptErrorExpectedTypeDescriptor` property of `NSScriptCommand`.
     * @return The converted Objective-C result.
     */
        AppleEventDescriptor script_error_expected_type_descriptor() const;
        /**
     * @brief Sets the `scriptErrorExpectedTypeDescriptor` property of `NSScriptCommand`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_script_error_expected_type_descriptor(const AppleEventDescriptor& value) const;
        /**
     * @brief Returns the `scriptErrorNumber` property of `NSScriptCommand`.
     * @return The converted Objective-C result.
     */
        std::int64_t script_error_number() const;
        /**
     * @brief Sets the `scriptErrorNumber` property of `NSScriptCommand`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_script_error_number(std::int64_t value) const;
        /**
     * @brief Returns the `scriptErrorOffendingObjectDescriptor` property of `NSScriptCommand`.
     * @return The converted Objective-C result.
     */
        AppleEventDescriptor script_error_offending_object_descriptor() const;
        /**
     * @brief Sets the `scriptErrorOffendingObjectDescriptor` property of `NSScriptCommand`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_script_error_offending_object_descriptor(const AppleEventDescriptor& value) const;
        /**
     * @brief Returns the `scriptErrorString` property of `NSScriptCommand`.
     * @return The converted Objective-C result.
     */
        std::string script_error_string() const;
        /**
     * @brief Sets the `scriptErrorString` property of `NSScriptCommand`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_script_error_string(const std::string& value) const;
        /**
     * @brief Returns the `wellFormed` property of `NSScriptCommand`.
     * @return The converted Objective-C result.
     */
        bool is_well_formed() const;
    };
}
