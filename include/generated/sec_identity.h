#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `SecIdentityRef`. */
    class SecIdentity : public Object
    {
    public:
        SecIdentity() = default;
        SecIdentity(std::nullptr_t)
        {
        }
        explicit SecIdentity(Adopt adopt) : Object(adopt)
        {
        }
    };
}
