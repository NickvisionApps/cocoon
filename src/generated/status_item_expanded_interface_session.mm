#include "generated/status_item_expanded_interface_session.h"
#include "internal.h"

namespace cocoon
{
    StatusItemExpandedInterfaceSession::StatusItemExpandedInterfaceSession() : StatusItemExpandedInterfaceSession(Adopt{cocoon::internal::retain([[::NSStatusItemExpandedInterfaceSession alloc] init])})
    {
    }

    StatusItemExpandedInterfaceSession::StatusItemExpandedInterfaceSession(std::nullptr_t) : Object(nullptr)
    {
    }

    StatusItemExpandedInterfaceSession::StatusItemExpandedInterfaceSession(Adopt adopt) : Object(adopt)
    {
    }

    void StatusItemExpandedInterfaceSession::cancel() const
    {
        [cocoon::internal::ns<::NSStatusItemExpandedInterfaceSession>(this) cancel];
    }
}
