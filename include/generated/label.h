#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text_field.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief A non-editable text label.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TextField.
     *
     * @par Example
     * @code
     * cocoon::Label label("Status");
     * label.set_string_value("Ready");
     * label.set_font(cocoon::Font::bold_system_font_of_size(14));
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextfield
     */
    class Label : public TextField
    {
    public:
        /// @brief Creates a new `NSTextField` instance and returns a handle to it.
        explicit Label(const std::string& text = "");
        /// @brief Creates a null handle that refers to no native object.
        Label(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Label(Adopt adopt);
    };
}
