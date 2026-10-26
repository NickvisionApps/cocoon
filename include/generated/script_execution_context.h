#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSScriptExecutionContext` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScriptExecutionContext script_execution_context;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScriptExecutionContext script_execution_context{};
     * auto made_0 = cocoon::ScriptExecutionContext::shared_script_execution_context();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsscriptexecutioncontext
     */
    class ScriptExecutionContext : public Object
    {
    public:
        /// @brief Creates a new `NSScriptExecutionContext` instance and returns a handle to it.
        explicit ScriptExecutionContext();
        /// @brief Creates a null handle that refers to no native object.
        ScriptExecutionContext(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScriptExecutionContext(Adopt adopt);
        /**
         * @brief Calls `+[NSScriptExecutionContext sharedScriptExecutionContext]`.
         * @return The converted Objective-C result.
         */
        static ScriptExecutionContext shared_script_execution_context();
        /**
         * @brief Returns the `objectBeingTested` property of `NSScriptExecutionContext`.
         * @return The converted Objective-C result.
         */
        Object object_being_tested() const;
        /**
         * @brief Sets the `objectBeingTested` property of `NSScriptExecutionContext`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_object_being_tested(const Object& value) const;
        /**
         * @brief Returns the `rangeContainerObject` property of `NSScriptExecutionContext`.
         * @return The converted Objective-C result.
         */
        Object range_container_object() const;
        /**
         * @brief Sets the `rangeContainerObject` property of `NSScriptExecutionContext`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_range_container_object(const Object& value) const;
        /**
         * @brief Returns the `topLevelObject` property of `NSScriptExecutionContext`.
         * @return The converted Objective-C result.
         */
        Object top_level_object() const;
        /**
         * @brief Sets the `topLevelObject` property of `NSScriptExecutionContext`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_top_level_object(const Object& value) const;
    };
}
