#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `CGPathRef`. */
    class CGPath : public Object
    {
    public:
        CGPath() = default;
        CGPath(std::nullptr_t)
        {
        }
        explicit CGPath(Adopt adopt) : Object(adopt)
        {
        }
    };
}
