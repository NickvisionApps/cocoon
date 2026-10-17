#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSTouch` (AppKit).
     * @details Unlike the iPhone, NSTouch objects do not persist for the life of the touch.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Touch touch;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Touch touch{};
     * touch.location_in_view(cocoon::View());
     * touch.previous_location_in_view(cocoon::View());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstouch
     */
    class Touch : public Object
    {
    public:
        /// @brief Creates a new `NSTouch` instance and returns a handle to it.
        explicit Touch();
        /// @brief Creates a null handle that refers to no native object.
        Touch(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Touch(Adopt adopt);
        /**
     * @brief Calls `-[NSTouch locationInView:]`.
     * @details These two methods are only valid for Direct touches. A nil view means the touch location in the root container of touch.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point location_in_view(const View& view) const;
        /**
     * @brief Calls `-[NSTouch previousLocationInView:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point previous_location_in_view(const View& view) const;
        /**
     * @brief Returns the `device` property of `NSTouch`.
     * @details Properties of the underlying touch device
     * @return The converted Objective-C result.
     */
        Object device() const;
        /**
     * @brief Returns the `deviceSize` property of `NSTouch`.
     * @details The range of the touch device in points (72ppi). Note: 0,0 is the lower left of the surface.
     * @return The converted Objective-C result.
     */
        Size device_size() const;
        /**
     * @brief Returns the `normalizedPosition` property of `NSTouch`.
     * @return The converted Objective-C result.
     */
        Point normalized_position() const;
        /**
     * @brief Returns the `phase` property of `NSTouch`.
     * @return The converted Objective-C result.
     */
        TouchPhase phase() const;
        /**
     * @brief Returns the `resting` property of `NSTouch`.
     * @return The converted Objective-C result.
     */
        bool is_resting() const;
        /**
     * @brief Returns the `type` property of `NSTouch`.
     * @details A touch can only be one type at a time
     * @return The converted Objective-C result.
     */
        TouchType type() const;
    };
}
