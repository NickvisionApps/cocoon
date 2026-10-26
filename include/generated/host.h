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
     * @details DEPRECATION NOTICE If you’re using 'NSHost' to resolve DNS names so that you can connect to a service, switch to a connect-by-name API, for example, 'nw_connection'. If you have other DNS resolution needs, switch to \<dns_sd.h>.
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
         * @return The converted Objective-C result.
         */
        static Host current_host();
        /**
         * @brief Calls `-[NSHost isEqualToHost:]`.
         * @param a_host Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_equal_to_host(const Host& a_host) const;
        /**
         * @brief Returns the `address` property of `NSHost`.
         * @return The converted Objective-C result.
         */
        std::string address() const;
        /**
         * @brief Returns the `addresses` property of `NSHost`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> addresses() const;
        /**
         * @brief Returns the `localizedName` property of `NSHost`.
         * @return The converted Objective-C result.
         */
        std::string localized_name() const;
        /**
         * @brief Returns the `name` property of `NSHost`.
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Returns the `names` property of `NSHost`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> names() const;
    };
}
