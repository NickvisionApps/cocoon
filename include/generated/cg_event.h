#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `CGEventRef`. */
    class CGEvent : public Object
    {
    public:
        CGEvent() = default;
        CGEvent(std::nullptr_t)
        {
        }
        explicit CGEvent(Adopt adopt) : Object(adopt)
        {
        }
    };
}
