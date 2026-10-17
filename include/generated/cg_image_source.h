#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `CGImageSourceRef`. */
    class CGImageSource : public Object
    {
    public:
        CGImageSource() = default;
        CGImageSource(std::nullptr_t)
        {
        }
        explicit CGImageSource(Adopt adopt) : Object(adopt)
        {
        }
    };
}
