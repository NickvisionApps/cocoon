#include "generated/null.h"
#include "internal.h"

namespace cocoon
{
    Null::Null() : Null(Adopt{cocoon::internal::retain([[::NSNull alloc] init])})
    {
    }

    Null::Null(std::nullptr_t) : Object(nullptr)
    {
    }

    Null::Null(Adopt adopt) : Object(adopt)
    {
    }

    Null Null::null()
    {
        return cocoon::internal::wrap<Null>([::NSNull null]);
    }
}
