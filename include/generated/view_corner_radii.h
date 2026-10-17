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
     * @brief C++ handle for the Objective-C class `NSViewCornerRadii` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ViewCornerRadii view_corner_radii(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsviewcornerradii
     */
    class ViewCornerRadii : public Object
    {
    public:
        ViewCornerRadii();
        /// @brief Creates a null handle that refers to no native object.
        ViewCornerRadii(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ViewCornerRadii(Adopt adopt);
        /**
     * @brief Returns the `bottomLeft` property of `NSViewCornerRadii`.
     * @details Radius of the bottom left corner of the view.
     * @return The converted Objective-C result.
     */
        double bottom_left() const;
        /**
     * @brief Returns the `bottomRight` property of `NSViewCornerRadii`.
     * @details Radius of the bottom right corner of the view.
     * @return The converted Objective-C result.
     */
        double bottom_right() const;
        /**
     * @brief Returns the `topLeft` property of `NSViewCornerRadii`.
     * @details Radius of the top left corner of the view.
     * @return The converted Objective-C result.
     */
        double top_left() const;
        /**
     * @brief Returns the `topRight` property of `NSViewCornerRadii`.
     * @details Radius of the top right corner of the view.
     * @return The converted Objective-C result.
     */
        double top_right() const;
    };
}

#endif