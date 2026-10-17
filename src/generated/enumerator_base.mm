#include "generated/enumerator_base.h"
#include "internal.h"

namespace cocoon
{
    EnumeratorBase::EnumeratorBase() : EnumeratorBase(Adopt{cocoon::internal::retain([[::NSEnumerator alloc] init])})
    {
    }

    EnumeratorBase::EnumeratorBase(std::nullptr_t) : Object(nullptr)
    {
    }

    EnumeratorBase::EnumeratorBase(Adopt adopt) : Object(adopt)
    {
    }

    Object EnumeratorBase::next_object() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSEnumerator>(this) nextObject]);
    }

    std::vector<Object> EnumeratorBase::all_objects() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSEnumerator>(this) allObjects], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }
}
