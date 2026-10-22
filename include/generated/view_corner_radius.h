#pragma once

#include "generated/availability.h"

#ifdef COCOON_MACOS_27
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSViewCornerRadius` (AppKit).
     * @details Represents a radius used to round a corner. It supports fixed and adaptive configurations.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ViewCornerRadius view_corner_radius(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ViewCornerRadius view_corner_radius(nullptr);
     * auto made_0 = cocoon::ViewCornerRadius::container_concentric_radius_with_minimum(1);
     * auto made_1 = cocoon::ViewCornerRadius::fixed_radius(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsviewcornerradius
     */
    class ViewCornerRadius : public Object
    {
    public:
        ViewCornerRadius();
        /// @brief Creates a null handle that refers to no native object.
        ViewCornerRadius(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ViewCornerRadius(Adopt adopt);
#ifdef COCOON_MACOS_27
        /**
         * @brief Calls `+[NSViewCornerRadius containerConcentricRadiusWithMinimum:]`.
         * @details A dynamic corner radius calculated based on the view’s container shape and limited to the provided minimum radius. - Parameter minimumRadius: Corner radius that’s applied when a corner of the view’s container is smaller than the specified radius.
         * @param minimum_radius Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static ViewCornerRadius container_concentric_radius_with_minimum(double minimum_radius);
#endif

#ifdef COCOON_MACOS_27
        /**
         * @brief Calls `+[NSViewCornerRadius fixedRadius:]`.
         * @details Shorthand initializer for a configuration where all four corners are using a fixed corner radius in points. - Parameter radius: Radius for all the corners.
         * @param radius Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static ViewCornerRadius fixed_radius(double radius);
#endif

#ifdef COCOON_MACOS_27
        /**
         * @brief Returns the `containerConcentricRadius` property of `NSViewCornerRadius`.
         * @details A dynamic corner radius calculated based on the view’s container shape.
         * @return The converted Objective-C result.
         */
        static ViewCornerRadius container_concentric_radius();
#endif
    };
}

#endif
