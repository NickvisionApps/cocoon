#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `CGLContextObj`. */
    class CGLContextObj : public Object
    {
    public:
        CGLContextObj() = default;
        CGLContextObj(std::nullptr_t)
        {
        }
        explicit CGLContextObj(Adopt adopt) : Object(adopt)
        {
        }
    };
}
