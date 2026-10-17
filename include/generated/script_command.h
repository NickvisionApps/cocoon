#pragma once

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
     * @details A self-contained scripting statement. An instance of ''NSScriptCommand'' represents a scripting statement, such as 'set word 5 of the front document to word 1 of the second document', and contains the information needed to perform the operation specified by the statement. When an Apple event reaches a Cocoa application, Cocoa's built-in scripting support transforms it into a script command (that is, an instance of 'NSScriptCommand' or one of the subclasses provided by Cocoa scripting or by your application) and executes the command in the context of the application. Executing a command means either invoking the selector associated with the command on the object or objects designated to receive the command, or having the command perform its default implementation method (''performDefaultImplementation()''). Your application most likely calls methods of 'NSScriptCommand' to extract the command arguments. You do this either in the 'performDefaultImplementation' method of a command subclass you have created, or in an object method designated as the selector to handle a particular command. As part of Cocoa's standard scripting implementation, 'NSScriptCommand' and its subclasses can handle the default command set for AppleScript's Standard suite for most applications without any subclassing. The Standard suite includes commands such as 'copy', 'count', 'create', 'delete', 'exists', and 'move', as well as common object classes such as 'application', 'document', and 'window'. For more information on working with script commands, see [Script Commands](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_script_cmds/SAppsScriptCmds.html\#//apple_ref/doc/uid/20001242) in [Cocoa Scripting Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_intro/SAppsIntro.html\#//apple_ref/doc/uid/TP40002164).
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
     * @details Returns the currently executing script command, if any. If a command is being executed in the current thread by Cocoa Scripting's built-in Apple event handling, return the command. Return 'nil' otherwise.
     * @return The converted Objective-C result.
     */
        static ScriptCommand current_command();
        /**
     * @brief Calls `-[NSScriptCommand executeCommand]`.
     * @details Evaluates the receiver specifier and arguments, validates the command, and executes it. If the command is valid and there are receivers, the command handler method for the receivers' class is invoked. If the command is valid but there are no receivers, 'performDefaultImplementation' is invoked.
     * @return The converted Objective-C result.
     */
        Object execute_command() const;
        /**
     * @brief Calls `-[NSScriptCommand performDefaultImplementation]`.
     * @details Overridden by subclasses to perform the default action for a command when no receivers explicitly handle it. If 'suspend' is invoked during the invocation of this method, its return value is ignored by Cocoa Scripting's built-in Apple event handling.
     * @return The converted Objective-C result.
     */
        Object perform_default_implementation() const;
        /**
     * @brief Calls `-[NSScriptCommand resumeExecutionWithResult:]`.
     * @details Resumes execution of a previously suspended command with a result. This method may be invoked in any thread, not just the one in which the corresponding invocation of 'suspendExecution' occurred.
     * @param result Argument converted to the Objective-C parameter of the same role.
     */
        void resume_execution_with_result(const Object& result) const;
        /**
     * @brief Calls `-[NSScriptCommand suspendExecution]`.
     * @details Suspends execution of this command. If the receiver is being executed in the current thread by Cocoa Scripting's built-in Apple event handling, suspend the execution of the command. A matching invocation of 'resumeExecutionWithResult:' must be made.
     */
        void suspend_execution() const;
        /**
     * @brief Returns the `appleEvent` property of `NSScriptCommand`.
     * @details The Apple event descriptor from which this command was constructed. Only available if the receiver was constructed by Cocoa Scripting's built-in Apple event handling.
     * @return The converted Objective-C result.
     */
        AppleEventDescriptor apple_event() const;
        /**
     * @brief Returns the `arguments` property of `NSScriptCommand`.
     * @details The arguments of the command.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> arguments() const;
        /**
     * @brief Sets the `arguments` property of `NSScriptCommand`.
     * @details The arguments of the command.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_arguments(const std::map<std::string, Object>& value) const;
        /**
     * @brief Returns the `commandDescription` property of `NSScriptCommand`.
     * @details The description of this script command.
     * @return The converted Objective-C result.
     */
        ScriptCommandDescription command_description() const;
        /**
     * @brief Returns the `directParameter` property of `NSScriptCommand`.
     * @details The object that corresponds to the direct parameter of the Apple event from which this command derives.
     * @return The converted Objective-C result.
     */
        Object direct_parameter() const;
        /**
     * @brief Sets the `directParameter` property of `NSScriptCommand`.
     * @details The object that corresponds to the direct parameter of the Apple event from which this command derives.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_direct_parameter(const Object& value) const;
        /**
     * @brief Returns the `evaluatedArguments` property of `NSScriptCommand`.
     * @details The arguments of the command, with any object specifiers already evaluated.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> evaluated_arguments() const;
        /**
     * @brief Returns the `evaluatedReceivers` property of `NSScriptCommand`.
     * @details If the direct parameter of the original event was an object specifier, returns the specified object or objects. Returns 'nil' if the direct parameter was not an object specifier or could not be evaluated.
     * @return The converted Objective-C result.
     */
        Object evaluated_receivers() const;
        /**
     * @brief Returns the `receiversSpecifier` property of `NSScriptCommand`.
     * @details The object specifier for the object or objects that will be given a chance to handle the command. If the direct parameter of the original event was an object specifier, 'setDirectParameter:' sends a 'setReceiversSpecifier:' message.
     * @return The converted Objective-C result.
     */
        ScriptObjectSpecifier receivers_specifier() const;
        /**
     * @brief Sets the `receiversSpecifier` property of `NSScriptCommand`.
     * @details The object specifier for the object or objects that will be given a chance to handle the command. If the direct parameter of the original event was an object specifier, 'setDirectParameter:' sends a 'setReceiversSpecifier:' message.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_receivers_specifier(const ScriptObjectSpecifier& value) const;
        /**
     * @brief Returns the `scriptErrorExpectedTypeDescriptor` property of `NSScriptCommand`.
     * @details An 'NSAppleEventDescriptor' that identifies the expected type when a type mismatch error occurs.
     * @return The converted Objective-C result.
     */
        AppleEventDescriptor script_error_expected_type_descriptor() const;
        /**
     * @brief Sets the `scriptErrorExpectedTypeDescriptor` property of `NSScriptCommand`.
     * @details An 'NSAppleEventDescriptor' that identifies the expected type when a type mismatch error occurs.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_script_error_expected_type_descriptor(const AppleEventDescriptor& value) const;
        /**
     * @brief Returns the `scriptErrorNumber` property of `NSScriptCommand`.
     * @details The error number associated with this command, if any.
     * @return The converted Objective-C result.
     */
        std::int64_t script_error_number() const;
        /**
     * @brief Sets the `scriptErrorNumber` property of `NSScriptCommand`.
     * @details The error number associated with this command, if any.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_script_error_number(std::int64_t value) const;
        /**
     * @brief Returns the `scriptErrorOffendingObjectDescriptor` property of `NSScriptCommand`.
     * @details An 'NSAppleEventDescriptor' that identifies the offending object when an error occurs.
     * @return The converted Objective-C result.
     */
        AppleEventDescriptor script_error_offending_object_descriptor() const;
        /**
     * @brief Sets the `scriptErrorOffendingObjectDescriptor` property of `NSScriptCommand`.
     * @details An 'NSAppleEventDescriptor' that identifies the offending object when an error occurs.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_script_error_offending_object_descriptor(const AppleEventDescriptor& value) const;
        /**
     * @brief Returns the `scriptErrorString` property of `NSScriptCommand`.
     * @details The error string associated with this command, if any.
     * @return The converted Objective-C result.
     */
        std::string script_error_string() const;
        /**
     * @brief Sets the `scriptErrorString` property of `NSScriptCommand`.
     * @details The error string associated with this command, if any.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_script_error_string(const std::string& value) const;
        /**
     * @brief Returns the `wellFormed` property of `NSScriptCommand`.
     * @details A Boolean value that indicates whether the command is well-formed according to its command description.
     * @return The converted Objective-C result.
     */
        bool is_well_formed() const;
    };
}
