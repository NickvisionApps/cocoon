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
     * @brief C++ handle for the Objective-C class `NSShadow` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Shadow shadow;
     * shadow.set_shadow_blur_radius(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Shadow shadow{};
     * shadow.set_shadow_blur_radius(1);
     * auto shadow_blur_radius = shadow.shadow_blur_radius();
     * shadow.set_shadow_color(cocoon::Color());
     * auto shadow_color = shadow.shadow_color();
     * shadow.set_shadow_offset({100, 100});
     * auto shadow_offset = shadow.shadow_offset();
     * shadow.set();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsshadow
     */
    class Shadow : public Object
    {
    public:
        /// @brief Creates a new `NSShadow` instance and returns a handle to it.
        explicit Shadow();
        /// @brief Creates a null handle that refers to no native object.
        Shadow(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Shadow(Adopt adopt);
        /**
         * @brief Calls `-[NSShadow set]`.
         */
        void set() const;
        /**
         * @brief Returns the `shadowBlurRadius` property of `NSShadow`.
         * @return The converted Objective-C result.
         */
        double shadow_blur_radius() const;
        /**
         * @brief Sets the `shadowBlurRadius` property of `NSShadow`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_shadow_blur_radius(double value) const;
        /**
         * @brief Returns the `shadowColor` property of `NSShadow`.
         * @return The converted Objective-C result.
         */
        Color shadow_color() const;
        /**
         * @brief Sets the `shadowColor` property of `NSShadow`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_shadow_color(const Color& value) const;
        /**
         * @brief Returns the `shadowOffset` property of `NSShadow`.
         * @return The converted Objective-C result.
         */
        Size shadow_offset() const;
        /**
         * @brief Sets the `shadowOffset` property of `NSShadow`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_shadow_offset(const Size& value) const;
    };
}
