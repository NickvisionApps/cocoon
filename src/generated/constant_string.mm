#include "generated/constant_string.h"
#include "internal.h"

namespace cocoon
{
    ConstantString::ConstantString() : ConstantString(Adopt{cocoon::internal::retain([[::NSConstantString alloc] init])})
    {
    }

    ConstantString::ConstantString(std::nullptr_t) : SimpleCString(nullptr)
    {
    }

    ConstantString::ConstantString(Adopt adopt) : SimpleCString(adopt)
    {
    }
}
