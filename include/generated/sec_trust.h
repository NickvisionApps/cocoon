#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `SecTrustRef`. */
    class SecTrust : public Object
    {
    public:
        SecTrust() = default;
        SecTrust(std::nullptr_t)
        {
        }
        explicit SecTrust(Adopt adopt) : Object(adopt)
        {
        }
    };
}
