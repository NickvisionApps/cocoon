#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `CGContextRef`. */
    class CGContext : public Object
    {
    public:
        CGContext() = default;
        CGContext(std::nullptr_t)
        {
        }
        explicit CGContext(Adopt adopt) : Object(adopt)
        {
        }
    };
}
