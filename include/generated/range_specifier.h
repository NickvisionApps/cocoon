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
     * @brief C++ handle for the Objective-C class `NSRangeSpecifier` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptObjectSpecifier.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::RangeSpecifier range_specifier;
     * range_specifier.set_end_specifier(cocoon::ScriptObjectSpecifier());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::RangeSpecifier range_specifier{};
     * range_specifier.set_end_specifier(cocoon::ScriptObjectSpecifier());
     * auto end_specifier = range_specifier.end_specifier();
     * range_specifier.set_start_specifier(cocoon::ScriptObjectSpecifier());
     * auto start_specifier = range_specifier.start_specifier();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsrangespecifier
     */
    class RangeSpecifier : public ScriptObjectSpecifier
    {
    public:
        /// @brief Creates a new `NSRangeSpecifier` instance and returns a handle to it.
        explicit RangeSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property, const ScriptObjectSpecifier& start_spec, const ScriptObjectSpecifier& end_spec);
        /// @brief Creates a new `NSRangeSpecifier` instance and returns a handle to it.
        explicit RangeSpecifier();
        /// @brief Creates a null handle that refers to no native object.
        RangeSpecifier(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit RangeSpecifier(Adopt adopt);
        /**
     * @brief Returns the `endSpecifier` property of `NSRangeSpecifier`.
     * @return The converted Objective-C result.
     */
        ScriptObjectSpecifier end_specifier() const;
        /**
     * @brief Sets the `endSpecifier` property of `NSRangeSpecifier`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_end_specifier(const ScriptObjectSpecifier& value) const;
        /**
     * @brief Returns the `startSpecifier` property of `NSRangeSpecifier`.
     * @return The converted Objective-C result.
     */
        ScriptObjectSpecifier start_specifier() const;
        /**
     * @brief Sets the `startSpecifier` property of `NSRangeSpecifier`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_start_specifier(const ScriptObjectSpecifier& value) const;
    };
}
