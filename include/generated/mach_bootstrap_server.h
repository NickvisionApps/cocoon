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
     * @brief C++ handle for the Objective-C class `NSMachBootstrapServer` (Foundation).
     * @details \@DeprecationSummary { Use ''NSXPCConnection'' instead. } A port name server that takes and returns Mach port objects. Port removal functionality is not supported in ''NSMachBootstrapServer''; if you want to cancel a service, you have to destroy the port (invalidate the ''NSMachPort'' given to ''registerPort:name:'').
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref PortNameServer.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MachBootstrapServer mach_bootstrap_server;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MachBootstrapServer mach_bootstrap_server{};
     * mach_bootstrap_server.port_for_name("text");
     * mach_bootstrap_server.port_for_name("text", "text");
     * mach_bootstrap_server.register_port(cocoon::Port(), "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmachbootstrapserver
     */
    class MachBootstrapServer : public PortNameServer
    {
    public:
        /// @brief Creates a new `NSMachBootstrapServer` instance and returns a handle to it.
        explicit MachBootstrapServer();
        /// @brief Creates a null handle that refers to no native object.
        MachBootstrapServer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MachBootstrapServer(Adopt adopt);
        using PortNameServer::port_for_name;
        using PortNameServer::register_port;
        /**
         * @brief Calls `-[NSMachBootstrapServer portForName:]`.
         * @details Looks up and returns the port registered under the specified name.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Port port_for_name(const std::string& name) const;
        /**
         * @brief Calls `-[NSMachBootstrapServer portForName:host:]`.
         * @details Looks up and returns the port registered under the specified name on a given host. The bootstrap server is a local-only server; the host parameter must be an empty string or 'nil'.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param host Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Port port_for_name(const std::string& name, const std::string& host) const;
        /**
         * @brief Calls `-[NSMachBootstrapServer registerPort:name:]`.
         * @details Registers a given port as a network service with the specified name.
         * @param port Argument converted to the Objective-C parameter of the same role.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool register_port(const Port& port, const std::string& name) const;
        /**
         * @brief Calls `-[NSMachBootstrapServer servicePortWithName:]`.
         * @details Returns the port for the specified service name, requesting the launch of the corresponding service if it is not already running.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Port service_port_with_name(const std::string& name) const;
        /**
         * @brief Calls `+[NSMachBootstrapServer sharedInstance]`.
         * @details Returns the shared instance of the Mach bootstrap server.
         * @return The converted Objective-C result.
         */
        static Object shared_instance();
    };
}
