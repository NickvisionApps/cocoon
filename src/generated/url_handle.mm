#include "generated/url_handle.h"
#include "internal.h"

namespace cocoon
{
    URLHandle::URLHandle() : URLHandle(Adopt{cocoon::internal::retain([[::NSURLHandle alloc] init])})
    {
    }

    URLHandle::URLHandle(std::nullptr_t) : Object(nullptr)
    {
    }

    URLHandle::URLHandle(Adopt adopt) : Object(adopt)
    {
    }
}
