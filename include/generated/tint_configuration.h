#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Color;

    /**
     * @brief C++ handle for the Objective-C class `NSTintConfiguration` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TintConfiguration tint_configuration;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstintconfiguration
     */
    class TintConfiguration : public Object
    {
    public:
        /// @brief Creates a new `NSTintConfiguration` instance and returns a handle to it.
        explicit TintConfiguration(const Color& color);
        /// @brief Creates a new `NSTintConfiguration` instance and returns a handle to it.
        explicit TintConfiguration();
        /// @brief Creates a null handle that refers to no native object.
        TintConfiguration(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TintConfiguration(Adopt adopt);
        /**
     * @brief Returns the `adaptsToUserAccentColor` property of `NSTintConfiguration`.
     * @details If YES, the tint configuration alters its effect based on the user's preferred Accent Color. Otherwise, the tint configuration produces a constant effect regardless of the Accent Color preference.
     * @return The converted Objective-C result.
     */
        bool adapts_to_user_accent_color() const;
        /**
     * @brief Returns the `baseTintColor` property of `NSTintConfiguration`.
     * @details The base NSColor supplied when creating the tint configuration object. If the receiver wasn't created using a base NSColor, this property returns nil.
     * @return The converted Objective-C result.
     */
        Color base_tint_color() const;
        /**
     * @brief Returns the `defaultTintConfiguration` property of `NSTintConfiguration`.
     * @details Specifies that content should be tinted using the system default for its context. For example, a source list icon's default tint matches the active Accent Color.
     * @return The converted Objective-C result.
     */
        static TintConfiguration default_tint_configuration();
        /**
     * @brief Returns the `equivalentContentTintColor` property of `NSTintConfiguration`.
     * @details An equivalent NSColor matching the effective content tint of the receiver. If the receiver can't be represented as a NSColor, this property returns nil.
     * @return The converted Objective-C result.
     */
        Color equivalent_content_tint_color() const;
        /**
     * @brief Returns the `monochromeTintConfiguration` property of `NSTintConfiguration`.
     * @details Specifies that content should prefer a monochrome appearance. Monochrome content remains monochrome regardless of the system Accent Color.
     * @return The converted Objective-C result.
     */
        static TintConfiguration monochrome_tint_configuration();
    };
}
