#pragma once

#include "generated/availability.h"
#include "generated/button.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSStatusBarButton` (AppKit).
     * @details Status bar buttons are the visual representation of 'NSStatusItem's, and are primarily displayed on the right side of the menu bar. When a template image is set as the 'image' property of the status bar button, it is rendered with the correct menu bar style. This guarantees that the button will look correct in various button states and appearances (such as dark menu bar).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Button.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::StatusBarButton status_bar_button;
     * status_bar_button.set_appears_disabled(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::StatusBarButton status_bar_button{};
     * status_bar_button.set_appears_disabled(true);
     * auto appears_disabled = status_bar_button.appears_disabled();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsstatusbarbutton
     */
    class StatusBarButton : public Button
    {
    public:
        /// @brief Creates a new `NSStatusBarButton` instance and returns a handle to it.
        explicit StatusBarButton();
        /// @brief Creates a null handle that refers to no native object.
        StatusBarButton(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit StatusBarButton(Adopt adopt);
        /**
         * @brief Returns the `appearsDisabled` property of `NSStatusBarButton`.
         * @details Determines whether the status bar icon has a disabled/off appearance while still being functional, such as allowing selection and actions. The default value is 'false'.
         * @return The converted Objective-C result.
         */
        bool appears_disabled() const;
        /**
         * @brief Sets the `appearsDisabled` property of `NSStatusBarButton`.
         * @details Determines whether the status bar icon has a disabled/off appearance while still being functional, such as allowing selection and actions. The default value is 'false'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_appears_disabled(bool value) const;
    };
}
