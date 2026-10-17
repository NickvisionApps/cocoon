#include "generated/cached_image_rep.h"
#include "internal.h"

namespace cocoon
{
    CachedImageRep::CachedImageRep() : CachedImageRep(Adopt{cocoon::internal::retain([[::NSCachedImageRep alloc] init])})
    {
    }

    CachedImageRep::CachedImageRep(std::nullptr_t) : ImageRep(nullptr)
    {
    }

    CachedImageRep::CachedImageRep(Adopt adopt) : ImageRep(adopt)
    {
    }
}
