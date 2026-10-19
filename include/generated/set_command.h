#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/script_command.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ScriptObjectSpecifier;

    /**
     * @brief C++ handle for the Objective-C class `NSSetCommand` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptCommand.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SetCommand set_command;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SetCommand set_command{};
     * set_command.set_receivers_specifier(cocoon::ScriptObjectSpecifier());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nssetcommand
     */
    class SetCommand : public ScriptCommand
    {
    public:
        /// @brief Creates a new `NSSetCommand` instance and returns a handle to it.
        explicit SetCommand();
        /// @brief Creates a null handle that refers to no native object.
        SetCommand(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SetCommand(Adopt adopt);
        using ScriptCommand::set_receivers_specifier;
        /**
     * @brief Calls `-[NSSetCommand setReceiversSpecifier:]`.
     * @param receivers_ref Argument converted to the Objective-C parameter of the same role.
     */
        void set_receivers_specifier(const ScriptObjectSpecifier& receivers_ref) const;
        /**
     * @brief Returns the `keySpecifier` property of `NSSetCommand`.
     * @return The converted Objective-C result.
     */
        ScriptObjectSpecifier key_specifier() const;
    };
}
