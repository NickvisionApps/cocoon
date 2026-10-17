#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `CFRunLoopRef`. */
    class CFRunLoop : public Object
    {
    public:
        CFRunLoop() = default;
        CFRunLoop(std::nullptr_t)
        {
        }
        explicit CFRunLoop(Adopt adopt) : Object(adopt)
        {
        }
    };
}
