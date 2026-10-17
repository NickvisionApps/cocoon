#include "generated/workspace_authorization.h"
#include "internal.h"

namespace cocoon
{
    WorkspaceAuthorization::WorkspaceAuthorization() : WorkspaceAuthorization(Adopt{cocoon::internal::retain([[::NSWorkspaceAuthorization alloc] init])})
    {
    }

    WorkspaceAuthorization::WorkspaceAuthorization(std::nullptr_t) : Object(nullptr)
    {
    }

    WorkspaceAuthorization::WorkspaceAuthorization(Adopt adopt) : Object(adopt)
    {
    }
}
