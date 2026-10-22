#pragma once

#include "generated/availability.h"
#include "generated/control.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief An on/off switch (NSSwitch).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * cocoon::Switch toggle;
     * toggle.set_on(true);
     * toggle.toggled().connect([](bool on) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Switch switch_{};
     * switch_.toggled().connect([](bool a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsswitch
     */
    class Switch : public Control
    {
    public:
        /// @brief Creates a new `NSSwitch` instance and returns a handle to it.
        explicit Switch();
        /// @brief Creates a null handle that refers to no native object.
        Switch(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Switch(Adopt adopt);
        /**
         * @brief Returns the `state` property of `NSSwitch`.
         * @details The current position of the switch. The values 'NSControlStateValueOff' and 'NSControlStateValueOn' indicate that the switch is in either the off or on position respectively. If the state property is set to any other value, it is interpreted as on. If set through the animator proxy, the switch animates to the new value.
         * @return The converted Objective-C result.
         */
        ControlState state() const;
        /**
         * @brief Sets the `state` property of `NSSwitch`.
         * @details The current position of the switch. The values 'NSControlStateValueOff' and 'NSControlStateValueOn' indicate that the switch is in either the off or on position respectively. If the state property is set to any other value, it is interpreted as on. If set through the animator proxy, the switch animates to the new value.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_state(ControlState value) const;
        /// @brief Convenience helper `is_on` provided by cocoon.
        bool is_on() const;
        /// @brief Convenience helper `set_on` provided by cocoon.
        void set_on(bool on) const;
        /// @brief Signal `toggled`: connect a callback with `toggled().connect(...)`.
        Signal<Switch, void(bool)> toggled() const
        {
            return Signal<Switch, void(bool)>(handle(), "toggled");
        }

    protected:
        static void bind_action_(void* native);
    };
}
