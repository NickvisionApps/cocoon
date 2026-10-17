#include "generated/status_item_expanded_interface_session.h"
#include "internal.h"

#ifdef COCOON_MACOS_27
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

#ifdef COCOON_MACOS_27
    void StatusItemExpandedInterfaceSession::cancel() const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSStatusItemExpandedInterfaceSession>(this) cancel];
        }
    }

#endif
}

#endif
