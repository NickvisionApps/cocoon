#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `IOSurfaceRef`. */
    class IOSurface : public Object
    {
    public:
        IOSurface() = default;
        IOSurface(std::nullptr_t)
        {
        }
        explicit IOSurface(Adopt adopt) : Object(adopt)
        {
        }
    };
}
