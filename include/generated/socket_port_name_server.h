#pragma once

#include "generated/enums.h"
#include "generated/port_name_server.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Port;

    /**
     * @brief C++ handle for the Objective-C class `NSSocketPortNameServer` (Foundation).
     * @details \@DeprecationSummary { Use ''NSXPCConnection'' instead. } A port name server that takes and returns socket ports. Port removal functionality is supported by the ''removePortForName:'' method and should be used to remove invalid socket ports. Unlike the other port name servers, ''NSSocketPortNameServer'' can operate over a network. By registering your socket ports, you make them available to other computers on the local network without hard-coding the TCP port numbers. Clients just need to know the name of the port. ''NSPortNameServer'' is implemented using ''NetService'' and registers ports in the local network domain. The registered name of a port must be unique within the local domain, not just the local host. The name server only supports TCP/IP (either IPv4 or IPv6) sockets. > Note: > Prior to OS X 10.2, ''NSSocketPortNameServer'' was inoperable.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref PortNameServer.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SocketPortNameServer socket_port_name_server;
     * socket_port_name_server.set_default_name_server_port_number(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SocketPortNameServer socket_port_name_server{};
     * socket_port_name_server.set_default_name_server_port_number(1);
     * auto default_name_server_port_number = socket_port_name_server.default_name_server_port_number();
     * socket_port_name_server.port_for_name("text");
     * socket_port_name_server.port_for_name("text", "text");
     * socket_port_name_server.port_for_name("text", "text", 1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nssocketportnameserver
     */
    class SocketPortNameServer : public PortNameServer
    {
    public:
        /// @brief Creates a new `NSSocketPortNameServer` instance and returns a handle to it.
        explicit SocketPortNameServer();
        /// @brief Creates a null handle that refers to no native object.
        SocketPortNameServer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SocketPortNameServer(Adopt adopt);
        using PortNameServer::port_for_name;
        using PortNameServer::register_port;
        using PortNameServer::remove_port_for_name;
        /**
     * @brief Calls `-[NSSocketPortNameServer portForName:]`.
     * @details Looks up and returns the port registered under the specified name.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Port port_for_name(const std::string& name) const;
        /**
     * @brief Calls `-[NSSocketPortNameServer portForName:host:]`.
     * @details Looks up and returns the port registered under the specified name on a given host.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param host Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Port port_for_name(const std::string& name, const std::string& host) const;
        /**
     * @brief Calls `-[NSSocketPortNameServer portForName:host:nameServerPortNumber:]`.
     * @details Looks up and returns the port registered under the specified name on a given host, using the specified port number for the name server.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param host Argument converted to the Objective-C parameter of the same role.
     * @param port_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Port port_for_name(const std::string& name, const std::string& host, std::uint16_t port_number) const;
        /**
     * @brief Calls `-[NSSocketPortNameServer registerPort:name:]`.
     * @details Registers a given port as a network service with the specified name.
     * @param port Argument converted to the Objective-C parameter of the same role.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool register_port(const Port& port, const std::string& name) const;
        /**
     * @brief Calls `-[NSSocketPortNameServer registerPort:name:nameServerPortNumber:]`.
     * @details Registers a given port as a network service with the specified name and name server port number.
     * @param port Argument converted to the Objective-C parameter of the same role.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param port_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool register_port(const Port& port, const std::string& name, std::uint16_t port_number) const;
        /**
     * @brief Calls `-[NSSocketPortNameServer removePortForName:]`.
     * @details Unregisters the port for a given name.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool remove_port_for_name(const std::string& name) const;
        /**
     * @brief Calls `+[NSSocketPortNameServer sharedInstance]`.
     * @details Returns the shared instance of the socket port name server.
     * @return The converted Objective-C result.
     */
        static Object shared_instance();
        /**
     * @brief Returns the `defaultNameServerPortNumber` property of `NSSocketPortNameServer`.
     * @details The default port number for the name server.
     * @return The converted Objective-C result.
     */
        std::uint16_t default_name_server_port_number() const;
        /**
     * @brief Sets the `defaultNameServerPortNumber` property of `NSSocketPortNameServer`.
     * @details The default port number for the name server.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_name_server_port_number(std::uint16_t value) const;
    };
}
