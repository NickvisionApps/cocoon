#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSTrackingArea` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TrackingArea tracking_area;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstrackingarea
     */
    class TrackingArea : public Object
    {
    public:
        /// @brief Creates a new `NSTrackingArea` instance and returns a handle to it.
        explicit TrackingArea(const Rect& rect, TrackingAreaOptions options, const Object& owner, const std::vector<std::pair<Object, Object>>& user_info);
        /// @brief Creates a new `NSTrackingArea` instance and returns a handle to it.
        explicit TrackingArea();
        /// @brief Creates a null handle that refers to no native object.
        TrackingArea(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TrackingArea(Adopt adopt);
        /**
     * @brief Returns the `options` property of `NSTrackingArea`.
     * @return The converted Objective-C result.
     */
        TrackingAreaOptions options() const;
        /**
     * @brief Returns the `owner` property of `NSTrackingArea`.
     * @return The converted Objective-C result.
     */
        Object owner() const;
        /**
     * @brief Returns the `rect` property of `NSTrackingArea`.
     * @return The converted Objective-C result.
     */
        Rect rect() const;
        /**
     * @brief Returns the `userInfo` property of `NSTrackingArea`.
     * @return The converted Objective-C result.
     */
        std::vector<std::pair<Object, Object>> user_info() const;
    };
}
