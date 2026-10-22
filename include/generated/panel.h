#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/window.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSPanel` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Window.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Panel panel;
     * panel.set_becomes_key_only_if_needed(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Panel panel{};
     * panel.set_becomes_key_only_if_needed(true);
     * auto becomes_key_only_if_needed = panel.becomes_key_only_if_needed();
     * panel.set_floating_panel(true);
     * auto floating_panel = panel.is_floating_panel();
     * panel.set_works_when_modal(true);
     * auto works_when_modal = panel.works_when_modal();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspanel
     */
    class Panel : public Window
    {
    public:
        /// @brief Creates a new `NSPanel` instance and returns a handle to it.
        explicit Panel();
        /// @brief Creates a null handle that refers to no native object.
        Panel(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Panel(Adopt adopt);
        using Window::is_floating_panel;
        using Window::works_when_modal;
        /**
         * @brief Returns the `becomesKeyOnlyIfNeeded` property of `NSPanel`.
         * @return The converted Objective-C result.
         */
        bool becomes_key_only_if_needed() const;
        /**
         * @brief Sets the `becomesKeyOnlyIfNeeded` property of `NSPanel`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_becomes_key_only_if_needed(bool value) const;
        /**
         * @brief Returns the `floatingPanel` property of `NSPanel`.
         * @return The converted Objective-C result.
         */
        bool is_floating_panel() const;
        /**
         * @brief Sets the `floatingPanel` property of `NSPanel`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_floating_panel(bool value) const;
        /**
         * @brief Returns the `worksWhenModal` property of `NSPanel`.
         * @return The converted Objective-C result.
         */
        bool works_when_modal() const;
        /**
         * @brief Sets the `worksWhenModal` property of `NSPanel`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_works_when_modal(bool value) const;
    };
}
