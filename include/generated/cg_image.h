#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `CGImageRef`. */
    class CGImage : public Object
    {
    public:
        CGImage() = default;
        CGImage(std::nullptr_t)
        {
        }
        explicit CGImage(Adopt adopt) : Object(adopt)
        {
        }
    };
}
