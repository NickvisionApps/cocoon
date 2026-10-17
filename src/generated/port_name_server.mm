#include "generated/port_name_server.h"
#include "internal.h"

namespace cocoon
{
    PortNameServer::PortNameServer() : PortNameServer(Adopt{cocoon::internal::retain([[::NSPortNameServer alloc] init])})
    {
    }

    PortNameServer::PortNameServer(std::nullptr_t) : Object(nullptr)
    {
    }

    PortNameServer::PortNameServer(Adopt adopt) : Object(adopt)
    {
    }

    Port PortNameServer::port_for_name(const std::string& name) const
    {
        return cocoon::internal::wrap<Port>([cocoon::internal::ns<::NSPortNameServer>(this) portForName:cocoon::internal::to(name)]);
    }

    Port PortNameServer::port_for_name(const std::string& name, const std::string& host) const
    {
        return cocoon::internal::wrap<Port>([cocoon::internal::ns<::NSPortNameServer>(this) portForName:cocoon::internal::to(name) host:cocoon::internal::to(host)]);
    }

    bool PortNameServer::register_port(const Port& port, const std::string& name) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPortNameServer>(this) registerPort:cocoon::internal::native<::NSPort>(port) name:cocoon::internal::to(name)]);
    }

    bool PortNameServer::remove_port_for_name(const std::string& name) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPortNameServer>(this) removePortForName:cocoon::internal::to(name)]);
    }

    PortNameServer PortNameServer::system_default_port_name_server()
    {
        return cocoon::internal::wrap<PortNameServer>([::NSPortNameServer systemDefaultPortNameServer]);
    }
}
