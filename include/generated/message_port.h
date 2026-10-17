#pragma once

#include "generated/enums.h"
#include "generated/port.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSMessagePort` (Foundation).
     * @details A port that can be used as an endpoint for distributed object connections (or raw messaging). ''MessagePort'' is a subclass of ''Port'' that allows for local (on the same machine) communication only. A companion class, ''SocketPort'', allows for both local and remote communication, but may be more expensive than ''MessagePort'' for the local case. ''MessagePort'' defines no additional methods over those already defined by ''Port''. > Note: > ''MessagePort'' conforms to the ''NSCoding'' protocol, but only supports coding by an ''NSPortCoder'' object. ''Port'' and its subclasses do not support archiving. > Important: > Avoid ''MessagePort''. There's little reason to use ''MessagePort'' rather than ''NSMachPort'' or ''SocketPort''. There's no particular performance or functionality advantage. It is recommended avoiding its use. > > ''MessagePort'' may be deprecated in the macOS 10.6 or later. \#\# See Also - [Distributed Objects Programming Topics](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/DistrObjects/DistrObjects.html\#//apple_ref/doc/uid/10000102i) A port that can be used for local message sending on all platforms.
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
