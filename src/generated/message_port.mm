#include "generated/message_port.h"
#include "internal.h"

namespace cocoon
{
    MessagePort::MessagePort() : MessagePort(Adopt{cocoon::internal::retain([[::NSMessagePort alloc] init])})
    {
    }

    MessagePort::MessagePort(std::nullptr_t) : Port(nullptr)
    {
    }

    MessagePort::MessagePort(Adopt adopt) : Port(adopt)
    {
    }
}
