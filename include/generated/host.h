#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSHost` (Foundation).
     * @details A representation of an individual host on the network. The ''NSHost'' class provides methods to access the network name and address information for a host. Instances of the ''NSHost'' class represent individual hosts on a network. Use ''NSHost'' objects to get the current host's names and addresses and to look up other hosts by name or by address. To create an ''NSHost'' object, use the ''current()'', ''init(address:)'', or ''init(name:)'' class methods (don't use 'alloc' and 'init'). These methods use available network administration services to discover all names and addresses for the host requested. They don't attempt to contact the host itself, however. This approach avoids untimely delays due to a host being unavailable, but it may result in incomplete information about the host. An ''NSHost'' object contains all of the network addresses and names discovered for a given host by the network administration services. Each ''NSHost'' object may contain several addresses and have more than one name. If an ''NSHost'' object has more than one name, the additional names are variations on the same name, typically the basic host name plus the fully qualified domain name. For example, with a host name '"sales"' in the domain '"anycorp.com"', an ''NSHost'' object can hold both the names '"sales"' and '"sales.anycorp.com"'. ''NSHost'' methods are thread-safe. \@DeprecationSummary { Use Network framework instead; see the deprecation notice in '\<Foundation/NSHost.h>'. }
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Host host;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Host host{};
     * auto made_0 = cocoon::Host::current_host();
     * host.is_equal_to_host(cocoon::Host());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nshost
     */
    class Host : public Object
    {
    public:
        /// @brief Creates a new `NSHost` instance and returns a handle to it.
        explicit Host(const std::string& address);
        /// @brief Creates a new `NSHost` instance and returns a handle to it.
        explicit Host();
        /// @brief Creates a null handle that refers to no native object.
        Host(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Host(Adopt adopt);
        /**
         * @brief Calls `+[NSHost currentHost]`.
         * @details Returns an ''NSHost'' object representing the host the process is running on. This method executes synchronously. The execution time of this method can be highly variable, depending on the local network configuration, and may block for several seconds if the network is unreachable. To avoid blocking execution on the main thread, you should call this method in an ''Operation'' or Grand Central Dispatch block that executes asynchronously in the background. - Returns: 'NSHost' object for the process's host.
         * @return The converted Objective-C result.
         */
        static Host current_host();
        /**
         * @brief Calls `-[NSHost isEqualToHost:]`.
         * @details Indicates whether the receiver represents the same host as another 'NSHost' object. - Parameters: - aHost: Host to compare the receiver to. - Returns: 'YES' when the receiver and 'aHost' share at least one network address; 'NO' otherwise.
         * @param a_host Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_equal_to_host(const Host& a_host) const;
        /**
         * @brief Returns the `address` property of `NSHost`.
         * @details One of the addresses associated with the receiver, such as '"192.42.172.1"' or '"fe80::1"'.
         * @return The converted Objective-C result.
         */
        std::string address() const;
        /**
         * @brief Returns the `addresses` property of `NSHost`.
         * @details All of the addresses associated with the receiver, including IPv6 and IPv4 addresses.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> addresses() const;
        /**
         * @brief Returns the `localizedName` property of `NSHost`.
         * @details The localized name for the host. This is the name displayed in the Finder sidebar and the Sharing preference panel. This property only returns a value when sent to the ''currentHost'' instance; all other instances currently return 'nil'. This property is key-value observable.
         * @return The converted Objective-C result.
         */
        std::string localized_name() const;
        /**
         * @brief Returns the `name` property of `NSHost`.
         * @details One of the hostnames associated with the receiver. Can be either a simple hostname, such as '"sales"', or a fully qualified domain name, such as '"sales.anycorp.com"'.
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Returns the `names` property of `NSHost`.
         * @details All of the hostnames associated with the receiver.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> names() const;
    };
}
