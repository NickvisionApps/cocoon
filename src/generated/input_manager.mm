#include "generated/input_manager.h"
#include "internal.h"

namespace cocoon
{
    InputManager::InputManager() : InputManager(Adopt{cocoon::internal::retain([[::NSInputManager alloc] init])})
    {
    }

    InputManager::InputManager(std::nullptr_t) : Object(nullptr)
    {
    }

    InputManager::InputManager(Adopt adopt) : Object(adopt)
    {
    }
}
