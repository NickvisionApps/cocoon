#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `NSModalSession`. */
    class ModalSession : public Object
    {
    public:
        ModalSession() = default;
        ModalSession(std::nullptr_t)
        {
        }
        explicit ModalSession(Adopt adopt) : Object(adopt)
        {
        }
    };
}
