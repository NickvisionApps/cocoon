#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text_field.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief A password style text field.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TextField.
     *
     * @par Example
     * @code
     * cocoon::SecureTextField password;
     * password.set_placeholder_string("Password");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssecuretextfield
     */
    class SecureTextField : public TextField
    {
    public:
        /// @brief Creates a new `NSSecureTextField` instance and returns a handle to it.
        explicit SecureTextField();
        /// @brief Creates a null handle that refers to no native object.
        SecureTextField(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SecureTextField(Adopt adopt);
    };
}
