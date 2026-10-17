#include "generated/simple_c_string.h"
#include "internal.h"

namespace cocoon
{
    SimpleCString::SimpleCString() : SimpleCString(Adopt{cocoon::internal::retain([[::NSSimpleCString alloc] init])})
    {
    }

    SimpleCString::SimpleCString(std::nullptr_t) : Object(nullptr)
    {
    }

    SimpleCString::SimpleCString(Adopt adopt) : Object(adopt)
    {
    }
}
