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
     * @brief C++ handle for the Objective-C class `NSUniqueIDSpecifier` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptObjectSpecifier.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UniqueIDSpecifier unique_id_specifier;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsuniqueidspecifier
     */
    class UniqueIDSpecifier : public ScriptObjectSpecifier
    {
    public:
        /// @brief Creates a new `NSUniqueIDSpecifier` instance and returns a handle to it.
        explicit UniqueIDSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property, const Object& unique_id);
        /// @brief Creates a new `NSUniqueIDSpecifier` instance and returns a handle to it.
        explicit UniqueIDSpecifier();
        /// @brief Creates a null handle that refers to no native object.
        UniqueIDSpecifier(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UniqueIDSpecifier(Adopt adopt);
        /**
     * @brief Returns the `uniqueID` property of `NSUniqueIDSpecifier`.
     * @return The converted Objective-C result.
     */
        Object unique_id() const;
        /**
     * @brief Sets the `uniqueID` property of `NSUniqueIDSpecifier`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_unique_id(const Object& value) const;
    };
}
