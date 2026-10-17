#include "generated/secure_text_field.h"
#include "internal.h"

namespace cocoon
{
    SecureTextField::SecureTextField() : SecureTextField(Adopt{cocoon::internal::retain([[NSSecureTextField alloc] init])})
    {
        TextField::bind_others_(handle());
        TextField::bind_action_(handle());
        TextField::install_delegate_delegate_(handle());
    }

    SecureTextField::SecureTextField(std::nullptr_t) : TextField(nullptr)
    {
    }

    SecureTextField::SecureTextField(Adopt adopt) : TextField(adopt)
    {
    }
}
