#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `CVImageBufferRef`. */
    class CVImageBuffer : public Object
    {
    public:
        CVImageBuffer() = default;
        CVImageBuffer(std::nullptr_t)
        {
        }
        explicit CVImageBuffer(Adopt adopt) : Object(adopt)
        {
        }
    };
}
