#include "generated/lock.h"
#include "internal.h"

namespace cocoon
{
    Lock::Lock() : Lock(Adopt{cocoon::internal::retain([[::NSLock alloc] init])})
    {
    }

    Lock::Lock(std::nullptr_t) : Object(nullptr)
    {
    }

    Lock::Lock(Adopt adopt) : Object(adopt)
    {
    }

    bool Lock::lock_before_date(const Date& limit) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLock>(this) lockBeforeDate:cocoon::internal::native<::NSDate>(limit)]);
    }

    bool Lock::try_lock() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLock>(this) tryLock]);
    }

    std::string Lock::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLock>(this) name]);
    }

    void Lock::set_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSLock>(this) setName:cocoon::internal::to(value)];
    }
}
