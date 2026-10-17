#include "generated/socket_port_name_server.h"
#include "internal.h"

namespace cocoon
{
    SocketPortNameServer::SocketPortNameServer() : SocketPortNameServer(Adopt{cocoon::internal::retain([[::NSSocketPortNameServer alloc] init])})
    {
    }

    SocketPortNameServer::SocketPortNameServer(std::nullptr_t) : PortNameServer(nullptr)
    {
    }

    SocketPortNameServer::SocketPortNameServer(Adopt adopt) : PortNameServer(adopt)
    {
    }

    Port SocketPortNameServer::port_for_name(const std::string& name) const
    {
        return cocoon::internal::wrap<Port>([cocoon::internal::ns<::NSSocketPortNameServer>(this) portForName:cocoon::internal::to(name)]);
    }

    Port SocketPortNameServer::port_for_name(const std::string& name, const std::string& host) const
    {
        return cocoon::internal::wrap<Port>([cocoon::internal::ns<::NSSocketPortNameServer>(this) portForName:cocoon::internal::to(name) host:cocoon::internal::to(host)]);
    }

    Port SocketPortNameServer::port_for_name(const std::string& name, const std::string& host, std::uint16_t port_number) const
    {
        return cocoon::internal::wrap<Port>([cocoon::internal::ns<::NSSocketPortNameServer>(this) portForName:cocoon::internal::to(name) host:cocoon::internal::to(host) nameServerPortNumber:static_cast<::uint16_t>(port_number)]);
    }

    bool SocketPortNameServer::register_port(const Port& port, const std::string& name) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSocketPortNameServer>(this) registerPort:cocoon::internal::native<::NSPort>(port) name:cocoon::internal::to(name)]);
    }

    bool SocketPortNameServer::register_port(const Port& port, const std::string& name, std::uint16_t port_number) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSocketPortNameServer>(this) registerPort:cocoon::internal::native<::NSPort>(port) name:cocoon::internal::to(name) nameServerPortNumber:static_cast<::uint16_t>(port_number)]);
    }

    bool SocketPortNameServer::remove_port_for_name(const std::string& name) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSocketPortNameServer>(this) removePortForName:cocoon::internal::to(name)]);
    }

    Object SocketPortNameServer::shared_instance()
    {
        return cocoon::internal::wrap<Object>([::NSSocketPortNameServer sharedInstance]);
    }

    std::uint16_t SocketPortNameServer::default_name_server_port_number() const
    {
        return static_cast<std::uint16_t>([cocoon::internal::ns<::NSSocketPortNameServer>(this) defaultNameServerPortNumber]);
    }

    void SocketPortNameServer::set_default_name_server_port_number(std::uint16_t value) const
    {
        [cocoon::internal::ns<::NSSocketPortNameServer>(this) setDefaultNameServerPortNumber:static_cast<::uint16_t>(value)];
    }
}
