#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `CGLPBufferObj`. */
    class CGLPBufferObj : public Object
    {
    public:
        CGLPBufferObj() = default;
        CGLPBufferObj(std::nullptr_t)
        {
        }
        explicit CGLPBufferObj(Adopt adopt) : Object(adopt)
        {
        }
    };
}
