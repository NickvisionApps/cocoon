#include "generated/condition.h"
#include "internal.h"

namespace cocoon
{
    Condition::Condition() : Condition(Adopt{cocoon::internal::retain([[::NSCondition alloc] init])})
    {
    }

    Condition::Condition(std::nullptr_t) : Object(nullptr)
    {
    }

    Condition::Condition(Adopt adopt) : Object(adopt)
    {
    }

    void Condition::broadcast() const
    {
        [cocoon::internal::ns<::NSCondition>(this) broadcast];
    }

    void Condition::signal_() const
    {
        [cocoon::internal::ns<::NSCondition>(this) signal];
    }

    void Condition::wait() const
    {
        [cocoon::internal::ns<::NSCondition>(this) wait];
    }

    bool Condition::wait_until_date(const Date& limit) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCondition>(this) waitUntilDate:cocoon::internal::native<::NSDate>(limit)]);
    }

    std::string Condition::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCondition>(this) name]);
    }

    void Condition::set_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSCondition>(this) setName:cocoon::internal::to(value)];
    }
}
