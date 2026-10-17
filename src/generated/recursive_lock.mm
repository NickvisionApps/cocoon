#include "generated/recursive_lock.h"
#include "internal.h"

namespace cocoon
{
    RecursiveLock::RecursiveLock() : RecursiveLock(Adopt{cocoon::internal::retain([[::NSRecursiveLock alloc] init])})
    {
    }

    RecursiveLock::RecursiveLock(std::nullptr_t) : Object(nullptr)
    {
    }

    RecursiveLock::RecursiveLock(Adopt adopt) : Object(adopt)
    {
    }

    bool RecursiveLock::lock_before_date(const Date& limit) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRecursiveLock>(this) lockBeforeDate:cocoon::internal::native<::NSDate>(limit)]);
    }

    bool RecursiveLock::try_lock() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRecursiveLock>(this) tryLock]);
    }

    std::string RecursiveLock::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRecursiveLock>(this) name]);
    }

    void RecursiveLock::set_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSRecursiveLock>(this) setName:cocoon::internal::to(value)];
    }
}
