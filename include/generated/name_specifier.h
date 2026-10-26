#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/script_object_specifier.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ScriptClassDescription;
    class ScriptObjectSpecifier;

    /**
     * @brief C++ handle for the Objective-C class `NSNameSpecifier` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptObjectSpecifier.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::NameSpecifier name_specifier;
     * name_specifier.set_name("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::NameSpecifier name_specifier{};
     * name_specifier.set_name("text");
     * auto name = name_specifier.name();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsnamespecifier
     */
    class NameSpecifier : public ScriptObjectSpecifier
    {
    public:
        /// @brief Creates a new `NSNameSpecifier` instance and returns a handle to it.
        explicit NameSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property, const std::string& name);
        /// @brief Creates a new `NSNameSpecifier` instance and returns a handle to it.
        explicit NameSpecifier();
        /// @brief Creates a null handle that refers to no native object.
        NameSpecifier(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit NameSpecifier(Adopt adopt);
        /**
         * @brief Returns the `name` property of `NSNameSpecifier`.
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Sets the `name` property of `NSNameSpecifier`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_name(const std::string& value) const;
    };
}
