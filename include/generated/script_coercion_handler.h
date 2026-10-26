#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSScriptCoercionHandler` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScriptCoercionHandler script_coercion_handler;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScriptCoercionHandler script_coercion_handler{};
     * auto made_0 = cocoon::ScriptCoercionHandler::shared_coercion_handler();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsscriptcoercionhandler
     */
    class ScriptCoercionHandler : public Object
    {
    public:
        /// @brief Creates a new `NSScriptCoercionHandler` instance and returns a handle to it.
        explicit ScriptCoercionHandler();
        /// @brief Creates a null handle that refers to no native object.
        ScriptCoercionHandler(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScriptCoercionHandler(Adopt adopt);
        /**
         * @brief Calls `-[NSScriptCoercionHandler coerceValue:toClass:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param to_class Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object coerce_value(const Object& value, const std::string& to_class) const;
        /**
         * @brief Calls `-[NSScriptCoercionHandler registerCoercer:selector:toConvertFromClass:toClass:]`.
         * @param coercer Argument converted to the Objective-C parameter of the same role.
         * @param selector Argument converted to the Objective-C parameter of the same role.
         * @param from_class Argument converted to the Objective-C parameter of the same role.
         * @param to_class Argument converted to the Objective-C parameter of the same role.
         */
        void register_coercer(const Object& coercer, const std::string& selector, const std::string& from_class, const std::string& to_class) const;
        /**
         * @brief Calls `+[NSScriptCoercionHandler sharedCoercionHandler]`.
         * @return The converted Objective-C result.
         */
        static ScriptCoercionHandler shared_coercion_handler();
    };
}
