#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AppleEventDescriptor;
    class AttributedString;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSAppleScript` (Foundation).
     * @details An object that provides the ability to load, compile, and execute scripts. This class provides applications with the ability to - load a script from a URL or from a text string - compile or execute a script or an individual Apple event - obtain an 'NSAppleEventDescriptor' containing the reply from an executed script or event - obtain an attributed string for a compiled script, suitable for display in a script editor - obtain various kinds of information about any errors that may occur > Important: > 'NSAppleScript' provides the ''executeAppleEvent(:error:)'' method so that you can send an Apple event to invoke a handler in a script. (In an AppleScript script, a handler is the equivalent of a function.) However, you cannot use this method to send Apple events to other applications. When you create an instance of 'NSAppleScript' object, you can use a URL to specify a script that can be in either text or compiled form, or you can supply the script as a string. Should an error occur when compiling or executing the script, several of the methods return a dictionary containing error information. The keys for obtaining error information, such as ''errorMessage'', are described in the Constants section. See also NSAppleScript Additions Reference in the Application Kit framework, which defines a method that returns the syntax-highlighted source code for a script.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::AppleScript apple_script;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsapplescript
     */
    class AppleScript : public Object
    {
    public:
        /// @brief Creates a new `NSAppleScript` instance and returns a handle to it.
        explicit AppleScript(const URL& url, std::map<std::string, Object>& error_info);
        /// @brief Creates a new `NSAppleScript` instance and returns a handle to it.
        explicit AppleScript(const std::string& source);
        /// @brief Creates a new `NSAppleScript` instance and returns a handle to it.
        explicit AppleScript();
        /// @brief Creates a null handle that refers to no native object.
        AppleScript(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit AppleScript(Adopt adopt);
        /**
     * @brief Calls `-[NSAppleScript compileAndReturnError:]`.
     * @details Compiles the receiver, if it is not already compiled. - Parameter errorInfo: On return, if an error occurs, a pointer to an error information dictionary. - Returns: 'YES' for success or if the script was already compiled, 'NO' otherwise.
     * @param error_info Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool compile_and_return_error(std::map<std::string, Object>& error_info) const;
        /**
     * @brief Calls `-[NSAppleScript executeAndReturnError:]`.
     * @details Executes the receiver, compiling it first if it is not already compiled. - Parameter errorInfo: On return, if an error occurs, a pointer to an error information dictionary. - Returns: The result of executing the event, or 'nil' if an error occurs. Any changes to property values caused by executing the script do not persist.
     * @param error_info Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        AppleEventDescriptor execute_and_return_error(std::map<std::string, Object>& error_info) const;
        /**
     * @brief Calls `-[NSAppleScript executeAppleEvent:error:]`.
     * @details Executes an Apple event in the context of the receiver, as a means of allowing the application to invoke a handler in the script. - Parameters: - event: The Apple event to execute. - errorInfo: On return, if an error occurs, a pointer to an error information dictionary. - Returns: The result of executing the event, or 'nil' if an error occurs. Compiles the receiver before executing it if it is not already compiled. > Important: You cannot use this method to send Apple events to other applications.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param error_info Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        AppleEventDescriptor execute_apple_event(const AppleEventDescriptor& event, std::map<std::string, Object>& error_info) const;
        /**
     * @brief Returns the `compiled` property of `NSAppleScript`.
     * @details A Boolean value that indicates whether the receiver's script has been compiled.
     * @return The converted Objective-C result.
     */
        bool is_compiled() const;
        /**
     * @brief Returns the `richTextSource` property of `NSAppleScript`.
     * @return The converted Objective-C result.
     */
        AttributedString rich_text_source() const;
        /**
     * @brief Returns the `source` property of `NSAppleScript`.
     * @details The script source for the receiver. It is possible for an 'NSAppleScript' that has been instantiated with '-initWithContentsOfURL:error:' to be a script for which the source code is not available but is nonetheless executable.
     * @return The converted Objective-C result.
     */
        std::string source() const;
    };
}
