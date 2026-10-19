#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Port;

    /**
     * @brief C++ handle for the Objective-C class `NSPortNameServer` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PortNameServer port_name_server;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PortNameServer port_name_server{};
     * auto made_0 = cocoon::PortNameServer::system_default_port_name_server();
     * port_name_server.port_for_name("text");
     * port_name_server.port_for_name("text", "text");
     * port_name_server.register_port(cocoon::Port(), "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsportnameserver
     */
    class PortNameServer : public Object
    {
    public:
        /// @brief Creates a new `NSPortNameServer` instance and returns a handle to it.
        explicit PortNameServer();
        /// @brief Creates a null handle that refers to no native object.
        PortNameServer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PortNameServer(Adopt adopt);
        /**
     * @brief Calls `-[NSPortNameServer portForName:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Port port_for_name(const std::string& name) const;
        /**
     * @brief Calls `-[NSPortNameServer portForName:host:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param host Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Port port_for_name(const std::string& name, const std::string& host) const;
        /**
     * @brief Calls `-[NSPortNameServer registerPort:name:]`.
     * @param port Argument converted to the Objective-C parameter of the same role.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool register_port(const Port& port, const std::string& name) const;
        /**
     * @brief Calls `-[NSPortNameServer removePortForName:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool remove_port_for_name(const std::string& name) const;
        /**
     * @brief Calls `+[NSPortNameServer systemDefaultPortNameServer]`.
     * @return The converted Objective-C result.
     */
        static PortNameServer system_default_port_name_server();
    };
}
