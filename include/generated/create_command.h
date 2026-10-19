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
     * @return The converted Objective-C result.
     */
        ScriptClassDescription create_class_description() const;
        /**
     * @brief Returns the `resolvedKeyDictionary` property of `NSCreateCommand`.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> resolved_key_dictionary() const;
    };
}
