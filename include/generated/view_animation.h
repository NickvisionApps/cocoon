#pragma once

#include "generated/animation.h"
#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSViewAnimation` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Animation.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ViewAnimation view_animation;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsviewanimation
     */
    class ViewAnimation : public Animation
    {
    public:
        /// @brief Creates a new `NSViewAnimation` instance and returns a handle to it.
        explicit ViewAnimation(const std::vector<std::map<std::string, Object>>& view_animations);
        /// @brief Creates a new `NSViewAnimation` instance and returns a handle to it.
        explicit ViewAnimation();
        /// @brief Creates a null handle that refers to no native object.
        ViewAnimation(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ViewAnimation(Adopt adopt);
        /**
     * @brief Returns the `viewAnimations` property of `NSViewAnimation`.
     * @return The converted Objective-C result.
     */
        std::vector<std::map<std::string, Object>> view_animations() const;
        /**
     * @brief Sets the `viewAnimations` property of `NSViewAnimation`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_view_animations(const std::vector<std::map<std::string, Object>>& value) const;
    };
}
