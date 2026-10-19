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
     * @brief C++ handle for the Objective-C class `NSSocketPortNameServer` (Foundation).
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
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Port port_for_name(const std::string& name) const;
        /**
     * @brief Calls `-[NSSocketPortNameServer portForName:host:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param host Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Port port_for_name(const std::string& name, const std::string& host) const;
        /**
     * @brief Calls `-[NSSocketPortNameServer portForName:host:nameServerPortNumber:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param host Argument converted to the Objective-C parameter of the same role.
     * @param port_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Port port_for_name(const std::string& name, const std::string& host, std::uint16_t port_number) const;
        /**
     * @brief Calls `-[NSSocketPortNameServer registerPort:name:]`.
     * @param port Argument converted to the Objective-C parameter of the same role.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool register_port(const Port& port, const std::string& name) const;
        /**
     * @brief Calls `-[NSSocketPortNameServer registerPort:name:nameServerPortNumber:]`.
     * @param port Argument converted to the Objective-C parameter of the same role.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param port_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool register_port(const Port& port, const std::string& name, std::uint16_t port_number) const;
        /**
     * @brief Calls `-[NSSocketPortNameServer removePortForName:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool remove_port_for_name(const std::string& name) const;
        /**
     * @brief Calls `+[NSSocketPortNameServer sharedInstance]`.
     * @return The converted Objective-C result.
     */
        static Object shared_instance();
        /**
     * @brief Returns the `defaultNameServerPortNumber` property of `NSSocketPortNameServer`.
     * @return The converted Objective-C result.
     */
        std::uint16_t default_name_server_port_number() const;
        /**
     * @brief Sets the `defaultNameServerPortNumber` property of `NSSocketPortNameServer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_name_server_port_number(std::uint16_t value) const;
    };
}
