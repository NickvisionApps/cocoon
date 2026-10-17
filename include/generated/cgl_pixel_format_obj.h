#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `CGLPixelFormatObj`. */
    class CGLPixelFormatObj : public Object
    {
    public:
        CGLPixelFormatObj() = default;
        CGLPixelFormatObj(std::nullptr_t)
        {
        }
        explicit CGLPixelFormatObj(Adopt adopt) : Object(adopt)
        {
        }
    };
}
