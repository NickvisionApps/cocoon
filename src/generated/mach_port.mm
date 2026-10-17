#include "generated/mach_port.h"
#include "internal.h"

namespace cocoon
{
    MachPort::MachPort(unsigned int mach_port) : MachPort(Adopt{cocoon::internal::retain([[::NSMachPort alloc] initWithMachPort:static_cast<::uint32_t>(mach_port)])})
    {
    }

    MachPort::MachPort(unsigned int mach_port, MachPortOptions f) : MachPort(Adopt{cocoon::internal::retain([[::NSMachPort alloc] initWithMachPort:static_cast<::uint32_t>(mach_port) options:static_cast<::NSMachPortOptions>(f)])})
    {
    }

    MachPort::MachPort() : MachPort(Adopt{cocoon::internal::retain([[::NSMachPort alloc] init])})
    {
    }

    MachPort::MachPort(std::nullptr_t) : Port(nullptr)
    {
    }

    MachPort::MachPort(Adopt adopt) : Port(adopt)
    {
    }

    Object MachPort::delegate() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSMachPort>(this) delegate]);
    }

    Port MachPort::port_with_mach_port(unsigned int mach_port)
    {
        return cocoon::internal::wrap<Port>([::NSMachPort portWithMachPort:static_cast<::uint32_t>(mach_port)]);
    }

    Port MachPort::port_with_mach_port(unsigned int mach_port, MachPortOptions f)
    {
        return cocoon::internal::wrap<Port>([::NSMachPort portWithMachPort:static_cast<::uint32_t>(mach_port) options:static_cast<::NSMachPortOptions>(f)]);
    }

    void MachPort::remove_from_run_loop(const RunLoop& run_loop, const std::string& mode) const
    {
        [cocoon::internal::ns<::NSMachPort>(this) removeFromRunLoop:cocoon::internal::native<::NSRunLoop>(run_loop) forMode:cocoon::internal::to(mode)];
    }

    void MachPort::schedule_in_run_loop(const RunLoop& run_loop, const std::string& mode) const
    {
        [cocoon::internal::ns<::NSMachPort>(this) scheduleInRunLoop:cocoon::internal::native<::NSRunLoop>(run_loop) forMode:cocoon::internal::to(mode)];
    }

    void MachPort::set_delegate(const Object& an_object) const
    {
        [cocoon::internal::ns<::NSMachPort>(this) setDelegate:cocoon::internal::native_id(an_object)];
    }

    unsigned int MachPort::mach_port() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSMachPort>(this) machPort]);
    }
}
