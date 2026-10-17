#include "generated/mach_bootstrap_server.h"
#include "internal.h"

namespace cocoon
{
    MachBootstrapServer::MachBootstrapServer() : MachBootstrapServer(Adopt{cocoon::internal::retain([[::NSMachBootstrapServer alloc] init])})
    {
    }

    MachBootstrapServer::MachBootstrapServer(std::nullptr_t) : PortNameServer(nullptr)
    {
    }

    MachBootstrapServer::MachBootstrapServer(Adopt adopt) : PortNameServer(adopt)
    {
    }

    Port MachBootstrapServer::port_for_name(const std::string& name) const
    {
        return cocoon::internal::wrap<Port>([cocoon::internal::ns<::NSMachBootstrapServer>(this) portForName:cocoon::internal::to(name)]);
    }

    Port MachBootstrapServer::port_for_name(const std::string& name, const std::string& host) const
    {
        return cocoon::internal::wrap<Port>([cocoon::internal::ns<::NSMachBootstrapServer>(this) portForName:cocoon::internal::to(name) host:cocoon::internal::to(host)]);
    }

    bool MachBootstrapServer::register_port(const Port& port, const std::string& name) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMachBootstrapServer>(this) registerPort:cocoon::internal::native<::NSPort>(port) name:cocoon::internal::to(name)]);
    }

    Port MachBootstrapServer::service_port_with_name(const std::string& name) const
    {
        return cocoon::internal::wrap<Port>([cocoon::internal::ns<::NSMachBootstrapServer>(this) servicePortWithName:cocoon::internal::to(name)]);
    }

    Object MachBootstrapServer::shared_instance()
    {
        return cocoon::internal::wrap<Object>([::NSMachBootstrapServer sharedInstance]);
    }
}
