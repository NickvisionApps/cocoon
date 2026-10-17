#include "generated/label.h"
#include "internal.h"

namespace cocoon
{
    Label::Label(const std::string& text) : Label(Adopt{cocoon::internal::retain([NSTextField labelWithString:cocoon::internal::to(text)])})
    {
        TextField::bind_others_(handle());
        TextField::bind_action_(handle());
        TextField::install_delegate_delegate_(handle());
    }

    Label::Label(std::nullptr_t) : TextField(nullptr)
    {
    }

    Label::Label(Adopt adopt) : TextField(adopt)
    {
    }
}
