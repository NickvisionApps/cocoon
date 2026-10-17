#include "generated/v_stack.h"
#include "internal.h"

namespace cocoon
{
    VStack::VStack() : VStack(Adopt{cocoon::internal::retain(cocoon::internal::make_stack(NSUserInterfaceLayoutOrientationVertical))})
    {
        StackView::install_delegate_delegate_(handle());
    }

    VStack::VStack(std::nullptr_t) : StackView(nullptr)
    {
    }

    VStack::VStack(Adopt adopt) : StackView(adopt)
    {
    }
}
