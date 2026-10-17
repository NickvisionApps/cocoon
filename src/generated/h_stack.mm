#include "generated/h_stack.h"
#include "internal.h"

namespace cocoon
{
    HStack::HStack() : HStack(Adopt{cocoon::internal::retain(cocoon::internal::make_stack(NSUserInterfaceLayoutOrientationHorizontal))})
    {
        StackView::install_delegate_delegate_(handle());
    }

    HStack::HStack(std::nullptr_t) : StackView(nullptr)
    {
    }

    HStack::HStack(Adopt adopt) : StackView(adopt)
    {
    }
}
