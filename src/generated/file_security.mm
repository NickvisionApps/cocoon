#include "generated/file_security.h"
#include "internal.h"

namespace cocoon
{
    FileSecurity::FileSecurity() : FileSecurity(Adopt{cocoon::internal::retain([[::NSFileSecurity alloc] init])})
    {
    }

    FileSecurity::FileSecurity(std::nullptr_t) : Object(nullptr)
    {
    }

    FileSecurity::FileSecurity(Adopt adopt) : Object(adopt)
    {
    }
}
