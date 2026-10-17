#include "generated/timer.h"
#include "internal.h"

namespace cocoon
{
    Timer::Timer(const Date& date, double interval, bool repeats, std::function<void(Timer)> block) : Timer(Adopt{cocoon::internal::retain([[::NSTimer alloc] initWithFireDate:cocoon::internal::native<::NSDate>(date) interval:static_cast<::NSTimeInterval>(interval) repeats:static_cast<::BOOL>(repeats) block:(block ? (void (^)(::NSTimer*)) ^ void(::NSTimer * a225_0) { block(cocoon::internal::wrap<Timer>(a225_0)); } : (void (^)(::NSTimer*))nil)])})
    {
    }

    Timer::Timer(const Date& date, double ti, const Object& t, const std::string& s, const Object& ui, bool rep) : Timer(Adopt{cocoon::internal::retain([[::NSTimer alloc] initWithFireDate:cocoon::internal::native<::NSDate>(date) interval:static_cast<::NSTimeInterval>(ti) target:cocoon::internal::native_id(t) selector:NSSelectorFromString(cocoon::internal::to(s)) userInfo:cocoon::internal::native_id(ui) repeats:static_cast<::BOOL>(rep)])})
    {
    }

    Timer::Timer() : Timer(Adopt{cocoon::internal::retain([[::NSTimer alloc] init])})
    {
    }

    Timer::Timer(std::nullptr_t) : Object(nullptr)
    {
    }

    Timer::Timer(Adopt adopt) : Object(adopt)
    {
    }

    void Timer::fire() const
    {
        [cocoon::internal::ns<::NSTimer>(this) fire];
    }

    void Timer::invalidate() const
    {
        [cocoon::internal::ns<::NSTimer>(this) invalidate];
    }

    Timer Timer::scheduled_timer_with_time_interval(double ti, const Invocation& invocation, bool yes_or_no)
    {
        return cocoon::internal::wrap<Timer>([::NSTimer scheduledTimerWithTimeInterval:static_cast<::NSTimeInterval>(ti) invocation:cocoon::internal::native<::NSInvocation>(invocation) repeats:static_cast<::BOOL>(yes_or_no)]);
    }

    Timer Timer::scheduled_timer_with_time_interval(double interval, bool repeats, std::function<void(Timer)> block)
    {
        return cocoon::internal::wrap<Timer>([::NSTimer scheduledTimerWithTimeInterval:static_cast<::NSTimeInterval>(interval) repeats:static_cast<::BOOL>(repeats) block:(block ? (void (^)(::NSTimer*)) ^ void(::NSTimer * a226_0) { block(cocoon::internal::wrap<Timer>(a226_0)); } : (void (^)(::NSTimer*))nil)]);
    }

    Timer Timer::scheduled_timer_with_time_interval(double ti, const Object& a_target, const std::string& a_selector, const Object& user_info, bool yes_or_no)
    {
        return cocoon::internal::wrap<Timer>([::NSTimer scheduledTimerWithTimeInterval:static_cast<::NSTimeInterval>(ti) target:cocoon::internal::native_id(a_target) selector:NSSelectorFromString(cocoon::internal::to(a_selector)) userInfo:cocoon::internal::native_id(user_info) repeats:static_cast<::BOOL>(yes_or_no)]);
    }

    Timer Timer::timer_with_time_interval(double ti, const Invocation& invocation, bool yes_or_no)
    {
        return cocoon::internal::wrap<Timer>([::NSTimer timerWithTimeInterval:static_cast<::NSTimeInterval>(ti) invocation:cocoon::internal::native<::NSInvocation>(invocation) repeats:static_cast<::BOOL>(yes_or_no)]);
    }

    Timer Timer::timer_with_time_interval(double interval, bool repeats, std::function<void(Timer)> block)
    {
        return cocoon::internal::wrap<Timer>([::NSTimer timerWithTimeInterval:static_cast<::NSTimeInterval>(interval) repeats:static_cast<::BOOL>(repeats) block:(block ? (void (^)(::NSTimer*)) ^ void(::NSTimer * a227_0) { block(cocoon::internal::wrap<Timer>(a227_0)); } : (void (^)(::NSTimer*))nil)]);
    }

    Timer Timer::timer_with_time_interval(double ti, const Object& a_target, const std::string& a_selector, const Object& user_info, bool yes_or_no)
    {
        return cocoon::internal::wrap<Timer>([::NSTimer timerWithTimeInterval:static_cast<::NSTimeInterval>(ti) target:cocoon::internal::native_id(a_target) selector:NSSelectorFromString(cocoon::internal::to(a_selector)) userInfo:cocoon::internal::native_id(user_info) repeats:static_cast<::BOOL>(yes_or_no)]);
    }

    Date Timer::fire_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSTimer>(this) fireDate]);
    }

    void Timer::set_fire_date(const Date& value) const
    {
        [cocoon::internal::ns<::NSTimer>(this) setFireDate:cocoon::internal::native<::NSDate>(value)];
    }

    double Timer::time_interval() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTimer>(this) timeInterval]);
    }

    double Timer::tolerance() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTimer>(this) tolerance]);
    }

    void Timer::set_tolerance(double value) const
    {
        [cocoon::internal::ns<::NSTimer>(this) setTolerance:static_cast<::NSTimeInterval>(value)];
    }

    Object Timer::user_info() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTimer>(this) userInfo]);
    }

    bool Timer::is_valid() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTimer>(this) isValid]);
    }
}
