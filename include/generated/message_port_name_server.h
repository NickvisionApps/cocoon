#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/port_name_server.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Port;

    /**
     * @brief C++ handle for the Objective-C class `NSMessagePortNameServer` (Foundation).
     * @details \@DeprecationSummary { Use ''NSXPCConnection'' instead. } A server takes and returns message ports. This port name server takes and returns instances of ''MessagePort''. Port removal functionality is not supported in ''NSMessagePortNameServer''; if you want to cancel a service, you have to destroy the port (invalidate the ''MessagePort'' object given to ''NSPortNameServer/registerPort:name:'').
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref PortNameServer.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MessagePortNameServer message_port_name_server;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MessagePortNameServer message_port_name_server{};
     * message_port_name_server.port_for_name("text");
     * message_port_name_server.port_for_name("text", "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmessageportnameserver
     */
    class MessagePortNameServer : public PortNameServer
    {
    public:
        /// @brief Creates a new `NSMessagePortNameServer` instance and returns a handle to it.
        explicit MessagePortNameServer();
        /// @brief Creates a null handle that refers to no native object.
        MessagePortNameServer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MessagePortNameServer(Adopt adopt);
        using PortNameServer::port_for_name;
        /**
     * @brief Calls `-[NSMessagePortNameServer portForName:]`.
     * @details Looks up and returns the port registered under the specified name.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Port port_for_name(const std::string& name) const;
        /**
     * @brief Calls `-[NSMessagePortNameServer portForName:host:]`.
     * @details Looks up and returns the port registered under the specified name on a given host. This name server is a local-only server; the host parameter must be an empty string or 'nil'.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param host Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Port port_for_name(const std::string& name, const std::string& host) const;
        /**
     * @brief Calls `+[NSMessagePortNameServer sharedInstance]`.
     * @details Returns the shared instance of the message port name server.
     * @return The converted Objective-C result.
     */
        static Object shared_instance();
    };
}
