#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `CGColorSpaceRef`. */
    class CGColorSpace : public Object
    {
    public:
        CGColorSpace() = default;
        CGColorSpace(std::nullptr_t)
        {
        }
        explicit CGColorSpace(Adopt adopt) : Object(adopt)
        {
        }
    };
}
