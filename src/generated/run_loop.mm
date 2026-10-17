#include "generated/run_loop.h"
#include "internal.h"

namespace cocoon
{
    RunLoop::RunLoop() : RunLoop(Adopt{cocoon::internal::retain([[::NSRunLoop alloc] init])})
    {
    }

    RunLoop::RunLoop(std::nullptr_t) : Object(nullptr)
    {
    }

    RunLoop::RunLoop(Adopt adopt) : Object(adopt)
    {
    }

    void RunLoop::accept_input_for_mode(const std::string& mode, const Date& limit_date) const
    {
        [cocoon::internal::ns<::NSRunLoop>(this) acceptInputForMode:cocoon::internal::to(mode) beforeDate:cocoon::internal::native<::NSDate>(limit_date)];
    }

    void RunLoop::add_port(const Port& a_port, const std::string& mode) const
    {
        [cocoon::internal::ns<::NSRunLoop>(this) addPort:cocoon::internal::native<::NSPort>(a_port) forMode:cocoon::internal::to(mode)];
    }

    void RunLoop::add_timer(const Timer& timer, const std::string& mode) const
    {
        [cocoon::internal::ns<::NSRunLoop>(this) addTimer:cocoon::internal::native<::NSTimer>(timer) forMode:cocoon::internal::to(mode)];
    }

    void RunLoop::cancel_perform_selector(const std::string& a_selector, const Object& target, const Object& arg) const
    {
        [cocoon::internal::ns<::NSRunLoop>(this) cancelPerformSelector:NSSelectorFromString(cocoon::internal::to(a_selector)) target:cocoon::internal::native_id(target) argument:cocoon::internal::native_id(arg)];
    }

    void RunLoop::cancel_perform_selectors_with_target(const Object& target) const
    {
        [cocoon::internal::ns<::NSRunLoop>(this) cancelPerformSelectorsWithTarget:cocoon::internal::native_id(target)];
    }

    CFRunLoop RunLoop::get_cf_run_loop() const
    {
        return cocoon::internal::wrap_cf<CFRunLoop>((const void*)([cocoon::internal::ns<::NSRunLoop>(this) getCFRunLoop]));
    }

    Date RunLoop::limit_date_for_mode(const std::string& mode) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSRunLoop>(this) limitDateForMode:cocoon::internal::to(mode)]);
    }

    void RunLoop::perform_block(std::function<void()> block) const
    {
        [cocoon::internal::ns<::NSRunLoop>(this) performBlock:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)];
    }

    void RunLoop::perform_in_modes(const std::vector<std::string>& modes, std::function<void()> block) const
    {
        [cocoon::internal::ns<::NSRunLoop>(this) performInModes:cocoon::internal::to_array(modes, [](const std::string& e) -> id
                                                               {
                                                                   return cocoon::internal::to(e);
                                                               })
                                            block:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)];
    }

    void RunLoop::perform_selector(const std::string& a_selector, const Object& target, const Object& arg, std::uint64_t order, const std::vector<std::string>& modes) const
    {
        [cocoon::internal::ns<::NSRunLoop>(this) performSelector:NSSelectorFromString(cocoon::internal::to(a_selector))
                                            target:cocoon::internal::native_id(target)
                                          argument:cocoon::internal::native_id(arg)
                                             order:static_cast<::NSUInteger>(order)
                                             modes:cocoon::internal::to_array(modes, [](const std::string& e) -> id
                                                                {
                                                                    return cocoon::internal::to(e);
                                                                })];
    }

    void RunLoop::remove_port(const Port& a_port, const std::string& mode) const
    {
        [cocoon::internal::ns<::NSRunLoop>(this) removePort:cocoon::internal::native<::NSPort>(a_port) forMode:cocoon::internal::to(mode)];
    }

    void RunLoop::run() const
    {
        [cocoon::internal::ns<::NSRunLoop>(this) run];
    }

    bool RunLoop::run_mode(const std::string& mode, const Date& limit_date) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRunLoop>(this) runMode:cocoon::internal::to(mode) beforeDate:cocoon::internal::native<::NSDate>(limit_date)]);
    }

    void RunLoop::run_until_date(const Date& limit_date) const
    {
        [cocoon::internal::ns<::NSRunLoop>(this) runUntilDate:cocoon::internal::native<::NSDate>(limit_date)];
    }

    std::string RunLoop::current_mode() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRunLoop>(this) currentMode]);
    }

    RunLoop RunLoop::current_run_loop()
    {
        return cocoon::internal::wrap<RunLoop>([::NSRunLoop currentRunLoop]);
    }

    RunLoop RunLoop::main_run_loop()
    {
        return cocoon::internal::wrap<RunLoop>([::NSRunLoop mainRunLoop]);
    }
}
