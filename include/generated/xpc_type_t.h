#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `xpc_type_t`. */
    class xpc_type_t : public Object
    {
    public:
        xpc_type_t() = default;
        xpc_type_t(std::nullptr_t)
        {
        }
        explicit xpc_type_t(Adopt adopt) : Object(adopt)
        {
        }
    };
}
