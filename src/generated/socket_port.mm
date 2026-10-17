#include "generated/socket_port.h"
#include "internal.h"

namespace cocoon
{
    SocketPort::SocketPort(int family, int type, int protocol, const std::vector<std::uint8_t>& address) : SocketPort(Adopt{cocoon::internal::retain([[::NSSocketPort alloc] initRemoteWithProtocolFamily:static_cast<int>(family) socketType:static_cast<int>(type) protocol:static_cast<int>(protocol) address:cocoon::internal::to_data(address)])})
    {
    }

    SocketPort::SocketPort(std::uint16_t port, const std::string& host_name) : SocketPort(Adopt{cocoon::internal::retain([[::NSSocketPort alloc] initRemoteWithTCPPort:static_cast<unsigned short>(port) host:cocoon::internal::to(host_name)])})
    {
    }

    SocketPort::SocketPort(int family, int type, int protocol, int sock) : SocketPort(Adopt{cocoon::internal::retain([[::NSSocketPort alloc] initWithProtocolFamily:static_cast<int>(family) socketType:static_cast<int>(type) protocol:static_cast<int>(protocol) socket:static_cast<::NSSocketNativeHandle>(sock)])})
    {
    }

    SocketPort::SocketPort(std::uint16_t port) : SocketPort(Adopt{cocoon::internal::retain([[::NSSocketPort alloc] initWithTCPPort:static_cast<unsigned short>(port)])})
    {
    }

    SocketPort::SocketPort() : SocketPort(Adopt{cocoon::internal::retain([[::NSSocketPort alloc] init])})
    {
    }

    SocketPort::SocketPort(std::nullptr_t) : Port(nullptr)
    {
    }

    SocketPort::SocketPort(Adopt adopt) : Port(adopt)
    {
    }

    std::vector<std::uint8_t> SocketPort::address() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSSocketPort>(this) address]);
    }

    int SocketPort::protocol() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSSocketPort>(this) protocol]);
    }

    int SocketPort::protocol_family() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSSocketPort>(this) protocolFamily]);
    }

    int SocketPort::socket() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSSocketPort>(this) socket]);
    }

    int SocketPort::socket_type() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSSocketPort>(this) socketType]);
    }
}
