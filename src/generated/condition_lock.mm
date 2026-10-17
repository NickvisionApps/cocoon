#include "generated/condition_lock.h"
#include "internal.h"

namespace cocoon
{
    ConditionLock::ConditionLock(std::int64_t condition) : ConditionLock(Adopt{cocoon::internal::retain([[::NSConditionLock alloc] initWithCondition:static_cast<::NSInteger>(condition)])})
    {
    }

    ConditionLock::ConditionLock() : ConditionLock(Adopt{cocoon::internal::retain([[::NSConditionLock alloc] init])})
    {
    }

    ConditionLock::ConditionLock(std::nullptr_t) : Object(nullptr)
    {
    }

    ConditionLock::ConditionLock(Adopt adopt) : Object(adopt)
    {
    }

    bool ConditionLock::lock_before_date(const Date& limit) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSConditionLock>(this) lockBeforeDate:cocoon::internal::native<::NSDate>(limit)]);
    }

    void ConditionLock::lock_when_condition(std::int64_t condition) const
    {
        [cocoon::internal::ns<::NSConditionLock>(this) lockWhenCondition:static_cast<::NSInteger>(condition)];
    }

    bool ConditionLock::lock_when_condition(std::int64_t condition, const Date& limit) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSConditionLock>(this) lockWhenCondition:static_cast<::NSInteger>(condition) beforeDate:cocoon::internal::native<::NSDate>(limit)]);
    }

    bool ConditionLock::try_lock() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSConditionLock>(this) tryLock]);
    }

    bool ConditionLock::try_lock_when_condition(std::int64_t condition) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSConditionLock>(this) tryLockWhenCondition:static_cast<::NSInteger>(condition)]);
    }

    void ConditionLock::unlock_with_condition(std::int64_t condition) const
    {
        [cocoon::internal::ns<::NSConditionLock>(this) unlockWithCondition:static_cast<::NSInteger>(condition)];
    }

    std::int64_t ConditionLock::condition() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSConditionLock>(this) condition]);
    }

    std::string ConditionLock::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSConditionLock>(this) name]);
    }

    void ConditionLock::set_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSConditionLock>(this) setName:cocoon::internal::to(value)];
    }
}
