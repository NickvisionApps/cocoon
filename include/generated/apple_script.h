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
         * @param error_info Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool compile_and_return_error(std::map<std::string, Object>& error_info) const;
        /**
         * @brief Calls `-[NSAppleScript executeAndReturnError:]`.
         * @param error_info Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor execute_and_return_error(std::map<std::string, Object>& error_info) const;
        /**
         * @brief Calls `-[NSAppleScript executeAppleEvent:error:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         * @param error_info Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor execute_apple_event(const AppleEventDescriptor& event, std::map<std::string, Object>& error_info) const;
        /**
         * @brief Returns the `compiled` property of `NSAppleScript`.
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
         * @return The converted Objective-C result.
         */
        std::string source() const;
    };
}
