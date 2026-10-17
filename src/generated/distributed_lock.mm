#include "generated/distributed_lock.h"
#include "internal.h"

namespace cocoon
{
    DistributedLock::DistributedLock(const std::string& path) : DistributedLock(Adopt{cocoon::internal::retain([[::NSDistributedLock alloc] initWithPath:cocoon::internal::to(path)])})
    {
    }

    DistributedLock::DistributedLock() : Object(nullptr)
    {
    }

    DistributedLock::DistributedLock(std::nullptr_t) : Object(nullptr)
    {
    }

    DistributedLock::DistributedLock(Adopt adopt) : Object(adopt)
    {
    }

    void DistributedLock::break_lock() const
    {
        [cocoon::internal::ns<::NSDistributedLock>(this) breakLock];
    }

    DistributedLock DistributedLock::lock_with_path(const std::string& path)
    {
        return cocoon::internal::wrap<DistributedLock>([::NSDistributedLock lockWithPath:cocoon::internal::to(path)]);
    }

    bool DistributedLock::try_lock() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDistributedLock>(this) tryLock]);
    }

    void DistributedLock::unlock() const
    {
        [cocoon::internal::ns<::NSDistributedLock>(this) unlock];
    }

    Date DistributedLock::lock_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDistributedLock>(this) lockDate]);
    }
}
