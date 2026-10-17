#pragma once

#include "generated/availability.h"
#include "generated/button.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief A radio button.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Button.
     *
     * @par Example
     * @code
     * cocoon::RadioButton radio("Option A");
     * radio.toggled().connect([](bool on) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::RadioButton radio_button{"text"};
     * radio_button.toggled().connect([](bool a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsbutton
     */
    class RadioButton : public Button
    {
    public:
        /// @brief Creates a new `NSButton` instance and returns a handle to it.
        explicit RadioButton(const std::string& title = "");
        /// @brief Creates a null handle that refers to no native object.
        RadioButton(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit RadioButton(Adopt adopt);
        /// @brief Signal `toggled`: connect a callback with `toggled().connect(...)`.
        Signal<RadioButton, void(bool)> toggled() const
        {
            return Signal<RadioButton, void(bool)>(handle(), "toggled");
        }

    protected:
        static void bind_action_(void* native);
    };
}
