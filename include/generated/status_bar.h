#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class StatusItem;

    /**
     * @brief C++ handle for the Objective-C class `NSStatusBar` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::StatusBar status_bar;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::StatusBar status_bar{};
     * status_bar.remove_status_item(cocoon::StatusItem());
     * status_bar.status_item_with_length(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsstatusbar
     */
    class StatusBar : public Object
    {
    public:
        /// @brief Creates a new `NSStatusBar` instance and returns a handle to it.
        explicit StatusBar();
        /// @brief Creates a null handle that refers to no native object.
        StatusBar(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit StatusBar(Adopt adopt);
        /**
     * @brief Calls `-[NSStatusBar removeStatusItem:]`.
     * @param item Argument converted to the Objective-C parameter of the same role.
     */
        void remove_status_item(const StatusItem& item) const;
        /**
     * @brief Calls `-[NSStatusBar statusItemWithLength:]`.
     * @param length Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        StatusItem status_item_with_length(double length) const;
        /**
     * @brief Returns the `systemStatusBar` property of `NSStatusBar`.
     * @return The converted Objective-C result.
     */
        static StatusBar system_status_bar();
        /**
     * @brief Returns the `thickness` property of `NSStatusBar`.
     * @return The converted Objective-C result.
     */
        double thickness() const;
        /**
     * @brief Returns the `vertical` property of `NSStatusBar`.
     * @return The converted Objective-C result.
     */
        bool is_vertical() const;
    };
}
