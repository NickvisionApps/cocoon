#include "generated/thread.h"
#include "internal.h"

namespace cocoon
{
    Thread::Thread(std::function<void()> block) : Thread(Adopt{cocoon::internal::retain([[::NSThread alloc] initWithBlock:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)])})
    {
    }

    Thread::Thread(const Object& target, const std::string& selector, const Object& argument) : Thread(Adopt{cocoon::internal::retain([[::NSThread alloc] initWithTarget:cocoon::internal::native_id(target) selector:NSSelectorFromString(cocoon::internal::to(selector)) object:cocoon::internal::native_id(argument)])})
    {
    }

    Thread::Thread() : Thread(Adopt{cocoon::internal::retain([[::NSThread alloc] init])})
    {
    }

    Thread::Thread(std::nullptr_t) : Object(nullptr)
    {
    }

    Thread::Thread(Adopt adopt) : Object(adopt)
    {
    }

    void Thread::cancel() const
    {
        [cocoon::internal::ns<::NSThread>(this) cancel];
    }

    void Thread::detach_new_thread_selector(const std::string& selector, const Object& target, const Object& argument)
    {
        [::NSThread detachNewThreadSelector:NSSelectorFromString(cocoon::internal::to(selector)) toTarget:cocoon::internal::native_id(target) withObject:cocoon::internal::native_id(argument)];
    }

    void Thread::detach_new_thread_with_block(std::function<void()> block)
    {
        [::NSThread detachNewThreadWithBlock:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)];
    }

    void Thread::exit()
    {
        [::NSThread exit];
    }

    bool Thread::is_multi_threaded()
    {
        return static_cast<bool>([::NSThread isMultiThreaded]);
    }

    void Thread::main_() const
    {
        [cocoon::internal::ns<::NSThread>(this) main];
    }

    void Thread::sleep_for_time_interval(double ti)
    {
        [::NSThread sleepForTimeInterval:static_cast<::NSTimeInterval>(ti)];
    }

    void Thread::sleep_until_date(const Date& date)
    {
        [::NSThread sleepUntilDate:cocoon::internal::native<::NSDate>(date)];
    }

    void Thread::start() const
    {
        [cocoon::internal::ns<::NSThread>(this) start];
    }

    std::vector<Number> Thread::call_stack_return_addresses()
    {
        return cocoon::internal::from_array<Number>([::NSThread callStackReturnAddresses], [](id e) -> Number
                                      {
                                          return cocoon::internal::wrap<Number>((::NSNumber*)e);
                                      });
    }

    std::vector<std::string> Thread::call_stack_symbols()
    {
        return cocoon::internal::from_array<std::string>([::NSThread callStackSymbols], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    bool Thread::is_cancelled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSThread>(this) isCancelled]);
    }

    Thread Thread::current_thread()
    {
        return cocoon::internal::wrap<Thread>([::NSThread currentThread]);
    }

    bool Thread::is_executing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSThread>(this) isExecuting]);
    }

    bool Thread::is_finished() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSThread>(this) isFinished]);
    }

    bool Thread::is_main_thread() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSThread>(this) isMainThread]);
    }

    Thread Thread::main_thread()
    {
        return cocoon::internal::wrap<Thread>([::NSThread mainThread]);
    }

    std::string Thread::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSThread>(this) name]);
    }

    void Thread::set_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSThread>(this) setName:cocoon::internal::to(value)];
    }

    QualityOfService Thread::quality_of_service() const
    {
        return static_cast<QualityOfService>([cocoon::internal::ns<::NSThread>(this) qualityOfService]);
    }

    void Thread::set_quality_of_service(QualityOfService value) const
    {
        [cocoon::internal::ns<::NSThread>(this) setQualityOfService:static_cast<::NSQualityOfService>(value)];
    }

    std::uint64_t Thread::stack_size() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSThread>(this) stackSize]);
    }

    void Thread::set_stack_size(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSThread>(this) setStackSize:static_cast<::NSUInteger>(value)];
    }

    std::vector<std::pair<Object, Object>> Thread::thread_dictionary() const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>([cocoon::internal::ns<::NSThread>(this) threadDictionary], [](id k) -> Object
                                                                           {
                                                                               return cocoon::internal::wrap<Object>(k);
                                                                           },
                                                                           [](id v) -> Object
                                                                           {
                                                                               return cocoon::internal::wrap<Object>(v);
                                                                           });
    }

    double Thread::thread_priority() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSThread>(this) threadPriority]);
    }

    void Thread::set_thread_priority(double value) const
    {
        [cocoon::internal::ns<::NSThread>(this) setThreadPriority:static_cast<double>(value)];
    }
}
