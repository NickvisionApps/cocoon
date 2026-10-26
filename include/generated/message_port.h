#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/port.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSMessagePort` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Port.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MessagePort message_port;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmessageport
     */
    class MessagePort : public Port
    {
    public:
        /// @brief Creates a new `NSMessagePort` instance and returns a handle to it.
        explicit MessagePort();
        /// @brief Creates a null handle that refers to no native object.
        MessagePort(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MessagePort(Adopt adopt);
    };
}
