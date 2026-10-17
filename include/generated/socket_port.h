#pragma once

#include "generated/enums.h"
#include "generated/port.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSSocketPort` (Foundation).
     * @details A port that represents a BSD socket. A ''NSSocketPort'' object can be used as an endpoint for distributed object connections. Companion classes, ''NSMachPort'' and ''NSMessagePort'', allow for local (on the same machine) communication only. The ''NSSocketPort'' class allows for both local and remote communication, but may be more expensive than the others for the local case.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Port.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SocketPort socket_port;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nssocketport
     */
    class SocketPort : public Port
    {
    public:
        /// @brief Creates a new `NSSocketPort` instance and returns a handle to it.
        explicit SocketPort(int family, int type, int protocol, const std::vector<std::uint8_t>& address);
        /// @brief Creates a new `NSSocketPort` instance and returns a handle to it.
        explicit SocketPort(std::uint16_t port, const std::string& host_name);
        /// @brief Creates a new `NSSocketPort` instance and returns a handle to it.
        explicit SocketPort(int family, int type, int protocol, int sock);
        /// @brief Creates a new `NSSocketPort` instance and returns a handle to it.
        explicit SocketPort(std::uint16_t port);
        /// @brief Creates a new `NSSocketPort` instance and returns a handle to it.
        explicit SocketPort();
        /// @brief Creates a null handle that refers to no native object.
        SocketPort(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SocketPort(Adopt adopt);
        /**
     * @brief Returns the `address` property of `NSSocketPort`.
     * @details The receiver's socket address structure stored inside an ''NSData'' object.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> address() const;
        /**
     * @brief Returns the `protocol` property of `NSSocketPort`.
     * @details The protocol that the receiver's socket uses.
     * @return The converted Objective-C result.
     */
        int protocol() const;
        /**
     * @brief Returns the `protocolFamily` property of `NSSocketPort`.
     * @details The protocol family of the receiver's socket.
     * @return The converted Objective-C result.
     */
        int protocol_family() const;
        /**
     * @brief Returns the `socket` property of `NSSocketPort`.
     * @details The receiver's native socket identifier on the platform.
     * @return The converted Objective-C result.
     */
        int socket() const;
        /**
     * @brief Returns the `socketType` property of `NSSocketPort`.
     * @details The type of the receiver's socket.
     * @return The converted Objective-C result.
     */
        int socket_type() const;
    };
}
