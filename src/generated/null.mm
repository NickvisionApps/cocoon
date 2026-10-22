#include "generated/null.h"
#include "internal.h"

namespace cocoon
{
    Null::Null() : Null(Adopt{cocoon::internal::retain([::NSNull null])})
    {
    }

    Null::Null(std::nullptr_t) : Object(nullptr)
    {
    }

    Null::Null(Adopt adopt) : Object(adopt)
    {
    }
}
