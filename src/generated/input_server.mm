#include "generated/input_server.h"
#include "internal.h"

namespace cocoon
{
    InputServer::InputServer() : InputServer(Adopt{cocoon::internal::retain([[::NSInputServer alloc] init])})
    {
    }

    InputServer::InputServer(std::nullptr_t) : Object(nullptr)
    {
    }

    InputServer::InputServer(Adopt adopt) : Object(adopt)
    {
    }
}
