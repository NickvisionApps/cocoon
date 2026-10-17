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
     * @brief C++ handle for the Objective-C class `NSRelativeSpecifier` (Foundation).
     * @details A specifier that indicates an object in a collection by its position relative to another object. You don't normally subclass 'NSRelativeSpecifier'.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptObjectSpecifier.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::RelativeSpecifier relative_specifier;
     * relative_specifier.set_base_specifier(cocoon::ScriptObjectSpecifier());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::RelativeSpecifier relative_specifier{};
     * relative_specifier.set_base_specifier(cocoon::ScriptObjectSpecifier());
     * auto base_specifier = relative_specifier.base_specifier();
     * relative_specifier.set_relative_position(cocoon::RelativePosition::After);
     * auto relative_position = relative_specifier.relative_position();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsrelativespecifier
     */
    class RelativeSpecifier : public ScriptObjectSpecifier
    {
    public:
        /// @brief Creates a new `NSRelativeSpecifier` instance and returns a handle to it.
        explicit RelativeSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property, RelativePosition rel_pos, const ScriptObjectSpecifier& base_specifier);
        /// @brief Creates a new `NSRelativeSpecifier` instance and returns a handle to it.
        explicit RelativeSpecifier();
        /// @brief Creates a null handle that refers to no native object.
        RelativeSpecifier(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit RelativeSpecifier(Adopt adopt);
        /**
     * @brief Returns the `baseSpecifier` property of `NSRelativeSpecifier`.
     * @details The specifier for the base object relative to which the target is located.
     * @return The converted Objective-C result.
     */
        ScriptObjectSpecifier base_specifier() const;
        /**
     * @brief Sets the `baseSpecifier` property of `NSRelativeSpecifier`.
     * @details The specifier for the base object relative to which the target is located.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_base_specifier(const ScriptObjectSpecifier& value) const;
        /**
     * @brief Returns the `relativePosition` property of `NSRelativeSpecifier`.
     * @details The relative position (before or after) of the object to be located.
     * @return The converted Objective-C result.
     */
        RelativePosition relative_position() const;
        /**
     * @brief Sets the `relativePosition` property of `NSRelativeSpecifier`.
     * @details The relative position (before or after) of the object to be located.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_relative_position(RelativePosition value) const;
    };
}
