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
     * @details The context in which the current script command is executed. An 'NSScriptExecutionContext' object is a shared instance (there is only one instance of the class) that represents the context in which the current script command is executed. 'NSScriptExecutionContext' tracks global state relating to the command being executed, especially the top-level container object (that is, the container implied by a specifier object that specifies no container) used in an evaluation of an ''NSScriptObjectSpecifier'' object. In most cases, the top-level container for a complete series of nested object specifiers is automatically set to the application object ('NSApp'), and you can get this object with the ''topLevelObject'' method. But you can also set this top-level container to something else (using ''topLevelObject'') if the situation warrants it. It is unlikely that you will need to subclass 'NSScriptExecutionContext'.
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
         * @details Returns the shared script execution context.
         * @return The converted Objective-C result.
         */
        static ScriptExecutionContext shared_script_execution_context();
        /**
         * @brief Returns the `objectBeingTested` property of `NSScriptExecutionContext`.
         * @details The object currently being tested by an 'NSWhoseSpecifier'.
         * @return The converted Objective-C result.
         */
        Object object_being_tested() const;
        /**
         * @brief Sets the `objectBeingTested` property of `NSScriptExecutionContext`.
         * @details The object currently being tested by an 'NSWhoseSpecifier'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_object_being_tested(const Object& value) const;
        /**
         * @brief Returns the `rangeContainerObject` property of `NSScriptExecutionContext`.
         * @details The container object for the current range specifier being evaluated.
         * @return The converted Objective-C result.
         */
        Object range_container_object() const;
        /**
         * @brief Sets the `rangeContainerObject` property of `NSScriptExecutionContext`.
         * @details The container object for the current range specifier being evaluated.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_range_container_object(const Object& value) const;
        /**
         * @brief Returns the `topLevelObject` property of `NSScriptExecutionContext`.
         * @details The top-level object in the current scripting context.
         * @return The converted Objective-C result.
         */
        Object top_level_object() const;
        /**
         * @brief Sets the `topLevelObject` property of `NSScriptExecutionContext`.
         * @details The top-level object in the current scripting context.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_top_level_object(const Object& value) const;
    };
}
