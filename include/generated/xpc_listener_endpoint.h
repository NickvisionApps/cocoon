#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSXPCListenerEndpoint` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::XPCListenerEndpoint xpc_listener_endpoint;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsxpclistenerendpoint
     */
    class XPCListenerEndpoint : public Object
    {
    public:
        /// @brief Creates a new `NSXPCListenerEndpoint` instance and returns a handle to it.
        explicit XPCListenerEndpoint();
        /// @brief Creates a null handle that refers to no native object.
        XPCListenerEndpoint(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit XPCListenerEndpoint(Adopt adopt);
    };
}
