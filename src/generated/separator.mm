#include "generated/separator.h"
#include "internal.h"

namespace cocoon
{
    Separator::Separator() : Separator(Adopt{cocoon::internal::retain(cocoon::internal::make_separator())})
    {
    }

    Separator::Separator(std::nullptr_t) : Box(nullptr)
    {
    }

    Separator::Separator(Adopt adopt) : Box(adopt)
    {
    }
}
