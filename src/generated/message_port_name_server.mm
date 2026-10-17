#include "generated/message_port_name_server.h"
#include "internal.h"

namespace cocoon
{
    MessagePortNameServer::MessagePortNameServer() : MessagePortNameServer(Adopt{cocoon::internal::retain([[::NSMessagePortNameServer alloc] init])})
    {
    }

    MessagePortNameServer::MessagePortNameServer(std::nullptr_t) : PortNameServer(nullptr)
    {
    }

    MessagePortNameServer::MessagePortNameServer(Adopt adopt) : PortNameServer(adopt)
    {
    }

    Port MessagePortNameServer::port_for_name(const std::string& name) const
    {
        return cocoon::internal::wrap<Port>([cocoon::internal::ns<::NSMessagePortNameServer>(this) portForName:cocoon::internal::to(name)]);
    }

    Port MessagePortNameServer::port_for_name(const std::string& name, const std::string& host) const
    {
        return cocoon::internal::wrap<Port>([cocoon::internal::ns<::NSMessagePortNameServer>(this) portForName:cocoon::internal::to(name) host:cocoon::internal::to(host)]);
    }

    Object MessagePortNameServer::shared_instance()
    {
        return cocoon::internal::wrap<Object>([::NSMessagePortNameServer sharedInstance]);
    }
}
