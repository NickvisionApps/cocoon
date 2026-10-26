#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class SecTrust;

    /**
     * @brief C++ handle for the Objective-C class `NSURLProtectionSpace` (Foundation).
     * @details \@class NSURLProtectionSpace \@discussion This class represents a protection space requiring authentication.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLProtectionSpace url_protection_space;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlprotectionspace
     */
    class URLProtectionSpace : public Object
    {
    public:
        /// @brief Creates a new `NSURLProtectionSpace` instance and returns a handle to it.
        explicit URLProtectionSpace(const std::string& host, std::int64_t port, const std::string& protocol, const std::string& realm, const std::string& authentication_method);
        /// @brief Creates a new `NSURLProtectionSpace` instance and returns a handle to it.
        explicit URLProtectionSpace();
        /// @brief Creates a null handle that refers to no native object.
        URLProtectionSpace(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLProtectionSpace(Adopt adopt);
        /**
         * @brief Returns the `authenticationMethod` property of `NSURLProtectionSpace`.
         * @details \@abstract Get the authentication method to be used for this protection space \@result The authentication method
         * @return The converted Objective-C result.
         */
        std::string authentication_method() const;
        /**
         * @brief Returns the `distinguishedNames` property of `NSURLProtectionSpace`.
         * @details \@abstract Returns an array of acceptable certificate issuing authorities for client certification authentication. Issuers are identified by their distinguished name and returned as a DER encoded data. \@result An array of NSData objects. (Nil if the authenticationMethod is not NSURLAuthenticationMethodClientCertificate)
         * @return The converted Objective-C result.
         */
        std::vector<std::vector<std::uint8_t>> distinguished_names() const;
        /**
         * @brief Returns the `host` property of `NSURLProtectionSpace`.
         * @details \@abstract Get the proxy host if this is a proxy authentication, or the host from the URL. \@result The host for this protection space.
         * @return The converted Objective-C result.
         */
        std::string host() const;
        /**
         * @brief Returns the `isProxy` property of `NSURLProtectionSpace`.
         * @details \@abstract Determine if this authenticating protection space is a proxy server \@result YES if a proxy, NO otherwise
         * @return The converted Objective-C result.
         */
        bool is_proxy() const;
        /**
         * @brief Returns the `port` property of `NSURLProtectionSpace`.
         * @details \@abstract Get the proxy port if this is a proxy authentication, or the port from the URL. \@result The port for this protection space, or 0 if not set.
         * @return The converted Objective-C result.
         */
        std::int64_t port() const;
        /**
         * @brief Returns the `protocol` property of `NSURLProtectionSpace`.
         * @details \@abstract Get the protocol of this protection space, if not a proxy \@result The type string, or nil if a proxy.
         * @return The converted Objective-C result.
         */
        std::string protocol() const;
        /**
         * @brief Returns the `proxyType` property of `NSURLProtectionSpace`.
         * @details \@abstract Get the type of this protection space, if a proxy \@result The type string, or nil if not a proxy.
         * @return The converted Objective-C result.
         */
        std::string proxy_type() const;
        /**
         * @brief Returns the `realm` property of `NSURLProtectionSpace`.
         * @details \@abstract Get the authentication realm for which the protection space that needs authentication \@discussion This is generally only available for http authentication, and may be nil otherwise. \@result The realm string
         * @return The converted Objective-C result.
         */
        std::string realm() const;
        /**
         * @brief Returns the `receivesCredentialSecurely` property of `NSURLProtectionSpace`.
         * @details \@abstract Determine if the password for this protection space can be sent securely \@result YES if a secure authentication method or protocol will be used, NO otherwise
         * @return The converted Objective-C result.
         */
        bool receives_credential_securely() const;
        /**
         * @brief Returns the `serverTrust` property of `NSURLProtectionSpace`.
         * @details \@abstract Returns a SecTrustRef which represents the state of the servers SSL transaction state \@result A SecTrustRef from Security.framework. (Nil if the authenticationMethod is not NSURLAuthenticationMethodServerTrust)
         * @return The converted Objective-C result.
         */
        SecTrust server_trust() const;
    };
}
