#include "generated/secure_text_field_cell.h"
#include "internal.h"

namespace cocoon
{
    SecureTextFieldCell::SecureTextFieldCell() : SecureTextFieldCell(Adopt{cocoon::internal::retain([[::NSSecureTextFieldCell alloc] init])})
    {
    }

    SecureTextFieldCell::SecureTextFieldCell(std::nullptr_t) : TextFieldCell(nullptr)
    {
    }

    SecureTextFieldCell::SecureTextFieldCell(Adopt adopt) : TextFieldCell(adopt)
    {
    }

    bool SecureTextFieldCell::echos_bullets() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSecureTextFieldCell>(this) echosBullets]);
    }

    void SecureTextFieldCell::set_echos_bullets(bool value) const
    {
        [cocoon::internal::ns<::NSSecureTextFieldCell>(this) setEchosBullets:static_cast<::BOOL>(value)];
    }
}
