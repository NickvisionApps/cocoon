#include "generated/movie.h"
#include "internal.h"

namespace cocoon
{
    Movie::Movie() : Movie(Adopt{cocoon::internal::retain([[::NSMovie alloc] init])})
    {
    }

    Movie::Movie(std::nullptr_t) : Object(nullptr)
    {
    }

    Movie::Movie(Adopt adopt) : Object(adopt)
    {
    }
}
