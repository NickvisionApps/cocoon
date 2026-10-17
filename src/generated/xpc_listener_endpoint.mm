#include "generated/xpc_listener_endpoint.h"
#include "internal.h"

namespace cocoon
{
    XPCListenerEndpoint::XPCListenerEndpoint() : XPCListenerEndpoint(Adopt{cocoon::internal::retain([[::NSXPCListenerEndpoint alloc] init])})
    {
    }

    XPCListenerEndpoint::XPCListenerEndpoint(std::nullptr_t) : Object(nullptr)
    {
    }

    XPCListenerEndpoint::XPCListenerEndpoint(Adopt adopt) : Object(adopt)
    {
    }
}
