#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text_field_cell.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSSecureTextFieldCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TextFieldCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SecureTextFieldCell secure_text_field_cell;
     * secure_text_field_cell.set_echos_bullets(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SecureTextFieldCell secure_text_field_cell{};
     * secure_text_field_cell.set_echos_bullets(true);
     * auto echos_bullets = secure_text_field_cell.echos_bullets();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssecuretextfieldcell
     */
    class SecureTextFieldCell : public TextFieldCell
    {
    public:
        /// @brief Creates a new `NSSecureTextFieldCell` instance and returns a handle to it.
        explicit SecureTextFieldCell();
        /// @brief Creates a null handle that refers to no native object.
        SecureTextFieldCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SecureTextFieldCell(Adopt adopt);
        /**
     * @brief Returns the `echosBullets` property of `NSSecureTextFieldCell`.
     * @return The converted Objective-C result.
     */
        bool echos_bullets() const;
        /**
     * @brief Sets the `echosBullets` property of `NSSecureTextFieldCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_echos_bullets(bool value) const;
    };
}
