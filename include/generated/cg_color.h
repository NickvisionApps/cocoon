#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `CGColorRef`. */
    class CGColor : public Object
    {
    public:
        CGColor() = default;
        CGColor(std::nullptr_t)
        {
        }
        explicit CGColor(Adopt adopt) : Object(adopt)
        {
        }
    };
}
