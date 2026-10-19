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
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Port port_for_name(const std::string& name) const;
        /**
     * @brief Calls `-[NSMachBootstrapServer portForName:host:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param host Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Port port_for_name(const std::string& name, const std::string& host) const;
        /**
     * @brief Calls `-[NSMachBootstrapServer registerPort:name:]`.
     * @param port Argument converted to the Objective-C parameter of the same role.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool register_port(const Port& port, const std::string& name) const;
        /**
     * @brief Calls `-[NSMachBootstrapServer servicePortWithName:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Port service_port_with_name(const std::string& name) const;
        /**
     * @brief Calls `+[NSMachBootstrapServer sharedInstance]`.
     * @return The converted Objective-C result.
     */
        static Object shared_instance();
    };
}
