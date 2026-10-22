#include "generated/port.h"
#include "internal.h"

namespace cocoon
{
    Port::Port() : Port(Adopt{cocoon::internal::retain([::NSPort port])})
    {
    }

    Port::Port(std::nullptr_t) : Object(nullptr)
    {
    }

    Port::Port(Adopt adopt) : Object(adopt)
    {
    }

    Object Port::delegate() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSPort>(this) delegate]);
    }

    void Port::invalidate() const
    {
        [cocoon::internal::ns<::NSPort>(this) invalidate];
    }

    void Port::remove_from_run_loop(const RunLoop& run_loop, const std::string& mode) const
    {
        [cocoon::internal::ns<::NSPort>(this) removeFromRunLoop:cocoon::internal::native<::NSRunLoop>(run_loop) forMode:cocoon::internal::to(mode)];
    }

    void Port::schedule_in_run_loop(const RunLoop& run_loop, const std::string& mode) const
    {
        [cocoon::internal::ns<::NSPort>(this) scheduleInRunLoop:cocoon::internal::native<::NSRunLoop>(run_loop) forMode:cocoon::internal::to(mode)];
    }

    bool Port::send_before_date(const Date& limit_date, const std::vector<Object>& components, const Port& receive_port, std::uint64_t header_space_reserved) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPort>(this) sendBeforeDate:cocoon::internal::native<::NSDate>(limit_date)
                                                                           components:[cocoon::internal::to_array(components, [](const Object& e) -> id
                                                                                                                  {
                                                                                                                      return cocoon::internal::native_id(e);
                                                                                                                  }) mutableCopy]
                                                                                 from:cocoon::internal::native<::NSPort>(receive_port)
                                                                             reserved:static_cast<::NSUInteger>(header_space_reserved)]);
    }

    bool Port::send_before_date(const Date& limit_date, std::uint64_t msg_id, const std::vector<Object>& components, const Port& receive_port, std::uint64_t header_space_reserved) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPort>(this) sendBeforeDate:cocoon::internal::native<::NSDate>(limit_date)
                                                                                msgid:static_cast<::NSUInteger>(msg_id)
                                                                           components:[cocoon::internal::to_array(components, [](const Object& e) -> id
                                                                                                                  {
                                                                                                                      return cocoon::internal::native_id(e);
                                                                                                                  }) mutableCopy]
                                                                                 from:cocoon::internal::native<::NSPort>(receive_port)
                                                                             reserved:static_cast<::NSUInteger>(header_space_reserved)]);
    }

    void Port::set_delegate(const Object& an_object) const
    {
        [cocoon::internal::ns<::NSPort>(this) setDelegate:cocoon::internal::native_id(an_object)];
    }

    std::uint64_t Port::reserved_space_length() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSPort>(this) reservedSpaceLength]);
    }

    bool Port::is_valid() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPort>(this) isValid]);
    }
}
