#include "generated/purgeable_data.h"
#include "internal.h"

namespace cocoon
{
    PurgeableData::PurgeableData() : PurgeableData(Adopt{cocoon::internal::retain([[::NSPurgeableData alloc] init])})
    {
    }

    PurgeableData::PurgeableData(std::nullptr_t) : Object(nullptr)
    {
    }

    PurgeableData::PurgeableData(Adopt adopt) : Object(adopt)
    {
    }
}
