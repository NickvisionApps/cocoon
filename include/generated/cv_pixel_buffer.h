#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `CVPixelBufferRef`. */
    class CVPixelBuffer : public Object
    {
    public:
        CVPixelBuffer() = default;
        CVPixelBuffer(std::nullptr_t)
        {
        }
        explicit CVPixelBuffer(Adopt adopt) : Object(adopt)
        {
        }
    };
}
