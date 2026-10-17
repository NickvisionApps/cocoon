#pragma once

#include "object.h"

namespace cocoon
{
    /** @brief Opaque handle for the Core Foundation style type `NSAppleEventManagerSuspensionID`. */
    class AppleEventManagerSuspensionID : public Object
    {
    public:
        AppleEventManagerSuspensionID() = default;
        AppleEventManagerSuspensionID(std::nullptr_t)
        {
        }
        explicit AppleEventManagerSuspensionID(Adopt adopt) : Object(adopt)
        {
        }
    };
}
