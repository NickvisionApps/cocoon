#pragma once

#include "generated/enums.h"
#include "generated/script_command.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ScriptObjectSpecifier;

    /**
     * @brief C++ handle for the Objective-C class `NSSetCommand` (Foundation).
     * @details A command that sets one or more attributes or relationships to one or more values. An instance of 'NSSetCommand' sets one or more attributes or relationships to one or more values; for example, it may set the (x, y) coordinates for a window's position or set the name of a document. 'NSSetCommand' is part of Cocoa's built-in scripting support. It works automatically to support the 'set' command through key-value coding. Most applications don't need to subclass 'NSSetCommand' or call its methods. 'NSSetCommand' uses available scripting class descriptions to determine whether it should set a value for an attribute (or property), or set a value for all elements (to-many objects). For the latter, it invokes \<doc://com.apple.documentation/documentation/objectivec/nsobject-swift.class/replacevalue(at:inpropertywithkey:withvalue:)>; for the former, it invokes \<doc://com.apple.documentation/documentation/objectivec/nsobject-swift.class/setvalue(:forkey:)> (or, if the receiver overrides \<doc://com.apple.documentation/documentation/objectivec/nsobject-swift.class/takevalue(:forkey:)>, it invokes that method, to support backward binary compatibility.) For information on working with 'set' commands, see [Getting and Setting Properties and Elements](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_get_set/SAppsGetSet.html\#//apple_ref/doc/uid/TP40002164-CH18) in [Cocoa Scripting Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_intro/SAppsIntro.html\#//apple_ref/doc/uid/TP40002164).
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
     * @details Splits off the inner-most child specifier from the receivers specifier.
     * @param receivers_ref Argument converted to the Objective-C parameter of the same role.
     */
        void set_receivers_specifier(const ScriptObjectSpecifier& receivers_ref) const;
        /**
     * @brief Returns the `keySpecifier` property of `NSSetCommand`.
     * @details The key specifier for the set operation.
     * @return The converted Objective-C result.
     */
        ScriptObjectSpecifier key_specifier() const;
    };
}
