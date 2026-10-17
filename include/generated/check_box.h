#pragma once

#include "generated/availability.h"
#include "generated/button.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief A check box button.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Button.
     *
     * @par Example
     * @code
     * cocoon::CheckBox check("Enable feature");
     * check.toggled().connect([](bool on) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CheckBox check_box{"text"};
     * check_box.toggled().connect([](bool a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsbutton
     */
    class CheckBox : public Button
    {
    public:
        /// @brief Creates a new `NSButton` instance and returns a handle to it.
        explicit CheckBox(const std::string& title = "");
        /// @brief Creates a null handle that refers to no native object.
        CheckBox(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CheckBox(Adopt adopt);
        /// @brief Signal `toggled`: connect a callback with `toggled().connect(...)`.
        Signal<CheckBox, void(bool)> toggled() const
        {
            return Signal<CheckBox, void(bool)>(handle(), "toggled");
        }

    protected:
        static void bind_action_(void* native);
    };
}
